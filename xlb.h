//--------------------------------------------------------------------------
// @file xlb.h
// @brief bind c++ to Lua
// @author wunoman@qq.com
// @date 20170219
//--------------------------------------------------------------------------
#ifndef _XLB_H
#define _XLB_H

#include <assert.h>
#include <array>
#include <cstring>
#include <string>
#include <functional>
#include <iostream>
#include <memory>
#include <tuple>
#include <type_traits>
#include <typeinfo>
#include <typeindex>
#include <unordered_map>
#include <vector>

using namespace std;
using namespace std::placeholders;

//--------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
#include <lauxlib.h>
#include <lua.h>
#include <lualib.h>
#ifdef __cplusplus
}
#endif

//--------------------------------------------------------------------------

#ifdef DEBUG

constexpr auto debug_mode = true;
#define xlb_debug(format, ...) \
    printf("    (LINE:%d,%s)" format, __LINE__, __FUNCTION__, ##__VA_ARGS__)
#define xlb_dbg() xlb_debug("\n")

#else

constexpr auto debug_mode = false;
#define xlb_debug(...)
#define xlb_dbg()

#endif

//--------------------------------------------------------------------------
// tir (Type Information Replenish)
//--------------------------------------------------------------------------

void xlb_donothing() {}

//--------------------------------------------------------------------------
template <typename T> using xlb_t = typename T::type;

//--------------------------------------------------------------------------
// xlt_each
//--------------------------------------------------------------------------
struct xlt_each { template <class... T> xlt_each(T...) {} };

//--------------------------------------------------------------------------
// xlt_typelist
//--------------------------------------------------------------------------
template <typename... T>
struct xlt_typelist {
    static int const size = sizeof...(T);
};

//--------------------------------------------------------------------------
// xlt_makeidx
//--------------------------------------------------------------------------
template <int...> struct xlb_idx {};

template <int, class Idx, int> struct xlt_makeidx;

template <int I, int... Idxs, int RM>
struct xlt_makeidx<I, xlb_idx<Idxs...>, RM> {
    using type = xlb_t<xlt_makeidx<I + 1, xlb_idx<Idxs..., I>, RM - 1>>;
};

template <int I, int... Idx>
struct xlt_makeidx<I, xlb_idx<Idx...>, 0> {
    using type = xlb_idx<Idx...>;
};

///< index sequence zero-based
template <int N> using xlb_idx_t = xlb_t<xlt_makeidx<0, xlb_idx<>, N>>; 


//-----------------------------------------------------------------------------
template <typename...T> struct xlb_tupsize {};
template <typename...T>
struct xlb_tupsize<std::tuple<T...>&> { 
    static constexpr auto value = sizeof...(T); 
};
template <typename...T>
struct xlb_tupsize<std::tuple<T...>> { 
    static constexpr auto value = sizeof...(T); 
};
template <typename TUP>
inline constexpr auto xlb_tupsize_v = xlb_tupsize<TUP>::value;


//--------------------------------------------------------------------------
// predeclare
//--------------------------------------------------------------------------
template <typename X> struct xlb_base_class;
template <typename X> struct xlb_class;
template <typename F> struct xlb_fmate;

// because reference is taked as pointer, and in some case have to distinct
// each other, if std::is_reference_v<T>==true then U<>T
template <typename Vt, typename T, typename U> struct xlb_lpointer {};
template <typename Vt, typename T> struct xlb_lstruct;

struct xlb_vter;
struct xlb_util;
struct xlb_property;
struct xlb_basewrap;

struct xlb_notpointer {
    using type = void;
    xlb_notpointer(const int* p = nullptr) {}
    void pusharg(lua_State* L, int& rc) {}
};

template <typename T, typename AT = xlb_notpointer,
          typename Del = std::default_delete<T>>
class xlb_wrap;

template <typename Vt, typename T>
using xlb_at = xlb_t<typename Vt::template xlb_tir<T>>;

template <typename R> struct xlt_rvtrait {};

struct xlb_luafunc {
    int ref_id = LUA_NOREF;
};

//-----------------------------------------------------------------------------
struct xlb_cbcf_base {
    virtual void setLua(lua_State* L) = 0;
    virtual void updatestatic(lua_State* L) = 0;
};

//-----------------------------------------------------------------------------
// type support
//-----------------------------------------------------------------------------
template<typename T> struct is_cp : std::false_type {};
template<typename T> struct is_cp<T* const> : std::true_type {};
template<typename T> inline constexpr auto is_cp_v = is_cp<T>::value;

template<typename T> struct is_vp : std::false_type {};
template<typename T> struct is_vp<T*> : std::true_type {};
template<typename T> inline constexpr auto is_vp_v = is_vp<T>::value;

template<typename T> struct is_p2cv : std::false_type {};
template<typename T> struct is_p2cv<const T*> : std::true_type {};
template<typename T> inline constexpr auto is_p2cv_v = is_p2cv<T>::value;

template<typename Vt, typename T> struct is_lstruct : std::false_type {};
template<typename Vt, typename T> struct is_lstruct<Vt, xlb_lstruct<Vt, T>> : std::true_type {}; 
template<typename Vt, typename T> inline constexpr auto is_lstruct_v = is_lstruct<Vt, T>::value;



//-----------------------------------------------------------------------------
// @struct xlb_ai
// argument info, the argument value loaded from Lua
//-----------------------------------------------------------------------------
struct xlb_ai 
{
    int from           = 0;   ///< fetch from
    int to             = 0;   ///< fetch to, [from, to)
    int type           = 0;   ///< lua data type
    int index          = 0;   ///< which argument, one-based
};

enum class xlf_prop : uint8_t {
    byref              = 0x01,  ///< return reference
    byval              = 0x02,  ///< return value if possible
}; // xlf_prop

// type qualifier
enum class xlf_qlf : uint8_t {
    ref                = 0x01,  ///< T&
    cref               = 0x02,  ///< const T&

    val                = 0x04,  ///< T
    cval               = 0x08,  ///< const T

    cp                 = 0x10,  ///< T* const
    p2cv               = 0x20,  ///< const T*
    cp2cv              = 0x40,  ///< const T* const
    vp                 = 0x80,  ///< T*
}; // xlf_qlf


enum class xlf_gc : uint8_t {
    yes                = 0x01,  ///< gc in lua
    no                 = 0x02,  ///< do not gc in lua
    yes_array          = 0x04,  ///< for delete[]
}; // xlf_gc

//-----------------------------------------------------------------------------
constexpr auto XLB_UPVALUE_1 = 1;

//-----------------------------------------------------------------------------
// function arguments type match
//-----------------------------------------------------------------------------
#define XLB_E_AMI_SAME              0x00000000
#define XLB_E_AMI_DEFAULT           0x00000000
#define XLB_E_AMI_TRANSLATE         0x00000001

#define XLB_E_AMI_BAD               0x10000000
#define XLB_E_AMI_DENY              0x10000001
#define XLB_E_AMI_NONE              0x10000002
#define XLB_E_AMI_FEW               0x10000003
#define XLB_E_AMI_TOMUCH            0x10000003
#define xlb_ambad(ami) (XLB_E_AMI_BAD <= (ami.match_result))

#define xlb_amfail(ami, e, msg) \
{   ami.match_result=e; \
    ami.extmsg="";\
    ami.extmsg+=__FILE__; \
    ami.extmsg+=" : "; \
    ami.extmsg+=to_string(__LINE__); \
    ami.extmsg+=" : "; \
    ami.extmsg+=msg; \
} \


struct xlb_ami {
    int match_result   { XLB_E_AMI_SAME };
    int arg_index      { 1 }; ///< 从1计数
    int arg_count      { 0 };  ///< lua_gettop
    int default_count  { 0 };
    int param_count    { 0 };
    int rc             { 0 };
    void* obj          { nullptr };

    std::string extmsg;  ///< for luaL_argerror
    xlb_ami(int ntop) : arg_count(ntop) {}
};  // xlb_ami

//--------------------------------------------------------------------------
// help struct
//--------------------------------------------------------------------------
struct xlb_djy {};  // da jiang you

struct xpo_base_rier {};
struct xpo_base_vter {};
struct xpo_base_dfer {};

struct xpo_none {};  ///< return this when no po specify
struct xpo_base_readonly {};
struct xpo_readonly : public xpo_base_readonly {};

//--------------------------------------------------------------------------
// xlb help template
//--------------------------------------------------------------------------
template <typename Base, bool IS_BASE_OF, typename... T>
struct xlt_search_derived {};

template <typename Base, typename Typelist>
struct xlt_getderived { using type = void; };

template <typename BASE>
struct xlt_getderived<BASE, xlt_typelist<>> { using type = void; };

template <typename Base, typename Head, typename... Tail>
struct xlt_getderived<Base, xlt_typelist<Head, Tail...>> 
{
    using type = xlb_t< xlt_search_derived<
        Base, std::is_base_of_v<Base, Head>, Head, Tail...> >;
};

template <typename Base, typename Typelist>
using xlt_getderived_t = xlb_t< xlt_getderived<Base, Typelist> >;

//--------------------------------------------------------------------------
template <typename Base, typename Head, typename... Tail>
struct xlt_search_derived<Base, false, Head, Tail...> 
{
    using type = xlt_getderived_t<Base, xlt_typelist<Tail...>>;
};

template <typename Base, typename Head, typename... Tail>
struct xlt_search_derived<Base, true, Head, Tail...> 
{
    using type = Head;
};

//--------------------------------------------------------------------------
// MACRO
//--------------------------------------------------------------------------
#define luaL_reg luaL_Reg
#define XLB_TRAP_FLAG 0xFF
#define XLB_EXISTS_FLAG 0x1

#define XLB_META_PREFIX "xlb_meta_"
#define XLB_STATEMENT_VALUE 1

#define XLB_SIV static inline void
#define XLB_SII static inline int
#define XLB_SIT static inline auto


//--------------------------------------------------------------------------
// @struct xlb_base_fptr
// @brief base struct for function pointer, NEE this without pointer type
// information
//--------------------------------------------------------------------------
struct xlb_base_fptr {
    using ptr_t = std::unique_ptr<xlb_base_fptr>;
    using onregistry_t = int (*)(lua_State* L, xlb_base_fptr*);

    /** @brief one process opportunity on pushing upvalue
     * @retval count of upvalue
     */
    onregistry_t onregistry;

    xlb_base_fptr(onregistry_t callback = nullptr) : onregistry(callback) {}

    virtual int pushupvalue(lua_State* L) { return 0; }
    virtual ~xlb_base_fptr() {}
};  // xlb_base_fptr

//--------------------------------------------------------------------------
// @struct xlb_pmate 
// @brief class property pointer mate
//--------------------------------------------------------------------------
struct xlb_base_pptr {
    using ptr_t = std::unique_ptr<xlb_base_pptr>;
};

template <class Prop_t>
struct xlb_pmate : public xlb_base_pptr {
    Prop_t p2prop;
    xlb_pmate(Prop_t p = nullptr) : p2prop(p) {}

    XLB_SIT get(void* vmate) {
        return reinterpret_cast<xlb_pmate*>(vmate)->p2prop;
    }
};

template <typename Prop_t>
auto xlb_makepropptr(Prop_t prop) {
    return xlb_base_pptr::ptr_t(new xlb_pmate<Prop_t>(prop));
}

template <typename FT>
inline auto xlb_makefuncptr(FT f) {
    return xlb_base_fptr::ptr_t(new xlb_fmate<FT>(f));
}

inline auto xlb_makefuncptr() { return xlb_base_fptr::ptr_t(nullptr); }

//--------------------------------------------------------------------------
// @struct xlb_prophandler
// @brief property include member data or member function
//--------------------------------------------------------------------------

struct xlb_prophandler {
    using ptr_t = xlb_base_pptr::ptr_t;
    using func_t = int (*)(lua_State*, void*, xlf_prop);
    func_t f;
    ptr_t prop_mate;

    xlb_prophandler() = default;
    xlb_prophandler(func_t _f, ptr_t&& p) : f(_f) { prop_mate.reset(p.release()); }

    xlb_prophandler(xlb_prophandler&& r) {
        f = r.f;
        prop_mate.reset(r.prop_mate.release());
    }

    xlb_prophandler& operator=(xlb_prophandler&& r) {
        f = r.f;
        prop_mate.reset(r.prop_mate.release());
        return (*this);
    }

    int operator()(lua_State* L, xlf_prop flag) {
        return f(L, prop_mate.get(), flag);
    }

};  // xlb_prophandler

//--------------------------------------------------------------------------
// @struct xlb_funchandler
//--------------------------------------------------------------------------
struct xlb_funchandler {
    using func_t = lua_CFunction;

    func_t f = nullptr;
    xlb_base_fptr::ptr_t ptr;

    xlb_funchandler() = default;
    xlb_funchandler(func_t _f, xlb_base_fptr::ptr_t&& _p) : f(_f) {
        ptr.reset(_p.release());
    }

    xlb_funchandler(xlb_funchandler&& _right) {
        f = _right.f;
        ptr.reset(_right.ptr.release());
    }

    xlb_funchandler& operator=(xlb_funchandler&& _right) {
        f = _right.f;
        ptr.reset(_right.ptr.release());
        return (*this);
    }

    int operator()(lua_State* L) {
        // called in __index
        lua_pushlightuserdata(L, ptr.get()); // upvalues
        lua_pushcclosure(L, f, 1);
        return 1;
    }
};  // xlb_funchandler

//--------------------------------------------------------------------------
using xlb_regs_t = std::vector<luaL_reg>;
using xlb_closure_t = std::tuple<const char*, lua_CFunction, xlb_base_fptr::ptr_t>;
using xlb_classfuncs_t = std::vector<xlb_closure_t>;
using xlb_consts_t = std::vector<std::pair<const char*, int>>;
using xlb_member_t = std::unordered_map<string, xlb_property>;
using xlb_metas_t = std::vector<const char**>;
using xlb_meta_t = const char*;

//--------------------------------------------------------------------------
static int xlu_search_getter(lua_State* L, xlb_meta_t meta_name,
                             const xlb_metas_t& super_names) {
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
        lua_remove(L, -2);  // remove metatable
        if (lua_isnil(L, -1)) {
            lua_pop(L, 1);
        } else {
            nfound = 1;
            break;
        }
    }
    return nfound;
} // xlu_search_getter

