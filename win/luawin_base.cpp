#include "luawin.h"

//------------------------------------------------------------------------------------------------
using namespace std;
using iLBuf = std::vector<char>;
using iLCBuf = const std::vector<char>;
#include "luawin.h"

//------------------------------------------------------------------------------------------------
void base64dec(iLCBuf &inbuf, iLBuf &outbuf) {
  const char DecodeTable[] = {
      0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
      62, // '+'
      0,  0,  0,
      63,                                     // '/'
      52, 53, 54, 55, 56, 57, 58, 59, 60, 61, // '0'-'9'
      0,  0,  0,  0,  0,  0,  0,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14,
      15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, // 'A'-'Z'
      0,  0,  0,  0,  0,  0,  26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41,
      42, 43, 44, 45, 46, 47, 48, 49, 50, 51, // 'a'-'z'
  };
  int nValue = 0;
  int i = 0;
  int DataByte = inbuf.size();
  const char *p = &inbuf.front();
  outbuf.clear();
  while (i < DataByte) {
    if (*p != '\r' && *p != '\n') {
      nValue = DecodeTable[*p++] << 18;
      nValue += DecodeTable[*p++] << 12;
      outbuf.push_back((char)((nValue & 0x00FF0000) >> 16));
      if (*p != '=') {
        nValue += DecodeTable[*p++] << 6;
        outbuf.push_back((char)((nValue & 0x0000FF00) >> 8));
        if (*p != '=') {
          nValue += DecodeTable[*p++];
          outbuf.push_back((char)(nValue & 0x000000FF));
        }
      }
      i += 4;
    } else {
      ++p;
      ++i;
    } // 回车换行,跳过
  }
}

