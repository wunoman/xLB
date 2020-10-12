#include "luawin.h"

//------------------------------------------------------------------------------------------------
int load_ctrl(lua_State* L)
{
#if defined(CHECK_BIND_CTRL)
    xlb_module(L, MODULE_NAME) ({

#if defined(WINVER) && (WINVER>=0x0600) // Vista
        xlb_f("CheckDlgButton", CheckDlgButton),
        xlb_f("CheckRadioButton", CheckRadioButton),
        xlb_f("IsDlgButtonChecked", IsDlgButtonChecked),
        xlb_f("Button_Enable", [](HWND hwnd, BOOL fEnable) { Button_Enable(hwnd, fEnable); }),
        xlb_f("Button_GetCheck", [](HWND hwnd)->UINT { return Button_GetCheck(hwnd); }),
        xlb_f("Button_GetIdealSize", [](HWND hwnd, SIZE* psize) { Button_GetIdealSize(hwnd, psize); }),
        xlb_f("Button_GetImageList", [](HWND hwnd, PBUTTON_IMAGELIST pil) { Button_GetImageList(hwnd, pil); }),
        xlb_f("Button_GetNote", [](HWND hwnd, LPCWSTR psz, int pcc) { Button_GetNote(hwnd, psz, pcc); }),
        xlb_f("Button_GetNoteLength", [](HWND hwnd)->UINT { return Button_GetNoteLength(hwnd); }),
        xlb_f("Button_GetSplitInfo", [](HWND hwnd, BUTTON_SPLITINFO* p) { Button_GetSplitInfo(hwnd, p); }),
        xlb_f("Button_GetState", [](HWND hwnd)->UINT { return Button_GetState(hwnd); }),
        xlb_f("Button_GetText", [](HWND hwnd, LPTSTR lpch, int cchMax) { Button_GetText(hwnd, lpch, cchMax); }),
        xlb_f("Button_GetTextMargin", [](HWND hwnd, RECT* pmargin) { Button_GetTextMargin(hwnd, pmargin); }),
        xlb_f("Button_SetCheck", [](HWND hwnd, int check) { Button_SetCheck(hwnd, check); }),
        xlb_f("Button_SetDropDownState", [](HWND hwnd, BOOL fDropDown) { Button_SetDropDownState(hwnd, fDropDown); }),
        xlb_f("Button_SetElevationRequiredState", [](HWND hwnd, BOOL fRequired) { Button_SetElevationRequiredState(hwnd, fRequired); }),
        xlb_f("Button_SetImageList", [](HWND hwnd, PBUTTON_IMAGELIST pil) { Button_SetImageList(hwnd, pil); }),
        xlb_f("Button_SetNote", [](HWND hwnd, LPCWSTR psz) { Button_SetNote(hwnd, psz); }),
        xlb_f("Button_SetSplitInfo", [](HWND hwnd, BUTTON_SPLITINFO* p) { Button_SetSplitInfo(hwnd, p); }),
        xlb_f("Button_SetState", [](HWND hwnd, BOOL state) { Button_SetState(hwnd, state); }),
        xlb_f("Button_SetStyle", [](HWND hwnd, DWORD style, BOOL fRedraw) { Button_SetStyle(hwnd, style, fRedraw); }),
        xlb_f("Button_SetText", [](HWND hwnd, LPTSTR lpsz) { Button_SetText(hwnd, lpsz); }),
        xlb_f("Button_SetTextMargin", [](HWND hwnd, RECT* pmargin) { Button_SetTextMargin(hwnd, pmargin); }),
        // Structures
        xlb_class<BUTTON_IMAGELIST>("BUTTON_IMAGELIST") .constructor<>() .destructor()
            .property("himl", &BUTTON_IMAGELIST::himl)
            .property("margin", &BUTTON_IMAGELIST::margin)
            .property("uAlign", &BUTTON_IMAGELIST::uAlign)
            ,
        xlb_class<BUTTON_SPLITINFO>("BUTTON_SPLITINFO") .constructor<>() .destructor()
            .property("mask", &BUTTON_SPLITINFO::mask)
            .property("himlGlyph", &BUTTON_SPLITINFO::himlGlyph)
            .property("uSplitStyle", &BUTTON_SPLITINFO::uSplitStyle)
            .property("size", &BUTTON_SPLITINFO::size)
            ,
        xlb_class<NMBCDROPDOWN>("NMBCDROPDOWN") .constructor<>() .destructor()
            .property("hdr", &NMBCDROPDOWN::hdr)
            .property("rcButton", &NMBCDROPDOWN::rcButton)
            ,
        xlb_class<NMBCHOTITEM>("NMBCHOTITEM") .constructor<>() .destructor()
            .property("hdr", &NMBCHOTITEM::hdr)
            .property("dwFlags", &NMBCHOTITEM::dwFlags)
            ,

        // Messages
        xlb_const("BCM_GETIDEALSIZE", BCM_GETIDEALSIZE),
        xlb_const("BCM_GETIMAGELIST", BCM_GETIMAGELIST),
        xlb_const("BCM_GETNOTE", BCM_GETNOTE),
        xlb_const("BCM_GETNOTELENGTH", BCM_GETNOTELENGTH),
        xlb_const("BCM_GETSPLITINFO", BCM_GETSPLITINFO),
        xlb_const("BCM_GETTEXTMARGIN", BCM_GETTEXTMARGIN),
        xlb_const("BCM_SETDROPDOWNSTATE", BCM_SETDROPDOWNSTATE),
        xlb_const("BCM_SETIMAGELIST", BCM_SETIMAGELIST),
        xlb_const("BCM_SETNOTE", BCM_SETNOTE),
        xlb_const("BCM_SETSHIELD", BCM_SETSHIELD),
        xlb_const("BCM_SETSPLITINFO", BCM_SETSPLITINFO),
        xlb_const("BCM_SETTEXTMARGIN", BCM_SETTEXTMARGIN),
        xlb_const("BM_CLICK", BM_CLICK),
        xlb_const("BM_GETCHECK", BM_GETCHECK),
        xlb_const("BM_GETIMAGE", BM_GETIMAGE),
        xlb_const("BM_GETSTATE", BM_GETSTATE),
        xlb_const("BM_SETCHECK", BM_SETCHECK),
        xlb_const("BM_SETDONTCLICK", BM_SETDONTCLICK),
        xlb_const("BM_SETIMAGE", BM_SETIMAGE),
        xlb_const("BM_SETSTATE", BM_SETSTATE),
        xlb_const("BM_SETSTYLE", BM_SETSTYLE),
        
        // Notifications
        xlb_const("BCN_DROPDOWN", BCN_DROPDOWN),
        xlb_const("BCN_HOTITEMCHANGE", BCN_HOTITEMCHANGE),
        xlb_const("BN_CLICKED", (uint32_t)BN_CLICKED), // value==0, ambiguouse
        xlb_const("BN_DBLCLK", BN_DBLCLK),
        xlb_const("BN_DISABLE", BN_DISABLE),
        xlb_const("BN_DOUBLECLICKED", BN_DOUBLECLICKED),
        xlb_const("BN_HILITE", BN_HILITE),
        xlb_const("BN_KILLFOCUS", BN_KILLFOCUS),
        xlb_const("BN_PAINT", BN_PAINT),
        xlb_const("BN_PUSHED", BN_PUSHED),
        xlb_const("BN_SETFOCUS", BN_SETFOCUS),
        xlb_const("BN_UNHILITE", BN_UNHILITE),
        xlb_const("BN_UNPUSHED", BN_UNPUSHED),
        xlb_const("NM_CUSTOMDRAW", NM_CUSTOMDRAW),
        xlb_const("WM_CTLCOLORBTN", WM_CTLCOLORBTN),

        // Button Styles
        xlb_const("BS_3STATE", BS_3STATE),
        xlb_const("BS_AUTO3STATE", BS_AUTO3STATE),
        xlb_const("BS_AUTOCHECKBOX", BS_AUTOCHECKBOX),
        xlb_const("BS_AUTORADIOBUTTON", BS_AUTORADIOBUTTON),
        xlb_const("BS_BITMAP", BS_BITMAP),
        xlb_const("BS_BOTTOM", BS_BOTTOM),
        xlb_const("BS_CENTER", BS_CENTER),
        xlb_const("BS_CHECKBOX", BS_CHECKBOX),
        xlb_const("BS_COMMANDLINK", BS_COMMANDLINK),
        xlb_const("BS_DEFCOMMANDLINK", BS_DEFCOMMANDLINK),
        xlb_const("BS_DEFPUSHBUTTON", BS_DEFPUSHBUTTON),
        xlb_const("BS_DEFSPLITBUTTON", BS_DEFSPLITBUTTON),
        xlb_const("BS_GROUPBOX", BS_GROUPBOX),
        xlb_const("BS_ICON", BS_ICON),
        xlb_const("BS_FLAT", BS_FLAT),
        xlb_const("BS_LEFT", BS_LEFT),
        xlb_const("BS_LEFTTEXT", BS_LEFTTEXT),
        xlb_const("BS_MULTILINE", BS_MULTILINE),
        xlb_const("BS_NOTIFY", BS_NOTIFY),
        xlb_const("BS_OWNERDRAW", BS_OWNERDRAW),
        xlb_const("BS_PUSHBUTTON", (uint32_t)BS_PUSHBUTTON),
        xlb_const("BS_PUSHLIKE", BS_PUSHLIKE),
        xlb_const("BS_RADIOBUTTON", BS_RADIOBUTTON),
        xlb_const("BS_RIGHT", BS_RIGHT),
        xlb_const("BS_RIGHTBUTTON", BS_RIGHTBUTTON),
        xlb_const("BS_SPLITBUTTON", BS_SPLITBUTTON),
        xlb_const("BS_TEXT", (uint32_t)BS_TEXT),
        xlb_const("BS_TOP", BS_TOP),
        xlb_const("BS_TYPEMASK", BS_TYPEMASK),
        xlb_const("BS_USERBUTTON", BS_USERBUTTON),
        xlb_const("BS_VCENTER", BS_VCENTER),

        // System Colors
        xlb_const("COLOR_3DDKSHADOW", COLOR_3DDKSHADOW),
        xlb_const("COLOR_3DFACE", COLOR_3DFACE),
        xlb_const("COLOR_3DHIGHLIGHT", COLOR_3DHIGHLIGHT),
        xlb_const("COLOR_3DHILIGHT", COLOR_3DHILIGHT),
        xlb_const("COLOR_3DLIGHT", COLOR_3DLIGHT),
        xlb_const("COLOR_3DSHADOW", COLOR_3DSHADOW),
        xlb_const("COLOR_ACTIVEBORDER", COLOR_ACTIVEBORDER),
        xlb_const("COLOR_ACTIVECAPTION", COLOR_ACTIVECAPTION),
        xlb_const("COLOR_APPWORKSPACE", COLOR_APPWORKSPACE),
        xlb_const("COLOR_BACKGROUND", COLOR_BACKGROUND),
        xlb_const("COLOR_BTNFACE", COLOR_BTNFACE),
        xlb_const("COLOR_BTNHIGHLIGHT", COLOR_BTNHIGHLIGHT),
        xlb_const("COLOR_BTNHILIGHT", COLOR_BTNHILIGHT),
        xlb_const("COLOR_BTNSHADOW", COLOR_BTNSHADOW),
        xlb_const("COLOR_BTNTEXT", COLOR_BTNTEXT),
        xlb_const("COLOR_CAPTIONTEXT", COLOR_CAPTIONTEXT),
        xlb_const("COLOR_DESKTOP", COLOR_DESKTOP),
        xlb_const("COLOR_GRADIENTACTIVECAPTION", COLOR_GRADIENTACTIVECAPTION),
        xlb_const("COLOR_GRADIENTINACTIVECAPTION", COLOR_GRADIENTINACTIVECAPTION),
        xlb_const("COLOR_GRAYTEXT", COLOR_GRAYTEXT),
        xlb_const("COLOR_HIGHLIGHT", COLOR_HIGHLIGHT),
        xlb_const("COLOR_HIGHLIGHTTEXT", COLOR_HIGHLIGHTTEXT),
        xlb_const("COLOR_HOTLIGHT", COLOR_HOTLIGHT),
        xlb_const("COLOR_INACTIVEBORDER", COLOR_INACTIVEBORDER),
        xlb_const("COLOR_INACTIVECAPTION", COLOR_INACTIVECAPTION),
        xlb_const("COLOR_INACTIVECAPTIONTEXT", COLOR_INACTIVECAPTIONTEXT),
        xlb_const("COLOR_INFOBK", COLOR_INFOBK),
        xlb_const("COLOR_INFOTEXT", COLOR_INFOTEXT),
        xlb_const("COLOR_MENU", COLOR_MENU),
        xlb_const("COLOR_MENUHILIGHT", COLOR_MENUHILIGHT),
        xlb_const("COLOR_MENUBAR", COLOR_MENUBAR),
        xlb_const("COLOR_MENUTEXT", COLOR_MENUTEXT),
        xlb_const("COLOR_SCROLLBAR", (uint32_t)COLOR_SCROLLBAR),
        xlb_const("COLOR_WINDOW", COLOR_WINDOW),
        xlb_const("COLOR_WINDOWFRAME", COLOR_WINDOWFRAME),
        xlb_const("COLOR_WINDOWTEXT", COLOR_WINDOWTEXT),

        // ComboBox
        xlb_f("DlgDirListComboBox", DlgDirListComboBox), 
        xlb_f("DlgDirSelectComboBoxEx", DlgDirSelectComboBoxEx), 
        xlb_f("GetComboBoxInfo", GetComboBoxInfo), 
        xlb_f("ComboBox_AddItemData", [](HWND hwnd, LPARAM data) { ComboBox_AddItemData(hwnd, data); }),
        xlb_f("ComboBox_AddString", [](HWND hwnd, LPCTSTR lpsz) { ComboBox_AddString(hwnd, lpsz); }),
        xlb_f("ComboBox_DeleteString", [](HWND hwnd, int index) { ComboBox_DeleteString(hwnd, index); }),
        xlb_f("ComboBox_Dir", [](HWND hwnd, UINT attrs, LPCTSTR lpszFileSpec) { ComboBox_Dir(hwnd, attrs, lpszFileSpec); }),
        xlb_f("ComboBox_Enable", [](HWND hwnd, BOOL fEnable) { ComboBox_Enable(hwnd, fEnable); }),
        xlb_f("ComboBox_FindItemData", [](HWND hwnd, int indexStart, LPARAM data)->int{ return ComboBox_FindItemData(hwnd, indexStart, data); }),
        xlb_f("ComboBox_FindString", [](HWND hwnd, int indexStart, LPCSTR lpszFind)->int{ return ComboBox_FindString(hwnd, indexStart, lpszFind); }),
        xlb_f("ComboBox_FindStringExact", [](HWND hwnd, int indexStart, LPCSTR lpszFind)->int{ return ComboBox_FindStringExact(hwnd, indexStart, lpszFind); }),
        xlb_f("ComboBox_GetCount", [](HWND hwnd)->int{ return ComboBox_GetCount(hwnd); }),
        xlb_f("ComboBox_GetCurSel", [](HWND hwnd)->int{ return ComboBox_GetCurSel(hwnd); }),
        xlb_f("ComboBox_GetDroppedControlRect", [](HWND hwnd, RECT* lprc) { ComboBox_GetDroppedControlRect(hwnd, lprc); }),
        xlb_f("ComboBox_GetDroppedState", [](HWND hwnd)->BOOL { return ComboBox_GetDroppedState(hwnd); }),
        xlb_f("ComboBox_GetExtendedUI", [](HWND hwnd)->UINT { return ComboBox_GetExtendedUI(hwnd); }),
        xlb_f("ComboBox_GetItemData", [](HWND hwnd, int index)->LRESULT { return ComboBox_GetItemData(hwnd, index); }),
        xlb_f("ComboBox_GetItemHeight", [](HWND hwnd)->UINT { return ComboBox_GetItemHeight(hwnd); }),
        xlb_f("ComboBox_GetLBText", [](HWND hwnd, int index, LPCTSTR lpszBuffer){ ComboBox_GetLBText(hwnd, index, lpszBuffer); }),
        xlb_f("ComboBox_GetLBTextLen", [](HWND hwnd, int index)->int { return ComboBox_GetLBTextLen(hwnd, index); }),
        xlb_f("ComboBox_GetText", [](HWND hwnd, LPTSTR lpch, int cchMax) { ComboBox_GetText(hwnd, lpch, cchMax); }),
        xlb_f("ComboBox_GetTextLength", [](HWND hwnd)->int { return ComboBox_GetTextLength(hwnd); }),
        xlb_f("ComboBox_InsertItemData", [](HWND hwnd, int index, LPARAM data) { ComboBox_InsertItemData(hwnd, index, data); }),
        xlb_f("ComboBox_InsertString", [](HWND hwnd, int index, LPCSTR lpsz) { ComboBox_InsertString(hwnd, index, lpsz); }),
        xlb_f("ComboBox_LimitText", [](HWND hwnd, int cchLimit)->int { return ComboBox_LimitText(hwnd, cchLimit); }),
        xlb_f("ComboBox_ResetContent", [](HWND hwnd) { ComboBox_ResetContent(hwnd); }),
        xlb_f("ComboBox_SelectItemData", [](HWND hwnd, int indexStart, LPARAM data) { ComboBox_SelectItemData(hwnd, indexStart, data); }),
        xlb_f("ComboBox_SelectString", [](HWND hwnd, int indexStart, LPCTSTR lpszSelect) { ComboBox_SelectString(hwnd, indexStart, lpszSelect); }),
        xlb_f("ComboBox_SetCurSel", [](HWND hwnd, int index) { ComboBox_SetCurSel(hwnd, index); }),
        xlb_f("ComboBox_SetExtendedUI", [](HWND hwnd, UINT flags) { ComboBox_SetExtendedUI(hwnd, flags); }),
        xlb_f("ComboBox_SetItemData", [](HWND hwnd, int index, LPARAM data) { ComboBox_SetItemData(hwnd, index, data); }),
        xlb_f("ComboBox_SetItemHeight", [](HWND hwnd, int index, int cyItem) { ComboBox_SetItemHeight(hwnd, index, cyItem); }),
        xlb_f("ComboBox_SetText", [](HWND hwnd, LPTSTR lpsz) { ComboBox_SetText(hwnd, lpsz); }),
        xlb_f("ComboBox_ShowDropdown", [](HWND hwnd, BOOL fShow) { ComboBox_ShowDropdown(hwnd, fShow); }),

        // Messages
        xlb_const("CB_ADDSTRING", CB_ADDSTRING),
        xlb_const("CB_DELETESTRING", CB_DELETESTRING),
        xlb_const("CB_DIR", CB_DIR),
        xlb_const("CB_FINDSTRING", CB_FINDSTRING),
        xlb_const("CB_FINDSTRINGEXACT", CB_FINDSTRINGEXACT),
        xlb_const("CB_GETCOMBOBOXINFO", CB_GETCOMBOBOXINFO),
        xlb_const("CB_GETCOUNT", CB_GETCOUNT),
        xlb_const("CB_GETCUEBANNER", CB_GETCUEBANNER),
        xlb_const("CB_GETCURSEL", CB_GETCURSEL),
        xlb_const("CB_GETDROPPEDCONTROLRECT", CB_GETDROPPEDCONTROLRECT),
        xlb_const("CB_GETDROPPEDSTATE", CB_GETDROPPEDSTATE),
        xlb_const("CB_GETDROPPEDWIDTH", CB_GETDROPPEDWIDTH),
        xlb_const("CB_GETEDITSEL", CB_GETEDITSEL),
        xlb_const("CB_GETEXTENDEDUI", CB_GETEXTENDEDUI),
        xlb_const("CB_GETHORIZONTALEXTENT", CB_GETHORIZONTALEXTENT),
        xlb_const("CB_GETITEMDATA", CB_GETITEMDATA),
        xlb_const("CB_GETITEMHEIGHT", CB_GETITEMHEIGHT),
        xlb_const("CB_GETLBTEXT", CB_GETLBTEXT),
        xlb_const("CB_GETLBTEXTLEN", CB_GETLBTEXTLEN),
        xlb_const("CB_GETLOCALE", CB_GETLOCALE),
        xlb_const("CB_GETMINVISIBLE", CB_GETMINVISIBLE),
        xlb_const("CB_GETTOPINDEX", CB_GETTOPINDEX),
        xlb_const("CB_INITSTORAGE", CB_INITSTORAGE),
        xlb_const("CB_INSERTSTRING", CB_INSERTSTRING),
        xlb_const("CB_LIMITTEXT", CB_LIMITTEXT),
        xlb_const("CB_RESETCONTENT", CB_RESETCONTENT),
        xlb_const("CB_SELECTSTRING", CB_SELECTSTRING),
        xlb_const("CB_SETCUEBANNER", CB_SETCUEBANNER),
        xlb_const("CB_SETCURSEL", CB_SETCURSEL),
        xlb_const("CB_SETDROPPEDWIDTH", CB_SETDROPPEDWIDTH),
        xlb_const("CB_SETEDITSEL", CB_SETEDITSEL),
        xlb_const("CB_SETEXTENDEDUI", CB_SETEXTENDEDUI),
        xlb_const("CB_SETHORIZONTALEXTENT", CB_SETHORIZONTALEXTENT),
        xlb_const("CB_SETITEMDATA", CB_SETITEMDATA),
        xlb_const("CB_SETITEMHEIGHT", CB_SETITEMHEIGHT),
        xlb_const("CB_SETLOCALE", CB_SETLOCALE),
        xlb_const("CB_SETMINVISIBLE", CB_SETMINVISIBLE),
        xlb_const("CB_SETTOPINDEX", CB_SETTOPINDEX),
        xlb_const("CB_SHOWDROPDOWN", CB_SHOWDROPDOWN),
        
        // Notifications
        xlb_const("CBN_CLOSEUP", CBN_CLOSEUP),
        xlb_const("CBN_DBLCLK", CBN_DBLCLK),
        xlb_const("CBN_DROPDOWN", CBN_DROPDOWN),
        xlb_const("CBN_EDITCHANGE", CBN_EDITCHANGE),
        xlb_const("CBN_EDITUPDATE", CBN_EDITUPDATE),
        xlb_const("CBN_ERRSPACE", CBN_ERRSPACE),
        xlb_const("CBN_KILLFOCUS", CBN_KILLFOCUS),
        xlb_const("CBN_SELCHANGE", CBN_SELCHANGE),
        xlb_const("CBN_SELENDCANCEL", CBN_SELENDCANCEL),
        xlb_const("CBN_SELENDOK", CBN_SELENDOK),
        xlb_const("CBN_SETFOCUS", CBN_SETFOCUS),
        xlb_const("WM_COMPAREITEM", WM_COMPAREITEM),
        xlb_const("WM_DRAWITEM", WM_DRAWITEM),
        xlb_const("WM_MEASUREITEM", WM_MEASUREITEM),

        // Structures
        xlb_class<COMBOBOXINFO>("COMBOBOXINFO") .constructor<>() .destructor()
            .property("cbSize", &COMBOBOXINFO::cbSize)
            .property("rcItem", &COMBOBOXINFO::rcItem)
            .property("rcButton", &COMBOBOXINFO::rcButton)
            .property("stateButton", &COMBOBOXINFO::stateButton)
            .property("hwndCombo", &COMBOBOXINFO::hwndCombo)
            .property("hwndItem", &COMBOBOXINFO::hwndItem)
            .property("hwndList", &COMBOBOXINFO::hwndList)
            ,
        xlb_class<COMPAREITEMSTRUCT>("COMPAREITEMSTRUCT") .constructor<>() .destructor()
            .property("CtlType", &COMPAREITEMSTRUCT::CtlType)
            .property("CtlID", &COMPAREITEMSTRUCT::CtlID)
            .property("hwndItem", &COMPAREITEMSTRUCT::hwndItem)
            .property("itemID1", &COMPAREITEMSTRUCT::itemID1)
            .property("itemData1", &COMPAREITEMSTRUCT::itemData1)
            .property("itemID2", &COMPAREITEMSTRUCT::itemID2)
            .property("itemData2", &COMPAREITEMSTRUCT::itemData2)
            .property("dwLocaleId", &COMPAREITEMSTRUCT::dwLocaleId)
            ,
        xlb_class<DRAWITEMSTRUCT>("DRAWITEMSTRUCT") .constructor<>() .destructor()
            .property("CtlType", &DRAWITEMSTRUCT::CtlType)
            .property("CtlID", &DRAWITEMSTRUCT::CtlID)
            .property("itemID", &DRAWITEMSTRUCT::itemID)
            .property("itemAction", &DRAWITEMSTRUCT::itemAction)
            .property("itemState", &DRAWITEMSTRUCT::itemState)
            .property("hwndItem", &DRAWITEMSTRUCT::hwndItem)
            .property("hDC", &DRAWITEMSTRUCT::hDC)
            .property("rcItem", &DRAWITEMSTRUCT::rcItem)
            .property("itemData", &DRAWITEMSTRUCT::itemData)
            ,
        xlb_class<MEASUREITEMSTRUCT>("MEASUREITEMSTRUCT") .constructor<>() .destructor()
            .property("CtlType", &MEASUREITEMSTRUCT::CtlType)
            .property("CtlID", &MEASUREITEMSTRUCT::CtlID)
            .property("itemID", &MEASUREITEMSTRUCT::itemID)
            .property("itemWidth", &MEASUREITEMSTRUCT::itemWidth)
            .property("itemHeight", &MEASUREITEMSTRUCT::itemHeight)
            .property("itemData", &MEASUREITEMSTRUCT::itemData)
            ,
        // Constants
        xlb_const("CBS_AUTOHSCROLL", CBS_AUTOHSCROLL),
        xlb_const("CBS_DISABLENOSCROLL", CBS_DISABLENOSCROLL),
        xlb_const("CBS_DROPDOWN", CBS_DROPDOWN),
        xlb_const("CBS_DROPDOWNLIST", CBS_DROPDOWNLIST),
        xlb_const("CBS_HASSTRINGS", CBS_HASSTRINGS),
        xlb_const("CBS_LOWERCASE", CBS_LOWERCASE),
        xlb_const("CBS_NOINTEGRALHEIGHT", CBS_NOINTEGRALHEIGHT),
        xlb_const("CBS_OEMCONVERT", CBS_OEMCONVERT),
        xlb_const("CBS_OWNERDRAWFIXED", CBS_OWNERDRAWFIXED),
        xlb_const("CBS_OWNERDRAWVARIABLE", CBS_OWNERDRAWVARIABLE),
        xlb_const("CBS_SIMPLE", CBS_SIMPLE),
        xlb_const("CBS_SORT", CBS_SORT),
        xlb_const("CBS_UPPERCASE", CBS_UPPERCASE),

        // ComboBoxEx
        // Messages
        xlb_const("CBEM_DELETEITEM", CBEM_DELETEITEM),
        xlb_const("CBEM_GETCOMBOCONTROL", CBEM_GETCOMBOCONTROL),
        xlb_const("CBEM_GETEDITCONTROL", CBEM_GETEDITCONTROL),
        xlb_const("CBEM_GETEXTENDEDSTYLE", CBEM_GETEXTENDEDSTYLE),
        xlb_const("CBEM_GETIMAGELIST", CBEM_GETIMAGELIST),
        xlb_const("CBEM_GETITEM", CBEM_GETITEM),
        xlb_const("CBEM_GETUNICODEFORMAT", CBEM_GETUNICODEFORMAT),
        xlb_const("CBEM_HASEDITCHANGED", CBEM_HASEDITCHANGED),
        xlb_const("CBEM_INSERTITEM", CBEM_INSERTITEM),
        //xlb_const("CBEM_KILLCOMBOFOCUS", CBEM_KILLCOMBOFOCUS), // This message is not implemented.
        //xlb_const("CBEM_SETCOMBOFOCUS", CBEM_SETCOMBOFOCUS), // This message is not implemented.
        xlb_const("CBEM_SETEXTENDEDSTYLE", CBEM_SETEXTENDEDSTYLE),
        xlb_const("CBEM_SETIMAGELIST", CBEM_SETIMAGELIST),
        xlb_const("CBEM_SETITEM", CBEM_SETITEM),
        xlb_const("CBEM_SETUNICODEFORMAT", CBEM_SETUNICODEFORMAT),
        xlb_const("CBEM_SETWINDOWTHEME", CBEM_SETWINDOWTHEME),

        // Notifications
        xlb_const("CBEN_BEGINEDIT", CBEN_BEGINEDIT),
        xlb_const("CBEN_DELETEITEM", CBEN_DELETEITEM),
        xlb_const("CBEN_DRAGBEGIN", CBEN_DRAGBEGIN),
        xlb_const("CBEN_ENDEDIT", CBEN_ENDEDIT),
        xlb_const("CBEN_GETDISPINFO", CBEN_GETDISPINFO),
        xlb_const("CBEN_INSERTITEM", CBEN_INSERTITEM),
        xlb_const("NM_SETCURSOR", NM_SETCURSOR),

        // Structures
        xlb_class<COMBOBOXEXITEM>("COMBOBOXEXITEM") .constructor<>() .destructor()
            .property("mask", &COMBOBOXEXITEM::mask)
            .property("iItem", &COMBOBOXEXITEM::iItem)
            .property("pszText", &COMBOBOXEXITEM::pszText)
            .property("cchTextMax", &COMBOBOXEXITEM::cchTextMax)
            .property("iImage", &COMBOBOXEXITEM::iImage)
            .property("iSelectedImage", &COMBOBOXEXITEM::iSelectedImage)
            .property("iOverlay", &COMBOBOXEXITEM::iOverlay)
            .property("iIndent", &COMBOBOXEXITEM::iIndent)
            .property("lParam", &COMBOBOXEXITEM::lParam)
            ,
        xlb_class<NMCBEDRAGBEGIN>("NMCBEDRAGBEGIN") .constructor<>() .destructor()
            .property("hdr", &NMCBEDRAGBEGIN::hdr)
            .property("iItemid", &NMCBEDRAGBEGIN::iItemid)
            .property("szText", &NMCBEDRAGBEGIN::szText)
            ,
        xlb_class<NMCBEENDEDIT>("NMCBEENDEDIT") .constructor<>() .destructor()
            .property("hdr", &NMCBEENDEDIT::hdr)
            .property("fChanged", &NMCBEENDEDIT::fChanged)
            .property("iNewSelection", &NMCBEENDEDIT::iNewSelection)
            .property("szText", &NMCBEENDEDIT::szText)
            .property("iWhy", &NMCBEENDEDIT::iWhy)
            ,
        xlb_class<NMCOMBOBOXEX>("NMCOMBOBOXEX") .constructor<>() .destructor()
            .property("hdr", &NMCOMBOBOXEX::hdr)
            .property("ceItem", &NMCOMBOBOXEX::ceItem)
            ,
        // Styles
        xlb_const("CBES_EX_CASESENSITIVE", CBES_EX_CASESENSITIVE),
        xlb_const("CBES_EX_NOEDITIMAGE", CBES_EX_NOEDITIMAGE),
        xlb_const("CBES_EX_NOEDITIMAGEINDENT", CBES_EX_NOEDITIMAGEINDENT),
        xlb_const("CBES_EX_NOSIZELIMIT", CBES_EX_NOSIZELIMIT),
        xlb_const("CBES_EX_PATHWORDBREAKPROC", CBES_EX_PATHWORDBREAKPROC),
        xlb_const("CBES_EX_TEXTENDELLIPSIS", CBES_EX_TEXTENDELLIPSIS),

        // Date and Time Picker
        // Macro
        xlb_f("DateTime_CloseMonthCal", [](HWND hwnd) { DateTime_CloseMonthCal(hwnd); }),
        xlb_f("DateTime_GetDateTimePickerInfo", [](HWND hwnd, DATETIMEPICKERINFO* pdtpi) { DateTime_GetDateTimePickerInfo(hwnd, pdtpi); }),
        xlb_f("DateTime_GetIdealSize", [](HWND hwnd, SIZE* psize) { DateTime_GetIdealSize(hwnd, psize); }),
        xlb_f("DateTime_GetMonthCal", [](HWND hwnd)->HWND { return DateTime_GetMonthCal(hwnd); }),
        xlb_f("DateTime_GetMonthCalColor", [](HWND hwnd, int iColor) { DateTime_GetMonthCalColor(hwnd, iColor); }),
        xlb_const("MCSC_BACKGROUND", (uint32_t)MCSC_BACKGROUND),
        xlb_const("MCSC_MONTHBK", MCSC_MONTHBK),
        xlb_const("MCSC_TEXT", MCSC_TEXT),
        xlb_const("MCSC_TITLEBK", MCSC_TITLEBK),
        xlb_const("MCSC_TITLETEXT", MCSC_TITLETEXT),
        xlb_const("MCSC_TRAILINGTEXT", MCSC_TRAILINGTEXT),
        xlb_f("DateTime_GetMonthCalFont", [](HWND hwnd) { DateTime_GetMonthCalFont(hwnd); }),
        xlb_f("DateTime_GetMonthCalStyle", [](HWND hwnd) { DateTime_GetMonthCalStyle(hwnd); }),
        xlb_f("DateTime_GetRange", [](HWND hwnd, LPSYSTEMTIME rgst) { DateTime_GetRange(hwnd, rgst); }),
        xlb_f("DateTime_GetSystemtime", [](HWND hwnd, LPSYSTEMTIME pst) { DateTime_GetSystemtime(hwnd, pst); }),
        xlb_f("DateTime_SetFormat", [](HWND hwnd, LPCTSTR sz) { DateTime_SetFormat(hwnd, sz); }),
        xlb_f("DateTime_SetMonthCalColor", [](HWND hwnd, int iColor, COLORREF clr) { DateTime_SetMonthCalColor(hwnd, iColor, clr); }),
        xlb_f("DateTime_SetMonthCalFont", [](HWND hwnd, HFONT hfont, long fRedraw) { DateTime_SetMonthCalFont(hwnd, hfont, fRedraw); }),
        xlb_f("DateTime_SetMonthCalStyle", [](HWND hwnd, DWORD dwStyle) { DateTime_SetMonthCalStyle(hwnd, dwStyle); }),
        xlb_f("DateTime_SetRange", [](HWND hwnd, DWORD gd, LPSYSTEMTIME rgst) { DateTime_SetRange(hwnd, gd, rgst); }),
        xlb_const("GDTR_MIN", GDTR_MIN),
        xlb_const("GDTR_MAX", GDTR_MAX),
        xlb_f("DateTime_SetSystemtime", [](HWND hwnd, DWORD gd, LPSYSTEMTIME pst) { DateTime_SetSystemtime(hwnd, gd, pst); }),
        xlb_const("GDT_VALID", (uint32_t)GDT_VALID),
        xlb_const("GDT_NONE", GDT_NONE),
        // Messages
        xlb_const("DTM_CLOSEMONTHCAL", DTM_CLOSEMONTHCAL),
        xlb_const("DTM_GETDATETIMEPICKERINFO", DTM_GETDATETIMEPICKERINFO),
        xlb_const("DTM_GETIDEALSIZE", DTM_GETIDEALSIZE),
        xlb_const("DTM_GETMCCOLOR", DTM_GETMCCOLOR),
        xlb_const("DTM_GETMCFONT", DTM_GETMCFONT),
        xlb_const("DTM_GETMCSTYLE", DTM_GETMCSTYLE),
        xlb_const("DTM_GETMONTHCAL", DTM_GETMONTHCAL),
        xlb_const("DTM_GETRANGE", DTM_GETRANGE),
        xlb_const("DTM_GETSYSTEMTIME", DTM_GETSYSTEMTIME),
        xlb_const("DTM_SETFORMAT", DTM_SETFORMAT),
        xlb_const("DTM_SETMCCOLOR", DTM_SETMCCOLOR),
        xlb_const("DTM_SETMCFONT", DTM_SETMCFONT),
        xlb_const("DTM_SETMCSTYLE", DTM_SETMCSTYLE),
        xlb_const("DTM_SETRANGE", DTM_SETRANGE),
        xlb_const("DTM_SETSYSTEMTIME", DTM_SETSYSTEMTIME),
        
        // Notifications
        xlb_const("DTN_CLOSEUP", DTN_CLOSEUP),
        xlb_const("DTN_DATETIMECHANGE", DTN_DATETIMECHANGE),
        xlb_const("DTN_DROPDOWN", DTN_DROPDOWN),
        xlb_const("DTN_FORMAT", DTN_FORMAT),
        xlb_const("DTN_FORMATQUERY", DTN_FORMATQUERY),
        xlb_const("DTN_USERSTRING", DTN_USERSTRING),
        xlb_const("DTN_WMKEYDOWN", DTN_WMKEYDOWN),
        xlb_const("NM_KILLFOCUS", NM_KILLFOCUS),
        xlb_const("NM_SETFOCUS", NM_SETFOCUS),
        // Styles
        xlb_const("MCS_DAYSTATE", MCS_DAYSTATE),
        xlb_const("MCS_MULTISELECT", MCS_MULTISELECT),
        xlb_const("MCS_WEEKNUMBERS", MCS_WEEKNUMBERS),
        xlb_const("MCS_NOTODAYCIRCLE", MCS_NOTODAYCIRCLE),
        xlb_const("MCS_NOTODAY", MCS_NOTODAY),
        xlb_const("MCS_NOTRAILINGDATES", MCS_NOTRAILINGDATES),
        xlb_const("MCS_SHORTDAYSOFWEEK", MCS_SHORTDAYSOFWEEK),
        xlb_const("MCS_NOSELCHANGEONNAV", MCS_NOSELCHANGEONNAV),
        xlb_const("DTS_APPCANPARSE", DTS_APPCANPARSE),
        xlb_const("DTS_LONGDATEFORMAT", DTS_LONGDATEFORMAT),
        xlb_const("DTS_RIGHTALIGN", DTS_RIGHTALIGN),
        xlb_const("DTS_SHOWNONE", DTS_SHOWNONE),
        xlb_const("DTS_SHORTDATEFORMAT", (uint32_t)DTS_SHORTDATEFORMAT),
        xlb_const("DTS_SHORTDATECENTURYFORMAT", DTS_SHORTDATECENTURYFORMAT),
        xlb_const("DTS_TIMEFORMAT", DTS_TIMEFORMAT),
        xlb_const("DTS_UPDOWN", DTS_UPDOWN),
        // Structures
        xlb_class<DATETIMEPICKERINFO>("DATETIMEPICKERINFO") .constructor<>() .destructor()
            .property("cbSize", &DATETIMEPICKERINFO::cbSize)
            .property("rcCheck", &DATETIMEPICKERINFO::rcCheck)
            .property("stateCheck", &DATETIMEPICKERINFO::stateCheck)
            .property("rcButton", &DATETIMEPICKERINFO::rcButton)
            .property("stateButton", &DATETIMEPICKERINFO::stateButton)
            .property("hwndEdit", &DATETIMEPICKERINFO::hwndEdit)
            .property("hwndUD", &DATETIMEPICKERINFO::hwndUD)
            .property("hwndDropDown", &DATETIMEPICKERINFO::hwndDropDown)
            ,
        xlb_class<NMDATETIMECHANGE>("NMDATETIMECHANGE") .constructor<>() .destructor()
            .property("nmhdr", &NMDATETIMECHANGE::nmhdr)
            .property("dwFlags", &NMDATETIMECHANGE::dwFlags)
            .property("st", &NMDATETIMECHANGE::st)
            ,
        xlb_class<NMDATETIMEFORMAT>("NMDATETIMEFORMAT") .constructor<>() .destructor()
            .property("nmhdr", &NMDATETIMEFORMAT::nmhdr)
            .property("pszFormat", &NMDATETIMEFORMAT::pszFormat)
            .property("st", &NMDATETIMEFORMAT::st)
            .property("pszDisplay", &NMDATETIMEFORMAT::pszDisplay)
            .property("szDisplay", &NMDATETIMEFORMAT::szDisplay)
            ,
        xlb_class<NMDATETIMEFORMATQUERY>("NMDATETIMEFORMATQUERY") .constructor<>() .destructor()
            .property("nmhdr", &NMDATETIMEFORMATQUERY::nmhdr)
            .property("pszFormat", &NMDATETIMEFORMATQUERY::pszFormat)
            .property("szMax", &NMDATETIMEFORMATQUERY::szMax)
            ,
        xlb_class<NMDATETIMESTRING>("NMDATETIMESTRING") .constructor<>() .destructor()
            .property("nmhdr", &NMDATETIMESTRING::nmhdr)
            .property("pszUserString", &NMDATETIMESTRING::pszUserString)
            .property("st", &NMDATETIMESTRING::st)
            .property("dwFlags", &NMDATETIMESTRING::dwFlags)
            ,
        xlb_class<NMDATETIMEWMKEYDOWN>("NMDATETIMEWMKEYDOWN") .constructor<>() .destructor()
            .property("nmhdr", &NMDATETIMEWMKEYDOWN::nmhdr)
            .property("nVirtKey", &NMDATETIMEWMKEYDOWN::nVirtKey)
            .property("pszFormat", &NMDATETIMEWMKEYDOWN::pszFormat)
            .property("st", &NMDATETIMEWMKEYDOWN::st)
            ,
        
        // Edit Control
        xlb_class<xlb_cbf<EDITWORDBREAKPROCA>>("EDITWORDBREAKPROCA").constructor<xlb_luafunc>(),
        xlb_f("Edit_CanUndo", [](HWND hwnd)->UINT { return Edit_CanUndo(hwnd); }),
        xlb_f("Edit_EmptyUndoBuffer", [](HWND hwnd) { Edit_EmptyUndoBuffer(hwnd); }),
        xlb_f("Edit_Enable", [](HWND hwnd, BOOL fEnable) { Edit_Enable(hwnd, fEnable); }),
        xlb_f("Edit_FmtLines", [](HWND hwnd, BOOL fAddEOL) { Edit_FmtLines(hwnd, fAddEOL); }),
        xlb_f("Edit_GetCaretIndex", [](HWND hwnd) { Edit_GetCaretIndex(hwnd); }),
        xlb_f("Edit_GetCueBannerText", [](HWND hwnd, LPCWSTR lpwText, LONG cchText) { Edit_GetCueBannerText(hwnd, lpwText, cchText); }),
        xlb_f("Edit_GetEndOfLine", [](HWND hwnd)->EC_ENDOFLINE { return Edit_GetEndOfLine(hwnd); }),
        xlb_const("EC_ENDOFLINE_DETECTFROMCONTENT", EC_ENDOFLINE_DETECTFROMCONTENT),
        xlb_const("EC_ENDOFLINE_CRLF", EC_ENDOFLINE_CRLF),
        xlb_const("EC_ENDOFLINE_CR", EC_ENDOFLINE_CR),
        xlb_const("EC_ENDOFLINE_LF", EC_ENDOFLINE_LF),
        xlb_f("Edit_GetExtendedStyle", [](HWND hwnd)->DWORD { return Edit_GetExtendedStyle(hwnd); }),
        xlb_f("Edit_GetFirstVisibleLine", [](HWND hwnd)->int { return Edit_GetFirstVisibleLine(hwnd); }),
        xlb_f("Edit_GetHandle", [](HWND hwnd)->HLOCAL { return Edit_GetHandle(hwnd); }),
        xlb_f("Edit_GetHilite", [](HWND hwnd) { return Edit_GetHilite(hwnd); }), // This macro is not implemented.
        xlb_f("Edit_GetLine", [](HWND hwnd, int line, LPTSTR lpch, int cchMax) { Edit_GetLine(hwnd, line, lpch, cchMax); }),
        xlb_f("Edit_GetLineCount", [](HWND hwnd)->int { return Edit_GetLineCount(hwnd); }),
        xlb_f("Edit_GetModify", [](HWND hwnd)->BOOL { return Edit_GetModify(hwnd); }),
        xlb_f("Edit_GetPasswordChar", [](HWND hwnd)->TCHAR { return Edit_GetPasswordChar(hwnd); }),
        xlb_f("Edit_GetRect", [](HWND hwnd, RECT* lprc) { Edit_GetRect(hwnd, lprc); }),
        xlb_f("Edit_GetSel", [](HWND hwnd)->int { return Edit_GetSel(hwnd); }),
        xlb_f("Edit_GetText", [](HWND hwnd, LPTSTR lpch, int cchMax) { Edit_GetText(hwnd, lpch, cchMax); }),
        xlb_f("Edit_GetTextLength", [](HWND hwnd)->int { return Edit_GetTextLength(hwnd); }),
        xlb_f("Edit_GetWordBreakProc", [](HWND hwnd)->EDITWORDBREAKPROC { return Edit_GetWordBreakProc(hwnd); }),
        xlb_f("Edit_GetZoom", [](HWND hwnd, WPARAM numerator, LPARAM denominator)->BOOL { return Edit_GetZoom(hwnd, numerator, denominator); }),
        xlb_f("Edit_HideBalloonTip", [](HWND hwnd) { Edit_HideBalloonTip(hwnd); }),
        xlb_f("Edit_LimitText", [](HWND hwnd, int cchMax) { Edit_LimitText(hwnd, cchMax); }),
        xlb_f("Edit_LineFromChar", [](HWND hwnd, int ich)->int { return Edit_LineFromChar(hwnd, ich); }),
        xlb_f("Edit_LineIndex", [](HWND hwnd, int line)->int { return Edit_LineIndex(hwnd, line); }),
        xlb_f("Edit_LineLength", [](HWND hwnd, int line)->int { return Edit_LineLength(hwnd, line); }),
        xlb_f("Edit_NoSetFocus", [](HWND hwnd)->DWORD { return Edit_NoSetFocus(hwnd); }),
        xlb_f("Edit_ReplaceSel", [](HWND hwnd, LPCTSTR lpszReplace) { Edit_ReplaceSel(hwnd, lpszReplace); }),
        xlb_f("Edit_Scroll", [](HWND hwnd, int dv, int dh) { Edit_Scroll(hwnd, dv, dh); }),
        xlb_f("Edit_ScrollCaret", [](HWND hwnd)->BOOL { return Edit_ScrollCaret(hwnd); }),
        xlb_f("Edit_SetCaretIndex", [](HWND hwnd, int newCaretIndex)->BOOL { return Edit_SetCaretIndex(hwnd, newCaretIndex); }),
        xlb_f("Edit_SetCueBannerText", [](HWND hwnd, LPCWSTR lpcwText)->BOOL { return Edit_SetCueBannerText(hwnd, lpcwText); }),
        xlb_f("Edit_SetCueBannerTextFocused", [](HWND hwnd, LPCWSTR lpcwText, BOOL fDrawFocused)->BOOL { return Edit_SetCueBannerTextFocused(hwnd, lpcwText, fDrawFocused); }),
        xlb_f("Edit_SetEndOfLine", [](HWND hwnd, EC_ENDOFLINE eolType)->DWORD { return Edit_SetEndOfLine(hwnd, eolType); }),
        xlb_f("Edit_SetExtendedStyle", [](HWND hwnd, DWORD dw, DWORD dwMask)->DWORD { return Edit_SetExtendedStyle(hwnd, dw, dwMask); }),
        xlb_const("ES_EX_ALLOWEOL_CR", ES_EX_ALLOWEOL_CR),
        xlb_const("ES_EX_ALLOWEOL_LF", ES_EX_ALLOWEOL_LF),
        xlb_const("ES_EX_ALLOWEOL_ALL", ES_EX_ALLOWEOL_ALL),
        xlb_const("ES_EX_CONVERT_EOL_ON_PASTE", ES_EX_CONVERT_EOL_ON_PASTE),
        xlb_const("ES_EX_ZOOMABLE", ES_EX_ZOOMABLE),
        xlb_f("Edit_SetHandle", [](HWND hwnd, HLOCAL h) { Edit_SetHandle(hwnd, h); }),
        xlb_f("Edit_SetHilite", [](HWND hwnd, int ichStart, int ichEnd) { Edit_SetHilite(hwnd, ichStart, ichEnd); }),
        xlb_f("Edit_SetModify", [](HWND hwnd, BOOL fModified) { Edit_SetModify(hwnd, fModified); }),
        xlb_f("Edit_SetPasswordChar", [](HWND hwnd, UINT ch) { Edit_SetPasswordChar(hwnd, ch); }),
        xlb_f("Edit_SetReadOnly", [](HWND hwnd, BOOL fReadOnly)->BOOL { return Edit_SetReadOnly(hwnd, fReadOnly); }),
        xlb_f("Edit_SetRect", [](HWND hwnd, RECT* lprc) { Edit_SetRect(hwnd, lprc); }),
        xlb_f("Edit_SetRectNoPaint", [](HWND hwnd, RECT* lprc) { Edit_SetRectNoPaint(hwnd, lprc); }),
        xlb_f("Edit_SetSel", [](HWND hwnd, int ichStart, int ichEnd) { Edit_SetSel(hwnd, ichStart, ichEnd); }),
        xlb_f("Edit_SetTabStops", [](HWND hwnd, int cTabs, int* lpTabs) { Edit_SetTabStops(hwnd, cTabs, lpTabs); }),
        xlb_f("Edit_SetText", [](HWND hwnd, LPTSTR lpsz)->BOOL { return Edit_SetText(hwnd, lpsz); }),
        xlb_f("Edit_SetWordBreakProc", [](HWND hwnd, EDITWORDBREAKPROC lpfnWordBreak) { Edit_SetWordBreakProc(hwnd, lpfnWordBreak); }),
        xlb_f("Edit_SetZoom", [](HWND hwnd, WPARAM numerator, LPARAM denominator)->BOOL { return Edit_SetZoom(hwnd, numerator, denominator); }),
        xlb_f("Edit_ShowBalloonTip", [](HWND hwnd, PEDITBALLOONTIP peditballoontip)->BOOL { return Edit_ShowBalloonTip(hwnd, peditballoontip); }),
        xlb_f("Edit_TakeFocus", [](HWND hwnd)->DWORD { return Edit_TakeFocus(hwnd); }),
        xlb_f("Edit_Undo", [](HWND hwnd)->BOOL { return Edit_Undo(hwnd); }),
        // Messages
        xlb_const("EM_CANUNDO", EM_CANUNDO),
        xlb_const("EM_CHARFROMPOS", EM_CHARFROMPOS),
        xlb_const("EM_EMPTYUNDOBUFFER", EM_EMPTYUNDOBUFFER),
        xlb_const("EM_FMTLINES", EM_FMTLINES),
        xlb_const("EM_GETCARETINDEX", EM_GETCARETINDEX),
        xlb_const("EM_GETCUEBANNER", EM_GETCUEBANNER),
        xlb_const("EM_GETENDOFLINE", EM_GETENDOFLINE),
        xlb_const("EM_GETEXTENDEDSTYLE", EM_GETEXTENDEDSTYLE),
        xlb_const("EM_GETFIRSTVISIBLELINE", EM_GETFIRSTVISIBLELINE),
        xlb_const("EM_GETHANDLE", EM_GETHANDLE),
        xlb_const("EM_GETHILITE", EM_GETHILITE),
        xlb_const("EM_GETIMESTATUS", EM_GETIMESTATUS),
        xlb_const("EM_GETLIMITTEXT", EM_GETLIMITTEXT),
        xlb_const("EM_GETLINE", EM_GETLINE),
        xlb_const("EM_GETLINECOUNT", EM_GETLINECOUNT),
        xlb_const("EM_GETMARGINS", EM_GETMARGINS),
        xlb_const("EM_GETMODIFY", EM_GETMODIFY),
        xlb_const("EM_GETPASSWORDCHAR", EM_GETPASSWORDCHAR),
        xlb_const("EM_GETRECT", EM_GETRECT),
        xlb_const("EM_GETSEL", EM_GETSEL),
        xlb_const("EM_GETTHUMB", EM_GETTHUMB),
        xlb_const("EM_GETWORDBREAKPROC", EM_GETWORDBREAKPROC),
        xlb_const("EM_GETZOOM", EM_GETZOOM),
        xlb_const("EM_HIDEBALLOONTIP", EM_HIDEBALLOONTIP),
        xlb_const("EM_LIMITTEXT", EM_LIMITTEXT),
        xlb_const("EM_LINEFROMCHAR", EM_LINEFROMCHAR),
        xlb_const("EM_LINEINDEX", EM_LINEINDEX),
        xlb_const("EM_LINELENGTH", EM_LINELENGTH),
        xlb_const("EM_LINESCROLL", EM_LINESCROLL),
        xlb_const("EM_NOSETFOCUS", EM_NOSETFOCUS),
        xlb_const("EM_POSFROMCHAR", EM_POSFROMCHAR),
        xlb_const("EM_REPLACESEL", EM_REPLACESEL),
        xlb_const("EM_SCROLL", EM_SCROLL),
        xlb_const("EM_SCROLLCARET", EM_SCROLLCARET),
        xlb_const("EM_SETCARETINDEX", EM_SETCARETINDEX),
        xlb_const("EM_SETCUEBANNER", EM_SETCUEBANNER),
        xlb_const("EM_SETENDOFLINE", EM_SETENDOFLINE),
        xlb_const("EM_SETEXTENDEDSTYLE", EM_SETEXTENDEDSTYLE),
        xlb_const("EM_SETHANDLE", EM_SETHANDLE),
        xlb_const("EM_SETHILITE", EM_SETHILITE),
        xlb_const("EM_SETIMESTATUS", EM_SETIMESTATUS),
        xlb_const("EM_SETLIMITTEXT", EM_SETLIMITTEXT),
        xlb_const("EM_SETMARGINS", EM_SETMARGINS),
        xlb_const("EM_SETMODIFY", EM_SETMODIFY),
        xlb_const("EM_SETPASSWORDCHAR", EM_SETPASSWORDCHAR),
        xlb_const("EM_SETREADONLY", EM_SETREADONLY),
        xlb_const("EM_SETRECT", EM_SETRECT),
        xlb_const("EM_SETRECTNP", EM_SETRECTNP),
        xlb_const("EM_SETSEL", EM_SETSEL),
        xlb_const("EM_SETTABSTOPS", EM_SETTABSTOPS),
        xlb_const("EM_SETWORDBREAKPROC", EM_SETWORDBREAKPROC),
        xlb_const("EM_SETZOOM", EM_SETZOOM),
        xlb_const("EM_SHOWBALLOONTIP", EM_SHOWBALLOONTIP),
        xlb_const("EM_TAKEFOCUS", EM_TAKEFOCUS),
        xlb_const("EM_UNDO", EM_UNDO),
        xlb_const("WM_UNDO", WM_UNDO),
        // Notifications
        xlb_const("EN_ALIGN_LTR_EC", EN_ALIGN_LTR_EC),
        xlb_const("EN_ALIGN_RTL_EC", EN_ALIGN_RTL_EC),
        xlb_const("EN_CHANGE", EN_CHANGE),
        xlb_const("EN_ERRSPACE", EN_ERRSPACE),
        xlb_const("EN_HSCROLL", EN_HSCROLL),
        xlb_const("EN_KILLFOCUS", EN_KILLFOCUS),
        xlb_const("EN_MAXTEXT", EN_MAXTEXT),
        xlb_const("EN_SETFOCUS", EN_SETFOCUS),
        xlb_const("EN_UPDATE", EN_UPDATE),
        xlb_const("EN_VSCROLL", EN_VSCROLL),
        xlb_const("WM_CTLCOLOREDIT", WM_CTLCOLOREDIT),
        // Styles
        xlb_const("ES_AUTOHSCROLL", ES_AUTOHSCROLL),
        xlb_const("ES_AUTOVSCROLL", ES_AUTOVSCROLL),
        xlb_const("ES_CENTER", ES_CENTER),
        xlb_const("ES_LEFT", (uint32_t)ES_LEFT),
        xlb_const("ES_LOWERCASE", ES_LOWERCASE),
        xlb_const("ES_MULTILINE", ES_MULTILINE),
        xlb_const("ES_NOHIDESEL", ES_NOHIDESEL),
        xlb_const("ES_NUMBER", ES_NUMBER),
        xlb_const("ES_OEMCONVERT", ES_OEMCONVERT),
        xlb_const("ES_PASSWORD", ES_PASSWORD),
        xlb_const("ES_READONLY", ES_READONLY),
        xlb_const("ES_RIGHT", ES_RIGHT),
        xlb_const("ES_UPPERCASE", ES_UPPERCASE),
        xlb_const("ES_WANTRETURN", ES_WANTRETURN),
        // Flat Scroll Bar
        xlb_const("SB_BOTH", SB_BOTH),
        xlb_const("SB_HORZ", (uint32_t)SB_HORZ),
        xlb_const("SB_VERT", SB_VERT),
        xlb_const("ESB_DISABLE_BOTH", ESB_DISABLE_BOTH),
        xlb_const("ESB_DISABLE_DOWN", ESB_DISABLE_DOWN),
        xlb_const("ESB_DISABLE_LEFT", ESB_DISABLE_LEFT),
        xlb_const("ESB_DISABLE_LTUP", ESB_DISABLE_LTUP),
        xlb_const("ESB_DISABLE_RIGHT", ESB_DISABLE_RIGHT),
        xlb_const("ESB_DISABLE_RTDN", ESB_DISABLE_RTDN),
        xlb_const("ESB_DISABLE_UP", ESB_DISABLE_UP),
        xlb_const("ESB_ENABLE_BOTH", (uint32_t)ESB_ENABLE_BOTH),
        xlb_f("FlatSB_EnableScrollBar", FlatSB_EnableScrollBar),
        xlb_f("FlatSB_GetScrollInfo", FlatSB_GetScrollInfo),
        xlb_f("FlatSB_GetScrollPos", FlatSB_GetScrollPos),
        xlb_f("FlatSB_GetScrollProp", FlatSB_GetScrollProp),
        //xlb_f("FlatSB_GetScrollPropPtr", FlatSB_GetScrollPropPtr), // higher 6.0 do not support
        xlb_f("FlatSB_GetScrollRange", FlatSB_GetScrollRange),
        xlb_f("FlatSB_SetScrollInfo", FlatSB_SetScrollInfo),
        xlb_f("FlatSB_SetScrollPos", FlatSB_SetScrollPos),
        xlb_f("FlatSB_SetScrollProp", FlatSB_SetScrollProp),
        xlb_f("FlatSB_SetScrollRange", FlatSB_SetScrollRange),
        xlb_f("FlatSB_ShowScrollBar", FlatSB_ShowScrollBar),
        xlb_f("InitializeFlatSB", InitializeFlatSB),
        xlb_f("UninitializeFlatSB", UninitializeFlatSB),
        xlb_const("WSB_PROP_CXHSCROLL", WSB_PROP_CXHSCROLL),
        xlb_const("WSB_PROP_CXHTHUMB", WSB_PROP_CXHTHUMB),
        xlb_const("WSB_PROP_CXVSCROLL", WSB_PROP_CXVSCROLL),
        xlb_const("WSB_PROP_CYHSCROLL", WSB_PROP_CYHSCROLL),
        xlb_const("WSB_PROP_CYVSCROLL", WSB_PROP_CYVSCROLL),
        xlb_const("WSB_PROP_CYVTHUMB", WSB_PROP_CYVTHUMB),
        xlb_const("WSB_PROP_HBKGCOLOR", WSB_PROP_HBKGCOLOR),
        xlb_const("WSB_PROP_HSTYLE", WSB_PROP_HSTYLE),
        xlb_const("WSB_PROP_PALETTE", WSB_PROP_PALETTE),
        xlb_const("WSB_PROP_VBKGCOLOR", WSB_PROP_VBKGCOLOR),
        xlb_const("WSB_PROP_VSTYLE", WSB_PROP_VSTYLE),
        xlb_const("WSB_PROP_WINSTYLE", WSB_PROP_WINSTYLE),
        
        // Header Control
        xlb_f("Header_ClearAllFilters", [](HWND hwnd)->int { return Header_ClearAllFilters(hwnd); }),
        xlb_f("Header_ClearFilter", [](HWND hwnd, int i)->int { return Header_ClearFilter(hwnd, i); }),
        xlb_f("Header_CreateDragImage", [](HWND hwnd, int i)->HIMAGELIST { return Header_CreateDragImage(hwnd, i); }),
        xlb_f("Header_DeleteItem", [](HWND hwnd, int index)->BOOL { return Header_DeleteItem(hwnd, index); }),
        xlb_f("Header_EditFilter", [](HWND hwnd, int i, BOOL fDiscardChanges)->BOOL { return Header_EditFilter(hwnd, i, fDiscardChanges); }),
        xlb_f("Header_GetBitmapMargin", [](HWND hwnd)->int { return Header_GetBitmapMargin(hwnd); }),
        xlb_f("Header_GetImageList", [](HWND hwnd)->HIMAGELIST { return Header_GetImageList(hwnd); }),
        xlb_f("Header_GetItem", [](HWND hwnd, int i, LPHDITEM phdi)->BOOL { return Header_GetItem(hwnd, i, phdi); }),
        xlb_f("Header_GetItemCount", [](HWND hwnd)->int { return Header_GetItemCount(hwnd); }),
        xlb_f("Header_GetItemDropDownRect", [](HWND hwnd, int iItem, LPRECT lprc)->BOOL { return Header_GetItemDropDownRect(hwnd, iItem, lprc); }),
        xlb_f("Header_GetOrderArray", [](HWND hwnd, int iCount, int* lpi)->BOOL { return Header_GetOrderArray(hwnd, iCount, lpi); }),
        xlb_f("Header_GetOverflowRect", [](HWND hwnd, LPRECT lprc)->BOOL { return Header_GetOverflowRect(hwnd, lprc); }),
        xlb_f("Header_GetStateImageList", [](HWND hwnd)->HIMAGELIST { return Header_GetStateImageList(hwnd); }),
        xlb_f("Header_GetUnicodeFormat", [](HWND hwnd)->BOOL { return Header_GetUnicodeFormat(hwnd); }),
        xlb_f("Header_InsertItem", [](HWND hwnd, int i, LPHDITEM phdi)->int { return Header_InsertItem(hwnd, i, phdi); }),
        xlb_f("Header_Layout", [](HWND hwnd, int i, LPHDLAYOUT playout)->BOOL { return Header_Layout(hwnd, playout); }),
        xlb_f("Header_OrderToIndex", [](HWND hwnd, int i)->int { return Header_OrderToIndex(hwnd, i); }),
        xlb_f("Header_SetBitmapMargin", [](HWND hwnd, int iWidth)->int { return Header_SetBitmapMargin(hwnd, iWidth); }),
        xlb_f("Header_SetFilterChangeTimeout", [](HWND hwnd, int i)->int { return Header_SetFilterChangeTimeout(hwnd, i); }),
        xlb_f("Header_SetFocusedItem", [](HWND hwnd, int iItem)->BOOL { return Header_SetFocusedItem(hwnd, iItem); }),
        xlb_f("Header_SetHotDivider", [](HWND hwnd, BOOL fPos, DWORD dw)->int { return Header_SetHotDivider(hwnd, fPos, dw); }),
        xlb_f("Header_SetImageList", [](HWND hwnd, BOOL fPos, HIMAGELIST himl)->HIMAGELIST { return Header_SetImageList(hwnd, himl); }),
        xlb_f("Header_SetItem", [](HWND hwnd, int i, LPHDITEM phdi)->BOOL { return Header_SetItem(hwnd, i, phdi); }),
        xlb_f("Header_SetOrderArray", [](HWND hwnd, int iCount, int* lpi)->BOOL { return Header_SetOrderArray(hwnd, iCount, lpi); }),
        xlb_f("Header_SetStateImageList", [](HWND hwnd, HIMAGELIST himl)->HIMAGELIST { return Header_SetStateImageList(hwnd, himl); }),
        xlb_f("Header_SetUnicodeFormat", [](HWND hwnd, BOOL fUnicode)->BOOL { return Header_SetUnicodeFormat(hwnd, fUnicode); }),
        // Messages
        xlb_const("HDM_CLEARFILTER", HDM_CLEARFILTER),
        xlb_const("HDM_CREATEDRAGIMAGE", HDM_CREATEDRAGIMAGE),
        xlb_const("HDM_DELETEITEM", HDM_DELETEITEM),
        xlb_const("HDM_EDITFILTER", HDM_EDITFILTER),
        xlb_const("HDM_GETBITMAPMARGIN", HDM_GETBITMAPMARGIN),
        xlb_const("HDM_GETFOCUSEDITEM", HDM_GETFOCUSEDITEM),
        xlb_const("HDM_GETIMAGELIST", HDM_GETIMAGELIST),
        xlb_const("HDM_GETITEM", HDM_GETITEM),
        xlb_const("HDM_GETITEMCOUNT", HDM_GETITEMCOUNT),
        xlb_const("HDM_GETITEMDROPDOWNRECT", HDM_GETITEMDROPDOWNRECT),
        xlb_const("HDM_GETITEMRECT", HDM_GETITEMRECT),
        xlb_const("HDM_GETORDERARRAY", HDM_GETORDERARRAY),
        xlb_const("HDM_GETOVERFLOWRECT", HDM_GETOVERFLOWRECT),
        xlb_const("HDM_GETUNICODEFORMAT", HDM_GETUNICODEFORMAT),
        xlb_const("HDM_HITTEST", HDM_HITTEST),
        xlb_const("HDM_INSERTITEM", HDM_INSERTITEM),
        xlb_const("HDM_LAYOUT", HDM_LAYOUT),
        xlb_const("HDM_ORDERTOINDEX", HDM_ORDERTOINDEX),
        xlb_const("HDM_SETBITMAPMARGIN", HDM_SETBITMAPMARGIN),
        xlb_const("HDM_SETFILTERCHANGETIMEOUT", HDM_SETFILTERCHANGETIMEOUT),
        xlb_const("HDM_SETFOCUSEDITEM", HDM_SETFOCUSEDITEM),
        xlb_const("HDM_SETHOTDIVIDER", HDM_SETHOTDIVIDER),
        xlb_const("HDM_SETIMAGELIST", HDM_SETIMAGELIST),
        xlb_const("HDM_SETITEM", HDM_SETITEM),
        xlb_const("HDM_SETORDERARRAY", HDM_SETORDERARRAY),
        xlb_const("HDM_SETUNICODEFORMAT", HDM_SETUNICODEFORMAT),
        //xlb_const("HDM_TRANSLATEACCELERATOR", HDM_TRANSLATEACCELERATOR), // not implemented
        // Notifications
        xlb_const("HDN_BEGINDRAG", HDN_BEGINDRAG),
        xlb_const("HDN_BEGINFILTEREDIT", HDN_BEGINFILTEREDIT),
        xlb_const("HDN_BEGINTRACK", HDN_BEGINTRACK),
        xlb_const("HDN_DIVIDERDBLCLICK", HDN_DIVIDERDBLCLICK),
        xlb_const("HDN_DROPDOWN", HDN_DROPDOWN),
        xlb_const("HDN_ENDDRAG", HDN_ENDDRAG),
        xlb_const("HDN_ENDFILTEREDIT", HDN_ENDFILTEREDIT),
        xlb_const("HDN_ENDTRACK", HDN_ENDTRACK),
        xlb_const("HDN_FILTERBTNCLICK", HDN_FILTERBTNCLICK),
        xlb_const("HDN_FILTERCHANGE", HDN_FILTERCHANGE),
        xlb_const("HDN_GETDISPINFO", HDN_GETDISPINFO),
        xlb_const("HDN_ITEMCHANGED", HDN_ITEMCHANGED),
        xlb_const("HDN_ITEMCHANGING", HDN_ITEMCHANGING),
        xlb_const("HDN_ITEMCLICK", HDN_ITEMCLICK),
        xlb_const("HDN_ITEMDBLCLICK", HDN_ITEMDBLCLICK),
        xlb_const("HDN_ITEMKEYDOWN", HDN_ITEMKEYDOWN),
        xlb_const("HDN_ITEMSTATEICONCLICK", HDN_ITEMSTATEICONCLICK),
        xlb_const("HDN_OVERFLOWCLICK", HDN_OVERFLOWCLICK),
        xlb_const("HDN_TRACK", HDN_TRACK),
        xlb_const("NM_CUSTOMDRAW", NM_CUSTOMDRAW),
        xlb_const("NM_RCLICK", NM_RCLICK),
        xlb_const("NM_RELEASEDCAPTURE", NM_RELEASEDCAPTURE),
        // Styles
        xlb_const("HDS_BUTTONS", HDS_BUTTONS),
        xlb_const("HDS_DRAGDROP", HDS_DRAGDROP),
        xlb_const("HDS_FILTERBAR", HDS_FILTERBAR),
        xlb_const("HDS_FLAT", HDS_FLAT),
        xlb_const("HDS_FULLDRAG", HDS_FULLDRAG),
        xlb_const("HDS_HIDDEN", HDS_HIDDEN),
        xlb_const("HDS_HORZ", (uint32_t)HDS_HORZ),
        xlb_const("HDS_HOTTRACK", HDS_HOTTRACK),
        xlb_const("HDS_CHECKBOXES", HDS_CHECKBOXES),
        xlb_const("HDS_NOSIZING", HDS_NOSIZING),
        xlb_const("HDS_OVERFLOW", HDS_OVERFLOW),

        // Hot Key
        xlb_const("HKM_GETHOTKEY", HKM_GETHOTKEY),
        xlb_const("HKM_SETHOTKEY", HKM_SETHOTKEY),
        xlb_const("HKM_SETRULES", HKM_SETRULES),

        // Image Lists
        //xlb_f("HIMAGELIST_QueryInterface", HIMAGELIST_QueryInterface),
        xlb_f("ImageList_Add", ImageList_Add),
        xlb_f("ImageList_AddMasked", ImageList_AddMasked),
        xlb_f("ImageList_BeginDrag", ImageList_BeginDrag),
        //xlb_f("ImageList_CoCreateInstance", ImageList_CoCreateInstance),
        xlb_f("ImageList_Copy", ImageList_Copy),
        xlb_f("ImageList_Create", ImageList_Create),
        xlb_f("ImageList_Destroy", ImageList_Destroy),
        xlb_f("ImageList_DragEnter", ImageList_DragEnter),
        xlb_f("ImageList_DragLeave", ImageList_DragLeave),
        xlb_f("ImageList_DragMove", ImageList_DragMove),
        xlb_f("ImageList_DragShowNolock", ImageList_DragShowNolock),
        xlb_f("ImageList_Draw", ImageList_Draw),
        xlb_f("ImageList_DrawEx", ImageList_DrawEx),
        xlb_f("ImageList_DrawIndirect", ImageList_DrawIndirect),
        xlb_f("ImageList_Duplicate", ImageList_Duplicate),
        xlb_f("ImageList_EndDrag", ImageList_EndDrag),
        xlb_f("ImageList_GetBkColor", ImageList_GetBkColor),
        xlb_f("ImageList_GetDragImage", ImageList_GetDragImage),
        xlb_f("ImageList_GetIcon", ImageList_GetIcon),
        xlb_f("ImageList_GetIconSize", ImageList_GetIconSize),
        xlb_f("ImageList_GetImageCount", ImageList_GetImageCount),
        xlb_f("ImageList_GetImageInfo", ImageList_GetImageInfo),
        xlb_f("ImageList_LoadImage", ImageList_LoadImage),
        xlb_f("ImageList_Merge", ImageList_Merge),
        xlb_f("ImageList_Read", ImageList_Read),
        //xlb_f("ImageList_ReadEx", ImageList_ReadEx), // FIXME: can not find entry
        xlb_f("ImageList_Remove", ImageList_Remove),
        xlb_f("ImageList_Replace", ImageList_Replace),
        xlb_f("ImageList_ReplaceIcon", ImageList_ReplaceIcon),
        xlb_f("ImageList_SetBkColor", ImageList_SetBkColor),
        //xlb_f("ImageList_SetColorTable", ImageList_SetColorTable), // FIXME: undeclared identifier
        xlb_f("ImageList_SetDragCursorImage", ImageList_SetDragCursorImage),
        xlb_f("ImageList_SetIconSize", ImageList_SetIconSize),
        xlb_f("ImageList_SetImageCount", ImageList_SetImageCount),
        xlb_f("ImageList_SetOverlayImage", ImageList_SetOverlayImage),
        xlb_f("ImageList_Write", ImageList_Write),
        //xlb_f("ImageList_WriteEx", ImageList_WriteEx), // FIXME: crash, do not exists in COMCTL32.dll
        xlb_const("ILP_NORMAL", (uint32_t)ILP_NORMAL),
        xlb_const("ILP_DOWNLEVEL", ILP_DOWNLEVEL),
        //Macro
        xlb_f("ImageList_AddIcon", [](HIMAGELIST himl, HICON hicon) 
                { ImageList_AddIcon(himl, hicon); }),
        xlb_f("ImageList_ExtractIcon", [](HINSTANCE h, HIMAGELIST himl, int i)->HICON 
                { return ImageList_ExtractIcon(h, himl, i); }),
        xlb_f("ImageList_LoadBitmap", [](HINSTANCE h, LPCTSTR lpbmp, int cx, int cGrow, COLORREF crMask)->HIMAGELIST 
                { return ImageList_LoadBitmap(h, lpbmp, cx, cGrow, crMask); }),
        xlb_f("ImageList_RemoveAll", [](HIMAGELIST himl) -> BOOL
                { return ImageList_RemoveAll(himl); }),
        xlb_f("INDEXTOOVERLAYMASK", [](int i) -> int { return INDEXTOOVERLAYMASK(i); }),

        // Interface
        xlb_class<IImageList>("IImageList")
            .method("Add", &IImageList::Add)
            .method("AddMasked", &IImageList::AddMasked)
            .method("BeginDrag", &IImageList::BeginDrag)
            .method("Clone", &IImageList::Clone)
            .method("Copy", &IImageList::Copy)
            .method("DragEnter", &IImageList::DragEnter)
            .method("DragLeave", &IImageList::DragLeave)
            .method("DragMove", &IImageList::DragMove)
            .method("DragShowNolock", &IImageList::DragShowNolock)
            .method("Draw", &IImageList::Draw)
            .method("EndDrag", &IImageList::EndDrag)
            .method("GetBkColor", &IImageList::GetBkColor)
            .method("GetDragImage", &IImageList::GetDragImage)
            .method("GetIcon", &IImageList::GetIcon)
            .method("GetIconSize", &IImageList::GetIconSize)
            .method("GetImageCount", &IImageList::GetImageCount)
            .method("GetImageInfo", &IImageList::GetImageInfo)
            .method("GetImageRect", &IImageList::GetImageRect)
            .method("GetItemFlags", &IImageList::GetItemFlags)
            .method("GetOverlayImage", &IImageList::GetOverlayImage)
            .method("Merge", &IImageList::Merge)
            .method("Remove", &IImageList::Remove)
            .method("Replace", &IImageList::Replace)
            .method("ReplaceIcon", &IImageList::ReplaceIcon)
            .method("SetBkColor", &IImageList::SetBkColor)
            .method("SetDragCursorImage", &IImageList::SetDragCursorImage)
            .method("SetIconSize", &IImageList::SetIconSize)
            .method("SetImageCount", &IImageList::SetImageCount)
            .method("SetOverlayImage", &IImageList::SetOverlayImage)
            ,

    xlb_class<IMAGEINFO>("IMAGEINFO") .constructor<>() .destructor()
        .property("hbmImage", &IMAGEINFO::hbmImage)
        .property("hbmMask", &IMAGEINFO::hbmMask)
        .property("Unused1", &IMAGEINFO::Unused1)
        .property("Unused2", &IMAGEINFO::Unused2)
        .property("rcImage", &IMAGEINFO::rcImage)
        ,
    xlb_class<IMAGELISTDRAWPARAMS>("IMAGELISTDRAWPARAMS") .constructor<>() .destructor()
        .property("cbSize", &IMAGELISTDRAWPARAMS::cbSize)
        .property("himl", &IMAGELISTDRAWPARAMS::himl)
        .property("i", &IMAGELISTDRAWPARAMS::i)
        .property("hdcDst", &IMAGELISTDRAWPARAMS::hdcDst)
        .property("x", &IMAGELISTDRAWPARAMS::x)
        .property("y", &IMAGELISTDRAWPARAMS::y)
        .property("cx", &IMAGELISTDRAWPARAMS::cx)
        .property("cy", &IMAGELISTDRAWPARAMS::cy)
        .property("xBitmap", &IMAGELISTDRAWPARAMS::xBitmap)
        .property("yBitmap", &IMAGELISTDRAWPARAMS::yBitmap)
        .property("rgbBk", &IMAGELISTDRAWPARAMS::rgbBk)
        .property("rgbFg", &IMAGELISTDRAWPARAMS::rgbFg)
        .property("fStyle", &IMAGELISTDRAWPARAMS::fStyle)
        .property("dwRop", &IMAGELISTDRAWPARAMS::dwRop)
        .property("fState", &IMAGELISTDRAWPARAMS::fState)
        .property("Frame", &IMAGELISTDRAWPARAMS::Frame)
        .property("crEffect", &IMAGELISTDRAWPARAMS::crEffect)
        ,

    // IP Address Controls
        xlb_f("FIRST_IPADDRESS", [](LPARAM x) -> auto { return FIRST_IPADDRESS(x); }),
        xlb_f("SECOND_IPADDRESS", [](LPARAM x) -> auto { return SECOND_IPADDRESS(x); }),
        xlb_f("THIRD_IPADDRESS", [](LPARAM x) -> auto { return THIRD_IPADDRESS(x); }),
        xlb_f("FOURTH_IPADDRESS", [](LPARAM x) -> auto { return FOURTH_IPADDRESS(x); }),
        xlb_f("MAKEIPADDRESS", [](BYTE b1, BYTE b2, BYTE b3, BYTE b4) -> auto { return MAKEIPADDRESS(b1,b2,b3,b4); }),
        xlb_f("MAKEIPRANGE", [](BYTE low, BYTE high) -> auto { return MAKEIPRANGE(low, high); }),

    // Messages
        xlb_const("BCM_GETIDEALSIZE", BCM_GETIDEALSIZE),
        xlb_const("IPM_CLEARADDRESS", IPM_CLEARADDRESS),
        xlb_const("IPM_GETADDRESS", IPM_GETADDRESS),
        xlb_const("IPM_ISBLANK", IPM_ISBLANK),
        xlb_const("IPM_SETADDRESS", IPM_SETADDRESS),
        xlb_const("IPM_SETFOCUS", IPM_SETFOCUS),
        xlb_const("IPM_SETRANGE", IPM_SETRANGE),
        xlb_const("IPN_FIELDCHANGED", IPN_FIELDCHANGED),

    // Structures
    xlb_class<NMIPADDRESS>("NMIPADDRESS") .constructor<>() .destructor()
        .property("hdr", &NMIPADDRESS::hdr)
        .property("iField", &NMIPADDRESS::iField)
        .property("iValue", &NMIPADDRESS::iValue)
        ,

    // ListBox
        xlb_f("DlgDirList", DlgDirList),
        xlb_f("DlgDirSelectEx", DlgDirSelectEx),
        xlb_f("DrawInsert", DrawInsert),
        xlb_f("GetListBoxInfo", GetListBoxInfo),
        xlb_f("LBItemFromPt", LBItemFromPt),
        xlb_f("MakeDragList", MakeDragList),

        xlb_const("LB_ADDFILE", LB_ADDFILE),
        xlb_const("LB_ADDSTRING", LB_ADDSTRING),
        xlb_const("LB_DELETESTRING", LB_DELETESTRING),
        xlb_const("LB_DIR", LB_DIR),
        xlb_const("LB_FINDSTRING", LB_FINDSTRING),
        xlb_const("LB_FINDSTRINGEXACT", LB_FINDSTRINGEXACT),
        xlb_const("LB_GETANCHORINDEX", LB_GETANCHORINDEX),
        xlb_const("LB_GETCARETINDEX", LB_GETCARETINDEX),
        xlb_const("LB_GETCOUNT", LB_GETCOUNT),
        xlb_const("LB_GETCURSEL", LB_GETCURSEL),
        xlb_const("LB_GETHORIZONTALEXTENT", LB_GETHORIZONTALEXTENT),
        xlb_const("LB_GETITEMDATA", LB_GETITEMDATA),
        xlb_const("LB_GETITEMHEIGHT", LB_GETITEMHEIGHT),
        xlb_const("LB_GETITEMRECT", LB_GETITEMRECT),
        xlb_const("LB_GETLISTBOXINFO", LB_GETLISTBOXINFO),
        xlb_const("LB_GETLOCALE", LB_GETLOCALE),
        xlb_const("LB_GETSEL", LB_GETSEL),
        xlb_const("LB_GETSELCOUNT", LB_GETSELCOUNT),
        xlb_const("LB_GETSELITEMS", LB_GETSELITEMS),
        xlb_const("LB_GETTEXT", LB_GETTEXT),
        xlb_const("LB_GETTEXTLEN", LB_GETTEXTLEN),
        xlb_const("LB_GETTOPINDEX", LB_GETTOPINDEX),
        xlb_const("LB_INITSTORAGE", LB_INITSTORAGE),
        xlb_const("LB_INSERTSTRING", LB_INSERTSTRING),
        xlb_const("LB_ITEMFROMPOINT", LB_ITEMFROMPOINT),
        xlb_const("LB_RESETCONTENT", LB_RESETCONTENT),
        xlb_const("LB_SELECTSTRING", LB_SELECTSTRING),
        xlb_const("LB_SELITEMRANGE", LB_SELITEMRANGE),
        xlb_const("LB_SELITEMRANGEEX", LB_SELITEMRANGEEX),
        xlb_const("LB_SETANCHORINDEX", LB_SETANCHORINDEX),
        xlb_const("LB_SETCARETINDEX", LB_SETCARETINDEX),
        xlb_const("LB_SETCOLUMNWIDTH", LB_SETCOLUMNWIDTH),
        xlb_const("LB_SETCOUNT", LB_SETCOUNT),
        xlb_const("LB_SETCURSEL", LB_SETCURSEL),
        xlb_const("LB_SETHORIZONTALEXTENT", LB_SETHORIZONTALEXTENT),
        xlb_const("LB_SETITEMDATA", LB_SETITEMDATA),
        xlb_const("LB_SETITEMHEIGHT", LB_SETITEMHEIGHT),
        xlb_const("LB_SETLOCALE", LB_SETLOCALE),
        xlb_const("LB_SETSEL", LB_SETSEL),
        xlb_const("LB_SETTABSTOPS", LB_SETTABSTOPS),
        xlb_const("LB_SETTOPINDEX", LB_SETTOPINDEX),
        xlb_const("LBN_DBLCLK", LBN_DBLCLK),
        xlb_const("LBN_ERRSPACE", LBN_ERRSPACE),
        xlb_const("LBN_KILLFOCUS", LBN_KILLFOCUS),
        xlb_const("LBN_SELCANCEL", LBN_SELCANCEL),
        xlb_const("LBN_SELCHANGE", LBN_SELCHANGE),
        xlb_const("LBN_SETFOCUS", LBN_SETFOCUS),
        xlb_const("WM_CHARTOITEM", WM_CHARTOITEM),
        xlb_const("WM_CTLCOLORLISTBOX", WM_CTLCOLORLISTBOX),
        xlb_const("WM_DELETEITEM", WM_DELETEITEM),
        xlb_const("WM_VKEYTOITEM", WM_VKEYTOITEM),
        xlb_const("DL_BEGINDRAG", DL_BEGINDRAG),
        xlb_const("DL_CANCELDRAG", DL_CANCELDRAG),
        xlb_const("DL_DRAGGING", DL_DRAGGING),
        xlb_const("DL_DROPPED", DL_DROPPED),
   
   xlb_class<DELETEITEMSTRUCT>("DELETEITEMSTRUCT") .constructor<>() .destructor()
        .property("CtlType", &DELETEITEMSTRUCT::CtlType)
        .property("CtlID", &DELETEITEMSTRUCT::CtlID)
        .property("itemID", &DELETEITEMSTRUCT::itemID)
        .property("hwndItem", &DELETEITEMSTRUCT::hwndItem)
        .property("itemData", &DELETEITEMSTRUCT::itemData)
        ,

        xlb_const("ODT_LISTBOX", ODT_LISTBOX),
        xlb_const("ODT_COMBOBOX", ODT_COMBOBOX),

    
    xlb_class<DRAGLISTINFO>("DRAGLISTINFO") .constructor<>() .destructor()
        .property("uNotification", &DRAGLISTINFO::uNotification)
        .property("hWnd", &DRAGLISTINFO::hWnd)
        .property("ptCursor", &DRAGLISTINFO::ptCursor)
        ,

        xlb_const("LBS_COMBOBOX", LBS_COMBOBOX),
        xlb_const("LBS_DISABLENOSCROLL", LBS_DISABLENOSCROLL),
        xlb_const("LBS_EXTENDEDSEL", LBS_EXTENDEDSEL),
        xlb_const("LBS_HASSTRINGS", LBS_HASSTRINGS),
        xlb_const("LBS_MULTICOLUMN", LBS_MULTICOLUMN),
        xlb_const("LBS_MULTIPLESEL", LBS_MULTIPLESEL),
        xlb_const("LBS_NODATA", LBS_NODATA),
        xlb_const("LBS_NOINTEGRALHEIGHT", LBS_NOINTEGRALHEIGHT),
        xlb_const("LBS_NOREDRAW", LBS_NOREDRAW),
        xlb_const("LBS_NOSEL", LBS_NOSEL),
        xlb_const("LBS_NOTIFY", LBS_NOTIFY),
        xlb_const("LBS_OWNERDRAWFIXED", LBS_OWNERDRAWFIXED),
        xlb_const("LBS_OWNERDRAWVARIABLE", LBS_OWNERDRAWVARIABLE),
        xlb_const("LBS_SORT", LBS_SORT),
        xlb_const("LBS_STANDARD", LBS_STANDARD),
        xlb_const("LBS_USETABSTOPS", LBS_USETABSTOPS),
        xlb_const("LBS_WANTKEYBOARDINPUT", LBS_WANTKEYBOARDINPUT),

    // List view
        xlb_f("ListView_ApproximateViewRect", [](HWND hwnd, int iWidth, int iHeight, int iCount)->auto { return ListView_ApproximateViewRect(hwnd, iWidth, iHeight, iCount); }),
        xlb_f("ListView_Arrange", [](HWND hwnd, UINT code)->auto { return ListView_Arrange(hwnd, code); }),
        xlb_f("ListView_CancelEditLabel", [](HWND hwnd)->auto { return ListView_CancelEditLabel(hwnd); }),
        xlb_f("ListView_CreateDragImage", [](HWND hwnd, int i, LPPOINT lpptUpLeft)->auto { return ListView_CreateDragImage(hwnd, i, lpptUpLeft); }),
        xlb_f("ListView_DeleteAllItems", [](HWND hwnd)->auto { return ListView_DeleteAllItems(hwnd); }),
        xlb_f("ListView_DeleteColumn", [](HWND hwnd, int iCol)->auto { return ListView_DeleteColumn(hwnd, iCol); }),
        xlb_f("ListView_DeleteItem", [](HWND hwnd, int i)->auto { return ListView_DeleteItem(hwnd, i); }),
        xlb_f("ListView_EditLabel", [](HWND hwnd, int i)->auto { return ListView_EditLabel(hwnd, i); }),
        xlb_f("ListView_EnableGroupView", [](HWND hwnd, BOOL fEnable)->auto { return ListView_EnableGroupView(hwnd, fEnable); }),
        xlb_f("ListView_EnsureVisible", [](HWND hwnd, int i, BOOL fParitalOK)->auto { return ListView_EnsureVisible(hwnd, i, fParitalOK); }),
        xlb_f("ListView_FindItem", [](HWND hwnd, int iStart, const LV_FINDINFO* plvfi)->auto { return ListView_FindItem(hwnd, iStart, plvfi); }),
        xlb_f("ListView_GetBkColor", [](HWND hwnd)->auto { return ListView_GetBkColor(hwnd); }),
        xlb_f("ListView_GetBkImage", [](HWND hwnd, LPLVBKIMAGE plvbki)->auto { return ListView_GetBkImage(hwnd, plvbki); }),
        xlb_f("ListView_GetCallbackMask", [](HWND hwnd)->auto { return ListView_GetCallbackMask(hwnd); }),
        xlb_f("ListView_GetCheckState", [](HWND hwnd, UINT i)->auto { return ListView_GetCheckState(hwnd, i); }),
        xlb_f("ListView_GetColumn", [](HWND hwnd, int iCol, LV_COLUMN* pcol)->auto { return ListView_GetColumn(hwnd, iCol, pcol); }),
        xlb_f("ListView_GetColumnOrderArray", [](HWND hwnd, int iCount, int* pi)->auto { return ListView_GetColumnOrderArray(hwnd, iCount, pi); }),
        xlb_f("ListView_GetColumnWidth", [](HWND hwnd, int iCol)->auto { return ListView_GetColumnWidth(hwnd, iCol); }),
        xlb_f("ListView_GetCountPerPage", [](HWND hwnd)->auto { return ListView_GetCountPerPage(hwnd); }),
        xlb_f("ListView_GetEditControl", [](HWND hwnd)->auto { return ListView_GetEditControl(hwnd); }),
        xlb_f("ListView_GetEmptyText", [](HWND hwnd, PWSTR pszText, UINT cchText)->auto { return ListView_GetEmptyText(hwnd, pszText, cchText); }),
        xlb_f("ListView_GetExtendedListViewStyle", [](HWND hwnd)->auto { return ListView_GetExtendedListViewStyle(hwnd); }),
        xlb_f("ListView_GetFocusedGroup", [](HWND hwnd)->auto { return ListView_GetFocusedGroup(hwnd); }),
        xlb_f("ListView_GetFooterInfo", [](HWND hwnd, LPLVFOOTERINFO plvfi)->auto { return ListView_GetFooterInfo(hwnd, plvfi); }),
        xlb_f("ListView_GetFooterItem", [](HWND hwnd, UINT iItem, LVFOOTERITEM* pfi)->auto { return ListView_GetFooterItem(hwnd, iItem, pfi); }),
        xlb_f("ListView_GetFooterItemRect", [](HWND hwnd, UINT iItem, RECT* prc)->auto { return ListView_GetFooterItemRect(hwnd, iItem, prc); }),
        xlb_f("ListView_GetFooterRect", [](HWND hwnd, RECT* prc)->auto { return ListView_GetFooterRect(hwnd, prc); }),
        xlb_f("ListView_GetGroupCount", [](HWND hwnd)->auto { return ListView_GetGroupCount(hwnd); }),
        xlb_f("ListView_GetGroupHeaderImageList", [](HWND hwnd)->auto { return ListView_GetGroupHeaderImageList(hwnd); }),
        xlb_f("ListView_GetGroupInfo", [](HWND hwnd, int iGroupId, PLVGROUP pgrp)->auto { return ListView_GetGroupInfo(hwnd, iGroupId, pgrp); }),
        xlb_f("ListView_GetGroupInfoByIndex", [](HWND hwnd, int iIndex, PLVGROUP pgrp)->auto { return ListView_GetGroupInfoByIndex(hwnd, iIndex, pgrp); }),
        xlb_f("ListView_GetGroupMetrics", [](HWND hwnd, PLVGROUPMETRICS pGroupMetrics)->auto { return ListView_GetGroupMetrics(hwnd, pGroupMetrics); }),
        xlb_f("ListView_GetGroupRect", [](HWND hwnd, int iGroupId, LONG type, RECT* prc)->auto { return ListView_GetGroupRect(hwnd, iGroupId, type, prc); }),
        xlb_f("ListView_GetGroupState", [](HWND hwnd, UINT dwGroupId, UINT dwMask)->auto { return ListView_GetGroupState(hwnd, dwGroupId, dwMask); }),
        xlb_f("ListView_GetHeader", [](HWND hwnd)->auto { return ListView_GetHeader(hwnd); }),
        xlb_f("ListView_GetHotCursor", [](HWND hwnd)->auto { return ListView_GetHotCursor(hwnd); }),
        xlb_f("ListView_GetHotItem", [](HWND hwnd)->auto { return ListView_GetHotItem(hwnd); }),
        xlb_f("ListView_GetHoverTime", [](HWND hwnd)->auto { return ListView_GetHoverTime(hwnd); }),
        xlb_f("ListView_GetImageList", [](HWND hwnd, int iImageList)->auto { return ListView_GetImageList(hwnd, iImageList); }),
        xlb_f("ListView_GetInsertMark", [](HWND hwnd, LPLVINSERTMARK lvim)->auto { return ListView_GetInsertMark(hwnd, lvim); }),
        xlb_f("ListView_GetInsertMarkColor", [](HWND hwnd)->auto { return ListView_GetInsertMarkColor(hwnd); }),
        xlb_f("ListView_GetInsertMarkRect", [](HWND hwnd, LPRECT rc)->auto { return ListView_GetInsertMarkRect(hwnd, rc); }),
        xlb_f("ListView_GetISearchString", [](HWND hwnd, LPSTR lpsz)->auto { return ListView_GetISearchString(hwnd, lpsz); }),
        xlb_f("ListView_GetItem", [](HWND hwnd, LPLVITEM pitem)->auto { return ListView_GetItem(hwnd, pitem); }),
        xlb_f("ListView_GetItemCount", [](HWND hwnd)->auto { return ListView_GetItemCount(hwnd); }),
        xlb_f("ListView_GetItemIndexRect", [](HWND hwnd, LVITEMINDEX* plvii, LONG iSubItem, LONG code, LPRECT prc)->auto { return ListView_GetItemIndexRect(hwnd, plvii, iSubItem, code, prc); }),
        xlb_f("ListView_GetItemPosition", [](HWND hwnd, int i, POINT* ppt)->auto { return ListView_GetItemPosition(hwnd, i, ppt); }),
        xlb_f("ListView_GetItemRect", [](HWND hwnd, int i, RECT* prc, int code)->auto { return ListView_GetItemRect(hwnd, i, prc, code); }),
        xlb_f("ListView_GetItemSpacing", [](HWND hwnd, BOOL fSmall)->auto { return ListView_GetItemSpacing(hwnd, fSmall); }),
        xlb_f("ListView_GetItemState", [](HWND hwnd, int i, UINT mask)->auto { return ListView_GetItemState(hwnd, i, mask); }),
        xlb_f("ListView_GetItemText", [](HWND hwnd, int i, int iSubItem_, LPTSTR pszText_, int cchTextMax_) { ListView_GetItemText(hwnd, i, iSubItem_, pszText_, cchTextMax_); }), //XXX: no return
        xlb_f("ListView_GetNextItem", [](HWND hwnd, int i, UINT flags)->auto { return ListView_GetNextItem(hwnd, i, flags); }),
        xlb_f("ListView_GetNextItemIndex", [](HWND hwnd, LVITEMINDEX* plvii, LPARAM flags)->auto { return ListView_GetNextItemIndex(hwnd, plvii, flags); }),

        xlb_f("ListView_GetNumberOfWorkAreas", [](HWND hwnd, LPUINT pnWorkAreas)->auto { return ListView_GetNumberOfWorkAreas(hwnd, pnWorkAreas); }),
        xlb_f("ListView_GetOrigin", [](HWND hwnd, LPPOINT ppt)->auto { return ListView_GetOrigin(hwnd, ppt); }),
        xlb_f("ListView_GetOutlineColor", [](HWND hwnd)->auto { return ListView_GetOutlineColor(hwnd); }),
        xlb_f("ListView_GetSelectedColumn", [](HWND hwnd)->auto { return ListView_GetSelectedColumn(hwnd); }),
        xlb_f("ListView_GetSelectedCount", [](HWND hwnd)->auto { return ListView_GetSelectedCount(hwnd); }),
        xlb_f("ListView_GetSelectionMark", [](HWND hwnd)->auto { return ListView_GetSelectionMark(hwnd); }),
        xlb_f("ListView_GetStringWidth", [](HWND hwnd, LPCSTR psz)->auto { return ListView_GetStringWidth(hwnd, psz); }),
        xlb_f("ListView_GetSubItemRect", [](HWND hwnd, int iItem, int iSubItem, int code, LPRECT prc)->auto { return ListView_GetSubItemRect(hwnd, iItem, iSubItem, code, prc); }),
        xlb_f("ListView_GetTextBkColor", [](HWND hwnd)->auto { return ListView_GetTextBkColor(hwnd); }),
        xlb_f("ListView_GetTextColor", [](HWND hwnd)->auto { return ListView_GetTextColor(hwnd); }),
        xlb_f("ListView_GetTileInfo", [](HWND hwnd, PLVTILEINFO pti)->auto { return ListView_GetTileInfo(hwnd, pti); }),
        xlb_f("ListView_GetTileViewInfo", [](HWND hwnd, PLVTILEVIEWINFO ptvi)->auto { return ListView_GetTileViewInfo(hwnd, ptvi); }),
        xlb_f("ListView_GetToolTips", [](HWND hwnd)->auto { return ListView_GetToolTips(hwnd); }),
        xlb_f("ListView_GetTopIndex", [](HWND hwnd)->auto { return ListView_GetTopIndex(hwnd); }),
        xlb_f("ListView_GetUnicodeFormat", [](HWND hwnd)->auto { return ListView_GetUnicodeFormat(hwnd); }),
        xlb_f("ListView_GetView", [](HWND hwnd)->auto { return ListView_GetView(hwnd); }),
        xlb_f("ListView_GetViewRect", [](HWND hwnd, RECT* prc)->auto { return ListView_GetViewRect(hwnd, prc); }),
        xlb_f("ListView_GetWorkAreas", [](HWND hwnd, INT nWorkAreas, LPRECT prc)->auto { return ListView_GetWorkAreas(hwnd, nWorkAreas, prc); }),
        xlb_f("ListView_HasGroup", [](HWND hwnd, int dwGroupId)->auto { return ListView_HasGroup(hwnd, dwGroupId); }),
        xlb_f("ListView_HitTest", [](HWND hwnd, LPLVHITTESTINFO pinfo)->auto { return ListView_HitTest(hwnd, pinfo); }),
        xlb_f("ListView_HitTestEx", [](HWND hwnd, LPLVHITTESTINFO pinfo)->auto { return ListView_HitTestEx(hwnd, pinfo); }),
        xlb_f("ListView_InsertColumn", [](HWND hwnd, int iCol, const LPLVCOLUMN pcol)->auto { return ListView_InsertColumn(hwnd, iCol, pcol); }),
        xlb_f("ListView_InsertGroup", [](HWND hwnd, int index, PLVGROUP pgrp)->auto { return ListView_InsertGroup(hwnd, index, pgrp); }),
        xlb_f("ListView_InsertGroupSorted", [](HWND hwnd, PLVINSERTGROUPSORTED structInsert)->auto { return ListView_InsertGroupSorted(hwnd, structInsert); }),
        xlb_f("ListView_InsertItem", [](HWND hwnd, const LPLVITEM pitem)->auto { return ListView_InsertItem(hwnd, pitem); }),
        xlb_f("ListView_InsertMarkHitTest", [](HWND hwnd, LPPOINT point, LPLVINSERTMARK lvim)->auto { return ListView_InsertMarkHitTest(hwnd, point, lvim); }),
        xlb_f("ListView_IsGroupViewEnabled", [](HWND hwnd)->auto { return ListView_IsGroupViewEnabled(hwnd); }),
        xlb_f("ListView_IsItemVisible", [](HWND hwnd, UINT index)->auto { return ListView_IsItemVisible(hwnd, index); }),
        xlb_f("ListView_MapIDToIndex", [](HWND hwnd, UINT id)->auto { return ListView_MapIDToIndex(hwnd, id); }),
        xlb_f("ListView_MapIndexToID", [](HWND hwnd, UINT index)->auto { return ListView_MapIndexToID(hwnd, index); }),
        xlb_f("ListView_MoveGroup", [](HWND hwnd, int iGroupId, int toIndex)->auto { return ListView_MoveGroup(hwnd, iGroupId, toIndex); }),
        xlb_f("ListView_MoveItemToGroup", [](HWND hwnd, int idItemFrom, int idGroupTo)->auto { return ListView_MoveItemToGroup(hwnd, idItemFrom, idGroupTo); }),
        xlb_f("ListView_RedrawItems", [](HWND hwnd, int iFirst, int iLast)->auto { return ListView_RedrawItems(hwnd, iFirst, iLast); }),
        xlb_f("ListView_RemoveAllGroups", [](HWND hwnd)->auto { return ListView_RemoveAllGroups(hwnd); }),
        xlb_f("ListView_RemoveGroup", [](HWND hwnd, int iGroupId)->auto { return ListView_RemoveGroup(hwnd, iGroupId); }),
        xlb_f("ListView_Scroll", [](HWND hwnd, int dx, int dy)->auto { return ListView_Scroll(hwnd, dx, dy); }),
        xlb_f("ListView_SetBkColor", [](HWND hwnd, COLORREF clrBk)->auto { return ListView_SetBkColor(hwnd, clrBk); }),
        xlb_f("ListView_SetBkImage", [](HWND hwnd, LPLVBKIMAGE plvbki)->auto { return ListView_SetBkImage(hwnd, plvbki); }),
        xlb_f("ListView_SetCallbackMask", [](HWND hwnd, UINT mask)->auto { return ListView_SetCallbackMask(hwnd, mask); }),
        xlb_f("ListView_SetCheckState", [](HWND hwnd, UINT i, BOOL fCheck) { ListView_SetCheckState(hwnd, i, fCheck); }), //XXX: no return
        xlb_f("ListView_SetColumn", [](HWND hwnd, int iCol, LPLVCOLUMN pcol)->auto { return ListView_SetColumn(hwnd, iCol, pcol); }),
        xlb_f("ListView_SetColumnOrderArray", [](HWND hwnd, int iCount, int* pi)->auto { return ListView_SetColumnOrderArray(hwnd, iCount, pi); }),
        xlb_f("ListView_SetColumnWidth", [](HWND hwnd, int iCol, int cx)->auto { return ListView_SetColumnWidth(hwnd, iCol, cx); }),
        xlb_f("ListView_SetExtendedListViewStyle", [](HWND hwnd, DWORD dw)->auto { return ListView_SetExtendedListViewStyle(hwnd, dw); }),
        xlb_f("ListView_SetExtendedListViewStyleEx", [](HWND hwnd, DWORD dwMask, DWORD dw)->auto { return ListView_SetExtendedListViewStyleEx(hwnd, dwMask, dw); }),
        xlb_f("ListView_SetGroupHeaderImageList", [](HWND hwnd, HIMAGELIST himl)->auto { return ListView_SetGroupHeaderImageList(hwnd, himl); }),
        xlb_f("ListView_SetGroupInfo", [](HWND hwnd, int iGroupId, PLVGROUP pgrp)->auto { return ListView_SetGroupInfo(hwnd, iGroupId, pgrp); }),
        xlb_f("ListView_SetGroupMetrics", [](HWND hwnd, PLVGROUPMETRICS pGroupMetrics)->auto { return ListView_SetGroupMetrics(hwnd, pGroupMetrics); }),
        xlb_f("ListView_SetGroupState", [](HWND hwnd, UINT dwGroupId, UINT dwMask, UINT dwState) { ListView_SetGroupState(hwnd, dwGroupId, dwMask, dwState); }), //XXX: no return
        xlb_f("ListView_SetHotCursor", [](HWND hwnd, HCURSOR hcur)->auto { return ListView_SetHotCursor(hwnd, hcur); }),
        xlb_f("ListView_SetHotItem", [](HWND hwnd, INT i)->auto { return ListView_SetHotItem(hwnd, i); }),
        xlb_f("ListView_SetHoverTime", [](HWND hwnd, DWORD dwHoverTimeMs)->auto { return ListView_SetHoverTime(hwnd, dwHoverTimeMs); }),
        xlb_f("ListView_SetIconSpacing", [](HWND hwnd, int cx, int cy)->auto { return ListView_SetIconSpacing(hwnd, cx, cy); }),
        xlb_f("ListView_SetImageList", [](HWND hwnd, HIMAGELIST himl, int iImageList)->auto { return ListView_SetImageList(hwnd, himl, iImageList); }),
        xlb_f("ListView_SetInfoTip", [](HWND hwnd, PLVSETINFOTIP plvInfoTip)->auto { return ListView_SetInfoTip(hwnd, plvInfoTip); }),
        xlb_f("ListView_SetInsertMark", [](HWND hwnd, LPLVINSERTMARK lvim)->auto { return ListView_SetInsertMark(hwnd, lvim); }),
        xlb_f("ListView_SetInsertMarkColor", [](HWND hwnd, COLORREF color)->auto { return ListView_SetInsertMarkColor(hwnd, color); }),
        xlb_f("ListView_SetItem", [](HWND hwnd, const LPLVITEM pitem)->auto { return ListView_SetItem(hwnd, pitem); }),
        xlb_f("ListView_SetItemCount", [](HWND hwnd, int cItems)->auto { return ListView_SetItemCount(hwnd, cItems); }),
        xlb_f("ListView_SetItemCountEx", [](HWND hwnd, int cItems, DWORD dwFlags)->auto { return ListView_SetItemCountEx(hwnd, cItems, dwFlags); }),
        xlb_f("ListView_SetItemIndexState", [](HWND hwnd, LVITEMINDEX* plvii, UINT data, UINT mask) { ListView_SetItemIndexState(hwnd, plvii, data, mask); }), //XXX: no return
        xlb_f("ListView_SetItemPosition", [](HWND hwnd, int i, int x, int y)->auto { return ListView_SetItemPosition(hwnd, i, x, y); }),
        xlb_f("ListView_SetItemPosition32", [](HWND hwnd, int i, int x0, int y0) { ListView_SetItemPosition32(hwnd, i, x0, y0); }),
        xlb_f("ListView_SetItemState", [](HWND hwnd, int i, UINT data, UINT mask) { ListView_SetItemState(hwnd, i, data, mask); }),
        xlb_f("ListView_SetItemText", [](HWND hwnd, int i, int iSubItem_, LPSTR pszText_) { ListView_SetItemText(hwnd, i, iSubItem_, pszText_); }),
        xlb_f("ListView_SetOutlineColor", [](HWND hwnd, COLORREF color)->auto { return ListView_SetOutlineColor(hwnd, color); }),
        xlb_f("ListView_SetSelectedColumn", [](HWND hwnd, int iCol)->auto { return ListView_SetSelectedColumn(hwnd, iCol); }),
        xlb_f("ListView_SetSelectionMark", [](HWND hwnd, INT i)->auto { return ListView_SetSelectionMark(hwnd, i); }),
        xlb_f("ListView_SetTextBkColor", [](HWND hwnd, COLORREF clrTextBk)->auto { return ListView_SetTextBkColor(hwnd, clrTextBk); }),
        xlb_f("ListView_SetTextColor", [](HWND hwnd, COLORREF clrText)->auto { return ListView_SetTextColor(hwnd, clrText); }),
        xlb_f("ListView_SetTileInfo", [](HWND hwnd, PLVTILEINFO pti)->auto { return ListView_SetTileInfo(hwnd, pti); }),
        xlb_f("ListView_SetTileViewInfo", [](HWND hwnd, PLVTILEVIEWINFO ptvi)->auto { return ListView_SetTileViewInfo(hwnd, ptvi); }),
        xlb_f("ListView_SetToolTips", [](HWND hwnd, HWND hwndNewHwnd)->auto { return ListView_SetToolTips(hwnd, hwndNewHwnd); }),
        xlb_f("ListView_SetUnicodeFormat", [](HWND hwnd, BOOL fUnicode)->auto { return ListView_SetUnicodeFormat(hwnd, fUnicode); }),
        xlb_f("ListView_SetView", [](HWND hwnd, DWORD iView)->auto { return ListView_SetView(hwnd, iView); }),
        xlb_f("ListView_SetWorkAreas", [](HWND hwnd, INT nWorkAreas, LPRECT prc)->auto { return ListView_SetWorkAreas(hwnd, nWorkAreas, prc); }),
        xlb_f("ListView_SortGroups", [](HWND hwnd, PFNLVGROUPCOMPARE _pfnGroupCompate, LPVOID _plv)->auto { return ListView_SortGroups(hwnd, _pfnGroupCompate, _plv); }),
        xlb_f("ListView_SortItems", [](HWND hwnd, PFNLVCOMPARE _pfnCompare, LPARAM _lPrm)->auto { return ListView_SortItems(hwnd, _pfnCompare, _lPrm); }),
        xlb_f("ListView_SortItemsEx", [](HWND hwnd, PFNLVCOMPARE _pfnCompare, LPARAM _lPrm)->auto { return ListView_SortItemsEx(hwnd, _pfnCompare, _lPrm); }),
        xlb_f("ListView_SubItemHitTest", [](HWND hwnd, LPLVHITTESTINFO plvhti)->auto { return ListView_SubItemHitTest(hwnd, plvhti); }),
        xlb_f("ListView_SubItemHitTestEx", [](HWND hwnd, LPLVHITTESTINFO plvhti)->auto { return ListView_SubItemHitTestEx(hwnd, plvhti); }),
        xlb_f("ListView_Update", [](HWND hwnd, int i)->auto { return ListView_Update(hwnd, i); }),

    xlb_class<xlb_cbf<PFNLVGROUPCOMPARE>>("PFNLVGROUPCOMPARE").constructor<xlb_luafunc>(),
    xlb_class<xlb_cbf<PFNLVCOMPARE>>("PFNLVCOMPARE").constructor<xlb_luafunc>(),

    xlb_class<LVBKIMAGEA>("LVBKIMAGEA") .constructor<>() .destructor()
        .property("ulFlags", &LVBKIMAGEA::ulFlags)
        .property("hbm", &LVBKIMAGEA::hbm)
        .property("pszImage", &LVBKIMAGEA::pszImage)
        .property("cchImageMax", &LVBKIMAGEA::cchImageMax)
        .property("xOffsetPercent", &LVBKIMAGEA::xOffsetPercent)
        .property("yOffsetPercent", &LVBKIMAGEA::yOffsetPercent)
        ,
    xlb_class<LVCOLUMNA>("LVCOLUMNA") .constructor<>() .destructor()
        .property("mask", &LVCOLUMNA::mask)
        .property("fmt", &LVCOLUMNA::fmt)
        .property("cx", &LVCOLUMNA::cx)
        .property("pszText", &LVCOLUMNA::pszText)
        .property("cchTextMax", &LVCOLUMNA::cchTextMax)
        .property("iSubItem", &LVCOLUMNA::iSubItem)
        .property("iImage", &LVCOLUMNA::iImage)
        .property("iOrder", &LVCOLUMNA::iOrder)
        .property("cxMin", &LVCOLUMNA::cxMin)
        .property("cxDefault", &LVCOLUMNA::cxDefault)
        .property("cxIdeal", &LVCOLUMNA::cxIdeal)
        ,
    xlb_class<LVFINDINFOA>("LVFINDINFOA") .constructor<>() .destructor()
        .property("flags", &LVFINDINFOA::flags)
        .property("psz", &LVFINDINFOA::psz)
        .property("lParam", &LVFINDINFOA::lParam)
        .property("pt", &LVFINDINFOA::pt)
        .property("vkDirection", &LVFINDINFOA::vkDirection)
        ,
    xlb_class<LVFOOTERINFO>("LVFOOTERINFO") .constructor<>() .destructor()
        .property("mask", &LVFOOTERINFO::mask)
        .property("pszText", &LVFOOTERINFO::pszText)
        .property("cchTextMax", &LVFOOTERINFO::cchTextMax)
        .property("cItems", &LVFOOTERINFO::cItems)
        ,
    xlb_class<LVFOOTERITEM>("LVFOOTERITEM") .constructor<>() .destructor()
        .property("mask", &LVFOOTERITEM::mask)
        .property("iItem", &LVFOOTERITEM::iItem)
        .property("pszText", &LVFOOTERITEM::pszText)
        .property("cchTextMax", &LVFOOTERITEM::cchTextMax)
        .property("state", &LVFOOTERITEM::state)
        .property("stateMask", &LVFOOTERITEM::stateMask)
        ,
    xlb_class<LVGROUP>("LVGROUP") .constructor<>() .destructor()
        .property("cbSize", &LVGROUP::cbSize)
        .property("mask", &LVGROUP::mask)
        .property("pszHeader", &LVGROUP::pszHeader)
        .property("cchHeader", &LVGROUP::cchHeader)
        .property("pszFooter", &LVGROUP::pszFooter)
        .property("cchFooter", &LVGROUP::cchFooter)
        .property("iGroupId", &LVGROUP::iGroupId)
        .property("stateMask", &LVGROUP::stateMask)
        .property("state", &LVGROUP::state)
        .property("uAlign", &LVGROUP::uAlign)
        .property("pszSubtitle", &LVGROUP::pszSubtitle)
        .property("cchSubtitle", &LVGROUP::cchSubtitle)
        .property("pszTask", &LVGROUP::pszTask)
        .property("cchTask", &LVGROUP::cchTask)
        .property("pszDescriptionTop", &LVGROUP::pszDescriptionTop)
        .property("cchDescriptionTop", &LVGROUP::cchDescriptionTop)
        .property("pszDescriptionBottom", &LVGROUP::pszDescriptionBottom)
        .property("cchDescriptionBottom", &LVGROUP::cchDescriptionBottom)
        .property("iTitleImage", &LVGROUP::iTitleImage)
        .property("iExtendedImage", &LVGROUP::iExtendedImage)
        .property("iFirstItem", &LVGROUP::iFirstItem)
        .property("cItems", &LVGROUP::cItems)
        .property("pszSubsetTitle", &LVGROUP::pszSubsetTitle)
        .property("cchSubsetTitle", &LVGROUP::cchSubsetTitle)
        ,
    xlb_class<LVGROUPMETRICS>("LVGROUPMETRICS") .constructor<>() .destructor()
        .property("cbSize", &LVGROUPMETRICS::cbSize)
        .property("mask", &LVGROUPMETRICS::mask)
        .property("Left", &LVGROUPMETRICS::Left)
        .property("Top", &LVGROUPMETRICS::Top)
        .property("Right", &LVGROUPMETRICS::Right)
        .property("Bottom", &LVGROUPMETRICS::Bottom)
        .property("crLeft", &LVGROUPMETRICS::crLeft)
        .property("crTop", &LVGROUPMETRICS::crTop)
        .property("crRight", &LVGROUPMETRICS::crRight)
        .property("crBottom", &LVGROUPMETRICS::crBottom)
        .property("crHeader", &LVGROUPMETRICS::crHeader)
        .property("crFooter", &LVGROUPMETRICS::crFooter)
        ,
    xlb_class<LVHITTESTINFO>("LVHITTESTINFO") .constructor<>() .destructor()
        .property("pt", &LVHITTESTINFO::pt)
        .property("flags", &LVHITTESTINFO::flags)
        .property("iItem", &LVHITTESTINFO::iItem)
        .property("iSubItem", &LVHITTESTINFO::iSubItem)
        .property("iGroup", &LVHITTESTINFO::iGroup)
        ,
xlb_class<LVINSERTGROUPSORTED>("LVINSERTGROUPSORTED") .constructor<>() .destructor()
        .property("pfnGroupCompare", &LVINSERTGROUPSORTED::pfnGroupCompare)
        .property("pvData", &LVINSERTGROUPSORTED::pvData)
        .property("lvGroup", &LVINSERTGROUPSORTED::lvGroup)
        ,
xlb_class<LVINSERTMARK>("LVINSERTMARK") .constructor<>() .destructor()
        .property("cbSize", &LVINSERTMARK::cbSize)
        .property("dwFlags", &LVINSERTMARK::dwFlags)
        .property("iItem", &LVINSERTMARK::iItem)
        .property("dwReserved", &LVINSERTMARK::dwReserved)
        ,
xlb_class<LVITEMA>("LVITEMA") .constructor<>() .destructor()
        .property("mask", &LVITEMA::mask)
        .property("iItem", &LVITEMA::iItem)
        .property("iSubItem", &LVITEMA::iSubItem)
        .property("state", &LVITEMA::state)
        .property("stateMask", &LVITEMA::stateMask)
        .property("pszText", &LVITEMA::pszText)
        .property("cchTextMax", &LVITEMA::cchTextMax)
        .property("iImage", &LVITEMA::iImage)
        .property("lParam", &LVITEMA::lParam)
        .property("iIndent", &LVITEMA::iIndent)
        .property("iGroupId", &LVITEMA::iGroupId)
        .property("cColumns", &LVITEMA::cColumns)
        .property("puColumns", &LVITEMA::puColumns)
        .property("piColFmt", &LVITEMA::piColFmt)
        .property("iGroup", &LVITEMA::iGroup)
        ,
xlb_class<LVITEMINDEX>("LVITEMINDEX") .constructor<>() .destructor()
        .property("iItem", &LVITEMINDEX::iItem)
        .property("iGroup", &LVITEMINDEX::iGroup)
        ,
xlb_class<LVSETINFOTIP>("LVSETINFOTIP") .constructor<>() .destructor()
        .property("cbSize", &LVSETINFOTIP::cbSize)
        .property("dwFlags", &LVSETINFOTIP::dwFlags)
        .property("pszText", &LVSETINFOTIP::pszText)
        .property("iItem", &LVSETINFOTIP::iItem)
        .property("iSubItem", &LVSETINFOTIP::iSubItem)
        ,
xlb_class<LVTILEINFO>("LVTILEINFO") .constructor<>() .destructor()
        .property("cbSize", &LVTILEINFO::cbSize)
        .property("iItem", &LVTILEINFO::iItem)
        .property("cColumns", &LVTILEINFO::cColumns)
        .property("puColumns", &LVTILEINFO::puColumns)
        .property("piColFmt", &LVTILEINFO::piColFmt)
        ,
xlb_class<LVTILEVIEWINFO>("LVTILEVIEWINFO") .constructor<>() .destructor()
        .property("cbSize", &LVTILEVIEWINFO::cbSize)
        .property("dwMask", &LVTILEVIEWINFO::dwMask)
        .property("dwFlags", &LVTILEVIEWINFO::dwFlags)
        .property("sizeTile", &LVTILEVIEWINFO::sizeTile)
        .property("cLines", &LVTILEVIEWINFO::cLines)
        .property("rcLabelMargin", &LVTILEVIEWINFO::rcLabelMargin)
        ,
xlb_class<NMITEMACTIVATE>("NMITEMACTIVATE") .constructor<>() .destructor()
        .property("hdr", &NMITEMACTIVATE::hdr)
        .property("iItem", &NMITEMACTIVATE::iItem)
        .property("iSubItem", &NMITEMACTIVATE::iSubItem)
        .property("uNewState", &NMITEMACTIVATE::uNewState)
        .property("uOldState", &NMITEMACTIVATE::uOldState)
        .property("uChanged", &NMITEMACTIVATE::uChanged)
        .property("ptAction", &NMITEMACTIVATE::ptAction)
        .property("lParam", &NMITEMACTIVATE::lParam)
        .property("uKeyFlags", &NMITEMACTIVATE::uKeyFlags)
        ,
xlb_class<NMLISTVIEW>("NMLISTVIEW") .constructor<>() .destructor()
        .property("hdr", &NMLISTVIEW::hdr)
        .property("iItem", &NMLISTVIEW::iItem)
        .property("iSubItem", &NMLISTVIEW::iSubItem)
        .property("uNewState", &NMLISTVIEW::uNewState)
        .property("uOldState", &NMLISTVIEW::uOldState)
        .property("uChanged", &NMLISTVIEW::uChanged)
        .property("ptAction", &NMLISTVIEW::ptAction)
        .property("lParam", &NMLISTVIEW::lParam)
        ,
xlb_class<NMLVCACHEHINT>("NMLVCACHEHINT") .constructor<>() .destructor()
        .property("hdr", &NMLVCACHEHINT::hdr)
        .property("iFrom", &NMLVCACHEHINT::iFrom)
        .property("iTo", &NMLVCACHEHINT::iTo)
        ,
xlb_class<NMLVCUSTOMDRAW>("NMLVCUSTOMDRAW") .constructor<>() .destructor()
        .property("nmcd", &NMLVCUSTOMDRAW::nmcd)
        .property("clrText", &NMLVCUSTOMDRAW::clrText)
        .property("clrTextBk", &NMLVCUSTOMDRAW::clrTextBk)
        .property("iSubItem", &NMLVCUSTOMDRAW::iSubItem)
        .property("dwItemType", &NMLVCUSTOMDRAW::dwItemType)
        .property("clrFace", &NMLVCUSTOMDRAW::clrFace)
        .property("iIconEffect", &NMLVCUSTOMDRAW::iIconEffect)
        .property("iIconPhase", &NMLVCUSTOMDRAW::iIconPhase)
        .property("iPartId", &NMLVCUSTOMDRAW::iPartId)
        .property("iStateId", &NMLVCUSTOMDRAW::iStateId)
        .property("rcText", &NMLVCUSTOMDRAW::rcText)
        .property("uAlign", &NMLVCUSTOMDRAW::uAlign)
        ,
xlb_class<NMLVDISPINFOA>("NMLVDISPINFOA") .constructor<>() .destructor()
        .property("hdr", &NMLVDISPINFOA::hdr)
        .property("item", &NMLVDISPINFOA::item)
        ,
xlb_class<NMLVEMPTYMARKUP>("NMLVEMPTYMARKUP") .constructor<>() .destructor()
        .property("hdr", &NMLVEMPTYMARKUP::hdr)
        .property("dwFlags", &NMLVEMPTYMARKUP::dwFlags)
//        .property("szMarkup", &NMLVEMPTYMARKUP::szMarkup)
        ,
xlb_class<NMLVFINDITEMA>("NMLVFINDITEMA") .constructor<>() .destructor()
        .property("hdr", &NMLVFINDITEMA::hdr)
        .property("iStart", &NMLVFINDITEMA::iStart)
        .property("lvfi", &NMLVFINDITEMA::lvfi)
        ,
xlb_class<NMLVGETINFOTIPA>("NMLVGETINFOTIPA") .constructor<>() .destructor()
        .property("hdr", &NMLVGETINFOTIPA::hdr)
        .property("dwFlags", &NMLVGETINFOTIPA::dwFlags)
        .property("pszText", &NMLVGETINFOTIPA::pszText)
        .property("cchTextMax", &NMLVGETINFOTIPA::cchTextMax)
        .property("iItem", &NMLVGETINFOTIPA::iItem)
        .property("iSubItem", &NMLVGETINFOTIPA::iSubItem)
        .property("lParam", &NMLVGETINFOTIPA::lParam)
        ,
xlb_class<NMLVKEYDOWN>("NMLVKEYDOWN") .constructor<>() .destructor()
        .property("hdr", &NMLVKEYDOWN::hdr)
        .property("wVKey", &NMLVKEYDOWN::wVKey)
        .property("flags", &NMLVKEYDOWN::flags)
        ,
xlb_class<NMLVLINK>("NMLVLINK") .constructor<>() .destructor()
        .property("hdr", &NMLVLINK::hdr)
        .property("link", &NMLVLINK::link)
        .property("iItem", &NMLVLINK::iItem)
        .property("iSubItem", &NMLVLINK::iSubItem)
        ,
xlb_class<NMLVODSTATECHANGE>("NMLVODSTATECHANGE") .constructor<>() .destructor()
        .property("hdr", &NMLVODSTATECHANGE::hdr)
        .property("iFrom", &NMLVODSTATECHANGE::iFrom)
        .property("iTo", &NMLVODSTATECHANGE::iTo)
        .property("uNewState", &NMLVODSTATECHANGE::uNewState)
        .property("uOldState", &NMLVODSTATECHANGE::uOldState)
        ,
xlb_class<NMLVSCROLL>("NMLVSCROLL") .constructor<>() .destructor()
        .property("hdr", &NMLVSCROLL::hdr)
        .property("dx", &NMLVSCROLL::dx)
        .property("dy", &NMLVSCROLL::dy)
        ,
        xlb_const("LVS_ALIGNLEFT", LVS_ALIGNLEFT),
        xlb_const("LVS_ALIGNMASK", LVS_ALIGNMASK),
        xlb_const("LVS_ALIGNTOP", LVS_ALIGNTOP),
        xlb_const("LVS_AUTOARRANGE", LVS_AUTOARRANGE),
        xlb_const("LVS_EDITLABELS", LVS_EDITLABELS),
        xlb_const("LVS_ICON", (uint32_t)LVS_ICON),
        xlb_const("LVS_LIST", LVS_LIST),
        xlb_const("LVS_NOCOLUMNHEADER", LVS_NOCOLUMNHEADER),
        xlb_const("LVS_NOLABELWRAP", LVS_NOLABELWRAP),
        xlb_const("LVS_NOSCROLL", LVS_NOSCROLL),
        xlb_const("LVS_NOSORTHEADER", LVS_NOSORTHEADER),
        xlb_const("LVS_OWNERDATA", LVS_OWNERDATA),
        xlb_const("LVS_OWNERDRAWFIXED", LVS_OWNERDRAWFIXED),
        xlb_const("LVS_REPORT", LVS_REPORT),
        xlb_const("LVS_SHAREIMAGELISTS", LVS_SHAREIMAGELISTS),
        xlb_const("LVS_SHOWSELALWAYS", LVS_SHOWSELALWAYS),
        xlb_const("LVS_SINGLESEL", LVS_SINGLESEL),
        xlb_const("LVS_SMALLICON", LVS_SMALLICON),
        xlb_const("LVS_SORTASCENDING", LVS_SORTASCENDING),
        xlb_const("LVS_SORTDESCENDING", LVS_SORTDESCENDING),
        xlb_const("LVS_TYPEMASK", LVS_TYPEMASK),
        xlb_const("LVS_TYPESTYLEMASK", LVS_TYPESTYLEMASK),
        xlb_const("LVS_EX_AUTOAUTOARRANGE", LVS_EX_AUTOAUTOARRANGE),
        xlb_const("LVS_EX_AUTOCHECKSELECT", LVS_EX_AUTOCHECKSELECT),
        xlb_const("LVS_EX_AUTOSIZECOLUMNS", LVS_EX_AUTOSIZECOLUMNS),
        xlb_const("LVS_EX_BORDERSELECT", LVS_EX_BORDERSELECT),
        xlb_const("LVS_EX_CHECKBOXES", LVS_EX_CHECKBOXES),
        xlb_const("LVS_EX_COLUMNOVERFLOW", LVS_EX_COLUMNOVERFLOW),
        xlb_const("LVS_EX_COLUMNSNAPPOINTS", LVS_EX_COLUMNSNAPPOINTS),
        xlb_const("LVS_EX_DOUBLEBUFFER", LVS_EX_DOUBLEBUFFER),
        xlb_const("LVS_EX_FLATSB", LVS_EX_FLATSB),
        xlb_const("LVS_EX_FULLROWSELECT", LVS_EX_FULLROWSELECT),
        xlb_const("LVS_EX_GRIDLINES", LVS_EX_GRIDLINES),
        xlb_const("LVS_EX_HEADERDRAGDROP", LVS_EX_HEADERDRAGDROP),
        xlb_const("LVS_EX_HEADERINALLVIEWS", LVS_EX_HEADERINALLVIEWS),
        xlb_const("LVS_EX_HIDELABELS", LVS_EX_HIDELABELS),
        xlb_const("LVS_EX_INFOTIP", LVS_EX_INFOTIP),
        xlb_const("LVS_EX_JUSTIFYCOLUMNS", LVS_EX_JUSTIFYCOLUMNS),
        xlb_const("LVS_EX_LABELTIP", LVS_EX_LABELTIP),
        xlb_const("LVS_EX_MULTIWORKAREAS", LVS_EX_MULTIWORKAREAS),
        xlb_const("LVS_EX_ONECLICKACTIVATE", LVS_EX_ONECLICKACTIVATE),
        xlb_const("LVS_EX_REGIONAL", LVS_EX_REGIONAL),
        xlb_const("LVS_EX_SIMPLESELECT", LVS_EX_SIMPLESELECT),
        xlb_const("LVS_EX_SINGLEROW", LVS_EX_SINGLEROW),
        xlb_const("LVS_EX_SNAPTOGRID", LVS_EX_SNAPTOGRID),
        xlb_const("LVS_EX_SUBITEMIMAGES", LVS_EX_SUBITEMIMAGES),
        xlb_const("LVS_EX_TRACKSELECT", LVS_EX_TRACKSELECT),
        xlb_const("LVS_EX_TRANSPARENTBKGND", LVS_EX_TRANSPARENTBKGND),
        xlb_const("LVS_EX_TRANSPARENTSHADOWTEXT", LVS_EX_TRANSPARENTSHADOWTEXT),
        xlb_const("LVS_EX_TWOCLICKACTIVATE", LVS_EX_TWOCLICKACTIVATE),
        xlb_const("LVS_EX_UNDERLINECOLD", LVS_EX_UNDERLINECOLD),
        xlb_const("LVS_EX_UNDERLINEHOT", LVS_EX_UNDERLINEHOT),
        xlb_const("LVSIL_NORMAL", LVSIL_NORMAL),
        xlb_const("LVSIL_SMALL", LVSIL_SMALL),
        xlb_const("LVSIL_STATE", LVSIL_STATE),
        xlb_const("LVSIL_GROUPHEADER", LVSIL_GROUPHEADER),
        xlb_const("LVSICF_NOINVALIDATEALL", LVSICF_NOINVALIDATEALL),
        xlb_const("LVSICF_NOSCROLL", LVSICF_NOSCROLL),
        xlb_const("LVIS_CUT", LVIS_CUT),
        xlb_const("LVIS_DROPHILITED", LVIS_DROPHILITED),
        xlb_const("LVIS_FOCUSED", LVIS_FOCUSED),
        xlb_const("LVIS_SELECTED", LVIS_SELECTED),
        
        xlb_const("LVM_APPROXIMATEVIEWRECT", LVM_APPROXIMATEVIEWRECT),
        xlb_const("LVM_ARRANGE", LVM_ARRANGE),
        xlb_const("LVM_CANCELEDITLABEL", LVM_CANCELEDITLABEL),
        xlb_const("LVM_CREATEDRAGIMAGE", LVM_CREATEDRAGIMAGE),
        xlb_const("LVM_DELETEALLITEMS", LVM_DELETEALLITEMS),
        xlb_const("LVM_DELETECOLUMN", LVM_DELETECOLUMN),
        xlb_const("LVM_DELETEITEM", LVM_DELETEITEM),
        xlb_const("LVM_EDITLABEL", LVM_EDITLABEL),
        xlb_const("LVM_ENABLEGROUPVIEW", LVM_ENABLEGROUPVIEW),
        xlb_const("LVM_ENSUREVISIBLE", LVM_ENSUREVISIBLE),
        xlb_const("LVM_FINDITEM", LVM_FINDITEM),
        xlb_const("LVM_GETBKCOLOR", LVM_GETBKCOLOR),
        xlb_const("LVM_GETBKIMAGE", LVM_GETBKIMAGE),
        xlb_const("LVM_GETCALLBACKMASK", LVM_GETCALLBACKMASK),
        xlb_const("LVM_GETCOLUMN", LVM_GETCOLUMN),
        xlb_const("LVM_GETCOLUMNORDERARRAY", LVM_GETCOLUMNORDERARRAY),
        xlb_const("LVM_GETCOLUMNWIDTH", LVM_GETCOLUMNWIDTH),
        xlb_const("LVM_GETCOUNTPERPAGE", LVM_GETCOUNTPERPAGE),
        xlb_const("LVM_GETEDITCONTROL", LVM_GETEDITCONTROL),
        xlb_const("LVM_GETEMPTYTEXT", LVM_GETEMPTYTEXT),
        xlb_const("LVM_GETEXTENDEDLISTVIEWSTYLE", LVM_GETEXTENDEDLISTVIEWSTYLE),
        xlb_const("LVM_GETFOCUSEDGROUP", LVM_GETFOCUSEDGROUP),
        xlb_const("LVM_GETFOOTERINFO", LVM_GETFOOTERINFO),
        xlb_const("LVM_GETFOOTERITEM", LVM_GETFOOTERITEM),
        xlb_const("LVM_GETFOOTERITEMRECT", LVM_GETFOOTERITEMRECT),
        xlb_const("LVM_GETFOOTERRECT", LVM_GETFOOTERRECT),
        xlb_const("LVM_GETGROUPCOUNT", LVM_GETGROUPCOUNT),
        xlb_const("LVM_GETGROUPINFO", LVM_GETGROUPINFO),
        xlb_const("LVM_GETGROUPINFOBYINDEX", LVM_GETGROUPINFOBYINDEX),
        xlb_const("LVM_GETGROUPMETRICS", LVM_GETGROUPMETRICS),
        xlb_const("LVM_GETGROUPRECT", LVM_GETGROUPRECT),
        xlb_const("LVM_GETGROUPSTATE", LVM_GETGROUPSTATE),
        xlb_const("LVM_GETHEADER", LVM_GETHEADER),
        xlb_const("LVM_GETHOTCURSOR", LVM_GETHOTCURSOR),
        xlb_const("LVM_GETHOTITEM", LVM_GETHOTITEM),
        xlb_const("LVM_GETHOVERTIME", LVM_GETHOVERTIME),
        xlb_const("LVM_GETIMAGELIST", LVM_GETIMAGELIST),
        xlb_const("LVM_GETINSERTMARK", LVM_GETINSERTMARK),
        xlb_const("LVM_GETINSERTMARKCOLOR", LVM_GETINSERTMARKCOLOR),
        xlb_const("LVM_GETINSERTMARKRECT", LVM_GETINSERTMARKRECT),
        xlb_const("LVM_GETISEARCHSTRING", LVM_GETISEARCHSTRING),
        xlb_const("LVM_GETITEM", LVM_GETITEM),
        xlb_const("LVM_GETITEMCOUNT", LVM_GETITEMCOUNT),
        xlb_const("LVM_GETITEMINDEXRECT", LVM_GETITEMINDEXRECT),
        xlb_const("LVM_GETITEMPOSITION", LVM_GETITEMPOSITION),
        xlb_const("LVM_GETITEMRECT", LVM_GETITEMRECT),
        xlb_const("LVM_GETITEMSPACING", LVM_GETITEMSPACING),
        xlb_const("LVM_GETITEMSTATE", LVM_GETITEMSTATE),
        xlb_const("LVM_GETITEMTEXT", LVM_GETITEMTEXT),
        xlb_const("LVM_GETNEXTITEM", LVM_GETNEXTITEM),
        xlb_const("LVM_GETNEXTITEMINDEX", LVM_GETNEXTITEMINDEX),
        xlb_const("LVM_GETNUMBEROFWORKAREAS", LVM_GETNUMBEROFWORKAREAS),
        xlb_const("LVM_GETORIGIN", LVM_GETORIGIN),
        xlb_const("LVM_GETOUTLINECOLOR", LVM_GETOUTLINECOLOR),
        xlb_const("LVM_GETSELECTEDCOLUMN", LVM_GETSELECTEDCOLUMN),
        xlb_const("LVM_GETSELECTEDCOUNT", LVM_GETSELECTEDCOUNT),
        xlb_const("LVM_GETSELECTIONMARK", LVM_GETSELECTIONMARK),
        xlb_const("LVM_GETSTRINGWIDTH", LVM_GETSTRINGWIDTH),
        xlb_const("LVM_GETSUBITEMRECT", LVM_GETSUBITEMRECT),
        xlb_const("LVM_GETTEXTBKCOLOR", LVM_GETTEXTBKCOLOR),
        xlb_const("LVM_GETTEXTCOLOR", LVM_GETTEXTCOLOR),
        xlb_const("LVM_GETTILEINFO", LVM_GETTILEINFO),
        xlb_const("LVM_GETTILEVIEWINFO", LVM_GETTILEVIEWINFO),
        xlb_const("LVM_GETTOOLTIPS", LVM_GETTOOLTIPS),
        xlb_const("LVM_GETTOPINDEX", LVM_GETTOPINDEX),
        xlb_const("LVM_GETUNICODEFORMAT", LVM_GETUNICODEFORMAT),
        xlb_const("LVM_GETVIEW", LVM_GETVIEW),
        xlb_const("LVM_GETVIEWRECT", LVM_GETVIEWRECT),
        xlb_const("LVM_GETWORKAREAS", LVM_GETWORKAREAS),
        xlb_const("LVM_HASGROUP", LVM_HASGROUP),
        xlb_const("LVM_HITTEST", LVM_HITTEST),
        xlb_const("LVM_INSERTCOLUMN", LVM_INSERTCOLUMN),
        xlb_const("LVM_INSERTGROUP", LVM_INSERTGROUP),
        xlb_const("LVM_INSERTGROUPSORTED", LVM_INSERTGROUPSORTED),
        xlb_const("LVM_INSERTITEM", LVM_INSERTITEM),
        xlb_const("LVM_INSERTMARKHITTEST", LVM_INSERTMARKHITTEST),
        xlb_const("LVM_ISGROUPVIEWENABLED", LVM_ISGROUPVIEWENABLED),
        xlb_const("LVM_ISITEMVISIBLE", LVM_ISITEMVISIBLE),
        xlb_const("LVM_MAPIDTOINDEX", LVM_MAPIDTOINDEX),
        xlb_const("LVM_MAPINDEXTOID", LVM_MAPINDEXTOID),
        xlb_const("LVM_MOVEGROUP", LVM_MOVEGROUP),
        xlb_const("LVM_MOVEITEMTOGROUP", LVM_MOVEITEMTOGROUP),
        xlb_const("LVM_REDRAWITEMS", LVM_REDRAWITEMS),
        xlb_const("LVM_REMOVEALLGROUPS", LVM_REMOVEALLGROUPS),
        xlb_const("LVM_REMOVEGROUP", LVM_REMOVEGROUP),
        xlb_const("LVM_SCROLL", LVM_SCROLL),
        xlb_const("LVM_SETBKCOLOR", LVM_SETBKCOLOR),
        xlb_const("LVM_SETBKIMAGE", LVM_SETBKIMAGE),
        xlb_const("LVM_SETCALLBACKMASK", LVM_SETCALLBACKMASK),
        xlb_const("LVM_SETCOLUMN", LVM_SETCOLUMN),
        xlb_const("LVM_SETCOLUMNORDERARRAY", LVM_SETCOLUMNORDERARRAY),
        xlb_const("LVM_SETCOLUMNWIDTH", LVM_SETCOLUMNWIDTH),
        xlb_const("LVM_SETEXTENDEDLISTVIEWSTYLE", LVM_SETEXTENDEDLISTVIEWSTYLE),
        xlb_const("LVM_SETGROUPINFO", LVM_SETGROUPINFO),
        xlb_const("LVM_SETGROUPMETRICS", LVM_SETGROUPMETRICS),
        xlb_const("LVM_SETHOTCURSOR", LVM_SETHOTCURSOR),
        xlb_const("LVM_SETHOTITEM", LVM_SETHOTITEM),
        xlb_const("LVM_SETHOVERTIME", LVM_SETHOVERTIME),
        xlb_const("LVM_SETICONSPACING", LVM_SETICONSPACING),
        xlb_const("LVM_SETIMAGELIST", LVM_SETIMAGELIST),
        xlb_const("LVM_SETINFOTIP", LVM_SETINFOTIP),
        xlb_const("LVM_SETINSERTMARK", LVM_SETINSERTMARK),
        xlb_const("LVM_SETINSERTMARKCOLOR", LVM_SETINSERTMARKCOLOR),
        xlb_const("LVM_SETITEM", LVM_SETITEM),
        xlb_const("LVM_SETITEMCOUNT", LVM_SETITEMCOUNT),
        xlb_const("LVM_SETITEMINDEXSTATE", LVM_SETITEMINDEXSTATE),
        xlb_const("LVM_SETITEMPOSITION", LVM_SETITEMPOSITION),
        xlb_const("LVM_SETITEMPOSITION32", LVM_SETITEMPOSITION32),
        xlb_const("LVM_SETITEMSTATE", LVM_SETITEMSTATE),
        xlb_const("LVM_SETITEMTEXT", LVM_SETITEMTEXT),
        xlb_const("LVM_SETOUTLINECOLOR", LVM_SETOUTLINECOLOR),
        xlb_const("LVM_SETSELECTEDCOLUMN", LVM_SETSELECTEDCOLUMN),
        xlb_const("LVM_SETSELECTIONMARK", LVM_SETSELECTIONMARK),
        xlb_const("LVM_SETTEXTBKCOLOR", LVM_SETTEXTBKCOLOR),
        xlb_const("LVM_SETTEXTCOLOR", LVM_SETTEXTCOLOR),
        xlb_const("LVM_SETTILEINFO", LVM_SETTILEINFO),
        xlb_const("LVM_SETTILEVIEWINFO", LVM_SETTILEVIEWINFO),
        //xlb_const("LVM_SETTILEWIDTH", LVM_SETTILEWIDTH), //XXX: This Message is unsupported.
        xlb_const("LVM_SETTOOLTIPS", LVM_SETTOOLTIPS),
        xlb_const("LVM_SETUNICODEFORMAT", LVM_SETUNICODEFORMAT),
        xlb_const("LVM_SETVIEW", LVM_SETVIEW),
        xlb_const("LVM_SETWORKAREAS", LVM_SETWORKAREAS),
        xlb_const("LVM_SORTGROUPS", LVM_SORTGROUPS),
        xlb_const("LVM_SORTITEMS", LVM_SORTITEMS),
        xlb_const("LVM_SORTITEMSEX", LVM_SORTITEMSEX),
        xlb_const("LVM_SUBITEMHITTEST", LVM_SUBITEMHITTEST),
        xlb_const("LVM_UPDATE", LVM_UPDATE),
        xlb_const("LVN_BEGINDRAG", LVN_BEGINDRAG),
        xlb_const("LVN_BEGINLABELEDIT", LVN_BEGINLABELEDIT),
        xlb_const("LVN_BEGINRDRAG", LVN_BEGINRDRAG),
        xlb_const("LVN_BEGINSCROLL", LVN_BEGINSCROLL),
        xlb_const("LVN_COLUMNCLICK", LVN_COLUMNCLICK),
        xlb_const("LVN_COLUMNDROPDOWN", LVN_COLUMNDROPDOWN),
        xlb_const("LVN_COLUMNOVERFLOWCLICK", LVN_COLUMNOVERFLOWCLICK),
        xlb_const("LVN_DELETEALLITEMS", LVN_DELETEALLITEMS),
        xlb_const("LVN_DELETEITEM", LVN_DELETEITEM),
        xlb_const("LVN_ENDLABELEDIT", LVN_ENDLABELEDIT),
        xlb_const("LVN_ENDSCROLL", LVN_ENDSCROLL),
        xlb_const("LVN_GETDISPINFO", LVN_GETDISPINFO),
        xlb_const("LVN_GETEMPTYMARKUP", LVN_GETEMPTYMARKUP),
        xlb_const("LVN_GETINFOTIP", LVN_GETINFOTIP),
        xlb_const("LVN_HOTTRACK", LVN_HOTTRACK),
        xlb_const("LVN_INCREMENTALSEARCH", LVN_INCREMENTALSEARCH),
        xlb_const("LVN_INSERTITEM", LVN_INSERTITEM),
        xlb_const("LVN_ITEMACTIVATE", LVN_ITEMACTIVATE),
        xlb_const("LVN_ITEMCHANGED", LVN_ITEMCHANGED),
        xlb_const("LVN_ITEMCHANGING", LVN_ITEMCHANGING),
        xlb_const("LVN_KEYDOWN", LVN_KEYDOWN),
        xlb_const("LVN_LINKCLICK", LVN_LINKCLICK),
        xlb_const("LVN_MARQUEEBEGIN", LVN_MARQUEEBEGIN),
        xlb_const("LVN_ODCACHEHINT", LVN_ODCACHEHINT),
        xlb_const("LVN_ODFINDITEM", LVN_ODFINDITEM),
        xlb_const("LVN_ODSTATECHANGED", LVN_ODSTATECHANGED),
        xlb_const("LVN_SETDISPINFO", LVN_SETDISPINFO),
        xlb_const("NM_CLICK", NM_CLICK),
        xlb_const("NM_CUSTOMDRAW", NM_CUSTOMDRAW),
        xlb_const("NM_DBLCLK", NM_DBLCLK),
        xlb_const("NM_HOVER", NM_HOVER),
        xlb_const("NM_KILLFOCUS", NM_KILLFOCUS),
        xlb_const("NM_RCLICK", NM_RCLICK),
        xlb_const("NM_RDBLCLK", NM_RDBLCLK),
        xlb_const("NM_RELEASEDCAPTURE", NM_RELEASEDCAPTURE),
        xlb_const("NM_RETURN", NM_RETURN),
        xlb_const("NM_SETFOCUS", NM_SETFOCUS),
        xlb_const("LVBKIF_SOURCE_NONE", LVBKIF_SOURCE_NONE),
        xlb_const("LVBKIF_SOURCE_HBITMAP", LVBKIF_SOURCE_HBITMAP),
        xlb_const("LVBKIF_SOURCE_URL", LVBKIF_SOURCE_URL),
        xlb_const("LVBKIF_STYLE_NORMAL", LVBKIF_STYLE_NORMAL),
        xlb_const("LVBKIF_STYLE_TILE", LVBKIF_STYLE_TILE),
        xlb_const("LVBKIF_FLAG_TILEOFFSET", LVBKIF_FLAG_TILEOFFSET),
        xlb_const("LVBKIF_TYPE_WATERMARK", LVBKIF_TYPE_WATERMARK),
        xlb_const("LVBKIF_FLAG_ALPHABLEND", LVBKIF_FLAG_ALPHABLEND),
        xlb_const("LVCF_FMT", LVCF_FMT),
        xlb_const("LVCF_WIDTH", LVCF_WIDTH),
        xlb_const("LVCF_TEXT", LVCF_TEXT),
        xlb_const("LVCF_SUBITEM", LVCF_SUBITEM),
        xlb_const("LVCF_IMAGE", LVCF_IMAGE),
        xlb_const("LVCF_ORDER", LVCF_ORDER),
        xlb_const("LVCF_MINWIDTH", LVCF_MINWIDTH),
        xlb_const("LVCF_DEFAULTWIDTH", LVCF_DEFAULTWIDTH),
        xlb_const("LVCF_IDEALWIDTH", LVCF_IDEALWIDTH),
        xlb_const("LVCFMT_LEFT", LVCFMT_LEFT),
        xlb_const("LVCFMT_RIGHT", LVCFMT_RIGHT),
        xlb_const("LVCFMT_CENTER", LVCFMT_CENTER),
        xlb_const("LVCFMT_JUSTIFYMASK", LVCFMT_JUSTIFYMASK),
        xlb_const("LVCFMT_IMAGE", LVCFMT_IMAGE),
        xlb_const("LVCFMT_BITMAP_ON_RIGHT", LVCFMT_BITMAP_ON_RIGHT),
        xlb_const("LVCFMT_COL_HAS_IMAGES", LVCFMT_COL_HAS_IMAGES),
        xlb_const("LVCFMT_FIXED_WIDTH", LVCFMT_FIXED_WIDTH),
        xlb_const("LVCFMT_NO_DPI_SCALE", LVCFMT_NO_DPI_SCALE),
        xlb_const("LVCFMT_FIXED_RATIO", LVCFMT_FIXED_RATIO),
        xlb_const("LVCFMT_SPLITBUTTON", LVCFMT_SPLITBUTTON),
        xlb_const("LVFI_PARAM", LVFI_PARAM),
        xlb_const("LVFI_PARTIAL", LVFI_PARTIAL),
        xlb_const("LVFI_STRING", LVFI_STRING),
        xlb_const("LVFI_SUBSTRING", LVFI_SUBSTRING),
        xlb_const("LVFI_WRAP", LVFI_WRAP),
        xlb_const("LVFI_NEARESTXY", LVFI_NEARESTXY),
        xlb_const("LVFIF_TEXT", LVFIF_TEXT),
        xlb_const("LVFIF_STATE", LVFIF_STATE),
        xlb_const("LVFIS_FOCUSED", LVFIS_FOCUSED),
        xlb_const("LVGF_NONE", LVGF_NONE),
        xlb_const("LVGF_HEADER", LVGF_HEADER),
        xlb_const("LVGF_FOOTER", LVGF_FOOTER),
        xlb_const("LVGF_STATE", LVGF_STATE),
        xlb_const("LVGF_ALIGN", LVGF_ALIGN),
        xlb_const("LVGF_GROUPID", LVGF_GROUPID),
        xlb_const("LVGF_SUBTITLE", LVGF_SUBTITLE),
        xlb_const("LVGF_TASK", LVGF_TASK),
        xlb_const("LVGF_DESCRIPTIONTOP", LVGF_DESCRIPTIONTOP),
        xlb_const("LVGF_DESCRIPTIONBOTTOM", LVGF_DESCRIPTIONBOTTOM),
        xlb_const("LVGF_TITLEIMAGE", LVGF_TITLEIMAGE),
        xlb_const("LVGF_EXTENDEDIMAGE", LVGF_EXTENDEDIMAGE),
        xlb_const("LVGF_ITEMS", LVGF_ITEMS),
        xlb_const("LVGF_SUBSET", LVGF_SUBSET),
        xlb_const("LVGF_SUBSETITEMS", LVGF_SUBSETITEMS),
        xlb_const("LVGS_NORMAL", LVGS_NORMAL),
        xlb_const("LVGS_COLLAPSED", LVGS_COLLAPSED),
        xlb_const("LVGS_HIDDEN", LVGS_HIDDEN),
        xlb_const("LVGS_NOHEADER", LVGS_NOHEADER),
        xlb_const("LVGS_COLLAPSIBLE", LVGS_COLLAPSIBLE),
        xlb_const("LVGS_FOCUSED", LVGS_FOCUSED),
        xlb_const("LVGS_SELECTED", LVGS_SELECTED),
        xlb_const("LVGS_SUBSETED", LVGS_SUBSETED),
        xlb_const("LVGS_SUBSETLINKFOCUSED", LVGS_SUBSETLINKFOCUSED),
        xlb_const("LVGA_FOOTER_CENTER", LVGA_FOOTER_CENTER),
        xlb_const("LVGA_FOOTER_LEFT", LVGA_FOOTER_LEFT),
        xlb_const("LVGA_FOOTER_RIGHT", LVGA_FOOTER_RIGHT),
        xlb_const("LVGA_HEADER_CENTER", LVGA_HEADER_CENTER),
        xlb_const("LVGA_HEADER_LEFT", LVGA_HEADER_LEFT),
        xlb_const("LVGA_HEADER_RIGHT", LVGA_HEADER_RIGHT),
        xlb_const("LVGMF_BORDERCOLOR", LVGMF_BORDERCOLOR),
        xlb_const("LVGMF_BORDERSIZE", LVGMF_BORDERSIZE),
        xlb_const("LVGMF_NONE", LVGMF_NONE),
        xlb_const("LVGMF_TEXTCOLOR", LVGMF_TEXTCOLOR),
        xlb_const("LVHT_ABOVE", LVHT_ABOVE),
        xlb_const("LVHT_BELOW", LVHT_BELOW),
        xlb_const("LVHT_NOWHERE", LVHT_NOWHERE),
        xlb_const("LVHT_ONITEMICON", LVHT_ONITEMICON),
        xlb_const("LVHT_ONITEMLABEL", LVHT_ONITEMLABEL),
        xlb_const("LVHT_ONITEMSTATEICON", LVHT_ONITEMSTATEICON),
        xlb_const("LVHT_TOLEFT", LVHT_TOLEFT),
        xlb_const("LVHT_TORIGHT", LVHT_TORIGHT),
        xlb_const("LVHT_EX_GROUP_HEADER", LVHT_EX_GROUP_HEADER),
        xlb_const("LVHT_EX_GROUP_FOOTER", LVHT_EX_GROUP_FOOTER),
        xlb_const("LVHT_EX_GROUP_COLLAPSE", LVHT_EX_GROUP_COLLAPSE),
        xlb_const("LVHT_EX_GROUP_BACKGROUND", LVHT_EX_GROUP_BACKGROUND),
        xlb_const("LVHT_EX_GROUP_STATEICON", LVHT_EX_GROUP_STATEICON),
        xlb_const("LVHT_EX_GROUP_SUBSETLINK", LVHT_EX_GROUP_SUBSETLINK),
        xlb_const("LVHT_EX_GROUP", LVHT_EX_GROUP),
        xlb_const("LVHT_EX_ONCONTENTS", LVHT_EX_ONCONTENTS),
        xlb_const("LVHT_EX_FOOTER", LVHT_EX_FOOTER),
        xlb_const("LVIM_AFTER", LVIM_AFTER),
        xlb_const("LVIF_COLFMT", LVIF_COLFMT),
        xlb_const("LVIF_COLUMNS", LVIF_COLUMNS),
        xlb_const("LVIF_DI_SETITEM", LVIF_DI_SETITEM),
        xlb_const("LVIF_GROUPID", LVIF_GROUPID),
        xlb_const("LVIF_IMAGE", LVIF_IMAGE),
        xlb_const("LVIF_INDENT", LVIF_INDENT),
        xlb_const("LVIF_NORECOMPUTE", LVIF_NORECOMPUTE),
        xlb_const("LVIF_PARAM", LVIF_PARAM),
        xlb_const("LVIF_STATE", LVIF_STATE),
        xlb_const("LVIF_TEXT", LVIF_TEXT),
        xlb_const("I_GROUPIDCALLBACK", I_GROUPIDCALLBACK),
        xlb_const("I_GROUPIDNONE", I_GROUPIDNONE),
        xlb_const("LVCFMT_LINE_BREAK", LVCFMT_LINE_BREAK),
        xlb_const("LVCFMT_FILL", LVCFMT_FILL),
        xlb_const("LVCFMT_WRAP", LVCFMT_WRAP),
        xlb_const("LVCFMT_NO_TITLE", LVCFMT_NO_TITLE),
        xlb_const("LVCFMT_TILE_PLACEMENTMASK", LVCFMT_TILE_PLACEMENTMASK),
        xlb_const("LVTVIM_TILESIZE", LVTVIM_TILESIZE),
        xlb_const("LVTVIM_COLUMNS", LVTVIM_COLUMNS),
        xlb_const("LVTVIM_LABELMARGIN", LVTVIM_LABELMARGIN),
        xlb_const("LVTVIF_AUTOSIZE", LVTVIF_AUTOSIZE),
        xlb_const("LVTVIF_EXTENDED", LVTVIF_EXTENDED),
        xlb_const("LVTVIF_FIXEDWIDTH", LVTVIF_FIXEDWIDTH),
        xlb_const("LVTVIF_FIXEDHEIGHT", LVTVIF_FIXEDHEIGHT),
        xlb_const("LVTVIF_FIXEDSIZE", LVTVIF_FIXEDSIZE),
        xlb_const("LVKF_ALT", LVKF_ALT),
        xlb_const("LVKF_CONTROL", LVKF_CONTROL),
        xlb_const("LVKF_SHIFT", LVKF_SHIFT),
        xlb_const("LVCDI_ITEM", LVCDI_ITEM),
        xlb_const("LVCDI_GROUP", LVCDI_GROUP),
        xlb_const("LVCDI_ITEMSLIST", LVCDI_ITEMSLIST),
        xlb_const("EMF_CENTERED", EMF_CENTERED),

        // Month Calendar
        xlb_f("MonthCal_GetCalendarBorder", [](HWND hwnd)->auto { return MonthCal_GetCalendarBorder(hwnd); }),
        xlb_f("MonthCal_GetCalendarCount", [](HWND hwnd)->auto { return MonthCal_GetCalendarCount(hwnd); }),
        xlb_f("MonthCal_GetCalendarGridInfo", [](HWND hwnd, MCGRIDINFO* pmcGridInfo)->auto { return MonthCal_GetCalendarGridInfo(hwnd, pmcGridInfo); }),
        xlb_f("MonthCal_GetCALID", [](HWND hwnd)->auto { return MonthCal_GetCALID(hwnd); }),
        xlb_f("MonthCal_GetColor", [](HWND hwnd, int iCol)->auto { return MonthCal_GetColor(hwnd, iCol); }),
        xlb_f("MonthCal_GetCurrentView", [](HWND hwnd)->auto { return MonthCal_GetCurrentView(hwnd); }),
        xlb_f("MonthCal_GetCurSel", [](HWND hwnd, LPSYSTEMTIME pst)->auto { return MonthCal_GetCurSel(hwnd, pst); }),
        xlb_f("MonthCal_GetFirstDayOfWeek", [](HWND hwnd)->auto { return MonthCal_GetFirstDayOfWeek(hwnd); }),
        xlb_f("MonthCal_GetMaxSelCount", [](HWND hwnd)->auto { return MonthCal_GetMaxSelCount(hwnd); }),
        xlb_f("MonthCal_GetMaxTodayWidth", [](HWND hwnd)->auto { return MonthCal_GetMaxTodayWidth(hwnd); }),
        xlb_f("MonthCal_GetMinReqRect", [](HWND hwnd, LPRECT prc)->auto { return MonthCal_GetMinReqRect(hwnd, prc); }),
        xlb_f("MonthCal_GetMonthDelta", [](HWND hwnd)->auto { return MonthCal_GetMonthDelta(hwnd); }),
        xlb_f("MonthCal_GetMonthRange", [](HWND hwnd, DWORD gmr, LPSYSTEMTIME rgst)->auto { return MonthCal_GetMonthRange(hwnd, gmr, rgst); }),
        xlb_f("MonthCal_GetRange", [](HWND hwnd, LPSYSTEMTIME rgst)->auto { return MonthCal_GetRange(hwnd, rgst); }),
        xlb_f("MonthCal_GetSelRange", [](HWND hwnd, LPSYSTEMTIME rgst)->auto { return MonthCal_GetSelRange(hwnd, rgst); }),
        xlb_f("MonthCal_GetToday", [](HWND hwnd, LPSETUPHOOKPROC pst)->auto { return MonthCal_GetToday(hwnd, pst); }),
        xlb_f("MonthCal_GetUnicodeFormat", [](HWND hwnd)->auto { return MonthCal_GetUnicodeFormat(hwnd); }),
        xlb_f("MonthCal_HitTest", [](HWND hwnd, PMCHITTESTINFO pinfo)->auto { return MonthCal_HitTest(hwnd, pinfo); }),
        xlb_f("MonthCal_SetCalendarBorder", [](HWND hwnd, BOOL fset, int xyborder)->auto { return MonthCal_SetCalendarBorder(hwnd, fset, xyborder); }),
        xlb_f("MonthCal_SetCALID", [](HWND hwnd, UINT calid)->auto { return MonthCal_SetCALID(hwnd, calid); }),
        xlb_f("MonthCal_SetColor", [](HWND hwnd, INT iCol, COLORREF clr)->auto { return MonthCal_SetColor(hwnd, iCol, clr); }),
        xlb_f("MonthCal_SetCurrentView", [](HWND hwnd, DWORD dwNewView)->auto { return MonthCal_SetCurrentView(hwnd, dwNewView); }),
        xlb_f("MonthCal_SetCurSel", [](HWND hwnd, LPSYSTEMTIME pst)->auto { return MonthCal_SetCurSel(hwnd, pst); }),
        xlb_f("MonthCal_SetDayState", [](HWND hwnd, INT cbds, LPMONTHDAYSTATE rgds)->auto { return MonthCal_SetDayState(hwnd, cbds, rgds); }),
        xlb_f("MonthCal_SetFirstDayOfWeek", [](HWND hwnd, INT iDay)->auto { return MonthCal_SetFirstDayOfWeek(hwnd, iDay); }),
        xlb_f("MonthCal_SetMaxSelCount", [](HWND hwnd, UINT n)->auto { return MonthCal_SetMaxSelCount(hwnd, n); }),
        xlb_f("MonthCal_SetMonthDelta", [](HWND hwnd, INT n)->auto { return MonthCal_SetMonthDelta(hwnd, n); }),
        xlb_f("MonthCal_SetRange", [](HWND hwnd, DWORD gd, LPSYSTEMTIME rgst)->auto { return MonthCal_SetRange(hwnd, gd, rgst); }),
        xlb_f("MonthCal_SetSelRange", [](HWND hwnd, LPSYSTEMTIME rgst)->auto { return MonthCal_SetSelRange(hwnd, rgst); }),
        xlb_f("MonthCal_SetToday", [](HWND hwnd, LPSYSTEMTIME pst)->auto { return MonthCal_SetToday(hwnd, pst); }),
        xlb_f("MonthCal_SetUnicodeFormat", [](HWND hwnd, BOOL fUnicode)->auto { return MonthCal_SetUnicodeFormat(hwnd, fUnicode); }),
        xlb_f("MonthCal_SizeRectToMin", [](HWND hwnd, LPRECT prc)->auto { return MonthCal_SizeRectToMin(hwnd, prc); }),
        
        xlb_const("MCSC_BACKGROUND", MCSC_BACKGROUND),
        xlb_const("MCSC_MONTHBK", MCSC_MONTHBK),
        xlb_const("MCSC_TEXT", MCSC_TEXT),
        xlb_const("MCSC_TITLEBK", MCSC_TITLEBK),
        xlb_const("MCSC_TITLETEXT", MCSC_TITLETEXT),
        xlb_const("MCSC_TRAILINGTEXT", MCSC_TRAILINGTEXT),
        xlb_const("GMR_DAYSTATE", GMR_DAYSTATE),
        xlb_const("GMR_VISIBLE", GMR_VISIBLE),
        xlb_const("MCSC_BACKGROUND", MCSC_BACKGROUND),
        xlb_const("MCSC_MONTHBK", MCSC_MONTHBK),
        xlb_const("MCSC_TEXT", MCSC_TEXT),
        xlb_const("MCSC_TITLEBK", MCSC_TITLEBK),
        xlb_const("MCSC_TITLETEXT", MCSC_TITLETEXT),
        xlb_const("MCSC_TRAILINGTEXT", MCSC_TRAILINGTEXT),
        xlb_const("MCMV_MONTH", MCMV_MONTH),
        xlb_const("MCMV_YEAR", MCMV_YEAR),
        xlb_const("MCMV_DECADE", MCMV_DECADE),
        xlb_const("MCMV_CENTURY", MCMV_CENTURY),
        xlb_const("GDTR_MAX", GDTR_MAX),
        xlb_const("GDTR_MIN", GDTR_MIN),

        xlb_const("MCM_GETCALENDARBORDER", MCM_GETCALENDARBORDER),
        xlb_const("MCM_GETCALENDARCOUNT", MCM_GETCALENDARCOUNT),
        xlb_const("MCM_GETCALENDARGRIDINFO", MCM_GETCALENDARGRIDINFO),
        xlb_const("MCM_GETCALID", MCM_GETCALID),
        xlb_const("MCM_GETCOLOR", MCM_GETCOLOR),
        xlb_const("MCM_GETCURRENTVIEW", MCM_GETCURRENTVIEW),
        xlb_const("MCM_GETCURSEL", MCM_GETCURSEL),
        xlb_const("MCM_GETFIRSTDAYOFWEEK", MCM_GETFIRSTDAYOFWEEK),
        xlb_const("MCM_GETMAXSELCOUNT", MCM_GETMAXSELCOUNT),
        xlb_const("MCM_GETMAXTODAYWIDTH", MCM_GETMAXTODAYWIDTH),
        xlb_const("MCM_GETMINREQRECT", MCM_GETMINREQRECT),
        xlb_const("MCM_GETMONTHDELTA", MCM_GETMONTHDELTA),
        xlb_const("MCM_GETMONTHRANGE", MCM_GETMONTHRANGE),
        xlb_const("MCM_GETRANGE", MCM_GETRANGE),
        xlb_const("MCM_GETSELRANGE", MCM_GETSELRANGE),
        xlb_const("MCM_GETTODAY", MCM_GETTODAY),
        xlb_const("MCM_GETUNICODEFORMAT", MCM_GETUNICODEFORMAT),
        xlb_const("MCM_HITTEST", MCM_HITTEST),
        xlb_const("MCM_SETCALENDARBORDER", MCM_SETCALENDARBORDER),
        xlb_const("MCM_SETCALID", MCM_SETCALID),
        xlb_const("MCM_SETCOLOR", MCM_SETCOLOR),
        xlb_const("MCM_SETCURRENTVIEW", MCM_SETCURRENTVIEW),
        xlb_const("MCM_SETCURSEL", MCM_SETCURSEL),
        xlb_const("MCM_SETDAYSTATE", MCM_SETDAYSTATE),
        xlb_const("MCM_SETFIRSTDAYOFWEEK", MCM_SETFIRSTDAYOFWEEK),
        xlb_const("MCM_SETMAXSELCOUNT", MCM_SETMAXSELCOUNT),
        xlb_const("MCM_SETMONTHDELTA", MCM_SETMONTHDELTA),
        xlb_const("MCM_SETRANGE", MCM_SETRANGE),
        xlb_const("MCM_SETSELRANGE", MCM_SETSELRANGE),
        xlb_const("MCM_SETTODAY", MCM_SETTODAY),
        xlb_const("MCM_SETUNICODEFORMAT", MCM_SETUNICODEFORMAT),
        xlb_const("MCM_SIZERECTTOMIN", MCM_SIZERECTTOMIN),
        xlb_const("MCN_GETDAYSTATE", MCN_GETDAYSTATE),
        xlb_const("MCN_SELCHANGE", MCN_SELCHANGE),
        xlb_const("MCN_SELECT", MCN_SELECT),
        xlb_const("MCN_VIEWCHANGE", MCN_VIEWCHANGE),
        xlb_const("NM_RELEASEDCAPTURE", NM_RELEASEDCAPTURE),
        
        xlb_const("MCS_DAYSTATE", MCS_DAYSTATE),
        xlb_const("MCS_MULTISELECT", MCS_MULTISELECT),
        xlb_const("MCS_WEEKNUMBERS", MCS_WEEKNUMBERS),
        xlb_const("MCS_NOTODAYCIRCLE", MCS_NOTODAYCIRCLE),
        xlb_const("MCS_NOTODAY", MCS_NOTODAY),
        xlb_const("MCS_NOTRAILINGDATES", MCS_NOTRAILINGDATES),
        xlb_const("MCS_SHORTDAYSOFWEEK", MCS_SHORTDAYSOFWEEK),
        xlb_const("MCS_NOSELCHANGEONNAV", MCS_NOSELCHANGEONNAV),

        xlb_const("MCHT_CALENDARBK", MCHT_CALENDARBK),
        xlb_const("MCHT_CALENDARCONTROL", MCHT_CALENDARCONTROL),
        xlb_const("MCHT_CALENDARDATE", MCHT_CALENDARDATE),
        xlb_const("MCHT_CALENDARDATEMIN", MCHT_CALENDARDATEMIN),
        xlb_const("MCHT_CALENDARDATEMAX", MCHT_CALENDARDATEMAX),
        xlb_const("MCHT_CALENDARDATENEXT", MCHT_CALENDARDATENEXT),
        xlb_const("MCHT_CALENDARDATEPREV", MCHT_CALENDARDATEPREV),
        xlb_const("MCHT_CALENDARDAY", MCHT_CALENDARDAY),
        xlb_const("MCHT_CALENDARWEEKNUM", MCHT_CALENDARWEEKNUM),
        xlb_const("MCHT_NOWHERE", MCHT_NOWHERE),
        xlb_const("MCHT_TITLEBK", MCHT_TITLEBK),
        xlb_const("MCHT_TITLEBTNNEXT", MCHT_TITLEBTNNEXT),
        xlb_const("MCHT_TITLEBTNPREV", MCHT_TITLEBTNPREV),
        xlb_const("MCHT_TITLEMONTH", MCHT_TITLEMONTH),
        xlb_const("MCHT_TITLEYEAR", MCHT_TITLEYEAR),
        

    xlb_class<MCGRIDINFO>("MCGRIDINFO") .constructor<>() .destructor()
        .property("cbSize", &MCGRIDINFO::cbSize)
        .property("dwPart", &MCGRIDINFO::dwPart)
        .property("dwFlags", &MCGRIDINFO::dwFlags)
        .property("iCalendar", &MCGRIDINFO::iCalendar)
        .property("iRow", &MCGRIDINFO::iRow)
        .property("iCol", &MCGRIDINFO::iCol)
        .property("bSelected", &MCGRIDINFO::bSelected)
        .property("stStart", &MCGRIDINFO::stStart)
        .property("stEnd", &MCGRIDINFO::stEnd)
        .property("rc", &MCGRIDINFO::rc)
        .property("pszName", &MCGRIDINFO::pszName)
        .property("cchName", &MCGRIDINFO::cchName)
        ,

    xlb_class<MCHITTESTINFO>("MCHITTESTINFO") .constructor<>() .destructor()
        .property("cbSize", &MCHITTESTINFO::cbSize)
        .property("pt", &MCHITTESTINFO::pt)
        .property("uHit", &MCHITTESTINFO::uHit)
        .property("st", &MCHITTESTINFO::st)
        .property("rc", &MCHITTESTINFO::rc)
        .property("iOffset", &MCHITTESTINFO::iOffset)
        .property("iRow", &MCHITTESTINFO::iRow)
        .property("iCol", &MCHITTESTINFO::iCol)
        ,

    xlb_class<NMDAYSTATE>("NMDAYSTATE") .constructor<>() .destructor()
        .property("nmhdr", &NMDAYSTATE::nmhdr)
        .property("stStart", &NMDAYSTATE::stStart)
        .property("cDayState", &NMDAYSTATE::cDayState)
        .property("prgDayState", &NMDAYSTATE::prgDayState)
        ,

    xlb_class<NMSELCHANGE>("NMSELCHANGE") .constructor<>() .destructor()
        .property("nmhdr", &NMSELCHANGE::nmhdr)
        .property("stSelStart", &NMSELCHANGE::stSelStart)
        .property("stSelEnd", &NMSELCHANGE::stSelEnd)
        ,
        
    xlb_class<NMVIEWCHANGE>("NMVIEWCHANGE") .constructor<>() .destructor()
        .property("nmhdr", &NMVIEWCHANGE::nmhdr)
        .property("dwOldView", &NMVIEWCHANGE::dwOldView)
        .property("dwNewView", &NMVIEWCHANGE::dwNewView)
        ,

    // Pager
    xlb_f("Pager_ForwardMouse", [](HWND hwnd, BOOL fFoward)->auto { return Pager_ForwardMouse(hwnd, fFoward); }),
    xlb_f("Pager_GetBkColor", [](HWND hwnd)->auto { return Pager_GetBkColor(hwnd); }),
    xlb_f("Pager_GetBorder", [](HWND hwnd)->auto { return Pager_GetBorder(hwnd); }),
    xlb_f("Pager_GetButtonSize", [](HWND hwnd)->auto { return Pager_GetButtonSize(hwnd); }),
    xlb_f("Pager_GetButtonState", [](HWND hwnd, int iButton)->auto { return Pager_GetButtonState(hwnd, iButton); }),
    xlb_f("Pager_GetDropTarget", [](HWND hwnd, IDropTarget** ppdt)->auto { return Pager_GetDropTarget(hwnd, ppdt); }),
    xlb_f("Pager_GetPos", [](HWND hwnd)->auto { return Pager_GetPos(hwnd); }),
    xlb_f("Pager_RecalcSize", [](HWND hwnd)->auto { return Pager_RecalcSize(hwnd); }),
    xlb_f("Pager_SetBkColor", [](HWND hwnd, COLORREF clr)->auto { return Pager_SetBkColor(hwnd, clr); }),
    xlb_f("Pager_SetBorder", [](HWND hwnd, int iBorder)->auto { return Pager_SetBorder(hwnd, iBorder); }),
    xlb_f("Pager_SetButtonSize", [](HWND hwnd, int iSize)->auto { return Pager_SetButtonSize(hwnd, iSize); }),
    xlb_f("Pager_SetChild", [](HWND hwnd, HWND hwndChild)->auto { return Pager_SetChild(hwnd, hwndChild); }),
    xlb_f("Pager_SetPos", [](HWND hwnd, int iPos)->auto { return Pager_SetPos(hwnd, iPos); }),
    xlb_f("Pager_SetScrollInfo", [](HWND hwnd, UINT cTimeOut, UINT cLinesPer, UINT cPixelsPerLine)->auto { return Pager_SetScrollInfo(hwnd, cTimeOut, cLinesPer, cPixelsPerLine); }),

    xlb_class<NMPGCALCSIZE>("NMPGCALCSIZE") .constructor<>() .destructor()
        .property("hdr", &NMPGCALCSIZE::hdr)
        .property("dwFlag", &NMPGCALCSIZE::dwFlag)
        .property("iWidth", &NMPGCALCSIZE::iWidth)
        .property("iHeight", &NMPGCALCSIZE::iHeight)
        ,

    xlb_class<NMPGHOTITEM>("NMPGHOTITEM") .constructor<>() .destructor()
        .property("hdr", &NMPGHOTITEM::hdr)
        .property("idOld", &NMPGHOTITEM::idOld)
        .property("idNew", &NMPGHOTITEM::idNew)
        .property("dwFlags", &NMPGHOTITEM::dwFlags)
        ,
    xlb_class<NMPGSCROLL>("NMPGSCROLL") .constructor<>() .destructor()
        .property("hdr", &NMPGSCROLL::hdr)
        .property("fwKeys", &NMPGSCROLL::fwKeys)
        .property("rcParent", &NMPGSCROLL::rcParent)
        .property("iDir", &NMPGSCROLL::iDir)
        .property("iXpos", &NMPGSCROLL::iXpos)
        .property("iYpos", &NMPGSCROLL::iYpos)
        .property("iScroll", &NMPGSCROLL::iScroll)
        ,

    xlb_const("PGM_FORWARDMOUSE", PGM_FORWARDMOUSE),
    xlb_const("PGM_GETBKCOLOR", PGM_GETBKCOLOR),
    xlb_const("PGM_GETBORDER", PGM_GETBORDER),
    xlb_const("PGM_GETBUTTONSIZE", PGM_GETBUTTONSIZE),
    xlb_const("PGM_GETBUTTONSTATE", PGM_GETBUTTONSTATE),
    xlb_const("PGM_GETDROPTARGET", PGM_GETDROPTARGET),
    xlb_const("PGM_GETPOS", PGM_GETPOS),
    xlb_const("PGM_RECALCSIZE", PGM_RECALCSIZE),
    xlb_const("PGM_SETBKCOLOR", PGM_SETBKCOLOR),
    xlb_const("PGM_SETBORDER", PGM_SETBORDER),
    xlb_const("PGM_SETBUTTONSIZE", PGM_SETBUTTONSIZE),
    xlb_const("PGM_SETCHILD", PGM_SETCHILD),
    xlb_const("PGM_SETPOS", PGM_SETPOS),
    xlb_const("PGM_SETSCROLLINFO", PGM_SETSCROLLINFO),
    xlb_const("NM_RELEASEDCAPTURE", NM_RELEASEDCAPTURE),
    xlb_const("PGN_CALCSIZE", PGN_CALCSIZE),
    xlb_const("PGN_HOTITEMCHANGE", PGN_HOTITEMCHANGE),
    xlb_const("PGN_SCROLL", PGN_SCROLL),
    xlb_const("NM_RELEASEDCAPTURE", NM_RELEASEDCAPTURE),
    xlb_const("PGN_CALCSIZE", PGN_CALCSIZE),
    xlb_const("PGN_HOTITEMCHANGE", PGN_HOTITEMCHANGE),
    xlb_const("PGN_SCROLL", PGN_SCROLL),
    xlb_const("PGF_CALCHEIGHT", PGF_CALCHEIGHT),
    xlb_const("PGF_CALCWIDTH", PGF_CALCWIDTH),
    xlb_const("HICF_ENTERING", HICF_ENTERING),
    xlb_const("HICF_LEAVING", HICF_LEAVING),
    xlb_const("PGK_SHIFT", PGK_SHIFT),
    xlb_const("PGK_CONTROL", PGK_CONTROL),
    xlb_const("PGK_MENU", PGK_MENU),
    xlb_const("PGF_SCROLLDOWN", PGF_SCROLLDOWN),
    xlb_const("PGF_SCROLLLEFT", PGF_SCROLLLEFT),
    xlb_const("PGF_SCROLLRIGHT", PGF_SCROLLRIGHT),
    xlb_const("PGF_SCROLLUP", PGF_SCROLLUP),

    // Progress Bar
    xlb_class<PBRANGE>("PBRANGE") .constructor<>() .destructor()
        .property("iLow", &PBRANGE::iLow)
        .property("iHigh", &PBRANGE::iHigh)
        ,

    xlb_const("PBM_DELTAPOS", PBM_DELTAPOS),
    xlb_const("PBM_GETBARCOLOR", PBM_GETBARCOLOR),
    xlb_const("PBM_GETBKCOLOR", PBM_GETBKCOLOR),
    xlb_const("PBM_GETPOS", PBM_GETPOS),
    xlb_const("PBM_GETRANGE", PBM_GETRANGE),
    xlb_const("PBM_GETSTATE", PBM_GETSTATE),
    xlb_const("PBM_GETSTEP", PBM_GETSTEP),
    xlb_const("PBM_SETBARCOLOR", PBM_SETBARCOLOR),
    xlb_const("PBM_SETBKCOLOR", PBM_SETBKCOLOR),
    xlb_const("PBM_SETMARQUEE", PBM_SETMARQUEE),
    xlb_const("PBM_SETPOS", PBM_SETPOS),
    xlb_const("PBM_SETRANGE", PBM_SETRANGE),
    xlb_const("PBM_SETRANGE32", PBM_SETRANGE32),
    xlb_const("PBM_SETSTATE", PBM_SETSTATE),
    xlb_const("PBM_SETSTEP", PBM_SETSTEP),
    xlb_const("PBM_STEPIT", PBM_STEPIT),
    xlb_const("PBS_MARQUEE", PBS_MARQUEE),
    xlb_const("PBS_SMOOTH", PBS_SMOOTH),
    xlb_const("PBS_SMOOTHREVERSE", PBS_SMOOTHREVERSE),
    xlb_const("PBS_VERTICAL", PBS_VERTICAL),

    // Property Sheet
    xlb_const("PSM_ADDPAGE", PSM_ADDPAGE),
    xlb_const("PSM_APPLY", PSM_APPLY),
    xlb_const("PSM_CANCELTOCLOSE", PSM_CANCELTOCLOSE),
    xlb_const("PSM_CHANGED", PSM_CHANGED),
    xlb_const("PSM_ENABLEWIZBUTTONS", PSM_ENABLEWIZBUTTONS),
    xlb_const("PSM_GETCURRENTPAGEHWND", PSM_GETCURRENTPAGEHWND),
    xlb_const("PSM_GETRESULT", PSM_GETRESULT),
    xlb_const("PSM_GETTABCONTROL", PSM_GETTABCONTROL),
    xlb_const("PSM_HWNDTOINDEX", PSM_HWNDTOINDEX),
    xlb_const("PSM_IDTOINDEX", PSM_IDTOINDEX),
    xlb_const("PSM_INDEXTOHWND", PSM_INDEXTOHWND),
    xlb_const("PSM_INDEXTOID", PSM_INDEXTOID),
    xlb_const("PSM_INDEXTOPAGE", PSM_INDEXTOPAGE),
    xlb_const("PSM_INSERTPAGE", PSM_INSERTPAGE),
    xlb_const("PSM_ISDIALOGMESSAGE", PSM_ISDIALOGMESSAGE),
    xlb_const("PSM_PAGETOINDEX", PSM_PAGETOINDEX),
    xlb_const("PSM_PRESSBUTTON", PSM_PRESSBUTTON),
    xlb_const("PSM_QUERYSIBLINGS", PSM_QUERYSIBLINGS),
    xlb_const("PSM_REBOOTSYSTEM", PSM_REBOOTSYSTEM),
    xlb_const("PSM_RECALCPAGESIZES", PSM_RECALCPAGESIZES),
    xlb_const("PSM_REMOVEPAGE", PSM_REMOVEPAGE),
    xlb_const("PSM_RESTARTWINDOWS", PSM_RESTARTWINDOWS),
    xlb_const("PSM_SETBUTTONTEXT", PSM_SETBUTTONTEXT),
    xlb_const("PSM_SETCURSEL", PSM_SETCURSEL),
    xlb_const("PSM_SETCURSELID", PSM_SETCURSELID),
    xlb_const("PSM_SETFINISHTEXT", PSM_SETFINISHTEXT),
    //xlb_const("PSM_SETHEADERBITMAP", PSM_SETHEADERBITMAP), // not implemented
    //xlb_const("PSM_SETHEADERBITMAPRESOURCE", PSM_SETHEADERBITMAPRESOURCE), // not implemented
    xlb_const("PSM_SETHEADERSUBTITLE", PSM_SETHEADERSUBTITLE),
    xlb_const("PSM_SETHEADERTITLE", PSM_SETHEADERTITLE),
    xlb_const("PSM_SETNEXTTEXT", PSM_SETNEXTTEXT),
    xlb_const("PSM_SETTITLE", PSM_SETTITLE),
    xlb_const("PSM_SETWIZBUTTONS", PSM_SETWIZBUTTONS),
    xlb_const("PSM_SHOWWIZBUTTONS", PSM_SHOWWIZBUTTONS),
    xlb_const("PSM_UNCHANGED", PSM_UNCHANGED),
    xlb_const("PSN_APPLY", PSN_APPLY),
    xlb_const("PSN_GETOBJECT", PSN_GETOBJECT),
    xlb_const("PSN_HELP", PSN_HELP),
    xlb_const("PSN_KILLACTIVE", PSN_KILLACTIVE),
    xlb_const("PSN_QUERYCANCEL", PSN_QUERYCANCEL),
    xlb_const("PSN_QUERYINITIALFOCUS", PSN_QUERYINITIALFOCUS),
    xlb_const("PSN_RESET", PSN_RESET),
    xlb_const("PSN_SETACTIVE", PSN_SETACTIVE),
    xlb_const("PSN_TRANSLATEACCELERATOR", PSN_TRANSLATEACCELERATOR),
    xlb_const("PSN_WIZBACK", PSN_WIZBACK),
    xlb_const("PSN_WIZFINISH", PSN_WIZFINISH),
    xlb_const("PSN_WIZNEXT", PSN_WIZNEXT),
    xlb_const("ID_PSREBOOTSYSTEM", ID_PSREBOOTSYSTEM),
    xlb_const("ID_PSRESTARTWINDOWS", ID_PSRESTARTWINDOWS),

    xlb_class<xlb_cbf<LPFNADDPROPSHEETPAGE>>("LPFNADDPROPSHEETPAGE").constructor<xlb_luafunc>(),
    xlb_f("CreatePropertySheetPage", CreatePropertySheetPage),
    xlb_f("DestroyPropertySheetPage", DestroyPropertySheetPage),
    xlb_f("PropertySheet", PropertySheet),
    xlb_class<xlb_cbf<LPFNPSPCALLBACKA>>("LPFNPSPCALLBACKA").constructor<xlb_luafunc>(),
    xlb_class<xlb_cbf<PFNPROPSHEETCALLBACK>>("PFNPROPSHEETCALLBACK").constructor<xlb_luafunc>(),

    xlb_class<PROPSHEETHEADERA_V2>("PROPSHEETHEADERA_V2") .constructor<>() .destructor()
        .property("hbmWatermark", &PROPSHEETHEADERA_V2::hbmWatermark)
        .property("pszbmWatermark", &PROPSHEETHEADERA_V2::pszbmWatermark)
        .property("hbmHeader", &PROPSHEETHEADERA_V2::hbmHeader)
        .property("pszbmHeader", &PROPSHEETHEADERA_V2::pszbmHeader)
        ,

    xlb_class<PROPSHEETPAGEA_V2>("PROPSHEETPAGEA_V2") .constructor<>() .destructor()
        .property("pszHeaderTitle", &PROPSHEETPAGEA_V2::pszHeaderTitle)
        .property("pszHeaderSubTitle", &PROPSHEETPAGEA_V2::pszHeaderSubTitle)
        ,

    xlb_class<PSHNOTIFY>("PSHNOTIFY") .constructor<>() .destructor()
        .property("hdr", &PSHNOTIFY::hdr)
        .property("lParam", &PSHNOTIFY::lParam)
        ,

    // Rebar
    xlb_class<NMRBAUTOSIZE>("NMRBAUTOSIZE") .constructor<>() .destructor()
        .property("hdr", &NMRBAUTOSIZE::hdr)
        .property("fChanged", &NMRBAUTOSIZE::fChanged)
        .property("rcTarget", &NMRBAUTOSIZE::rcTarget)
        .property("rcActual", &NMRBAUTOSIZE::rcActual)
        ,

    xlb_class<NMREBAR>("NMREBAR") .constructor<>() .destructor()
        .property("hdr", &NMREBAR::hdr)
        .property("dwMask", &NMREBAR::dwMask)
        .property("uBand", &NMREBAR::uBand)
        .property("fStyle", &NMREBAR::fStyle)
        .property("wID", &NMREBAR::wID)
        .property("lParam", &NMREBAR::lParam)
        ,

    xlb_class<NMREBARAUTOBREAK>("NMREBARAUTOBREAK") .constructor<>() .destructor()
        .property("hdr", &NMREBARAUTOBREAK::hdr)
        .property("uBand", &NMREBARAUTOBREAK::uBand)
        .property("wID", &NMREBARAUTOBREAK::wID)
        .property("lParam", &NMREBARAUTOBREAK::lParam)
        .property("uMsg", &NMREBARAUTOBREAK::uMsg)
        .property("fStyleCurrent", &NMREBARAUTOBREAK::fStyleCurrent)
        .property("fAutoBreak", &NMREBARAUTOBREAK::fAutoBreak)
        ,

    xlb_class<NMREBARCHEVRON>("NMREBARCHEVRON") .constructor<>() .destructor()
        .property("hdr", &NMREBARCHEVRON::hdr)
        .property("uBand", &NMREBARCHEVRON::uBand)
        .property("wID", &NMREBARCHEVRON::wID)
        .property("lParam", &NMREBARCHEVRON::lParam)
        .property("rc", &NMREBARCHEVRON::rc)
        .property("lParamNM", &NMREBARCHEVRON::lParamNM)
        ,

    xlb_class<NMREBARCHILDSIZE>("NMREBARCHILDSIZE") .constructor<>() .destructor()
        .property("hdr", &NMREBARCHILDSIZE::hdr)
        .property("uBand", &NMREBARCHILDSIZE::uBand)
        .property("wID", &NMREBARCHILDSIZE::wID)
        .property("rcChild", &NMREBARCHILDSIZE::rcChild)
        .property("rcBand", &NMREBARCHILDSIZE::rcBand)
        ,
    xlb_class<NMREBARSPLITTER>("NMREBARSPLITTER") .constructor<>() .destructor()
        .property("hdr", &NMREBARSPLITTER::hdr)
        .property("rcSizing", &NMREBARSPLITTER::rcSizing)
        ,
    xlb_class<RBHITTESTINFO>("RBHITTESTINFO") .constructor<>() .destructor()
        .property("pt", &RBHITTESTINFO::pt)
        .property("flags", &RBHITTESTINFO::flags)
        .property("iBand", &RBHITTESTINFO::iBand)
        ,
    xlb_class<REBARBANDINFOA>("REBARBANDINFOA") .constructor<>() .destructor()
        .property("cbSize", &REBARBANDINFOA::cbSize)
        .property("fMask", &REBARBANDINFOA::fMask)
        .property("fStyle", &REBARBANDINFOA::fStyle)
        .property("clrFore", &REBARBANDINFOA::clrFore)
        .property("clrBack", &REBARBANDINFOA::clrBack)
        .property("lpText", &REBARBANDINFOA::lpText)
        .property("cch", &REBARBANDINFOA::cch)
        .property("iImage", &REBARBANDINFOA::iImage)
        .property("hwndChild", &REBARBANDINFOA::hwndChild)
        .property("cxMinChild", &REBARBANDINFOA::cxMinChild)
        .property("cyMinChild", &REBARBANDINFOA::cyMinChild)
        .property("cx", &REBARBANDINFOA::cx)
        .property("hbmBack", &REBARBANDINFOA::hbmBack)
        .property("wID", &REBARBANDINFOA::wID)
        .property("cyChild", &REBARBANDINFOA::cyChild)
        .property("cyMaxChild", &REBARBANDINFOA::cyMaxChild)
        .property("cyIntegral", &REBARBANDINFOA::cyIntegral)
        .property("cxIdeal", &REBARBANDINFOA::cxIdeal)
        .property("lParam", &REBARBANDINFOA::lParam)
        .property("cxHeader", &REBARBANDINFOA::cxHeader)
        .property("rcChevronLocation", &REBARBANDINFOA::rcChevronLocation)
        .property("uChevronState", &REBARBANDINFOA::uChevronState)
        ,
    xlb_class<REBARINFO>("REBARINFO") .constructor<>() .destructor()
        .property("cbSize", &REBARINFO::cbSize)
        .property("fMask", &REBARINFO::fMask)
        .property("himl", &REBARINFO::himl)
        .property("himl", &REBARINFO::himl)
        ,

        xlb_const("RBIM_IMAGELIST", RBIM_IMAGELIST),
        xlb_const("RB_BEGINDRAG", RB_BEGINDRAG),
        xlb_const("RB_DELETEBAND", RB_DELETEBAND),
        xlb_const("RB_DRAGMOVE", RB_DRAGMOVE),
        xlb_const("RB_ENDDRAG", RB_ENDDRAG),
        xlb_const("RB_GETBANDBORDERS", RB_GETBANDBORDERS),
        xlb_const("RB_GETBANDCOUNT", RB_GETBANDCOUNT),
        xlb_const("RB_GETBANDINFO", RB_GETBANDINFO),
        xlb_const("RB_GETBANDMARGINS", RB_GETBANDMARGINS),
        xlb_const("RB_GETBARHEIGHT", RB_GETBARHEIGHT),
        xlb_const("RB_GETBARINFO", RB_GETBARINFO),
        xlb_const("RB_GETBKCOLOR", RB_GETBKCOLOR),
        xlb_const("RB_GETCOLORSCHEME", RB_GETCOLORSCHEME),
        xlb_const("RB_GETDROPTARGET", RB_GETDROPTARGET),
        xlb_const("RB_GETEXTENDEDSTYLE", RB_GETEXTENDEDSTYLE),
        xlb_const("RB_GETPALETTE", RB_GETPALETTE),
        xlb_const("RB_GETRECT", RB_GETRECT),
        xlb_const("RB_GETROWCOUNT", RB_GETROWCOUNT),
        xlb_const("RB_GETROWHEIGHT", RB_GETROWHEIGHT),
        xlb_const("RB_GETTEXTCOLOR", RB_GETTEXTCOLOR),
        xlb_const("RB_GETTOOLTIPS", RB_GETTOOLTIPS),
        xlb_const("RB_GETUNICODEFORMAT", RB_GETUNICODEFORMAT),
        xlb_const("RB_HITTEST", RB_HITTEST),
        xlb_const("RB_IDTOINDEX", RB_IDTOINDEX),
        xlb_const("RB_INSERTBAND", RB_INSERTBAND),
        xlb_const("RB_MAXIMIZEBAND", RB_MAXIMIZEBAND),
        xlb_const("RB_MINIMIZEBAND", RB_MINIMIZEBAND),
        xlb_const("RB_MOVEBAND", RB_MOVEBAND),
        xlb_const("RB_PUSHCHEVRON", RB_PUSHCHEVRON),
        xlb_const("RB_SETBANDINFO", RB_SETBANDINFO),
        xlb_const("RB_SETBANDWIDTH", RB_SETBANDWIDTH),
        xlb_const("RB_SETBARINFO", RB_SETBARINFO),
        xlb_const("RB_SETBKCOLOR", RB_SETBKCOLOR),
        xlb_const("RB_SETCOLORSCHEME", RB_SETCOLORSCHEME),
        xlb_const("RB_SETEXTENDEDSTYLE", RB_SETEXTENDEDSTYLE),
        xlb_const("RB_SETPALETTE", RB_SETPALETTE),
        xlb_const("RB_SETPARENT", RB_SETPARENT),
        xlb_const("RB_SETTEXTCOLOR", RB_SETTEXTCOLOR),
        xlb_const("RB_SETTOOLTIPS", RB_SETTOOLTIPS),
        xlb_const("RB_SETUNICODEFORMAT", RB_SETUNICODEFORMAT),
        xlb_const("RB_SETWINDOWTHEME", RB_SETWINDOWTHEME),
        xlb_const("RB_SHOWBAND", RB_SHOWBAND),
        xlb_const("RB_SIZETORECT", RB_SIZETORECT),
        xlb_const("NM_CUSTOMDRAW", NM_CUSTOMDRAW),
        xlb_const("NM_NCHITTEST", NM_NCHITTEST),
        xlb_const("NM_RELEASEDCAPTURE", NM_RELEASEDCAPTURE),
        xlb_const("RBN_AUTOBREAK", RBN_AUTOBREAK),
        xlb_const("RBN_AUTOSIZE", RBN_AUTOSIZE),
        xlb_const("RBN_BEGINDRAG", RBN_BEGINDRAG),
        xlb_const("RBN_CHEVRONPUSHED", RBN_CHEVRONPUSHED),
        xlb_const("RBN_CHILDSIZE", RBN_CHILDSIZE),
        xlb_const("RBN_DELETEDBAND", RBN_DELETEDBAND),
        xlb_const("RBN_DELETINGBAND", RBN_DELETINGBAND),
        xlb_const("RBN_ENDDRAG", RBN_ENDDRAG),
        xlb_const("RBN_GETOBJECT", RBN_GETOBJECT),
        xlb_const("RBN_HEIGHTCHANGE", RBN_HEIGHTCHANGE),
        xlb_const("RBN_LAYOUTCHANGED", RBN_LAYOUTCHANGED),
        xlb_const("RBN_MINMAX", RBN_MINMAX),
        xlb_const("RBN_SPLITTERDRAG", RBN_SPLITTERDRAG),
        xlb_const("RBS_AUTOSIZE", RBS_AUTOSIZE),
        xlb_const("RBS_BANDBORDERS", RBS_BANDBORDERS),
        xlb_const("RBS_DBLCLKTOGGLE", RBS_DBLCLKTOGGLE),
        xlb_const("RBS_FIXEDORDER", RBS_FIXEDORDER),
        xlb_const("RBS_REGISTERDROP", RBS_REGISTERDROP),
        xlb_const("RBS_TOOLTIPS", RBS_TOOLTIPS),
        xlb_const("RBS_VARHEIGHT", RBS_VARHEIGHT),
        xlb_const("RBS_VERTICALGRIPPER", RBS_VERTICALGRIPPER),

        // Rich Edit
    xlb_class<BIDIOPTIONS>("BIDIOPTIONS") .constructor<>() .destructor()
            .property("cbSize", &BIDIOPTIONS::cbSize)
            .property("wMask", &BIDIOPTIONS::wMask)
            .property("wEffects", &BIDIOPTIONS::wEffects)
            ,
    xlb_class<CHARFORMATA>("CHARFORMATA") .constructor<>() .destructor()
            .property("cbSize", &CHARFORMATA::cbSize)
            .property("dwMask", &CHARFORMATA::dwMask)
            .property("dwEffects", &CHARFORMATA::dwEffects)
            .property("yHeight", &CHARFORMATA::yHeight)
            .property("yOffset", &CHARFORMATA::yOffset)
            .property("crTextColor", &CHARFORMATA::crTextColor)
            .property("bCharSet", &CHARFORMATA::bCharSet)
            .property("bPitchAndFamily", &CHARFORMATA::bPitchAndFamily)
            .property("szFaceName", &CHARFORMATA::szFaceName)
            ,
    xlb_class<CHARFORMAT2A>("CHARFORMAT2A") .constructor<>() .destructor()
            .property("wWeight", &CHARFORMAT2A::wWeight)
            .property("sSpacing", &CHARFORMAT2A::sSpacing)
            .property("crBackColor", &CHARFORMAT2A::crBackColor)
            .property("lcid", &CHARFORMAT2A::lcid)
            .property("dwReserved", &CHARFORMAT2A::dwReserved)
            .property("dwCookie", &CHARFORMAT2A::dwCookie)
            .property("dwReserved", &CHARFORMAT2A::dwReserved)
            .property("sStyle", &CHARFORMAT2A::sStyle)
            .property("wKerning", &CHARFORMAT2A::wKerning)
            .property("bUnderlineType", &CHARFORMAT2A::bUnderlineType)
            .property("bAnimation", &CHARFORMAT2A::bAnimation)
            .property("bRevAuthor", &CHARFORMAT2A::bRevAuthor)
            .property("bUnderlineColor", &CHARFORMAT2A::bUnderlineColor)
            ,
    xlb_class<CHARRANGE>("CHARRANGE") .constructor<>() .destructor()
            .property("cpMin", &CHARRANGE::cpMin)
            .property("cpMax", &CHARRANGE::cpMax)
            ,
    xlb_class<COMPCOLOR>("COMPCOLOR") .constructor<>() .destructor()
            .property("crText", &COMPCOLOR::crText)
            .property("crBackground", &COMPCOLOR::crBackground)
            .property("dwEffects", &COMPCOLOR::dwEffects)
            ,
    xlb_class<EDITSTREAM>("EDITSTREAM") .constructor<>() .destructor()
            .property("dwCookie", &EDITSTREAM::dwCookie)
            .property("dwError", &EDITSTREAM::dwError)
            .property("pfnCallback", &EDITSTREAM::pfnCallback)
            ,
    xlb_class<xlb_cbf<EDITSTREAMCALLBACK>>("EDITSTREAMCALLBACK").constructor<xlb_luafunc>(),
    xlb_class<ENCORRECTTEXT>("ENCORRECTTEXT") .constructor<>() .destructor()
            .property("nmhdr", &ENCORRECTTEXT::nmhdr)
            .property("chrg", &ENCORRECTTEXT::chrg)
            .property("seltyp", &ENCORRECTTEXT::seltyp)
            ,
    xlb_class<ENDROPFILES>("ENDROPFILES") .constructor<>() .destructor()
            .property("nmhdr", &ENDROPFILES::nmhdr)
            .property("hDrop", &ENDROPFILES::hDrop)
            .property("cp", &ENDROPFILES::cp)
            .property("fProtected", &ENDROPFILES::fProtected)
            ,
    xlb_class<ENLINK>("ENLINK") .constructor<>() .destructor()
            .property("nmhdr", &ENLINK::nmhdr)
            .property("msg", &ENLINK::msg)
            .property("wParam", &ENLINK::wParam)
            .property("lParam", &ENLINK::lParam)
            .property("chrg", &ENLINK::chrg)
            ,
    xlb_class<ENLOWFIRTF>("ENLOWFIRTF") .constructor<>() .destructor()
            .property("nmhdr", &ENLOWFIRTF::nmhdr)
            .property("szControl", &ENLOWFIRTF::szControl)
            ,
    xlb_class<ENOLEOPFAILED>("ENOLEOPFAILED") .constructor<>() .destructor()
            .property("nmhdr", &ENOLEOPFAILED::nmhdr)
            .property("iob", &ENOLEOPFAILED::iob)
            .property("lOper", &ENOLEOPFAILED::lOper)
            .property("hr", &ENOLEOPFAILED::hr)
            ,
    xlb_class<ENPROTECTED>("ENPROTECTED") .constructor<>() .destructor()
            .property("nmhdr", &ENPROTECTED::nmhdr)
            .property("msg", &ENPROTECTED::msg)
            .property("wParam", &ENPROTECTED::wParam)
            .property("lParam", &ENPROTECTED::lParam)
            .property("chrg", &ENPROTECTED::chrg)
            ,
    xlb_class<ENSAVECLIPBOARD>("ENSAVECLIPBOARD") .constructor<>() .destructor()
            .property("nmhdr", &ENSAVECLIPBOARD::nmhdr)
            .property("cObjectCount", &ENSAVECLIPBOARD::cObjectCount)
            .property("cch", &ENSAVECLIPBOARD::cch)
            ,
    xlb_class<FINDTEXTA>("FINDTEXTA") .constructor<>() .destructor()
            .property("chrg", &FINDTEXTA::chrg)
            .property("lpstrText", &FINDTEXTA::lpstrText)
            ,
    xlb_class<FINDTEXTEXA>("FINDTEXTEXA") .constructor<>() .destructor()
            .property("chrg", &FINDTEXTEXA::chrg)
            .property("lpstrText", &FINDTEXTEXA::lpstrText)
            .property("chrgText", &FINDTEXTEXA::chrgText)
            ,
    xlb_class<FORMATRANGE>("FORMATRANGE") .constructor<>() .destructor()
            .property("hdcTarget", &FORMATRANGE::hdcTarget)
            .property("hdc", &FORMATRANGE::hdc)
            .property("rc", &FORMATRANGE::rc)
            .property("rcPage", &FORMATRANGE::rcPage)
            .property("chrg", &FORMATRANGE::chrg)
            ,
    xlb_class<GETTEXTEX>("GETTEXTEX") .constructor<>() .destructor()
            .property("cb", &GETTEXTEX::cb)
            .property("flags", &GETTEXTEX::flags)
            .property("codepage", &GETTEXTEX::codepage)
            .property("lpDefaultChar", &GETTEXTEX::lpDefaultChar)
            .property("lpUsedDefChar", &GETTEXTEX::lpUsedDefChar)
            ,
    xlb_class<GETTEXTLENGTHEX>("GETTEXTLENGTHEX") .constructor<>() .destructor()
            .property("flags", &GETTEXTLENGTHEX::flags)
            .property("codepage", &GETTEXTLENGTHEX::codepage)
            ,
    xlb_class<HYPHENATEINFO>("HYPHENATEINFO") .constructor<>() .destructor()
            .property("cbSize", &HYPHENATEINFO::cbSize)
            .property("dxHyphenateZone", &HYPHENATEINFO::dxHyphenateZone)
            .property("pfnHyphenate", &HYPHENATEINFO::pfnHyphenate)
            ,
    xlb_class<xlb_cbf<decltype(HYPHENATEINFO::pfnHyphenate)>>("HyphenateProc").constructor<xlb_luafunc>(),
    xlb_class<HYPHRESULT>("HYPHRESULT") .constructor<>() .destructor()
            .property("khyph", &HYPHRESULT::khyph)
            .property("ichHyph", &HYPHRESULT::ichHyph)
            .property("chHyph", &HYPHRESULT::chHyph)
            ,
    xlb_class<IMECOMPTEXT>("IMECOMPTEXT") .constructor<>() .destructor()
            .property("cb", &IMECOMPTEXT::cb)
            .property("flags", &IMECOMPTEXT::flags)
            ,
    xlb_class<MSGFILTER>("MSGFILTER") .constructor<>() .destructor()
            .property("nmhdr", &MSGFILTER::nmhdr)
            .property("msg", &MSGFILTER::msg)
            .property("wParam", &MSGFILTER::wParam)
            .property("lParam", &MSGFILTER::lParam)
            ,
    xlb_class<OBJECTPOSITIONS>("OBJECTPOSITIONS") .constructor<>() .destructor()
            .property("nmhdr", &OBJECTPOSITIONS::nmhdr)
            .property("cObjectCount", &OBJECTPOSITIONS::cObjectCount)
            .property("pcpPositions", &OBJECTPOSITIONS::pcpPositions)
            ,
    xlb_class<PARAFORMAT>("PARAFORMAT") .constructor<>() .destructor()
            .property("cbSize", &PARAFORMAT::cbSize)
            .property("dwMask", &PARAFORMAT::dwMask)
            .property("wNumbering", &PARAFORMAT::wNumbering)
            .property("wReserved", &PARAFORMAT::wReserved)
            .property("wEffects", &PARAFORMAT::wEffects)
            .property("dxStartIndent", &PARAFORMAT::dxStartIndent)
            .property("dxRightIndent", &PARAFORMAT::dxRightIndent)
            .property("dxOffset", &PARAFORMAT::dxOffset)
            .property("wAlignment", &PARAFORMAT::wAlignment)
            .property("cTabCount", &PARAFORMAT::cTabCount)
            .property("rgxTabs", &PARAFORMAT::rgxTabs)
            ,
    xlb_class<PARAFORMAT2>("PARAFORMAT2") .constructor<>() .destructor()
            .property("dySpaceBefore", &PARAFORMAT2::dySpaceBefore)
            .property("dySpaceAfter", &PARAFORMAT2::dySpaceAfter)
            .property("dyLineSpacing", &PARAFORMAT2::dyLineSpacing)
            .property("sStyle", &PARAFORMAT2::sStyle)
            .property("bLineSpacingRule", &PARAFORMAT2::bLineSpacingRule)
            .property("bOutlineLevel", &PARAFORMAT2::bOutlineLevel)
            .property("wShadingWeight", &PARAFORMAT2::wShadingWeight)
            .property("wShadingStyle", &PARAFORMAT2::wShadingStyle)
            .property("wNumberingStart", &PARAFORMAT2::wNumberingStart)
            .property("wNumberingStyle", &PARAFORMAT2::wNumberingStyle)
            .property("wNumberingTab", &PARAFORMAT2::wNumberingTab)
            .property("wBorderSpace", &PARAFORMAT2::wBorderSpace)
            .property("wBorderWidth", &PARAFORMAT2::wBorderWidth)
            .property("wBorders", &PARAFORMAT2::wBorders)
            ,
    xlb_class<PUNCTUATION>("PUNCTUATION") .constructor<>() .destructor()
            .property("iSize", &PUNCTUATION::iSize)
            .property("szPunctuation", &PUNCTUATION::szPunctuation)
            ,
    xlb_class<REOBJECT>("REOBJECT") .constructor<>() .destructor()
            .property("cbStruct", &REOBJECT::cbStruct)
            .property("cp", &REOBJECT::cp)
            .property("clsid", &REOBJECT::clsid)
            .property("poleobj", &REOBJECT::poleobj)
            .property("pstg", &REOBJECT::pstg)
            .property("polesite", &REOBJECT::polesite)
            .property("sizel", &REOBJECT::sizel)
            .property("dvaspect", &REOBJECT::dvaspect)
            .property("dwFlags", &REOBJECT::dwFlags)
            .property("dwUser", &REOBJECT::dwUser)
            ,
    xlb_class<REPASTESPECIAL>("REPASTESPECIAL") .constructor<>() .destructor()
            .property("dwAspect", &REPASTESPECIAL::dwAspect)
            .property("dwParam", &REPASTESPECIAL::dwParam)
            ,
    xlb_class<REQRESIZE>("REQRESIZE") .constructor<>() .destructor()
            .property("nmhdr", &REQRESIZE::nmhdr)
            .property("rc", &REQRESIZE::rc)
            ,
    xlb_class<SELCHANGE>("SELCHANGE") .constructor<>() .destructor()
            .property("nmhdr", &SELCHANGE::nmhdr)
            .property("chrg", &SELCHANGE::chrg)
            .property("seltyp", &SELCHANGE::seltyp)
            ,
    xlb_class<SETTEXTEX>("SETTEXTEX") .constructor<>() .destructor()
            .property("flags", &SETTEXTEX::flags)
            .property("codepage", &SETTEXTEX::codepage)
            ,
    xlb_class<TEXTRANGEA>("TEXTRANGEA") .constructor<>() .destructor()
            .property("chrg", &TEXTRANGEA::chrg)
            .property("lpstrText", &TEXTRANGEA::lpstrText)
            ,

        xlb_const("SEL_TEXT", SEL_TEXT),
        xlb_const("SEL_OBJECT", SEL_OBJECT),
        xlb_const("SEL_MULTICHAR", SEL_MULTICHAR),
        xlb_const("SEL_MULTIOBJECT", SEL_MULTIOBJECT),
        xlb_const("EM_AUTOURLDETECT", EM_AUTOURLDETECT),
        xlb_const("EM_CANPASTE", EM_CANPASTE),
        xlb_const("EM_CANREDO", EM_CANREDO),
        xlb_const("EM_DISPLAYBAND", EM_DISPLAYBAND),
        xlb_const("EM_EXGETSEL", EM_EXGETSEL),
        xlb_const("EM_EXLIMITTEXT", EM_EXLIMITTEXT),
        xlb_const("EM_EXLINEFROMCHAR", EM_EXLINEFROMCHAR),
        xlb_const("EM_EXSETSEL", EM_EXSETSEL),
        xlb_const("EM_FINDTEXT", EM_FINDTEXT),
        xlb_const("EM_FINDTEXTEX", EM_FINDTEXTEX),
        xlb_const("EM_FINDTEXTEXW", EM_FINDTEXTEXW),
        xlb_const("EM_FINDTEXTW", EM_FINDTEXTW),
        xlb_const("EM_FINDWORDBREAK", EM_FINDWORDBREAK),
        xlb_const("EM_FORMATRANGE", EM_FORMATRANGE),
        xlb_const("EM_GETAUTOURLDETECT", EM_GETAUTOURLDETECT),
        xlb_const("EM_GETBIDIOPTIONS", EM_GETBIDIOPTIONS),
        xlb_const("EM_GETCHARFORMAT", EM_GETCHARFORMAT),
        xlb_const("EM_GETCTFMODEBIAS", EM_GETCTFMODEBIAS),
        xlb_const("EM_GETCTFOPENSTATUS", EM_GETCTFOPENSTATUS),
        xlb_const("EM_GETEDITSTYLE", EM_GETEDITSTYLE),
        xlb_const("EM_GETEVENTMASK", EM_GETEVENTMASK),
        xlb_const("EM_GETHYPHENATEINFO", EM_GETHYPHENATEINFO),
        xlb_const("EM_GETIMECOLOR", EM_GETIMECOLOR),
        xlb_const("EM_GETIMECOMPMODE", EM_GETIMECOMPMODE),
        xlb_const("EM_GETIMECOMPTEXT", EM_GETIMECOMPTEXT),
        xlb_const("EM_GETIMEMODEBIAS", EM_GETIMEMODEBIAS),
        xlb_const("EM_GETIMEOPTIONS", EM_GETIMEOPTIONS),
        xlb_const("EM_GETIMEPROPERTY", EM_GETIMEPROPERTY),
        xlb_const("EM_GETLANGOPTIONS", EM_GETLANGOPTIONS),
        xlb_const("EM_GETOLEINTERFACE", EM_GETOLEINTERFACE),
        xlb_const("EM_GETOPTIONS", EM_GETOPTIONS),
        xlb_const("EM_GETPAGEROTATE", EM_GETPAGEROTATE),
        xlb_const("EM_GETPARAFORMAT", EM_GETPARAFORMAT),
        xlb_const("EM_GETPUNCTUATION", EM_GETPUNCTUATION),
        xlb_const("EM_GETREDONAME", EM_GETREDONAME),
        xlb_const("EM_GETSCROLLPOS", EM_GETSCROLLPOS),
        xlb_const("EM_GETSELTEXT", EM_GETSELTEXT),
        xlb_const("EM_GETTEXTEX", EM_GETTEXTEX),
        xlb_const("EM_GETTEXTLENGTHEX", EM_GETTEXTLENGTHEX),
        xlb_const("EM_GETTEXTMODE", EM_GETTEXTMODE),
        xlb_const("EM_GETTEXTRANGE", EM_GETTEXTRANGE),
        xlb_const("EM_GETTYPOGRAPHYOPTIONS", EM_GETTYPOGRAPHYOPTIONS),
        xlb_const("EM_GETUNDONAME", EM_GETUNDONAME),
        xlb_const("EM_GETWORDBREAKPROCEX", EM_GETWORDBREAKPROCEX),
        xlb_const("EM_GETWORDWRAPMODE", EM_GETWORDWRAPMODE),
        xlb_const("EM_GETZOOM", EM_GETZOOM),
        xlb_const("EM_HIDESELECTION", EM_HIDESELECTION),
        xlb_const("EM_ISIME", EM_ISIME),
        xlb_const("EM_PASTESPECIAL", EM_PASTESPECIAL),
        xlb_const("EM_RECONVERSION", EM_RECONVERSION),
        xlb_const("EM_REDO", EM_REDO),
        xlb_const("EM_REQUESTRESIZE", EM_REQUESTRESIZE),
        xlb_const("EM_SELECTIONTYPE", EM_SELECTIONTYPE),
        xlb_const("EM_SETBIDIOPTIONS", EM_SETBIDIOPTIONS),
        xlb_const("EM_SETBKGNDCOLOR", EM_SETBKGNDCOLOR),
        xlb_const("EM_SETCHARFORMAT", EM_SETCHARFORMAT),
        xlb_const("EM_SETCTFMODEBIAS", EM_SETCTFMODEBIAS),
        xlb_const("EM_SETCTFOPENSTATUS", EM_SETCTFOPENSTATUS),
        xlb_const("EM_SETEDITSTYLE", EM_SETEDITSTYLE),
        xlb_const("EM_SETEVENTMASK", EM_SETEVENTMASK),
        xlb_const("EM_SETFONTSIZE", EM_SETFONTSIZE),
        xlb_const("EM_SETHYPHENATEINFO", EM_SETHYPHENATEINFO),
        xlb_const("EM_SETIMECOLOR", EM_SETIMECOLOR),
        xlb_const("EM_SETIMEMODEBIAS", EM_SETIMEMODEBIAS),
        xlb_const("EM_SETIMEOPTIONS", EM_SETIMEOPTIONS),
        xlb_const("EM_SETLANGOPTIONS", EM_SETLANGOPTIONS),
        xlb_const("EM_SETOLECALLBACK", EM_SETOLECALLBACK),
        xlb_const("EM_SETOPTIONS", EM_SETOPTIONS),
        xlb_const("EM_SETPAGEROTATE", EM_SETPAGEROTATE),
        xlb_const("EM_SETPALETTE", EM_SETPALETTE),
        xlb_const("EM_SETPARAFORMAT", EM_SETPARAFORMAT),
        xlb_const("EM_SETPUNCTUATION", EM_SETPUNCTUATION),
        xlb_const("EM_SETSCROLLPOS", EM_SETSCROLLPOS),
        xlb_const("EM_SETTARGETDEVICE", EM_SETTARGETDEVICE),
        xlb_const("EM_SETTEXTEX", EM_SETTEXTEX),
        xlb_const("EM_SETTEXTMODE", EM_SETTEXTMODE),
        xlb_const("EM_SETTYPOGRAPHYOPTIONS", EM_SETTYPOGRAPHYOPTIONS),
        xlb_const("EM_SETUNDOLIMIT", EM_SETUNDOLIMIT),
        xlb_const("EM_SETWORDBREAKPROCEX", EM_SETWORDBREAKPROCEX),
        xlb_const("EM_SETWORDWRAPMODE", EM_SETWORDWRAPMODE),
        xlb_const("EM_SETZOOM", EM_SETZOOM),
        xlb_const("EM_SHOWSCROLLBAR", EM_SHOWSCROLLBAR),
        xlb_const("EM_STOPGROUPTYPING", EM_STOPGROUPTYPING),
        xlb_const("EM_STREAMIN", EM_STREAMIN),
        xlb_const("EM_STREAMOUT", EM_STREAMOUT),
        xlb_const("EN_ALIGNLTR", EN_ALIGNLTR),
        xlb_const("EN_ALIGNRTL", EN_ALIGNRTL),
        xlb_const("EN_CORRECTTEXT", EN_CORRECTTEXT),
        xlb_const("EN_DRAGDROPDONE", EN_DRAGDROPDONE),
        xlb_const("EN_DROPFILES", EN_DROPFILES),
        xlb_const("EN_IMECHANGE", EN_IMECHANGE),
        xlb_const("EN_LINK", EN_LINK),
        xlb_const("EN_LOWFIRTF", EN_LOWFIRTF),
        xlb_const("EN_MSGFILTER", EN_MSGFILTER),
        xlb_const("EN_OBJECTPOSITIONS", EN_OBJECTPOSITIONS),
        xlb_const("EN_OLEOPFAILED", EN_OLEOPFAILED),
        xlb_const("EN_PROTECTED", EN_PROTECTED),
        xlb_const("EN_REQUESTRESIZE", EN_REQUESTRESIZE),
        xlb_const("EN_SAVECLIPBOARD", EN_SAVECLIPBOARD),
        xlb_const("EN_SELCHANGE", EN_SELCHANGE),
        xlb_const("EN_STOPNOUNDO", EN_STOPNOUNDO),
        xlb_const("ES_DISABLENOSCROLL", ES_DISABLENOSCROLL),
        xlb_const("ES_EX_NOCALLOLEINIT", ES_EX_NOCALLOLEINIT),
        xlb_const("ES_NOIME", ES_NOIME),
        xlb_const("ES_NOOLEDRAGDROP", ES_NOOLEDRAGDROP),
        xlb_const("ES_SAVESEL", ES_SAVESEL),
        xlb_const("ES_SELECTIONBAR", ES_SELECTIONBAR),
        xlb_const("ES_SELFIME", ES_SELFIME),
        xlb_const("ES_SUNKEN", ES_SUNKEN),
        xlb_const("ES_VERTICAL", ES_VERTICAL),
        xlb_const("ES_AUTOHSCROLL", ES_AUTOHSCROLL),
        xlb_const("ES_AUTOVSCROLL", ES_AUTOVSCROLL),
        xlb_const("ES_CENTER", ES_CENTER),
        xlb_const("ES_LEFT", ES_LEFT),
        xlb_const("ES_MULTILINE", ES_MULTILINE),
        xlb_const("ES_NOHIDESEL", ES_NOHIDESEL),
        xlb_const("ES_NUMBER", ES_NUMBER),
        xlb_const("ES_PASSWORD", ES_PASSWORD),
        xlb_const("ES_READONLY", ES_READONLY),
        xlb_const("ES_RIGHT", ES_RIGHT),
        xlb_const("ES_WANTRETURN", ES_WANTRETURN),
        xlb_const("ENM_CHANGE", ENM_CHANGE),
        xlb_const("ENM_CLIPFORMAT", ENM_CLIPFORMAT),
        xlb_const("ENM_CORRECTTEXT", ENM_CORRECTTEXT),
        xlb_const("ENM_DRAGDROPDONE", ENM_DRAGDROPDONE),
        xlb_const("ENM_DROPFILES", ENM_DROPFILES),
        xlb_const("ENM_IMECHANGE", ENM_IMECHANGE),
        xlb_const("ENM_KEYEVENTS", ENM_KEYEVENTS),
        xlb_const("ENM_LINK", ENM_LINK),
        xlb_const("ENM_LOWFIRTF", ENM_LOWFIRTF),
        xlb_const("ENM_MOUSEEVENTS", ENM_MOUSEEVENTS),
        xlb_const("ENM_OBJECTPOSITIONS", ENM_OBJECTPOSITIONS),
        xlb_const("ENM_PARAGRAPHEXPANDED", ENM_PARAGRAPHEXPANDED),
        xlb_const("ENM_PROTECTED", ENM_PROTECTED),
        xlb_const("ENM_REQUESTRESIZE", ENM_REQUESTRESIZE),
        xlb_const("ENM_SCROLL", ENM_SCROLL),
        xlb_const("ENM_SCROLLEVENTS", ENM_SCROLLEVENTS),
        xlb_const("ENM_SELCHANGE", ENM_SELCHANGE),
        xlb_const("ENM_UPDATE", ENM_UPDATE),
        xlb_const("REO_ALIGNTORIGHT", REO_ALIGNTORIGHT),
        xlb_const("REO_BELOWBASELINE", REO_BELOWBASELINE),
        xlb_const("REO_BLANK", REO_BLANK),
        xlb_const("REO_CANROTATE", REO_CANROTATE),
        xlb_const("REO_DONTNEEDPALETTE", REO_DONTNEEDPALETTE),
        xlb_const("REO_DYNAMICSIZE", REO_DYNAMICSIZE),
        xlb_const("REO_GETMETAFILE", REO_GETMETAFILE),
        xlb_const("REO_HILITED", REO_HILITED),
        xlb_const("REO_INPLACEACTIVE", REO_INPLACEACTIVE),
        xlb_const("REO_INVERTEDSELECT", REO_INVERTEDSELECT),
        xlb_const("REO_LINK", REO_LINK),
        xlb_const("REO_LINKAVAILABLE", REO_LINKAVAILABLE),
        xlb_const("REO_OPEN", REO_OPEN),
        xlb_const("REO_OWNERDRAWSELECT", REO_OWNERDRAWSELECT),
        xlb_const("REO_RESIZABLE", REO_RESIZABLE),
        xlb_const("REO_SELECTED", REO_SELECTED),
        xlb_const("REO_STATIC", REO_STATIC),
        xlb_const("REO_USEASBACKGROUND", REO_USEASBACKGROUND),
        xlb_const("REO_WRAPTEXTAROUND", REO_WRAPTEXTAROUND),

        // Scroll Bar
        xlb_f("EnableScrollBar", EnableScrollBar),
        xlb_f("GetScrollBarInfo", GetScrollBarInfo),
        xlb_f("GetScrollInfo", GetScrollInfo),
        xlb_f("GetScrollPos", GetScrollPos),
        xlb_f("GetScrollRange", GetScrollRange),
        xlb_f("ScrollDC", ScrollDC),
        xlb_f("ScrollWindow", ScrollWindow),
        xlb_f("ScrollWindowEx", ScrollWindowEx),
        xlb_f("SetScrollInfo", SetScrollInfo),
        xlb_f("SetScrollPos", SetScrollPos),
        xlb_f("SetScrollRange", SetScrollRange),
        xlb_f("ShowScrollBar", ShowScrollBar),
        
        xlb_class<SCROLLBARINFO>("SCROLLBARINFO") .constructor<>() .destructor()
            .property("cbSize", &SCROLLBARINFO::cbSize)
            .property("rcScrollBar", &SCROLLBARINFO::rcScrollBar)
            .property("dxyLineButton", &SCROLLBARINFO::dxyLineButton)
            .property("xyThumbTop", &SCROLLBARINFO::xyThumbTop)
            .property("xyThumbBottom", &SCROLLBARINFO::xyThumbBottom)
            .property("reserved", &SCROLLBARINFO::reserved)
            .property("rgstate", &SCROLLBARINFO::rgstate)
            ,
        xlb_class<SCROLLINFO>("SCROLLINFO") .constructor<>() .destructor()
            .property("cbSize", &SCROLLINFO::cbSize)
            .property("fMask", &SCROLLINFO::fMask)
            .property("nMin", &SCROLLINFO::nMin)
            .property("nMax", &SCROLLINFO::nMax)
            .property("nPage", &SCROLLINFO::nPage)
            .property("nPos", &SCROLLINFO::nPos)
            .property("nTrackPos", &SCROLLINFO::nTrackPos)
            ,

        xlb_const("SBM_ENABLE_ARROWS", SBM_ENABLE_ARROWS),
        xlb_const("SBM_GETPOS", SBM_GETPOS),
        xlb_const("SBM_GETRANGE", SBM_GETRANGE),
        xlb_const("SBM_GETSCROLLBARINFO", SBM_GETSCROLLBARINFO),
        xlb_const("SBM_GETSCROLLINFO", SBM_GETSCROLLINFO),
        xlb_const("SBM_SETPOS", SBM_SETPOS),
        xlb_const("SBM_SETRANGE", SBM_SETRANGE),
        xlb_const("SBM_SETRANGEREDRAW", SBM_SETRANGEREDRAW),
        xlb_const("SBM_SETSCROLLINFO", SBM_SETSCROLLINFO),
        xlb_const("WM_CTLCOLORSCROLLBAR", WM_CTLCOLORSCROLLBAR),
        xlb_const("WM_HSCROLL", WM_HSCROLL),
        xlb_const("WM_VSCROLL", WM_VSCROLL),
        xlb_const("SBS_BOTTOMALIGN", SBS_BOTTOMALIGN),
        xlb_const("SBS_HORZ", SBS_HORZ),
        xlb_const("SBS_LEFTALIGN", SBS_LEFTALIGN),
        xlb_const("SBS_RIGHTALIGN", SBS_RIGHTALIGN),
        xlb_const("SBS_SIZEBOX", SBS_SIZEBOX),
        xlb_const("SBS_SIZEBOXBOTTOMRIGHTALIGN", SBS_SIZEBOXBOTTOMRIGHTALIGN),
        xlb_const("SBS_SIZEBOXTOPLEFTALIGN", SBS_SIZEBOXTOPLEFTALIGN),
        xlb_const("SBS_SIZEGRIP", SBS_SIZEGRIP),
        xlb_const("SBS_TOPALIGN", SBS_TOPALIGN),
        xlb_const("SBS_VERT", SBS_VERT),
        xlb_const("STATE_SYSTEM_INVISIBLE", STATE_SYSTEM_INVISIBLE),
        xlb_const("STATE_SYSTEM_OFFSCREEN", STATE_SYSTEM_OFFSCREEN),
        xlb_const("STATE_SYSTEM_PRESSED", STATE_SYSTEM_PRESSED),
        xlb_const("STATE_SYSTEM_UNAVAILABLE", STATE_SYSTEM_UNAVAILABLE),
        xlb_const("SIF_ALL", SIF_ALL),
        xlb_const("SIF_DISABLENOSCROLL", SIF_DISABLENOSCROLL),
        xlb_const("SIF_PAGE", SIF_PAGE),
        xlb_const("SIF_POS", SIF_POS),
        xlb_const("SIF_RANGE", SIF_RANGE),
        xlb_const("SIF_TRACKPOS", SIF_TRACKPOS),

        // Static Control
        xlb_const("STM_GETICON", STM_GETICON),
        xlb_const("STM_GETIMAGE", STM_GETIMAGE),
        xlb_const("STM_SETICON", STM_SETICON),
        xlb_const("STM_SETIMAGE", STM_SETIMAGE),
        xlb_const("STN_CLICKED", STN_CLICKED),
        xlb_const("STN_DBLCLK", STN_DBLCLK),
        xlb_const("STN_DISABLE", STN_DISABLE),
        xlb_const("STN_ENABLE", STN_ENABLE),
        xlb_const("WM_CTLCOLORSTATIC", WM_CTLCOLORSTATIC),

        // Status Bar
        xlb_f("CreateStatusWindow", CreateStatusWindow),
        xlb_f("DrawStatusText", DrawStatusText),
        xlb_f("MenuHelp", MenuHelp),

        xlb_const("SB_GETBORDERS", SB_GETBORDERS),
        xlb_const("SB_GETICON", SB_GETICON),
        xlb_const("SB_GETPARTS", SB_GETPARTS),
        xlb_const("SB_GETRECT", SB_GETRECT),
        xlb_const("SB_GETTEXT", SB_GETTEXT),
        xlb_const("SB_GETTEXTLENGTH", SB_GETTEXTLENGTH),
        xlb_const("SB_GETTIPTEXT", SB_GETTIPTEXT),
        xlb_const("SB_GETUNICODEFORMAT", SB_GETUNICODEFORMAT),
        xlb_const("SB_ISSIMPLE", SB_ISSIMPLE),
        xlb_const("SB_SETBKCOLOR", SB_SETBKCOLOR),
        xlb_const("SB_SETICON", SB_SETICON),
        xlb_const("SB_SETMINHEIGHT", SB_SETMINHEIGHT),
        xlb_const("SB_SETPARTS", SB_SETPARTS),
        xlb_const("SB_SETTEXT", SB_SETTEXT),
        xlb_const("SB_SETTIPTEXT", SB_SETTIPTEXT),
        xlb_const("SB_SETUNICODEFORMAT", SB_SETUNICODEFORMAT),
        xlb_const("SB_SIMPLE", SB_SIMPLE),
        xlb_const("NM_CLICK", NM_CLICK),
        xlb_const("NM_DBLCLK", NM_DBLCLK),
        xlb_const("NM_RCLICK", NM_RCLICK),
        xlb_const("NM_RDBLCLK", NM_RDBLCLK),
        xlb_const("SBN_SIMPLEMODECHANGE", SBN_SIMPLEMODECHANGE),
        xlb_const("SBARS_SIZEGRIP", SBARS_SIZEGRIP),
        xlb_const("SBT_TOOLTIPS", SBT_TOOLTIPS),
        xlb_const("SBARS_TOOLTIPS", SBARS_TOOLTIPS),

        // SysLink
        xlb_class<NMLINK>("NMLINK") .constructor<>() .destructor()
            .property("hdr", &NMLINK::hdr)
            .property("item", &NMLINK::item)
            ,
        xlb_class<LITEM>("LITEM") .constructor<>() .destructor()
            .property("mask", &LITEM::mask)
            .property("iLink", &LITEM::iLink)
            .property("state", &LITEM::state)
            .property("stateMask", &LITEM::stateMask)
            .property("szID", &LITEM::szID)
            .property("szUrl", &LITEM::szUrl)
            ,
        xlb_class<LHITTESTINFO>("LHITTESTINFO") .constructor<>() .destructor()
            .property("pt", &LHITTESTINFO::pt)
            .property("item", &LHITTESTINFO::item)
            ,

        xlb_const("LM_GETIDEALHEIGHT", LM_GETIDEALHEIGHT),
        xlb_const("LM_GETIDEALSIZE", LM_GETIDEALSIZE),
        xlb_const("LM_GETITEM", LM_GETITEM),
        xlb_const("LM_HITTEST", LM_HITTEST),
        xlb_const("LM_SETITEM", LM_SETITEM),
        xlb_const("LIF_ITEMINDEX", LIF_ITEMINDEX),
        xlb_const("LIF_STATE", LIF_STATE),
        xlb_const("LIF_ITEMID", LIF_ITEMID),
        xlb_const("LIF_URL", LIF_URL),
        xlb_const("LIS_ENABLED", LIS_ENABLED),
        xlb_const("LIS_FOCUSED", LIS_FOCUSED),
        xlb_const("LIS_VISITED", LIS_VISITED),
        xlb_const("LIS_HOTTRACK", LIS_HOTTRACK),
        xlb_const("LIS_DEFAULTCOLORS", LIS_DEFAULTCOLORS),

        // Tab
        xlb_class<TCITEMHEADERA>("TCITEMHEADERA") .constructor<>() .destructor()
            .property("mask", &TCITEMHEADERA::mask)
            .property("lpReserved1", &TCITEMHEADERA::lpReserved1)
            .property("lpReserved2", &TCITEMHEADERA::lpReserved2)
            .property("pszText", &TCITEMHEADERA::pszText)
            .property("cchTextMax", &TCITEMHEADERA::cchTextMax)
            .property("iImage", &TCITEMHEADERA::iImage)
            ,

        xlb_class<TCITEMA>("TCITEMA") .constructor<>() .destructor()
            .property("mask", &TCITEMA::mask)
            .property("dwState", &TCITEMA::dwState)
            .property("dwStateMask", &TCITEMA::dwStateMask)
            .property("pszText", &TCITEMA::pszText)
            .property("cchTextMax", &TCITEMA::cchTextMax)
            .property("iImage", &TCITEMA::iImage)
            .property("lParam", &TCITEMA::lParam)
            ,
        xlb_class<TCHITTESTINFO>("TCHITTESTINFO") .constructor<>() .destructor()
            .property("pt", &TCHITTESTINFO::pt)
            .property("flags", &TCHITTESTINFO::flags)
            ,
        xlb_class<NMTCKEYDOWN>("NMTCKEYDOWN") .constructor<>() .destructor()
            .property("hdr", &NMTCKEYDOWN::hdr)
            .property("wVKey", &NMTCKEYDOWN::wVKey)
            .property("flags", &NMTCKEYDOWN::flags)
            ,

        xlb_f("TabCtrl_AdjustRect", [](HWND hwnd, BOOL bLarger, RECT* prc)->auto { return TabCtrl_AdjustRect(hwnd, bLarger, prc); }),
        xlb_f("TabCtrl_DeleteAllItems", [](HWND hwnd)->auto { return TabCtrl_DeleteAllItems(hwnd); }),
        xlb_f("TabCtrl_DeleteItem", [](HWND hwnd, int i)->auto { return TabCtrl_DeleteItem(hwnd, i); }),
        xlb_f("TabCtrl_DeselectAll", [](HWND hwnd, BOOL fExcludeFocus)->auto { return TabCtrl_DeselectAll(hwnd, fExcludeFocus); }),
        xlb_f("TabCtrl_GetCurFocus", [](HWND hwnd)->auto { return TabCtrl_GetCurFocus(hwnd); }),
        xlb_f("TabCtrl_GetCurSel", [](HWND hwnd)->auto { return TabCtrl_GetCurSel(hwnd); }),
        xlb_f("TabCtrl_GetExtendedStyle", [](HWND hwnd)->auto { return TabCtrl_GetExtendedStyle(hwnd); }),
        xlb_f("TabCtrl_GetImageList", [](HWND hwnd)->auto { return TabCtrl_GetImageList(hwnd); }),
        xlb_f("TabCtrl_GetItem", [](HWND hwnd, int iItem, LPTCITEM pitem)->auto { return TabCtrl_GetItem(hwnd, iItem, pitem); }),
        xlb_f("TabCtrl_GetItemCount", [](HWND hwnd)->auto { return TabCtrl_GetItemCount(hwnd); }),
        xlb_f("TabCtrl_GetItemRect", [](HWND hwnd, int i, RECT* prc)->auto { return TabCtrl_GetItemRect(hwnd, i, prc); }),
        xlb_f("TabCtrl_GetRowCount", [](HWND hwnd)->auto { return TabCtrl_GetRowCount(hwnd); }),
        xlb_f("TabCtrl_GetToolTips", [](HWND hwnd)->auto { return TabCtrl_GetToolTips(hwnd); }),
        xlb_f("TabCtrl_GetUnicodeFormat", [](HWND hwnd)->auto { return TabCtrl_GetUnicodeFormat(hwnd); }),
        xlb_f("TabCtrl_HighlightItem", [](HWND hwnd, INT i, WORD fHighlight)->auto { return TabCtrl_HighlightItem(hwnd, i, fHighlight); }),
        xlb_f("TabCtrl_HitTest", [](HWND hwnd, LPTCHITTESTINFO pinfo)->auto { return TabCtrl_HitTest(hwnd, pinfo); }),
        xlb_f("TabCtrl_InsertItem", [](HWND hwnd, int iItem, const LPTCITEM pitem)->auto { return TabCtrl_InsertItem(hwnd, iItem, pitem); }),
        xlb_f("TabCtrl_RemoveImage", [](HWND hwnd, int i)->auto { return TabCtrl_RemoveImage(hwnd, i); }),
        xlb_f("TabCtrl_SetCurFocus", [](HWND hwnd, int i)->auto { return TabCtrl_SetCurFocus(hwnd, i); }),
        xlb_f("TabCtrl_SetCurSel", [](HWND hwnd, int i)->auto { return TabCtrl_SetCurSel(hwnd, i); }),
        xlb_f("TabCtrl_SetExtendedStyle", [](HWND hwnd, DWORD dw)->auto { return TabCtrl_SetExtendedStyle(hwnd, dw); }),
        xlb_f("TabCtrl_SetImageList", [](HWND hwnd, HIMAGELIST himl)->auto { return TabCtrl_SetImageList(hwnd, himl); }),
        xlb_f("TabCtrl_SetItem", [](HWND hwnd, int iItem, LPTCITEM pitem)->auto { return TabCtrl_SetItem(hwnd, iItem, pitem); }),
        xlb_f("TabCtrl_SetItemExtra", [](HWND hwnd, int cb)->auto { return TabCtrl_SetItemExtra(hwnd, cb); }),
        xlb_f("TabCtrl_SetItemSize", [](HWND hwnd, int x, int y)->auto { return TabCtrl_SetItemSize(hwnd, x, y); }),
        xlb_f("TabCtrl_SetMinTabWidth", [](HWND hwnd, int x)->auto { return TabCtrl_SetMinTabWidth(hwnd, x); }),
        xlb_f("TabCtrl_SetPadding", [](HWND hwnd, int cx, int cy)->auto { return TabCtrl_SetPadding(hwnd, cx, cy); }),
        xlb_f("TabCtrl_SetToolTips", [](HWND hwnd, HWND hwndTT)->auto { return TabCtrl_SetToolTips(hwnd, hwndTT); }),
        xlb_f("TabCtrl_SetUnicodeFormat", [](HWND hwnd, BOOL fUnicode)->auto { return TabCtrl_SetUnicodeFormat(hwnd, fUnicode); }),

        xlb_const("TCM_ADJUSTRECT", TCM_ADJUSTRECT),
        xlb_const("TCM_DELETEALLITEMS", TCM_DELETEALLITEMS),
        xlb_const("TCM_DELETEITEM", TCM_DELETEITEM),
        xlb_const("TCM_DESELECTALL", TCM_DESELECTALL),
        xlb_const("TCM_GETCURFOCUS", TCM_GETCURFOCUS),
        xlb_const("TCM_GETCURSEL", TCM_GETCURSEL),
        xlb_const("TCM_GETEXTENDEDSTYLE", TCM_GETEXTENDEDSTYLE),
        xlb_const("TCM_GETIMAGELIST", TCM_GETIMAGELIST),
        xlb_const("TCM_GETITEM", TCM_GETITEM),
        xlb_const("TCM_GETITEMCOUNT", TCM_GETITEMCOUNT),
        xlb_const("TCM_GETITEMRECT", TCM_GETITEMRECT),
        xlb_const("TCM_GETROWCOUNT", TCM_GETROWCOUNT),
        xlb_const("TCM_GETTOOLTIPS", TCM_GETTOOLTIPS),
        xlb_const("TCM_GETUNICODEFORMAT", TCM_GETUNICODEFORMAT),
        xlb_const("TCM_HIGHLIGHTITEM", TCM_HIGHLIGHTITEM),
        xlb_const("TCM_HITTEST", TCM_HITTEST),
        xlb_const("TCM_INSERTITEM", TCM_INSERTITEM),
        xlb_const("TCM_REMOVEIMAGE", TCM_REMOVEIMAGE),
        xlb_const("TCM_SETCURFOCUS", TCM_SETCURFOCUS),
        xlb_const("TCM_SETCURSEL", TCM_SETCURSEL),
        xlb_const("TCM_SETEXTENDEDSTYLE", TCM_SETEXTENDEDSTYLE),
        xlb_const("TCM_SETIMAGELIST", TCM_SETIMAGELIST),
        xlb_const("TCM_SETITEM", TCM_SETITEM),
        xlb_const("TCM_SETITEMEXTRA", TCM_SETITEMEXTRA),
        xlb_const("TCM_SETITEMSIZE", TCM_SETITEMSIZE),
        xlb_const("TCM_SETMINTABWIDTH", TCM_SETMINTABWIDTH),
        xlb_const("TCM_SETPADDING", TCM_SETPADDING),
        xlb_const("TCM_SETTOOLTIPS", TCM_SETTOOLTIPS),
        xlb_const("TCM_SETUNICODEFORMAT", TCM_SETUNICODEFORMAT),
        xlb_const("NM_CLICK", NM_CLICK),
        xlb_const("NM_DBLCLK", NM_DBLCLK),
        xlb_const("NM_RCLICK", NM_RCLICK),
        xlb_const("NM_RDBLCLK", NM_RDBLCLK),
        xlb_const("NM_RELEASEDCAPTURE", NM_RELEASEDCAPTURE),
        xlb_const("TCN_FOCUSCHANGE", TCN_FOCUSCHANGE),
        xlb_const("TCN_GETOBJECT", TCN_GETOBJECT),
        xlb_const("TCN_KEYDOWN", TCN_KEYDOWN),
        xlb_const("TCN_SELCHANGE", TCN_SELCHANGE),
        xlb_const("TCN_SELCHANGING", TCN_SELCHANGING),
        xlb_const("TCS_BOTTOM", TCS_BOTTOM),
        xlb_const("TCS_BUTTONS", TCS_BUTTONS),
        xlb_const("TCS_FIXEDWIDTH", TCS_FIXEDWIDTH),
        xlb_const("TCS_FLATBUTTONS", TCS_FLATBUTTONS),
        xlb_const("TCS_FOCUSNEVER", TCS_FOCUSNEVER),
        xlb_const("TCS_FOCUSONBUTTONDOWN", TCS_FOCUSONBUTTONDOWN),
        xlb_const("TCS_FORCEICONLEFT", TCS_FORCEICONLEFT),
        xlb_const("TCS_FORCELABELLEFT", TCS_FORCELABELLEFT),
        xlb_const("TCS_HOTTRACK", TCS_HOTTRACK),
        xlb_const("TCS_MULTILINE", TCS_MULTILINE),
        xlb_const("TCS_MULTISELECT", TCS_MULTISELECT),
        xlb_const("TCS_OWNERDRAWFIXED", TCS_OWNERDRAWFIXED),
        xlb_const("TCS_RAGGEDRIGHT", TCS_RAGGEDRIGHT),
        xlb_const("TCS_RIGHT", TCS_RIGHT),
        xlb_const("TCS_RIGHTJUSTIFY", TCS_RIGHTJUSTIFY),
        xlb_const("TCS_SCROLLOPPOSITE", TCS_SCROLLOPPOSITE),
        xlb_const("TCS_SINGLELINE", TCS_SINGLELINE),
        xlb_const("TCS_TABS", TCS_TABS),
        xlb_const("TCS_TOOLTIPS", TCS_TOOLTIPS),
        xlb_const("TCS_VERTICAL", TCS_VERTICAL),
        xlb_const("TCIS_BUTTONPRESSED", TCIS_BUTTONPRESSED),
        xlb_const("TCIS_HIGHLIGHTED", TCIS_HIGHLIGHTED),
        xlb_const("TCS_EX_FLATSEPARATORS", TCS_EX_FLATSEPARATORS),
        xlb_const("TCS_EX_REGISTERDROP", TCS_EX_REGISTERDROP),


        // Task Dialog
        xlb_f("TaskDialog", TaskDialog),
        xlb_f("TaskDialogIndirect", TaskDialogIndirect),
        xlb_class<xlb_cbf<PFTASKDIALOGCALLBACK>>("PFTASKDIALOGCALLBACK").constructor<xlb_luafunc>(),

        xlb_class<TASKDIALOGCONFIG>("TASKDIALOGCONFIG") .constructor<>() .destructor()
            .property("cbSize", &TASKDIALOGCONFIG::cbSize)
            .property("hwndParent", &TASKDIALOGCONFIG::hwndParent)
            .property("hInstance", &TASKDIALOGCONFIG::hInstance)
            .property("dwFlags", &TASKDIALOGCONFIG::dwFlags)
            .property("dwCommonButtons", &TASKDIALOGCONFIG::dwCommonButtons)
            .property("pszWindowTitle", &TASKDIALOGCONFIG::pszWindowTitle)
            .property("hMainIcon", &TASKDIALOGCONFIG::hMainIcon)
            .property("pszMainIcon", &TASKDIALOGCONFIG::pszMainIcon)
            .property("pszMainInstruction", &TASKDIALOGCONFIG::pszMainInstruction)
            .property("pszContent", &TASKDIALOGCONFIG::pszContent)
            .property("cButtons", &TASKDIALOGCONFIG::cButtons)
            .property("pButtons", &TASKDIALOGCONFIG::pButtons)
            .property("nDefaultButton", &TASKDIALOGCONFIG::nDefaultButton)
            .property("cRadioButtons", &TASKDIALOGCONFIG::cRadioButtons)
            .property("pRadioButtons", &TASKDIALOGCONFIG::pRadioButtons)
            .property("nDefaultRadioButton", &TASKDIALOGCONFIG::nDefaultRadioButton)
            .property("pszVerificationText", &TASKDIALOGCONFIG::pszVerificationText)
            .property("pszExpandedInformation", &TASKDIALOGCONFIG::pszExpandedInformation)
            .property("pszExpandedControlText", &TASKDIALOGCONFIG::pszExpandedControlText)
            .property("pszCollapsedControlText", &TASKDIALOGCONFIG::pszCollapsedControlText)
            .property("hFooterIcon", &TASKDIALOGCONFIG::hFooterIcon)
            .property("pszFooterIcon", &TASKDIALOGCONFIG::pszFooterIcon)
            .property("pszFooter", &TASKDIALOGCONFIG::pszFooter)
            .property("pfCallback", &TASKDIALOGCONFIG::pfCallback)
            .property("lpCallbackData", &TASKDIALOGCONFIG::lpCallbackData)
            .property("cxWidth", &TASKDIALOGCONFIG::cxWidth)
            ,
        xlb_class<TASKDIALOG_BUTTON>("TASKDIALOG_BUTTON") .constructor<>() .destructor()
            .property("nButtonID", &TASKDIALOG_BUTTON::nButtonID)
            .property("pszButtonText", &TASKDIALOG_BUTTON::pszButtonText)
            ,

        xlb_const("TDM_CLICK_BUTTON", TDM_CLICK_BUTTON),
        xlb_const("TDM_CLICK_RADIO_BUTTON", TDM_CLICK_RADIO_BUTTON),
        xlb_const("TDM_CLICK_VERIFICATION", TDM_CLICK_VERIFICATION),
        xlb_const("TDM_ENABLE_BUTTON", TDM_ENABLE_BUTTON),
        xlb_const("TDM_ENABLE_RADIO_BUTTON", TDM_ENABLE_RADIO_BUTTON),
        xlb_const("TDM_NAVIGATE_PAGE", TDM_NAVIGATE_PAGE),
        xlb_const("TDM_SET_BUTTON_ELEVATION_REQUIRED_STATE", TDM_SET_BUTTON_ELEVATION_REQUIRED_STATE),
        xlb_const("TDM_SET_ELEMENT_TEXT", TDM_SET_ELEMENT_TEXT),
        xlb_const("TDM_SET_MARQUEE_PROGRESS_BAR", TDM_SET_MARQUEE_PROGRESS_BAR),
        xlb_const("TDM_SET_PROGRESS_BAR_MARQUEE", TDM_SET_PROGRESS_BAR_MARQUEE),
        xlb_const("TDM_SET_PROGRESS_BAR_POS", TDM_SET_PROGRESS_BAR_POS),
        xlb_const("TDM_SET_PROGRESS_BAR_RANGE", TDM_SET_PROGRESS_BAR_RANGE),
        xlb_const("TDM_SET_PROGRESS_BAR_STATE", TDM_SET_PROGRESS_BAR_STATE),
        xlb_const("TDM_UPDATE_ELEMENT_TEXT", TDM_UPDATE_ELEMENT_TEXT),
        xlb_const("TDM_UPDATE_ICON", TDM_UPDATE_ICON),
        xlb_const("TDN_BUTTON_CLICKED", TDN_BUTTON_CLICKED),
        xlb_const("TDN_CREATED", TDN_CREATED),
        xlb_const("TDN_DESTROYED", TDN_DESTROYED),
        xlb_const("TDN_DIALOG_CONSTRUCTED", TDN_DIALOG_CONSTRUCTED),
        xlb_const("TDN_EXPANDO_BUTTON_CLICKED", TDN_EXPANDO_BUTTON_CLICKED),
        xlb_const("TDN_HELP", TDN_HELP),
        xlb_const("TDN_HYPERLINK_CLICKED", TDN_HYPERLINK_CLICKED),
        xlb_const("TDN_NAVIGATED", TDN_NAVIGATED),
        xlb_const("TDN_RADIO_BUTTON_CLICKED", TDN_RADIO_BUTTON_CLICKED),
        xlb_const("TDN_TIMER", TDN_TIMER),
        xlb_const("TDN_VERIFICATION_CLICKED", TDN_VERIFICATION_CLICKED),
        xlb_const("TDF_ENABLE_HYPERLINKS", TDF_ENABLE_HYPERLINKS),
        xlb_const("TDF_USE_HICON_MAIN", TDF_USE_HICON_MAIN),
        xlb_const("TDF_USE_HICON_FOOTER", TDF_USE_HICON_FOOTER),
        xlb_const("TDF_ALLOW_DIALOG_CANCELLATION", TDF_ALLOW_DIALOG_CANCELLATION),
        xlb_const("TDF_USE_COMMAND_LINKS", TDF_USE_COMMAND_LINKS),
        xlb_const("TDF_USE_COMMAND_LINKS_NO_ICON", TDF_USE_COMMAND_LINKS_NO_ICON),
        xlb_const("TDF_EXPAND_FOOTER_AREA", TDF_EXPAND_FOOTER_AREA),
        xlb_const("TDF_EXPANDED_BY_DEFAULT", TDF_EXPANDED_BY_DEFAULT),
        xlb_const("TDF_VERIFICATION_FLAG_CHECKED", TDF_VERIFICATION_FLAG_CHECKED),
        xlb_const("TDF_SHOW_PROGRESS_BAR", TDF_SHOW_PROGRESS_BAR),
        xlb_const("TDF_SHOW_MARQUEE_PROGRESS_BAR", TDF_SHOW_MARQUEE_PROGRESS_BAR),
        xlb_const("TDF_CALLBACK_TIMER", TDF_CALLBACK_TIMER),
        xlb_const("TDF_POSITION_RELATIVE_TO_WINDOW", TDF_POSITION_RELATIVE_TO_WINDOW),
        xlb_const("TDF_RTL_LAYOUT", TDF_RTL_LAYOUT),
        xlb_const("TDF_NO_DEFAULT_RADIO_BUTTON", TDF_NO_DEFAULT_RADIO_BUTTON),
        xlb_const("TDF_CAN_BE_MINIMIZED", TDF_CAN_BE_MINIMIZED),
        xlb_const("TDF_SIZE_TO_CONTENT", TDF_SIZE_TO_CONTENT),
        xlb_const("TDF_SIZE_TO_CONTENT", TDF_SIZE_TO_CONTENT),
        xlb_const("TDCBF_OK_BUTTON", TDCBF_OK_BUTTON),
        xlb_const("TDCBF_YES_BUTTON", TDCBF_YES_BUTTON),
        xlb_const("TDCBF_NO_BUTTON", TDCBF_NO_BUTTON),
        xlb_const("TDCBF_CANCEL_BUTTON", TDCBF_CANCEL_BUTTON),
        xlb_const("TDCBF_RETRY_BUTTON", TDCBF_RETRY_BUTTON),
        xlb_const("TDCBF_CLOSE_BUTTON", TDCBF_CLOSE_BUTTON),
        //xlb_const("TD_ERROR_ICON", TD_ERROR_ICON), // FIXME: crash
        //xlb_const("TD_WARNING_ICON", TD_WARNING_ICON),
        //xlb_const("TD_INFORMATION_ICON", TD_INFORMATION_ICON),
        //xlb_const("TD_SHIELD_ICON", TD_SHIELD_ICON),
        xlb_const("IDCANCEL", IDCANCEL),
        xlb_const("IDNO", IDNO),
        xlb_const("IDOK", IDOK),
        xlb_const("IDRETRY", IDRETRY),
        xlb_const("IDYES", IDYES),
        xlb_const("IDCLOSE", IDCLOSE),

        // Toolbar
        xlb_f("CreateMappedBitmap", CreateMappedBitmap),
        xlb_f("CreateToolbarEx", CreateToolbarEx),

        xlb_const("TB_ADDBITMAP", TB_ADDBITMAP),
        xlb_const("TB_ADDBUTTONS", TB_ADDBUTTONS),
        xlb_const("TB_ADDSTRING", TB_ADDSTRING),
        xlb_const("TB_AUTOSIZE", TB_AUTOSIZE),
        xlb_const("TB_BUTTONCOUNT", TB_BUTTONCOUNT),
        xlb_const("TB_BUTTONSTRUCTSIZE", TB_BUTTONSTRUCTSIZE),
        xlb_const("TB_CHANGEBITMAP", TB_CHANGEBITMAP),
        xlb_const("TB_CHECKBUTTON", TB_CHECKBUTTON),
        xlb_const("TB_COMMANDTOINDEX", TB_COMMANDTOINDEX),
        xlb_const("TB_CUSTOMIZE", TB_CUSTOMIZE),
        xlb_const("TB_DELETEBUTTON", TB_DELETEBUTTON),
        xlb_const("TB_ENABLEBUTTON", TB_ENABLEBUTTON),
        xlb_const("TB_GETANCHORHIGHLIGHT", TB_GETANCHORHIGHLIGHT),
        xlb_const("TB_GETBITMAP", TB_GETBITMAP),
        xlb_const("TB_GETBITMAPFLAGS", TB_GETBITMAPFLAGS),
        xlb_const("TB_GETBUTTON", TB_GETBUTTON),
        xlb_const("TB_GETBUTTONINFO", TB_GETBUTTONINFO),
        xlb_const("TB_GETBUTTONSIZE", TB_GETBUTTONSIZE),
        xlb_const("TB_GETBUTTONTEXT", TB_GETBUTTONTEXT),
        xlb_const("TB_GETCOLORSCHEME", TB_GETCOLORSCHEME),
        xlb_const("TB_GETDISABLEDIMAGELIST", TB_GETDISABLEDIMAGELIST),
        xlb_const("TB_GETEXTENDEDSTYLE", TB_GETEXTENDEDSTYLE),
        xlb_const("TB_GETHOTIMAGELIST", TB_GETHOTIMAGELIST),
        xlb_const("TB_GETHOTITEM", TB_GETHOTITEM),
        xlb_const("TB_GETIDEALSIZE", TB_GETIDEALSIZE),
        xlb_const("TB_GETIMAGELIST", TB_GETIMAGELIST),
        xlb_const("TB_GETIMAGELISTCOUNT", TB_GETIMAGELISTCOUNT),
        xlb_const("TB_GETINSERTMARK", TB_GETINSERTMARK),
        xlb_const("TB_GETINSERTMARKCOLOR", TB_GETINSERTMARKCOLOR),
        xlb_const("TB_GETITEMDROPDOWNRECT", TB_GETITEMDROPDOWNRECT),
        xlb_const("TB_GETITEMRECT", TB_GETITEMRECT),
        xlb_const("TB_GETMAXSIZE", TB_GETMAXSIZE),
        xlb_const("TB_GETMETRICS", TB_GETMETRICS),
        xlb_const("TB_GETOBJECT", TB_GETOBJECT),
        xlb_const("TB_GETPADDING", TB_GETPADDING),
        xlb_const("TB_GETPRESSEDIMAGELIST", TB_GETPRESSEDIMAGELIST),
        xlb_const("TB_GETRECT", TB_GETRECT),
        xlb_const("TB_GETROWS", TB_GETROWS),
        xlb_const("TB_GETSTATE", TB_GETSTATE),
        xlb_const("TB_GETSTRING", TB_GETSTRING),
        xlb_const("TB_GETSTYLE", TB_GETSTYLE),
        xlb_const("TB_GETTEXTROWS", TB_GETTEXTROWS),
        xlb_const("TB_GETTOOLTIPS", TB_GETTOOLTIPS),
        xlb_const("TB_GETUNICODEFORMAT", TB_GETUNICODEFORMAT),
        xlb_const("TB_HASACCELERATOR", TB_HASACCELERATOR),
        xlb_const("TB_HIDEBUTTON", TB_HIDEBUTTON),
        xlb_const("TB_HITTEST", TB_HITTEST),
        xlb_const("TB_INDETERMINATE", TB_INDETERMINATE),
        xlb_const("TB_INSERTBUTTON", TB_INSERTBUTTON),
        xlb_const("TB_INSERTMARKHITTEST", TB_INSERTMARKHITTEST),
        xlb_const("TB_ISBUTTONCHECKED", TB_ISBUTTONCHECKED),
        xlb_const("TB_ISBUTTONENABLED", TB_ISBUTTONENABLED),
        xlb_const("TB_ISBUTTONHIDDEN", TB_ISBUTTONHIDDEN),
        xlb_const("TB_ISBUTTONHIGHLIGHTED", TB_ISBUTTONHIGHLIGHTED),
        xlb_const("TB_ISBUTTONINDETERMINATE", TB_ISBUTTONINDETERMINATE),
        xlb_const("TB_ISBUTTONPRESSED", TB_ISBUTTONPRESSED),
        xlb_const("TB_LOADIMAGES", TB_LOADIMAGES),
        xlb_const("TB_MAPACCELERATOR", TB_MAPACCELERATOR),
        xlb_const("TB_MARKBUTTON", TB_MARKBUTTON),
        xlb_const("TB_MOVEBUTTON", TB_MOVEBUTTON),
        xlb_const("TB_PRESSBUTTON", TB_PRESSBUTTON),
        xlb_const("TB_REPLACEBITMAP", TB_REPLACEBITMAP),
        xlb_const("TB_SAVERESTORE", TB_SAVERESTORE),
        xlb_const("TB_SETANCHORHIGHLIGHT", TB_SETANCHORHIGHLIGHT),
        xlb_const("TB_SETBITMAPSIZE", TB_SETBITMAPSIZE),
        xlb_const("TB_SETBOUNDINGSIZE", TB_SETBOUNDINGSIZE),
        xlb_const("TB_SETBUTTONINFO", TB_SETBUTTONINFO),
        xlb_const("TB_SETBUTTONSIZE", TB_SETBUTTONSIZE),
        xlb_const("TB_SETBUTTONWIDTH", TB_SETBUTTONWIDTH),
        xlb_const("TB_SETCMDID", TB_SETCMDID),
        xlb_const("TB_SETCOLORSCHEME", TB_SETCOLORSCHEME),
        xlb_const("TB_SETDISABLEDIMAGELIST", TB_SETDISABLEDIMAGELIST),
        xlb_const("TB_SETDRAWTEXTFLAGS", TB_SETDRAWTEXTFLAGS),
        xlb_const("TB_SETEXTENDEDSTYLE", TB_SETEXTENDEDSTYLE),
        xlb_const("TB_SETHOTIMAGELIST", TB_SETHOTIMAGELIST),
        xlb_const("TB_SETHOTITEM", TB_SETHOTITEM),
        xlb_const("TB_SETHOTITEM2", TB_SETHOTITEM2),
        xlb_const("TB_SETIMAGELIST", TB_SETIMAGELIST),
        xlb_const("TB_SETINDENT", TB_SETINDENT),
        xlb_const("TB_SETINSERTMARK", TB_SETINSERTMARK),
        xlb_const("TB_SETINSERTMARKCOLOR", TB_SETINSERTMARKCOLOR),
        xlb_const("TB_SETLISTGAP", TB_SETLISTGAP),
        xlb_const("TB_SETMAXTEXTROWS", TB_SETMAXTEXTROWS),
        xlb_const("TB_SETMETRICS", TB_SETMETRICS),
        xlb_const("TB_SETPADDING", TB_SETPADDING),
        xlb_const("TB_SETPARENT", TB_SETPARENT),
        xlb_const("TB_SETPRESSEDIMAGELIST", TB_SETPRESSEDIMAGELIST),
        xlb_const("TB_SETROWS", TB_SETROWS),
        xlb_const("TB_SETSTATE", TB_SETSTATE),
        xlb_const("TB_SETSTYLE", TB_SETSTYLE),
        xlb_const("TB_SETTOOLTIPS", TB_SETTOOLTIPS),
        xlb_const("TB_SETUNICODEFORMAT", TB_SETUNICODEFORMAT),
        xlb_const("TB_SETWINDOWTHEME", TB_SETWINDOWTHEME),
        //xlb_const("TB_TRANSLATEACCELERATOR", TB_TRANSLATEACCELERATOR), // not implemented
        
        xlb_const("NM_CHAR", NM_CHAR),
        xlb_const("NM_CLICK", NM_CLICK),
        xlb_const("NM_CUSTOMDRAW", NM_CUSTOMDRAW),
        xlb_const("NM_DBLCLK", NM_DBLCLK),
        xlb_const("NM_KEYDOWN", NM_KEYDOWN),
        xlb_const("NM_LDOWN", NM_LDOWN),
        xlb_const("NM_RCLICK", NM_RCLICK),
        xlb_const("NM_RDBLCLK", NM_RDBLCLK),
        xlb_const("NM_RELEASEDCAPTURE", NM_RELEASEDCAPTURE),
        xlb_const("NM_TOOLTIPSCREATED", NM_TOOLTIPSCREATED),
        xlb_const("TBN_BEGINADJUST", TBN_BEGINADJUST),
        xlb_const("TBN_BEGINDRAG", TBN_BEGINDRAG),
        xlb_const("TBN_CUSTHELP", TBN_CUSTHELP),
        xlb_const("TBN_DELETINGBUTTON", TBN_DELETINGBUTTON),
        xlb_const("TBN_DRAGOUT", TBN_DRAGOUT),
        xlb_const("TBN_DRAGOVER", TBN_DRAGOVER),
        xlb_const("TBN_DROPDOWN", TBN_DROPDOWN),
        xlb_const("TBN_DUPACCELERATOR", TBN_DUPACCELERATOR),
        xlb_const("TBN_ENDADJUST", TBN_ENDADJUST),
        xlb_const("TBN_ENDDRAG", TBN_ENDDRAG),
        xlb_const("TBN_GETBUTTONINFO", TBN_GETBUTTONINFO),
        xlb_const("TBN_GETDISPINFO", TBN_GETDISPINFO),
        xlb_const("TBN_GETINFOTIP", TBN_GETINFOTIP),
        xlb_const("TBN_GETOBJECT", TBN_GETOBJECT),
        xlb_const("TBN_HOTITEMCHANGE", TBN_HOTITEMCHANGE),
        xlb_const("TBN_INITCUSTOMIZE", TBN_INITCUSTOMIZE),
        xlb_const("TBN_MAPACCELERATOR", TBN_MAPACCELERATOR),
        xlb_const("TBN_QUERYDELETE", TBN_QUERYDELETE),
        xlb_const("TBN_QUERYINSERT", TBN_QUERYINSERT),
        xlb_const("TBN_RESET", TBN_RESET),
        xlb_const("TBN_RESTORE", TBN_RESTORE),
        xlb_const("TBN_SAVE", TBN_SAVE),
        xlb_const("TBN_TOOLBARCHANGE", TBN_TOOLBARCHANGE),
        xlb_const("TBN_WRAPACCELERATOR", TBN_WRAPACCELERATOR),
        xlb_const("TBN_WRAPHOTITEM", TBN_WRAPHOTITEM),
        xlb_const("HIST_ADDTOFAVORITES", HIST_ADDTOFAVORITES),
        xlb_const("HIST_BACK", HIST_BACK),
        xlb_const("HIST_FAVORITES", HIST_FAVORITES),
        xlb_const("HIST_FORWARD", HIST_FORWARD),
        xlb_const("HIST_VIEWTREE", HIST_VIEWTREE),
        xlb_const("STD_COPY", STD_COPY),
        xlb_const("STD_CUT", STD_CUT),
        xlb_const("STD_DELETE", STD_DELETE),
        xlb_const("STD_FILENEW", STD_FILENEW),
        xlb_const("STD_FILEOPEN", STD_FILEOPEN),
        xlb_const("STD_FILESAVE", STD_FILESAVE),
        xlb_const("STD_FIND", STD_FIND),
        xlb_const("STD_HELP", STD_HELP),
        xlb_const("STD_PASTE", STD_PASTE),
        xlb_const("STD_PRINT", STD_PRINT),
        xlb_const("STD_PRINTPRE", STD_PRINTPRE),
        xlb_const("STD_PROPERTIES", STD_PROPERTIES),
        xlb_const("STD_REDOW", STD_REDOW),
        xlb_const("STD_REPLACE", STD_REPLACE),
        xlb_const("STD_UNDO", STD_UNDO),
        xlb_const("VIEW_DETAILS", VIEW_DETAILS),
        xlb_const("VIEW_LARGEICONS", VIEW_LARGEICONS),
        xlb_const("VIEW_LIST", VIEW_LIST),
        xlb_const("VIEW_NETCONNECT", VIEW_NETCONNECT),
        xlb_const("VIEW_NETDISCONNECT", VIEW_NETDISCONNECT),
        xlb_const("VIEW_NEWFOLDER", VIEW_NEWFOLDER),
        xlb_const("VIEW_PARENTFOLDER", VIEW_PARENTFOLDER),
        xlb_const("VIEW_SMALLICONS", VIEW_SMALLICONS),
        xlb_const("VIEW_SORTDATE", VIEW_SORTDATE),
        xlb_const("VIEW_SORTNAME", VIEW_SORTNAME),
        xlb_const("VIEW_SORTSIZE", VIEW_SORTSIZE),
        xlb_const("VIEW_SORTTYPE", VIEW_SORTTYPE),
        xlb_const("TBSTYLE_EX_DRAWDDARROWS", TBSTYLE_EX_DRAWDDARROWS),
        xlb_const("TBSTYLE_EX_HIDECLIPPEDBUTTONS", TBSTYLE_EX_HIDECLIPPEDBUTTONS),
        xlb_const("TBSTYLE_EX_DOUBLEBUFFER", TBSTYLE_EX_DOUBLEBUFFER),
        xlb_const("TBSTYLE_EX_MIXEDBUTTONS", TBSTYLE_EX_MIXEDBUTTONS),
        xlb_const("TBSTYLE_EX_MULTICOLUMN", TBSTYLE_EX_MULTICOLUMN),
        xlb_const("TBSTYLE_EX_VERTICAL", TBSTYLE_EX_VERTICAL),
        xlb_const("TBSTYLE_ALTDRAG", TBSTYLE_ALTDRAG),
        xlb_const("TBSTYLE_CUSTOMERASE", TBSTYLE_CUSTOMERASE),
        xlb_const("TBSTYLE_FLAT", TBSTYLE_FLAT),
        xlb_const("TBSTYLE_LIST", TBSTYLE_LIST),
        xlb_const("TBSTYLE_REGISTERDROP", TBSTYLE_REGISTERDROP),
        xlb_const("TBSTYLE_TOOLTIPS", TBSTYLE_TOOLTIPS),
        xlb_const("TBSTYLE_TRANSPARENT", TBSTYLE_TRANSPARENT),
        xlb_const("TBSTYLE_WRAPABLE", TBSTYLE_WRAPABLE),
        xlb_const("BTNS_AUTOSIZE", BTNS_AUTOSIZE),
        xlb_const("BTNS_BUTTON", BTNS_BUTTON),
        xlb_const("BTNS_CHECK", BTNS_CHECK),
        xlb_const("BTNS_CHECKGROUP", BTNS_CHECKGROUP),
        xlb_const("BTNS_DROPDOWN", BTNS_DROPDOWN),
        xlb_const("BTNS_GROUP", BTNS_GROUP),
        xlb_const("BTNS_NOPREFIX", BTNS_NOPREFIX),
        xlb_const("BTNS_SEP", BTNS_SEP),
        xlb_const("BTNS_SHOWTEXT", BTNS_SHOWTEXT),
        xlb_const("BTNS_WHOLEDROPDOWN", BTNS_WHOLEDROPDOWN),
        xlb_const("TBSTYLE_AUTOSIZE", TBSTYLE_AUTOSIZE),
        xlb_const("TBSTYLE_BUTTON", TBSTYLE_BUTTON),
        xlb_const("TBSTYLE_CHECK", TBSTYLE_CHECK),
        xlb_const("TBSTYLE_CHECKGROUP", TBSTYLE_CHECKGROUP),
        xlb_const("TBSTYLE_DROPDOWN", TBSTYLE_DROPDOWN),
        xlb_const("TBSTYLE_GROUP", TBSTYLE_GROUP),
        xlb_const("TBSTYLE_NOPREFIX", TBSTYLE_NOPREFIX),
        xlb_const("TBSTYLE_SEP", TBSTYLE_SEP),
        xlb_const("TBSTATE_CHECKED", TBSTATE_CHECKED),
        xlb_const("TBSTATE_ELLIPSES", TBSTATE_ELLIPSES),
        xlb_const("TBSTATE_ENABLED", TBSTATE_ENABLED),
        xlb_const("TBSTATE_HIDDEN", TBSTATE_HIDDEN),
        xlb_const("TBSTATE_INDETERMINATE", TBSTATE_INDETERMINATE),
        xlb_const("TBSTATE_MARKED", TBSTATE_MARKED),
        xlb_const("TBSTATE_PRESSED", TBSTATE_PRESSED),
        xlb_const("TBSTATE_WRAP", TBSTATE_WRAP),

        xlb_class<COLORMAP>("COLORMAP") .constructor<>() .destructor()
            .property("from", &COLORMAP::from)
            .property("to", &COLORMAP::to)
            ,
        xlb_class<NMTBCUSTOMDRAW>("NMTBCUSTOMDRAW") .constructor<>() .destructor()
            .property("nmcd", &NMTBCUSTOMDRAW::nmcd)
            .property("hbrMonoDither", &NMTBCUSTOMDRAW::hbrMonoDither)
            .property("hbrLines", &NMTBCUSTOMDRAW::hbrLines)
            .property("hpenLines", &NMTBCUSTOMDRAW::hpenLines)
            .property("clrText", &NMTBCUSTOMDRAW::clrText)
            .property("clrMark", &NMTBCUSTOMDRAW::clrMark)
            .property("clrTextHighlight", &NMTBCUSTOMDRAW::clrTextHighlight)
            .property("clrBtnFace", &NMTBCUSTOMDRAW::clrBtnFace)
            .property("clrBtnHighlight", &NMTBCUSTOMDRAW::clrBtnHighlight)
            .property("clrHighlightHotTrack", &NMTBCUSTOMDRAW::clrHighlightHotTrack)
            .property("rcText", &NMTBCUSTOMDRAW::rcText)
            .property("nStringBkMode", &NMTBCUSTOMDRAW::nStringBkMode)
            .property("nHLStringBkMode", &NMTBCUSTOMDRAW::nHLStringBkMode)
            .property("iListGap", &NMTBCUSTOMDRAW::iListGap)
            ,
        xlb_class<NMTBDISPINFOA>("NMTBDISPINFOA") .constructor<>() .destructor()
            .property("hdr", &NMTBDISPINFOA::hdr)
            .property("dwMask", &NMTBDISPINFOA::dwMask)
            .property("idCommand", &NMTBDISPINFOA::idCommand)
            .property("lParam", &NMTBDISPINFOA::lParam)
            .property("iImage", &NMTBDISPINFOA::iImage)
            .property("pszText", &NMTBDISPINFOA::pszText)
            .property("cchText", &NMTBDISPINFOA::cchText)
            ,
        xlb_class<NMTBGETINFOTIPA>("NMTBGETINFOTIPA") .constructor<>() .destructor()
            .property("hdr", &NMTBGETINFOTIPA::hdr)
            .property("pszText", &NMTBGETINFOTIPA::pszText)
            .property("cchTextMax", &NMTBGETINFOTIPA::cchTextMax)
            .property("iItem", &NMTBGETINFOTIPA::iItem)
            .property("lParam", &NMTBGETINFOTIPA::lParam)
            ,
        xlb_class<NMTBHOTITEM>("NMTBHOTITEM") .constructor<>() .destructor()
            .property("hdr", &NMTBHOTITEM::hdr)
            .property("idOld", &NMTBHOTITEM::idOld)
            .property("idNew", &NMTBHOTITEM::idNew)
            .property("dwFlags", &NMTBHOTITEM::dwFlags)
            ,
        xlb_class<NMTBRESTORE>("NMTBRESTORE") .constructor<>() .destructor()
            .property("hdr", &NMTBRESTORE::hdr)
            .property("pData", &NMTBRESTORE::pData)
            .property("pCurrent", &NMTBRESTORE::pCurrent)
            .property("cbData", &NMTBRESTORE::cbData)
            .property("iItem", &NMTBRESTORE::iItem)
            .property("cButtons", &NMTBRESTORE::cButtons)
            .property("cbBytesPerRecord", &NMTBRESTORE::cbBytesPerRecord)
            .property("tbButton", &NMTBRESTORE::tbButton)
            ,
        xlb_class<NMTBSAVE>("NMTBSAVE") .constructor<>() .destructor()
            .property("hdr", &NMTBSAVE::hdr)
            .property("pData", &NMTBSAVE::pData)
            .property("pCurrent", &NMTBSAVE::pCurrent)
            .property("cbData", &NMTBSAVE::cbData)
            .property("iItem", &NMTBSAVE::iItem)
            .property("cButtons", &NMTBSAVE::cButtons)
            .property("tbButton", &NMTBSAVE::tbButton)
            ,
        xlb_class<NMTOOLBARA>("NMTOOLBARA") .constructor<>() .destructor()
            .property("hdr", &NMTOOLBARA::hdr)
            .property("iItem", &NMTOOLBARA::iItem)
            .property("tbButton", &NMTOOLBARA::tbButton)
            .property("cchText", &NMTOOLBARA::cchText)
            .property("pszText", &NMTOOLBARA::pszText)
            .property("rcButton", &NMTOOLBARA::rcButton)
            ,
        xlb_class<TBADDBITMAP>("TBADDBITMAP") .constructor<>() .destructor()
            .property("hInst", &TBADDBITMAP::hInst)
            .property("nID", &TBADDBITMAP::nID)
            ,
        xlb_class<TBBUTTON>("TBBUTTON") .constructor<>() .destructor()
            .property("iBitmap", &TBBUTTON::iBitmap)
            .property("idCommand", &TBBUTTON::idCommand)
            .property("fsState", &TBBUTTON::fsState)
            .property("fsStyle", &TBBUTTON::fsStyle)
            .property("bReserved", &TBBUTTON::bReserved)
            .property("dwData", &TBBUTTON::dwData)
            .property("iString", &TBBUTTON::iString)
            ,
        xlb_class<TBBUTTONINFOA>("TBBUTTONINFOA") .constructor<>() .destructor()
            .property("cbSize", &TBBUTTONINFOA::cbSize)
            .property("dwMask", &TBBUTTONINFOA::dwMask)
            .property("idCommand", &TBBUTTONINFOA::idCommand)
            .property("iImage", &TBBUTTONINFOA::iImage)
            .property("fsState", &TBBUTTONINFOA::fsState)
            .property("fsStyle", &TBBUTTONINFOA::fsStyle)
            .property("cx", &TBBUTTONINFOA::cx)
            .property("lParam", &TBBUTTONINFOA::lParam)
            .property("pszText", &TBBUTTONINFOA::pszText)
            .property("cchText", &TBBUTTONINFOA::cchText)
            ,
        xlb_class<TBINSERTMARK>("TBINSERTMARK") .constructor<>() .destructor()
            .property("iButton", &TBINSERTMARK::iButton)
            .property("dwFlags", &TBINSERTMARK::dwFlags)
            ,
        xlb_class<TBMETRICS>("TBMETRICS") .constructor<>() .destructor()
            .property("cbSize", &TBMETRICS::cbSize)
            .property("dwMask", &TBMETRICS::dwMask)
            .property("cxPad", &TBMETRICS::cxPad)
            .property("cyPad", &TBMETRICS::cyPad)
            .property("cxBarPad", &TBMETRICS::cxBarPad)
            .property("cyBarPad", &TBMETRICS::cyBarPad)
            .property("cxButtonSpacing", &TBMETRICS::cxButtonSpacing)
            .property("cyButtonSpacing", &TBMETRICS::cyButtonSpacing)
            ,
        xlb_class<TBREPLACEBITMAP>("TBREPLACEBITMAP") .constructor<>() .destructor()
            .property("hInstOld", &TBREPLACEBITMAP::hInstOld)
            .property("nIDOld", &TBREPLACEBITMAP::nIDOld)
            .property("hInstNew", &TBREPLACEBITMAP::hInstNew)
            .property("nIDNew", &TBREPLACEBITMAP::nIDNew)
            .property("nButtons", &TBREPLACEBITMAP::nButtons)
            ,
        xlb_class<TBSAVEPARAMSA>("TBSAVEPARAMSA") .constructor<>() .destructor()
            .property("hkr", &TBSAVEPARAMSA::hkr)
            .property("pszSubKey", &TBSAVEPARAMSA::pszSubKey)
            .property("pszValueName", &TBSAVEPARAMSA::pszValueName)
            ,

        // Tooltip
        xlb_class<NMTTCUSTOMDRAW>("NMTTCUSTOMDRAW") .constructor<>() .destructor()
            .property("nmcd", &NMTTCUSTOMDRAW::nmcd)
            .property("uDrawFlags", &NMTTCUSTOMDRAW::uDrawFlags)
            ,
        xlb_class<NMTTDISPINFOA>("NMTTDISPINFOA") .constructor<>() .destructor()
            .property("hdr", &NMTTDISPINFOA::hdr)
            .property("lpszText", &NMTTDISPINFOA::lpszText)
            .property("szText", &NMTTDISPINFOA::szText)
            .property("hinst", &NMTTDISPINFOA::hinst)
            .property("uFlags", &NMTTDISPINFOA::uFlags)
            .property("lParam", &NMTTDISPINFOA::lParam)
            ,
        xlb_class<TTTOOLINFOA>("TTTOOLINFOA") .constructor<>() .destructor()
            .property("cbSize", &TTTOOLINFOA::cbSize)
            .property("uFlags", &TTTOOLINFOA::uFlags)
            .property("hwnd", &TTTOOLINFOA::hwnd)
            .property("uId", &TTTOOLINFOA::uId)
            .property("rect", &TTTOOLINFOA::rect)
            .property("hinst", &TTTOOLINFOA::hinst)
            .property("lpszText", &TTTOOLINFOA::lpszText)
            .property("lParam", &TTTOOLINFOA::lParam)
            .property("lpReserved", &TTTOOLINFOA::lpReserved)
            ,
        xlb_class<TTGETTITLE>("TTGETTITLE") .constructor<>() .destructor()
            .property("dwSize", &TTGETTITLE::dwSize)
            .property("uTitleBitmap", &TTGETTITLE::uTitleBitmap)
            .property("cch", &TTGETTITLE::cch)
            .property("pszTitle", &TTGETTITLE::pszTitle)
            ,
        xlb_class<TTHITTESTINFOA>("TTHITTESTINFOA") .constructor<>() .destructor()
            .property("hwnd", &TTHITTESTINFOA::hwnd)
            .property("pt", &TTHITTESTINFOA::pt)
            .property("ti", &TTHITTESTINFOA::ti)
            ,

        xlb_const("TTM_ACTIVATE", TTM_ACTIVATE),
        xlb_const("TTM_ADDTOOL", TTM_ADDTOOL),
        xlb_const("TTM_ADJUSTRECT", TTM_ADJUSTRECT),
        xlb_const("TTM_DELTOOL", TTM_DELTOOL),
        xlb_const("TTM_ENUMTOOLS", TTM_ENUMTOOLS),
        xlb_const("TTM_GETBUBBLESIZE", TTM_GETBUBBLESIZE),
        xlb_const("TTM_GETCURRENTTOOL", TTM_GETCURRENTTOOL),
        xlb_const("TTM_GETDELAYTIME", TTM_GETDELAYTIME),
        xlb_const("TTM_GETMARGIN", TTM_GETMARGIN),
        xlb_const("TTM_GETMAXTIPWIDTH", TTM_GETMAXTIPWIDTH),
        xlb_const("TTM_GETTEXT", TTM_GETTEXT),
        xlb_const("TTM_GETTIPBKCOLOR", TTM_GETTIPBKCOLOR),
        xlb_const("TTM_GETTIPTEXTCOLOR", TTM_GETTIPTEXTCOLOR),
        xlb_const("TTM_GETTITLE", TTM_GETTITLE),
        xlb_const("TTM_GETTOOLCOUNT", TTM_GETTOOLCOUNT),
        xlb_const("TTM_GETTOOLINFO", TTM_GETTOOLINFO),
        xlb_const("TTM_HITTEST", TTM_HITTEST),
        xlb_const("TTM_NEWTOOLRECT", TTM_NEWTOOLRECT),
        xlb_const("TTM_POP", TTM_POP),
        xlb_const("TTM_POPUP", TTM_POPUP),
        xlb_const("TTM_RELAYEVENT", TTM_RELAYEVENT),
        xlb_const("TTM_SETDELAYTIME", TTM_SETDELAYTIME),
        xlb_const("TTM_SETMARGIN", TTM_SETMARGIN),
        xlb_const("TTM_SETMAXTIPWIDTH", TTM_SETMAXTIPWIDTH),
        xlb_const("TTM_SETTIPBKCOLOR", TTM_SETTIPBKCOLOR),
        xlb_const("TTM_SETTIPTEXTCOLOR", TTM_SETTIPTEXTCOLOR),
        xlb_const("TTM_SETTITLE", TTM_SETTITLE),
        xlb_const("TTM_SETTOOLINFO", TTM_SETTOOLINFO),
        xlb_const("TTM_SETWINDOWTHEME", TTM_SETWINDOWTHEME),
        xlb_const("TTM_TRACKACTIVATE", TTM_TRACKACTIVATE),
        xlb_const("TTM_TRACKPOSITION", TTM_TRACKPOSITION),
        xlb_const("TTM_UPDATE", TTM_UPDATE),
        xlb_const("TTM_UPDATETIPTEXT", TTM_UPDATETIPTEXT),
        xlb_const("TTM_WINDOWFROMPOINT", TTM_WINDOWFROMPOINT),
        xlb_const("NM_CUSTOMDRAW", NM_CUSTOMDRAW),
        xlb_const("TTN_GETDISPINFO", TTN_GETDISPINFO),
        xlb_const("TTN_LINKCLICK", TTN_LINKCLICK),
        xlb_const("TTN_NEEDTEXT", TTN_NEEDTEXT),
        xlb_const("TTN_POP", TTN_POP),
        xlb_const("TTN_SHOW", TTN_SHOW),
        xlb_const("TTS_ALWAYSTIP", TTS_ALWAYSTIP),
        xlb_const("TTS_BALLOON", TTS_BALLOON),
        xlb_const("TTS_CLOSE", TTS_CLOSE),
        xlb_const("TTS_NOANIMATE", TTS_NOANIMATE),
        xlb_const("TTS_NOFADE", TTS_NOFADE),
        xlb_const("TTS_NOPREFIX", TTS_NOPREFIX),
        xlb_const("TTS_USEVISUALSTYLE", TTS_USEVISUALSTYLE),

        // Trackbar
        xlb_const("TBM_CLEARSEL", TBM_CLEARSEL),
        xlb_const("TBM_CLEARTICS", TBM_CLEARTICS),
        xlb_const("TBM_GETBUDDY", TBM_GETBUDDY),
        xlb_const("TBM_GETCHANNELRECT", TBM_GETCHANNELRECT),
        xlb_const("TBM_GETLINESIZE", TBM_GETLINESIZE),
        xlb_const("TBM_GETNUMTICS", TBM_GETNUMTICS),
        xlb_const("TBM_GETPAGESIZE", TBM_GETPAGESIZE),
        xlb_const("TBM_GETPOS", TBM_GETPOS),
        xlb_const("TBM_GETPTICS", TBM_GETPTICS),
        xlb_const("TBM_GETRANGEMAX", TBM_GETRANGEMAX),
        xlb_const("TBM_GETRANGEMIN", TBM_GETRANGEMIN),
        xlb_const("TBM_GETSELEND", TBM_GETSELEND),
        xlb_const("TBM_GETSELSTART", TBM_GETSELSTART),
        xlb_const("TBM_GETTHUMBLENGTH", TBM_GETTHUMBLENGTH),
        xlb_const("TBM_GETTHUMBRECT", TBM_GETTHUMBRECT),
        xlb_const("TBM_GETTIC", TBM_GETTIC),
        xlb_const("TBM_GETTICPOS", TBM_GETTICPOS),
        xlb_const("TBM_GETTOOLTIPS", TBM_GETTOOLTIPS),
        xlb_const("TBM_GETUNICODEFORMAT", TBM_GETUNICODEFORMAT),
        xlb_const("TBM_SETBUDDY", TBM_SETBUDDY),
        xlb_const("TBM_SETLINESIZE", TBM_SETLINESIZE),
        xlb_const("TBM_SETPAGESIZE", TBM_SETPAGESIZE),
        xlb_const("TBM_SETPOS", TBM_SETPOS),
        xlb_const("TBM_SETPOSNOTIFY", TBM_SETPOSNOTIFY),
        xlb_const("TBM_SETRANGE", TBM_SETRANGE),
        xlb_const("TBM_SETRANGEMAX", TBM_SETRANGEMAX),
        xlb_const("TBM_SETRANGEMIN", TBM_SETRANGEMIN),
        xlb_const("TBM_SETSEL", TBM_SETSEL),
        xlb_const("TBM_SETSELEND", TBM_SETSELEND),
        xlb_const("TBM_SETSELSTART", TBM_SETSELSTART),
        xlb_const("TBM_SETTHUMBLENGTH", TBM_SETTHUMBLENGTH),
        xlb_const("TBM_SETTIC", TBM_SETTIC),
        xlb_const("TBM_SETTICFREQ", TBM_SETTICFREQ),
        xlb_const("TBM_SETTIPSIDE", TBM_SETTIPSIDE),
        xlb_const("TBM_SETTOOLTIPS", TBM_SETTOOLTIPS),
        xlb_const("TBM_SETUNICODEFORMAT", TBM_SETUNICODEFORMAT),
        xlb_const("NM_CUSTOMDRAW", NM_CUSTOMDRAW),
        xlb_const("NM_RELEASEDCAPTURE", NM_RELEASEDCAPTURE),
        xlb_const("TRBN_THUMBPOSCHANGING", TRBN_THUMBPOSCHANGING),
        xlb_const("TBCD_CHANNEL", TBCD_CHANNEL),
        xlb_const("TBCD_THUMB", TBCD_THUMB),
        xlb_const("TBCD_TICS", TBCD_TICS),
        xlb_const("TBS_AUTOTICKS", TBS_AUTOTICKS),
        xlb_const("TBS_VERT", TBS_VERT),
        xlb_const("TBS_HORZ", TBS_HORZ),
        xlb_const("TBS_TOP", TBS_TOP),
        xlb_const("TBS_BOTTOM", TBS_BOTTOM),
        xlb_const("TBS_LEFT", TBS_LEFT),
        xlb_const("TBS_RIGHT", TBS_RIGHT),
        xlb_const("TBS_BOTH", TBS_BOTH),
        xlb_const("TBS_NOTICKS", TBS_NOTICKS),
        xlb_const("TBS_ENABLESELRANGE", TBS_ENABLESELRANGE),
        xlb_const("TBS_FIXEDLENGTH", TBS_FIXEDLENGTH),
        xlb_const("TBS_NOTHUMB", TBS_NOTHUMB),
        xlb_const("TBS_TOOLTIPS", TBS_TOOLTIPS),
        xlb_const("TBS_REVERSED", TBS_REVERSED),
        xlb_const("TBS_DOWNISLEFT", TBS_DOWNISLEFT),
        xlb_const("TBS_NOTIFYBEFOREMOVE", TBS_NOTIFYBEFOREMOVE),
        xlb_const("TBS_TRANSPARENTBKGND", TBS_TRANSPARENTBKGND),

        // TreeView

        xlb_f("TreeView_CreateDragImage", [](HWND hwnd, HTREEITEM hitem)->auto { return TreeView_CreateDragImage(hwnd, hitem); }),
        xlb_f("TreeView_DeleteAllItems", [](HWND hwnd)->auto { return TreeView_DeleteAllItems(hwnd); }),
        xlb_f("TreeView_DeleteItem", [](HWND hwnd, HTREEITEM hitem)->auto { return TreeView_DeleteItem(hwnd, hitem); }),
        xlb_f("TreeView_EditLabel", [](HWND hwnd, HTREEITEM hitem)->auto { return TreeView_EditLabel(hwnd, hitem); }),
        xlb_f("TreeView_EndEditLabelNow", [](HWND hwnd, BOOL fCancel)->auto { return TreeView_EndEditLabelNow(hwnd, fCancel); }),
        xlb_f("TreeView_EnsureVisible", [](HWND hwnd, HTREEITEM hitem)->auto { return TreeView_EnsureVisible(hwnd, hitem); }),
        xlb_f("TreeView_Expand", [](HWND hwnd, HTREEITEM hitem, UINT code)->auto { return TreeView_Expand(hwnd, hitem, code); }),
        xlb_f("TreeView_GetBkColor", [](HWND hwnd)->auto { return TreeView_GetBkColor(hwnd); }),
        xlb_f("TreeView_GetCheckState", [](HWND hwnd, HTREEITEM hitem)->auto { return TreeView_GetCheckState(hwnd, hitem); }),
        xlb_f("TreeView_GetChild", [](HWND hwnd, HTREEITEM hitem)->auto { return TreeView_GetChild(hwnd, hitem); }),
        xlb_f("TreeView_GetCount", [](HWND hwnd)->auto { return TreeView_GetCount(hwnd); }),
        xlb_f("TreeView_GetDropHilight", [](HWND hwnd)->auto { return TreeView_GetDropHilight(hwnd); }),
        xlb_f("TreeView_GetEditControl", [](HWND hwnd)->auto { return TreeView_GetEditControl(hwnd); }),
        xlb_f("TreeView_GetExtendedStyle", [](HWND hwnd)->auto { return TreeView_GetExtendedStyle(hwnd); }),
        xlb_f("TreeView_GetFirstVisible", [](HWND hwnd)->auto { return TreeView_GetFirstVisible(hwnd); }),
        xlb_f("TreeView_GetImageList", [](HWND hwnd, INT iImage)->auto { return TreeView_GetImageList(hwnd, iImage); }),
        xlb_f("TreeView_GetIndent", [](HWND hwnd)->auto { return TreeView_GetIndent(hwnd); }),
        xlb_f("TreeView_GetInsertMarkColor", [](HWND hwnd)->auto { return TreeView_GetInsertMarkColor(hwnd); }),
        xlb_f("TreeView_GetISearchString", [](HWND hwnd, LPTSTR lpsz)->auto { return TreeView_GetISearchString(hwnd, lpsz); }),
        xlb_f("TreeView_GetItem", [](HWND hwnd, LPTVITEM pitem)->auto { return TreeView_GetItem(hwnd, pitem); }),
        xlb_f("TreeView_GetItemHeight", [](HWND hwnd)->auto { return TreeView_GetItemHeight(hwnd); }),
        xlb_f("TreeView_GetItemPartRect", [](HWND hwnd, HTREEITEM hitem, RECT* prc, TVITEMPART partid)->auto { TreeView_GetItemPartRect(hwnd, hitem, prc, partid); }),
        xlb_f("TreeView_GetItemRect", [](HWND hwnd, HTREEITEM hitem, LPRECT prc, BOOL code)->auto { return TreeView_GetItemRect(hwnd, hitem, prc, code); }),
        xlb_f("TreeView_GetItemState", [](HWND hwnd, HTREEITEM hitem, UINT mask)->auto { return TreeView_GetItemState(hwnd, hitem, mask); }),
        xlb_f("TreeView_GetLastVisible", [](HWND hwnd)->auto { return TreeView_GetLastVisible(hwnd); }),
        xlb_f("TreeView_GetLineColor", [](HWND hwnd)->auto { return TreeView_GetLineColor(hwnd); }),
        xlb_f("TreeView_GetNextItem", [](HWND hwnd, HTREEITEM hitem, UINT code)->auto { return TreeView_GetNextItem(hwnd, hitem, code); }),
        xlb_f("TreeView_GetNextSelected", [](HWND hwnd, HTREEITEM* hitem)->auto { return TreeView_GetNextSelected(hwnd, hitem); }),
        xlb_f("TreeView_GetNextSibling", [](HWND hwnd, HTREEITEM hitem)->auto { return TreeView_GetNextSibling(hwnd, hitem); }),
        xlb_f("TreeView_GetNextVisible", [](HWND hwnd, HTREEITEM hitem)->auto { return TreeView_GetNextVisible(hwnd, hitem); }),
        xlb_f("TreeView_GetParent", [](HWND hwnd, HTREEITEM hitem)->auto { return TreeView_GetParent(hwnd, hitem); }),
        xlb_f("TreeView_GetPrevSibling", [](HWND hwnd, HTREEITEM hitem)->auto { return TreeView_GetPrevSibling(hwnd, hitem); }),
        xlb_f("TreeView_GetPrevVisible", [](HWND hwnd, HTREEITEM hitem)->auto { return TreeView_GetPrevVisible(hwnd, hitem); }),
        xlb_f("TreeView_GetRoot", [](HWND hwnd)->auto { return TreeView_GetRoot(hwnd); }),
        xlb_f("TreeView_GetScrollTime", [](HWND hwnd)->auto { return TreeView_GetScrollTime(hwnd); }),
        xlb_f("TreeView_GetSelectedCount", [](HWND hwnd)->auto { return TreeView_GetSelectedCount(hwnd); }),
        xlb_f("TreeView_GetSelection", [](HWND hwnd)->auto { return TreeView_GetSelection(hwnd); }),
        xlb_f("TreeView_GetTextColor", [](HWND hwnd)->auto { return TreeView_GetTextColor(hwnd); }),
        xlb_f("TreeView_GetToolTips", [](HWND hwnd)->auto { return TreeView_GetToolTips(hwnd); }),
        xlb_f("TreeView_GetUnicodeFormat", [](HWND hwnd)->auto { return TreeView_GetUnicodeFormat(hwnd); }),
        xlb_f("TreeView_GetVisibleCount", [](HWND hwnd)->auto { return TreeView_GetVisibleCount(hwnd); }),
        xlb_f("TreeView_HitTest", [](HWND hwnd, LPTVHITTESTINFO lpht)->auto { return TreeView_HitTest(hwnd, lpht); }),
        xlb_f("TreeView_InsertItem", [](HWND hwnd, LPTVINSERTSTRUCT lpis)->auto { return TreeView_InsertItem(hwnd, lpis); }),
        xlb_f("TreeView_MapAccIDToHTREEITEM", [](HWND hwnd, UINT id)->auto { return TreeView_MapAccIDToHTREEITEM(hwnd, id); }),
        xlb_f("TreeView_MapHTREEITEMToAccID", [](HWND hwnd, HTREEITEM hitem)->auto { return TreeView_MapHTREEITEMToAccID(hwnd, hitem); }),
        xlb_f("TreeView_Select", [](HWND hwnd, HTREEITEM hitem, UINT code)->auto { return TreeView_Select(hwnd, hitem, code); }),
        xlb_f("TreeView_SelectDropTarget", [](HWND hwnd, HTREEITEM hitem)->auto { return TreeView_SelectDropTarget(hwnd, hitem); }),
        xlb_f("TreeView_SelectItem", [](HWND hwnd, HTREEITEM hitem)->auto { return TreeView_SelectItem(hwnd, hitem); }),
        xlb_f("TreeView_SelectSetFirstVisible", [](HWND hwnd, HTREEITEM hitem)->auto { return TreeView_SelectSetFirstVisible(hwnd, hitem); }),
        xlb_f("TreeView_SetAutoScrollInfo", [](HWND hwnd, UINT uPixperSec, UINT uUpdateTime)->auto { return TreeView_SetAutoScrollInfo(hwnd, uPixperSec, uUpdateTime); }),
        xlb_f("TreeView_SetBkColor", [](HWND hwnd, COLORREF clr)->auto { return TreeView_SetBkColor(hwnd, clr); }),
        xlb_f("TreeView_SetBorder", [](HWND hwnd, DWORD dwFlags, SHORT xBorder, SHORT yBorder)->auto { return TreeView_SetBorder(hwnd, dwFlags, xBorder, yBorder); }),
        xlb_f("TreeView_SetCheckState", [](HWND hwnd, HTREEITEM hitem, BOOL fCheck)->auto { TreeView_SetCheckState(hwnd, hitem, fCheck); }),
        xlb_f("TreeView_SetExtendedStyle", [](HWND hwnd, DWORD dw, UINT mask)->auto { return TreeView_SetExtendedStyle(hwnd, dw, mask); }),
        xlb_f("TreeView_SetHot", [](HWND hwnd, HTREEITEM hitem)->auto { return TreeView_SetHot(hwnd, hitem); }),
        xlb_f("TreeView_SetImageList", [](HWND hwnd, HIMAGELIST himl, INT iImage)->auto { return TreeView_SetImageList(hwnd, himl, iImage); }),
        xlb_f("TreeView_SetIndent", [](HWND hwnd, INT indent)->auto { return TreeView_SetIndent(hwnd, indent); }),
        xlb_f("TreeView_SetInsertMark", [](HWND hwnd, HTREEITEM hitem, BOOL fAfter)->auto { return TreeView_SetInsertMark(hwnd, hitem, fAfter); }),
        xlb_f("TreeView_SetInsertMarkColor", [](HWND hwnd, COLORREF clr)->auto { return TreeView_SetInsertMarkColor(hwnd, clr); }),
        xlb_f("TreeView_SetItem", [](HWND hwnd, LPTVITEM pitem)->auto { return TreeView_SetItem(hwnd, pitem); }),
        xlb_f("TreeView_SetItemHeight", [](HWND hwnd, SHORT iHeight)->auto { return TreeView_SetItemHeight(hwnd, iHeight); }),
        xlb_f("TreeView_SetItemState", [](HWND hwnd, HTREEITEM hitem, UINT data, UINT _mask)->auto { TreeView_SetItemState(hwnd, hitem, data, _mask); }),
        xlb_f("TreeView_SetLineColor", [](HWND hwnd, COLORREF clr)->auto { return TreeView_SetLineColor(hwnd, clr); }),
        xlb_f("TreeView_SetScrollTime", [](HWND hwnd, UINT uTime)->auto { return TreeView_SetScrollTime(hwnd, uTime); }),
        xlb_f("TreeView_SetTextColor", [](HWND hwnd, COLORREF clr)->auto { return TreeView_SetTextColor(hwnd, clr); }),
        xlb_f("TreeView_SetToolTips", [](HWND hwnd, HWND hwndTT)->auto { return TreeView_SetToolTips(hwnd, hwndTT); }),
        xlb_f("TreeView_SetUnicodeFormat", [](HWND hwnd, BOOL fUnicode)->auto { return TreeView_SetUnicodeFormat(hwnd, fUnicode); }),
        xlb_f("TreeView_ShowInfoTip", [](HWND hwnd, HTREEITEM hitem)->auto { return TreeView_ShowInfoTip(hwnd, hitem); }),
        xlb_f("TreeView_SortChildren", [](HWND hwnd, HTREEITEM hitem, BOOL recurse)->auto { return TreeView_SortChildren(hwnd, hitem, recurse); }),
        xlb_f("TreeView_SortChildrenCB", [](HWND hwnd, LPTVSORTCB psort, BOOL recurse)->auto { return TreeView_SortChildrenCB(hwnd, psort, recurse); }),
        

        xlb_class<NMTREEVIEWA>("NMTREEVIEWA") .constructor<>() .destructor()
            .property("hdr", &NMTREEVIEWA::hdr)
            .property("action", &NMTREEVIEWA::action)
            .property("itemOld", &NMTREEVIEWA::itemOld)
            .property("itemNew", &NMTREEVIEWA::itemNew)
            .property("ptDrag", &NMTREEVIEWA::ptDrag)
            ,
#if (_WIN32_IE > 0x0600)
        xlb_class<NMTVASYNCDRAW>("NMTVASYNCDRAW") .constructor<>() .destructor()
            .property("hdr", &NMTVASYNCDRAW::hdr)
            .property("pimldp", &NMTVASYNCDRAW::pimldp)
            .property("hr", &NMTVASYNCDRAW::hr)
            .property("hItem", &NMTVASYNCDRAW::hItem)
            .property("lParam", &NMTVASYNCDRAW::lParam)
            .property("dwRetFlags", &NMTVASYNCDRAW::dwRetFlags)
            .property("iRetImageIndex", &NMTVASYNCDRAW::iRetImageIndex)
            ,
#endif
        xlb_class<NMTVCUSTOMDRAW>("NMTVCUSTOMDRAW") .constructor<>() .destructor()
            .property("nmcd", &NMTVCUSTOMDRAW::nmcd)
            .property("clrText", &NMTVCUSTOMDRAW::clrText)
            .property("clrTextBk", &NMTVCUSTOMDRAW::clrTextBk)
            .property("iLevel", &NMTVCUSTOMDRAW::iLevel)
            ,
        xlb_class<NMTVDISPINFOA>("NMTVDISPINFOA") .constructor<>() .destructor()
            .property("hdr", &NMTVDISPINFOA::hdr)
            .property("item", &NMTVDISPINFOA::item)
            ,
        xlb_class<NMTVDISPINFOEXA>("NMTVDISPINFOEXA") .constructor<>() .destructor()
            .property("hdr", &NMTVDISPINFOEXA::hdr)
            .property("item", &NMTVDISPINFOEXA::item)
            ,
        xlb_class<NMTVGETINFOTIPA>("NMTVGETINFOTIPA") .constructor<>() .destructor()
            .property("hdr", &NMTVGETINFOTIPA::hdr)
            .property("pszText", &NMTVGETINFOTIPA::pszText)
            .property("cchTextMax", &NMTVGETINFOTIPA::cchTextMax)
            .property("hItem", &NMTVGETINFOTIPA::hItem)
            .property("lParam", &NMTVGETINFOTIPA::lParam)
            ,
        xlb_class<NMTVITEMCHANGE>("NMTVITEMCHANGE") .constructor<>() .destructor()
            .property("hdr", &NMTVITEMCHANGE::hdr)
            .property("uChanged", &NMTVITEMCHANGE::uChanged)
            .property("hItem", &NMTVITEMCHANGE::hItem)
            .property("uStateNew", &NMTVITEMCHANGE::uStateNew)
            .property("uStateOld", &NMTVITEMCHANGE::uStateOld)
            .property("lParam", &NMTVITEMCHANGE::lParam)
            ,
        // NMTVITEMRECT // unsupported
        xlb_class<NMTVKEYDOWN>("NMTVKEYDOWN") .constructor<>() .destructor()
            .property("hdr", &NMTVKEYDOWN::hdr)
            .property("wVKey", &NMTVKEYDOWN::wVKey)
            .property("flags", &NMTVKEYDOWN::flags)
            ,
        xlb_class<NMTVSTATEIMAGECHANGING>("NMTVSTATEIMAGECHANGING") .constructor<>() .destructor()
            .property("hdr", &NMTVSTATEIMAGECHANGING::hdr)
            .property("hti", &NMTVSTATEIMAGECHANGING::hti)
            .property("iOldStateImageIndex", &NMTVSTATEIMAGECHANGING::iOldStateImageIndex)
            .property("iNewStateImageIndex", &NMTVSTATEIMAGECHANGING::iNewStateImageIndex)
            ,
        xlb_class<TVGETITEMPARTRECTINFO>("TVGETITEMPARTRECTINFO") .constructor<>() .destructor()
            .property("hti", &TVGETITEMPARTRECTINFO::hti)
            .property("prc", &TVGETITEMPARTRECTINFO::prc)
            .property("partID", &TVGETITEMPARTRECTINFO::partID)
            ,
        xlb_class<TVHITTESTINFO>("TVHITTESTINFO") .constructor<>() .destructor()
            .property("pt", &TVHITTESTINFO::pt)
            .property("flags", &TVHITTESTINFO::flags)
            .property("hItem", &TVHITTESTINFO::hItem)
            ,
        xlb_class<TVINSERTSTRUCTA>("TVINSERTSTRUCTA") .constructor<>() .destructor()
            .property("hParent", &TVINSERTSTRUCTA::hParent)
            .property("hInsertAfter", &TVINSERTSTRUCTA::hInsertAfter)
            .property("itemex", &TVINSERTSTRUCTA::itemex)
            .property("item", &TVINSERTSTRUCTA::item)
            ,
        xlb_class<TVITEMA>("TVITEMA") .constructor<>() .destructor()
            .property("mask", &TVITEMA::mask)
            .property("hItem", &TVITEMA::hItem)
            .property("state", &TVITEMA::state)
            .property("stateMask", &TVITEMA::stateMask)
            .property("pszText", &TVITEMA::pszText)
            .property("cchTextMax", &TVITEMA::cchTextMax)
            .property("iImage", &TVITEMA::iImage)
            .property("iSelectedImage", &TVITEMA::iSelectedImage)
            .property("cChildren", &TVITEMA::cChildren)
            .property("lParam", &TVITEMA::lParam)
            ,
        xlb_class<TVITEMEXA>("TVITEMEXA") .constructor<>() .destructor()
            .property("mask", &TVITEMEXA::mask)
            .property("hItem", &TVITEMEXA::hItem)
            .property("state", &TVITEMEXA::state)
            .property("stateMask", &TVITEMEXA::stateMask)
            .property("pszText", &TVITEMEXA::pszText)
            .property("cchTextMax", &TVITEMEXA::cchTextMax)
            .property("iImage", &TVITEMEXA::iImage)
            .property("iSelectedImage", &TVITEMEXA::iSelectedImage)
            .property("cChildren", &TVITEMEXA::cChildren)
            .property("lParam", &TVITEMEXA::lParam)
            .property("iIntegral", &TVITEMEXA::iIntegral)
            .property("uStateEx", &TVITEMEXA::uStateEx)
            .property("hwnd", &TVITEMEXA::hwnd)
            .property("iExpandedImage", &TVITEMEXA::iExpandedImage)
            .property("iReserved", &TVITEMEXA::iReserved)
            ,
        xlb_class<TVSORTCB>("TVSORTCB") .constructor<>() .destructor()
            .property("hParent", &TVSORTCB::hParent)
            .property("lpfnCompare", &TVSORTCB::lpfnCompare)
            .property("lParam", &TVSORTCB::lParam)
            ,

        xlb_const("TVM_CREATEDRAGIMAGE", TVM_CREATEDRAGIMAGE),
        xlb_const("TVM_DELETEITEM", TVM_DELETEITEM),
        xlb_const("TVM_EDITLABEL", TVM_EDITLABEL),
        xlb_const("TVM_ENDEDITLABELNOW", TVM_ENDEDITLABELNOW),
        xlb_const("TVM_ENSUREVISIBLE", TVM_ENSUREVISIBLE),
        xlb_const("TVM_EXPAND", TVM_EXPAND),
        xlb_const("TVM_GETBKCOLOR", TVM_GETBKCOLOR),
        xlb_const("TVM_GETCOUNT", TVM_GETCOUNT),
        xlb_const("TVM_GETEDITCONTROL", TVM_GETEDITCONTROL),
        xlb_const("TVM_GETEXTENDEDSTYLE", TVM_GETEXTENDEDSTYLE),
        xlb_const("TVM_GETIMAGELIST", TVM_GETIMAGELIST),
        xlb_const("TVM_GETINDENT", TVM_GETINDENT),
        xlb_const("TVM_GETINSERTMARKCOLOR", TVM_GETINSERTMARKCOLOR),
        xlb_const("TVM_GETISEARCHSTRING", TVM_GETISEARCHSTRING),
        xlb_const("TVM_GETITEM", TVM_GETITEM),
        xlb_const("TVM_GETITEMHEIGHT", TVM_GETITEMHEIGHT),
        xlb_const("TVM_GETITEMPARTRECT", TVM_GETITEMPARTRECT),
        xlb_const("TVM_GETITEMRECT", TVM_GETITEMRECT),
        xlb_const("TVM_GETITEMSTATE", TVM_GETITEMSTATE),
        xlb_const("TVM_GETLINECOLOR", TVM_GETLINECOLOR),
        xlb_const("TVM_GETNEXTITEM", TVM_GETNEXTITEM),
        xlb_const("TVM_GETSCROLLTIME", TVM_GETSCROLLTIME),
        xlb_const("TVM_GETSELECTEDCOUNT", TVM_GETSELECTEDCOUNT),
        xlb_const("TVM_GETTEXTCOLOR", TVM_GETTEXTCOLOR),
        xlb_const("TVM_GETTOOLTIPS", TVM_GETTOOLTIPS),
        xlb_const("TVM_GETUNICODEFORMAT", TVM_GETUNICODEFORMAT),
        xlb_const("TVM_GETVISIBLECOUNT", TVM_GETVISIBLECOUNT),
        xlb_const("TVM_HITTEST", TVM_HITTEST),
        xlb_const("TVM_INSERTITEM", TVM_INSERTITEM),
        xlb_const("TVM_MAPACCIDTOHTREEITEM", TVM_MAPACCIDTOHTREEITEM),
        xlb_const("TVM_MAPHTREEITEMTOACCID", TVM_MAPHTREEITEMTOACCID),
        xlb_const("TVM_SELECTITEM", TVM_SELECTITEM),
        xlb_const("TVM_SETAUTOSCROLLINFO", TVM_SETAUTOSCROLLINFO),
        xlb_const("TVM_SETBKCOLOR", TVM_SETBKCOLOR),
        xlb_const("TVM_SETBORDER", TVM_SETBORDER),
        xlb_const("TVM_SETEXTENDEDSTYLE", TVM_SETEXTENDEDSTYLE),
        xlb_const("TVM_SETHOT", TVM_SETHOT),
        xlb_const("TVM_SETIMAGELIST", TVM_SETIMAGELIST),
        xlb_const("TVM_SETINDENT", TVM_SETINDENT),
        xlb_const("TVM_SETINSERTMARK", TVM_SETINSERTMARK),
        xlb_const("TVM_SETINSERTMARKCOLOR", TVM_SETINSERTMARKCOLOR),
        xlb_const("TVM_SETITEM", TVM_SETITEM),
        xlb_const("TVM_SETITEMHEIGHT", TVM_SETITEMHEIGHT),
        xlb_const("TVM_SETLINECOLOR", TVM_SETLINECOLOR),
        xlb_const("TVM_SETSCROLLTIME", TVM_SETSCROLLTIME),
        xlb_const("TVM_SETTEXTCOLOR", TVM_SETTEXTCOLOR),
        xlb_const("TVM_SETTOOLTIPS", TVM_SETTOOLTIPS),
        xlb_const("TVM_SETUNICODEFORMAT", TVM_SETUNICODEFORMAT),
        xlb_const("TVM_SHOWINFOTIP", TVM_SHOWINFOTIP),
        xlb_const("TVM_SORTCHILDREN", TVM_SORTCHILDREN),
        xlb_const("TVM_SORTCHILDRENCB", TVM_SORTCHILDRENCB),
        xlb_const("NM_CLICK", NM_CLICK),
        xlb_const("NM_CUSTOMDRAW", NM_CUSTOMDRAW),
        xlb_const("NM_DBLCLK", NM_DBLCLK),
        xlb_const("NM_KILLFOCUS", NM_KILLFOCUS),
        xlb_const("NM_RCLICK", NM_RCLICK),
        xlb_const("NM_RDBLCLK", NM_RDBLCLK),
        xlb_const("NM_RETURN", NM_RETURN),
        xlb_const("NM_SETCURSOR", NM_SETCURSOR),
        xlb_const("NM_SETFOCUS", NM_SETFOCUS),
        xlb_const("TVN_ASYNCDRAW", TVN_ASYNCDRAW),
        xlb_const("TVN_BEGINDRAG", TVN_BEGINDRAG),
        xlb_const("TVN_BEGINLABELEDIT", TVN_BEGINLABELEDIT),
        xlb_const("TVN_BEGINRDRAG", TVN_BEGINRDRAG),
        xlb_const("TVN_DELETEITEM", TVN_DELETEITEM),
        xlb_const("TVN_ENDLABELEDIT", TVN_ENDLABELEDIT),
        xlb_const("TVN_GETDISPINFO", TVN_GETDISPINFO),
        xlb_const("TVN_GETINFOTIP", TVN_GETINFOTIP),
        xlb_const("TVN_ITEMCHANGED", TVN_ITEMCHANGED),
        xlb_const("TVN_ITEMCHANGING", TVN_ITEMCHANGING),
        xlb_const("TVN_ITEMEXPANDED", TVN_ITEMEXPANDED),
        xlb_const("TVN_ITEMEXPANDING", TVN_ITEMEXPANDING),
        xlb_const("TVN_KEYDOWN", TVN_KEYDOWN),
        xlb_const("TVN_SELCHANGED", TVN_SELCHANGED),
        xlb_const("TVN_SELCHANGING", TVN_SELCHANGING),
        xlb_const("TVN_SETDISPINFO", TVN_SETDISPINFO),
        xlb_const("TVN_SINGLEEXPAND", TVN_SINGLEEXPAND),
    
        xlb_const("TVS_EX_AUTOHSCROLL", TVS_EX_AUTOHSCROLL),
        xlb_const("TVS_EX_DIMMEDCHECKBOXES", TVS_EX_DIMMEDCHECKBOXES),
        xlb_const("TVS_EX_DOUBLEBUFFER", TVS_EX_DOUBLEBUFFER),
        xlb_const("TVS_EX_DRAWIMAGEASYNC", TVS_EX_DRAWIMAGEASYNC),
        xlb_const("TVS_EX_EXCLUSIONCHECKBOXES", TVS_EX_EXCLUSIONCHECKBOXES),
        xlb_const("TVS_EX_FADEINOUTEXPANDOS", TVS_EX_FADEINOUTEXPANDOS),
        xlb_const("TVS_EX_MULTISELECT", TVS_EX_MULTISELECT),
        xlb_const("TVS_EX_NOINDENTSTATE", TVS_EX_NOINDENTSTATE),
        xlb_const("TVS_EX_NOSINGLECOLLAPSE", TVS_EX_NOSINGLECOLLAPSE),
        xlb_const("TVS_EX_PARTIALCHECKBOXES", TVS_EX_PARTIALCHECKBOXES),
        xlb_const("TVS_EX_RICHTOOLTIP", TVS_EX_RICHTOOLTIP),
        xlb_const("TVIS_BOLD", TVIS_BOLD),
        xlb_const("TVIS_CUT", TVIS_CUT),
        xlb_const("TVIS_DROPHILITED", TVIS_DROPHILITED),
        xlb_const("TVIS_EXPANDED", TVIS_EXPANDED),
        xlb_const("TVIS_EXPANDEDONCE", TVIS_EXPANDEDONCE),
        xlb_const("TVIS_EXPANDPARTIAL", TVIS_EXPANDPARTIAL),
        xlb_const("TVIS_SELECTED", TVIS_SELECTED),
        xlb_const("TVIS_OVERLAYMASK", TVIS_OVERLAYMASK),
        xlb_const("TVIS_STATEIMAGEMASK", TVIS_STATEIMAGEMASK),
        xlb_const("TVIS_USERMASK", TVIS_USERMASK),
        xlb_const("TVS_CHECKBOXES", TVS_CHECKBOXES),
        xlb_const("TVS_DISABLEDRAGDROP", TVS_DISABLEDRAGDROP),
        xlb_const("TVS_EDITLABELS", TVS_EDITLABELS),
        xlb_const("TVS_FULLROWSELECT", TVS_FULLROWSELECT),
        xlb_const("TVS_HASBUTTONS", TVS_HASBUTTONS),
        xlb_const("TVS_HASLINES", TVS_HASLINES),
        xlb_const("TVS_INFOTIP", TVS_INFOTIP),
        xlb_const("TVS_LINESATROOT", TVS_LINESATROOT),
        xlb_const("TVS_NOHSCROLL", TVS_NOHSCROLL),
        xlb_const("TVS_NONEVENHEIGHT", TVS_NONEVENHEIGHT),
        xlb_const("TVS_NOSCROLL", TVS_NOSCROLL),
        xlb_const("TVS_NOTOOLTIPS", TVS_NOTOOLTIPS),
        xlb_const("TVS_RTLREADING", TVS_RTLREADING),
        xlb_const("TVS_SHOWSELALWAYS", TVS_SHOWSELALWAYS),
        xlb_const("TVS_SINGLEEXPAND", TVS_SINGLEEXPAND),
        xlb_const("TVS_TRACKSELECT", TVS_TRACKSELECT),

        xlb_const("TVSIL_NORMAL", TVSIL_NORMAL),
        xlb_const("TVSIL_STATE", TVSIL_STATE),
        xlb_const("TVGN_CARET", TVGN_CARET),
        xlb_const("TVGN_CHILD", TVGN_CHILD),
        xlb_const("TVGN_DROPHILITE", TVGN_DROPHILITE),
        xlb_const("TVGN_FIRSTVISIBLE", TVGN_FIRSTVISIBLE),
        xlb_const("TVGN_NEXT", TVGN_NEXT),
        xlb_const("TVGN_NEXTSELECTED", TVGN_NEXTSELECTED),
        xlb_const("TVGN_NEXTVISIBLE", TVGN_NEXTVISIBLE),
        xlb_const("TVGN_PARENT", TVGN_PARENT),
        xlb_const("TVGN_PREVIOUS", TVGN_PREVIOUS),
        xlb_const("TVGN_PREVIOUSVISIBLE", TVGN_PREVIOUSVISIBLE),
        xlb_const("TVGN_ROOT", TVGN_ROOT),
        xlb_const("TVGN_CARET", TVGN_CARET),
        xlb_const("TVGN_DROPHILITE", TVGN_DROPHILITE),
        xlb_const("TVGN_FIRSTVISIBLE", TVGN_FIRSTVISIBLE),
        xlb_const("TVSBF_XBORDER", TVSBF_XBORDER),
        xlb_const("TVSBF_YBORDER", TVSBF_YBORDER),
        xlb_const("TVSIL_NORMAL", TVSIL_NORMAL),
        xlb_const("TVSIL_STATE", TVSIL_STATE),
        //xlb_const("ADRF_DRAWIMAGE", ADRF_DRAWIMAGE), //FIXME: undeclared
        //xlb_const("ADRF_DRAWSYNC", ADRF_DRAWSYNC),
        //xlb_const("ADRF_DRAWNOTHING", ADRF_DRAWNOTHING),

        // Up-Down Control
        xlb_f("CreateUpDownControl", CreateUpDownControl),
        xlb_class<NMUPDOWN>("NMUPDOWN") .constructor<>() .destructor()
            .property("hdr", &NMUPDOWN::hdr)
            .property("iPos", &NMUPDOWN::iPos)
            .property("iDelta", &NMUPDOWN::iDelta)
            ,
        xlb_class<UDACCEL>("UDACCEL") .constructor<>() .destructor()
            .property("nSec", &UDACCEL::nSec)
            .property("nInc", &UDACCEL::nInc)
            ,
        xlb_const("UDM_GETACCEL", UDM_GETACCEL),
        xlb_const("UDM_GETBASE", UDM_GETBASE),
        xlb_const("UDM_GETBUDDY", UDM_GETBUDDY),
        xlb_const("UDM_GETPOS", UDM_GETPOS),
        xlb_const("UDM_GETPOS32", UDM_GETPOS32),
        xlb_const("UDM_GETRANGE", UDM_GETRANGE),
        xlb_const("UDM_GETRANGE32", UDM_GETRANGE32),
        xlb_const("UDM_GETUNICODEFORMAT", UDM_GETUNICODEFORMAT),
        xlb_const("UDM_SETACCEL", UDM_SETACCEL),
        xlb_const("UDM_SETBASE", UDM_SETBASE),
        xlb_const("UDM_SETBUDDY", UDM_SETBUDDY),
        xlb_const("UDM_SETPOS", UDM_SETPOS),
        xlb_const("UDM_SETPOS32", UDM_SETPOS32),
        xlb_const("UDM_SETRANGE", UDM_SETRANGE),
        xlb_const("UDM_SETRANGE32", UDM_SETRANGE32),
        xlb_const("UDM_SETUNICODEFORMAT", UDM_SETUNICODEFORMAT),
        xlb_const("NM_RELEASEDCAPTURE", NM_RELEASEDCAPTURE),
        xlb_const("UDN_DELTAPOS", UDN_DELTAPOS),
        xlb_const("UDS_ALIGNLEFT", UDS_ALIGNLEFT),
        xlb_const("UDS_ALIGNRIGHT", UDS_ALIGNRIGHT),
        xlb_const("UDS_ARROWKEYS", UDS_ARROWKEYS),
        xlb_const("UDS_AUTOBUDDY", UDS_AUTOBUDDY),
        xlb_const("UDS_HORZ", UDS_HORZ),
        xlb_const("UDS_HOTTRACK", UDS_HOTTRACK),
        xlb_const("UDS_NOTHOUSANDS", UDS_NOTHOUSANDS),
        xlb_const("UDS_SETBUDDYINT", UDS_SETBUDDYINT),
        xlb_const("UDS_WRAP", UDS_WRAP),
    
        // General Control Reference
        //xlb_f("DoReaderMode", DoReaderMode), // unavailable
        xlb_f("DPA_Clone", DPA_Clone),
        xlb_f("DPA_Create", DPA_Create),
        xlb_f("DPA_CreateEx", DPA_CreateEx),
        xlb_f("DPA_DeleteAllPtrs", DPA_DeleteAllPtrs),
        xlb_f("DPA_DeletePtr", DPA_DeletePtr),
        xlb_f("DPA_Destroy", DPA_Destroy),
        xlb_class<xlb_cbf<DPA_DestroyCallback_t>>("DPA_DestroyCallback").constructor<xlb_luafunc>(),
        xlb_class<xlb_cbf<DPA_EnumCallback_t>>("DPA_EnumCallback").constructor<xlb_luafunc>(),
        xlb_f("DPA_GetPtr", DPA_GetPtr),
        xlb_f("DPA_GetPtrIndex", DPA_GetPtrIndex),
        xlb_f("DPA_GetSize", DPA_GetSize),
        xlb_f("DPA_Grow", DPA_Grow),
        xlb_f("DPA_InsertPtr", DPA_InsertPtr),
        xlb_f("DPA_LoadStream", DPA_LoadStream),
        xlb_f<DPA_Merge_t>("DPA_Merge", DPA_Merge),
        xlb_f("DPA_SaveStream", DPA_SaveStream),
        xlb_f<DPA_Search_t>("DPA_Search", DPA_Search),
        xlb_f("DPA_SetPtr", DPA_SetPtr),
        xlb_f<DPA_Sort_t>("DPA_Sort", DPA_Sort),
        xlb_f("DrawShadowText", DrawShadowText),
        //xlb_f("DrawTextExPrivWrap", DrawTextExPrivWrap), // not recommended
        //xlb_f("DrawTextWrap", DrawTextWrap), // not recommended
        xlb_f("DSA_Clone", DSA_Clone),
        xlb_f("DSA_Create", DSA_Create),
        xlb_f("DSA_DeleteAllItems", DSA_DeleteAllItems),
        xlb_f("DSA_DeleteItem", DSA_DeleteItem),
        xlb_f("DSA_Destroy", DSA_Destroy),
        xlb_class<xlb_cbf<DPA_EnumCallback_t>>("DSA_DestroyCallback").constructor<xlb_luafunc>(),
        xlb_class<xlb_cbf<DSA_EnumCallback_t>>("DSA_EnumCallback").constructor<xlb_luafunc>(),
        xlb_f("DSA_GetItem", DSA_GetItem),
        xlb_f("DSA_GetItemPtr", DSA_GetItemPtr),
        xlb_f("DSA_GetSize", DSA_GetSize),
        xlb_f("DSA_InsertItem", DSA_InsertItem),
        xlb_f("DSA_SetItem", DSA_SetItem),
        xlb_f<DSA_Sort_t>("DSA_Sort", DSA_Sort),
        //xlb_f("ExtTextOutWrap", ExtTextOutWrap), // not recommended
        xlb_f("GetEffectiveClientRect", GetEffectiveClientRect),
        xlb_f("GetMUILanguage", GetMUILanguage),
        //xlb_f("GetTextExtentPoint32Wrap", GetTextExtentPoint32Wrap), // not recommended
        xlb_f("InitCommonControls", InitCommonControls),
        xlb_f("InitCommonControlsEx", InitCommonControlsEx),
        xlb_f("InitMUILanguage", InitMUILanguage),
        xlb_f("LoadIconMetric", LoadIconMetric),
        xlb_f("LoadIconWithScaleDown", LoadIconWithScaleDown),
        //xlb_f("MirrorIcon", MirrorIcon), // FIXME: 414, comctl32.dll
        xlb_class<xlb_cbf<PFNDACOMPARE>>("PFNDACOMPARE").constructor<xlb_luafunc>(),
        xlb_class<xlb_cbf<PFNDACOMPARECONST>>("PFNDACOMPARECONST").constructor<xlb_luafunc>(),
        xlb_class<xlb_cbf<PFNDAENUMCALLBACK>>("PFNDAENUMCALLBACK").constructor<xlb_luafunc>(),
        xlb_class<xlb_cbf<PFNDAENUMCALLBACKCONST>>("PFNDAENUMCALLBACKCONST").constructor<xlb_luafunc>(),
        xlb_class<xlb_cbf<PFNDPACOMPARE>>("PFNDPACOMPARE").constructor<xlb_luafunc>(),
        xlb_class<xlb_cbf<PFNDPACOMPARECONST>>("PFNDPACOMPARECONST").constructor<xlb_luafunc>(),
        xlb_class<xlb_cbf<PFNDPAENUMCALLBACK>>("PFNDPAENUMCALLBACK").constructor<xlb_luafunc>(),
        xlb_class<xlb_cbf<PFNDPAMERGE>>("PFNDPAMERGE").constructor<xlb_luafunc>(),
        xlb_class<xlb_cbf<PFNDPAMERGECONST>>("PFNDPAMERGECONST").constructor<xlb_luafunc>(),
        xlb_class<xlb_cbf<PFNDPASTREAM>>("PFNDPASTREAM").constructor<xlb_luafunc>(),
        xlb_class<xlb_cbf<PFNDSAENUMCALLBACK>>("PFNDSAENUMCALLBACK").constructor<xlb_luafunc>(),
        //xlb_class<xlb_cbf<ReaderScrollCallback>>("ReaderScroll").constructor<xlb_luafunc>(), // unavailable
        xlb_f("ShowHideMenuCtl", ShowHideMenuCtl),
        //xlb_f("Str_GetPtr", Str_GetPtr), // unavailable, 233 Str_GetPtrA, 235 Str_GetPtrW comctl32.dll
        xlb_f("Str_SetPtrW", Str_SetPtrW),
        //xlb_class<xlb_cbf<TranslateDispatchCallback>>("TranslateDispatch").constructor<xlb_luafunc>(), // unavailable

        xlb_f("DPA_AppendPtr", [](HDPA hdpa, void* pitem)->auto { return DPA_AppendPtr(hdpa, pitem); }),
        xlb_f("DPA_FastDeleteLastPtr", [](HDPA hdpa)->auto { return DPA_FastDeleteLastPtr(hdpa); }),
        xlb_f("DPA_FastGetPtr", [](HDPA hdpa, int i)->auto { return DPA_FastGetPtr(hdpa, i); }),
        xlb_f("DPA_GetPtrCount", [](HDPA hdpa)->auto { return DPA_GetPtrCount(hdpa); }),
        xlb_f("DPA_GetPtrPtr", [](HDPA hdpa)->auto { return DPA_GetPtrPtr(hdpa); }),
        xlb_f("DPA_SetPtrCount", [](HDPA hdpa, UINT cItems)->auto { return DPA_SetPtrCount(hdpa, cItems); }),
        xlb_f("DPA_SortedInsertPtr", [](HDPA hdpa, void* pFind, int iStart, PFNDPACOMPARE pfnCompare, LPARAM lParam, UINT options, void* pitem)->auto { return DPA_SortedInsertPtr(hdpa, pFind, iStart, pfnCompare, lParam, options, pitem); }),
        xlb_f("DSA_AppendItem", [](HDSA hdsa, void* pitem)->auto { return DSA_AppendItem(hdsa, pitem); }),
        xlb_f("DSA_GetItemCount", [](HDSA hdsa)->auto { return DSA_GetItemCount(hdsa); }),
        xlb_f("FORWARD_WM_NOTIFY", [](HWND hwnd, int idFrom, NMHDR* pnmhdr, LRESULT (*fn)(HWND,UINT,WPARAM,LPARAM) )->auto { return FORWARD_WM_NOTIFY(hwnd, idFrom, pnmhdr, fn); }),
        xlb_f("HANDLE_WM_NOTIFY", [](HWND hwnd, WPARAM wParam, LPARAM lParam, LRESULT (*fn)(HWND,WPARAM,NMHDR*))->auto { return HANDLE_WM_NOTIFY(hwnd, wParam, lParam, fn); }),
        xlb_f("INDEXTOSTATEIMAGEMASK", [](UINT i)->auto { return INDEXTOSTATEIMAGEMASK(i); }),

        xlb_class<COLORSCHEME>("COLORSCHEME") .constructor<>() .destructor()
            .property("dwSize", &COLORSCHEME::dwSize)
            .property("clrBtnHighlight", &COLORSCHEME::clrBtnHighlight)
            .property("clrBtnShadow", &COLORSCHEME::clrBtnShadow)
            ,
        xlb_class<DPASTREAMINFO>("DPASTREAMINFO") .constructor<>() .destructor()
            .property("iPos", &DPASTREAMINFO::iPos)
            .property("pvItem", &DPASTREAMINFO::pvItem)
            ,
        xlb_class<INITCOMMONCONTROLSEX>("INITCOMMONCONTROLSEX") .constructor<>() .destructor()
            .property("dwSize", &INITCOMMONCONTROLSEX::dwSize)
            .property("dwICC", &INITCOMMONCONTROLSEX::dwICC)
            ,
        xlb_class<NMCHAR>("NMCHAR") .constructor<>() .destructor()
            .property("hdr", &NMCHAR::hdr)
            .property("ch", &NMCHAR::ch)
            .property("dwItemPrev", &NMCHAR::dwItemPrev)
            .property("dwItemNext", &NMCHAR::dwItemNext)
            ,
        xlb_class<NMCUSTOMSPLITRECTINFO>("NMCUSTOMSPLITRECTINFO") .constructor<>() .destructor()
            .property("hdr", &NMCUSTOMSPLITRECTINFO::hdr)
            .property("rcClient", &NMCUSTOMSPLITRECTINFO::rcClient)
            .property("rcButton", &NMCUSTOMSPLITRECTINFO::rcButton)
            .property("rcSplit", &NMCUSTOMSPLITRECTINFO::rcSplit)
            ,
        xlb_class<NMCUSTOMTEXT>("NMCUSTOMTEXT") .constructor<>() .destructor()
            .property("hdr", &NMCUSTOMTEXT::hdr)
            .property("hDC", &NMCUSTOMTEXT::hDC)
            .property("lpString", &NMCUSTOMTEXT::lpString)
            .property("nCount", &NMCUSTOMTEXT::nCount)
            .property("lpRect", &NMCUSTOMTEXT::lpRect)
            .property("uFormat", &NMCUSTOMTEXT::uFormat)
            .property("fLink", &NMCUSTOMTEXT::fLink)
            ,
        xlb_class<NMHDR>("NMHDR") .constructor<>() .destructor()
            .property("hwndFrom", &NMHDR::hwndFrom)
            .property("idFrom", &NMHDR::idFrom)
            .property("code", &NMHDR::code)
            ,
        xlb_class<NMKEY>("NMKEY") .constructor<>() .destructor()
            .property("hdr", &NMKEY::hdr)
            .property("nVKey", &NMKEY::nVKey)
            .property("uFlags", &NMKEY::uFlags)
            ,
        xlb_class<NMMOUSE>("NMMOUSE") .constructor<>() .destructor()
            .property("hdr", &NMMOUSE::hdr)
            .property("dwItemSpec", &NMMOUSE::dwItemSpec)
            .property("dwItemData", &NMMOUSE::dwItemData)
            .property("pt", &NMMOUSE::pt)
            .property("dwHitInfo", &NMMOUSE::dwHitInfo)
            ,
        xlb_class<NMOBJECTNOTIFY>("NMOBJECTNOTIFY") .constructor<>() .destructor()
            .property("hdr", &NMOBJECTNOTIFY::hdr)
            .property("iItem", &NMOBJECTNOTIFY::iItem)
            .property("piid", &NMOBJECTNOTIFY::piid)
            .property("pObject", &NMOBJECTNOTIFY::pObject)
            .property("hResult", &NMOBJECTNOTIFY::hResult)
            .property("dwFlags", &NMOBJECTNOTIFY::dwFlags)
            ,
        xlb_class<NMTOOLTIPSCREATED>("NMTOOLTIPSCREATED") .constructor<>() .destructor()
            .property("hdr", &NMTOOLTIPSCREATED::hdr)
            .property("hwndToolTips", &NMTOOLTIPSCREATED::hwndToolTips)
            ,
        // unsupported
        //xlb_class<READERMODEINFO>("READERMODEINFO") .constructor<>() .destructor()
        //    .property("cbSize", &READERMODEINFO::cbSize)
        //    .property("hwnd", &READERMODEINFO::hwnd)
        //    .property("fFlags", &READERMODEINFO::fFlags)
        //    .property("prc", &READERMODEINFO::prc)
        //    .property("pfnScroll", &READERMODEINFO::pfnScroll)
        //    .property("fFlags", &READERMODEINFO::fFlags)
        //    .property("lParam", &READERMODEINFO::lParam)
        //    ,

        xlb_const("CCM_DPISCALE", CCM_DPISCALE),
        xlb_const("CCM_GETUNICODEFORMAT", CCM_GETUNICODEFORMAT),
        xlb_const("CCM_GETVERSION", CCM_GETVERSION),
        xlb_const("CCM_SETUNICODEFORMAT", CCM_SETUNICODEFORMAT),
        xlb_const("CCM_SETVERSION", CCM_SETVERSION),
        xlb_const("CCM_SETWINDOWTHEME", CCM_SETWINDOWTHEME),
        xlb_const("WM_NOTIFY", WM_NOTIFY),
        xlb_const("WM_NOTIFYFORMAT", WM_NOTIFYFORMAT),
        xlb_const("NM_CHAR", NM_CHAR),
        xlb_const("NM_CUSTOMDRAW", NM_CUSTOMDRAW),
        xlb_const("NM_CUSTOMTEXT", NM_CUSTOMTEXT),
        xlb_const("NM_FONTCHANGED", NM_FONTCHANGED),
        xlb_const("NM_GETCUSTOMSPLITRECT", NM_GETCUSTOMSPLITRECT),
        xlb_const("NM_HOVER", NM_HOVER),
        xlb_const("NM_KEYDOWN", NM_KEYDOWN),
        xlb_const("NM_KILLFOCUS", NM_KILLFOCUS),
        xlb_const("NM_LDOWN", NM_LDOWN),
        xlb_const("NM_NCHITTEST", NM_NCHITTEST),
        xlb_const("NM_OUTOFMEMORY", NM_OUTOFMEMORY),
        xlb_const("NM_RDOWN", NM_RDOWN),
        xlb_const("NM_RELEASEDCAPTURE", NM_RELEASEDCAPTURE),
        xlb_const("NM_RETURN", NM_RETURN),
        xlb_const("NM_SETCURSOR", NM_SETCURSOR),
        xlb_const("NM_SETFOCUS", NM_SETFOCUS),
        xlb_const("NM_THEMECHANGED", NM_THEMECHANGED),
        xlb_const("NM_TOOLTIPSCREATED", NM_TOOLTIPSCREATED),
        xlb_const("NM_TVSTATEIMAGECHANGING", NM_TVSTATEIMAGECHANGING),

        xlb_const("DPAS_INSERTBEFORE", DPAS_INSERTBEFORE),
        xlb_const("DPAS_INSERTAFTER", DPAS_INSERTAFTER),
        xlb_const("ICC_ANIMATE_CLASS", ICC_ANIMATE_CLASS),
        xlb_const("ICC_BAR_CLASSES", ICC_BAR_CLASSES),
        xlb_const("ICC_COOL_CLASSES", ICC_COOL_CLASSES),
        xlb_const("ICC_DATE_CLASSES", ICC_DATE_CLASSES),
        xlb_const("ICC_HOTKEY_CLASS", ICC_HOTKEY_CLASS),
        xlb_const("ICC_INTERNET_CLASSES", ICC_INTERNET_CLASSES),
        xlb_const("ICC_LINK_CLASS", ICC_LINK_CLASS),
        xlb_const("ICC_LISTVIEW_CLASSES", ICC_LISTVIEW_CLASSES),
        xlb_const("ICC_NATIVEFNTCTL_CLASS", ICC_NATIVEFNTCTL_CLASS),
        xlb_const("ICC_PAGESCROLLER_CLASS", ICC_PAGESCROLLER_CLASS),
        xlb_const("ICC_PROGRESS_CLASS", ICC_PROGRESS_CLASS),
        xlb_const("ICC_STANDARD_CLASSES", ICC_STANDARD_CLASSES),
        xlb_const("ICC_TAB_CLASSES", ICC_TAB_CLASSES),
        xlb_const("ICC_TREEVIEW_CLASSES", ICC_TREEVIEW_CLASSES),
        xlb_const("ICC_UPDOWN_CLASS", ICC_UPDOWN_CLASS),
        xlb_const("ICC_USEREX_CLASSES", ICC_USEREX_CLASSES),
        xlb_const("ICC_WIN95_CLASSES", ICC_WIN95_CLASSES),
        // unsupported
        //xlb_const("RMF_ZEROCURSOR", RMF_ZEROCURSOR),
        //xlb_const("RMF_VERTICALONLY", RMF_VERTICALONLY),
        //xlb_const("RMF_HORIZONTALONLY", RMF_HORIZONTALONLY),

        // Network Management
        xlb_const("DSREG_UNKNOWN_JOIN", DSREG_UNKNOWN_JOIN),
        xlb_const("DSREG_DEVICE_JOIN", DSREG_DEVICE_JOIN),
        xlb_const("DSREG_WORKPLACE_JOIN", DSREG_WORKPLACE_JOIN),

#ifdef compile
#endif

#endif // 0x0600

        xlb_const("CHECK_BIND_CTRL", CHECK_BIND_CTRL)
    }); // module
#endif // defined(CHECK_BIND_CTRL)

    return 0;
} // load_ctrl