//--------------------------------------------------------------------------
static int xlu_search_setter(lua_State* L, xlb_meta_t meta_name,
                             const xlb_metas_t& super_names) {
    int nfound = 0;
    for (auto& meta_name : super_names) {
        lua_getfield(L, LUA_REGISTRYINDEX, (*meta_name));  // [metatable]
        assert(lua_istable(L, -1));

        lua_pushstring(L, "__newindex");  // [metatable, "__newindex"]
        lua_rawget(L, -2);                // [metatable, __newindex]
        lua_remove(L, -2);                // remove metatable [__newindex]

        lua_pushvalue(L, 1);  // [1]=userdata
        lua_pushvalue(L, 2);  // [2]=keyname
        lua_pushvalue(L, 3);  // [3]=setvalue
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
} // xlu_search_setter

//--------------------------------------------------------------------------
// search super tree for meta_name
//--------------------------------------------------------------------------
static bool xlu_checksuper(lua_State* L, int index, xlb_meta_t meta_name) {
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
} // xlu_checksuper


//--------------------------------------------------------------------------
// xlb_meta value of userdata equal to meta_name
// or userdata's ancient those meta_name equal to meta_name
//--------------------------------------------------------------------------
static bool xlu_checkudata(lua_State* L, int index, xlb_meta_t meta_name) {
    assert(meta_name != nullptr);
    bool checked = false;
    if (lua_isuserdata(L, index)) {
        lua_getmetatable(L, index);
        lua_pushstring(L, "xlb_meta");
        lua_rawget(L, -2);
        checked = (strcmp(meta_name, lua_tostring(L, -1)) == 0);
        lua_pop(L, 1);  // pop xlb_meta's value

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
                lua_pop(L, 1);  // xlb_super's value
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
        lua_pop(L, 1);  // pop metatable
    }
    return checked;
} // xlu_checkudata

//--------------------------------------------------------------------------
static void xlu_newobjmeta(lua_State* L, xlb_meta_t meta_name,
                           const xlb_regs_t& meta_funcs,
                           const xlb_classfuncs_t& method_funcs,
                           const xlb_metas_t& super_metas) {
    xlb_debug("%s\n", meta_name);
    luaL_newmetatable(L, meta_name);  // XXX: push table on #1
    if (1 < meta_funcs.size()) {
        luaL_setfuncs(L, &meta_funcs.front(), 0);
    }

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
        assert(nullptr != *super);  ///< require xlb_base_class<X>
        lua_pushstring(L, (*super));
        lua_pushnumber(L, XLB_EXISTS_FLAG);
        lua_rawset(L, -3);
    }
    lua_rawset(L, -3);

    /** XXX:class method with upvalues,
     * __index and __newindex are in metatable
     */
    for (auto& finfo : method_funcs) {
        printf("%04d,( : %s)\n", __LINE__, __FUNCTION__);
        lua_pushstring(L, std::get<0>(finfo));  ///< [0]==function name
        auto upvalue_count = std::get<2>(finfo)->pushupvalue(L);
        lua_pushcclosure(L, std::get<1>(finfo), upvalue_count);
        lua_rawset(L, -3);
    }

    lua_pop(L, 1);  // XXX:pop metatable in #1
}  // xlu_newobjmeta

//-----------------------------------------------------------------------------
static void xlu_newtypelib(lua_State* L, const char* type_name,
                           xlb_regs_t& type_table,
                           const xlb_consts_t& const_values,
                           int typesize,
                           int parent_table_index) {
    if (0 != parent_table_index) {
        lua_pushstring(L, type_name);
        xlb_debug("type_name=%s\n", type_name);
    }

    lua_createtable(L, 0, type_table.size() - 1);
    luaL_setfuncs(L, &type_table.front(), 0);

    for (const auto& const_value : const_values) {
        xlb_debug("[const %s]\n", const_value.first);
        lua_pushstring(L, const_value.first);
        lua_pushinteger(L, const_value.second);
        lua_rawset(L, -3);
        xlb_dbg();
    }

    lua_pushvalue(L, -1);
    lua_setmetatable(L, -2);  // XXX:meta itself

    lua_pushstring(L, "typesize");
    lua_pushinteger(L, typesize);
    lua_rawset(L, -3);

    if (0 != parent_table_index) {
        if (parent_table_index < 0) {
            parent_table_index -= 2;
        }
        lua_rawset(L, parent_table_index);
    } else {
        lua_setglobal(L, type_name);
    }
}  // xlu_newtypelib

//-----------------------------------------------------------------------------
// wrap obj with value
//-----------------------------------------------------------------------------
template <typename X>
int xlb_pushobj(lua_State* L, X& v, xlf_gc gcf, void* place = nullptr) {
    using w_t = xlb_wrap<X>;
    auto wp = w_t::getplace(L, place);
    auto p = reinterpret_cast<X*>(&v);
    new (wp) w_t(p, gcf, xlf_qlf::val);
    w_t::setmeta_struct(L, -1);
    return { 1 };
}  // xlb_pushobj

//-----------------------------------------------------------------------------
// wrap obj those class have xlb_base_class<PT>
//-----------------------------------------------------------------------------
template <typename X>
int xlb_pushstructval(lua_State* L, X& v, xlf_gc gcf, void* place = nullptr) {
    using w_t = xlb_wrap< std::remove_const_t<X> >;

    xlf_qlf qlf = xlf_qlf::val;
    if constexpr ( std::is_const_v<X> ) { qlf = xlf_qlf::cval; }

    auto pointer { &v };
    printf("%04d,(0x%p : %s)\n", __LINE__, pointer, __FUNCTION__);
    auto wp { w_t::getplace(L, place) };
    new (wp) w_t(pointer, gcf, qlf);
    w_t::setmeta_struct(L, -1);
    return { 1 };
}  // xlb_pushstructref

//-----------------------------------------------------------------------------
// wrap obj those class have xlb_base_class<PT>
//-----------------------------------------------------------------------------
template <typename X>
int xlb_pushstructref(lua_State* L, X& v, xlf_gc gcf, void* place = nullptr) {
    using w_t = xlb_wrap<X>;
    auto pointer { &v };
    printf("%04d,(0x%p : %s)\n", __LINE__, pointer, __FUNCTION__);
    auto wp { w_t::getplace(L, place) };
    new (wp) w_t(pointer, gcf, xlf_qlf::ref);
    w_t::setmeta_struct(L, -1);
    return { 1 };
}  // xlb_pushstructref

//-----------------------------------------------------------------------------
// wrap obj those class have xlb_base_class<PT>
//-----------------------------------------------------------------------------
template <typename X>
int xlb_pushstructref(lua_State* L, const X& v, xlf_gc gcf, void* place = nullptr) {
    auto pointer = &v;
    printf("%04d,(0x%p : %s)\n", __LINE__, pointer, __FUNCTION__);
    //XXX:using X but no const X
    using w_t = xlb_wrap<std::remove_cv_t<X>>;
    auto wp = w_t::getplace(L, place);
    new (wp) w_t(pointer, gcf, xlf_qlf::cref);
    printf("%04d,(0x%p,0x%u)\n", __LINE__, &wp->tQlf, (int)xlf_qlf::cref);
    w_t::setmeta_struct(L, -1);
    return { 1 };
}  // xlb_pushstructref

//-----------------------------------------------------------------------------
// wrap obj those class is not xlb_base_class<PT>
//-----------------------------------------------------------------------------
template <typename P, typename AT> // P==const T*
int xlb_pushrefaspointer(lua_State* L, P pointer, xlf_gc gcf, void* place=nullptr,
    std::enable_if_t<is_p2cv_v<P>>* noused=0) {
    using w_t = xlb_wrap<typename AT::type, AT>;
    auto wp = w_t::getplace(L, place);
    new (wp) w_t(pointer, gcf, xlf_qlf::cref);
    w_t::setmeta_pointer(L, -1);
    printf("%04d,(0x%p : %s)\n", __LINE__, pointer, __FUNCTION__);
    return { 1 };
}  // xlb_pushrefaspointer

//-----------------------------------------------------------------------------
// wrap obj those class is not xlb_base_class<PT>
//-----------------------------------------------------------------------------
template <typename P, typename AT> // P==T*
int xlb_pushrefaspointer(lua_State* L, P pointer, xlf_gc gcf, void* place=nullptr,
    std::enable_if_t<!is_p2cv_v<P>>* noused=0) {
    //printf("%04d,(typeid.name=%s)\n", __LINE__, typeid(typename AT::type).name());
    using w_t = xlb_wrap<typename AT::type, AT>;
    auto wp = w_t::getplace(L, place);
    new (wp) w_t(pointer, gcf, xlf_qlf::ref);
    w_t::setmeta_pointer(L, -1);
    //printf("%04d,(0x%p : %s)\n", __LINE__, pointer, __FUNCTION__);
    return { 1 };
}  // xlb_pushrefaspointer

//-----------------------------------------------------------------------------
// xlb_wrap : wrap lightuserdata(pointer) which have xlb_base_class to user data
//-----------------------------------------------------------------------------
struct xlb_basewrap {
    xlf_gc gcflag;
    xlf_qlf tQlf;
    xlb_basewrap(xlf_gc gcf, xlf_qlf tqlf) : gcflag(gcf), tQlf(tqlf) {}
    virtual void* getpointer() = 0;
    virtual int getobjcopy(lua_State* L) = 0;
    virtual int getobjref(lua_State* L) = 0;
    virtual int same_tid(const std::type_index&) = 0;
    virtual ~xlb_basewrap() = default;
};  // xlb_basewrap

inline auto xlb_wpispointer(xlb_basewrap* wp) {
    return wp->tQlf>=xlf_qlf::cp && wp->tQlf<=xlf_qlf::vp;
}

inline auto xlb_wpisref(xlb_basewrap* wp) {
    return wp->tQlf==xlf_qlf::ref || wp->tQlf==xlf_qlf::cref;
}

inline auto xlb_wpisconst(xlb_basewrap* wp) {
    return wp->tQlf==xlf_qlf::cref || wp->tQlf==xlf_qlf::cval;
}

inline auto xlb_wpcopyable(xlb_basewrap* wp) {
    return wp->tQlf==xlf_qlf::ref
        || wp->tQlf==xlf_qlf::cref
        || wp->tQlf==xlf_qlf::val
        || wp->tQlf==xlf_qlf::cval;
}

inline auto xlb_wpcompaddr(xlb_basewrap* wp) {
    return wp->tQlf==xlf_qlf::cp
        || wp->tQlf==xlf_qlf::p2cv
        || wp->tQlf==xlf_qlf::cp2cv
        || wp->tQlf==xlf_qlf::vp;
}


//-----------------------------------------------------------------------------

template <typename T>
auto xlb_touserdata(lua_State* L, int index) {
    return reinterpret_cast<T*>(lua_touserdata(L, index));
}

template <typename T>
auto xlb_towrap(lua_State* L, int index) {
    return reinterpret_cast<xlb_wrap<T>*>(lua_touserdata(L, index));
}

template <typename T>
XLB_SIT xlb_testwrap(lua_State* L, int index) {
    using w_t = xlb_wrap<T>;
    return reinterpret_cast<w_t*>(
        luaL_testudata(L, index, xlb_base_class<T>::meta_name));
}

template <typename T>
XLB_SIT xlb_testwrap(lua_State* L, int index, const char* meta) {
    using w_t = xlb_wrap<T>;
    return reinterpret_cast<w_t*>(luaL_testudata(L, index, meta));
}

//template <typename T>
//auto xlb_getpt(xlb_wrap<T>* wp) {
//    assert(wp);
//    return reinterpret_cast<T*>(wp->getpointer());
//}

template <typename P, typename WRAP>
auto xlb_getpointer(WRAP* wp) {
    assert(wp);
    return reinterpret_cast<P>(wp->getpointer());
}

template <typename T>
auto xlb_toself(lua_State* L, int index) {
    auto wp = xlb_towrap<T>(L, index);
    assert(wp);
    auto pobj = reinterpret_cast<T*>(wp->getpointer());
    assert(pobj);
    return pobj;
}

template <typename T>
auto xlb_sametid(xlb_basewrap* wp) {
    return wp->same_tid(xlb_wrap<T>::typeidx);
}

auto xlb_tobasewrap(lua_State* L, int index) {
    xlb_basewrap* wp { nullptr };
    if (auto vp = lua_touserdata(L, index)) {
        lua_getmetatable(L, index);
        if (lua_istable(L, -1)) {
            lua_pushstring(L, "xlb_meta");
            lua_rawget(L, -2);
            auto xlb_meta_name = lua_tostring(L, -1);
            assert(xlb_meta_name);
            if (xlb_meta_name && (strstr(xlb_meta_name, XLB_META_PREFIX)==xlb_meta_name)) {
                wp = reinterpret_cast<xlb_basewrap*>(vp);
            }
            lua_pop(L, 2);
        }
        assert(wp);
    }
    return wp;
}

//-----------------------------------------------------------------------------
template <typename Idx> struct xlb_assignarrary {};
template <int... idx> struct xlb_assignarrary<xlb_idx<idx...>> {
    template<typename LEFT, typename RIGHT>
        XLB_SIV go(LEFT& left, RIGHT& right, bool is_moved=false) {
            using e_t = decltype(left[0]);
            printf("%04d,(typeid=%s)\n", __LINE__, typeid(right).name());
            xlt_each{( (is_moved) 
                    ? (left[idx] = std::move<e_t>(right[idx]), XLB_STATEMENT_VALUE)
                    : (left[idx] = right[idx], XLB_STATEMENT_VALUE)
                    )...};
        }
};

//-----------------------------------------------------------------------------
template <typename T>
constexpr auto xlb_sizeof() {
    auto r = 0;
    //if constexpr ( std::is_function_v<T> ) {
    //    r = sizeof(void*);
    //} else {
        if constexpr ( std::is_void_v<T> ) {
            r = sizeof(int);
        } else {
            r = sizeof(T);
        }
    //}
    return r;
}

//-----------------------------------------------------------------------------
// @struct xlb_wrap
// wrap object's address as ud, and then we can set metatable on it.
//-----------------------------------------------------------------------------

template <typename T, typename AT, typename WRO_DEL>
class xlb_wrap : public xlb_basewrap 
{
public:
    using w_t = xlb_wrap<T, AT, WRO_DEL>;
    inline static const auto typeidx { std::type_index(typeid(T)) };
    T* pointer;

    xlb_wrap(const T* p, xlf_gc gcf, xlf_qlf tqlf)
        : xlb_basewrap(gcf, tqlf) { 
            if constexpr ( std::is_function_v<T> ) {
                gcf = xlf_gc::no;
                pointer = p;
            } else {
                pointer = const_cast<T*>(p);
            }
            xlb_debug("(0x%p)\n", p); 
        }

public:
    virtual ~xlb_wrap() {
        if constexpr ( !std::is_same_v<T, void> ) {
            if constexpr ( !std::is_function_v<T> && !std::is_abstract_v<T> ) {
                if (gcflag == xlf_gc::yes) {
                    xlb_debug("(0x%p,typeid.name=%s)\n", pointer, typeid(T).name());
                    WRO_DEL()(pointer);
                } else {
                    if constexpr ( std::is_same_v<std::default_delete<T>, WRO_DEL> ) {
                        if (gcflag == xlf_gc::yes_array) {
                            std::default_delete<T[]>()(pointer);
                        }
                    } else { WRO_DEL()(pointer); }
                }
            }
        }
    }

