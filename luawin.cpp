//-----------------------------------------------------------------------------
#include "luawin.h"


//LRESULT WINAPI ScreenSaverProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
//{
//    return DefScreenSaverProc(hWnd, message, wParam, lParam);
//}
//
//BOOL WINAPI ScreenSaverConfigureDialog(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
//{
//    return false;
//}
//
//BOOL RegisterDialogClasses(HANDLE hInst) {
//    return false;
//}

//-----------------------------------------------------------------------------
const char* lua_win_api_version() { return "Windows API (Lua53)"; }

//-----------------------------------------------------------------------------
// XXX: /DEF:win.def
// module main
int luaopen_luawin(lua_State* L) 
{
    bind_win_api_desktop_tech(L);
    return 0;
}

//-----------------------------------------------------------------------------
int bind_win_api_desktop_tech(lua_State* L)
{
    xlb_module(L, MODULE_NAME) ({
        xlb_f("load_base", load_base),
        xlb_f("load_snmp", load_snmp),
        xlb_f("load_gui", load_gui),
        xlb_f("load_wmsg", load_wmsg),
        xlb_f("load_dialog", load_dialog),
        xlb_const("WIN_API_DESKTOP_TECH", BIND_WIN_CHECKED)
    });
    return 0;
} // bind_win_api_desktop_tech

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
int load_dialog(lua_State* L)
{
#if defined(CHECK_BIND_WMSG)

    xlb_module(L, MODULE_NAME) ({
        xlb_f("CommDlgExtendedError", CommDlgExtendedError),

        xlb_f("CreateDialog", [](
                    HINSTANCE hInstance,
                    LPCSTR    lpTemplateName,
                    HWND      hWndParent,
                    DLGPROC   lpDialogFunc) { return 
                CreateDialog(hInstance, lpTemplateName, hWndParent, lpDialogFunc); }),

        xlb_f("CreateDialogIndirect", [](
                    HINSTANCE       hInstance,
                    LPCDLGTEMPLATEA lpTemplate,
                    HWND            hWndParent,
                    DLGPROC         lpDialogFunc) { return 
                CreateDialogIndirect(hInstance, lpTemplate, hWndParent, lpDialogFunc); }),

        xlb_f("CreateDialogIndirectParam", CreateDialogIndirectParam),
        xlb_f("CreateDialogParam", CreateDialogParam),

        xlb_f("DialogBox", [](
                    HINSTANCE hInstance,
                    LPCSTR    lpTemplateName,
                    HWND      hWndParent,
                    DLGPROC   lpDialogFunc) { return 
                DialogBox(hInstance, lpTemplateName, hWndParent, lpDialogFunc); }),

        xlb_f("DialogBoxIndirect", [](
                    HINSTANCE       hInstance,
                    LPCDLGTEMPLATEA hDialogTemplate,
                    HWND            hWndParent,
                    DLGPROC         lpDialogFunc) { return 
                DialogBoxIndirect(hInstance, hDialogTemplate, hWndParent, lpDialogFunc); }),

        xlb_f("DialogBoxIndirectParam", DialogBoxIndirectParam),
        xlb_f("DialogBoxParam", DialogBoxParam),
        xlb_class<xlb_cbf<DLGPROC>>("DLGPROC").constructor<xlb_luafunc>(),
        xlb_f("EndDialog", EndDialog),
        xlb_f("FindText", FindText),

        //// XXX:Interface: IPrintDialogCallback,IPrintDialogServices
        ////xlb_f("GetCurrentDevMode", GetCurrentDevMode),
        ////xlb_f("GetCurrentPortName", GetCurrentPortName),
        ////xlb_f("GetCurrentPrinterName", GetCurrentPrinterName),
        ////xlb_f("HandleMessage", HandleMessage),
        ////xlb_f("InitDone", InitDone),
        ////xlb_f("SelectionChange", SelectionChange),
        ////PrintDlgEx,PRINTDLGEX

        xlb_f("GetDialogBaseUnits", GetDialogBaseUnits),
        xlb_f("GetDlgCtrlID", GetDlgCtrlID),
        xlb_f("GetDlgItem", GetDlgItem),
        xlb_f("GetDlgItemInt", GetDlgItemInt),
        xlb_f("GetDlgItemText", GetDlgItemText),
        xlb_f("GetFileTitle", GetFileTitle),
        xlb_f("GetNextDlgGroupItem", GetNextDlgGroupItem),
        xlb_f("GetNextDlgTabItem", GetNextDlgTabItem),
        xlb_f("GetOpenFileName", GetOpenFileName),
        xlb_f("GetSaveFileName", GetSaveFileName),
        xlb_f("IsDialogMessage", IsDialogMessage),
        xlb_class<xlb_cbf<LPCCHOOKPROC>>("LPCCHOOKPROC").constructor<xlb_luafunc>(),
        xlb_class<xlb_cbf<LPCFHOOKPROC>>("LPCFHOOKPROC").constructor<xlb_luafunc>(),
        xlb_class<xlb_cbf<LPFRHOOKPROC>>("LPFRHOOKPROC").constructor<xlb_luafunc>(),
        xlb_class<xlb_cbf<LPOFNHOOKPROC>>("LPOFNHOOKPROC").constructor<xlb_luafunc>(),
        xlb_class<xlb_cbf<LPPAGEPAINTHOOK>>("LPPAGEPAINTHOOK").constructor<xlb_luafunc>(),
        xlb_class<xlb_cbf<LPPAGESETUPHOOK>>("LPPAGESETUPHOOK").constructor<xlb_luafunc>(),
        xlb_class<xlb_cbf<LPPRINTHOOKPROC>>("LPPRINTHOOKPROC").constructor<xlb_luafunc>(),
        xlb_class<xlb_cbf<LPSETUPHOOKPROC>>("LPSETUPHOOKPROC").constructor<xlb_luafunc>(),
        xlb_f("MapDialogRect", MapDialogRect),
        xlb_f("MessageBox", MessageBox),
        xlb_f("MessageBox", MessageBox),
        xlb_f("MessageBoxEx", MessageBoxEx),
        xlb_f("MessageBoxIndirect", MessageBoxIndirect),
        xlb_f("ReplaceText", ReplaceText),
        xlb_f("SendDlgItemMessage", SendDlgItemMessage),
        xlb_f("SetDlgItemInt", SetDlgItemInt),
        xlb_f("SetDlgItemText", SetDlgItemText),

        xlb_class<CHOOSEFONT>("CHOOSEFONT") .constructor<>() .destructor()
            .property("lStructSize", &CHOOSEFONT::lStructSize)
            .property("hwndOwner", &CHOOSEFONT::hwndOwner)
            .property("hDC", &CHOOSEFONT::hDC)
            .property("lpLogFont", &CHOOSEFONT::lpLogFont)
            .property("iPointSize", &CHOOSEFONT::iPointSize)
            .property("Flags", &CHOOSEFONT::Flags)
            .property("rgbColors", &CHOOSEFONT::rgbColors)
            .property("lCustData", &CHOOSEFONT::lCustData)
            .property("lpfnHook", &CHOOSEFONT::lpfnHook)
            .property("lpTemplateName", &CHOOSEFONT::lpTemplateName)
            .property("hInstance", &CHOOSEFONT::hInstance)
            .property("lpszStyle", &CHOOSEFONT::lpszStyle)
            .property("nFontType", &CHOOSEFONT::nFontType)
            .property("___MISSING_ALIGNMENT__", &CHOOSEFONT::___MISSING_ALIGNMENT__)
            .property("nSizeMin", &CHOOSEFONT::nSizeMin)
            .property("nSizeMax", &CHOOSEFONT::nSizeMax)
            ,
        xlb_class<DEVNAMES>("DEVNAMES") .constructor<>() .destructor()
            .property("wDriverOffset", &DEVNAMES::wDriverOffset)
            .property("wDeviceOffset", &DEVNAMES::wDeviceOffset)
            .property("wOutputOffset", &DEVNAMES::wOutputOffset)
            .property("wDefault", &DEVNAMES::wDefault)
            ,
        xlb_class<DLGITEMTEMPLATE>("DLGITEMTEMPLATE") .constructor<>() .destructor()
            .property("style", &DLGITEMTEMPLATE::style)
            .property("dwExtendedStyle", &DLGITEMTEMPLATE::dwExtendedStyle)
            .property("x", &DLGITEMTEMPLATE::x)
            .property("y", &DLGITEMTEMPLATE::y)
            .property("cx", &DLGITEMTEMPLATE::cx)
            .property("cy", &DLGITEMTEMPLATE::cy)
            .property("id", &DLGITEMTEMPLATE::id)
            ,
        xlb_class<DLGTEMPLATE>("DLGTEMPLATE") .constructor<>() .destructor()
            .property("style", &DLGTEMPLATE::style)
            .property("dwExtendedStyle", &DLGTEMPLATE::dwExtendedStyle)
            .property("cdit", &DLGTEMPLATE::cdit)
            .property("x", &DLGTEMPLATE::x)
            .property("y", &DLGTEMPLATE::y)
            .property("cx", &DLGTEMPLATE::cx)
            .property("cy", &DLGTEMPLATE::cy)
            ,
        xlb_class<FINDREPLACE>("FINDREPLACE") .constructor<>() .destructor()
            .property("lStructSize", &FINDREPLACE::lStructSize)
            .property("hwndOwner", &FINDREPLACE::hwndOwner)
            .property("hInstance", &FINDREPLACE::hInstance)
            .property("Flags", &FINDREPLACE::Flags)
            .property("lpstrFindWhat", &FINDREPLACE::lpstrFindWhat)
            .property("lpstrReplaceWith", &FINDREPLACE::lpstrReplaceWith)
            .property("wFindWhatLen", &FINDREPLACE::wFindWhatLen)
            .property("wReplaceWithLen", &FINDREPLACE::wReplaceWithLen)
            .property("lCustData", &FINDREPLACE::lCustData)
            .property("lpfnHook", &FINDREPLACE::lpfnHook)
            .property("lpTemplateName", &FINDREPLACE::lpTemplateName)
            ,
        xlb_class<MSGBOXPARAMS>("MSGBOXPARAMS") .constructor<>() .destructor()
            .property("cbSize", &MSGBOXPARAMS::cbSize)
            .property("hwndOwner", &MSGBOXPARAMS::hwndOwner)
            .property("hInstance", &MSGBOXPARAMS::hInstance)
            .property("lpszText", &MSGBOXPARAMS::lpszText)
            .property("lpszCaption", &MSGBOXPARAMS::lpszCaption)
            .property("dwStyle", &MSGBOXPARAMS::dwStyle)
            .property("lpszIcon", &MSGBOXPARAMS::lpszIcon)
            .property("dwContextHelpId", &MSGBOXPARAMS::dwContextHelpId)
            .property("lpfnMsgBoxCallback", &MSGBOXPARAMS::lpfnMsgBoxCallback)
            .property("dwLanguageId", &MSGBOXPARAMS::dwLanguageId)
            ,
        xlb_class<OFNOTIFY>("OFNOTIFY") .constructor<>() .destructor()
            .property("hdr", &OFNOTIFY::hdr)
            .property("lpOFN", &OFNOTIFY::lpOFN)
            .property("pszFile", &OFNOTIFY::pszFile)
            ,
        xlb_class<OFNOTIFYEX>("OFNOTIFYEX") .constructor<>() .destructor()
            .property("hdr", &OFNOTIFYEX::hdr)
            .property("lpOFN", &OFNOTIFYEX::lpOFN)
            .property("psf", &OFNOTIFYEX::psf)
            .property("pidl", &OFNOTIFYEX::pidl)
            ,
        xlb_class<OPENFILENAME>("OPENFILENAME") .constructor<>() .destructor()
            .property("lStructSize", &OPENFILENAME::lStructSize)
            .property("hwndOwner", &OPENFILENAME::hwndOwner)
            .property("hInstance", &OPENFILENAME::hInstance)
            .property("lpstrFilter", &OPENFILENAME::lpstrFilter)
            .property("lpstrCustomFilter", &OPENFILENAME::lpstrCustomFilter)
            .property("nMaxCustFilter", &OPENFILENAME::nMaxCustFilter)
            .property("nFilterIndex", &OPENFILENAME::nFilterIndex)
            .property("lpstrFile", &OPENFILENAME::lpstrFile)
            .property("nMaxFile", &OPENFILENAME::nMaxFile)
            .property("lpstrFileTitle", &OPENFILENAME::lpstrFileTitle)
            .property("nMaxFileTitle", &OPENFILENAME::nMaxFileTitle)
            .property("lpstrInitialDir", &OPENFILENAME::lpstrInitialDir)
            .property("lpstrTitle", &OPENFILENAME::lpstrTitle)
            .property("Flags", &OPENFILENAME::Flags)
            .property("nFileOffset", &OPENFILENAME::nFileOffset)
            .property("nFileExtension", &OPENFILENAME::nFileExtension)
            .property("lpstrDefExt", &OPENFILENAME::lpstrDefExt)
            .property("lCustData", &OPENFILENAME::lCustData)
            .property("lpfnHook", &OPENFILENAME::lpfnHook)
            .property("lpTemplateName", &OPENFILENAME::lpTemplateName)
            ////.property("lpEditInfo", &OPENFILENAME::lpEditInfo)
            ////.property("lpstrPrompt", &OPENFILENAME::lpstrPrompt)
            .property("pvReserved", &OPENFILENAME::pvReserved)
            .property("dwReserved", &OPENFILENAME::dwReserved)
            .property("FlagsEx", &OPENFILENAME::FlagsEx)
            ,
        xlb_class<PAGESETUPDLG>("PAGESETUPDLG") .constructor<>() .destructor()
            .property("lStructSize", &PAGESETUPDLG::lStructSize)
            .property("hwndOwner", &PAGESETUPDLG::hwndOwner)
            .property("hDevMode", &PAGESETUPDLG::hDevMode)
            .property("hDevNames", &PAGESETUPDLG::hDevNames)
            .property("Flags", &PAGESETUPDLG::Flags)
            .property("ptPaperSize", &PAGESETUPDLG::ptPaperSize)
            .property("rtMinMargin", &PAGESETUPDLG::rtMinMargin)
            .property("rtMargin", &PAGESETUPDLG::rtMargin)
            .property("hInstance", &PAGESETUPDLG::hInstance)
            .property("lCustData", &PAGESETUPDLG::lCustData)
            .property("lpfnPageSetupHook", &PAGESETUPDLG::lpfnPageSetupHook)
            .property("lpfnPagePaintHook", &PAGESETUPDLG::lpfnPagePaintHook)
            .property("lpPageSetupTemplateName", &PAGESETUPDLG::lpPageSetupTemplateName)
            .property("hPageSetupTemplate", &PAGESETUPDLG::hPageSetupTemplate)
            ,
        xlb_class<PRINTDLG>("PRINTDLG") .constructor<>() .destructor()
            .property("lStructSize", &PRINTDLG::lStructSize)
            .property("hwndOwner", &PRINTDLG::hwndOwner)
            .property("hDevMode", &PRINTDLG::hDevMode)
            .property("hDevNames", &PRINTDLG::hDevNames)
            .property("hDC", &PRINTDLG::hDC)
            .property("Flags", &PRINTDLG::Flags)
            .property("nFromPage", &PRINTDLG::nFromPage)
            .property("nToPage", &PRINTDLG::nToPage)
            .property("nMinPage", &PRINTDLG::nMinPage)
            .property("nMaxPage", &PRINTDLG::nMaxPage)
            .property("nCopies", &PRINTDLG::nCopies)
            .property("hInstance", &PRINTDLG::hInstance)
            .property("lCustData", &PRINTDLG::lCustData)
            .property("lpfnPrintHook", &PRINTDLG::lpfnPrintHook)
            .property("lpfnSetupHook", &PRINTDLG::lpfnSetupHook)
            .property("lpPrintTemplateName", &PRINTDLG::lpPrintTemplateName)
            .property("lpSetupTemplateName", &PRINTDLG::lpSetupTemplateName)
            .property("hPrintTemplate", &PRINTDLG::hPrintTemplate)
            .property("hSetupTemplate", &PRINTDLG::hSetupTemplate)
            ,
        xlb_class<PRINTDLGEX>("PRINTDLGEX") .constructor<>() .destructor()
            .property("lStructSize", &PRINTDLGEX::lStructSize)
            .property("hwndOwner", &PRINTDLGEX::hwndOwner)
            .property("hDevMode", &PRINTDLGEX::hDevMode)
            .property("hDevNames", &PRINTDLGEX::hDevNames)
            .property("hDC", &PRINTDLGEX::hDC)
            .property("Flags", &PRINTDLGEX::Flags)
            .property("Flags2", &PRINTDLGEX::Flags2)
            .property("ExclusionFlags", &PRINTDLGEX::ExclusionFlags)
            .property("nPageRanges", &PRINTDLGEX::nPageRanges)
            .property("nMaxPageRanges", &PRINTDLGEX::nMaxPageRanges)
            .property("lpPageRanges", &PRINTDLGEX::lpPageRanges)
            .property("nMinPage", &PRINTDLGEX::nMinPage)
            .property("nMaxPage", &PRINTDLGEX::nMaxPage)
            .property("nCopies", &PRINTDLGEX::nCopies)
            .property("hInstance", &PRINTDLGEX::hInstance)
            .property("lpPrintTemplateName", &PRINTDLGEX::lpPrintTemplateName)
            .property("lpCallback", &PRINTDLGEX::lpCallback)
            .property("nPropertyPages", &PRINTDLGEX::nPropertyPages)
            //// XXX: atldlgs.h: we use void* here instead of HPROPSHEETPAGE 
            //// becuase HPROPSHEETPAGE is a _PSP*, but _PSP is not defined properly
            .property("lphPropertyPages", reinterpret_cast<void** PRINTDLGEX::*>(&PRINTDLGEX::lphPropertyPages))
            .property("nStartPage", &PRINTDLGEX::nStartPage)
            .property("dwResultAction", &PRINTDLGEX::dwResultAction)
            ,
        xlb_class<PRINTPAGERANGE>("PRINTPAGERANGE") .constructor<>() .destructor()
            .property("nFromPage", &PRINTPAGERANGE::nFromPage)
            .property("nToPage", &PRINTPAGERANGE::nToPage)
            ,
        xlb_const("CHECK_BIND_DLG", BIND_WIN_CHECKED)
    });
#endif // CHECK_BIND_DLG
    return 0;
}

