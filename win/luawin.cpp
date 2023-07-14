//--------------------------------------------------------------------------------------------------
// bind Windows API to Lua using XLB
//--------------------------------------------------------------------------------------------------
#include "luawin.h"

// build app and provide WINVER as argument, such as
// build WINVER=0x0601

//--------------------------------------------------------------------------------------------------
xlb_fmat_evthandler *Win32_libf::CreateFmatHandler(TCHAR *ln, const char *fn) {
  auto h = new Libf();
  h->libn = ln;
  h->funcn = fn;
  // h->on_registry = Win32_libf::register;
  h->on_getf = Win32_libf::getf;
  return h;
}

// static int registry(lua_State *L, xlb_fmat_evthandler *) { return 0; }
void *Win32_libf::getf(lua_State *L, xlb_fmat_evthandler *evth) {
  assert(evth);
  auto libf = dynamic_cast<Libf *>(evth);
  assert(libf);
  assert(libf->libn);
  assert(libf->funcn);
  void *f = nullptr;
  auto hlib = ::LoadLibrary(libf->libn);
  assert(hlib != NULL); //"fail to LoadLibrary"
  f = ::GetProcAddress(hlib, libf->funcn);
  assert(f != NULL); // "fail to GetProcAddress"

  return f;
}

//--------------------------------------------------------------------------------------------------
// XXX: /DEF:win.def
// module main
int luaopen_luawin(lua_State *L) {
  xlb_module{L, MODULE_NAME}({});
  bind_win_api_desktop_tech(L);
  return 0;
}

//--------------------------------------------------------------------------------------------------
int bind_win_api_desktop_tech(lua_State *L) {
  // xlb_debug("PROCESS_TERMINATE=0x%x\n", PROCESS_TERMINATE);
  xlb_module(L, MODULE_NAME)({
    xlb_const("WINVER", WINVER), xlb_const("VERSION", "Windows API (Lua53)"),
#if defined(UNICODE)
        xlb_const("UNICODE", UNICODE),
#endif

#ifdef BIND_BASE
        xlb_f("load_base", load_base), xlb_const("CHECK_BIND_BASE", BIND_BASE),
#endif
#ifdef BIND_MSG
        xlb_const("CHECK_BIND_MSG", BIND_MSG), xlb_f("load_msg", load_msg),
#endif
#ifdef BIND_GDI
        xlb_const("CHECK_BIND_GDI", BIND_GDI), xlb_f("load_gdi", load_gdi),
#endif
#ifdef BIND_DLG
        xlb_const("CHECK_BIND_DLG", BIND_DLG), xlb_f("load_dlg", load_dlg),
#endif
#ifdef BIND_SNMP
        xlb_const("CHECK_BIND_SNMP", BIND_SNMP), xlb_f("load_snmp", load_snmp),
#endif
#ifdef BIND_PROC
        xlb_const("CHECK_BIND_PROC", BIND_PROC), xlb_f("load_proc", load_proc),
#endif
#ifdef BIND_KM
        xlb_const("CHECK_BIND_KM", BIND_KM), xlb_f("load_km", load_km),
#endif
#ifdef BIND_CTRL
        xlb_const("CHECK_BIND_CTRL", BIND_CTRL), xlb_f("load_ctrl", load_ctrl),
#endif
#ifdef BIND_NWM
        xlb_const("CHECK_BIND_NWM", BIND_NWM), xlb_f("load_nwm", load_nwm),
#endif
#ifdef BIND_SHL
        xlb_const("CHECK_BIND_SHL", BIND_SHL), xlb_f("load_shl", load_shl),
#endif
#ifdef BIND_COM
        xlb_const("CHECK_BIND_COM", BIND_COM), xlb_f("load_com", load_com)
#endif
  });
  return 0;
} // bind_win_api_desktop_tech

//--------------------------------------------------------------------------------------------------