    virtual int getobjcopy(lua_State* L) override {
        int rc {0};
        // only pointer have this functional, identify by AT!=xlb_notpointer
        // example: T==int, AT==xlb_lintegral<int>, AT::type==int,
        if constexpr (!std::is_same_v<AT, xlb_notpointer>) {
            if constexpr (!std::is_same_v<xlb_t<AT>, void>) {
                if constexpr ( !std::is_function_v<T> && !std::is_abstract_v<T> ) {
                    AT at(*pointer);
                    at.pusharg(L, rc);
                }
            }
        } // is pointer
        return rc;
    }

    virtual int getobjref(lua_State* L) override {
        int rc { 0 };
        if constexpr (!std::is_same_v<AT, xlb_notpointer>) {
            if constexpr (!std::is_same_v<xlb_t<AT>, void>) {
                using origin_t = typename AT::type;
                using ref_t = std::add_lvalue_reference_t<origin_t>;
                using Ref_at = xlb_at<typename AT::vter, ref_t>;
                using pointer_t = std::add_pointer_t<origin_t>;
                auto wp = xlb_touserdata<xlb_basewrap>(L, 1);
                auto p = xlb_getpointer<pointer_t>(wp);
                Ref_at ref(p);
                ref.pusharg(L, rc);
            }
        } // is pointer
        return rc;
    }

    virtual int same_tid(const std::type_index& r) override { return typeidx==r; }

    virtual void* getpointer()  override { return (void*)pointer; }

    T* operator->() const { return pointer; }

    static int cf___getcopy(lua_State* L) {
        auto rc { 0 };
        if constexpr (!std::is_same_v<AT, xlb_notpointer>) {
            auto wp = xlb_touserdata<xlb_basewrap>(L, 1);
            if (wp && xlb_wpispointer(wp)) {
                rc = wp->getobjcopy(L);
            } else {
                rc = luaL_argerror(L, 1, "pointer expected.");
            }
        }
        return rc;
    }

    static int cf___getpointer(lua_State* L) {
        auto wp = xlb_touserdata<xlb_basewrap>(L, 1);
        lua_pushlightuserdata(L, wp->getpointer());
        return 1;
    }

    static int cf___getref(lua_State* L) {
        auto rc { 0 };
        if constexpr (!std::is_same_v<AT, xlb_notpointer>) {
            auto wp = xlb_touserdata<xlb_basewrap>(L, 1);
            if (wp && xlb_wpispointer(wp)) {
                rc = wp->getobjref(L);
            } else {
                rc = luaL_argerror(L, 1, "pointer expected.");
            }
        }
        return rc;
    }

    static void setmeta_pointer(lua_State* L, int index) {
        if (0 != luaL_newmetatable(L, "xlb_meta_xlb_pointer")) {
            lua_pushstring(L, "__index");
            lua_pushvalue(L, -2);
            lua_rawset(L, -3);

            lua_pushstring(L, "xlb_meta");
            lua_pushstring(L, "xlb_meta_xlb_pointer");
            lua_rawset(L, -3);

            lua_pushstring(L, "__getpointer");
            lua_pushcfunction(L, cf___getpointer);
            lua_rawset(L, -3);

            lua_pushstring(L, "__getcopy");
            lua_pushcfunction(L, cf___getcopy);
            lua_rawset(L, -3);

            lua_pushstring(L, "__getref");
            lua_pushcfunction(L, cf___getref);
            lua_rawset(L, -3);
        }

        lua_setmetatable(L, (index < 0) ? --index : index);  // ud.metatable = metatable
    }

    static void setmeta_struct(lua_State* L, int index, lua_Number N = 0) {
        auto obj_meta = xlb_base_class<T>::meta_name;
        if constexpr (debug_mode) {
            if (obj_meta == nullptr) {
                printf("%d,ERROR:(typeid.name=%s)\n", __LINE__, typeid(T).name());
            }
        }
        if (obj_meta!=nullptr) {
            luaL_newmetatable(L, obj_meta);  // s: -2(ud), -1(metatable)
            lua_setmetatable(L, (index < 0) ? --index : index);  // ud.metatable = metatable
        } else {
            luaL_error(L, "class need binded first");
        }
    }

    static w_t* getplace(lua_State* L, void*& place) {
        return reinterpret_cast<w_t*>(place 
                ? place 
                : lua_newuserdata(L, sizeof(w_t)));
    }

};  // xlb_wrap

//-----------------------------------------------------------------------------
// xlb_pushpointer : (T* const) type pointer as userdata
//-----------------------------------------------------------------------------
template <typename P, typename AT>  // P=T * const
int xlb_pushpointer(lua_State* L, P pointer, void* place = nullptr,
    std::enable_if_t<is_cp_v<P>>* noused = 0) {
    using w_t = xlb_wrap<typename AT::type, AT>;
    auto wp = w_t::getplace(L, place);
    new (wp) w_t(pointer, xlf_gc::no, xlf_qlf::cp);
    w_t::setmeta_pointer(L, -1);
    printf("%04d,(0x%p : %s)\n", __LINE__, pointer, __FUNCTION__);
    return { 1 };
}

//-----------------------------------------------------------------------------
// xlb_pushpointer : (T*) type pointer as userdata
//-----------------------------------------------------------------------------
template <typename P, typename AT>  // P=T*
int xlb_pushpointer(lua_State* L, P pointer, void* place = nullptr,
    std::enable_if_t<!is_p2cv_v<P> && is_vp_v<P>>* noused = 0) {
    //printf("%d,(typeid.name=%s)\n", __LINE__, typeid(P).name());
    using w_t = xlb_wrap<std::remove_pointer_t<P>, AT>;
    auto wp = w_t::getplace(L, place);
    new (wp) w_t(pointer, xlf_gc::no, xlf_qlf::vp);
    w_t::setmeta_pointer(L, -1);
    return { 1 };
}

//-----------------------------------------------------------------------------
// xlb_pushpointer : (const T*) type pointer as userdata
//-----------------------------------------------------------------------------
template <typename P, typename AT>  // P=const T *
int xlb_pushpointer(lua_State* L, P pointer, void* place = nullptr,
    std::enable_if_t<is_p2cv_v<P>>* noused = 0) {
    printf("%04d,(0x%p : %s)\n", __LINE__, pointer, __FUNCTION__);
    using w_t = xlb_wrap<xlb_t<AT>, AT>;
    auto wp = w_t::getplace(L, place);
    new (wp) w_t(pointer, xlf_gc::no, xlf_qlf::p2cv);
    w_t::setmeta_pointer(L, -1);
    return { 1 };
}

//-----------------------------------------------------------------------------
// xlb argument agent
//-----------------------------------------------------------------------------
template <typename T> struct xlb_selftype {
    XLB_SIV getarg(lua_State* L, xlb_ami& ami) {
        auto extmsg    { "xlb: invalid self" };
        auto wp        { xlb_towrap<T>(L, 1) }; //assert(1 == ami.arg_index)
        auto pobj      { (T*)nullptr };
        if (wp && (!xlb_wpisconst(wp))) {
            pobj = xlb_getpointer<T*>(wp);
        } else {
            extmsg     = "xlb: nonconst object expected"; 
        }
        if (pobj) { ami.obj = pobj; ++ami.arg_index; 
        } else { xlb_amfail(ami, XLB_E_AMI_BAD, extmsg); }
    }
};

template <typename T> struct xlb_selftype<const T> {
    XLB_SIV getarg(lua_State* L, xlb_ami& ami) {
        if (auto pobj { xlb_toself<T>(L, 1) }) {
            ami.obj = pobj; ++ami.arg_index;
        } else {
            xlb_amfail(ami, XLB_E_AMI_BAD, "xlb: invalid self");
        }
    }
};

//----------------------------------------------------------------------------
// xlb_ignore
//----------------------------------------------------------------------------
struct xlb_ignore {
    XLB_SIV getarg(lua_State*, xlb_ami& ami) {
        //printf("%04d,(%d : %s)\n", __LINE__, ami.arg_index, __FUNCTION__);
        if (ami.arg_count >= ami.arg_index) { ++ami.arg_index; }
    }
};

//----------------------------------------------------------------------------
// xlb_lpointer
//----------------------------------------------------------------------------

template <typename Vt>
struct xlb_lpointer<Vt, void*, void*>  // void*
{
    using vter = Vt;
    using type = void*;
    using pointer_t = void*;
    using deref_t = void;

    pointer_t pointer;

    xlb_lpointer(void* p=nullptr) { pointer = (void*)p; }
    xlb_lpointer& operator=(void* p) { pointer = p; return (*this); }
    operator void*() { return pointer; }

    void getarg(lua_State* L, xlb_ami& ami) {
        pointer = nullptr;
        //printf("%04d,(0x%p : %s)\n", __LINE__, this, __FUNCTION__);
        auto wp = xlb_testwrap<void>(L, ami.arg_index, "xlb_meta_xlb_pointer");
        if (wp && xlb_sametid<void>(wp)) {
            if (wp->tQlf==xlf_qlf::vp) { // T*
                pointer = xlb_getpointer<pointer_t>(wp);
            }
        }
        if (pointer) { ++ami.arg_index;
        } else { xlb_amfail(ami, XLB_E_AMI_BAD, "wrong type, void* expected"); }
    }

    void pusharg(lua_State* L, int& rc) {
        using AT = xlb_at<Vt, deref_t>;
        //printf("%d,(typeid.name=%s)\n", __LINE__, typeid(deref_t).name());
        rc += xlb_pushpointer<void*, AT>(L, pointer);
    }
}; //xlb_lpointer<Vt, void*, void*>

//----------------------------------------------------------------------------
template <typename Vt>
struct xlb_lpointer<Vt, const void*, const void*>  // void*
{
    using vter = Vt;
    using type = void*;
    using pointer_t = void*;
    using p_t = const void*;
    using deref_t = void;

    p_t pointer;

    xlb_lpointer(p_t p=nullptr) { pointer = (p_t)p; }
    xlb_lpointer& operator=(p_t p) { pointer = p; return (*this); }
    operator p_t() { return pointer; }

    void getarg(lua_State* L, xlb_ami& ami) {
        pointer = nullptr;
        //printf("%04d,(0x%p : %s)\n", __LINE__, this, __FUNCTION__);
        auto wp = xlb_testwrap<void>(L, ami.arg_index, "xlb_meta_xlb_pointer");
        if (wp && xlb_sametid<void>(wp)) {
            if (wp->tQlf==xlf_qlf::vp) { // T*
                pointer = xlb_getpointer<pointer_t>(wp);
            }
        }
        if (pointer) { ++ami.arg_index;
        } else { xlb_amfail(ami, XLB_E_AMI_BAD, "wrong type, void* expected"); }
    }

    void pusharg(lua_State* L, int& rc) {
        using AT = xlb_at<Vt, deref_t>;
        //printf("%d,(typeid.name=%s)\n", __LINE__, typeid(deref_t).name());
        rc += xlb_pushpointer<p_t, AT>(L, pointer);
    }
}; //xlb_lpointer<Vt, const void*, const void*>


//----------------------------------------------------------------------------
template <typename Vt, typename T, typename U>
struct xlb_lpointer<Vt, T*, U>  // T* or T&
{
    using vter = Vt;
    using type = T*;
    using pointer_t = T*;
    using deref_t = T;

    pointer_t pointer;

    xlb_lpointer(pointer_t p = nullptr) { pointer = (T*)p; }
    xlb_lpointer(T&& v) { pointer = &v; }
    xlb_lpointer& operator=(pointer_t p) { pointer = p; return (*this); }
    operator pointer_t() { return pointer; }
    operator T&() { return *pointer; }

    void getarg(lua_State* L, xlb_ami& ami) {
        pointer = nullptr;

        if constexpr (std::is_reference_v<U>) { // U==T&
            auto wp = xlb_towrap<T>(L, ami.arg_index);
            //printf("%04d,(0x%p : %d, %s)\n", __LINE__, wp, xlb_sametid<T>(wp), __FUNCTION__);
            if (wp && xlb_sametid<T>(wp) && 
                    (wp->tQlf==xlf_qlf::val || wp->tQlf==xlf_qlf::ref)) {
                // accept T (not const T) as T&
                pointer = xlb_getpointer<pointer_t>(wp);
            }
        }

        if (!pointer) {
            //printf("%04d,(0x%p : %s)\n", __LINE__, this, __FUNCTION__);
            auto wp = xlb_testwrap<T>(L, ami.arg_index, "xlb_meta_xlb_pointer");
            if (wp && xlb_sametid<T>(wp)) {
                if (wp->tQlf==xlf_qlf::vp) { // T*
                    pointer = xlb_getpointer<pointer_t>(wp);
                }
            } else {
                if constexpr ( std::is_same_v<T, char> ) {
                    if (lua_type(L, ami.arg_index) == LUA_TSTRING) {
                        pointer = const_cast<char*>(lua_tostring(L, ami.arg_index));
                    }
                }
                if constexpr ( std::is_function_v<T> ) {
                    using cbf_t = xlb_cbf<T*>; // FIXME: no PO
                    auto wp = xlb_tobasewrap(L, ami.arg_index);
                    if (wp && xlb_sametid<cbf_t>(wp)) {
                        //printf("%d,(typeid.name=%s,0x%p)\n", __LINE__, typeid(T).name(), wp);
                        auto p = reinterpret_cast<cbf_t*>(wp->getpointer());
                        // XXX:temporary update static member
                        // solve multi cbf using static member problem
                        p->updatestatic(L);
                        pointer = &cbf_t::cbf_agent;
                    }
                }
            }
        }

        if (pointer || lua_isnil(L, ami.arg_index)) { 
            // accept nil as nullptr
            ++ami.arg_index;
        } else { 
            printf("%d,(typeid.name=%s)\n", __LINE__, typeid(T).name());
            xlb_amfail(ami, XLB_E_AMI_BAD, "wrong type, T* or T& expected"); 
        }
    }

    void pusharg(lua_State* L, int& rc) {
        using AT = xlb_at<Vt, deref_t>;
        //printf("%d,(typeid.name=%s)\n", __LINE__, typeid(deref_t).name());
        if constexpr (std::is_reference_v<U>) { // U==T&
            if constexpr ( is_lstruct_v<Vt, AT> ) { // AT==xlb_lstruct<...>
                //printf("%04d,(0x%p : %s)\n", __LINE__, this, __FUNCTION__);
                rc += xlb_pushstructref(L, (*pointer), xlf_gc::no);
            } else {
                //printf("%04d,(0x%p : %s)\n", __LINE__, this, __FUNCTION__);
                rc += xlb_pushrefaspointer<pointer_t, AT>(L, pointer, xlf_gc::no);
            }
        } else {
            //printf("%d,(typeid.name=%s)\n", __LINE__, typeid(pointer_t).name());
            //printf("%d,(typeid.name=%s)\n", __LINE__, typeid(AT).name());
            rc += xlb_pushpointer<pointer_t, AT>(L, pointer);
        }
    }
};  // xlb_lpointer<T*, U>

//----------------------------------------------------------------------------
template <typename Vt, typename T, typename U>
struct xlb_lpointer<Vt, T* const, U>  // T *const
{
    using vter = Vt;
    using type = T* const;
    using pointer_t = T* const;
    using deref_t = T;

