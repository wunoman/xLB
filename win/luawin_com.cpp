#include "luawin.h"

//-------------------------------------------------------------------------------------------------------------------
// Component Object Model (COM)
int load_com( lua_State* L ) {
#if defined( CHECK_BIND_COM )
    xlb_module( L, MODULE_NAME )( {

#if defined( WINVER ) && ( WINVER >= 0x0600 )  // Vista
        xlb_f( "BindMoniker", BindMoniker ), 
        xlb_f( "CLSIDFromProgID", CLSIDFromProgID ),
        xlb_f( "CLSIDFromString", CLSIDFromString ),
        xlb_f( "CoAddRefServerProcess", CoAddRefServerProcess ),
        xlb_f( "CoBuildVersion", CoBuildVersion ), xlb_f( "CoCopyProxy", CoCopyProxy ),
        xlb_f( "CoCreateFreeThreadedMarshaler", CoCreateFreeThreadedMarshaler ),
        xlb_f( "CoCreateGuid", CoCreateGuid ), xlb_f( "CoCreateInstance", CoCreateInstance ),
        xlb_f( "CoCreateInstanceEx", CoCreateInstanceEx ),
        xlb_f( "CoDisconnectObject", CoDisconnectObject ),
        xlb_f( "CoFileTimeNow", CoFileTimeNow ),
        xlb_f( "CoFreeAllLibraries", CoFreeAllLibraries ),
        xlb_f( "CoFreeLibrary", CoFreeLibrary ),
        xlb_f( "CoFreeUnusedLibraries", CoFreeUnusedLibraries ),
        xlb_f( "CoGetCallContext", CoGetCallContext ),
        xlb_f( "CoGetClassObject", CoGetClassObject ),
        xlb_f( "CoGetCurrentProcess", CoGetCurrentProcess ),
        xlb_f( "CoGetInstanceFromFile", CoGetInstanceFromFile ),
        xlb_f( "CoGetInstanceFromIStorage", CoGetInstanceFromIStorage ),
        xlb_f( "CoGetInterfaceAndReleaseStream", CoGetInterfaceAndReleaseStream ),
        xlb_f( "CoGetMalloc", CoGetMalloc ),
        xlb_f( "CoGetMarshalSizeMax", CoGetMarshalSizeMax ),
        xlb_f( "CoGetObject", CoGetObject ), xlb_f( "CoGetPSClsid", CoGetPSClsid ),
        xlb_f( "CoGetStandardMarshal", CoGetStandardMarshal ),
        xlb_f( "CoGetTreatAsClass", CoGetTreatAsClass ),
        xlb_f( "CoImpersonateClient", CoImpersonateClient ),
        xlb_f( "CoInitialize", CoInitialize ), xlb_f( "CoInitializeEx", CoInitializeEx ),
        xlb_f( "CoInitializeSecurity", CoInitializeSecurity ),
        xlb_f( "CoIsHandlerConnected", CoIsHandlerConnected ),
        xlb_f( "CoIsOle1Class", CoIsOle1Class ), xlb_f( "CoLoadLibrary", CoLoadLibrary ),
        xlb_f( "CoLockObjectExternal", CoLockObjectExternal ),
        xlb_f( "CoMarshalHresult", CoMarshalHresult ),
        xlb_f( "CoMarshalInterface", CoMarshalInterface ),
        xlb_f( "CoMarshalInterThreadInterfaceInStream",
               CoMarshalInterThreadInterfaceInStream ),
        xlb_f( "CoQueryAuthenticationServices", CoQueryAuthenticationServices ),
        xlb_f( "CoQueryClientBlanket", CoQueryClientBlanket ),
        xlb_f( "CoQueryProxyBlanket", CoQueryProxyBlanket ),
        xlb_f( "CoRegisterClassObject", CoRegisterClassObject ),
        xlb_f( "CoRegisterMallocSpy", CoRegisterMallocSpy ),
        xlb_f( "CoRegisterMessageFilter", CoRegisterMessageFilter ),
        xlb_f( "CoRegisterPSClsid", CoRegisterPSClsid ),
        xlb_f( "CoRegisterSurrogate", CoRegisterSurrogate ),
        xlb_f( "CoReleaseMarshalData", CoReleaseMarshalData ),
        xlb_f( "CoReleaseServerProcess", CoReleaseServerProcess ),
        xlb_f( "CoResumeClassObjects", CoResumeClassObjects ),
        xlb_f( "CoRevertToSelf", CoRevertToSelf ),
        xlb_f( "CoRevokeClassObject", CoRevokeClassObject ),
        xlb_f( "CoRevokeMallocSpy", CoRevokeMallocSpy ),
        xlb_f( "CoSetProxyBlanket", CoSetProxyBlanket ),
        xlb_f( "CoSuspendClassObjects", CoSuspendClassObjects ),
        xlb_f( "CoSwitchCallContext", CoSwitchCallContext ),
        xlb_f( "CoTaskMemAlloc", CoTaskMemAlloc ), xlb_f( "CoTaskMemFree", CoTaskMemFree ),
        xlb_f( "CoTaskMemRealloc", CoTaskMemRealloc ),
        xlb_f( "CoTreatAsClass", CoTreatAsClass ), xlb_f( "CoUninitialize", CoUninitialize ),
        xlb_f( "CoUnmarshalHresult", CoUnmarshalHresult ),
        xlb_f( "CoUnmarshalInterface", CoUnmarshalInterface ),
        xlb_f( "CreateAntiMoniker", CreateAntiMoniker ),
        xlb_f( "CreateBindCtx", CreateBindCtx ),
        xlb_f( "CreateClassMoniker", CreateClassMoniker ),
        xlb_f( "CreateFileMoniker", CreateFileMoniker ),
        xlb_f( "CreateGenericComposite", CreateGenericComposite ),
        xlb_f( "CreateItemMoniker", CreateItemMoniker ),
        xlb_f( "CreatePointerMoniker", CreatePointerMoniker ),
        // xlb_f("DirectInputCreate", DirectInputCreate), // unsupported

        // xlb_f("DllCanUnloadNow", DllCanUnloadNow), // exported
        // xlb_f("DllGetClassObject", DllGetClassObject), // exported
        // xlb_f("DllRegisterServer", DllRegisterServer), // exported
        // xlb_f("DllUnregisterServer", DllUnregisterServer), // exported

        xlb_f( "GetClassFile", GetClassFile ),
        xlb_f( "GetRunningObjectTable", GetRunningObjectTable ),
        xlb_f( "IIDFromString", IIDFromString ), xlb_f( "IsEqualGUID", IsEqualGUID ),
        // xlb_f("IsValidIid", IsValidIid), // Obsolete
        // xlb_f("IsValidInterface", IsValidInterface), // Obsolete
        // xlb_f("IsValidPtrIn", IsValidPtrIn), // Obsolete
        // xlb_f("IsValidPtrOut", IsValidPtrOut), // Obsolete
        xlb_f( "MkParseDisplayName", MkParseDisplayName ),
        xlb_f( "MonikerCommonPrefixWith", MonikerCommonPrefixWith ),
        xlb_f( "MonikerRelativePathTo", MonikerRelativePathTo ),
        xlb_f( "ProgIDFromCLSID", ProgIDFromCLSID ),
        xlb_f( "StringFromCLSID", StringFromCLSID ),
        xlb_f( "StringFromGUID2", StringFromGUID2 ), xlb_f( "StringFromIID", StringFromIID ),
        ////https://docs.microsoft.com/en-us/previous-versions/windows/embedded/ms885910%28v%3dmsdn.10%29
        // xlb_f("UpdateDCOMSettings", UpdateDCOMSettings),

        xlb_const("CLSCTX_INPROC_SERVER", CLSCTX_INPROC_SERVER),
        xlb_const("CLSCTX_LOCAL_SERVER", CLSCTX_LOCAL_SERVER),
        xlb_const("CLSCTX_REMOTE_SERVER", CLSCTX_REMOTE_SERVER),
        xlb_const("CLSCTX_ALL", CLSCTX_ALL),

        // Interface
        xlb_interface<IUnknown>( "IUnknown" )
            .type_property( "IID", __uuidof( IUnknown ) )
            .method<HRESULT ( IUnknown::* )( REFIID, void** )>( "QueryInterface",
                                                                &IUnknown::QueryInterface )
            .method( "AddRef", &IUnknown::AddRef )
            .method( "Release", &IUnknown::Release )
            ,

        // CLSID_DCOMAccessControl 
        xlb_interface<IAccessControl>( "IAccessControl" )
            .inherited<IUnknown>()
            .type_property( "CLSID", CLSID_DCOMAccessControl )
            .type_property( "IID", __uuidof( IAccessControl ) )
            .method( "GrantAccessRights", &IAccessControl::GrantAccessRights )
            .method( "SetAccessRights", &IAccessControl::SetAccessRights )
            .method( "SetOwner", &IAccessControl::SetOwner )
            .method( "RevokeAccessRights", &IAccessControl::RevokeAccessRights )
            .method( "GetAllAccessRights", &IAccessControl::GetAllAccessRights )
            .method( "IsAccessAllowed", &IAccessControl::IsAccessAllowed )
            ,

        xlb_interface<IBindCtx>( "IBindCtx")
            .inherited<IUnknown>()
            // accessible through a call to CreateBindCtx function
            .type_property( "IID", __uuidof( IBindCtx ) )
            .method( "RegisterObjectBound", &IBindCtx::RegisterObjectBound )
            .method( "RevokeObjectBound", &IBindCtx::RevokeObjectBound )
            .method( "ReleaseBoundObjects", &IBindCtx::ReleaseBoundObjects )
            .method( "SetBindOptions", &IBindCtx::SetBindOptions )
            .method( "GetBindOptions", &IBindCtx::GetBindOptions )
            .method( "GetRunningObjectTable", &IBindCtx::GetRunningObjectTable )
            .method( "RegisterObjectParam", &IBindCtx::RegisterObjectParam )
            .method( "GetObjectParam", &IBindCtx::GetObjectParam )
            .method( "EnumObjectParam", &IBindCtx::EnumObjectParam )
            .method( "RevokeObjectParam", &IBindCtx::RevokeObjectParam )
            ,

        // https://docs.microsoft.com/en-us/windows/win32/com/the-component-categories-manager
        // To facilitate the handling of component categories and to guarantee
        // consistency of the registry, the system provides the Component
        // Categories Manager, a COM object with a CLSID of
        // CLSID_StdComponentCategoriesMgr. This COM object provides the
        // following interfaces: ICatInformation, ICatRegister
        
        xlb_interface<ICatInformation>( "ICatInformation" )
            .inherited<IUnknown>()
            .type_property( "CLSID", CLSID_StdComponentCategoriesMgr )
            .type_property( "IID", __uuidof( ICatInformation ) )
            .method( "EnumCategories", &ICatInformation::EnumCategories )
            .method( "GetCategoryDesc", &ICatInformation::GetCategoryDesc )
            .method( "EnumClassesOfCategories", &ICatInformation::EnumClassesOfCategories )
            .method( "IsClassOfCategories", &ICatInformation::IsClassOfCategories )
            .method( "EnumImplCategoriesOfClass", &ICatInformation::EnumImplCategoriesOfClass )
            .method( "EnumReqCategoriesOfClass", &ICatInformation::EnumReqCategoriesOfClass )
            ,

        xlb_interface<ICatRegister>( "ICatRegister" )
            .inherited<IUnknown>()
            .type_property( "CLSID", CLSID_StdComponentCategoriesMgr )
            .type_property( "IID", __uuidof( ICatRegister ) )
            .method( "RegisterCategories", &ICatRegister::RegisterCategories )
            .method( "UnRegisterCategories", &ICatRegister::UnRegisterCategories )
            .method( "RegisterClassImplCategories", &ICatRegister::RegisterClassImplCategories )
            .method( "UnRegisterClassImplCategories", &ICatRegister::UnRegisterClassImplCategories )
            .method( "RegisterClassReqCategories", &ICatRegister::RegisterClassReqCategories )
            .method( "UnRegisterClassReqCategories", &ICatRegister::UnRegisterClassReqCategories )
            ,

        xlb_interface<IClassActivator>( "IClassActivator" )
            .inherited<IUnknown>()
            .type_property( "IID", __uuidof( IClassActivator ) )
            .method( "GetClassObject", &IClassActivator::GetClassObject )
            ,

        xlb_interface<IClassFactory>( "IClassFactory" )
            .inherited<IUnknown>()
            .type_property( "IID", __uuidof( IClassFactory ) )
            .method( "CreateInstance", &IClassFactory::CreateInstance )
            .method( "LockServer", &IClassFactory::LockServer )
            ,

        xlb_interface<IClassFactory2>( "IClassFactory2" )
            .inherited<IClassFactory>()
            .type_property( "IID", __uuidof( IClassFactory2 ) )
            .method( "GetLicInfo", &IClassFactory2::GetLicInfo )
            .method( "RequestLicKey", &IClassFactory2::RequestLicKey )
            .method( "CreateInstanceLic", &IClassFactory2::CreateInstanceLic )
            ,

        xlb_interface<IClientSecurity>( "IClientSecurity" )
            .inherited<IUnknown>()
            .type_property( "IID", __uuidof( IClientSecurity ) )
            .method( "QueryBlanket", &IClientSecurity::QueryBlanket )
            .method( "SetBlanket", &IClientSecurity::SetBlanket )
            .method( "CopyProxy", &IClientSecurity::CopyProxy )
            ,

        xlb_interface<IConnectionPoint>( "IConnectionPoint" )
            .inherited<IUnknown>()
            .type_property( "IID", __uuidof( IConnectionPoint ) )
            .method( "GetConnectionInterface", &IConnectionPoint::GetConnectionInterface )
            .method( "GetConnectionPointContainer", &IConnectionPoint::GetConnectionPointContainer )
            .method( "Advise", &IConnectionPoint::Advise )
            .method( "Unadvise", &IConnectionPoint::Unadvise )
            .method( "EnumConnections", &IConnectionPoint::EnumConnections )
            ,

        xlb_interface<IConnectionPointContainer>( "IConnectionPointContainer" )
            .inherited<IUnknown>()
            .type_property( "IID", __uuidof( IConnectionPointContainer ) )
            .method( "EnumConnectionPoints", &IConnectionPointContainer::EnumConnectionPoints )
            .method( "FindConnectionPoint", &IConnectionPointContainer::FindConnectionPoint )
            ,

        xlb_interface<IContinueCallback>( "IContinueCallback" )
            .inherited<IUnknown>()
            .type_property( "IID", __uuidof( IContinueCallback ) )
            .method( "FContinue", &IContinueCallback::FContinue )
            .method( "FContinuePrinting", &IContinueCallback::FContinuePrinting )
            ,

        xlb_interface<IDataObject>( "IDataObject" )
            .inherited<IUnknown>()
            .type_property( "IID", __uuidof( IDataObject ) )
            .method( "GetData", &IDataObject::GetData )
            .method( "GetDataHere", &IDataObject::GetDataHere )
            .method( "QueryGetData", &IDataObject::QueryGetData )
            .method( "GetCanonicalFormatEtc", &IDataObject::GetCanonicalFormatEtc )
            .method( "SetData", &IDataObject::SetData )
            .method( "EnumFormatEtc", &IDataObject::EnumFormatEtc )
            .method( "DAdvise", &IDataObject::DAdvise )
            .method( "DUnadvise", &IDataObject::DUnadvise )
            .method( "EnumDAdvise", &IDataObject::EnumDAdvise )
            ,

#ifdef _WIN32_WCE
        xlb_interface<IDccMan>( "IDccMan" )
            .inherited<IUnknown>()
            .type_property( "IID", __uuidof( IDccMan ) )
            .method( "Advise", &IDccMan::Advise )
            .method( "ShowCommSettings", &IDccMan::ShowCommSettings )
            .method( "Unadvise", &IDccMan::Unadvise )
            ,

        xlb_interface<IDccManSink>( "IDccManSink" )
            .inherited<IUnknown>()
            .type_property( "IID", __uuidof( IDccManSink ) )
            .method( "OnLogActive", &IDccManSink::OnLogActive )
            .method( "OnLogAnswered", &IDccManSink::OnLogAnswered )
            .method( "OnLogDisconnection", &IDccManSink::OnLogDisconnection )
            .method( "OnLogError", &IDccManSink::OnLogError )
            .method( "OnLogInactive", &IDccManSink::OnLogInactive )
            .method( "OnLogIpAddr", &IDccManSink::OnLogIpAddr )
            .method( "OnLogListen", &IDccManSink::OnLogListen )
            .method( "OnLogTerminated", &IDccManSink::OnLogTerminated )
            ,
#endif // _WIN32_WCE

        xlb_interface<IEnumConnectionPoints>( "IEnumConnectionPoints" )
            .inherited<IUnknown>()
            .type_property( "IID", __uuidof( IEnumConnectionPoints ) )
            .method( "Clone", &IEnumConnectionPoints::Clone )
            .method( "Next", &IEnumConnectionPoints::Next )
            .method( "Reset", &IEnumConnectionPoints::Reset )
            .method( "Skip", &IEnumConnectionPoints::Skip )
            ,

        xlb_interface<IEnumConnections>( "IEnumConnections" )
            .inherited<IUnknown>()
            .type_property( "IID", __uuidof( IEnumConnections ) )
            .method( "Clone", &IEnumConnections::Clone )
            .method( "Next", &IEnumConnections::Next )
            .method( "Reset", &IEnumConnections::Reset )
            .method( "Skip", &IEnumConnections::Skip )
            ,

        xlb_interface<IEnumFORMATETC>( "IEnumFORMATETC" )
            .inherited<IUnknown>()
            .type_property( "IID", __uuidof( IEnumFORMATETC ) )
            .method( "Clone", &IEnumFORMATETC::Clone )
            .method( "Next", &IEnumFORMATETC::Next )
            .method( "Reset", &IEnumFORMATETC::Reset )
            .method( "Skip", &IEnumFORMATETC::Skip )
            ,

        xlb_interface<IEnumMoniker>( "IEnumMoniker" )
            .inherited<IUnknown>()
            .type_property( "IID", __uuidof( IEnumMoniker ) )
            .method( "Clone", &IEnumMoniker::Clone )
            .method( "Next", &IEnumMoniker::Next )
            .method( "Reset", &IEnumMoniker::Reset )
            .method( "Skip", &IEnumMoniker::Skip )
            ,

        xlb_interface<IEnumSTATDATA>( "IEnumSTATDATA" )
            .inherited<IUnknown>()
            .type_property( "IID", __uuidof( IEnumSTATDATA ) )
            .method( "Clone", &IEnumSTATDATA::Clone )
            .method( "Next", &IEnumSTATDATA::Next )
            .method( "Reset", &IEnumSTATDATA::Reset )
            .method( "Skip", &IEnumSTATDATA::Skip )
            ,

        xlb_interface<IEnumSTATSTG>( "IEnumSTATSTG" )
            .inherited<IUnknown>()
            .type_property( "IID", __uuidof( IEnumSTATSTG ) )
            .method( "Clone", &IEnumSTATSTG::Clone )
            .method( "Next", &IEnumSTATSTG::Next )
            .method( "Reset", &IEnumSTATSTG::Reset )
            .method( "Skip", &IEnumSTATSTG::Skip )
            ,

        xlb_interface<IEnumString>( "IEnumString" )
            .inherited<IUnknown>()
            .type_property( "IID", __uuidof( IEnumString ) )
            .method( "Clone", &IEnumString::Clone )
            .method( "Next", &IEnumString::Next )
            .method( "Reset", &IEnumString::Reset )
            .method( "Skip", &IEnumString::Skip )
            ,

        xlb_interface<IEnumUnknown>( "IEnumUnknown" )
            .inherited<IUnknown>()
            .type_property( "IID", __uuidof( IEnumUnknown ) )
            .method( "Clone", &IEnumUnknown::Clone )
            .method( "Next", &IEnumUnknown::Next )
            .method( "Reset", &IEnumUnknown::Reset )
            .method( "Skip", &IEnumUnknown::Skip )
            ,

        xlb_interface<IErrorLog>( "IErrorlog" )
            .inherited<IUnknown>()
            .type_property( "IID", __uuidof( IErrorLog ) )
            .method( "AddError", &IErrorLog::AddError )
            ,

        xlb_interface<IExternalConnection>( "IExternalConnection" )
            .inherited<IUnknown>()
            .type_property( "IID", __uuidof( IExternalConnection ) )
            .method( "AddConnection", &IExternalConnection::AddConnection )
            .method( "ReleaseConnection", &IExternalConnection::ReleaseConnection )
            ,

        xlb_interface<IFillLockBytes>( "IFillLockBytes" )
            .inherited<IUnknown>()
            .type_property( "IID", __uuidof( IFillLockBytes ) )
            .method( "FillAppend", &IFillLockBytes::FillAppend )
            .method( "FillAt", &IFillLockBytes::FillAt )
            .method( "SetFillSize", &IFillLockBytes::SetFillSize )
            .method( "Terminate", &IFillLockBytes::Terminate )
            ,

        xlb_interface<IGlobalInterfaceTable>( "IGlobalInterfaceTable" )
            .inherited<IUnknown>()
            .type_property( "IID", __uuidof( IGlobalInterfaceTable ) )
            .method( "RegisterInterfaceInGlobal", &IGlobalInterfaceTable::RegisterInterfaceInGlobal )
            .method( "RevokeInterfaceFromGlobal", &IGlobalInterfaceTable::RevokeInterfaceFromGlobal )
            .method( "GetInterfaceFromGlobal", &IGlobalInterfaceTable::GetInterfaceFromGlobal )
            ,

        xlb_interface<IMalloc>( "IMalloc" )
            .inherited<IUnknown>()
            .type_property( "IID", __uuidof( IMalloc ) )
            .method( "Alloc", &IMalloc::Alloc )
            .method( "Realloc", &IMalloc::Realloc )
            .method( "Free", &IMalloc::Free )
            .method( "GetSize", &IMalloc::GetSize )
            .method( "DidAlloc", &IMalloc::DidAlloc )
            .method( "HeapMinimize", &IMalloc::HeapMinimize )
            ,

        xlb_interface<IMallocSpy>( "IMallocSpy" )
            .inherited<IUnknown>()
            .type_property( "IID", __uuidof( IMallocSpy ) )
            .method( "PreAlloc", &IMallocSpy::PreAlloc )
            .method( "PostAlloc", &IMallocSpy::PostAlloc )
            .method( "PreFree", &IMallocSpy::PreFree )
            .method( "PostFree", &IMallocSpy::PostFree )
            .method( "PreRealloc", &IMallocSpy::PreRealloc )
            .method( "PostRealloc", &IMallocSpy::PostRealloc )
            .method( "PreGetSize", &IMallocSpy::PreGetSize )
            .method( "PostGetSize", &IMallocSpy::PostGetSize )
            .method( "PreDidAlloc", &IMallocSpy::PreDidAlloc )
            .method( "PostDidAlloc", &IMallocSpy::PostDidAlloc )
            .method( "PreHeapMinimize", &IMallocSpy::PreHeapMinimize )
            .method( "PostHeapMinimize", &IMallocSpy::PostHeapMinimize )
            ,

        xlb_interface<IMarshal>( "IMarshal" )
            .inherited<IUnknown>()
            .type_property( "IID", __uuidof( IMarshal ) )
            .method( "GetUnmarshalClass", &IMarshal::GetUnmarshalClass )
            .method( "GetMarshalSizeMax", &IMarshal::GetMarshalSizeMax )
            .method( "MarshalInterface", &IMarshal::MarshalInterface )
            .method( "UnmarshalInterface", &IMarshal::UnmarshalInterface )
            .method( "ReleaseMarshalData", &IMarshal::ReleaseMarshalData )
            .method( "DisconnectObject", &IMarshal::DisconnectObject )
            ,


        xlb_interface<IMessageFilter>( "IMessageFilter" )
            .inherited<IUnknown>()
            .type_property( "IID", __uuidof( IMessageFilter ) )
            .method( "HandleInComingCall", &IMessageFilter::HandleInComingCall )
            .method( "RetryRejectedCall", &IMessageFilter::RetryRejectedCall )
            .method( "MessagePending", &IMessageFilter::MessagePending )
            ,

        xlb_interface<IMoniker>( "IMoniker" )
            .inherited<IUnknown>()
            .type_property( "IID", __uuidof( IMoniker ) )
            .method( "BindToObject", &IMoniker::BindToObject )
            .method( "BindToStorage", &IMoniker::BindToStorage )
            .method( "CommonPrefixWith", &IMoniker::CommonPrefixWith )
            .method( "ComposeWith", &IMoniker::ComposeWith )
            .method( "Enum", &IMoniker::Enum )
            .method( "GetDisplayName", &IMoniker::GetDisplayName )
            .method( "GetTimeOfLastChange", &IMoniker::GetTimeOfLastChange )
            .method( "Hash", &IMoniker::Hash )
            .method( "Inverse", &IMoniker::Inverse )
            .method( "IsEqual", &IMoniker::IsEqual )
            .method( "IsRunning", &IMoniker::IsRunning )
            .method( "IsSystemMoniker", &IMoniker::IsSystemMoniker )
            .method( "ParseDisplayName", &IMoniker::ParseDisplayName )
            .method( "Reduce", &IMoniker::Reduce )
            .method( "RelativePathTo", &IMoniker::RelativePathTo )
            ,

        xlb_interface<IMultiQI>( "IMultiQI" )
            .inherited<IUnknown>()
            .type_property( "IID", __uuidof( IMultiQI ) )
            .method( "QueryMultipleInterfaces", &IMultiQI::QueryMultipleInterfaces )
            ,

        xlb_interface<IObjectSafety>( "IObjectSafety" )
            .inherited<IUnknown>()
            .type_property( "IID", __uuidof( IObjectSafety ) )
            .method( "GetInterfaceSafetyOptions", &IObjectSafety::GetInterfaceSafetyOptions )
            .method( "SetInterfaceSafetyOptions", &IObjectSafety::SetInterfaceSafetyOptions )
            ,

        xlb_interface<IParseDisplayName>( "IParseDisplayName" )
            .inherited<IUnknown>()
            .type_property( "IID", __uuidof( IParseDisplayName ) )
            .method( "ParseDisplayName", &IParseDisplayName::ParseDisplayName )
            ,

        xlb_interface<IOleContainer>( "IOleItemContainer" )
            .inherited<IParseDisplayName>()
            .type_property( "IID", __uuidof( IOleContainer ) )
            .method( "EnumObjects", &IOleContainer::EnumObjects )
            .method( "LockContainer", &IOleContainer::LockContainer )
            ,

        xlb_interface<IOleItemContainer>( "IOleItemContainer" )
            .inherited<IOleContainer>()
            .type_property( "IID", __uuidof( IOleItemContainer ) )
            .method( "GetObject", &IOleItemContainer::GetObject )
            .method( "GetObjectStorage", &IOleItemContainer::GetObjectStorage )
            .method( "IsRunning", &IOleItemContainer::IsRunning )
            ,

        xlb_interface<IOleLink>( "IOleLink" )
            .inherited<IUnknown>()
            .type_property( "IID", __uuidof( IOleLink ) )
            .method( "SetUpdateOptions", &IOleLink::SetUpdateOptions )
            .method( "GetUpdateOptions", &IOleLink::GetUpdateOptions )
            .method( "SetSourceMoniker", &IOleLink::SetSourceMoniker )
            .method( "GetSourceMoniker", &IOleLink::GetSourceMoniker )
            .method( "SetSourceDisplayName", &IOleLink::SetSourceDisplayName )
            .method( "GetSourceDisplayName", &IOleLink::GetSourceDisplayName )
            .method( "BindToSource", &IOleLink::BindToSource )
            .method( "BindIfRunning", &IOleLink::BindIfRunning )
            .method( "GetBoundSource", &IOleLink::GetBoundSource )
            .method( "UnbindSource", &IOleLink::UnbindSource )
            .method( "Update", &IOleLink::Update )
            ,

        xlb_interface<IPersist>( "IPersist" )
            .inherited<IUnknown>()
            .type_property( "IID", __uuidof( IPersist ) )
            .method( "GetClassID", &IPersist::GetClassID )
            ,

        xlb_interface<IPersistFile>( "IPersistFile" )
            .inherited<IUnknown>()
            .inherited<IPersist>()
            .type_property( "IID", __uuidof( IPersistFile ) )
            .method( "IsDirty", &IPersistFile::IsDirty )
            .method( "Load", &IPersistFile::Load )
            .method( "Save", &IPersistFile::Save )
            .method( "SaveCompleted", &IPersistFile::SaveCompleted )
            .method( "GetCurFile", &IPersistFile::GetCurFile )
            ,

        xlb_interface<IPersistPropertyBag>( "IPersistPropertyBag" )
            .inherited<IUnknown>()
            .type_property( "IID", __uuidof( IPersistPropertyBag ) )
            .method( "InitNew", &IPersistPropertyBag::InitNew )
            .method( "Load", &IPersistPropertyBag::Load )
            .method( "Save", &IPersistPropertyBag::Save )
            ,

        xlb_interface<IPersistStorage>( "IPersistStorage" )
            .inherited<IPersist>()
            .type_property( "IID", __uuidof( IPersistStorage ) )
            .method( "HandsOffStorage", &IPersistStorage::HandsOffStorage )
            .method( "InitNew", &IPersistStorage::InitNew )
            .method( "IsDirty", &IPersistStorage::IsDirty )
            .method( "Load", &IPersistStorage::Load )
            .method( "Save", &IPersistStorage::Save )
            .method( "SaveCompleted", &IPersistStorage::SaveCompleted )
            ,

        xlb_interface<IPersistStream>( "IPersistStream" )
            .inherited<IPersist>()
            .type_property( "IID", __uuidof( IPersistStream ) )
            .method( "GetSizeMax", &IPersistStream::GetSizeMax )
            .method( "IsDirty", &IPersistStream::IsDirty )
            .method( "Load", &IPersistStream::Load )
            .method( "Save", &IPersistStream::Save )
            ,

        xlb_interface<IPersistStreamInit>( "IPersistStreamInit" )
            .inherited<IPersist>()
            .type_property( "IID", __uuidof( IPersistStreamInit ) )
            .method( "GetSizeMax", &IPersistStreamInit::GetSizeMax )
            .method( "InitNew", &IPersistStreamInit::InitNew )
            .method( "IsDirty", &IPersistStreamInit::IsDirty )
            .method( "Load", &IPersistStreamInit::Load )
            .method( "Save", &IPersistStreamInit::Save )
            ,

        xlb_interface<IProgressNotify>( "IProgressNotify" )
            .inherited<IUnknown>()
            .type_property( "IID", __uuidof( IProgressNotify ) )
            .method( "OnProgress", &IProgressNotify::OnProgress )
            ,

        xlb_interface<IPropertyBag>( "IPropertyBag" )
            .inherited<IUnknown>()
            .type_property( "IID", __uuidof( IPropertyBag ) )
            .method( "Read", &IPropertyBag::Read )
            .method( "Write", &IPropertyBag::Write )
            ,

        xlb_interface<IProvideClassInfo>( "IProvideClassInfo" )
            .inherited<IUnknown>()
            .type_property( "IID", __uuidof( IProvideClassInfo ) )
            .method( "GetClassInfo", &IProvideClassInfo::GetClassInfo )
            ,

        xlb_interface<IProvideClassInfo2>( "IProvideClassInfo2" )
            .inherited<IProvideClassInfo>()
            .type_property( "IID", __uuidof( IProvideClassInfo2 ) )
            .method( "GetGUID", &IProvideClassInfo2::GetClassInfo )
            ,

        xlb_interface<IROTData>( "IROTData" )
            .inherited<IUnknown>()
            .type_property( "IID", __uuidof( IROTData ) )
            .method( "GetComparisonData", &IROTData::GetComparisonData )
            ,

        xlb_interface<IRunnableObject>( "IRunnableObject" )
            .inherited<IUnknown>()
            .type_property( "IID", __uuidof( IRunnableObject ) )
            .method( "GetRunningClass", &IRunnableObject::GetRunningClass )
            .method( "IsRunning", &IRunnableObject::IsRunning )
            .method( "LockRunning", &IRunnableObject::LockRunning )
            .method( "Run", &IRunnableObject::Run )
            .method( "SetContainedObject", &IRunnableObject::SetContainedObject )
            ,

        xlb_interface<IRunningObjectTable>( "IRunningObjectTable" )
            .inherited<IUnknown>()
            .type_property( "IID", __uuidof( IRunningObjectTable ) )
            .method( "EnumRunning", &IRunningObjectTable::EnumRunning )
            .method( "GetObject", &IRunningObjectTable::GetObject )
            .method( "GetTimeOfLastChange", &IRunningObjectTable::GetTimeOfLastChange )
            .method( "IsRunning", &IRunningObjectTable::IsRunning )
            .method( "NoteChangeTime", &IRunningObjectTable::NoteChangeTime )
            .method( "Register", &IRunningObjectTable::Register )
            .method( "Revoke", &IRunningObjectTable::Revoke )
            ,

        xlb_interface<ISequentialStream>( "ISequentialStream" )
            .inherited<IUnknown>()
            .type_property( "IID", __uuidof( ISequentialStream ) )
            .method( "Read", &ISequentialStream::Read )
            .method( "Write", &ISequentialStream::Write )
            ,

        xlb_interface<IServerSecurity>( "IServerSecurity" )
            .inherited<IUnknown>()
            .type_property( "IID", __uuidof( IServerSecurity ) )
            .method( "ImpersonateClient", &IServerSecurity::ImpersonateClient )
            .method( "IsImpersonating", &IServerSecurity::IsImpersonating )
            .method( "QueryBlanket", &IServerSecurity::QueryBlanket )
            .method( "RevertToSelf", &IServerSecurity::RevertToSelf )
            ,

        xlb_interface<IStdMarshalInfo>( "IStdMarshalInfo" )
            .inherited<IUnknown>()
            .type_property( "IID", __uuidof( IStdMarshalInfo ) )
            .method( "GetClassForHandler", &IStdMarshalInfo::GetClassForHandler )
            ,

        xlb_interface<ISurrogate>( "ISurrogate" )
            .inherited<IUnknown>()
            .type_property( "IID", __uuidof( ISurrogate ) )
            .method( "FreeSurrogate", &ISurrogate::FreeSurrogate )
            .method( "LoadDllServer", &ISurrogate::LoadDllServer )
            ,

        xlb_interface<IViewObject>( "IViewObject" )
            .inherited<IUnknown>()
            .type_property( "IID", __uuidof( IViewObject ) )
            .method( "Draw", &IViewObject::Draw )
            .method( "Freeze", &IViewObject::Freeze )
            .method( "GetAdvise", &IViewObject::GetAdvise )
            .method( "GetColorSet", &IViewObject::GetColorSet )
            .method( "SetAdvise", &IViewObject::SetAdvise )
            .method( "Unfreeze", &IViewObject::Unfreeze )
            ,

        xlb_interface<IViewObject2>( "IViewObject2" )
            .inherited<IViewObject>()
            .type_property( "IID", __uuidof( IViewObject2 ) )
            .method( "GetExtent", &IViewObject2::GetExtent )
            ,

        xlb_interface<IViewObjectEx>( "IViewObjectEx" )
            .inherited<IViewObject2>()
            .type_property( "IID", __uuidof( IViewObjectEx ) )
            .method( "GetNaturalExtent", &IViewObjectEx::GetNaturalExtent )
            .method( "GetRect", &IViewObjectEx::GetRect )
            .method( "GetViewStatus", &IViewObjectEx::GetViewStatus )
            .method( "QueryHitPoint", &IViewObjectEx::QueryHitPoint )
            .method( "QueryHitRect", &IViewObjectEx::QueryHitRect )
            ,
        
        
        
        // example
        // https://docs.microsoft.com/en-us/windows/win32/learnwin32/example--the-open-dialog-box
        //

        // structures and enumerations
        
        //BIND_FLAGS;
        xlb_const("BIND_MAYBOTHERUSER", BIND_MAYBOTHERUSER),
        xlb_const("BIND_JUSTTESTEXISTENCE", BIND_JUSTTESTEXISTENCE),

        xlb_class<BIND_OPTS>("BIND_OPTS") .constructor<>() .destructor()
            .property("cbStruct", &BIND_OPTS::cbStruct) 
            .property("grfFlags", &BIND_OPTS::grfFlags) 
            .property("grfMode", &BIND_OPTS::grfMode) 
            .property("dwTickCountDeadline", &BIND_OPTS::dwTickCountDeadline) 
            ,

        xlb_class<BIND_OPTS2>("BIND_OPTS2") .constructor<>() .destructor()
            .property("cbStruct", &BIND_OPTS2::cbStruct)
            .property("grfFlags", &BIND_OPTS2::grfFlags)
            .property("grfMode", &BIND_OPTS2::grfMode)
            .property("dwTickCountDeadline", &BIND_OPTS2::dwTickCountDeadline)
            .property("dwTrackFlags", &BIND_OPTS2::dwTrackFlags)
            .property("dwClassContext", &BIND_OPTS2::dwClassContext)
            .property("locale", &BIND_OPTS2::locale)
            .property("pServerInfo", &BIND_OPTS2::pServerInfo)
            ,

        //CLSCTX 
        xlb_const("CLSCTX_INPROC_SERVER", CLSCTX_INPROC_SERVER),
        xlb_const("CLSCTX_INPROC_HANDLER", CLSCTX_INPROC_HANDLER),
        xlb_const("CLSCTX_LOCAL_SERVER", CLSCTX_LOCAL_SERVER),
        xlb_const("CLSCTX_REMOTE_SERVER", CLSCTX_REMOTE_SERVER),
        xlb_const("CLSCTX_SERVER", CLSCTX_SERVER),
        xlb_const("CLSCTX_ALL", CLSCTX_ALL),

        xlb_class<COAUTHINFO>("COAUTHINFO") .constructor<>() .destructor()
            .property("dwAuthnSvc", &COAUTHINFO::dwAuthnSvc)
            .property("dwAuthzSvc", &COAUTHINFO::dwAuthzSvc)
            .property("pwszServerPrincName", &COAUTHINFO::pwszServerPrincName)
            .property("dwAuthnLevel", &COAUTHINFO::dwAuthnLevel)
            .property("dwImpersonationLevel", &COAUTHINFO::dwImpersonationLevel)
            .property("pAuthIdentityData", &COAUTHINFO::pAuthIdentityData)
            .property("dwCapabilities", &COAUTHINFO::dwCapabilities)
            ,

        xlb_class<CONTROLINFO>("CONTROLINFO") .constructor<>() .destructor()
            .property("cb", &CONTROLINFO::cb)
            .property("hAccel", &CONTROLINFO::hAccel)
            .property("cAccel", &CONTROLINFO::cAccel)
            .property("dwFlags", &CONTROLINFO::dwFlags)
            ,

        xlb_const("CTRLINFO_EATS_RETURN", CTRLINFO_EATS_RETURN),
        xlb_const("CTRLINFO_EATS_ESCAPE", CTRLINFO_EATS_ESCAPE),

        xlb_class<COSERVERINFO>("COSERVERINFO") .constructor<>() .destructor()
            .property("dwReserved1", &COSERVERINFO::dwReserved1)
            .property("pwszName", &COSERVERINFO::pwszName)
            .property("pAuthInfo", &COSERVERINFO::pAuthInfo)
            .property("dwReserved2", &COSERVERINFO::dwReserved2)
            ,

        //DATADIR;
        xlb_const("DATADIR_GET", DATADIR_GET),
        xlb_const("DATADIR_SET", DATADIR_SET),

        //DVASPECT2;
        xlb_const("DVASPECT_OPAQUE", DVASPECT_OPAQUE),
        xlb_const("DVASPECT_TRANSPARENT", DVASPECT_TRANSPARENT),

        //DVEXTENTMODE
        xlb_const("DVEXTENT_CONTENT", DVEXTENT_CONTENT),
        xlb_const("DVEXTENT_INTEGRAL", DVEXTENT_INTEGRAL),

        //HITRESULT
        xlb_const("HITRESULT_OUTSIDE", HITRESULT_OUTSIDE),
        xlb_const("HITRESULT_TRANSPARENT", HITRESULT_TRANSPARENT),
        xlb_const("HITRESULT_CLOSE", HITRESULT_CLOSE),
        xlb_const("HITRESULT_HIT", HITRESULT_HIT),

        //MKRREDUCE
        xlb_const("MKRREDUCE_ONE", MKRREDUCE_ONE),
        xlb_const("MKRREDUCE_TOUSER", MKRREDUCE_TOUSER),
        xlb_const("MKRREDUCE_THROUGHUSER", MKRREDUCE_THROUGHUSER),
        xlb_const("MKRREDUCE_ALL", MKRREDUCE_ALL),

        //MKSYS
        xlb_const("MKSYS_NONE", MKSYS_NONE),
        xlb_const("MKSYS_GENERICCOMPOSITE", MKSYS_GENERICCOMPOSITE),
        xlb_const("MKSYS_FILEMONIKER", MKSYS_FILEMONIKER),
        xlb_const("MKSYS_ANTIMONIKER", MKSYS_ANTIMONIKER),
        xlb_const("MKSYS_ITEMMONIKER", MKSYS_ITEMMONIKER),
        xlb_const("MKSYS_POINTERMONIKER", MKSYS_POINTERMONIKER),
        xlb_const("MKSYS_CLASSMONIKER", MKSYS_CLASSMONIKER),
        xlb_const("MKSYS_OBJREFMONIKER", MKSYS_OBJREFMONIKER),
        xlb_const("MKSYS_SESSIONMONIKER", MKSYS_SESSIONMONIKER),

        //OLEGETMONIKER
        xlb_const("OLEGETMONIKER_ONLYIFTHERE", OLEGETMONIKER_ONLYIFTHERE),
        xlb_const("OLEGETMONIKER_FORCEASSIGN", OLEGETMONIKER_FORCEASSIGN),
        xlb_const("OLEGETMONIKER_UNASSIGN", OLEGETMONIKER_UNASSIGN),
        xlb_const("OLEGETMONIKER_TEMPFORUSER ", OLEGETMONIKER_TEMPFORUSER),

        //OLELINKBIND
        xlb_const("OLELINKBIND_EVENIFCLASSDIFF", OLELINKBIND_EVENIFCLASSDIFF),

        //OLEUPDATE
        xlb_const("OLEUPDATE_ALWAYS", OLEUPDATE_ALWAYS),
        xlb_const("OLEUPDATE_ONCALL", OLEUPDATE_ONCALL),

        //OLEWHICHMK
        xlb_const("OLEWHICHMK_CONTAINER", OLEWHICHMK_CONTAINER),
        xlb_const("OLEWHICHMK_OBJREL", OLEWHICHMK_OBJREL),
        xlb_const("OLEWHICHMK_OBJFULL", OLEWHICHMK_OBJFULL),

        //STGC
        xlb_const("STGC_DEFAULT", STGC_DEFAULT),
        xlb_const("STGC_OVERWRITE", STGC_OVERWRITE),
        xlb_const("STGC_ONLYIFCURRENT", STGC_ONLYIFCURRENT),
        xlb_const("STGC_DANGEROUSLYCOMMITMERELYTODISKCACHE", STGC_DANGEROUSLYCOMMITMERELYTODISKCACHE),

        //VIEWSTATUS
        xlb_const("VIEWSTATUS_OPAQUE", VIEWSTATUS_OPAQUE),
        xlb_const("VIEWSTATUS_SOLIDBKGND", VIEWSTATUS_SOLIDBKGND),
        xlb_const("VIEWSTATUS_DVASPECTOPAQUE", VIEWSTATUS_DVASPECTOPAQUE),
        xlb_const("VIEWSTATUS_DVASPECTTRANSPARENT ", VIEWSTATUS_DVASPECTTRANSPARENT),

#endif  // 0x0600
            xlb_const( "CHECK_BIND_COM", CHECK_BIND_COM )
    } );
#endif  // defined(CHECK_BIND_COM)
    return 0;
}  // load_com

//------------------------------------------------------------------------------------------------
