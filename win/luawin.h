#if _MSC_VER > 1000
#pragma once
#endif

//------------------------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
#include <lauxlib.h>
#include <lua.h>
#include <lualib.h>
#ifdef __cplusplus
}
#endif
#define luaf_declare(fn) int fn(lua_State *);


//------------------------------------------------------------------------------------------------
#define BIND_WIN_CHECKED 0x1

// #define BIND_BASE BIND_WIN_CHECKED
//#define BIND_MSG
//#define BIND_PROC
//#define BIND_KM
//#define BIND_RAS
//#define BIND_GDI
//#define BIND_CTRL
//#define BIND_DLG
//#define BIND_NWM
//#define BIND_SHL
//#define BIND_COM

//------------------------------------------------------------------------------------------------
#ifndef MODULE_NAME
#define MODULE_NAME "luawin"
#endif

//------------------------------------------------------------------------------------------------
#include <SDKDDKVer.h>
#include <windows.h>
#include <windowsx.h>

#ifdef _WIN64
using QWORD = unsigned __int64;
#endif

//------------------------------------------------------------------------------------------------
// https://docs.microsoft.com/en-us/windows/win32/api/
// https://docs.microsoft.com/en-us/windows/desktop/api/index
//------------------------------------------------------------------------------------------------
// Compile options
// WINVER
// BIND_ALL
// BIND_WIN_8_1_MINCORE_LIB
// _WIN32_IE

//------------------------------------------------------------------------------------------------
// sdkddkver.h
// Minimum system required                     Macros to define
// Windows 10                                  WINVER>=0x0A00
// Windows 8.1                                 WINVER>=0x0603
// Win8,                                       WINVER>=0x0602
// Win7,                                       WINVER>=0x0601
// Windows Server 2008 R2,                     WINVER>=0x0601
// Windows Server 2008,                        WINVER>=0x0600
// Windows Vista,                              WINVER>=0x0600
// Windows Server 2003,                        WINVER>=0x0502
// Windows XP,                                 WINVER>=0x0501
// Windows 2000,                               WINVER>=0x0500
// Windows NT 4.0,                             WINVER>=0x0400
// Windows Me,                                 WINVER>=0x0500
// Windows 98,                                 WINVER>=0x0410
// Windows 95,                                 WINVER>=0x0400
//
// #define _WIN32_WINNT_NT4                    0x0400 // Windows NT 4.0
// #define _WIN32_WINNT_WIN2K                  0x0500 // Windows 2000
// #define _WIN32_WINNT_WINXP                  0x0501 // Windows XP
// #define _WIN32_WINNT_WS03                   0x0502 // Windows Server 2003
// #define _WIN32_WINNT_WIN6                   0x0600 // Windows Vista
// #define _WIN32_WINNT_VISTA                  0x0600 // Windows Vista
// #define _WIN32_WINNT_WS08                   0x0600 // Windows Server 2008
// #define _WIN32_WINNT_LONGHORN               0x0600 // Windows Vista
// #define _WIN32_WINNT_WIN7                   0x0601 // Windows 7
// #define _WIN32_WINNT_WIN8                   0x0602 // Windows 8
// #define _WIN32_WINNT_WINBLUE                0x0603 // Windows 8.1
// #define _WIN32_WINNT_WINTHRESHOLD           0x0A00 // Windows 10
// #define _WIN32_WINNT_WIN10                  0x0A00 // Windows 10
//
// Internet Explorer 10.0	                   _WIN32_IE_IE100   (0x0A00)
// Internet Explorer 9.0	                   _WIN32_IE_IE90    (0x0900)
// Internet Explorer 8.0	                   _WIN32_IE_IE80    (0x0800)
// Internet Explorer 7.0	                   _WIN32_IE_IE70    (0x0700)
// Internet Explorer 6.0 SP2	               _WIN32_IE_IE60SP2 (0x0603)
// Internet Explorer 6.0 SP1	               _WIN32_IE_IE60SP1 (0x0601)
// Internet Explorer 6.0	                   _WIN32_IE_IE60    (0x0600)
// Internet Explorer 5.5	                   _WIN32_IE_IE55    (0x0550)
// Internet Explorer 5.01	                   _WIN32_IE_IE501   (0x0501)
// Internet Explorer 5.0, 5.0a, 5.0b	       _WIN32_IE_IE50    (0x0500)

