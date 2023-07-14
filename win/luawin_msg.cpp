#include "luawin.h"

//------------------------------------------------------------------------------------------------
int load_msg(lua_State *L) {
#if defined(BIND_MSG)

  xlb_module(L, MODULE_NAME)({
    xlb_f("AdjustWindowRect", AdjustWindowRect), xlb_f("AdjustWindowRectEx", AdjustWindowRectEx),
        xlb_f("AllowSetForegroundWindow", AllowSetForegroundWindow),
        xlb_f("AnimateWindow", AnimateWindow), xlb_f("AnyPopup", AnyPopup),
        xlb_f("ArrangeIconicWindows", ArrangeIconicWindows),
        xlb_f("BeginDeferWindowPos", BeginDeferWindowPos),
        xlb_f("BringWindowToTop", BringWindowToTop),
        xlb_f("BroadcastSystemMessage", BroadcastSystemMessage),
        xlb_f("BroadcastSystemMessageEx", BroadcastSystemMessageExA),
        xlb_f("CalculatePopupWindowPosition", CalculatePopupWindowPosition),
        xlb_f("CallMsgFilter", CallMsgFilter), xlb_f("CallNextHookEx", CallNextHookEx),
        xlb_f("CallWindowProc", CallWindowProc), xlb_f("CascadeWindows", CascadeWindows),
        xlb_f("ChangeWindowMessageFilter", ChangeWindowMessageFilter),
        xlb_f("ChangeWindowMessageFilterEx", ChangeWindowMessageFilterEx),
        xlb_f("ChildWindowFromPoint", ChildWindowFromPoint),
        xlb_f("ChildWindowFromPointEx", ChildWindowFromPointEx), xlb_f("CloseWindow", CloseWindow),
        xlb_f("CreateMDIWindow", CreateMDIWindow),
        // xlb_f("CreateWindow", CreateWindow),
        xlb_f("CreateWindowEx", CreateWindowEx), xlb_f("DeferWindowPos", DeferWindowPos),
        xlb_f("DefFrameProc", DefFrameProc), xlb_f("DefMDIChildProc", DefMDIChildProc),
        xlb_f("DefWindowProc", DefWindowProc),
        xlb_f("DeregisterShellHookWindow", DeregisterShellHookWindow),
        xlb_f("DestroyWindow", DestroyWindow), xlb_f("DispatchMessage", DispatchMessage),
        xlb_f("DispatchMessage", DispatchMessage), xlb_f("EndDeferWindowPos", EndDeferWindowPos),
        ////xlb_f("EndTask", EndTask), // XXX:This function is not intended for general use.
        xlb_f("EnumChildWindows", EnumChildWindows), xlb_f("EnumProps", EnumProps),
        xlb_f("EnumPropsEx", EnumPropsEx), xlb_f("EnumThreadWindows", EnumThreadWindows),
        xlb_f("EnumWindows", EnumWindows),
        xlb_class<xlb_cbf<WNDENUMPROC>>("EnumWindowsProc").constructor<xlb_luafunc>(),
        xlb_f("FindWindow", FindWindow), xlb_f("FindWindowEx", FindWindowEx),
        xlb_f("GET_X_LPARAM", [](LPARAM lp) { return GET_X_LPARAM(lp); }),
        xlb_f("GET_Y_LPARAM", [](LPARAM lp) { return GET_Y_LPARAM(lp); }),
        xlb_f("GetAltTabInfo", GetAltTabInfo), xlb_f("GetAncestor", GetAncestor),
        xlb_f("GetClassInfo", GetClassInfo), xlb_f("GetClassInfoEx", GetClassInfoEx),
        xlb_f("GetClassLong", GetClassLong), xlb_f("GetClassLongPtr", GetClassLongPtr),
        xlb_f("GetClassName", GetClassName), xlb_f("GetClassName", GetClassName),
        xlb_f("GetClassWord", GetClassWord), xlb_f("GetClientRect", GetClientRect),
        xlb_f("GetDesktopWindow", GetDesktopWindow),
        xlb_f("GetForegroundWindow", GetForegroundWindow),
        xlb_f("GetGUIThreadInfo", GetGUIThreadInfo), xlb_f("GetInputState", GetInputState),
        xlb_f("GetLastActivePopup", GetLastActivePopup),
        xlb_f("GetLayeredWindowAttributes", GetLayeredWindowAttributes),
        xlb_f("GetMessage", GetMessage), xlb_f("GetMessageExtraInfo", GetMessageExtraInfo),
        xlb_f("GetMessagePos", GetMessagePos), xlb_f("GetMessageTime", GetMessageTime),
        xlb_f("GetNextWindow", [](HWND hwnd, UINT wCmd) { return GetNextWindow(hwnd, wCmd); }),
        xlb_f("GetParent", GetParent), xlb_f("GetProcessDefaultLayout", GetProcessDefaultLayout),
        xlb_f("GetProp", GetProp), xlb_f("GetQueueStatus", GetQueueStatus),
        xlb_f("GetShellWindow", GetShellWindow), xlb_f("GetSysColor", GetSysColor),
        xlb_f("GetSystemMetrics", GetSystemMetrics), xlb_f("GetTitleBarInfo", GetTitleBarInfo),
        xlb_f("GetTopWindow", GetTopWindow), xlb_f("GetWindow", GetWindow),
        xlb_const("GW_CHILD", GW_CHILD),
        xlb_const("GW_ENABLEDPOPUP", GW_ENABLEDPOPUP),
        xlb_const("GW_HWNDFIRST", GW_HWNDFIRST),
        xlb_const("GW_HWNDLAST", GW_HWNDLAST),
        xlb_const("GW_HWNDNEXT", GW_HWNDNEXT),
        xlb_const("GW_HWNDPREV", GW_HWNDPREV),
        xlb_const("GW_OWNER", GW_OWNER),
        xlb_f("GetWindowDisplayAffinity", GetWindowDisplayAffinity),
        xlb_f("GetWindowInfo", GetWindowInfo), xlb_f("GetWindowLongPtr", GetWindowLongPtr),
        xlb_f("GetWindowModuleFileName", GetWindowModuleFileName),
        xlb_f("GetWindowPlacement", GetWindowPlacement), xlb_f("GetWindowRect", GetWindowRect),
        xlb_f("GetWindowText", GetWindowText), xlb_f("GetWindowTextLength", GetWindowTextLength),
        xlb_f("GetWindowThreadProcessId", GetWindowThreadProcessId),
        xlb_class<xlb_cbf<HOOKPROC>>("HOOKPROC").constructor<xlb_luafunc>(),
        xlb_f("InSendMessage", InSendMessage), xlb_f("InSendMessageEx", InSendMessageEx),
        xlb_f("InternalGetWindowText", InternalGetWindowText), xlb_f("IsChild", IsChild),
        xlb_f("IsGUIThread", IsGUIThread), xlb_f("IsHungAppWindow", IsHungAppWindow),
        xlb_f("IsIconic", IsIconic), xlb_f("IsProcessDPIAware", IsProcessDPIAware),
        xlb_f("IsWindow", IsWindow), xlb_f("IsWindowUnicode", IsWindowUnicode),
        xlb_f("IsWindowVisible", IsWindowVisible), xlb_f("IsZoomed", IsZoomed),
        xlb_f("KillTimer", KillTimer), xlb_f("LockSetForegroundWindow", LockSetForegroundWindow),
        xlb_f("LogicalToPhysicalPoint", LogicalToPhysicalPoint),
        xlb_f("MAKELPARAM", [](DWORD l, DWORD h) { return MAKELPARAM(l, h); }),
        xlb_f("MAKELRESULT", [](DWORD l, DWORD h) { return MAKELRESULT(l, h); }),
        xlb_f("MAKEWPARAM", [](DWORD l, DWORD h) { return MAKEWPARAM(l, h); }),
        xlb_f("MoveWindow", MoveWindow), xlb_f("OpenIcon", OpenIcon),
        xlb_f("PeekMessage", PeekMessage), xlb_f("PhysicalToLogicalPoint", PhysicalToLogicalPoint),
        xlb_f("PostMessage", PostMessage), xlb_f("PostQuitMessage", PostQuitMessage),
        xlb_f("PostThreadMessage", PostThreadMessage),
        xlb_class<xlb_cbf<PROPENUMPROC>>("PROPENUMPROC").constructor<xlb_luafunc>(),
        xlb_class<xlb_cbf<PROPENUMPROCEX>>("PROPENUMPROCEX").constructor<xlb_luafunc>(),
        xlb_f("RealChildWindowFromPoint", RealChildWindowFromPoint),
        xlb_f("RegisterClass", RegisterClass), xlb_f("RegisterClassEx", RegisterClassEx),
        xlb_f("RegisterShellHookWindow", RegisterShellHookWindow),
        xlb_f("RegisterWindowMessage", RegisterWindowMessage), xlb_f("RemoveProp", RemoveProp),
        xlb_f("ReplyMessage", ReplyMessage),
        xlb_class<xlb_cbf<SENDASYNCPROC>>("SENDASYNCPROC").constructor<xlb_luafunc>(),
        xlb_f("SendMessage", SendMessage), xlb_f("SendMessage", SendMessage),
        xlb_f("SendMessageCallback", SendMessageCallback),
        xlb_f("SendMessageTimeout", SendMessageTimeout),
        xlb_f("SendNotifyMessage", SendNotifyMessage), xlb_f("SetClassLong", SetClassLong),
        xlb_f("SetClassLongPtr", SetClassLongPtr), xlb_f("SetClassWord", SetClassWord),

#if (WINVER >= 0x0602)
    // xlb_f("SetCoalescableTimer", SetCoalescableTimer), // Windows8, Windows Server 2012
#endif

        xlb_f("SetForegroundWindow", SetForegroundWindow),
        xlb_f("SetLayeredWindowAttributes", SetLayeredWindowAttributes),
        xlb_f("SetMessageExtraInfo", SetMessageExtraInfo), xlb_f("SetParent", SetParent),
        xlb_f("SetProcessDefaultLayout", SetProcessDefaultLayout),
        xlb_f("SetProcessDPIAware", SetProcessDPIAware), xlb_f("SetProp", SetProp),
        xlb_f("SetSysColors", SetSysColors), xlb_f("SetTimer", SetTimer),
        xlb_f("SetWindowDisplayAffinity", SetWindowDisplayAffinity),
        xlb_f("SetWindowLong", SetWindowLong), xlb_f("SetWindowLongPtr", SetWindowLongPtr),
        xlb_f("SetWindowPlacement", SetWindowPlacement), xlb_f("SetWindowPos", SetWindowPos),
        xlb_f("SetWindowsHookEx", SetWindowsHookEx), xlb_f("SetWindowText", SetWindowText),
        xlb_f("ShowOwnedPopups", ShowOwnedPopups), xlb_f("ShowWindow", ShowWindow),
        xlb_f("ShowWindowAsync", ShowWindowAsync), xlb_f("SoundSentry", SoundSentry),
        xlb_f("SwitchToThisWindow", SwitchToThisWindow),
        xlb_f("SystemParametersInfo", SystemParametersInfo), xlb_f("TileWindows", TileWindows),
        xlb_class<xlb_cbf<TIMERPROC>>("TIMERPROC").constructor<xlb_luafunc>(),
        xlb_f("TranslateMDISysAccel", TranslateMDISysAccel),
        xlb_f("TranslateMessage", TranslateMessage),
        xlb_f("UnhookWindowsHookEx", UnhookWindowsHookEx),
        xlb_f("UnregisterClass", UnregisterClass),
        xlb_f("UpdateLayeredWindow", UpdateLayeredWindow), xlb_f("WaitMessage", WaitMessage),
        xlb_f("WindowFromPhysicalPoint", WindowFromPhysicalPoint),
        xlb_f("WindowFromPoint", WindowFromPoint),
        xlb_class<xlb_cbf<WNDPROC>>("WNDPROC").constructor<xlb_luafunc>(), // WindowProc
        ////xlb_f("WinMain", WinMain),

        xlb_class<ALTTABINFO>("ALTTABINFO")
            .constructor<>()
            .destructor()
            .property("cbSize", &ALTTABINFO::cbSize)
            .property("cItems", &ALTTABINFO::cItems)
            .property("cColumns", &ALTTABINFO::cColumns)
            .property("cRows", &ALTTABINFO::cRows)
            .property("iColFocus", &ALTTABINFO::iColFocus)
            .property("iRowFocus", &ALTTABINFO::iRowFocus)
            .property("cxItem", &ALTTABINFO::cxItem)
            .property("cyItem", &ALTTABINFO::cyItem)
            .property("ptStart", &ALTTABINFO::ptStart),
        xlb_class<ANIMATIONINFO>("ANIMATIONINFO")
            .constructor<>()
            .destructor()
            .property("cbSize", &ANIMATIONINFO::cbSize)
            .property("iMinAnimate", &ANIMATIONINFO::iMinAnimate),
        xlb_class<AUDIODESCRIPTION>("AUDIODESCRIPTION")
            .constructor<>()
            .destructor()
            .property("cbSize", &AUDIODESCRIPTION::cbSize)
            .property("Enabled", &AUDIODESCRIPTION::Enabled)
            .property("Locale", &AUDIODESCRIPTION::Locale),
        xlb_class<BSMINFO>("BSMINFO")
            .constructor<>()
            .destructor()
            .property("cbSize", &BSMINFO::cbSize)
            .property("hdesk", &BSMINFO::hdesk)
            .property("hwnd", &BSMINFO::hwnd)
            .property("luid", &BSMINFO::luid),
        xlb_class<CBT_CREATEWND>("CBT_CREATEWNDA")
            .constructor<>()
            .destructor()
            .property("lpcs", &CBT_CREATEWND::lpcs)
            .property("hwndInsertAfter", &CBT_CREATEWND::hwndInsertAfter),
        xlb_class<CBTACTIVATESTRUCT>("CBTACTIVATESTRUCT")
            .constructor<>()
            .destructor()
            .property("fMouse", &CBTACTIVATESTRUCT::fMouse)
            .property("hWndActive", &CBTACTIVATESTRUCT::hWndActive),
        xlb_class<CHANGEFILTERSTRUCT>("CHANGEFILTERSTRUCT")
            .constructor<>()
            .destructor()
            .property("cbSize", &CHANGEFILTERSTRUCT::cbSize)
            .property("ExtStatus", &CHANGEFILTERSTRUCT::ExtStatus),
        xlb_class<CLIENTCREATESTRUCT>("CLIENTCREATESTRUCT")
            .constructor<>()
            .destructor()
            .property("hWindowMenu", &CLIENTCREATESTRUCT::hWindowMenu)
            .property("idFirstChild", &CLIENTCREATESTRUCT::idFirstChild),
        xlb_class<CREATESTRUCT>("CREATESTRUCT")
            .constructor<>()
            .destructor()
            .property("lpCreateParams", &CREATESTRUCT::lpCreateParams)
            .property("hInstance", &CREATESTRUCT::hInstance)
            .property("hMenu", &CREATESTRUCT::hMenu)
            .property("hwndParent", &CREATESTRUCT::hwndParent)
            .property("cy", &CREATESTRUCT::cy)
            .property("cx", &CREATESTRUCT::cx)
            .property("y", &CREATESTRUCT::y)
            .property("x", &CREATESTRUCT::x)
            .property("style", &CREATESTRUCT::style)
            .property("lpszName", &CREATESTRUCT::lpszName)
            .property("lpszClass", &CREATESTRUCT::lpszClass)
            .property("dwExStyle", &CREATESTRUCT::dwExStyle),
        xlb_class<CWPRETSTRUCT>("CWPRETSTRUCT")
            .constructor<>()
            .destructor()
            .property("lResult", &CWPRETSTRUCT::lResult)
            .property("lParam", &CWPRETSTRUCT::lParam)
            .property("wParam", &CWPRETSTRUCT::wParam)
            .property("message", &CWPRETSTRUCT::message)
            .property("hwnd", &CWPRETSTRUCT::hwnd),
        xlb_class<CWPSTRUCT>("CWPSTRUCT")
            .constructor<>()
            .destructor()
            .property("lParam", &CWPSTRUCT::lParam)
            .property("wParam", &CWPSTRUCT::wParam)
            .property("message", &CWPSTRUCT::message)
            .property("hwnd", &CWPSTRUCT::hwnd),
        xlb_class<DEBUGHOOKINFO>("DEBUGHOOKINFO")
            .constructor<>()
            .destructor()
            .property("idThread", &DEBUGHOOKINFO::idThread)
            .property("idThreadInstaller", &DEBUGHOOKINFO::idThreadInstaller)
            .property("lParam", &DEBUGHOOKINFO::lParam)
            .property("wParam", &DEBUGHOOKINFO::wParam)
            .property("code", &DEBUGHOOKINFO::code),
        xlb_class<EVENTMSG>("EVENTMSG")
            .constructor<>()
            .destructor()
            .property("message", &EVENTMSG::message)
            .property("paramL", &EVENTMSG::paramL)
            .property("paramH", &EVENTMSG::paramH)
            .property("time", &EVENTMSG::time)
            .property("hwnd", &EVENTMSG::hwnd),
        xlb_class<GUITHREADINFO>("GUITHREADINFO")
            .constructor<>()
            .destructor()
            .property("cbSize", &GUITHREADINFO::cbSize)
            .property("flags", &GUITHREADINFO::flags)
            .property("hwndActive", &GUITHREADINFO::hwndActive)
            .property("hwndFocus", &GUITHREADINFO::hwndFocus)
            .property("hwndCapture", &GUITHREADINFO::hwndCapture)
            .property("hwndMenuOwner", &GUITHREADINFO::hwndMenuOwner)
            .property("hwndMoveSize", &GUITHREADINFO::hwndMoveSize)
            .property("hwndCaret", &GUITHREADINFO::hwndCaret)
            .property("rcCaret", &GUITHREADINFO::rcCaret),
        xlb_class<KBDLLHOOKSTRUCT>("KBDLLHOOKSTRUCT")
            .constructor<>()
            .destructor()
            .property("vkCode", &KBDLLHOOKSTRUCT::vkCode)
            .property("scanCode", &KBDLLHOOKSTRUCT::scanCode)
            .property("flags", &KBDLLHOOKSTRUCT::flags)
            .property("time", &KBDLLHOOKSTRUCT::time)
            .property("dwExtraInfo", &KBDLLHOOKSTRUCT::dwExtraInfo),
        xlb_class<MDICREATESTRUCT>("MDICREATESTRUCT")
            .constructor<>()
            .destructor()
            .property("szClass", &MDICREATESTRUCT::szClass)
            .property("szTitle", &MDICREATESTRUCT::szTitle)
            .property("hOwner", &MDICREATESTRUCT::hOwner)
            .property("x", &MDICREATESTRUCT::x)
            .property("y", &MDICREATESTRUCT::y)
            .property("cx", &MDICREATESTRUCT::cx)
            .property("cy", &MDICREATESTRUCT::cy)
            .property("style", &MDICREATESTRUCT::style)
            .property("lParam", &MDICREATESTRUCT::lParam),
        xlb_class<MINIMIZEDMETRICS>("MINIMIZEDMETRICS")
            .constructor<>()
            .destructor()
            .property("cbSize", &MINIMIZEDMETRICS::cbSize)
            .property("iWidth", &MINIMIZEDMETRICS::iWidth)
            .property("iHorzGap", &MINIMIZEDMETRICS::iHorzGap)
            .property("iVertGap", &MINIMIZEDMETRICS::iVertGap)
            .property("iArrange", &MINIMIZEDMETRICS::iArrange),
        xlb_class<MINMAXINFO>("MINMAXINFO")
            .constructor<>()
            .destructor()
            .property("ptReserved", &MINMAXINFO::ptReserved)
            .property("ptMaxSize", &MINMAXINFO::ptMaxSize)
            .property("ptMaxPosition", &MINMAXINFO::ptMaxPosition)
            .property("ptMinTrackSize", &MINMAXINFO::ptMinTrackSize)
            .property("ptMaxTrackSize", &MINMAXINFO::ptMaxTrackSize),
        xlb_class<MOUSEHOOKSTRUCT>("MOUSEHOOKSTRUCT")
            .constructor<>()
            .destructor()
            .property("pt", &MOUSEHOOKSTRUCT::pt)
            .property("hwnd", &MOUSEHOOKSTRUCT::hwnd)
            .property("wHitTestCode", &MOUSEHOOKSTRUCT::wHitTestCode)
            .property("dwExtraInfo", &MOUSEHOOKSTRUCT::dwExtraInfo),
        xlb_class<MOUSEHOOKSTRUCTEX>("MOUSEHOOKSTRUCTEX")
            .constructor()
            .destructor()
            .inherited<MOUSEHOOKSTRUCT>()
            .property("mouseData", &MOUSEHOOKSTRUCTEX::mouseData),
        xlb_class<MSG>("MSG")
            .constructor<>()
            .destructor()
            .property("hwnd", &MSG::hwnd)
            .property("message", &MSG::message)
            .property("wParam", &MSG::wParam)
            .property("lParam", &MSG::lParam)
            .property("time", &MSG::time)
            .property("pt", &MSG::pt)
        //.property("lPrivate", &MSG::lPrivate)
        ,
        xlb_class<MSLLHOOKSTRUCT>("MSLLHOOKSTRUCT")
            .constructor<>()
            .destructor()
            .property("pt", &MSLLHOOKSTRUCT::pt)
            .property("mouseData", &MSLLHOOKSTRUCT::mouseData)
            .property("flags", &MSLLHOOKSTRUCT::flags)
            .property("time", &MSLLHOOKSTRUCT::time)
            .property("dwExtraInfo", &MSLLHOOKSTRUCT::dwExtraInfo),
        xlb_class<NCCALCSIZE_PARAMS>("NCCALCSIZE_PARAMS")
            .constructor<>()
            .destructor()
            .property("rgrc", &NCCALCSIZE_PARAMS::rgrc)
            .property("lppos", &NCCALCSIZE_PARAMS::lppos),
        xlb_class<NONCLIENTMETRICS>("NONCLIENTMETRICS")
            .constructor<>()
            .destructor()
            .property("cbSize", &NONCLIENTMETRICS::cbSize)
            .property("iBorderWidth", &NONCLIENTMETRICS::iBorderWidth)
            .property("iScrollWidth", &NONCLIENTMETRICS::iScrollWidth)
            .property("iScrollHeight", &NONCLIENTMETRICS::iScrollHeight)
            .property("iCaptionWidth", &NONCLIENTMETRICS::iCaptionWidth)
            .property("iCaptionHeight", &NONCLIENTMETRICS::iCaptionHeight)
            .property("lfCaptionFont", &NONCLIENTMETRICS::lfCaptionFont)
            .property("iSmCaptionWidth", &NONCLIENTMETRICS::iSmCaptionWidth)
            .property("iSmCaptionHeight", &NONCLIENTMETRICS::iSmCaptionHeight)
            .property("lfSmCaptionFont", &NONCLIENTMETRICS::lfSmCaptionFont)
            .property("iMenuWidth", &NONCLIENTMETRICS::iMenuWidth)
            .property("iMenuHeight", &NONCLIENTMETRICS::iMenuHeight)
            .property("lfMenuFont", &NONCLIENTMETRICS::lfMenuFont)
            .property("lfStatusFont", &NONCLIENTMETRICS::lfStatusFont)
            .property("lfMessageFont", &NONCLIENTMETRICS::lfMessageFont)
            .property("iPaddedBorderWidth", &NONCLIENTMETRICS::iPaddedBorderWidth),
        xlb_class<STYLESTRUCT>("STYLESTRUCT")
            .constructor<>()
            .destructor()
            .property("styleOld", &STYLESTRUCT::styleOld)
            .property("styleNew", &STYLESTRUCT::styleNew),
        xlb_class<TITLEBARINFO>("TITLEBARINFO")
            .constructor<>()
            .destructor()
            .property("cbSize", &TITLEBARINFO::cbSize)
            .property("rcTitleBar", &TITLEBARINFO::rcTitleBar)
            .property("rgstate", &TITLEBARINFO::rgstate),
        xlb_class<TITLEBARINFOEX>("TITLEBARINFOEX")
            .constructor<>()
            .destructor()
            .property("cbSize", &TITLEBARINFOEX::cbSize)
            .property("rcTitleBar", &TITLEBARINFOEX::rcTitleBar)
            .property("rgstate", &TITLEBARINFOEX::rgstate)
            .property("rgrect", &TITLEBARINFOEX::rgrect),
        xlb_class<UPDATELAYEREDWINDOWINFO>("UPDATELAYEREDWINDOWINFO")
            .constructor<>()
            .destructor()
            .property("cbSize", &UPDATELAYEREDWINDOWINFO::cbSize)
            .property("hdcDst", &UPDATELAYEREDWINDOWINFO::hdcDst)
            .property("pptDst", &UPDATELAYEREDWINDOWINFO::pptDst)
            .property("psize", &UPDATELAYEREDWINDOWINFO::psize)
            .property("hdcSrc", &UPDATELAYEREDWINDOWINFO::hdcSrc)
            .property("pptSrc", &UPDATELAYEREDWINDOWINFO::pptSrc)
            .property("crKey", &UPDATELAYEREDWINDOWINFO::crKey)
            .property("pblend", &UPDATELAYEREDWINDOWINFO::pblend)
            .property("dwFlags", &UPDATELAYEREDWINDOWINFO::dwFlags)
            .property("prcDirty", &UPDATELAYEREDWINDOWINFO::prcDirty),
        xlb_class<WINDOWINFO>("WINDOWINFO")
            .constructor<>()
            .destructor()
            .property("cbSize", &WINDOWINFO::cbSize)
            .property("rcWindow", &WINDOWINFO::rcWindow)
            .property("rcClient", &WINDOWINFO::rcClient)
            .property("dwStyle", &WINDOWINFO::dwStyle)
            .property("dwExStyle", &WINDOWINFO::dwExStyle)
            .property("dwWindowStatus", &WINDOWINFO::dwWindowStatus)
            .property("cxWindowBorders", &WINDOWINFO::cxWindowBorders)
            .property("cyWindowBorders", &WINDOWINFO::cyWindowBorders)
            .property("atomWindowType", &WINDOWINFO::atomWindowType)
            .property("wCreatorVersion", &WINDOWINFO::wCreatorVersion),
        xlb_class<WINDOWPLACEMENT>("WINDOWPLACEMENT")
            .constructor<>()
            .destructor()
            .property("length", &WINDOWPLACEMENT::length)
            .property("flags", &WINDOWPLACEMENT::flags)
            .property("showCmd", &WINDOWPLACEMENT::showCmd)
            .property("ptMinPosition", &WINDOWPLACEMENT::ptMinPosition)
            .property("ptMaxPosition", &WINDOWPLACEMENT::ptMaxPosition)
            .property("rcNormalPosition", &WINDOWPLACEMENT::rcNormalPosition)
        //.property("rcDevice", &WINDOWPLACEMENT::rcDevice)
        ,
        xlb_class<WINDOWPOS>("WINDOWPOS")
            .constructor<>()
            .destructor()
            .property("hwndInsertAfter", &WINDOWPOS::hwndInsertAfter)
            .property("hwnd", &WINDOWPOS::hwnd)
            .property("x", &WINDOWPOS::x)
            .property("y", &WINDOWPOS::y)
            .property("cx", &WINDOWPOS::cx)
            .property("cy", &WINDOWPOS::cy)
            .property("flags", &WINDOWPOS::flags),
        xlb_class<WNDCLASS>("WNDCLASS")
            .constructor<>()
            .destructor()
            .property("style", &WNDCLASS::style)
            .property("lpfnWndProc", &WNDCLASS::lpfnWndProc)
            .property("cbClsExtra", &WNDCLASS::cbClsExtra)
            .property("cbWndExtra", &WNDCLASS::cbWndExtra)
            .property("hInstance", &WNDCLASS::hInstance)
            .property("hIcon", &WNDCLASS::hIcon)
            .property("hCursor", &WNDCLASS::hCursor)
            .property("hbrBackground", &WNDCLASS::hbrBackground)
            .property("lpszMenuName", &WNDCLASS::lpszMenuName)
            .property("lpszClassName", &WNDCLASS::lpszClassName),
        xlb_class<WNDCLASSEX>("WNDCLASSEX")
            .constructor<>()
            .destructor()
            .property("cbSize", &WNDCLASSEX::cbSize)
            .property("style", &WNDCLASSEX::style)
            .property("lpfnWndProc", &WNDCLASSEX::lpfnWndProc)
            .property("cbClsExtra", &WNDCLASSEX::cbClsExtra)
            .property("cbWndExtra", &WNDCLASSEX::cbWndExtra)
            .property("hInstance", &WNDCLASSEX::hInstance)
            .property("hIcon", &WNDCLASSEX::hIcon)
            .property("hCursor", &WNDCLASSEX::hCursor)
            .property("hbrBackground", &WNDCLASSEX::hbrBackground)
            .property("lpszMenuName", &WNDCLASSEX::lpszMenuName)
            .property("lpszClassName", &WNDCLASSEX::lpszClassName)
            .property("hIconSm", &WNDCLASSEX::hIconSm)
  });
#endif // BIND_MSG
  return 0;
}
