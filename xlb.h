/** @file xlb.h
 * @brief bind c++ to Lua
 *
 * @author wunoman@qq.com
 * @date 20170219
 */
#ifndef _XLB_H
#define _XLB_H

#include <typeinfo>
#include <iostream>
#include <vector>
#include <assert.h>
#include <cstring>
#include <tuple>
#include <memory>
#include <type_traits>
#include <array>
#include <unordered_map>
#include <functional>

using namespace std;
using namespace std::placeholders;



//XXX:when lua compile with g++ instead gcc, comment this line
extern "C" { 
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
} // lua header files


#ifdef DEBUG
#define xlb_debug(format,...) fprintf(stdout, "    (LINE:%d,%s)" format, __LINE__, __FUNCTION__, ##__VA_ARGS__)
#define xlb_dbg() xlb_debug("\n")
#else
#define xlb_debug(...)
#define xlb_dbg()
#endif


// tir (Type Information Replenish) 类型信息补充

/*---------------------------------------------------------------------------
xlt_each
-----------------------------------------------------------------------------*/
struct xlt_each
{ 
  template<class ...T> xlt_each(T...) {} 
};


/*---------------------------------------------------------------------------
xlt_typelist
-----------------------------------------------------------------------------*/
template<typename...T> struct xlt_typelist 
{
  static int const size = sizeof...(T);
};

/*---------------------------------------------------------------------------
xlt_createindexer
-----------------------------------------------------------------------------*/
template<int...> struct xlb_idxer{}; 

template<int, class Idxer, int> 
struct xlt_createindexer;

template<int I, int...Idxs, int RM> struct xlt_createindexer<I, xlb_idxer<Idxs...>, RM> 
{
  using type = typename 
    xlt_createindexer<I+1, xlb_idxer<Idxs..., I>, RM-1>::type;
};

template<int I, int...Idxs> struct xlt_createindexer<I, xlb_idxer<Idxs...>, 0> 
{
  typedef xlb_idxer<Idxs...> type;
};

///<XXX:index sequence zero-based
template<typename ...Types> struct xlb_toidxer
  : xlt_createindexer<0, xlb_idxer<>, sizeof...(Types)> 
{};


template<int...RPI> using xlb_rpi = xlb_idxer<RPI...>; // xlb_idxer alias

/**--------------------------------------------------------------------------
 * @struct xlb_ai
 * argument info, the argument value loaded from Lua
 * 一个函数的参数需要从Lua中获取[from, to)范围内参数，解除了参数一对一关系
-----------------------------------------------------------------------------*/
struct xlb_ai 
{
  int from  = 0;    ///< Lua栈索引,参数从第几个栈元素开始提取数据
  int to    = 0;    ///< 参数提取的数据跨过多少个栈元素
  int type  = 0;    ///< 栈元素类型,Lua数据类型
  int index = 0;    ///< 第几个参数,从1开始计数(与ami.arg_index不同,它是0开始计数)
};

enum class xlb_flag : int 
{
  gc                   = 1,       ///< gc in lua
  not_gc               = 0,       ///< do not gc in lua

  var_obj              = 0x0,     ///< T&
  const_obj            = 0x1,     ///< const T&

  const_pointer        = 0x00002, ///< T* const
  const_pvalue         = 0x00004, ///< const T*
  const_pandv          = 0x00008, ///< const T* const
  var_pointer          = 0x00010, ///< T*

  object               = 0x10000,
  pointer              = 0x20000,

  property_byref       = 0x200000, ///< 返回属性的引用
  property_byval       = 0x400000, ///< 如果可以返回值的,返回属性的值
}; // xlb_flag

/*---------------------------------------------------------------------------
predeclare
-----------------------------------------------------------------------------*/
template<typename X> struct xlb_base_class;
template<typename X> struct xlb_class;
template<typename F> struct xlb_fpartner;
template<typename T, typename VTER> struct xlb_lpointer {};

struct xlb_vter;
struct xlb_util;
struct xlb_property;

struct xlb_notpointer
{
  using type = void;
  xlb_notpointer(const int* p=nullptr) {}
  void pusharg(lua_State* L, const xlb_ai& ai, int& rc, xlb_flag gc=xlb_flag::not_gc) 
  {
    xlb_dbg();
  }
};

template<typename T, 
    typename AT=xlb_notpointer, 
    typename DEL=std::default_delete<T>
    > class xlb_wrap;


template<typename VTER, typename T>
using xlb_getagenttype = typename VTER::template xlb_tir<T>::type;


/*---------------------------------------------------------------------------
help struct
-----------------------------------------------------------------------------*/
struct xlb_djy {}; // 打酱油
//struct xlb_default_policy {};

struct xpo_base_rier {};
struct xpo_base_vter {};
struct xpo_base_dfer {};

struct xpo_none {}; ///< XXX:指定的PO不存在则返回此类型
struct xpo_base_readonly {};
struct xpo_readonly : public xpo_base_readonly {};


/*---------------------------------------------------------------------------
xlb help template
-----------------------------------------------------------------------------*/
template<typename Base, typename Condition, typename ...T>
struct xlt_search_derived {};

template<typename Base, typename Typelist>
struct xlb_getderived 
{
  using type = void;
};

template<typename BASE>
struct xlb_getderived<BASE, xlt_typelist<>> 
{
  using type = void;
};

template<typename Base, typename Head, typename ...Tail>
struct xlb_getderived<Base, xlt_typelist<Head, Tail...>> 
{
  using type = typename xlt_search_derived<
        Base, 
        typename std::is_base_of<Base, Head>::type, 
        Head, 
        Tail...
        >::type;
};

template<typename Base, typename H, typename ...T>
struct xlt_search_derived<Base, false_type, H, T...> 
{
  using type = typename xlb_getderived<Base, xlt_typelist<T...>>::type;
};

template<typename Base, typename H, typename ...T>
struct xlt_search_derived<Base, true_type, H, T...> 
{
  using type = H;
};


/*---------------------------------------------------------------------------
MACRO
-----------------------------------------------------------------------------*/
#define luaL_reg luaL_Reg
#define XLB_TRAP_FLAG            0xFF
#define XLB_EXISTS_FLAG          0x1

#define XLB_META_PREFIX          "xlb_meta_"
#define XLB_STATEMENT_VALUE      1

#define XLB_SIV static inline void 
#define XLB_SII static inline int 
#define XLB_SIT static inline auto 

/*---------------------------------------------------------------------------
@struct xlb_base_fptr
@brief base struct for function pointer, NEE this without pointer type information
-----------------------------------------------------------------------------*/
struct xlb_base_fptr
{
  using ptr_t = std::unique_ptr<xlb_base_fptr>;
  using onregistry_t = int (*)(lua_State* L, xlb_base_fptr*);

  /** @brief 当把函数指针做为upvalue压栈时,提供一次机会,可以压入其实upvalue
   * @retval 返回压入栈upvalue的个数
   */
  onregistry_t onregistry;

  xlb_base_fptr(onregistry_t callback=nullptr) 
    : onregistry(callback) 
  {}

  virtual int pushupvalue(lua_State* L) { return 0; }
  virtual ~xlb_base_fptr() {}
}; // xlb_base_fptr


/*---------------------------------------------------------------------------
xlb_ppartner 属性指针
-----------------------------------------------------------------------------*/
struct xlb_base_pptr
{
  using ptr_t = std::unique_ptr<xlb_base_pptr>;
};

template<class PROP_T>
struct xlb_ppartner : public xlb_base_pptr
{
  PROP_T p2prop;
  xlb_ppartner(PROP_T p=nullptr) : p2prop(p) {}

  XLB_SIT get(void* vp)
  {
    return reinterpret_cast<xlb_ppartner*>(vp)->p2prop;
  }
};

template<typename Prop_t>
auto xlb_makepropptr(Prop_t prop)
{
  return xlb_base_pptr::ptr_t(new xlb_ppartner<Prop_t>(prop));
}

template<typename FT>
inline auto xlb_makefuncptr(FT f)
{
  return xlb_base_fptr::ptr_t(new xlb_fpartner<FT>(f));
}

inline auto xlb_makefuncptr()
{
  return xlb_base_fptr::ptr_t(nullptr);
}


/*---------------------------------------------------------------------------
 xlb_prophandler
-----------------------------------------------------------------------------*/

struct xlb_prophandler
{
  using ptr_t = xlb_base_pptr::ptr_t;
  using func_t = int (*)(lua_State*, void*, xlb_flag);
  func_t f;
  ptr_t ptr;

  xlb_prophandler() = default;
  xlb_prophandler(func_t _f, ptr_t&& p) : f(_f) 
  {
    ptr.reset(p.release());
  }

  xlb_prophandler(xlb_prophandler&& r)
  {
    f = r.f;
    ptr.reset(r.ptr.release());
  }

  xlb_prophandler& operator=(xlb_prophandler&& r)
  {
    f = r.f;
    ptr.reset(r.ptr.release());
    return (*this);
  }

  int operator()(lua_State* L, xlb_flag flag)
  {
    return f(L, ptr.get(), flag);
  }

}; // xlb_prophandler


/*---------------------------------------------------------------------------
 xlb_funchandler
-----------------------------------------------------------------------------*/
struct xlb_funchandler
{
  using func_t = lua_CFunction;

  func_t f = nullptr;
  xlb_base_fptr::ptr_t ptr;

  xlb_funchandler() = default;
  xlb_funchandler(func_t _f, xlb_base_fptr::ptr_t&& _p) : f(_f) 
  {
    ptr.reset(_p.release());
  }

  xlb_funchandler(xlb_funchandler&& _right)
  {
    f = _right.f;
    ptr.reset(_right.ptr.release());
  }

  xlb_funchandler& operator=(xlb_funchandler&& _right)
  {
    f = _right.f;
    ptr.reset(_right.ptr.release());
    return (*this);
  }

  int operator()(lua_State* L)
  {
    lua_pushlightuserdata(L, ptr.get());
    lua_pushcclosure(L, f, 1); //XXX:method with upvalue
    return 1;
  }
}; // xlb_funchandler


/*---------------------------------------------------------------------------

-----------------------------------------------------------------------------*/
using xlb_regs_t         = std::vector<luaL_reg>;
using xlb_closure_t      = std::tuple<const char*, lua_CFunction, xlb_base_fptr::ptr_t>;
using xlb_classfuncs_t   = std::vector<xlb_closure_t>;
using xlb_consts_t       = std::vector<std::pair<const char*, int>>;
using xlb_member_t       = std::unordered_map<string, xlb_property>;
using xlb_metas_t        = std::vector<const char**>;
using xlb_meta_t         = const char*;

static int xlu_search_getter(lua_State* L, xlb_meta_t meta_name, const xlb_metas_t& super_names) 
{
  int nfound = 0;
  for (auto& meta_name : super_names) {
    lua_getfield(L, LUA_REGISTRYINDEX, (*meta_name));
    assert(lua_istable(L, -1));
    lua_pushstring(L, "__index");
    lua_rawget(L, -2);
    lua_pushvalue(L, 1);
    lua_pushvalue(L, 2);
    // XXX: manual call __index, instead using lua_gettable
    // since the value one the 1 index must be userdata
    lua_pcall(L, 2, 1, 0); 
    lua_remove(L, -2); // remove metatable
    if (lua_isnil(L, -1)) {
      lua_pop(L, 1);
    } else {
      nfound = 1;
      break;
    }
  }
  return nfound;
}

static int xlu_search_setter(lua_State* L, xlb_meta_t meta_name, const xlb_metas_t& super_names) 
{
  int nfound = 0;
  for (auto& meta_name : super_names) {
    lua_getfield(L, LUA_REGISTRYINDEX, (*meta_name)); // [metatable]
    assert(lua_istable(L, -1));

    lua_pushstring(L, "__newindex"); // [metatable, "__newindex"]
    lua_rawget(L, -2);               // [metatable, __newindex]
    lua_remove(L, -2);               // remove metatable [__newindex]

    /** XXX:手工调用__newindex,传递参数,并加上一个标志参数,
     * __newindex处理函数根据这个标志参数知道它是被谁调用的
     * 传递的参数个数总共为4个
     */
    lua_pushvalue(L, 1);             // [1]=userdata
    lua_pushvalue(L, 2);             // [2]=keyname
    lua_pushvalue(L, 3);             // [3]=setvalue
    lua_pushnumber(L, XLB_TRAP_FLAG);
    lua_pcall(L, 4, 1, 0); 

    if (lua_isnil(L, -1)) {
      lua_pop(L, 1);
    } else {
      nfound = 1;
      break;
    }
  }
  return nfound;
}