//------------------------------------------------------------------------------------------------
// _MSC_VER
// MS VC++ 12.0 _MSC_VER = 1800 (Visual C++ 2013)
// MS VC++ 11.0 _MSC_VER = 1700 (Visual C++ 2012)
// MS VC++ 10.0 _MSC_VER = 1600 (Visual C++ 2010)
// MS VC++ 9.0 _MSC_VER = 1500
// MS VC++ 8.0 _MSC_VER = 1400
// MS VC++ 7.1 _MSC_VER = 1310
// MS VC++ 7.0 _MSC_VER = 1300
// MS VC++ 6.0 _MSC_VER = 1200
// MS VC++ 5.0 _MSC_VER = 1100

//------------------------------------------------------------------------------------------------
// Minimum system required Macros to define
// Windows Server 2008 NTDDI_VERSION >= NTDDI_LONGHORN
// Windows Vista NTDDI_VERSION >= NTDDI_VISTA
// Windows Server 2003 SP1 NTDDI_VERSION >= NTDDI_WS03SP1
// Windows Server 2003 NTDDI_VERSION >= NTDDI_WS03
// Windows XP SP2 NTDDI_VERSION >= NTDDI_WINXPSP2
// Windows XP SP1 NTDDI_VERSION >= NTDDI_WINXPSP1
// Windows XP NTDDI_VERSION >= NTDDI_WINXP
// Windows 2000 SP4 NTDDI_VERSION >= NTDDI_WIN2KSP4
// Windows 2000 SP3 NTDDI_VERSION >= NTDDI_WIN2KSP3
// Windows 2000 SP2 NTDDI_VERSION >= NTDDI_WIN2KSP2
// Windows 2000 SP1 NTDDI_VERSION >= NTDDI_WIN2KSP1
// Windows 2000 NTDDI_VERSION >= NTDDI_WIN2K

//------------------------------------------------------------------------------------------------
#include <aclapi.h>
#include <cpl.h>
#include <shellapi.h>
#include <winbase.h>
#include <wingdi.h>
#include <winuser.h>

//#include <ntifs.h> //<ntddk.h> //<wdm.h>
#include <commctrl.h>
#include <minwinbase.h>
#include <richedit.h>

#include <fileapi.h>
#include <winnls.h>

//#include <wfext.h>

#pragma comment(lib, "Gdi32.lib")
#pragma comment(lib, "Winspool.lib")
#pragma comment(lib, "Advapi32.lib")
#pragma comment(lib, "User32.lib")
#pragma comment(lib, "Comdlg32.lib")
#pragma comment(lib, "Comctl32.lib") // Comctl32.dll
#pragma comment(lib, "Shell32.lib")
//#pragma comment(lib, "ntoskrnl.lib")

//
#if defined(WINVER) && (WINVER >= 0x0A00)
#pragma comment(lib, "OneCore.lib") // KernelBase.dll
#endif

#pragma comment(lib, "Kernel32.lib")

#ifdef BIND_WIN_8_1_MINCORE_LIB
#pragma comment(lib, "Mincore.lib")
// XXX:api-ms-win-core-processthreads-l1-1-2.dll
// XXX:api-ms-win-shcore-scaling-l1-1-0.dll
// XXX:api-ms-win-shcore-scaling-l1-1-1.dll
// XXX:api-ms-win-core-psm-appnotify-l1-1-0.dll
#endif

//#include <scrnsave.h>
//#pragma comment(lib, "Scrnsave.lib")

#pragma comment(lib, "Imm32.lib")
#pragma comment(lib, "Lz32.lib")
#pragma comment(lib, "Snmpapi.lib")
#pragma comment(lib, "Ws2_32.lib")
#pragma comment(lib, "Mgmtapi.lib")

//#include <nddeapi.h>
//#pragma comment(lib, "Nddeapi.lib")

#include <lm.h>
#include <lmaccess.h>
#include <lmat.h>
#include <lmshare.h>

#pragma comment(lib, "Netapi32.lib")

//------------------------------------------------------------------------------------------------
// Windows Shell
// https://docs.microsoft.com/en-us/previous-versions/windows/desktop/legacy/bb773177(v=vs.85)
// https://docs.microsoft.com/en-us/windows/win32/api/_shell/
#if ((defined(BIND_SHL) || defined(BIND_ALL)))
#include <Cscsearchapiif.hxx>
#include <Pathcch.h>
#pragma comment(lib, "Pathcch.lib")
#include <objbase.h>
#include <shobjidl.h>
#include <shobjidl_core.h>

