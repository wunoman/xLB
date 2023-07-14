//--------------------------------------------------------------------------------------------------
// @file xlb.h
// @brief bind c++ to Lua
// @author wunoman@qq.com
// @date 20170219
//--------------------------------------------------------------------------------------------------
#ifndef _XLB_H
#define _XLB_H

#include <assert.h>

#include <array>
// #include <cstring>
#include <functional>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <tuple>
#include <type_traits>
#include <typeindex>
#include <typeinfo>
#include <unordered_map>
#include <vector>

using namespace std;
using namespace std::placeholders;

//--------------------------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
#include <lauxlib.h>
#include <lua.h>
#include <lualib.h>
#ifdef __cplusplus
}
#endif

//--------------------------------------------------------------------------------------------------

#ifdef DEBUG

constexpr auto debug_mode = true;
#define xlb_debug(format, ...)                                                                     \
  printf("(%07d,%-15s,%-15s) " format, __LINE__, __FUNCTION__, __FILE__, ##__VA_ARGS__)
#define xlb_dbg() xlb_debug("\n")

#else

constexpr auto debug_mode = false;
#define xlb_debug(...)
#define xlb_dbg()

#endif

//--------------------------------------------------------------------------------------------------
// tir (Type Information Replenish)
//--------------------------------------------------------------------------------------------------

static void xlb_donothing() {}

//--------------------------------------------------------------------------------------------------
struct xlb_guard {};

//--------------------------------------------------------------------------------------------------
template <typename T> using xlb_t = typename T::type;

//--------------------------------------------------------------------------------------------------
// xlt_each
//--------------------------------------------------------------------------------------------------
struct xlt_each {
  template <class... T> xlt_each(T...) {}
};

//--------------------------------------------------------------------------------------------------
// xlt_typelist
//--------------------------------------------------------------------------------------------------
template <typename... T> struct xlt_typelist { static int const size = sizeof...(T); };

//--------------------------------------------------------------------------------------------------
// xlt_makeidx
//--------------------------------------------------------------------------------------------------
template <int...> struct xlb_idx {};

template <int, class Idx, int> struct xlt_makeidx;

template <int I, int... Idxs, int RM> struct xlt_makeidx<I, xlb_idx<Idxs...>, RM> {
  using type = xlb_t<xlt_makeidx<I + 1, xlb_idx<Idxs..., I>, RM - 1>>;
};

template <int I, int... Idx> struct xlt_makeidx<I, xlb_idx<Idx...>, 0> {
  using type = xlb_idx<Idx...>;
};

///< index sequence zero-based
template <int N> using xlb_idx_t = xlb_t<xlt_makeidx<0, xlb_idx<>, N>>;

//--------------------------------------------------------------------------------------------------
template <typename... T> struct xlb_tupsize {};
template <typename... T> struct xlb_tupsize<std::tuple<T...> &> {
  static constexpr auto value = sizeof...(T);
};
template <typename... T> struct xlb_tupsize<std::tuple<T...>> {
  static constexpr auto value = sizeof...(T);
};
template <typename TUP> inline constexpr auto xlb_tupsize_v = xlb_tupsize<TUP>::value;

//--------------------------------------------------------------------------------------------------
// predeclare
//--------------------------------------------------------------------------------------------------
template <typename X> struct xlb_base_class;
template <typename X> struct xlb_class;
template <typename F> struct xlb_fmate;

// because reference is taked as pointer, and in some case have to distinct
// each other, if std::is_reference_v<T>==true then U<>T
template <typename Vt, typename T, typename U, typename Dtor> struct xlb_lpointer {};

template <typename Vt, typename T> struct xlb_lstruct;

struct xlb_vter;
struct xlb_util;
struct xlb_property;
struct xlb_base_wrap;
struct xlb_delete;

struct xlb_notpointer {
  using type = void;
  xlb_notpointer(const int *p = nullptr) {}
  void pusharg(lua_State *L, int &rc) {}
};

template <typename T, typename AT = xlb_notpointer, typename Del = std::default_delete<T>>
class xlb_wrap;

template <typename Vt, typename T> using xlb_at = xlb_t<typename Vt::template xlb_tir<T>>;

template <typename R> struct xlt_rvtrait {};

struct xlb_luafunc {
  int ref_id = LUA_NOREF;
};

//--------------------------------------------------------------------------------------------------
struct xlb_base_cbcf {
  virtual void setLua(lua_State *L) = 0;
  virtual void updatestatic(lua_State *L) = 0;
};

//--------------------------------------------------------------------------------------------------
// type support
//--------------------------------------------------------------------------------------------------
template <bool B, class T, class F> using xlt_ifelse_t = std::conditional_t<B, T, F>;

//--------------------------------------------------------------------------------------------------
template <typename T> struct is_cp : std::false_type {};
template <typename T> struct is_cp<T *const> : std::true_type {};
template <typename T> inline constexpr auto is_cp_v = is_cp<T>::value;

template <typename T> struct is_vp : std::false_type {};
template <typename T> struct is_vp<T *> : std::true_type {};
template <typename T> inline constexpr auto is_vp_v = is_vp<T>::value;

template <typename T> struct is_p2cv : std::false_type {};
template <typename T> struct is_p2cv<const T *> : std::true_type {};
template <typename T> inline constexpr auto is_p2cv_v = is_p2cv<T>::value;

//--------------------------------------------------------------------------------------------------
template <typename Vt, typename T> struct is_lstruct : std::false_type {};
template <typename Vt, typename T> struct is_lstruct<Vt, xlb_lstruct<Vt, T>> : std::true_type {};
template <typename Vt, typename T> inline constexpr auto is_lstruct_v = is_lstruct<Vt, T>::value;

//--------------------------------------------------------------------------------------------------
template <typename T, typename = void> struct is_complete : std::false_type {};
template <typename T> struct is_complete<T, decltype(void(sizeof(T)))> : std::true_type {};
template <typename T> inline constexpr auto is_complete_v = is_complete<T>::value;

template <typename T> struct xlb_completetype {
  using type = xlt_ifelse_t<is_complete_v<T>, T, void>;
};

template <typename T> using xlb_completetype_t = xlb_t<xlb_completetype<T>>;

//--------------------------------------------------------------------------------------------------
template <typename T> constexpr auto xlb_sizeof() {
  return sizeof(
      // XXX: for incomplete type
      std::conditional_t<std::is_void_v<xlb_completetype_t<T>>, int, T>);
  // return sizeof(std::conditional_t<std::is_void_v<T>, int, T>);
}

//--------------------------------------------------------------------------------------------------
// @struct xlb_ai
// argument info, the argument value loaded from Lua
//--------------------------------------------------------------------------------------------------
struct xlb_ai {
  int from = 0;  ///< fetch from
  int to = 0;    ///< fetch to, [from, to)
  int type = 0;  ///< lua data type
  int index = 0; ///< which argument, one-based
};

enum class xlf_prop : uint8_t {
  byref = 0x01, ///< return reference
  byval = 0x02, ///< return value if possible
  smart = 0x04, ///< return ref when lstruct
};              // xlf_prop

// type qualifier
enum class xlf_qlf : uint16_t {
  ref = 0x01,  ///< T&
  cref = 0x02, ///< const T&

  val = 0x04,  ///< T
  cval = 0x08, ///< const T

  cp = 0x10,    ///< T* const
  p2cv = 0x20,  ///< const T*
  cp2cv = 0x40, ///< const T* const
  vp = 0x80,    ///< T*

  arrayval = 0x100,  ///< T[]
  carrayval = 0x200, ///< const T[]
};                   // xlf_qlf

enum class xlf_gc : uint8_t {
  yes = 0x01,        ///< gc in lua
  no = 0x02,         ///< do not gc in lua
  yesArray = 0x04,   ///< for delete[]
  yesInplace = 0x08, ///< for in place new operator
};                   // xlf_gc

//--------------------------------------------------------------------------------------------------
constexpr auto XLB_UPVALUE_1 = 1;

//--------------------------------------------------------------------------------------------------
// function arguments type match
//--------------------------------------------------------------------------------------------------
#define XLB_E_AMI_SAME      0x00000000
#define XLB_E_AMI_DEFAULT   0x00000000
#define XLB_E_AMI_TRANSLATE 0x00000001

#define XLB_E_AMI_BAD    0x10000000
#define XLB_E_AMI_DENY   0x10000001
#define XLB_E_AMI_NONE   0x10000002
#define XLB_E_AMI_FEW    0x10000003
#define XLB_E_AMI_TOMUCH 0x10000003
#define xlb_ambad(ami)   (XLB_E_AMI_BAD <= (ami.match_result))
#define xlb_amgood(ami)  (XLB_E_AMI_BAD > (ami.match_result))

#define xlb_amfail(ami, e, msg)                                                                    \
  {                                                                                                \
    ami.match_result = e;                                                                          \
    ami.extmsg = "";                                                                               \
    ami.extmsg += __FILE__;                                                                        \
    ami.extmsg += " : ";                                                                           \
    ami.extmsg += to_string(__LINE__);                                                             \
    ami.extmsg += " : ";                                                                           \
    ami.extmsg += msg;                                                                             \
  }

struct xlb_ami {
  int match_result{XLB_E_AMI_SAME};
  int arg_index{1}; ///< one_based counter
  ///< how many argument push into lua stack, general equal to lua_gettop
  int arg_count{0}; ///< lua_gettop
  int default_count{0};
  int param_count{0};
  int rc{0};
  ///< storage "this" object
  void *obj{nullptr};
  ///< for left operator, if not nullptr, AT can storage value into this
  ///< address directly
  void *raw_left{nullptr};

  std::string extmsg; ///< for luaL_argerror
  xlb_ami(int ac) : arg_count(ac) {}
}; // xlb_ami

//--------------------------------------------------------------------------------------------------
// help struct
//--------------------------------------------------------------------------------------------------
using xlb_djy = void; // da jiang you

struct xpo_base_rier {};
struct xpo_base_vter {};
struct xpo_base_dfer {};

struct xpo_none {}; ///< return this when no po specify
struct xpo_base_readonly {};
struct xpo_readonly : public xpo_base_readonly {};

struct xpo_no_newinplace {};

//--------------------------------------------------------------------------------------------------
// xlb help template
//--------------------------------------------------------------------------------------------------
template <typename Base, bool IS_BASE_OF, typename... T> struct xlt_search_derived {};

template <typename Base, typename Typelist> struct xlt_getderived { using type = void; };

template <typename BASE> struct xlt_getderived<BASE, xlt_typelist<>> { using type = void; };

template <typename Base, typename Head, typename... Tail>
struct xlt_getderived<Base, xlt_typelist<Head, Tail...>> {
  using type = xlb_t<xlt_search_derived<Base, std::is_base_of_v<Base, Head>, Head, Tail...>>;
};

template <typename Base, typename Typelist>
using xlt_getderived_t = xlb_t<xlt_getderived<Base, Typelist>>;

//--------------------------------------------------------------------------------------------------
template <typename Base, typename Head, typename... Tail>
struct xlt_search_derived<Base, false, Head, Tail...> {
  using type = xlt_getderived_t<Base, xlt_typelist<Tail...>>;
};

template <typename Base, typename Head, typename... Tail>
struct xlt_search_derived<Base, true, Head, Tail...> {
  using type = Head;
};

//--------------------------------------------------------------------------------------------------
// MACRO
//--------------------------------------------------------------------------------------------------
#define luaL_reg        luaL_Reg
#define XLB_EXISTS_FLAG 0x1

#define XLB_META_PREFIX         "xlb_meta_"
#define XLB_STATEMENT_VALUE     1
#define XLB_META_PREFIX_ARRAY   "xlb_meta_array"
#define XLB_META_PREFIX_POINTER "xlb_meta_pointer"

#define XLB_SIV static inline void
#define XLB_SII static inline int
#define XLB_SIT static inline auto

//--------------------------------------------------------------------------------------------------
struct xlb_fmat_evthandler {
  using self_t = xlb_fmat_evthandler;
  using ptr_t = std::unique_ptr<xlb_fmat_evthandler>;
  using on_registry_t = int (*)(lua_State *L, self_t *);
  using on_getf_t = void *(*)(lua_State *L, self_t *);

  on_registry_t on_registry = nullptr;
  on_getf_t on_getf = nullptr;
  virtual ~xlb_fmat_evthandler(){};
};

//--------------------------------------------------------------------------------------------------
// @struct xlb_base_func_ptr
// @brief base struct for function pointer, this struct have no pointer type information
//--------------------------------------------------------------------------------------------------
struct xlb_base_func_ptr {
  using ptr_t = std::unique_ptr<xlb_base_func_ptr>;
  xlb_base_func_ptr() {}
  virtual int pushupvalue(lua_State *L, xlb_fmat_evthandler *evt = nullptr) { return 0; }
  virtual ~xlb_base_func_ptr() {}
}; // xlb_base_func_ptr
//

//--------------------------------------------------------------------------------------------------
// @struct xlb_propmate
// @brief class property pointer mate
//--------------------------------------------------------------------------------------------------
struct xlb_base_prop_ptr {
  using ptr_t = std::unique_ptr<xlb_base_prop_ptr>;
};

template <class Prop_t> struct xlb_propmate : public xlb_base_prop_ptr {
  Prop_t p2prop;
  xlb_propmate(Prop_t p = nullptr) : p2prop(p) {}

  XLB_SIT get(void *vmate) { return reinterpret_cast<xlb_propmate *>(vmate)->p2prop; }
};

template <typename Prop_t> auto xlb_makepropptr(Prop_t prop) {
  return xlb_base_prop_ptr::ptr_t(new xlb_propmate<Prop_t>(prop));
}

template <typename FT> inline auto xlb_makefuncptr(FT f) {
  return xlb_base_func_ptr::ptr_t(new xlb_fmate<FT>(f));
}

inline auto xlb_makefuncptr() { return xlb_base_func_ptr::ptr_t(nullptr); }

//--------------------------------------------------------------------------------------------------
// @struct xlb_prophandler
// @brief property include member data or member function
//--------------------------------------------------------------------------------------------------

struct xlb_prophandler {
  using ptr_t = xlb_base_prop_ptr::ptr_t;
  using func_t = int (*)(lua_State *, void *, xlf_prop);
  func_t f;
  mutable ptr_t propMate;

  xlb_prophandler() = default;
  xlb_prophandler(func_t _f, ptr_t &&ptr) : f(_f), propMate(std::move(ptr)) {}

  xlb_prophandler(const xlb_prophandler &r) {
    f = r.f;
    propMate = std::move(r.propMate);
  }

  xlb_prophandler &operator=(xlb_prophandler &&r) {
    f = r.f;
    propMate = std::move(r.propMate);
    return (*this);
  }

  int operator()(lua_State *L, xlf_prop flag) { return f(L, propMate.get(), flag); }

}; // xlb_prophandler

//--------------------------------------------------------------------------------------------------
// @struct xlb_funchandler
//--------------------------------------------------------------------------------------------------
struct xlb_funchandler {
  using func_t = lua_CFunction;

  func_t f = nullptr;
  mutable xlb_base_func_ptr::ptr_t ptr;

  xlb_funchandler() = default;
  xlb_funchandler(func_t _f, xlb_base_func_ptr::ptr_t &&_p) : f(_f) { ptr.reset(_p.release()); }

  xlb_funchandler(const xlb_funchandler &r) {
    f = r.f;
    ptr = std::move(r.ptr);
  }

  xlb_funchandler &operator=(xlb_funchandler &&r) {
    f = r.f;
    ptr = std::move(r.ptr);
    return (*this);
  }

  int operator()(lua_State *L, xlf_prop flag) {
    // called in __index
    lua_pushlightuserdata(L, ptr.get()); // upvalues
    lua_pushcclosure(L, f, 1);
    return 1;
  }
}; // xlb_funchandler

//--------------------------------------------------------------------------------------------------
struct xlb_base_agent {
  virtual void getarg(lua_State *L, xlb_ami &ami) {}
  virtual void pusharg(lua_State *L, int &rc) {}
  virtual ~xlb_base_agent() {}
};

//--------------------------------------------------------------------------------------------------
struct xlb_base_property {
  using self_t = xlb_base_property;
  using ptr_t = std::unique_ptr<self_t>;
  enum { unknown, readonly, readwrite, writeonly, function, bitfield };
  int type = unknown;
  xlb_base_property() = default;
  xlb_base_property(const xlb_base_property &) = default;
  self_t &operator=(xlb_base_property &&r) = default;
  virtual ~xlb_base_property(){};

  virtual int do_get(lua_State *L, xlf_prop flag) { return 0; }
  virtual int do_set(lua_State *L, xlf_prop flag) { return 0; }
  virtual int do_func(lua_State *L, xlf_prop flag) { return 0; }
};

//--------------------------------------------------------------------------------------------------
using xlb_regs_t = std::vector<luaL_reg>;
using xlb_cf_t = std::tuple<const char *, lua_CFunction, xlb_base_func_ptr::ptr_t>;
using xlb_cfs_t = std::vector<xlb_cf_t>;
using xlb_consts_t = std::vector<std::pair<const char *, int>>;
using xlb_member_t = std::unordered_map<string, std::unique_ptr<xlb_base_property>>;
using xlb_metas_t = std::vector<const char **>;
using xlb_meta_t = const char *;
using xlb_static_member_t = std::unordered_map<string, std::unique_ptr<xlb_base_agent>>;

//--------------------------------------------------------------------------------------------------
static int xlu_search_getter(lua_State *L, xlb_meta_t metaName, const xlb_metas_t &superNames) {
  int nfound = 0;
  for (auto &metaName : superNames) {
    auto top = lua_gettop(L);
    lua_getfield(L, LUA_REGISTRYINDEX, (*metaName));
    assert(lua_istable(L, -1));
    lua_pushstring(L, "__index");
    lua_rawget(L, -2);
    lua_remove(L, -2); // remove metatable

    lua_pushvalue(L, 1); // ud
    lua_pushvalue(L, 2); // k
    // XXX: manual call __index, instead using lua_gettable
    // since the value on the index 1 must be userdata
    lua_pcall(L, 2, 1, 0);

    if (top < lua_gettop(L)) {
      lua_settop(L, top + 1);
      nfound = 1;
      break;
    }
  }
  return nfound;
} // xlu_search_getter

//--------------------------------------------------------------------------------------------------
static int xlu_search_setter(lua_State *L, xlb_meta_t metaName, const xlb_metas_t &superNames) {
  int nfound = 0;
  for (auto &metaName : superNames) {
    auto top = lua_gettop(L);
    lua_getfield(L, LUA_REGISTRYINDEX, (*metaName)); // [metatable]
    assert(lua_istable(L, -1));

    lua_pushstring(L, "__newindex"); // [metatable, "__newindex"]
    lua_rawget(L, -2);               // [metatable, __newindex]
    lua_remove(L, -2);               // remove metatable

    lua_pushvalue(L, 1); // [1]=userdata
    lua_pushvalue(L, 2); // [2]=keyname
    lua_pushvalue(L, 3); // [3]=setvalue
    lua_pcall(L, 3, 1, 0);

    if (top < lua_gettop(L)) {
      lua_settop(L, top + 1);
      nfound = 1;
      break;
    }
  }
  return nfound;
} // xlu_search_setter

//--------------------------------------------------------------------------------------------------
// search super tree for metaName
//--------------------------------------------------------------------------------------------------
static bool xlu_checksuper(lua_State *L, int index, xlb_meta_t metaName) {
  //-1:xlb_super={...}
  std::vector<string> table_names;
  lua_pushnil(L);
  while (lua_next(L, index) != 0) {
    table_names.push_back(string(lua_tostring(L, -2)));
    lua_pop(L, 1);
  }
  while (!table_names.empty()) {
    string table_name = table_names.back();
    table_names.pop_back();
    if (table_name == metaName) {
      return true;
    } else {
      lua_getfield(L, LUA_REGISTRYINDEX, table_name.c_str());
      lua_pushstring(L, "xlb_super");
      lua_rawget(L, -2);
      if (lua_istable(L, -1)) {
        auto table_index = lua_gettop(L);
        lua_pushnil(L);
        while (lua_next(L, table_index) != 0) {
          table_names.push_back(string(lua_tostring(L, -2)));
          lua_pop(L, 1);
        }
      }
      lua_pop(L, 2);
    }
  }
  return false;
} // xlu_checksuper

//--------------------------------------------------------------------------------------------------
// xlb_meta value of userdata equal to metaName
// or userdata's ancient those metaName equal to metaName
//--------------------------------------------------------------------------------------------------
static bool xlu_checkudata(lua_State *L, int index, xlb_meta_t metaName) {
  assert(metaName != nullptr);
  bool checked = false;
  if (lua_isuserdata(L, index)) {
    lua_getmetatable(L, index);
    lua_pushstring(L, "xlb_meta");
    lua_rawget(L, -2);
    checked = (strcmp(metaName, lua_tostring(L, -1)) == 0);
    lua_pop(L, 1); // pop xlb_meta's value

    if (!checked) {
      lua_pushstring(L, "xlb_ancient");
      lua_rawget(L, -2);
      if (!lua_istable(L, -1)) {
        lua_pop(L, 1);
        lua_pushstring(L, "xlb_ancient");
        lua_newtable(L);
        lua_rawset(L, -3);
        lua_pushstring(L, "xlb_ancient");
        lua_rawget(L, -2);
      }
      lua_pushstring(L, metaName);
      lua_rawget(L, -2);
      checked = !lua_isnil(L, -1);
      lua_pop(L, 2);

      if (!checked) {
        lua_pushstring(L, "xlb_super");
        lua_rawget(L, -2);
        if (lua_istable(L, -1)) {
          checked = xlu_checksuper(L, lua_gettop(L), metaName);
        }
        lua_pop(L, 1); // xlb_super's value
        if (checked) {
          lua_pushstring(L, "xlb_ancient");
          lua_rawget(L, -2);
          lua_pushstring(L, metaName);
          lua_pushnumber(L, 1);
          lua_rawset(L, -3);
          lua_pop(L, 1);
        }
      }
    }
    lua_pop(L, 1); // pop metatable
  }
  return checked;
} // xlu_checkudata

//--------------------------------------------------------------------------------------------------
static void xlu_newobjmeta(
    lua_State *L, xlb_meta_t metaName, const xlb_regs_t &metaFuncs, const xlb_cfs_t &upvalueFuncs,
    const xlb_metas_t &superMetas) {
  // xlb_debug("%s\n", metaName);
  luaL_newmetatable(L, metaName); // XXX: push table on #-1
  if (1 < metaFuncs.size()) {
    luaL_setfuncs(L, &metaFuncs.front(), 0);
  }

  // set metatable.metatable to itself
  lua_pushvalue(L, -1);
  lua_setmetatable(L, -2);

  lua_pushstring(L, "xlb_meta");
  lua_pushstring(L, metaName);
  lua_rawset(L, -3);

  lua_pushstring(L, "xlb_ancient");
  lua_newtable(L);
  lua_rawset(L, -3);

  lua_pushstring(L, "xlb_super");
  lua_newtable(L);
  for (auto &super : superMetas) {
    assert(nullptr != *super); ///< require xlb_base_class<X>
    lua_pushstring(L, (*super));
    lua_pushnumber(L, XLB_EXISTS_FLAG);
    lua_rawset(L, -3);
  }
  lua_rawset(L, -3);

  /** XXX:class method with upvalues,
   * __index and __newindex are in metatable
   */
  for (auto &finfo : upvalueFuncs) {
    lua_pushstring(L, std::get<0>(finfo)); ///< [0]==function name
    auto upvalue_count = std::get<2>(finfo)->pushupvalue(L);
    lua_pushcclosure(L, std::get<1>(finfo), upvalue_count);
    lua_rawset(L, -3);
  }

  lua_pop(L, 1); // XXX:pop metatable in #1
} // xlu_newobjmeta

//--------------------------------------------------------------------------------------------------
static void xlu_newtypelib(
    lua_State *L, const char *typeName, xlb_regs_t &typeTable,
    const xlb_static_member_t &staticMember, int typeSize, int parentTableIndex) {
  if (0 != parentTableIndex) {
    lua_pushstring(L, typeName);
  }

  lua_createtable(L, 0, typeTable.size() - 1);
  luaL_setfuncs(L, &typeTable.front(), 0);

  {
    auto rc{0};
    auto top{lua_gettop(L)};
    for (auto &item : staticMember) {
      lua_pushstring(L, item.first.c_str());
      rc = 0;
      item.second->pusharg(L, rc);
      (1 == rc) ? lua_rawset(L, -3) : lua_settop(L, top);
    }
  }

  lua_pushvalue(L, -1);
  lua_setmetatable(L, -2); // XXX:meta itself

  lua_pushstring(L, "typesize");
  lua_pushinteger(L, typeSize);
  lua_rawset(L, -3);

  if (0 != parentTableIndex) {
    if (parentTableIndex < 0) {
      parentTableIndex -= 2;
    }
    lua_rawset(L, parentTableIndex);
  } else {
    lua_setglobal(L, typeName);
  }
} // xlu_newtypelib

//--------------------------------------------------------------------------------------------------
static void xlb_setwrapuservalue(lua_State *L, int index) {
  lua_pushlightuserdata(L, (void *)L);
  lua_setuservalue(L, index);
}

static bool xlb_testwrapuservalue(lua_State *L, int index) {
  lua_getuservalue(L, index);
  // xlb_debug( "(%p,%p)\n", lua_touserdata( L, -1 ), L );
  auto r = (lua_touserdata(L, -1) == L);
  lua_pop(L, 1);
  return r;
}

//--------------------------------------------------------------------------------------------------
// wrap obj those type is T=eT[N]
//--------------------------------------------------------------------------------------------------
template <typename Vt, typename ARR>
int xlb_pusharraypointer(lua_State *L, ARR v, xlf_gc gcf, void *place = nullptr) {
  using eT = std::remove_extent_t<ARR>;
  using w_t = xlb_wrap<eT[]>; // XXX: array's length save in wp.len

  auto qlf{xlf_qlf::arrayval};
  if constexpr (std::is_const_v<ARR>) {
    qlf = xlf_qlf::carrayval;
  }

  auto pointer{reinterpret_cast<std::add_pointer_t<eT[]>>(v)};
  // xlb_debug("(%p,eT=%s,%s)\n", pointer, typeid(eT).name(),
  // typeid(ARR).name());
  auto wp{w_t::getplace(L, place)};
  new (wp) w_t(pointer, gcf, qlf);
  w_t::template setmeta_array<Vt>(L, -1);
  wp->len = std::extent_v<ARR>; // XXX: bad
  // xlb_debug("(%p,%llu)\n", pointer, std::extent_v<ARR>);
  return {1};
} // xlb_pusharraypointer

//--------------------------------------------------------------------------------------------------
// wrap obj with value
//--------------------------------------------------------------------------------------------------
template <typename X> int xlb_pushobj(lua_State *L, X &v, xlf_gc gcf, void *place = nullptr) {
  using w_t = xlb_wrap<X>;
  auto wp = w_t::getplace(L, place);
  auto p = reinterpret_cast<X *>(&v);
  new (wp) w_t(p, gcf, xlf_qlf::val);
  w_t::setmeta_struct(L, -1);
  return {1};
} // xlb_pushobj

//--------------------------------------------------------------------------------------------------
// wrap obj those class have xlb_base_class<PT>
//--------------------------------------------------------------------------------------------------
template <typename X> int xlb_pushstructval(lua_State *L, X &v, xlf_gc gcf, void *place = nullptr) {
  using w_t = xlb_wrap<std::remove_const_t<X>>;

  xlf_qlf qlf = xlf_qlf::val;
  if constexpr (std::is_const_v<X>) {
    qlf = xlf_qlf::cval;
  }

  auto pointer{&v};
  auto wp{w_t::getplace(L, place)};
  new (wp) w_t(pointer, gcf, qlf);
  w_t::setmeta_struct(L, -1);
  return {1};
} // xlb_pushstructval

//--------------------------------------------------------------------------------------------------
// wrap obj those class have xlb_base_class<PT>
//--------------------------------------------------------------------------------------------------
template <typename X> int xlb_pushstructref(lua_State *L, X &v, xlf_gc gcf, void *place = nullptr) {
  using w_t = xlb_wrap<X>;
  auto pointer{&v};
  auto wp{w_t::getplace(L, place)};
  new (wp) w_t(pointer, gcf, xlf_qlf::ref);
  w_t::setmeta_struct(L, -1);
  return {1};
} // xlb_pushstructref

//--------------------------------------------------------------------------------------------------
// wrap obj those class have xlb_base_class<PT>
//--------------------------------------------------------------------------------------------------
template <typename X>
int xlb_pushstructref(lua_State *L, const X &v, xlf_gc gcf, void *place = nullptr) {
  auto pointer = &v;
  // XXX:using X but no const X
  using w_t = xlb_wrap<std::remove_cv_t<X>>;
  auto wp = w_t::getplace(L, place);
  new (wp) w_t(pointer, gcf, xlf_qlf::cref);
  w_t::setmeta_struct(L, -1);
  return {1};
} // xlb_pushstructref

//--------------------------------------------------------------------------------------------------
// wrap obj those class is not xlb_base_class<PT>
//--------------------------------------------------------------------------------------------------
template <typename P, typename AT> // P==const T*
int xlb_pushrefaspointer(
    lua_State *L, P pointer, xlf_gc gcf, void *place = nullptr,
    std::enable_if_t<is_p2cv_v<P>> * = 0) {
  using w_t = xlb_wrap<typename AT::type, AT>;
  auto wp = w_t::getplace(L, place);
  new (wp) w_t(pointer, gcf, xlf_qlf::cref);
  w_t::setmeta_pointer(L, -1);
  return {1};
} // xlb_pushrefaspointer

//--------------------------------------------------------------------------------------------------
// wrap obj those class is not xlb_base_class<PT>
//--------------------------------------------------------------------------------------------------
template <typename P, typename AT> // P==T*
int xlb_pushrefaspointer(
    lua_State *L, P pointer, xlf_gc gcf, void *place = nullptr,
    std::enable_if_t<!is_p2cv_v<P>> * = 0) {
  using w_t = xlb_wrap<typename AT::type, AT>;
  auto wp = w_t::getplace(L, place);
  new (wp) w_t(pointer, gcf, xlf_qlf::ref);
  w_t::setmeta_pointer(L, -1);
  return {1};
} // xlb_pushrefaspointer

//--------------------------------------------------------------------------------------------------
// xlb_base_wrap : wrap lightuserdata(pointer) which have xlb_base_class to user
// data
//--------------------------------------------------------------------------------------------------

struct xlb_base_wrap {
  xlf_gc gcFlag;
  xlf_qlf tQlf;
  xlb_base_wrap(xlf_gc gcf, xlf_qlf tqlf) : gcFlag(gcf), tQlf(tqlf) {}
  virtual void *getpointer() = 0;
  virtual int dereference(lua_State *L) { return 0; };
  virtual int lvaluereference(lua_State *L) { return 0; };
  virtual int pushaddress(lua_State *L) { return 0; };
  virtual int issametypeindex(const std::type_index &) = 0;
  virtual ~xlb_base_wrap() = default;
}; // xlb_base_wrap

inline auto xlb_wpispointer(xlb_base_wrap *wp) {
  return wp->tQlf >= xlf_qlf::cp && wp->tQlf <= xlf_qlf::vp;
}

inline auto xlb_wpisref(xlb_base_wrap *wp) {
  return wp->tQlf == xlf_qlf::ref || wp->tQlf == xlf_qlf::cref;
}

inline auto xlb_wpisconst(xlb_base_wrap *wp) {
  return wp->tQlf == xlf_qlf::cref || wp->tQlf == xlf_qlf::cval || wp->tQlf == xlf_qlf::carrayval;
}

inline auto xlb_wpisentity(xlb_base_wrap *wp) {
  return wp->tQlf == xlf_qlf::ref || wp->tQlf == xlf_qlf::val;
}

inline auto xlb_wpiscopyable(xlb_base_wrap *wp) {
  return wp->tQlf == xlf_qlf::ref || wp->tQlf == xlf_qlf::cref || wp->tQlf == xlf_qlf::val ||
         wp->tQlf == xlf_qlf::cval;
}

inline auto xlb_wpiscv(xlb_base_wrap *wp) {
  return wp->tQlf == xlf_qlf::p2cv || wp->tQlf == xlf_qlf::cp2cv;
}

inline auto xlb_wpisconstfeignpointer(xlb_base_wrap *wp) {
  return wp->tQlf == xlf_qlf::p2cv || wp->tQlf == xlf_qlf::cref || wp->tQlf == xlf_qlf::carrayval;
}

// inline auto xlb_wpcompaddr(xlb_base_wrap* wp) {
//    return wp->tQlf==xlf_qlf::cp
//        || wp->tQlf==xlf_qlf::p2cv
//        || wp->tQlf==xlf_qlf::cp2cv
//        || wp->tQlf==xlf_qlf::vp;
//}

//--------------------------------------------------------------------------------------------------

template <typename P, typename NU = std::enable_if_t<std::is_pointer_v<P>>>
XLB_SIT xlb_aspointer(lua_State *L, int index) {
  return reinterpret_cast<P>(lua_touserdata(L, index));
}

template <typename T> XLB_SIT xlb_touserdata(lua_State *L, int index) {
  return reinterpret_cast<T *>(lua_touserdata(L, index));
}

XLB_SIT xlb_tobasewrap(lua_State *L, int index) {
  xlb_base_wrap *wp{
      xlb_testwrapuservalue(L, index) ? reinterpret_cast<xlb_base_wrap *>(lua_touserdata(L, index))
                                      : nullptr};
  return wp;
}

template <typename T> XLB_SIT xlb_towrap(lua_State *L, int index) {
  xlb_wrap<T> *wp{
      xlb_testwrapuservalue(L, index) ? reinterpret_cast<xlb_wrap<T> *>(lua_touserdata(L, index))
                                      : nullptr};
  return wp;
}

template <typename T, typename Deref_AT = xlb_notpointer>
XLB_SIT xlb_testwrap(lua_State *L, int index) {
  using w_t = xlb_wrap<T, Deref_AT>;
  assert(xlb_base_class<T>::metaName);
  auto wp = reinterpret_cast<w_t *>(luaL_testudata(L, index, xlb_base_class<T>::metaName));
  return wp;
}

template <typename T> XLB_SIT xlb_testwrap(lua_State *L, int index, const char *meta) {
  using w_t = xlb_wrap<T>;
  auto wp = reinterpret_cast<w_t *>(luaL_testudata(L, index, meta));
  return wp;
}

template <typename T> auto xlb_toself(lua_State *L, int index) {
  auto wp = xlb_towrap<T>(L, index);
  assert(wp);
  auto pobj = reinterpret_cast<T *>(wp->getpointer());
  assert(pobj);
  return pobj;
}

//--------------------------------------------------------------------------------------------------

template <typename P, typename WP> XLB_SIT xlb_getwppointer(WP *wp) {
  assert(wp);
  return reinterpret_cast<P>(wp->getpointer());
}

template <typename T> XLB_SIT xlb_issametypeindex(xlb_base_wrap *wp) {
  return wp->issametypeindex(xlb_wrap<T>::typeidx);
}

//--------------------------------------------------------------------------------------------------
template <typename Vt, typename eT, typename WP> int xlu_arrayitem_setter(lua_State *L) { // ud,k,v
  if constexpr (!std::is_const_v<eT>) {
    constexpr const auto ud_index{1};
    constexpr const auto key_index{2};
    constexpr const auto val_index{3};

    auto wp{reinterpret_cast<WP *>(lua_touserdata(L, ud_index))}; // ud
    assert(wp);
    auto array_length{wp->len};

    auto item_index{lua_tointeger(L, key_index)};
    if (item_index > 0 && item_index <= array_length) {
      if (wp->tQlf == xlf_qlf::arrayval) {
        using PARR = std::add_pointer_t<eT[]>;
        auto p = xlb_getwppointer<PARR>(wp);
        assert(p);
        auto &arr = (*p);

        // xlb_debug( "(%p,%lld)\n", &arr, item_index );

        xlb_at<Vt, eT> v;
        xlb_ami item_ami{lua_gettop(L)};
        item_ami.arg_index = val_index;
        auto pointer{arr + item_index - 1};
        if constexpr (std::is_array_v<eT>) { // eT is array
          item_ami.raw_left = pointer;       // put value directively
        }
        v.getarg(L, item_ami);
        if constexpr (!std::is_array_v<eT>) {
          *pointer = v;
        }
      } else {
        /* do nothing for const */
      }
    }
  }
  return {0};
} // xlu_arrayitem_setter

//--------------------------------------------------------------------------------------------------
template <typename Vt, typename eT, typename WP> int xlu_arrayitem_getter(lua_State *L) { // ud,k
  constexpr const auto ud_index{1};
  constexpr const auto key_index{2};

  auto wp{reinterpret_cast<WP *>(lua_touserdata(L, ud_index))}; // ud
  auto array_length{wp->len};
  using PARR = std::add_pointer_t<eT[]>;
  auto p = xlb_getwppointer<PARR>(wp);

  auto rc{0};
  if (lua_isinteger(L, key_index)) {
    auto item_index{(size_t)lua_tointeger(L, key_index)};
    if (item_index > 0 && item_index <= array_length) {
      auto &arr = (*p);
      // xlb_debug( "(%p,%lld,eT=%s)\n", &arr, item_index, typeid(eT).name() );
      eT *pointer{arr + item_index - 1};
      xlb_at<Vt, eT> v{pointer};
      // xlb_debug( "(%p(%llu)[%lld],%s)\n", &arr, array_length, item_index,
      // typeid(decltype(v)).name() ); xlb_debug( "(%p,%s)\n", pointer,
      // typeid(eT).name() );
      v.pusharg(L, rc);
    } // else index out of bounds
  } else if (lua_isstring(L, key_index)) {
    auto key = lua_tostring(L, key_index);
    if (0 == strcmp(key, "len")) {
      lua_pushinteger(L, wp->len);
      rc += 1;
    } else if (0 == strcmp(key, "tostring")) {
      if constexpr (std::is_same_v<eT, char>) {
        lua_pushlstring(L, (const char *)p, wp->len);
        rc += 1;
      }
      if constexpr (std::is_same_v<eT, wchar_t>) {
        lua_pushlstring(L, (const char *)p, 2 * wp->len);
        rc += 1;
      }
    }
  }
  return rc;
} // xlu_arrayitem_getter

//--------------------------------------------------------------------------------------------------
template <typename eT> void xlu_arraymetaname(std::string &meta_name) {
  meta_name.clear();
  meta_name = XLB_META_PREFIX_ARRAY;
  meta_name += "(";
  if (std::is_const_v<eT>)
    meta_name += "const ";
  meta_name += typeid(std::remove_const_t<eT>).name();
  meta_name += "[])";
}

//--------------------------------------------------------------------------------------------------
template <typename Vt, typename eT, typename WP> int xlu_newarraylib(lua_State *L) {
  std::string meta_name;
  xlu_arraymetaname<eT>(meta_name);
  if (luaL_newmetatable(L, meta_name.c_str())) {
    xlb_regs_t metaFuncs{};
    metaFuncs.push_back({"__newindex", xlu_arrayitem_setter<Vt, eT, WP>});
    metaFuncs.push_back({"__index", xlu_arrayitem_getter<Vt, eT, WP>});
    metaFuncs.push_back({nullptr, nullptr});
    luaL_setfuncs(L, &metaFuncs.front(), 0);
    lua_pushvalue(L, -1);
    lua_setmetatable(L, -2);
  }
  return {1};
}

//--------------------------------------------------------------------------------------------------
template <typename T> void xlu_pointermetaname(std::string &meta_name) {
  meta_name.clear();
  meta_name = XLB_META_PREFIX_POINTER;
  meta_name += "(";
  if (std::is_const_v<T>)
    meta_name += "const ";
  if constexpr (is_complete_v<T>) {
    meta_name += typeid(std::remove_const_t<T>).name();
  } else {
    meta_name += "void";
  }
  meta_name += "*)";
}

template <typename Vt, typename T, typename WP> int xlu_newpointerlib(lua_State *L) {
  std::string meta_name;
  xlu_pointermetaname<T>(meta_name);
  // xlb_debug( "(%s)\n", meta_name.c_str() );
  if (luaL_newmetatable(L, meta_name.c_str())) {
    lua_pushstring(L, "__index");
    lua_pushvalue(L, -2);
    lua_rawset(L, -3);

    lua_pushstring(L, "xlb_meta");
    lua_pushstring(L, "xlb_meta_xlb_pointer");
    lua_rawset(L, -3);

    lua_pushstring(L, "__lightuserdata");
    lua_pushcfunction(L, WP::cf___lightuserdata);
    lua_rawset(L, -3);

    lua_pushstring(L, "__getaddress");
    lua_pushcfunction(L, WP::cf___getaddress);
    lua_rawset(L, -3);

    lua_pushstring(L, "__dereference");
    lua_pushcfunction(L, WP::cf___dereference);
    lua_rawset(L, -3);

    lua_pushstring(L, "__lvaluereference");
    lua_pushcfunction(L, WP::cf___lvaluereference);
    lua_rawset(L, -3);
  }
  return {1};
}

//--------------------------------------------------------------------------------------------------
static std::string xlu_getmetaname(lua_State *L, int index) {
  const char *meta_name{""};
  auto top{lua_gettop(L)};
  if (lua_getmetatable(L, index)) {
    lua_pushstring(L, "__name");
    lua_rawget(L, -2);
    meta_name = lua_tostring(L, -1);
  }
  lua_settop(L, top);
  return std::string{meta_name};
}

static bool xlu_checkmetaprefix(std::string &meta_name, const char *prefix) {
  return (std::string::npos != meta_name.find(prefix));
}

static bool xlu_checkmetaprefix(lua_State *L, int index, const char *prefix) {
  auto top{lua_gettop(L)};
  bool ret{false};
  if (lua_getmetatable(L, index)) {
    lua_pushstring(L, "__name");
    lua_rawget(L, -2);
    auto meta_name{lua_tostring(L, -1)};
    ret = (nullptr == meta_name) ? false : (nullptr != strstr(meta_name, prefix));
  }
  lua_settop(L, top);
  return ret;
}

static auto xlb_tobasewphaveprefix(lua_State *L, int index, const char *prefix) {
  return (xlu_checkmetaprefix(L, index, XLB_META_PREFIX_POINTER)) ? xlb_tobasewrap(L, index)
                                                                  : (xlb_base_wrap *)nullptr;
}

//--------------------------------------------------------------------------------------------------
template <unsigned N> struct xlb_assignarrary {
  template <typename LEFT, typename RIGHT>
  XLB_SIV go(LEFT &left, RIGHT &right, bool isMoved = false) {
    // using e_t = decltype( left[ 0 ] );
    using e_t = std::remove_extent_t<LEFT>;
    if constexpr (!std::is_const_v<e_t>) {
      // xlb_debug("(%s)\n", typeid(right).name());
      if constexpr (std::is_array_v<e_t>) {
        constexpr const auto M{std::extent_v<e_t, 0>};
        for (auto idx = 0; idx < M; ++idx) {
          xlb_assignarrary<M>::go(left[idx], right[idx], isMoved);
        }
      } else {
        for (auto idx = 0; idx < N; ++idx) {
          (isMoved) ? left[idx] = std::move(right[idx]) : left[idx] = right[idx];
        }
      }
    }
  }
};

//--------------------------------------------------------------------------------------------------
// @struct xlb_wrap
// wrap object's address as ud, and then we can set metatable on it.
//--------------------------------------------------------------------------------------------------

template <typename T, typename Deref_AT, typename WRO_DEL> class xlb_wrap : public xlb_base_wrap {
  using type = T;
  using deref_at = Deref_AT;
  using delete_t = WRO_DEL;

public:
  inline static const auto typeidx{std::type_index(typeid(xlb_completetype_t<T>))};

  T *pointer{nullptr};
  size_t len{0}; // for array

  xlb_wrap(const T *p, xlf_gc gcf, xlf_qlf tqlf) : xlb_base_wrap(gcf, tqlf) {
    if constexpr (std::is_function_v<T>) {
      gcf = xlf_gc::no;
      pointer = p;
    } else {
      pointer = const_cast<T *>(p); // writable judged by tQlf
    }
  }

public:
  virtual ~xlb_wrap() {
    // xlb_debug("%s,gcFlag=%u\n", typeid(T).name(), (unsigned)gcFlag);
    if (!pointer)
      return;
    if constexpr (!std::is_void_v<T> && is_complete_v<T>) {
      if constexpr (!std::is_function_v<T> && !std::is_abstract_v<T>) {
        if (gcFlag == xlf_gc::yes) {
          assert(pointer);
          WRO_DEL()(pointer);
        } else {
          if constexpr (std::is_same_v<std::default_delete<T>, WRO_DEL>) {
            if constexpr (std::is_array_v<T>) {
              if (gcFlag == xlf_gc::yesArray) {
                assert(pointer);
                std::default_delete<T[]>()(pointer);
              }
            } else {
              if constexpr (std::is_destructible_v<T> && !std::is_pod_v<T>) {
                if (gcFlag == xlf_gc::yesInplace) {
                  assert(pointer);
                  pointer->~T();
                }
              }
            }
          }
        }
      }
    }
  } // ~xlb_wrap

  void freeit(void (*freef)(T *)) {
    freef(pointer);
    pointer = nullptr;
  }

  //// T (*)(wp) { return (*pointer); }
  virtual int dereference(lua_State *L) override {
    int rc{0};
    // only pointer have this functional, identify by deref_at!=xlb_notpointer
    // example: T==int, deref_at==xlb_lintegral<int>, deref_at::type==int,
    if constexpr (!std::is_same_v<deref_at, xlb_notpointer>) {
      if constexpr (!std::is_same_v<xlb_t<deref_at>, void> && is_complete_v<T>) {
        if constexpr (!std::is_function_v<T> && !std::is_abstract_v<T>) {
          assert(pointer);
          deref_at at(*pointer);
          at.pusharg(L, rc);
        }
      }
    } // is pointer
    return rc;
  }

  //// T& (*)(wp) { return (*pointer); }
  virtual int lvaluereference(lua_State *L) override {
    int rc{0};
    if constexpr (!std::is_same_v<deref_at, xlb_notpointer>) {
      if constexpr (
          !std::is_same_v<xlb_t<deref_at>, void> && !std::is_same_v<xlb_t<deref_at>, const void>) {
        using origin_t = xlb_t<deref_at>;                    // T
        using ref_t = std::add_lvalue_reference_t<origin_t>; // T&
        using ref_at = xlb_at<typename deref_at::vter, ref_t>;
        using pointer_t = std::add_pointer_t<origin_t>; // T*
        auto wp = xlb_touserdata<xlb_base_wrap>(L, 1);
        auto p = xlb_getwppointer<pointer_t>(wp);
        ref_at ref(p);
        ref.pusharg(L, rc);
      }
    } // is pointer
    return rc;
  }

  //// T* (*)(wp) { return (pointer); }
  virtual int pushaddress(lua_State *L) override {
    int rc{0};
    if constexpr (std::is_pointer_v<T>) {
      using unref1_t = std::remove_pointer_t<T>;
      if constexpr (std::is_pointer_v<unref1_t>) {
        // nothing to do while T==T**
      } else {
        using p_t = std::add_pointer_t<T>;
        xlb_at<xlb_vter, p_t> ptto(pointer); // XXX
        ptto.pusharg(L, rc);
      }
    } else {
      if constexpr (std::is_array_v<T>) { // T[]
        // XXX: typeof (pointer) == T[] *
        using p_t = std::decay_t<T>;
        xlb_at<xlb_vter, p_t> ptto(*pointer); // *pointer=T[]
        ptto.pusharg(L, rc);
      } else {
        using p_t = std::add_pointer_t<T>;
        xlb_at<xlb_vter, p_t> ptto(pointer); // XXX
        ptto.pusharg(L, rc);
      }
    }
    // xlb_debug( "(%s)\n", typeid( T ).name() );
    return rc;
  }

  virtual int issametypeindex(const std::type_index &r) override { return typeidx == r; }
  virtual void *getpointer() override { return (void *)pointer; }
  T *operator->() const { return pointer; }

  // T (*)(wp) { return (*pointer); }
  static int cf___dereference(lua_State *L) {
    auto rc{0};
    if constexpr (!std::is_same_v<deref_at, xlb_notpointer>) {
      auto wp = xlb_touserdata<xlb_base_wrap>(L, 1);
      if (wp && (xlb_wpispointer(wp) || xlb_wpisref(wp))) {
        rc = wp->dereference(L);
      } else {
        rc = luaL_argerror(L, 1, "pointer expected.");
      }
    }
    return rc;
  }

  static int cf___getaddress(lua_State *L) {
    auto rc{0};
    auto wp = xlb_touserdata<xlb_base_wrap>(L, 1);
    if (wp) {
      rc = wp->pushaddress(L);
    } else {
      xlb_debug("warning: function called with self\n");
    }
    return rc;
  }

  static int cf___lightuserdata(lua_State *L) {
    auto rc{1};
    auto wp = xlb_touserdata<xlb_base_wrap>(L, 1);
    (wp) ? lua_pushlightuserdata(L, wp->getpointer()) : lua_pushnil(L);
    return rc;
  }

  // T& (*)(wp) { return (*pointer); }
  static int cf___lvaluereference(lua_State *L) {
    auto rc{0};
    if constexpr (!std::is_same_v<deref_at, xlb_notpointer>) {
      auto wp = xlb_touserdata<xlb_base_wrap>(L, 1);
      // xlb_debug( "%p, %d\n", wp, xlb_wpisref( wp ) );
      if (wp && (xlb_wpisref(wp) || xlb_wpispointer(wp))) {
        rc = wp->lvaluereference(L);
      } else {
        rc = luaL_argerror(L, 1, "pointer expected.");
      }
    }
    return rc;
  }

  static void setmeta_pointer(lua_State *L, int index) {
    xlu_newpointerlib<xlb_vter, T, xlb_wrap>(L);
    lua_setmetatable(L, (index < 0) ? --index : index); // ud.metatable = metatable
    xlb_setwrapuservalue(L, index);
  }

  static void setmeta_struct(lua_State *L, int index, lua_Number N = 0) {
    auto obj_meta = xlb_base_class<T>::metaName;
    if (obj_meta != nullptr) {
      luaL_newmetatable(L, obj_meta);                     // s: -2(ud), -1(metatable)
      lua_setmetatable(L, (index < 0) ? --index : index); // ud.metatable = metatable
      xlb_setwrapuservalue(L, index);
    } else {
      if constexpr (is_complete_v<T>) {
        xlb_debug("(%s) type need binded first\n", typeid(T).name());
      }
      luaL_error(L, "class need binded first");
    }
  }

  template <typename Vt> static void setmeta_array(lua_State *L, int index, lua_Number N = 0) {
    using eT = std::remove_extent_t<T>;
    // xlb_debug("(eT=%s,%s)\n", typeid(eT).name(), typeid(T).name());
    xlu_newarraylib<Vt, eT, xlb_wrap>(L);
    lua_setmetatable(L, (index < 0) ? --index : index); // ud.metatable = metatable
    xlb_setwrapuservalue(L, index);
  }

  static auto getplace(lua_State *L, void *place) {
    auto p = place ? place : lua_newuserdata(L, sizeof(xlb_wrap));
    return reinterpret_cast<xlb_wrap *>(p);
  }

}; // xlb_wrap

//--------------------------------------------------------------------------------------------------
// xlb_pushpointer : (T* const) type pointer as userdata
//--------------------------------------------------------------------------------------------------
template <typename P, typename Deref_AT> // P=T * const
int xlb_pushpointer(
    lua_State *L, P pointer, void *place = nullptr, std::enable_if_t<is_cp_v<P>> * = 0) {
  using w_t = xlb_wrap<std::remove_pointer_t<P>, Deref_AT>;
  auto wp = w_t::getplace(L, place);
  new (wp) w_t(pointer, xlf_gc::no, xlf_qlf::cp);
  w_t::setmeta_pointer(L, -1);
  // xlb_debug("(0x%p)\n", pointer);
  return {1};
}

//--------------------------------------------------------------------------------------------------
// xlb_pushpointer : (T*) type pointer as userdata
//--------------------------------------------------------------------------------------------------
template <typename P, typename Deref_AT> // P=T*
int xlb_pushpointer(
    lua_State *L, P pointer, void *place = nullptr,
    std::enable_if_t<!is_p2cv_v<P> && is_vp_v<P>> * = 0) {
  // xlb_debug("(%s)\n", typeid(P).name());
  using w_t = xlb_wrap<std::remove_pointer_t<P>, Deref_AT>;
  auto wp = w_t::getplace(L, place);
  new (wp) w_t(pointer, xlf_gc::no, xlf_qlf::vp);
  w_t::setmeta_pointer(L, -1);
  return {1};
}

//--------------------------------------------------------------------------------------------------
// xlb_pushpointer : (const T*) type pointer as userdata
//--------------------------------------------------------------------------------------------------
template <typename P, typename Deref_AT> // P=const T *
int xlb_pushpointer(
    lua_State *L, P pointer, void *place = nullptr, std::enable_if_t<is_p2cv_v<P>> * = 0) {
  // xlb_debug("(0x%p)\n", pointer);
  using w_t = xlb_wrap<std::remove_pointer_t<P>, Deref_AT>;
  auto wp = w_t::getplace(L, place);
  new (wp) w_t(pointer, xlf_gc::no, xlf_qlf::p2cv);
  w_t::setmeta_pointer(L, -1);
  return {1};
}

//--------------------------------------------------------------------------------------------------
// xlb argument agent
//--------------------------------------------------------------------------------------------------
template <typename T> struct xlb_selfagent {
  XLB_SIV getarg(lua_State *L, xlb_ami &ami) {
    auto extmsg{"xlb: invalid self"};
    auto wp{xlb_towrap<T>(L, 1)}; // assert(1 == ami.arg_index)
    auto pobj{(T *)nullptr};
    if (wp && (!xlb_wpisconst(wp))) {
      pobj = xlb_getwppointer<T *>(wp);
    } else {
      extmsg = "xlb: nonconst object expected";
    }
    if (pobj) {
      ami.obj = pobj;
      ++ami.arg_index;
    } else {
      xlb_amfail(ami, XLB_E_AMI_BAD, extmsg);
    }
  }
};

template <typename T> struct xlb_selfagent<const T> {
  XLB_SIV getarg(lua_State *L, xlb_ami &ami) {
    if (auto pobj{xlb_toself<T>(L, 1)}) {
      ami.obj = pobj;
      ++ami.arg_index;
    } else {
      xlb_amfail(ami, XLB_E_AMI_BAD, "xlb: invalid self");
    }
  }
};

//--------------------------------------------------------------------------------------------------
// xlb_ignore
//--------------------------------------------------------------------------------------------------
struct xlb_ignore {
  XLB_SIV getarg(lua_State *, xlb_ami &ami) {
    // xlb_debug("(%d)\n", ami.arg_index);
    if (ami.arg_count >= ami.arg_index) {
      ++ami.arg_index;
    }
  }
};

//--------------------------------------------------------------------------------------------------
// xlb_lpointer
//--------------------------------------------------------------------------------------------------

template <typename Vt, typename Dtor>
struct xlb_lpointer<Vt, void *, void *, Dtor> : public xlb_base_agent // void*
{
  using vter = Vt;
  using type = void *;
  using pointer_t = void *;
  using deref_t = void;
  using delete_t = Dtor;

  pointer_t pointer;

  xlb_lpointer(void *p = nullptr) { pointer = (void *)p; }
  xlb_lpointer &operator=(void *p) {
    pointer = p;
    return (*this);
  }
  operator void *() { return pointer; }

  void getarg(lua_State *L, xlb_ami &ami) override {
    pointer = nullptr;
    // xlb_debug("(0x%p)\n", this);
    auto got{false};
    if (auto wp{xlb_tobasewphaveprefix(L, ami.arg_index, XLB_META_PREFIX_POINTER)}) {
      if (xlb_issametypeindex<void>(wp)) {
        if (wp->tQlf == xlf_qlf::vp) { // T*
          pointer = xlb_getwppointer<pointer_t>(wp);
          got = true;
        }
      }
    }
    // RULE: accept nil as nullptr
    if (!got) {
      if (lua_isnil(L, ami.arg_index)) {
        pointer = nullptr;
        got = true;
      }
    }
    if (!got && lua_isuserdata(L, ami.arg_index)) {
      // accept lightuserdata
      pointer = lua_touserdata(L, ami.arg_index);
      got = true;
    }
    if (got) {
      ++ami.arg_index;
    } else {
      xlb_amfail(ami, XLB_E_AMI_BAD, "wrong type, void* expected");
    }
  }

  void pusharg(lua_State *L, int &rc) override {
    using deref_at = xlb_at<Vt, deref_t>;
    // xlb_debug("(%s)\n", typeid(deref_t).name());
    rc += xlb_pushpointer<void *, deref_at>(L, pointer);
  }
}; // xlb_lpointer<Vt, void*, void*>

//--------------------------------------------------------------------------------------------------
template <typename Vt, typename Dtor>
struct xlb_lpointer<Vt, const void *, const void *, Dtor> : public xlb_base_agent // const void*
{
  using vter = Vt;
  using type = const void *;
  using pointer_t = const void *;
  using deref_t = std::remove_pointer_t<type>;
  using delete_t = Dtor;

  pointer_t pointer;

  xlb_lpointer(pointer_t p = nullptr) : pointer(p) {}
  xlb_lpointer &operator=(pointer_t p) {
    pointer = p;
    return (*this);
  }
  operator pointer_t() { return pointer; }

  void getarg(lua_State *L, xlb_ami &ami) override {
    pointer = nullptr;
    // xlb_debug("(0x%p)\n", this);
    auto got{false};
    if (auto wp{xlb_tobasewphaveprefix(L, ami.arg_index, XLB_META_PREFIX_POINTER)}) {
      if (xlb_issametypeindex<const void>(wp)) {
        if (wp->tQlf == xlf_qlf::vp) { // T*
          pointer = xlb_getwppointer<pointer_t>(wp);
          got = true;
        }
      }
    }
    // RULE: accept nil as nullptr
    if (!got) {
      if (lua_isnil(L, ami.arg_index)) {
        pointer = nullptr;
        got = true;
      }
    }
    if (got) {
      ++ami.arg_index;
    } else {
      xlb_amfail(ami, XLB_E_AMI_BAD, "wrong type, const void* expected");
    }
  }

  void pusharg(lua_State *L, int &rc) override {
    using deref_at = xlb_at<Vt, deref_t>;
    // xlb_debug("(%s)\n", typeid(deref_t).name());
    rc += xlb_pushpointer<pointer_t, deref_at>(L, pointer);
  }
}; // xlb_lpointer<Vt, const void*, const void*>

//--------------------------------------------------------------------------------------------------
template <typename Vt, typename T, typename U, typename Dtor>
struct xlb_lpointer<Vt, T *, U, Dtor> : public xlb_base_agent // T* or T&
{
  using vter = Vt;
  using type = T *;
  using pointer_t = T *;
  using reference_t = T &;
  using deref_t = std::remove_pointer_t<type>;
  using delete_t = Dtor;

  pointer_t pointer;

  xlb_lpointer(pointer_t p = nullptr) { pointer = (T *)p; }
  xlb_lpointer(T &&v) { pointer = &v; }
  xlb_lpointer &operator=(pointer_t p) {
    pointer = p;
    return (*this);
  }
  operator pointer_t() { return pointer; }
  // operator reference_t() {
  //   assert(pointer);
  //   return *pointer;
  // }

  void getarg(lua_State *L, xlb_ami &ami) override {
    pointer = nullptr;
    // XXX:maybe we get the pointer but it's value equal nullptr
    auto got{false};
    // xlb_debug("\n");

    if constexpr (std::is_reference_v<U>) { // U==T&
      // xlb_dbg();
      auto wp = xlb_towrap<T>(L, ami.arg_index);
      // xlb_debug("(%p,%d)\n", wp, xlb_issametypeindex<T>(wp));
      if (wp && xlb_issametypeindex<T>(wp) &&
          (wp->tQlf == xlf_qlf::val || wp->tQlf == xlf_qlf::ref)) {
        // accept T (not const T) as T&
        pointer = xlb_getwppointer<pointer_t>(wp);
        // xlb_debug("%p\n", pointer);
        got = true;
      }
    }

    if (!got) {
      // xlb_debug("(0x%p)\n", this);
      // xlb_dbg();
      if (auto wp{xlb_tobasewphaveprefix(L, ami.arg_index, XLB_META_PREFIX_POINTER)}) {
        if (xlb_issametypeindex<T>(wp)) {
          if (wp->tQlf == xlf_qlf::vp) { // T*
            pointer = xlb_getwppointer<pointer_t>(wp);
            got = true;
          }
        }
      }
    }
    if (!got) {
      // xlb_dbg();
      if constexpr (std::is_same_v<T, char>) {
        if (lua_type(L, ami.arg_index) == LUA_TSTRING) {
          pointer = const_cast<char *>(lua_tostring(L, ami.arg_index));
          got = true;
        }
      }
      if constexpr (std::is_same_v<T, wchar_t>) {
        if (lua_type(L, ami.arg_index) == LUA_TSTRING) {
          pointer = reinterpret_cast<wchar_t *>(const_cast<char *>(lua_tostring(L, ami.arg_index)));
          got = true;
        }
      }
      if constexpr (std::is_function_v<T>) {
        using cbf_t = xlb_cbf<T *>; // TODO: no PO
        auto wp = xlb_tobasewrap(L, ami.arg_index);
        if (wp && xlb_issametypeindex<cbf_t>(wp)) {
          // xlb_debug("(%s,0x%p)\n", typeid(T).name(), wp);
          auto p = reinterpret_cast<cbf_t *>(wp->getpointer());
          // XXX:temporary update static member
          // solve multi cbf using static member problem
          p->updatestatic(L);
          pointer = &cbf_t::cbf_agent;
          got = true;
        }
      }
    }

    if (!got) { // maybe memory block, such as return from malloc function
      auto wp{xlb_tobasewrap(L, ami.arg_index)};
      if (wp) {
        if (!xlb_wpisconst(wp)) {
          pointer = xlb_getwppointer<T *>(wp); // XXX:size must meet
          got = true;
          // xlb_debug( "%p\n", pointer );
        } else {
          // xlb_debug( "%p\n", pointer );
        }
      } else {
        // not wp, but userdata such as lightuserdata
        if (lua_isuserdata(L, ami.arg_index)) {
          pointer = xlb_aspointer<pointer_t>(L, ami.arg_index);
          got = true;
          // xlb_debug( "%p\n", pointer );
        }
      }
    }

    // RULE: because U&, do not accept nil as nullptr
    if constexpr (!std::is_reference_v<U>) { // U==T*
      // RULE: accept nil as nullptr
      if (!got) {
        if (lua_isnil(L, ami.arg_index)) {
          pointer = nullptr;
          got = true;
        }
      }
    }

    // xlb_debug("(%d,0x%p)\n", got, pointer);
    if (got) {
      ++ami.arg_index;
    } else {
      if constexpr (debug_mode) {
        using TT = xlb_completetype_t<T>;
        xlb_debug("(%s)\n", typeid(TT).name());
      }
      xlb_amfail(ami, XLB_E_AMI_BAD, "wrong type, T* or T& expected");
    }
  } // getarg

  void pusharg(lua_State *L, int &rc) override {
    using deref_at = xlb_at<Vt, deref_t>;
    // xlb_debug("(%s)\n", typeid(deref_t).name());
    if constexpr (std::is_reference_v<U>) {       // U==T&
      if constexpr (is_lstruct_v<Vt, deref_at>) { // deref_at==xlb_lstruct<...>
        // xlb_debug("(0x%p)\n", this);
        assert(pointer);
        rc += xlb_pushstructref(L, (*pointer), xlf_gc::no);
      } else {
        // xlb_debug("(0x%p)\n", this);
        rc += xlb_pushrefaspointer<pointer_t, deref_at>(L, pointer, xlf_gc::no);
      }
    } else {
      // xlb_debug("(%s,%s)\n", typeid(pointer_t).name(), typeid(deref_at).name());
      // RULE: when U==T*, push nullptr as nil
      if (pointer == nullptr) {
        lua_pushnil(L);
        rc += 1;
      } else {
        rc += xlb_pushpointer<pointer_t, deref_at>(L, pointer);
      }
    }
  } // putarg
};  // xlb_lpointer<T*, U>

//--------------------------------------------------------------------------------------------------
template <typename Vt, typename T, typename U, typename Dtor>
struct xlb_lpointer<Vt, T *const, U, Dtor> : public xlb_base_agent // T *const
{
  using vter = Vt;
  using type = T *const;
  using pointer_t = T *const;
  using deref_t = std::remove_pointer_t<type>;
  using delete_t = Dtor;

  T *pointer; // no const

  xlb_lpointer(pointer_t p = nullptr) : pointer(p) {}
  operator pointer_t() { return pointer; }

  void getarg(lua_State *L, xlb_ami &ami) override {
    auto got{false};
    if (auto wp{xlb_tobasewphaveprefix(L, ami.arg_index, XLB_META_PREFIX_POINTER)}) {
      if (xlb_wpispointer(wp)) {
        if constexpr (!std::is_const_v<T>) {
          if (!xlb_wpiscv(wp)) {
            pointer = xlb_getwppointer<pointer_t>(wp);
            got = true;
          }
        }
      } else {
        pointer = xlb_getwppointer<pointer_t>(wp);
        got = true;
      }
    }

    // RULE: accept nil as nullptr
    if (!got) {
      if (lua_isnil(L, ami.arg_index)) {
        pointer = nullptr;
        got = true;
      }
    }

    if (got) {
      ++ami.arg_index;
    } else {
      xlb_amfail(ami, XLB_E_AMI_BAD, "const pointer expected.");
    }
  }

  void pusharg(lua_State *L, int &rc) override {
    using deref_at = xlb_at<Vt, deref_t>;
    if (pointer == nullptr) {
      lua_pushnil(L);
      rc += 1;
    } else {
      rc += xlb_pushpointer<pointer_t, deref_at>(L, pointer);
      // xlb_debug( "(0x%p)\n", this);
    }
  }
}; // xlb_lpointer<Vt, T* const, U>

//--------------------------------------------------------------------------------------------------
template <typename Vt, typename T, typename U, typename Dtor>
struct xlb_lpointer<Vt, const T *, U, Dtor> : public xlb_base_agent // const T*, const T&
{
  using vter = Vt;
  using type = const T *;
  using pointer_t = const T *;
  using deref_t = std::remove_pointer_t<type>;
  using delete_t = Dtor;

  pointer_t pointer;

  xlb_lpointer(pointer_t p = nullptr) : pointer(p) {}

  // std::move(const T&) === const T
  template <typename CONST_REF>
  xlb_lpointer(CONST_REF &&r, std::enable_if_t<!std::is_pointer_v<CONST_REF>> * = 0)
      : pointer(&r) {}

  operator const T &() {
    assert(pointer);
    xlb_debug("(0x%p)\n", pointer);
    return (*pointer);
  }
  operator pointer_t() { return pointer; }

  void getarg(lua_State *L, xlb_ami &ami) override {
    bool got{false};
    pointer = nullptr;
    // xlb_debug("%s\n", typeid(T).name());
    if constexpr (std::is_reference_v<U>) {
      // accept const T& or T& or const T or T
      auto wp = xlb_testwrap<T>(L, ami.arg_index);
      // xlb_debug("%s\n", typeid(T).name());
      if (wp && xlb_wpiscopyable(wp)) {
        pointer = xlb_getwppointer<pointer_t>(wp);
        got = true;
      }
    } else {
      // accept T* or const T*
      if (auto wp{xlb_tobasewphaveprefix(L, ami.arg_index, XLB_META_PREFIX_POINTER)}) {
        if (xlb_issametypeindex<T>(wp)) {
          pointer = xlb_getwppointer<pointer_t>(wp);
          got = true;
        }
      }
      // xlb_debug("(%s,%d,%p)\n", typeid(T).name(), got, pointer);
    }
    if (!got) {
      auto wp = xlb_tobasewrap(L, ami.arg_index);
      if (wp && xlb_wpisconstfeignpointer(wp)) { // take(pointer,reference,array) as pointer
        pointer = xlb_getwppointer<pointer_t>(wp);
        got = true;
      }
      if constexpr (std::is_same_v<T, char>) {
        if (lua_type(L, ami.arg_index) == LUA_TSTRING) {
          pointer = const_cast<char *>(lua_tostring(L, ami.arg_index));
          got = true;
        }
      }
      if constexpr (std::is_same_v<T, wchar_t>) {
        auto tp = lua_type(L, ami.arg_index);
        if (tp == LUA_TSTRING) {
          pointer = reinterpret_cast<wchar_t *>(const_cast<char *>(lua_tostring(L, ami.arg_index)));
          got = true;
        } else if (tp == LUA_TNIL) {
          pointer = nullptr;
          got = true;
        }
      }
    }
    // RULE: because U&, do not accept nil as nullptr
    if constexpr (!std::is_reference_v<U>) { // U==T*
      // RULE: accept nil as nullptr
      if (!got) {
        if (lua_isnil(L, ami.arg_index)) {
          pointer = nullptr;
          got = true;
        }
      }
    }

    if (got) {
      ++ami.arg_index;
    } else {
      if constexpr (debug_mode) {
        xlb_debug("(%s)\n", typeid(type).name());
      }
      xlb_amfail(ami, XLB_E_AMI_BAD, "wrong type");
    }
  }

  void pusharg(lua_State *L, int &rc) override {
    using deref_at = xlb_at<Vt, deref_t>;
    if constexpr (std::is_reference_v<U>) {
      if constexpr (is_lstruct_v<Vt,
                                 deref_at>) { // deref_at==xlb_lstruct<const T>
        // xlb_debug("(0x%p)\n", this);
        assert(pointer);
        auto &v = (*pointer); // const T&
        rc += xlb_pushstructref(L, v, xlf_gc::no);
      } else {
        // xlb_debug("(0x%p)\n", this);
        rc += xlb_pushrefaspointer<pointer_t, deref_at>(L, pointer, xlf_gc::no);
      }
    } else {
      if (pointer == nullptr) {
        lua_pushnil(L);
        rc += 1;
      } else {
        rc += xlb_pushpointer<pointer_t, deref_at>(L, pointer);
      }
      // xlb_debug("(0x%p)\n", this);
    }
  }
}; // xlb_lpointer<const T*, U> or const T&

//--------------------------------------------------------------------------------------------------
template <typename Vt, typename Dtor>
struct xlb_lpointer<Vt, const char *, const char *, Dtor> : public xlb_base_agent {
  using vter = Vt;
  using type = const char *;
  using pointer_t = const char *;
  using deref_t = std::remove_pointer_t<type>;
  using delete_t = Dtor;

  pointer_t pointer;

  xlb_lpointer(pointer_t p = nullptr) : pointer(p) {}
  xlb_lpointer &operator=(pointer_t p) {
    pointer = p;
    return (*this);
  }
  operator pointer_t() const { return pointer; }

  void getarg(lua_State *L, xlb_ami &ami) override {
    pointer = lua_tostring(L, ami.arg_index);
    ++ami.arg_index;
  }

  void pusharg(lua_State *L, int &rc) override {
    // If pointer is nullptr, pushes nil and returns  nullptr.
    lua_pushstring(L, pointer);
    ++rc;
  }
}; // xlb_lpointer<const char*>

//--------------------------------------------------------------------------------------------------
template <typename Vt> struct xlb_lstruct<Vt, void> : public xlb_base_agent {
  using vter = Vt;
  using type = void;
};

template <typename Vt> struct xlb_lstruct<Vt, const void> : public xlb_base_agent {
  using vter = Vt;
  using type = const void;
};

//--------------------------------------------------------------------------------------------------
// xlb_lstruct for xlb_base_class<T>
// agent for T v, do not copy the object in the lua, just keep it's address
//--------------------------------------------------------------------------------------------------
template <typename Vt, typename T> struct xlb_lstruct : public xlb_base_agent {
  using vter = Vt;
  using type = T;
  using pointer_t = T *;

  pointer_t pointer{nullptr};
  bool isMoved{false};

  xlb_lstruct(T *p = nullptr) : pointer((T *)p) {}
  xlb_lstruct(T &v) : pointer(&v) {}
  xlb_lstruct(T &&v) {
    pointer = &v;
    isMoved = true;
    // xlb_debug("(0x%p)\n", pointer);
  }
  operator T &() {
    assert(pointer);
    return (*pointer);
  }

  void getarg(lua_State *L, xlb_ami &ami) override {
    pointer = nullptr;
    assert(xlb_base_class<T>::metaName != nullptr);

    // when T's AT==xlb_lstruct then wp<T&>.meta==wp<T>.meta
    auto wp = xlb_testwrap<T>(L, ami.arg_index);

    xlb_debug("\n");
    if (wp && xlb_wpiscopyable(wp)) {
      pointer = xlb_getwppointer<pointer_t>(wp);
    }

    if (pointer) {
      ++ami.arg_index;
    } else {
      xlb_amfail(ami, XLB_E_AMI_BAD, "wrong type");
    }
  }

  void pusharg(lua_State *L, int &rc) override {
    // xlb_debug("(typeid=%s,isMoved=%d)\n", typeid(pointer).name(), isMoved);
    if constexpr (std::is_array_v<T>) {
      assert(pointer);
      auto &right{*pointer};
      auto left{new T()};
      xlb_assignarrary<std::extent_v<T, 0>>::go(left, right, isMoved);
      pointer = reinterpret_cast<T *>(left); // XXX: T is not decay
      auto &v{*pointer};
      rc += xlb_pushstructval(L, (T &)v, xlf_gc::yesArray);
    } else {
      assert(pointer);
      auto &right{*pointer};
      pointer = (isMoved) ? new T(std::move(right)) : new T(right);
      auto &v{*pointer};
      rc += xlb_pushstructval(L, (T &)v, xlf_gc::yes);
    }
  }
}; // xlb_lstruct<T>

//--------------------------------------------------------------------------------------------------
// T === const X or X
template <typename Vt, typename T>
struct xlb_lstruct<Vt, T &> : public xlb_base_agent // reference, do not copy
{
  using vter = Vt;
  using type = T;
  using pointer_t = T *;

  T *pointer{nullptr};
  xlb_lstruct(T &&v) : pointer(&v) {}
  operator T &() {
    assert(pointer);
    return (*pointer);
  }

  void getarg(lua_State *L, xlb_ami &ami) override {
    pointer = nullptr;
    assert(xlb_base_class<T>::metaName != nullptr);

    xlb_debug("\n");
    if (auto wp = xlb_testwrap<T>(L, ami.arg_index)) {
      if (xlb_issametypeindex<T>(wp)) {
        auto tmatched{false};
        if constexpr (std::is_const_v<T>) { // parameter==const T&
          tmatched = xlb_wpiscopyable(wp);  // argument==value or reference
        } else {
          tmatched = xlb_wpisentity(wp); // parameter==T&
        }
        if (tmatched) {
          pointer = xlb_getwppointer<pointer_t>(wp);
        }
      }
    }

    if (pointer) {
      ++ami.arg_index;
    } else {
      xlb_amfail(ami, XLB_E_AMI_BAD, "wrong type");
    }
  }

  void pusharg(lua_State *L, int &rc) override {
    assert(pointer);
    rc += xlb_pushstructref(L, (*pointer), xlf_gc::no);
  }
}; // xlb_lstruct<T&>

//--------------------------------------------------------------------------------------------------
template <typename Vt, typename T> struct xlb_lnumber : public xlb_base_agent {
  using vter = Vt;
  using type = T;
  T value;

  xlb_lnumber(T *p) {
    if (p)
      value = *p;
  }
  xlb_lnumber(T v = 0.0) { value = v; }
  operator T &() { return value; }

  void getarg(lua_State *L, xlb_ami &ami) override {
    value = lua_tonumber(L, ami.arg_index);
    ++ami.arg_index;
  }

  void pusharg(lua_State *L, int &rc) override {
    lua_pushnumber(L, value);
    ++rc;
  }
}; // xlb_lnumber

//--------------------------------------------------------------------------------------------------
template <typename Vt, typename T> struct xlb_lintegral : public xlb_base_agent {
  using vter = Vt;
  using type = T;

  T value{0};

  xlb_lintegral(const T *p) {
    if (p)
      value = *p;
  }
  xlb_lintegral(const T &v = 0) { value = v; }
  xlb_lintegral(T &&v) { value = v; }

  xlb_lintegral &operator=(T v) {
    value = v;
    return (*this);
  }

  operator T &() { return value; }

  void getarg(lua_State *L, xlb_ami &ami) override {
    if (lua_isboolean(L, ami.arg_index)) {
      value = (lua_toboolean(L, ami.arg_index)) ? 1 : 0;
      ++ami.arg_index;
    } else {
      // Converts the Lua value at the given index to the
      // signed integral type lua_Integer. The Lua value must
      // be an integer, or a number or string convertible to an
      // integer ; otherwise, lua_tointegerx returns 0.
      if (lua_isinteger(L, ami.arg_index)) {
        value = lua_tointeger(L, ami.arg_index);
        ++ami.arg_index;
      } else {
        stringstream ss;
        ss << "xlb: #" << ami.arg_index << " integer expected.";
        xlb_amfail(ami, XLB_E_AMI_BAD, ss.str());
      }
    }
  }

  void pusharg(lua_State *L, int &rc) override {
    lua_pushinteger(L, value);
    ++rc;
  }
}; // xlb_lintegral

//--------------------------------------------------------------------------------------------------
// xlb_larray
//--------------------------------------------------------------------------------------------------
template <typename Vt, int N, typename T> struct xlb_larray : public xlb_base_agent {
  using vter = Vt;
  using type = T[N];
  using pointer_t = T *;
  using item_reference = T &;
  using reference = type &;

  pointer_t pointer{nullptr};
  std::unique_ptr<T> ptr;

  xlb_larray(T p[N] = nullptr) : pointer(p) {}
  xlb_larray(T (*p)[N]) : pointer((pointer_t)p) {} // second dimension

  operator reference() {
    // xlb_debug( "\n" );
    assert(pointer);
    return (type &)(*pointer);
  }

  item_reference getelement(int index) {
    assert(pointer);
    return *(pointer + index);
  }

  item_reference operator[](int index) {
    assert(pointer);
    return *(pointer + index);
  }

  void getarg(lua_State *L, xlb_ami &ami) override {
    auto got{false};
    // xlb_debug( "(N=%d,%s)\n\n", N, typeid( T ).name() );
    switch (lua_type(L, ami.arg_index)) {
    case LUA_TTABLE: {                     // accept table
      if constexpr (!std::is_const_v<T>) { // will setup array
        ptr.reset(ami.raw_left ? (T *)ami.raw_left : new type);
        auto arr{pointer = ptr.get()};
        assert(pointer);
        xlb_at<Vt, T> v;
        auto top{lua_gettop(L)};
        xlb_ami item_ami{top + 1};

        for (int i = 0; i < N; ++i, ++arr) {
          lua_rawgeti(L, ami.arg_index, i + 1);
          if (!lua_isnil(L, -1)) {
            item_ami.arg_index = top + 1;
            item_ami.raw_left = arr;
            v.getarg(L, item_ami);
            if constexpr (!std::is_array_v<T>) {
              *arr = v;
              // xlb_debug("(%p,%d)\n", arr, *arr);
            }
          }
          lua_pop(L, 1);
        }
        lua_settop(L, top);
        got = true;
        if (ami.raw_left) {
          ptr.release();
        } else {
          // xlb_debug("(new space, %llu, %p)\n", sizeof(type), pointer);
        }
      }
      break;
    }
    case LUA_TUSERDATA: { // accept array
      using eT = T;
      // wp = xlb_testwrap<eT>( L, ami.arg_index, XLB_META_PREFIX_ARRAY );
      xlb_base_wrap *wp{nullptr};
      std::string meta_name{xlu_getmetaname(L, ami.arg_index)};
      // xlb_debug( "(%s,%p)\n", meta_name.c_str(), wp );
      if (xlu_checkmetaprefix(meta_name, XLB_META_PREFIX_ARRAY)) {
        if (!wp) {
          wp = xlb_tobasewrap(L, ami.arg_index);
          if (wp && xlb_issametypeindex<eT[]>(wp)) {
            // xlb_debug( "(%s,%p)\n", meta_name.c_str(), wp );
            if constexpr (!std::is_const_v<eT>) {
              if (wp && xlb_wpisconst(wp)) {
                wp = nullptr;
              }
            }
          }
        }
        if (!wp) {
          if constexpr (std::is_const_v<eT>) { // accept not const
            using eT = std::remove_const_t<eT>;
            // wp = xlb_testwrap<eT>( L, ami.arg_index, XLB_META_PREFIX_ARRAY );
            wp = xlb_tobasewrap(L, ami.arg_index);
            if (wp && !xlb_issametypeindex<eT[]>(wp)) {
              wp = nullptr;
            }
          }
        }
      }
      if (!wp) {
        if (xlu_checkmetaprefix(meta_name, XLB_META_PREFIX_POINTER)) {
          wp = xlb_tobasewrap(L, ami.arg_index);
        }
        if (wp) {
          // xlb_debug( "(%p,%s,%d)\n", wp, typeid( eT ).name(), xlb_wpisconst(
          // wp ) );
          if constexpr (!std::is_const_v<eT>) {
            if (wp && xlb_wpisconst(wp)) {
              wp = nullptr;
            }
          }
        }
      }
      if (wp) {
        pointer = xlb_getwppointer<pointer_t>(wp);
        // xlb_debug( "(%p,%p)\n", &left, &right );
        got = true;
      }
      break;
    }
    }
    if (got) {
      ++ami.arg_index;
      // xlb_debug( "(%d)\n", ami.arg_index );
    } else {
      xlb_amfail(ami, XLB_E_AMI_BAD, "wrong type");
    }
  }

  void pusharg(lua_State *L, int &rc) override {
    if (pointer) {
      // xlb_debug( "(%s,%p)\n", typeid( type ).name(), pointer );
      rc += xlb_pusharraypointer<Vt, T[N]>(L, pointer, xlf_gc::no);
    } else {
      lua_pushnil(L);
      rc += 1;
    }
  }
}; // xlb_larray<Vt, N, T>

//--------------------------------------------------------------------------------------------------

template <typename Vt, typename T> struct xlb_lboolean : public xlb_base_agent {
  using vter = Vt;
  using type = bool;
  bool value;

  xlb_lboolean(bool b = false) : value(b) {}
  xlb_lboolean &operator=(int v) {
    value = v;
    return (*this);
  }
  operator bool() const { return value; }

  void getarg(lua_State *L, xlb_ami &ami) override {
    value = lua_toboolean(L, ami.arg_index);
    // xlb_debug("(%s)\n", lua_typename(L, (lua_type(L, ami.arg_index))));
    ++ami.arg_index;
  }

  void pusharg(lua_State *L, int &rc) override {
    lua_pushboolean(L, value);
    // xlb_debug("(%s)\n", lua_typename(L, (lua_type(L, -1))));
    ++rc;
  }
}; // xlb_lboolean

//--------------------------------------------------------------------------------------------------
template <typename Vt> struct xlb_lfunc : public xlb_base_agent {
  using vter = Vt;
  using type = xlb_luafunc;
  int refid = LUA_NOREF;

  xlb_lfunc(int id = LUA_NOREF) : refid(id) {}
  operator xlb_luafunc() const { return {refid}; }

  void getarg(lua_State *L, xlb_ami &ami) override {
    // xlb_debug("(%d,%d)\n", lua_type(L, ami.arg_index), LUA_TFUNCTION);
    if (lua_type(L, ami.arg_index) == LUA_TFUNCTION) {
      lua_pushnil(L);                 // #-1
      lua_copy(L, ami.arg_index, -1); // copy and replace #-1
      refid = luaL_ref(L, LUA_REGISTRYINDEX);
      // xlb_debug("(%d)\n", refid);
      ++ami.arg_index;
    } else {
      xlb_amfail(ami, XLB_E_AMI_BAD, "xlb: lua function expected");
    }
  }

  void pusharg(lua_State *L, int &rc) override {
    lua_rawgeti(L, LUA_REGISTRYINDEX, refid);
    ++rc;
  }
}; // xlb_lfunc

//--------------------------------------------------------------------------------------------------
// GC wrap, destructe wrap object
//--------------------------------------------------------------------------------------------------
template <typename T> int xlb_wpdtor(lua_State *L) {
  if (auto wp = xlb_testwrap<T>(L, 1)) {
    assert(wp);
    wp->~xlb_wrap<T>();
  }
  return 0;
}

/** XXX: have free function to free pointer */
template <typename T, auto freef> int xlb_wpdtor(lua_State *L) {
  if (auto wp = xlb_testwrap<T>(L, 1)) {
    assert(wp);
    wp->freeit(freef);
    wp->~xlb_wrap<T>();
    // xlb_debug("(%s)\n", typeid(T *).name());
  }
  return 0;
}

//--------------------------------------------------------------------------------------------------
//  xlt_typelist
//--------------------------------------------------------------------------------------------------
template <class Vt, class FT> struct xlb_typeforge {};

template <class Vt, class R, class Tx, class... A> struct xlb_typeforge<Vt, R (Tx::*)(A...)> {
  using tuple_t = std::tuple<xlb_at<Vt, A>...>;
  using idx_t = xlb_idx_t<sizeof...(A)>;
  using param_t = xlt_typelist<A...>;
  using rv_t = R;
  using rv_at = xlb_at<Vt, xlt_rvtrait<R>>;
  using obj_t = Tx;
  using arginfo_t = array<xlb_ai, sizeof...(A)>;
  using const_t = false_type;
};

template <class Vt, class R, class Tx, class... A> struct xlb_typeforge<Vt, R (Tx::*)(A...) const> {
  using tuple_t = std::tuple<xlb_at<Vt, A>...>;
  using idx_t = xlb_idx_t<sizeof...(A)>;
  using param_t = xlt_typelist<A...>;
  using rv_t = R;
  using rv_at = xlb_at<Vt, xlt_rvtrait<R>>;
  using obj_t = Tx;
  using arginfo_t = array<xlb_ai, sizeof...(A)>;
  using const_t = true_type;
};

#ifndef _WIN64
template <class Vt, class R, class Tx, class... A>
struct xlb_typeforge<Vt, R (__stdcall Tx::*)(A...)> {
  using tuple_t = std::tuple<xlb_at<Vt, A>...>;
  using idx_t = xlb_idx_t<sizeof...(A)>;
  using param_t = xlt_typelist<A...>;
  using rv_t = R;
  using rv_at = xlb_at<Vt, xlt_rvtrait<R>>;
  using obj_t = Tx;
  using arginfo_t = array<xlb_ai, sizeof...(A)>;
  using const_t = false_type;
};
#endif

//--------------------------------------------------------------------------------------------------
#ifndef _WIN64
template <class Vt, class R, class... A> struct xlb_typeforge<Vt, R(__cdecl *)(A...)> {
  using tuple_t = std::tuple<xlb_at<Vt, A>...>;
  using idx_t = xlb_idx_t<sizeof...(A)>;
  using param_t = xlt_typelist<A...>;
  using rv_t = R;
  using rv_at = xlb_at<Vt, xlt_rvtrait<R>>;
  using obj_t = void;
  using arginfo_t = array<xlb_ai, sizeof...(A)>;
  using const_t = false_type;
};
#endif

//  On ARM and x64 processors, __stdcall is accepted and ignored by the
//  compiler; on ARM and x64 architectures, by convention, arguments are passed
//  in registers when possible, and subsequent arguments are passed on the
//  stack. __fastcall is faster than __cdecl and __stdcall is default calling
//  convention for Windows 64-bit. The __fastcall calling convention specifies
//  that arguments to functions are to be passed in registers, when possible.
//  This calling convention only applies to the x86 architecture.
template <class Vt, class R, class... A> struct xlb_typeforge<Vt, R(__stdcall *)(A...)> {
  using tuple_t = std::tuple<xlb_at<Vt, A>...>;
  using idx_t = xlb_idx_t<sizeof...(A)>;
  using param_t = xlt_typelist<A...>;
  using rv_t = R;
  using rv_at = xlb_at<Vt, xlt_rvtrait<R>>;
  using obj_t = void;
  using arginfo_t = array<xlb_ai, sizeof...(A)>;
  using const_t = false_type;
};

template <class Vt, class... A> struct xlb_typeforge<Vt, void (*)(A...)> {
  using tuple_t = std::tuple<xlb_at<Vt, A>...>;
  using idx_t = xlb_idx_t<sizeof...(A)>;
  using param_t = xlt_typelist<A...>;
  using rv_t = void;
  using rv_at = xlb_at<Vt, xlt_rvtrait<void>>;
  using obj_t = void;
  using arginfo_t = array<xlb_ai, sizeof...(A)>;
  using const_t = false_type;
};

//--------------------------------------------------------------------------------------------------
// xlb_dfer
// function with default parameters provider
//--------------------------------------------------------------------------------------------------

struct xlb_dfer : public xpo_base_dfer {
  template <class TUP> XLB_SII go(TUP &tup, int dc) { return 0; }
};

template <class TUP, class T, int idx> XLB_SIV xlb_default_assign(TUP &tup, T &&A) {
  std::get<idx>(tup) = A;
}

template <typename TUP, typename Idxer, typename... T> struct xlb_setdefaultval {};

template <typename TUP, int... idx, typename... T>
struct xlb_setdefaultval<TUP, xlb_idx<idx...>, T...> {
  XLB_SIV go(TUP &tup, int dc, T &&...Dvs) {
    constexpr auto tsize = xlb_tupsize_v<TUP>;
    constexpr auto dsize = sizeof...(Dvs);
    static_assert(tsize >= dsize, "too much default value");
    xlt_each{
        ((idx >= (dsize - dc)) ? (std::get<tsize - dsize + idx>(tup) = std::forward<T>(Dvs),
                                  // xlb_debug("(%d-%d,%d,%d)\n", tsize, dsize, idx, dc),
                                  XLB_STATEMENT_VALUE)
                               : XLB_STATEMENT_VALUE)...};
  }
};

template <typename TUP, typename... T> XLB_SII xlb_putdefault(TUP &tup, int dc, T &&...Dvs) {
  constexpr auto tsize = xlb_tupsize_v<TUP>;
  constexpr auto dsize = sizeof...(T);
  static_assert(tsize >= dsize);
  using SETDEFAULTVAL = xlb_setdefaultval<TUP, xlb_idx_t<sizeof...(T)>, T...>;
  SETDEFAULTVAL::go(tup, dc, std::forward<T>(Dvs)...);
  return sizeof...(Dvs);
}

//--------------------------------------------------------------------------------------------------
// xlb_getargs
// decltype(AIs)===array<xlb_ai, ...>
//--------------------------------------------------------------------------------------------------
template <typename TUP, typename Idx, typename Dft> struct xlb_getargs {};

template <typename TUP, typename Dft> struct xlb_getargs<TUP, xlb_idx<>, Dft> {
  template <typename AIs> XLB_SIV go(lua_State *L, TUP &tup, AIs &ais, xlb_ami &ami) {
    // xlb_debug("(%d,%u,%d)\n", ami.arg_count, ami.arg_index,
    // ami.match_result);
    if (ami.arg_count >= ami.arg_index) {
      xlb_amfail(ami, XLB_E_AMI_TOMUCH, "xlb: too much arguments");
    }
  }
};

template <typename TUP, int Param_i, int... idxs, typename Dft>
struct xlb_getargs<TUP, xlb_idx<Param_i, idxs...>, Dft> {
  template <typename AIs> XLB_SIV go(lua_State *L, TUP &tup, AIs &ais, xlb_ami &ami) {
    if (ami.arg_count >= ami.arg_index) {
      auto &ai = ais[Param_i];
      ai.from = ami.arg_index;
      ai.type = lua_type(L, ami.arg_index);
      ai.index = Param_i + 1;
      auto &agent{std::get<Param_i>(tup)};
      // xlb_debug("(%s)\n", typeid(decltype(agent)).name());
      agent.getarg(L, ami);
      ai.to = ami.arg_index; // [from,to)
    } else {
      ami.match_result = XLB_E_AMI_FEW;
    }
    // xlb_debug("(%d,%u,%x)\n", ami.arg_count, ami.arg_index,
    // ami.match_result);

    if (xlb_ambad(ami)) {
      if (XLB_E_AMI_FEW == ami.match_result) {
        auto stack_remain = (ami.arg_count - (ami.arg_index - 1));
        auto args_remain = (ami.param_count - Param_i);
        auto dc = args_remain - stack_remain;
        ami.default_count = Dft::go(tup, dc);
        if (stack_remain - args_remain + ami.default_count >= 0) {
          ami.match_result = XLB_E_AMI_DEFAULT;
        } else {
          stringstream ss;
          ss << "xlb: too few arguments (" << ami.arg_index << "," << ami.param_count << ")";
          xlb_amfail(ami, ami.match_result, ss.str());
          // xlb_amfail( ami, ami.match_result, "xlb: too few arguments" );
        }
      }
    } else {
      // xlb_debug("(%d,%u,%d)\n", ami.arg_count, ami.arg_index,
      // ami.match_result);
      xlb_getargs<TUP, xlb_idx<idxs...>, Dft>::go(L, tup, ais, ami);
    }
  }
}; // xlb_getargs

//--------------------------------------------------------------------------------------------------
//  default value support
//--------------------------------------------------------------------------------------------------
template <typename Lam> struct xlb_derived_dfer : public xpo_base_dfer {
  ///< use static member to keep lambda instead non static member
  inline static Lam *plmd{nullptr};
  xlb_derived_dfer(Lam &l) { plmd = &l; }
  template <typename TUP> XLB_SII go(TUP &tup, int dc) { return (*plmd)(tup, dc); }
};

template <typename Lam> auto xpo_default(Lam lmd) {
  using po_default_t = xlb_derived_dfer<decltype(lmd)>;
  return po_default_t(lmd);
}

//--------------------------------------------------------------------------------------------------
template <typename Idx, auto... Dvs> struct xlb_assign_default_value {};
template <int... idx, auto... Dvs> struct xlb_assign_default_value<xlb_idx<idx...>, Dvs...> {
  template <typename TUP> XLB_SIV go(TUP &tup, int dc) {
    constexpr auto tsize = xlb_tupsize_v<TUP>;
    constexpr auto dsize = sizeof...(Dvs);
    static_assert(tsize >= dsize, "too much default value");
    xlt_each{((idx >= (dsize - dc)) ? (std::get<tsize - dsize + idx>(tup) = Dvs, 0) : 0)...};
  }
};

template <auto... Dvs> auto xpo_dvs() {
  auto lmd = [](auto &tup, int dc) -> int {
    using Idx = xlb_idx_t<sizeof...(Dvs)>;
    xlb_assign_default_value<Idx, Dvs...>::template go(tup, dc);
    // xlb_debug("(<1>=%d,%u)\n", (int)get<1>(tup), sizeof...(Dvs));
    return sizeof...(Dvs);
  };
  return xpo_default(lmd);
}

//--------------------------------------------------------------------------------------------------
//  xlb_derived_rier
//--------------------------------------------------------------------------------------------------

template <int... PLACEHOLDERS> struct xlb_derived_rier : public xpo_base_rier {};

using xlb_rier = void;

//--------------------------------------------------------------------------------------------------
//  xlb_pushfrv
//  push addition parameters of function into lua_State
//--------------------------------------------------------------------------------------------------
struct xlb_pushfrv {
  template <typename, typename> struct xlb_tir {};
};

template <typename TUP> struct xlb_pushfrv::xlb_tir<void, TUP> {
  template <typename AIs> XLB_SIV go(lua_State *L, TUP &tup, const AIs &ais, int &rc) {}
};

template <int... RPI> struct xlb_pushfrv::xlb_tir<xlb_derived_rier<RPI...>, std::tuple<>> {
  template <typename AIs> XLB_SIV go(lua_State *L, std::tuple<> &tup, const AIs &ais, int &rc) {}
};

template <int... RPI, typename... A>
struct xlb_pushfrv::xlb_tir<xlb_derived_rier<RPI...>, std::tuple<A...>> {
  template <typename AIs> XLB_SIV go(lua_State *L, std::tuple<A...> &tup, const AIs &ais, int &rc) {
    xlt_each{(get<RPI - 1>(tup).push(L, rc), XLB_STATEMENT_VALUE)...};
  }
};

//--------------------------------------------------------------------------------------------------
// @struct xlb_ctor_r
// @brief trait for result of constructor
//--------------------------------------------------------------------------------------------------
template <typename T> class xlb_ctor_r {
public:
  using type = T;
  xlb_ctor_r(T *p) : pointer(p) {}
  T &getobj() {
    assert(pointer);
    return *pointer;
  }

protected:
  T *pointer = nullptr;
}; // xlb_ctor_r

template <typename T> class xlb_ctor_inplace_r : public xlb_ctor_r<T> {};

/** XXX: argument #1 is table, object that create in Lua just through new
 * operator. this function is the agent of class contructor function and binded
 * to Lua as metatable's default call method named __call, (__call(t,...)).
 * those xlb_ctor_r object must gc in Lua witch delete operator. ignore table
 * that is argument #1 of __call method.
 * TODO: make it PO, meet another new operator action
 */
template <typename T, typename... A> xlb_ctor_r<T> xlb_ctor(xlb_ignore, A... args) {
  return {new T(args...)};
}

/** XXX: must ignore #1 as normal xlb_ctor */
template <typename T, T *(*f)(void)> xlb_ctor_r<T> xlb_ctor_c_style(xlb_ignore) { return {f()}; }

//--------------------------------------------------------------------------------------------------
struct xlb_memblock {
  void *memblock = nullptr;
  xlb_memblock(void *p) : memblock(p) {}
  operator void *() { return memblock; }
}; // xlb_memblock

template <typename Vt> struct xlb_lmemblock : public xlb_base_agent, xlb_memblock {
  using vter = Vt;
  xlb_lmemblock(void *p = nullptr) : xlb_memblock(p) {}
  //// operator xlb_memblock& () { return (*this); }

  void getarg(lua_State *L, xlb_ami &ami) override {
    auto extmsg{"xlb: invalid self"};
    auto wp{xlb_tobasewrap(L, ami.arg_index)};
    if (wp && (!xlb_wpisconst(wp))) {
      memblock = xlb_getwppointer<void *>(wp);
    } else {
      extmsg = "xlb: nonconst object expected";
    }
    if (memblock) {
      ++ami.arg_index;
      // xlb_debug("(0x%p)\n", memblock);
    } else {
      xlb_amfail(ami, XLB_E_AMI_BAD, extmsg);
    }
  }

  void pusharg(lua_State *L, int &rc) override {
    using AT = xlb_at<Vt, void>;
    rc += xlb_pushpointer<void *, AT>(L, memblock);
  }
}; // xlb_lmemblock<Vt>

// XXX: argument xlb_memblock is copy not reference
template <typename T, typename... A>
xlb_ctor_inplace_r<T> xlb_ctor_inplace(xlb_ignore, xlb_memblock place, A... args) {
  return {new ((void *)place) T(args...)};
}

//--------------------------------------------------------------------------------------------------
template <typename T> struct is_ctor_r : std::false_type {};
template <typename T> struct is_ctor_r<xlb_ctor_r<T>> : std::true_type {};
template <typename T> struct is_ctor_r<xlb_ctor_inplace_r<T>> : std::true_type {};

//--------------------------------------------------------------------------------------------------
// @struct xlb_rv2l
// @brief push result of function into lua_State
//--------------------------------------------------------------------------------------------------
struct xlb_rv2l {
  template <typename R, typename AT> struct xlb_tir {
    XLB_SIV go(lua_State *L, AT &r, int &rc) { r.pusharg(L, rc); }
  };

  /* XXX: for special type xlb_ctor_r, push new object to Lua
   * xlb_rv2l for xlb_ctor function return value (make it special type
   * xlb_ctor_r)
   */
  template <typename R, typename AT> struct xlb_tir<xlb_ctor_r<R>, AT> {
    XLB_SIV go(lua_State *L, xlb_ctor_r<R> &r, int &rc) {
      rc += xlb_pushobj(L, r.getobj(), xlf_gc::yes);
    }
  };

  template <typename R, typename AT> struct xlb_tir<xlb_ctor_inplace_r<R>, AT> {
    XLB_SIV go(lua_State *L, xlb_ctor_inplace_r<R> &r, int &rc) {
      rc += xlb_pushobj(L, r.getobj(), xlf_gc::yesInplace);
    }
  };
}; // xlb_rv2l

//--------------------------------------------------------------------------------------------------
struct xlb_delete {
  template <typename T, typename = void> struct xlb_tir { using type = std::default_delete<T>; };
};

template <typename T> using xlb_delete_t = xlb_t<xlb_delete::xlb_tir<T>>;

//--------------------------------------------------------------------------------------------------
// xlb_vter, help us to get AT(agent type) that is used to
// 1. load variable from Lua
// 2. store variable
// 3. and push WT(wrap value) variable to Lua
// usage: using t = xlb_vter::xlb_tir<T>::type
//--------------------------------------------------------------------------------------------------
struct xlb_vter {
  template <typename X, typename Partial = xlb_djy> struct xlb_tir {};
}; // xlb_vter

//--------------------------------------------------------------------------------------------------
// ignore this var, it's a special val such as self object
//--------------------------------------------------------------------------------------------------
template <> struct xlb_vter::xlb_tir<xlb_ignore> {
  using vter = xlb_vter;
  using type = xlb_ignore;
};

template <> struct xlb_vter::xlb_tir<xlb_memblock> {
  using vter = xlb_vter;
  using type = xlb_lmemblock<vter>;
};

//--------------------------------------------------------------------------------------------------
// type for result value that with xlt_rvtrait of function
// that is constructor; constructor function return xlb_ctor_r<X>;
// xlt_rvtrait means var is the result of function
//--------------------------------------------------------------------------------------------------
template <typename X> struct xlb_vter::xlb_tir<xlt_rvtrait<xlb_ctor_r<X>>> {
  using vter = xlb_vter;
  using type = xlb_ctor_r<X>;
};

//--------------------------------------------------------------------------------------------------
// reference as pointer, and take it as pointer,
// pass xlb_vter to help get more information about the pointer type.
//--------------------------------------------------------------------------------------------------
template <typename X> struct xlb_vter::xlb_tir<xlt_rvtrait<X &>> {
  using vter = xlb_vter;
  using type = xlb_lpointer<vter, X *, X &, xlb_delete_t<X>>;
};

template <typename X> struct xlb_vter::xlb_tir<xlt_rvtrait<const X &>> {
  using vter = xlb_vter;
  using type = xlb_lpointer<vter, const X *, const X &, xlb_delete_t<X>>;
};

template <typename X> // for pointer or array
struct xlb_vter::xlb_tir<xlt_rvtrait<X *>> {
  using vter = xlb_vter;
  using type = xlb_lpointer<vter, X *, X *, xlb_delete_t<X>>;
};

template <typename X> struct xlb_vter::xlb_tir<xlt_rvtrait<X *const>> {
  using vter = xlb_vter;
  using type = xlb_lpointer<vter, X *const, X *const, xlb_delete_t<X>>;
};

// type for result of function that return void
template <> struct xlb_vter::xlb_tir<xlt_rvtrait<void>> {
  using vter = xlb_vter;
  using type = xlt_rvtrait<void>;
};

template <> struct xlb_vter::xlb_tir<xlt_rvtrait<bool>> {
  using vter = xlb_vter;
  using type = xlb_lboolean<vter, bool>;
};

template <typename X> struct xlb_vter::xlb_tir<xlt_rvtrait<const X *>> {
  using vter = xlb_vter;
  using type = xlb_lpointer<vter, const X *, const X *, xlb_delete_t<X>>;
};

template <typename X> struct xlb_vter::xlb_tir<xlt_rvtrait<const X *const>> {
  using vter = xlb_vter;
  using type = xlb_lpointer<vter, const X *const, const X *const, xlb_delete_t<X>>;
};

//--------------------------------------------------------------------------------------------------
template <> struct xlb_vter::xlb_tir<void> {
  using vter = xlb_vter;
  using type = xlb_lstruct<vter, void>;
};

template <> struct xlb_vter::xlb_tir<void *> {
  using vter = xlb_vter;
  using type = xlb_lpointer<vter, void *, void *, xlb_delete_t<void *>>;
};

//--------------------------------------------------------------------------------------------------
template <> struct xlb_vter::xlb_tir<xlb_luafunc> {
  using vter = xlb_vter;
  using type = xlb_lfunc<vter>;
};

//--------------------------------------------------------------------------------------------------
// pointer and reference
//--------------------------------------------------------------------------------------------------

template <typename T> struct xlb_vter::xlb_tir<T &> {
  using vter = xlb_vter;
  using type = xlt_ifelse_t<
      std::is_array_v<T>, xlb_t<xlb_vter::xlb_tir<T>>,
      xlb_lpointer<vter, T *, T &, xlb_delete_t<T>>>;
};

template <typename T> struct xlb_vter::xlb_tir<T *> {
  using vter = xlb_vter;
  using type = xlb_lpointer<vter, T *, T *, xlb_delete_t<T>>;
};

template <typename T> struct xlb_vter::xlb_tir<const T *> {
  using vter = xlb_vter;
  using type = xlb_lpointer<vter, const T *, const T *, xlb_delete_t<T>>;
};

template <typename T> struct xlb_vter::xlb_tir<T *const> {
  using vter = xlb_vter;
  using type = xlb_lpointer<vter, T *const, T *const, xlb_delete_t<T>>;
};

//--------------------------------------------------------------------------------------------------
// TCHAR array
//--------------------------------------------------------------------------------------------------
template <int N, typename T> struct xlb_vter::xlb_tir<T[N]> {
  using vter = xlb_vter;
  using type = xlb_larray<vter, N, T>;
};

//--------------------------------------------------------------------------------------------------
// TODO: make it extend
//--------------------------------------------------------------------------------------------------
template <typename, typename, typename> struct xlt_vter_query {};
struct xlt_fit_floating {};
struct xlt_fit_bool {};
struct xlt_fit_integral {};
struct xlt_fit_customize {};

template <typename T> struct xlt_cond_integral {
  using type = xlt_ifelse_t<std::is_integral_v<T>, xlt_fit_integral, xlt_fit_customize>;
};
template <typename T> using xlt_cond_integral_t = typename xlt_cond_integral<T>::type;

template <typename T> struct xlt_cond_bool {
  using type = xlt_ifelse_t<std::is_same_v<T, bool>, xlt_fit_bool, xlt_cond_integral_t<T>>;
};
template <typename T> using xlt_cond_bool_t = typename xlt_cond_bool<T>::type;

template <typename T> struct xlt_cond_floating {
  using type = xlt_ifelse_t<std::is_floating_point_v<T>, xlt_fit_floating, xlt_cond_bool_t<T>>;
};
template <typename T> using xlt_cond_floating_t = typename xlt_cond_floating<T>::type;

//--------------------------------------------------------------------------------------------------
template <typename Vt, typename X, typename COND>
using xlt_vter_query_t = typename xlt_vter_query<Vt, X, COND>::type;

template <typename Vt, typename X> struct xlt_vter_query<Vt, X, xlt_fit_customize> {
  using type = xlb_lstruct<Vt, X>;
}; // XXX:default

template <typename Vt, typename X> struct xlt_vter_query<Vt, X, xlt_fit_integral> {
  // using type = xlb_lintegral<Vt, std::remove_cv_t<X>>;
  using type = xlb_lintegral<Vt, std::remove_const_t<X>>;
};

template <typename Vt, typename X> struct xlt_vter_query<Vt, X, xlt_fit_bool> {
  // using type = xlb_lintegral<Vt, std::remove_cv_t<X>>;
  using type = xlb_lboolean<Vt, std::remove_const_t<X>>;
};

template <typename Vt, typename X> struct xlt_vter_query<Vt, X, xlt_fit_floating> {
  using type = xlb_lnumber<Vt, X>;
};

//--------------------------------------------------------------------------------------------------
template <typename X> struct xlb_vter::xlb_tir<X> {
  using type = xlt_vter_query_t<xlb_vter, X, xlt_cond_floating_t<X>>;
};

template <typename X> ///< XXX: for return Type
struct xlb_vter::xlb_tir<xlt_rvtrait<X>> {
  using type = xlt_vter_query_t<xlb_vter, X, xlt_cond_floating_t<X>>;
};

//--------------------------------------------------------------------------------------------------
// PO selector
//--------------------------------------------------------------------------------------------------
template <typename T> struct xpo_vter_selector { using type = T; };
template <> struct xpo_vter_selector<void> { using type = xlb_vter; };

template <typename T> struct xpo_dfer_selector { using type = T; };
template <> struct xpo_dfer_selector<void> { using type = xlb_dfer; };

template <typename T> struct xpo_rier_selector { using type = T; };
template <> struct xpo_rier_selector<void> { using type = xlb_rier; };

template <typename T> struct xpo_readonly_selector { using type = xpo_readonly; };
template <> struct xpo_readonly_selector<void> { using type = xpo_none; };

//--------------------------------------------------------------------------------------------------
template <typename BASE, template <typename> class SELECTOR, typename... PO> struct xlt_searchlist {
  using type = xlb_t<SELECTOR<xlt_getderived_t<BASE, xlt_typelist<PO...>>>>;
};

//--------------------------------------------------------------------------------------------------
template <typename... PO>
using xpo_get_readonly =
    typename xlt_searchlist<xpo_base_readonly, xpo_readonly_selector, PO...>::type;

template <typename... PO>
using xpo_get_vter = typename xlt_searchlist<xpo_base_vter, xpo_vter_selector, PO...>::type;

template <typename... PO>
using xpo_get_default = typename xlt_searchlist<xpo_base_dfer, xpo_dfer_selector, PO...>::type;

template <typename... PO>
using xpo_get_rier = typename xlt_searchlist<xpo_base_rier, xpo_rier_selector, PO...>::type;

//--------------------------------------------------------------------------------------------------
//  xlb_selfobj
//--------------------------------------------------------------------------------------------------
template <typename X, typename CONST_T> struct xlb_selfobj {
  template <typename TUP, typename AIs> XLB_SIV go(lua_State *L, TUP &tup, xlb_ami &ami, AIs &ais) {
    xlb_selfagent<const X>().getarg(L, ami);
  }
};

template <typename X> struct xlb_selfobj<X, false_type> {
  template <typename TUP, typename AIs> XLB_SIV go(lua_State *L, TUP &tup, xlb_ami &ami, AIs &ais) {
    xlb_selfagent<X>().getarg(L, ami);
  }
};

// for no self function to get self object, such as constructor function
template <> struct xlb_selfobj<void, false_type> {
  template <typename TUP, typename AIs> XLB_SIV go(lua_State *, TUP &tup, xlb_ami &, AIs &ais) {}
};

//--------------------------------------------------------------------------------------------------
// xlb_invoke
//--------------------------------------------------------------------------------------------------
struct xlb_invoke {
  template <
      typename R, bool, typename R_AT, typename Tx, bool, typename FT, typename Idx,
      typename TYPELIST, typename R2L>
  struct xlb_tir {};
};

///< for r pobj->f(...)
template <
    typename R, typename R_AT, typename Tx, typename FT, typename... A, int... idxs, typename R2L>
struct xlb_invoke::xlb_tir<
    R, false, R_AT, Tx, false, FT, xlb_idx<idxs...>, xlt_typelist<A...>, R2L> {
  template <typename... Arg> XLB_SIV go(lua_State *L, xlb_ami &ami, FT f, std::tuple<Arg...> &tup) {
    // AT do not copy the arguments and so no std::move() used
    // xlb_debug("(%s)\n", typeid(R_AT).name());
    auto &&t = (reinterpret_cast<Tx *>(ami.obj)->*f)((A)std::get<idxs>(tup)...);
    R_AT r(std::move(t));
    R2L::template xlb_tir<R, R_AT>::go(L, r, ami.rc);
  }
};

///< for void pobj->f(...)
template <typename Tx, typename FT, typename... A, int... idxs, typename R2L>
struct xlb_invoke::xlb_tir<
    void, true, xlt_rvtrait<void>, Tx, false, FT, xlb_idx<idxs...>, xlt_typelist<A...>, R2L> {
  template <typename... Arg> XLB_SIV go(lua_State *L, xlb_ami &ami, FT f, std::tuple<Arg...> &tup) {
    (reinterpret_cast<Tx *>(ami.obj)->*f)((A)std::get<idxs>(tup)...);
  }
};

///< for r f(...)
template <typename R, typename R_AT, typename FT, typename... A, int... idxs, typename R2L>
struct xlb_invoke::xlb_tir<
    R, false, R_AT, void, true, FT, xlb_idx<idxs...>, xlt_typelist<A...>, R2L> {
  template <typename... Arg> XLB_SIV go(lua_State *L, xlb_ami &ami, FT f, std::tuple<Arg...> &tup) {
    auto &&tmp_return = std::move(f((A)std::get<idxs>(tup)...));

    ///< for xlb_cbf which take lua callback function as class
    if constexpr (is_ctor_r<R>::value) {
      // XXX: is_base_of_v need complete type
      using T = xlb_t<R>;
      if constexpr (is_complete_v<T>) { // do not merge with next line
        if constexpr (std::is_base_of_v<xlb_base_cbcf, T>) {
          tmp_return.getobj().setLua(L);
        }
      }
    }

    R_AT r(std::move(tmp_return));
    R2L::template xlb_tir<R, R_AT>::go(L, r, ami.rc);
  }
};

///< for void f(...)
template <typename FT, typename... A, int... idxs, typename R2L>
struct xlb_invoke::xlb_tir<
    void, true, xlt_rvtrait<void>, void, true, FT, xlb_idx<idxs...>, xlt_typelist<A...>, R2L> {
  template <typename... Arg> XLB_SIV go(lua_State *L, xlb_ami &, FT f, std::tuple<Arg...> &tup) {
    f((A)std::get<idxs>(tup)...);
  }
};

//--------------------------------------------------------------------------------------------------
//  xlt_each_ovlfunc
//--------------------------------------------------------------------------------------------------

template <lua_CFunction... fcandidate> struct xlt_call_ovl;

template <lua_CFunction f, lua_CFunction... fcandidate> struct xlt_call_ovl<f, fcandidate...> {
  XLB_SIV go(lua_State *L, xlb_ami &ami) {
    ami.match_result = XLB_E_AMI_SAME;
    lua_pushlightuserdata(L, &ami);
    lua_pushcclosure(L, f, 1);
    lua_insert(L, 1);
    lua_call(L, ami.arg_count, LUA_MULTRET); // call inner function
    if (!xlb_ambad(ami)) {
      // have called function, return f as additional return
      lua_pushcfunction(L, f);
      ++ami.rc;
    }
    if constexpr (sizeof...(fcandidate) > 0) {
      if (xlb_ambad(ami)) {
        ami.rc = 0;
        lua_pop(L, lua_gettop(L) - ami.arg_count);
        xlt_call_ovl<fcandidate...>::go(L, ami);
      }
    }
  }
};

using xlb_ovlfs_t = std::vector<lua_CFunction>;
//--------------------------------------------------------------------------------------------------
static int xlb_ovlfsagent(lua_State *L) {
  auto p_fsv = xlb_aspointer<xlb_ovlfs_t *>(L, lua_upvalueindex(XLB_UPVALUE_1));
  assert(p_fsv);

  xlb_ami ami{lua_gettop(L)};
  for (auto &f : (*p_fsv)) {
    ami.match_result = XLB_E_AMI_SAME;
    lua_pushlightuserdata(L, &ami);
    lua_pushcclosure(L, f, 1);
    for (auto i = 1; i <= ami.arg_count; ++i) {
      lua_pushvalue(L, i);
    }
    lua_call(L, ami.arg_count, LUA_MULTRET); // call inner function
    if (xlb_amgood(ami)) {
      // have called function, return f as additional return
      lua_pushcfunction(L, f);
      ++ami.rc;
      break;
    } // else { xlb_debug("%s\n", ami.extmsg.c_str()); }
  }

  return ami.rc;
}

//--------------------------------------------------------------------------------------------------
// @struct xlb_cfunction
// @brief overload function candidate
//--------------------------------------------------------------------------------------------------
template <
    typename FT, FT f, typename Dft = xlb_dfer, typename rpi_po = xlb_rier, typename R2L = xlb_rv2l,
    typename PTER = xlb_pushfrv, typename Vt = xlb_vter>
int xlb_cfunction(lua_State *L) {
  using forge_t = xlb_typeforge<Vt, FT>;
  using tuple_t = typename forge_t::tuple_t;
  using idx_t = typename forge_t::idx_t;
  using param_t = typename forge_t::param_t;
  using rv_t = typename forge_t::rv_t;
  using rv_at = typename forge_t::rv_at;
  using obj_t = typename forge_t::obj_t;
  using arginfo_t = typename forge_t::arginfo_t;
  using const_t = typename forge_t::const_t;

  arginfo_t ais;
  tuple_t tup;

  // get ami, first upvalue is xlb_ami with inner function
  // if get ami, means f is a inner function
  auto p_ami = reinterpret_cast<xlb_ami *>(lua_touserdata(L, lua_upvalueindex(XLB_UPVALUE_1)));
  std::unique_ptr<xlb_ami> ptr_ami;
  if (nullptr == p_ami) {
    ptr_ami.reset(new xlb_ami(lua_gettop(L)));
    p_ami = ptr_ami.get();
  }
  auto &ami = (*p_ami);

  ami.arg_index = 1; // reset it
  ami.param_count = param_t::size;

  xlb_selfobj<obj_t, const_t>::go(L, tup, ami, ais);

  if (!xlb_ambad(ami)) {
    xlb_getargs<tuple_t, idx_t, Dft>::go(L, tup, ais, ami);
  }

  if (!xlb_ambad(ami)) {
    xlb_invoke::template xlb_tir<
        rv_t, std::is_void_v<rv_t>, rv_at, obj_t, std::is_void_v<obj_t>, FT, idx_t, param_t,
        xlb_rv2l>::go(L, ami, f, tup);
    PTER::template xlb_tir<rpi_po, tuple_t>::go(L, tup, ais, ami.rc);
  } else {
    if (ptr_ami.get() == nullptr) { // XXX: f is inner function
      ami.rc = ami.arg_count;       // recover scene limited
    } else {
      ami.rc = luaL_argerror(L, ami.arg_index, ami.extmsg.c_str());
    }
  }

  return ami.rc;
} // xlb_cfunction

//--------------------------------------------------------------------------------------------------
// @struct xlb_ovlfunction
// @brief overload function
//--------------------------------------------------------------------------------------------------
template <lua_CFunction f, lua_CFunction... fcandidate> int xlb_ovlfunction(lua_State *L) {
  xlb_ami ami(lua_gettop(L));
  xlt_call_ovl<f, fcandidate...>::go(L, ami);
  if (xlb_ambad(ami)) {
    ami.rc = luaL_argerror(L, ami.arg_index, ami.extmsg.c_str());
  }
  return ami.rc;
}

//--------------------------------------------------------------------------------------------------
// xlb_fmate help to handle cf's upvalue such as function pointer
//--------------------------------------------------------------------------------------------------

template <class FT> struct xlb_fmate : public xlb_base_func_ptr {
  using self_t = xlb_fmate;
  FT fpointer;
  xlb_fmat_evthandler::ptr_t evtptr;

  xlb_fmate(FT f = nullptr, xlb_fmat_evthandler *evt = nullptr) : fpointer(f) { evtptr.reset(evt); }

  virtual int pushupvalue(lua_State *L, xlb_fmat_evthandler *evt = nullptr) override {
    int rc{0};
    auto place = lua_newuserdata(L, sizeof(self_t));
    new (place) self_t(fpointer, evt); // XXX:wrap fpointer as upvalue
    ++rc;
    return rc;
  }

  static FT topointer(lua_State *L, int index) {
    auto p = lua_touserdata(L, lua_upvalueindex(index));
    auto fmat = reinterpret_cast<self_t *>(p);
    assert(fmat != nullptr);
    if (fmat->fpointer == nullptr) {
      if constexpr (!std::is_member_function_pointer_v<FT>) {
        auto evth = fmat->evtptr.get();
        if (evth) {
          if (evth->on_getf) {
            fmat->fpointer = reinterpret_cast<FT>(evth->on_getf(L, evth));
          }
        }
      }
      assert(fmat->fpointer);
    }
    return fmat->fpointer;
  }

  // FT topointer() { return fpointer; }

  XLB_SII newuserdata(lua_State *L, FT f, xlb_fmat_evthandler::ptr_t &fevth) {
    auto place = lua_newuserdata(L, sizeof(self_t));
    new (place) self_t(f, fevth.release()); // XXX:wrap fpointer as upvalue
    return {1};
  }

  XLB_SIT create(FT f) { return xlb_base_func_ptr::ptr_t(new self_t(f)); }

}; // xlb_fmate

//--------------------------------------------------------------------------------------------------
// @struct xlb_cbf
// @brief call back function
//--------------------------------------------------------------------------------------------------
template <typename FT, typename... PO> struct xlb_cbf {};

template <typename R, typename... A, class... PO>
struct xlb_cbf<R(__stdcall *)(A...), PO...> : public xlb_base_cbcf {
  inline static lua_State *lua_static{nullptr};
  inline static int id_static{LUA_NOREF};
  virtual void setLua(lua_State *L) override { lua_local = L; }
  virtual void updatestatic(lua_State *L) override {
    lua_static = L;
    id_static = id_local;
  }

  lua_State *lua_local{nullptr};
  int id_local{LUA_NOREF};

  using FT = R (*)(A...);
  using Vt = xpo_get_vter<PO...>;

  ////xlb_cbf(xlb_luafunc&& luaf) { id_local = luaf.ref_id; }
  xlb_cbf(const xlb_luafunc &luaf) { id_local = luaf.ref_id; }
  xlb_cbf(const xlb_cbf &r) { id_local = r.id_local; }
  xlb_cbf(int id) { id_local = id; }
  virtual ~xlb_cbf() {
    assert(lua_local);
    luaL_unref(lua_local, LUA_REGISTRYINDEX, id_local);
  }

  static R cbf_agent(A... a) __attribute__((stdcall)) { // LLVM
    // static R cbf_agent( A... a ) { // MSVC
    auto &L = lua_static;
    assert(L);
    assert(id_static != LUA_REFNIL && id_static != -1);

    auto rc{0};

    lua_rawgeti(L, LUA_REGISTRYINDEX, id_static);
    assert(lua_isfunction(L, -1));
    xlt_each{(xlb_at<Vt, A>(a).pusharg(L, rc), XLB_STATEMENT_VALUE)...};
    lua_pcall(L, sizeof...(A), LUA_MULTRET, 0);

    xlb_ami ami{lua_gettop(L)};

    ami.arg_index = lua_gettop(L);
    if constexpr (!std::is_void_v<R>) {
      xlb_at<Vt, R> r;
      r.getarg(L, ami);
      return (R &)r;
    }
  }

}; // xlb_cbf

//--------------------------------------------------------------------------------------------------
#ifndef _WIN64
template <typename R, typename... A, class... PO>
struct xlb_cbf<R (*)(A...), PO...> : public xlb_base_cbcf {
  inline static lua_State *lua_static{nullptr};
  inline static int id_static{LUA_NOREF};
  virtual void setLua(lua_State *L) override { lua_local = L; }
  virtual void updatestatic(lua_State *L) override {
    lua_static = L;
    id_static = id_local;
  }

  lua_State *lua_local{nullptr};
  int id_local{LUA_NOREF};

  using FT = R (*)(A...);
  using Vt = xpo_get_vter<PO...>;

  xlb_cbf(xlb_luafunc &&luaf) { id_local = luaf.ref_id; }
  xlb_cbf(int id) { id_local = id; }
  virtual ~xlb_cbf() {
    assert(lua_local);
    luaL_unref(lua_local, LUA_REGISTRYINDEX, id_local);
  }

  static R cbf_agent(A... a) {
    auto &L = lua_static;
    assert(L);
    assert(id_static != LUA_REFNIL && id_static != -1);

    auto rc{0};

    lua_rawgeti(L, LUA_REGISTRYINDEX, id_static);
    assert(lua_isfunction(L, -1));
    xlt_each{(xlb_at<Vt, A>(a).pusharg(L, rc), XLB_STATEMENT_VALUE)...};
    lua_pcall(L, sizeof...(A), LUA_MULTRET, 0);

    xlb_ami ami(lua_gettop(L));

    ami.arg_index = lua_gettop(L);
    if constexpr (!std::is_void_v<R>) {
      xlb_at<Vt, R> r;
      r.getarg(L, ami);
      // using x = BOOL (CALLBACK* )(HWND, LPARAM);
      // xlb_debug("(%d,%s)\n", (R&)r, typeid(R).name());
      // xlb_debug("(%d,%s)\n", (R&)r, typeid(HWND).name());
      // xlb_debug("(%s)\n", typeid(x).name());
      return (R &)r;
    }
  }

}; // xlb_cbf

#endif

//--------------------------------------------------------------------------------------------------
// @struct xlb_f2cf_pure
// @brief no upvalue for cfunction
//--------------------------------------------------------------------------------------------------
template <auto f, class... PO> int xlb_f2cf_pure(lua_State *L) {
  using Vt = xpo_get_vter<PO...>;
  using Dft = xpo_get_default<PO...>;
  using rpi_po = xpo_get_rier<PO...>;

  using FT = decltype(f);
  using forge_t = xlb_typeforge<Vt, FT>;
  using tuple_t = typename forge_t::tuple_t;
  using idx_t = typename forge_t::idx_t;
  using param_t = typename forge_t::param_t;
  using rv_t = typename forge_t::rv_t;
  using rv_at = typename forge_t::rv_at;
  using obj_t = typename forge_t::obj_t;
  using arginfo_t = typename forge_t::arginfo_t;
  using const_t = typename forge_t::const_t;

  arginfo_t ais;
  tuple_t tup;
  xlb_ami ami(lua_gettop(L));
  ami.param_count = param_t::size;

  // maybe obj_t == void
  xlb_selfobj<obj_t, const_t>::go(L, tup, ami, ais);

  if (!xlb_ambad(ami)) {
    xlb_getargs<tuple_t, idx_t, Dft>::go(L, tup, ais, ami);
  }

  if (xlb_ambad(ami)) {
    return luaL_argerror(L, ami.arg_index, ami.extmsg.c_str());
  }

  ami.rc = 0;
  xlb_invoke::template xlb_tir<
      rv_t, std::is_void_v<rv_t>, rv_at, obj_t, std::is_void_v<obj_t>, FT, idx_t, param_t,
      xlb_rv2l>::go(L, ami, f, tup);

  xlb_pushfrv::template xlb_tir<rpi_po, tuple_t>::go(L, tup, ais, ami.rc);
  // xlb_debug("%d\n", ami.rc);
  return ami.rc;

} // xlb_f2cf_pure

//--------------------------------------------------------------------------------------------------
// @struct xlb_f2cf_ovlcand
// @brief overload functions candidate
//--------------------------------------------------------------------------------------------------
template <auto f, class... PO> int xlb_f2cf_ovlcand(lua_State *L) {
  using Vt = xpo_get_vter<PO...>;
  using Dft = xpo_get_default<PO...>;
  using rpi_po = xpo_get_rier<PO...>;

  using FT = decltype(f);
  using forge_t = xlb_typeforge<Vt, FT>;
  using tuple_t = typename forge_t::tuple_t;
  using idx_t = typename forge_t::idx_t;
  using param_t = typename forge_t::param_t;
  using rv_t = typename forge_t::rv_t;
  using rv_at = typename forge_t::rv_at;
  using obj_t = typename forge_t::obj_t;
  using arginfo_t = typename forge_t::arginfo_t;
  using const_t = typename forge_t::const_t;

  arginfo_t ais;
  tuple_t tup;

  // get ami, first upvalue is xlb_ami with inner function
  // if get ami, means f is a inner function
  auto p_ami = xlb_aspointer<xlb_ami *>(L, lua_upvalueindex(XLB_UPVALUE_1));
  std::unique_ptr<xlb_ami> ptr_ami;
  if (nullptr == p_ami) {
    ptr_ami.reset(new xlb_ami(lua_gettop(L)));
    p_ami = ptr_ami.get();
  }
  auto &ami{*p_ami};

  ami.arg_index = 1; // update
  ami.param_count = param_t::size;

  xlb_selfobj<obj_t, const_t>::go(L, tup, ami, ais);

  if (xlb_amgood(ami)) {
    xlb_getargs<tuple_t, idx_t, Dft>::go(L, tup, ais, ami);
  }

  if (xlb_amgood(ami)) {
    xlb_invoke::template xlb_tir<
        rv_t, std::is_void_v<rv_t>, rv_at, obj_t, std::is_void_v<obj_t>, FT, idx_t, param_t,
        xlb_rv2l>::go(L, ami, f, tup);
    xlb_pushfrv::template xlb_tir<rpi_po, tuple_t>::go(L, tup, ais, ami.rc);
  } else {
    if (nullptr == ptr_ami.get()) { // f is inner function ( get xlb_ami upvalue )
      ami.rc = 0;                   // next function's arguments is copyed by xlb_ovlfsagent
    } else {
      ami.rc = luaL_argerror(L, ami.arg_index, ami.extmsg.c_str());
    }
  }
  return ami.rc;

} // xlb_f2cf_ovlcand

//--------------------------------------------------------------------------------------------------
// @struct xlb_f2cf_upvalue
// @brief with upvalue
//--------------------------------------------------------------------------------------------------
template <class FT, /*FT f,*/ class... PO> int xlb_f2cf_upvalue(lua_State *L) {
  using Vt = xpo_get_vter<PO...>;
  using def_po = xpo_get_default<PO...>;
  using rpi_po = xpo_get_rier<PO...>;

  using forge_t = xlb_typeforge<Vt, FT>;
  using tuple_t = typename forge_t::tuple_t;
  using idx_t = typename forge_t::idx_t;
  using param_t = typename forge_t::param_t;
  using rv_t = typename forge_t::rv_t;
  using rv_at = typename forge_t::rv_at;
  using obj_t = typename forge_t::obj_t;
  using arginfo_t = typename forge_t::arginfo_t;
  using const_t = typename forge_t::const_t;

  arginfo_t ais;
  tuple_t tup;
  xlb_ami ami(lua_gettop(L));
  ami.param_count = param_t::size;

  xlb_selfobj<obj_t, const_t>::go(L, tup, ami, ais);

  if (xlb_amgood(ami)) {
    xlb_getargs<tuple_t, idx_t, def_po>::go(L, tup, ais, ami);
  }
  if (xlb_ambad(ami)) {
    xlb_debug("%s\n", ami.extmsg.c_str());
    return luaL_argerror(L, ami.arg_index, ami.extmsg.c_str());
  }

  auto f = xlb_fmate<FT>::topointer(L, XLB_UPVALUE_1);

  ami.rc = 0;
  xlb_invoke::template xlb_tir<
      rv_t, std::is_void_v<rv_t>, rv_at, obj_t, std::is_void_v<obj_t>, FT, idx_t, param_t,
      xlb_rv2l>::go(L, ami, f, tup);

  xlb_pushfrv::template xlb_tir<rpi_po, tuple_t>::go(L, tup, ais, ami.rc);
  // xlb_debug("ami.rc=%d\n", ami.rc);
  return ami.rc;

} // xlb_f2cf_upvalue

//--------------------------------------------------------------------------------------------------
//  module namespace
//--------------------------------------------------------------------------------------------------
struct xlb_module;
struct xlb_ns;

//--------------------------------------------------------------------------------------------------
struct xlb_regitem {
  std::string name;
  xlb_regitem(const char *n = "") : name(n) {}
  // virtual void registry(xlb_ns *ns) {}
  virtual void registry(xlb_ns *ns) = 0;
}; // xlb_regitem

//--------------------------------------------------------------------------------------------------
struct xlb_regchain : public std::vector<xlb_regitem *> {
  template <class... T> xlb_regchain(const T &...regitem) {
    xlt_each{(push_back((xlb_regitem *)&regitem), XLB_STATEMENT_VALUE)...};
  }
}; // xlb_regchain

//--------------------------------------------------------------------------------------------------
struct xlb_ns {
  lua_State *lua{nullptr};
  const char *table_name{(const char *)nullptr};
  int luaIndex = 0;
  int parentTableIndex = 0;
}; // xlb_ns

//--------------------------------------------------------------------------------------------------
template <typename FT, class... PO> struct xlb_function : public xlb_regitem {
  using rr_t = xlb_function &&;
  FT fpointer;
  xlb_fmat_evthandler::ptr_t fevth;

  xlb_function(const char *fn, FT f, xlb_fmat_evthandler *feh = nullptr)
      : xlb_regitem(fn), fpointer(f), fevth(feh) {}

  virtual ~xlb_function() {}

  virtual void registry(xlb_ns *ns) override {
    assert(ns);
    auto &L = ns->lua;
    lua_pushstring(L, name.c_str());
    auto count_upvalue = xlb_fmate<FT>::newuserdata(L, fpointer, fevth);
    lua_pushcclosure(L, xlb_f2cf_upvalue<FT, PO...>, count_upvalue);
    lua_rawset(L, ns->luaIndex);
  }

}; // xlb_function

//--------------------------------------------------------------------------------------------------
struct xlb_function_ovl : public xlb_regitem {
  using rr_t = xlb_function_ovl &&;
  xlb_ovlfs_t fs;

  xlb_function_ovl(const char *fn, xlb_ovlfs_t &&fs_) : xlb_regitem(fn), fs(std::move(fs_)) {}
  virtual ~xlb_function_ovl() {}
  virtual void registry(xlb_ns *ns) override {
    assert(ns);
    auto &L{ns->lua};
    lua_pushstring(L, name.c_str());

    auto place{lua_newuserdata(L, sizeof(fs))};
    new (place) xlb_ovlfs_t(std::move(fs));

    auto count_upvalue{1};
    lua_pushcclosure(L, xlb_ovlfsagent, count_upvalue);
    lua_rawset(L, ns->luaIndex);
  }

}; // xlb_function_ovl

//--------------------------------------------------------------------------------------------------
struct xlb_cf : public xlb_regitem {
  using rr_t = xlb_cf &&;
  lua_CFunction fpointer;

  xlb_cf(const char *fn, lua_CFunction cf) : xlb_regitem(fn), fpointer(cf) {}

  virtual ~xlb_cf() {}

  virtual void registry(xlb_ns *ns) override {
    auto &L = ns->lua;
    lua_pushstring(L, name.c_str());
    lua_pushcfunction(L, fpointer);
    lua_rawset(L, ns->luaIndex);
  }

}; // xlb_cf

//--------------------------------------------------------------------------------------------------
template <typename FT, typename... PO>
auto xlb_f(
    const char *fn, FT f, std::enable_if_t<std::is_function_v<std::remove_pointer_t<FT>>> * = 0) {
  return xlb_function<FT, PO...>(fn, f);
}

template <typename FT, typename... PO>
auto xlb_f(
    const char *fn, FT f, xlb_fmat_evthandler *evth,
    std::enable_if_t<std::is_function_v<std::remove_pointer_t<FT>>> * = 0) {
  return xlb_function<FT, PO...>(fn, f, evth);
}

static auto xlb_f(const char *fn, lua_CFunction f) { return xlb_cf(fn, f); }

#define xlb_func(f) xlb_f(#f, f)

//--------------------------------------------------------------------------------------------------
template <typename Lambda> struct xlt_lambda {
  template <typename T> struct deduce_type {};
  template <typename R, typename obj_t, typename... A>
  struct deduce_type<R (obj_t::*)(A...) const> {
    using type = R (*)(A...);
  };
  using type = xlb_t<deduce_type<Lambda>>;
};

template <typename Lambda>
auto xlb_f(
    const char *fn, Lambda lambda,
    std::enable_if_t<!std::is_function_v<std::remove_pointer_t<Lambda>>> * = 0) {
  using lambda_ft = xlb_t<xlt_lambda<decltype(&Lambda::operator())>>;
  return xlb_function<lambda_ft>(fn, (lambda_ft)lambda);
}

//--------------------------------------------------------------------------------------------------
template <typename Lambda> static constexpr auto xlb_lambda2f(const Lambda &t) {
  using f_type = xlb_t<xlt_lambda<decltype(&Lambda::operator())>>;
  return (f_type)t;
}

// static lua_CFunction xlb_magicf2cf_ovl( lua_CFunction f ) { return f; }

template <typename Lambda>
lua_CFunction xlb_magicf2cf_ovl(
    Lambda f, std::enable_if_t<!std::is_function_v<std::remove_pointer_t<Lambda>>> * = 0) {
  return xlb_f2cf_ovlcand<xlb_lambda2f(f)>;
}

template <typename FT, std::enable_if_t<std::is_function_v<std::remove_pointer_t<FT>>> * = 0>
lua_CFunction xlb_magicf2cf_ovl(FT f) {
  return xlb_f2cf_ovlcand<f>;
}

template <typename F1, typename F2, typename... Fs>
auto xlb_f(const char *fn, F1 f1, F2 f2, Fs... fs) {
  // XXX: do not use lambda in unevaluation context ( function's signature )
  xlb_ovlfs_t v{xlb_magicf2cf_ovl(f1), xlb_magicf2cf_ovl(f2)};
  xlt_each{(v.push_back(xlb_magicf2cf_ovl(fs)), XLB_STATEMENT_VALUE)...};
  return xlb_function_ovl(fn, std::move(v));
}

//--------------------------------------------------------------------------------------------------
template <typename Lambda> struct xlt_lambda2cf_pure {
  static constexpr lua_CFunction cast(Lambda f) { return xlb_f2cf_pure<xlb_lambda2f(f)>; }
};

//--------------------------------------------------------------------------------------------------
// xlb_propgetter
//--------------------------------------------------------------------------------------------------
template <class Pro_t> struct xlb_propforge {};

template <class P, class Tx> struct xlb_propforge<P Tx::*> {
  using obj_t = Tx;
  using property_t = P;
};

template <typename Vt, typename Prop_t>
XLB_SIV xlb_pushprop(lua_State *L, Prop_t &prop, int &rc, xlf_prop vor) {
  if (xlf_prop::smart == vor) {
    // xlb_debug("smart\n");
    if constexpr (is_lstruct_v<Vt, xlb_at<Vt, Prop_t>>) {
      vor = xlf_prop::byref;
    } else {
      vor = xlf_prop::byval;
    }
  }

  if (xlf_prop::byref == vor) {
    // xlb_debug("byref\n");
    using Prop_AT = xlb_at<Vt, std::add_lvalue_reference_t<Prop_t>>;
    Prop_AT agent{&prop};
    agent.pusharg(L, rc);
  }

  if (xlf_prop::byval == vor) {
    // xlb_debug("byval\n");
    using Prop_AT = xlb_at<Vt, Prop_t>;
    Prop_AT agent{prop};
    agent.pusharg(L, rc);
  }
} // xlb_pushprop

template <class Prop_t, class... PO>
int xlb_propgetter(
    lua_State *L, void *vmate,
    xlf_prop vor = xlf_prop::smart) { // t,k
  auto rc{0};
  using Vt = xpo_get_vter<PO...>;
  using forge_t = xlb_propforge<Prop_t>;
  using obj_t = typename forge_t::obj_t;
  using property_t = typename forge_t::property_t;

  auto pobj{xlb_toself<obj_t>(L, 1)};
  auto p2prop = xlb_propmate<Prop_t>::get(vmate);
  xlb_pushprop<Vt, property_t>(L, (pobj->*p2prop), rc, vor);
  return rc;
} // xlb_propgetter

template <class Prop_t, class... PO>
int xlb_propsetter(
    lua_State *L, void *vmate,
    xlf_prop vor = xlf_prop::byval) { // t,k,v
  using Vt = xpo_get_vter<PO...>;
  using forge_t = xlb_propforge<Prop_t>;
  using obj_t = typename forge_t::obj_t;
  using property_t = typename forge_t::property_t;
  using property_at = xlb_at<Vt, property_t>;

  constexpr const auto vindex{3}; // 1:t,2:k,3:v

  auto wp{xlb_towrap<obj_t>(L, 1)};
  // xlb_debug("%p,%d,%d\n", wp, xlb_wpisconst(wp),
  // std::is_const_v<property_t>);

  if constexpr (!std::is_const_v<property_t>) {
    if (wp && !xlb_wpisconst(wp)) {
      auto pobj{xlb_getwppointer<obj_t *>(wp)};
      assert(pobj);

      auto p2prop{xlb_propmate<Prop_t>::get(vmate)};
      auto &left{((*pobj).*p2prop)};

      xlb_ami ami(lua_gettop(L));
      ami.obj = pobj;
      ami.arg_index = vindex;

      if constexpr (std::is_array_v<property_t>) {
        ami.raw_left = reinterpret_cast<void *>(&left);
        property_at v;
        v.getarg(L, ami);

        using e_t = std::remove_extent_t<property_t>;
        e_t *right{v};
        // xlb_debug("%s\n", typeid(decltype(right)).name());
        if (!ami.raw_left) {
          xlb_assignarrary<std::extent_v<property_t, 0>>::go(left, right);
        }
      } else {
        property_at v;
        v.getarg(L, ami);
        auto &right{(property_t &)v};
        left = right;
        // xlb_debug("obj=%p\n", pobj);
      }
    } else { /* do nothing for const member */
    }
  }

  return 0;
} // xlb_propsetter

//--------------------------------------------------------------------------------------------------
//  @struct xlb_property
//  @brief property include function and member, read write flag
//--------------------------------------------------------------------------------------------------

struct xlb_property : public xlb_base_property {
  using self_t = xlb_property;
  using rr_t = xlb_property &&;

  xlb_prophandler getter;
  xlb_prophandler setter;
  xlb_funchandler funcer;

  xlb_property() = default;
  xlb_property(const xlb_property &r)
      : getter(std::move(r.getter)), setter(std::move(r.setter)), funcer(std::move(r.funcer)) {}
  self_t &operator=(xlb_property &&r) = default;
  virtual ~xlb_property() = default;

  template <typename Prop_t, typename... PO> static ptr_t create(Prop_t prop, xpo_readonly) {
    auto temp = std::make_unique<xlb_property>();
    temp->type = xlb_base_property::readonly;
    temp->getter = xlb_prophandler(xlb_propgetter<Prop_t, PO...>, xlb_makepropptr(prop));
    return std::move(temp);
  }

  template <typename Prop_t, typename... PO> static ptr_t create(Prop_t prop, xpo_none) {
    auto temp = std::make_unique<xlb_property>();
    temp->type = xlb_base_property::readwrite;
    temp->getter = xlb_prophandler(xlb_propgetter<Prop_t, PO...>, xlb_makepropptr(prop));
    temp->setter = xlb_prophandler(xlb_propsetter<Prop_t, PO...>, xlb_makepropptr(prop));
    return std::move(temp);
  }

  template <typename FT> static ptr_t create(lua_CFunction cf, FT f) {
    auto temp = std::make_unique<xlb_property>();
    temp->type = xlb_base_property::function;
    temp->funcer = xlb_funchandler(cf, xlb_makefuncptr(f));
    return std::move(temp);
  }

  static ptr_t create(lua_CFunction cf) {
    auto temp = std::make_unique<xlb_property>();
    temp->type = xlb_base_property::function;
    temp->funcer = xlb_funchandler(cf, xlb_makefuncptr(nullptr));
    return std::move(temp);
  }

  virtual int do_get(lua_State *L, xlf_prop flag) override { return getter(L, flag); }
  virtual int do_set(lua_State *L, xlf_prop flag) override { return setter(L, flag); }
  virtual int do_func(lua_State *L, xlf_prop flag) override { return funcer(L, flag); }

}; // xlb_property

//--------------------------------------------------------------------------------------------------
#define XLB_BF3ARG(T, b) #b, [](T * obj) { return obj->b; }, [](T * obj, int64_t v) { obj->b = v; }

struct xlb_bitfieldprop : public xlb_base_property {
  using self_t = xlb_bitfieldprop;
  using rr_t = xlb_bitfieldprop &&;

  lua_CFunction reader;
  lua_CFunction writer;

  template <typename Reader_t, typename Writer_t> static ptr_t create(Reader_t r, Writer_t w) {
    auto temp = std::make_unique<xlb_bitfieldprop>();
    temp->type = xlb_base_property::bitfield;
    temp->reader = xlt_lambda2cf_pure<Reader_t>::cast(r);
    temp->writer = xlt_lambda2cf_pure<Writer_t>::cast(w);
    return std::move(temp);
  }

  xlb_bitfieldprop() = default;
  xlb_bitfieldprop(const xlb_bitfieldprop &another) {
    reader = another.reader;
    writer = another.writer;
  }
  self_t &operator=(xlb_bitfieldprop &&r) = default;
  virtual ~xlb_bitfieldprop() = default;
  virtual int do_get(lua_State *L, xlf_prop flag) override {
    auto rc{0};
    if (reader && 2 == lua_gettop(L)) { // ud,k
      lua_pop(L, 1);
      rc = reader(L);
    }
    return rc;
  }
  virtual int do_set(lua_State *L, xlf_prop flag) override {
    auto rc{0};
    xlb_debug("(%d)\n", lua_gettop(L));
    if (writer && 3 == lua_gettop(L)) { // ud,k,v
      lua_remove(L, -2);
      rc = writer(L);
    }
    return rc;
  }
};
//--------------------------------------------------------------------------------------------------
struct xlb_namespace : public xlb_ns, public xlb_regitem {
  xlb_regchain chain;
  xlb_namespace(const char *space_name = nullptr) : xlb_regitem(space_name) {
    xlb_ns::table_name = space_name;
    assert(nullptr != table_name); ///< name of namespace expected
  }

  virtual void registry(xlb_ns *parentNS) override {
    auto L = parentNS->lua;
    xlb_ns::lua = L;
    lua_pushstring(L, table_name);
    lua_newtable(L);
    luaIndex = lua_gettop(L);

    for (auto &reg : chain) {
      reg->registry(this);
    }
    lua_rawset(L, parentNS->luaIndex);
  }

  xlb_namespace &operator()(xlb_regchain &&items) {
    chain = std::move(items);
    return (*this);
  }

}; // xlb_namespace

//--------------------------------------------------------------------------------------------------
struct xlb_const : public xlb_regitem {
  uint32_t vtype;
  union {
    uint64_t cv{0};     // 0
    const char *cs;     // 1
    const wchar_t *wcs; // 2
    struct {
      const void *p;
      unsigned len;
    } blk; // 3
  };

  template <class T>
  xlb_const(
      const char *name, T v, std::enable_if_t<std::is_integral_v<T> || std::is_enum_v<T>> * = 0)
      : xlb_regitem(name), cv(v), vtype(0) {}
  xlb_const(const char *name, const char *v) : xlb_regitem(name), vtype(1), cs(v) {}
  xlb_const(const char *name, const wchar_t *v) : xlb_regitem(name), vtype(2), wcs(v) {}
  template <class T>
  xlb_const(
      const char *name, const T &v, unsigned len = sizeof(T),
      std::enable_if_t<std::is_class_v<T>> * = 0)
      : xlb_regitem(name), blk{&v, len}, vtype(3) {}

  virtual void registry(xlb_ns *parentNS) override {
    auto L{parentNS->lua};
    lua_pushstring(L, name.c_str());
    switch (vtype) {
    case 0:
      lua_pushinteger(L, cv);
      break;
    case 1:
      lua_pushstring(L, cs);
      break;
    case 2:
      lua_pushlstring(L, reinterpret_cast<const char *>(wcs), wcslen(wcs) * sizeof(wchar_t));
      break;
    case 3:
      lua_pushlstring(L, reinterpret_cast<const char *>(blk.p), blk.len);
      break;
    default:
      lua_pushnil(L);
      break;
    }
    lua_rawset(L, parentNS->luaIndex);
  }
};

//--------------------------------------------------------------------------------------------------
template <typename T, typename Vt = xlb_vter> struct xlb_cref : public xlb_regitem {
  const T &cv;

  xlb_cref(const char *name, const T &v) : xlb_regitem(name), cv(v){};

  virtual void registry(xlb_ns *parentNS) override {
    auto L{parentNS->lua};
    lua_pushstring(L, name.c_str());
    using cv_at = xlb_at<Vt, decltype(cv)>;
    // using cv_at  = xlb_at<Vt, const T*>;
    cv_at v{&cv};
    auto rc{0};
    v.pusharg(L, rc);
    lua_rawset(L, parentNS->luaIndex);
  }
};

//--------------------------------------------------------------------------------------------------
struct xlb_module : public xlb_ns, public xlb_regitem {
  xlb_module(lua_State *L, const char *table_name = nullptr, int pti = 0) {
    xlb_ns::table_name = table_name;
    xlb_ns::lua = L;
    xlb_ns::parentTableIndex = pti;
  }

  xlb_module &operator()(const xlb_regchain &chain) {
    auto &L = xlb_ns::lua;
    auto &moduleName = xlb_ns::table_name;

    auto havemodule = false;
    if (moduleName) {
      if (0 != parentTableIndex) {
        lua_pushstring(L, moduleName);
        lua_gettable(L, parentTableIndex);
      } else {
        lua_getglobal(L, moduleName);
      }
      havemodule = (lua_type(L, -1) == LUA_TTABLE);
      if (!havemodule)
        lua_pop(L, 1);
    }

    if (!havemodule) {
      if (nullptr != moduleName) {
        lua_pushstring(L, moduleName);
      }
      lua_newtable(L);
    }

    luaIndex = lua_gettop(L);
    for (auto &item : chain) {
      // xlb_debug("%p\n", &item);
      item->registry(this);
    }

    if (!havemodule && (nullptr != moduleName)) {
      if (0 != parentTableIndex) {
        if (parentTableIndex < 0)
          parentTableIndex -= 2;
        lua_rawset(L, parentTableIndex);
      } else {
        lua_setglobal(L, moduleName);
        lua_pop(L, 1); // the table name that have been pushed
      }
    }
    return (*this);
  }

  virtual void registry(xlb_ns *ns) override {}

}; // xlb_module

//--------------------------------------------------------------------------------------------------
//  xlb_base_class
//--------------------------------------------------------------------------------------------------
template <typename X> struct xlb_base_class : public xlb_regitem {
  using self_t = xlb_base_class;
  using rr_t = self_t &&;
  using this_t = self_t *;
  inline static xlb_meta_t metaName{nullptr};
  inline static xlb_meta_t typeName{nullptr};
  inline static std::string metaNameBuf{};
  inline static std::string typeNameBuf{};
  inline static xlb_metas_t superNames{};
  inline static xlb_regs_t metaFuncs{};
  inline static xlb_regs_t typeTable{};
  inline static xlb_cfs_t upvalueFuncs{};
  inline static xlb_member_t memberMap{};
  inline static xlb_static_member_t staticmemberMap{};

  // xlb_f2cf_static
  template <class FT, /*FT f,*/ class... PO> static int xlb_f2cf_static(lua_State *L) {
    using Vt = xpo_get_vter<PO...>;
    using Dft = xpo_get_default<PO...>;
    using rpi_po = xpo_get_rier<PO...>;

    using forge_t = xlb_typeforge<Vt, FT>;
    using tuple_t = typename forge_t::tuple_t;
    using idx_t = typename forge_t::idx_t;
    using param_t = typename forge_t::param_t;
    using rv_t = typename forge_t::rv_t;
    using rv_at = typename forge_t::rv_at;
    using obj_t = typename forge_t::obj_t;
    using arginfo_t = typename forge_t::arginfo_t;
    using const_t = typename forge_t::const_t;

    arginfo_t ais;
    tuple_t tup;
    xlb_ami ami(lua_gettop(L));
    ami.param_count = param_t::size;

    xlb_selfobj<obj_t, const_t>::go(L, tup, ami, ais);

    if (!xlb_ambad(ami)) {
      xlb_getargs<tuple_t, idx_t, Dft>::go(L, tup, ais, ami);
    }

    if (xlb_ambad(ami)) {
      return luaL_argerror(L, ami.arg_index, ami.extmsg.c_str());
    }

    auto f = xlb_fmate<FT>::topointer(L, XLB_UPVALUE_1);

    ami.rc = 0;
    xlb_invoke::template xlb_tir<
        rv_t, std::is_void_v<rv_t>, rv_at, obj_t, std::is_void_v<obj_t>, FT, idx_t, param_t,
        xlb_rv2l>::go(L, ami, f, tup);

    xlb_pushfrv::template xlb_tir<rpi_po, tuple_t>::go(L, tup, ais, ami.rc);
    return ami.rc;

  } // xlb_f2cf_static

  static int index_handler(lua_State *L) { ///< __index(ud,k)
    auto key = lua_tostring(L, 2);
    if (!key)
      key = "";

    auto prop_flag{xlf_prop::smart}; // not byval

    ///< XXX:Rule, when key has prefix '&', return property's reference
    if (key[0] == '&') {
      prop_flag = xlf_prop::byref;
      ++key;
    }

    auto iter{memberMap.find(key)};
    auto nfound = 0;
    if (iter != memberMap.end()) {
      auto &prop = (*iter->second.get());
      switch (prop.type) {
      case xlb_base_property::readonly:
      case xlb_base_property::readwrite:
        nfound = prop.do_get(L, prop_flag);
        break;
      case xlb_base_property::function:
        nfound = prop.do_func(L, prop_flag);
        break;
      case xlb_base_property::bitfield:
        nfound = prop.do_get(L, prop_flag);
        break;
      }
    }

    if (0 == nfound) {
      // XXX:search getter from super class
      nfound = xlu_search_getter(L, metaName, superNames);
    }
    return nfound;
  } // index_handler

  static int newindex_handler(lua_State *L) { ///< __newindex(ud,k,v)
    auto var_name = lua_tostring(L, 2);
    var_name = (nullptr == var_name) ? "" : var_name;
    auto iter = memberMap.find(var_name);
    auto top = lua_gettop(L);
    int nfound = 0;
    if (iter != memberMap.end()) {
      auto &prop = (*iter->second.get());
      switch (prop.type) {
      case xlb_base_property::writeonly:
      case xlb_base_property::readwrite:
      case xlb_base_property::bitfield:
        prop.do_set(L, xlf_prop::byval);
        lua_pushvalue(L, 1); ////< ud
        nfound = 1;
        break;
      case xlb_base_property::readonly:
        break; // do nothing for readonly
      }
    } // if found

    if (0 == nfound && 0 < superNames.size()) {
      nfound = xlu_search_setter(L, metaName, superNames);
    }
    return nfound;

  } // newindex_handler

  static int typetostring_handler(lua_State *L) {
    auto p = lua_topointer(L, -1);
    lua_pushfstring(L, "(xlb type table: 0x%p)", p);
    return 1;
  }

  static X *f_return_pointer_of_type() { // pointer to type
    return {(X *)nullptr};
  }

  template <typename Super_a, typename... Super_b> auto inherited() {
    superNames.push_back(&xlb_base_class<Super_a>::metaName);
    xlt_each{(superNames.push_back(&xlb_base_class<Super_b>::metaName), XLB_STATEMENT_VALUE)...};
    return std::move(*this);
  }

  // rr_t type_function( const char fn[], lua_CFunction f ) {
  //    typeTable.push_back( { fn, f } );
  //    return std::move( *this );
  //}

  template <typename T> auto type_property(const char *prop_name, T &v) {
    using agent_t = xlb_at<xlb_vter, T>;
    staticmemberMap[prop_name] = make_unique<agent_t>(v);
    return std::move(*this);
  }

  auto constructor(lua_CFunction cf) {
    typeTable.push_back({"__call", cf});
    return std::move(*this);
  }

  template <typename... A> rr_t constructor() {
    typeTable.push_back({"__call", xlb_f2cf_pure<&xlb_ctor<X, A...>>});
    typeTable.push_back({"newinplace", xlb_f2cf_pure<&xlb_ctor_inplace<X, A...>>});
    /** XXX: pointer, such as T* in C++ **/
    typeTable.push_back({"pointertotype", xlb_f2cf_pure<&f_return_pointer_of_type>});
    return std::move(*this);
  }

  template <typename... A> rr_t constructor(xpo_no_newinplace &&) {
    // constexpr lua_CFunction cf = xlb_f2cf_pure<&xlb_ctor<X, A...>>;
    constexpr lua_CFunction cf = xlb_f2cf_pure<&xlb_ctor<X, A...>>;
    typeTable.push_back({"__call", cf});
    return std::move(*this);
  }

  /** XXX: for C style ==> T* f(), f must in template argument **/
  template <X *(*f)(void)> rr_t constructor() {
    constexpr auto ccf = xlb_ctor_c_style<X, f>;
    typeTable.push_back({"__call", xlb_f2cf_pure<ccf>});
    return std::move(*this);
  }

  template <void (*freef)(X *)> rr_t destructor() {
    metaFuncs.push_back({"__gc", xlb_wpdtor<X, freef>});
    return std::move(*this);
  }

  rr_t destructor() {
    metaFuncs.push_back({"__gc", xlb_wpdtor<X>});
    return std::move(*this);
  }

  rr_t method(const char *func_name, lua_CFunction cf) {
    memberMap[func_name] = xlb_property::create(cf);
    return std::move(*this);
  }

  template <typename FT, class... PO> rr_t method(const char *func_name, FT f, PO...) {
    memberMap[func_name] = xlb_property::create(xlb_f2cf_static<FT, PO...>, f);
    return std::move(*this);
  }

  template <auto f, class... PO> rr_t method(const char *func_name, PO...) {
    using FT = decltype(f);
    memberMap[func_name] = xlb_property::create(xlb_f2cf_static<FT, PO...>, f);
    // xlb_debug("(%s)\n", func_name);
    return std::move(*this);
  }

  template <class Prop_t, class... PO> rr_t property(const char prop_name[], Prop_t prop, PO...) {
    using check_po_readonly = xpo_get_readonly<PO...>;
    memberMap[prop_name] = xlb_property::create<Prop_t, PO...>(prop, check_po_readonly());
    return std::move(*this);
  }

  template <typename Reader_t, typename Writer_t>
  rr_t property(
      const char prop_name[], Reader_t reader, Writer_t writer,
      std::enable_if_t<std::is_class_v<std::remove_pointer_t<Reader_t>>> * = 0) {
    memberMap[prop_name] = xlb_bitfieldprop::create(reader, writer);
    return std::move(*this);
  }

  static void registry(lua_State *L, int parentTableIndex = 0) {
    metaFuncs.push_back({"__index", &index_handler});
    metaFuncs.push_back({"__newindex", &newindex_handler});
    metaFuncs.push_back({nullptr, nullptr});
    typeTable.push_back({"__tostring", &typetostring_handler});
    typeTable.push_back({nullptr, nullptr});

    // xlb_debug("(%s)\n", typeName);
    xlu_newtypelib(L, typeName, typeTable, staticmemberMap, xlb_sizeof<X>(), parentTableIndex);
    xlu_newobjmeta(L, metaName, metaFuncs, upvalueFuncs, superNames);

    metaFuncs.clear();
    typeTable.clear();
    staticmemberMap.clear();
  }

  void setup_names(const char *class_name) {
    xlb_regitem::name = class_name;
    metaNameBuf = XLB_META_PREFIX;
    metaNameBuf += class_name;
    typeNameBuf = class_name;
    metaName = metaNameBuf.c_str();
    typeName = typeNameBuf.c_str();
  }

  virtual void registry(xlb_ns *ns) override {}
}; // xlb_base_class

//--------------------------------------------------------------------------------------------------
// xlb_class
//--------------------------------------------------------------------------------------------------
template <typename T> struct xlb_class : public xlb_base_class<T> {
  using rr_t = xlb_class &&;
  using bc_t = xlb_base_class<T>;
  using ri_t = xlb_regitem;

  xlb_class(const char *class_name) {
    bc_t::setup_names(class_name);
    // xlb_debug("(%s)\n", bc_t::typeName);
  }

  virtual ~xlb_class() {}

  xlb_class(xlb_class &&o) = delete;

  virtual void registry(xlb_ns *ns) override {
    // xlb_debug("%p\n", ns);
    bc_t::registry(ns->lua, ns->luaIndex);
  }

}; // xlb_class

//--------------------------------------------------------------------------------------------------
static int xlb_type(lua_State *L) {
  auto rc{1};
  if (auto wp = xlb_touserdata<xlb_base_wrap>(L, 1)) {
    auto fmt = "(0x%p : unknown)";
    switch (wp->tQlf) {
    case xlf_qlf::ref:
      fmt = "(0x%p : T&)";
      break;
    case xlf_qlf::cref:
      fmt = "(0x%p : const T&)";
      break;
    case xlf_qlf::val:
      fmt = "(0x%p : T)";
      break;
    case xlf_qlf::cval:
      fmt = "(0x%p : const T)";
      break;
    case xlf_qlf::cp:
      fmt = "(0x%p : T* const)";
      break;
    case xlf_qlf::p2cv:
      fmt = "(0x%p : const T*)";
      break;
    case xlf_qlf::cp2cv:
      fmt = "(0x%p : const T* const)";
      break;
    case xlf_qlf::vp:
      fmt = "(0x%p : T*)";
      break;
    case xlf_qlf::arrayval:
      fmt = "(0x%p : T[])";
      break;
    case xlf_qlf::carrayval:
      fmt = "(0x%p : const T[])";
      break;
    }
    lua_pushfstring(L, fmt, wp->getpointer());
  } else {
    lua_pushstring(L, lua_typename(L, lua_type(L, -1)));
  }
  return rc;
}

//--------------------------------------------------------------------------------------------------
static int xlb_pvtostring(lua_State *L) {
  using pv_t = void *;
  using lpointer_t = xlb_lpointer<xlb_vter, pv_t, pv_t, std::default_delete<pv_t>>;
  auto rc{1};
  lpointer_t lpointer;
  xlb_ami ami(lua_gettop(L));

  ami.arg_index = 1;
  lpointer.getarg(L, ami);
  if (xlb_ambad(ami)) {
    return luaL_argerror(L, ami.arg_index, ami.extmsg.c_str());
  }
  auto s{reinterpret_cast<const char *>(lpointer.pointer)};
  auto len{(lua_isinteger(L, 2)) ? lua_tointeger(L, 2) : -1};
  (len == -1) ? lua_pushstring(L, s) : lua_pushlstring(L, s, len);
  return rc;
}

//--------------------------------------------------------------------------------------------------
static int xlb_pvtointeger(lua_State *L) {
  using pv_t = void *;
  using lpointer_t = xlb_lpointer<xlb_vter, pv_t, pv_t, std::default_delete<pv_t>>;
  auto rc{1};
  lpointer_t lpointer;
  xlb_ami ami(lua_gettop(L));

  ami.arg_index = 1;
  lpointer.getarg(L, ami);
  if (xlb_ambad(ami)) {
    return luaL_argerror(L, ami.arg_index, ami.extmsg.c_str());
  }
  auto v{lpointer.pointer};
  // xlb_debug("pointer=%p\n", v);
  auto len{(lua_isnumber(L, 2)) ? lua_tointeger(L, 2) : -1};
  switch (len) {
  case 1:
    lua_pushinteger(L, *(int8_t *)v);
    break;
  case 2:
    lua_pushinteger(L, *(int16_t *)v);
    break;
  case 4:
    lua_pushinteger(L, *(int32_t *)v);
    break;
  case 8:
    lua_pushinteger(L, *(int64_t *)v);
    break;
  default:
    --rc;
  }
  return rc;
}

//--------------------------------------------------------------------------------------------------
// custom data type
// for string(char array) with len
struct xlb_lstr {
  const char *pch = nullptr;
  std::size_t len = 0;
};

struct xlb_lstr_agent_t : public xlb_base_agent {
  using vter = xlb_vter;
  using type = xlb_lstr;
  type val;
  xlb_lstr_agent_t(type &r) {
    val.pch = r.pch;
    val.len = r.len;
  }
  xlb_lstr_agent_t(type &&r) {
    val.pch = r.pch;
    val.len = r.len;
  }
  virtual void getarg(lua_State *L, xlb_ami &ami) {
    val.pch = luaL_tolstring(L, ami.arg_index, &val.len);
    ++ami.arg_index;
  }
  virtual void pusharg(lua_State *L, int &rc) {
    lua_pushlstring(L, val.pch, val.len);
    ++rc;
  }
};

template <> struct xlb_vter::xlb_tir<xlb_lstr> {
  using vter = xlb_vter;
  using type = xlb_lstr_agent_t;
};

template <> struct xlb_vter::xlb_tir<xlt_rvtrait<xlb_lstr>> {
  using vter = xlb_vter;
  using type = xlb_lstr_agent_t;
};

//--------------------------------------------------------------------------------------------------
#endif //__XLB_H__
