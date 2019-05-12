<img src="https://www.lua.org/images/logo.gif" />

# xLB ( ver 0.0.1 )
xlb is another library for binding C++ to Lua. It depends on C++17, It just one header file and do not need nothing else.

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
```    
    xlb_module(L, MODULE_NAME) ({
            xlb_const("WINVER", WINVER)
    });
```
+ function
```
    xlb_module(L, MODULE_NAME) ({
            xlb_f("malloc", malloc),
            xlb_f("free", free)
    });
```
+ callback as class
```
    xlb_module(L, MODULE_NAME) ({
        xlb_class<xlb_cbf<DLGPROC>>("DLGPROC").constructor<xlb_luafunc>()
    });
```
+ inherited
```
    xlb_module(L, MODULE_NAME) ({
        xlb_class<classB>("classB")
            .inherited<classA>()
            .constructor<>()
            .destructor()
    });
```
+ tag struct and property
```
    xlb_module(L, MODULE_NAME) ({
        xlb_class<PRINTPAGERANGE>("PRINTPAGERANGE") .constructor<>() .destructor()
            .property("nFromPage", &PRINTPAGERANGE::nFromPage)
            .property("nToPage", &PRINTPAGERANGE::nToPage)
    });
```
+ create object with new in place ( malloc and free )
```
    require 'luawin'
    luawin.load_base();
    function BASE()
        luawin.load_dialog();
        print('---sizeof PRINTPAGERANGE=' .. luawin.PRINTPAGERANGE.typesize); 
        local a = luawin.malloc(luawin.PRINTPAGERANGE.typesize);
        print('---a=' .. luawin.type(a));
        local b = luawin.PRINTPAGERANGE:newin(a);
        b.nFromPage = 1;
        b.nToPage = 2;
        print('---b.nFromPage=' .. b.nFromPage);
        print('---b.nToPage=' .. b.nToPage);
        print('---b=' .. luawin.type(b));
        b = nil;
        collectgarbage();
        print('--');
        luawin.free(a);
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
                
## Sample
+ bind Windows API to Lua ( BASE, MESSAGE, GUI, Dialog and SNMP )

## License
+ Licensed under the [MIT License](https://www.lua.org/license.html).

