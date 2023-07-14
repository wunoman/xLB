#include "luawin.h"

//------------------------------------------------------------------------------------------------
int load_proc(lua_State *L) {
#if defined(BIND_PROC)
  xlb_module(L, MODULE_NAME)({
  // Process Functions
#if (defined WINVER) && (WINVER >= 0x0A00)
    xlb_f("CreateDispatcherQueueController", CreateDispatcherQueueController),
#endif
        xlb_f("CreateProcess", CreateProcess), xlb_f("CreateProcessAsUser", CreateProcessAsUser),
        xlb_f("CreateProcessWithLogonW", CreateProcessWithLogonW),
        xlb_f("CreateProcessWithTokenW", CreateProcessWithTokenW),
        xlb_f("ExitProcess", [](UINT uExitCode) { ExitProcess(uExitCode); }),
        xlb_f("FlushProcessWriteBuffers", FlushProcessWriteBuffers),
        xlb_f("FreeEnvironmentStrings", FreeEnvironmentStrings),
        xlb_f("GetCommandLine", GetCommandLine), xlb_f("GetCurrentProcess", GetCurrentProcess),
        xlb_f("GetCurrentProcessId", GetCurrentProcessId),
        xlb_f("GetCurrentProcessorNumber", GetCurrentProcessorNumber),
        xlb_f("GetEnvironmentStrings", GetEnvironmentStrings),
        xlb_f("GetEnvironmentVariable", GetEnvironmentVariable),
        xlb_f("GetExitCodeProcess", GetExitCodeProcess), xlb_f("GetGuiResources", GetGuiResources),
        xlb_f("GetLogicalProcessorInformation", GetLogicalProcessorInformation),
        xlb_f("GetPriorityClass", GetPriorityClass),
        xlb_f("GetProcessAffinityMask", GetProcessAffinityMask),
        xlb_f("GetProcessGroupAffinity", GetProcessGroupAffinity),
        xlb_f("GetProcessHandleCount", GetProcessHandleCount), xlb_f("GetProcessId", GetProcessId),
        xlb_f("GetProcessIdOfThread", GetProcessIdOfThread),
        xlb_f("GetProcessIoCounters", GetProcessIoCounters),
#if (WINVER >= 0x0602)
        xlb_f("GetProcessMitigationPolicy", GetProcessMitigationPolicy),
#endif
        xlb_f("GetProcessPriorityBoost", GetProcessPriorityBoost),
        xlb_f("GetProcessShutdownParameters", GetProcessShutdownParameters),
        xlb_f("GetProcessTimes", GetProcessTimes), xlb_f("GetProcessVersion", GetProcessVersion),
        xlb_f("GetProcessWorkingSetSize", GetProcessWorkingSetSize),
        xlb_f("GetProcessWorkingSetSizeEx", GetProcessWorkingSetSizeEx),
        xlb_f("GetProcessorSystemCycleTime", GetProcessorSystemCycleTime),
        xlb_f("GetStartupInfo", GetStartupInfo),
#if (WINVER >= 0x0602)
        xlb_f("IsImmersiveProcess", IsImmersiveProcess),
#endif
        xlb_f("NeedCurrentDirectoryForExePath", NeedCurrentDirectoryForExePath),
        xlb_f("OpenProcess", OpenProcess),
        xlb_f<GETPROCESSHANDLEFROMHWND>(
            "GetProcessHandleFromHwnd", nullptr,
            Win32_libf::CreateFmatHandler(_T("Oleacc.dll"), "GetProcessHandleFromHwnd")),

        xlb_const("PROCESS_ALL_ACCESS", PROCESS_ALL_ACCESS),
        xlb_const("PROCESS_CREATE_PROCESS", PROCESS_CREATE_PROCESS),
        xlb_const("PROCESS_CREATE_THREAD", PROCESS_CREATE_THREAD),
        xlb_const("PROCESS_DUP_HANDLE", PROCESS_DUP_HANDLE),
        xlb_const("PROCESS_QUERY_INFORMATION", PROCESS_QUERY_INFORMATION),
        xlb_const("PROCESS_QUERY_LIMITED_INFORMATION", PROCESS_QUERY_LIMITED_INFORMATION),
        xlb_const("PROCESS_SET_INFORMATION", PROCESS_SET_INFORMATION),
        xlb_const("PROCESS_SET_QUOTA", PROCESS_SET_QUOTA),
        xlb_const("PROCESS_SUSPEND_RESUME", PROCESS_SUSPEND_RESUME),
        xlb_const("PROCESS_TERMINATE", PROCESS_TERMINATE),
        xlb_const("PROCESS_VM_OPERATION", PROCESS_VM_OPERATION),
        xlb_const("PROCESS_VM_READ", PROCESS_VM_READ),
        xlb_const("PROCESS_VM_WRITE", PROCESS_VM_WRITE), xlb_const("SYNCHRONIZE", SYNCHRONIZE),

        xlb_f("QueryFullProcessImageName", QueryFullProcessImageName),
        xlb_f("QueryProcessAffinityUpdateMode", QueryProcessAffinityUpdateMode),
        xlb_f("QueryProcessCycleTime", QueryProcessCycleTime),
        xlb_f("SetEnvironmentVariable", SetEnvironmentVariable),
        xlb_f("SetPriorityClass", SetPriorityClass),
        xlb_f("SetProcessAffinityMask", SetProcessAffinityMask),
        xlb_f("SetProcessAffinityUpdateMode", SetProcessAffinityUpdateMode),
#if (WINVER >= 0x0602)
        xlb_f("SetProcessInformation", SetProcessInformation),
        xlb_f("SetProcessMitigationPolicy", SetProcessMitigationPolicy),
#endif
        xlb_f("SetProcessPriorityBoost", SetProcessPriorityBoost),
#if (WINVER >= 0x0602)
        xlb_f("SetProcessRestrictionExemption", SetProcessRestrictionExemption),
#endif
        xlb_f("SetProcessShutdownParameters", SetProcessShutdownParameters),
        xlb_f("SetProcessWorkingSetSize", SetProcessWorkingSetSize),
        xlb_f("SetProcessWorkingSetSizeEx", SetProcessWorkingSetSizeEx),
        xlb_f("TerminateProcess", TerminateProcess),

        // Process Enumeration Functions
        xlb_f("EnumProcesses", EnumProcesses), xlb_f("Process32First", Process32First),
        xlb_f("Process32Next", Process32Next),
        xlb_f("WTSEnumerateProcesses", WTSEnumerateProcesses),

    // Policy Functions
#if (WINVER >= 0x0602)
        xlb_f("QueryProtectedPolicy", QueryProtectedPolicy),
        xlb_f("SetProtectedPolicy", SetProtectedPolicy),
#endif

        // Thread Functions
        xlb_f("AttachThreadInput", AttachThreadInput),
        xlb_f("CreateRemoteThread", CreateRemoteThread),
        xlb_f("CreateRemoteThreadEx", CreateRemoteThreadEx), xlb_f("CreateThread", CreateThread),
        xlb_f("ExitThread", [](DWORD dwExitCode) { ExitThread(dwExitCode); }),
        xlb_f("GetCurrentThread", GetCurrentThread),
        xlb_f("GetCurrentThreadId", GetCurrentThreadId),
        xlb_f("GetExitCodeThread", GetExitCodeThread),
#if (WINVER >= 0x0A00)
        xlb_f("GetThreadDescription", GetThreadDescription),
#endif
        xlb_f("GetThreadGroupAffinity", GetThreadGroupAffinity), xlb_f("GetThreadId", GetThreadId),
        xlb_f("GetThreadIdealProcessorEx", GetThreadIdealProcessorEx),
#if (WINVER >= 0x0602)
        xlb_f("GetThreadInformation", GetThreadInformation),
#endif
        xlb_f("GetThreadIOPendingFlag", GetThreadIOPendingFlag),
        xlb_f("GetThreadPriority", GetThreadPriority),
        xlb_f("GetThreadPriorityBoost", GetThreadPriorityBoost),
        xlb_f("GetThreadTimes", GetThreadTimes), xlb_f("OpenThread", OpenThread),
        xlb_f("QueryIdleProcessorCycleTime", QueryIdleProcessorCycleTime),
        xlb_f("QueryThreadCycleTime", QueryThreadCycleTime), xlb_f("ResumeThread", ResumeThread),
        xlb_f("SetThreadAffinityMask", SetThreadAffinityMask),
#if (WINVER >= 0x0A00)
        xlb_f("SetThreadDescription", SetThreadDescription),
#endif
        xlb_f("SetThreadGroupAffinity", SetThreadGroupAffinity),
        xlb_f("SetThreadIdealProcessor", SetThreadIdealProcessor),
        xlb_f("SetThreadIdealProcessorEx", SetThreadIdealProcessorEx),
#if (WINVER >= 0x0602)
        xlb_f("SetThreadInformation", SetThreadInformation),
#endif
        xlb_f("SetThreadPriority", SetThreadPriority),
        xlb_f("SetThreadPriorityBoost", SetThreadPriorityBoost),
        xlb_f("SetThreadStackGuarantee", SetThreadStackGuarantee), xlb_f("Sleep", Sleep),
        xlb_f("SleepEx", SleepEx), xlb_f("SuspendThread", SuspendThread),
        xlb_f("SwitchToThread", SwitchToThread), xlb_f("TerminateThread", TerminateThread),
        xlb_class<xlb_cbf<LPTHREAD_START_ROUTINE>>("ThreadProc").constructor<xlb_luafunc>(),
        xlb_f("TlsAlloc", TlsAlloc), xlb_f("TlsFree", TlsFree), xlb_f("TlsGetValue", TlsGetValue),
        xlb_f("TlsSetValue", TlsSetValue), xlb_f("WaitForInputIdle", WaitForInputIdle),

        // Process and Thread Extended Attribute Functions
        xlb_f("DeleteProcThreadAttributeList", DeleteProcThreadAttributeList),
        xlb_f("InitializeProcThreadAttributeList", InitializeProcThreadAttributeList),
        xlb_f("UpdateProcThreadAttribute", UpdateProcThreadAttribute),
        //

        // WOW64 Functions
        xlb_f("IsWow64Message", IsWow64Message), xlb_f("IsWow64Process", IsWow64Process),
#if (WINVER >= 0x0A00)
        xlb_f("IsWow64Process2", IsWow64Process2),
#endif
        xlb_f("Wow64SuspendThread", Wow64SuspendThread),

        // Job Object Functions
        xlb_f("AssignProcessToJobObject", AssignProcessToJobObject),
        xlb_f("CreateJobObject", CreateJobObject), xlb_f("IsProcessInJob", IsProcessInJob),
        xlb_f("OpenJobObject", OpenJobObject),
        xlb_f("QueryInformationJobObject", QueryInformationJobObject),
        xlb_f("SetInformationJobObject", SetInformationJobObject),
        xlb_f("TerminateJobObject", TerminateJobObject),
        xlb_f("UserHandleGrantAccess", UserHandleGrantAccess),

        // Thread Pool Functions
        xlb_f("CallbackMayRunLong", CallbackMayRunLong),
        xlb_f("CancelThreadpoolIo", CancelThreadpoolIo), xlb_f("CloseThreadpool", CloseThreadpool),
        xlb_f("CloseThreadpoolCleanupGroup", CloseThreadpoolCleanupGroup),
        xlb_f("CloseThreadpoolCleanupGroupMembers", CloseThreadpoolCleanupGroupMembers),
        xlb_f("CloseThreadpoolIo", CloseThreadpoolIo),
        xlb_f("CloseThreadpoolTimer", CloseThreadpoolTimer),
        xlb_f("CloseThreadpoolWait", CloseThreadpoolWait),
        xlb_f("CloseThreadpoolWork", CloseThreadpoolWork),
        xlb_f("CreateThreadpool", CreateThreadpool),
        xlb_f("CreateThreadpoolCleanupGroup", CreateThreadpoolCleanupGroup),
        xlb_f("CreateThreadpoolIo", CreateThreadpoolIo),
        xlb_f("CreateThreadpoolTimer", CreateThreadpoolTimer),
        xlb_f("CreateThreadpoolWait", CreateThreadpoolWait),
        xlb_f("CreateThreadpoolWork", CreateThreadpoolWork),
        xlb_f("DestroyThreadpoolEnvironment", DestroyThreadpoolEnvironment),
        xlb_f("DisassociateCurrentThreadFromCallback", DisassociateCurrentThreadFromCallback),
        xlb_f("FreeLibraryWhenCallbackReturns", FreeLibraryWhenCallbackReturns),
        xlb_f("InitializeThreadpoolEnvironment", InitializeThreadpoolEnvironment),
        xlb_f("IsThreadpoolTimerSet", IsThreadpoolTimerSet),
        xlb_f("LeaveCriticalSectionWhenCallbackReturns", LeaveCriticalSectionWhenCallbackReturns),
        xlb_f("QueryThreadpoolStackInformation", QueryThreadpoolStackInformation),
        xlb_f("ReleaseMutexWhenCallbackReturns", ReleaseMutexWhenCallbackReturns),
        xlb_f("ReleaseSemaphoreWhenCallbackReturns", ReleaseSemaphoreWhenCallbackReturns),
        xlb_f("SetEventWhenCallbackReturns", SetEventWhenCallbackReturns),
        xlb_f("SetThreadpoolCallbackCleanupGroup", SetThreadpoolCallbackCleanupGroup),
        xlb_f("SetThreadpoolCallbackLibrary", SetThreadpoolCallbackLibrary),
        xlb_f("SetThreadpoolCallbackPersistent", SetThreadpoolCallbackPersistent),
        xlb_f("SetThreadpoolCallbackPool", SetThreadpoolCallbackPool),
        xlb_f("SetThreadpoolCallbackPriority", SetThreadpoolCallbackPriority),
        xlb_f("SetThreadpoolCallbackRunsLong", SetThreadpoolCallbackRunsLong),
        xlb_f("SetThreadpoolStackInformation", SetThreadpoolStackInformation),
        xlb_f("SetThreadpoolThreadMaximum", SetThreadpoolThreadMaximum),
        xlb_f("SetThreadpoolThreadMinimum", SetThreadpoolThreadMinimum),

#if defined(WINVER) && (WINVER >= 0x0602)
        xlb_f("SetThreadpoolTimerEx", SetThreadpoolTimerEx),
#endif
        xlb_f("SetThreadpoolTimer", SetThreadpoolTimer),
        xlb_f("SetThreadpoolWait", SetThreadpoolWait),
#if defined(WINVER) && (WINVER >= 0x0602)
        xlb_f("SetThreadpoolWaitEx", SetThreadpoolWaitEx),
#endif
        xlb_f("StartThreadpoolIo", StartThreadpoolIo),
        xlb_f("SubmitThreadpoolWork", SubmitThreadpoolWork),
        xlb_f("TpInitializeCallbackEnviron", TpInitializeCallbackEnviron),
        xlb_f("TpDestroyCallbackEnviron", TpDestroyCallbackEnviron),
        xlb_f("TpSetCallbackActivationContext", TpSetCallbackActivationContext),
        xlb_f("TpSetCallbackCleanupGroup", TpSetCallbackCleanupGroup),
        xlb_f("TpSetCallbackFinalizationCallback", TpSetCallbackFinalizationCallback),
        xlb_f("TpSetCallbackLongFunction", TpSetCallbackLongFunction),
        xlb_f("TpSetCallbackNoActivationContext", TpSetCallbackNoActivationContext),
        xlb_f("TpSetCallbackPersistent", TpSetCallbackPersistent),
        xlb_f("TpSetCallbackPriority", TpSetCallbackPriority),
        xlb_f("TpSetCallbackRaceWithDll", TpSetCallbackRaceWithDll),
        xlb_f("TpSetCallbackThreadpool", TpSetCallbackThreadpool),
        xlb_f("TrySubmitThreadpoolCallback", TrySubmitThreadpoolCallback),
        xlb_f("WaitForThreadpoolIoCallbacks", WaitForThreadpoolIoCallbacks),
        xlb_f("WaitForThreadpoolTimerCallbacks", WaitForThreadpoolTimerCallbacks),
        xlb_f("WaitForThreadpoolWaitCallbacks", WaitForThreadpoolWaitCallbacks),
        xlb_f("WaitForThreadpoolWorkCallbacks", WaitForThreadpoolWorkCallbacks),
#ifdef compile
#endif

        // part of the original thread pooling API
        xlb_f("BindIoCompletionCallback", BindIoCompletionCallback),
        xlb_f("QueueUserWorkItem", QueueUserWorkItem),
        xlb_f("RegisterWaitForSingleObject", RegisterWaitForSingleObject),
        xlb_f("UnregisterWaitEx", UnregisterWaitEx),

        // Thread Ordering Service Functions
        xlb_f("AvQuerySystemResponsiveness", AvQuerySystemResponsiveness),
        xlb_f("AvRtCreateThreadOrderingGroup", AvRtCreateThreadOrderingGroup),
        xlb_f("AvRtCreateThreadOrderingGroupEx", AvRtCreateThreadOrderingGroupEx),
        xlb_f("AvRtDeleteThreadOrderingGroup", AvRtDeleteThreadOrderingGroup),
        xlb_f("AvRtJoinThreadOrderingGroup", AvRtJoinThreadOrderingGroup),
        xlb_f("AvRtLeaveThreadOrderingGroup", AvRtLeaveThreadOrderingGroup),
        xlb_f("AvRtWaitOnThreadOrderingGroup", AvRtWaitOnThreadOrderingGroup),

        // Multimedia Class Scheduler Service Functions
        xlb_f("AvRevertMmThreadCharacteristics", AvRevertMmThreadCharacteristics),
        xlb_f("AvSetMmMaxThreadCharacteristics", AvSetMmMaxThreadCharacteristics),
        xlb_f("AvSetMmThreadCharacteristics", AvSetMmThreadCharacteristics),
        xlb_f("AvSetMmThreadPriority", AvSetMmThreadPriority),

        // Fiber Functions
        xlb_f("ConvertFiberToThread", ConvertFiberToThread),
        xlb_f("ConvertThreadToFiber", ConvertThreadToFiber),
        xlb_f("ConvertThreadToFiberEx", ConvertThreadToFiberEx), xlb_f("CreateFiber", CreateFiber),
        xlb_f("CreateFiberEx", CreateFiberEx), xlb_f("DeleteFiber", DeleteFiber),
        xlb_class<xlb_cbf<LPFIBER_START_ROUTINE>>("LPFIBER_START_ROUTINE")
            .constructor<xlb_luafunc>(), // FiberProc
        xlb_f("FlsAlloc", FlsAlloc), xlb_f("FlsFree", FlsFree), xlb_f("FlsGetValue", FlsGetValue),
        xlb_f("FlsSetValue", FlsSetValue), xlb_f("IsThreadAFiber", IsThreadAFiber),
        xlb_f("SwitchToFiber", SwitchToFiber),

        // NUMA Support Functions
        xlb_f("AllocateUserPhysicalPagesNuma", AllocateUserPhysicalPagesNuma),
        xlb_f("GetLogicalProcessorInformation", GetLogicalProcessorInformation),
        xlb_f("GetNumaAvailableMemoryNode", GetNumaAvailableMemoryNode),
        xlb_f("GetNumaAvailableMemoryNodeEx", GetNumaAvailableMemoryNodeEx),
        xlb_f("GetNumaHighestNodeNumber", GetNumaHighestNodeNumber),
        xlb_f("GetNumaNodeNumberFromHandle", GetNumaNodeNumberFromHandle),
        xlb_f("GetNumaNodeProcessorMask", GetNumaNodeProcessorMask),
        xlb_f("GetNumaNodeProcessorMaskEx", GetNumaNodeProcessorMaskEx),
        xlb_f("GetNumaProcessorNode", GetNumaProcessorNode),
        xlb_f("GetNumaProcessorNodeEx", GetNumaProcessorNodeEx),
        xlb_f("GetNumaProximityNode", GetNumaProximityNode),
        xlb_f("GetNumaProximityNodeEx", GetNumaProximityNodeEx),
        xlb_f("VirtualAllocExNuma", VirtualAllocExNuma),

        // Processor Functions
        xlb_f("GetActiveProcessorCount", GetActiveProcessorCount),
        xlb_f("GetActiveProcessorGroupCount", GetActiveProcessorGroupCount),
        xlb_f("GetCurrentProcessorNumber", GetCurrentProcessorNumber),
        xlb_f("GetCurrentProcessorNumberEx", GetCurrentProcessorNumberEx),
        xlb_f("GetLogicalProcessorInformation", GetLogicalProcessorInformation),
        xlb_f("GetLogicalProcessorInformationEx", GetLogicalProcessorInformationEx),
        xlb_f("GetMaximumProcessorCount", GetMaximumProcessorCount),
        xlb_f("GetMaximumProcessorGroupCount", GetMaximumProcessorGroupCount),
        xlb_f("QueryIdleProcessorCycleTime", QueryIdleProcessorCycleTime),
        xlb_f("QueryIdleProcessorCycleTimeEx", QueryIdleProcessorCycleTimeEx),

    // User-Mode Scheduling Functions
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
        xlb_class<xlb_cbf<PUMS_SCHEDULER_ENTRY_POINT>>("PUMS_SCHEDULER_ENTRY_POINT")
            .constructor<xlb_luafunc>(), // UmsSchedulerProc
        xlb_f("UmsThreadYield", UmsThreadYield),
#endif
        // tlhelp32
        xlb_f("CreateToolhelp32Snapshot", CreateToolhelp32Snapshot),
        xlb_const("TH32CS_SNAPHEAPLIST", TH32CS_SNAPHEAPLIST),
        xlb_const("TH32CS_SNAPPROCESS", TH32CS_SNAPPROCESS),
        xlb_const("TH32CS_SNAPTHREAD", TH32CS_SNAPTHREAD),
        xlb_const("TH32CS_SNAPMODULE", TH32CS_SNAPMODULE),
        xlb_const("TH32CS_SNAPMODULE32", TH32CS_SNAPMODULE32),
        xlb_const("TH32CS_SNAPALL", TH32CS_SNAPALL), xlb_const("TH32CS_INHERIT", TH32CS_INHERIT),
        xlb_class<HEAPLIST32>("HEAPLIST32")
            .constructor()
            .destructor()
            .property("dwSize", &HEAPLIST32::dwSize)
            .property("th32ProcessID", &HEAPLIST32::th32ProcessID)
            .property("th32HeapID", &HEAPLIST32::th32HeapID)
            .property("dwFlags", &HEAPLIST32::dwFlags),
        xlb_f("Heap32ListFirst", Heap32ListFirst), xlb_f("Heap32ListNext", Heap32ListNext),
        xlb_class<HEAPENTRY32>("HEAPENTRY32")
            .constructor()
            .destructor()
            .property("dwSize", &HEAPENTRY32::dwSize)
            .property("hHandle", &HEAPENTRY32::hHandle)
            .property("dwAddress", &HEAPENTRY32::dwAddress)
            .property("dwBlockSize", &HEAPENTRY32::dwBlockSize)
            .property("dwFlags", &HEAPENTRY32::dwFlags)
            .property("dwLockCount", &HEAPENTRY32::dwLockCount)
            .property("dwResvd", &HEAPENTRY32::dwResvd)
            .property("th32ProcessID", &HEAPENTRY32::th32ProcessID)
            .property("th32HeapID", &HEAPENTRY32::th32HeapID),
        xlb_const("LF32_FIXED", LF32_FIXED), xlb_const("LF32_FREE", LF32_FREE),
        xlb_const("LF32_MOVEABLE", LF32_MOVEABLE), xlb_f("Heap32First", Heap32First),
        xlb_f("Heap32Next", Heap32Next),
        xlb_f("Toolhelp32ReadProcessMemory", Toolhelp32ReadProcessMemory),
        xlb_class<PROCESSENTRY32>("PROCESSENTRY32")
            .constructor()
            .destructor()
            .property("dwSize", &PROCESSENTRY32::dwSize)
            .property("cntUsage", &PROCESSENTRY32::cntUsage)
            .property("th32ProcessID", &PROCESSENTRY32::th32ProcessID)
            .property("th32DefaultHeapID", &PROCESSENTRY32::th32DefaultHeapID)
            .property("th32ModuleID", &PROCESSENTRY32::th32ModuleID)
            .property("cntThreads", &PROCESSENTRY32::cntThreads)
            .property("th32ParentProcessID", &PROCESSENTRY32::th32ParentProcessID)
            .property("pcPriClassBase", &PROCESSENTRY32::pcPriClassBase)
            .property("dwFlags", &PROCESSENTRY32::dwFlags)
            .property("szExeFile", &PROCESSENTRY32::szExeFile),
        xlb_class<THREADENTRY32>("THREADENTRY32")
            .constructor()
            .destructor()
            .property("dwSize", &THREADENTRY32::dwSize)
            .property("cntUsage", &THREADENTRY32::cntUsage)
            .property("th32ThreadID", &THREADENTRY32::th32ThreadID)
            .property("th32OwnerProcessID", &THREADENTRY32::th32OwnerProcessID)
            .property("tpBasePri", &THREADENTRY32::tpBasePri)
            .property("tpDeltaPri", &THREADENTRY32::tpDeltaPri)
            .property("dwFlags", &THREADENTRY32::dwFlags),
        xlb_f("Thread32First", Thread32First), xlb_f("Thread32Next", Thread32Next),
        xlb_class<MODULEENTRY32>("MODULEENTRY32")
            .constructor()
            .destructor()
            .property("dwSize", &MODULEENTRY32::dwSize)
            .property("th32ModuleID", &MODULEENTRY32::th32ModuleID)
            .property("th32ProcessID", &MODULEENTRY32::th32ProcessID)
            .property("GlblcntUsage", &MODULEENTRY32::GlblcntUsage)
            .property("ProccntUsage", &MODULEENTRY32::ProccntUsage)
            .property("modBaseAddr", &MODULEENTRY32::modBaseAddr)
            .property("modBaseSize", &MODULEENTRY32::modBaseSize)
            .property("hModule", &MODULEENTRY32::hModule)
            .property("szModule", &MODULEENTRY32::szModule)
            .property("szExePath", &MODULEENTRY32::szExePath),
        xlb_f("Module32First", Module32First), xlb_f("Module32Next", Module32Next)

    // Obsolete Functions
    // NtGetCurrentProcessorNumber
    // NtQueryInformationProcess
    // NtQueryInformationThread
    // WinExec
    // ZwQueryInformationProcess
  });
#endif // defined(BIND_PROC)

  return 0;
} // load_process
