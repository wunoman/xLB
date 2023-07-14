#include "win.h"


int main(int argc, char** args) 
{
    auto L = luaL_newstate();
    luaL_openlibs(L);


    //printf("%d\n", std::is_same_v<BOOL, bool>);
    //using CallWndProc_t = xlb_cbf<HOOKPROC>;

    //xlb_module(L, "w") [{
    //    xlb_class<xlb_cbf<HOOKPROC>>("CallWndProc").constructor<xlb_luafunc>(),
    //    xlb_class<xlb_cbf<WNDENUMPROC>>("EnumWindowsProc").constructor<xlb_luafunc>(),
    //    xlb_f("GetWindowText", GetWindowText),
    //    xlb_f("type", xlb_type)
    //}];
        
    bind_win_api_function();

    if (argc>=2) {
        xlb_loadfile(L, args[1]);
    }
    lua_close(L);

    return 0;
}