//-----------------------------------------------------------------------------
int load_wmsg(lua_State* L)
{
#if defined(CHECK_BIND_WMSG)

    xlb_module(L, MODULE_NAME) ({
        xlb_f("AdjustWindowRect", AdjustWindowRect),
        xlb_f("AdjustWindowRectEx", AdjustWindowRectEx),
        xlb_f("AllowSetForegroundWindow", AllowSetForegroundWindow),
        xlb_f("AnimateWindow", AnimateWindow),
        xlb_f("AnyPopup", AnyPopup),
        xlb_f("ArrangeIconicWindows", ArrangeIconicWindows),
        xlb_f("BeginDeferWindowPos", BeginDeferWindowPos),
        xlb_f("BringWindowToTop", BringWindowToTop),
        xlb_f("BroadcastSystemMessage", BroadcastSystemMessage),
        xlb_f("BroadcastSystemMessageEx", BroadcastSystemMessageExA),
        xlb_f("CalculatePopupWindowPosition", CalculatePopupWindowPosition),
        xlb_f("CallMsgFilter", CallMsgFilter),
        xlb_f("CallNextHookEx", CallNextHookEx),
        xlb_f("CallWindowProc", CallWindowProc),
        xlb_f("CascadeWindows", CascadeWindows),
        xlb_f("ChangeWindowMessageFilter", ChangeWindowMessageFilter),
        xlb_f("ChangeWindowMessageFilterEx", ChangeWindowMessageFilterEx),
        xlb_f("ChildWindowFromPoint", ChildWindowFromPoint),
        xlb_f("ChildWindowFromPointEx", ChildWindowFromPointEx),
        xlb_f("CloseWindow", CloseWindow),
        xlb_f("CreateMDIWindow", CreateMDIWindow),
        //xlb_f("CreateWindow", CreateWindow),
        xlb_f("CreateWindowEx", CreateWindowEx),
        xlb_f("DeferWindowPos", DeferWindowPos),
        xlb_f("DefFrameProc", DefFrameProc),
        xlb_f("DefMDIChildProc", DefMDIChildProc),
        xlb_f("DefWindowProc", DefWindowProc),
        xlb_f("DeregisterShellHookWindow", DeregisterShellHookWindow),
        xlb_f("DestroyWindow", DestroyWindow),
        xlb_f("DispatchMessage", DispatchMessage),
        xlb_f("DispatchMessage", DispatchMessage),
        xlb_f("EndDeferWindowPos", EndDeferWindowPos),
        ////xlb_f("EndTask", EndTask), // XXX:This function is not intended for general use.
        xlb_f("EnumChildWindows", EnumChildWindows),
        xlb_f("EnumProps", EnumProps),
        xlb_f("EnumPropsEx", EnumPropsEx),
        xlb_f("EnumThreadWindows", EnumThreadWindows),
        xlb_f("EnumWindows", EnumWindows),
        xlb_class<xlb_cbf<WNDENUMPROC>>("EnumWindowsProc").constructor<xlb_luafunc>(),
        xlb_f("FindWindow", FindWindow),
        xlb_f("FindWindowEx", FindWindowEx),
        xlb_f("GET_X_LPARAM", [](LPARAM lp) { return GET_X_LPARAM(lp); }),
        xlb_f("GET_Y_LPARAM", [](LPARAM lp) { return GET_Y_LPARAM(lp); }),
        xlb_f("GetAltTabInfo", GetAltTabInfo),
        xlb_f("GetAncestor", GetAncestor),
        xlb_f("GetClassInfo", GetClassInfo),
        xlb_f("GetClassInfoEx", GetClassInfoEx),
        xlb_f("GetClassLong", GetClassLong),
        xlb_f("GetClassLongPtr", GetClassLongPtr),
        xlb_f("GetClassName", GetClassName),
        xlb_f("GetClassName", GetClassName),
        xlb_f("GetClassWord", GetClassWord),
        xlb_f("GetClientRect", GetClientRect),
        xlb_f("GetDesktopWindow", GetDesktopWindow),
        xlb_f("GetForegroundWindow", GetForegroundWindow),
        xlb_f("GetGUIThreadInfo", GetGUIThreadInfo),
        xlb_f("GetInputState", GetInputState),
        xlb_f("GetLastActivePopup", GetLastActivePopup),
        xlb_f("GetLayeredWindowAttributes", GetLayeredWindowAttributes),
        xlb_f("GetMessage", GetMessage),
        xlb_f("GetMessageExtraInfo", GetMessageExtraInfo),
        xlb_f("GetMessagePos", GetMessagePos),
        xlb_f("GetMessageTime", GetMessageTime),
        xlb_f("GetNextWindow", [](HWND hwnd, UINT wCmd) { return GetNextWindow(hwnd, wCmd); }),
        xlb_f("GetParent", GetParent),
        xlb_f("GetProcessDefaultLayout", GetProcessDefaultLayout),
        xlb_f("GetProp", GetProp),
        xlb_f("GetQueueStatus", GetQueueStatus),
        xlb_f("GetShellWindow", GetShellWindow),
        xlb_f("GetSysColor", GetSysColor),
        xlb_f("GetSystemMetrics", GetSystemMetrics),
        xlb_f("GetTitleBarInfo", GetTitleBarInfo),
        xlb_f("GetTopWindow", GetTopWindow),
        xlb_f("GetWindow", GetWindow),
        xlb_f("GetWindowDisplayAffinity", GetWindowDisplayAffinity),
        xlb_f("GetWindowInfo", GetWindowInfo),
        xlb_f("GetWindowLongPtr", GetWindowLongPtr),
        xlb_f("GetWindowModuleFileName", GetWindowModuleFileName),
        xlb_f("GetWindowPlacement", GetWindowPlacement),
        xlb_f("GetWindowRect", GetWindowRect),
        xlb_f("GetWindowText", GetWindowText),
        xlb_f("GetWindowTextLength", GetWindowTextLength),
        xlb_f("GetWindowThreadProcessId", GetWindowThreadProcessId),
        xlb_class<xlb_cbf<HOOKPROC>>("HOOKPROC").constructor<xlb_luafunc>(),
        xlb_f("InSendMessage", InSendMessage),
        xlb_f("InSendMessageEx", InSendMessageEx),
        xlb_f("InternalGetWindowText", InternalGetWindowText),
        xlb_f("IsChild", IsChild),
        xlb_f("IsGUIThread", IsGUIThread),
        xlb_f("IsHungAppWindow", IsHungAppWindow),
        xlb_f("IsIconic", IsIconic),
        xlb_f("IsProcessDPIAware", IsProcessDPIAware),
        xlb_f("IsWindow", IsWindow),
        xlb_f("IsWindowUnicode", IsWindowUnicode),
        xlb_f("IsWindowVisible", IsWindowVisible),
        xlb_f("IsZoomed", IsZoomed),
        xlb_f("KillTimer", KillTimer),
        xlb_f("LockSetForegroundWindow", LockSetForegroundWindow),
        xlb_f("LogicalToPhysicalPoint", LogicalToPhysicalPoint),
        xlb_f("MAKELPARAM", [](DWORD l, DWORD h) { return MAKELPARAM(l,h); }),
        xlb_f("MAKELRESULT", [](DWORD l, DWORD h) { return MAKELRESULT(l,h); }),
        xlb_f("MAKEWPARAM", [](DWORD l, DWORD h) { return MAKEWPARAM(l,h); }),
        xlb_f("MoveWindow", MoveWindow),
        xlb_f("OpenIcon", OpenIcon),
        xlb_f("PeekMessage", PeekMessage),
        xlb_f("PhysicalToLogicalPoint", PhysicalToLogicalPoint),
        xlb_f("PostMessage", PostMessage),
        xlb_f("PostQuitMessage", PostQuitMessage),
        xlb_f("PostThreadMessage", PostThreadMessage),
        xlb_class<xlb_cbf<PROPENUMPROC>>("PROPENUMPROC").constructor<xlb_luafunc>(),
        xlb_class<xlb_cbf<PROPENUMPROCEX>>("PROPENUMPROCEX").constructor<xlb_luafunc>(),
        xlb_f("RealChildWindowFromPoint", RealChildWindowFromPoint),
        xlb_f("RegisterClass", RegisterClass),
        xlb_f("RegisterClassEx", RegisterClassEx),
        xlb_f("RegisterShellHookWindow", RegisterShellHookWindow),
        xlb_f("RegisterWindowMessage", RegisterWindowMessage),
        xlb_f("RemoveProp", RemoveProp),
        xlb_f("ReplyMessage", ReplyMessage),
        xlb_class<xlb_cbf<SENDASYNCPROC>>("SENDASYNCPROC").constructor<xlb_luafunc>(),
        xlb_f("SendMessage", SendMessage),
        xlb_f("SendMessage", SendMessage),
        xlb_f("SendMessageCallback", SendMessageCallback),
        xlb_f("SendMessageTimeout", SendMessageTimeout),
        xlb_f("SendNotifyMessage", SendNotifyMessage),
        xlb_f("SetClassLong", SetClassLong),
        xlb_f("SetClassLongPtr", SetClassLongPtr),
        xlb_f("SetClassWord", SetClassWord),

#if (WINVER>=0x0602)
        //xlb_f("SetCoalescableTimer", SetCoalescableTimer), // Windows8, Windows Server 2012
#endif

        xlb_f("SetForegroundWindow", SetForegroundWindow),
        xlb_f("SetLayeredWindowAttributes", SetLayeredWindowAttributes),
        xlb_f("SetMessageExtraInfo", SetMessageExtraInfo),
        xlb_f("SetParent", SetParent),
        xlb_f("SetProcessDefaultLayout", SetProcessDefaultLayout),
        xlb_f("SetProcessDPIAware", SetProcessDPIAware),
        xlb_f("SetProp", SetProp),
        xlb_f("SetSysColors", SetSysColors),
        xlb_f("SetTimer", SetTimer),
        xlb_f("SetWindowDisplayAffinity", SetWindowDisplayAffinity),
        xlb_f("SetWindowLong", SetWindowLong),
        xlb_f("SetWindowLongPtr", SetWindowLongPtr),
        xlb_f("SetWindowPlacement", SetWindowPlacement),
        xlb_f("SetWindowPos", SetWindowPos),
        xlb_f("SetWindowsHookEx", SetWindowsHookEx),
        xlb_f("SetWindowText", SetWindowText),
        xlb_f("ShowOwnedPopups", ShowOwnedPopups),
        xlb_f("ShowWindow", ShowWindow),
        xlb_f("ShowWindowAsync", ShowWindowAsync),
        xlb_f("SoundSentry", SoundSentry),
        xlb_f("SwitchToThisWindow", SwitchToThisWindow),
        xlb_f("SystemParametersInfo", SystemParametersInfo),
        xlb_f("TileWindows", TileWindows),
        xlb_class<xlb_cbf<TIMERPROC>>("TIMERPROC").constructor<xlb_luafunc>(),
        xlb_f("TranslateMDISysAccel", TranslateMDISysAccel),
        xlb_f("TranslateMessage", TranslateMessage),
        xlb_f("UnhookWindowsHookEx", UnhookWindowsHookEx),
        xlb_f("UnregisterClass", UnregisterClass),
        xlb_f("UpdateLayeredWindow", UpdateLayeredWindow),
        xlb_f("WaitMessage", WaitMessage),
        xlb_f("WindowFromPhysicalPoint", WindowFromPhysicalPoint),
        xlb_f("WindowFromPoint", WindowFromPoint),
        xlb_class<xlb_cbf<WNDPROC>>("WNDPROC").constructor<xlb_luafunc>(), // WindowProc
        ////xlb_f("WinMain", WinMain),
            
        xlb_class<ALTTABINFO>("ALTTABINFO") .constructor<>() .destructor()
            .property("cbSize", &ALTTABINFO::cbSize)
            .property("cItems", &ALTTABINFO::cItems)
            .property("cColumns", &ALTTABINFO::cColumns)
            .property("cRows", &ALTTABINFO::cRows)
            .property("iColFocus", &ALTTABINFO::iColFocus)
            .property("iRowFocus", &ALTTABINFO::iRowFocus)
            .property("cxItem", &ALTTABINFO::cxItem)
            .property("cyItem", &ALTTABINFO::cyItem)
            .property("ptStart", &ALTTABINFO::ptStart)
            ,
        xlb_class<ANIMATIONINFO>("ANIMATIONINFO") .constructor<>() .destructor()
            .property("cbSize", &ANIMATIONINFO::cbSize)
            .property("iMinAnimate", &ANIMATIONINFO::iMinAnimate)
            ,
        xlb_class<AUDIODESCRIPTION>("AUDIODESCRIPTION") .constructor<>() .destructor()
            .property("cbSize", &AUDIODESCRIPTION::cbSize)
            .property("Enabled", &AUDIODESCRIPTION::Enabled)
            .property("Locale", &AUDIODESCRIPTION::Locale)
            ,
        xlb_class<BSMINFO>("BSMINFO") .constructor<>() .destructor()
            .property("cbSize", &BSMINFO::cbSize)
            .property("hdesk", &BSMINFO::hdesk)
            .property("hwnd", &BSMINFO::hwnd)
            .property("luid", &BSMINFO::luid)
            ,
        xlb_class<CBT_CREATEWND>("CBT_CREATEWNDA") .constructor<>() .destructor()
            .property("lpcs", &CBT_CREATEWND::lpcs)
            .property("hwndInsertAfter", &CBT_CREATEWND::hwndInsertAfter)
            ,
        xlb_class<CBTACTIVATESTRUCT>("CBTACTIVATESTRUCT") .constructor<>() .destructor()
            .property("fMouse", &CBTACTIVATESTRUCT::fMouse)
            .property("hWndActive", &CBTACTIVATESTRUCT::hWndActive)
            ,
        xlb_class<CHANGEFILTERSTRUCT>("CHANGEFILTERSTRUCT") .constructor<>() .destructor()
            .property("cbSize", &CHANGEFILTERSTRUCT::cbSize)
            .property("ExtStatus", &CHANGEFILTERSTRUCT::ExtStatus)
            ,
        xlb_class<CLIENTCREATESTRUCT>("CLIENTCREATESTRUCT") .constructor<>() .destructor()
            .property("hWindowMenu", &CLIENTCREATESTRUCT::hWindowMenu)
            .property("idFirstChild", &CLIENTCREATESTRUCT::idFirstChild)
            ,
        xlb_class<CREATESTRUCT>("CREATESTRUCT") .constructor<>() .destructor()
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
            .property("dwExStyle", &CREATESTRUCT::dwExStyle)
            ,
        xlb_class<CWPRETSTRUCT>("CWPRETSTRUCT") .constructor<>() .destructor()
            .property("lResult", &CWPRETSTRUCT::lResult)
            .property("lParam", &CWPRETSTRUCT::lParam)
            .property("wParam", &CWPRETSTRUCT::wParam)
            .property("message", &CWPRETSTRUCT::message)
            .property("hwnd", &CWPRETSTRUCT::hwnd)
            ,
        xlb_class<CWPSTRUCT>("CWPSTRUCT") .constructor<>() .destructor()
            .property("lParam", &CWPSTRUCT::lParam)
            .property("wParam", &CWPSTRUCT::wParam)
            .property("message", &CWPSTRUCT::message)
            .property("hwnd", &CWPSTRUCT::hwnd)
            ,
        xlb_class<DEBUGHOOKINFO>("DEBUGHOOKINFO") .constructor<>() .destructor()
            .property("idThread", &DEBUGHOOKINFO::idThread)
            .property("idThreadInstaller", &DEBUGHOOKINFO::idThreadInstaller)
            .property("lParam", &DEBUGHOOKINFO::lParam)
            .property("wParam", &DEBUGHOOKINFO::wParam)
            .property("code", &DEBUGHOOKINFO::code)
            ,
        xlb_class<EVENTMSG>("EVENTMSG") .constructor<>() .destructor()
            .property("message", &EVENTMSG::message)
            .property("paramL", &EVENTMSG::paramL)
            .property("paramH", &EVENTMSG::paramH)
            .property("time", &EVENTMSG::time)
            .property("hwnd", &EVENTMSG::hwnd)
            ,
        xlb_class<GUITHREADINFO>("GUITHREADINFO") .constructor<>() .destructor()
            .property("cbSize", &GUITHREADINFO::cbSize)
            .property("flags", &GUITHREADINFO::flags)
            .property("hwndActive", &GUITHREADINFO::hwndActive)
            .property("hwndFocus", &GUITHREADINFO::hwndFocus)
            .property("hwndCapture", &GUITHREADINFO::hwndCapture)
            .property("hwndMenuOwner", &GUITHREADINFO::hwndMenuOwner)
            .property("hwndMoveSize", &GUITHREADINFO::hwndMoveSize)
            .property("hwndCaret", &GUITHREADINFO::hwndCaret)
            .property("rcCaret", &GUITHREADINFO::rcCaret)
            ,
        xlb_class<KBDLLHOOKSTRUCT>("KBDLLHOOKSTRUCT") .constructor<>() .destructor()
            .property("vkCode", &KBDLLHOOKSTRUCT::vkCode)
            .property("scanCode", &KBDLLHOOKSTRUCT::scanCode)
            .property("flags", &KBDLLHOOKSTRUCT::flags)
            .property("time", &KBDLLHOOKSTRUCT::time)
            .property("dwExtraInfo", &KBDLLHOOKSTRUCT::dwExtraInfo)
            ,
        xlb_class<MDICREATESTRUCT>("MDICREATESTRUCT") .constructor<>() .destructor()
            .property("szClass", &MDICREATESTRUCT::szClass)
            .property("szTitle", &MDICREATESTRUCT::szTitle)
            .property("hOwner", &MDICREATESTRUCT::hOwner)
            .property("x", &MDICREATESTRUCT::x)
            .property("y", &MDICREATESTRUCT::y)
            .property("cx", &MDICREATESTRUCT::cx)
            .property("cy", &MDICREATESTRUCT::cy)
            .property("style", &MDICREATESTRUCT::style)
            .property("lParam", &MDICREATESTRUCT::lParam)
            ,
        xlb_class<MINIMIZEDMETRICS>("MINIMIZEDMETRICS") .constructor<>() .destructor()
            .property("cbSize", &MINIMIZEDMETRICS::cbSize)
            .property("iWidth", &MINIMIZEDMETRICS::iWidth)
            .property("iHorzGap", &MINIMIZEDMETRICS::iHorzGap)
            .property("iVertGap", &MINIMIZEDMETRICS::iVertGap)
            .property("iArrange", &MINIMIZEDMETRICS::iArrange)
            ,
        xlb_class<MINMAXINFO>("MINMAXINFO") .constructor<>() .destructor()
            .property("ptReserved", &MINMAXINFO::ptReserved)
            .property("ptMaxSize", &MINMAXINFO::ptMaxSize)
            .property("ptMaxPosition", &MINMAXINFO::ptMaxPosition)
            .property("ptMinTrackSize", &MINMAXINFO::ptMinTrackSize)
            .property("ptMaxTrackSize", &MINMAXINFO::ptMaxTrackSize)
            ,
        xlb_class<MOUSEHOOKSTRUCT>("MOUSEHOOKSTRUCT") .constructor<>() .destructor()
            .property("pt", &MOUSEHOOKSTRUCT::pt)
            .property("hwnd", &MOUSEHOOKSTRUCT::hwnd)
            .property("wHitTestCode", &MOUSEHOOKSTRUCT::wHitTestCode)
            .property("dwExtraInfo", &MOUSEHOOKSTRUCT::dwExtraInfo)
            ,
        xlb_class<MOUSEHOOKSTRUCTEX>("MOUSEHOOKSTRUCTEX") .constructor() .destructor()
            .inherited<MOUSEHOOKSTRUCT>()
            .property("mouseData", &MOUSEHOOKSTRUCTEX::mouseData)
            ,
        xlb_class<MSG>("MSG") .constructor<>() .destructor()
            .property("hwnd", &MSG::hwnd)
            .property("message", &MSG::message)
            .property("wParam", &MSG::wParam)
            .property("lParam", &MSG::lParam)
            .property("time", &MSG::time)
            .property("pt", &MSG::pt)
            //.property("lPrivate", &MSG::lPrivate)
            ,
        xlb_class<MSLLHOOKSTRUCT>("MSLLHOOKSTRUCT") .constructor<>() .destructor()
            .property("pt", &MSLLHOOKSTRUCT::pt)
            .property("mouseData", &MSLLHOOKSTRUCT::mouseData)
            .property("flags", &MSLLHOOKSTRUCT::flags)
            .property("time", &MSLLHOOKSTRUCT::time)
            .property("dwExtraInfo", &MSLLHOOKSTRUCT::dwExtraInfo)
            ,
        xlb_class<NCCALCSIZE_PARAMS>("NCCALCSIZE_PARAMS") .constructor<>() .destructor()
            .property("rgrc", &NCCALCSIZE_PARAMS::rgrc)
            .property("lppos", &NCCALCSIZE_PARAMS::lppos)
            ,
        xlb_class<NONCLIENTMETRICS>("NONCLIENTMETRICS") .constructor<>() .destructor()
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
            .property("iPaddedBorderWidth", &NONCLIENTMETRICS::iPaddedBorderWidth)
            ,
        xlb_class<STYLESTRUCT>("STYLESTRUCT") .constructor<>() .destructor()
            .property("styleOld", &STYLESTRUCT::styleOld)
            .property("styleNew", &STYLESTRUCT::styleNew)
            ,
        xlb_class<TITLEBARINFO>("TITLEBARINFO") .constructor<>() .destructor()
            .property("cbSize", &TITLEBARINFO::cbSize)
            .property("rcTitleBar", &TITLEBARINFO::rcTitleBar)
            .property("rgstate", &TITLEBARINFO::rgstate)
            ,
        xlb_class<TITLEBARINFOEX>("TITLEBARINFOEX") .constructor<>() .destructor()
            .property("cbSize", &TITLEBARINFOEX::cbSize)
            .property("rcTitleBar", &TITLEBARINFOEX::rcTitleBar)
            .property("rgstate", &TITLEBARINFOEX::rgstate)
            .property("rgrect", &TITLEBARINFOEX::rgrect)
            ,
        xlb_class<UPDATELAYEREDWINDOWINFO>("UPDATELAYEREDWINDOWINFO") .constructor<>() .destructor()
            .property("cbSize", &UPDATELAYEREDWINDOWINFO::cbSize)
            .property("hdcDst", &UPDATELAYEREDWINDOWINFO::hdcDst)
            .property("pptDst", &UPDATELAYEREDWINDOWINFO::pptDst)
            .property("psize", &UPDATELAYEREDWINDOWINFO::psize)
            .property("hdcSrc", &UPDATELAYEREDWINDOWINFO::hdcSrc)
            .property("pptSrc", &UPDATELAYEREDWINDOWINFO::pptSrc)
            .property("crKey", &UPDATELAYEREDWINDOWINFO::crKey)
            .property("pblend", &UPDATELAYEREDWINDOWINFO::pblend)
            .property("dwFlags", &UPDATELAYEREDWINDOWINFO::dwFlags)
            .property("prcDirty", &UPDATELAYEREDWINDOWINFO::prcDirty)
            ,
        xlb_class<WINDOWINFO>("WINDOWINFO") .constructor<>() .destructor()
            .property("cbSize", &WINDOWINFO::cbSize)
            .property("rcWindow", &WINDOWINFO::rcWindow)
            .property("rcClient", &WINDOWINFO::rcClient)
            .property("dwStyle", &WINDOWINFO::dwStyle)
            .property("dwExStyle", &WINDOWINFO::dwExStyle)
            .property("dwWindowStatus", &WINDOWINFO::dwWindowStatus)
            .property("cxWindowBorders", &WINDOWINFO::cxWindowBorders)
            .property("cyWindowBorders", &WINDOWINFO::cyWindowBorders)
            .property("atomWindowType", &WINDOWINFO::atomWindowType)
            .property("wCreatorVersion", &WINDOWINFO::wCreatorVersion)
            ,
        xlb_class<WINDOWPLACEMENT>("WINDOWPLACEMENT") .constructor<>() .destructor()
            .property("length", &WINDOWPLACEMENT::length)
            .property("flags", &WINDOWPLACEMENT::flags)
            .property("showCmd", &WINDOWPLACEMENT::showCmd)
            .property("ptMinPosition", &WINDOWPLACEMENT::ptMinPosition)
            .property("ptMaxPosition", &WINDOWPLACEMENT::ptMaxPosition)
            .property("rcNormalPosition", &WINDOWPLACEMENT::rcNormalPosition)
            //.property("rcDevice", &WINDOWPLACEMENT::rcDevice)
            ,
        xlb_class<WINDOWPOS>("WINDOWPOS") .constructor<>() .destructor()
            .property("hwndInsertAfter", &WINDOWPOS::hwndInsertAfter)
            .property("hwnd", &WINDOWPOS::hwnd)
            .property("x", &WINDOWPOS::x)
            .property("y", &WINDOWPOS::y)
            .property("cx", &WINDOWPOS::cx)
            .property("cy", &WINDOWPOS::cy)
            .property("flags", &WINDOWPOS::flags)
            ,
        xlb_class<WNDCLASS>("WNDCLASS") .constructor<>() .destructor()
            .property("style", &WNDCLASS::style)
            .property("lpfnWndProc", &WNDCLASS::lpfnWndProc)
            .property("cbClsExtra", &WNDCLASS::cbClsExtra)
            .property("cbWndExtra", &WNDCLASS::cbWndExtra)
            .property("hInstance", &WNDCLASS::hInstance)
            .property("hIcon", &WNDCLASS::hIcon)
            .property("hCursor", &WNDCLASS::hCursor)
            .property("hbrBackground", &WNDCLASS::hbrBackground)
            .property("lpszMenuName", &WNDCLASS::lpszMenuName)
            .property("lpszClassName", &WNDCLASS::lpszClassName)
            ,
        xlb_class<WNDCLASSEX>("WNDCLASSEX") .constructor<>() .destructor()
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
            ,

        xlb_const("CHECK_BIND_WMSG", BIND_WIN_CHECKED)
    });
#endif // CHECK_BIND_WMSG
    return 0;
}


