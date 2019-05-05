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
int luaopen_luawin(lua_State* L) {


    printf("WINVER=0x%04x\n", WINVER);
    bind_win_api_function(L);
    bind_win_api_desktop_tech(L);

    return 0;
}

//-----------------------------------------------------------------------------
void bind_win_api_function(lua_State* L) {
    xlb_module(L, MODULE_NAME) ({
#ifdef compile
        xlb_f("_hread", _hread),
        xlb_f("_hwrite", _hwrite),
        xlb_f("_lclose", _lclose),
        xlb_f("_lcreat", _lcreat),
        xlb_f("_llseek", _llseek),
        xlb_f("_lopen", _lopen),
        xlb_f("_lread", _lread),
        xlb_f("_lwrite", _lwrite),
        ////xlb_f("AbnormalTermination", AbnormalTermination()),
        xlb_f("AbortDoc", AbortDoc),
        xlb_f("AbortPath", AbortPath),
        xlb_f("AbortPrinter", AbortPrinter),
        xlb_class<xlb_cbf<ABORTPROC>>("AbortProc").constructor<xlb_luafunc>(),
        xlb_f("AbortSystemShutdown", AbortSystemShutdown),
        xlb_f("AccessCheck", AccessCheck),
        xlb_f("AccessCheckAndAuditAlarm", AccessCheckAndAuditAlarm),
        ////xlb_f("AcsLan", AcsLan),
        xlb_f("ActivateKeyboardLayout", ActivateKeyboardLayout),
        xlb_f("AddAccessAllowedAce", AddAccessAllowedAce),
        xlb_f("AddAccessDeniedAce", AddAccessDeniedAce),
        xlb_f("AddAce", AddAce),
        xlb_f("AddAtom", AddAtom),
        xlb_f("AddAuditAccessAce", AddAuditAccessAce),
        xlb_f("AddFontResource", AddFontResource),
        xlb_f("AddForm", AddForm),
        xlb_f("AddJob", AddJob),
        xlb_f("AddMonitor", AddMonitor),
        xlb_f("AddPort", AddPort),
        xlb_f("AddPrinter", AddPrinter),
        xlb_f("AddPrinterConnection", AddPrinterConnection),
        xlb_f("AddPrinterDriver", AddPrinterDriver),
        xlb_f("AddPrintProcessor", AddPrintProcessor),
        xlb_f("AddPrintProvidor", AddPrintProvidor),
        xlb_class<xlb_cbf<ADDPROPSHEETPAGEPROC>>("AddPropSheetPageProc").constructor<xlb_luafunc>(),
        xlb_f("AdjustTokenGroups", AdjustTokenGroups),
        xlb_f("AdjustTokenPrivileges", AdjustTokenPrivileges),
        xlb_f("AdjustWindowRect", AdjustWindowRect),
        xlb_f("AdjustWindowRectEx", AdjustWindowRectEx),
        xlb_f("AdvancedDocumentProperties", AdvancedDocumentProperties),
        xlb_f("AllocateAndInitializeSid", AllocateAndInitializeSid),
        xlb_f("AllocateLocallyUniqueId", AllocateLocallyUniqueId),
        xlb_f("AllocConsole", AllocConsole),
        xlb_f("AngleArc", AngleArc),
        xlb_f("AnimatePalette", AnimatePalette),
        xlb_f("AnsiLower", AnsiLower),
        xlb_f("AnsiLowerBuff", AnsiLowerBuff),
        xlb_f("AnsiNext", AnsiNext),
        xlb_f("AnsiPrev", AnsiPrev),
        xlb_f("AnsiToOem", AnsiToOem),
        xlb_f("AnsiToOemBuff", AnsiToOemBuff),
        xlb_f("AnsiUpper", AnsiUpper),
        xlb_f("AnsiUpperBuff", AnsiUpperBuff),
        xlb_f("AnyPopup", AnyPopup),
        xlb_f("AppendMenu", AppendMenu),
        xlb_f("Arc", Arc),
        xlb_f("ArcTo", ArcTo),
        xlb_f("AreAllAccessesGranted", AreAllAccessesGranted),
        xlb_f("AreAnyAccessesGranted", AreAnyAccessesGranted),
        xlb_f("AreFileApisANSI", AreFileApisANSI),
        xlb_f("ArrangeIconicWindows", ArrangeIconicWindows),
        xlb_f("AttachThreadInput", AttachThreadInput),
        xlb_f("BackupEventLog", BackupEventLog),
        xlb_f("BackupRead", BackupRead),
        xlb_f("BackupSeek", BackupSeek),
        xlb_f("BackupWrite", BackupWrite),
        xlb_f("Beep", Beep),
        xlb_f("BeginDeferWindowPos", BeginDeferWindowPos),
        xlb_f("BeginPaint", BeginPaint),
        xlb_f("BeginPath", BeginPath),
        xlb_f("BeginUpdateResource", BeginUpdateResource),
        xlb_f("BitBlt", BitBlt),
        xlb_f("BringWindowToTop", BringWindowToTop),
        xlb_f("BroadcastSystemMessage", BroadcastSystemMessage),
        xlb_class<xlb_cbf<BROWSECALLBACKPROC>>("BrowseCallbackProc").constructor<xlb_luafunc>(),
        xlb_f("BuildCommDCB", BuildCommDCB),
        xlb_f("BuildCommDCBAndTimeouts", BuildCommDCBAndTimeouts),
        xlb_f("BuildExplicitAccessWithName", BuildExplicitAccessWithName),
        xlb_f("BuildImpersonateExplicitAccessWithName", BuildImpersonateExplicitAccessWithName),
        xlb_f("BuildImpersonateTrustee", BuildImpersonateTrustee),
        xlb_f("BuildSecurityDescriptor", BuildSecurityDescriptor),
        xlb_f("BuildTrusteeWithName", BuildTrusteeWithName),
        xlb_f("BuildTrusteeWithSid", BuildTrusteeWithSid),
        xlb_f("CallMsgFilter", CallMsgFilter),
        xlb_f("CallNamedPipe", CallNamedPipe),
        xlb_f("CallNextHookEx", CallNextHookEx),
        xlb_f("CallWindowProc", CallWindowProc),
        xlb_class<xlb_cbf<HOOKPROC>>("CallWndProc").constructor<xlb_luafunc>(),
        xlb_class<xlb_cbf<HOOKPROC>>("CallWndRetProc").constructor<xlb_luafunc>(),
        xlb_f("CancelDC", CancelDC),
        xlb_f("CancelIo", CancelIo),
        xlb_f("CancelWaitableTimer", CancelWaitableTimer),
        xlb_f("CascadeWindows", CascadeWindows),
        xlb_class<xlb_cbf<HOOKPROC>>("CBTProc").constructor<xlb_luafunc>(),
        xlb_class<xlb_cbf<LPCCHOOKPROC>>("CCHookProc").constructor<xlb_luafunc>(),
        xlb_class<xlb_cbf<LPCFHOOKPROC>>("CFHookProc").constructor<xlb_luafunc>(),
        xlb_f("ChangeClipboardChain", ChangeClipboardChain),
        xlb_f("ChangeDisplaySettings", ChangeDisplaySettings),
        xlb_f("ChangeMenu", ChangeMenu),
        xlb_f("ChangeServiceConfig", ChangeServiceConfig),
        xlb_f("CharLower", CharLower),
        xlb_f("CharLowerBuff", CharLowerBuff),
        xlb_f("CharNext", CharNext),
        xlb_f("CharNextExA", CharNextExA),
        xlb_f("CharPrev", CharPrev),
        xlb_f("CharPrevExA", CharPrevExA),
        xlb_f("CharToOem", CharToOem),
        xlb_f("CharToOemBuff", CharToOemBuff),
        xlb_f("CharUpper", CharUpper),
        xlb_f("CharUpperBuff", CharUpperBuff),
        xlb_f("CheckColorsInGamut", CheckColorsInGamut),
        xlb_f("CheckDlgButton", CheckDlgButton),
        xlb_f("CheckMenuItem", CheckMenuItem),
        xlb_f("CheckMenuRadioItem", CheckMenuRadioItem),
        xlb_f("CheckRadioButton", CheckRadioButton),
        xlb_f("ChildWindowFromPoint", ChildWindowFromPoint),
        xlb_f("ChildWindowFromPointEx", ChildWindowFromPointEx),
        xlb_f("ChooseColor", ChooseColor),
        xlb_f("ChooseFont", ChooseFont),
        xlb_f("ClearCommBreak", ClearCommBreak),
        xlb_f("ClearCommError", ClearCommError),
        xlb_f("ClearEventLog", ClearEventLog),
        xlb_f("ClientToScreen", ClientToScreen),
        xlb_f("ClipCursor", ClipCursor),
        xlb_f("CloseClipboard", CloseClipboard),
        xlb_f("CloseDesktop", CloseDesktop),
        xlb_f("CloseEnhMetaFile", CloseEnhMetaFile),
        xlb_f("CloseEventLog", CloseEventLog),
        xlb_f("CloseFigure", CloseFigure),
        xlb_f("CloseHandle", CloseHandle),
        xlb_f("CloseMetaFile", CloseMetaFile),
        xlb_f("ClosePrinter", ClosePrinter),
        xlb_f("CloseServiceHandle", CloseServiceHandle),
        xlb_f("CloseWindow", CloseWindow),
        xlb_f("CloseWindowStation", CloseWindowStation),
        xlb_f("ColorMatchToTarget", ColorMatchToTarget),
        xlb_f("CombineRgn", CombineRgn),
        xlb_f("CombineTransform", CombineTransform),
        xlb_f("CommandLineToArgvW", CommandLineToArgvW),
        xlb_f("CommConfigDialog", CommConfigDialog),
        xlb_f("CommDlgExtendedError", CommDlgExtendedError),
        xlb_f("CompareFileTime", CompareFileTime),
        xlb_f("CompareString", CompareString),
        xlb_f("ConfigurePort", ConfigurePort),
        xlb_f("ConnectNamedPipe", ConnectNamedPipe),
        xlb_f("ConnectToPrinterDlg", ConnectToPrinterDlg),
        xlb_f("ContinueDebugEvent", ContinueDebugEvent),
        xlb_f("ControlService", ControlService),
        xlb_f("ConvertDefaultLocale", ConvertDefaultLocale),
        xlb_f("ConvertThreadToFiber", ConvertThreadToFiber),
        xlb_f("CopyAcceleratorTable", CopyAcceleratorTable),
        xlb_f("CopyCursor", CopyIcon),
        xlb_f("CopyEnhMetaFile", CopyEnhMetaFile),
        xlb_f("CopyFile", CopyFile),
        xlb_f("CopyFileEx", CopyFileEx),
        xlb_f("CopyIcon", CopyIcon),
        xlb_f("CopyImage", CopyImage),
        ////xlb_f("CopyLZFile", CopyLZFile), // Outdated
        xlb_f("CopyMemory", [](PVOID Destination, const VOID* Source, SIZE_T length)->void { 
                ::CopyMemory(Destination, Source, length); }),
        xlb_f("CopyMetaFile", CopyMetaFile),
        xlb_class<xlb_cbf<LPPROGRESS_ROUTINE>>("CopyProgressRoutine").constructor<xlb_luafunc>(),
        xlb_f("CopyRect", CopyRect),
        xlb_f("CopySid", CopySid),
        xlb_f("CountClipboardFormats", CountClipboardFormats),
        ////xlb_f("CPlApplet", CPlApplet), // Unknown
        xlb_f("CreateAcceleratorTable", CreateAcceleratorTable),
        xlb_f("CreateBitmap", CreateBitmap),
        xlb_f("CreateBitmapIndirect", CreateBitmapIndirect),
        xlb_f("CreateBrushIndirect", CreateBrushIndirect),
        xlb_f("CreateCaret", CreateCaret),
        xlb_f("CreateColorSpace", CreateColorSpace),
        xlb_f("CreateCompatibleBitmap", CreateCompatibleBitmap),
        xlb_f("CreateCompatibleDC", CreateCompatibleDC),
        xlb_f("CreateConsoleScreenBuffer", CreateConsoleScreenBuffer),
        xlb_f("CreateCursor", CreateCursor),
        xlb_f("CreateDC", CreateDC),
        xlb_f("CreateDesktop", CreateDesktop),
        xlb_f("CreateDialog", CreateDialogParam),
        xlb_f("CreateDialogIndirect", CreateDialogIndirectParam),
        xlb_f("CreateDialogIndirectParam", CreateDialogIndirectParam),
        xlb_f("CreateDialogParam", CreateDialogParam),
        xlb_f("CreateDIBitmap", CreateDIBitmap),
        xlb_f("CreateDIBPatternBrush", CreateDIBPatternBrush),
        xlb_f("CreateDIBPatternBrushPt", CreateDIBPatternBrushPt),
        xlb_f("CreateDIBSection", CreateDIBSection),
        xlb_f("CreateDirectory", CreateDirectory),
        xlb_f("CreateDirectoryEx", CreateDirectoryEx),
        xlb_f("CreateDiscardableBitmap", CreateDiscardableBitmap),
        xlb_f("CreateEllipticRgn", CreateEllipticRgn),
        xlb_f("CreateEllipticRgnIndirect", CreateEllipticRgnIndirect),
        xlb_f("CreateEnhMetaFile", CreateEnhMetaFile),
        xlb_f("CreateEvent", CreateEvent),
        xlb_f("CreateFiber", CreateFiber),
        xlb_f("CreateFile", CreateFile),
        xlb_f("CreateFileMapping", CreateFileMapping),
        xlb_f("CreateFont", CreateFont),
        xlb_f("CreateFontIndirect", CreateFontIndirect),
        xlb_f("CreateHalftonePalette", CreateHalftonePalette),
        xlb_f("CreateHatchBrush", CreateHatchBrush),
        xlb_f("CreateIC", CreateIC),
        xlb_f("CreateIcon", CreateIcon),
        xlb_f("CreateIconFromResource", CreateIconFromResource),
        xlb_f("CreateIconFromResourceEx", CreateIconFromResourceEx),
        xlb_f("CreateIconIndirect", CreateIconIndirect),
        xlb_f("CreateIoCompletionPort", CreateIoCompletionPort),
        xlb_f("CreateMailslot", CreateMailslot),
        xlb_f("CreateMappedBitmap", CreateMappedBitmap),
        xlb_f("CreateMenu", CreateMenu),
        xlb_f("CreateMetaFile", CreateMetaFile),
        xlb_f("CreateMutex", CreateMutex),
        xlb_f("CreateNamedPipe", CreateNamedPipe),
        xlb_f("CreatePalette", CreatePalette),
        xlb_f("CreatePatternBrush", CreatePatternBrush),
        xlb_f("CreatePen", CreatePen),
        xlb_f("CreatePenIndirect", CreatePenIndirect),
        xlb_f("CreatePipe", CreatePipe),
        xlb_f("CreatePolygonRgn", CreatePolygonRgn),
        xlb_f("CreatePolyPolygonRgn", CreatePolyPolygonRgn),
        xlb_f("CreatePopupMenu", CreatePopupMenu),
        xlb_f("CreatePrivateObjectSecurity", CreatePrivateObjectSecurity),
        xlb_f("CreateProcess", CreateProcess),
        xlb_f("CreateProcessAsUser", CreateProcessAsUser),
        ////xlb_f("CreatePropertySheetPage", CreatePropertySheetPage), // _PSP
        xlb_f("CreateRectRgn", CreateRectRgn),
        xlb_f("CreateRectRgnIndirect", CreateRectRgnIndirect),
        xlb_f("CreateRemoteThread", CreateRemoteThread),
        xlb_f("CreateRoundRectRgn", CreateRoundRectRgn),
        xlb_f("CreateScalableFontResource", CreateScalableFontResource),
        xlb_f("CreateSemaphore", CreateSemaphore),
        xlb_f("CreateService", CreateService),
        xlb_f("CreateSolidBrush", CreateSolidBrush),
        xlb_f("CreateTapePartition", CreateTapePartition),
        xlb_f("CreateToolbarEx", CreateToolbarEx),
        xlb_f("CreateThread", CreateThread),
        xlb_f("CreateUpDownControl", CreateUpDownControl),
        xlb_f("CreateWaitableTimer", CreateWaitableTimer),
        ////xlb_f("CreateWindow", CreateWindow),
        xlb_f("CreateWindowEx", CreateWindowEx),
        xlb_f("CreateWindowStation", CreateWindowStation),
        xlb_f("CryptAcquireContext", CryptAcquireContext),
        xlb_f("CryptCreateHash", CryptCreateHash),
        xlb_f("CryptDecrypt", CryptDecrypt),
        xlb_f("CryptDeriveKey", CryptDeriveKey),
        xlb_f("CryptDestroyHash", CryptDestroyHash),
        xlb_f("CryptDestroyKey", CryptDestroyKey),
        xlb_f("CryptEncrypt", CryptEncrypt),
        xlb_f("CryptExportKey", CryptExportKey),
        xlb_f("CryptGenKey", CryptGenKey),
        xlb_f("CryptGenRandom", CryptGenRandom),
        xlb_f("CryptGetHashParam", CryptGetHashParam),
        xlb_f("CryptGetKeyParam", CryptGetKeyParam),
        xlb_f("CryptGetProvParam", CryptGetProvParam),
        xlb_f("CryptGetUserKey", CryptGetUserKey),
        xlb_f("CryptHashData", CryptHashData),
        xlb_f("CryptHashSessionKey", CryptHashSessionKey),
        xlb_f("CryptImportKey", CryptImportKey),
        xlb_f("CryptReleaseContext", CryptReleaseContext),
        xlb_f("CryptSetHashParam", CryptSetHashParam),
        xlb_f("CryptSetKeyParam", CryptSetKeyParam),
        xlb_f("CryptSetProvider", CryptSetProvider),
        xlb_f("CryptSetProvParam", CryptSetProvParam),
        xlb_f("CryptSignHash", CryptSignHash),
        xlb_f("CryptVerifySignature", CryptVerifySignature),
        xlb_f("DdeAbandonTransaction", DdeAbandonTransaction),
        xlb_f("DdeAccessData", DdeAccessData),
        xlb_f("DdeAddData", DdeAddData),
        xlb_class<xlb_cbf<PFNCALLBACK>>("DdeCallback").constructor<xlb_luafunc>(),
        xlb_f("DdeClientTransaction", DdeClientTransaction),
        xlb_f("DdeCmpStringHandles", DdeCmpStringHandles),
        xlb_f("DdeConnect", DdeConnect),
        xlb_f("DdeConnectList", DdeConnectList),
        xlb_f("DdeCreateDataHandle", DdeCreateDataHandle),
        xlb_f("DdeCreateStringHandle", DdeCreateStringHandle),
        xlb_f("DdeDisconnect", DdeDisconnect),
        xlb_f("DdeDisconnectList", DdeDisconnectList),
        xlb_f("DdeEnableCallback", DdeEnableCallback),
        xlb_f("DdeFreeDataHandle", DdeFreeDataHandle),
        xlb_f("DdeFreeStringHandle", DdeFreeStringHandle),
        xlb_f("DdeGetData", DdeGetData),
        xlb_f("DdeGetLastError", DdeGetLastError),
        xlb_f("DdeImpersonateClient", DdeImpersonateClient),
        xlb_f("DdeInitialize", DdeInitialize),
        xlb_f("DdeKeepStringHandle", DdeKeepStringHandle),
        xlb_f("DdeNameService", DdeNameService),
        xlb_f("DdePostAdvise", DdePostAdvise),
        xlb_f("DdeQueryConvInfo", DdeQueryConvInfo),
        xlb_f("DdeQueryNextServer", DdeQueryNextServer),
        xlb_f("DdeQueryString", DdeQueryString),
        xlb_f("DdeReconnect", DdeReconnect),
        xlb_f("DdeSetQualityOfService", DdeSetQualityOfService),
        xlb_f("DdeSetUserHandle", DdeSetUserHandle),
        xlb_f("DdeUnaccessData", DdeUnaccessData),
        xlb_f("DdeUninitialize", DdeUninitialize),
        xlb_f("DebugActiveProcess", DebugActiveProcess),
        xlb_f("DebugBreak", DebugBreak),
        xlb_class<xlb_cbf<HOOKPROC>>("DebugProc").constructor<xlb_luafunc>(),
        xlb_f("DefDlgProc", DefDlgProc),
        xlb_f("DeferWindowPos", DeferWindowPos),
        xlb_f("DefFrameProc", DefFrameProc),
        ////xlb_f("DefHookProc", DefHookProc), // convert to CallNextHookEx
        xlb_f("DefineDosDevice", DefineDosDevice),
        ////xlb_f("DefineHandleTable", DefineHandleTable), // Outdated
        xlb_f("DefMDIChildProc", DefMDIChildProc),
        //xlb_f("DefScreenSaverProc", DefScreenSaverProc), //FIXME
        xlb_f("DefWindowProc", DefWindowProc),
        xlb_f("DeleteAce", DeleteAce),
        xlb_f("DeleteAtom", DeleteAtom),
        xlb_f("DeleteColorSpace", DeleteColorSpace),
        xlb_f("DeleteCriticalSection", DeleteCriticalSection),
        xlb_f("DeleteDC", DeleteDC),
        xlb_f("DeleteEnhMetaFile", DeleteEnhMetaFile),
        xlb_f("DeleteFiber", DeleteFiber),
        xlb_f("DeleteFile", DeleteFile),
        xlb_f("DeleteForm", DeleteForm),
        xlb_f("DeleteMenu", DeleteMenu),
        xlb_f("DeleteMetaFile", DeleteMetaFile),
        xlb_f("DeleteMonitor", DeleteMonitor),
        xlb_f("DeleteObject", DeleteObject),
        xlb_f("DeletePort", DeletePort),
        xlb_f("DeletePrinter", DeletePrinter),
        xlb_f("DeletePrinterConnection", DeletePrinterConnection),
        xlb_f("DeletePrinterData", DeletePrinterData),
        xlb_f("DeletePrinterDriver", DeletePrinterDriver),
        xlb_f("DeletePrintProcessor", DeletePrintProcessor),
        xlb_f("DeletePrintProvidor", DeletePrintProvidor),
        xlb_f("DeleteService", DeleteService),
        xlb_f("DeregisterEventSource", DeregisterEventSource),
        xlb_f("DestroyAcceleratorTable", DestroyAcceleratorTable),
        xlb_f("DestroyCaret", DestroyCaret),
        xlb_f("DestroyCursor", DestroyCursor),
        xlb_f("DestroyIcon", DestroyIcon),
        xlb_f("DestroyMenu", DestroyMenu),
        xlb_f("DestroyPrivateObjectSecurity", DestroyPrivateObjectSecurity),
        //xlb_f("DestroyPropertySheetPage", DestroyPropertySheetPage), // _PSP
        xlb_f("DestroyWindow", DestroyWindow),
        xlb_f("DeviceCapabilities", DeviceCapabilities),
        xlb_f("DeviceIoControl", DeviceIoControl),
        xlb_f("DialogBox", [](HINSTANCE hInstance, LPCTSTR lpTemplate, 
                    HWND hWndParent, DLGPROC lpDialogFunc)->void { 
                DialogBox(hInstance, lpTemplate, hWndParent, lpDialogFunc); }),
        xlb_f("DialogBoxIndirect", [](
                    HINSTANCE hInstance, LPCDLGTEMPLATE lpTemplate, 
                    HWND hWndParent, DLGPROC lpDialogFunc)->void { 
                ::DialogBoxIndirect(hInstance, lpTemplate, hWndParent, lpDialogFunc);
                }),
        xlb_f("DialogBoxIndirectParam", DialogBoxIndirectParam),
        xlb_f("DialogBoxParam", DialogBoxParam),
        xlb_class<xlb_cbf<DLGPROC>>("DialogProc").constructor<xlb_luafunc>(),
        xlb_f("DisableThreadLibraryCalls", DisableThreadLibraryCalls),
        xlb_f("DisconnectNamedPipe", DisconnectNamedPipe),
        xlb_f("DispatchMessage", DispatchMessage),
        xlb_f("DlgDirList", DlgDirList),
        xlb_f("DlgDirListComboBox", DlgDirListComboBox),
        xlb_f("DlgDirSelectComboBoxEx", DlgDirSelectComboBoxEx),
        //xlb_f("DllEntryPoint", DllEntryPoint),
        xlb_f("DocumentProperties", DocumentProperties),
        xlb_f("DosDateTimeToFileTime", DosDateTimeToFileTime),
        xlb_f("DPtoLP", DPtoLP),
        xlb_f("DragAcceptFiles", DragAcceptFiles),
        xlb_f("DragDetect", DragDetect),
        xlb_f("DragFinish", DragFinish),
        xlb_f("DragQueryFile", DragQueryFile),
        xlb_f("DragQueryPoint", DragQueryPoint),
        xlb_f("DrawAnimatedRects", DrawAnimatedRects),
        xlb_f("DrawCaption", DrawCaption),
        xlb_f("DrawEdge", DrawEdge),
        xlb_f("DrawEscape", DrawEscape),
        xlb_f("DrawFocusRect", DrawFocusRect),
        xlb_f("DrawFrameControl", DrawFrameControl),
        xlb_f("DrawIcon", DrawIcon),
        xlb_f("DrawIconEx", DrawIconEx),
        xlb_f("DrawInsert", DrawInsert),
        xlb_f("DrawMenuBar", DrawMenuBar),
        xlb_f("DrawState", DrawState),
        xlb_class<xlb_cbf<DRAWSTATEPROC>>("DialogProc").constructor<xlb_luafunc>(),
        xlb_f("DrawStatusText", DrawStatusText),
        xlb_f("DrawText", DrawText),
        xlb_f("DrawTextEx", DrawTextEx),
        xlb_f("DuplicateHandle", DuplicateHandle),
        xlb_f("DuplicateToken", DuplicateToken),
        xlb_f("DuplicateTokenEx", DuplicateTokenEx),
        xlb_class<xlb_cbf<EDITWORDBREAKPROC>>("EditWordBreakProc").constructor<xlb_luafunc>(),
        // XXX:EDITWORDBREAKPROCEX is not __attribute__((stdcall))
        xlb_class<xlb_cbf<EDITWORDBREAKPROCEX>>("EditWordBreakProcEx").constructor<xlb_luafunc>(),
        xlb_f("Ellipse", Ellipse),
        xlb_f("EmptyClipboard", EmptyClipboard),
        //xlb_f("EnableEUDC", EnableEUDC), // Windows CE OS
        xlb_f("EnableMenuItem", EnableMenuItem),
        xlb_f("EnableScrollBar", EnableScrollBar),
        xlb_f("EnableWindow", EnableWindow),
        xlb_f("EndDeferWindowPos", EndDeferWindowPos),
        xlb_f("EndDialog", EndDialog),
        xlb_f("EndDoc", EndDoc),
        xlb_f("EndDocPrinter", EndDocPrinter),
        xlb_f("EndPage", EndPage),
        xlb_f("EndPagePrinter", EndPagePrinter),
        xlb_f("EndPaint", EndPaint),
        xlb_f("EndPath", EndPath),
        xlb_f("EndUpdateResource", EndUpdateResource),
        xlb_class<xlb_cbf<ENHMFENUMPROC>>("EnhMetaFileProc").constructor<xlb_luafunc>(),
        xlb_f("EnumCalendarInfo", EnumCalendarInfo),
        xlb_class<xlb_cbf<WNDENUMPROC>>("EnumChildProc").constructor<xlb_luafunc>(),
        xlb_f("EnumChildWindows", EnumChildWindows),
        xlb_f("EnumClipboardFormats", EnumClipboardFormats),
        xlb_class<xlb_cbf<CODEPAGE_ENUMPROC>>("EnumCodePagesProc").constructor<xlb_luafunc>(),
        xlb_f("EnumDateFormats", EnumDateFormats),
        xlb_class<xlb_cbf<DATEFMT_ENUMPROC>>("EnumDateFormatsProc").constructor<xlb_luafunc>(), // Windows 2000 Server
        xlb_f("EnumDependentServices", EnumDependentServices),
        xlb_class<xlb_cbf<DESKTOPENUMPROC>>("EnumDesktopProc").constructor<xlb_luafunc>(),
        xlb_f("EnumDesktops", EnumDesktops),
        xlb_f("EnumDesktopWindows", EnumDesktopWindows),
        xlb_f("EnumDisplaySettings", EnumDisplaySettings),
        xlb_f("EnumEnhMetaFile", EnumEnhMetaFile),
        xlb_class<xlb_cbf<FONTENUMPROC>>("EnumFontFamExProc").constructor<xlb_luafunc>(),
        xlb_f("EnumFontFamilies", EnumFontFamilies),
        xlb_f("EnumFontFamiliesEx", EnumFontFamiliesEx),
        xlb_class<xlb_cbf<FONTENUMPROC>>("EnumFontFamProc").constructor<xlb_luafunc>(),
        xlb_f("EnumFonts", EnumFonts),
        xlb_class<xlb_cbf<FONTENUMPROC>>("EnumFontsProc").constructor<xlb_luafunc>(),
        xlb_f("EnumForms", EnumForms),
        xlb_f("EnumICMProfiles", EnumICMProfiles),
        xlb_class<xlb_cbf<ICMENUMPROC>>("EnumICMProfilesProc").constructor<xlb_luafunc>(),
        xlb_f("EnumJobs", EnumJobs),
        xlb_class<xlb_cbf<LOCALE_ENUMPROC>>("EnumLocalesProc").constructor<xlb_luafunc>(),
        xlb_f("EnumMetaFile", EnumMetaFile),
        xlb_class<xlb_cbf<MFENUMPROC>>("EnumMetaFileProc").constructor<xlb_luafunc>(),
        xlb_f("EnumMonitors", EnumMonitors),
        xlb_f("EnumObjects", EnumObjects),
        xlb_class<xlb_cbf<GOBJENUMPROC>>("EnumObjectsProc").constructor<xlb_luafunc>(),
        xlb_f("EnumPorts", EnumPorts),
        xlb_f("EnumPrinterData", EnumPrinterData),
        xlb_f("EnumPrinterDrivers", EnumPrinterDrivers),
        xlb_f("EnumPrinters", EnumPrinters),
        xlb_f("EnumPrintProcessorDatatypes", EnumPrintProcessorDatatypes),
        xlb_f("EnumPrintProcessors", EnumPrintProcessors),
        xlb_f("EnumProps", EnumProps),
        xlb_f("EnumPropsEx", EnumPropsEx),
        xlb_class<xlb_cbf<REGISTERWORDENUMPROC>>("EnumRegisterWordProc").constructor<xlb_luafunc>(),
        xlb_class<xlb_cbf<ENUMRESLANGPROC>>("EnumResLangProc").constructor<xlb_luafunc>(),
        xlb_class<xlb_cbf<ENUMRESNAMEPROC>>("EnumResNameProc").constructor<xlb_luafunc>(),
        xlb_f("EnumResourceLanguages", EnumResourceLanguages),
        xlb_f("EnumResourceNames", EnumResourceNames),
        xlb_f("EnumResourceTypes", EnumResourceTypes),
        xlb_class<xlb_cbf<ENUMRESTYPEPROC>>("EnumResTypeProc").constructor<xlb_luafunc>(),
        xlb_f("EnumServicesStatus", EnumServicesStatus),
        xlb_f("EnumSystemCodePages", EnumSystemCodePages),
        xlb_f("EnumSystemLocales", EnumSystemLocales),
        //xlb_f("EnumTaskWindows", EnumTaskWindows), // Compatibility
        xlb_f("EnumThreadWindows", EnumThreadWindows),
        xlb_class<xlb_cbf<WNDENUMPROC>>("EnumThreadWndProc").constructor<xlb_luafunc>(),
        xlb_f("EnumTimeFormats", EnumTimeFormats),
        xlb_class<xlb_cbf<TIMEFMT_ENUMPROC>>("EnumTimeFormatsProc").constructor<xlb_luafunc>(),
        xlb_f("EnumWindows", EnumWindows),
        xlb_class<xlb_cbf<WINSTAENUMPROC>>("EnumWindowStationProc").constructor<xlb_luafunc>(),
        xlb_f("EnumWindowStations", EnumWindowStations),
        xlb_f("EqualPrefixSid", EqualPrefixSid),
        xlb_f("EqualRect", EqualRect),
        xlb_f("EqualRgn", EqualRgn),
        xlb_f("EqualSid", EqualSid),
        xlb_f("EraseTape", EraseTape),
        xlb_f("Escape", Escape),
        xlb_f("EscapeCommFunction", EscapeCommFunction),
        xlb_f("ExcludeClipRect", ExcludeClipRect),
        xlb_f("ExcludeUpdateRgn", ExcludeUpdateRgn),
        // XXX: ExitProcess [[noreturn]]
        xlb_f<void (WINAPI*)(UINT)>("ExitProcess", ExitProcess),
        // XXX: ExitThread [[noreturn]]
        xlb_f<void (WINAPI*)(DWORD)>("ExitThread", ExitThread),
        ////xlb_f("ExitWindows", ExitWindows),
        xlb_f("ExitWindowsEx", ExitWindowsEx),
        xlb_f("ExpandEnvironmentStrings", ExpandEnvironmentStrings),
        xlb_f("ExtCreatePen", ExtCreatePen),
        ////xlb_f("ExtensionPropSheetPageProc", ExtensionPropSheetPageProc), // Windows CE
        xlb_f("ExtEscape", ExtEscape),
        xlb_f("ExtFloodFill", ExtFloodFill),
        xlb_f("ExtractAssociatedIcon", ExtractAssociatedIcon),
        xlb_f("ExtractIcon", ExtractIcon),
        xlb_f("ExtractIconEx", ExtractIconEx),
        xlb_f("ExtSelectClipRgn", ExtSelectClipRgn),
        xlb_f("ExtTextOut", ExtTextOut),
        xlb_f("FatalAppExit", FatalAppExit),
        xlb_f("FatalExit", FatalExit),
        xlb_class<xlb_cbf<LPOVERLAPPED_COMPLETION_ROUTINE>>("FileIOCompletionRoutine").constructor<xlb_luafunc>(),
        xlb_f("FileTimeToDosDateTime", FileTimeToDosDateTime),
        xlb_f("FileTimeToLocalFileTime", FileTimeToLocalFileTime),
        xlb_f("FileTimeToSystemTime", FileTimeToSystemTime),
        xlb_f("FillConsoleOutputAttribute", FillConsoleOutputAttribute),
        xlb_f("FillConsoleOutputCharacter", FillConsoleOutputCharacter),
        xlb_f("FillMemory", [](PVOID Destination, SIZE_T length, BYTE Fill)->void { 
                ::FillMemory(Destination, length, Fill); }),
        xlb_f("FillPath", FillPath),
        xlb_f("FillRect", FillRect),
        xlb_f("FillRgn", FillRgn),
        xlb_f("FindAtom", FindAtom),
        xlb_f("FindClose", FindClose),
        xlb_f("FindCloseChangeNotification", FindCloseChangeNotification),
        xlb_f("FindClosePrinterChangeNotification", FindClosePrinterChangeNotification),
        xlb_f("FindExecutable", FindExecutable),
        xlb_f("FindFirstChangeNotification", FindFirstChangeNotification),
        xlb_f("FindFirstFile", FindFirstFile),
        xlb_f("FindFirstFileEx", FindFirstFileEx),
        xlb_f("FindFirstFreeAce", FindFirstFreeAce),
        xlb_f("FindFirstPrinterChangeNotification", FindFirstPrinterChangeNotification),
        xlb_f("FindNextChangeNotification", FindNextChangeNotification),
        xlb_f("FindNextFile", FindNextFile),
        xlb_f("FindNextPrinterChangeNotification", FindNextPrinterChangeNotification),
        xlb_f("FindResource", FindResource),
        xlb_f("FindResourceEx", FindResourceEx),
        xlb_f("FindText", FindText),
        xlb_f("FindWindow", FindWindow),
        xlb_f("FindWindowEx", FindWindowEx),
        xlb_f("FixBrushOrgEx", FixBrushOrgEx),
        xlb_f("FlashWindow", FlashWindow),
        xlb_f("FlattenPath", FlattenPath),
        xlb_f("FloodFill", FloodFill),
        xlb_f("FlushConsoleInputBuffer", FlushConsoleInputBuffer),
        xlb_f("FlushFileBuffers", FlushFileBuffers),
        xlb_f("FlushInstructionCache", FlushInstructionCache),
        xlb_f("FlushViewOfFile", FlushViewOfFile),
        xlb_class<xlb_cbf<FMEXTENSIONPROC>>("FMExtensionProc").constructor<xlb_luafunc>(), // Windows 2000
        xlb_f("FoldString", FoldString),
        xlb_class<xlb_cbf<HOOKPROC>>("ForegroundIdleProc").constructor<xlb_luafunc>(),
        xlb_f("FormatMessage", FormatMessage),
        xlb_f("FrameRect", FrameRect),
        xlb_f("FrameRgn", FrameRgn),
        xlb_f("FreeConsole", FreeConsole),
        xlb_f("FreeDDElParam", FreeDDElParam),
        xlb_f("FreeEnvironmentStrings", FreeEnvironmentStrings),
        xlb_f("FreeLibrary", FreeLibrary),
        // XXX: FreeLibraryAndExitThread [[noreturn]]
        xlb_f<void (WINAPI*)(HMODULE,DWORD)>("FreeLibraryAndExitThread", FreeLibraryAndExitThread), //[[noreturn]]
        ////xlb_f("FreeModule", FreeModule), // Outdated
        xlb_f("FreePrinterNotifyInfo", FreePrinterNotifyInfo),
        ////xlb_f("FreeProcInstance", FreeProcInstance), // Outdated
        xlb_f("FreeResource", FreeResource),
        xlb_f("FreeSid", FreeSid),
        xlb_class<xlb_cbf<LPFRHOOKPROC>>("FRHookProc").constructor<xlb_luafunc>(),
        xlb_f("GdiComment", GdiComment),
        xlb_f("GdiFlush", GdiFlush),
        xlb_f("GdiGetBatchLimit", GdiGetBatchLimit),
        xlb_f("GdiSetBatchLimit", GdiSetBatchLimit),
        xlb_f("GenerateConsoleCtrlEvent", GenerateConsoleCtrlEvent),
        xlb_f("GetAce", GetAce),
        xlb_f("GetAclInformation", GetAclInformation),
        xlb_f("GetACP", GetACP),
        xlb_f("GetActiveWindow", GetActiveWindow),
        xlb_f("GetArcDirection", GetArcDirection),
        xlb_f("GetAspectRatioFilterEx", GetAspectRatioFilterEx),
        xlb_f("GetAsyncKeyState", GetAsyncKeyState),
        xlb_f("GetAtomName", GetAtomName),
        xlb_f("GetAuditedPermissionsFromAcl", GetAuditedPermissionsFromAcl),
        xlb_f("GetBinaryType", GetBinaryType),
        xlb_f("GetBitmapBits", GetBitmapBits),
        xlb_f("GetBitmapDimensionEx", GetBitmapDimensionEx),
        xlb_f("GetBkColor", GetBkColor),
        xlb_f("GetBkMode", GetBkMode),
        xlb_f("GetBoundsRect", GetBoundsRect),
        xlb_f("GetBrushOrgEx", GetBrushOrgEx),
        xlb_f("GetCapture", GetCapture),
        xlb_f("GetCaretBlinkTime", GetCaretBlinkTime),
        xlb_f("GetCaretPos", GetCaretPos),
        xlb_f("GetCharABCWidths", GetCharABCWidths),
        xlb_f("GetCharABCWidthsFloat", GetCharABCWidthsFloat),
        xlb_f("GetCharacterPlacement", GetCharacterPlacement),
        xlb_f("GetCharWidth", GetCharWidth),
        xlb_f("GetCharWidth32", GetCharWidth32),
        xlb_f("GetCharWidthFloat", GetCharWidthFloat),
        xlb_f("GetClassInfo", GetClassInfo),
        xlb_f("GetClassInfoEx", GetClassInfoEx),
        xlb_f("GetClassLong", GetClassLong),
        xlb_f("GetClassName", GetClassName),
        xlb_f("GetClassWord", GetClassWord),
        xlb_f("GetClientRect", GetClientRect),
        xlb_f("GetClipboardData", GetClipboardData),
        xlb_f("GetClipboardFormatName", GetClipboardFormatName),
        xlb_f("GetClipboardOwner", GetClipboardOwner),
        xlb_f("GetClipboardViewer", GetClipboardViewer),
        xlb_f("GetClipBox", GetClipBox),
        xlb_f("GetClipCursor", GetClipCursor),
        xlb_f("GetClipRgn", GetClipRgn),
        xlb_f("GetColorAdjustment", GetColorAdjustment),
        xlb_f("GetColorSpace", GetColorSpace),
        xlb_f("GetCommandLine", GetCommandLine),
        xlb_f("GetCommConfig", GetCommConfig),
        xlb_f("GetCommMask", GetCommMask),
        xlb_f("GetCommModemStatus", GetCommModemStatus),
        xlb_f("GetCommProperties", GetCommProperties),
        xlb_f("GetCommState", GetCommState),
        xlb_f("GetCommTimeouts", GetCommTimeouts),
        xlb_f("GetCompressedFileSize", GetCompressedFileSize),
        xlb_f("GetComputerName", GetComputerName),
        xlb_f("GetConsoleCP", GetConsoleCP),
        xlb_f("GetConsoleCursorInfo", GetConsoleCursorInfo),
        xlb_f("GetConsoleMode", GetConsoleMode),
        xlb_f("GetConsoleOutputCP", GetConsoleOutputCP),
        xlb_f("GetConsoleScreenBufferInfo", GetConsoleScreenBufferInfo),
        xlb_f("GetConsoleTitle", GetConsoleTitle),
        xlb_f("GetCPInfo", GetCPInfo),
        xlb_f("GetCurrencyFormat", GetCurrencyFormat),
        xlb_f("GetCurrentDirectory", GetCurrentDirectory),
        xlb_f("GetCurrentFiber", GetCurrentFiber),
        xlb_f("GetCurrentHwProfile", GetCurrentHwProfile),
        xlb_f("GetCurrentObject", GetCurrentObject),
        xlb_f("GetCurrentPositionEx", GetCurrentPositionEx),
        xlb_f("GetCurrentProcess", GetCurrentProcess),
        xlb_f("GetCurrentProcessId", GetCurrentProcessId),
        xlb_f("GetCurrentThread", GetCurrentThread),
        xlb_f("GetCurrentThreadId", GetCurrentThreadId),
        //xlb_f("GetCurrentTime", GetCurrentTime), //FIXME
        xlb_f("GetCursor", GetCursor),
        xlb_f("GetCursorPos", GetCursorPos),
        xlb_f("GetDateFormat", GetDateFormat),
        xlb_f("GetDC", GetDC),
        xlb_f("GetDCEx", GetDCEx),
        xlb_f("GetDCOrgEx", GetDCOrgEx),
        xlb_f("GetDefaultCommConfig", GetDefaultCommConfig),
        xlb_f("GetDesktopWindow", GetDesktopWindow),
        xlb_f("GetDeviceCaps", GetDeviceCaps),
        xlb_f("GetDeviceGammaRamp", GetDeviceGammaRamp),
        xlb_f("GetDialogBaseUnits", GetDialogBaseUnits),
        xlb_f("GetDIBits", GetDIBits),
        xlb_f("GetDiskFreeSpace", GetDiskFreeSpace),
        xlb_f("GetDiskFreeSpaceEx", GetDiskFreeSpaceEx),
        xlb_f("GetDlgCtrlID", GetDlgCtrlID),
        xlb_f("GetDlgItem", GetDlgItem),
        xlb_f("GetDlgItemInt", GetDlgItemInt),
        xlb_f("GetDlgItemText", GetDlgItemText),
        xlb_f("GetDoubleClickTime", GetDoubleClickTime),
        xlb_f("GetDriveType", GetDriveType),
        xlb_f("GetEffectiveClientRect", GetEffectiveClientRect),
        xlb_f("GetEffectiveRightsFromAcl", GetEffectiveRightsFromAcl),
        xlb_f("GetEnhMetaFile", GetEnhMetaFile),
        xlb_f("GetEnhMetaFileBits", GetEnhMetaFileBits),
        xlb_f("GetEnhMetaFileDescription", GetEnhMetaFileDescription),
        xlb_f("GetEnhMetaFileHeader", GetEnhMetaFileHeader),
        xlb_f("GetEnhMetaFilePaletteEntries", GetEnhMetaFilePaletteEntries),
        xlb_f("GetEnvironmentStrings", GetEnvironmentStrings),
        xlb_f("GetEnvironmentVariable", GetEnvironmentVariable),
        ////xlb_f("GetExceptionCode", []()->DWORD { return GetExceptionCode(); }),
        ////xlb_f("GetExceptionInformation", []()->LPEXCEPTION_POINTERS { return GetExceptionInformation(); }),
        xlb_f("GetExitCodeProcess", GetExitCodeProcess),
        xlb_f("GetExitCodeThread", GetExitCodeThread),
        xlb_f("GetExpandedName", GetExpandedName),
        xlb_f("GetExplicitEntriesFromAcl", GetExplicitEntriesFromAcl),
        xlb_f("GetFiberData", GetFiberData),
        xlb_f("GetFileAttributes", GetFileAttributes),
        xlb_f("GetFileAttributesEx", GetFileAttributesEx),
        xlb_f("GetFileInformationByHandle", GetFileInformationByHandle),
        xlb_f("GetFileSecurity", GetFileSecurity),
        xlb_f("GetFileSize", GetFileSize),
        xlb_f("GetFileTime", GetFileTime),
        xlb_f("GetFileTitle", GetFileTitle),
        xlb_f("GetFileType", GetFileType),
        xlb_f("GetFileVersionInfo", GetFileVersionInfo),
        xlb_f("GetFileVersionInfoSize", GetFileVersionInfoSize),
        xlb_f("GetFocus", GetFocus),
        xlb_f("GetFontData", GetFontData),
        xlb_f("GetFontLanguageInfo", GetFontLanguageInfo),
        xlb_f("GetForegroundWindow", GetForegroundWindow),
        xlb_f("GetForm", GetForm),
        ////xlb_f("GetFreeSpace", GetFreeSpace), //FIXME
        xlb_f("GetFullPathName", GetFullPathName),
        xlb_f("GetGlyphOutline", GetGlyphOutline),
        xlb_f("GetGraphicsMode", GetGraphicsMode),
        xlb_f("GetHandleInformation", GetHandleInformation),
        xlb_f("GetICMProfile", GetICMProfile),
        xlb_f("GetIconInfo", GetIconInfo),
        xlb_f("GetInputState", GetInputState),
        xlb_f("GetJob", GetJob),
        xlb_f("GetKBCodePage", GetKBCodePage),
        xlb_f("GetKernelObjectSecurity", GetKernelObjectSecurity),
        xlb_f("GetKerningPairs", GetKerningPairs),
        xlb_f("GetKeyboardLayout", GetKeyboardLayout),
        xlb_f("GetKeyboardLayoutList", GetKeyboardLayoutList),
        xlb_f("GetKeyboardLayoutName", GetKeyboardLayoutName),
        xlb_f("GetKeyboardState", GetKeyboardState),
        xlb_f("GetKeyboardType", GetKeyboardType),
        xlb_f("GetKeyNameText", GetKeyNameText),
        xlb_f("GetKeyState", GetKeyState),
        xlb_f("GetLargestConsoleWindowSize", GetLargestConsoleWindowSize),
        xlb_f("GetLastActivePopup", GetLastActivePopup),
        xlb_f("GetLastError", GetLastError),
        xlb_f("GetLengthSid", GetLengthSid),
        xlb_f("GetLocaleInfo", GetLocaleInfo),
        xlb_f("GetLocalTime", GetLocalTime),
        xlb_f("GetLogColorSpace", GetLogColorSpace),
        xlb_f("GetLogicalDrives", GetLogicalDrives),
        xlb_f("GetLogicalDriveStrings", GetLogicalDriveStrings),
        xlb_f("GetMailslotInfo", GetMailslotInfo),
        xlb_f("GetMapMode", GetMapMode),
        xlb_f("GetMenu", GetMenu),
        xlb_f("GetMenuCheckMarkDimensions", GetMenuCheckMarkDimensions),
        xlb_f("GetMenuContextHelpId", GetMenuContextHelpId),
        xlb_f("GetMenuDefaultItem", GetMenuDefaultItem),
        xlb_f("GetMenuItemCount", GetMenuItemCount),
        xlb_f("GetMenuItemID", GetMenuItemID),
        xlb_f("GetMenuItemInfo", GetMenuItemInfo),
        xlb_f("GetMenuItemRect", GetMenuItemRect),
        xlb_f("GetMenuState", GetMenuState),
        xlb_f("GetMenuString", GetMenuString),
        xlb_f("GetMessage", GetMessage),
        xlb_f("GetMessageExtraInfo", GetMessageExtraInfo),
        xlb_f("GetMessagePos", GetMessagePos),
        xlb_f("GetMessageTime", GetMessageTime),
        xlb_f("GetMetaFile", GetMetaFile),
        xlb_f("GetMetaFileBitsEx", GetMetaFileBitsEx),
        xlb_f("GetMetaRgn", GetMetaRgn),
        xlb_f("GetMiterLimit", GetMiterLimit),
        xlb_f("GetModuleFileName", GetModuleFileName),
        xlb_f("GetModuleHandle", GetModuleHandle),
        xlb_class<xlb_cbf<HOOKPROC>>("GetMsgProc").constructor<xlb_luafunc>(),
        xlb_f("GetMultipleTrustee", GetMultipleTrustee),
        xlb_f("GetMultipleTrusteeOperation", GetMultipleTrusteeOperation),
        xlb_f("GetNamedPipeHandleState", GetNamedPipeHandleState),
        xlb_f("GetNamedPipeInfo", GetNamedPipeInfo),
        xlb_f("GetNamedSecurityInfo", GetNamedSecurityInfo),
        xlb_f("GetNearestColor", GetNearestColor),
        xlb_f("GetNearestPaletteIndex", GetNearestPaletteIndex),
        xlb_f("GetNextDlgGroupItem", GetNextDlgGroupItem),
        xlb_f("GetNextDlgTabItem", GetNextDlgTabItem),
        xlb_f("GetNextWindow", GetWindow), //XXX:
        xlb_f("GetNumberFormat", GetNumberFormat),
        xlb_f("GetNumberOfConsoleInputEvents", GetNumberOfConsoleInputEvents),
        xlb_f("GetNumberOfConsoleMouseButtons", GetNumberOfConsoleMouseButtons),
        xlb_f("GetNumberOfEventLogRecords", GetNumberOfEventLogRecords),
        xlb_f("GetObject", GetObject),
        xlb_f("GetObjectType", GetObjectType),
        xlb_f("GetOEMCP", GetOEMCP),
        xlb_f("GetOldestEventLogRecord", GetOldestEventLogRecord),
        xlb_f("GetOpenClipboardWindow", GetOpenClipboardWindow),
        xlb_f("GetOpenFileName", GetOpenFileName),
        xlb_f("GetOutlineTextMetrics", GetOutlineTextMetrics),
        xlb_f("GetOverlappedResult", GetOverlappedResult),
        xlb_f("GetPaletteEntries", GetPaletteEntries),
        xlb_f("GetParent", GetParent),
        xlb_f("GetPath", GetPath),
        xlb_f("GetPixel", GetPixel),
        xlb_f("GetPolyFillMode", GetPolyFillMode),
        xlb_f("GetPrinter", GetPrinter),
        xlb_f("GetPrinterData", GetPrinterData),
        xlb_f("GetPrinterDriver", GetPrinterDriver),
        xlb_f("GetPrinterDriverDirectory", GetPrinterDriverDirectory),
        xlb_f("GetPrintProcessorDirectory", GetPrintProcessorDirectory),
        xlb_f("GetPriorityClass", GetPriorityClass),
        xlb_f("GetPriorityClipboardFormat", GetPriorityClipboardFormat),
        xlb_f("GetPrivateObjectSecurity", GetPrivateObjectSecurity),
        xlb_f("GetPrivateProfileInt", GetPrivateProfileInt),
        xlb_f("GetPrivateProfileSection", GetPrivateProfileSection),
        xlb_f("GetPrivateProfileSectionNames", GetPrivateProfileSectionNames),
        xlb_f("GetPrivateProfileString", GetPrivateProfileString),
        xlb_f("GetPrivateProfileStruct", GetPrivateProfileStruct),
        xlb_f("GetProcAddress", GetProcAddress),
        xlb_f("GetProcessAffinityMask", GetProcessAffinityMask),
        xlb_f("GetProcessHeap", GetProcessHeap),
        xlb_f("GetProcessHeaps", GetProcessHeaps),
        xlb_f("GetProcessPriorityBoost", GetProcessPriorityBoost),
        xlb_f("GetProcessShutdownParameters", GetProcessShutdownParameters),
        xlb_f("GetProcessTimes", GetProcessTimes),
        xlb_f("GetProcessVersion", GetProcessVersion),
        xlb_f("GetProcessWindowStation", GetProcessWindowStation),
        xlb_f("GetProcessWorkingSetSize", GetProcessWorkingSetSize),
        xlb_f("GetProfileInt", GetProfileInt),
        xlb_f("GetProfileSection", GetProfileSection),
        xlb_f("GetProfileString", GetProfileString),
        xlb_f("GetProp", GetProp),
        xlb_f("GetQueuedCompletionStatus", GetQueuedCompletionStatus),
        xlb_f("GetQueueStatus", GetQueueStatus),
        xlb_f("GetRasterizerCaps", GetRasterizerCaps),
        xlb_f("GetRegionData", GetRegionData),
        xlb_f("GetRgnBox", GetRgnBox),
        xlb_f("GetROP2", GetROP2),
        xlb_f("GetSaveFileName", GetSaveFileName),
        xlb_f("GetScrollInfo", GetScrollInfo),
        xlb_f("GetScrollPos", GetScrollPos),
        xlb_f("GetScrollRange", GetScrollRange),
        xlb_f("GetSecurityDescriptorControl", GetSecurityDescriptorControl),
        xlb_f("GetSecurityDescriptorDacl", GetSecurityDescriptorDacl),
        xlb_f("GetSecurityDescriptorGroup", GetSecurityDescriptorGroup),
        xlb_f("GetSecurityDescriptorLength", GetSecurityDescriptorLength),
        xlb_f("GetSecurityDescriptorOwner", GetSecurityDescriptorOwner),
        xlb_f("GetSecurityDescriptorSacl", GetSecurityDescriptorSacl),
        xlb_f("GetSecurityInfo", GetSecurityInfo),
        xlb_f("GetServiceDisplayName", GetServiceDisplayName),
        xlb_f("GetServiceKeyName", GetServiceKeyName),
        xlb_f("GetShortPathName", GetShortPathName),
        xlb_f("GetSidIdentifierAuthority", GetSidIdentifierAuthority),
        xlb_f("GetSidLengthRequired", GetSidLengthRequired),
        xlb_f("GetSidSubAuthority", GetSidSubAuthority),
        xlb_f("GetSidSubAuthorityCount", GetSidSubAuthorityCount),
        xlb_f("GetStartupInfo", GetStartupInfo),
        xlb_f("GetStdHandle", GetStdHandle),
        xlb_f("GetStockObject", GetStockObject),
        xlb_f("GetStretchBltMode", GetStretchBltMode),
        xlb_f("GetStringTypeA", GetStringTypeA),
        xlb_f("GetStringTypeEx", GetStringTypeEx),
        xlb_f("GetStringTypeW", GetStringTypeW),
        xlb_f("GetSubMenu", GetSubMenu),
        xlb_f("GetSysColor", GetSysColor),
        xlb_f("GetSysColorBrush", GetSysColorBrush),
        ////xlb_f("GetSysModalWindow", GetSysModalWindow), //FIXME
        xlb_f("GetSystemDefaultLangID", GetSystemDefaultLangID),
        xlb_f("GetSystemDefaultLCID", GetSystemDefaultLCID),
        xlb_f("GetSystemDirectory", GetSystemDirectory),
        xlb_f("GetSystemInfo", GetSystemInfo),
        xlb_f("GetSystemMenu", GetSystemMenu),
        xlb_f("GetSystemMetrics", GetSystemMetrics),
        xlb_f("GetSystemPaletteEntries", GetSystemPaletteEntries),
        xlb_f("GetSystemPaletteUse", GetSystemPaletteUse),
        xlb_f("GetSystemTime", GetSystemTime),
        xlb_f("GetSystemTimeAdjustment", GetSystemTimeAdjustment),
        xlb_f("GetSystemTimeAsFileTime", GetSystemTimeAsFileTime),
        xlb_f("GetTabbedTextExtent", GetTabbedTextExtent),
        xlb_f("GetTapeParameters", GetTapeParameters),
        xlb_f("GetTapePosition", GetTapePosition),
        xlb_f("GetTapeStatus", GetTapeStatus),
        xlb_f("GetTempFileName", GetTempFileName),
        xlb_f("GetTempPath", GetTempPath),
        xlb_f("GetTextAlign", GetTextAlign),
        xlb_f("GetTextCharacterExtra", GetTextCharacterExtra),
        xlb_f("GetTextCharset", GetTextCharset),
        xlb_f("GetTextCharsetInfo", GetTextCharsetInfo),
        xlb_f("GetTextColor", GetTextColor),
        xlb_f("GetTextExtentExPoint", GetTextExtentExPoint),
        xlb_f("GetTextExtentPoint", GetTextExtentPoint),
        xlb_f("GetTextExtentPoint32", GetTextExtentPoint32),
        xlb_f("GetTextFace", GetTextFace),
        xlb_f("GetTextMetrics", GetTextMetrics),
        xlb_f("GetThreadContext", GetThreadContext),
        xlb_f("GetThreadDesktop", GetThreadDesktop),
        xlb_f("GetThreadLocale", GetThreadLocale),
        xlb_f("GetThreadPriority", GetThreadPriority),
        xlb_f("GetThreadPriorityBoost", GetThreadPriorityBoost),
        xlb_f("GetThreadSelectorEntry", GetThreadSelectorEntry),
        xlb_f("GetThreadTimes", GetThreadTimes),
        xlb_f("GetTickCount", GetTickCount),
        xlb_f("GetTimeFormat", GetTimeFormat),
        xlb_f("GetTimeZoneInformation", GetTimeZoneInformation),
        xlb_f("GetTokenInformation", GetTokenInformation),
        xlb_f("GetTopWindow", GetTopWindow),
        xlb_f("GetTrusteeForm", GetTrusteeForm),
        xlb_f("GetTrusteeName", GetTrusteeName),
        xlb_f("GetTrusteeType", GetTrusteeType),
        xlb_f("GetUpdateRect", GetUpdateRect),
        xlb_f("GetUpdateRgn", GetUpdateRgn),
        xlb_f("GetUserDefaultLangID", GetUserDefaultLangID),
        xlb_f("GetUserDefaultLCID", GetUserDefaultLCID),
        xlb_f("GetUserName", GetUserName),
        xlb_f("GetUserObjectInformation", GetUserObjectInformation),
        xlb_f("GetUserObjectSecurity", GetUserObjectSecurity),
        ////xlb_f("GetVersion", GetVersion), // deprecated
        ////xlb_f("GetVersionEx", GetVersionEx), // deprecated
        xlb_f("GetViewportExtEx", GetViewportExtEx),
        xlb_f("GetViewportOrgEx", GetViewportOrgEx),
        xlb_f("GetVolumeInformation", GetVolumeInformation),
        xlb_f("GetWindow", GetWindow),
        xlb_f("GetWindowContextHelpId", GetWindowContextHelpId),
        xlb_f("GetWindowDC", GetWindowDC),
        xlb_f("GetWindowExtEx", GetWindowExtEx),
        xlb_f("GetWindowLong", GetWindowLong),
        xlb_f("GetWindowOrgEx", GetWindowOrgEx),
        xlb_f("GetWindowPlacement", GetWindowPlacement),
        xlb_f("GetWindowRect", GetWindowRect),
        xlb_f("GetWindowRgn", GetWindowRgn),
        xlb_f("GetWindowsDirectory", GetWindowsDirectory),
        ////xlb_f("GetWindowTask", GetWindowTask), // Outdated
        xlb_f("GetWindowText", GetWindowText),
        xlb_f("GetWindowTextLength", GetWindowTextLength),
        xlb_f("GetWindowThreadProcessId", GetWindowThreadProcessId),
        xlb_f("GetWindowWord", GetWindowWord),
        xlb_f("GetWinMetaFileBits", GetWinMetaFileBits),
        xlb_f("GetWorldTransform", GetWorldTransform),
        xlb_f("GlobalAddAtom", GlobalAddAtom),
        xlb_f("GlobalAlloc", GlobalAlloc),
        xlb_f("GlobalCompact", GlobalCompact),
        xlb_f("GlobalDeleteAtom", GlobalDeleteAtom),
        xlb_f("GlobalDiscard", [](HGLOBAL h)->void { GlobalDiscard(h); }),
        xlb_f("GlobalFindAtom", GlobalFindAtom),
        xlb_f("GlobalFix", GlobalFix),
        xlb_f("GlobalFlags", GlobalFlags),
        xlb_f("GlobalFree", GlobalFree),
        xlb_f("GlobalGetAtomName", GlobalGetAtomName),
        xlb_f("GlobalHandle", GlobalHandle),
        xlb_f("GlobalLock", GlobalLock),
        ////xlb_f("GlobalLRUNewest", GlobalLRUNewest), // Outdated
        ////xlb_f("GlobalLRUOldest", GlobalLRUOldest), // Outdated
        xlb_f("GlobalMemoryStatus", GlobalMemoryStatus),
        xlb_f("GlobalReAlloc", GlobalReAlloc),
        xlb_f("GlobalSize", GlobalSize),
        xlb_f("GlobalUnfix", GlobalUnfix),
        xlb_f("GlobalUnlock", GlobalUnlock),
        xlb_f("GlobalUnWire", GlobalUnWire),
        xlb_f("GlobalWire", GlobalWire),
        xlb_f("GrayString", GrayString),
        xlb_class<xlb_cbf<PHANDLER_ROUTINE>>("HandlerRoutine").constructor<xlb_luafunc>(),
        xlb_f("HeapAlloc", HeapAlloc),
        xlb_f("HeapCompact", HeapCompact),
        xlb_f("HeapCreate", HeapCreate),
        xlb_f("HeapDestroy", HeapDestroy),
        xlb_f("HeapLock", HeapLock),
        xlb_f("HeapReAlloc", HeapReAlloc),
        xlb_f("HeapSize", HeapSize),
        xlb_f("HeapUnlock", HeapUnlock),
        xlb_f("HeapValidate", HeapValidate),
        xlb_f("HeapWalk", HeapWalk),
        xlb_f("HideCaret", HideCaret),
        xlb_f("HiliteMenuItem", HiliteMenuItem),
        //xlb_f("ImageList_Add", ImageList_Add),
        //xlb_f("ImageList_AddMasked", ImageList_AddMasked),
        //xlb_f("ImageList_BeginDrag", ImageList_BeginDrag),
        //xlb_f("ImageList_Create", ImageList_Create),
        //xlb_f("ImageList_Destroy", ImageList_Destroy),
        //xlb_f("ImageList_DragEnter", ImageList_DragEnter),
        //xlb_f("ImageList_DragLeave", ImageList_DragLeave),
        //xlb_f("ImageList_DragMove", ImageList_DragMove),
        //xlb_f("ImageList_DragShowNolock", ImageList_DragShowNolock),
        //xlb_f("ImageList_Draw", ImageList_Draw),
        //xlb_f("ImageList_DrawEx", ImageList_DrawEx),
        //xlb_f("ImageList_EndDrag", ImageList_EndDrag),
        //xlb_f("ImageList_ExtractIcon", ImageList_ExtractIcon), // FIXME Macro
        //xlb_f("ImageList_GetBkColor", ImageList_GetBkColor),
        //xlb_f("ImageList_GetDragImage", ImageList_GetDragImage),
        //xlb_f("ImageList_GetIcon", ImageList_GetIcon),
        //xlb_f("ImageList_GetIconSize", ImageList_GetIconSize),
        //xlb_f("ImageList_GetImageCount", ImageList_GetImageCount),
        //xlb_f("ImageList_GetImageInfo", ImageList_GetImageInfo),
        //xlb_f("ImageList_LoadBitmap", ImageList_LoadBitmap),
        //xlb_f("ImageList_LoadImage", ImageList_LoadImage),
        //xlb_f("ImageList_Merge", ImageList_Merge),
        //xlb_f("ImageList_Read", ImageList_Read),
        //xlb_f("ImageList_Remove", ImageList_Remove),
        //xlb_f("ImageList_Replace", ImageList_Replace),
        //xlb_f("ImageList_ReplaceIcon", ImageList_ReplaceIcon),
        //xlb_f("ImageList_SetBkColor", ImageList_SetBkColor),
        //xlb_f("ImageList_SetDragCursorImage", ImageList_SetDragCursorImage),
        //xlb_f("ImageList_SetIconSize", ImageList_SetIconSize),
        //xlb_f("ImageList_SetOverlayImage", ImageList_SetOverlayImage),
        //xlb_f("ImageList_Write", ImageList_Write),
        xlb_f("ImmAssociateContext", ImmAssociateContext),
        xlb_f("ImmConfigureIME", ImmConfigureIME),
        xlb_f("ImmCreateContext", ImmCreateContext),
        xlb_f("ImmDestroyContext", ImmDestroyContext),
        xlb_f("ImmEnumRegisterWord", ImmEnumRegisterWord),
        xlb_f("ImmEscape", ImmEscape),
        xlb_f("ImmGetCandidateList", ImmGetCandidateList),
        xlb_f("ImmGetCandidateListCount", ImmGetCandidateListCount),
        xlb_f("ImmGetCandidateWindow", ImmGetCandidateWindow),
        xlb_f("ImmGetCompositionFont", ImmGetCompositionFont),
        xlb_f("ImmGetCompositionString", ImmGetCompositionString),
        xlb_f("ImmGetCompositionWindow", ImmGetCompositionWindow),
        xlb_f("ImmGetContext", ImmGetContext),
        xlb_f("ImmGetConversionList", ImmGetConversionList),
        xlb_f("ImmGetConversionStatus", ImmGetConversionStatus),
        xlb_f("ImmGetDefaultIMEWnd", ImmGetDefaultIMEWnd),
        xlb_f("ImmGetDescription", ImmGetDescription),
        xlb_f("ImmGetGuideLine", ImmGetGuideLine),
        xlb_f("ImmGetIMEFileName", ImmGetIMEFileName),
        xlb_f("ImmGetOpenStatus", ImmGetOpenStatus),
        xlb_f("ImmGetProperty", ImmGetProperty),
        xlb_f("ImmGetRegisterWordStyle", ImmGetRegisterWordStyle),
        xlb_f("ImmGetStatusWindowPos", ImmGetStatusWindowPos),
        xlb_f("ImmGetVirtualKey", ImmGetVirtualKey),
        xlb_f("ImmInstallIME", ImmInstallIME),
        xlb_f("ImmIsIME", ImmIsIME),
        xlb_f("ImmIsUIMessage", ImmIsUIMessage),
        xlb_f("ImmNotifyIME", ImmNotifyIME),
        xlb_f("ImmRegisterWord", ImmRegisterWord),
        xlb_f("ImmReleaseContext", ImmReleaseContext),
        xlb_f("ImmSetCandidateWindow", ImmSetCandidateWindow),
        xlb_f("ImmSetCompositionFont", ImmSetCompositionFont),
        xlb_f("ImmSetCompositionString", ImmSetCompositionString),
        xlb_f("ImmSetCompositionWindow", ImmSetCompositionWindow),
        xlb_f("ImmSetConversionStatus", ImmSetConversionStatus),
        xlb_f("ImmSetOpenStatus", ImmSetOpenStatus),
        xlb_f("ImmSetStatusWindowPos", ImmSetStatusWindowPos),
        xlb_f("ImmSimulateHotKey", ImmSimulateHotKey),
        xlb_f("ImmUnregisterWord", ImmUnregisterWord),
        xlb_f("ImpersonateDdeClientWindow", ImpersonateDdeClientWindow),
        xlb_f("ImpersonateLoggedOnUser", ImpersonateLoggedOnUser),
        xlb_f("ImpersonateNamedPipeClient", ImpersonateNamedPipeClient),
        xlb_f("ImpersonateSelf", ImpersonateSelf),
        xlb_f("InflateRect", InflateRect),
        xlb_f("InitAtomTable", InitAtomTable),
        xlb_f("InitCommonControls", InitCommonControls),
        xlb_f("InitializeAcl", InitializeAcl),
        xlb_f("InitializeCriticalSection", InitializeCriticalSection),
        xlb_f("InitializeSecurityDescriptor", InitializeSecurityDescriptor),
        xlb_f("InitializeSid", InitializeSid),
        xlb_f("InitiateSystemShutdown", InitiateSystemShutdown),
        xlb_f("InSendMessage", InSendMessage),
        xlb_f("InsertMenu", InsertMenu),
        xlb_f("InsertMenuItem", InsertMenuItem),
        xlb_f("Int32x32To64", [](int32_t a, int32_t b)->int64_t { return Int32x32To64(a,b); }),
        xlb_f("Int64ShllMod32", [](uint64_t a, uint32_t b)->uint32_t { return Int64ShllMod32(a,b); }),
        xlb_f("Int64ShraMod32", [](uint64_t a, uint32_t b)->uint32_t { return Int64ShraMod32(a,b); }),
        xlb_f("Int64ShrlMod32", [](uint64_t a, uint32_t b)->uint32_t { return Int64ShrlMod32(a,b); }),
        //xlb_f("InterlockedCompareExchange", InterlockedCompareExchange), //FIXME
        //xlb_f("InterlockedDecrement", InterlockedDecrement), //FIXME
        //xlb_f("InterlockedExchange", InterlockedExchange), //FIXME
        //xlb_f("InterlockedExchangeAdd", InterlockedExchangeAdd), //FIXME
        //xlb_f("InterlockedIncrement", InterlockedIncrement), //FIXME
        xlb_f("IntersectClipRect", IntersectClipRect),
        xlb_f("IntersectRect", IntersectRect),
        xlb_f("InvalidateRect", InvalidateRect),
        xlb_f("InvalidateRgn", InvalidateRgn),
        xlb_f("InvertRect", InvertRect),
        xlb_f("InvertRgn", InvertRgn),
        xlb_f("IsBadCodePtr", IsBadCodePtr),
        xlb_f("IsBadHugeReadPtr", IsBadHugeReadPtr),
        xlb_f("IsBadHugeWritePtr", IsBadHugeWritePtr),
        xlb_f("IsBadReadPtr", IsBadReadPtr),
        xlb_f("IsBadStringPtr", IsBadStringPtr),
        xlb_f("IsBadWritePtr", IsBadWritePtr),
        xlb_f("IsCharAlpha", IsCharAlpha),
        xlb_f("IsCharAlphaNumeric", IsCharAlphaNumeric),
        xlb_f("IsCharLower", IsCharLower),
        xlb_f("IsCharUpper", IsCharUpper),
        xlb_f("IsChild", IsChild),
        xlb_f("IsClipboardFormatAvailable", IsClipboardFormatAvailable),
        xlb_f("IsDBCSLeadByte", IsDBCSLeadByte),
        xlb_f("IsDBCSLeadByteEx", IsDBCSLeadByteEx),
        xlb_f("IsDebuggerPresent", IsDebuggerPresent),
        xlb_f("IsDialogMessage", IsDialogMessage),
        xlb_f("IsDlgButtonChecked", IsDlgButtonChecked),
        xlb_f("IsIconic", IsIconic),
        xlb_f("IsMenu", IsMenu),
        xlb_f("IsProcessorFeaturePresent", IsProcessorFeaturePresent),
        xlb_f("IsRectEmpty", IsRectEmpty),
        xlb_f("IsTextUnicode", IsTextUnicode),
        xlb_f("IsValidAcl", IsValidAcl),
        xlb_f("IsValidCodePage", IsValidCodePage),
        xlb_f("IsValidLocale", IsValidLocale),
        xlb_f("IsValidSecurityDescriptor", IsValidSecurityDescriptor),
        xlb_f("IsValidSid", IsValidSid),
        xlb_f("IsWindow", IsWindow),
        xlb_f("IsWindowEnabled", IsWindowEnabled),
        xlb_f("IsWindowUnicode", IsWindowUnicode),
        xlb_f("IsWindowVisible", IsWindowVisible),
        xlb_f("IsZoomed", IsZoomed),
        xlb_class<xlb_cbf<HOOKPROC>>("JournalPlaybackProc").constructor<xlb_luafunc>(),
        xlb_class<xlb_cbf<HOOKPROC>>("JournalRecordProc").constructor<xlb_luafunc>(),
        xlb_f("keybd_event", keybd_event),
        xlb_class<xlb_cbf<HOOKPROC>>("KeyboardProc").constructor<xlb_luafunc>(),
        xlb_f("KillTimer", KillTimer),
        xlb_f("LBItemFromPt", LBItemFromPt),
        xlb_f("LCMapString", LCMapString),
        xlb_f("LeaveCriticalSection", LeaveCriticalSection),
        ////xlb_f("LimitEmsPages", LimitEmsPages),
        xlb_f("LineDDA", LineDDA),
        xlb_class<xlb_cbf<LINEDDAPROC>>("LineDDAProc").constructor<xlb_luafunc>(),
        xlb_f("LineTo", LineTo),
        xlb_f("LoadAccelerators", LoadAccelerators),
        xlb_f("LoadBitmap", LoadBitmap),
        xlb_f("LoadCursor", LoadCursor),
        xlb_f("LoadCursorFromFile", LoadCursorFromFile),
        xlb_f("LoadIcon", LoadIcon),
        xlb_f("LoadImage", LoadImage),
        xlb_f("LoadKeyboardLayout", LoadKeyboardLayout),
        xlb_f("LoadLibrary", LoadLibrary),
        xlb_f("LoadLibraryEx", LoadLibraryEx),
        xlb_f("LoadMenu", LoadMenu),
        xlb_f("LoadMenuIndirect", LoadMenuIndirect),
        xlb_f("LoadModule", LoadModule),
        xlb_f("LoadResource", LoadResource),
        xlb_f("LoadString", LoadString),
        xlb_f("LocalAlloc", LocalAlloc),
        xlb_f("LocalCompact", LocalCompact),
        xlb_f("LocalDiscard", [](HGLOBAL h)->void { LocalDiscard(h); }),
        xlb_f("LocalFileTimeToFileTime", LocalFileTimeToFileTime),
        xlb_f("LocalFlags", LocalFlags),
        xlb_f("LocalFree", LocalFree),
        xlb_f("LocalHandle", LocalHandle),
        xlb_f("LocalLock", LocalLock),
        xlb_f("LocalReAlloc", LocalReAlloc),
        xlb_f("LocalShrink", LocalShrink),
        xlb_f("LocalSize", LocalSize),
        xlb_f("LocalUnlock", LocalUnlock),
        xlb_f("LockFile", LockFile),
        xlb_f("LockFileEx", LockFileEx),
        xlb_f("LockResource", LockResource),
        ////xlb_f("LockSegment", LockSegment), // Outdated
        xlb_f("LockServiceDatabase", LockServiceDatabase),
        xlb_f("LockWindowUpdate", LockWindowUpdate),
        xlb_f("LogonUser", LogonUser),
        xlb_f("LookupAccountName", LookupAccountName),
        xlb_f("LookupAccountSid", LookupAccountSid),
        xlb_f("LookupIconIdFromDirectory", LookupIconIdFromDirectory),
        xlb_f("LookupIconIdFromDirectoryEx", LookupIconIdFromDirectoryEx),
        xlb_f("LookupPrivilegeDisplayName", LookupPrivilegeDisplayName),
        xlb_f("LookupPrivilegeName", LookupPrivilegeName),
        xlb_f("LookupPrivilegeValue", LookupPrivilegeValue),
        xlb_f("LookupSecurityDescriptorParts", LookupSecurityDescriptorParts),
        xlb_f("LPtoDP", LPtoDP),
        ////xlb_f("LSEnumProviders", LSEnumProviders),
        ////xlb_f("LSFreeHandle", LSFreeHandle),
        ////xlb_f("LSGetMessage", LSGetMessage),
        ////xlb_f("LSQuery", LSQuery),
        ////xlb_f("LSRelease", LSRelease),
        ////xlb_f("LSRequest", LSRequest),
        ////xlb_f("LSUpdate", LSUpdate),
        xlb_f("lstrcat", lstrcat),
        xlb_f("lstrcmp", lstrcmp),
        xlb_f("lstrcmpi", lstrcmpi),
        xlb_f("lstrcpy", lstrcpy),
        xlb_f("lstrcpyn", lstrcpyn),
        xlb_f("lstrlen", lstrlen),
        xlb_f("LZClose", LZClose),
        xlb_f("LZCopy", LZCopy),
        xlb_f("LZDone", LZDone),
        xlb_f("LZInit", LZInit),
        xlb_f("LZOpenFile", LZOpenFile),
        xlb_f("LZRead", LZRead),
        xlb_f("LZSeek", LZSeek),
        xlb_f("LZStart", LZStart),
        xlb_f("MakeAbsoluteSD", MakeAbsoluteSD),
        xlb_f("MakeDragList", MakeDragList),
        ////xlb_f("MakeProcInstance", MakeProcInstance), // Outdated
        xlb_f("MakeSelfRelativeSD", MakeSelfRelativeSD),
        xlb_f("MapDialogRect", MapDialogRect),
        xlb_f("MapGenericMask", MapGenericMask),
        xlb_f("MapViewOfFile", MapViewOfFile),
        xlb_f("MapViewOfFileEx", MapViewOfFileEx),
        xlb_f("MapVirtualKey", MapVirtualKey),
        xlb_f("MapVirtualKeyEx", MapVirtualKeyEx),
        xlb_f("MapWindowPoints", MapWindowPoints),
        xlb_f("MenuHelp", MenuHelp),
        xlb_f("MenuItemFromPoint", MenuItemFromPoint),
        xlb_f("MessageBeep", MessageBeep),
        xlb_f("MessageBox", MessageBox),
        xlb_f("MessageBoxEx", MessageBoxEx),
        xlb_f("MessageBoxIndirect", MessageBoxIndirect),
        xlb_class<xlb_cbf<HOOKPROC>>("MessageProc").constructor<xlb_luafunc>(),
        xlb_f("ModifyMenu", ModifyMenu),
        xlb_f("ModifyWorldTransform", ModifyWorldTransform),
        xlb_f("mouse_event", mouse_event),
        xlb_class<xlb_cbf<HOOKPROC>>("MouseProc").constructor<xlb_luafunc>(),
        xlb_f("MoveFile", MoveFile),
        xlb_f("MoveFileEx", MoveFileEx),
        xlb_f("MoveMemory", [](PVOID Destination, VOID* Source, SIZE_T Length)->void { 
                MoveMemory(Destination, Source, Length); }),
        xlb_f("MoveToEx", MoveToEx),
        xlb_f("MoveWindow", MoveWindow),
        xlb_f("MsgWaitForMultipleObjects", MsgWaitForMultipleObjects),
        xlb_f("MsgWaitForMultipleObjectsEx", MsgWaitForMultipleObjectsEx),
        xlb_f("MulDiv", MulDiv),
        xlb_f("MultiByteToWideChar", MultiByteToWideChar),

#ifdef BIND_WIN_8_1_MINCORE_LIB
        xlb_f("MultinetGetConnectionPerformance", MultinetGetConnectionPerformance),
#endif

        // XXX:Network DDE is no longer supported. Nddeapi.dll is present on 
        // Windows Vista, but all function calls return NDDE_NOT_IMPLEMENTED.
        ////xlb_f("NDdeGetErrorString", NDdeGetErrorString),
        ////xlb_f("NDdeGetShareSecurity", NDdeGetShareSecurity),
        ////xlb_f("NDdeGetTrustedShare", NDdeGetTrustedShare),
        ////xlb_f("NDdeIsValidAppTopicList", NDdeIsValidAppTopicList),
        ////xlb_f("NDdeIsValidShareName", NDdeIsValidShareName),
        ////xlb_f("NDdeSetShareSecurity", NDdeSetShareSecurity),
        ////xlb_f("NDdeSetTrustedShare", NDdeSetTrustedShare),
        ////xlb_f("NDdeShareAdd", NDdeShareAdd),
        ////xlb_f("NDdeShareDel", NDdeShareDel),
        ////xlb_f("NDdeShareEnum", NDdeShareEnum),
        ////xlb_f("NDdeShareGetInfo", NDdeShareGetInfo),
        ////xlb_f("NDdeShareSetInfo", NDdeShareSetInfo),
        ////xlb_f("NDdeTrustedShareEnum", NDdeTrustedShareEnum),

        xlb_f("NetAccessAdd", NetAccessAdd),
        ////xlb_f("NetAccessCheck", NetAccessCheck), // not supported
        xlb_f("NetAccessDel", NetAccessDel),
        xlb_f("NetAccessEnum", NetAccessEnum),
        xlb_f("NetAccessGetInfo", NetAccessGetInfo),
        xlb_f("NetAccessGetUserPerms", NetAccessGetUserPerms),
        xlb_f("NetAccessSetInfo", NetAccessSetInfo),
        xlb_f("NetAlertRaise", NetAlertRaise),
        xlb_f("NetAlertRaiseEx", NetAlertRaiseEx),
        xlb_f("NetApiBufferAllocate", NetApiBufferAllocate),
        xlb_f("NetApiBufferFree", NetApiBufferFree),
        xlb_f("NetApiBufferReallocate", NetApiBufferReallocate),
        xlb_f("NetApiBufferSize", NetApiBufferSize),
        xlb_f("NetAuditClear", NetAuditClear),
        xlb_f("NetAuditRead", NetAuditRead),
        xlb_f("NetConfigGet", NetConfigGet),
        xlb_f("NetConfigGetAll", NetConfigGetAll),
        xlb_f("NetConfigSet", NetConfigSet),
        xlb_f("NetConnectionEnum", NetConnectionEnum),
        xlb_f("NetErrorLogClear", NetErrorLogClear),
        xlb_f("NetErrorLogRead", NetErrorLogRead),
        xlb_f("NetFileClose", NetFileClose),
        xlb_f("NetFileEnum", NetFileEnum),
        xlb_f("NetFileGetInfo", NetFileGetInfo),
        xlb_f("NetGetAnyDCName", NetGetAnyDCName),
        xlb_f("NetGetDCName", NetGetDCName),
        xlb_f("NetGetDisplayInformationIndex", NetGetDisplayInformationIndex),
        xlb_f("NetGroupAdd", NetGroupAdd),
        xlb_f("NetGroupAddUser", NetGroupAddUser),
        xlb_f("NetGroupDel", NetGroupDel),
        xlb_f("NetGroupDelUser", NetGroupDelUser),
        xlb_f("NetGroupEnum", NetGroupEnum),
        xlb_f("NetGroupGetInfo", NetGroupGetInfo),
        xlb_f("NetGroupGetUsers", NetGroupGetUsers),
        xlb_f("NetGroupSetInfo", NetGroupSetInfo),
        xlb_f("NetGroupSetUsers", NetGroupSetUsers),
        ////xlb_f("NetHandleGetInfo", NetHandleGetInfo),
        ////xlb_f("NetHandleSetInfo", NetHandleSetInfo),
        xlb_f("NetLocalGroupAdd", NetLocalGroupAdd),
        xlb_f("NetLocalGroupAddMember", NetLocalGroupAddMember),
        xlb_f("NetLocalGroupAddMembers", NetLocalGroupAddMembers),
        xlb_f("NetLocalGroupDel", NetLocalGroupDel),
        xlb_f("NetLocalGroupDelMember", NetLocalGroupDelMember),
        xlb_f("NetLocalGroupDelMembers", NetLocalGroupDelMembers),
        xlb_f("NetLocalGroupEnum", NetLocalGroupEnum),
        xlb_f("NetLocalGroupGetInfo", NetLocalGroupGetInfo),
        xlb_f("NetLocalGroupGetMembers", NetLocalGroupGetMembers),
        xlb_f("NetLocalGroupSetInfo", NetLocalGroupSetInfo),
        xlb_f("NetLocalGroupSetMembers", NetLocalGroupSetMembers),
        xlb_f("NetMessageBufferSend", NetMessageBufferSend),
        xlb_f("NetMessageNameAdd", NetMessageNameAdd),
        xlb_f("NetMessageNameDel", NetMessageNameDel),
        xlb_f("NetMessageNameEnum", NetMessageNameEnum),
        xlb_f("NetMessageNameGetInfo", NetMessageNameGetInfo),
        xlb_f("NetQueryDisplayInformation", NetQueryDisplayInformation),
        xlb_f("NetRemoteTOD", NetRemoteTOD),
        xlb_f("NetReplExportDirAdd", NetReplExportDirAdd),
        xlb_f("NetReplExportDirDel", NetReplExportDirDel),
        xlb_f("NetReplExportDirEnum", NetReplExportDirEnum),
        xlb_f("NetReplExportDirGetInfo", NetReplExportDirGetInfo),
        xlb_f("NetReplExportDirLock", NetReplExportDirLock),
        xlb_f("NetReplExportDirSetInfo", NetReplExportDirSetInfo),
        xlb_f("NetReplExportDirUnlock", NetReplExportDirUnlock),
        xlb_f("NetReplGetInfo", NetReplGetInfo),
        xlb_f("NetReplImportDirAdd", NetReplImportDirAdd),
        xlb_f("NetReplImportDirDel", NetReplImportDirDel),
        xlb_f("NetReplImportDirEnum", NetReplImportDirEnum),
        xlb_f("NetReplImportDirGetInfo", NetReplImportDirGetInfo),
        xlb_f("NetReplImportDirLock", NetReplImportDirLock),
        xlb_f("NetReplImportDirUnlock", NetReplImportDirUnlock),
        xlb_f("NetReplSetInfo", NetReplSetInfo),
        xlb_f("NetScheduleJobAdd", NetScheduleJobAdd),
        xlb_f("NetScheduleJobDel", NetScheduleJobDel),
        xlb_f("NetScheduleJobEnum", NetScheduleJobEnum),
        xlb_f("NetScheduleJobGetInfo", NetScheduleJobGetInfo),
        xlb_f("NetServerDiskEnum", NetServerDiskEnum),
        xlb_f("NetServerEnum", NetServerEnum),
        xlb_f("NetServerGetInfo", NetServerGetInfo),
        xlb_f("NetServerSetInfo", NetServerSetInfo),
        xlb_f("NetServerTransportAdd", NetServerTransportAdd),
        xlb_f("NetServerTransportDel", NetServerTransportDel),
        xlb_f("NetServerTransportEnum", NetServerTransportEnum),
        xlb_f("NetServiceControl", NetServiceControl),
        xlb_f("NetServiceEnum", NetServiceEnum),
        xlb_f("NetServiceGetInfo", NetServiceGetInfo),
        xlb_f("NetServiceInstall", NetServiceInstall),
        xlb_f("NetSessionDel", NetSessionDel),
        xlb_f("NetSessionEnum", NetSessionEnum),
        xlb_f("NetSessionGetInfo", NetSessionGetInfo),
        xlb_f("NetShareAdd", NetShareAdd),
        xlb_f("NetShareCheck", NetShareCheck),
        xlb_f("NetShareDel", NetShareDel),
        xlb_f("NetShareEnum", NetShareEnum),
        xlb_f("NetShareGetInfo", NetShareGetInfo),
        xlb_f("NetShareSetInfo", NetShareSetInfo),
        xlb_f("NetStatisticsGet", NetStatisticsGet),
        ////xlb_f("NetStatisticsGet2", NetStatisticsGet2),
        xlb_f("NetUseAdd", NetUseAdd),
        xlb_f("NetUseDel", NetUseDel),
        xlb_f("NetUseEnum", NetUseEnum),
        xlb_f("NetUseGetInfo", NetUseGetInfo),
        xlb_f("NetUserAdd", NetUserAdd),
        xlb_f("NetUserChangePassword", NetUserChangePassword),
        xlb_f("NetUserDel", NetUserDel),
        xlb_f("NetUserEnum", NetUserEnum),
        xlb_f("NetUserGetGroups", NetUserGetGroups),
        xlb_f("NetUserGetInfo", NetUserGetInfo),
        xlb_f("NetUserGetLocalGroups", NetUserGetLocalGroups),
        xlb_f("NetUserModalsGet", NetUserModalsGet),
        xlb_f("NetUserModalsSet", NetUserModalsSet),
        xlb_f("NetUserSetGroups", NetUserSetGroups),
        xlb_f("NetUserSetInfo", NetUserSetInfo),
        xlb_f("NetWkstaGetInfo", NetWkstaGetInfo),
        xlb_f("NetWkstaSetInfo", NetWkstaSetInfo),
        xlb_f("NetWkstaTransportAdd", NetWkstaTransportAdd),
        xlb_f("NetWkstaTransportDel", NetWkstaTransportDel),
        xlb_f("NetWkstaTransportEnum", NetWkstaTransportEnum),
        xlb_f("NetWkstaUserEnum", NetWkstaUserEnum),
        xlb_f("NetWkstaUserGetInfo", NetWkstaUserGetInfo),
        xlb_f("NetWkstaUserSetInfo", NetWkstaUserSetInfo),
        xlb_f("NotifyBootConfigStatus", NotifyBootConfigStatus),
        xlb_f("NotifyChangeEventLog", NotifyChangeEventLog),
        xlb_f("ObjectCloseAuditAlarm", ObjectCloseAuditAlarm),
        xlb_f("ObjectDeleteAuditAlarm", ObjectDeleteAuditAlarm),
        xlb_f("ObjectOpenAuditAlarm", ObjectOpenAuditAlarm),
        xlb_f("ObjectPrivilegeAuditAlarm", ObjectPrivilegeAuditAlarm),
        xlb_f("OemKeyScan", OemKeyScan),
        xlb_f("OemToAnsi", OemToAnsi),
        xlb_f("OemToAnsiBuff", OemToAnsiBuff),
        xlb_f("OemToChar", OemToChar),
        xlb_f("OemToCharBuff", OemToCharBuff),
        xlb_f("OffsetClipRgn", OffsetClipRgn),
        xlb_f("OffsetRect", OffsetRect),
        xlb_f("OffsetRgn", OffsetRgn),
        xlb_f("OffsetViewportOrgEx", OffsetViewportOrgEx),
        xlb_f("OffsetWindowOrgEx", OffsetWindowOrgEx),
        xlb_class<xlb_cbf<LPOFNHOOKPROC>>("OFNHookProc").constructor<xlb_luafunc>(),
        xlb_class<xlb_cbf<LPOFNHOOKPROC>>("OFNHookProcOldStyle").constructor<xlb_luafunc>(),
        xlb_f("OpenBackupEventLog", OpenBackupEventLog),
        xlb_f("OpenClipboard", OpenClipboard),
        xlb_f("OpenDesktop", OpenDesktop),
        xlb_f("OpenEvent", OpenEvent),
        xlb_f("OpenEventLog", OpenEventLog),
        xlb_f("OpenFile", OpenFile),
        xlb_f("OpenFileMapping", OpenFileMapping),
        xlb_f("OpenIcon", OpenIcon),
        xlb_f("OpenInputDesktop", OpenInputDesktop),
        xlb_f("OpenMutex", OpenMutex),
        xlb_f("OpenPrinter", OpenPrinter),
        xlb_f("OpenProcess", OpenProcess),
        xlb_f("OpenProcessToken", OpenProcessToken),
        xlb_f("OpenSCManager", OpenSCManager),
        xlb_f("OpenSemaphore", OpenSemaphore),
        xlb_f("OpenService", OpenService),
        xlb_f("OpenThreadToken", OpenThreadToken),
        xlb_f("OpenWaitableTimer", OpenWaitableTimer),
        xlb_f("OpenWindowStation", OpenWindowStation),
        xlb_f("OutputDebugString", OutputDebugString),
        ////xlb_f("OutputProc", OutputProc),
        xlb_f("PackDDElParam", PackDDElParam),
        xlb_class<xlb_cbf<LPPAGEPAINTHOOK>>("PagePaintHook").constructor<xlb_luafunc>(),
        xlb_f("PageSetupDlg", PageSetupDlg),
        xlb_class<xlb_cbf<LPPAGESETUPHOOK>>("PageSetupHook").constructor<xlb_luafunc>(),
        xlb_f("PaintDesktop", PaintDesktop),
        xlb_f("PaintRgn", PaintRgn),
        xlb_f("PatBlt", PatBlt),
        xlb_f("PathToRegion", PathToRegion),
        xlb_f("PeekConsoleInput", PeekConsoleInput),
        xlb_f("PeekMessage", PeekMessage),
        xlb_f("PeekNamedPipe", PeekNamedPipe),
        xlb_f("PlayEnhMetaFile", PlayEnhMetaFile),
        xlb_f("PlayEnhMetaFileRecord", PlayEnhMetaFileRecord),
        xlb_f("PlayMetaFile", PlayMetaFile),
        xlb_f("PlayMetaFileRecord", PlayMetaFileRecord),
        xlb_f("PlgBlt", PlgBlt),
        xlb_f("PolyBezier", PolyBezier),
        xlb_f("PolyBezierTo", PolyBezierTo),
        xlb_f("PolyDraw", PolyDraw),
        xlb_f("PolylineTo", PolylineTo),
        xlb_f("PolyPolygon", PolyPolygon),
        xlb_f("PolyPolyline", PolyPolyline),
        xlb_f("PolyTextOut", PolyTextOut),
        ////xlb_f("PostAppMessage", PostAppMessage),
        xlb_f("PostMessage", PostMessage),
        xlb_f("PostQueuedCompletionStatus", PostQueuedCompletionStatus),
        xlb_f("PostQuitMessage", PostQuitMessage),
        xlb_f("PostThreadMessage", PostThreadMessage),
        xlb_f("PrepareTape", PrepareTape),
        xlb_f("PrintDlg", PrintDlg),
        xlb_f("PrinterMessageBox", PrinterMessageBox),
        xlb_f("PrinterProperties", PrinterProperties),
        xlb_class<xlb_cbf<LPPRINTHOOKPROC>>("PrintHookProc").constructor<xlb_luafunc>(),
        xlb_f("PrivilegeCheck", PrivilegeCheck),
        xlb_f("PrivilegedServiceAuditAlarm", PrivilegedServiceAuditAlarm),
        xlb_class<xlb_cbf<PROPENUMPROC>>("PropEnumProc").constructor<xlb_luafunc>(),
        xlb_class<xlb_cbf<PROPENUMPROCEX>>("PropEnumProcEx").constructor<xlb_luafunc>(),
        xlb_f("PropertySheet", PropertySheet),
        xlb_class<xlb_cbf<PROPSHEETPAGEPROC>>("PropSheetPageProc").constructor<xlb_luafunc>(),
        xlb_class<xlb_cbf<PROPSHEETPROC>>("PropSheetProc").constructor<xlb_luafunc>(),
        xlb_f("PtInRect", PtInRect),
        xlb_f("PtInRegion", PtInRegion),
        xlb_f("PtVisible", PtVisible),
        xlb_f("PulseEvent", PulseEvent),
        xlb_f("PurgeComm", PurgeComm),
        xlb_f("QueryDosDevice", QueryDosDevice),
        xlb_f("QueryPerformanceCounter", QueryPerformanceCounter),
        xlb_f("QueryPerformanceFrequency", QueryPerformanceFrequency),
        xlb_f("QueryServiceConfig", QueryServiceConfig),
        xlb_f("QueryServiceLockStatus", QueryServiceLockStatus),
        xlb_f("QueryServiceObjectSecurity", QueryServiceObjectSecurity),
        xlb_f("QueryServiceStatus", QueryServiceStatus),
        xlb_f("RaiseException", RaiseException),


        xlb_f("ReadConsole", ReadConsole),
        xlb_f("ReadConsoleInput", ReadConsoleInput),
        xlb_f("ReadConsoleOutput", ReadConsoleOutput),
        xlb_f("ReadConsoleOutputAttribute", ReadConsoleOutputAttribute),
        xlb_f("ReadConsoleOutputCharacter", ReadConsoleOutputCharacter),
        xlb_f("ReadDirectoryChangesW", ReadDirectoryChangesW),
        xlb_f("ReadEventLog", ReadEventLog),
        xlb_f("ReadFile", ReadFile),
        xlb_f("ReadFileEx", ReadFileEx),
        xlb_f("ReadPrinter", ReadPrinter),
        xlb_f("ReadProcessMemory", ReadProcessMemory),
        xlb_f("RealizePalette", RealizePalette),
        xlb_f("RectInRegion", RectInRegion),
        xlb_f("RectVisible", RectVisible),
        xlb_f("RedrawWindow", RedrawWindow),
        xlb_f("RegCloseKey", RegCloseKey),
        xlb_f("RegConnectRegistry", RegConnectRegistry),
        xlb_f("RegCreateKey", RegCreateKey),
        xlb_f("RegCreateKeyEx", RegCreateKeyEx),
        xlb_f("RegDeleteKey", RegDeleteKey),
        xlb_f("RegDeleteValue", RegDeleteValue),
        xlb_f("RegEnumKey", RegEnumKey),
        xlb_f("RegEnumKeyEx", RegEnumKeyEx),
        xlb_f("RegEnumValue", RegEnumValue),
        xlb_f("RegFlushKey", RegFlushKey),
        xlb_f("RegGetKeySecurity", RegGetKeySecurity),
        xlb_f("RegisterClass", RegisterClass),
        xlb_f("RegisterClassEx", RegisterClassEx),
        xlb_f("RegisterClipboardFormat", RegisterClipboardFormat),
        //xlb_f("RegisterDialogClasses", RegisterDialogClasses),
        xlb_f("RegisterEventSource", RegisterEventSource),
        xlb_f("RegisterHotKey", RegisterHotKey),
        xlb_f("RegisterServiceCtrlHandler", RegisterServiceCtrlHandler),
        xlb_f("RegisterWindowMessage", RegisterWindowMessage),
        xlb_f("RegLoadKey", RegLoadKey),
        xlb_f("RegNotifyChangeKeyValue", RegNotifyChangeKeyValue),
        xlb_f("RegOpenKey", RegOpenKey),
        xlb_f("RegOpenKeyEx", RegOpenKeyEx),
        xlb_f("RegQueryInfoKey", RegQueryInfoKey),
        xlb_f("RegQueryMultipleValues", RegQueryMultipleValues),
        xlb_f("RegQueryValue", RegQueryValue),
        xlb_f("RegQueryValueEx", RegQueryValueEx),
        xlb_f("RegReplaceKey", RegReplaceKey),
        xlb_f("RegRestoreKey", RegRestoreKey),
        xlb_f("RegSaveKey", RegSaveKey),
        xlb_f("RegSetKeySecurity", RegSetKeySecurity),
        xlb_f("RegSetValue", RegSetValue),
        xlb_f("RegSetValueEx", RegSetValueEx),
        xlb_f("RegUnLoadKey", RegUnLoadKey),
        xlb_f("ReleaseCapture", ReleaseCapture),
        xlb_f("ReleaseDC", ReleaseDC),
        xlb_f("ReleaseMutex", ReleaseMutex),
        xlb_f("ReleaseSemaphore", ReleaseSemaphore),
        xlb_f("RemoveDirectory", RemoveDirectory),
        xlb_f("RemoveFontResource", RemoveFontResource),
        xlb_f("RemoveMenu", RemoveMenu),
        xlb_f("RemoveProp", RemoveProp),
        xlb_f("ReplaceText", ReplaceText),
        xlb_f("ReplyMessage", ReplyMessage),
        xlb_f("ReportEvent", ReportEvent),
        xlb_f("ResetDC", ResetDC),
        xlb_f("ResetEvent", ResetEvent),
        xlb_f("ResetPrinter", ResetPrinter),
        xlb_f("ResizePalette", ResizePalette),
        xlb_f("RestoreDC", RestoreDC),
        xlb_f("ResumeThread", ResumeThread),
        xlb_f("ReuseDDElParam", ReuseDDElParam),
        xlb_f("RevertToSelf", RevertToSelf),
        xlb_f("RoundRect", RoundRect),
        xlb_f("SaveDC", SaveDC),
        xlb_f("ScaleViewportExtEx", ScaleViewportExtEx),
        xlb_f("ScaleWindowExtEx", ScaleWindowExtEx),
        xlb_f("ScheduleJob", ScheduleJob),
        //xlb_f("ScreenSaverConfigureDialog", ScreenSaverConfigureDialog), //FIXME
        //xlb_f("ScreenSaverProc", ScreenSaverProc), //FIXME
        xlb_f("ScreenToClient", ScreenToClient),
        xlb_f("ScrollConsoleScreenBuffer", ScrollConsoleScreenBuffer),
        xlb_f("ScrollDC", ScrollDC),
        xlb_f("ScrollWindow", ScrollWindow),
        xlb_f("ScrollWindowEx", ScrollWindowEx),
        xlb_f("SearchPath", SearchPath),
        xlb_f("SelectClipPath", SelectClipPath),
        xlb_f("SelectClipRgn", SelectClipRgn),
        xlb_f("SelectObject", SelectObject),
        xlb_f("SelectPalette", SelectPalette),
        xlb_class<xlb_cbf<SENDASYNCPROC>>("SendAsyncProc").constructor<xlb_luafunc>(),
        xlb_f("SendDlgItemMessage", SendDlgItemMessage),
        xlb_f("SendMessage", SendMessage),
        xlb_f("SendMessageCallback", SendMessageCallback),
        xlb_f("SendMessageTimeout", SendMessageTimeout),
        xlb_f("SendNotifyMessage", SendNotifyMessage),
        //xlb_f("ServiceMain", ServiceMain), // FIXME
        xlb_f("SetAbortProc", SetAbortProc),
        xlb_f("SetAclInformation", SetAclInformation),
        xlb_f("SetActiveWindow", SetActiveWindow),
        xlb_f("SetArcDirection", SetArcDirection),
        xlb_f("SetBitmapBits", SetBitmapBits),
        xlb_f("SetBitmapDimensionEx", SetBitmapDimensionEx),
        xlb_f("SetBkColor", SetBkColor),
        xlb_f("SetBkMode", SetBkMode),
        xlb_f("SetBoundsRect", SetBoundsRect),
        xlb_f("SetBrushOrgEx", SetBrushOrgEx),
        xlb_f("SetCapture", SetCapture),
        xlb_f("SetCaretBlinkTime", SetCaretBlinkTime),
        xlb_f("SetCaretPos", SetCaretPos),
        xlb_f("SetClassLong", SetClassLong),
        xlb_f("SetClassWord", SetClassWord),
        xlb_f("SetClipboardData", SetClipboardData),
        xlb_f("SetClipboardViewer", SetClipboardViewer),
        xlb_f("SetColorAdjustment", SetColorAdjustment),
        xlb_f("SetColorSpace", SetColorSpace),
        xlb_f("SetCommBreak", SetCommBreak),
        xlb_f("SetCommConfig", SetCommConfig),
        xlb_f("SetCommMask", SetCommMask),
        xlb_f("SetCommState", SetCommState),
        xlb_f("SetCommTimeouts", SetCommTimeouts),
        xlb_f("SetComputerName", SetComputerName),
        xlb_f("SetConsoleActiveScreenBuffer", SetConsoleActiveScreenBuffer),
        xlb_f("SetConsoleCP", SetConsoleCP),
        xlb_f("SetConsoleCtrlHandler", SetConsoleCtrlHandler),
        xlb_f("SetConsoleCursorInfo", SetConsoleCursorInfo),
        xlb_f("SetConsoleCursorPosition", SetConsoleCursorPosition),
        xlb_f("SetConsoleMode", SetConsoleMode),
        xlb_f("SetConsoleOutputCP", SetConsoleOutputCP),
        xlb_f("SetConsoleScreenBufferSize", SetConsoleScreenBufferSize),
        xlb_f("SetConsoleTextAttribute", SetConsoleTextAttribute),
        xlb_f("SetConsoleTitle", SetConsoleTitle),
        xlb_f("SetConsoleWindowInfo", SetConsoleWindowInfo),
        xlb_f("SetCurrentDirectory", SetCurrentDirectory),
        xlb_f("SetCursor", SetCursor),
        xlb_f("SetCursorPos", SetCursorPos),
        xlb_f("SetDebugErrorLevel", SetDebugErrorLevel),
        xlb_f("SetDefaultCommConfig", SetDefaultCommConfig),
        xlb_f("SetDeviceGammaRamp", SetDeviceGammaRamp),
        xlb_f("SetDIBColorTable", SetDIBColorTable),
        xlb_f("SetDIBits", SetDIBits),
        xlb_f("SetDIBitsToDevice", SetDIBitsToDevice),
        xlb_f("SetDlgItemInt", SetDlgItemInt),
        xlb_f("SetDlgItemText", SetDlgItemText),
        xlb_f("SetDoubleClickTime", SetDoubleClickTime),
        xlb_f("SetEndOfFile", SetEndOfFile),
        xlb_f("SetEnhMetaFileBits", SetEnhMetaFileBits),
        xlb_f("SetEntriesInAcl", SetEntriesInAcl),
        xlb_f("SetEnvironmentVariable", SetEnvironmentVariable),
        xlb_f("SetErrorMode", SetErrorMode),
        xlb_f("SetEvent", SetEvent),
        xlb_f("SetFileApisToANSI", SetFileApisToANSI),
        xlb_f("SetFileApisToOEM", SetFileApisToOEM),
        xlb_f("SetFileAttributes", SetFileAttributes),
        xlb_f("SetFilePointer", SetFilePointer),
        xlb_f("SetFileSecurity", SetFileSecurity),
        xlb_f("SetFileTime", SetFileTime),
        xlb_f("SetFocus", SetFocus),
        xlb_f("SetForegroundWindow", SetForegroundWindow),
        xlb_f("SetForm", SetForm),
        xlb_f("SetGraphicsMode", SetGraphicsMode),
        xlb_f("SetHandleCount", SetHandleCount),
        xlb_f("SetHandleInformation", SetHandleInformation),
        xlb_f("SetICMMode", SetICMMode),
        xlb_f("SetICMProfile", SetICMProfile),
        xlb_f("SetJob", SetJob),
        xlb_f("SetKernelObjectSecurity", SetKernelObjectSecurity),
        xlb_f("SetKeyboardState", SetKeyboardState),
        xlb_f("SetLastError", SetLastError),
        xlb_f("SetLastErrorEx", SetLastErrorEx),
        xlb_f("SetLocaleInfo", SetLocaleInfo),
        xlb_f("SetLocalTime", SetLocalTime),
        xlb_f("SetMailslotInfo", SetMailslotInfo),
        xlb_f("SetMapMode", SetMapMode),
        xlb_f("SetMapperFlags", SetMapperFlags),
        xlb_f("SetMenu", SetMenu),
        xlb_f("SetMenuContextHelpId", SetMenuContextHelpId),
        xlb_f("SetMenuDefaultItem", SetMenuDefaultItem),
        xlb_f("SetMenuItemBitmaps", SetMenuItemBitmaps),
        xlb_f("SetMenuItemInfo", SetMenuItemInfo),
        xlb_f("SetMessageExtraInfo", SetMessageExtraInfo),
        xlb_f("SetMessageQueue", SetMessageQueue),
        xlb_f("SetMetaFileBitsEx", SetMetaFileBitsEx),
        xlb_f("SetMetaRgn", SetMetaRgn),
        xlb_f("SetMiterLimit", SetMiterLimit),
        xlb_f("SetNamedPipeHandleState", SetNamedPipeHandleState),
        xlb_f("SetPaletteEntries", SetPaletteEntries),
        xlb_f("SetParent", SetParent),
        xlb_f("SetPixel", SetPixel),
        xlb_f("SetPixelV", SetPixelV),
        xlb_f("SetPolyFillMode", SetPolyFillMode),
        xlb_f("SetPort", SetPort),
        xlb_f("SetPrinter", SetPrinter),
        xlb_f("SetPrinterData", SetPrinterData),
        xlb_f("SetPriorityClass", SetPriorityClass),
        xlb_f("SetPrivateObjectSecurity", SetPrivateObjectSecurity),
        xlb_f("SetProcessAffinityMask", SetProcessAffinityMask),
        xlb_f("SetProcessPriorityBoost", SetProcessPriorityBoost),
        xlb_f("SetProcessShutdownParameters", SetProcessShutdownParameters),
        xlb_f("SetProcessWindowStation", SetProcessWindowStation),
        xlb_f("SetProcessWorkingSetSize", SetProcessWorkingSetSize),
        xlb_f("SetProp", SetProp),
        xlb_f("SetRect", SetRect),
        xlb_f("SetRectEmpty", SetRectEmpty),
        xlb_f("SetRectRgn", SetRectRgn),
        xlb_f("SetROP2", SetROP2),
        xlb_f("SetScrollInfo", SetScrollInfo),
        xlb_f("SetScrollPos", SetScrollPos),
        xlb_f("SetScrollRange", SetScrollRange),
        xlb_f("SetSecurityDescriptorDacl", SetSecurityDescriptorDacl),
        xlb_f("SetSecurityDescriptorGroup", SetSecurityDescriptorGroup),
        xlb_f("SetSecurityDescriptorOwner", SetSecurityDescriptorOwner),
        xlb_f("SetSecurityDescriptorSacl", SetSecurityDescriptorSacl),
        xlb_f("SetSecurityInfo", SetSecurityInfo),
        xlb_f("SetServiceBits", SetServiceBits),
        xlb_f("SetServiceObjectSecurity", SetServiceObjectSecurity),
        xlb_f("SetServiceStatus", SetServiceStatus),
        xlb_f("SetStdHandle", SetStdHandle),
        xlb_f("SetStretchBltMode", SetStretchBltMode),
        ////xlb_f("SetSwapAreaSize", SetSwapAreaSize), // Outdated
        xlb_f("SetSysColors", SetSysColors),
        ////xlb_f("SetSysModalWindow", SetSysModalWindow), // Outdated
        xlb_f("SetSystemCursor", SetSystemCursor),
        xlb_f("SetSystemPaletteUse", SetSystemPaletteUse),
        xlb_f("SetSystemPowerState", SetSystemPowerState),
        xlb_f("SetSystemTime", SetSystemTime),
        xlb_f("SetSystemTimeAdjustment", SetSystemTimeAdjustment),
        xlb_f("SetTapeParameters", SetTapeParameters),
        xlb_f("SetTapePosition", SetTapePosition),
        xlb_f("SetTextAlign", SetTextAlign),
        xlb_f("SetTextCharacterExtra", SetTextCharacterExtra),
        xlb_f("SetTextColor", SetTextColor),
        xlb_f("SetTextJustification", SetTextJustification),
        xlb_f("SetThreadAffinityMask", SetThreadAffinityMask),
        xlb_f("SetThreadContext", SetThreadContext),
        xlb_f("SetThreadDesktop", SetThreadDesktop),
        xlb_f("SetThreadIdealProcessor", SetThreadIdealProcessor),
        xlb_f("SetThreadLocale", SetThreadLocale),
        xlb_f("SetThreadPriority", SetThreadPriority),
        xlb_f("SetThreadPriorityBoost", SetThreadPriorityBoost),
        xlb_f("SetThreadToken", SetThreadToken),
        xlb_f("SetTimer", SetTimer),
        xlb_f("SetTimeZoneInformation", SetTimeZoneInformation),
        xlb_f("SetTokenInformation", SetTokenInformation),
        xlb_f("SetUnhandledExceptionFilter", SetUnhandledExceptionFilter),
        xlb_f("SetupComm", SetupComm),
        xlb_class<xlb_cbf<LPSETUPHOOKPROC>>("SetupHookProc").constructor<xlb_luafunc>(),
        xlb_f("SetUserObjectInformation", SetUserObjectInformation),
        xlb_f("SetUserObjectSecurity", SetUserObjectSecurity),
        xlb_f("SetViewportExtEx", SetViewportExtEx),
        xlb_f("SetViewportOrgEx", SetViewportOrgEx),
        xlb_f("SetVolumeLabel", SetVolumeLabel),
        xlb_f("SetWaitableTimer", SetWaitableTimer),
        xlb_f("SetWindowContextHelpId", SetWindowContextHelpId),
        xlb_f("SetWindowExtEx", SetWindowExtEx),
        xlb_f("SetWindowLong", SetWindowLong),
        xlb_f("SetWindowOrgEx", SetWindowOrgEx),
        xlb_f("SetWindowPlacement", SetWindowPlacement),
        xlb_f("SetWindowPos", SetWindowPos),
        xlb_f("SetWindowRgn", SetWindowRgn),
        xlb_f("SetWindowsHook", SetWindowsHook),
        xlb_f("SetWindowsHookEx", SetWindowsHookEx),
        xlb_f("SetWindowText", SetWindowText),
        xlb_f("SetWindowWord", SetWindowWord),
        xlb_f("SetWinMetaFileBits", SetWinMetaFileBits),
        xlb_f("SetWorldTransform", SetWorldTransform),
        xlb_f("SHAddToRecentDocs", SHAddToRecentDocs),
        xlb_f("SHAppBarMessage", SHAppBarMessage),
        xlb_f("SHBrowseForFolder", SHBrowseForFolder),
        xlb_f("SHChangeNotify", SHChangeNotify),
        xlb_f("Shell_NotifyIcon", Shell_NotifyIcon),
        xlb_f("ShellAbout", ShellAbout),
        xlb_f("ShellExecute", ShellExecute),
        xlb_f("ShellExecuteEx", ShellExecuteEx),
        xlb_class<xlb_cbf<HOOKPROC>>("ShellProc").constructor<xlb_luafunc>(),
        xlb_f("SHFileOperation", SHFileOperation),
        xlb_f("SHFreeNameMappings", SHFreeNameMappings),
        xlb_f("SHGetDataFromIDList", SHGetDataFromIDList),
        xlb_f("SHGetDesktopFolder", SHGetDesktopFolder),
        xlb_f("SHGetFileInfo", SHGetFileInfo),
        xlb_f("SHGetInstanceExplorer", SHGetInstanceExplorer),
        xlb_f("SHGetMalloc", SHGetMalloc),
        xlb_f("SHGetPathFromIDList", SHGetPathFromIDList),
        xlb_f("SHGetSpecialFolderLocation", SHGetSpecialFolderLocation),
        xlb_f("SHLoadInProc", SHLoadInProc),
        xlb_f("ShowCaret", ShowCaret),
        xlb_f("ShowCursor", ShowCursor),
        xlb_f("ShowHideMenuCtl", ShowHideMenuCtl),
        xlb_f("ShowOwnedPopups", ShowOwnedPopups),
        xlb_f("ShowScrollBar", ShowScrollBar),
        xlb_f("ShowWindow", ShowWindow),
        xlb_f("ShowWindowAsync", ShowWindowAsync),
        xlb_f("SignalObjectAndWait", SignalObjectAndWait),
        xlb_f("SizeofResource", SizeofResource),
        xlb_f("SleepEx", SleepEx),
        //xlb_f("SnmpExtensionInit", SnmpExtensionInit), // inetmib1.dll
        //xlb_f("SnmpExtensionInitEx", SnmpExtensionInitEx),
        //xlb_f("SnmpExtensionQuery", SnmpExtensionQuery),
        //xlb_f("SnmpExtensionTrap", SnmpExtensionTrap),
        xlb_f("SnmpMgrClose", SnmpMgrClose),
        xlb_f("SnmpMgrGetTrap", SnmpMgrGetTrap),
        xlb_f("SnmpMgrOidToStr", SnmpMgrOidToStr),
        xlb_f("SnmpMgrOpen", SnmpMgrOpen),
        xlb_f("SnmpMgrRequest", SnmpMgrRequest),
        xlb_f("SnmpMgrStrToOid", SnmpMgrStrToOid),
        xlb_f("SnmpMgrTrapListen", SnmpMgrTrapListen),
        xlb_f("SnmpUtilMemAlloc", SnmpUtilMemAlloc),
        xlb_f("SnmpUtilMemFree", SnmpUtilMemFree),
        xlb_f("SnmpUtilMemReAlloc", SnmpUtilMemReAlloc),
        xlb_f("SnmpUtilOidAppend", SnmpUtilOidAppend),
        xlb_f("SnmpUtilOidCmp", SnmpUtilOidCmp),
        xlb_f("SnmpUtilOidCpy", SnmpUtilOidCpy),
        xlb_f("SnmpUtilOidFree", SnmpUtilOidFree),
        xlb_f("SnmpUtilOidNCmp", SnmpUtilOidNCmp),
        xlb_f("SnmpUtilVarBindCpy", SnmpUtilVarBindCpy),
        xlb_f("SnmpUtilVarBindListCpy", SnmpUtilVarBindListCpy),
        xlb_f("SnmpUtilVarBindFree", SnmpUtilVarBindFree),
        xlb_f("SnmpUtilVarBindListFree", SnmpUtilVarBindListFree),
        //xlb_f("SOBailOut", SOBailOut),
        //xlb_f("SOBeginTable", SOBeginTable),
        //xlb_f("SOEndColumnInfo", SOEndColumnInfo),
        //xlb_f("SOEndFieldInfo", SOEndFieldInfo),
        //xlb_f("SOEndFontTable", SOEndFontTable),
        //xlb_f("SOEndPalette", SOEndPalette),
        //xlb_f("SOEndTable", SOEndTable),
        //xlb_f("SOEndTabStops", SOEndTabStops),
        //xlb_f("SOGetInfo", SOGetInfo),
        //xlb_f("SOGetScanLineBuffer", SOGetScanLineBuffer),
        //xlb_f("SOPutBitmapHeader", SOPutBitmapHeader),
        //xlb_f("SOPutBreak", SOPutBreak),
        //xlb_f("SOPutChar", SOPutChar),
        //xlb_f("SOPutCharAttr", SOPutCharAttr),
        //xlb_f("SOPutCharFontById", SOPutCharFontById),
        //xlb_f("SOPutCharFontByName", SOPutCharFontByName),
        //xlb_f("SOPutCharHeight", SOPutCharHeight),
        //xlb_f("SOPutCharX", SOPutCharX),
        //xlb_f("SOPutColumnInfo", SOPutColumnInfo),
        //xlb_f("SOPutDataCell", SOPutDataCell),
        //xlb_f("SOPutEmbeddedObject", SOPutEmbeddedObject),
        //xlb_f("SOPutField", SOPutField),
        //xlb_f("SOPutFieldInfo", SOPutFieldInfo),
        //xlb_f("SOPutFontTableEntry", SOPutFontTableEntry),
        //xlb_f("SOPutHdrEntry", SOPutHdrEntry),
        //xlb_f("SOPutMoreText", SOPutMoreText),
        //xlb_f("SOPutMoreVarField", SOPutMoreVarField),
        //xlb_f("SOPutPaletteEntry", SOPutPaletteEntry),
        //xlb_f("SOPutParaAlign", SOPutParaAlign),
        //xlb_f("SOPutParaIndents", SOPutParaIndents),
        //xlb_f("SOPutParaMargins", SOPutParaMargins),
        //xlb_f("SOPutParaSpacing", SOPutParaSpacing),
        //xlb_f("SOPutScanLineData", SOPutScanLineData),
        //xlb_f("SOPutSectionName", SOPutSectionName),
        //xlb_f("SOPutSectionType", SOPutSectionType),
        //xlb_f("SOPutSpecialCharX", SOPutSpecialCharX),
        //xlb_f("SOPutSubdocInfo", SOPutSubdocInfo),
        //xlb_f("SOPutTableCellInfo", SOPutTableCellInfo),
        //xlb_f("SOPutTableRowFormat", SOPutTableRowFormat),
        //xlb_f("SOPutTabStop", SOPutTabStop),
        //xlb_f("SOPutTextCell", SOPutTextCell),
        //xlb_f("SOPutVarField", SOPutVarField),
        //xlb_f("SOPutVectorHeader", SOPutVectorHeader),
        //xlb_f("SOSetDateBase", SOSetDateBase),
        //xlb_f("SOStartColumnInfo", SOStartColumnInfo),
        //xlb_f("SOStartFieldInfo", SOStartFieldInfo),
        //xlb_f("SOStartFontTable", SOStartFontTable),
        //xlb_f("SOStartPalette", SOStartPalette),
        //xlb_f("SOStartTabStops", SOStartTabStops),
        //xlb_f("SoundSentryProc", SoundSentryProc),
        //xlb_f("SOVectorAttr", SOVectorAttr),
        //xlb_f("SOVectorObject", SOVectorObject),
        //xlb_f("SUUserPopData", SUUserPopData),
        //xlb_f("SUUserPushData", SUUserPushData),
        //xlb_f("SUUserRetrieveData", SUUserRetrieveData),
        //xlb_f("SUUserSaveData", SUUserSaveData),
        xlb_f("StartDoc", StartDoc),
        xlb_f("StartDocPrinter", StartDocPrinter),
        xlb_f("StartPage", StartPage),
        xlb_f("StartPagePrinter", StartPagePrinter),
        xlb_f("StartService", StartService),
        xlb_f("StartServiceCtrlDispatcher", StartServiceCtrlDispatcher),
        xlb_f("StretchBlt", StretchBlt),
        xlb_f("StretchDIBits", StretchDIBits),
        xlb_f("StrokeAndFillPath", StrokeAndFillPath),
        xlb_f("StrokePath", StrokePath),
        xlb_f("SubtractRect", SubtractRect),
        xlb_f("SuspendThread", SuspendThread),
        xlb_f("SwapMouseButton", SwapMouseButton),
        xlb_f("SwitchDesktop", SwitchDesktop),
        xlb_f("SwitchToFiber", SwitchToFiber),
        xlb_f("SwitchToThread", SwitchToThread),
        xlb_class<xlb_cbf<HOOKPROC>>("SysMsgProc").constructor<xlb_luafunc>(),
        xlb_f("SystemParametersInfo", SystemParametersInfo),
        xlb_f("SystemTimeToFileTime", SystemTimeToFileTime),
        xlb_f("SystemTimeToTzSpecificLocalTime", SystemTimeToTzSpecificLocalTime),
        xlb_f("TabbedTextOut", TabbedTextOut),
        xlb_f("TerminateProcess", TerminateProcess),
        xlb_f("TerminateThread", TerminateThread),
        xlb_f("TextOut", TextOut),
        xlb_f("TileWindows", TileWindows),
        xlb_class<xlb_cbf<TIMERPROC>>("TimerProc").constructor<xlb_luafunc>(),
        xlb_f("TlsAlloc", TlsAlloc),
        xlb_f("TlsFree", TlsFree),
        xlb_f("TlsGetValue", TlsGetValue),
        xlb_f("TlsSetValue", TlsSetValue),
        xlb_f("ToAscii", ToAscii),
        xlb_f("ToAsciiEx", ToAsciiEx),
        xlb_f("ToUnicode", ToUnicode),
        xlb_f("ToUnicodeEx", ToUnicodeEx),
        xlb_f("TrackMouseEvent", TrackMouseEvent),
        xlb_f("TrackPopupMenu", TrackPopupMenu),
        xlb_f("TrackPopupMenuEx", TrackPopupMenuEx),
        xlb_f("TransactNamedPipe", TransactNamedPipe),
        xlb_f("TranslateAccelerator", TranslateAccelerator),
        xlb_f("TranslateCharsetInfo", TranslateCharsetInfo),
        xlb_f("TranslateMDISysAccel", TranslateMDISysAccel),
        xlb_f("TranslateMessage", TranslateMessage),
        xlb_f("TransmitCommChar", TransmitCommChar),
        xlb_f("TryEnterCriticalSection", TryEnterCriticalSection),
        //xlb_f("UInt32x32To64", UInt32x32To64),
        xlb_f("UInt32x32To64", [](uint32_t a, uint32_t b)->uint64_t { return UInt32x32To64(a,b); }),
        ////xlb_f("UndeleteFile", UndeleteFile), // FIXME
        xlb_f("UnhandledExceptionFilter", UnhandledExceptionFilter),
        xlb_f("UnhookWindowsHook", UnhookWindowsHook),
        xlb_f("UnhookWindowsHookEx", UnhookWindowsHookEx),
        xlb_f("UnionRect", UnionRect),
        xlb_f("UnloadKeyboardLayout", UnloadKeyboardLayout),
        xlb_f("UnlockFile", UnlockFile),
        xlb_f("UnlockFileEx", UnlockFileEx),
        ////xlb_f("UnlockResource", UnlockResource), // Outdated
        ////xlb_f("UnlockSegment", UnlockSegment), // Outdated
        xlb_f("UnlockServiceDatabase", UnlockServiceDatabase),
        xlb_f("UnmapViewOfFile", UnmapViewOfFile),
        xlb_f("UnpackDDElParam", UnpackDDElParam),
        xlb_f("UnrealizeObject", UnrealizeObject),
        xlb_f("UnregisterClass", UnregisterClass),
        xlb_f("UnregisterHotKey", UnregisterHotKey),
        xlb_f("UpdateColors", UpdateColors),
        xlb_f("UpdateICMRegKey", UpdateICMRegKey),
        xlb_f("UpdateResource", UpdateResource),
        xlb_f("UpdateWindow", UpdateWindow),
        xlb_f("ValidateRect", ValidateRect),
        xlb_f("ValidateRgn", ValidateRgn),
        //---xlb_f("VerFindFile", VerFindFile),
        //---xlb_f("VerInstallFile", VerInstallFile),
        xlb_f("VerLanguageName", VerLanguageName),
        //---xlb_f("VerQueryValue", VerQueryValue),
        xlb_f("VirtualAlloc", VirtualAlloc),
        xlb_f("VirtualAllocEx", VirtualAllocEx),
        xlb_f("VirtualFree", VirtualFree),
        xlb_f("VirtualFreeEx", VirtualFreeEx),
        xlb_f("VirtualLock", VirtualLock),
        xlb_f("VirtualProtect", VirtualProtect),
        xlb_f("VirtualProtectEx", VirtualProtectEx),
        xlb_f("VirtualQuery", VirtualQuery),
        xlb_f("VirtualQueryEx", VirtualQueryEx),
        xlb_f("VirtualUnlock", VirtualUnlock),
        xlb_f("VkKeyScan", VkKeyScan),
        xlb_f("VkKeyScanEx", VkKeyScanEx),
        //---xlb_f("VwStreamCloseFunc", VwStreamCloseFunc),
        //---xlb_f("VwStreamOpenFunc", VwStreamOpenFunc),
        //---xlb_f("VwStreamReadFunc", VwStreamReadFunc),
        //---xlb_f("VwStreamReadRecordFunc", VwStreamReadRecordFunc),
        //---xlb_f("VwStreamSectionFunc", VwStreamSectionFunc),
        //---xlb_f("VwStreamSeekFunc", VwStreamSeekFunc),
        //---xlb_f("VwStreamTellFunc", VwStreamTellFunc),
        xlb_f("WaitCommEvent", WaitCommEvent),
        xlb_f("WaitForDebugEvent", WaitForDebugEvent),
        xlb_f("WaitForInputIdle", WaitForInputIdle),
        xlb_f("WaitForMultipleObjects", WaitForMultipleObjects),
        xlb_f("WaitForMultipleObjectsEx", WaitForMultipleObjectsEx),
        xlb_f("WaitForPrinterChange", WaitForPrinterChange),
        xlb_f("WaitForSingleObject", WaitForSingleObject),
        xlb_f("WaitForSingleObjectEx", WaitForSingleObjectEx),
        xlb_f("WaitMessage", WaitMessage),
        xlb_f("WaitNamedPipe", WaitNamedPipe),
        xlb_f("WideCharToMultiByte", WideCharToMultiByte),
        xlb_f("WidenPath", WidenPath),
        xlb_f("WindowFromDC", WindowFromDC),
        xlb_f("WindowFromPoint", WindowFromPoint),
        xlb_class<xlb_cbf<WNDPROC>>("WNDPROC").constructor<xlb_luafunc>(), // WindowProc
        xlb_f("WinExec", WinExec),
        xlb_f("WinHelp", WinHelp),
        //xlb_f("WinLoadTrustProvider", WinLoadTrustProvider),
        //xlb_f("WinMain", WinMain),
        //xlb_f("WinSubmitCertificate", WinSubmitCertificate),
        //xlb_f("WinTrustProviderClientInitialize", WinTrustProviderClientInitialize),
        //xlb_f("WinTrustProviderClientUnload", WinTrustProviderClientUnload),
        //xlb_f("WinTrustProviderPing", WinTrustProviderPing),
        //xlb_f("WinTrustProviderServerInitialize", WinTrustProviderServerInitialize),
        //xlb_f("WinTrustProviderServerUnload", WinTrustProviderServerUnload),
        //xlb_f("WinTrustProviderSubmitCertificate", WinTrustProviderSubmitCertificate),
        //xlb_f("WinTrustProviderVerifyTrust", WinTrustProviderVerifyTrust),
        //xlb_f("WinTrustSipInitialize", WinTrustSipInitialize),
        //xlb_f("WinTrustSubjectCheckContentInfo", WinTrustSubjectCheckContentInfo),
        //xlb_f("WinTrustSubjectEnumCertificates", WinTrustSubjectEnumCertificates),
        //xlb_f("WinTrustSubjectGetCertHeader", WinTrustSubjectGetCertHeader),
        //xlb_f("WinTrustSubjectGetCertificate", WinTrustSubjectGetCertificate),
        //xlb_f("WinTrustSubjectGetName", WinTrustSubjectGetName),
        xlb_f("WinVerifyTrust", WinVerifyTrust),

#ifdef BIND_WIN_8_1_MINCORE_LIB
        xlb_f("WNetAddConnection", WNetAddConnection),
        xlb_f("WNetAddConnection2", WNetAddConnection2),
        xlb_f("WNetAddConnection3", WNetAddConnection3),
        xlb_f("WNetCancelConnection", WNetCancelConnection),
        xlb_f("WNetCancelConnection2", WNetCancelConnection2),
        xlb_f("WNetCloseEnum", WNetCloseEnum),
        xlb_f("WNetConnectionDialog", WNetConnectionDialog),
        xlb_f("WNetDisconnectDialog", WNetDisconnectDialog),
        xlb_f("WNetEnumResource", WNetEnumResource),
        xlb_f("WNetGetConnection", WNetGetConnection),
        xlb_f("WNetGetLastError", WNetGetLastError),
        xlb_f("WNetGetUniversalName", WNetGetUniversalName),
        xlb_f("WNetGetUser", WNetGetUser),
        xlb_f("WNetOpenEnum", WNetOpenEnum),
#endif // BIND_WIN_8_1_MINCORE_LIB

        xlb_f("WriteConsole", WriteConsole),
        xlb_f("WriteConsoleInput", WriteConsoleInput),
        xlb_f("WriteConsoleOutput", WriteConsoleOutput),
        xlb_f("WriteConsoleOutputAttribute", WriteConsoleOutputAttribute),
        xlb_f("WriteConsoleOutputCharacter", WriteConsoleOutputCharacter),
        xlb_f("WriteFile", WriteFile),
        xlb_f("WriteFileEx", WriteFileEx),
        xlb_f("WritePrinter", WritePrinter),
        xlb_f("WritePrivateProfileSection", WritePrivateProfileSection),
        xlb_f("WritePrivateProfileString", WritePrivateProfileString),
        xlb_f("WritePrivateProfileStruct", WritePrivateProfileStruct),
        xlb_f("WriteProcessMemory", WriteProcessMemory),
        xlb_f("WriteProfileSection", WriteProfileSection),
        xlb_f("WriteProfileString", WriteProfileString),
        xlb_f("WriteTapemark", WriteTapemark),
        //xlb_f("wsprintf", wsprintf),
        xlb_f("wvsprintf", wvsprintf),
        //xlb_f("Yield", Yield),
        xlb_f("ZeroMemory", [](PVOID ptr, SIZE_T cnt)->PVOID { return ::SecureZeroMemory(ptr,cnt); }),
        
#endif
#ifdef compile
#endif

        xlb_f("type", xlb_type),
        xlb_f("_version", lua_win_api_version)
    });

} // bind_win_api_function


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
        xlb_const("CHECK_BIND_DLG", 1)
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
        xlb_f("EnumPropsW", EnumPropsW),
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
        xlb_f("GetMessageW", GetMessageW),
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

        xlb_const("CHECK_BIND_WMSG", 1)
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
        xlb_f("AddFontResourceA", AddFontResourceA),
        xlb_f("AddFontResourceExA", AddFontResourceExA),
        xlb_f("AddFontResourceExW", AddFontResourceExW),
        xlb_f("AddFontResourceW", AddFontResourceW),
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
        xlb_f("ChangeDisplaySettingsA", ChangeDisplaySettingsA),
        xlb_f("ChangeDisplaySettingsExA", ChangeDisplaySettingsExA),
        xlb_f("ChangeDisplaySettingsExW", ChangeDisplaySettingsExW),
        xlb_f("ChangeDisplaySettingsW", ChangeDisplaySettingsW),
        xlb_f("Chord", Chord),
        xlb_f("ClientToScreen", ClientToScreen),
        xlb_f("CloseEnhMetaFile", CloseEnhMetaFile),
        xlb_f("CloseFigure", CloseFigure),
        xlb_f("CloseMetaFile", CloseMetaFile),
        xlb_f("CombineRgn", CombineRgn),
        xlb_f("CombineTransform", CombineTransform),
        xlb_f("CopyEnhMetaFileA", CopyEnhMetaFileA),
        xlb_f("CopyEnhMetaFileW", CopyEnhMetaFileW),
        xlb_f("CopyMetaFileA", CopyMetaFileA),
        xlb_f("CopyMetaFileW", CopyMetaFileW),
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
        xlb_f("CreateEnhMetaFileA", CreateEnhMetaFileA),
        xlb_f("CreateEnhMetaFileW", CreateEnhMetaFileW),
        xlb_f("CreateFontA", CreateFontA),
        xlb_f("CreateFontIndirectA", CreateFontIndirectA),
        xlb_f("CreateFontIndirectExA", CreateFontIndirectExA),
        xlb_f("CreateFontIndirectExW", CreateFontIndirectExW),
        xlb_f("CreateFontIndirectW", CreateFontIndirectW),
        xlb_f("CreateFontPackage", CreateFontPackage),
        xlb_f("CreateFontW", CreateFontW),
        xlb_f("CreateHalftonePalette", CreateHalftonePalette),
        xlb_f("CreateHatchBrush", CreateHatchBrush),
        xlb_f("CreateICA", CreateICA),
        xlb_f("CreateICW", CreateICW),
        xlb_f("CreateMetaFileA", CreateMetaFileA),
        xlb_f("CreateMetaFileW", CreateMetaFileW),
        xlb_f("CreatePalette", CreatePalette),
        xlb_f("CreatePatternBrush", CreatePatternBrush),
        xlb_f("CreatePen", CreatePen),
        xlb_f("CreatePenIndirect", CreatePenIndirect),
        xlb_f("CreatePolygonRgn", CreatePolygonRgn),
        xlb_f("CreatePolyPolygonRgn", CreatePolyPolygonRgn),
        xlb_f("CreateRectRgn", CreateRectRgn),
        xlb_f("CreateRectRgnIndirect", CreateRectRgnIndirect),
        xlb_f("CreateRoundRectRgn", CreateRoundRectRgn),
        xlb_f("CreateScalableFontResourceA", CreateScalableFontResourceA),
        xlb_f("CreateScalableFontResourceW", CreateScalableFontResourceW),
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
        xlb_f("DrawStateA", DrawStateA),
        xlb_class<xlb_cbf<DRAWSTATEPROC>>("DRAWSTATEPROC").constructor<xlb_luafunc>(),
        xlb_f("DrawStateW", DrawStateW),
        xlb_f("DrawText", DrawText),
        xlb_f("DrawTextA", DrawTextA),
        xlb_f("DrawTextExA", DrawTextExA),
        xlb_f("DrawTextExW", DrawTextExW),
        xlb_f("DrawTextW", DrawTextW),
        xlb_f("Ellipse", Ellipse),
        xlb_f("EndPaint", EndPaint),
        xlb_f("EndPath", EndPath),
        xlb_class<xlb_cbf<ENHMFENUMPROC>>("ENHMFENUMPROC").constructor<xlb_luafunc>(),
        xlb_f("EnumDisplayDevicesA", EnumDisplayDevicesA),
        xlb_f("EnumDisplayDevicesW", EnumDisplayDevicesW),
        xlb_f("EnumDisplayMonitors", EnumDisplayMonitors),
        xlb_f("EnumDisplaySettingsA", EnumDisplaySettingsA),
        xlb_f("EnumDisplaySettingsExA", EnumDisplaySettingsExA),
        xlb_f("EnumDisplaySettingsExW", EnumDisplaySettingsExW),
        xlb_f("EnumDisplaySettingsW", EnumDisplaySettingsW),
        xlb_f("EnumEnhMetaFile", EnumEnhMetaFile),
        xlb_f("EnumFontFamiliesA", EnumFontFamiliesA),
        xlb_f("EnumFontFamiliesExA", EnumFontFamiliesExA),
        xlb_f("EnumFontFamiliesExW", EnumFontFamiliesExW),
        xlb_f("EnumFontFamiliesW", EnumFontFamiliesW),
        xlb_f("EnumFontsA", EnumFontsA),
        xlb_f("EnumFontsW", EnumFontsW),
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
        xlb_f("ExtTextOutA", ExtTextOutA),
        xlb_f("ExtTextOutW", ExtTextOutW),
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
        xlb_f("GetCharABCWidthsA", GetCharABCWidthsA),
        xlb_f("GetCharABCWidthsFloatA", GetCharABCWidthsFloatA),
        xlb_f("GetCharABCWidthsFloatW", GetCharABCWidthsFloatW),
        xlb_f("GetCharABCWidthsI", GetCharABCWidthsI),
        xlb_f("GetCharABCWidthsW", GetCharABCWidthsW),
        xlb_f("GetCharacterPlacementA", GetCharacterPlacementA),
        xlb_f("GetCharacterPlacementW", GetCharacterPlacementW),
        xlb_f("GetCharWidth32A", GetCharWidth32A),
        xlb_f("GetCharWidth32W", GetCharWidth32W),
        xlb_f("GetCharWidthA", GetCharWidthA),
        xlb_f("GetCharWidthFloatA", GetCharWidthFloatA),
        xlb_f("GetCharWidthFloatW", GetCharWidthFloatW),
        xlb_f("GetCharWidthI", GetCharWidthI),
        xlb_f("GetCharWidthW", GetCharWidthW),
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
        xlb_f("GetEnhMetaFileA", GetEnhMetaFileA),
        xlb_f("GetEnhMetaFileBits", GetEnhMetaFileBits),
        xlb_f("GetEnhMetaFileDescriptionA", GetEnhMetaFileDescriptionA),
        xlb_f("GetEnhMetaFileDescriptionW", GetEnhMetaFileDescriptionW),
        xlb_f("GetEnhMetaFileHeader", GetEnhMetaFileHeader),
        xlb_f("GetEnhMetaFilePaletteEntries", GetEnhMetaFilePaletteEntries),
        xlb_f("GetEnhMetaFileW", GetEnhMetaFileW),
        xlb_f("GetFontData", GetFontData),
        xlb_f("GetFontLanguageInfo", GetFontLanguageInfo),
        xlb_f("GetFontUnicodeRanges", GetFontUnicodeRanges),
        xlb_f("GetGlyphIndicesA", GetGlyphIndicesA),
        xlb_f("GetGlyphIndicesW", GetGlyphIndicesW),
        xlb_f("GetGlyphOutlineA", GetGlyphOutlineA),
        xlb_f("GetGlyphOutlineW", GetGlyphOutlineW),
        xlb_f("GetGraphicsMode", GetGraphicsMode),
        xlb_f("GetGValue", [](COLORREF rgb) { return GetGValue(rgb); }),
        xlb_f("GetKerningPairsA", GetKerningPairsA),
        xlb_f("GetKerningPairsW", GetKerningPairsW),
        xlb_f("GetLayout", GetLayout),
        xlb_f("GetMapMode", GetMapMode),
        xlb_f("GetMetaFileA", GetMetaFileA),
        xlb_f("GetMetaFileBitsEx", GetMetaFileBitsEx),
        xlb_f("GetMetaFileW", GetMetaFileW),
        xlb_f("GetMetaRgn", GetMetaRgn),
        xlb_f("GetMiterLimit", GetMiterLimit),
        xlb_f("GetMonitorInfoA", GetMonitorInfoA),
        xlb_f("GetMonitorInfoW", GetMonitorInfoW),
        xlb_f("GetNearestColor", GetNearestColor),
        xlb_f("GetNearestPaletteIndex", GetNearestPaletteIndex),
        xlb_f("GetObject", GetObject),
        xlb_f("GetObjectA", GetObjectA),
        xlb_f("GetObjectType", GetObjectType),
        xlb_f("GetObjectW", GetObjectW),
        xlb_f("GetOutlineTextMetricsA", GetOutlineTextMetricsA),
        xlb_f("GetOutlineTextMetricsW", GetOutlineTextMetricsW),
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
        xlb_f("GetTabbedTextExtentA", GetTabbedTextExtentA),
        xlb_f("GetTabbedTextExtentW", GetTabbedTextExtentW),
        xlb_f("GetTextAlign", GetTextAlign),
        xlb_f("GetTextCharacterExtra", GetTextCharacterExtra),
        xlb_f("GetTextColor", GetTextColor),
        xlb_f("GetTextExtentExPointA", GetTextExtentExPointA),
        xlb_f("GetTextExtentExPointI", GetTextExtentExPointI),
        xlb_f("GetTextExtentExPointW", GetTextExtentExPointW),
        xlb_f("GetTextExtentPoint32A", GetTextExtentPoint32A),
        xlb_f("GetTextExtentPoint32W", GetTextExtentPoint32W),
        xlb_f("GetTextExtentPointA", GetTextExtentPointA),
        xlb_f("GetTextExtentPointI", GetTextExtentPointI),
        xlb_f("GetTextExtentPointW", GetTextExtentPointW),
        xlb_f("GetTextFaceA", GetTextFaceA),
        xlb_f("GetTextFaceW", GetTextFaceW),
        xlb_f("GetTextMetrics", GetTextMetrics),
        xlb_f("GetTextMetricsA", GetTextMetricsA),
        xlb_f("GetTextMetricsW", GetTextMetricsW),
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
        xlb_f("GrayStringA", GrayStringA),
        xlb_class<xlb_cbf<GRAYSTRINGPROC>>("GRAYSTRINGPROC").constructor<xlb_luafunc>(),
        xlb_f("GrayStringW", GrayStringW),
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
        xlb_f("LoadBitmapA", LoadBitmapA),
        xlb_f("LoadBitmapW", LoadBitmapW),
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
        xlb_f("PolyTextOutA", PolyTextOutA),
        xlb_f("PolyTextOutW", PolyTextOutW),
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
        xlb_f("RemoveFontResourceA", RemoveFontResourceA),
        xlb_f("RemoveFontResourceExA", RemoveFontResourceExA),
        xlb_f("RemoveFontResourceExW", RemoveFontResourceExW),
        xlb_f("RemoveFontResourceW", RemoveFontResourceW),
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
        xlb_f("TabbedTextOutA", TabbedTextOutA),
        xlb_f("TabbedTextOutW", TabbedTextOutW),
        xlb_f("TextOutA", TextOutA),
        xlb_f("TextOutW", TextOutW),
        xlb_f("TransparentBlt", TransparentBlt),
        xlb_f("TTCharToUnicode", TTCharToUnicode),
        xlb_f("TTDeleteEmbeddedFont", TTDeleteEmbeddedFont),
        xlb_f("TTEmbedFont", TTEmbedFont),
        xlb_f("TTEmbedFontEx", TTEmbedFontEx),
        xlb_f("TTEmbedFontFromFileA", TTEmbedFontFromFileA),
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
            .property("abcA", &ABC::abcA)
            .property("abcB", &ABC::abcB)
            .property("abcC", &ABC::abcC)
            ,
        xlb_class<ABCFLOAT>("ABCFLOAT") .constructor() .destructor()
            .property("abcfA", &ABCFLOAT::abcfA)
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
        xlb_const("CHECK_BIND_GDI", 1)
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
            xlb_f("SnmpUtilIdsToA", SnmpUtilIdsToA),
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
            xlb_f("SnmpUtilOidToA", SnmpUtilOidToA),
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
            xlb_const("CHECK_BIND_SNMP", 1)
    });
#endif // defined(CHECK_BIND_SNMP)

    return 0;
}

//-----------------------------------------------------------------------------
void bind_win_api_desktop_tech(lua_State* L)
{
    xlb_module(L, MODULE_NAME) ({
        xlb_f("load_snmp", load_snmp),
        xlb_f("load_gui", load_gui),
        xlb_f("load_wmsg", load_wmsg),
        xlb_f("load_dialog", load_dialog),
        xlb_const("WIN_API_DESKTOP_TECH", 1)
    });
} // bind_win_api_desktop_tech