    pointer_t pointer;

    xlb_lpointer(pointer_t p = nullptr) : pointer(p) {}
    operator pointer_t() { return pointer; }

    void getarg(lua_State* L, xlb_ami& ami) {
        using w_t = xlb_wrap<T>;
        auto wp = reinterpret_cast<w_t*>(
            luaL_testudata(L, ami.arg_index, "xlb_meta_xlb_pointer"));

        if (wp && xlb_wpcompaddr(wp)) {
            pointer = xlb_getpointer<pointer_t>(wp);
            ++ami.arg_index;
        } else {
            xlb_amfail(ami, XLB_E_AMI_BAD,  "const pointer expected.");
        }
    }

    void pusharg(lua_State* L, int& rc) {
        using AT = xlb_at<Vt, deref_t>;
        rc += xlb_pushpointer<pointer_t, AT>(L, pointer);
            printf("%04d,(0x%p : %s)\n", __LINE__, this, __FUNCTION__);
    }
};  // xlb_lpointer<T* const, U, Vt>

//----------------------------------------------------------------------------
template <typename Vt, typename T, typename U>
struct xlb_lpointer<Vt, const T*, U>  // const T*, const T&
{
    using vter = Vt;
    using type = const T*;
    using pointer_t = const T*;
    using deref_t = const T;

    pointer_t pointer;

    xlb_lpointer(pointer_t p = nullptr) : pointer(p) {}

    // std::move(const T&) === const T
    template<typename CONST_REF>
    xlb_lpointer(CONST_REF&& r, std::enable_if_t<!std::is_pointer_v<CONST_REF>>* noused=0) 
    : pointer(&r) {}

    operator const T&() { return (*pointer); }
    operator pointer_t() { return pointer; }

    void getarg(lua_State* L, xlb_ami& ami) {
        pointer = nullptr;
        if constexpr (std::is_reference_v<U>) {
            //accept const T& or T& or const T or T
            auto wp = xlb_testwrap<T>(L, ami.arg_index);
            if (wp && xlb_wpcopyable(wp)) {
                pointer = xlb_getpointer<pointer_t>(wp);
            }
        } else {
            // accept T* or const T*
            auto wp = xlb_testwrap<T>(L, ami.arg_index, "xlb_meta_xlb_pointer");
            if (wp && xlb_sametid<T>(wp)) {
                pointer = xlb_getpointer<pointer_t>(wp);
            }
        }

        if (pointer) { ++ami.arg_index;
        } else {xlb_amfail(ami, XLB_E_AMI_BAD, "wrong type"); }

    }

    void pusharg(lua_State* L, int& rc) {
        using AT = xlb_at<Vt, deref_t>;
        if constexpr ( std::is_reference_v<U> ) {
            if constexpr ( is_lstruct_v<Vt, AT> ) { // AT==xlb_lstruct<const T>
                printf("%04d,(0x%p : %s)\n", __LINE__, this, __FUNCTION__);
                auto& v = (*pointer); // const T&
                rc += xlb_pushstructref(L, v, xlf_gc::no);
            } else {
                printf("%04d,(0x%p : %s)\n", __LINE__, this, __FUNCTION__);
                //rc += xlb_pushpointer<pointer_t, AT>(L, pointer);
                rc += xlb_pushrefaspointer<pointer_t, AT>(L, pointer, xlf_gc::no);
            }
        } else {
            rc += xlb_pushpointer<pointer_t, AT>(L, pointer);
            printf("%04d,(0x%p : %s)\n", __LINE__, this, __FUNCTION__);
        }
    }
};  // xlb_lpointer<const T*, U> or const T&

//-----------------------------------------------------------------------------
template <typename Vt>
struct xlb_lpointer<Vt, const char*, const char*> {
    using vter = Vt;
    using type = const char*;
    using pointer_t = const char*;

    pointer_t pointer;

    xlb_lpointer(pointer_t p = nullptr) : pointer(p) {}
    xlb_lpointer& operator=(pointer_t p) {
        pointer = p;
        return (*this);
    }
    operator pointer_t() const { return pointer; }

    void getarg(lua_State* L, xlb_ami& ami) {
        pointer = lua_tostring(L, ami.arg_index);
        ++ami.arg_index;
    }

    void pusharg(lua_State* L, int& rc) {
        lua_pushstring(L, pointer);
        ++rc;
    }
};  // xlb_lpointer<const char*>

//-----------------------------------------------------------------------------
template <typename Vt>
struct xlb_lstruct<Vt, void>  
{
    using vter = Vt;
    using type = void;
};

//-----------------------------------------------------------------------------
// xlb_lstruct for xlb_base_class<T>
// agent for T v, do not copy the object in the lua, just keep it's address
//-----------------------------------------------------------------------------
template <typename Vt, typename T>
struct xlb_lstruct  
{
    using vter = Vt;
    using type = T;
    using pointer_t = T*;

    pointer_t pointer { nullptr };
    bool is_moved { false };

    xlb_lstruct(T* p=nullptr) : pointer((T*)p) {}
    xlb_lstruct(T& v) : pointer(&v) {}
    xlb_lstruct(T&& v) { 
        pointer = &v; 
        is_moved = true;
        printf("%04d,(0x%p : %s)\n", __LINE__, pointer, __FUNCTION__);
    }
    operator T &() { return (*pointer); }

    void getarg(lua_State* L, xlb_ami& ami) {
        pointer = nullptr;
        assert(xlb_base_class<T>::meta_name != nullptr);

        // when T's AT==xlb_lstruct then wp<T&>.meta==wp<T>.meta
        auto wp = xlb_testwrap<T>(L, ami.arg_index);

        if (wp && xlb_wpcopyable(wp)) {
            pointer = xlb_getpointer<pointer_t>(wp);
        }

        if (pointer) { ++ami.arg_index;
        } else { xlb_amfail(ami, XLB_E_AMI_BAD, "wrong type"); }
    }


    void pusharg(lua_State* L, int& rc) {
        printf("%04d,(typeid=%s,is_moved=%d)\n", __LINE__, typeid(pointer).name(), is_moved);
        if constexpr ( std::is_array_v<T> ) {
            using e_t = std::remove_extent_t<T>;
            using idx_t = xlb_idx_t< std::extent_v<T, 0> >;
            auto& right = (*pointer);
            auto left = (new T());
            xlb_assignarrary<idx_t>::go(left, right, is_moved);
            pointer = reinterpret_cast<T*>(left); // XXX: T is not decay
            auto& v = (*pointer);
            rc += xlb_pushstructval(L, (T&)v, xlf_gc::yes_array);
        } else {
            auto& right = (*pointer);
            pointer = (is_moved) ? new T(std::move(right)) : new T(right);
            auto& v = (*pointer);
            rc += xlb_pushstructval(L, (T&)v, xlf_gc::yes);
        }
    }
};  // xlb_lstruct<T>

//-----------------------------------------------------------------------------
// T === const X or X
template <typename Vt, typename T>
struct xlb_lstruct<Vt, T&>  // reference, do not copy
{
    using vter = Vt;
    using type = T;
    using pointer_t = T*;

    T* pointer;
    xlb_lstruct(const T* p=nullptr) : pointer(p) {}
    xlb_lstruct(T&& v) : pointer(&v) {}
    operator T&() { return (*pointer); }

    void getarg(lua_State* L, xlb_ami& ami) {
        pointer = nullptr;
        assert(xlb_base_class<T>::meta_name != nullptr);

        auto wp = xlb_testwrap<T>(L, ami.arg_index);

        if (auto tmatched=wp && xlb_sametid<T>(wp)) {
            if constexpr (std::is_const_v<T>) {
                tmatched = (wp->tQlf==xlf_qlf::cref) || (wp->tQlf==xlf_qlf::cval); // const T&
                printf("%04d,(0x%p : %s)\n", __LINE__, pointer, __FUNCTION__);
            } else {
                tmatched = (wp->tQlf==xlf_qlf::ref) || (wp->tQlf==xlf_qlf::val); // T&
                printf("%04d,(0x%p : %s)\n", __LINE__, pointer, __FUNCTION__);
            }
            if (tmatched) {
                pointer = xlb_getpointer<pointer_t>(wp);
            }
        }

        if (pointer) { ++ami.arg_index;
        } else { xlb_amfail(ami, XLB_E_AMI_BAD, "wrong type"); }
    }

    void pusharg(lua_State* L, int& rc) {
        rc += xlb_pushstructref(L, (*pointer), xlf_gc::no);
    }
};  // xlb_lstruct<T&>

//-----------------------------------------------------------------------------

template <typename Vt, typename T>
struct xlb_lnumber 
{
    using vter = Vt;
    using type = T;
    T value;

    xlb_lnumber(T* p) { if (p) value = *p; }
    //xlb_lnumber() { value = 0.0; }
    xlb_lnumber(T v=0.0) { value = v; }
    //xlb_lnumber(T&& v) { value = v; }
    operator T&() { return value; }

    void getarg(lua_State* L, xlb_ami& ami) {
        value = lua_tonumber(L, ami.arg_index);
        ++ami.arg_index;
    }

    void pusharg(lua_State* L, int& rc) {
        lua_pushnumber(L, value);
        ++rc;
    }
};  // xlb_lnumber

//-----------------------------------------------------------------------------
template <typename Vt, typename T>
struct xlb_lintegral 
{
    using vter = Vt;
    using type = T;

    T value;

    xlb_lintegral(T* p) { if (p) value = *p;  }
    xlb_lintegral(const T& v=0) { value = v; }
    xlb_lintegral(T&& v) { value = v; }

    xlb_lintegral& operator=(T v) { value = v; return (*this); }

    operator T&() { return value; }

    void getarg(lua_State* L, xlb_ami& ami) 
    {
        if (lua_isboolean(L, ami.arg_index)) {
            value = (lua_toboolean(L, ami.arg_index)) ? 1 : 0;
        } else {
            // Converts the Lua value at the given index to the 
            // signed integral type lua_Integer. The Lua value must 
            // be an integer, or a number or string convertible to an 
            // integer ; otherwise, lua_tointegerx returns 0.
            value = lua_tointeger(L, ami.arg_index);
        }
        //printf("%04d,(%d,%s : %s)\n", __LINE__, value, lua_typename(L, (lua_type(L, ami.arg_index))), __FUNCTION__);
        ++ami.arg_index;
    }

    void pusharg(lua_State* L, int& rc) 
    {
        lua_pushinteger(L, value);
        ++rc;
    }
};  // xlb_lintegral

//-----------------------------------------------------------------------------

template <typename Vt, typename T>
struct xlb_lboolean 
{
    using vter = Vt;
    using type = bool;
    bool value;

    xlb_lboolean(bool b = false) : value(b) {}
    xlb_lboolean& operator=(int v) { value = v; return (*this); }
    operator bool() const { return value; }

    void getarg(lua_State* L, xlb_ami& ami) {
        value = lua_toboolean(L, ami.arg_index);
        //printf("%04d,(%d,%s : %s)\n", __LINE__, value, lua_typename(L, (lua_type(L, ami.arg_index))), __FUNCTION__);
        ++ami.arg_index;
    }

    void pusharg(lua_State* L, int& rc) {
        lua_pushboolean(L, value);
        ++rc;
    }
};

//-----------------------------------------------------------------------------
template <typename Vt>
struct xlb_lfunc
{
    using vter = Vt;
    using type = xlb_luafunc;
    int refid = LUA_NOREF;

    xlb_lfunc(int id = LUA_NOREF) : refid(id) {}
    //xlb_lfunc& operator=(int v) { value = v; return (*this); }
    //operator int() const { return refid; }
    operator xlb_luafunc() const { return { refid }; }

    void getarg(lua_State* L, xlb_ami& ami) {
        //printf("%04d,(%d,%d)\n", __LINE__, lua_type(L, ami.arg_index), LUA_TFUNCTION);
        if (lua_type(L, ami.arg_index) == LUA_TFUNCTION) {
            lua_pushnil(L);
            lua_copy(L, ami.arg_index, -1);
            refid = luaL_ref(L, LUA_REGISTRYINDEX);
            //printf("%04d,(%d)\n", __LINE__, refid);
            ++ami.arg_index;
        } else {
            xlb_amfail(ami, XLB_E_AMI_BAD, "xlb: function expected");
        }
    }

    void pusharg(lua_State* L, int& rc) {
        lua_rawgeti(L, LUA_REGISTRYINDEX, refid);
        ++rc;
    }
}; // xlb_lfunc

//-----------------------------------------------------------------------------

template <typename Vt, typename T>
struct xlb_carray 
{
    using vter = Vt;
    using type = T;
    T* value;
    xlb_carray& operator=(void* address) {
        value = (T*)address;
        return (*this);
    }
    operator T&() { xlb_dbg(); return (*value); }
    operator T*() { xlb_dbg(); return value; }
    explicit operator T() { return *value; }
};

//-----------------------------------------------------------------------------
// GC wrap, destructe wrap object
//-----------------------------------------------------------------------------
template <typename T>
int xlb_wpdtor(lua_State* L) {
    if (auto wp = xlb_testwrap<T>(L, 1)) { wp->~xlb_wrap<T>(); }
    return 0;
}

//-----------------------------------------------------------------------------
//  xlt_typelist
//-----------------------------------------------------------------------------
template <class Vt, class FT>
struct xlb_typeforge {
};

template <class Vt, class R, class Tx, class... A>
struct xlb_typeforge<Vt, R (Tx::*)(A...)> {
    using tuple_t    = std::tuple<xlb_at<Vt, A>...>;
    using idx_t      = xlb_idx_t<sizeof...(A)>;
    using param_t    = xlt_typelist<A...>;
    using result_t   = R;
    using rv_at      = xlb_at<Vt, xlt_rvtrait<R>>;
    using obj_t      = Tx;
    using arginfo_t  = array<xlb_ai, sizeof...(A)>;
    using const_t    = false_type;
};

template <class Vt, class R, class Tx, class... A>
struct xlb_typeforge<Vt, R (Tx::*)(A...) const> {
    using tuple_t    = std::tuple<xlb_at<Vt, A>...>;
    using idx_t      = xlb_idx_t<sizeof...(A)>;
    using param_t    = xlt_typelist<A...>;
    using result_t   = R;
    using rv_at      = xlb_at<Vt, xlt_rvtrait<R>>;
    using obj_t      = Tx;
    using arginfo_t  = array<xlb_ai, sizeof...(A)>;
    using const_t    = true_type;
};

//-----------------------------------------------------------------------------
#ifndef _WIN64
template <class Vt, class R, class... A>
struct xlb_typeforge<Vt, R (__cdecl*)(A...)> {
    using tuple_t    = std::tuple<xlb_at<Vt, A>...>;
    using idx_t      = xlb_idx_t<sizeof...(A)>;
    using param_t    = xlt_typelist<A...>;
    using result_t   = R;
    using rv_at      = xlb_at<Vt, xlt_rvtrait<R>>;
    using obj_t      = void;
    using arginfo_t  = array<xlb_ai, sizeof...(A)>;
    using const_t    = false_type;
};
#endif