//-----------------------------------------------------------------------------
int load_gui(lua_State* L)
{
#if defined(CHECK_BIND_GDI)

    xlb_module(L, MODULE_NAME) ({
        xlb_f("AbortPath", AbortPath),
        xlb_f("AddFontMemResourceEx", AddFontMemResourceEx),
        xlb_f("AddFontResource", AddFontResource),
        xlb_f("AddFontResourceEx", AddFontResourceEx),
        xlb_f("AlphaBlend", AlphaBlend),
        xlb_f("AngleArc", AngleArc),
        xlb_f("AnimatePalette", AnimatePalette),
        xlb_f("Arc", Arc),
        xlb_f("ArcTo", ArcTo),
        xlb_f("BeginPaint", BeginPaint),
        xlb_f("BeginPath", BeginPath),
        xlb_f("BitBlt", BitBlt),
        xlb_f("CancelDC", CancelDC),
        xlb_class<xlb_cbf<CFP_ALLOCPROC>>("CFP_ALLOCPROC").constructor<xlb_luafunc>(),
        xlb_class<xlb_cbf<CFP_FREEPROC>>("CFP_FREEPROC").constructor<xlb_luafunc>(),
        xlb_class<xlb_cbf<CFP_REALLOCPROC>>("CFP_REALLOCPROC").constructor<xlb_luafunc>(),
        xlb_f("ChangeDisplaySettings", ChangeDisplaySettings),
        xlb_f("ChangeDisplaySettingsEx", ChangeDisplaySettingsEx),
        xlb_f("Chord", Chord),
        xlb_f("ClientToScreen", ClientToScreen),
        xlb_f("CloseEnhMetaFile", CloseEnhMetaFile),
        xlb_f("CloseFigure", CloseFigure),
        xlb_f("CloseMetaFile", CloseMetaFile),
        xlb_f("CombineRgn", CombineRgn),
        xlb_f("CombineTransform", CombineTransform),
        xlb_f("CopyEnhMetaFile", CopyEnhMetaFile),
        xlb_f("CopyMetaFile", CopyMetaFile),
        xlb_f("CopyRect", CopyRect),
        xlb_f("CreateBitmap", CreateBitmap),
        xlb_f("CreateBitmapIndirect", CreateBitmapIndirect),
        xlb_f("CreateBrushIndirect", CreateBrushIndirect),
        xlb_f("CreateCompatibleBitmap", CreateCompatibleBitmap),
        xlb_f("CreateCompatibleDC", CreateCompatibleDC),
        xlb_f("CreateDCA", CreateDCA),
        xlb_f("CreateDCW", CreateDCW),
        xlb_f("CreateDIBitmap", CreateDIBitmap),
        xlb_f("CreateDIBPatternBrush", CreateDIBPatternBrush),
        xlb_f("CreateDIBPatternBrushPt", CreateDIBPatternBrushPt),
        xlb_f("CreateDIBSection", CreateDIBSection),
        xlb_f("CreateDiscardableBitmap", CreateDiscardableBitmap),
        xlb_f("CreateEllipticRgn", CreateEllipticRgn),
        xlb_f("CreateEllipticRgnIndirect", CreateEllipticRgnIndirect),
        xlb_f("CreateEnhMetaFile", CreateEnhMetaFile),
        xlb_f("CreateFont", CreateFont),
        xlb_f("CreateFontIndirect", CreateFontIndirect),
        xlb_f("CreateFontIndirectEx", CreateFontIndirectEx),
        xlb_f("CreateFontPackage", CreateFontPackage),
        xlb_f("CreateHalftonePalette", CreateHalftonePalette),
        xlb_f("CreateHatchBrush", CreateHatchBrush),
        xlb_f("CreateICA", CreateICA),
        xlb_f("CreateICW", CreateICW),
        xlb_f("CreateMetaFile", CreateMetaFile),
        xlb_f("CreatePalette", CreatePalette),
        xlb_f("CreatePatternBrush", CreatePatternBrush),
        xlb_f("CreatePen", CreatePen),
        xlb_f("CreatePenIndirect", CreatePenIndirect),
        xlb_f("CreatePolygonRgn", CreatePolygonRgn),
        xlb_f("CreatePolyPolygonRgn", CreatePolyPolygonRgn),
        xlb_f("CreateRectRgn", CreateRectRgn),
        xlb_f("CreateRectRgnIndirect", CreateRectRgnIndirect),
        xlb_f("CreateRoundRectRgn", CreateRoundRectRgn),
        xlb_f("CreateScalableFontResource", CreateScalableFontResource),
        xlb_f("CreateSolidBrush", CreateSolidBrush),
        xlb_f("DeleteDC", DeleteDC),
        xlb_f("DeleteEnhMetaFile", DeleteEnhMetaFile),
        xlb_f("DeleteFont", [](HFONT hfont)->void { DeleteObject((HGDIOBJ)(HFONT)(hfont)); }),
        xlb_f("DeleteMetaFile", DeleteMetaFile),
        xlb_f("DeleteObject", DeleteObject),
        xlb_f("DIBINDEX", [](int n) { return DIBINDEX(n); }),
        xlb_f("DPtoLP", DPtoLP),
        xlb_f("DrawAnimatedRects", DrawAnimatedRects),
        xlb_f("DrawCaption", DrawCaption),
        xlb_f("DrawEdge", DrawEdge),
        xlb_f("DrawEscape", DrawEscape),
        xlb_f("DrawFocusRect", DrawFocusRect),
        xlb_f("DrawFrameControl", DrawFrameControl),
        xlb_f("DrawState", DrawState),
        xlb_class<xlb_cbf<DRAWSTATEPROC>>("DRAWSTATEPROC").constructor<xlb_luafunc>(),
        xlb_f("DrawText", DrawText),
        xlb_f("DrawTextEx", DrawTextEx),
        xlb_f("Ellipse", Ellipse),
        xlb_f("EndPaint", EndPaint),
        xlb_f("EndPath", EndPath),
        xlb_class<xlb_cbf<ENHMFENUMPROC>>("ENHMFENUMPROC").constructor<xlb_luafunc>(),
        xlb_f("EnumDisplayDevices", EnumDisplayDevices),
        xlb_f("EnumDisplayMonitors", EnumDisplayMonitors),
        xlb_f("EnumDisplaySettings", EnumDisplaySettings),
        xlb_f("EnumDisplaySettingsEx", EnumDisplaySettingsEx),
        xlb_f("EnumEnhMetaFile", EnumEnhMetaFile),
        xlb_f("EnumFontFamilies", EnumFontFamilies),
        xlb_f("EnumFontFamiliesEx", EnumFontFamiliesEx),
        xlb_f("EnumFonts", EnumFonts),
        xlb_f("EnumMetaFile", EnumMetaFile),
        xlb_f("EnumObjects", EnumObjects),
        xlb_f("EqualRect", EqualRect),
        xlb_f("EqualRgn", EqualRgn),
        xlb_f("ExcludeClipRect", ExcludeClipRect),
        xlb_f("ExcludeUpdateRgn", ExcludeUpdateRgn),
        xlb_f("ExtCreatePen", ExtCreatePen),
        xlb_f("ExtCreateRegion", ExtCreateRegion),
        xlb_f("ExtFloodFill", ExtFloodFill),
        xlb_f("ExtSelectClipRgn", ExtSelectClipRgn),
        xlb_f("ExtTextOut", ExtTextOut),
        xlb_f("FillPath", FillPath),
        xlb_f("FillRect", FillRect),
        xlb_f("FillRgn", FillRgn),
        xlb_f("FlattenPath", FlattenPath),
        xlb_f("FloodFill", FloodFill),
        xlb_f("FrameRect", FrameRect),
        xlb_f("FrameRgn", FrameRgn),
        xlb_f("GdiAlphaBlend", GdiAlphaBlend),
        xlb_f("GdiComment", GdiComment),
        xlb_f("GdiFlush", GdiFlush),
        xlb_f("GdiGetBatchLimit", GdiGetBatchLimit),
        xlb_f("GdiGradientFill", GdiGradientFill),
        xlb_f("GdiSetBatchLimit", GdiSetBatchLimit),
        xlb_f("GdiTransparentBlt", GdiTransparentBlt),
        xlb_f("GetArcDirection", GetArcDirection),
        xlb_f("GetAspectRatioFilterEx", GetAspectRatioFilterEx),
        xlb_f("GetBitmapBits", GetBitmapBits),
        xlb_f("GetBitmapDimensionEx", GetBitmapDimensionEx),
        xlb_f("GetBkColor", GetBkColor),
        xlb_f("GetBkMode", GetBkMode),
        xlb_f("GetBoundsRect", GetBoundsRect),
        xlb_f("GetBrushOrgEx", GetBrushOrgEx),
        xlb_f("GetBValue", [](COLORREF rgb) { return GetBValue(rgb); }),
        xlb_f("GetCharABCWidths", GetCharABCWidths),
        xlb_f("GetCharABCWidthsFloat", GetCharABCWidthsFloat),
        xlb_f("GetCharABCWidthsI", GetCharABCWidthsI),
        xlb_f("GetCharacterPlacement", GetCharacterPlacement),
        xlb_f("GetCharWidth32A", GetCharWidth32A),
        xlb_f("GetCharWidth32W", GetCharWidth32W),
        xlb_f("GetCharWidth", GetCharWidth),
        xlb_f("GetCharWidthFloat", GetCharWidthFloat),
        xlb_f("GetCharWidthI", GetCharWidthI),
        xlb_f("GetClipBox", GetClipBox),
        xlb_f("GetClipRgn", GetClipRgn),
        xlb_f("GetColorAdjustment", GetColorAdjustment),
        xlb_f("GetCurrentObject", GetCurrentObject),
        xlb_f("GetCurrentPositionEx", GetCurrentPositionEx),
        xlb_f("GetDC", GetDC),
        xlb_f("GetDCBrushColor", GetDCBrushColor),
        xlb_f("GetDCEx", GetDCEx),
        xlb_f("GetDCOrgEx", GetDCOrgEx),
        xlb_f("GetDCPenColor", GetDCPenColor),
        xlb_f("GetDeviceCaps", GetDeviceCaps),
        xlb_f("GetDIBColorTable", GetDIBColorTable),
        xlb_f("GetDIBits", GetDIBits),
        xlb_f("GetEnhMetaFile", GetEnhMetaFile),
        xlb_f("GetEnhMetaFileBits", GetEnhMetaFileBits),
        xlb_f("GetEnhMetaFileDescription", GetEnhMetaFileDescription),
        xlb_f("GetEnhMetaFileHeader", GetEnhMetaFileHeader),
        xlb_f("GetEnhMetaFilePaletteEntries", GetEnhMetaFilePaletteEntries),
        xlb_f("GetFontData", GetFontData),
        xlb_f("GetFontLanguageInfo", GetFontLanguageInfo),
        xlb_f("GetFontUnicodeRanges", GetFontUnicodeRanges),
        xlb_f("GetGlyphIndices", GetGlyphIndices),
        xlb_f("GetGlyphOutline", GetGlyphOutline),
        xlb_f("GetGraphicsMode", GetGraphicsMode),
        xlb_f("GetGValue", [](COLORREF rgb) { return GetGValue(rgb); }),
        xlb_f("GetKerningPairs", GetKerningPairs),
        xlb_f("GetLayout", GetLayout),
        xlb_f("GetMapMode", GetMapMode),
        xlb_f("GetMetaFile", GetMetaFile),
        xlb_f("GetMetaFileBitsEx", GetMetaFileBitsEx),
        xlb_f("GetMetaRgn", GetMetaRgn),
        xlb_f("GetMiterLimit", GetMiterLimit),
        xlb_f("GetMonitorInfo", GetMonitorInfo),
        xlb_f("GetNearestColor", GetNearestColor),
        xlb_f("GetNearestPaletteIndex", GetNearestPaletteIndex),
        xlb_f("GetObject", GetObject),
        xlb_f("GetObject", GetObject),
        xlb_f("GetObjectType", GetObjectType),
        xlb_f("GetOutlineTextMetrics", GetOutlineTextMetrics),
        xlb_f("GetPaletteEntries", GetPaletteEntries),
        xlb_f("GetPath", GetPath),
        xlb_f("GetPixel", GetPixel),
        xlb_f("GetPolyFillMode", GetPolyFillMode),
        xlb_f("GetRandomRgn", GetRandomRgn),
        xlb_f("GetRasterizerCaps", GetRasterizerCaps),
        xlb_f("GetRegionData", GetRegionData),
        xlb_f("GetRgnBox", GetRgnBox),
        xlb_f("GetROP2", GetROP2),
        xlb_f("GetRValue", [](COLORREF rgb) { return GetRValue(rgb); }),
        xlb_f("GetStockObject", GetStockObject),
        xlb_f("GetStretchBltMode", GetStretchBltMode),
        xlb_f("GetSysColorBrush", GetSysColorBrush),
        xlb_f("GetSystemPaletteEntries", GetSystemPaletteEntries),
        xlb_f("GetSystemPaletteUse", GetSystemPaletteUse),
        xlb_f("GetTabbedTextExtent", GetTabbedTextExtent),
        xlb_f("GetTextAlign", GetTextAlign),
        xlb_f("GetTextCharacterExtra", GetTextCharacterExtra),
        xlb_f("GetTextColor", GetTextColor),
        xlb_f("GetTextExtentExPoint", GetTextExtentExPoint),
        xlb_f("GetTextExtentExPointI", GetTextExtentExPointI),
        xlb_f("GetTextExtentPoint32A", GetTextExtentPoint32A),
        xlb_f("GetTextExtentPoint32W", GetTextExtentPoint32W),
        xlb_f("GetTextExtentPoint", GetTextExtentPoint),
        xlb_f("GetTextExtentPointI", GetTextExtentPointI),
        xlb_f("GetTextFace", GetTextFace),
        xlb_f("GetTextMetrics", GetTextMetrics),
        xlb_f("GetTextMetrics", GetTextMetrics),
        xlb_f("GetUpdateRect", GetUpdateRect),
        xlb_f("GetUpdateRgn", GetUpdateRgn),
        xlb_f("GetViewportExtEx", GetViewportExtEx),
        xlb_f("GetViewportOrgEx", GetViewportOrgEx),
        xlb_f("GetWindowDC", GetWindowDC),
        xlb_f("GetWindowExtEx", GetWindowExtEx),
        xlb_f("GetWindowOrgEx", GetWindowOrgEx),
        xlb_f("GetWindowRgn", GetWindowRgn),
        xlb_f("GetWindowRgnBox", GetWindowRgnBox),
        xlb_f("GetWinMetaFileBits", GetWinMetaFileBits),
        xlb_f("GetWorldTransform", GetWorldTransform),
        xlb_class<xlb_cbf<GOBJENUMPROC>>("GOBJENUMPROC").constructor<xlb_luafunc>(),
        xlb_f("GradientFill", GradientFill),
        xlb_f("GrayString", GrayString),
        xlb_class<xlb_cbf<GRAYSTRINGPROC>>("GRAYSTRINGPROC").constructor<xlb_luafunc>(),
        xlb_f("InflateRect", InflateRect),
        xlb_f("IntersectClipRect", IntersectClipRect),
        xlb_f("IntersectRect", IntersectRect),
        xlb_f("InvalidateRect", InvalidateRect),
        xlb_f("InvalidateRgn", InvalidateRgn),
        xlb_f("InvertRect", InvertRect),
        xlb_f("InvertRgn", InvertRgn),
        xlb_f("IsRectEmpty", IsRectEmpty),
        xlb_f("LineDDA", LineDDA),
        xlb_class<xlb_cbf<LINEDDAPROC>>("LINEDDAPROC").constructor<xlb_luafunc>(),
        xlb_f("LineTo", LineTo),
        xlb_f("LoadBitmap", LoadBitmap),
        xlb_f("LockWindowUpdate", LockWindowUpdate),
        xlb_f("LPtoDP", LPtoDP),
        xlb_f("MAKEPOINTS", [](long l) { return MAKEPOINTS(l); }),
        xlb_f("MAKEROP4", [](uint32_t fore, uint32_t back) { return MAKEROP4(fore, back); }),
        xlb_f("MapWindowPoints", MapWindowPoints),
        xlb_f("MaskBlt", MaskBlt),
        xlb_f("MergeFontPackage", MergeFontPackage),
        xlb_class<xlb_cbf<MFENUMPROC>>("MFENUMPROC").constructor<xlb_luafunc>(),
        xlb_f("ModifyWorldTransform", ModifyWorldTransform),
        xlb_class<xlb_cbf<MONITORENUMPROC>>("MONITORENUMPROC").constructor<xlb_luafunc>(),
        xlb_f("MonitorFromPoint", MonitorFromPoint),
        xlb_f("MonitorFromRect", MonitorFromRect),
        xlb_f("MonitorFromWindow", MonitorFromWindow),
        xlb_f("MoveToEx", MoveToEx),
        xlb_f("OffsetClipRgn", OffsetClipRgn),
        xlb_f("OffsetRect", OffsetRect),
        xlb_f("OffsetRgn", OffsetRgn),
        xlb_f("OffsetViewportOrgEx", OffsetViewportOrgEx),
        xlb_f("OffsetWindowOrgEx", OffsetWindowOrgEx),
        xlb_f("PaintDesktop", PaintDesktop),
        xlb_f("PaintRgn", PaintRgn),
        xlb_f("PALETTEINDEX", [](int i) { return PALETTEINDEX(i); }),
        xlb_f("PALETTERGB", [](int r, int g, int b) { return PALETTERGB(r,g,b); }),
        xlb_f("PatBlt", PatBlt),
        xlb_f("PathToRegion", PathToRegion),
        xlb_f("Pie", Pie),
        xlb_f("PlayEnhMetaFile", PlayEnhMetaFile),
        xlb_f("PlayEnhMetaFileRecord", PlayEnhMetaFileRecord),
        xlb_f("PlayMetaFile", PlayMetaFile),
        xlb_f("PlayMetaFileRecord", PlayMetaFileRecord),
        xlb_f("PlgBlt", PlgBlt),
        xlb_f("POINTSTOPOINT", [](POINT& pt, POINTS pts) { POINTSTOPOINT(pt,pts); }),
        xlb_f("POINTTOPOINTS", [](POINT& pt) { return POINTTOPOINTS(pt); }),
        xlb_f("PolyBezier", PolyBezier),
        xlb_f("PolyBezierTo", PolyBezierTo),
        xlb_f("PolyDraw", PolyDraw),
        xlb_f("Polygon", Polygon),
        xlb_f("Polyline", Polyline),
        xlb_f("PolylineTo", PolylineTo),
        xlb_f("PolyPolygon", PolyPolygon),
        xlb_f("PolyPolyline", PolyPolyline),
        xlb_f("PolyTextOut", PolyTextOut),
        xlb_f("PtInRect", PtInRect),
        xlb_f("PtInRegion", PtInRegion),
        xlb_f("PtVisible", PtVisible),
        xlb_f("RealizePalette", RealizePalette),
        xlb_f("Rectangle", Rectangle),
        xlb_f("RectInRegion", RectInRegion),
        xlb_f("RectVisible", RectVisible),
        xlb_f("RedrawWindow", RedrawWindow),
        xlb_f("ReleaseDC", ReleaseDC),
        xlb_f("RemoveFontMemResourceEx", RemoveFontMemResourceEx),
        xlb_f("RemoveFontResource", RemoveFontResource),
        xlb_f("RemoveFontResourceEx", RemoveFontResourceEx),
        xlb_f("ResetDCA", ResetDCA),
        xlb_f("ResetDCW", ResetDCW),
        xlb_f("ResizePalette", ResizePalette),
        xlb_f("RestoreDC", RestoreDC),
        xlb_f("RGB", [](int r, int g, int b) { return RGB(r,g,b); }),
        xlb_f("RoundRect", RoundRect),
        xlb_f("SaveDC", SaveDC),
        xlb_f("ScaleViewportExtEx", ScaleViewportExtEx),
        xlb_f("ScaleWindowExtEx", ScaleWindowExtEx),
        xlb_f("ScreenToClient", ScreenToClient),
        xlb_f("SelectClipPath", SelectClipPath),
        xlb_f("SelectClipRgn", SelectClipRgn),
        xlb_f("SelectFont", [](HDC hdc, HFONT hfont) { return SelectFont(hdc, hfont); }),
        xlb_f("SelectObject", SelectObject),
        xlb_f("SelectPalette", SelectPalette),
        xlb_f("SetArcDirection", SetArcDirection),
        xlb_f("SetBitmapBits", SetBitmapBits),
        xlb_f("SetBitmapDimensionEx", SetBitmapDimensionEx),
        xlb_f("SetBkColor", SetBkColor),
        xlb_f("SetBkMode", SetBkMode),
        xlb_f("SetBoundsRect", SetBoundsRect),
        xlb_f("SetBrushOrgEx", SetBrushOrgEx),
        xlb_f("SetColorAdjustment", SetColorAdjustment),
        xlb_f("SetDCBrushColor", SetDCBrushColor),
        xlb_f("SetDCPenColor", SetDCPenColor),
        xlb_f("SetDIBColorTable", SetDIBColorTable),
        xlb_f("SetDIBits", SetDIBits),
        xlb_f("SetDIBitsToDevice", SetDIBitsToDevice),
        xlb_f("SetEnhMetaFileBits", SetEnhMetaFileBits),
        xlb_f("SetGraphicsMode", SetGraphicsMode),
        xlb_f("SetLayout", SetLayout),
        xlb_f("SetMapMode", SetMapMode),
        xlb_f("SetMapperFlags", SetMapperFlags),
        xlb_f("SetMetaFileBitsEx", SetMetaFileBitsEx),
        xlb_f("SetMetaRgn", SetMetaRgn),
        xlb_f("SetMiterLimit", SetMiterLimit),
        xlb_f("SetPaletteEntries", SetPaletteEntries),
        xlb_f("SetPixel", SetPixel),
        xlb_f("SetPixelV", SetPixelV),
        xlb_f("SetPolyFillMode", SetPolyFillMode),
        xlb_f("SetRect", SetRect),
        xlb_f("SetRectEmpty", SetRectEmpty),
        xlb_f("SetRectRgn", SetRectRgn),
        xlb_f("SetROP2", SetROP2),
        xlb_f("SetStretchBltMode", SetStretchBltMode),
        xlb_f("SetSystemPaletteUse", SetSystemPaletteUse),
        xlb_f("SetTextAlign", SetTextAlign),
        xlb_f("SetTextCharacterExtra", SetTextCharacterExtra),
        xlb_f("SetTextColor", SetTextColor),
        xlb_f("SetTextJustification", SetTextJustification),
        xlb_f("SetViewportExtEx", SetViewportExtEx),
        xlb_f("SetViewportOrgEx", SetViewportOrgEx),
        xlb_f("SetWindowExtEx", SetWindowExtEx),
        xlb_f("SetWindowOrgEx", SetWindowOrgEx),
        xlb_f("SetWindowRgn", SetWindowRgn),
        xlb_f("SetWinMetaFileBits", SetWinMetaFileBits),
        xlb_f("SetWorldTransform", SetWorldTransform),
        xlb_f("StretchBlt", StretchBlt),
        xlb_f("StretchDIBits", StretchDIBits),
        xlb_f("StrokeAndFillPath", StrokeAndFillPath),
        xlb_f("StrokePath", StrokePath),
        xlb_f("SubtractRect", SubtractRect),
        xlb_f("TabbedTextOut", TabbedTextOut),
        xlb_f("TextOut", TextOut),
        xlb_f("TransparentBlt", TransparentBlt),
        xlb_f("TTCharToUnicode", TTCharToUnicode),
        xlb_f("TTDeleteEmbeddedFont", TTDeleteEmbeddedFont),
        xlb_f("TTEmbedFont", TTEmbedFont),
        xlb_f("TTEmbedFontEx", TTEmbedFontEx),
        xlb_f("TTEmbedFontFromFile", TTEmbedFontFromFile),
        xlb_f("TTEnableEmbeddingForFacename", TTEnableEmbeddingForFacename),
        xlb_f("TTGetEmbeddedFontInfo", TTGetEmbeddedFontInfo),
        xlb_f("TTGetEmbeddingType", TTGetEmbeddingType),
        xlb_f("TTGetNewFontName", TTGetNewFontName),
        xlb_f("TTIsEmbeddingEnabled", TTIsEmbeddingEnabled),
        xlb_f("TTIsEmbeddingEnabledForFacename", TTIsEmbeddingEnabledForFacename),
        xlb_f("TTLoadEmbeddedFont", TTLoadEmbeddedFont),
        xlb_f("TTRunValidationTests", TTRunValidationTests),
        xlb_f("TTRunValidationTestsEx", TTRunValidationTestsEx),
        xlb_f("UnionRect", UnionRect),
        xlb_f("UnrealizeObject", UnrealizeObject),
        xlb_f("UpdateColors", UpdateColors),
        xlb_f("UpdateWindow", UpdateWindow),
        xlb_f("ValidateRect", ValidateRect),
        xlb_f("ValidateRgn", ValidateRgn),
        xlb_f("WidenPath", WidenPath),
        xlb_f("WindowFromDC", WindowFromDC),
#ifdef compile
#endif
        xlb_class<ABC>("ABC") .constructor() .destructor()
            .property("abc", &AB::abcA)
            .property("abcB", &ABC::abcB)
            .property("abcC", &ABC::abcC)
            ,
        xlb_class<ABCFLOAT>("ABCFLOAT") .constructor() .destructor()
            .property("abcf", &ABCFLOA::abcfA)
            .property("abcfB", &ABCFLOAT::abcfB)
            .property("abcfC", &ABCFLOAT::abcfC)
            ,
        xlb_class<AXESLIST>("AXESLIST") .constructor() .destructor()
            .property("axlReserved", &AXESLIST::axlReserved)
            .property("axlNumAxes", &AXESLIST::axlNumAxes)
            .property("axlAxisInfo", &AXESLIST::axlAxisInfo)
            ,
        xlb_class<AXISINFO>("AXISINFO") .constructor() .destructor()
            .property("axMinValue", &AXISINFO::axMinValue)
            .property("axMaxValue", &AXISINFO::axMaxValue)
            .property("axAxisName", &AXISINFO::axAxisName)
            ,
        xlb_class<BITMAP>("BITMAP") .constructor() .destructor()
            .property("bmType", &BITMAP::bmType)
            .property("bmWidth", &BITMAP::bmWidth)
            .property("bmHeight", &BITMAP::bmHeight)
            .property("bmWidthBytes", &BITMAP::bmWidthBytes)
            .property("bmPlanes", &BITMAP::bmPlanes)
            .property("bmBitsPixel", &BITMAP::bmBitsPixel)
            .property("bmBits", &BITMAP::bmBits)
            , 
        xlb_class<BITMAPCOREHEADER>("BITMAPCOREHEADER") .constructor() .destructor()
            .property("bcSize", &BITMAPCOREHEADER::bcSize)
            .property("bcWidth", &BITMAPCOREHEADER::bcWidth)
            .property("bcHeight", &BITMAPCOREHEADER::bcHeight)
            .property("bcPlanes", &BITMAPCOREHEADER::bcPlanes)
            .property("bcBitCount", &BITMAPCOREHEADER::bcBitCount)
            , 
        xlb_class<BITMAPCOREINFO>("BITMAPCOREINFO") .constructor() .destructor()
            .property("bmciHeader", &BITMAPCOREINFO::bmciHeader)
            .property("bmciColors", &BITMAPCOREINFO::bmciColors)
            ,
        xlb_class<BITMAPFILEHEADER>("BITMAPFILEHEADER") .constructor() .destructor()
            .property("bfType", &BITMAPFILEHEADER::bfType)
            .property("bfSize", &BITMAPFILEHEADER::bfSize)
            .property("bfReserved1", &BITMAPFILEHEADER::bfReserved1)
            .property("bfReserved2", &BITMAPFILEHEADER::bfReserved2)
            .property("bfOffBits", &BITMAPFILEHEADER::bfOffBits)
            ,
        xlb_class<BITMAPINFO>("BITMAPINFO") .constructor() .destructor()
            .property("bmiHeader", &BITMAPINFO::bmiHeader)
            .property("bmiColors", &BITMAPINFO::bmiColors)
            ,
        xlb_class<BITMAPV4HEADER>("BITMAPV4HEADER") .constructor() .destructor()
            .property("bV4Size", &BITMAPV4HEADER::bV4Size)
            .property("bV4Width", &BITMAPV4HEADER::bV4Width)
            .property("bV4Height", &BITMAPV4HEADER::bV4Height)
            .property("bV4Planes", &BITMAPV4HEADER::bV4Planes)
            .property("bV4BitCount", &BITMAPV4HEADER::bV4BitCount)
            .property("bV4V4Compression", &BITMAPV4HEADER::bV4V4Compression)
            .property("bV4SizeImage", &BITMAPV4HEADER::bV4SizeImage)
            .property("bV4XPelsPerMeter", &BITMAPV4HEADER::bV4XPelsPerMeter)
            .property("bV4YPelsPerMeter", &BITMAPV4HEADER::bV4YPelsPerMeter)
            .property("bV4ClrUsed", &BITMAPV4HEADER::bV4ClrUsed)
            .property("bV4ClrImportant", &BITMAPV4HEADER::bV4ClrImportant)
            .property("bV4RedMask", &BITMAPV4HEADER::bV4RedMask)
            .property("bV4GreenMask", &BITMAPV4HEADER::bV4GreenMask)
            .property("bV4BlueMask", &BITMAPV4HEADER::bV4BlueMask)
            .property("bV4AlphaMask", &BITMAPV4HEADER::bV4AlphaMask)
            .property("bV4CSType", &BITMAPV4HEADER::bV4CSType)
            .property("bV4Endpoints", &BITMAPV4HEADER::bV4Endpoints)
            .property("bV4GammaRed", &BITMAPV4HEADER::bV4GammaRed)
            .property("bV4GammaGreen", &BITMAPV4HEADER::bV4GammaGreen)
            .property("bV4GammaBlue", &BITMAPV4HEADER::bV4GammaBlue)
            ,
        xlb_class<BITMAPV5HEADER>("BITMAPV5HEADER") .constructor() .destructor()
            .property("bV5Size", &BITMAPV5HEADER::bV5Size)
            .property("bV5Width", &BITMAPV5HEADER::bV5Width)
            .property("bV5Height", &BITMAPV5HEADER::bV5Height)
            .property("bV5Planes", &BITMAPV5HEADER::bV5Planes)
            .property("bV5BitCount", &BITMAPV5HEADER::bV5BitCount)
            .property("bV5Compression", &BITMAPV5HEADER::bV5Compression)
            .property("bV5SizeImage", &BITMAPV5HEADER::bV5SizeImage)
            .property("bV5XPelsPerMeter", &BITMAPV5HEADER::bV5XPelsPerMeter)
            .property("bV5YPelsPerMeter", &BITMAPV5HEADER::bV5YPelsPerMeter)
            .property("bV5ClrUsed", &BITMAPV5HEADER::bV5ClrUsed)
            .property("bV5ClrImportant", &BITMAPV5HEADER::bV5ClrImportant)
            .property("bV5RedMask", &BITMAPV5HEADER::bV5RedMask)
            .property("bV5GreenMask", &BITMAPV5HEADER::bV5GreenMask)
            .property("bV5BlueMask", &BITMAPV5HEADER::bV5BlueMask)
            .property("bV5AlphaMask", &BITMAPV5HEADER::bV5AlphaMask)
            .property("bV5CSType", &BITMAPV5HEADER::bV5CSType)
            .property("bV5Endpoints", &BITMAPV5HEADER::bV5Endpoints)
            .property("bV5GammaRed", &BITMAPV5HEADER::bV5GammaRed)
            .property("bV5GammaGreen", &BITMAPV5HEADER::bV5GammaGreen)
            .property("bV5GammaBlue", &BITMAPV5HEADER::bV5GammaBlue)
            .property("bV5Intent", &BITMAPV5HEADER::bV5Intent)
            .property("bV5ProfileData", &BITMAPV5HEADER::bV5ProfileData)
            .property("bV5ProfileSize", &BITMAPV5HEADER::bV5ProfileSize)
            .property("bV5Reserved", &BITMAPV5HEADER::bV5Reserved)
            ,
        xlb_class<BLENDFUNCTION>("BLENDFUNCTION") .constructor() .destructor()
            .property("BlendOp", &BLENDFUNCTION::BlendOp)
            .property("BlendFlags", &BLENDFUNCTION::BlendFlags)
            .property("SourceConstantAlpha", &BLENDFUNCTION::SourceConstantAlpha)
            .property("AlphaFormat", &BLENDFUNCTION::AlphaFormat)
            ,
        xlb_class<COLORADJUSTMENT>("COLORADJUSTMENT") .constructor() .destructor()
            .property("caSize", &COLORADJUSTMENT::caSize)
            .property("caFlags", &COLORADJUSTMENT::caFlags)
            .property("caIlluminantIndex", &COLORADJUSTMENT::caIlluminantIndex)
            .property("caRedGamma", &COLORADJUSTMENT::caRedGamma)
            .property("caGreenGamma", &COLORADJUSTMENT::caGreenGamma)
            .property("caBlueGamma", &COLORADJUSTMENT::caBlueGamma)
            .property("caReferenceBlack", &COLORADJUSTMENT::caReferenceBlack)
            .property("caReferenceWhite", &COLORADJUSTMENT::caReferenceWhite)
            .property("caContrast", &COLORADJUSTMENT::caContrast)
            .property("caBrightness", &COLORADJUSTMENT::caBrightness)
            .property("caColorfulness", &COLORADJUSTMENT::caColorfulness)
            .property("caRedGreenTint", &COLORADJUSTMENT::caRedGreenTint)
            ,
        xlb_class<DESIGNVECTOR>("DESIGNVECTOR") .constructor() .destructor()
            .property("dvReserved", &DESIGNVECTOR::dvReserved)
            .property("dvNumAxes", &DESIGNVECTOR::dvNumAxes)
            .property("dvValues", &DESIGNVECTOR::dvValues)
            ,
        xlb_class<DIBSECTION>("DIBSECTION") .constructor() .destructor()
            .property("dsBm", &DIBSECTION::dsBm)
            .property("dsBmih", &DIBSECTION::dsBmih)
            .property("dsBitfields", &DIBSECTION::dsBitfields)
            .property("dshSection", &DIBSECTION::dshSection)
            .property("dsOffset", &DIBSECTION::dsOffset)
            ,
        xlb_class<DISPLAY_DEVICE>("DISPLAY_DEVICE") .constructor() .destructor()
            .property("cb", &DISPLAY_DEVICE::cb)
            .property("DeviceName", &DISPLAY_DEVICE::DeviceName)
            .property("DeviceString", &DISPLAY_DEVICE::DeviceString)
            .property("StateFlags", &DISPLAY_DEVICE::StateFlags)
            .property("DeviceID", &DISPLAY_DEVICE::DeviceID)
            .property("DeviceKey", &DISPLAY_DEVICE::DeviceKey)
            ,
        xlb_class<DRAWTEXTPARAMS>("DRAWTEXTPARAMS") .constructor() .destructor()
            .property("cbSize", &DRAWTEXTPARAMS::cbSize)
            .property("iTabLength", &DRAWTEXTPARAMS::iTabLength)
            .property("iLeftMargin", &DRAWTEXTPARAMS::iLeftMargin)
            .property("iRightMargin", &DRAWTEXTPARAMS::iRightMargin)
            .property("uiLengthDrawn", &DRAWTEXTPARAMS::uiLengthDrawn)
            ,
        xlb_class<EMR>("EMR") .constructor() .destructor()
            .property("iType", &EMR::iType)
            .property("nSize", &EMR::nSize)
            ,
        xlb_class<EMRABORTPATH>("EMRABORTPATH") .constructor() .destructor()
            .property("emr", &EMRABORTPATH::emr)
            ,
        xlb_class<EMRALPHABLEND>("EMRALPHABLEND") .constructor() .destructor()
            .property("emr", &EMRALPHABLEND::emr)
            .property("rclBounds", &EMRALPHABLEND::rclBounds)
            .property("xDest", &EMRALPHABLEND::xDest)
            .property("yDest", &EMRALPHABLEND::yDest)
            .property("cxDest", &EMRALPHABLEND::cxDest)
            .property("cyDest", &EMRALPHABLEND::cyDest)
            .property("dwRop", &EMRALPHABLEND::dwRop)
            .property("xSrc", &EMRALPHABLEND::xSrc)
            .property("ySrc", &EMRALPHABLEND::ySrc)
            .property("xformSrc", &EMRALPHABLEND::xformSrc)
            .property("crBkColorSrc", &EMRALPHABLEND::crBkColorSrc)
            .property("iUsageSrc", &EMRALPHABLEND::iUsageSrc)
            .property("offBmiSrc", &EMRALPHABLEND::offBmiSrc)
            .property("cbBmiSrc", &EMRALPHABLEND::cbBmiSrc)
            .property("offBitsSrc", &EMRALPHABLEND::offBitsSrc)
            .property("cbBitsSrc", &EMRALPHABLEND::cbBitsSrc)
            .property("cxSrc", &EMRALPHABLEND::cxSrc)
            .property("cySrc", &EMRALPHABLEND::cySrc)
            ,
        xlb_class<EMRANGLEARC>("EMRANGLEARC") .constructor() .destructor()
            .property("emr", &EMRANGLEARC::emr)
            .property("ptlCenter", &EMRANGLEARC::ptlCenter)
            .property("nRadius", &EMRANGLEARC::nRadius)
            .property("eStartAngle", &EMRANGLEARC::eStartAngle)
            .property("eSweepAngle", &EMRANGLEARC::eSweepAngle)
            ,
        xlb_class<EMRARC>("EMRARC") .constructor() .destructor()
            .property("emr", &EMRARC::emr)
            .property("rclBox", &EMRARC::rclBox)
            .property("ptlStart", &EMRARC::ptlStart)
            .property("ptlEnd", &EMRARC::ptlEnd)
            ,
        xlb_class<EMRBITBLT>("EMRARCEMRBITBLT") .constructor() .destructor()
            .property("emr", &EMRBITBLT::emr)
            .property("rclBounds", &EMRBITBLT::rclBounds)
            .property("xDest", &EMRBITBLT::xDest)
            .property("yDest", &EMRBITBLT::yDest)
            .property("cxDest", &EMRBITBLT::cxDest)
            .property("cyDest", &EMRBITBLT::cyDest)
            .property("dwRop", &EMRBITBLT::dwRop)
            .property("xSrc", &EMRBITBLT::xSrc)
            .property("ySrc", &EMRBITBLT::ySrc)
            .property("xformSrc", &EMRBITBLT::xformSrc)
            .property("crBkColorSrc", &EMRBITBLT::crBkColorSrc)
            .property("iUsageSrc", &EMRBITBLT::iUsageSrc)
            .property("offBmiSrc", &EMRBITBLT::offBmiSrc)
            .property("cbBmiSrc", &EMRBITBLT::cbBmiSrc)
            .property("offBitsSrc", &EMRBITBLT::offBitsSrc)
            .property("cbBitsSrc", &EMRBITBLT::cbBitsSrc)
            ,
        xlb_class<EMRCOLORCORRECTPALETTE>("EMRCOLORCORRECTPALETTE") .constructor() .destructor()
            .property("emr", &EMRCOLORCORRECTPALETTE::emr)
            .property("ihPalette", &EMRCOLORCORRECTPALETTE::ihPalette)
            .property("nFirstEntry", &EMRCOLORCORRECTPALETTE::nFirstEntry)
            .property("nPalEntries", &EMRCOLORCORRECTPALETTE::nPalEntries)
            .property("nReserved", &EMRCOLORCORRECTPALETTE::nReserved)
            ,
        xlb_class<EMRCOLORMATCHTOTARGET>("EMRCOLORMATCHTOTARGET") .constructor() .destructor()
            .property("emr", &EMRCOLORMATCHTOTARGET::emr)
            .property("dwAction", &EMRCOLORMATCHTOTARGET::dwAction)
            .property("dwFlags", &EMRCOLORMATCHTOTARGET::dwFlags)
            .property("cbName", &EMRCOLORMATCHTOTARGET::cbName)
            .property("cbData", &EMRCOLORMATCHTOTARGET::cbData)
            .property("Data", &EMRCOLORMATCHTOTARGET::Data)
            ,
        xlb_class<EMRCREATEBRUSHINDIRECT>("EMRCREATEBRUSHINDIRECT") .constructor() .destructor()
            .property("emr", &EMRCREATEBRUSHINDIRECT::emr)
            .property("ihBrush", &EMRCREATEBRUSHINDIRECT::ihBrush)
            .property("lb", &EMRCREATEBRUSHINDIRECT::lb)
            ,
        xlb_class<EMRCREATECOLORSPACE>("EMRCREATECOLORSPACE") .constructor() .destructor()
            .property("emr", &EMRCREATECOLORSPACE::emr)
            .property("ihCS", &EMRCREATECOLORSPACE::ihCS)
            .property("lcs", &EMRCREATECOLORSPACE::lcs)
            ,
        xlb_class<EMRCREATECOLORSPACEW>("EMRCREATECOLORSPACEW") .constructor() .destructor()
            .property("emr", &EMRCREATECOLORSPACEW::emr)
            .property("ihCS", &EMRCREATECOLORSPACEW::ihCS)
            .property("lcs", &EMRCREATECOLORSPACEW::lcs)
            .property("dwFlags", &EMRCREATECOLORSPACEW::dwFlags)
            .property("cbData", &EMRCREATECOLORSPACEW::cbData)
            .property("Data", &EMRCREATECOLORSPACEW::Data)
            ,
        xlb_class<EMRCREATEDIBPATTERNBRUSHPT>("EMRCREATEDIBPATTERNBRUSHPT") .constructor() .destructor()
            .property("emr", &EMRCREATEDIBPATTERNBRUSHPT::emr)
            .property("ihBrush", &EMRCREATEDIBPATTERNBRUSHPT::ihBrush)
            .property("iUsage", &EMRCREATEDIBPATTERNBRUSHPT::iUsage)
            .property("offBmi", &EMRCREATEDIBPATTERNBRUSHPT::offBmi)
            .property("cbBmi", &EMRCREATEDIBPATTERNBRUSHPT::cbBmi)
            .property("offBits", &EMRCREATEDIBPATTERNBRUSHPT::offBits)
            .property("cbBits", &EMRCREATEDIBPATTERNBRUSHPT::cbBits)
            ,
        xlb_class<EMRCREATEMONOBRUSH>("EMRCREATEMONOBRUSH") .constructor() .destructor()
            .property("emr", &EMRCREATEMONOBRUSH::emr)
            .property("ihBrush", &EMRCREATEMONOBRUSH::ihBrush)
            .property("iUsage", &EMRCREATEMONOBRUSH::iUsage)
            .property("offBmi", &EMRCREATEMONOBRUSH::offBmi)
            .property("cbBmi", &EMRCREATEMONOBRUSH::cbBmi)
            .property("offBits", &EMRCREATEMONOBRUSH::offBits)
            .property("cbBits", &EMRCREATEMONOBRUSH::cbBits)
            ,
        xlb_class<EMRCREATEPALETTE>("EMRCREATEPALETTE") .constructor() .destructor()
            .property("emr", &EMRCREATEPALETTE::emr)
            .property("ihPal", &EMRCREATEPALETTE::ihPal)
            .property("lgpl", &EMRCREATEPALETTE::lgpl)
            ,
        xlb_class<EMRCREATEPEN>("EMRCREATEPEN") .constructor() .destructor()
            .property("emr", &EMRCREATEPEN::emr)
            .property("ihPen", &EMRCREATEPEN::ihPen)
            .property("lopn", &EMRCREATEPEN::lopn)
            ,
        xlb_class<EMRELLIPSE>("EMRELLIPSE") .constructor() .destructor()
            .property("emr", &EMRELLIPSE::emr)
            .property("rclBox", &EMRELLIPSE::rclBox)
            ,
        xlb_class<EMREOF>("EMREOF") .constructor() .destructor()
            .property("emr", &EMREOF::emr)
            .property("nPalEntries", &EMREOF::nPalEntries)
            .property("offPalEntries", &EMREOF::offPalEntries)
            .property("nSizeLast", &EMREOF::nSizeLast)
            ,
        xlb_class<EMREXCLUDECLIPRECT>("EMREXCLUDECLIPRECT") .constructor() .destructor()
            .property("emr", &EMREXCLUDECLIPRECT::emr)
            .property("rclClip", &EMREXCLUDECLIPRECT::rclClip)
            ,
        xlb_class<EMREXTCREATEFONTINDIRECTW>("EMREXTCREATEFONTINDIRECTW") .constructor() .destructor()
            .property("emr", &EMREXTCREATEFONTINDIRECTW::emr)
            .property("ihFont", &EMREXTCREATEFONTINDIRECTW::ihFont)
            .property("elfw", &EMREXTCREATEFONTINDIRECTW::elfw)
            ,
        xlb_class<EMREXTCREATEPEN>("EMREXTCREATEPEN") .constructor() .destructor()
            .property("emr", &EMREXTCREATEPEN::emr)
            .property("ihPen", &EMREXTCREATEPEN::ihPen)
            .property("offBmi", &EMREXTCREATEPEN::offBmi)
            .property("cbBmi", &EMREXTCREATEPEN::cbBmi)
            .property("offBits", &EMREXTCREATEPEN::offBits)
            .property("cbBits", &EMREXTCREATEPEN::cbBits)
            .property("elp", &EMREXTCREATEPEN::elp)
            ,
        xlb_class<EMREXTFLOODFILL>("EMREXTFLOODFILL") .constructor() .destructor()
            .property("emr", &EMREXTFLOODFILL::emr)
            .property("ptlStart", &EMREXTFLOODFILL::ptlStart)
            .property("crColor", &EMREXTFLOODFILL::crColor)
            .property("iMode", &EMREXTFLOODFILL::iMode)
            ,
        xlb_class<EMREXTSELECTCLIPRGN>("EMREXTSELECTCLIPRGN") .constructor() .destructor()
            .property("emr", &EMREXTSELECTCLIPRGN::emr)
            .property("cbRgnData", &EMREXTSELECTCLIPRGN::cbRgnData)
            .property("iMode", &EMREXTSELECTCLIPRGN::iMode)
            .property("RgnData", &EMREXTSELECTCLIPRGN::RgnData)
            ,
        xlb_class<EMREXTTEXTOUTA>("EMREXTTEXTOUTA") .constructor() .destructor()
            .property("emr", &EMREXTTEXTOUTA::emr)
            .property("rclBounds", &EMREXTTEXTOUTA::rclBounds)
            .property("iGraphicsMode", &EMREXTTEXTOUTA::iGraphicsMode)
            .property("exScale", &EMREXTTEXTOUTA::exScale)
            .property("eyScale", &EMREXTTEXTOUTA::eyScale)
            .property("emrtext", &EMREXTTEXTOUTA::emrtext)
            ,
        xlb_class<EMRFILLPATH>("EMRFILLPATH") .constructor() .destructor()
            .property("emr", &EMRFILLPATH::emr)
            .property("rclBounds", &EMRFILLPATH::rclBounds)
            ,
        xlb_class<EMRFILLRGN>("EMRFILLRGN") .constructor() .destructor()
            .property("emr", &EMRFILLRGN::emr)
            .property("rclBounds", &EMRFILLRGN::rclBounds)
            .property("cbRgnData", &EMRFILLRGN::cbRgnData)
            .property("ihBrush", &EMRFILLRGN::ihBrush)
            .property("RgnData", &EMRFILLRGN::RgnData)
            ,
        xlb_class<EMRFORMAT>("EMRFORMAT") .constructor() .destructor()
            .property("dSignature", &EMRFORMAT::dSignature)
            .property("nVersion", &EMRFORMAT::nVersion)
            .property("cbData", &EMRFORMAT::cbData)
            .property("offData", &EMRFORMAT::offData)
            ,
        xlb_class<EMRFRAMERGN>("EMRFRAMERGN") .constructor() .destructor()
            .property("emr", &EMRFRAMERGN::emr)
            .property("rclBounds", &EMRFRAMERGN::rclBounds)
            .property("cbRgnData", &EMRFRAMERGN::cbRgnData)
            .property("ihBrush", &EMRFRAMERGN::ihBrush)
            .property("szlStroke", &EMRFRAMERGN::szlStroke)
            .property("RgnData", &EMRFRAMERGN::RgnData)
            ,
        xlb_class<EMRGDICOMMENT>("EMRGDICOMMENT") .constructor() .destructor()
            .property("emr", &EMRGDICOMMENT::emr)
            .property("cbData", &EMRGDICOMMENT::cbData)
            .property("Data", &EMRGDICOMMENT::Data)
            ,
        xlb_class<EMRGLSBOUNDEDRECORD>("EMRGLSBOUNDEDRECORD") .constructor() .destructor()
            .property("emr", &EMRGLSBOUNDEDRECORD::emr)
            .property("rclBounds", &EMRGLSBOUNDEDRECORD::rclBounds)
            .property("cbData", &EMRGLSBOUNDEDRECORD::cbData)
            .property("Data", &EMRGLSBOUNDEDRECORD::Data)
            ,
        xlb_class<EMRGLSRECORD>("EMRGLSRECORD") .constructor() .destructor()
            .property("emr", &EMRGLSRECORD::emr)
            .property("cbData", &EMRGLSRECORD::cbData)
            .property("Data", &EMRGLSRECORD::Data)
            ,
        xlb_class<EMRGRADIENTFILL>("EMRGRADIENTFILL") .constructor() .destructor()
            .property("emr", &EMRGRADIENTFILL::emr)
            .property("rclBounds", &EMRGRADIENTFILL::rclBounds)
            .property("nVer", &EMRGRADIENTFILL::nVer)
            .property("nTri", &EMRGRADIENTFILL::nTri)
            .property("ulMode", &EMRGRADIENTFILL::ulMode)
            .property("Ver", &EMRGRADIENTFILL::Ver)
            ,
        xlb_class<EMRINVERTRGN>("EMRINVERTRGN") .constructor() .destructor()
            .property("emr", &EMRINVERTRGN::emr)
            .property("rclBounds", &EMRINVERTRGN::rclBounds)
            .property("cbRgnData", &EMRINVERTRGN::cbRgnData)
            .property("RgnData", &EMRINVERTRGN::RgnData)
            ,
        xlb_class<EMRLINETO>("EMRLINETO") .constructor() .destructor()
            .property("emr", &EMRLINETO::emr)
            .property("ptl", &EMRLINETO::ptl)
            ,
        xlb_class<EMRMASKBLT>("EMRMASKBLT") .constructor() .destructor()
            .property("emr", &EMRMASKBLT::emr)
            .property("rclBounds", &EMRMASKBLT::rclBounds)
            .property("xDest", &EMRMASKBLT::xDest)
            .property("yDest", &EMRMASKBLT::yDest)
            .property("cxDest", &EMRMASKBLT::cxDest)
            .property("cyDest", &EMRMASKBLT::cyDest)
            .property("dwRop", &EMRMASKBLT::dwRop)
            .property("xSrc", &EMRMASKBLT::xSrc)
            .property("ySrc", &EMRMASKBLT::ySrc)
            .property("xformSrc", &EMRMASKBLT::xformSrc)
            .property("crBkColorSrc", &EMRMASKBLT::crBkColorSrc)
            .property("iUsageSrc", &EMRMASKBLT::iUsageSrc)
            .property("offBmiSrc", &EMRMASKBLT::offBmiSrc)
            .property("cbBmiSrc", &EMRMASKBLT::cbBmiSrc)
            .property("offBitsSrc", &EMRMASKBLT::offBitsSrc)
            .property("cbBitsSrc", &EMRMASKBLT::cbBitsSrc)
            .property("xMask", &EMRMASKBLT::xMask)
            .property("yMask", &EMRMASKBLT::yMask)
            .property("iUsageMask", &EMRMASKBLT::iUsageMask)
            .property("offBmiMask", &EMRMASKBLT::offBmiMask)
            .property("cbBmiMask", &EMRMASKBLT::cbBmiMask)
            .property("offBitsMask", &EMRMASKBLT::offBitsMask)
            .property("cbBitsMask", &EMRMASKBLT::cbBitsMask)
            ,
        xlb_class<EMRMODIFYWORLDTRANSFORM>("EMRMODIFYWORLDTRANSFORM") .constructor() .destructor()
            .property("emr", &EMRMODIFYWORLDTRANSFORM::emr)
            .property("xform", &EMRMODIFYWORLDTRANSFORM::xform)
            .property("iMode", &EMRMODIFYWORLDTRANSFORM::iMode)
            ,
        xlb_class<EMROFFSETCLIPRGN>("EMROFFSETCLIPRGN") .constructor() .destructor()
            .property("emr", &EMROFFSETCLIPRGN::emr)
            .property("ptlOffset", &EMROFFSETCLIPRGN::ptlOffset)
            ,
        xlb_class<EMRPIXELFORMAT>("EMRPIXELFORMAT") .constructor() .destructor()
            .property("emr", &EMRPIXELFORMAT::emr)
            .property("pfd", &EMRPIXELFORMAT::pfd)
            ,
        xlb_class<EMRPLGBLT>("EMRPLGBLT") .constructor() .destructor()
            .property("emr", &EMRPLGBLT::emr)
            .property("rclBounds", &EMRPLGBLT::rclBounds)
            .property("aptlDest", &EMRPLGBLT::aptlDest)
            .property("xSrc", &EMRPLGBLT::xSrc)
            .property("ySrc", &EMRPLGBLT::ySrc)
            .property("cxSrc", &EMRPLGBLT::cxSrc)
            .property("cySrc", &EMRPLGBLT::cySrc)
            .property("xformSrc", &EMRPLGBLT::xformSrc)
            .property("crBkColorSrc", &EMRPLGBLT::crBkColorSrc)
            .property("iUsageSrc", &EMRPLGBLT::iUsageSrc)
            .property("offBmiSrc", &EMRPLGBLT::offBmiSrc)
            .property("cbBmiSrc", &EMRPLGBLT::cbBmiSrc)
            .property("offBitsSrc", &EMRPLGBLT::offBitsSrc)
            .property("cbBitsSrc", &EMRPLGBLT::cbBitsSrc)
            .property("xMask", &EMRPLGBLT::xMask)
            .property("yMask", &EMRPLGBLT::yMask)
            .property("iUsageMask", &EMRPLGBLT::iUsageMask)
            .property("offBmiMask", &EMRPLGBLT::offBmiMask)
            .property("cbBmiMask", &EMRPLGBLT::cbBmiMask)
            .property("offBitsMask", &EMRPLGBLT::offBitsMask)
            .property("cbBitsMask", &EMRPLGBLT::cbBitsMask)
            ,
        xlb_class<EMRPOLYDRAW>("EMRPOLYDRAW") .constructor() .destructor()
            .property("emr", &EMRPOLYDRAW::emr)
            .property("rclBounds", &EMRPOLYDRAW::rclBounds)
            .property("cptl", &EMRPOLYDRAW::cptl)
            .property("aptl", &EMRPOLYDRAW::aptl)
            .property("abTypes", &EMRPOLYDRAW::abTypes)
            ,
        xlb_class<EMRPOLYDRAW16>("EMRPOLYDRAW16") .constructor() .destructor()
            .property("emr", &EMRPOLYDRAW16::emr)
            .property("rclBounds", &EMRPOLYDRAW16::rclBounds)
            .property("cpts", &EMRPOLYDRAW16::cpts)
            .property("apts", &EMRPOLYDRAW16::apts)
            .property("abTypes", &EMRPOLYDRAW16::abTypes)
            ,
        xlb_class<EMRPOLYLINE>("EMRPOLYLINE") .constructor() .destructor()
            .property("emr", &EMRPOLYLINE::emr)
            .property("rclBounds", &EMRPOLYLINE::rclBounds)
            .property("cptl", &EMRPOLYLINE::cptl)
            .property("aptl", &EMRPOLYLINE::aptl)
            ,
        xlb_class<EMRPOLYLINE16>("EMRPOLYLINE16") .constructor() .destructor()
            .property("emr", &EMRPOLYLINE16::emr)
            .property("rclBounds", &EMRPOLYLINE16::rclBounds)
            .property("cpts", &EMRPOLYLINE16::cpts)
            .property("apts", &EMRPOLYLINE16::apts)
            ,
        xlb_class<EMRPOLYPOLYLINE>("EMRPOLYPOLYLINE") .constructor() .destructor()
            .property("emr", &EMRPOLYPOLYLINE::emr)
            .property("rclBounds", &EMRPOLYPOLYLINE::rclBounds)
            .property("nPolys", &EMRPOLYPOLYLINE::nPolys)
            .property("cptl", &EMRPOLYPOLYLINE::cptl)
            .property("aPolyCounts", &EMRPOLYPOLYLINE::aPolyCounts)
            .property("aptl", &EMRPOLYPOLYLINE::aptl)
            ,
        xlb_class<EMRPOLYPOLYLINE16>("EMRPOLYPOLYLINE16") .constructor() .destructor()
            .property("emr", &EMRPOLYPOLYLINE16::emr)
            .property("rclBounds", &EMRPOLYPOLYLINE16::rclBounds)
            .property("nPolys", &EMRPOLYPOLYLINE16::nPolys)
            .property("cpts", &EMRPOLYPOLYLINE16::cpts)
            .property("aPolyCounts", &EMRPOLYPOLYLINE16::aPolyCounts)
            .property("apts", &EMRPOLYPOLYLINE16::apts)
            ,
        xlb_class<EMRPOLYTEXTOUTA>("EMRPOLYTEXTOUTA") .constructor() .destructor()
            .property("emr", &EMRPOLYTEXTOUTA::emr)
            .property("rclBounds", &EMRPOLYTEXTOUTA::rclBounds)
            .property("iGraphicsMode", &EMRPOLYTEXTOUTA::iGraphicsMode)
            .property("exScale", &EMRPOLYTEXTOUTA::exScale)
            .property("eyScale", &EMRPOLYTEXTOUTA::eyScale)
            .property("cStrings", &EMRPOLYTEXTOUTA::cStrings)
            .property("aemrtext", &EMRPOLYTEXTOUTA::aemrtext)
            ,
        xlb_class<EMRRESIZEPALETTE>("EMRRESIZEPALETTE") .constructor() .destructor()
            .property("emr", &EMRRESIZEPALETTE::emr)
            .property("ihPal", &EMRRESIZEPALETTE::ihPal)
            .property("cEntries", &EMRRESIZEPALETTE::cEntries)
            ,
        xlb_class<EMRRESTOREDC>("EMRRESTOREDC") .constructor() .destructor()
            .property("emr", &EMRRESTOREDC::emr)
            .property("iRelative", &EMRRESTOREDC::iRelative)
            ,
        xlb_class<EMRROUNDRECT>("EMRROUNDRECT") .constructor() .destructor()
            .property("emr", &EMRROUNDRECT::emr)
            .property("rclBox", &EMRROUNDRECT::rclBox)
            .property("szlCorner", &EMRROUNDRECT::szlCorner)
            ,
        xlb_class<EMRSCALEVIEWPORTEXTEX>("EMRSCALEVIEWPORTEXTEX") .constructor() .destructor()
            .property("emr", &EMRSCALEVIEWPORTEXTEX::emr)
            .property("xNum", &EMRSCALEVIEWPORTEXTEX::xNum)
            .property("xDenom", &EMRSCALEVIEWPORTEXTEX::xDenom)
            .property("yNum", &EMRSCALEVIEWPORTEXTEX::yNum)
            .property("yDenom", &EMRSCALEVIEWPORTEXTEX::yDenom)
            ,
        xlb_class<EMRSELECTCLIPPATH>("EMRSELECTCLIPPATH") .constructor() .destructor()
            .property("emr", &EMRSELECTCLIPPATH::emr)
            .property("iMode", &EMRSELECTCLIPPATH::iMode)
            ,
        xlb_class<EMRSELECTOBJECT>("EMRSELECTOBJECT") .constructor() .destructor()
            .property("emr", &EMRSELECTOBJECT::emr)
            .property("ihObject", &EMRSELECTOBJECT::ihObject)
            ,
        xlb_class<EMRSELECTPALETTE>("EMRSELECTPALETTE") .constructor() .destructor()
            .property("emr", &EMRSELECTPALETTE::emr)
            .property("ihPal", &EMRSELECTPALETTE::ihPal)
            ,
        xlb_class<EMRSETARCDIRECTION>("EMRSETARCDIRECTION") .constructor() .destructor()
            .property("emr", &EMRSETARCDIRECTION::emr)
            .property("iArcDirection", &EMRSETARCDIRECTION::iArcDirection)
            ,
        xlb_class<EMRSETBKCOLOR>("EMRSETBKCOLOR") .constructor() .destructor()
            .property("emr", &EMRSETBKCOLOR::emr)
            .property("crColor", &EMRSETBKCOLOR::crColor)
            ,
        xlb_class<EMRSETCOLORADJUSTMENT>("EMRSETCOLORADJUSTMENT") .constructor() .destructor()
            .property("emr", &EMRSETCOLORADJUSTMENT::emr)
            .property("ColorAdjustment", &EMRSETCOLORADJUSTMENT::ColorAdjustment)
            ,
        xlb_class<EMRSETCOLORSPACE>("EMRSETCOLORSPACE") .constructor() .destructor()
            .property("emr", &EMRSETCOLORSPACE::emr)
            .property("ihCS", &EMRSETCOLORSPACE::ihCS)
            ,
        xlb_class<EMRSETDIBITSTODEVICE>("EMRSETDIBITSTODEVICE") .constructor() .destructor()
            .property("emr", &EMRSETDIBITSTODEVICE::emr)
            .property("rclBounds", &EMRSETDIBITSTODEVICE::rclBounds)
            .property("xDest", &EMRSETDIBITSTODEVICE::xDest)
            .property("yDest", &EMRSETDIBITSTODEVICE::yDest)
            .property("xSrc", &EMRSETDIBITSTODEVICE::xSrc)
            .property("ySrc", &EMRSETDIBITSTODEVICE::ySrc)
            .property("cxSrc", &EMRSETDIBITSTODEVICE::cxSrc)
            .property("cySrc", &EMRSETDIBITSTODEVICE::cySrc)
            .property("offBmiSrc", &EMRSETDIBITSTODEVICE::offBmiSrc)
            .property("cbBmiSrc", &EMRSETDIBITSTODEVICE::cbBmiSrc)
            .property("offBitsSrc", &EMRSETDIBITSTODEVICE::offBitsSrc)
            .property("cbBitsSrc", &EMRSETDIBITSTODEVICE::cbBitsSrc)
            .property("iUsageSrc", &EMRSETDIBITSTODEVICE::iUsageSrc)
            .property("iStartScan", &EMRSETDIBITSTODEVICE::iStartScan)
            .property("cScans", &EMRSETDIBITSTODEVICE::cScans)
            ,
        xlb_class<EMRSETICMPROFILE>("EMRSETICMPROFILE") .constructor() .destructor()
            .property("emr", &EMRSETICMPROFILE::emr)
            .property("dwFlags", &EMRSETICMPROFILE::dwFlags)
            .property("cbName", &EMRSETICMPROFILE::cbName)
            .property("cbData", &EMRSETICMPROFILE::cbData)
            .property("Data", &EMRSETICMPROFILE::Data)
            ,
        xlb_class<EMRSETMAPPERFLAGS>("EMRSETMAPPERFLAGS") .constructor() .destructor()
            .property("emr", &EMRSETICMPROFILE::emr)
            .property("dwFlags", &EMRSETICMPROFILE::dwFlags)
            ,
        xlb_class<EMRSETMITERLIMIT>("EMRSETMITERLIMIT") .constructor() .destructor()
            .property("emr", &EMRSETMITERLIMIT::emr)
            .property("eMiterLimit", &EMRSETMITERLIMIT::eMiterLimit)
            ,
        xlb_class<EMRSETPALETTEENTRIES>("EMRSETPALETTEENTRIES") .constructor() .destructor()
            .property("emr", &EMRSETPALETTEENTRIES::emr)
            .property("ihPal", &EMRSETPALETTEENTRIES::ihPal)
            .property("iStart", &EMRSETPALETTEENTRIES::iStart)
            .property("cEntries", &EMRSETPALETTEENTRIES::cEntries)
            .property("aPalEntries", &EMRSETPALETTEENTRIES::aPalEntries)
            ,
        xlb_class<EMRSETPIXELV>("EMRSETPIXELV") .constructor() .destructor()
            .property("emr", &EMRSETPIXELV::emr)
            .property("ptlPixel", &EMRSETPIXELV::ptlPixel)
            .property("crColor", &EMRSETPIXELV::crColor)
            ,
        xlb_class<EMRSETVIEWPORTEXTEX>("EMRSETVIEWPORTEXTEX") .constructor() .destructor()
            .property("emr", &EMRSETVIEWPORTEXTEX::emr)
            .property("szlExtent", &EMRSETVIEWPORTEXTEX::szlExtent)
            ,
        xlb_class<EMRSETVIEWPORTORGEX>("EMRSETVIEWPORTORGEX") .constructor() .destructor()
            .property("emr", &EMRSETVIEWPORTORGEX::emr)
            .property("ptlOrigin", &EMRSETVIEWPORTORGEX::ptlOrigin)
            ,
        xlb_class<EMRSETWORLDTRANSFORM>("EMRSETWORLDTRANSFORM") .constructor() .destructor()
            .property("emr", &EMRSETWORLDTRANSFORM::emr)
            .property("xform", &EMRSETWORLDTRANSFORM::xform)
            ,
        xlb_class<EMRSTRETCHBLT>("EMRSTRETCHBLT") .constructor() .destructor()
            .property("emr", &EMRSTRETCHBLT::emr)
            .property("rclBounds", &EMRSTRETCHBLT::rclBounds)
            .property("xDest", &EMRSTRETCHBLT::xDest)
            .property("yDest", &EMRSTRETCHBLT::yDest)
            .property("cxDest", &EMRSTRETCHBLT::cxDest)
            .property("cyDest", &EMRSTRETCHBLT::cyDest)
            .property("dwRop", &EMRSTRETCHBLT::dwRop)
            .property("xSrc", &EMRSTRETCHBLT::xSrc)
            .property("ySrc", &EMRSTRETCHBLT::ySrc)
            .property("xformSrc", &EMRSTRETCHBLT::xformSrc)
            .property("crBkColorSrc", &EMRSTRETCHBLT::crBkColorSrc)
            .property("iUsageSrc", &EMRSTRETCHBLT::iUsageSrc)
            .property("offBmiSrc", &EMRSTRETCHBLT::offBmiSrc)
            .property("cbBmiSrc", &EMRSTRETCHBLT::cbBmiSrc)
            .property("offBitsSrc", &EMRSTRETCHBLT::offBitsSrc)
            .property("cbBitsSrc", &EMRSTRETCHBLT::cbBitsSrc)
            .property("cxSrc", &EMRSTRETCHBLT::cxSrc)
            .property("cySrc", &EMRSTRETCHBLT::cySrc)
            ,
        xlb_class<EMRSTRETCHDIBITS>("EMRSTRETCHDIBITS") .constructor() .destructor()
            .property("emr", &EMRSTRETCHDIBITS::emr)
            .property("rclBounds", &EMRSTRETCHDIBITS::rclBounds)
            .property("xDest", &EMRSTRETCHDIBITS::xDest)
            .property("yDest", &EMRSTRETCHDIBITS::yDest)
            .property("xSrc", &EMRSTRETCHDIBITS::xSrc)
            .property("ySrc", &EMRSTRETCHDIBITS::ySrc)
            .property("cxSrc", &EMRSTRETCHDIBITS::cxSrc)
            .property("cySrc", &EMRSTRETCHDIBITS::cySrc)
            .property("offBmiSrc", &EMRSTRETCHDIBITS::offBmiSrc)
            .property("cbBmiSrc", &EMRSTRETCHDIBITS::cbBmiSrc)
            .property("offBitsSrc", &EMRSTRETCHDIBITS::offBitsSrc)
            .property("cbBitsSrc", &EMRSTRETCHDIBITS::cbBitsSrc)
            .property("iUsageSrc", &EMRSTRETCHDIBITS::iUsageSrc)
            .property("dwRop", &EMRSTRETCHDIBITS::dwRop)
            .property("cxDest", &EMRSTRETCHDIBITS::cxDest)
            .property("cyDest", &EMRSTRETCHDIBITS::cyDest)
            ,
        xlb_class<EMRTEXT>("EMRTEXT") .constructor() .destructor()
            .property("ptlReference", &EMRTEXT::ptlReference)
            .property("nChars", &EMRTEXT::nChars)
            .property("offString", &EMRTEXT::offString)
            .property("fOptions", &EMRTEXT::fOptions)
            .property("rcl", &EMRTEXT::rcl)
            .property("offDx", &EMRTEXT::offDx)
            ,
        xlb_class<EMRTRANSPARENTBLT>("EMRTRANSPARENTBLT") .constructor() .destructor()
            .property("emr", &EMRTRANSPARENTBLT::emr)
            .property("rclBounds", &EMRTRANSPARENTBLT::rclBounds)
            .property("xDest", &EMRTRANSPARENTBLT::xDest)
            .property("yDest", &EMRTRANSPARENTBLT::yDest)
            .property("cxDest", &EMRTRANSPARENTBLT::cxDest)
            .property("cyDest", &EMRTRANSPARENTBLT::cyDest)
            .property("dwRop", &EMRTRANSPARENTBLT::dwRop)
            .property("xSrc", &EMRTRANSPARENTBLT::xSrc)
            .property("ySrc", &EMRTRANSPARENTBLT::ySrc)
            .property("xformSrc", &EMRTRANSPARENTBLT::xformSrc)
            .property("crBkColorSrc", &EMRTRANSPARENTBLT::crBkColorSrc)
            .property("iUsageSrc", &EMRTRANSPARENTBLT::iUsageSrc)
            .property("offBmiSrc", &EMRTRANSPARENTBLT::offBmiSrc)
            .property("cbBmiSrc", &EMRTRANSPARENTBLT::cbBmiSrc)
            .property("offBitsSrc", &EMRTRANSPARENTBLT::offBitsSrc)
            .property("cbBitsSrc", &EMRTRANSPARENTBLT::cbBitsSrc)
            .property("cxSrc", &EMRTRANSPARENTBLT::cxSrc)
            .property("cySrc", &EMRTRANSPARENTBLT::cySrc)
            ,
        xlb_class<ENHMETAHEADER>("ENHMETAHEADER") .constructor() .destructor()
            .property("iType", &ENHMETAHEADER::iType)
            .property("nSize", &ENHMETAHEADER::nSize)
            .property("rclBounds", &ENHMETAHEADER::rclBounds)
            .property("rclFrame", &ENHMETAHEADER::rclFrame)
            .property("dSignature", &ENHMETAHEADER::dSignature)
            .property("nVersion", &ENHMETAHEADER::nVersion)
            .property("nBytes", &ENHMETAHEADER::nBytes)
            .property("nRecords", &ENHMETAHEADER::nRecords)
            .property("nHandles", &ENHMETAHEADER::nHandles)
            .property("sReserved", &ENHMETAHEADER::sReserved)
            .property("nDescription", &ENHMETAHEADER::nDescription)
            .property("offDescription", &ENHMETAHEADER::offDescription)
            .property("nPalEntries", &ENHMETAHEADER::nPalEntries)
            .property("szlDevice", &ENHMETAHEADER::szlDevice)
            .property("szlMillimeters", &ENHMETAHEADER::szlMillimeters)
            .property("cbPixelFormat", &ENHMETAHEADER::cbPixelFormat)
            .property("offPixelFormat", &ENHMETAHEADER::offPixelFormat)
            .property("bOpenGL", &ENHMETAHEADER::bOpenGL)
            .property("szlMicrometers", &ENHMETAHEADER::szlMicrometers)
            ,
        xlb_class<ENHMETARECORD>("ENHMETARECORD") .constructor() .destructor()
            .property("iType", &ENHMETARECORD::iType)
            .property("nSize", &ENHMETARECORD::nSize)
            .property("dParm", &ENHMETARECORD::dParm)
            ,
        xlb_class<ENUMLOGFONT>("ENUMLOGFONT") .constructor() .destructor()
            .property("elfLogFont", &ENUMLOGFONT::elfLogFont)
            .property("elfFullName", &ENUMLOGFONT::elfFullName)
            .property("elfStyle", &ENUMLOGFONT::elfStyle)
            ,
        xlb_class<ENUMLOGFONTEX>("ENUMLOGFONTEX") .constructor() .destructor()
            .property("elfLogFont", &ENUMLOGFONTEX::elfLogFont)
            .property("elfFullName", &ENUMLOGFONTEX::elfFullName)
            .property("elfStyle", &ENUMLOGFONTEX::elfStyle)
            .property("elfScript", &ENUMLOGFONTEX::elfScript)
            ,
        xlb_class<ENUMLOGFONTEXDV>("ENUMLOGFONTEXDV") .constructor() .destructor()
            .property("elfEnumLogfontEx", &ENUMLOGFONTEXDV::elfEnumLogfontEx)
            .property("elfDesignVector", &ENUMLOGFONTEXDV::elfDesignVector)
            ,
        xlb_class<ENUMTEXTMETRIC>("ENUMTEXTMETRIC") .constructor() .destructor()
            .property("etmNewTextMetricEx", &ENUMTEXTMETRIC::etmNewTextMetricEx)
            .property("etmAxesList", &ENUMTEXTMETRIC::etmAxesList)
            ,
        xlb_class<EXTLOGFONT>("EXTLOGFONT") .constructor() .destructor()
            .property("elfLogFont", &EXTLOGFONT::elfLogFont)
            .property("elfFullName", &EXTLOGFONT::elfFullName)
            .property("elfStyle", &EXTLOGFONT::elfStyle)
            .property("elfVersion", &EXTLOGFONT::elfVersion)
            .property("elfStyleSize", &EXTLOGFONT::elfStyleSize)
            .property("elfMatch", &EXTLOGFONT::elfMatch)
            .property("elfReserved", &EXTLOGFONT::elfReserved)
            .property("elfVendorId", &EXTLOGFONT::elfVendorId)
            .property("elfCulture", &EXTLOGFONT::elfCulture)
            .property("elfPanose", &EXTLOGFONT::elfPanose)
            ,
        xlb_class<EXTLOGPEN>("EXTLOGPEN") .constructor() .destructor()
            .property("elpPenStyle", &EXTLOGPEN::elpPenStyle)
            .property("elpWidth", &EXTLOGPEN::elpWidth)
            .property("elpBrushStyle", &EXTLOGPEN::elpBrushStyle)
            .property("elpColor", &EXTLOGPEN::elpColor)
            .property("elpHatch", &EXTLOGPEN::elpHatch)
            .property("elpNumEntries", &EXTLOGPEN::elpNumEntries)
            .property("elpStyleEntry", &EXTLOGPEN::elpStyleEntry)
            ,
        xlb_class<FIXED>("FIXED") .constructor() .destructor()
            .property("fract", &FIXED::fract)
            .property("value", &FIXED::value)
            ,
        xlb_class<GCP_RESULTS>("GCP_RESULTS") .constructor() .destructor()
            .property("lStructSize", &GCP_RESULTS::lStructSize)
            .property("lpOutString", &GCP_RESULTS::lpOutString)
            .property("lpOrder", &GCP_RESULTS::lpOrder)
            .property("lpDx", &GCP_RESULTS::lpDx)
            .property("lpCaretPos", &GCP_RESULTS::lpCaretPos)
            .property("lpClass", &GCP_RESULTS::lpClass)
            .property("lpGlyphs", &GCP_RESULTS::lpGlyphs)
            .property("nGlyphs", &GCP_RESULTS::nGlyphs)
            .property("nMaxFit", &GCP_RESULTS::nMaxFit)
            ,
        xlb_class<GLYPHMETRICS>("GLYPHMETRICS") .constructor() .destructor()
            .property("gmBlackBoxX", &GLYPHMETRICS::gmBlackBoxX)
            .property("gmBlackBoxY", &GLYPHMETRICS::gmBlackBoxY)
            .property("gmptGlyphOrigin", &GLYPHMETRICS::gmptGlyphOrigin)
            .property("gmCellIncX", &GLYPHMETRICS::gmCellIncX)
            .property("gmCellIncY", &GLYPHMETRICS::gmCellIncY)
            ,
        xlb_class<GLYPHSET>("GLYPHSET") .constructor() .destructor()
            .property("cbThis", &GLYPHSET::cbThis)
            .property("flAccel", &GLYPHSET::flAccel)
            .property("cGlyphsSupported", &GLYPHSET::cGlyphsSupported)
            .property("cRanges", &GLYPHSET::cRanges)
            .property("ranges", &GLYPHSET::ranges)
            ,
        xlb_class<GRADIENT_RECT>("GRADIENT_RECT") .constructor() .destructor()
            .property("UpperLeft", &GRADIENT_RECT::UpperLeft)
            .property("LowerRight", &GRADIENT_RECT::LowerRight)
            ,
        xlb_class<GRADIENT_TRIANGLE>("GRADIENT_TRIANGLE") .constructor() .destructor()
            .property("Vertex1", &GRADIENT_TRIANGLE::Vertex1)
            .property("Vertex2", &GRADIENT_TRIANGLE::Vertex2)
            .property("Vertex3", &GRADIENT_TRIANGLE::Vertex3)
            ,
        xlb_class<HANDLETABLE>("HANDLETABLE") .constructor() .destructor()
            .property("objectHandle", &HANDLETABLE::objectHandle)
            ,
        xlb_class<KERNINGPAIR>("KERNINGPAIR") .constructor() .destructor()
            .property("wFirst", &KERNINGPAIR::wFirst)
            .property("wSecond", &KERNINGPAIR::wSecond)
            .property("iKernAmount", &KERNINGPAIR::iKernAmount)
            ,
        xlb_class<LOGBRUSH>("LOGBRUSH") .constructor() .destructor()
            .property("lbStyle", &LOGBRUSH::lbStyle)
            .property("lbColor", &LOGBRUSH::lbColor)
            .property("lbHatch", &LOGBRUSH::lbHatch)
            ,
        xlb_class<LOGBRUSH32>("LOGBRUSH32") .constructor() .destructor()
            .property("lbStyle", &LOGBRUSH32::lbStyle)
            .property("lbColor", &LOGBRUSH32::lbColor)
            .property("lbHatch", &LOGBRUSH32::lbHatch)
            ,
        xlb_class<LOGFONT>("LOGFONT") .constructor() .destructor()
            .property("lfHeight", &LOGFONT::lfHeight)
            .property("lfWidth", &LOGFONT::lfWidth)
            .property("lfEscapement", &LOGFONT::lfEscapement)
            .property("lfOrientation", &LOGFONT::lfOrientation)
            .property("lfWeight", &LOGFONT::lfWeight)
            .property("lfItalic", &LOGFONT::lfItalic)
            .property("lfUnderline", &LOGFONT::lfUnderline)
            .property("lfStrikeOut", &LOGFONT::lfStrikeOut)
            .property("lfCharSet", &LOGFONT::lfCharSet)
            .property("lfOutPrecision", &LOGFONT::lfOutPrecision)
            .property("lfClipPrecision", &LOGFONT::lfClipPrecision)
            .property("lfQuality", &LOGFONT::lfQuality)
            .property("lfPitchAndFamily", &LOGFONT::lfPitchAndFamily)
            .property("lfFaceName", &LOGFONT::lfFaceName)
            ,
        xlb_class<LOGPALETTE>("LOGPALETTE") .constructor() .destructor()
            .property("palVersion", &LOGPALETTE::palVersion)
            .property("palNumEntries", &LOGPALETTE::palNumEntries)
            .property("palPalEntry", &LOGPALETTE::palPalEntry)
            ,
        xlb_class<LOGPEN>("LOGPEN") .constructor() .destructor()
            .property("lopnStyle", &LOGPEN::lopnStyle)
            .property("lopnWidth", &LOGPEN::lopnWidth)
            .property("lopnColor", &LOGPEN::lopnColor)
            ,
        xlb_class<MAT2>("MAT2") .constructor() .destructor()
            .property("eM11", &MAT2::eM11)
            .property("eM12", &MAT2::eM12)
            .property("eM21", &MAT2::eM21)
            .property("eM22", &MAT2::eM22)
            ,
        xlb_class<METAHEADER>("METAHEADER") .constructor() .destructor()
            .property("mtType", &METAHEADER::mtType)
            .property("mtHeaderSize", &METAHEADER::mtHeaderSize)
            .property("mtVersion", &METAHEADER::mtVersion)
            .property("mtSize", &METAHEADER::mtSize)
            .property("mtNoObjects", &METAHEADER::mtNoObjects)
            .property("mtMaxRecord", &METAHEADER::mtMaxRecord)
            .property("mtNoParameters", &METAHEADER::mtNoParameters)
            ,
        xlb_class<METARECORD>("METARECORD") .constructor() .destructor()
            .property("rdSize", &METARECORD::rdSize)
            .property("rdFunction", &METARECORD::rdFunction)
            .property("rdParm", &METARECORD::rdParm)
            ,
        xlb_class<MONITORINFO>("MONITORINFO") .constructor() .destructor()
            .property("cbSize", &MONITORINFO::cbSize)
            .property("rcMonitor", &MONITORINFO::rcMonitor)
            .property("rcWork", &MONITORINFO::rcWork)
            .property("dwFlags", &MONITORINFO::dwFlags)
            ,
        xlb_class<MONITORINFOEX>("MONITORINFOEX") .constructor() .destructor()
            .inherited<MONITORINFO>()
            .property("szDevice", &MONITORINFOEX::szDevice)
            //.property("tagMONITORINFO", &MONITORINFOEX::tagMONITORINFO)
            ,
        xlb_class<NEWTEXTMETRIC>("NEWTEXTMETRIC") .constructor() .destructor()
            .property("tmHeight", &NEWTEXTMETRIC::tmHeight)
            .property("tmAscent", &NEWTEXTMETRIC::tmAscent)
            .property("tmDescent", &NEWTEXTMETRIC::tmDescent)
            .property("tmInternalLeading", &NEWTEXTMETRIC::tmInternalLeading)
            .property("tmExternalLeading", &NEWTEXTMETRIC::tmExternalLeading)
            .property("tmAveCharWidth", &NEWTEXTMETRIC::tmAveCharWidth)
            .property("tmMaxCharWidth", &NEWTEXTMETRIC::tmMaxCharWidth)
            .property("tmWeight", &NEWTEXTMETRIC::tmWeight)
            .property("tmOverhang", &NEWTEXTMETRIC::tmOverhang)
            .property("tmDigitizedAspectX", &NEWTEXTMETRIC::tmDigitizedAspectX)
            .property("tmDigitizedAspectY", &NEWTEXTMETRIC::tmDigitizedAspectY)
            .property("tmFirstChar", &NEWTEXTMETRIC::tmFirstChar)
            .property("tmLastChar", &NEWTEXTMETRIC::tmLastChar)
            .property("tmDefaultChar", &NEWTEXTMETRIC::tmDefaultChar)
            .property("tmBreakChar", &NEWTEXTMETRIC::tmBreakChar)
            .property("tmItalic", &NEWTEXTMETRIC::tmItalic)
            .property("tmUnderlined", &NEWTEXTMETRIC::tmUnderlined)
            .property("tmStruckOut", &NEWTEXTMETRIC::tmStruckOut)
            .property("tmPitchAndFamily", &NEWTEXTMETRIC::tmPitchAndFamily)
            .property("tmCharSet", &NEWTEXTMETRIC::tmCharSet)
            .property("ntmFlags", &NEWTEXTMETRIC::ntmFlags)
            .property("ntmSizeEM", &NEWTEXTMETRIC::ntmSizeEM)
            .property("ntmCellHeight", &NEWTEXTMETRIC::ntmCellHeight)
            .property("ntmAvgWidth", &NEWTEXTMETRIC::ntmAvgWidth)
            ,
        xlb_class<NEWTEXTMETRICEX>("NEWTEXTMETRICEX") .constructor() .destructor()
            .property("ntmTm", &NEWTEXTMETRICEX::ntmTm)
            .property("ntmFontSig", &NEWTEXTMETRICEX::ntmFontSig)
            ,
        xlb_class<OUTLINETEXTMETRIC>("OUTLINETEXTMETRIC") .constructor() .destructor()
            .property("otmSize", &OUTLINETEXTMETRIC::otmSize)
            .property("otmTextMetrics", &OUTLINETEXTMETRIC::otmTextMetrics)
            .property("otmFiller", &OUTLINETEXTMETRIC::otmFiller)
            .property("otmPanoseNumber", &OUTLINETEXTMETRIC::otmPanoseNumber)
            .property("otmfsSelection", &OUTLINETEXTMETRIC::otmfsSelection)
            .property("otmfsType", &OUTLINETEXTMETRIC::otmfsType)
            .property("otmsCharSlopeRise", &OUTLINETEXTMETRIC::otmsCharSlopeRise)
            .property("otmsCharSlopeRun", &OUTLINETEXTMETRIC::otmsCharSlopeRun)
            .property("otmItalicAngle", &OUTLINETEXTMETRIC::otmItalicAngle)
            .property("otmEMSquare", &OUTLINETEXTMETRIC::otmEMSquare)
            .property("otmAscent", &OUTLINETEXTMETRIC::otmAscent)
            .property("otmDescent", &OUTLINETEXTMETRIC::otmDescent)
            .property("otmLineGap", &OUTLINETEXTMETRIC::otmLineGap)
            .property("otmsCapEmHeight", &OUTLINETEXTMETRIC::otmsCapEmHeight)
            .property("otmsXHeight", &OUTLINETEXTMETRIC::otmsXHeight)
            .property("otmrcFontBox", &OUTLINETEXTMETRIC::otmrcFontBox)
            .property("otmMacAscent", &OUTLINETEXTMETRIC::otmMacAscent)
            .property("otmMacDescent", &OUTLINETEXTMETRIC::otmMacDescent)
            .property("otmMacLineGap", &OUTLINETEXTMETRIC::otmMacLineGap)
            .property("otmusMinimumPPEM", &OUTLINETEXTMETRIC::otmusMinimumPPEM)
            .property("otmptSubscriptSize", &OUTLINETEXTMETRIC::otmptSubscriptSize)
            .property("otmptSubscriptOffset", &OUTLINETEXTMETRIC::otmptSubscriptOffset)
            .property("otmptSuperscriptSize", &OUTLINETEXTMETRIC::otmptSuperscriptSize)
            .property("otmptSuperscriptOffset", &OUTLINETEXTMETRIC::otmptSuperscriptOffset)
            .property("otmsStrikeoutSize", &OUTLINETEXTMETRIC::otmsStrikeoutSize)
            .property("otmsStrikeoutPosition", &OUTLINETEXTMETRIC::otmsStrikeoutPosition)
            .property("otmsUnderscoreSize", &OUTLINETEXTMETRIC::otmsUnderscoreSize)
            .property("otmsUnderscorePosition", &OUTLINETEXTMETRIC::otmsUnderscorePosition)
            .property("otmpFamilyName", &OUTLINETEXTMETRIC::otmpFamilyName)
            .property("otmpFaceName", &OUTLINETEXTMETRIC::otmpFaceName)
            .property("otmpStyleName", &OUTLINETEXTMETRIC::otmpStyleName)
            .property("otmpFullName", &OUTLINETEXTMETRIC::otmpFullName)
            ,
        xlb_class<PAINTSTRUCT>("PAINTSTRUCT") .constructor() .destructor()
            .property("hdc", &PAINTSTRUCT::hdc)
            .property("fErase", &PAINTSTRUCT::fErase)
            .property("rcPaint", &PAINTSTRUCT::rcPaint)
            .property("fRestore", &PAINTSTRUCT::fRestore)
            .property("fIncUpdate", &PAINTSTRUCT::fIncUpdate)
            .property("rgbReserved", &PAINTSTRUCT::rgbReserved)
            ,
        xlb_class<PANOSE>("PANOSE") .constructor() .destructor()
            .property("bFamilyType", &PANOSE::bFamilyType)
            .property("bSerifStyle", &PANOSE::bSerifStyle)
            .property("bWeight", &PANOSE::bWeight)
            .property("bProportion", &PANOSE::bProportion)
            .property("bContrast", &PANOSE::bContrast)
            .property("bStrokeVariation", &PANOSE::bStrokeVariation)
            .property("bArmStyle", &PANOSE::bArmStyle)
            .property("bLetterform", &PANOSE::bLetterform)
            .property("bMidline", &PANOSE::bMidline)
            .property("bXHeight", &PANOSE::bXHeight)
            ,
        xlb_class<POINTFX>("POINTFX") .constructor() .destructor()
            .property("x", &POINTFX::x)
            .property("y", &POINTFX::y)
            ,
        xlb_class<POLYTEXTA>("POLYTEXTA") .constructor() .destructor()
            .property("x", &POLYTEXTA::x)
            .property("y", &POLYTEXTA::y)
            .property("n", &POLYTEXTA::n)
            .property("lpstr", &POLYTEXTA::lpstr)
            .property("uiFlags", &POLYTEXTA::uiFlags)
            .property("rcl", &POLYTEXTA::rcl)
            .property("pdx", &POLYTEXTA::pdx)
            ,
        xlb_class<RASTERIZER_STATUS>("RASTERIZER_STATUS") .constructor() .destructor()
            .property("nSize", &RASTERIZER_STATUS::nSize)
            .property("wFlags", &RASTERIZER_STATUS::wFlags)
            .property("nLanguageID", &RASTERIZER_STATUS::nLanguageID)
            ,
        xlb_class<RGBQUAD>("RGBQUAD") .constructor() .destructor()
            .property("rgbBlue", &RGBQUAD::rgbBlue)
            .property("rgbGreen", &RGBQUAD::rgbGreen)
            .property("rgbRed", &RGBQUAD::rgbRed)
            .property("rgbReserved", &RGBQUAD::rgbReserved)
            ,
        xlb_class<RGBTRIPLE>("RGBTRIPLE") .constructor() .destructor()
            .property("rgbtBlue", &RGBTRIPLE::rgbtBlue)
            .property("rgbtGreen", &RGBTRIPLE::rgbtGreen)
            .property("rgbtRed", &RGBTRIPLE::rgbtRed)
            ,
        xlb_class<RGNDATA>("RGNDATA") .constructor() .destructor()
            .property("rdh", &RGNDATA::rdh)
            .property("Buffer", &RGNDATA::Buffer)
            ,
        xlb_class<RGNDATAHEADER>("RGNDATAHEADER") .constructor() .destructor()
            .property("dwSize", &RGNDATAHEADER::dwSize)
            .property("iType", &RGNDATAHEADER::iType)
            .property("nCount", &RGNDATAHEADER::nCount)
            .property("nRgnSize", &RGNDATAHEADER::nRgnSize)
            .property("rcBound", &RGNDATAHEADER::rcBound)
            ,
        xlb_class<TEXTMETRIC>("TEXTMETRIC") .constructor() .destructor()
            .property("tmHeight", &TEXTMETRIC::tmHeight)
            .property("tmAscent", &TEXTMETRIC::tmAscent)
            .property("tmDescent", &TEXTMETRIC::tmDescent)
            .property("tmInternalLeading", &TEXTMETRIC::tmInternalLeading)
            .property("tmExternalLeading", &TEXTMETRIC::tmExternalLeading)
            .property("tmAveCharWidth", &TEXTMETRIC::tmAveCharWidth)
            .property("tmMaxCharWidth", &TEXTMETRIC::tmMaxCharWidth)
            .property("tmWeight", &TEXTMETRIC::tmWeight)
            .property("tmOverhang", &TEXTMETRIC::tmOverhang)
            .property("tmDigitizedAspectX", &TEXTMETRIC::tmDigitizedAspectX)
            .property("tmDigitizedAspectY", &TEXTMETRIC::tmDigitizedAspectY)
            .property("tmFirstChar", &TEXTMETRIC::tmFirstChar)
            .property("tmLastChar", &TEXTMETRIC::tmLastChar)
            .property("tmDefaultChar", &TEXTMETRIC::tmDefaultChar)
            .property("tmBreakChar", &TEXTMETRIC::tmBreakChar)
            .property("tmItalic", &TEXTMETRIC::tmItalic)
            .property("tmUnderlined", &TEXTMETRIC::tmUnderlined)
            .property("tmStruckOut", &TEXTMETRIC::tmStruckOut)
            .property("tmPitchAndFamily", &TEXTMETRIC::tmPitchAndFamily)
            .property("tmCharSet", &TEXTMETRIC::tmCharSet)
            ,
        xlb_class<TRIVERTEX>("TRIVERTEX") .constructor() .destructor()
            .property("x", &TRIVERTEX::x)
            .property("y", &TRIVERTEX::y)
            .property("Red", &TRIVERTEX::Red)
            .property("Green", &TRIVERTEX::Green)
            .property("Blue", &TRIVERTEX::Blue)
            .property("Alpha", &TRIVERTEX::Alpha)
            ,
        xlb_class<TTEMBEDINFO>("TTEMBEDINFO") .constructor() .destructor()
            .property("usStructSize", &TTEMBEDINFO::usStructSize)
            .property("usRootStrSize", &TTEMBEDINFO::usRootStrSize)
            .property("pusRootStr", &TTEMBEDINFO::pusRootStr)
            ,
        xlb_class<TTLOADINFO>("TTLOADINFO") .constructor() .destructor()
            .property("usStructSize", &TTLOADINFO::usStructSize)
            .property("usRefStrSize", &TTLOADINFO::usRefStrSize)
            .property("pusRefStr", &TTLOADINFO::pusRefStr)
            ,
        xlb_class<TTPOLYCURVE>("TTPOLYCURVE") .constructor() .destructor()
            .property("wType", &TTPOLYCURVE::wType)
            .property("cpfx", &TTPOLYCURVE::cpfx)
            .property("apfx", &TTPOLYCURVE::apfx)
            ,
        xlb_class<TTPOLYGONHEADER>("TTPOLYGONHEADER") .constructor() .destructor()
            .property("cb", &TTPOLYGONHEADER::cb)
            .property("dwType", &TTPOLYGONHEADER::dwType)
            .property("pfxStart", &TTPOLYGONHEADER::pfxStart)
            ,
        xlb_class<TTVALIDATIONTESTSPARAMS>("TTVALIDATIONTESTSPARAMS") .constructor() .destructor()
            .property("ulStructSize", &TTVALIDATIONTESTSPARAMS::ulStructSize)
            .property("lTestFromSize", &TTVALIDATIONTESTSPARAMS::lTestFromSize)
            .property("lTestToSize", &TTVALIDATIONTESTSPARAMS::lTestToSize)
            .property("ulCharSet", &TTVALIDATIONTESTSPARAMS::ulCharSet)
            .property("usReserved1", &TTVALIDATIONTESTSPARAMS::usReserved1)
            .property("usCharCodeCount", &TTVALIDATIONTESTSPARAMS::usCharCodeCount)
            .property("pusCharCodeSet", &TTVALIDATIONTESTSPARAMS::pusCharCodeSet)
            ,
        xlb_class<TTVALIDATIONTESTSPARAMSEX>("TTVALIDATIONTESTSPARAMSEX") .constructor() .destructor()
            .property("ulStructSize", &TTVALIDATIONTESTSPARAMSEX::ulStructSize)
            .property("lTestFromSize", &TTVALIDATIONTESTSPARAMSEX::lTestFromSize)
            .property("lTestToSize", &TTVALIDATIONTESTSPARAMSEX::lTestToSize)
            .property("ulCharSet", &TTVALIDATIONTESTSPARAMSEX::ulCharSet)
            .property("usReserved1", &TTVALIDATIONTESTSPARAMSEX::usReserved1)
            .property("usCharCodeCount", &TTVALIDATIONTESTSPARAMSEX::usCharCodeCount)
            .property("pulCharCodeSet", &TTVALIDATIONTESTSPARAMSEX::pulCharCodeSet)
            ,
        xlb_class<WCRANGE>("WCRANGE") .constructor() .destructor()
            .property("wcLow", &WCRANGE::wcLow)
            .property("cGlyphs", &WCRANGE::cGlyphs)
            ,
        xlb_class<XFORM>("XFORM") .constructor() .destructor()
            .property("eM11", &XFORM::eM11)
            .property("eM12", &XFORM::eM12)
            .property("eM21", &XFORM::eM21)
            .property("eM22", &XFORM::eM22)
            .property("eDx", &XFORM::eDx)
            .property("eDy", &XFORM::eDy)
            ,
        xlb_const("CHECK_BIND_GDI", BIND_WIN_CHECKED)
    });
#endif // defined(CHECK_BIND_GDI)

    return 0;
}