#pragma comment(lib, "Ole32.lib")
// API-MS-WIN-CORE-PATH-L1-1-0.DLL
luaf_declare(load_shl);

#if (WINVER == 0x0500)
#include <Wfext.h>
using FMExtensionProc = LONG(CALLBACK *)(HWND hwnd, WORD wMsg, LONG lParam);
#endif

using BrowseCallbackProc = int(CALLBACK *)(HWND hwnd, UINT uMsg, LPARAM lParam, LPARAM lpData);
using MRUCMPPROC = int(CALLBACK *)(LPCTSTR pString1, LPCTSTR pString2);

#if (WINVER >= 0x0603)
#include <shellscalingapi.h>
#endif

#include <userenv.h>
#pragma comment(lib, "userenv.lib")
#pragma comment(lib, "Shlwapi.lib")

//#include <scrnsave.h>
//#pragma comment(lib, "Scrnsave.lib")

#include <shellscalingapi.h>
#include <syncmgr.h>

#pragma comment(lib, "shcore.lib")
////#define STRICT_TYPED_ITEMIDS

#include <shlobj.h>
#include <shlobj_core.h>
#include <wininet.h> //#define _WININET_ // for COMPONENT

#include <intshcut.h>

#include <appnotify.h>
#pragma comment(lib, "Appnotify.lib") // Twinapi.core.dll

#include <Iphlpapi.h>
#include <credentialprovider.h>
#include <mobsync.h>
#include <shappmgr.h>
#include <shdeprecated.h>
#include <shidfact.h>
#include <shlguid.h>
#include <thumbcache.h>
#include <thumbnailstreamcache.h>

#include <appmgmt.h>
#include <appnotify.h>
#include <cpl.h>
#include <credentialprovider.h>
#include <dimm.h>
#include <imagetranscode.h>
#include <inputpanelconfiguration.h>
#include <intsafe.h>
#include <intshcut.h>
#include <mobsync.h>
#include <objectarray.h>
#include <pathcch.h>
#include <profinfo.h>
#include <propkeydef.h>
#include <scrnsave.h>
#include <shappmgr.h>
#include <shdeprecated.h>
#include <shidfact.h>
#include <shimgdata.h>
#include <shlwapi.h>
#include <shtypes.h>
#include <storageprovider.h>
#include <syncmgr.h>
#include <thumbcache.h>
#include <thumbnailstreamcache.h>
#include <tlogstg.h>
#include <userenv.h>
#endif

#include <tchar.h>
//------------------------------------------------------------------------------------------------
#include <xlb.h>

//------------------------------------------------------------------------------------------------
// for LoadLibrary GetProcAddress to get function pointer
 struct Win32_libf {
  struct Libf : public xlb_fmat_evthandler {
    TCHAR *libn;
    const char *funcn;
    virtual ~Libf() {}
  };

  static xlb_fmat_evthandler *CreateFmatHandler(TCHAR* ln, const char* fn) {
    auto h = new Libf();
    h->libn = ln;
    h->funcn = fn;
    // h->on_registry = Win32_libf::register;
    h->on_getf = Win32_libf::getf;
    return h;
  }

  // static int registry(lua_State *L, xlb_fmat_evthandler *) { return 0; }
  static void* getf(lua_State *L, xlb_fmat_evthandler *evth) { 
    assert(evth);
    auto libf = dynamic_cast<Libf*>(evth);
    assert(libf);
    assert(libf->libn);
    assert(libf->funcn);
    void* f = nullptr;
    auto hlib = ::LoadLibrary(libf->libn);
    assert(hlib!=NULL); //"fail to LoadLibrary"
    f = ::GetProcAddress(hlib, libf->funcn);
    assert(f!=NULL); // "fail to GetProcAddress"

    return f;
  }
}; // Win32_libf

//------------------------------------------------------------------------------------------------
// XXX: special delete for interface, call release instead
template <typename T> struct xlb_win_interface_delete {
  void operator()(T *intf) {
    assert(intf);
    intf->Release();
  }
};

template <typename T>
using enable_if_interface = std::enable_if_t<std::is_base_of_v<IUnknown, xlb_completetype_t<T>>>;

template <typename T> struct xlb_delete::xlb_tir<T, enable_if_interface<T>> {
  using type = xlb_win_interface_delete<T>;
};

//------------------------------------------------------------------------------------------------
// Component Object Model (COM)
// https://docs.microsoft.com/en-us/previous-versions/windows/embedded/ms885856(v=msdn.10)
#if ((defined(BIND_COM) || defined(BIND_ALL)))
#include <IAccess.h>
#include <Olectl.h>
#include <combaseapi.h>