//  On ARM and x64 processors, __stdcall is accepted and ignored by the compiler; 
//  on ARM and x64 architectures, by convention, arguments are passed in registers 
//  when possible, and subsequent arguments are passed on the stack. __fastcall is 
//  faster than __cdecl and __stdcall is default calling convention for Windows 
//  64-bit. The __fastcall calling convention specifies that arguments to functions 
//  are to be passed in registers, when possible. This calling convention only 
//  applies to the x86 architecture. 
template <class Vt, class R, class... A>
struct xlb_typeforge<Vt, R (__stdcall*)(A...)> {
    using tuple_t    = std::tuple<xlb_at<Vt, A>...>;
    using idx_t      = xlb_idx_t<sizeof...(A)>;
    using param_t    = xlt_typelist<A...>;
    using result_t   = R;
    using rv_at      = xlb_at<Vt, xlt_rvtrait<R>>;
    using obj_t      = void;
    using arginfo_t  = array<xlb_ai, sizeof...(A)>;
    using const_t    = false_type;
};

template <class Vt, class... A>
struct xlb_typeforge<Vt, void (*)(A...)> {
    using tuple_t    = std::tuple<xlb_at<Vt, A>...>;
    using idx_t      = xlb_idx_t<sizeof...(A)>;
    using param_t    = xlt_typelist<A...>;
    using result_t   = void;
    using rv_at      = xlb_at<Vt, xlt_rvtrait<void>>;
    using obj_t      = void;
    using arginfo_t  = array<xlb_ai, sizeof...(A)>;
    using const_t    = false_type;
};




//-----------------------------------------------------------------------------
// xlb_dfer
// function with default parameters provider
//-----------------------------------------------------------------------------

struct xlb_dfer : public xpo_base_dfer {
    template <class TUP> XLB_SII go(TUP& tuple, int dc) { return 0; }
};

template <class TUP, class T, int idx>
XLB_SIV xlb_default_assign(TUP& tuple, T&& A) {
    xlb_debug("(typeid.name=%s)\n", typeid(T).name());
    std::get<idx>(tuple) = A;
}

template <typename TUP, typename Idxer, typename... T>
struct xlb_setdefaultval {};

template <typename TUP, int... idx, typename... T>
struct xlb_setdefaultval<TUP, xlb_idx<idx...>, T...> {
    XLB_SIV go(TUP& tuple, int dc, T&&... Dvs) {
        constexpr auto tsize = xlb_tupsize_v<TUP>;
        constexpr auto dsize = sizeof...(Dvs);
        static_assert(tsize>=dsize, "too much default value");
        xlt_each{( 
                (idx>=(dsize-dc)) 
                ? (std::get<tsize - dsize + idx>(tuple) = std::forward<T>(Dvs), 
                  //printf("%04d,(%d-%d,%d,%d : %s)\n", __LINE__, tsize, dsize, idx, dc, __FUNCTION__),
                  XLB_STATEMENT_VALUE)
                : XLB_STATEMENT_VALUE  
                )...};
    }
};

template <typename TUP, typename... T>
XLB_SII xlb_putdefault(TUP& tuple, int dc, T&&... Dvs) {
    constexpr auto tsize = xlb_tupsize_v<TUP>;
    constexpr auto dsize = sizeof...(T);
    static_assert(tsize >= dsize);
    xlb_setdefaultval<TUP, xlb_idx_t<sizeof...(T)>, T...>::go(
        tuple, dc, std::forward<T>(Dvs)...);
    return sizeof...(Dvs);
}

//-----------------------------------------------------------------------------
// xlb_getargs
// decltype(AIs)===array<xlb_ai, ...>
//-----------------------------------------------------------------------------
template <typename TUP, typename Idx, typename Dft>
struct xlb_getargs {};

template <typename TUP, typename Dft>
struct xlb_getargs<TUP, xlb_idx<>, Dft> {
    template <typename AIs>
    XLB_SIV go(lua_State* L, TUP& tuple, AIs& ais, xlb_ami& ami) {
        //printf("%04d,(arg_count=%d, arg_index=%d)\n", __LINE__, ami.arg_count, ami.arg_index);
        if (ami.arg_count >= ami.arg_index) {
            xlb_amfail(ami, XLB_E_AMI_TOMUCH, "xlb: too much arguments");
        }
    }
};

template <typename TUP, int Param_i, int... idxs, typename Dft>
struct xlb_getargs<TUP, xlb_idx<Param_i, idxs...>, Dft> {
    template <typename AIs>
    XLB_SIV go(lua_State* L, TUP& tuple, AIs& ais, xlb_ami& ami) {
        if (ami.arg_count >= ami.arg_index) {
            auto& ai = ais[Param_i];
            //printf("%04d,(%d,%u)\n", __LINE__, ami.arg_count, ami.arg_index);
                ai.from = ami.arg_index;
                ai.type = lua_type(L, ami.arg_index);
                ai.index = Param_i + 1;
            std::get<Param_i>(tuple).getarg(L, ami);
                ai.to = ami.arg_index;  // [from,to)
        } else {
            ami.match_result = XLB_E_AMI_FEW;
        }

        if (xlb_ambad(ami)) {
            if (XLB_E_AMI_FEW == ami.match_result) {
                auto stack_remain = (ami.arg_count - (ami.arg_index - 1));
                auto args_remain = (ami.param_count - Param_i);
                auto dc = args_remain - stack_remain;
                ami.default_count = Dft::go(tuple, dc);
                if (stack_remain - args_remain + ami.default_count >= 0) {
                    ami.match_result = XLB_E_AMI_DEFAULT;
                } else {
                    xlb_amfail(ami, ami.match_result, "xlb: too few arguments");
                }
            }
        } else {
            xlb_getargs<TUP, xlb_idx<idxs...>,  Dft>::go( L, tuple, ais, ami);
        }
    }
};  // xlb_getargs

//-----------------------------------------------------------------------------
//  default value support
//-----------------------------------------------------------------------------
template <typename Lam>
struct xlb_derived_dfer : public xpo_base_dfer {
    ///< use static member to keep lambda instead non static member
    inline static Lam* plmd { nullptr };  
    xlb_derived_dfer(Lam& l) { plmd = &l; }
    template <typename TUP> XLB_SII go(TUP& tup, int dc) {
        return (*plmd)(tup, dc);
    }
};

template <typename Lam>
auto xpo_default(Lam lmd) {
    using po_default_t = xlb_derived_dfer<decltype(lmd)>;
    return po_default_t(lmd);
}

//-----------------------------------------------------------------------------
template<typename Idx, auto...Dvs> struct xlb_assign_default_value {};
template<int ...idx, auto...Dvs> 
struct xlb_assign_default_value<xlb_idx<idx...>, Dvs...> {
    template<typename TUP> XLB_SIV go(TUP& tup, int dc) {
        constexpr auto tsize = xlb_tupsize_v<TUP>;
        constexpr auto dsize = sizeof...(Dvs);
        static_assert(tsize>=dsize, "too much default value");
        xlt_each{( 
                (idx>=(dsize-dc)) ?  (std::get<tsize - dsize + idx>(tup)=Dvs, 0) :0 
                )...};
    }
};

template<auto...Dvs>
auto xpo_dvs() {
    auto lmd = [](auto& tup, int dc)->int{
        using Idx = xlb_idx_t<sizeof...(Dvs)>;
        xlb_assign_default_value<Idx, Dvs...>::template go(tup, dc);
        //printf("%04d,(<1>=%d,%u)\n", __LINE__, (int)get<1>(tup), sizeof...(Dvs));
        return sizeof...(Dvs);
    };
    return xpo_default(lmd);
}

//-----------------------------------------------------------------------------
//  xlb_derived_rier
//-----------------------------------------------------------------------------

template <int... PLACEHOLDERS>
struct xlb_derived_rier : public xpo_base_rier {};

using xlb_rier = void;

//-----------------------------------------------------------------------------
//  xlb_pter
//  push addition parameters of function into lua_State
//-----------------------------------------------------------------------------
struct xlb_pter {
    template <typename, typename>
    struct xlb_tir {};
};

template <typename TUP>
struct xlb_pter::xlb_tir<void, TUP>
{
    template <typename AIs>
    XLB_SIV go(lua_State* L, TUP& tuple, const AIs& ais, int& rc) {}
};

template <int... RPI>
struct xlb_pter::xlb_tir<xlb_derived_rier<RPI...>, std::tuple<>> {
    template <typename AIs>
    XLB_SIV go(lua_State* L, std::tuple<>& tuple, const AIs& ais, int& rc) {}
};

template <int... RPI, typename... A>
struct xlb_pter::xlb_tir<xlb_derived_rier<RPI...>, std::tuple<A...>> {
    template <typename AIs>
    XLB_SIV go(lua_State* L, std::tuple<A...>& tuple, const AIs& ais, int& rc) {
        xlt_each{(get<RPI - 1>(tuple).push(L, rc), XLB_STATEMENT_VALUE)...};
    }
};

//-----------------------------------------------------------------------------
// xlb_ctor_r trait for result of construtor
//-----------------------------------------------------------------------------
template <typename T> class xlb_ctor_r 
{
public:
    using type = T;
    xlb_ctor_r(T* p) : pointer(p) {}
    T& getobj() { return *pointer; }
protected:
    T* pointer = nullptr;
}; // xlb_ctor_r

/** XXX: argument #1 is table, object that create in Lua just through new
 * operator. this function is the agent of class contructor function and binded
 * to Lua as metatable's default call method named __call. those xlb_ctor_r
 * object must gc in Lua witch delete operator. ignore table that is __call
 * argument #1
 * TODO: make it PO, meet another new operator action
 */
template <typename T, typename... A>
xlb_ctor_r<T> xlb_ctor(xlb_ignore, A... args) {
    return { new T(args...) };
}

template <typename T> struct is_ctor_r : std::false_type {};
template <typename T> struct is_ctor_r<xlb_ctor_r<T>> : std::true_type {};

//-----------------------------------------------------------------------------
// @struct xlb_rv2l
// @brief push result of function into lua_State
//-----------------------------------------------------------------------------
struct xlb_rv2l 
{
    template <typename R, typename AT>
    struct xlb_tir {
        XLB_SIV go(lua_State* L, AT& r, int& rc) {
            xlb_debug("(result:typeid.name=%s)\n", typeid(R).name());
            r.pusharg(L, rc);
        }
    };

    /* XXX: for special type xlb_ctor_r, push new object to Lua
     * xlb_rv2l for xlb_ctor function return value (make it special type
     * xlb_ctor_r)
     */
    template <typename R, typename AT>
    struct xlb_tir<xlb_ctor_r<R>, AT> {
        XLB_SIV go(lua_State* L, xlb_ctor_r<R>& r, int& rc) {
            xlb_debug("(result:typeid.name=%s)\n", typeid(R).name());
            //rc += xlb_pushobj(L, r.pointer, xlf_gc::yes);
            rc += xlb_pushobj(L, r.getobj(), xlf_gc::yes);
        }
    };

};  // xlb_rv2l

//-----------------------------------------------------------------------------
// xlb_vter, help us to get AT(agent type) that is used to 
// 1. load variable from Lua
// 2. store variable
// 3. and push WT(wrap value) variable to Lua
// usage: using t = xlb_vter::xlb_tir<T>::type
//-----------------------------------------------------------------------------
struct xlb_vter {
    template <typename X, typename DJY = xlb_djy>
    struct xlb_tir {};
};  // xlb_vter

//-----------------------------------------------------------------------------
// ignore this var, it's a special val such as self object
//-----------------------------------------------------------------------------
template <>
struct xlb_vter::xlb_tir<xlb_ignore> {
    using vter = xlb_vter;
    using type = xlb_ignore;
};

//-----------------------------------------------------------------------------
// type for result value that with xlt_rvtrait of function 
// that is constructor; constructor function return xlb_ctor_r<X>;
// xlt_rvtrait means var is the result of function
//-----------------------------------------------------------------------------
template <typename X>
struct xlb_vter::xlb_tir<xlt_rvtrait<xlb_ctor_r<X>>> {
    using vter = xlb_vter;
    using type = xlb_ctor_r<X>;
};

//-----------------------------------------------------------------------------
// reference as pointer, and take it as pointer, 
// pass xlb_vter to help get more information about the pointer type.
//-----------------------------------------------------------------------------
template <typename X>  
struct xlb_vter::xlb_tir<xlt_rvtrait<X&>> {
    using vter = xlb_vter;
    using type = xlb_lpointer<vter, X*, X&>;
};

template <typename X>  
struct xlb_vter::xlb_tir<xlt_rvtrait<const X&>> {
    using vter = xlb_vter;
    using type = xlb_lpointer<vter, const X*, const X&>;
};

template <typename X>  // for pointer
struct xlb_vter::xlb_tir<xlt_rvtrait<X*>> {
    using vter = xlb_vter;
    using type = xlb_lpointer<vter, X*, X*>;
};

template <typename X>
struct xlb_vter::xlb_tir<xlt_rvtrait<X* const>> {
    using vter = xlb_vter;
    using type = xlb_lpointer<vter, X* const, X* const>;
};

// type for result of function that return void
template <>
struct xlb_vter::xlb_tir<xlt_rvtrait<void>> {
    using vter = xlb_vter;
    using type = xlt_rvtrait<void>;
};

template <>
struct xlb_vter::xlb_tir<xlt_rvtrait<bool>> {
    using vter = xlb_vter;
    using type = xlb_lboolean<vter, bool>;
};

template <typename X>
struct xlb_vter::xlb_tir<xlt_rvtrait<const X*>> {
    using vter = xlb_vter;
    using type = xlb_lpointer<vter, const X*, const X*>;
};

template <typename X>
struct xlb_vter::xlb_tir<xlt_rvtrait<const X* const>> {
    using vter = xlb_vter;
    using type = xlb_lpointer<vter, const X* const, const X* const>;
};

//--------------------------------------------------------------------------
template <>
struct xlb_vter::xlb_tir<void> {
    using vter = xlb_vter;
    using type = xlb_lstruct<vter, void>;
};

template <>
struct xlb_vter::xlb_tir<void*> {
    using vter = xlb_vter;
    using type = xlb_lpointer<vter, void*, void*>;
};

//--------------------------------------------------------------------------
template <>
struct xlb_vter::xlb_tir<xlb_luafunc> {
    using vter = xlb_vter;
    using type = xlb_lfunc<vter>;
};

//--------------------------------------------------------------------------
// pointer and reference
//--------------------------------------------------------------------------

template <typename T>
struct xlb_vter::xlb_tir<T&> {
    using vter = xlb_vter;
    using type = xlb_lpointer<vter, T*, T&>;
};

template <typename T>
struct xlb_vter::xlb_tir<T*> {
    using vter = xlb_vter;
    using type = xlb_lpointer<vter, T*, T*>;
};

template <typename T>
struct xlb_vter::xlb_tir<const T*> {
    using vter = xlb_vter;
    using type = xlb_lpointer<vter, const T*, const T*>;
};