//-----------------------------------------------------------------------------
int load_snmp(lua_State* L)
{
#if defined(CHECK_BIND_SNMP)

    xlb_module(L, MODULE_NAME) ({
            xlb_class<xlb_cbf<SNMPAPI_CALLBACK>>("SNMPAPI_CALLBACK").constructor<xlb_luafunc>(),
            xlb_f("SnmpCancelMsg", SnmpCancelMsg),
            xlb_f("SnmpCleanup", SnmpCleanup),
            xlb_f("SnmpCleanupEx", SnmpCleanupEx),
            xlb_f("SnmpClose", SnmpClose),
            xlb_f("SnmpContextToStr", SnmpContextToStr),
            xlb_f("SnmpCountVbl", SnmpCountVbl),
            xlb_f("SnmpCreatePdu", SnmpCreatePdu),
            xlb_f("SnmpCreateSession", SnmpCreateSession),
            xlb_f("SnmpCreateVbl", SnmpCreateVbl),
            xlb_f("SnmpDecodeMsg", SnmpDecodeMsg),
            xlb_f("SnmpDeleteVb", SnmpDeleteVb),
            xlb_f("SnmpDuplicatePdu", SnmpDuplicatePdu),
            xlb_f("SnmpDuplicateVbl", SnmpDuplicateVbl),
            xlb_f("SnmpEncodeMsg", SnmpEncodeMsg),
            xlb_f("SnmpEntityToStr", SnmpEntityToStr),
            //xlb_f("SnmpExtensionClose", SnmpExtensionClose),
            //xlb_f("SnmpExtensionInit", SnmpExtensionInit),
            //xlb_f("SnmpExtensionInitEx", SnmpExtensionInitEx),
            //xlb_f("SnmpExtensionMonitor", SnmpExtensionMonitor),
            //xlb_f("SnmpExtensionQuery", SnmpExtensionQuery),
            //xlb_f("SnmpExtensionQueryEx", SnmpExtensionQueryEx),
            //xlb_f("SnmpExtensionTrap", SnmpExtensionTrap),
            xlb_f("SnmpFreeContext", SnmpFreeContext),
            xlb_f("SnmpFreeDescriptor", SnmpFreeDescriptor),
            xlb_f("SnmpFreeEntity", SnmpFreeEntity),
            xlb_f("SnmpFreePdu", SnmpFreePdu),
            xlb_f("SnmpFreeVbl", SnmpFreeVbl),
            xlb_f("SnmpGetLastError", SnmpGetLastError),
            xlb_f("SnmpGetPduData", SnmpGetPduData),
            xlb_f("SnmpGetRetransmitMode", SnmpGetRetransmitMode),
            xlb_f("SnmpGetRetry", SnmpGetRetry),
            xlb_f("SnmpGetTimeout", SnmpGetTimeout),
            xlb_f("SnmpGetTranslateMode", SnmpGetTranslateMode),
            xlb_f("SnmpGetVb", SnmpGetVb),
            xlb_f("SnmpGetVendorInfo", SnmpGetVendorInfo),
            xlb_f("SnmpListen", SnmpListen),
            xlb_f("SnmpMgrClose", SnmpMgrClose),
            xlb_f("SnmpMgrCtl", SnmpMgrCtl),
            xlb_f("SnmpMgrGetTrap", SnmpMgrGetTrap),
            xlb_f("SnmpMgrGetTrapEx", SnmpMgrGetTrapEx),
            xlb_f("SnmpMgrOidToStr", SnmpMgrOidToStr),
            xlb_f("SnmpMgrOpen", SnmpMgrOpen),
            xlb_f("SnmpMgrRequest", SnmpMgrRequest),
            xlb_f("SnmpMgrStrToOid", SnmpMgrStrToOid),
            xlb_f("SnmpMgrTrapListen", SnmpMgrTrapListen),
            xlb_f("SnmpOidCompare", SnmpOidCompare),
            xlb_f("SnmpOidCopy", SnmpOidCopy),
            xlb_f("SnmpOidToStr", SnmpOidToStr),
            xlb_f("SnmpOpen", SnmpOpen),
            xlb_f("SnmpRecvMsg", SnmpRecvMsg),
            xlb_f("SnmpRegister", SnmpRegister),
            xlb_f("SnmpSendMsg", SnmpSendMsg),
            xlb_f("SnmpSetPduData", SnmpSetPduData),
            xlb_f("SnmpSetPort", SnmpSetPort),
            xlb_f("SnmpSetRetransmitMode", SnmpSetRetransmitMode),
            xlb_f("SnmpSetRetry", SnmpSetRetry),
            xlb_f("SnmpSetTimeout", SnmpSetTimeout),
            xlb_f("SnmpSetTranslateMode", SnmpSetTranslateMode),
            xlb_f("SnmpSetVb", SnmpSetVb),
            xlb_f("SnmpStartup", SnmpStartup),
            xlb_f("SnmpStartupEx", SnmpStartupEx),
            xlb_f("SnmpStrToContext", SnmpStrToContext),
            xlb_f("SnmpStrToEntity", SnmpStrToEntity),
            xlb_f("SnmpStrToOid", SnmpStrToOid),
            xlb_f("SnmpSvcGetUptime", SnmpSvcGetUptime),
            xlb_f("SnmpSvcSetLogLevel", SnmpSvcSetLogLevel),
            xlb_f("SnmpSvcSetLogType", SnmpSvcSetLogType),
            xlb_f("SnmpUtilAsnAnyCpy", SnmpUtilAsnAnyCpy),
            xlb_f("SnmpUtilAsnAnyFree", SnmpUtilAsnAnyFree),
            //xlb_f("SnmpUtilDbgPrint", SnmpUtilDbgPrint), // ...
            xlb_f("SnmpUtilIdsTo", SnmpUtilIdsTo),
            xlb_f("SnmpUtilMemAlloc", SnmpUtilMemAlloc),
            xlb_f("SnmpUtilMemFree", SnmpUtilMemFree),
            xlb_f("SnmpUtilMemReAlloc", SnmpUtilMemReAlloc),
            xlb_f("SnmpUtilOctetsCmp", SnmpUtilOctetsCmp),
            xlb_f("SnmpUtilOctetsCpy", SnmpUtilOctetsCpy),
            xlb_f("SnmpUtilOctetsFree", SnmpUtilOctetsFree),
            xlb_f("SnmpUtilOctetsNCmp", SnmpUtilOctetsNCmp),
            xlb_f("SnmpUtilOidAppend", SnmpUtilOidAppend),
            xlb_f("SnmpUtilOidCmp", SnmpUtilOidCmp),
            xlb_f("SnmpUtilOidCpy", SnmpUtilOidCpy),
            xlb_f("SnmpUtilOidFree", SnmpUtilOidFree),
            xlb_f("SnmpUtilOidNCmp", SnmpUtilOidNCmp),
            xlb_f("SnmpUtilOidTo", SnmpUtilOidTo),
            xlb_f("SnmpUtilPrintAsnAny", SnmpUtilPrintAsnAny),
            xlb_f("SnmpUtilPrintOid", SnmpUtilPrintOid),
            xlb_f("SnmpUtilVarBindCpy", SnmpUtilVarBindCpy),
            xlb_f("SnmpUtilVarBindFree", SnmpUtilVarBindFree),
            xlb_f("SnmpUtilVarBindListCpy", SnmpUtilVarBindListCpy),
            xlb_f("SnmpUtilVarBindListFree", SnmpUtilVarBindListFree),
            xlb_class<AsnAny>("AsnAny") .constructor<>() .destructor()
                .property("asnType", &AsnAny::asnType)
                .property("asnValue", &AsnAny::asnValue),
            xlb_class<decltype(AsnAny::asnValue)>("AsnAny::asnValue") .constructor<>() .destructor()
                .property("unsigned32", &decltype(AsnAny::asnValue)::unsigned32)
                .property("counter64", &decltype(AsnAny::asnValue)::counter64)
                .property("string", &decltype(AsnAny::asnValue)::string)
                .property("bits", &decltype(AsnAny::asnValue)::bits)
                .property("object", &decltype(AsnAny::asnValue)::object)
                .property("sequence", &decltype(AsnAny::asnValue)::sequence)
                .property("address", &decltype(AsnAny::asnValue)::address)
                .property("counter", &decltype(AsnAny::asnValue)::counter)
                .property("gauge", &decltype(AsnAny::asnValue)::gauge)
                .property("ticks", &decltype(AsnAny::asnValue)::ticks)
                .property("arbitrary", &decltype(AsnAny::asnValue)::arbitrary),
            xlb_class<AsnObjectIdentifier>("AsnObjectIdentifier") .constructor<>() .destructor()
                .property("idLength", &AsnObjectIdentifier::idLength)
                .property("ids", &AsnObjectIdentifier::ids)
                ,
            xlb_class<AsnOctetString>("AsnOctetString") .constructor<>() .destructor()
                .property("stream", &AsnOctetString::stream)
                .property("length", &AsnOctetString::length)
                .property("dynamic", &AsnOctetString::dynamic)
                ,
            xlb_class<smiCNTR64>("smiCNTR64") .constructor<>() .destructor()
                .property("hipart", &smiCNTR64::hipart)
                .property("lopart", &smiCNTR64::lopart)
                ,
            xlb_class<smiOCTETS>("smiOCTETS") .constructor<>() .destructor()
                .property("len", &smiOCTETS::len)
                .property("ptr", &smiOCTETS::ptr)
                ,
            xlb_class<smiOID>("smiOID") .constructor<>() .destructor()
                .property("len", &smiOID::len)
                .property("ptr", &smiOID::ptr)
                ,
            xlb_class<smiVALUE>("smiVALUE") .constructor<>() .destructor()
                .property("syntax", &smiVALUE::syntax)
                .property("value", &smiVALUE::value)
                ,
            xlb_class<decltype(smiVALUE::value)>("smiVALUE::value") .constructor<>() .destructor()
                .property("sNumber", &decltype(smiVALUE::value)::sNumber)
                .property("uNumber", &decltype(smiVALUE::value)::uNumber)
                .property("hNumber", &decltype(smiVALUE::value)::hNumber)
                .property("string", &decltype(smiVALUE::value)::string)
                .property("oid", &decltype(smiVALUE::value)::oid)
                .property("empty", &decltype(smiVALUE::value)::empty)
                ,
            xlb_class<smiVENDORINFO>("smiVENDORINFO") .constructor<>() .destructor()
                .property("vendorName", &smiVENDORINFO::vendorName)
                .property("vendorContact", &smiVENDORINFO::vendorContact)
                .property("vendorVersionId", &smiVENDORINFO::vendorVersionId)
                .property("vendorVersionDate", &smiVENDORINFO::vendorVersionDate)
                .property("vendorEnterprise", &smiVENDORINFO::vendorEnterprise)
                ,
            xlb_class<SnmpVarBind>("SnmpVarBind") .constructor<>() .destructor()
                .property("name", &SnmpVarBind::name)
                .property("value", &SnmpVarBind::value)
                ,
            xlb_class<SnmpVarBindList>("SnmpVarBindList") .constructor<>() .destructor()
                .property("list", &SnmpVarBindList::list)
                .property("len", &SnmpVarBindList::len)
                ,
#ifdef compile
#endif
            xlb_const("CHECK_BIND_SNMP", BIND_WIN_CHECKED)
    });
#endif // defined(CHECK_BIND_SNMP)

    return 0;
}

