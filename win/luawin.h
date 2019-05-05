#if _MSC_VER > 1000
#pragma once
#endif

//-----------------------------------------------------------------------------
//#define BIND_RAS
//#define BIND_GDI
#define BIND_WMSG
#define BIND_DLG

//-----------------------------------------------------------------------------
#define MODULE_NAME "luawin"

//-----------------------------------------------------------------------------
#include <windows.h>
#include <windowsx.h>

//-----------------------------------------------------------------------------
// https://docs.microsoft.com/en-us/windows/desktop/api/index
//-----------------------------------------------------------------------------
// Compile options
// BIND_ALL
// BIND_WIN_8_1_MINCORE_LIB
// BIND_RAS
// BIND_SNMP
// BIND_WINDOWS_7
// BIND_WINDOWS_2008_R2

//-----------------------------------------------------------------------------
// sdkddkver.h
// Minimum system required              Macros to define
// Windows 10                           WINVER>=0x0A00
// Windows 8.1                          WINVER>=0x0603
// Win8,                                WINVER>=0x0602
// Win7,                                WINVER>=0x0601
// Windows Server 2008 R2,              WINVER>=0x0601
// Windows Server 2008,                 WINVER>=0x0600
// Windows Vista,                       WINVER>=0x0600
// Windows Server 2003,                 WINVER>=0x0502
// Windows XP,                          WINVER>=0x0501
// Windows 2000,                        WINVER>=0x0500
// Windows NT 4.0,                      WINVER>=0x0400
// Windows Me,                          WINVER>=0x0500
// Windows 98,                          WINVER>=0x0410
// Windows 95,                          WINVER>=0x0400
//
// Internet Explorer 10.0	            _WIN32_IE_IE100   (0x0A00)
// Internet Explorer 9.0	            _WIN32_IE_IE90    (0x0900)
// Internet Explorer 8.0	            _WIN32_IE_IE80    (0x0800)
// Internet Explorer 7.0	            _WIN32_IE_IE70    (0x0700)
// Internet Explorer 6.0 SP2	        _WIN32_IE_IE60SP2 (0x0603)
// Internet Explorer 6.0 SP1	        _WIN32_IE_IE60SP1 (0x0601)
// Internet Explorer 6.0	            _WIN32_IE_IE60    (0x0600)
// Internet Explorer 5.5	            _WIN32_IE_IE55    (0x0550)
// Internet Explorer 5.01	            _WIN32_IE_IE501   (0x0501)
// Internet Explorer 5.0, 5.0a, 5.0b	_WIN32_IE_IE50    (0x0500)

//-----------------------------------------------------------------------------

#if defined(WINVER) && (WINVER>=0x0601)
#define BIND_WINDOWS_7
#endif

#if defined(WINVER) && (WINVER>=0x0500)
#define BIND_WINDOWS_2000
#endif



//-----------------------------------------------------------------------------
#include <winbase.h>
#include <wingdi.h>
#include <aclapi.h>
#include <winuser.h>
#include <cpl.h>
#include <shellapi.h>
//#include <ntifs.h> //<ntddk.h> //<wdm.h>
#include <commctrl.h>
#include <minwinbase.h>
#include <richedit.h>

#include <shlobj.h>
#include <winnls.h>
#include <fileapi.h>
//#include <wfext.h>

#pragma comment(lib, "Gdi32.lib")
#pragma comment(lib, "Winspool.lib")
#pragma comment(lib, "Advapi32.lib")
#pragma comment(lib, "User32.lib")
#pragma comment(lib, "Comdlg32.lib")
#pragma comment(lib, "Comctl32.lib") // Comctl32.dll
#pragma comment(lib, "Shell32.lib")
//#pragma comment(lib, "ntoskrnl.lib")

#ifdef BIND_WIN_8_1_MINCORE_LIB
#pragma comment(lib, "Mincore.lib") 
//XXX:api-ms-win-core-processthreads-l1-1-2.dll
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
#include <lmat.h>
#include <lmshare.h>
#include <lmaccess.h>
#pragma comment(lib, "Netapi32.lib")


//-----------------------------------------------------------------------------
// Simple Network Management Protocol
// SNMP is available for use in the operating systems specified in the 
// Requirements section. It may be altered or unavailable in subsequent 
// versions. Instead, use Windows Remote Management, which is the Microsoft 
// implementation of WS-Man.
// https://docs.microsoft.com/en-us/windows/desktop/api/_snmp/
#if (defined(BIND_WINDOWS_7) && (defined(BIND_SNMP) || defined(BIND_ALL)))
#define CHECK_BIND_SNMP
#include <snmp.h>
#include <mgmtapi.h>
#include <winsnmp.h>
#pragma comment(lib, "Snmpapi.lib")
#pragma comment(lib, "Wsnmp32.lib")
#endif

//-----------------------------------------------------------------------------
// Windows GDI
// https://docs.microsoft.com/en-us/windows/desktop/api/_gdi/
#if (defined(BIND_WINDOWS_7) && (defined(BIND_GDI) || defined(BIND_ALL)))
#define CHECK_BIND_GDI
#include <fontsub.h>
#include <mmsystem.h>
#include <prnasnot.h>
#include <prntvpt.h>
#include <t2embapi.h>
#include <tvout.h>
#include <windef.h>
#include <xpsprint.h>
#pragma comment(lib, "Msimg32.lib")
#pragma comment(lib, "FontSub.lib")
#pragma comment(lib, "T2embed.lib")
#endif

//-----------------------------------------------------------------------------
// Windows and Messages
// https://docs.microsoft.com/en-us/windows/desktop/api/_winmsg/
#if (defined(BIND_WINDOWS_7) && (defined(BIND_WMSG) || defined(BIND_ALL)))
#define CHECK_BIND_WMSG
#endif



//-----------------------------------------------------------------------------
// Dialog Boxes
// https://docs.microsoft.com/en-us/windows/desktop/api/_dlgbox/
#if (defined(BIND_WINDOWS_7) && (defined(BIND_DLG) || defined(BIND_ALL)))
#define CHECK_BIND_DLG
#include <commdlg.h>
#include <Prsht.h>
#endif



//-----------------------------------------------------------------------------
//#include <lsapi.h>

#include <wintrust.h>
#pragma comment(lib, "Wintrust.lib")

#pragma comment(lib, "version.lib")

//-----------------------------------------------------------------------------
#include <xlb.h>

//-----------------------------------------------------------------------------

const char* lua_win_api_version();

//-----------------------------------------------------------------------------
using ADDPROPSHEETPAGEPROC = BOOL CALLBACK (*)(HPROPSHEETPAGE hpage, LPARAM lParam);
using BROWSECALLBACKPROC = int CALLBACK (*)(HWND hwnd,UINT uMsg,LPARAM lParam,LPARAM lpData);
using FMEXTENSIONPROC = LONG CALLBACK (*)(HWND hwnd, WORD wMsg, LONG lParam);
using PROPSHEETPROC = void CALLBACK (*)(HWND hwndDlg, UINT uMsg, LPARAM lParam);
using PROPSHEETPAGEPROC = UINT CALLBACK (*)(HWND hwnd, UINT uMsg, LPPROPSHEETPAGE ppsp); 

//-----------------------------------------------------------------------------

void bind_win_api_function(lua_State* L);
void bind_win_api_desktop_tech(lua_State* L);

//-----------------------------------------------------------------------------