template <typename T>
struct xlb_vter::xlb_tir<T* const> {
    using vter = xlb_vter;
    using type = xlb_lpointer<vter, T* const, T* const>;
};

//--------------------------------------------------------------------------
// XXX:匹配类型:除了一些特例化类型之外再对类型做一个选择(根据条件进行范围选择),
// 使这些类型对应到相应的代理类型上
// TODO:使这个选择链可以扩展
//--------------------------------------------------------------------------
template <bool, typename choose_if_true, typename choose_if_false>
struct xlt_ifelse 
{
    using type = choose_if_true;
};
template <typename choose_if_true, typename choose_if_false>
struct xlt_ifelse<false,  choose_if_true,  choose_if_false> 
{
    using type = choose_if_false;
};
template<bool cond, typename true_t, typename false_t>
using xlt_ifelse_t = typename xlt_ifelse<cond, true_t, false_t>::type;

//--------------------------------------------------------------------------
template <typename, typename, typename>
struct xlt_vter_query {};
struct xlt_fit_floating {};
struct xlt_fit_integral {};
struct xlt_fit_customize {};


template <typename T>
struct xlt_cond_integral 
{
    using type = xlt_ifelse_t<std::is_integral_v<T>, 
          xlt_fit_integral, 
          xlt_fit_customize>;
};
template<typename T>
using xlt_cond_integral_t = typename xlt_cond_integral<T>::type;

template <typename T>
struct xlt_cond_floating 
{
    using type = xlt_ifelse_t<std::is_floating_point_v<T>, 
        xlt_fit_floating,
        xlt_cond_integral_t<T>>;
};
template<typename T>
using xlt_cond_floating_t = typename xlt_cond_floating<T>::type;

//--------------------------------------------------------------------------
template <typename Vt, typename X, typename COND>
using xlt_vter_query_t = typename xlt_vter_query<Vt, X, COND>::type;

template <typename Vt, typename X>
struct xlt_vter_query<Vt, X, xlt_fit_customize> 
{
    using type = xlb_lstruct<Vt, X>;
};  // XXX:default

template <typename Vt, typename X>
struct xlt_vter_query<Vt, X, xlt_fit_integral> 
{
    //using type = xlb_lintegral<Vt, int>;
    //using type = xlb_lintegral<Vt, X>;
    using type = xlb_lintegral<Vt, std::remove_cv_t<X>>;
};

template <typename Vt, typename X>
struct xlt_vter_query<Vt, X, xlt_fit_floating> 
{
    //using type = xlb_lnumber<Vt, double>;
    using type = xlb_lnumber<Vt, X>;
};

//--------------------------------------------------------------------------
template <typename X>
struct xlb_vter::xlb_tir<X> 
{
    using type = xlt_vter_query_t<xlb_vter, X, xlt_cond_floating_t<X>>;
};

template <typename X>  ///< XXX: for return Type
struct xlb_vter::xlb_tir<xlt_rvtrait<X>> 
{
    using type = xlt_vter_query_t<xlb_vter, X, xlt_cond_floating_t<X>>;
};

//--------------------------------------------------------------------------
// PO selector
//--------------------------------------------------------------------------
template <typename T>
struct xpo_vter_selector { using type = T; };
template <> struct xpo_vter_selector<void> { using type = xlb_vter; };

template <typename T> struct xpo_dfer_selector { using type = T; };
template <> struct xpo_dfer_selector<void> { using type = xlb_dfer; };

template <typename T>
struct xpo_rier_selector { using type = T; };
template <> struct xpo_rier_selector<void> { using type = xlb_rier; };

template <typename T>
struct xpo_readonly_selector { using type = xpo_readonly; };
template <> struct xpo_readonly_selector<void> { using type = xpo_none; };

//--------------------------------------------------------------------------
template <typename BASE, template <typename> class SELECTOR, typename... PO>
struct xlt_searchlist 
{
    using type = xlb_t< SELECTOR<
        xlt_getderived_t<BASE, xlt_typelist<PO...>>
        > >;
};

//--------------------------------------------------------------------------
template <typename... PO>
using xpo_get_readonly =
    typename xlt_searchlist<xpo_base_readonly, xpo_readonly_selector,
                            PO...>::type;

template <typename... PO>
using xpo_get_vter =
    typename xlt_searchlist<xpo_base_vter, xpo_vter_selector, PO...>::type;

template <typename... PO>
using xpo_get_default =
    typename xlt_searchlist<xpo_base_dfer, xpo_dfer_selector, PO...>::type;

template <typename... PO>
using xpo_get_rier =
    typename xlt_searchlist<xpo_base_rier, xpo_rier_selector, PO...>::type;

//-----------------------------------------------------------------------------
//  xlb_selfobj
//-----------------------------------------------------------------------------
template <typename X, typename CONST_T>
struct xlb_selfobj {
    template <typename TUP, typename AIs>
    XLB_SIV go(lua_State* L, TUP& tuple, xlb_ami& ami, AIs& ais) {
        xlb_selftype<const X>().getarg(L, ami);
    }
};

template <typename X>
struct xlb_selfobj<X, false_type> {
    template <typename TUP, typename AIs>
    XLB_SIV go(lua_State* L, TUP& tuple, xlb_ami& ami, AIs& ais) {
        xlb_selftype<X>().getarg(L, ami);
    }
};

// for no self function to get self object, such as constructor function
template <>
struct xlb_selfobj<void, false_type> {
    template <typename TUP, typename AIs>
    XLB_SIV go(lua_State*, TUP& tuple, xlb_ami&, AIs& ais) {}
};

//-----------------------------------------------------------------------------
// xlb_invoke
//-----------------------------------------------------------------------------
struct xlb_invoke {
    template <typename R, bool, typename R_AT, typename Tx, 
             bool, typename FT, typename Idx,
             typename TYPELIST, typename R2L>
    struct xlb_tir {};
};

///< for r pobj->f(...)
template <typename R, typename R_AT, typename Tx, 
         typename FT, typename... A, int...idxs, typename R2L>
struct xlb_invoke::xlb_tir<R, false, R_AT, Tx, false, FT, xlb_idx<idxs...>,
                           xlt_typelist<A...>, R2L> {
    template <typename... Arg>
    XLB_SIV go(lua_State* L, xlb_ami& ami, FT f, std::tuple<Arg...>& tuple) {
        // AT do not copy the arguments and so no std::move() used
        printf("%04d,(typeid=%s)\n", __LINE__, typeid(R_AT).name());
        auto&& t = (reinterpret_cast<Tx*>(ami.obj)->*f)(std::get<idxs>(tuple)...);
        R_AT r(std::move(t));
        R2L::template xlb_tir<R, R_AT>::go(L, r, ami.rc);
    }
};

///< for void pobj->f(...)
template <typename Tx, typename FT, typename... A, int... idxs, typename R2L>
struct xlb_invoke::xlb_tir<void, true, xlt_rvtrait<void>, Tx, false, FT,
                           xlb_idx<idxs...>, xlt_typelist<A...>, R2L> {
    template <typename... Arg>
    XLB_SIV go(lua_State* L, xlb_ami& ami, FT f, std::tuple<Arg...>& tuple) {
        (reinterpret_cast<Tx*>(ami.obj)->*f)(
                (A&)std::get<idxs>(tuple) // explicit type cast
                ...);
    }
};

///< for r f(...)
template <typename R, typename R_AT, typename FT, typename... A, int... idxs, 
         typename R2L>
struct xlb_invoke::xlb_tir<R, false, R_AT, void, true, FT, xlb_idx<idxs...>,
                           xlt_typelist<A...>, R2L> {
    template <typename... Arg>
    XLB_SIV go(lua_State* L, xlb_ami& ami, FT f, std::tuple<Arg...>& tuple) {
        auto&& t = std::move(f(
                    (A&)std::get<idxs>(tuple) // explicit type cast
                    ...));

        // when agent for constructor that create callback gent object
        // and this function called in xlb_f2cf_pure
        if constexpr ( is_ctor_r<R>::value ) {
            if constexpr ( std::is_base_of_v<xlb_cbcf_base, xlb_t<R>> ) {
                t.getobj().setLua(L);
            }
        }

        R_AT r(std::move(t));
        R2L::template xlb_tir<R, R_AT>::go(L, r, ami.rc);
    }
};

///< for void f(...)
template <typename FT, typename... A, int... idxs, typename R2L>
struct xlb_invoke::xlb_tir<void, true, xlt_rvtrait<void>, void, true, FT,
                           xlb_idx<idxs...>, xlt_typelist<A...>, R2L> {
    template <typename... Arg>
    XLB_SIV go(lua_State* L, xlb_ami&, FT f, std::tuple<Arg...>& tuple) {
        f((A&)std::get<idxs>(tuple)...);
    }
};

//-----------------------------------------------------------------------------
//  xlt_each_ovlfunc
//-----------------------------------------------------------------------------

template <lua_CFunction... fcandidate> struct xlt_call_ovl;

template <lua_CFunction f, lua_CFunction... fcandidate>
struct xlt_call_ovl<f, fcandidate...> {
    XLB_SIV go(lua_State* L, xlb_ami& ami) {
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
        if constexpr ( sizeof...(fcandidate)>0 ) {
            if (xlb_ambad(ami)) {
                ami.rc = 0;
                lua_pop(L, lua_gettop(L)-ami.arg_count);
                xlt_call_ovl<fcandidate...>::go(L, ami);
            }
        }
    }
};


//-----------------------------------------------------------------------------
//  xlb_cfunction
//  overload function
//-----------------------------------------------------------------------------
template <typename FT, FT f, 
         typename Dft = xlb_dfer, 
         typename RIER = xlb_rier,
         typename R2L = xlb_rv2l, 
         typename PTER = xlb_pter, 
         typename Vt = xlb_vter>
//void xlb_cfunction(lua_State* L, xlb_ami& ami) {
int xlb_cfunction(lua_State* L) {
    using forge_t = xlb_typeforge<Vt, FT>;
    using tuple_t = typename forge_t::tuple_t;
    using idx_t = typename forge_t::idx_t;
    using param_t = typename forge_t::param_t;
    using result_t = typename forge_t::result_t;
    using rv_at = typename forge_t::rv_at;
    using obj_t = typename forge_t::obj_t;
    using arginfo_t = typename forge_t::arginfo_t;
    using const_t = typename forge_t::const_t;

    arginfo_t ais;
    tuple_t tuple;

    // get ami, first upvalue is xlb_ami with inner function
    // if get ami, means f is inner function
    auto p_ami = reinterpret_cast<xlb_ami*>(
            lua_touserdata(L, lua_upvalueindex(XLB_UPVALUE_1)));
    std::unique_ptr<xlb_ami> ptr_ami;
    if (nullptr == p_ami) {
        ptr_ami.reset(new xlb_ami(lua_gettop(L)));
        p_ami = ptr_ami.get();
    }
    auto& ami = (*p_ami);

    ami.arg_index = 1;
    ami.param_count = param_t::size;
    printf("%04d,(0x%p : %d : %d: %s)\n", __LINE__, p_ami, ami.arg_index, ami.param_count, __FUNCTION__);

    xlb_selfobj<obj_t, const_t>::go(L, tuple, ami, ais);

    if (!xlb_ambad(ami)) {
        xlb_getargs<tuple_t, idx_t, Dft>::go(L, tuple, ais, ami);
    }

    if (!xlb_ambad(ami)) {
        xlb_invoke::template xlb_tir<result_t,
                                     std::is_same_v<result_t, void>, rv_at,
                                     obj_t, std::is_same_v<obj_t, void>,
                                     FT, idx_t, param_t, R2L>::go(L, ami, f,
                                                                      tuple);
        PTER::template xlb_tir<RIER, tuple_t>::go(L, tuple, ais, ami.rc);

    } else {
        if (ptr_ami.get()==nullptr) { // f is inner function
            ami.rc = ami.arg_count; // recover scene
        } else {
            ami.rc = luaL_argerror(L, ami.arg_index, ami.extmsg.c_str());
        }
    }
    return ami.rc;
}  // xlb_cfunction

//-----------------------------------------------------------------------------
//  xlb_cfunction
//  overload function
//-----------------------------------------------------------------------------
template <lua_CFunction f, lua_CFunction... fcandidate>
int xlb_ovlfunction(lua_State* L) {
    xlb_ami ami(lua_gettop(L));
    xlt_call_ovl<f, fcandidate...>::go(L, ami);
    if (xlb_ambad(ami)) {
        ami.rc = luaL_argerror(L, ami.arg_index, ami.extmsg.c_str());
    }
    return ami.rc;
}

//-----------------------------------------------------------------------------
//  xlb_policy
//-----------------------------------------------------------------------------
struct xlb_policy {
    using Dft = void;
    using RIER = void;
    using Vt = void;
};

//-----------------------------------------------------------------------------
//  xlb_fmate help to handle cf's upvalue such as function pointer
//-----------------------------------------------------------------------------

template <class FT>
struct xlb_fmate : public xlb_base_fptr {
    using self_t = xlb_fmate<FT>;
    FT fpointer;

    xlb_fmate(FT f=nullptr, onregistry_t callback=nullptr)
        : xlb_base_fptr(callback), fpointer(f) {}

    virtual int pushupvalue(lua_State* L) override {
        int rc{0};

        auto place = lua_newuserdata(L, sizeof(self_t));
        new (place) self_t(fpointer);  // XXX:wrap fpointer as upvalue
        ++rc;

        if (nullptr != onregistry) {
            rc += onregistry(L, this);
        }
        xlb_dbg();
        return rc;
    }

    FT topointer(lua_State* L, int index) {
        auto p = lua_touserdata(L, lua_upvalueindex(index));
        auto fpa = reinterpret_cast<self_t*>(p);
        assert(fpa != nullptr);
        return fpa->fpointer;
    }
    
    FT topointer() { return fpointer; }

    XLB_SII newuserdata(lua_State* L, FT f) {
        auto place = lua_newuserdata(L, sizeof(self_t));
        new (place) self_t(f);  // XXX:wrap fpointer as upvalue
        return 1;
    }

    XLB_SIT create(FT f) { return xlb_base_fptr::ptr_t(new self_t(f)); }

};  // xlb_fmate


//-----------------------------------------------------------------------------
// call back function
//-----------------------------------------------------------------------------
template<typename FT, typename... PO> struct xlb_cbf{};

template <typename R, typename...A, class... PO>
struct xlb_cbf<R(__stdcall*)(A...), PO...> : public xlb_cbcf_base {

    inline static lua_State* ls_static { nullptr };
    inline static int id_static { LUA_NOREF };
    virtual void setLua(lua_State* L) override { ls_local = L; }
    virtual void updatestatic(lua_State* L) override 
    { 
        ls_static = L;
        id_static = id_local; 
    }

    lua_State* ls_local { nullptr };
    int id_local { LUA_NOREF };

    using FT = R(*)(A...);
    using Vt = xpo_get_vter<PO...>;