//-----------------------------------------------------------------------------
int load_base(lua_State* L)
{
    xlb_module(L, MODULE_NAME) ({
            xlb_const("WINVER", WINVER),
            xlb_f("VERSION", lua_win_api_version),
            xlb_f("type", xlb_type),
            xlb_f("malloc", malloc),
            xlb_f("free", free),
            xlb_f("realloc", realloc),

            xlb_f("_lclose", _lclose),
            xlb_f("_lcreat", _lcreat),
            xlb_f("_llseek", _llseek),
            xlb_f("_lopen", _lopen),
            xlb_f("_lread", _lread),
            xlb_f("_lwrite", _lwrite),
            xlb_f("AccessCheckAndAuditAlarm", AccessCheckAndAuditAlarm),
            xlb_f("AccessCheckByTypeAndAuditAlarm", AccessCheckByTypeAndAuditAlarm),
            xlb_f("AccessCheckByTypeResultListAndAuditAlarm", AccessCheckByTypeResultListAndAuditAlarm),
            xlb_f("AccessCheckByTypeResultListAndAuditAlarmByHandle", AccessCheckByTypeResultListAndAuditAlarmByHandle),
            xlb_f("ActivateActCtx", ActivateActCtx),
            xlb_f("AddAtom", AddAtom),
            xlb_f("AddConditionalAce", AddConditionalAce),
            xlb_f("AddIntegrityLabelToBoundaryDescriptor", AddIntegrityLabelToBoundaryDescriptor),
            xlb_f("AddRefActCtx", AddRefActCtx),
            xlb_f("AddSecureMemoryCacheCallback", AddSecureMemoryCacheCallback),
            xlb_f("ApplicationRecoveryFinished", ApplicationRecoveryFinished),
            xlb_f("ApplicationRecoveryInProgress", ApplicationRecoveryInProgress),
            xlb_f("BackupEventLog", BackupEventLog),
            xlb_f("BackupRead", BackupRead),
            xlb_f("BackupSeek", BackupSeek),
            xlb_f("BackupWrite", BackupWrite),
            xlb_f("BeginUpdateResource", BeginUpdateResource),
            xlb_f("BindIoCompletionCallback", BindIoCompletionCallback),
            xlb_f("BuildCommDCB", BuildCommDCB),
            xlb_f("BuildCommDCBAndTimeouts", BuildCommDCBAndTimeouts),
            xlb_f("CallNamedPipe", CallNamedPipe),
            xlb_f("CheckNameLegalDOS8Dot3", CheckNameLegalDOS8Dot3),
            xlb_f("ClearCommBreak", ClearCommBreak),
            xlb_f("ClearCommError", ClearCommError),
            xlb_f("ClearEventLog", ClearEventLog),
            xlb_f("CloseEncryptedFileRaw", CloseEncryptedFileRaw),
            xlb_f("CloseEventLog", CloseEventLog),
            xlb_f("CommConfigDialog", CommConfigDialog),
            xlb_f("ConvertFiberToThread", ConvertFiberToThread),
            xlb_f("ConvertThreadToFiber", ConvertThreadToFiber),
            xlb_f("ConvertThreadToFiberEx", ConvertThreadToFiberEx),
            xlb_f("CopyContext", CopyContext),
            xlb_f("CopyFile", CopyFile),
            xlb_f("CopyFile2", CopyFile2),
            xlb_f("CopyFileEx", CopyFileEx),
            xlb_f("CopyFileTransacted", CopyFileTransacted),
            xlb_f("CreateActCtx", CreateActCtx),
            xlb_f("CreateBoundaryDescriptor", CreateBoundaryDescriptor),
            xlb_f("CreateDirectory", CreateDirectory),
            xlb_f("CreateDirectoryEx", CreateDirectoryEx),
            xlb_f("CreateDirectoryTransacted", CreateDirectoryTransacted),
            xlb_f("CreateFiber", CreateFiber),
            xlb_f("CreateFiberEx", CreateFiberEx),
            xlb_f("CreateFileMapping", CreateFileMapping),
            xlb_f("CreateFileMappingNuma", CreateFileMappingNuma),
            xlb_f("CreateFileTransacted", CreateFileTransacted),
            xlb_f("CreateHardLink", CreateHardLink),
            xlb_f("CreateHardLinkTransacted", CreateHardLinkTransacted),
            xlb_f("CreateJobObject", CreateJobObject),
            xlb_f("CreateMailslot", CreateMailslot),
            xlb_f("CreateNamedPipe", CreateNamedPipe),
            xlb_f("CreatePrivateNamespace", CreatePrivateNamespace),
            xlb_f("CreateSemaphore", CreateSemaphore),
            xlb_f("CreateSemaphoreEx", CreateSemaphoreEx),
            xlb_f("CreateSymbolicLink", CreateSymbolicLink),
            xlb_f("CreateSymbolicLinkTransacted", CreateSymbolicLinkTransacted),
            xlb_f("CreateTapePartition", CreateTapePartition),
            xlb_f("CreateUmsCompletionList", CreateUmsCompletionList),
            xlb_f("CreateUmsThreadContext", CreateUmsThreadContext),
            xlb_f("DeactivateActCtx", DeactivateActCtx),
            xlb_f("DebugBreakProcess", DebugBreakProcess),
            xlb_f("DebugSetProcessKillOnExit", DebugSetProcessKillOnExit),
            xlb_f("DecryptFile", DecryptFile),
            xlb_f("DefineDosDevice", DefineDosDevice),
            xlb_f("DeleteAtom", DeleteAtom),
            xlb_f("DeleteFiber", DeleteFiber),
            xlb_f("DeleteFile", DeleteFile),
            xlb_f("DeleteFileTransacted", DeleteFileTransacted),
            xlb_f("DeleteTimerQueue", DeleteTimerQueue),
            xlb_f("DeleteUmsCompletionList", DeleteUmsCompletionList),
            xlb_f("DeleteUmsThreadContext", DeleteUmsThreadContext),
            xlb_f("DeleteVolumeMountPoint", DeleteVolumeMountPoint),
            xlb_f("DequeueUmsCompletionListItems", DequeueUmsCompletionListItems),
            xlb_f("DeregisterEventSource", DeregisterEventSource),
            xlb_f("DestroyThreadpoolEnvironment", DestroyThreadpoolEnvironment),
            xlb_f("DisableThreadProfiling", DisableThreadProfiling),
            xlb_f("DnsHostnameToComputerName", DnsHostnameToComputerName),
            xlb_f("DosDateTimeToFileTime", DosDateTimeToFileTime),
            xlb_f("EnableThreadProfiling", EnableThreadProfiling),
            xlb_f("EncryptFile", EncryptFile),
            xlb_f("EndUpdateResource", EndUpdateResource),
            xlb_f("EnterUmsSchedulingMode", EnterUmsSchedulingMode),
            xlb_f("EnumResourceLanguages", EnumResourceLanguages),
            xlb_f("EnumResourceNames", EnumResourceNames),
            xlb_f("EnumResourceTypes", EnumResourceTypes),
            xlb_f("EraseTape", EraseTape),
            xlb_f("EscapeCommFunction", EscapeCommFunction),
            xlb_f("ExecuteUmsThread", ExecuteUmsThread),
            xlb_f("FatalExit", FatalExit),
            xlb_f("FileEncryptionStatus", FileEncryptionStatus),
            xlb_f("FileTimeToDosDateTime", FileTimeToDosDateTime),
            xlb_f("FindActCtxSectionGuid", FindActCtxSectionGuid),
            xlb_f("FindActCtxSectionString", FindActCtxSectionString),
            xlb_f("FindAtom", FindAtom),
            xlb_f("FindFirstFileTransacted", FindFirstFileTransacted),
            xlb_f("FindFirstVolume", FindFirstVolume),
            xlb_f("FindFirstVolumeMountPoint", FindFirstVolumeMountPoint),
            xlb_f("FindNextVolume", FindNextVolume),
            xlb_f("FindNextVolumeMountPoint", FindNextVolumeMountPoint),
            xlb_f("FindResource", FindResource),
            xlb_f("FindResourceEx", FindResourceEx),
            xlb_f("FindVolumeMountPointClose", FindVolumeMountPointClose),
            xlb_f("FormatMessage", FormatMessage),
            xlb_f("FormatMessage", FormatMessage),
            xlb_f("GetActiveProcessorCount", GetActiveProcessorCount),
            xlb_f("GetActiveProcessorGroupCount", GetActiveProcessorGroupCount),
            xlb_f("GetApplicationRecoveryCallback", GetApplicationRecoveryCallback),
            xlb_f("GetApplicationRestartSettings", GetApplicationRestartSettings),
            xlb_f("GetAtomName", GetAtomName),
            xlb_f("GetBinaryType", GetBinaryType),
            xlb_f("GetCommConfig", GetCommConfig),
            xlb_f("GetCommMask", GetCommMask),
            xlb_f("GetCommModemStatus", GetCommModemStatus),

            //xlb_f("GetCommPorts", GetCommPorts), // FIXME: Windows 10

            xlb_f("GetCommProperties", GetCommProperties),
            xlb_f("GetCommState", GetCommState),
            xlb_f("GetCommTimeouts", GetCommTimeouts),
            xlb_f("GetCompressedFileSizeTransacted", GetCompressedFileSizeTransacted),
            xlb_f("GetComputerName", GetComputerName),
            xlb_f("GetCurrentActCtx", GetCurrentActCtx),
            xlb_f("GetCurrentDirectory", GetCurrentDirectory),
            xlb_f("GetCurrentHwProfile", GetCurrentHwProfile),
            xlb_f("GetCurrentUmsThread", GetCurrentUmsThread),
            xlb_f("GetDefaultCommConfig", GetDefaultCommConfig),
            xlb_f("GetDevicePowerState", GetDevicePowerState),
            xlb_f("GetDllDirectory", GetDllDirectory),
            xlb_f("GetEnabledXStateFeatures", GetEnabledXStateFeatures),
            xlb_f("GetEnvironmentVariable", GetEnvironmentVariable),
            xlb_f("GetEventLogInformation", GetEventLogInformation),
            xlb_f("GetFileAttributesTransacted", GetFileAttributesTransacted),
            xlb_f("GetFileBandwidthReservation", GetFileBandwidthReservation),
            xlb_f("GetFileInformationByHandleEx", GetFileInformationByHandleEx),
            xlb_f("GetFileSecurity", GetFileSecurity),
            xlb_f("GetFirmwareEnvironmentVariable", GetFirmwareEnvironmentVariable),
            xlb_f("GetFirmwareEnvironmentVariableEx", GetFirmwareEnvironmentVariableEx),
            xlb_f("GetFirmwareType", GetFirmwareType),
            xlb_f("GetFullPathNameTransacted", GetFullPathNameTransacted),
            xlb_f("GetLogicalDriveStrings", GetLogicalDriveStrings),
            xlb_f("GetLongPathNameTransacted", GetLongPathNameTransacted),
            xlb_f("GetMailslotInfo", GetMailslotInfo),
            xlb_f("GetMaximumProcessorCount", GetMaximumProcessorCount),
            xlb_f("GetMaximumProcessorGroupCount", GetMaximumProcessorGroupCount),
            xlb_f("GetNamedPipeClientComputerName", GetNamedPipeClientComputerName),
            xlb_f("GetNamedPipeClientProcessId", GetNamedPipeClientProcessId),
            xlb_f("GetNamedPipeClientSessionId", GetNamedPipeClientSessionId),
            xlb_f("GetNamedPipeHandleState", GetNamedPipeHandleState),
            xlb_f("GetNamedPipeServerProcessId", GetNamedPipeServerProcessId),
            xlb_f("GetNamedPipeServerSessionId", GetNamedPipeServerSessionId),
            xlb_f("GetNextUmsListItem", GetNextUmsListItem),
            xlb_f("GetNumaAvailableMemoryNode", GetNumaAvailableMemoryNode),
            xlb_f("GetNumaAvailableMemoryNodeEx", GetNumaAvailableMemoryNodeEx),
            xlb_f("GetNumaNodeNumberFromHandle", GetNumaNodeNumberFromHandle),
            xlb_f("GetNumaNodeProcessorMask", GetNumaNodeProcessorMask),
            xlb_f("GetNumaProcessorNode", GetNumaProcessorNode),
            xlb_f("GetNumaProcessorNodeEx", GetNumaProcessorNodeEx),
            xlb_f("GetNumaProximityNode", GetNumaProximityNode),
            xlb_f("GetNumberOfEventLogRecords", GetNumberOfEventLogRecords),
            xlb_f("GetOldestEventLogRecord", GetOldestEventLogRecord),
            xlb_f("GetPrivateProfileInt", GetPrivateProfileInt),
            xlb_f("GetPrivateProfileSection", GetPrivateProfileSection),
            xlb_f("GetPrivateProfileSectionNames", GetPrivateProfileSectionNames),
            xlb_f("GetPrivateProfileString", GetPrivateProfileString),
            xlb_f("GetPrivateProfileStruct", GetPrivateProfileStruct),
            xlb_f("GetProcessAffinityMask", GetProcessAffinityMask),
            xlb_f("GetProcessDEPPolicy", GetProcessDEPPolicy),
            xlb_f("GetProcessIoCounters", GetProcessIoCounters),
            xlb_f("GetProcessWorkingSetSize", GetProcessWorkingSetSize),
            xlb_f("GetProfileInt", GetProfileInt),
            xlb_f("GetProfileSection", GetProfileSection),
            xlb_f("GetProfileString", GetProfileString),
            xlb_f("GetShortPathName", GetShortPathName),
            xlb_f("GetSystemDEPPolicy", GetSystemDEPPolicy),
            xlb_f("GetSystemPowerStatus", GetSystemPowerStatus),
            xlb_f("GetSystemRegistryQuota", GetSystemRegistryQuota),
            xlb_f("GetTapeParameters", GetTapeParameters),
            xlb_f("GetTapePosition", GetTapePosition),
            xlb_f("GetTapeStatus", GetTapeStatus),
            xlb_f("GetTempFileName", GetTempFileName),
            xlb_f("GetThreadSelectorEntry", GetThreadSelectorEntry),
            xlb_f("GetUmsCompletionListEvent", GetUmsCompletionListEvent),
            xlb_f("GetUmsSystemThreadInformation", GetUmsSystemThreadInformation),
            xlb_f("GetUserName", GetUserName),
            xlb_f("GetVolumeNameForVolumeMountPoint", GetVolumeNameForVolumeMountPoint),
            xlb_f("GetVolumePathName", GetVolumePathName),
            xlb_f("GetVolumePathNamesForVolumeName", GetVolumePathNamesForVolumeName),
            xlb_f("GetXStateFeaturesMask", GetXStateFeaturesMask),
            xlb_f("GlobalAddAtom", GlobalAddAtom),
            xlb_f("GlobalAddAtomEx", GlobalAddAtomEx),
            xlb_f("GlobalAlloc", GlobalAlloc),
            xlb_f("GlobalDeleteAtom", GlobalDeleteAtom),
            xlb_f("GlobalDiscard", [](HGLOBAL h){ GlobalDiscard(h); }),
            xlb_f("GlobalFindAtom", GlobalFindAtom),
            xlb_f("GlobalFlags", GlobalFlags),
            xlb_f("GlobalFree", GlobalFree),
            xlb_f("GlobalGetAtomName", GlobalGetAtomName),
            xlb_f("GlobalHandle", GlobalHandle),
            xlb_f("GlobalLock", GlobalLock),
            xlb_f("GlobalMemoryStatus", GlobalMemoryStatus),
            xlb_f("GlobalReAlloc", GlobalReAlloc),
            xlb_f("GlobalSize", GlobalSize),
            xlb_f("GlobalUnlock", GlobalUnlock),
            xlb_f("HasOverlappedIoCompleted", [](OVERLAPPED* lp) { HasOverlappedIoCompleted(lp); }),
            xlb_f("InitAtomTable", InitAtomTable),
            xlb_f("InitializeContext", InitializeContext),
            xlb_f("InitializeThreadpoolEnvironment", InitializeThreadpoolEnvironment),
            //xlb_f("InterlockedExchangeSubtract", InterlockedExchangeSubtract), // FIXME
            xlb_f("IsBadCodePtr", IsBadCodePtr),
            xlb_f("IsBadReadPtr", IsBadReadPtr),
            xlb_f("IsBadStringPtr", IsBadStringPtr),
            xlb_f("IsBadWritePtr", IsBadWritePtr),
            xlb_f("IsNativeVhdBoot", IsNativeVhdBoot),
            xlb_f("IsSystemResumeAutomatic", IsSystemResumeAutomatic),
            xlb_f("IsTextUnicode", IsTextUnicode),
            xlb_f("LoadModule", LoadModule),
            xlb_f("LoadPackagedLibrary", LoadPackagedLibrary),
            xlb_f("LocalAlloc", LocalAlloc),
            xlb_f("LocalFlags", LocalFlags),
            xlb_f("LocalFree", LocalFree),
            xlb_f("LocalHandle", LocalHandle),
            xlb_f("LocalLock", LocalLock),
            xlb_f("LocalReAlloc", LocalReAlloc),
            xlb_f("LocalSize", LocalSize),
            xlb_f("LocalUnlock", LocalUnlock),
            xlb_f("LocateXStateFeature", LocateXStateFeature),
            xlb_f("LogonUser", LogonUser),
            xlb_f("LogonUserEx", LogonUserEx),
            xlb_f("LookupAccountName", LookupAccountName),
            xlb_f("LookupAccountSid", LookupAccountSid),
            //xlb_f("LookupAccountSidLocal", LookupAccountSidLocal), //FIXME
            xlb_f("LookupPrivilegeDisplayName", LookupPrivilegeDisplayName),
            xlb_f("LookupPrivilegeName", LookupPrivilegeName),
            xlb_f("LookupPrivilegeValue", LookupPrivilegeValue),
            xlb_f("lstrcat", lstrcat),
            xlb_f("lstrcmp", lstrcmp),
            xlb_f("lstrcmpi", lstrcmpi),
            xlb_f("lstrcpy", lstrcpy),
            xlb_f("lstrcpyn", lstrcpyn),
            xlb_f("lstrlen", lstrlen),
            xlb_f("MAKEINTATOM", [](LPTSTR i)->LPTSTR{ return MAKEINTATOM(i); }),
            xlb_f("MapUserPhysicalPagesScatter", MapUserPhysicalPagesScatter),
            xlb_f("MapViewOfFileExNuma", MapViewOfFileExNuma),
            xlb_f("MoveFile", MoveFile),
            xlb_f("MoveFileEx", MoveFileEx),
            xlb_f("MoveFileTransacted", MoveFileTransacted),
            xlb_f("MoveFileWithProgress", MoveFileWithProgress),
            xlb_f("MulDiv", MulDiv),
            xlb_f("NotifyChangeEventLog", NotifyChangeEventLog),

            xlb_f("ObjectCloseAuditAlarm", ObjectCloseAuditAlarm),
            xlb_f("ObjectDeleteAuditAlarm", ObjectDeleteAuditAlarm),
            xlb_f("ObjectOpenAuditAlarm", ObjectOpenAuditAlarm),
            xlb_f("ObjectPrivilegeAuditAlarm", ObjectPrivilegeAuditAlarm),
            xlb_f("OpenBackupEventLog", OpenBackupEventLog),
            //xlb_f("OpenCommPort", OpenCommPort),
            xlb_f("OpenEncryptedFileRaw", OpenEncryptedFileRaw),
            xlb_f("OpenEventLog", OpenEventLog),
            xlb_f("OpenFile", OpenFile),
            xlb_f("OpenFileById", OpenFileById),
            xlb_f("OpenFileMapping", OpenFileMapping),
            xlb_f("OpenJobObject", OpenJobObject),
            xlb_f("OpenPrivateNamespace", OpenPrivateNamespace),
            xlb_f("OperationEnd", OperationEnd),
            xlb_f("OperationStart", OperationStart),

            xlb_f("PowerClearRequest", PowerClearRequest),
            xlb_f("PowerCreateRequest", PowerCreateRequest),
            xlb_f("PowerSetRequest", PowerSetRequest),
            xlb_f("PrepareTape", PrepareTape),
            xlb_f("PrivilegedServiceAuditAlarm", PrivilegedServiceAuditAlarm),
            xlb_f("PulseEvent", PulseEvent),
            //xlb_f("PurgeComm", PurgeComm),
            xlb_f("QueryDosDevice", QueryDosDevice),
            xlb_f("QueryFullProcessImageName", QueryFullProcessImageName),
            xlb_f("QueryThreadProfiling", QueryThreadProfiling),
            xlb_f("QueryUmsThreadInformation", QueryUmsThreadInformation),
            xlb_f("ReadEncryptedFileRaw", ReadEncryptedFileRaw),
            xlb_f("ReadEventLog", ReadEventLog),
            xlb_f("ReadThreadProfilingData", ReadThreadProfilingData),
            xlb_f("RegisterApplicationRecoveryCallback", RegisterApplicationRecoveryCallback),
            xlb_f("RegisterApplicationRestart", RegisterApplicationRestart),
            xlb_f("RegisterEventSource", RegisterEventSource),
            xlb_f("RegisterWaitForSingleObject", RegisterWaitForSingleObject),
            xlb_f("ReleaseActCtx", ReleaseActCtx),
            xlb_f("RemoveDirectoryTransacted", RemoveDirectoryTransacted),
            xlb_f("RemoveSecureMemoryCacheCallback", RemoveSecureMemoryCacheCallback),
            xlb_f("ReOpenFile", ReOpenFile),
            xlb_f("ReplaceFile", ReplaceFile),
            xlb_f("ReportEvent", ReportEvent),
            xlb_f("RequestWakeupLatency", RequestWakeupLatency),
            //xlb_f("SetCommBreak", SetCommBreak),
            //xlb_f("SetCommConfig", SetCommConfig),
            //xlb_f("SetCommMask", SetCommMask),
            //xlb_f("SetCommState", SetCommState),
            //xlb_f("SetCommTimeouts", SetCommTimeouts),
            xlb_f("SetCurrentDirectory", SetCurrentDirectory),
            //xlb_f("SetDefaultCommConfig", SetDefaultCommConfig),
            xlb_f("SetDllDirectory", SetDllDirectory),
            xlb_f("SetEnvironmentVariable", SetEnvironmentVariable),
            xlb_f("SetFileAttributesTransacted", SetFileAttributesTransacted),
            xlb_f("SetFileBandwidthReservation", SetFileBandwidthReservation),
            xlb_f("SetFileCompletionNotificationModes", SetFileCompletionNotificationModes),
            xlb_f("SetFileSecurity", SetFileSecurity),
            xlb_f("SetFileShortName", SetFileShortName),
            xlb_f("SetFirmwareEnvironmentVariable", SetFirmwareEnvironmentVariable),
            xlb_f("SetFirmwareEnvironmentVariableEx", SetFirmwareEnvironmentVariableEx),
            xlb_f("SetMailslotInfo", SetMailslotInfo),
            xlb_f("SetProcessAffinityMask", SetProcessAffinityMask),
            xlb_f("SetProcessDEPPolicy", SetProcessDEPPolicy),
            xlb_f("SetProcessWorkingSetSize", SetProcessWorkingSetSize),
            xlb_f("SetSearchPathMode", SetSearchPathMode),
            xlb_f("SetSystemPowerState", SetSystemPowerState),
            xlb_f("SetTapeParameters", SetTapeParameters),
            xlb_f("SetTapePosition", SetTapePosition),
            xlb_f("SetThreadAffinityMask", SetThreadAffinityMask),
            xlb_f("SetThreadExecutionState", SetThreadExecutionState),
            xlb_f("SetThreadpoolCallbackCleanupGroup", SetThreadpoolCallbackCleanupGroup),
            xlb_f("SetThreadpoolCallbackLibrary", SetThreadpoolCallbackLibrary),
            xlb_f("SetThreadpoolCallbackPersistent", SetThreadpoolCallbackPersistent),
            xlb_f("SetThreadpoolCallbackPool", SetThreadpoolCallbackPool),
            xlb_f("SetThreadpoolCallbackPriority", SetThreadpoolCallbackPriority),
            xlb_f("SetThreadpoolCallbackRunsLong", SetThreadpoolCallbackRunsLong),
            xlb_f("SetUmsThreadInformation", SetUmsThreadInformation),
            //xlb_f("SetupComm", SetupComm),
            xlb_f("SetVolumeLabel", SetVolumeLabel),
            xlb_f("SetVolumeMountPoint", SetVolumeMountPoint),
            xlb_f("SetXStateFeaturesMask", SetXStateFeaturesMask),
            xlb_f("SwitchToFiber", SwitchToFiber),
            //xlb_f("TransmitCommChar", TransmitCommChar),
            xlb_f("UmsThreadYield", UmsThreadYield),
            xlb_f("UnregisterApplicationRecoveryCallback", UnregisterApplicationRecoveryCallback),
            xlb_f("UnregisterApplicationRestart", UnregisterApplicationRestart),
            xlb_f("UnregisterWait", UnregisterWait),
            xlb_f("UpdateResource", UpdateResource),
            xlb_f("VerifyVersionInfo", VerifyVersionInfo),
            //xlb_f("WaitCommEvent", WaitCommEvent),
            xlb_f("WaitNamedPipe", WaitNamedPipe),
            xlb_f("WinExec", WinExec),
            //xlb_f("WinMain", WinMain),
            xlb_f("Wow64EnableWow64FsRedirection", Wow64EnableWow64FsRedirection),
            xlb_f("Wow64GetThreadContext", Wow64GetThreadContext),
            xlb_f("Wow64GetThreadSelectorEntry", Wow64GetThreadSelectorEntry),
            xlb_f("Wow64SetThreadContext", Wow64SetThreadContext),
            xlb_f("Wow64SuspendThread", Wow64SuspendThread),
            xlb_f("WriteEncryptedFileRaw", WriteEncryptedFileRaw),
            xlb_f("WritePrivateProfileSection", WritePrivateProfileSection),
            xlb_f("WritePrivateProfileString", WritePrivateProfileString),
            xlb_f("WritePrivateProfileStruct", WritePrivateProfileStruct),
            xlb_f("WriteProfileSection", WriteProfileSection),
            xlb_f("WriteProfileString", WriteProfileString),
            xlb_f("WriteTapemark", WriteTapemark),
            xlb_f("WTSGetActiveConsoleSessionId", WTSGetActiveConsoleSessionId),
            xlb_f("ZombifyActCtx", ZombifyActCtx),
#ifdef compile
#endif
            xlb_const("CHECK_BIND_BASE", BIND_WIN_CHECKED)
    });
    return 0;
};

