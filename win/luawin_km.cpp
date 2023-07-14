#include "luawin.h"

//------------------------------------------------------------------------------------------------
int load_km(lua_State *L) {
#if defined(BIND_KM)
  xlb_module(L, MODULE_NAME)(
      {xlb_f("_TrackMouseEvent", _TrackMouseEvent),
       xlb_f("ActivateKeyboardLayout", ActivateKeyboardLayout),
       xlb_f("BlockInput", BlockInput),
       xlb_f("DefRawInputProc", DefRawInputProc),
       xlb_f("DragDetect", DragDetect), xlb_f("EnableWindow", EnableWindow),
       xlb_f(
           "GET_APPCOMMAND_LPARAM",
           [](LPARAM lp) -> auto { return GET_APPCOMMAND_LPARAM(lp); }),
       xlb_f(
           "GET_DEVICE_LPARAM",
           [](LPARAM lp) -> auto { return GET_DEVICE_LPARAM(lp); }),
       xlb_f(
           "GET_FLAGS_LPARAM",
           [](LPARAM lp) -> auto { return GET_FLAGS_LPARAM(lp); }),
       xlb_f(
           "GET_KEYSTATE_LPARAM",
           [](LPARAM lp) -> auto { return GET_KEYSTATE_LPARAM(lp); }),
       xlb_f(
           "GET_KEYSTATE_WPARAM",
           [](LPARAM wp) -> auto { return GET_KEYSTATE_WPARAM(wp); }),
       xlb_f(
           "GET_NCHITTEST_WPARAM",
           [](LPARAM wp) -> auto { return GET_NCHITTEST_WPARAM(wp); }),
       xlb_f(
           "GET_RAWINPUT_CODE_WPARAM",
           [](LPARAM wp) -> auto { return GET_RAWINPUT_CODE_WPARAM(wp); }),
       xlb_f(
           "GET_WHEEL_DELTA_WPARAM",
           [](LPARAM wp) -> auto { return GET_WHEEL_DELTA_WPARAM(wp); }),
       xlb_f(
           "GET_XBUTTON_WPARAM",
           [](LPARAM wp) -> auto { return GET_XBUTTON_WPARAM(wp); }),
       xlb_f("GetActiveWindow", GetActiveWindow),
       xlb_f("GetAsyncKeyState", GetAsyncKeyState),
       xlb_f("GetCapture", GetCapture),
       xlb_f("GetDoubleClickTime", GetDoubleClickTime),
       xlb_f("GetFocus", GetFocus), xlb_f("GetKBCodePage", GetKBCodePage),
       xlb_f("GetKeyboardLayout", GetKeyboardLayout),
       xlb_f("GetKeyboardLayoutList", GetKeyboardLayoutList),
       xlb_f("GetKeyboardLayoutNameA", GetKeyboardLayoutNameA),
       xlb_f("GetKeyboardLayoutNameW", GetKeyboardLayoutNameW),
       xlb_f("GetKeyboardState", GetKeyboardState),
       xlb_f("GetKeyboardType", GetKeyboardType),
       xlb_f("GetKeyNameTextA", GetKeyNameTextA),
       xlb_f("GetKeyNameTextW", GetKeyNameTextW),
       xlb_f("GetKeyState", GetKeyState),
       xlb_f("GetLastInputInfo", GetLastInputInfo),
       xlb_f("GetMouseMovePointsEx", GetMouseMovePointsEx),
       xlb_f("GetRawInputBuffer", GetRawInputBuffer),
       xlb_f("GetRawInputData", GetRawInputData),
       xlb_f("GetRawInputDeviceInfoA", GetRawInputDeviceInfoA),
       xlb_f("GetRawInputDeviceInfoW", GetRawInputDeviceInfoW),
       xlb_f("GetRawInputDeviceList", GetRawInputDeviceList),
       xlb_f("GetRegisteredRawInputDevices", GetRegisteredRawInputDevices),
       xlb_f("IsWindowEnabled", IsWindowEnabled),
       xlb_f("keybd_event", keybd_event),
       xlb_f("LoadKeyboardLayoutA", LoadKeyboardLayoutA),
       xlb_f("LoadKeyboardLayoutW", LoadKeyboardLayoutW),
       xlb_f("MapVirtualKeyA", MapVirtualKeyA),
       xlb_f("MapVirtualKeyExA", MapVirtualKeyExA),
       xlb_f("MapVirtualKeyExW", MapVirtualKeyExW),
       xlb_f("MapVirtualKeyW", MapVirtualKeyW),
       xlb_f("mouse_event", mouse_event),
       xlb_f(
           "NEXTRAWINPUTBLOCK",
           [](RAWINPUT * ptr) -> auto { return NEXTRAWINPUTBLOCK(ptr); }),
       xlb_f("OemKeyScan", OemKeyScan), xlb_f("RegisterHotKey", RegisterHotKey),
       xlb_f("RegisterRawInputDevices", RegisterRawInputDevices),
       xlb_f("ReleaseCapture", ReleaseCapture), xlb_f("SendInput", SendInput),
       xlb_f("SetActiveWindow", SetActiveWindow),
       xlb_f("SetCapture", SetCapture),
       xlb_f("SetDoubleClickTime", SetDoubleClickTime),
       xlb_f("SetFocus", SetFocus), xlb_f("SetKeyboardState", SetKeyboardState),
       xlb_f("SwapMouseButton", SwapMouseButton), xlb_f("ToAscii", ToAscii),
       xlb_f("ToAsciiEx", ToAsciiEx), xlb_f("ToUnicode", ToUnicode),
       xlb_f("ToUnicodeEx", ToUnicodeEx),
       xlb_f("TrackMouseEvent", TrackMouseEvent),
       xlb_f("UnloadKeyboardLayout", UnloadKeyboardLayout),
       xlb_f("UnregisterHotKey", UnregisterHotKey),
       xlb_f("VkKeyScanA", VkKeyScanA), xlb_f("VkKeyScanExA", VkKeyScanExA),
       xlb_f("VkKeyScanExW", VkKeyScanExW), xlb_f("VkKeyScanW", VkKeyScanW),

       // Structures
       xlb_class<HARDWAREINPUT>("HARDWAREINPUT")
           .constructor<>()
           .destructor()
           .property("uMsg", &HARDWAREINPUT::uMsg)
           .property("wParamL", &HARDWAREINPUT::wParamL)
           .property("wParamH", &HARDWAREINPUT::wParamH),
       xlb_class<INPUT>("INPUT")
           .constructor<>()
           .destructor()
           .property("type", &INPUT::type)
           .property("mi", &INPUT::mi)
           .property("ki", &INPUT::ki)
           .property("hi", &INPUT::hi),
       xlb_class<KEYBDINPUT>("KEYBDINPUT")
           .constructor<>()
           .destructor()
           .property("wVk", &KEYBDINPUT::wVk)
           .property("wScan", &KEYBDINPUT::wScan)
           .property("dwFlags", &KEYBDINPUT::dwFlags)
           .property("time", &KEYBDINPUT::time)
           .property("dwExtraInfo", &KEYBDINPUT::dwExtraInfo),
       xlb_class<LASTINPUTINFO>("LASTINPUTINFO")
           .constructor<>()
           .destructor()
           .property("cbSize", &LASTINPUTINFO::cbSize)
           .property("dwTime", &LASTINPUTINFO::dwTime),
       xlb_class<MOUSEINPUT>("MOUSEINPUT")
           .constructor<>()
           .destructor()
           .property("dx", &MOUSEINPUT::dx)
           .property("dy", &MOUSEINPUT::dy)
           .property("mouseData", &MOUSEINPUT::mouseData)
           .property("dwFlags", &MOUSEINPUT::dwFlags)
           .property("time", &MOUSEINPUT::time)
           .property("dwExtraInfo", &MOUSEINPUT::dwExtraInfo),
       xlb_class<MOUSEMOVEPOINT>("MOUSEMOVEPOINT")
           .constructor<>()
           .destructor()
           .property("x", &MOUSEMOVEPOINT::x)
           .property("y", &MOUSEMOVEPOINT::y)
           .property("time", &MOUSEMOVEPOINT::time)
           .property("dwExtraInfo", &MOUSEMOVEPOINT::dwExtraInfo),
       xlb_class<RAWHID>("RAWHID")
           .constructor<>()
           .destructor()
           .property("dwSizeHid", &RAWHID::dwSizeHid)
           .property("dwCount", &RAWHID::dwCount)
           .property("bRawData", &RAWHID::bRawData),

       xlb_class<RAWINPUT>("RAWINPUT")
           .constructor<>()
           .destructor()
           .property("header", &RAWINPUT::header)
           .property("data", &RAWINPUT::data),
       xlb_class<decltype(RAWINPUT::data)>("RAWINPUT::data")
           .constructor<>()
           .destructor()
           .property("mouse", &decltype(RAWINPUT::data)::mouse)
           .property("keyboard", &decltype(RAWINPUT::data)::keyboard)
           .property("hid", &decltype(RAWINPUT::data)::hid),
       xlb_class<RAWINPUTDEVICE>("RAWINPUTDEVICE")
           .constructor<>()
           .destructor()
           .property("usUsagePage", &RAWINPUTDEVICE::usUsagePage)
           .property("usUsage", &RAWINPUTDEVICE::usUsage)
           .property("dwFlags", &RAWINPUTDEVICE::dwFlags)
           .property("hwndTarget", &RAWINPUTDEVICE::hwndTarget),
       xlb_class<RAWINPUTDEVICELIST>("RAWINPUTDEVICELIST")
           .constructor<>()
           .destructor()
           .property("hDevice", &RAWINPUTDEVICELIST::hDevice)
           .property("dwType", &RAWINPUTDEVICELIST::dwType),
       xlb_class<RAWINPUTHEADER>("RAWINPUTHEADER")
           .constructor<>()
           .destructor()
           .property("dwType", &RAWINPUTHEADER::dwType)
           .property("dwSize", &RAWINPUTHEADER::dwSize)
           .property("hDevice", &RAWINPUTHEADER::hDevice)
           .property("wParam", &RAWINPUTHEADER::wParam),
       xlb_class<RAWKEYBOARD>("RAWKEYBOARD")
           .constructor<>()
           .destructor()
           .property("MakeCode", &RAWKEYBOARD::MakeCode)
           .property("Flags", &RAWKEYBOARD::Flags)
           .property("Reserved", &RAWKEYBOARD::Reserved)
           .property("VKey", &RAWKEYBOARD::VKey)
           .property("Message", &RAWKEYBOARD::Message)
           .property("ExtraInformation", &RAWKEYBOARD::ExtraInformation),
       xlb_class<RAWMOUSE>("RAWMOUSE")
           .constructor<>()
           .destructor()
           .property("usFlags", &RAWMOUSE::usFlags)
           .property("ulButtons", &RAWMOUSE::ulButtons)
           .property("usButtonFlags", &RAWMOUSE::usButtonFlags)
           .property("usButtonData", &RAWMOUSE::usButtonData)
           .property("ulRawButtons", &RAWMOUSE::ulRawButtons)
           .property("lLastX", &RAWMOUSE::lLastX)
           .property("lLastY", &RAWMOUSE::lLastY)
           .property("ulExtraInformation", &RAWMOUSE::ulExtraInformation),
       xlb_class<RID_DEVICE_INFO>("RID_DEVICE_INFO")
           .constructor<>()
           .destructor()
           .property("cbSize", &RID_DEVICE_INFO::cbSize)
           .property("dwType", &RID_DEVICE_INFO::dwType)
           .property("mouse", &RID_DEVICE_INFO::mouse)
           .property("keyboard", &RID_DEVICE_INFO::keyboard)
           .property("hid", &RID_DEVICE_INFO::hid),
       xlb_class<RID_DEVICE_INFO_HID>("RID_DEVICE_INFO_HID")
           .constructor<>()
           .destructor()
           .property("dwVendorId", &RID_DEVICE_INFO_HID::dwVendorId)
           .property("dwProductId", &RID_DEVICE_INFO_HID::dwProductId)
           .property("dwVersionNumber", &RID_DEVICE_INFO_HID::dwVersionNumber)
           .property("usUsagePage", &RID_DEVICE_INFO_HID::usUsagePage)
           .property("usUsage", &RID_DEVICE_INFO_HID::usUsage),
       xlb_class<RID_DEVICE_INFO_KEYBOARD>("RID_DEVICE_INFO_KEYBOARD")
           .constructor<>()
           .destructor()
           .property("dwType", &RID_DEVICE_INFO_KEYBOARD::dwType)
           .property("dwSubType", &RID_DEVICE_INFO_KEYBOARD::dwSubType)
           .property("dwKeyboardMode",
                     &RID_DEVICE_INFO_KEYBOARD::dwKeyboardMode)
           .property("dwNumberOfFunctionKeys",
                     &RID_DEVICE_INFO_KEYBOARD::dwNumberOfFunctionKeys)
           .property("dwNumberOfIndicators",
                     &RID_DEVICE_INFO_KEYBOARD::dwNumberOfIndicators)
           .property("dwNumberOfKeysTotal",
                     &RID_DEVICE_INFO_KEYBOARD::dwNumberOfKeysTotal),
       xlb_class<RID_DEVICE_INFO_MOUSE>("RID_DEVICE_INFO_MOUSE")
           .constructor<>()
           .destructor()
           .property("dwId", &RID_DEVICE_INFO_MOUSE::dwId)
           .property("dwNumberOfButtons",
                     &RID_DEVICE_INFO_MOUSE::dwNumberOfButtons)
           .property("dwSampleRate", &RID_DEVICE_INFO_MOUSE::dwSampleRate)
           .property("fHasHorizontalWheel",
                     &RID_DEVICE_INFO_MOUSE::fHasHorizontalWheel),
       xlb_class<TRACKMOUSEEVENT>("TRACKMOUSEEVENT")
           .constructor<>()
           .destructor()
           .property("cbSize", &TRACKMOUSEEVENT::cbSize)
           .property("dwFlags", &TRACKMOUSEEVENT::dwFlags)
           .property("hwndTrack", &TRACKMOUSEEVENT::hwndTrack)
           .property("dwHoverTime", &TRACKMOUSEEVENT::dwHoverTime)

      });
#ifdef compile
#endif
#endif // defined(BIND_KM)

  return 0;
} // load_km