/* XXX: search super tree for meta_name
 */
static bool xlu_checksuper(lua_State* L, int index, xlb_meta_t meta_name) 
{
  //-1:xlb_super={...}
  std::vector<string> table_names;
  lua_pushnil(L);
  while (lua_next(L, index) != 0) {
    table_names.push_back(string(lua_tostring(L,-2)));
    lua_pop(L, 1);
  }
  while (!table_names.empty()) {
    string table_name = table_names.back();
    table_names.pop_back();
    if (table_name == meta_name) {
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
}
/* XXX: xlb_meta value of userdata equal to meta_name
 * or userdata's ancient those meta_name equal to meta_name
 */
static bool xlu_checkudata(lua_State* L, int index, xlb_meta_t meta_name) 
{
  assert(meta_name!=nullptr);
  bool checked = false;
  if (lua_isuserdata(L, index)) {
    lua_getmetatable(L, index);
    lua_pushstring(L, "xlb_meta");
    lua_rawget(L, -2);
    checked = (strcmp(meta_name, lua_tostring(L, -1)) == 0);
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
      lua_pushstring(L, meta_name);
      lua_rawget(L, -2);
      checked = !lua_isnil(L, -1);
      lua_pop(L, 2);

      if (!checked) {
        lua_pushstring(L, "xlb_super");
        lua_rawget(L, -2);
        if (lua_istable(L, -1)) {
          checked = xlu_checksuper(L, lua_gettop(L), meta_name);
        }
        lua_pop(L, 1); // xlb_super's value
        if (checked) {
          lua_pushstring(L, "xlb_ancient");
          lua_rawget(L, -2);
          lua_pushstring(L, meta_name);
          lua_pushnumber(L, 1);
          lua_rawset(L, -3);
          lua_pop(L, 1);
        }
      }
    }
    lua_pop(L, 1); // pop metatable
  }
  return checked;
}

static void xlu_newobjmeta(lua_State* L, xlb_meta_t meta_name, 
    const xlb_regs_t& meta_funcs, 
    const xlb_classfuncs_t& method_funcs,
    const xlb_metas_t& super_metas) 
{
  xlb_debug("%s\n", meta_name);
  luaL_newmetatable(L, meta_name); //XXX: push table on #1
  if (1 < meta_funcs.size()) { luaL_setfuncs(L, &meta_funcs.front(), 0); }

  // set metatable.metatable to itself
  lua_pushvalue(L, -1);
  lua_setmetatable(L, -2);

  lua_pushstring(L, "xlb_meta");
  lua_pushstring(L, meta_name);
  lua_rawset(L, -3);

  lua_pushstring(L, "xlb_ancient");
  lua_newtable(L);
  lua_rawset(L, -3);

  lua_pushstring(L, "xlb_super");
  lua_newtable(L);
  for (auto& super : super_metas) {
    lua_pushstring(L, (*super));
    assert(nullptr!=*super); ///< XXX:need instantiation xlb_base_class<X>
    lua_pushnumber(L, XLB_EXISTS_FLAG);
    lua_rawset(L, -3);
  }
  lua_rawset(L, -3);

  /** XXX:class method with upvalues
   * __index和__newindex在metatable中
   */
  for (auto& finfo : method_funcs) {
    xlb_debug("%s\n", std::get<0>(finfo));
    lua_pushstring(L, std::get<0>(finfo)); ///< [0]==function name
    auto upvalue_count = std::get<2>(finfo)->pushupvalue(L); ///< push upvalue
    lua_pushcclosure(L, std::get<1>(finfo), upvalue_count); ///< [1]=function pointer
    lua_rawset(L, -3);
  }

  lua_pop(L, 1); //XXX:pop metatable in #1
} // xlu_newobjmeta

static void xlu_newtypelib(lua_State* L, const char* type_name, 
    xlb_regs_t& type_table, const xlb_consts_t& const_values, 
    int parent_table_index) 
{
  if (0 != parent_table_index) {
    lua_pushstring(L, type_name);
    xlb_debug("type_name=%s\n", type_name);
  }

  //luaL_newlib(L, &type_table.front());
  lua_createtable(L, 0, type_table.size()-1);
  luaL_setfuncs(L, &type_table.front(), 0);

  for (const auto& const_value : const_values) {
    xlb_debug("[const %s]\n", const_value.first);
    lua_pushstring(L, const_value.first);
    lua_pushinteger(L, const_value.second);
    lua_rawset(L, -3);
    xlb_dbg();
  }

  lua_pushvalue(L, -1);
  lua_setmetatable(L, -2); //XXX:meta itself

  if (0 != parent_table_index) {
    if (parent_table_index < 0) { parent_table_index -= 2; }
    lua_rawset(L, parent_table_index);
  } else {
    lua_setglobal(L, type_name);
  }
} // xlu_newtypelib

/*---------------------------------------------------------------------------
wrap obj those class have xlb_base_class<PT>
-----------------------------------------------------------------------------*/
template<typename X>
int xlb_pushobj(lua_State* L, X* pointer, xlb_flag gc, void* place=nullptr)
{
  using w_t = xlb_wrap<X>;
  if (nullptr == place) { place = lua_newuserdata(L, sizeof(w_t)); }
  auto wp = reinterpret_cast<w_t*>(place);
  new(wp) w_t(pointer, gc, xlb_flag::object);
  wp->varflag = xlb_flag::var_obj;
  w_t::pushuserdata(L, -1);
  return 1;
} // xlb_pushobj

/*---------------------------------------------------------------------------
wrap obj those class have xlb_base_class<PT>
-----------------------------------------------------------------------------*/
template<typename X>
int xlb_pushobj(lua_State* L, const X* pointer, xlb_flag gc, void* place=nullptr)
{
  using w_t = xlb_wrap<X>;
  if (nullptr == place) { place = lua_newuserdata(L, sizeof(w_t)); }
  auto wp = reinterpret_cast<w_t*>(place);
  new(wp) w_t(pointer, gc, xlb_flag::object);
  wp->varflag = xlb_flag::const_obj;
  w_t::pushuserdata(L, -1);
  return 1;
} // xlb_pushobj

/*---------------------------------------------------------------------------
xlb_wrap : wrap lightuserdata(pointer) which have xlb_base_class to user data
-----------------------------------------------------------------------------*/
struct xlbI_pushobject
{
  virtual int dereference(lua_State* L) = 0;
}; // xlbI_pushobject


///< 将指针对象所指向的值输出到Lua中,实现类似C++的(*p)功能
struct xlb_push_pointer_value
{
  /** XXX:如果AT非指针(即非xlb_lpointer<T>),调用AT的pusharg功能,输出对象
   * AT对象对指针输入的构造会做特殊处理,其不会管理对象的生命周期
   */
  template<typename AT> struct xlb_tir 
  {
    XLB_SIV go(lua_State* L, const void* p, int& rc)
    {
      using pv_t = typename std::add_pointer<typename std::add_const<typename AT::type>::type>::type;
      AT pointer_get_value(reinterpret_cast<pv_t>(p));
      xlb_ai ai;
      xlb_debug("(typeid.name=%s)\n", typeid(AT).name());
      pointer_get_value.pusharg(L, ai, rc, xlb_flag::not_gc); //XXX:not gc
    }
  };
};


///< XXX:如果AT是指针(即xlb_lpointer<T>)
template<typename T, typename VTER>
struct xlb_push_pointer_value::xlb_tir<xlb_lpointer<T, VTER>>
{
  XLB_SIV go(lua_State* L, const void* p, int& rc)
  {
    using AT = xlb_lpointer<T, VTER>;
    using pv_t = const T*;
    /** XXX:当AT是xlb_lpointer<T>时,AT对于传入指针的构造并不会对指针做取值操作
     * 需要在这里先对指针做取值操作
     */
    auto pv = *reinterpret_cast<pv_t>(p);

    AT pointer_get_value(pv); 
    xlb_ai ai;
    xlb_debug("(typeid.name=%s)\n", typeid(AT).name());
    pointer_get_value.pusharg(L, ai, rc, xlb_flag::not_gc); //XXX:not gc
  }

  XLB_SIV go(lua_State* L, void* p, int& rc)
  {
    using AT = xlb_lpointer<T, VTER>;
    using pv_t = T*;
    auto pv = *reinterpret_cast<pv_t>(p);

    AT pointer_get_value(pv); 
    xlb_ai ai;
    xlb_debug("(typeid.name=%s)\n", typeid(AT).name());
    pointer_get_value.pusharg(L, ai, rc, xlb_flag::not_gc); //XXX:not gc
  }

};

template<> struct xlb_push_pointer_value::xlb_tir<xlb_notpointer> 
{
  XLB_SIV go(lua_State* L, const void* p, int& rc) 
  {
    xlb_debug("(notpointer)\n");
  }
};


template<typename T>
auto xlb_touserdata(lua_State* L, int index)
{
  return reinterpret_cast<T*>(lua_touserdata(L, index));
}

template<typename X>
XLB_SIT xlb_checkwrap(lua_State* L, int index)
{
  using w_t = xlb_wrap<X>;
  return reinterpret_cast<w_t*>(luaL_checkudata(L, index, xlb_base_class<X>::meta_name));
  //return (w_t*)lua_touserdata(L, index);
}

/*---------------------------------------------------------------------------
xlb_wrap
-----------------------------------------------------------------------------*/

/* @struct xlb_wrap
 * This template used to wrapper lightuserdata as userdata, and then we can
 * set metatable on its. It's instance life managered by C++ not by Lua. */
template<typename T, typename AT, typename DEL>
class xlb_wrap : public xlbI_pushobject
{
public:
  using w_t = xlb_wrap<T, AT, DEL>;
  T* pointer;
  xlb_flag gc_in_lua;
  xlb_flag varflag;
  xlb_flag vkind;

  xlb_wrap(T* p, xlb_flag gc, xlb_flag k) 
      : pointer(p)
      , gc_in_lua(gc)
      , vkind(k)
      , varflag(xlb_flag::var_obj) 
  {
    xlb_debug("(0x%p)\n", p);
  }

  xlb_wrap(const T* p, xlb_flag gc, xlb_flag k) 
      : pointer(const_cast<T*>(p))
      , gc_in_lua(gc)
      , vkind(k)
      , varflag(xlb_flag::const_obj) 
  {
    xlb_debug("(0x%p)\n", p);
  }

public:
  virtual ~xlb_wrap() 
  { 
    if (gc_in_lua==xlb_flag::gc) { 
      xlb_debug("(0x%p,typeid.name=%s)\n", pointer, typeid(T).name());
      DEL()(pointer);
    } 
  }
  inline bool is_const() { return varflag == xlb_flag::const_obj; }

  /** XXX:多态函数,根据不同的类型实现其取值(*p)
   * 使用到了指针所取值的代理类型AT,AT用于将指针所指向的值输出到Lua中
   */
  virtual int dereference(lua_State* L) override
  {
    int rc{0};
    if (this->varflag == xlb_flag::const_pvalue || this->varflag == xlb_flag::const_pandv) {
      auto p = reinterpret_cast<const T*>(this->getpointer());
      xlb_push_pointer_value::template xlb_tir<AT>::go(L, p, rc);
    } else {
      auto p = reinterpret_cast<T*>(this->getpointer());
      xlb_push_pointer_value::template xlb_tir<AT>::go(L, p, rc);
    }
    return rc;
  }

  T* ptr() const { return pointer; }
  T* operator->() const  { return pointer; }


  inline void setvarflag(xlb_flag v) { varflag = v; }
  inline xlb_flag getvarflag() { return varflag; }
  inline void* getpointer() { return pointer; }

  static int cf___tostring(lua_State* L)
  {
    auto wobj = xlb_touserdata<xlb_wrap<void>>(L, 1);
    auto p = wobj->getpointer();
    const char* fmt = "(FIXME %p)";
    switch (wobj->getvarflag()) {
      case xlb_flag::var_pointer: fmt = "(xlb T*: 0x%p)"; break;
      case xlb_flag::const_pointer: fmt = "(xlb T* const: 0x%p)"; break;
      case xlb_flag::const_pvalue: fmt = "(xlb const T*: 0x%p)"; break;
      case xlb_flag::const_pandv: fmt = "(xlb const T* const: 0x%p)"; break;
    }
    lua_pushfstring(L, fmt, p);
    return 1;
  }

  static int cf___getobject(lua_State* L)
  {
    auto rc = 0;
    auto wobj = xlb_touserdata<xlbI_pushobject>(L, 1);
    if (nullptr != wobj) {
      rc = wobj->dereference(L);
    } else {
      luaL_argerror(L, 1, "xlb_meta_xlb_pointer expected.");
    }
    return rc;
  }

  static int cf___getpointer(lua_State* L) 
  { 
    auto wobj = xlb_touserdata<xlb_wrap<void>>(L, 1);
    lua_pushlightuserdata(L, wobj->getpointer()); 
    //xlb_debug("(0x%08x),top=%d\n", p, lua_gettop(L));
    return 1;
  }

  static void userdata_pointer(lua_State* L, int index)
  {
    if (0 != luaL_newmetatable(L, "xlb_meta_xlb_pointer")) { 

      lua_pushstring(L, "__index"); //XXX:must have __index
      lua_pushvalue(L, -2);
      lua_rawset(L, -3);

      lua_pushstring(L, "__getpointer");
      lua_pushcfunction(L, cf___getpointer);
      lua_rawset(L, -3);

      lua_pushstring(L, "__getobject");
      lua_pushcfunction(L, cf___getobject);
      lua_rawset(L, -3);

      lua_pushstring(L, "__tostring");
      lua_pushcfunction(L, cf___tostring);
      lua_rawset(L, -3);
    }

    if (index < 0) { --index; } // s:1(ud),2(metatable)
    lua_setmetatable(L, index); // ud.metatable = metatable
  }

  static void pushuserdata(lua_State* L, int index, lua_Number N=0) 
  {
    auto meta_for_object = xlb_base_class<T>::meta_name;
#ifdef DEBUG
    if (xlb_base_class<T>::meta_name == nullptr) {
      xlb_debug("ERROR:(typeid.name=%s)\n", typeid(T).name());
    }
#endif
    assert(meta_for_object != nullptr); //XXX:type is not xlb_base_class<T> 
    luaL_newmetatable(L, meta_for_object); // s: 1(ud), 2(metatable)
    if (index < 0) { --index; }
    lua_setmetatable(L, index); // ud.metatable = metatable
  }

}; // xlb_wrap

/*---------------------------------------------------------------------------
type analysis helper
-----------------------------------------------------------------------------*/
template<typename PT> struct is_constpandv { static const bool value = false; };
template<typename T_> struct is_constpandv<const T_* const> 
{ 
  static const bool value = true; 
  using type = T_;
};

template<typename PT> struct is_constpointer { static const bool value = false; };
template<typename T_> struct is_constpointer<T_* const> 
{ 
  static const bool value = true; 
  using type = T_;
};

template<typename PT> struct is_varpointer { static const bool value = false; };
template<typename T_> struct is_varpointer<const T_*> { static const bool value = false; };
template<typename T_> struct is_varpointer<T_*>
{
  static const bool value = true; 
  using type = T_;
};

template<typename PT> struct is_constval { static const bool value = false; };
template<typename T_> struct is_constval<const T_*> 
{ 
  static const bool value = true; 
  using type = T_;
};

/*---------------------------------------------------------------------------
xlb_pushpointer : (T* const) type pointer as userdata
-----------------------------------------------------------------------------*/
template<typename PT, typename AT> // PT=T * const
static void xlb_pushpointer(lua_State* L, PT pointer, void* place=nullptr, 
    typename std::enable_if<is_constpointer<PT>::value>::type *n=0) 
{
  using w_t = xlb_wrap<typename is_constpointer<PT>::type, AT>;
  if (nullptr == place) { place = lua_newuserdata(L, sizeof(w_t)); }
  new((w_t*)place) w_t(pointer, xlb_flag::not_gc, xlb_flag::pointer);
  reinterpret_cast<w_t*>(place)->setvarflag(xlb_flag::const_pointer);
  w_t::userdata_pointer(L, -1);
  xlb_debug("(0x%p->0x%p)\n", place, pointer);
}

/*---------------------------------------------------------------------------
xlb_pushpoin : (T*) type pointer as userdata
-----------------------------------------------------------------------------*/
template<typename PT, typename AT> // PT=T*
void xlb_pushpointer(lua_State* L, PT pointer, void* place=nullptr,
    typename std::enable_if<is_varpointer<PT>::value>::type *n=0)
{
  using w_t = xlb_wrap<typename std::remove_pointer<PT>::type, AT>;
  if (nullptr == place) { place = lua_newuserdata(L, sizeof(w_t)); }
  new((w_t*)place) w_t(pointer, xlb_flag::not_gc, xlb_flag::pointer);
  reinterpret_cast<w_t*>(place)->setvarflag(xlb_flag::var_pointer);
  w_t::userdata_pointer(L, -1);
  xlb_debug("(0x%p->0x%p)\n", place, pointer);
}

/*---------------------------------------------------------------------------
xlb_pushpoin : (const T*) type pointer as userdata
-----------------------------------------------------------------------------*/
template<typename PT, typename AT> // PT=const T *
void xlb_pushpointer(lua_State* L, PT pointer, void* place=nullptr, 
    typename std::enable_if<is_constval<PT>::value>::type *n=0) 
{
  using w_t = xlb_wrap<typename is_constval<PT>::type, AT>;
  if (nullptr == place) { place = lua_newuserdata(L, sizeof(w_t)); }
  new((w_t*)place) w_t(pointer, xlb_flag::not_gc, xlb_flag::pointer);
  reinterpret_cast<w_t*>(place)->setvarflag(xlb_flag::const_pvalue);
  w_t::userdata_pointer(L, -1);
  xlb_debug("(0x%p->0x%p)\n", place, pointer);
}


/*---------------------------------------------------------------------------
xlb_toaddress
-----------------------------------------------------------------------------*/
template<class X>
inline X* xlb_toaddress(lua_State* L, int index, xlb_wrap<X>** pwp=nullptr) 
{
  using w_t = xlb_wrap<X>;
  X* pobj = nullptr;

  //TODO: 对于从派生对象返回其基类对象也是允许的
  //auto wp = xlb_checkwrap<X>(L, index);
  auto wp = (w_t*)lua_touserdata(L, index);

  if (wp) {
    pobj = wp->ptr();
    if (pwp) { *pwp = wp; }
  }
  return pobj;
}

/*---------------------------------------------------------------------------
xlb argument type match
-----------------------------------------------------------------------------*/
#define XLB_E_AMI_BAD           0x10000000
#define XLB_E_AMI_DENY          0x10000001
#define XLB_E_AMI_NONE          0x10000002
#define XLB_E_AMI_FEW           0x10000003
#define XLB_E_AMI_TOMUCH        0x10000003
#define XLB_E_AMI_SAME          0x0
#define XLB_E_AMI_DEFAULT       0x0
#define XLB_E_AMI_TRANSLATE     0x1
#define xlb_badtype(tmi) (XLB_E_AMI_BAD <= (tmi.type_match))

struct xlb_ami 
{
  int type_match       = XLB_E_AMI_SAME;

  /** indicate the argument index in arguments of function
   */
  int arg_index        = 0;

  /** load argument from next_index, 
   * and make it indicate then next argument
   */
  int next_index       = 0;
  int top              = 0; ///< lua_gettop
  int default_count    = 0;
  int arg_count        = 0;
  int rc               = 0;

  /** class self object, it's default value equal nullptr 
   * means self have not been load from lua)
   */
  void* obj            = nullptr; 

  std::string extmsg;  ///< for luaL_argerror

}; // xlb_ami


/*---------------------------------------------------------------------------
xlb argument agent 
-----------------------------------------------------------------------------*/
template<typename X> struct xlb_selftype
{
  XLB_SIV getarg(lua_State* L, xlb_ami& ami) 
  {
    assert(1 == ami.next_index);
    xlb_wrap<X>* wp = nullptr;
    auto obj = xlb_toaddress<X>(L, ami.next_index, &wp);
    if (obj) {
      if (wp->is_const()) {
        ami.type_match = XLB_E_AMI_BAD;
        ami.extmsg = "xlb: const object provied";
      } else {
        ami.obj = obj;
        ++ami.next_index;
      }
    } else {
      ami.type_match = XLB_E_AMI_BAD;
      ami.extmsg = "xlb: invalid self";
    }
  }
};

template<typename X> struct xlb_selftype<const X>
{
  XLB_SIV getarg(lua_State* L, xlb_ami& ami) 
  {
    assert(1 == ami.next_index);
    auto obj = xlb_toaddress<X>(L, ami.next_index);
    if (obj) {
      ami.obj = obj;
      ++ami.next_index;
    } else {
      ami.type_match = XLB_E_AMI_BAD;
      ami.extmsg = "xlb: invalid self";
    }
  }
};

/*---------------------------------------------------------------------------
xlb_ignore
-----------------------------------------------------------------------------*/
struct xlb_ignore
{
  XLB_SIV getarg(lua_State*, xlb_ami& ami) 
  {
    if (ami.top >= ami.next_index) {
      ++ami.next_index;
    }
  }
};

/*---------------------------------------------------------------------------
xlb_candidate
-----------------------------------------------------------------------------*/
template<typename T>
T* xlb_candidate(lua_State* L, int index, xlb_meta_t meta_name)
{
  return nullptr;
}

/*---------------------------------------------------------------------------
xlb_lpointer 代替指针类型和引用类型
-----------------------------------------------------------------------------*/

template<typename T, typename VTER>
struct xlb_lpointer<T*, VTER> // T *
{ 
  using vter_type = VTER;
  using type = T; 
  using pointer_type = T*;
  using w_t = xlb_wrap<T>;

  T* pointer;

  xlb_lpointer(T* p=nullptr) { pointer = (T*)p; }
  xlb_lpointer(T&& v) { pointer = &v; } //XXX:for xlb_invoke
  xlb_lpointer& operator= (T* p) { pointer = p; return (*this); } 

  operator T*()  { return pointer; }
  operator T&()  { return *pointer; } //XXX: pointer as reference

  void getarg(lua_State* L, xlb_ami& ami) 
  { 
    //TODO:需要改变,让它可以接受一些候选类型参数
    auto wp = reinterpret_cast<w_t*>(luaL_checkudata(L, ami.next_index, "xlb_meta_xlb_pointer"));
    //auto wp = xlb_candidate<T*>(L, ami.next_index, "xlb_meta_xlb_pointer");

    if (wp==nullptr) {
      ami.type_match = XLB_E_AMI_BAD;
      ami.extmsg = "xlb pointer expected.";
    } else {
      //XXX:作为参数,形参T*允许接收T*const实参,T*const形参会退化成T*
      if (wp->varflag==xlb_flag::const_pandv || wp->varflag==xlb_flag::const_pvalue) {
        ami.type_match = XLB_E_AMI_BAD;
        ami.extmsg = "var pointer expected.";
      } else {
        pointer = reinterpret_cast<decltype(pointer)>(wp->getpointer());
        ++ami.next_index;
      }
    }
    xlb_dbg();
  }

  void pusharg(lua_State* L, const xlb_ai& ai, int& rc, xlb_flag gc=xlb_flag::not_gc) 
  { 
    xlb_dbg();
    using AT = xlb_getagenttype<VTER, T>;
    xlb_pushpointer<decltype(pointer), AT>(L, pointer);
    ++rc;
  }
}; // xlb_lpointer

template<typename T, typename VTER> 
struct xlb_lpointer<T* const, VTER> // T * const
{ 
  using vter_type = VTER;
  using type = T; 
  using pointer_type = T* const;
  T* const pointer;
  xlb_lpointer(T* const p=nullptr) : pointer(p) {}
  operator T* const ()  { return pointer; }
  void getarg(lua_State* L, xlb_ami& ami)
  { 
    using w_t = xlb_wrap<T>;
    auto wp = reinterpret_cast<w_t*>(luaL_checkudata(L, ami.next_index, "xlb_meta_xlb_pointer"));
    if (wp==nullptr) {
      ami.type_match = XLB_E_AMI_BAD;
      ami.extmsg = "const pointer expected.";
    } else {
      if (wp->varflag!=xlb_flag::const_pointer && wp->varflag!=xlb_flag::var_pointer) {
        ami.type_match = XLB_E_AMI_BAD;
        ami.extmsg = "const pointer expected.";
      } else {
        pointer = reinterpret_cast<decltype(pointer)>(wp->getpointer());
        ++ami.next_index;
      }
    }
    xlb_dbg();
  }

  void pusharg(lua_State* L, const xlb_ai& ai, int& rc, xlb_flag gc=xlb_flag::not_gc) 
  { 
    xlb_dbg();
    using AT = xlb_getagenttype<VTER, T>;
    xlb_pushpointer<decltype(pointer), AT>(L, pointer);
    ++rc;
  }
}; // xlb_lpointer


template<typename T, typename VTER>
struct xlb_lpointer<const T*, VTER> // const T *
{ 
  using vter_type = VTER;
  using type = T; 
  using pointer_type = const T*;
  const T* pointer;
  xlb_lpointer(const T* p=nullptr) : pointer(p) {}
  operator const T* ()  { return pointer; }
  void getarg(lua_State* L, xlb_ami& ami) 
  { 
    using w_t = xlb_wrap<T>;
    xlb_dbg(); //TODO:
    auto wp = reinterpret_cast<w_t*>(luaL_checkudata(L, ami.next_index, "xlb_meta_xlb_pointer"));
    if (wp==nullptr) {
      ami.type_match = XLB_E_AMI_BAD;
      ami.extmsg = "pointer to const value expected.";
    } else {
      /* 传入const_pandv须保证指针和值都不被修改,但接收后不能保证指针不被修改
       * 传入const_pointer须保证指针不被修改,但接收后只能保证值不被修改
       * 可以接收var_pointer
       */
      if (wp->varflag==xlb_flag::const_pandv || wp->varflag==xlb_flag::const_pointer) {
        ami.type_match = XLB_E_AMI_BAD;
        ami.extmsg = "const T* or T* expected.";
      } else {
        pointer = reinterpret_cast<decltype(pointer)>(wp->getpointer());
        ++ami.next_index;
      }
    }
  }

  void pusharg(lua_State* L, const xlb_ai& ai, int& rc, xlb_flag gc=xlb_flag::not_gc) 
  { 
    xlb_dbg();
    using AT = xlb_getagenttype<VTER, T>;
    xlb_pushpointer<decltype(pointer), AT>(L, pointer);
    ++rc;
  }
}; // xlb_lpointer

template<typename VTER>
struct xlb_lpointer<const char*, VTER> 
{ 
  using vter_type = VTER;
  using type = const char*; 
  using pointer_type = const char*;

  const char* pointer;

  xlb_lpointer(const char* p=nullptr) : pointer(p) {}
  xlb_lpointer& operator= (const char* p) { pointer = p; return (*this); }
  operator const char* () const { return pointer; }
  void getarg(lua_State* L, xlb_ami& ami) { pointer = lua_tostring(L, ami.next_index++); }

  void pusharg(lua_State* L, const xlb_ai& ai, int& rc, xlb_flag gc=xlb_flag::not_gc) 
  { 
    xlb_dbg();
    lua_pushstring(L, pointer); 
  }
}; // xlb_lpointer


/*---------------------------------------------------------------------------
xlb_lstruct for xlb_base_class<T>
-----------------------------------------------------------------------------*/
template<typename X> struct xlb_lstruct // 传值,对对象进行拷贝
{ 
  using type = X; 
  X* pointer;
  bool flag_no_copy = false;

  ///< 传入指针,如果非空,认为不管理对象的生命
  xlb_lstruct(const X* p=nullptr) : pointer((X*)p) 
  {
    flag_no_copy = (p!=nullptr);
  }
  xlb_lstruct(X&& v) { xlb_dbg(); pointer = new X(std::move(v)); }
  xlb_lstruct(const X& v) { xlb_dbg(); pointer = new X(v); }

  xlb_lstruct& operator= (X&& v) { xlb_dbg(); pointer = new X(std::move(v)); return (*this); }
  xlb_lstruct& operator= (X& v) { xlb_dbg(); pointer = new X(v); return (*this); }
  operator X&&() { return std::move(*pointer); }

  virtual ~xlb_lstruct() 
  { 
    xlb_debug("%d\n", flag_no_copy);
    if (!flag_no_copy) delete pointer; 
  }

  void getarg(lua_State* L, xlb_ami& ami) 
  { 
    using w_t = xlb_wrap<X>;
    assert(xlb_base_class<X>::meta_name != nullptr); //XXX:type is not xlb_base_class<X> 
    auto wp = xlb_checkwrap<X>(L, ami.next_index);
    //TODO:receive X& as xlb_lpointer<X*>
    if (wp==nullptr) {
      ami.type_match = XLB_E_AMI_BAD;
      ami.extmsg = "xlb object expected.";
    } else {
      if (wp->varflag==xlb_flag::var_obj) {
        //XXX:copy object, and that should be gc in Lua
        pointer = new X(*(reinterpret_cast<decltype(pointer)>(wp->getpointer())));
        ++ami.next_index;
      } else {
        ami.type_match = XLB_E_AMI_BAD;
        ami.extmsg = "xlb object expected.";
      }
    }
  }
  
  void pusharg(lua_State* L, const xlb_ai& ai, int& rc, xlb_flag gc=xlb_flag::gc) 
  { 
    //XXX: instance should gc in Lua because that was a new copy
    rc += xlb_pushobj(L, pointer, gc); 
    if (gc==xlb_flag::gc) {
      pointer = nullptr;
    }
  }
}; // xlb_lstruct


template<typename X> struct xlb_lstruct<X&> // 引用,不对拷贝对象
{ 
  using type = X; 
  X* pointer;
  xlb_lstruct(const X* p=nullptr) : pointer(p) {} //XXX: for tuple<xlb_lstruct...>
  xlb_lstruct(X&& v) : pointer(&v) {} //XXX: for xlb_lstruct a=std::move(b)
  operator X&() { return (*pointer); }

  void getarg(lua_State* L, xlb_ami& ami) 
  { 
    xlb_dbg();
    using w_t = xlb_wrap<X>;
    assert(xlb_base_class<X>::meta_name != nullptr); //XXX:type is not xlb_base_class<X> 
    auto wp = xlb_checkwrap<X>(L, ami.next_index);
    if (wp==nullptr) {
      ami.type_match = XLB_E_AMI_BAD;
      ami.extmsg = "xlb object expected.";
    } else {
      if (wp->varflag==xlb_flag::var_obj) {
        //XXX:copy object, and that should be gc in Lua
        pointer = reinterpret_cast<decltype(pointer)>(wp->getpointer());
        ++ami.next_index;
      } else {
        ami.type_match = XLB_E_AMI_BAD;
        ami.extmsg = "xlb object expected.";
      }
    }
  }

  void pusharg(lua_State* L, const xlb_ai& ai, int& rc, xlb_flag gc=xlb_flag::not_gc) 
  { 
    xlb_dbg();
    //XXX: instance should not gc in Lua because that was not a new copy
    rc += xlb_pushobj(L, pointer, gc); //xlb_flag::not_gc 
  }
}; // xlb_lstruct


template<typename T> struct xlb_lnumber 
{ 
  using type = T; 
  T value;

  xlb_lnumber(const T* p) { value = *p; }
  xlb_lnumber() { value = 0.0; }
  xlb_lnumber(const T& v) { value = v; }

  xlb_lnumber& operator= (T v) { value = v; return (*this); }
  xlb_lnumber& operator= (T* v) { value = *v; return (*this); }

  operator T&() { return value; }
  operator T*() const { return &value; }
  explicit operator T()  { return value; } //XXX: explicit avoid ambiguous(T() and T&())

  void getarg(lua_State* L, xlb_ami& ami) 
  { 
    value = lua_tonumber(L, ami.next_index++); 
  }

  void pusharg(lua_State* L, const xlb_ai& ai, int& rc, xlb_flag gc=xlb_flag::not_gc) 
  { 
    xlb_dbg();
    lua_pushnumber(L, value); 
    ++rc;
  }
}; // xlb_lnumber


template<typename T> struct xlb_linteger
{ 
  //XXX:lua_Integer maybe not same as T
  using type = T; 
  T value;
  xlb_linteger(const T* p) { value = *p; xlb_dbg(); }
  xlb_linteger() { value = 0; xlb_dbg(); }
  xlb_linteger(const T& v) { value = v; xlb_dbg(); }

  xlb_linteger& operator= (T v) { value = v; return (*this); }
  xlb_linteger& operator= (T* v) { value = *v; return (*this); }

  operator T&() { return value; }
  operator T*() { return &value; }
  explicit operator T()  { return value; } //XXX: explicit avoid ambiguous(T() and T&())

  void getarg(lua_State* L, xlb_ami& ami) 
  { 
    value = lua_tointeger(L, ami.next_index++); 
  }

  void pusharg(lua_State* L, const xlb_ai& ai, int& rc, xlb_flag gc=xlb_flag::not_gc) 
  { 
    lua_pushinteger(L, value); 
    ++rc;
  }
}; // xlb_linteger


template<typename T> struct xlb_lboolean 
{ 
  using type = bool; 
  bool value;
  xlb_lboolean(bool b=false) : value(b) {}

  xlb_lboolean& operator= (int v) { value = v; return (*this); }
  operator bool () const { return value; }

  void getarg(lua_State* L, xlb_ami& ami) 
  { 
    value = lua_toboolean(L, ami.next_index++); 
  }

  void pusharg(lua_State* L, const xlb_ai& ai, int& rc, xlb_flag gc=xlb_flag::not_gc) 
  { 
    xlb_dbg();
    lua_pushboolean(L, value); 
    ++rc;
  }
};


template<typename T> struct xlb_carray 
{ 
  using type = T; 
  T* value;
  xlb_carray& operator= (void* address) { value = (T*)address; return (*this); }
  operator T&() { xlb_dbg(); return (*value); }
  operator T*() { xlb_dbg(); return value; }
  explicit operator T()  { return *value; }
};


/*---------------------------------------------------------------------------
help function
-----------------------------------------------------------------------------*/
template<typename X>
std::string xlb_regname()
{
  auto pch = xlb_base_class<X>::meta_name;
  auto pname = strstr(pch, XLB_META_PREFIX);
  if (pname) {
    pname += strlen(XLB_META_PREFIX);
  }
  assert(pname!=nullptr); ///< class must have been registered
  return { pname };
};

/*---------------------------------------------------------------------------
xlt_rvtrait
-----------------------------------------------------------------------------*/
template<typename R> struct xlt_rvtrait {};

/*---------------------------------------------------------------------------
xlb_gc
-----------------------------------------------------------------------------*/
template<typename T>
int xlb_gc(lua_State* L) 
{
  auto wp = xlb_checkwrap<T>(L, 1);
  if (wp) { wp->~xlb_wrap<T>(); }
  return 0;
}

/*---------------------------------------------------------------------------
xlt_typelist
-----------------------------------------------------------------------------*/
template<class VTER, class FT> struct xlb_typeforge {};

template<class VTER, class R, class Tx, class...A> 
struct xlb_typeforge<VTER, R(Tx::*)(A...)> 
{
  using tuple_t        = std::tuple<xlb_getagenttype<VTER, A>...>;
  using argagent_t     = xlt_typelist<xlb_getagenttype<VTER, A>...>;
  using idxer_t        = typename xlb_toidxer<A...>::type;
  using arglist_t      = xlt_typelist<A...>;
  using result_t       = R;
  using rv_at          = xlb_getagenttype<VTER, xlt_rvtrait<R>>;
  using obj_t          = Tx;
  using arginfo_t      = array<xlb_ai, sizeof...(A)>;
  using const_t        = false_type;
};

template<class VTER, class R, class Tx, class...A> 
struct xlb_typeforge<VTER, R(Tx::*)(A...) const> 
{
  using tuple_t        = std::tuple<xlb_getagenttype<VTER, A>...>;
  using argagent_t     = xlt_typelist<xlb_getagenttype<VTER, A>...>;
  using idxer_t        = typename xlb_toidxer<A...>::type;
  using arglist_t      = xlt_typelist<A...>;
  using result_t       = R;
  using rv_at          = xlb_getagenttype<VTER, xlt_rvtrait<R>>;
  using obj_t          = Tx;
  using arginfo_t      = array<xlb_ai, sizeof...(A)>;
  using const_t        = true_type;
};

template<class VTER, class R, class...A> 
struct xlb_typeforge<VTER, R(*)(A...)> 
{
  using tuple_t        = std::tuple<xlb_getagenttype<VTER, A>...>;
  using argagent_t     = xlt_typelist<xlb_getagenttype<VTER, A>...>;
  using idxer_t        = typename xlb_toidxer<A...>::type;
  using arglist_t      = xlt_typelist<A...>;
  using result_t       = R;
  using rv_at          = xlb_getagenttype<VTER, xlt_rvtrait<R>>;
  using obj_t          = void;
  using arginfo_t      = array<xlb_ai, sizeof...(A)>;
  using const_t        = false_type;
};

/*---------------------------------------------------------------------------
xlb_dfer
function default parameters provider
-----------------------------------------------------------------------------*/
struct xlb_dfer : public xpo_base_dfer
{
  template<class TUP> XLB_SII go(TUP& tuple) { return 0; }
};

template<class TUP, class T, int Idx>
XLB_SIV xlb_default_assign(TUP& tuple, T&& A) 
{
  xlb_debug("(typeid.name=%s)\n", typeid(T).name());
  std::get<Idx>(tuple) = A;
}

template<int BaseIdx, class TUP, class Idxer, class...T>
struct xlb_setdefaultval {};

template<int BaseIdx, class TUP, int...Idxs, class...T>
struct xlb_setdefaultval<BaseIdx, TUP, xlb_idxer<Idxs...>, T...> 
{
  XLB_SIV go(TUP& tuple, T&&...DA) 
  {
    xlt_each {(
        xlb_default_assign<TUP, T, BaseIdx+Idxs>(tuple, std::forward<decltype(DA)>(DA)), 
        XLB_STATEMENT_VALUE
    )...};
  }
};

template<class TUP, class...T>
XLB_SII xlb_putdefault(TUP& tuple, T&&...DA) 
{
  using idxer_t = typename xlb_toidxer<T...>::type;
  constexpr int base_index = std::tuple_size<TUP>::value - sizeof...(T);
  xlb_setdefaultval<base_index, TUP, idxer_t, T...>
    ::go(tuple, std::forward<decltype(DA)>(DA)...);
  return sizeof...(DA);
}

/*---------------------------------------------------------------------------
xlb_getargs
XXX: AIs is array<xlb_ai, ...>
-----------------------------------------------------------------------------*/
template<typename TUP, typename IDXER, typename TYPELIST> 
struct xlb_getargs {};


template<typename TUP> 
struct xlb_getargs<TUP, xlb_idxer<>, xlt_typelist<>> 
{
  template<typename AIs>
    XLB_SIV go(lua_State* L, TUP& tuple, AIs& ais, xlb_ami& ami) 
    { 
      //xlb_debug(" top:%d, index:%d\n", ami.top, ami.next_index);
      if (ami.top >= ami.next_index) {
        ami.type_match = XLB_E_AMI_TOMUCH;
        ami.extmsg = "xlb: too much arguments";
      }
    }
};

template<typename TUP, int ARG_INDEX, int...idxs, typename HEAD, typename...Tail>
struct xlb_getargs<TUP, xlb_idxer<ARG_INDEX, idxs...>, xlt_typelist<HEAD, Tail...>> 
{
  template<typename AIs>
  XLB_SIV go(lua_State* L, TUP& tuple, AIs& ais, xlb_ami& ami) 
  {
    //xlb_debug("top:%d, index:%d\n", ami.top, ami.next_index);
    ///< XXX: ARG_INDEX zero-based
    if (ami.top >= ami.next_index) {
      auto& ai = ais[ARG_INDEX];
            ai.from = ami.next_index;
            ai.type = lua_type(L, ami.next_index);
            ai.index = ARG_INDEX + 1;

      ami.arg_index = ARG_INDEX;
      std::get<ARG_INDEX>(tuple).getarg(L, ami);
      ai.to = ami.next_index; // [from,to)

    } else { ami.type_match = XLB_E_AMI_FEW; }

    if (xlb_badtype(ami)) {
      if (XLB_E_AMI_FEW == ami.type_match) {
        auto stack_remain = (ami.top - (ami.next_index - 1));
        auto args_remain = (ami.arg_count - ARG_INDEX);
        if (stack_remain - args_remain + ami.default_count >= 0) {
          ami.type_match = XLB_E_AMI_DEFAULT;
        } else {
          ami.extmsg = "xlb: too few arguments";
        }
      }
    } else {
      xlb_getargs<TUP, xlb_idxer<idxs...>, xlt_typelist<Tail...>>
          ::go(L, tuple, ais, ami);
    }
  }
}; //xlb_getargs


/*---------------------------------------------------------------------------
default value
为函数提供缺省参数（运行时），与函数的声明时缺少参数不同
-----------------------------------------------------------------------------*/
template<typename LMD> 
struct xlb_derived_dfer : public xpo_base_dfer 
{
  static LMD* plmd; ///< XXX:使用类静态变量来传递lamda函数指针而不是类成员
  xlb_derived_dfer(LMD& l) { plmd = &l; }
  template<typename TUP>XLB_SII go(TUP& tup) { return (*plmd)(tup); }
};

template<typename LMD> LMD* xlb_derived_dfer<LMD>::plmd = nullptr;

template<typename LMD>
auto xpo_default(LMD lmd) -> xlb_derived_dfer<decltype(lmd)> 
{ 
  using default_t = xlb_derived_dfer<decltype(lmd)>;
  const auto& temp_object = default_t(lmd);
  xlb_debug("(plmd=0x%p)\n", default_t::plmd);
  return temp_object;
}


/*---------------------------------------------------------------------------
xlb_derived_rier
-----------------------------------------------------------------------------*/

template<int ...PLACEHOLDERS> 
struct xlb_derived_rier : public xpo_base_rier { };

using xlb_rier = void;


/*---------------------------------------------------------------------------
xlb_pter
push addition parameters of function into lua_State
允许将额外的参数（除函数返回值之外的）压入到lua_State栈中
-----------------------------------------------------------------------------*/
struct xlb_pter 
{
  template<typename, typename> struct xlb_tir {}; 
};


template<typename TUP> struct xlb_pter::xlb_tir<void, TUP> //XXX:void与缺省的xlb_rier相对应
{
  template<typename AIs> XLB_SIV go(lua_State* L, TUP& tuple, const AIs& ais, int& rc) {}
};

template<int...RPI>
struct xlb_pter::xlb_tir<xlb_derived_rier<RPI...>, std::tuple<>>
{
  template<typename AIs> XLB_SIV go(lua_State* L, std::tuple<>& tuple, const AIs& ais, int& rc) {}
};

template<int...RPI, typename...A> 
struct xlb_pter::xlb_tir<xlb_derived_rier<RPI...>, std::tuple<A...>> 
{
  template<typename AIs>
  XLB_SIV go(lua_State* L, std::tuple<A...>& tuple, const AIs& ais, int& rc) 
  {
    //XXX:有坑,RPI-1超出tuple元素范围
    xlt_each{(get<RPI-1>(tuple).push(L, rc), XLB_STATEMENT_VALUE)...};
  }
};

/*---------------------------------------------------------------------------
xlb_ctor_r 类构造函数的返回类型
-----------------------------------------------------------------------------*/
template<typename T> struct xlb_ctor_r 
{
  using type = T;
  T* pointer;
};

/** XXX: argument #1 is table, object that create in Lua just through new operator.
 * this function is the agent of class contructor function and binded to Lua as
 * metatable's default call method named __call. those xlb_ctor_r object must gc
 * in Lua witch delete operator.
 * ignore table while is __call argument #1
 * TODO: make it PO, another new operator action
 */
template<typename T, typename...A> xlb_ctor_r<T> xlb_ctor(xlb_ignore, A...args) 
{ 
  return { new T(args...) }; 
}

/*---------------------------------------------------------------------------
xlb_rv2l
push result of function into lua_State
-----------------------------------------------------------------------------*/
struct xlb_rv2l 
{
  template<typename R, typename RESULT_AGENT> struct xlb_tir 
  {
    XLB_SIV go(lua_State* L, const xlb_ai& ai, RESULT_AGENT& r, int& rc) 
    {
      xlb_debug("(result:typeid.name=%s)\n", typeid(R).name());
      r.pusharg(L, ai, rc);
    }
  };

  /* XXX: for special type xlb_ctor_r, push new object to Lua
   * xlb_rv2l for xlb_ctor function return value (make it special type xlb_ctor_r)
   */
  template<typename X, typename RESULT_AGENT> struct xlb_tir<xlb_ctor_r<X>, RESULT_AGENT> 
  {
    XLB_SIV go(lua_State* L, const xlb_ai& ai, const xlb_ctor_r<X>& obj, int& rc) 
    {
      xlb_debug("(result:typeid.name=%s)\n", typeid(X).name());
      rc += xlb_pushobj(L, obj.pointer, xlb_flag::gc); //XXX: instance should gc in Lua
    }
  };
}; // xlb_rv2l

/*---------------------------------------------------------------------------
xlb_vter
tuple element type according to function parameter
-----------------------------------------------------------------------------*/
struct xlb_vter
{
  template<typename X, typename DJY=xlb_djy> struct xlb_tir {};
}; // xlb_vter


template<> struct xlb_vter::xlb_tir<xlb_ignore> { using type = xlb_ignore; };

/* type for result of function that is constructor
 */
template<typename X>
struct xlb_vter::xlb_tir<xlt_rvtrait<xlb_ctor_r<X>>> { using type = xlb_ctor_r<X>; };

template<typename X> // reference as pointer
struct xlb_vter::xlb_tir<xlt_rvtrait<X&>> { using type = xlb_lpointer<X*, xlb_vter>; };

template<typename X> // for pointer
struct xlb_vter::xlb_tir<xlt_rvtrait<X*>> { using type = xlb_lpointer<X*, xlb_vter>; };

template<typename X>
struct xlb_vter::xlb_tir<xlt_rvtrait<X* const>> { using type = xlb_lpointer<X* const, xlb_vter>; };

/* type for result of function that return void
 */
template<>
struct xlb_vter::xlb_tir<xlt_rvtrait<void>> { using type = xlt_rvtrait<void>; };

template<>
struct xlb_vter::xlb_tir<xlt_rvtrait<bool>> { using type = xlb_lboolean<bool>; };

/*
template<>
struct xlb_vter::xlb_tir<xlt_rvtrait<int>>
{
  using type = xlb_linteger<int>;
};
*/


template<typename X>
struct xlb_vter::xlb_tir<xlt_rvtrait<const X*>> { using type = xlb_lpointer<const X*, xlb_vter>; };

template<typename X>
struct xlb_vter::xlb_tir<xlt_rvtrait<const X* const>> { using type = xlb_lpointer<const X* const, xlb_vter>; };

/*---------------------------------------------------------------------------
pointer and reference
-----------------------------------------------------------------------------*/
template<typename T>
struct xlb_vter::xlb_tir<T&>
{
  using type = xlb_lpointer<T*, xlb_vter>;
};

template<typename T>
struct xlb_vter::xlb_tir<T*>
{
  using type = xlb_lpointer<T*, xlb_vter>; // default template
};

template<typename T>
struct xlb_vter::xlb_tir<const T*>
{
  using type = xlb_lpointer<const T*, xlb_vter>;
};

template<typename T>
struct xlb_vter::xlb_tir<T* const>
{
  using type = xlb_lpointer<T* const, xlb_vter>;
};

/** XXX:匹配类型:除了一些特例化类型之外再对类型做一个选择(根据条件进行范围选择),
 * 使这些类型对应到相应的代理类型上
 * TODO:使这个选择链可以扩展
 */
template<bool, typename T1, typename > struct xlt_choose { using type=T1; };
template<typename T1, typename T2> struct xlt_choose<false, T1, T2> { using type=T2; };

template<typename,typename> struct xlt_vter_query {};
struct xlt_fit_floating {};
struct xlt_fit_integral {};
struct xlt_fit_customize {};

template<typename T> struct xlt_cond_integral 
{ 
  static constexpr bool value = std::is_integral<T>::value; 
  using type = typename xlt_choose<value, xlt_fit_integral, xlt_fit_customize >::type;
};

template<typename T> struct xlt_cond_floating 
{ 
  static constexpr bool value = std::is_floating_point<T>::value; 
  using type = typename xlt_choose<value, xlt_fit_floating , typename xlt_cond_integral<T>::type >::type;
};

template<typename X> struct xlt_vter_query<X, xlt_fit_customize> { using type = xlb_lstruct<X>; }; //XXX:default
template<typename X> struct xlt_vter_query<X, xlt_fit_integral>  { using type = xlb_linteger<int>; };
template<typename X> struct xlt_vter_query<X, xlt_fit_floating > { using type = xlb_lnumber<double>; };

template<typename X>
struct xlb_vter::xlb_tir<X>
{
  using type = typename xlt_vter_query<X, typename xlt_cond_floating<X>::type>::type;
};

template<typename X> ///< XXX: for return Type
struct xlb_vter::xlb_tir<xlt_rvtrait<X>> 
{
  using type = typename xlt_vter_query<X, typename xlt_cond_floating<X>::type>::type;
};

/*---------------------------------------------------------------------------
PO selector
-----------------------------------------------------------------------------*/
template<typename T> struct xpo_vter_selector{ using type = T; };
template<> struct xpo_vter_selector<void> { using type = xlb_vter; };

template<typename T> struct  xpo_dfer_selector{ using type = T; };
template<> struct xpo_dfer_selector<void> { using type = xlb_dfer; };

template<typename T> struct xpo_rier_selector { using type = T; };
template<> struct xpo_rier_selector<void> { using type = xlb_rier; };

template<typename T> struct xpo_readonly_selector { using type = xpo_readonly; };
template<> struct xpo_readonly_selector<void> { using type = xpo_none; };


template<typename WHAT, template<typename> class SELECTOR, typename ...PO> 
struct xlt_searchlist
{
  using type = typename SELECTOR
    <
      typename xlb_getderived<WHAT, xlt_typelist<PO...>>::type
    >::type;
};

template<typename ...PO>
using xlb_getpo_readonly = typename xlt_searchlist<xpo_base_readonly, xpo_readonly_selector, PO...>::type;

template<typename ...PO>
using xlb_getpo_vter = typename xlt_searchlist<xpo_base_vter, xpo_vter_selector, PO...>::type;

template<typename ...PO>
using xlb_getpo_dfer = typename xlt_searchlist<xpo_base_dfer, xpo_dfer_selector, PO...>::type;

template<typename ...PO>
using xlb_getpo_rier = typename xlt_searchlist<xpo_base_rier, xpo_rier_selector, PO...>::type;


/*---------------------------------------------------------------------------
xlb_invoke
-----------------------------------------------------------------------------*/
struct xlb_invoke 
{
  template<class R, bool, class R_AT, class Tx, bool, class FT, class IDXER, class TYPELIST, class R2L> 
    struct xlb_tir {};
};

///< XXX:for r obj->f(...)
template<class R, class R_AT, class Tx, class FT, class...A, int...idxs, class R2L> 
struct xlb_invoke::xlb_tir<R, false, R_AT, Tx, false, FT, xlb_idxer<idxs...>, xlt_typelist<A...>, R2L> 
{
  template<class...B> 
    XLB_SIV go(lua_State* L, xlb_ami& ami, FT f, std::tuple<B...>& tuple) 
    {
      R_AT r = std::move((reinterpret_cast<Tx*>(ami.obj)->*f)(std::move(std::get<idxs>(tuple))...));
      xlb_ai ai;
          ai.index = 0;
          ai.from = 0;
          ai.to = 0;
          ai.type = LUA_TNIL;
      R2L::template xlb_tir<R, R_AT>::go(L, ai, r, ami.rc);
    }
};

///< for void pobj->f(...)
template<class Tx, class FT, class...A, int...idxs, class R2L> 
struct xlb_invoke::xlb_tir<void, true, xlt_rvtrait<void>, Tx, false, FT, xlb_idxer<idxs...>, xlt_typelist<A...>, R2L> 
{
  template<class...B> 
    XLB_SIV go(lua_State* L, xlb_ami& ami, FT f, std::tuple<B...>& tuple) 
    {
      ///< XXX:tuple中的数据都为函数中的局部变量,在函数调用后不再对其操作,可对其move取右值引用
      (reinterpret_cast<Tx*>(ami.obj)->*f)(std::move(std::get<idxs>(tuple))...);
    }
};

///< for r f(...)
template<class R, class R_AT, class FT, class...A, int...idxs, class R2L> 
struct xlb_invoke::xlb_tir<R, false, R_AT, void, true, FT, xlb_idxer<idxs...>, xlt_typelist<A...>, R2L> 
{
  template<class...B> 
    XLB_SIV go(lua_State* L, xlb_ami& ami, FT f, std::tuple<B...>& tuple) 
    {
      R_AT r = std::move(f(std::move(std::get<idxs>(tuple))...));
      xlb_ai ai;
          ai.index = 0;
          ai.from = 0;
          ai.to = 0;
          ai.type = LUA_TNIL;
      R2L::template xlb_tir<R, R_AT>::go(L, ai, r, ami.rc);
    }
};

///< for void f(...)
template<class FT, class...A, int...idxs, class R2L> 
struct xlb_invoke::xlb_tir<void, true, xlt_rvtrait<void>, void, true, FT, xlb_idxer<idxs...>, xlt_typelist<A...>, R2L> 
{
  template<class...B> 
    XLB_SIV go(lua_State* L, xlb_ami&, FT f, std::tuple<B...>& tuple) 
    {
      xlb_dbg();
      f(std::move(std::get<idxs>(tuple))...);
    }
};

/*---------------------------------------------------------------------------
xlt_each_ovlfunc
-----------------------------------------------------------------------------*/
using xlb_ovlfunc = void (*)(lua_State* L, xlb_ami& ami);

template <xlb_ovlfunc... Fs> struct xlt_each_ovlfunc_impl;

template <xlb_ovlfunc F> struct xlt_each_ovlfunc_impl<F> 
{
  static void go(lua_State* L, xlb_ami& ami) 
  {
    ami.type_match = XLB_E_AMI_SAME;
    F(L, ami);
  }
};

template <xlb_ovlfunc F, xlb_ovlfunc...Fs>
struct xlt_each_ovlfunc_impl<F, Fs...> 
{
  XLB_SIV go(lua_State* L, xlb_ami& ami) 
  {
    ami.type_match = XLB_E_AMI_SAME;
    F(L, ami);
    if (xlb_badtype(ami)) {
      xlt_each_ovlfunc_impl<Fs...>::go(L, ami);
    }
  }
};

template <xlb_ovlfunc...Fs>
inline void xlt_each_ovlfunc(lua_State* L, xlb_ami& ami) 
{
  xlt_each_ovlfunc_impl<Fs...>::go(L, ami);
}

/*---------------------------------------------------------------------------
xlb_selfobj
-----------------------------------------------------------------------------*/
template<typename X, typename CONST_T>
struct xlb_selfobj
{
  template<typename TUP, typename AIs>
  XLB_SIV go(lua_State* L, TUP& tuple, xlb_ami& ami, AIs& ais) 
  {
    if (nullptr == ami.obj) {
      xlb_selftype<const X>().getarg(L, ami);
    }
  }
};

template<typename X>
struct xlb_selfobj<X, false_type>
{
  template<typename TUP, typename AIs>
  XLB_SIV go(lua_State* L, TUP& tuple, xlb_ami& ami, AIs& ais) 
  {
    if (nullptr == ami.obj) {
      xlb_selftype<X>().getarg(L, ami);
    }
  }
};

template<> struct xlb_selfobj<void, false_type> 
{
  template<typename TUP, typename AIs>
  XLB_SIV go(lua_State*, TUP& tuple, xlb_ami&, AIs& ais) {}
};

/*---------------------------------------------------------------------------
xlb_cfunction
overload function
-----------------------------------------------------------------------------*/
template<class FT, FT f, 
    class DFER=xlb_dfer, 
    class RIER=xlb_rier, 
    class R2L=xlb_rv2l, 
    class PTER=xlb_pter, 
    class VTER=xlb_vter
> void xlb_cfunction(lua_State* L, xlb_ami& ami) 
{
  using forge_t         = xlb_typeforge<VTER, FT>;
  using tuple_t         = typename forge_t::tuple_t;
  using idxer_t         = typename forge_t::idxer_t;
  using argagent_t      = typename forge_t::argagent_t;
  using arglist_t       = typename forge_t::arglist_t;
  using result_t        = typename forge_t::result_t;
  using rv_at           = typename forge_t::rv_at;
  using obj_t           = typename forge_t::obj_t;
  using arginfo_t       = typename forge_t::arginfo_t;
  using const_t         = typename forge_t::const_t;

  arginfo_t ais;
  tuple_t tuple;
  ami.next_index = 1;
  ami.arg_index = 0;

  xlb_selfobj<obj_t, const_t>::go(L, tuple, ami, ais);

  if (!xlb_badtype(ami)) {
    xlb_debug("(default_value){{\n");
    ami.default_count = DFER::go(tuple);
    xlb_debug("(default_value:%d)}}\n", ami.default_count);
    ami.arg_count = arglist_t::size;
    xlb_debug("(getargs){{\n");
    xlb_getargs<tuple_t, idxer_t, argagent_t>::go(L, tuple, ais, ami);
    xlb_debug("(getargs)}}\n");
  }
  ami.rc = ami.type_match;
  if (!xlb_badtype(ami)) {
    xlb_invoke::template xlb_tir
      <
        result_t, std::is_same<result_t, void>::value, 
        rv_at, 
        obj_t, std::is_same<obj_t, void>::value, 
        FT, idxer_t, arglist_t, R2L
      >::go(L, ami, f, tuple);
    PTER::template xlb_tir<RIER, tuple_t>::go(L, tuple, ais, ami.rc);
  }
  return ami.rc;

} // xlb_cfunction

/*---------------------------------------------------------------------------
xlb_cfunction
overload function
-----------------------------------------------------------------------------*/
template<xlb_ovlfunc F, xlb_ovlfunc...Fs> int xlb_cfunction(lua_State* L) 
{
  xlb_ami ami; 
      ami.top = lua_gettop(L);
      ami.obj = nullptr;
  xlt_each_ovlfunc<F, Fs...>(L, ami);
  if (xlb_badtype(ami)) {
    return luaL_argerror(L, ami.next_index, ami.extmsg.c_str());
  }
  return ami.rc;
}

/*---------------------------------------------------------------------------
xlb_policy
-----------------------------------------------------------------------------*/
struct xlb_policy 
{
  using DFER = void;
  using RIER = void;
  using VTER = void;
};

/*---------------------------------------------------------------------------
xlb_fpartner 函数指针,帮助处理upvalue
-----------------------------------------------------------------------------*/

template<class FT>
struct xlb_fpartner : public xlb_base_fptr
{
  using self_t = xlb_fpartner<FT>;
  FT fpointer;

  xlb_fpartner(FT f=nullptr, onregistry_t callback=nullptr) 
    : xlb_base_fptr(callback), fpointer(f)
  {}

  virtual int pushupvalue(lua_State* L) override
  {
    int rc{0};

    auto place = lua_newuserdata(L, sizeof(self_t));
    new (place) self_t(fpointer); //XXX:wrap fpointer as upvalue
    ++rc;

    if (nullptr != onregistry) { rc += onregistry(L, this); }
    xlb_dbg();
    return rc;
  }

  FT topointer(lua_State* L, int index) 
  {
    auto fpa = reinterpret_cast<self_t*>(lua_touserdata(L, lua_upvalueindex(index)));
    assert(fpa != nullptr);
    return fpa->fpointer;
  }

  FT topointer() { return fpointer; }

  XLB_SII newuserdata(lua_State* L, FT f) 
  {
    auto place = lua_newuserdata(L, sizeof(self_t));
    new (place)self_t(f); //XXX:wrap fpointer as upvalue
    return 1;
  }

  XLB_SIT create(FT f)
  {
    return xlb_base_fptr::ptr_t(new self_t(f));
  }

}; //xlb_fpartner

/*---------------------------------------------------------------------------
xlb_f2cf_pure
no upvalue for cfunction
-----------------------------------------------------------------------------*/
template<class FT, FT f, class ...PO> int xlb_f2cf_pure(lua_State* L) 
{
  using VTER            = xlb_getpo_vter<PO...>;
  using DFER            = xlb_getpo_dfer<PO...>;
  using RIER            = xlb_getpo_rier<PO...>;

  using forge_t         = xlb_typeforge<VTER, FT>;
  using tuple_t         = typename forge_t::tuple_t;
  using idxer_t         = typename forge_t::idxer_t;
  using argagent_t      = typename forge_t::argagent_t;
  using arglist_t       = typename forge_t::arglist_t;
  using result_t        = typename forge_t::result_t;
  using rv_at           = typename forge_t::rv_at;
  using obj_t           = typename forge_t::obj_t;
  using arginfo_t       = typename forge_t::arginfo_t;
  using const_t         = typename forge_t::const_t;

  arginfo_t ais;
  tuple_t tuple;
  xlb_ami ami; 
      ami.top = lua_gettop(L);
      ami.next_index = 1;

  xlb_selfobj<obj_t, const_t>::go(L, tuple, ami, ais);

  if (!xlb_badtype(ami)) {
    ami.default_count = DFER::go(tuple);
    ami.arg_count = arglist_t::size;
    xlb_getargs<tuple_t, idxer_t, argagent_t>::go(L, tuple, ais, ami);
  }

  if (xlb_badtype(ami)) {
    xlb_dbg();
    return luaL_argerror(L, ami.next_index, ami.extmsg.c_str());
  }

  ami.rc = 0;
  xlb_debug("(invoke){{\n");
  xlb_invoke::template xlb_tir <
      result_t, std::is_same<result_t, void>::value, 
      rv_at, 
      obj_t, std::is_same<obj_t, void>::value, 
      FT, idxer_t, arglist_t, xlb_rv2l
    >::go(L, ami, f, tuple);
  xlb_debug("(invoke)}}\n");

  xlb_pter::template xlb_tir<RIER, tuple_t>::go(L, tuple, ais, ami.rc);
  return ami.rc;

} // xlb_f2cf_pure

/*---------------------------------------------------------------------------
xlb_f2cf
-----------------------------------------------------------------------------*/
template<class FT, /*FT f,*/ class ...PO> int xlb_f2cf(lua_State* L) 
{
  using VTER            = xlb_getpo_vter<PO...>;
  using DFER            = xlb_getpo_dfer<PO...>;
  using RIER            = xlb_getpo_rier<PO...>;

  using forge_t         = xlb_typeforge<VTER, FT>;
  using tuple_t         = typename forge_t::tuple_t;
  using idxer_t         = typename forge_t::idxer_t;
  using argagent_t      = typename forge_t::argagent_t;
  using arglist_t       = typename forge_t::arglist_t;
  using result_t        = typename forge_t::result_t;
  using rv_at           = typename forge_t::rv_at;
  using obj_t           = typename forge_t::obj_t;
  using arginfo_t       = typename forge_t::arginfo_t;
  using const_t         = typename forge_t::const_t;

  arginfo_t ais;
  tuple_t tuple;
  xlb_ami ami; 
      ami.top = lua_gettop(L);
      ami.next_index = 1;

  xlb_selfobj<obj_t, const_t>::go(L, tuple, ami, ais);

  if (!xlb_badtype(ami)) {
    ami.default_count = DFER::go(tuple);
    ami.arg_count = arglist_t::size;
    xlb_getargs<tuple_t, idxer_t, argagent_t>::go(L, tuple, ais, ami);
  }
  if (xlb_badtype(ami)) {
    return luaL_argerror(L, ami.next_index, ami.extmsg.c_str());
  }

  xlb_fpartner<FT> fpa;
  auto f = fpa.topointer(L, 1); ///< XXX:first upvalue

  ami.rc = 0;
  xlb_debug("(invoke){{\n");
  xlb_invoke::template xlb_tir <
      result_t, std::is_same<result_t, void>::value, 
      rv_at, 
      obj_t, std::is_same<obj_t, void>::value, 
      FT, idxer_t, arglist_t, xlb_rv2l
    >::go(L, ami, f, tuple);
  xlb_debug("(invoke)}}\n");

  xlb_pter::template xlb_tir<RIER, tuple_t>::go(L, tuple, ais, ami.rc);
  return ami.rc;

} // xlb_f2cf


/*---------------------------------------------------------------------------
xlb_propgetter
-----------------------------------------------------------------------------*/
template<class Pro_t> struct xlb_propforge {};
template<class P, class Tx> struct xlb_propforge<P Tx::*> 
{
  using obj_t = Tx;
  using property_t = P;
};

/** XXX:将属性值或其引用输出到Lua中 */
template<typename VTER, typename Pro_t>
XLB_SIV xlb_pushprop(lua_State* L, Pro_t& property, int& rc, xlb_flag vor)
{
  if (xlb_flag::property_byref == vor) {
    using property_at      = xlb_getagenttype<VTER, typename std::add_pointer<Pro_t>::type>;
    property_at p_as_ret   = &property; ///< XXX:使用属性的地址

    xlb_ai ai;
    ai.type = LUA_TNIL;

    xlb_debug("(typeid.name=%s)\n", typeid(property_at).name());
    xlb_debug("(typeid.name=%s)\n", typeid(Pro_t).name());
    p_as_ret.pusharg(L, ai, rc);
  }

  if (xlb_flag::property_byval == vor) {
    using property_at      = xlb_getagenttype<VTER, Pro_t>;
    property_at p_as_ret   = property; ///< XXX:使用属性的值
    xlb_ai ai;
    ai.type = LUA_TNIL;

    xlb_debug("(typeid.name=%s)\n", typeid(property_at).name());
    xlb_debug("(typeid.name=%s)\n", typeid(Pro_t).name());
    p_as_ret.pusharg(L, ai, rc);
  }
}

template<class Pro_t, class ...PO>
int xlb_propgetter(lua_State* L, void* vp, xlb_flag vor=xlb_flag::property_byval) 
{ // t,k
  using VTER        = xlb_getpo_vter<PO...>;
  using forge_t     = xlb_propforge<Pro_t>;
  using obj_t       = typename forge_t::obj_t;

  auto obj = xlb_toaddress<obj_t>(L, 1);
  assert(obj != nullptr);

  auto rc = 0;
  /** TODO:属性输出时应该为引用类型,如何使用这个属性时才确定是拷贝还是继续引用
   * 一个这样的属性引用需要包含两个东西,一是对象,二是指针
   * 如果vor==property_byref,那么返回的一定是引用
   * 如果vor==property_byval,那么返回尽可能的是值,但对于对象和指针之类的则返回userdata
   * 需要提供对象以及指针信息,并要求其按vor标志执行
   */
  auto p2prop = xlb_ppartner<Pro_t>::get(vp);
  xlb_pushprop<VTER>(L, (obj->*p2prop), rc, vor); ///< XXX:property is pointer
  return rc;
}

template<class Pro_t, class ...PO>
int xlb_propsetter(lua_State* L, void* vp, xlb_flag vor=xlb_flag::property_byval) 
{ // t,k,v
  using VTER         = xlb_getpo_vter<PO...>;
  using forge_t      = xlb_propforge<Pro_t>;

  using obj_t        = typename forge_t::obj_t;
  using property_t   = typename forge_t::property_t;
  using property_at  = xlb_getagenttype<VTER, property_t>;

  auto obj = xlb_toaddress<obj_t>(L, 1);
  assert(obj != nullptr);

  xlb_debug("(typeid.name=%s)\n", typeid(VTER).name());

  xlb_ami ami; 
      ami.top = lua_gettop(L);
      ami.obj = obj;
      ami.next_index = 3;

  property_at property_value;
  property_value.getarg(L, ami);

  auto p2prop = xlb_ppartner<Pro_t>::get(vp);
  (*obj).*p2prop = property_value;

  return 0;
} // xlb_propsetter


/*---------------------------------------------------------------------------
@struct xlb_property
@brief property include function and member, read write flag
-----------------------------------------------------------------------------*/

struct xlb_property 
{
  using self_t = xlb_property;
  using RVR_t = xlb_property&&;
  enum { unknown, readonly, readwrite, writeonly, function };
  int type = unknown;

  xlb_prophandler getter;
  xlb_prophandler setter;
  xlb_funchandler funcer;

  xlb_property() {}

  template<typename Prop_t, typename ...PO>
    static self_t create(Prop_t prop, xpo_readonly)
    {
      xlb_property temp;
      temp.type = xlb_property::readonly;
      temp.getter = xlb_prophandler(xlb_propgetter<Prop_t, PO...>, xlb_makepropptr(prop));
      return temp;
    }

  template<typename Prop_t, typename ...PO>
    static self_t create(Prop_t prop, xpo_none)
    {
      xlb_property temp;
      temp.type = xlb_property::readwrite;
      temp.getter = xlb_prophandler(xlb_propgetter<Prop_t, PO...>, xlb_makepropptr(prop));
      temp.setter = xlb_prophandler(xlb_propsetter<Prop_t, PO...>, xlb_makepropptr(prop));
      return temp;
    }

  template<typename FT>
  static self_t create(lua_CFunction cf, FT f)
    {
      xlb_property temp;
      temp.type = xlb_property::function; 
      temp.funcer = xlb_funchandler(cf, xlb_makefuncptr(f));
      return temp;
    }

}; // xlb_property

/*---------------------------------------------------------------------------
module namespace
-----------------------------------------------------------------------------*/
struct xlb_module;
struct xlbI_namespace;

struct xlbI_chainelem 
{
  std::string name;
  virtual void registry(xlbI_namespace* ns) {}
}; //xlbI_chainelem

struct xlb_regchain : public std::vector<xlbI_chainelem*>
{ 
  template<class ...T> xlb_regchain(const T&... registration) 
  {
    xlt_each { 
      (push_back((xlbI_chainelem*)&registration), XLB_STATEMENT_VALUE)...
    };
  } 
}; //xlb_regchain

struct xlbI_namespace 
{
  using RVR_t                = xlbI_namespace&&;
  lua_State* lua             = nullptr;
  const char* luaTableName   = nullptr;
  int luaIndex               = 0;
  int parent_table_index     = 0;
}; //xlbI_namespace

template<typename FT, class ...PO>
struct xlb_function : public xlbI_chainelem 
{
  using RVR_t = xlb_function&&;
  FT fpointer;

  xlb_function(const char* fn, FT f) 
  {
    xlb_debug("%s\n", fn);
    name = fn;
    fpointer = f;
  }

  virtual ~xlb_function() 
  {
    xlb_debug("%s\n", name.c_str());
  }

  virtual void registry(xlbI_namespace* ns) override
  {
    auto& L = ns->lua;
    lua_pushstring(L, name.c_str());
    auto count_upvalue = xlb_fpartner<FT>::newuserdata(L, fpointer);
    lua_pushcclosure(L, xlb_f2cf<FT, PO...>, count_upvalue);
    lua_rawset(L, ns->luaIndex);
  }

  RVR_t arg() { return std::move(*this); }

}; //xlb_function

template<typename FT, typename ...PO>
auto xlb_f(const char* fn, FT f)
{
  return xlb_function<FT, PO...>(fn, f);
}

struct xlb_namespace : public xlbI_namespace, public xlbI_chainelem 
{
  xlb_regchain chain;
  xlb_namespace(const char* space_name = nullptr) 
  {
    name = space_name;
    xlb_debug("%s\n", name.c_str());
    xlbI_namespace::luaTableName = space_name;
    assert(nullptr!=luaTableName); ///< name of namespace expected
  }

  virtual void registry(xlbI_namespace* parent_ns) override
  {
    auto L = parent_ns->lua;
    xlbI_namespace::lua = L;
    lua_pushstring(L, luaTableName);
    lua_newtable(L);
    luaIndex = lua_gettop(L);

    for (auto& reg : chain) {
      xlb_debug("%s->%s\n", xlbI_namespace::luaTableName, reg->name.c_str());
      reg->registry(this);
    }
    lua_rawset(L, parent_ns->luaIndex);
  }

  xlb_namespace& operator[](xlb_regchain&& chain) 
  {
    chain = std::move(chain);
    return (*this);
  }

}; //xlb_namespace

struct xlb_module : public xlbI_namespace, public xlbI_chainelem 
{

  xlb_module(lua_State* L, const char* table_name=nullptr, int pti=0) 
  {
    xlb_debug(":+module\n");
    xlbI_namespace::luaTableName = table_name;
    xlbI_namespace::lua = L;
    xlbI_namespace::parent_table_index = pti;
  }

  xlb_module& operator[](const xlb_regchain& chain) 
  {
    auto& L = xlbI_namespace::lua;
    auto& moduleName = xlbI_namespace::luaTableName;

    if (nullptr != moduleName) { 
      lua_pushstring(L, moduleName); 
    }
    lua_newtable(L);
    luaIndex = lua_gettop(L);
    xlb_debug("%s=[\n", moduleName);
    for (auto& reg : chain) {
      xlb_debug("  %s\n", reg->name.c_str());
      reg->registry(this);
    }
    xlb_debug("]\n");

    if (nullptr != moduleName) {
      if (0 != parent_table_index) {
        if (parent_table_index < 0) parent_table_index -= 2;
        lua_rawset(L, parent_table_index);
      } else {
        lua_setglobal(L, moduleName);
        lua_pop(L, 1); // the table name that have been pushed
      }
    }
    return (*this);
  }

  virtual void registry(xlbI_namespace* ns) override
  {}

}; //xlb_module


/*---------------------------------------------------------------------------
xlb_base_class
-----------------------------------------------------------------------------*/
template<typename X>
struct xlb_base_class : public xlbI_chainelem
{
  using self_t = xlb_base_class;
  using RVR_t = self_t&&;
  using this_t = self_t*;
  static xlb_meta_t meta_name;
  static xlb_meta_t type_name;
  static std::string meta_name_buf;
  static std::string type_name_buf;
  static xlb_metas_t super_names;
  static xlb_regs_t meta_funcs;
  static xlb_regs_t type_table;
  static xlb_classfuncs_t method_funcs;
  static xlb_consts_t const_values;
  static xlb_member_t member_map;

  /*---------------------------------------------------------------------------
  xlb_f2cf_static
  -----------------------------------------------------------------------------*/
  template<class FT, /*FT f,*/ class ...PO> 
  static int xlb_f2cf_static(lua_State* L) 
  {
    using VTER            = xlb_getpo_vter<PO...>;
    using DFER            = xlb_getpo_dfer<PO...>;
    using RIER            = xlb_getpo_rier<PO...>;

    using forge_t         = xlb_typeforge<VTER, FT>;
    using tuple_t         = typename forge_t::tuple_t;
    using idxer_t         = typename forge_t::idxer_t;
    using argagent_t      = typename forge_t::argagent_t;
    using arglist_t       = typename forge_t::arglist_t;
    using result_t        = typename forge_t::result_t;
    using rv_at           = typename forge_t::rv_at;
    using obj_t           = typename forge_t::obj_t;
    using arginfo_t       = typename forge_t::arginfo_t;
    using const_t         = typename forge_t::const_t;

    arginfo_t ais;
    tuple_t tuple;
    xlb_ami ami; 
        ami.top = lua_gettop(L);
        ami.next_index = 1;

    xlb_selfobj<obj_t, const_t>::go(L, tuple, ami, ais);

    if (!xlb_badtype(ami)) {
      xlb_debug("(default_value){{\n");
      ami.default_count = DFER::go(tuple);
      ami.arg_count = arglist_t::size;
      xlb_debug("(default_value:%d)}}\n", ami.default_count);
      xlb_debug("(getargs){{\n");
      xlb_getargs<tuple_t, idxer_t, argagent_t>::go(L, tuple, ais, ami);
      xlb_debug("(getargs)}}\n");
    }

    if (xlb_badtype(ami)) {
      return luaL_argerror(L, ami.next_index, ami.extmsg.c_str());
    }

    xlb_fpartner<FT> fpa;
    auto f = fpa.topointer(L, 1); ///< XXX:first upvalue

    ami.rc = 0;
    xlb_invoke::template xlb_tir<
        result_t, std::is_same<result_t, void>::value, 
        rv_at, 
        obj_t, std::is_same<obj_t, void>::value, 
        FT, 
        idxer_t, 
        arglist_t, 
        xlb_rv2l
      >::go(L, ami, f, tuple);

    xlb_pter::template xlb_tir<RIER, tuple_t>::go(L, tuple, ais, ami.rc);
    return ami.rc;

  } // xlb_f2cf_static

  ///< XXX:search metatable for key
  static int index_handler(lua_State* L) ///< __index(t,k) 
  { 
    auto key = luaL_optlstring(L, 2, "", nullptr);
    auto flag = xlb_flag::property_byval;
    ///< XXX:特有功能,对于属性名称前加&字符,则返回该属性的引用
    if (key[0]=='&') {
      flag = xlb_flag::property_byref;
      ++key;
    }
    auto iter = member_map.find(key);
    int nfound = 0;
    if (iter != member_map.end()) {
      auto& property = iter->second; 
      xlb_debug("(%s){{\n", key);
      switch (iter->second.type) {
        case xlb_property::readonly:
        case xlb_property::readwrite:
          property.getter(L, flag);
          nfound = 1;
          break;
        case xlb_property::function:
          property.funcer(L);
          nfound = 1;
          break;
      }
      xlb_debug("(%s)}}\n", key);
    }
    //xlb_debug("(%s,%d)\n", key, nfound);

    if (0 == nfound) {
      //XXX:search getter from super class
      nfound = xlu_search_getter(L, meta_name, super_names);
    }
    return nfound;
  } // index_handler

  static int newindex_handler(lua_State* L) ///< __newindex(t,k,v)
  { 
    auto var_name = luaL_optlstring(L, 2, "", nullptr);
    auto iter = member_map.find(var_name);
    auto top = lua_gettop(L);
    int nfound = 0;
    if (iter != member_map.end()) {
      auto& property = iter->second;
      switch (iter->second.type) {
        case xlb_property::writeonly:
        case xlb_property::readwrite:
          property.setter(L, xlb_flag::property_byval);

          if (4 == top) { //XXX:meant called by search_setter
            lua_pushnumber(L, XLB_TRAP_FLAG);
          }
          nfound = 2;
        break;
      }
    }

    if (0 == nfound) { nfound = xlu_search_setter(L, meta_name, super_names); }
    if (2 == nfound) { //XXX:have found it
      if (4 == top) { 
        nfound = 1; //XXX:tell search_setter that setter have been found
      } else {
        nfound = 0; //XXX:setter have been called, and 0 return
      }
    } else {
      if (4 == top) { 
        lua_pushnil(L); //XXX:tell search_setter nothing found
        nfound = 1; 
      } else {
        nfound = 0; //XXX:setter(L) called in search_setter
      }
    }
    return nfound;

  } // newindex_handler

  static int tostring_handler(lua_State* L) 
  {
    xlb_wrap<X>* wp = nullptr;
    auto obj = xlb_toaddress<X>(L, 1, &wp);
    assert(wp!=nullptr);
    if (wp->is_const()) {
      lua_pushfstring(L, "(xlb object const: 0x%p)", obj);
    } else {
      lua_pushfstring(L, "(xlb object: 0x%p)", obj);
    }
    return 1;
  }

  static int typetostring_handler(lua_State* L) 
  {
    auto p = lua_topointer(L, -1);
    lua_pushfstring(L, "(xlb type table: 0x%p)", p);
    return 1;
  }

  template<typename Super_a, typename ...Super_b>
    RVR_t inherited() 
    { 
      super_names.push_back(&xlb_base_class<Super_a>::meta_name);
      xlt_each { 
        (super_names.push_back(&xlb_base_class<Super_b>::meta_name), XLB_STATEMENT_VALUE)...
      };
      return std::move(*this);
    }

  void type_function(const char fn[], lua_CFunction f) 
  { 
    type_table.insert(begin(type_table), {fn, f});
  }

  RVR_t constructor(lua_CFunction f) 
  {
    type_table.insert(begin(type_table), {"__call", f});
    return std::move(*this);
  }

  template<typename ...A>
    RVR_t constructor() 
    {
      lua_CFunction cf = xlb_f2cf_pure<decltype(&xlb_ctor<X, A...>), &xlb_ctor<X, A...>>;
      type_table.insert(begin(type_table), {"__call", cf});
      return std::move(*this);
    }

  RVR_t destructor() 
  { 
    meta_funcs.insert(begin(meta_funcs), {"__gc", xlb_gc<X>});
    return std::move(*this);
  }

  RVR_t method(const char fn[], lua_CFunction f) 
  { 
    //member_map[fn] = xlb_property::create(f, xlb_base_fptr::ptr_t(nullptr));
    member_map[fn] = xlb_property::create(f, xlb_makefuncptr());
    return std::move(*this);
  }

  template<typename FT, class ...PO>
    RVR_t method(const char* func_name, FT f, PO...) 
    {
      member_map[func_name] = xlb_property::create(xlb_f2cf_static<FT, PO...>, f);
      return std::move(*this);
    }

  template<auto f, class ...PO>
    RVR_t method(const char* func_name, PO...) 
    {
      using FT = decltype(f);
      member_map[func_name] = xlb_property::create(xlb_f2cf_static<FT, PO...>, f);
      return std::move(*this);
    }

  template<class Prop_t, class ...PO>
    RVR_t property(const char property_name[], Prop_t prop, PO...) 
    {
      using check_po_readonly = xlb_getpo_readonly<PO...>;
      member_map[property_name] = xlb_property::create<Prop_t, PO...>(prop, check_po_readonly());
      return std::move(*this);
    }


  RVR_t def_const(const char* var_name, int value) 
  {
    const_values.push_back({var_name, value});
    return std::move(*this);
  }

  static void registry(lua_State* L, int parent_table_index = 0)
  {
    meta_funcs.insert(begin(meta_funcs), {"__index",    &index_handler});
    meta_funcs.insert(begin(meta_funcs), {"__newindex", &newindex_handler});
    meta_funcs.insert(begin(meta_funcs), {"__tostring", &tostring_handler});

    type_table.insert(begin(type_table), {"__tostring", &typetostring_handler});

    xlu_newtypelib(L, type_name, type_table, const_values, parent_table_index);
    xlu_newobjmeta(L, meta_name, meta_funcs, method_funcs, super_names);

  }

}; //xlb_base_class

template<class X> const char*          xlb_base_class<X>::meta_name=nullptr;
template<class X> const char*          xlb_base_class<X>::type_name=nullptr;
template<class X> std::string          xlb_base_class<X>::meta_name_buf;
template<class X> std::string          xlb_base_class<X>::type_name_buf;
template<class X> xlb_metas_t          xlb_base_class<X>::super_names={};
template<class X> xlb_regs_t           xlb_base_class<X>::type_table={{nullptr,nullptr}};
template<class X> xlb_regs_t           xlb_base_class<X>::meta_funcs={{nullptr,nullptr}};
template<class X> xlb_classfuncs_t     xlb_base_class<X>::method_funcs={};
template<class X> xlb_consts_t         xlb_base_class<X>::const_values={};
template<class X> xlb_member_t         xlb_base_class<X>::member_map={};

/*---------------------------------------------------------------------------
xlb_class
-----------------------------------------------------------------------------*/
template<typename T> struct xlb_class : public xlb_base_class<T> 
{
  using RVR_t = xlb_class&&;
  using STATIC = xlb_base_class<T>;
  using ACIENT = xlbI_chainelem;

  xlb_class(const char* class_name) 
  { 
    ACIENT::name = class_name; 
    STATIC::meta_name_buf = XLB_META_PREFIX;
    STATIC::meta_name_buf += class_name;
    STATIC::type_name_buf = class_name;
    STATIC::meta_name = STATIC::meta_name_buf.c_str();
    STATIC::type_name = STATIC::type_name_buf.c_str();
    xlb_debug("(%s)\n", ACIENT::name.c_str());
    xlb_debug("(%s)\n", xlb_base_class<T>::meta_name);
  }

  virtual ~xlb_class() 
  {
    xlb_debug("(%s),0x%p\n", ACIENT::name.c_str(), this);
  }

  xlb_class(xlb_class&& o) = delete;

  virtual void registry(xlbI_namespace* name_space) override
  {
    STATIC::registry(name_space->lua, name_space->luaIndex);
  }

  RVR_t def() 
  {
    xlb_dbg();
    return std::move(*this);
  }
}; //xlb_class


/*---------------------------------------------------------------------------
xlb helper
-----------------------------------------------------------------------------*/
void xlb_loadstring(lua_State* L, const char* s) 
{
  int flag_error = 0;
  if (luaL_loadstring(L, s) == 0) {
    if (lua_pcall(L, 0, LUA_MULTRET, 0)) {
      flag_error = 1;
    }
  }
  if (flag_error) {
    xlb_debug("Error: %s\n", lua_tostring(L, -1));
  }
}

void xlb_loadfile(lua_State* L, const char* fn) 
{
  luaL_loadfile(L, fn);
  if (lua_pcall(L, 0, LUA_MULTRET, 0)) {
    xlb_debug("%s\n", lua_tostring(L, -1));
    lua_pop(L, 1);
  }
}

#endif //__XLB_H__