#pragma comment(lib, "Oleaut32.lib")
#include <Comcat.h>
#include <objidl.h>
#include <objsafe.h>

#ifdef _WIN32_WCE
#include <Dccole.h>
#endif

luaf_declare(load_com);

template <typename T> struct xlb_interface : public xlb_base_class<T> {
  using rr_t = xlb_interface &&;
  using bc_t = xlb_base_class<T>;
  using ri_t = xlb_regitem;

  xlb_interface(const char *class_name) { bc_t::setup_names(class_name); }

  virtual ~xlb_interface() {}

  xlb_interface(xlb_interface &&) = delete;

  virtual void registry(xlb_ns *ns) override { bc_t::registry(ns->lua, ns->luaIndex); }

}; // xlb_interface

template <typename P> // P=T * const
int xlb_pushinterface(lua_State *L, P pointer, void *place = nullptr) {
  using w_t = xlb_wrap<std::remove_pointer_t<P>, xlb_notpointer, xlb_win_interface_delete>;
  auto wp = w_t::getplace(L, place);
  new (wp) w_t(pointer, xlf_gc::yes, xlf_qlf::vp);
  w_t::setmeta_pointer(L, -1);
  // xlb_debug("(0x%p)\n", pointer);
  return {1};
}

#endif

//------------------------------------------------------------------------------------------------
// Windows Base
// https://docs.microsoft.com/en-us/windows/win32/api/winbase/
#if ((defined(BIND_BASE) || defined(BIND_ALL)))
#include <guiddef.h>
#endif

//------------------------------------------------------------------------------------------------
// Simple Network Management Protocol
// SNMP is available for use in the operating systems specified in the
// Requirements section. It may be altered or unavailable in subsequent
// versions. Instead, use Windows Remote Management, which is the Microsoft
// implementation of WS-Man.
// https://docs.microsoft.com/en-us/windows/desktop/api/_snmp/
#if ((defined(BIND_SNMP) || defined(BIND_ALL)))
#include <mgmtapi.h>
#include <snmp.h>
#include <winsnmp.h>

#pragma comment(lib, "Snmpapi.lib")
#pragma comment(lib, "Wsnmp32.lib")
luaf_declare(load_snmp);
#endif

//------------------------------------------------------------------------------------------------
// Windows GDI
// https://docs.microsoft.com/en-us/windows/desktop/api/_gdi/
#if ((defined(BIND_GDI) || defined(BIND_ALL)))
#include <fontsub.h>
#include <mmsystem.h>
#include <prnasnot.h>
#include <prntvpt.h>
#include <t2embapi.h>
#include <tvout.h>
#include <windef.h>
//#include <xpsprint.h>
#pragma comment(lib, "Msimg32.lib")
#pragma comment(lib, "FontSub.lib")
#pragma comment(lib, "T2embed.lib")

luaf_declare(load_gdi);
#endif

//------------------------------------------------------------------------------------------------
// Windows Controls
// https://docs.microsoft.com/zh-cn/windows/win32/controls/window-controls
// https://docs.microsoft.com/zh-cn/windows/win32/controls/individual-control-info
#if ((defined(BIND_CTRL) || defined(BIND_ALL)))
// https://docs.microsoft.com/zh-cn/windows/win32/controls/buttons
// https://docs.microsoft.com/zh-cn/windows/win32/controls/combo-boxes
// https://docs.microsoft.com/zh-cn/windows/win32/controls/edit-controls
// https://docs.microsoft.com/zh-cn/windows/win32/controls/list-view-control-reference
// https://docs.microsoft.com/zh-cn/windows/win32/controls/month-calendar-control-reference
//
// Enabling Visual Styles
// https://docs.microsoft.com/zh-cn/windows/win32/controls/cookbook-overview
#include <commoncontrols.h>
#include <prsht.h>
#include <richole.h>

luaf_declare(load_ctrl);

using DPA_DestroyCallback_t =
    void (*)(_In_ HDPA hdpa, _In_ PFNDAENUMCALLBACKCONST pfnCB, _In_opt_ void *pData);
using DPA_EnumCallback_t =
    void (*)(_In_ HDPA hdpa, _In_ PFNDAENUMCALLBACKCONST pfnCB, _In_opt_ void *pData);
