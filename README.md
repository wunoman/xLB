<img src="https://www.lua.org/images/logo.gif" />

# xLB ( ver 0.0.2 )
xlb is another library for binding C++ to Lua. It depends on C++17, and it's just one header file.

## Features
+ function
+ callback function
+ class ( member data and function )
+ inherited function
+ overload function ( do not recommend )
+ constant and namespace
+ default value for function
+ dereference from pointer
+ get address of value

## Do not support yet
+ operator overload

## Usage
+ module and const integral
```c++
    xlb_module(L, MODULE_NAME) ({
            xlb_const("WINVER", WINVER)
    });
```
+ function
```c++
    xlb_module(L, MODULE_NAME) ({
            xlb_f("malloc", malloc),
            xlb_f("free", free)
    });
```
+ callback as class
```c++
    xlb_module(L, MODULE_NAME) ({
        xlb_class<xlb_cbf<WNDENUMPROC>>("EnumWindowsProc").constructor<xlb_luafunc>(),
    });
```
```lua
    function EnumWindows()
        luawin.load_wmsg()
        local len = 1024
        local buff = string.rep('\0', len)
        local EnumWindowsProc = luawin.EnumWindowsProc(function(hwnd, lParam) 
            local len = luawin.GetWindowText(hwnd, buff, len)
            print('---' .. string.sub(buff, 1, len) .. ',' .. lParam)
            return true
        end);
        luawin.EnumWindows(EnumWindowsProc, 999)
    end
```
  maybe Output is :
```
    ---MSCTFIME UI,999
    ---Default IME,999
```
+ inherited
```c++
    xlb_module(L, MODULE_NAME) ({
        xlb_class<classB>("classB")
            .inherited<classA>()
            .constructor<>()
            .destructor()
    });
```
+ tag struct and property
```c++
    xlb_module(L, MODULE_NAME) ({
        xlb_class<PRINTPAGERANGE>("PRINTPAGERANGE") .constructor<>() .destructor()
            .property("nFromPage", &PRINTPAGERANGE::nFromPage)
            .property("nToPage", &PRINTPAGERANGE::nToPage)
    });
```
+ create object with new in place ( malloc and free )
```lua
    require 'luawin'
    luawin.load_base()
    function BASE()
        luawin.load_dialog()
        print('---sizeof PRINTPAGERANGE=' .. luawin.PRINTPAGERANGE.typesize)
        local a = luawin.malloc(luawin.PRINTPAGERANGE.typesize)
        print('---a=' .. luawin.type(a))
        local b = luawin.PRINTPAGERANGE:newinplace(a)
        b.nFromPage = 1
        b.nToPage = 2
        print('---b.nFromPage=' .. b.nFromPage)
        print('---b.nToPage=' .. b.nToPage)
        print('---b=' .. luawin.type(b))
        b = nil
        collectgarbage()
        print('--')
        luawin.free(a)
    end
```
  maybe Output is:
```
    ---sizeof PRINTPAGERANGE=8
    ---a=(0x000001B028EA7720 : T*)
    ---b.nFromPage=1
    ---b.nToPage=2
    ---b=(0x000001B028EA7720 : T)
```
+ LoadLibrary and GetProcAddress
implement xlb_fmat_evthandler's getf and xlb_f(name, nullptr, Win32_libf::getf(...))
```
// for LoadLibrary GetProcAddress to get function pointer
 struct Win32_libf {
  struct Libf : public xlb_fmat_evthandler {
    TCHAR *libn;
    const char *funcn;
    virtual ~Libf() {}
  };

  static xlb_fmat_evthandler *CreateFmatHandler(TCHAR* ln, const char* fn) {
    auto h = new Libf();
    h->libn = ln;
    h->funcn = fn;
    // h->on_registry = Win32_libf::register;
    h->on_getf = Win32_libf::getf;
    return h;
  }

  // static int registry(lua_State *L, xlb_fmat_evthandler *) { return 0; }
  static void* getf(lua_State *L, xlb_fmat_evthandler *evth) { 
    assert(evth);
    auto libf = dynamic_cast<Libf*>(evth);
    assert(libf);
    assert(libf->libn);
    assert(libf->funcn);
    void* f = nullptr;
    auto hlib = ::LoadLibrary(libf->libn);
    assert(hlib!=NULL); //"fail to LoadLibrary"
    f = ::GetProcAddress(hlib, libf->funcn);
    assert(f!=NULL); // "fail to GetProcAddress"

    return f;
  }
}; // Win32_libf

```

                
## Sample
+ bind Windows API to Lua ( BASE, MESSAGE, GUI, Dialog and SNMP, ... )

## History
- 20230714 add some function(a2w,a2u,...) to support convert char* to wchar_t* utf_8
- 20230714 allow delay get function pointer for LoadLibray and GetProcAddress
- 20230714 accept nil as nullptr and push nullptr as nil
- 20230521 bind C style library with xlb_class, method, constructor, destructor
- 20230521 bind boolean with AT xlb_lboolean
- 20230521 custom data type xlb_lstr AT for string with length just like lua's string type

## License
+ Licensed under the [MIT License](https://www.lua.org/license.html).