    xlb_cbf(xlb_luafunc& luaf) { id_local = luaf.ref_id; }
    xlb_cbf(int id) { id_local = id; }
    virtual ~xlb_cbf() {
        assert(ls_local);
        luaL_unref(ls_local, LUA_REGISTRYINDEX, id_local);
    }

    static R cbf_agent(A...a) __attribute__((stdcall)) {
        auto& L = ls_static;
        assert(L);
        assert(id_static!=LUA_REFNIL && id_static!=-1);
        auto rc { 0 };
        lua_rawgeti(L, LUA_REGISTRYINDEX, id_static);
        assert(lua_isfunction(L, -1));
        xlt_each{(xlb_at<Vt, A>(a).pusharg(L, rc), XLB_STATEMENT_VALUE)...};
        lua_pcall(L, sizeof...(A),  LUA_MULTRET, 0);
        xlb_ami ami(lua_gettop(L));
        ami.arg_index = lua_gettop(L);
        if constexpr ( !std::is_same_v<R, void> ) {
            xlb_at<Vt, R> r;
            r.getarg(L, ami);
            //using x = BOOL (CALLBACK* )(HWND, LPARAM);
            //printf("%04d,(%d,%s : %s)\n", __LINE__, (R&)r, typeid(R).name(), __FUNCTION__);
            //printf("%04d,(%d,%s : %s)\n", __LINE__, (R&)r, typeid(HWND).name(), __FUNCTION__);
            //printf("%04d,(%s : %s)\n", __LINE__, typeid(x).name(), __FUNCTION__);
            return (R&)r;
        }
    }

}; // xlb_cbf

#ifndef _WIN64
template <typename R, typename...A, class... PO>
struct xlb_cbf<R (*)(A...), PO...> : public xlb_cbcf_base {

    inline static lua_State* ls_static { nullptr };
    inline static int id_static { LUA_NOREF };
    virtual void setLua(lua_State* L) override { ls_local = L; }
    virtual void updatestatic(lua_State* L) override 
    { 
        ls_static = L;
        id_static = id_local; 
    }

    lua_State* ls_local { nullptr };
    int id_local { LUA_NOREF };

    using FT = R(*)(A...);
    using Vt = xpo_get_vter<PO...>;

    xlb_cbf(xlb_luafunc& luaf) { id_local = luaf.ref_id; }
    xlb_cbf(int id) { id_local = id; }
    virtual ~xlb_cbf() {
        assert(ls_local);
        luaL_unref(ls_local, LUA_REGISTRYINDEX, id_local);
    }

    static R cbf_agent(A...a) {
        auto& L = ls_static;
        assert(L);
        assert(id_static!=LUA_REFNIL && id_static!=-1);
        auto rc { 0 };
        lua_rawgeti(L, LUA_REGISTRYINDEX, id_static);
        assert(lua_isfunction(L, -1));
        xlt_each{(xlb_at<Vt, A>(a).pusharg(L, rc), XLB_STATEMENT_VALUE)...};
        lua_pcall(L, sizeof...(A),  LUA_MULTRET, 0);
        xlb_ami ami(lua_gettop(L));
        ami.arg_index = lua_gettop(L);
        if constexpr ( !std::is_same_v<R, void> ) {
            xlb_at<Vt, R> r;
            r.getarg(L, ami);
            //using x = BOOL (CALLBACK* )(HWND, LPARAM);
            //printf("%04d,(%d,%s : %s)\n", __LINE__, (R&)r, typeid(R).name(), __FUNCTION__);
            //printf("%04d,(%d,%s : %s)\n", __LINE__, (R&)r, typeid(HWND).name(), __FUNCTION__);
            //printf("%04d,(%s : %s)\n", __LINE__, typeid(x).name(), __FUNCTION__);
            return (R&)r;
        }
    }

}; // xlb_cbf
#endif

//-----------------------------------------------------------------------------
//  xlb_f2cf_pure
//  no upvalue for cfunction
//-----------------------------------------------------------------------------
template <auto f, class... PO>
int xlb_f2cf_pure(lua_State* L) {
    using Vt = xpo_get_vter<PO...>;
    using Dft = xpo_get_default<PO...>;
    using RIER = xpo_get_rier<PO...>;

    using FT = decltype(f);
    using forge_t = xlb_typeforge<Vt, FT>;
    using tuple_t = typename forge_t::tuple_t;
    using idx_t = typename forge_t::idx_t;
    using param_t = typename forge_t::param_t;
    using result_t = typename forge_t::result_t;
    using rv_at = typename forge_t::rv_at;
    using obj_t = typename forge_t::obj_t;
    using arginfo_t = typename forge_t::arginfo_t;
    using const_t = typename forge_t::const_t;

    arginfo_t ais;
    tuple_t tuple;
    xlb_ami ami(lua_gettop(L));
    ami.param_count = param_t::size;

    // maybe obj_t == void
    xlb_selfobj<obj_t, const_t>::go(L, tuple, ami, ais);

    if (!xlb_ambad(ami)) {
        xlb_getargs<tuple_t, idx_t, Dft>::go(L, tuple, ais, ami);
    }

    if (xlb_ambad(ami)) {
        return luaL_argerror(L, ami.arg_index, ami.extmsg.c_str());
    }

    ami.rc = 0;
    xlb_invoke::template xlb_tir<result_t, std::is_same_v<result_t, void>,
                                 rv_at, obj_t, std::is_same_v<obj_t, void>,
                                 FT, idx_t, param_t, xlb_rv2l>::go(L, ami,
                                                                       f,
                                                                       tuple);

    xlb_pter::template xlb_tir<RIER, tuple_t>::go(L, tuple, ais, ami.rc);
    return ami.rc;

}  // xlb_f2cf_pure

//-----------------------------------------------------------------------------
// xlb_f2cf_upvalue
//-------------------------------------------------------------------------------
template <class FT, /*FT f,*/ class... PO>
int xlb_f2cf_upvalue(lua_State* L) {
    using Vt = xpo_get_vter<PO...>;
    using Dft = xpo_get_default<PO...>;
    using RIER = xpo_get_rier<PO...>;

    using forge_t = xlb_typeforge<Vt, FT>;
    using tuple_t = typename forge_t::tuple_t;
    using idx_t = typename forge_t::idx_t;
    using param_t = typename forge_t::param_t;
    using result_t = typename forge_t::result_t;
    using rv_at = typename forge_t::rv_at;
    using obj_t = typename forge_t::obj_t;
    using arginfo_t = typename forge_t::arginfo_t;
    using const_t = typename forge_t::const_t;

    arginfo_t ais;
    tuple_t tuple;
    xlb_ami ami(lua_gettop(L));
    ami.param_count = param_t::size;

    xlb_selfobj<obj_t, const_t>::go(L, tuple, ami, ais);

    if (!xlb_ambad(ami)) {
        xlb_getargs<tuple_t, idx_t, Dft>::go(L, tuple, ais, ami);
    }
    if (xlb_ambad(ami)) {
        return luaL_argerror(L, ami.arg_index, ami.extmsg.c_str());
    }

    xlb_fmate<FT> fpa;
    auto f = fpa.topointer(L, XLB_UPVALUE_1);

    ami.rc = 0;
    xlb_invoke::template xlb_tir<result_t, std::is_same_v<result_t, void>,
                                 rv_at, obj_t, std::is_same_v<obj_t, void>,
                                 FT, idx_t, param_t, xlb_rv2l>::go(L, ami,
                                                                       f,
                                                                       tuple);

    xlb_pter::template xlb_tir<RIER, tuple_t>::go(L, tuple, ais, ami.rc);
    return ami.rc;

}  // xlb_f2cf_upvalue

//-----------------------------------------------------------------------------
// xlb_propgetter
//-----------------------------------------------------------------------------
template <class Pro_t> struct xlb_propforge {};

template <class P, class Tx>
struct xlb_propforge<P Tx::*> {
    using obj_t = Tx;
    using property_t = P;
};

template <typename Vt, typename Prop_t>
XLB_SIV xlb_pushprop(lua_State* L, Prop_t& prop, int& rc, xlf_prop vor) {
    if (xlf_prop::byref == vor) {
        //using Prop_AT = xlb_at<Vt, std::add_pointer_t<Prop_t>>;
        using Prop_AT = xlb_at<Vt, std::add_lvalue_reference_t<Prop_t>>;
        Prop_AT agent { &prop };

        xlb_debug("(typeid.name=%s)\n", typeid(&prop).name());
        xlb_debug("(typeid.name=%s)\n", typeid(Prop_AT).name());
        xlb_debug("(typeid.name=%s)\n", typeid(Prop_t).name());
        agent.pusharg(L, rc);
    }

    if (xlf_prop::byval == vor) {
        using Prop_AT = xlb_at<Vt, Prop_t>;
        Prop_AT agent { prop };
        
        xlb_debug("(typeid.name=%s)\n", typeid(Prop_AT).name());
        xlb_debug("(typeid.name=%s)\n", typeid(Prop_t).name());
        agent.pusharg(L, rc);
    }
}

template <class Prop_t, class... PO>
int xlb_propgetter(lua_State* L, void* vmate, xlf_prop vor = xlf_prop::byval) {  // t,k
    using Vt         = xpo_get_vter<PO...>;
    using forge_t    = xlb_propforge<Prop_t>;
    using obj_t      = typename forge_t::obj_t;
    using property_t = typename forge_t::property_t;

    auto rc { 0 };
    auto pobj { xlb_toself<obj_t>(L, 1) };
    auto p2prop = xlb_pmate<Prop_t>::get(vmate);
    xlb_pushprop<Vt, property_t>(L, (pobj->*p2prop), rc, vor);
    return rc;
} // xlb_propgetter

template <class Prop_t, class... PO>
int xlb_propsetter(lua_State* L, void* vmate, xlf_prop vor = xlf_prop::byval) {  // t,k,v
    using Vt           = xpo_get_vter<PO...>;
    using forge_t      = xlb_propforge<Prop_t>;
    using obj_t        = typename forge_t::obj_t;
    using property_t   = typename forge_t::property_t;
    using property_at  = xlb_at<Vt, property_t>;

    if constexpr ( !std::is_const_v<property_t>) {
        auto wp { xlb_towrap<obj_t>(L, 1) };
        if (wp && !xlb_wpisconst(wp)) {
            auto pobj { xlb_getpointer<obj_t*>(wp) };
            assert(pobj);
            xlb_ami ami(lua_gettop(L));
                ami.obj = pobj;
                ami.arg_index = 3; // 1:t,2:k,3:v

            property_at v;
            v.getarg(L, ami);

            auto p2prop = xlb_pmate<Prop_t>::get(vmate);

            if constexpr ( std::is_array_v<property_t> ) {
                using e_t = std::remove_extent_t<property_t>;
                using idx_t = xlb_idx_t< std::extent_v<property_t, 0> >;
                auto& right = (property_t&)v;
                auto left = ((*pobj).*p2prop);

                xlb_assignarrary<idx_t>::go(left, right);
            } else {
                (*pobj).*p2prop = (std::add_lvalue_reference_t<property_t>)v;
            }

        } else { /* do nothing for const object */ }
    } else { /* do nothing for const member */ }

    return 0;
}  // xlb_propsetter

//-----------------------------------------------------------------------------
//  @struct xlb_property
//  @brief property include function and member, read write flag
//-----------------------------------------------------------------------------

struct xlb_property {
    using self_t = xlb_property;
    using rvr_t = xlb_property&&;
    enum { unknown, readonly, readwrite, writeonly, function };
    int type = unknown;

    xlb_prophandler getter;
    xlb_prophandler setter;
    xlb_funchandler funcer;

    xlb_property() {}

    template <typename Prop_t, typename... PO>
    static self_t create(Prop_t prop, xpo_readonly) {
        xlb_property temp;
        temp.type = xlb_property::readonly;
        temp.getter = xlb_prophandler(xlb_propgetter<Prop_t, PO...>,
                                      xlb_makepropptr(prop));
        return temp;
    }

    template <typename Prop_t, typename... PO>
    static self_t create(Prop_t prop, xpo_none) {
        xlb_property temp;
        temp.type = xlb_property::readwrite;
        temp.getter = xlb_prophandler(xlb_propgetter<Prop_t, PO...>,
                                      xlb_makepropptr(prop));
        temp.setter = xlb_prophandler(xlb_propsetter<Prop_t, PO...>,
                                      xlb_makepropptr(prop));
        return temp;
    }

    template <typename FT>
    static self_t create(lua_CFunction cf, FT f) {
        xlb_property temp;
        temp.type = xlb_property::function;
        temp.funcer = xlb_funchandler(cf, xlb_makefuncptr(f));
        return temp;
    }

    static self_t create(lua_CFunction cf) {
        xlb_property temp;
        temp.type = xlb_property::function;
        temp.funcer = xlb_funchandler(cf, xlb_makefuncptr(nullptr));
        return temp;
    }

};  // xlb_property

//-----------------------------------------------------------------------------
//  module namespace
//-----------------------------------------------------------------------------
struct xlb_module;
struct xli_scope;

struct xlb_regitem {
    std::string name;
    xlb_regitem(const char* n="") : name(n) {}
    virtual void registry(xli_scope* ns) {}
};  // xlb_regitem

struct xlb_regchain : public std::vector<xlb_regitem*> {
    template <class... T>
    xlb_regchain(const T&... regitem) {
        xlt_each{(push_back((xlb_regitem*)&regitem), XLB_STATEMENT_VALUE)...};
    }
};  // xlb_regchain

//-----------------------------------------------------------------------------
struct xli_scope {
    lua_State* lua { nullptr };
    const char* luaTableName { (const char*)nullptr };
    int luaIndex = 0;
    int parent_table_index = 0;
};  // xli_scope

//-----------------------------------------------------------------------------
template <typename FT, class... PO>
struct xlb_function : public xlb_regitem {
    using rvr_t = xlb_function&&;
    FT fpointer;

    xlb_function(const char* fn, FT f) : xlb_regitem(fn), fpointer(f) {}

    virtual ~xlb_function() {}

    virtual void registry(xli_scope* ns) override {
        assert(ns);
        auto& L = ns->lua;
        lua_pushstring(L, name.c_str());
        auto count_upvalue = xlb_fmate<FT>::newuserdata(L, fpointer);
        lua_pushcclosure(L, xlb_f2cf_upvalue<FT, PO...>, count_upvalue);
        lua_rawset(L, ns->luaIndex);
    }

    rvr_t arg() { return std::move(*this); }

};  // xlb_function

//-----------------------------------------------------------------------------
struct xlb_cf : public xlb_regitem {
    using rvr_t = xlb_cf&&;
    lua_CFunction fpointer;

    xlb_cf(const char* fn, lua_CFunction cf) : xlb_regitem(fn), fpointer(cf) {}

    virtual ~xlb_cf() {}

    virtual void registry(xli_scope* ns) override {
        auto& L = ns->lua;
        lua_pushstring(L, name.c_str());
        lua_pushcfunction(L, fpointer);
        lua_rawset(L, ns->luaIndex);
    }

    rvr_t arg() { return std::move(*this); }

};  // xlb_cf


