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
            
## Sample
+ bind Windows API to Lua ( SNMP, MESSAGE, GUI and Dialog )

## License
+ Licensed under the [MIT License](https://www.lua.org/license.html).

