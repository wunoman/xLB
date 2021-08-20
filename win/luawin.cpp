//------------------------------------------------------------------------------------------------
// bind Windows API to Lua using XLB
//------------------------------------------------------------------------------------------------
#include "luawin.h"

//build app and provide WINVER as argument, such as
//build WINVER=0x0601

//------------------------------------------------------------------------------------------------
// XXX: /DEF:win.def
// module main
int luaopen_luawin(lua_State* L) {

    xlb_module{L, MODULE_NAME} ({
    });
    bind_win_api_desktop_tech(L);
    return 0;
}

//------------------------------------------------------------------------------------------------
int bind_win_api_desktop_tech(lua_State* L) {
    //xlb_debug("PROCESS_TERMINATE=0x%x\n", PROCESS_TERMINATE);
    xlb_module(L, MODULE_NAME) ({
        xlb_f("load_base",       load_base             ),

#ifdef BIND_MSG
        xlb_f("load_msg",        load_msg              ),
#endif
#ifdef BIND_GDI
        xlb_f("load_gdi",        load_gdi              ),
#endif
#ifdef BIND_DLG
        xlb_f("load_dialog",     load_dialog           ),
#endif
#ifdef BIND_SNMP
        xlb_f("load_snmp",       load_snmp             ),
#endif
#ifdef BIND_PROCESS
        xlb_f("load_process",    load_process          ),
#endif
#ifdef BIND_KM
        xlb_f("load_km",         load_km               ),
#endif
#ifdef BIND_CTRL
        xlb_f("load_ctrl",       load_ctrl             ),
#endif
#ifdef BIND_NWM
        xlb_f("load_nwm",        load_nwm              ),
#endif
#ifdef BIND_SHL
        xlb_f("load_shl",        load_shl              ),
#endif
#ifdef BIND_COM
        xlb_f("load_com",        load_com              ),
#endif
        xlb_const("WINVER", WINVER),
        xlb_const("VERSION", "Windows API (Lua53)")
    });
    return 0;
} // bind_win_api_desktop_tech