//------------------------------------------------------------------------------------------------
void base64enc(iLCBuf &inbuf, iLBuf &outbuf, int needreturn) {
  const char EncodeTable[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
  unsigned char Tmp[4] = {0};
  int LineLength = 0;
  int DataByte = inbuf.size();
  const char *pIn = &inbuf.front();
  outbuf.clear();
  for (int i = 0; i < (int)(DataByte / 3); i++) {
    Tmp[1] = *pIn++;
    Tmp[2] = *pIn++;
    Tmp[3] = *pIn++;
    outbuf.push_back(EncodeTable[Tmp[1] >> 2]);
    outbuf.push_back(EncodeTable[((Tmp[1] << 4) | (Tmp[2] >> 4)) & 0x3F]);
    outbuf.push_back(EncodeTable[((Tmp[2] << 2) | (Tmp[3] >> 6)) & 0x3F]);
    outbuf.push_back(EncodeTable[Tmp[3] & 0x3F]);
    if (LineLength += 4, LineLength == 76 && needreturn) {
      outbuf.push_back('\r');
      outbuf.push_back('\n');
      LineLength = 0;
    }
  }
  int Mod = DataByte % 3;
  if (Mod == 1) {
    Tmp[1] = *pIn++;
    outbuf.push_back(EncodeTable[(Tmp[1] & 0xFC) >> 2]);
    outbuf.push_back(EncodeTable[((Tmp[1] & 0x03) << 4)]);
    outbuf.push_back('=');
    outbuf.push_back('=');
  } else if (Mod == 2) {
    Tmp[1] = *pIn++;
    Tmp[2] = *pIn++;
    outbuf.push_back(EncodeTable[(Tmp[1] & 0xFC) >> 2]);
    outbuf.push_back(EncodeTable[((Tmp[1] & 0x03) << 4) | ((Tmp[2] & 0xF0) >> 4)]);
    outbuf.push_back(EncodeTable[((Tmp[2] & 0x0F) << 2)]);
    outbuf.push_back('=');
  }
}

//------------------------------------------------------------------------------------------------
int Base64Decode(lua_State *L) {
  int rc = 0;
  size_t len = 0;
  const char *Data = luaL_optlstring(L, 2, "", &len);
  if (strcmp(Data, "")) {
    iLBuf inBuf(Data, Data + len);
    iLBuf outBuf;
    base64dec(inBuf, outBuf);
    lua_pushstring(L, &outBuf.front());
    lua_pushnumber(L, outBuf.size());
    rc = 2;
  }
  return rc;
}

int Base64Encode(lua_State *L) {
  int rc = 0;
  size_t len = 0;
  const char *Data = luaL_optlstring(L, 2, "", &len);
  if (strcmp(Data, "")) {
    iLBuf inBuf(Data, Data + len);
    iLBuf outBuf;
    base64enc(inBuf, outBuf, 0);
    lua_pushstring(L, &outBuf.front());
    lua_pushnumber(L, outBuf.size());
    rc = 2;
  }
  return rc;
}

wchar_t *mb2wc(const char *mbstr, int &len, int cp) {
  wchar_t *wcstr = NULL;
  int size = MultiByteToWideChar(cp, 0, mbstr, len, NULL, 0);
  if (size > 0) {
    wcstr = new wchar_t[size];
    memset(wcstr, 0, size * sizeof(wchar_t));
    int result = MultiByteToWideChar(cp, 0, mbstr, len, wcstr, size);
    if (result == 0) { // MultiByteToWideChar returns 0 if it does not succeed.
      delete[] wcstr;
      wcstr = NULL;
    }
    // len = 2*(size-1); // do not include terminating null character
    len = size;
  }
  return wcstr;
}

char *wc2mb(const wchar_t *wcstr, int &len, int cp) {
  char *mbstr = NULL;
  int size = WideCharToMultiByte(cp, 0, wcstr, len, NULL, 0, NULL, NULL);
  if (size > 0) {
    mbstr = new char[size];
    memset(mbstr, 0, size * sizeof(char));
    int result = WideCharToMultiByte(cp, 0, wcstr, len, mbstr, size, NULL, NULL);
    if (result == 0) { // MultiByteToWideChar returns 0 if it does not succeed.
      delete[] mbstr;
      mbstr = NULL;
    }
    // len = --size;
    len = size;
  }
  return mbstr;
}

int u2w(lua_State *L, int index) {
  int rc = 0;
  size_t len_bytes = 0;
  const char *mbstr = lua_tolstring(L, index, &len_bytes);
  if (mbstr && len_bytes > 0) {
    int len_wc = len_bytes;
    wchar_t *wcstr = mb2wc(mbstr, len_wc, CP_UTF8);
    if (wcstr) {
      len_bytes = sizeof(wchar_t) * len_wc;
      lua_pushlstring(L, (const char *)wcstr, len_bytes);
      lua_pushnumber(L, len_bytes);
      rc = 2;
      delete[] wcstr;
    }
  }
  return rc;
}

int u2a(lua_State *L, int index) {
  int rc = 0;
  size_t len_bytes = 0;
  const char *mbstr = lua_tolstring(L, index, &len_bytes);
  if (mbstr && len_bytes > 0) {
    int len_wc = len_bytes;
    wchar_t *wcstr = mb2wc(mbstr, len_wc, CP_UTF8);
    if (wcstr) {
      char *nmbstr = wc2mb(wcstr, len_wc, CP_ACP);
      if (nmbstr) {
        len_bytes = len_wc;
        lua_pushlstring(L, nmbstr, len_bytes);
        lua_pushnumber(L, len_bytes);
        rc = 2;
        delete[] nmbstr;
      }
      delete[] wcstr;
    }
  }

  if (0 == rc) {
    lua_pushstring(L, "");
    lua_pushnumber(L, 0);
    rc = 2;
  }
  return rc;
}

int a2u(lua_State *L, int index) {
  int rc = 0;
  size_t len_bytes = 0;
  const char *mbstr = lua_tolstring(L, index, &len_bytes);
  if (mbstr && len_bytes > 0) {
    int len_wc = len_bytes;
    wchar_t *wcstr = mb2wc(mbstr, len_wc, CP_ACP);
    if (wcstr) {
      int len_bytes = len_wc;
      char *nmbstr = wc2mb(wcstr, len_bytes, CP_UTF8);
      if (nmbstr) {
        lua_pushlstring(L, nmbstr, len_bytes);
        lua_pushnumber(L, len_bytes);
        rc = 2;
        delete[] nmbstr;
      }
      delete[] wcstr;
    }
  }

  if (0 == rc) {
    lua_pushstring(L, "");
    lua_pushnumber(L, 0);
    rc = 2;
  }
  return rc;
}

int a2w(lua_State *L, int index) {
  int rc = 0;
  size_t len_bytes = 0;
  const char *mbstr = lua_tolstring(L, index, &len_bytes);
  if (mbstr && len_bytes > 0) {
    int len_wc = len_bytes;
    wchar_t *wcstr = mb2wc(mbstr, len_wc, CP_ACP);
    if (wcstr) {
      len_bytes = sizeof(wchar_t) * len_wc;
      lua_pushlstring(L, (const char *)wcstr, len_bytes);
      lua_pushnumber(L, len_bytes);
      delete[] wcstr;
      rc = 2;
    }
  }

  if (0 == rc) {
    lua_pushstring(L, "");
    lua_pushnumber(L, 0);
    rc = 2;
  }
  return rc;
}

int w2a(lua_State *L, int index) {
  int rc = 0;
  size_t len_bytes = 0;
  int size = 0;
  auto wcstr = (const wchar_t *)lua_tolstring(L, index, &len_bytes);
  if (wcstr && len_bytes > 0) {
    int len_wc = len_bytes / sizeof(wchar_t); // multibyte as wchar_t string
    char *mbstr = wc2mb((wchar_t *)wcstr, len_wc, CP_ACP);

    if (mbstr) {
      lua_pushlstring(L, mbstr, len_wc);
      lua_pushnumber(L, len_wc);
      delete[] mbstr;
      rc = 2;
    }
  }

  if (0 == rc) {
    lua_pushstring(L, "");
    lua_pushnumber(L, 0);
    rc = 2;
  }
  return rc;
}

int w2u(lua_State *L, int index) {
  int rc = 0;
  size_t len_bytes = 0;
  const char *wcstr = lua_tolstring(L, index, &len_bytes);
  if (wcstr && len_bytes > 0) {
    int len_wc = len_bytes / sizeof(wchar_t);
    char *mbstr = wc2mb((wchar_t *)wcstr, len_wc, CP_UTF8);
    if (mbstr) {
      lua_pushlstring(L, mbstr, len_wc);
      lua_pushnumber(L, len_wc);
      delete[] mbstr;
      rc = 2;
    }
  }

  if (0 == rc) {
    lua_pushstring(L, "");
    lua_pushnumber(L, 0);
    rc = 2;
  }
  return rc;
}

int u2w(lua_State *L) {
  int itop = lua_gettop(L);
  int rc = 0;
  for (int index = 1; index <= itop; ++index) {
    rc += u2w(L, index);
  }
  return rc;
}

int u2a(lua_State *L) {
  int itop = lua_gettop(L);
  int rc = 0;
  for (int index = 1; index <= itop; ++index) {
    rc += u2a(L, index);
  }
  return rc;
}

int a2u(lua_State *L) {
  int itop = lua_gettop(L);
  int rc = 0;
  for (int index = 1; index <= itop; ++index) {
    rc += a2u(L, index);
  }
  return rc;
}

int a2w(lua_State *L) {
  int itop = lua_gettop(L);
  int rc = 0;
  for (int index = 1; index <= itop; ++index) {
    rc += a2w(L, index);
  }
  return rc;
}

int w2u(lua_State *L) {
  int itop = lua_gettop(L);
  int rc = 0;
  for (int index = 1; index <= itop; ++index) {
    rc += w2u(L, index);
  }
  return rc;
}

int w2a(lua_State *L) {
  int itop = lua_gettop(L);
  int rc = 0;
  for (int index = 1; index <= itop; ++index) {
    rc += w2a(L, index);
  }
  return rc;
}

int Bytes(lua_State *L) {
  auto pch = luaL_optstring(L, 1, "");
  auto len = luaL_optnumber(L, 2, strlen(pch));
  std::string str;
  char buf[6];
  memset(buf, 0, 6);
  // auto len = strlen(pch);
  for (int i = 0; i < len; ++i) {
    sprintf(buf, "0x%02x ", (unsigned char)*pch++);
    str += buf;
  }
  lua_pushlstring(L, str.c_str(), 5 * len);
  return 1;
}

int cstr(lua_State *L) {
  auto pch = lua_tostring(L, 1);
  auto len = strlen(pch);
  if (nullptr == pch) {
    lua_pushnil(L);
  } else {
    lua_pushlstring(L, pch, len);
  }
  return 1;
}

//------------------------------------------------------------------------------------------------
int load_base(lua_State *L) {
#if defined(BIND_BASE)
  xlb_module(L, MODULE_NAME)({
    xlb_f("base64enc", Base64Encode), xlb_f("base64dec", Base64Decode), xlb_f("a2w", a2w),
        xlb_f("w2a", w2a), 
        xlb_f("a2u", a2u), xlb_f("u2a", u2a), xlb_f("w2u", w2u),
        xlb_f("u2w", u2w), xlb_f("bytes", Bytes), xlb_f("pvtostring", xlb_pvtostring),
        xlb_f("pvtointeger", xlb_pvtointeger), xlb_f("type", xlb_type), xlb_f("cstr", cstr),

        xlb_f("malloc", malloc), xlb_f("free", free), xlb_f("realloc", realloc),
        xlb_f("GetLastError", GetLastError),

        xlb_f("_lclose", _lclose), xlb_f("_lcreat", _lcreat), xlb_f("_llseek", _llseek),
        xlb_f("_lopen", _lopen), xlb_f("_lread", _lread), xlb_f("_lwrite", _lwrite),
        xlb_f("AccessCheckAndAuditAlarm", AccessCheckAndAuditAlarm),
        xlb_f("AccessCheckByTypeAndAuditAlarm", AccessCheckByTypeAndAuditAlarm),
        xlb_f("AccessCheckByTypeResultListAndAuditAlarm", AccessCheckByTypeResultListAndAuditAlarm),
        xlb_f(
            "AccessCheckByTypeResultListAndAuditAlarmByHandle",
            AccessCheckByTypeResultListAndAuditAlarmByHandle),
        xlb_f("ActivateActCtx", ActivateActCtx), xlb_f("AddAtom", AddAtom),
        xlb_f("AddConditionalAce", AddConditionalAce),
        xlb_f("AddIntegrityLabelToBoundaryDescriptor", AddIntegrityLabelToBoundaryDescriptor),
        xlb_f("AddRefActCtx", AddRefActCtx),
#if defined(WINVER) && (WINVER >= 0x0600)
        xlb_class<xlb_cbf<PSECURE_MEMORY_CACHE_CALLBACK>>("PSECURE_MEMORY_CACHE_CALLBACK")
            .constructor<xlb_luafunc>(),
        xlb_f("AddSecureMemoryCacheCallback", AddSecureMemoryCacheCallback),
#endif
        xlb_f("ApplicationRecoveryFinished", ApplicationRecoveryFinished),
        xlb_f("ApplicationRecoveryInProgress", ApplicationRecoveryInProgress),
        xlb_f("BackupEventLog", BackupEventLog), xlb_f("BackupRead", BackupRead),
        xlb_f("BackupSeek", BackupSeek), xlb_f("BackupWrite", BackupWrite),
        xlb_f("BeginUpdateResource", BeginUpdateResource),
        xlb_f("BindIoCompletionCallback", BindIoCompletionCallback),
        xlb_f("BuildCommDCB", BuildCommDCB),
        xlb_f("BuildCommDCBAndTimeouts", BuildCommDCBAndTimeouts),
        xlb_f("CallNamedPipe", CallNamedPipe),
        xlb_f("CheckNameLegalDOS8Dot3", CheckNameLegalDOS8Dot3),
        xlb_f("ClearCommBreak", ClearCommBreak), xlb_f("ClearCommError", ClearCommError),
        xlb_f("ClearEventLog", ClearEventLog),
        xlb_f("CloseEncryptedFileRaw", CloseEncryptedFileRaw),
        xlb_f("CloseEventLog", CloseEventLog), xlb_f("CommConfigDialog", CommConfigDialog),
        xlb_f("ConvertFiberToThread", ConvertFiberToThread),
        xlb_f("ConvertThreadToFiber", ConvertThreadToFiber),
        xlb_f("ConvertThreadToFiberEx", ConvertThreadToFiberEx), xlb_f("CopyContext", CopyContext),
        xlb_f("CopyFile", CopyFile),

#if defined(WINVER) && (WINVER >= 0x0602)
        xlb_f("CopyFile2", CopyFile2), // Win8
#endif

        xlb_f("CopyFileEx", CopyFileEx), xlb_f("CopyFileTransacted", CopyFileTransacted),
        xlb_f("CreateActCtx", CreateActCtx),
        xlb_f("CreateBoundaryDescriptor", CreateBoundaryDescriptor),
        xlb_f("CreateDirectory", CreateDirectory), xlb_f("CreateDirectoryEx", CreateDirectoryEx),
        xlb_f("CreateDirectoryTransacted", CreateDirectoryTransacted),
        xlb_f("CreateFiber", CreateFiber), xlb_f("CreateFiberEx", CreateFiberEx),
        xlb_f("CreateFileMapping", CreateFileMapping),
        xlb_f("CreateFileMappingNuma", CreateFileMappingNuma),
        xlb_f("CreateFileTransacted", CreateFileTransacted),
        xlb_f("CreateHardLink", CreateHardLink),
        xlb_f("CreateHardLinkTransacted", CreateHardLinkTransacted),
        xlb_f("CreateJobObject", CreateJobObject), xlb_f("CreateMailslot", CreateMailslot),
        xlb_f("CreateNamedPipe", CreateNamedPipe),
        xlb_f("CreatePrivateNamespace", CreatePrivateNamespace),
        xlb_f("CreateSemaphore", CreateSemaphore), xlb_f("CreateSemaphoreEx", CreateSemaphoreEx),
        xlb_f("CreateSymbolicLink", CreateSymbolicLink),
        xlb_f("CreateSymbolicLinkTransacted", CreateSymbolicLinkTransacted),
        xlb_f("CreateTapePartition", CreateTapePartition),

#ifdef _WIN64
        xlb_f("CreateUmsCompletionList", CreateUmsCompletionList),
        xlb_f("CreateUmsThreadContext", CreateUmsThreadContext),
        xlb_f("DeleteUmsCompletionList", DeleteUmsCompletionList),
        xlb_f("DeleteUmsThreadContext", DeleteUmsThreadContext),
        xlb_f("DequeueUmsCompletionListItems", DequeueUmsCompletionListItems),
        xlb_f("EnterUmsSchedulingMode", EnterUmsSchedulingMode),
        xlb_f("ExecuteUmsThread", ExecuteUmsThread),
        xlb_f("GetCurrentUmsThread", GetCurrentUmsThread),
        xlb_f("GetNextUmsListItem", GetNextUmsListItem),
        xlb_f("GetUmsCompletionListEvent", GetUmsCompletionListEvent),
        xlb_f("GetUmsSystemThreadInformation", GetUmsSystemThreadInformation),
        xlb_f("QueryUmsThreadInformation", QueryUmsThreadInformation),
        xlb_f("SetUmsThreadInformation", SetUmsThreadInformation),
        xlb_f("UmsThreadYield", UmsThreadYield),
#endif

        xlb_f("DeactivateActCtx", DeactivateActCtx), xlb_f("DebugBreakProcess", DebugBreakProcess),
        xlb_f("DebugSetProcessKillOnExit", DebugSetProcessKillOnExit),
        xlb_f("DecryptFile", DecryptFile), xlb_f("DefineDosDevice", DefineDosDevice),
        xlb_f("DeleteAtom", DeleteAtom), xlb_f("DeleteFiber", DeleteFiber),
        xlb_f("DeleteFile", DeleteFile), xlb_f("DeleteFileTransacted", DeleteFileTransacted),
        xlb_f("DeleteTimerQueue", DeleteTimerQueue),
        xlb_f("DeleteVolumeMountPoint", DeleteVolumeMountPoint),
        xlb_f("DeregisterEventSource", DeregisterEventSource),
        xlb_f("DestroyThreadpoolEnvironment", DestroyThreadpoolEnvironment),
        xlb_f("DisableThreadProfiling", DisableThreadProfiling),
        xlb_f("DnsHostnameToComputerName", DnsHostnameToComputerName),
        xlb_f("DosDateTimeToFileTime", DosDateTimeToFileTime),
        xlb_f("EnableThreadProfiling", EnableThreadProfiling), xlb_f("EncryptFile", EncryptFile),
        xlb_f("EndUpdateResource", EndUpdateResource),
        xlb_f("EnumResourceLanguages", EnumResourceLanguages),
        xlb_f("EnumResourceNames", EnumResourceNames),
        xlb_f("EnumResourceTypes", EnumResourceTypes), xlb_f("EraseTape", EraseTape),
        xlb_f("EscapeCommFunction", EscapeCommFunction), xlb_f("FatalExit", FatalExit),
        xlb_f("FileEncryptionStatus", FileEncryptionStatus),
        xlb_f("FileTimeToDosDateTime", FileTimeToDosDateTime),
        xlb_f("FindActCtxSectionGuid", FindActCtxSectionGuid),
        xlb_f("FindActCtxSectionString", FindActCtxSectionString), xlb_f("FindAtom", FindAtom),
        xlb_f("FindFirstFileTransacted", FindFirstFileTransacted),
        xlb_f("FindFirstVolume", FindFirstVolume),
        xlb_f("FindFirstVolumeMountPoint", FindFirstVolumeMountPoint),
        xlb_f("FindNextVolume", FindNextVolume),
        xlb_f("FindNextVolumeMountPoint", FindNextVolumeMountPoint),
        xlb_f("FindResource", FindResource), xlb_f("FindResourceEx", FindResourceEx),
        xlb_f("FindVolumeMountPointClose", FindVolumeMountPointClose),
        xlb_f("FormatMessage", FormatMessage), xlb_f("FormatMessage", FormatMessage),
        xlb_f("GetActiveProcessorCount", GetActiveProcessorCount),
        xlb_f("GetActiveProcessorGroupCount", GetActiveProcessorGroupCount),
        xlb_f("GetApplicationRecoveryCallback", GetApplicationRecoveryCallback),
        xlb_f("GetApplicationRestartSettings", GetApplicationRestartSettings),
        xlb_f("GetAtomName", GetAtomName), xlb_f("GetBinaryType", GetBinaryType),
        xlb_f("GetCommConfig", GetCommConfig), xlb_f("GetCommMask", GetCommMask),
        xlb_f("GetCommModemStatus", GetCommModemStatus),

#if defined(WINVER) && (WINVER >= 0x0A00)
        xlb_f("GetCommPorts", GetCommPorts), // FIXME: Windows 10
#endif

        xlb_f("GetCommProperties", GetCommProperties), xlb_f("GetCommState", GetCommState),
        xlb_f("GetCommTimeouts", GetCommTimeouts),
        xlb_f("GetCompressedFileSizeTransacted", GetCompressedFileSizeTransacted),
        xlb_f("GetComputerName", GetComputerName), xlb_f("GetCurrentActCtx", GetCurrentActCtx),
        xlb_f("GetCurrentDirectory", GetCurrentDirectory),
        xlb_f("GetCurrentHwProfile", GetCurrentHwProfile),
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
#if defined(WINVER) && (WINVER >= 0x0602)
        xlb_f("GetFirmwareEnvironmentVariableEx", GetFirmwareEnvironmentVariableEx),
        xlb_f("GetFirmwareType", GetFirmwareType),
#endif
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
        xlb_f("GetProfileInt", GetProfileInt), xlb_f("GetProfileSection", GetProfileSection),
        xlb_f("GetProfileString", GetProfileString), xlb_f("GetShortPathName", GetShortPathName),
        xlb_f("GetSystemDEPPolicy", GetSystemDEPPolicy),
        xlb_f("GetSystemPowerStatus", GetSystemPowerStatus),
        xlb_f("GetSystemRegistryQuota", GetSystemRegistryQuota),
        xlb_f("GetTapeParameters", GetTapeParameters), xlb_f("GetTapePosition", GetTapePosition),
        xlb_f("GetTapeStatus", GetTapeStatus), xlb_f("GetTempFileName", GetTempFileName),
        xlb_f("GetThreadSelectorEntry", GetThreadSelectorEntry), xlb_f("GetUserName", GetUserName),
        xlb_f("GetVolumeNameForVolumeMountPoint", GetVolumeNameForVolumeMountPoint),
        xlb_f("GetVolumePathName", GetVolumePathName),
        xlb_f("GetVolumePathNamesForVolumeName", GetVolumePathNamesForVolumeName),
        xlb_f("GetXStateFeaturesMask", GetXStateFeaturesMask),
        xlb_f("GlobalAddAtom", GlobalAddAtom),
#if defined(WINVER) && (WINVER >= 0x0602)
        xlb_f("GlobalAddAtomEx", GlobalAddAtomEx), // FIXME: Fail in Win7
#endif
        xlb_f("GlobalAlloc", GlobalAlloc), xlb_f("GlobalDeleteAtom", GlobalDeleteAtom),
        xlb_f("GlobalDiscard", [](HGLOBAL h) { GlobalDiscard(h); }),
        xlb_f("GlobalFindAtom", GlobalFindAtom), xlb_f("GlobalFlags", GlobalFlags),
        xlb_f("GlobalFree", GlobalFree), xlb_f("GlobalGetAtomName", GlobalGetAtomName),
        xlb_f("GlobalHandle", GlobalHandle), xlb_f("GlobalLock", GlobalLock),
        xlb_f("GlobalMemoryStatus", GlobalMemoryStatus), xlb_f("GlobalReAlloc", GlobalReAlloc),
        xlb_f("GlobalSize", GlobalSize), xlb_f("GlobalUnlock", GlobalUnlock),

        xlb_class<GUID>("GUID")
            .constructor<>()
            .destructor()
            .property("Data1", &GUID::Data1)
            .property("Data2", &GUID::Data2)
            .property("Data3", &GUID::Data3)
            .property("Data4", &GUID::Data4),

        xlb_f("HasOverlappedIoCompleted", [](OVERLAPPED *lp) { HasOverlappedIoCompleted(lp); }),
        xlb_f("InitAtomTable", InitAtomTable), xlb_f("InitializeContext", InitializeContext),
        xlb_f("InitializeThreadpoolEnvironment", InitializeThreadpoolEnvironment),
        xlb_f<unsigned long (*)(unsigned long volatile *, unsigned long)>(
            "InterlockedExchangeSubtract", InterlockedExchangeSubtract),
        xlb_f("IsBadCodePtr", IsBadCodePtr), xlb_f("IsBadReadPtr", IsBadReadPtr),
        xlb_f("IsBadStringPtr", IsBadStringPtr), xlb_f("IsBadWritePtr", IsBadWritePtr),

#if defined(WINVER) && (WINVER >= 0x0602)
        xlb_f("IsNativeVhdBoot", IsNativeVhdBoot),
#endif

        xlb_f("IsSystemResumeAutomatic", IsSystemResumeAutomatic),
        xlb_f("IsTextUnicode", IsTextUnicode), xlb_f("LoadModule", LoadModule),

#if defined(WINVER) && (WINVER >= 0x0602)
        xlb_f("LoadPackagedLibrary", LoadPackagedLibrary),
#endif

        xlb_f("LocalAlloc", LocalAlloc), xlb_f("LocalFlags", LocalFlags),
        xlb_f("LocalFree", LocalFree), xlb_f("LocalHandle", LocalHandle),
        xlb_f("LocalLock", LocalLock), xlb_f("LocalReAlloc", LocalReAlloc),
        xlb_f("LocalSize", LocalSize), xlb_f("LocalUnlock", LocalUnlock),
        xlb_f("LocateXStateFeature", LocateXStateFeature), xlb_f("LogonUser", LogonUser),
        xlb_f("LogonUserEx", LogonUserEx), xlb_f("LookupAccountName", LookupAccountName),
        xlb_f("LookupAccountSid", LookupAccountSid),
        // xlb_f("LookupAccountSidLocal", LookupAccountSidLocal), //FIXME:
        // unsolved
        xlb_f("LookupPrivilegeDisplayName", LookupPrivilegeDisplayName),
        xlb_f("LookupPrivilegeName", LookupPrivilegeName),
        xlb_f("LookupPrivilegeValue", LookupPrivilegeValue), xlb_f("lstrcat", lstrcat),
        xlb_f("lstrcmp", lstrcmp), xlb_f("lstrcmpi", lstrcmpi), xlb_f("lstrcpy", lstrcpy),
        xlb_f("lstrcpyn", lstrcpyn), xlb_f("lstrlen", lstrlen),
        xlb_f("MAKEINTATOM", [](LPTSTR i) -> LPTSTR { return MAKEINTATOM(i); }),
        xlb_f("MapUserPhysicalPagesScatter", MapUserPhysicalPagesScatter),
        xlb_f("MapViewOfFileExNuma", MapViewOfFileExNuma), xlb_f("MoveFile", MoveFile),
        xlb_f("MoveFileEx", MoveFileEx), xlb_f("MoveFileTransacted", MoveFileTransacted),
        xlb_f("MoveFileWithProgress", MoveFileWithProgress), xlb_f("MulDiv", MulDiv),

        xlb_f("NotifyChangeEventLog", NotifyChangeEventLog),
        xlb_f("ObjectCloseAuditAlarm", ObjectCloseAuditAlarm),
        xlb_f("ObjectDeleteAuditAlarm", ObjectDeleteAuditAlarm),
        xlb_f("ObjectOpenAuditAlarm", ObjectOpenAuditAlarm),
        xlb_f("ObjectPrivilegeAuditAlarm", ObjectPrivilegeAuditAlarm),
        xlb_f("OpenBackupEventLog", OpenBackupEventLog),

#if defined(WINVER) && (WINVER >= 0x0A00)
        xlb_f("OpenCommPort", OpenCommPort),
#endif

        xlb_f("OpenEncryptedFileRaw", OpenEncryptedFileRaw), xlb_f("OpenEventLog", OpenEventLog),
        xlb_f("OpenFile", OpenFile), xlb_f("OpenFileById", OpenFileById),
        xlb_f("OpenFileMapping", OpenFileMapping), xlb_f("OpenJobObject", OpenJobObject),
        xlb_f("OpenPrivateNamespace", OpenPrivateNamespace),

#if defined(WINVER) && (WINVER >= 0x0602)
        xlb_f("OperationEnd", OperationEnd), xlb_f("OperationStart", OperationStart),
#endif

        xlb_f("PowerClearRequest", PowerClearRequest),
        xlb_f("PowerCreateRequest", PowerCreateRequest), xlb_f("PowerSetRequest", PowerSetRequest),
        xlb_f("PrepareTape", PrepareTape),
        xlb_f("PrivilegedServiceAuditAlarm", PrivilegedServiceAuditAlarm),
        xlb_f("PulseEvent", PulseEvent),
        // xlb_f("PurgeComm", PurgeComm),
        xlb_f("QueryDosDevice", QueryDosDevice),
        xlb_f("QueryFullProcessImageName", QueryFullProcessImageName),
        xlb_f("QueryThreadProfiling", QueryThreadProfiling),
        xlb_f("ReadEncryptedFileRaw", ReadEncryptedFileRaw), xlb_f("ReadEventLog", ReadEventLog),
        xlb_f("ReadThreadProfilingData", ReadThreadProfilingData),
        xlb_f("RegisterApplicationRecoveryCallback", RegisterApplicationRecoveryCallback),
        xlb_f("RegisterApplicationRestart", RegisterApplicationRestart),
        xlb_f("RegisterEventSource", RegisterEventSource),
        xlb_f("RegisterWaitForSingleObject", RegisterWaitForSingleObject),
        xlb_f("ReleaseActCtx", ReleaseActCtx),
        xlb_f("RemoveDirectoryTransacted", RemoveDirectoryTransacted),
        xlb_f("RemoveSecureMemoryCacheCallback", RemoveSecureMemoryCacheCallback),
        xlb_f("ReOpenFile", ReOpenFile), xlb_f("ReplaceFile", ReplaceFile),
        xlb_f("ReportEvent", ReportEvent), xlb_f("RequestWakeupLatency", RequestWakeupLatency),
        xlb_f("SetCommBreak", SetCommBreak), xlb_f("SetCommConfig", SetCommConfig),
        xlb_f("SetCommMask", SetCommMask), xlb_f("SetCommState", SetCommState),
        xlb_f("SetCommTimeouts", SetCommTimeouts),
        xlb_f("SetCurrentDirectory", SetCurrentDirectory),
        xlb_f("SetDefaultCommConfig", SetDefaultCommConfig),

        xlb_f("SetDllDirectory", SetDllDirectory),
        xlb_f("SetEnvironmentVariable", SetEnvironmentVariable),
        xlb_f("SetFileAttributesTransacted", SetFileAttributesTransacted),
        xlb_f("SetFileBandwidthReservation", SetFileBandwidthReservation),
        xlb_f("SetFileCompletionNotificationModes", SetFileCompletionNotificationModes),
        xlb_f("SetFileSecurity", SetFileSecurity), xlb_f("SetFileShortName", SetFileShortName),
        xlb_f("SetFirmwareEnvironmentVariable", SetFirmwareEnvironmentVariable),

#if defined(WINVER) && (WINVER >= 0x0602)
        xlb_f("SetFirmwareEnvironmentVariableEx", SetFirmwareEnvironmentVariableEx),
#endif

        xlb_f("SetMailslotInfo", SetMailslotInfo),
        xlb_f("SetProcessAffinityMask", SetProcessAffinityMask),
        xlb_f("SetProcessDEPPolicy", SetProcessDEPPolicy),
        xlb_f("SetProcessWorkingSetSize", SetProcessWorkingSetSize),
        xlb_f("SetSearchPathMode", SetSearchPathMode),
        xlb_f("SetSystemPowerState", SetSystemPowerState),
        xlb_f("SetTapeParameters", SetTapeParameters), xlb_f("SetTapePosition", SetTapePosition),
        xlb_f("SetThreadAffinityMask", SetThreadAffinityMask),
        xlb_f("SetThreadExecutionState", SetThreadExecutionState),
        xlb_f("SetThreadpoolCallbackCleanupGroup", SetThreadpoolCallbackCleanupGroup),
        xlb_f("SetThreadpoolCallbackLibrary", SetThreadpoolCallbackLibrary),
        xlb_f("SetThreadpoolCallbackPersistent", SetThreadpoolCallbackPersistent),
        xlb_f("SetThreadpoolCallbackPool", SetThreadpoolCallbackPool),
        xlb_f("SetThreadpoolCallbackPriority", SetThreadpoolCallbackPriority),
        xlb_f("SetThreadpoolCallbackRunsLong", SetThreadpoolCallbackRunsLong),
        xlb_f("SetupComm", SetupComm), xlb_f("SetVolumeLabel", SetVolumeLabel),
        xlb_f("SetVolumeMountPoint", SetVolumeMountPoint),
        xlb_f("SetXStateFeaturesMask", SetXStateFeaturesMask),
        xlb_f("SwitchToFiber", SwitchToFiber), xlb_f("TransmitCommChar", TransmitCommChar),
        xlb_f("UnregisterApplicationRecoveryCallback", UnregisterApplicationRecoveryCallback),
        xlb_f("UnregisterApplicationRestart", UnregisterApplicationRestart),
        xlb_f("UnregisterWait", UnregisterWait), xlb_f("UpdateResource", UpdateResource),
        xlb_f("VerifyVersionInfo", VerifyVersionInfo), xlb_f("WaitCommEvent", WaitCommEvent),
        xlb_f("WaitNamedPipe", WaitNamedPipe), xlb_f("WinExec", WinExec),
        ////xlb_f("WinMain", WinMain),
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
        xlb_f("WriteProfileString", WriteProfileString), xlb_f("WriteTapemark", WriteTapemark),
        xlb_f("WTSGetActiveConsoleSessionId", WTSGetActiveConsoleSessionId),
        xlb_f("ZombifyActCtx", ZombifyActCtx)
#ifdef dbg_compile
#endif

  });
#endif // defined(BIND_BASE)

  return 0;
} // load_base