using DPA_Merge_t = BOOL (*)(
    _Inout_ HDPA hdpaDest, _In_ HDPA hdpaSrc, _In_ DWORD dwFlags, _In_ PFNDACOMPARECONST pfnCompare,
    _In_ PFNDPAMERGECONST pfnMerge, _In_ LPARAM lParam);
using DPA_Search_t = int (*)(
    _In_ HDPA hdpa, _In_opt_ const void *pFind, _In_ int iStart, _In_ PFNDACOMPARECONST pfnCompare,
    _In_ LPARAM lParam, _In_ UINT options);
using DPA_Sort_t =
    BOOL (*)(_Inout_ HDPA hdpa, _In_ PFNDACOMPARECONST pfnCompare, _In_ LPARAM lParam);
using DSA_DestroyCallback_t =
    void (*)(_Inout_opt_ HDSA hdsa, _In_ PFNDAENUMCALLBACKCONST pfnCB, _In_opt_ void *pData);
using DSA_EnumCallback_t =
    void (*)(_In_ HDSA hdsa, _In_ PFNDAENUMCALLBACKCONST pfnCB, _In_opt_ void *pData);
using DSA_Sort_t =
    BOOL (*)(_Inout_ HDSA hdsa, _In_ PFNDACOMPARECONST pfnCompare, _In_ LPARAM lParam);

#endif

//------------------------------------------------------------------------------------------------
// Network Management
// https://docs.microsoft.com/en-us/windows/win32/api/_netmgmt/
#if ((defined(BIND_NWM) || defined(BIND_ALL)))
#include "atacct.h"
#pragma comment(lib, "Mstask.lib")
luaf_declare(load_nwm);
#endif

//------------------------------------------------------------------------------------------------
// Windows and Messages
// https://docs.microsoft.com/en-us/windows/desktop/api/_winmsg/
#if ((defined(BIND_MSG) || defined(BIND_ALL)))
luaf_declare(load_msg);
#endif

//------------------------------------------------------------------------------------------------
// Dialog Boxes
// https://docs.microsoft.com/en-us/windows/desktop/api/_dlgbox/
#if ((defined(BIND_DLG) || defined(BIND_ALL)))
#include <Prsht.h>
#include <commdlg.h>

luaf_declare(load_dlg);
#endif

using GETPROCESSHANDLEFROMHWND = HANDLE WINAPI (*)(HWND hwnd);
//------------------------------------------------------------------------------------------------
// System Services - Processes
// https://docs.microsoft.com/zh-cn/windows/win32/procthread/process-and-thread-functions
#if ((defined(BIND_PROC) || defined(BIND_ALL)))

#if (defined WINVER) && (WINVER >= 0x0A00)
#include <dispatcherqueue.h>
#include <processthreadsapi.h>

#pragma comment(lib, "CoreMessaging.lib")
#include <wow64apiset.h>
#endif

#if (defined WINVER) && (WINVER >= 0x0600)
#include <avrt.h>
#pragma comment(lib, "Avrt.lib")
#endif

#include <psapi.h>
#include <tlhelp32.h>
#include <wtsapi32.h>
#pragma comment(lib, "wtsapi32.lib")


luaf_declare(load_proc);
#endif

//------------------------------------------------------------------------------------------------
// Keyboard and Mouse Input
// https://docs.microsoft.com/en-us/windows/win32/api/_inputdev/
#if ((defined(BIND_KM) || defined(BIND_ALL)))
luaf_declare(load_km);
#endif

//------------------------------------------------------------------------------------------------
//#include <lsapi.h>

#include <wintrust.h>
#pragma comment(lib, "Wintrust.lib")

#pragma comment(lib, "version.lib")

//------------------------------------------------------------------------------------------------
using ADDPROPSHEETPAGEPROC = BOOL CALLBACK (*)(HPROPSHEETPAGE hpage, LPARAM lParam);
using BROWSECALLBACKPROC = int CALLBACK (*)(HWND hwnd, UINT uMsg, LPARAM lParam, LPARAM lpData);
using FMEXTENSIONPROC = LONG CALLBACK (*)(HWND hwnd, WORD wMsg, LONG lParam);
using PROPSHEETPROC = void CALLBACK (*)(HWND hwndDlg, UINT uMsg, LPARAM lParam);
using PROPSHEETPAGEPROC = UINT CALLBACK (*)(HWND hwnd, UINT uMsg, LPPROPSHEETPAGE ppsp);

luaf_declare(load_base);
luaf_declare(bind_win_api_desktop_tech);

//------------------------------------------------------------------------------------------------