//------------------------------------------------------------------------------------------------
int load_base(lua_State* L)
{
#if defined(CHECK_BIND_BASE)
    xlb_module(L, MODULE_NAME) ({
        xlb_const("WINVER", WINVER),
        xlb_f("pvtostring", xlb_pvtostring),
        xlb_f("pvtointeger", xlb_pvtointeger),
        xlb_f("xlb_type", xlb_type),

        xlb_f("malloc", malloc),
        xlb_f("free", free),
        xlb_f("realloc", realloc),
        xlb_f("GetLastError", GetLastError),

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

#if defined(WINVER) && (WINVER>=0x0602)
        xlb_f("CopyFile2", CopyFile2), // Win8
#endif

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
        xlb_f("DeleteVolumeMountPoint", DeleteVolumeMountPoint),
        xlb_f("DeregisterEventSource", DeregisterEventSource),
        xlb_f("DestroyThreadpoolEnvironment", DestroyThreadpoolEnvironment),
        xlb_f("DisableThreadProfiling", DisableThreadProfiling),
        xlb_f("DnsHostnameToComputerName", DnsHostnameToComputerName),
        xlb_f("DosDateTimeToFileTime", DosDateTimeToFileTime),
        xlb_f("EnableThreadProfiling", EnableThreadProfiling),
        xlb_f("EncryptFile", EncryptFile),
        xlb_f("EndUpdateResource", EndUpdateResource),
        xlb_f("EnumResourceLanguages", EnumResourceLanguages),
        xlb_f("EnumResourceNames", EnumResourceNames),
        xlb_f("EnumResourceTypes", EnumResourceTypes),
        xlb_f("EraseTape", EraseTape),
        xlb_f("EscapeCommFunction", EscapeCommFunction),
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

#if defined(WINVER) && (WINVER>=0x0A00)
        xlb_f("GetCommPorts", GetCommPorts), // FIXME: Windows 10
#endif

        xlb_f("GetCommProperties", GetCommProperties),
        xlb_f("GetCommState", GetCommState),
        xlb_f("GetCommTimeouts", GetCommTimeouts),
        xlb_f("GetCompressedFileSizeTransacted", GetCompressedFileSizeTransacted),
        xlb_f("GetComputerName", GetComputerName),
        xlb_f("GetCurrentActCtx", GetCurrentActCtx),
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
#if defined(WINVER) && (WINVER>=0x0602)
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
        xlb_f("GetUserName", GetUserName),
        xlb_f("GetVolumeNameForVolumeMountPoint", GetVolumeNameForVolumeMountPoint),
        xlb_f("GetVolumePathName", GetVolumePathName),
        xlb_f("GetVolumePathNamesForVolumeName", GetVolumePathNamesForVolumeName),
        xlb_f("GetXStateFeaturesMask", GetXStateFeaturesMask),
        xlb_f("GlobalAddAtom", GlobalAddAtom),
#if defined(WINVER) && (WINVER>=0x0602)
        xlb_f("GlobalAddAtomEx", GlobalAddAtomEx), // FIXME: Fail in Win7
#endif
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

        xlb_class<GUID>("GUID") .constructor<>() .destructor()
            .property("Data1", &GUID::Data1)
            .property("Data2", &GUID::Data2)
            .property("Data3", &GUID::Data3)
            .property("Data4", &GUID::Data4)
            ,

        xlb_f("HasOverlappedIoCompleted", [](OVERLAPPED* lp) { HasOverlappedIoCompleted(lp); }),
        xlb_f("InitAtomTable", InitAtomTable),
        xlb_f("InitializeContext", InitializeContext),
        xlb_f("InitializeThreadpoolEnvironment", InitializeThreadpoolEnvironment),
        xlb_f<unsigned long(*)(unsigned long volatile *, unsigned long)>(
                "InterlockedExchangeSubtract", InterlockedExchangeSubtract),
        xlb_f("IsBadCodePtr", IsBadCodePtr),
        xlb_f("IsBadReadPtr", IsBadReadPtr),
        xlb_f("IsBadStringPtr", IsBadStringPtr),
        xlb_f("IsBadWritePtr", IsBadWritePtr),

#if defined(WINVER) && (WINVER>=0x0602)
        xlb_f("IsNativeVhdBoot", IsNativeVhdBoot),
#endif

        xlb_f("IsSystemResumeAutomatic", IsSystemResumeAutomatic),
        xlb_f("IsTextUnicode", IsTextUnicode),
        xlb_f("LoadModule", LoadModule),

#if defined(WINVER) && (WINVER>=0x0602)
        xlb_f("LoadPackagedLibrary", LoadPackagedLibrary),
#endif

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
        //xlb_f("LookupAccountSidLocal", LookupAccountSidLocal), //FIXME: unsolved
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

#if defined(WINVER) && (WINVER>=0x0A00)
        xlb_f("OpenCommPort", OpenCommPort),
#endif

        xlb_f("OpenEncryptedFileRaw", OpenEncryptedFileRaw),
        xlb_f("OpenEventLog", OpenEventLog),
        xlb_f("OpenFile", OpenFile),
        xlb_f("OpenFileById", OpenFileById),
        xlb_f("OpenFileMapping", OpenFileMapping),
        xlb_f("OpenJobObject", OpenJobObject),
        xlb_f("OpenPrivateNamespace", OpenPrivateNamespace),

#if defined(WINVER) && (WINVER>=0x0602)
        xlb_f("OperationEnd", OperationEnd),
        xlb_f("OperationStart", OperationStart),
#endif

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
        xlb_f("SetCommBreak", SetCommBreak),
        xlb_f("SetCommConfig", SetCommConfig),
        xlb_f("SetCommMask", SetCommMask),
        xlb_f("SetCommState", SetCommState),
        xlb_f("SetCommTimeouts", SetCommTimeouts),
        xlb_f("SetCurrentDirectory", SetCurrentDirectory),
        xlb_f("SetDefaultCommConfig", SetDefaultCommConfig),

        xlb_f("SetDllDirectory", SetDllDirectory),
        xlb_f("SetEnvironmentVariable", SetEnvironmentVariable),
        xlb_f("SetFileAttributesTransacted", SetFileAttributesTransacted),
        xlb_f("SetFileBandwidthReservation", SetFileBandwidthReservation),
        xlb_f("SetFileCompletionNotificationModes", SetFileCompletionNotificationModes),
        xlb_f("SetFileSecurity", SetFileSecurity),
        xlb_f("SetFileShortName", SetFileShortName),
        xlb_f("SetFirmwareEnvironmentVariable", SetFirmwareEnvironmentVariable),

#if defined(WINVER) && (WINVER>=0x0602)
        xlb_f("SetFirmwareEnvironmentVariableEx", SetFirmwareEnvironmentVariableEx),
#endif

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
        xlb_f("SetupComm", SetupComm),
        xlb_f("SetVolumeLabel", SetVolumeLabel),
        xlb_f("SetVolumeMountPoint", SetVolumeMountPoint),
        xlb_f("SetXStateFeaturesMask", SetXStateFeaturesMask),
        xlb_f("SwitchToFiber", SwitchToFiber),
        xlb_f("TransmitCommChar", TransmitCommChar),
        xlb_f("UnregisterApplicationRecoveryCallback", UnregisterApplicationRecoveryCallback),
        xlb_f("UnregisterApplicationRestart", UnregisterApplicationRestart),
        xlb_f("UnregisterWait", UnregisterWait),
        xlb_f("UpdateResource", UpdateResource),
        xlb_f("VerifyVersionInfo", VerifyVersionInfo),
        xlb_f("WaitCommEvent", WaitCommEvent),
        xlb_f("WaitNamedPipe", WaitNamedPipe),
        xlb_f("WinExec", WinExec),
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
        xlb_f("WriteProfileString", WriteProfileString),
        xlb_f("WriteTapemark", WriteTapemark),
        xlb_f("WTSGetActiveConsoleSessionId", WTSGetActiveConsoleSessionId),
        xlb_f("ZombifyActCtx", ZombifyActCtx),

        xlb_const("CHECK_BIND_BASE", CHECK_BIND_BASE)
    });
#endif // defined(CHECK_BIND_BASE)

    return 0;
} // load_base


//------------------------------------------------------------------------------------------------
