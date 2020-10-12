#include "luawin.h"

//------------------------------------------------------------------------------------------------
int load_process(lua_State* L)
{
#if defined(CHECK_BIND_PROCESS)
    xlb_module(L, MODULE_NAME) ({
            // Process Functions
#if (defined WINVER) && (WINVER>=0x0A00)
            xlb_f("CreateDispatcherQueueController", CreateDispatcherQueueController),
#endif
            xlb_f("CreateProcess", CreateProcess),
            xlb_f("CreateProcessAsUser", CreateProcessAsUser),
            xlb_f("CreateProcessWithLogonW", CreateProcessWithLogonW),
            xlb_f("CreateProcessWithTokenW", CreateProcessWithTokenW),
            xlb_f("ExitProcess", [](UINT uExitCode) { ExitProcess(uExitCode); }),
            xlb_f("FlushProcessWriteBuffers", FlushProcessWriteBuffers),
            xlb_f("FreeEnvironmentStrings", FreeEnvironmentStrings),
            xlb_f("GetCommandLine", GetCommandLine),
            xlb_f("GetCurrentProcess", GetCurrentProcess),
            xlb_f("GetCurrentProcessId", GetCurrentProcessId),
            xlb_f("GetCurrentProcessorNumber", GetCurrentProcessorNumber),
            xlb_f("GetEnvironmentStrings", GetEnvironmentStrings),
            xlb_f("GetEnvironmentVariable", GetEnvironmentVariable),
            xlb_f("GetExitCodeProcess", GetExitCodeProcess),
            xlb_f("GetGuiResources", GetGuiResources),
            xlb_f("GetLogicalProcessorInformation", GetLogicalProcessorInformation),
            xlb_f("GetPriorityClass", GetPriorityClass),
            xlb_f("GetProcessAffinityMask", GetProcessAffinityMask),
            xlb_f("GetProcessGroupAffinity", GetProcessGroupAffinity),
            xlb_f("GetProcessHandleCount", GetProcessHandleCount),
            xlb_f("GetProcessId", GetProcessId),
            xlb_f("GetProcessIdOfThread", GetProcessIdOfThread),
            xlb_f("GetProcessIoCounters", GetProcessIoCounters),
#if (WINVER>=0x0602)
            xlb_f("GetProcessMitigationPolicy", GetProcessMitigationPolicy),
#endif
            xlb_f("GetProcessPriorityBoost", GetProcessPriorityBoost),
            xlb_f("GetProcessShutdownParameters", GetProcessShutdownParameters),
            xlb_f("GetProcessTimes", GetProcessTimes),
            xlb_f("GetProcessVersion", GetProcessVersion),
            xlb_f("GetProcessWorkingSetSize", GetProcessWorkingSetSize),
            xlb_f("GetProcessWorkingSetSizeEx", GetProcessWorkingSetSizeEx),
            xlb_f("GetProcessorSystemCycleTime", GetProcessorSystemCycleTime),
            xlb_f("GetStartupInfo", GetStartupInfo),
#if (WINVER>=0x0602)
            xlb_f("IsImmersiveProcess", IsImmersiveProcess),
#endif
            xlb_f("NeedCurrentDirectoryForExePath", NeedCurrentDirectoryForExePath),
            xlb_f("OpenProcess", OpenProcess),
            xlb_f("QueryFullProcessImageName", QueryFullProcessImageName),
            xlb_f("QueryProcessAffinityUpdateMode", QueryProcessAffinityUpdateMode),
            xlb_f("QueryProcessCycleTime", QueryProcessCycleTime),
            xlb_f("SetEnvironmentVariable", SetEnvironmentVariable),
            xlb_f("SetPriorityClass", SetPriorityClass),
            xlb_f("SetProcessAffinityMask", SetProcessAffinityMask),
            xlb_f("SetProcessAffinityUpdateMode", SetProcessAffinityUpdateMode),
#if (WINVER>=0x0602)
            xlb_f("SetProcessInformation", SetProcessInformation),
            xlb_f("SetProcessMitigationPolicy", SetProcessMitigationPolicy),
#endif
            xlb_f("SetProcessPriorityBoost", SetProcessPriorityBoost),
#if (WINVER>=0x0602)
            xlb_f("SetProcessRestrictionExemption", SetProcessRestrictionExemption),
#endif
            xlb_f("SetProcessShutdownParameters", SetProcessShutdownParameters),
            xlb_f("SetProcessWorkingSetSize", SetProcessWorkingSetSize),
            xlb_f("SetProcessWorkingSetSizeEx", SetProcessWorkingSetSizeEx),
            xlb_f("TerminateProcess", TerminateProcess),

            // Process Enumeration Functions
            xlb_f("EnumProcesses", EnumProcesses),
            xlb_f("Process32First", Process32First),
            xlb_f("Process32Next", Process32Next),
            xlb_f("WTSEnumerateProcesses", WTSEnumerateProcesses),
            
            // Policy Functions
#if (WINVER>=0x0602)
            xlb_f("QueryProtectedPolicy", QueryProtectedPolicy),
            xlb_f("SetProtectedPolicy", SetProtectedPolicy),
#endif
            
            // Thread Functions
            xlb_f("AttachThreadInput", AttachThreadInput),
            xlb_f("CreateRemoteThread", CreateRemoteThread),
            xlb_f("CreateRemoteThreadEx", CreateRemoteThreadEx),
            xlb_f("CreateThread", CreateThread),
            xlb_f("ExitThread", [](DWORD dwExitCode) { ExitThread(dwExitCode); }),
            xlb_f("GetCurrentThread", GetCurrentThread),
            xlb_f("GetCurrentThreadId", GetCurrentThreadId),
            xlb_f("GetExitCodeThread", GetExitCodeThread),
#if (WINVER>=0x0A00)
            xlb_f("GetThreadDescription", GetThreadDescription),
#endif
            xlb_f("GetThreadGroupAffinity", GetThreadGroupAffinity),
            xlb_f("GetThreadId", GetThreadId),
            xlb_f("GetThreadIdealProcessorEx", GetThreadIdealProcessorEx),
#if (WINVER>=0x0602)
            xlb_f("GetThreadInformation", GetThreadInformation),
#endif
            xlb_f("GetThreadIOPendingFlag", GetThreadIOPendingFlag),
            xlb_f("GetThreadPriority", GetThreadPriority),
            xlb_f("GetThreadPriorityBoost", GetThreadPriorityBoost),
            xlb_f("GetThreadTimes", GetThreadTimes),
            xlb_f("OpenThread", OpenThread),
            xlb_f("QueryIdleProcessorCycleTime", QueryIdleProcessorCycleTime),
            xlb_f("QueryThreadCycleTime", QueryThreadCycleTime),
            xlb_f("ResumeThread", ResumeThread),
            xlb_f("SetThreadAffinityMask", SetThreadAffinityMask),
#if (WINVER>=0x0A00)
            xlb_f("SetThreadDescription", SetThreadDescription),
#endif
            xlb_f("SetThreadGroupAffinity", SetThreadGroupAffinity),
            xlb_f("SetThreadIdealProcessor", SetThreadIdealProcessor),
            xlb_f("SetThreadIdealProcessorEx", SetThreadIdealProcessorEx),
#if (WINVER>=0x0602)
            xlb_f("SetThreadInformation", SetThreadInformation),
#endif
            xlb_f("SetThreadPriority", SetThreadPriority),
            xlb_f("SetThreadPriorityBoost", SetThreadPriorityBoost),
            xlb_f("SetThreadStackGuarantee", SetThreadStackGuarantee),
            xlb_f("Sleep", Sleep),
            xlb_f("SleepEx", SleepEx),
            xlb_f("SuspendThread", SuspendThread),
            xlb_f("SwitchToThread", SwitchToThread),
            xlb_f("TerminateThread", TerminateThread),
            xlb_class<xlb_cbf<LPTHREAD_START_ROUTINE>>("ThreadProc").constructor<xlb_luafunc>(),
            xlb_f("TlsAlloc", TlsAlloc),
            xlb_f("TlsFree", TlsFree),
            xlb_f("TlsGetValue", TlsGetValue),
            xlb_f("TlsSetValue", TlsSetValue),
            xlb_f("WaitForInputIdle", WaitForInputIdle),

            // Process and Thread Extended Attribute Functions
            xlb_f("DeleteProcThreadAttributeList", DeleteProcThreadAttributeList),
            xlb_f("InitializeProcThreadAttributeList", InitializeProcThreadAttributeList),
            xlb_f("UpdateProcThreadAttribute", UpdateProcThreadAttribute),
            // 
            
            // WOW64 Functions
            xlb_f("IsWow64Message", IsWow64Message),
            xlb_f("IsWow64Process", IsWow64Process),
#if (WINVER>=0x0A00)
            xlb_f("IsWow64Process2", IsWow64Process2),
#endif
            xlb_f("Wow64SuspendThread", Wow64SuspendThread),

            // Job Object Functions
            xlb_f("AssignProcessToJobObject", AssignProcessToJobObject),
            xlb_f("CreateJobObject", CreateJobObject),
            xlb_f("IsProcessInJob", IsProcessInJob),
            xlb_f("OpenJobObject", OpenJobObject),
            xlb_f("QueryInformationJobObject", QueryInformationJobObject),
            xlb_f("SetInformationJobObject", SetInformationJobObject),
            xlb_f("TerminateJobObject", TerminateJobObject),
            xlb_f("UserHandleGrantAccess", UserHandleGrantAccess),

            // Thread Pool Functions
            xlb_f("CallbackMayRunLong", CallbackMayRunLong),
            xlb_f("CancelThreadpoolIo", CancelThreadpoolIo),
            xlb_f("CloseThreadpool", CloseThreadpool),
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

#if defined(WINVER) && (WINVER>=0x0602)
            xlb_f("SetThreadpoolTimerEx", SetThreadpoolTimerEx),
#endif
            xlb_f("SetThreadpoolTimer", SetThreadpoolTimer),
            xlb_f("SetThreadpoolWait", SetThreadpoolWait),
#if defined(WINVER) && (WINVER>=0x0602)
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
            xlb_f("ConvertThreadToFiberEx", ConvertThreadToFiberEx),
            xlb_f("CreateFiber", CreateFiber),
            xlb_f("CreateFiberEx", CreateFiberEx),
            xlb_f("DeleteFiber", DeleteFiber),
            xlb_class<xlb_cbf<LPFIBER_START_ROUTINE>>("LPFIBER_START_ROUTINE").constructor<xlb_luafunc>(), // FiberProc
            xlb_f("FlsAlloc", FlsAlloc),
            xlb_f("FlsFree", FlsFree),
            xlb_f("FlsGetValue", FlsGetValue),
            xlb_f("FlsSetValue", FlsSetValue),
            xlb_f("IsThreadAFiber", IsThreadAFiber),
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
            xlb_class<xlb_cbf<PUMS_SCHEDULER_ENTRY_POINT>>("PUMS_SCHEDULER_ENTRY_POINT").constructor<xlb_luafunc>(), // UmsSchedulerProc
            xlb_f("UmsThreadYield", UmsThreadYield),
#endif

            // Obsolete Functions
            // NtGetCurrentProcessorNumber
            // NtQueryInformationProcess
            // NtQueryInformationThread
            // WinExec
            // ZwQueryInformationProcess
 
            
            xlb_const("CHECK_BIND_PROCESS", CHECK_BIND_PROCESS)
    });
#endif // defined(CHECK_BIND_PROCESS)

    return 0;
} // load_process
