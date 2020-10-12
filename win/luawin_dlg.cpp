#include "luawin.h"

//------------------------------------------------------------------------------------------------
int load_dialog(lua_State* L)
{
#if defined(CHECK_BIND_DLG)

    xlb_module(L, MODULE_NAME) ({
        xlb_f("HIWORD", [](DWORD dw) { return HIWORD(dw); }),
        xlb_f("LOWORD", [](DWORD dw) { return LOWORD(dw); }),

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
        xlb_const("CHECK_BIND_DLG", CHECK_BIND_DLG)
    });
#endif // CHECK_BIND_DLG
    return 0;
}