//-----------------------------------------------------------------------------
template <typename FT, typename... PO>
auto xlb_f(const char* fn, FT f,
        std::enable_if_t<std::is_function_v<std::remove_pointer_t<FT>>>*noused=0 
        ) { return xlb_function<FT, PO...>(fn, f); }

auto xlb_f(const char* fn, lua_CFunction f) { return xlb_cf(fn, f); }

//-----------------------------------------------------------------------------

template <typename Lambda>
struct xlt_lambda {
    template < typename T > struct deduce_type ;
    template < typename R, typename obj_t, typename... A >
    struct deduce_type< R(obj_t::*)(A...) const >
    { using type = R (*)(A...); };
    using type = xlb_t< deduce_type<Lambda> >;
};

template <typename Lambda>
auto xlb_f(const char* fn, Lambda lambda, 
        std::enable_if_t<!std::is_function_v<std::remove_pointer_t<Lambda>>>*noused=0) {
    using lambda_ft = xlb_t< xlt_lambda<decltype(&Lambda::operator())> >;
    return xlb_function<lambda_ft>(fn, (lambda_ft)lambda);
}

//-----------------------------------------------------------------------------
struct xlb_namespace : public xli_scope, public xlb_regitem {
    xlb_regchain chain;
    xlb_namespace(const char* space_name = nullptr) : xlb_regitem(space_name) {
        xli_scope::luaTableName = space_name;
        assert(nullptr != luaTableName);  ///< name of namespace expected
    }

    virtual void registry(xli_scope* parent_ns) override {
        auto L = parent_ns->lua;
        xli_scope::lua = L;
        lua_pushstring(L, luaTableName);
        lua_newtable(L);
        luaIndex = lua_gettop(L);

        for (auto& reg : chain) {
            reg->registry(this);
        }
        lua_rawset(L, parent_ns->luaIndex);
    }

    xlb_namespace& operator()(xlb_regchain&& items) {
        chain = std::move(items);
        return (*this);
    }

};  // xlb_namespace

//-----------------------------------------------------------------------------
struct xlb_const : public xlb_regitem {
    uint32_t cv;
    xlb_const(const char* name, uint32_t v) : xlb_regitem(name), cv(v) {}
    virtual void registry(xli_scope* parent_ns) override {
        auto L = parent_ns->lua;
        lua_pushstring(L, name.c_str());
        lua_pushinteger(L, cv);
        lua_rawset(L, parent_ns->luaIndex);
    }
};

//-----------------------------------------------------------------------------
struct xlb_module : public xli_scope, public xlb_regitem {
    xlb_module(lua_State* L, const char* table_name = nullptr, int pti = 0) {
        xlb_debug(":+module\n");
        xli_scope::luaTableName = table_name;
        xli_scope::lua = L;
        xli_scope::parent_table_index = pti;
    }

    xlb_module& operator()(const xlb_regchain& chain) {
        auto& L = xli_scope::lua;
        auto& moduleName = xli_scope::luaTableName;

        auto havemodule = false;
        //printf("%04d,(%d,%p : %s)\n", __LINE__, parent_table_index, moduleName, __FUNCTION__);
        if (moduleName) {
            if (0 != parent_table_index) {
                lua_pushstring(L, moduleName);
                lua_gettable(L, parent_table_index);
            } else {
                lua_getglobal(L, moduleName);
            }
            havemodule = (lua_type(L, -1) == LUA_TTABLE);
            if (!havemodule) lua_pop(L, 1);
            //printf("%04d,(%d : %s)\n", __LINE__, havemodule, __FUNCTION__);
        }

        if (!havemodule) {
            if (nullptr != moduleName) {
                lua_pushstring(L, moduleName);
            }
            lua_newtable(L);
        }

        luaIndex = lua_gettop(L);
        for (auto& reg : chain) {
            reg->registry(this);
        }

        if (!havemodule && (nullptr != moduleName)) {
            if (0 != parent_table_index) {
                if (parent_table_index < 0) parent_table_index -= 2;
                lua_rawset(L, parent_table_index);
            } else {
                lua_setglobal(L, moduleName);
                lua_pop(L, 1);  // the table name that have been pushed
            }
        }
        return (*this);
    }

    virtual void registry(xli_scope* ns) override {}

};  // xlb_module

//-----------------------------------------------------------------------------
//  xlb_base_class
//-------------------------------------------------------------------------------
template <typename X>
struct xlb_base_class : public xlb_regitem {
    using self_t = xlb_base_class;
    using rvr_t = self_t&&;
    using this_t = self_t*;
    inline static xlb_meta_t       meta_name     { nullptr };
    inline static xlb_meta_t       type_name     { nullptr };
    inline static std::string      meta_name_buf {};
    inline static std::string      type_name_buf {};
    inline static xlb_metas_t      super_names   {};
    inline static xlb_regs_t       meta_funcs    {{nullptr, nullptr}};
    inline static xlb_regs_t       type_table    {{nullptr, nullptr}};
    inline static xlb_classfuncs_t method_funcs  {};
    inline static xlb_consts_t     const_values  {};
    inline static xlb_member_t     member_map    {};

    // xlb_f2cf_static
    template <class FT, /*FT f,*/ class... PO>
    static int xlb_f2cf_static(lua_State* L) {
        using Vt = xpo_get_vter<PO...>;
        using Dft = xpo_get_default<PO...>;
        using RIER = xpo_get_rier<PO...>;

        using forge_t = xlb_typeforge<Vt, FT>;
        using tuple_t = typename forge_t::tuple_t;
        using idx_t = typename forge_t::idx_t;
        using param_t = typename forge_t::param_t;
        using result_t = typename forge_t::result_t;
        using rv_at = typename forge_t::rv_at;
        using obj_t = typename forge_t::obj_t;
        using arginfo_t = typename forge_t::arginfo_t;
        using const_t = typename forge_t::const_t;

        arginfo_t ais;
        tuple_t tuple;
        xlb_ami ami(lua_gettop(L));
        ami.param_count = param_t::size;

        xlb_selfobj<obj_t, const_t>::go(L, tuple, ami, ais);

        if (!xlb_ambad(ami)) {
            xlb_getargs<tuple_t, idx_t, Dft>::go(L, tuple, ais, ami);
        }

        if (xlb_ambad(ami)) {
            return luaL_argerror(L, ami.arg_index, ami.extmsg.c_str());
        }

        xlb_fmate<FT> fpa;
        auto f = fpa.topointer(L, 1);  ///< XXX:first upvalue

        ami.rc = 0;
        xlb_invoke::template xlb_tir<
            result_t, std::is_same_v<result_t, void>, rv_at, obj_t,
            std::is_same_v<obj_t, void>, FT, idx_t, param_t,
            xlb_rv2l>::go(L, ami, f, tuple);

        xlb_pter::template xlb_tir<RIER, tuple_t>::go(L, tuple, ais, ami.rc);
        return ami.rc;

    }  // xlb_f2cf_static

    static int index_handler(lua_State* L)  ///< __index(t,k)
    {
        auto key = luaL_optstring(L, 2, "");
        auto prop_flag = xlf_prop::byval;
        ///< when key has prefix '&', return property's reference
        xlb_debug("[%s]\n", key);
        if (key[0] == '&') {
            prop_flag = xlf_prop::byref;
            ++key;
        }
        auto iter = member_map.find(key);
        auto nfound = 0;
        if (iter != member_map.end()) {
            auto& prop = iter->second;
            switch (iter->second.type) {
                case xlb_property::readonly:
                case xlb_property::readwrite:
                    prop.getter(L, prop_flag);
                    nfound = 1;
                    break;
                case xlb_property::function:
                    prop.funcer(L);
                    nfound = 1;
                    break;
            }
        }
        // xlb_debug("(%s,%d)\n", key, nfound);

        if (0 == nfound) {
            // XXX:search getter from super class
            nfound = xlu_search_getter(L, meta_name, super_names);
        }
        return nfound;
    }  // index_handler

    static int newindex_handler(lua_State* L)  ///< __newindex(t,k,v)
    {
        auto var_name = luaL_optlstring(L, 2, "", nullptr);
        auto iter = member_map.find(var_name);
        auto top = lua_gettop(L);
        int nfound = 0;
        if (iter != member_map.end()) {
            auto& prop = iter->second;
            switch (iter->second.type) {
                case xlb_property::writeonly:
                case xlb_property::readwrite:
                    prop.setter(L, xlf_prop::byval);

                    if (4 == top) {  // XXX:meant called by search_setter
                        lua_pushnumber(L, XLB_TRAP_FLAG);
                    }
                    nfound = 2;
                    break;
            }
        }

        if (0 == nfound) {
            nfound = xlu_search_setter(L, meta_name, super_names);
        }
        if (2 == nfound) {  // XXX:have found it
            if (4 == top) {
                // XXX:tell search_setter that setter have been found
                nfound = 1;  
            } else {
                nfound = 0;  // XXX:setter have been called, and 0 return
            }
        } else {
            if (4 == top) {
                lua_pushnil(L);  // XXX:tell search_setter nothing found
                nfound = 1;
            } else {
                nfound = 0;  // XXX:setter(L) called in search_setter
            }
        }
        return nfound;

    }  // newindex_handler

    static int typetostring_handler(lua_State* L) {
        auto p = lua_topointer(L, -1);
        lua_pushfstring(L, "(xlb type table: 0x%p)", p);
        return 1;
    }

    template <typename Super_a, typename... Super_b>
    rvr_t inherited() {
        super_names.push_back(&xlb_base_class<Super_a>::meta_name);
        xlt_each{(super_names.push_back(&xlb_base_class<Super_b>::meta_name),
                  XLB_STATEMENT_VALUE)...};
        return std::move(*this);
    }

    void type_function(const char fn[], lua_CFunction f) {
        type_table.insert(begin(type_table), {fn, f});
    }

    rvr_t constructor(lua_CFunction cf) {
        type_table.insert(begin(type_table), {"__call", cf});
        return std::move(*this);
    }

    template <typename... A>
    rvr_t constructor() {
        constexpr lua_CFunction cf = xlb_f2cf_pure<&xlb_ctor<X, A...>>;
        type_table.insert(begin(type_table), {"__call", cf});
        return std::move(*this);
    }

    rvr_t destructor() {
        meta_funcs.insert(begin(meta_funcs), {"__gc", xlb_wpdtor<X>});
        return std::move(*this);
    }

    //rvr_t method(const char* func_name, lua_CFunction f) {
    //    member_map[func_name] = xlb_property::create(f, xlb_makefuncptr(f));
    //    return std::move(*this);
    //}

    rvr_t method(const char* func_name, lua_CFunction cf) {
        member_map[func_name] = xlb_property::create(cf);
        return std::move(*this);
    }


    template <typename FT, class... PO>
    rvr_t method(const char* func_name, FT f, PO...) {
        member_map[func_name] =
            xlb_property::create(xlb_f2cf_static<FT, PO...>, f);
        return std::move(*this);
    }

    template <auto f, class... PO>
    rvr_t method(const char* func_name, PO...) {
        using FT = decltype(f);
        member_map[func_name] =
            xlb_property::create(xlb_f2cf_static<FT, PO...>, f);
        return std::move(*this);
    }

    template <class Prop_t, class... PO>
    rvr_t property(const char prop_name[], Prop_t prop, PO...) {
        using check_po_readonly = xpo_get_readonly<PO...>;
        member_map[prop_name] =
            xlb_property::create<Prop_t, PO...>(prop, check_po_readonly());
        return std::move(*this);
    }

    rvr_t def_const(const char* var_name, int value) {
        const_values.push_back({var_name, value});
        return std::move(*this);
    }

    static void registry(lua_State* L, int parent_table_index = 0) {
        meta_funcs.insert(begin(meta_funcs), {"__index", &index_handler});
        meta_funcs.insert(begin(meta_funcs), {"__newindex", &newindex_handler});
        type_table.insert(begin(type_table), {"__tostring", &typetostring_handler});

        xlu_newtypelib(L, type_name, type_table, const_values, 
                xlb_sizeof<X>(), parent_table_index);
        xlu_newobjmeta(L, meta_name, meta_funcs, method_funcs, super_names);
    }

};  // xlb_base_class

//-----------------------------------------------------------------------------
// xlb_class
//-----------------------------------------------------------------------------
template <typename T>
struct xlb_class : public xlb_base_class<T> {
    using rvr_t = xlb_class&&;
    using bc_t = xlb_base_class<T>;
    using ri_t = xlb_regitem;

    xlb_class(const char* class_name) {
        ri_t::name = class_name;
        bc_t::meta_name_buf = XLB_META_PREFIX;
        bc_t::meta_name_buf += class_name;
        bc_t::type_name_buf = class_name;
        bc_t::meta_name = bc_t::meta_name_buf.c_str();
        bc_t::type_name = bc_t::type_name_buf.c_str();
        xlb_debug("(%s)\n", ri_t::name.c_str());
        xlb_debug("(%s)\n", xlb_base_class<T>::meta_name);
    }

    virtual ~xlb_class() {
        xlb_debug("(%s),0x%p\n", ri_t::name.c_str(), this);
    }

    xlb_class(xlb_class&& o) = delete;

    virtual void registry(xli_scope* name_space) override {
        bc_t::registry(name_space->lua, name_space->luaIndex);
    }

    rvr_t def() {
        xlb_dbg();
        return std::move(*this);
    }
};  // xlb_class

int xlb_type(lua_State* L) {
    auto rc { 1 };
    if (auto wp = xlb_touserdata<xlb_basewrap>(L, 1)) {
        auto fmt = "(FIXME %p)";
        switch (wp->tQlf) {
            case xlf_qlf::ref:   fmt = "(0x%p : T&)"; break;
            case xlf_qlf::cref:  fmt = "(0x%p : const T&)"; break;
            case xlf_qlf::val:   fmt = "(0x%p : T)"; break;
            case xlf_qlf::cval:  fmt = "(0x%p : const T)"; break;
            case xlf_qlf::cp:    fmt = "(0x%p : T* const)"; break;
            case xlf_qlf::p2cv:  fmt = "(0x%p : const T*)"; break;
            case xlf_qlf::cp2cv: fmt = "(0x%p : const T* const)"; break;
            case xlf_qlf::vp:    fmt = "(0x%p : T*)"; break;
        }
        lua_pushfstring(L, fmt, wp->getpointer());
    } else {
        lua_pushstring(L, lua_typename(L, lua_type(L, -1)));
    }
    return rc;
}

//-----------------------------------------------------------------------------
//xlb helper
//-----------------------------------------------------------------------------
void xlb_loadstring(lua_State* L, const char* s) {
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

void xlb_loadfile(lua_State* L, const char* fn) {
    luaL_loadfile(L, fn);
    if (lua_pcall(L, 0, LUA_MULTRET, 0)) {
        //xlb_debug("%s\n", lua_tostring(L, -1));
        printf("%s\n", lua_tostring(L, -1));
        lua_pop(L, 1);
    }
}

#endif  //__XLB_H__
