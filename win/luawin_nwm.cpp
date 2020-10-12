#include "luawin.h"


LPBYTE ovl_ALERT_VAR_DATA(ADMIN_OTHER_INFO* p) { return ALERT_VAR_DATA(p); };
LPBYTE ovl_ALERT_VAR_DATA(PRINT_OTHER_INFO* p) { return ALERT_VAR_DATA(p); };
LPBYTE ovl_ALERT_VAR_DATA(USER_OTHER_INFO* p) { return ALERT_VAR_DATA(p); };

//------------------------------------------------------------------------------------------------
// Network Management
int load_nwm(lua_State* L)
{
#if defined(CHECK_BIND_NWM)
    xlb_module( L, MODULE_NAME )( {

#if defined(WINVER) && (WINVER>=0x0600) // Vista
        xlb_f(
        "ALERT_OTHER_INFO",
        []( ADMIN_OTHER_INFO* p ) -> auto { return ALERT_VAR_DATA( p ); },
        []( PRINT_OTHER_INFO * p ) -> auto { return ALERT_VAR_DATA( p ); },
        []( USER_OTHER_INFO * p ) -> auto { return ALERT_VAR_DATA( p ); } 
        ),

        xlb_f( "GetNetScheduleAccountInformation", GetNetScheduleAccountInformation ),
        // xlb_f("NetAccessAdd", NetAccessAdd), // unsupported
        // xlb_f("NetAccessDel", NetAccessDel), // unsupported
        // xlb_f("NetAccessEnum", NetAccessEnum), // unsupported
        // xlb_f("NetAccessGetInfo", NetAccessGetInfo), // unsupported
        // xlb_f("NetAccessGetUserPerms", NetAccessGetUserPerms), // unsupported
        // xlb_f("NetAccessSetInfo", NetAccessSetInfo), // unsupported
        xlb_f( "NetAddAlternateComputerName", NetAddAlternateComputerName ),
        xlb_f( "NetAlertRaise", NetAlertRaise ), xlb_f( "NetAlertRaiseEx", NetAlertRaiseEx ),
        xlb_f( "NetApiBufferAllocate", NetApiBufferAllocate ),
        xlb_f( "NetApiBufferFree", NetApiBufferFree ),
        xlb_f( "NetApiBufferReallocate", NetApiBufferReallocate ),
        xlb_f( "NetApiBufferSize", NetApiBufferSize ),
        xlb_f( "NetAuditClear", NetAuditClear ), xlb_f( "NetAuditRead", NetAuditRead ),
        xlb_f( "NetAuditWrite", NetAuditWrite ), xlb_f( "NetConfigGet", NetConfigGet ),
        xlb_f( "NetConfigGetAll", NetConfigGetAll ), xlb_f( "NetConfigSet", NetConfigSet ),

#if defined(WINVER) && (WINVER>=0x0602)
        xlb_f( "NetCreateProvisioningPackage", NetCreateProvisioningPackage ),
#endif
        xlb_f( "NetEnumerateComputerNames", NetEnumerateComputerNames ),
        xlb_f( "NetErrorLogClear", NetErrorLogClear ),
        xlb_f( "NetErrorLogRead", NetErrorLogRead ),
        xlb_f( "NetErrorLogWrite", NetErrorLogWrite ),
#if defined(WINVER) && (WINVER>=0x0A00)
        xlb_f( "NetFreeAadJoinInformation", NetFreeAadJoinInformation ),
        xlb_f( "NetGetAadJoinInformation", NetGetAadJoinInformation ),
#endif
        xlb_f( "NetGetAnyDCName", NetGetAnyDCName ), xlb_f( "NetGetDCName", NetGetDCName ),
        xlb_f( "NetGetDisplayInformationIndex", NetGetDisplayInformationIndex ),
        xlb_f( "NetGetJoinableOUs", NetGetJoinableOUs ),
        xlb_f( "NetGetJoinInformation", NetGetJoinInformation ),
        xlb_f( "NetGroupAdd", NetGroupAdd ), xlb_f( "NetGroupAddUser", NetGroupAddUser ),
        xlb_f( "NetGroupDel", NetGroupDel ), xlb_f( "NetGroupDelUser", NetGroupDelUser ),
        xlb_f( "NetGroupEnum", NetGroupEnum ), xlb_f( "NetGroupGetInfo", NetGroupGetInfo ),
        xlb_f( "NetGroupGetUsers", NetGroupGetUsers ),
        xlb_f( "NetGroupSetInfo", NetGroupSetInfo ),
        xlb_f( "NetGroupSetUsers", NetGroupSetUsers ),
        xlb_f( "NetJoinDomain", NetJoinDomain ),
        xlb_f( "NetLocalGroupAdd", NetLocalGroupAdd ),
        //xlb_f( "NetLocalGroupAddMember", NetLocalGroupAddMember ), // obsolete
        xlb_f( "NetLocalGroupAddMembers", NetLocalGroupAddMembers ),
        xlb_f( "NetLocalGroupDel", NetLocalGroupDel ),
        xlb_f( "NetLocalGroupDelMember", NetLocalGroupDelMember ),
        xlb_f( "NetLocalGroupDelMembers", NetLocalGroupDelMembers ),
        xlb_f( "NetLocalGroupEnum", NetLocalGroupEnum ),
        xlb_f( "NetLocalGroupGetInfo", NetLocalGroupGetInfo ),
        xlb_f( "NetLocalGroupGetMembers", NetLocalGroupGetMembers ),
        xlb_f( "NetLocalGroupSetInfo", NetLocalGroupSetInfo ),
        xlb_f( "NetLocalGroupSetMembers", NetLocalGroupSetMembers ),
        xlb_f( "NetMessageBufferSend", NetMessageBufferSend ),
        xlb_f( "NetMessageNameAdd", NetMessageNameAdd ),
        xlb_f( "NetMessageNameDel", NetMessageNameDel ),
        xlb_f( "NetMessageNameEnum", NetMessageNameEnum ),
        xlb_f( "NetMessageNameGetInfo", NetMessageNameGetInfo ),
        xlb_f( "NetProvisionComputerAccount", NetProvisionComputerAccount ),
        xlb_f( "NetQueryDisplayInformation", NetQueryDisplayInformation ),
        xlb_f( "NetRemoteComputerSupports", NetRemoteComputerSupports ),
        xlb_f( "NetRemoteTOD", NetRemoteTOD ),
        xlb_f( "NetRemoveAlternateComputerName", NetRemoveAlternateComputerName ),
        xlb_f( "NetRenameMachineInDomain", NetRenameMachineInDomain ),
        xlb_f( "NetRequestOfflineDomainJoin", NetRequestOfflineDomainJoin ),
        
#if defined(WINVER) && (WINVER>=0x0602)
    xlb_f( "NetRequestProvisioningPackageInstall", NetRequestProvisioningPackageInstall ),
#endif
    xlb_f( "NetScheduleJobAdd", NetScheduleJobAdd ),
    xlb_f( "NetScheduleJobDel", NetScheduleJobDel ),
    xlb_f( "NetScheduleJobEnum", NetScheduleJobEnum ),
    xlb_f( "NetScheduleJobGetInfo", NetScheduleJobGetInfo ),
    xlb_f( "NetServerComputerNameAdd", NetServerComputerNameAdd ),
    xlb_f( "NetServerComputerNameDel", NetServerComputerNameDel ),
    xlb_f( "NetServerDiskEnum", NetServerDiskEnum ),
    xlb_f( "NetServerEnum", NetServerEnum ),
    xlb_f( "NetServerGetInfo", NetServerGetInfo ),
    xlb_f( "NetServerSetInfo", NetServerSetInfo ),
    xlb_f( "NetServerTransportAdd", NetServerTransportAdd ),
    xlb_f( "NetServerTransportAddEx", NetServerTransportAddEx ),
    xlb_f( "NetServerTransportDel", NetServerTransportDel ),
    xlb_f( "NetServerTransportEnum", NetServerTransportEnum ),
    xlb_f( "NetServiceControl", NetServiceControl ),
    //xlb_f( "NetServiceEnum", NetServiceEnum ), // obsolete
    //xlb_f( "NetServiceGetInfo", NetServiceGetInfo ), // obsolete
    //xlb_f( "NetServiceInstall", NetServiceInstall ), // obsolete
    xlb_f( "NetSetPrimaryComputerName", NetSetPrimaryComputerName ),
    xlb_f( "NetUnjoinDomain", NetUnjoinDomain ), xlb_f( "NetUseAdd", NetUseAdd ),
    xlb_f( "NetUseDel", NetUseDel ), xlb_f( "NetUseEnum", NetUseEnum ),
    xlb_f( "NetUseGetInfo", NetUseGetInfo ), xlb_f( "NetUserAdd", NetUserAdd ),
    xlb_f( "NetUserChangePassword", NetUserChangePassword ),
    xlb_f( "NetUserDel", NetUserDel ), xlb_f( "NetUserEnum", NetUserEnum ),
    xlb_f( "NetUserGetGroups", NetUserGetGroups ),
    xlb_f( "NetUserGetInfo", NetUserGetInfo ),
    xlb_f( "NetUserGetLocalGroups", NetUserGetLocalGroups ),
    xlb_f( "NetUserModalsGet", NetUserModalsGet ),
    xlb_f( "NetUserModalsSet", NetUserModalsSet ),
    xlb_f( "NetUserSetGroups", NetUserSetGroups ),
    xlb_f( "NetUserSetInfo", NetUserSetInfo ),
    xlb_f( "NetValidateName", NetValidateName ),
    xlb_f( "NetValidatePasswordPolicy", NetValidatePasswordPolicy ),
    xlb_f( "NetValidatePasswordPolicyFree", NetValidatePasswordPolicyFree ),
    xlb_f( "NetWkstaGetInfo", NetWkstaGetInfo ),
    xlb_f( "NetWkstaSetInfo", NetWkstaSetInfo ),
    //xlb_f( "NetWkstaTransportAdd", NetWkstaTransportAdd ), // unsupported
    //xlb_f( "NetWkstaTransportDel", NetWkstaTransportDel ), // unsupported
    xlb_f( "NetWkstaTransportEnum", NetWkstaTransportEnum ),
    xlb_f( "NetWkstaUserEnum", NetWkstaUserEnum ),
    xlb_f( "NetWkstaUserGetInfo", NetWkstaUserGetInfo ),
    xlb_f( "NetWkstaUserSetInfo", NetWkstaUserSetInfo ),
    xlb_f( "SetNetScheduleAccountInformation", SetNetScheduleAccountInformation ),

        xlb_class<ADMIN_OTHER_INFO>("ADMIN_OTHER_INFO") .constructor<>() .destructor()
            .property("alrtad_errcode", &ADMIN_OTHER_INFO::alrtad_errcode)
            .property("alrtad_numstrings", &ADMIN_OTHER_INFO::alrtad_numstrings)
            ,
        xlb_class<AT_ENUM>("AT_ENUM") .constructor<>() .destructor()
            .property("JobId", &AT_ENUM::JobId)
            .property("JobTime", &AT_ENUM::JobTime)
            .property("DaysOfMonth", &AT_ENUM::DaysOfMonth)
            .property("DaysOfWeek", &AT_ENUM::DaysOfWeek)
            .property("Flags", &AT_ENUM::Flags)
            .property("Command", &AT_ENUM::Command)
            ,
            xlb_const("JOB_RUN_PERIODICALLY", JOB_RUN_PERIODICALLY),
            xlb_const("JOB_EXEC_ERROR", JOB_EXEC_ERROR),
            xlb_const("JOB_RUNS_TODAY", JOB_RUNS_TODAY),
            xlb_const("JOB_NONINTERACTIVE", JOB_NONINTERACTIVE),

        xlb_class<AT_INFO>("AT_INFO") .constructor<>() .destructor()
            .property("JobTime", &AT_INFO::JobTime)
            .property("DaysOfMonth", &AT_INFO::DaysOfMonth)
            .property("DaysOfWeek", &AT_INFO::DaysOfWeek)
            .property("Flags", &AT_INFO::Flags)
            .property("Command", &AT_INFO::Command)
            ,
            xlb_const("JOB_RUN_PERIODICALLY", JOB_RUN_PERIODICALLY),
            xlb_const("JOB_ADD_CURRENT_DATE", JOB_ADD_CURRENT_DATE),
            xlb_const("JOB_NONINTERACTIVE", JOB_NONINTERACTIVE),
            xlb_const("JOB_RUN_PERIODICALLY", JOB_RUN_PERIODICALLY),
            xlb_const("JOB_EXEC_ERROR", JOB_EXEC_ERROR),
            xlb_const("JOB_RUNS_TODAY", JOB_RUNS_TODAY),
            xlb_const("JOB_NONINTERACTIVE", JOB_NONINTERACTIVE),
        xlb_class<DSREG_JOIN_INFO>("DSREG_JOIN_INFO") .constructor<>() .destructor()
            .property("joinType", &DSREG_JOIN_INFO::joinType)
            .property("pJoinCertificate", &DSREG_JOIN_INFO::pJoinCertificate)
            .property("pszDeviceId", &DSREG_JOIN_INFO::pszDeviceId)
            .property("pszIdpDomain", &DSREG_JOIN_INFO::pszIdpDomain)
            .property("pszTenantId", &DSREG_JOIN_INFO::pszTenantId)
            .property("pszJoinUserEmail", &DSREG_JOIN_INFO::pszJoinUserEmail)
            .property("pszTenantDisplayName", &DSREG_JOIN_INFO::pszTenantDisplayName)
            .property("pszMdmEnrollmentUrl", &DSREG_JOIN_INFO::pszMdmEnrollmentUrl)
            .property("pszMdmTermsOfUseUrl", &DSREG_JOIN_INFO::pszMdmTermsOfUseUrl)
            .property("pszMdmComplianceUrl", &DSREG_JOIN_INFO::pszMdmComplianceUrl)
            .property("pszUserSettingSyncUrl", &DSREG_JOIN_INFO::pszUserSettingSyncUrl)
            .property("pUserInfo", &DSREG_JOIN_INFO::pUserInfo)
            ,
        xlb_class<DSREG_USER_INFO>("DSREG_USER_INFO") .constructor<>() .destructor()
            .property("pszUserEmail", &DSREG_USER_INFO::pszUserEmail)
            .property("pszUserKeyId", &DSREG_USER_INFO::pszUserKeyId)
            .property("pszUserKeyName", &DSREG_USER_INFO::pszUserKeyName)
            ,
        xlb_class<ERRLOG_OTHER_INFO>("ERRLOG_OTHER_INFO") .constructor<>() .destructor()
            .property("alrter_errcode", &ERRLOG_OTHER_INFO::alrter_errcode)
            .property("alrter_offset", &ERRLOG_OTHER_INFO::alrter_offset)
            ,
        xlb_class<GROUP_INFO_0>("GROUP_INFO_0") .constructor<>() .destructor()
            .property("grpi0_name", &GROUP_INFO_0::grpi0_name)
            ,
        xlb_class<GROUP_INFO_1>("GROUP_INFO_1") .constructor<>() .destructor()
            .property("grpi1_name", &GROUP_INFO_1::grpi1_name)
            .property("grpi1_comment", &GROUP_INFO_1::grpi1_comment)
            ,
        xlb_class<GROUP_INFO_1002>("GROUP_INFO_1002") .constructor<>() .destructor()
            .property("grpi1002_comment", &GROUP_INFO_1002::grpi1002_comment)
            ,
        xlb_class<GROUP_INFO_1005>("GROUP_INFO_1005") .constructor<>() .destructor()
            .property("grpi1005_attributes", &GROUP_INFO_1005::grpi1005_attributes)
            ,
        xlb_class<GROUP_INFO_2>("GROUP_INFO_2") .constructor<>() .destructor()
            .property("grpi2_name", &GROUP_INFO_2::grpi2_name)
            .property("grpi2_comment", &GROUP_INFO_2::grpi2_comment)
            .property("grpi2_group_id", &GROUP_INFO_2::grpi2_group_id)
            .property("grpi2_attributes", &GROUP_INFO_2::grpi2_attributes)
            ,
        xlb_class<GROUP_INFO_3>("GROUP_INFO_3") .constructor<>() .destructor()
            .property("grpi3_name", &GROUP_INFO_3::grpi3_name)
            .property("grpi3_comment", &GROUP_INFO_3::grpi3_comment)
            .property("grpi3_group_sid", &GROUP_INFO_3::grpi3_group_sid)
            .property("grpi3_attributes", &GROUP_INFO_3::grpi3_attributes)
            ,
        xlb_class<GROUP_USERS_INFO_0>("GROUP_USERS_INFO_0") .constructor<>() .destructor()
            .property("grui0_name", &GROUP_USERS_INFO_0::grui0_name)
            ,
        xlb_class<GROUP_USERS_INFO_1>("GROUP_USERS_INFO_1") .constructor<>() .destructor()
            .property("grui1_name", &GROUP_USERS_INFO_1::grui1_name)
            .property("grui1_attributes", &GROUP_USERS_INFO_1::grui1_attributes)
            ,
            xlb_const("SE_GROUP_MANDATORY", SE_GROUP_MANDATORY),
            xlb_const("SE_GROUP_ENABLED_BY_DEFAULT", SE_GROUP_ENABLED_BY_DEFAULT),
            xlb_const("SE_GROUP_ENABLED", SE_GROUP_ENABLED),
            xlb_const("SE_GROUP_OWNER", SE_GROUP_OWNER),
            xlb_const("SE_GROUP_USE_FOR_DENY_ONLY", SE_GROUP_USE_FOR_DENY_ONLY),
            xlb_const("SE_GROUP_INTEGRITY", SE_GROUP_INTEGRITY),
            xlb_const("SE_GROUP_INTEGRITY_ENABLED", SE_GROUP_INTEGRITY_ENABLED),
            xlb_const("SE_GROUP_LOGON_ID", SE_GROUP_LOGON_ID),
            xlb_const("SE_GROUP_RESOURCE", SE_GROUP_RESOURCE),
        xlb_class<LOCALGROUP_INFO_0>("LOCALGROUP_INFO_0") .constructor<>() .destructor()
            .property("lgrpi0_name", &LOCALGROUP_INFO_0::lgrpi0_name)
            ,
        xlb_class<LOCALGROUP_INFO_1>("LOCALGROUP_INFO_1") .constructor<>() .destructor()
            .property("lgrpi1_name", &LOCALGROUP_INFO_1::lgrpi1_name)
            .property("lgrpi1_comment", &LOCALGROUP_INFO_1::lgrpi1_comment)
            ,
        xlb_class<LOCALGROUP_INFO_1002>("LOCALGROUP_INFO_1002") .constructor<>() .destructor()
            .property("lgrpi1002_comment", &LOCALGROUP_INFO_1002::lgrpi1002_comment)
            ,
        xlb_class<LOCALGROUP_MEMBERS_INFO_0>("LOCALGROUP_MEMBERS_INFO_0") .constructor<>() .destructor()
            .property("lgrmi0_sid", &LOCALGROUP_MEMBERS_INFO_0::lgrmi0_sid)
            ,
        xlb_class<LOCALGROUP_MEMBERS_INFO_1>("LOCALGROUP_MEMBERS_INFO_1") .constructor<>() .destructor()
            .property("lgrmi1_sid", &LOCALGROUP_MEMBERS_INFO_1::lgrmi1_sid)
            .property("lgrmi1_sidusage", &LOCALGROUP_MEMBERS_INFO_1::lgrmi1_sidusage)
            .property("lgrmi1_name", &LOCALGROUP_MEMBERS_INFO_1::lgrmi1_name)
            ,
        xlb_class<LOCALGROUP_MEMBERS_INFO_2>("LOCALGROUP_MEMBERS_INFO_2") .constructor<>() .destructor()
            .property("lgrmi2_sid", &LOCALGROUP_MEMBERS_INFO_2::lgrmi2_sid)
            .property("lgrmi2_sidusage", &LOCALGROUP_MEMBERS_INFO_2::lgrmi2_sidusage)
            .property("lgrmi2_domainandname", &LOCALGROUP_MEMBERS_INFO_2::lgrmi2_domainandname)
            ,

            xlb_const("SidTypeUser", SidTypeUser),
            xlb_const("SidTypeGroup", SidTypeGroup),
            xlb_const("SidTypeDomain", SidTypeDomain),
            xlb_const("SidTypeAlias", SidTypeAlias),
            xlb_const("SidTypeWellKnownGroup", SidTypeWellKnownGroup),
            xlb_const("SidTypeDeletedAccount", SidTypeDeletedAccount),
            xlb_const("SidTypeInvalid", SidTypeInvalid),
            xlb_const("SidTypeUnknown", SidTypeUnknown),
            xlb_const("SidTypeComputer", SidTypeComputer),
            xlb_const("SidTypeLabel", SidTypeLabel),
            xlb_const("SidTypeLogonSession", SidTypeLogonSession),

        xlb_class<LOCALGROUP_MEMBERS_INFO_3>("LOCALGROUP_MEMBERS_INFO_3") .constructor<>() .destructor()
            .property("lgrmi3_domainandname", &LOCALGROUP_MEMBERS_INFO_3::lgrmi3_domainandname)
            ,
        xlb_class<LOCALGROUP_USERS_INFO_0>("LOCALGROUP_USERS_INFO_0") .constructor<>() .destructor()
            .property("lgrui0_name", &LOCALGROUP_USERS_INFO_0::lgrui0_name)
            ,
        xlb_class<MSG_INFO_0>("MSG_INFO_0") .constructor<>() .destructor()
            .property("msgi0_name", &MSG_INFO_0::msgi0_name)
            ,
        xlb_class<MSG_INFO_1>("MSG_INFO_1") .constructor<>() .destructor()
            .property("msgi1_name", &MSG_INFO_1::msgi1_name)
            .property("msgi1_forward_flag", &MSG_INFO_1::msgi1_forward_flag)
            .property("msgi1_forward", &MSG_INFO_1::msgi1_forward)
            ,
        xlb_class<NET_DISPLAY_GROUP>("NET_DISPLAY_GROUP") .constructor<>() .destructor()
            .property("grpi3_name", &NET_DISPLAY_GROUP::grpi3_name)
            .property("grpi3_comment", &NET_DISPLAY_GROUP::grpi3_comment)
            .property("grpi3_group_id", &NET_DISPLAY_GROUP::grpi3_group_id)
            .property("grpi3_attributes", &NET_DISPLAY_GROUP::grpi3_attributes)
            .property("grpi3_next_index", &NET_DISPLAY_GROUP::grpi3_next_index)
            ,
        xlb_class<NET_DISPLAY_MACHINE>("NET_DISPLAY_MACHINE") .constructor<>() .destructor()
            .property("usri2_name", &NET_DISPLAY_MACHINE::usri2_name)
            .property("usri2_comment", &NET_DISPLAY_MACHINE::usri2_comment)
            .property("usri2_flags", &NET_DISPLAY_MACHINE::usri2_flags)
            .property("usri2_user_id", &NET_DISPLAY_MACHINE::usri2_user_id)
            .property("usri2_next_index", &NET_DISPLAY_MACHINE::usri2_next_index)
            ,
            xlb_const("UF_SCRIPT", UF_SCRIPT),
            xlb_const("UF_ACCOUNTDISABLE", UF_ACCOUNTDISABLE),
            xlb_const("UF_PASSWD_NOTREQD", UF_PASSWD_NOTREQD),
            xlb_const("UF_PASSWD_CANT_CHANGE", UF_PASSWD_CANT_CHANGE),
            xlb_const("UF_LOCKOUT", UF_LOCKOUT),
            xlb_const("UF_DONT_EXPIRE_PASSWD", UF_DONT_EXPIRE_PASSWD),
            xlb_const("UF_TRUSTED_FOR_DELEGATION", UF_TRUSTED_FOR_DELEGATION),
            xlb_const("UF_ENCRYPTED_TEXT_PASSWORD_ALLOWED", UF_ENCRYPTED_TEXT_PASSWORD_ALLOWED),
            xlb_const("UF_NOT_DELEGATED", UF_NOT_DELEGATED),
            xlb_const("UF_SMARTCARD_REQUIRED", UF_SMARTCARD_REQUIRED),
            xlb_const("UF_USE_DES_KEY_ONLY", UF_USE_DES_KEY_ONLY),
            xlb_const("UF_DONT_REQUIRE_PREAUTH", UF_DONT_REQUIRE_PREAUTH),
            xlb_const("UF_PASSWORD_EXPIRED", UF_PASSWORD_EXPIRED),
            xlb_const("UF_TRUSTED_TO_AUTHENTICATE_FOR_DELEGATION", UF_TRUSTED_TO_AUTHENTICATE_FOR_DELEGATION),
            xlb_const("UF_NORMAL_ACCOUNT", UF_NORMAL_ACCOUNT),
            xlb_const("UF_TEMP_DUPLICATE_ACCOUNT", UF_TEMP_DUPLICATE_ACCOUNT),
            xlb_const("UF_WORKSTATION_TRUST_ACCOUNT", UF_WORKSTATION_TRUST_ACCOUNT),
            xlb_const("UF_SERVER_TRUST_ACCOUNT", UF_SERVER_TRUST_ACCOUNT),
            xlb_const("UF_INTERDOMAIN_TRUST_ACCOUNT", UF_INTERDOMAIN_TRUST_ACCOUNT),
        xlb_class<NET_DISPLAY_USER>("NET_DISPLAY_USER") .constructor<>() .destructor()
            .property("usri1_name", &NET_DISPLAY_USER::usri1_name)
            .property("usri1_comment", &NET_DISPLAY_USER::usri1_comment)
            .property("usri1_flags", &NET_DISPLAY_USER::usri1_flags)
            .property("usri1_full_name", &NET_DISPLAY_USER::usri1_full_name)
            .property("usri1_user_id", &NET_DISPLAY_USER::usri1_user_id)
            .property("usri1_next_index", &NET_DISPLAY_USER::usri1_next_index)
            ,
            xlb_const("UF_SCRIPT", UF_SCRIPT),
            xlb_const("UF_ACCOUNTDISABLE", UF_ACCOUNTDISABLE),
            xlb_const("UF_PASSWD_NOTREQD", UF_PASSWD_NOTREQD),
            xlb_const("UF_PASSWD_CANT_CHANGE", UF_PASSWD_CANT_CHANGE),
            xlb_const("UF_LOCKOUT", UF_LOCKOUT),
            xlb_const("UF_DONT_EXPIRE_PASSWD", UF_DONT_EXPIRE_PASSWD),
            xlb_const("UF_TRUSTED_FOR_DELEGATION", UF_TRUSTED_FOR_DELEGATION),
            xlb_const("UF_ENCRYPTED_TEXT_PASSWORD_ALLOWED", UF_ENCRYPTED_TEXT_PASSWORD_ALLOWED),
            xlb_const("UF_NOT_DELEGATED", UF_NOT_DELEGATED),
            xlb_const("UF_SMARTCARD_REQUIRED", UF_SMARTCARD_REQUIRED),
            xlb_const("UF_USE_DES_KEY_ONLY", UF_USE_DES_KEY_ONLY),
            xlb_const("UF_DONT_REQUIRE_PREAUTH", UF_DONT_REQUIRE_PREAUTH),
            xlb_const("UF_PASSWORD_EXPIRED", UF_PASSWORD_EXPIRED),
            xlb_const("UF_TRUSTED_TO_AUTHENTICATE_FOR_DELEGATION", UF_TRUSTED_TO_AUTHENTICATE_FOR_DELEGATION),
            xlb_const("UF_NORMAL_ACCOUNT", UF_NORMAL_ACCOUNT),
            xlb_const("UF_TEMP_DUPLICATE_ACCOUNT", UF_TEMP_DUPLICATE_ACCOUNT),
            xlb_const("UF_WORKSTATION_TRUST_ACCOUNT", UF_WORKSTATION_TRUST_ACCOUNT),
            xlb_const("UF_SERVER_TRUST_ACCOUNT", UF_SERVER_TRUST_ACCOUNT),
            xlb_const("UF_INTERDOMAIN_TRUST_ACCOUNT", UF_INTERDOMAIN_TRUST_ACCOUNT),
        xlb_class<NET_VALIDATE_AUTHENTICATION_INPUT_ARG>("NET_VALIDATE_AUTHENTICATION_INPUT_ARG") .constructor<>() .destructor()
            .property("InputPersistedFields", &NET_VALIDATE_AUTHENTICATION_INPUT_ARG::InputPersistedFields)
            .property("PasswordMatched", &NET_VALIDATE_AUTHENTICATION_INPUT_ARG::PasswordMatched)
            ,
        xlb_class<NET_VALIDATE_OUTPUT_ARG>("NET_VALIDATE_OUTPUT_ARG") .constructor<>() .destructor()
            .property("ChangedPersistedFields", &NET_VALIDATE_OUTPUT_ARG::ChangedPersistedFields)
            .property("ValidationStatus", &NET_VALIDATE_OUTPUT_ARG::ValidationStatus)
            ,
            xlb_const("NERR_AccountLockedOut", NERR_AccountLockedOut),
            xlb_const("NERR_PasswordMustChange", NERR_PasswordMustChange),
            xlb_const("NERR_PasswordExpired", NERR_PasswordExpired),
            xlb_const("NERR_BadPassword", NERR_BadPassword),
            xlb_const("NERR_Success", NERR_Success),
            xlb_const("NERR_AccountLockedOut", NERR_AccountLockedOut),
            xlb_const("NERR_PasswordTooRecent", NERR_PasswordTooRecent),
            xlb_const("NERR_BadPassword", NERR_BadPassword),
            xlb_const("NERR_PasswordHistConflict", NERR_PasswordHistConflict),
            xlb_const("NERR_PasswordTooShort", NERR_PasswordTooShort),
            xlb_const("NERR_PasswordTooLong", NERR_PasswordTooLong),
            xlb_const("NERR_PasswordNotComplexEnough", NERR_PasswordNotComplexEnough),
            xlb_const("NERR_PasswordFilterError", NERR_PasswordFilterError),
            xlb_const("NERR_Success", NERR_Success),
            xlb_const("NERR_PasswordTooShort", NERR_PasswordTooShort),
            xlb_const("NERR_PasswordTooLong", NERR_PasswordTooLong),
            xlb_const("NERR_PasswordNotComplexEnough", NERR_PasswordNotComplexEnough),
            xlb_const("NERR_PasswordFilterError", NERR_PasswordFilterError),
            xlb_const("NERR_Success", NERR_Success),
        xlb_class<NET_VALIDATE_PASSWORD_CHANGE_INPUT_ARG>("NET_VALIDATE_PASSWORD_CHANGE_INPUT_ARG") .constructor<>() .destructor()
            .property("InputPersistedFields", &NET_VALIDATE_PASSWORD_CHANGE_INPUT_ARG::InputPersistedFields)
            .property("ClearPassword", &NET_VALIDATE_PASSWORD_CHANGE_INPUT_ARG::ClearPassword)
            .property("UserAccountName", &NET_VALIDATE_PASSWORD_CHANGE_INPUT_ARG::UserAccountName)
            .property("HashedPassword", &NET_VALIDATE_PASSWORD_CHANGE_INPUT_ARG::HashedPassword)
            .property("PasswordMatch", &NET_VALIDATE_PASSWORD_CHANGE_INPUT_ARG::PasswordMatch)
            ,
        xlb_class<NET_VALIDATE_PASSWORD_HASH>("NET_VALIDATE_PASSWORD_HASH") .constructor<>() .destructor()
            .property("Length", &NET_VALIDATE_PASSWORD_HASH::Length)
            .property("Hash", &NET_VALIDATE_PASSWORD_HASH::Hash)
            ,
        xlb_class<NET_VALIDATE_PASSWORD_RESET_INPUT_ARG>("NET_VALIDATE_PASSWORD_RESET_INPUT_ARG") .constructor<>() .destructor()
            .property("InputPersistedFields", &NET_VALIDATE_PASSWORD_RESET_INPUT_ARG::InputPersistedFields)
            .property("ClearPassword", &NET_VALIDATE_PASSWORD_RESET_INPUT_ARG::ClearPassword)
            .property("UserAccountName", &NET_VALIDATE_PASSWORD_RESET_INPUT_ARG::UserAccountName)
            .property("HashedPassword", &NET_VALIDATE_PASSWORD_RESET_INPUT_ARG::HashedPassword)
            .property("PasswordMustChangeAtNextLogon", &NET_VALIDATE_PASSWORD_RESET_INPUT_ARG::PasswordMustChangeAtNextLogon)
            .property("ClearLockout", &NET_VALIDATE_PASSWORD_RESET_INPUT_ARG::ClearLockout)
            ,
        xlb_class<NET_VALIDATE_PERSISTED_FIELDS>("NET_VALIDATE_PERSISTED_FIELDS") .constructor<>() .destructor()
            .property("PresentFields", &NET_VALIDATE_PERSISTED_FIELDS::PresentFields)
            .property("PasswordLastSet", &NET_VALIDATE_PERSISTED_FIELDS::PasswordLastSet)
            .property("BadPasswordTime", &NET_VALIDATE_PERSISTED_FIELDS::BadPasswordTime)
            .property("LockoutTime", &NET_VALIDATE_PERSISTED_FIELDS::LockoutTime)
            .property("BadPasswordCount", &NET_VALIDATE_PERSISTED_FIELDS::BadPasswordCount)
            .property("PasswordHistoryLength", &NET_VALIDATE_PERSISTED_FIELDS::PasswordHistoryLength)
            .property("PasswordHistory", &NET_VALIDATE_PERSISTED_FIELDS::PasswordHistory)
            ,
            xlb_const("NET_VALIDATE_PASSWORD_LAST_SET", NET_VALIDATE_PASSWORD_LAST_SET),
            xlb_const("NET_VALIDATE_BAD_PASSWORD_TIME", NET_VALIDATE_BAD_PASSWORD_TIME),
            xlb_const("NET_VALIDATE_LOCKOUT_TIME", NET_VALIDATE_LOCKOUT_TIME),
            xlb_const("NET_VALIDATE_BAD_PASSWORD_COUNT", NET_VALIDATE_BAD_PASSWORD_COUNT),
            xlb_const("NET_VALIDATE_PASSWORD_HISTORY_LENGTH", NET_VALIDATE_PASSWORD_HISTORY_LENGTH),
            xlb_const("NET_VALIDATE_PASSWORD_HISTORY", NET_VALIDATE_PASSWORD_HISTORY),
        xlb_class<NETSETUP_PROVISIONING_PARAMS>("NETSETUP_PROVISIONING_PARAMS") .constructor<>() .destructor()
            .property("dwVersion", &NETSETUP_PROVISIONING_PARAMS::dwVersion)
            .property("lpDomain", &NETSETUP_PROVISIONING_PARAMS::lpDomain)
            .property("lpHostName", &NETSETUP_PROVISIONING_PARAMS::lpHostName)
            .property("lpMachineAccountOU", &NETSETUP_PROVISIONING_PARAMS::lpMachineAccountOU)
            .property("lpDcName", &NETSETUP_PROVISIONING_PARAMS::lpDcName)
            .property("dwProvisionOptions", &NETSETUP_PROVISIONING_PARAMS::dwProvisionOptions)
            .property("aCertTemplateNames", &NETSETUP_PROVISIONING_PARAMS::aCertTemplateNames)
            .property("cCertTemplateNames", &NETSETUP_PROVISIONING_PARAMS::cCertTemplateNames)
            .property("aMachinePolicyNames", &NETSETUP_PROVISIONING_PARAMS::aMachinePolicyNames)
            .property("cMachinePolicyNames", &NETSETUP_PROVISIONING_PARAMS::cMachinePolicyNames)
            .property("aMachinePolicyPaths", &NETSETUP_PROVISIONING_PARAMS::aMachinePolicyPaths)
            .property("cMachinePolicyPaths", &NETSETUP_PROVISIONING_PARAMS::cMachinePolicyPaths)
            .property("lpNetbiosName", &NETSETUP_PROVISIONING_PARAMS::lpNetbiosName)
            .property("lpSiteName", &NETSETUP_PROVISIONING_PARAMS::lpSiteName)
            .property("lpPrimaryDNSDomain", &NETSETUP_PROVISIONING_PARAMS::lpPrimaryDNSDomain)
            ,
            xlb_const("NETSETUP_PROVISIONING_PARAMS_CURRENT_VERSION", NETSETUP_PROVISIONING_PARAMS_CURRENT_VERSION),
            xlb_const("NETSETUP_PROVISION_DOWNLEVEL_PRIV_SUPPORT", NETSETUP_PROVISION_DOWNLEVEL_PRIV_SUPPORT),
            xlb_const("NETSETUP_PROVISION_REUSE_ACCOUNT", NETSETUP_PROVISION_REUSE_ACCOUNT),
            xlb_const("NETSETUP_PROVISION_USE_DEFAULT_PASSWORD", NETSETUP_PROVISION_USE_DEFAULT_PASSWORD),
            xlb_const("NETSETUP_PROVISION_SKIP_ACCOUNT_SEARCH", NETSETUP_PROVISION_SKIP_ACCOUNT_SEARCH),
            xlb_const("NETSETUP_PROVISION_ROOT_CA_CERTS", NETSETUP_PROVISION_ROOT_CA_CERTS),
        xlb_class<PRINT_OTHER_INFO>("PRINT_OTHER_INFO") .constructor<>() .destructor()
            .property("alrtpr_jobid", &PRINT_OTHER_INFO::alrtpr_jobid)
            .property("alrtpr_status", &PRINT_OTHER_INFO::alrtpr_status)
            .property("alrtpr_submitted", &PRINT_OTHER_INFO::alrtpr_submitted)
            .property("alrtpr_size", &PRINT_OTHER_INFO::alrtpr_size)
            ,
            xlb_const("PRJOB_QS_QUEUED", PRJOB_QS_QUEUED),
            xlb_const("PRJOB_QS_PAUSED", PRJOB_QS_PAUSED),
            xlb_const("PRJOB_QS_SPOOLING", PRJOB_QS_SPOOLING),
            xlb_const("PRJOB_QS_PRINTING", PRJOB_QS_PRINTING),
            xlb_const("PRJOB_COMPLETE", PRJOB_COMPLETE),
            xlb_const("PRJOB_INTERV", PRJOB_INTERV),
            xlb_const("PRJOB_ERROR", PRJOB_ERROR),
            xlb_const("PRJOB_DESTOFFLINE", PRJOB_DESTOFFLINE),
            xlb_const("PRJOB_DESTPAUSED", PRJOB_DESTPAUSED),
            xlb_const("PRJOB_NOTIFY", PRJOB_NOTIFY),
            xlb_const("PRJOB_DESTNOPAPER", PRJOB_DESTNOPAPER),
            xlb_const("PRJOB_DELETED", PRJOB_DELETED),
        xlb_class<SERVER_INFO_100>("SERVER_INFO_100") .constructor<>() .destructor()
            .property("sv100_platform_id", &SERVER_INFO_100::sv100_platform_id)
            .property("sv100_name", &SERVER_INFO_100::sv100_name)
            ,
            xlb_const("PLATFORM_ID_DOS", PLATFORM_ID_DOS),
            xlb_const("PLATFORM_ID_OS2", PLATFORM_ID_OS2),
            xlb_const("PLATFORM_ID_NT", PLATFORM_ID_NT),
            xlb_const("PLATFORM_ID_OSF", PLATFORM_ID_OSF),
            xlb_const("PLATFORM_ID_VMS", PLATFORM_ID_VMS),
        xlb_class<SERVER_INFO_1005>("SERVER_INFO_1005") .constructor<>() .destructor()
            .property("sv1005_comment", &SERVER_INFO_1005::sv1005_comment)
            ,
        xlb_class<SERVER_INFO_101>("SERVER_INFO_101") .constructor<>() .destructor()
            .property("sv101_platform_id", &SERVER_INFO_101::sv101_platform_id)
            .property("sv101_name", &SERVER_INFO_101::sv101_name)
            .property("sv101_version_major", &SERVER_INFO_101::sv101_version_major)
            .property("sv101_version_minor", &SERVER_INFO_101::sv101_version_minor)
            .property("sv101_type", &SERVER_INFO_101::sv101_type)
            .property("sv101_comment", &SERVER_INFO_101::sv101_comment)
            ,
            xlb_const("PLATFORM_ID_DOS", PLATFORM_ID_DOS),
            xlb_const("PLATFORM_ID_OS2", PLATFORM_ID_OS2),
            xlb_const("PLATFORM_ID_NT", PLATFORM_ID_NT),
            xlb_const("PLATFORM_ID_OSF", PLATFORM_ID_OSF),
            xlb_const("PLATFORM_ID_VMS", PLATFORM_ID_VMS),
            xlb_const("SV_TYPE_WORKSTATION", SV_TYPE_WORKSTATION),
            xlb_const("SV_TYPE_SERVER", SV_TYPE_SERVER),
            xlb_const("SV_TYPE_SQLSERVER", SV_TYPE_SQLSERVER),
            xlb_const("SV_TYPE_DOMAIN_CTRL", SV_TYPE_DOMAIN_CTRL),
            xlb_const("SV_TYPE_DOMAIN_BAKCTRL", SV_TYPE_DOMAIN_BAKCTRL),
            xlb_const("SV_TYPE_TIME_SOURCE", SV_TYPE_TIME_SOURCE),
            xlb_const("SV_TYPE_AFP", SV_TYPE_AFP),
            xlb_const("SV_TYPE_NOVELL", SV_TYPE_NOVELL),
            xlb_const("SV_TYPE_DOMAIN_MEMBER", SV_TYPE_DOMAIN_MEMBER),
            xlb_const("SV_TYPE_PRINTQ_SERVER", SV_TYPE_PRINTQ_SERVER),
            xlb_const("SV_TYPE_DIALIN_SERVER", SV_TYPE_DIALIN_SERVER),
            xlb_const("SV_TYPE_XENIX_SERVER", SV_TYPE_XENIX_SERVER),
            xlb_const("SV_TYPE_NT", SV_TYPE_NT),
            xlb_const("SV_TYPE_WFW", SV_TYPE_WFW),
            xlb_const("SV_TYPE_SERVER_MFPN", SV_TYPE_SERVER_MFPN),
            xlb_const("SV_TYPE_SERVER_NT", SV_TYPE_SERVER_NT),
            xlb_const("SV_TYPE_POTENTIAL_BROWSER", SV_TYPE_POTENTIAL_BROWSER),
            xlb_const("SV_TYPE_BACKUP_BROWSER", SV_TYPE_BACKUP_BROWSER),
            xlb_const("SV_TYPE_MASTER_BROWSER", SV_TYPE_MASTER_BROWSER),
            xlb_const("SV_TYPE_DOMAIN_MASTER", SV_TYPE_DOMAIN_MASTER),
            xlb_const("SV_TYPE_SERVER_OSF", SV_TYPE_SERVER_OSF),
            xlb_const("SV_TYPE_SERVER_VMS", SV_TYPE_SERVER_VMS),
            xlb_const("SV_TYPE_WINDOWS", SV_TYPE_WINDOWS),
            xlb_const("SV_TYPE_DFS", SV_TYPE_DFS),
            xlb_const("SV_TYPE_CLUSTER_NT", SV_TYPE_CLUSTER_NT),
            xlb_const("SV_TYPE_TERMINALSERVER", SV_TYPE_TERMINALSERVER),
            xlb_const("SV_TYPE_CLUSTER_VS_NT", SV_TYPE_CLUSTER_VS_NT),
            xlb_const("SV_TYPE_DCE", SV_TYPE_DCE),
            xlb_const("SV_TYPE_ALTERNATE_XPORT", SV_TYPE_ALTERNATE_XPORT),
            xlb_const("SV_TYPE_LOCAL_LIST_ONLY", SV_TYPE_LOCAL_LIST_ONLY),
            xlb_const("SV_TYPE_DOMAIN_ENUM", SV_TYPE_DOMAIN_ENUM),
        xlb_class<SERVER_INFO_1010>("SERVER_INFO_1010") .constructor<>() .destructor()
            .property("sv1010_disc", &SERVER_INFO_1010::sv1010_disc)
            ,
        xlb_class<SERVER_INFO_1016>("SERVER_INFO_1016") .constructor<>() .destructor()
            .property("sv1016_hidden", &SERVER_INFO_1016::sv1016_hidden)
            ,
            xlb_const("SV_VISIBLE", SV_VISIBLE),
            xlb_const("SV_HIDDEN", SV_HIDDEN),
        xlb_class<SERVER_INFO_1017>("SERVER_INFO_1017") .constructor<>() .destructor()
            .property("sv1017_announce", &SERVER_INFO_1017::sv1017_announce)
            ,
        xlb_class<SERVER_INFO_1018>("SERVER_INFO_1018") .constructor<>() .destructor()
            .property("sv1018_anndelta", &SERVER_INFO_1018::sv1018_anndelta)
            ,
        xlb_class<SERVER_INFO_102>("SERVER_INFO_102") .constructor<>() .destructor()
            .property("sv102_platform_id", &SERVER_INFO_102::sv102_platform_id)
            .property("sv102_name", &SERVER_INFO_102::sv102_name)
            .property("sv102_version_major", &SERVER_INFO_102::sv102_version_major)
            .property("sv102_version_minor", &SERVER_INFO_102::sv102_version_minor)
            .property("sv102_type", &SERVER_INFO_102::sv102_type)
            .property("sv102_comment", &SERVER_INFO_102::sv102_comment)
            .property("sv102_users", &SERVER_INFO_102::sv102_users)
            .property("sv102_disc", &SERVER_INFO_102::sv102_disc)
            .property("sv102_hidden", &SERVER_INFO_102::sv102_hidden)
            .property("sv102_announce", &SERVER_INFO_102::sv102_announce)
            .property("sv102_anndelta", &SERVER_INFO_102::sv102_anndelta)
            .property("sv102_licenses", &SERVER_INFO_102::sv102_licenses)
            .property("sv102_userpath", &SERVER_INFO_102::sv102_userpath)
            ,
            xlb_const("PLATFORM_ID_DOS", PLATFORM_ID_DOS),
            xlb_const("PLATFORM_ID_OS2", PLATFORM_ID_OS2),
            xlb_const("PLATFORM_ID_NT", PLATFORM_ID_NT),
            xlb_const("PLATFORM_ID_OSF", PLATFORM_ID_OSF),
            xlb_const("PLATFORM_ID_VMS", PLATFORM_ID_VMS),
            xlb_const("SV_TYPE_WORKSTATION", SV_TYPE_WORKSTATION),
            xlb_const("SV_TYPE_SERVER", SV_TYPE_SERVER),
            xlb_const("SV_TYPE_SQLSERVER", SV_TYPE_SQLSERVER),
            xlb_const("SV_TYPE_DOMAIN_CTRL", SV_TYPE_DOMAIN_CTRL),
            xlb_const("SV_TYPE_DOMAIN_BAKCTRL", SV_TYPE_DOMAIN_BAKCTRL),
            xlb_const("SV_TYPE_TIME_SOURCE", SV_TYPE_TIME_SOURCE),
            xlb_const("SV_TYPE_AFP", SV_TYPE_AFP),
            xlb_const("SV_TYPE_NOVELL", SV_TYPE_NOVELL),
            xlb_const("SV_TYPE_DOMAIN_MEMBER", SV_TYPE_DOMAIN_MEMBER),
            xlb_const("SV_TYPE_PRINTQ_SERVER", SV_TYPE_PRINTQ_SERVER),
            xlb_const("SV_TYPE_DIALIN_SERVER", SV_TYPE_DIALIN_SERVER),
            xlb_const("SV_TYPE_XENIX_SERVER", SV_TYPE_XENIX_SERVER),
            xlb_const("SV_TYPE_NT", SV_TYPE_NT),
            xlb_const("SV_TYPE_WFW", SV_TYPE_WFW),
            xlb_const("SV_TYPE_SERVER_MFPN", SV_TYPE_SERVER_MFPN),
            xlb_const("SV_TYPE_SERVER_NT", SV_TYPE_SERVER_NT),
            xlb_const("SV_TYPE_POTENTIAL_BROWSER", SV_TYPE_POTENTIAL_BROWSER),
            xlb_const("SV_TYPE_BACKUP_BROWSER", SV_TYPE_BACKUP_BROWSER),
            xlb_const("SV_TYPE_MASTER_BROWSER", SV_TYPE_MASTER_BROWSER),
            xlb_const("SV_TYPE_DOMAIN_MASTER", SV_TYPE_DOMAIN_MASTER),
            xlb_const("SV_TYPE_SERVER_OSF", SV_TYPE_SERVER_OSF),
            xlb_const("SV_TYPE_SERVER_VMS", SV_TYPE_SERVER_VMS),
            xlb_const("SV_TYPE_WINDOWS", SV_TYPE_WINDOWS),
            xlb_const("SV_TYPE_DFS", SV_TYPE_DFS),
            xlb_const("SV_TYPE_CLUSTER_NT", SV_TYPE_CLUSTER_NT),
            xlb_const("SV_TYPE_TERMINALSERVER", SV_TYPE_TERMINALSERVER),
            xlb_const("SV_TYPE_CLUSTER_VS_NT", SV_TYPE_CLUSTER_VS_NT),
            xlb_const("SV_TYPE_DCE", SV_TYPE_DCE),
            xlb_const("SV_TYPE_ALTERNATE_XPORT", SV_TYPE_ALTERNATE_XPORT),
            xlb_const("SV_TYPE_LOCAL_LIST_ONLY", SV_TYPE_LOCAL_LIST_ONLY),
            xlb_const("SV_TYPE_DOMAIN_ENUM", SV_TYPE_DOMAIN_ENUM),
        xlb_class<SERVER_INFO_1107>("SERVER_INFO_1107") .constructor<>() .destructor()
            .property("sv1107_users", &SERVER_INFO_1107::sv1107_users)
            ,
        xlb_class<SERVER_INFO_1501>("SERVER_INFO_1501") .constructor<>() .destructor()
            .property("sv1501_sessopens", &SERVER_INFO_1501::sv1501_sessopens)
            ,
        xlb_class<SERVER_INFO_1502>("SERVER_INFO_1502") .constructor<>() .destructor()
            .property("sv1502_sessvcs", &SERVER_INFO_1502::sv1502_sessvcs)
            ,
        xlb_class<SERVER_INFO_1503>("SERVER_INFO_1503") .constructor<>() .destructor()
            .property("sv1503_opensearch", &SERVER_INFO_1503::sv1503_opensearch)
            ,
        xlb_class<SERVER_INFO_1506>("SERVER_INFO_1506") .constructor<>() .destructor()
            .property("sv1506_maxworkitems", &SERVER_INFO_1506::sv1506_maxworkitems)
            ,
        xlb_class<SERVER_INFO_1509>("SERVER_INFO_1509") .constructor<>() .destructor()
            .property("sv1509_maxrawbuflen", &SERVER_INFO_1509::sv1509_maxrawbuflen)
            ,
        xlb_class<SERVER_INFO_1510>("SERVER_INFO_1510") .constructor<>() .destructor()
            .property("sv1510_sessusers", &SERVER_INFO_1510::sv1510_sessusers)
            ,
        xlb_class<SERVER_INFO_1511>("SERVER_INFO_1511") .constructor<>() .destructor()
            .property("sv1511_sessconns", &SERVER_INFO_1511::sv1511_sessconns)
            ,
        xlb_class<SERVER_INFO_1512>("SERVER_INFO_1512") .constructor<>() .destructor()
            .property("sv1512_maxnonpagedmemoryusage", &SERVER_INFO_1512::sv1512_maxnonpagedmemoryusage)
            ,
        xlb_class<SERVER_INFO_1513>("SERVER_INFO_1513") .constructor<>() .destructor()
            .property("sv1513_maxpagedmemoryusage", &SERVER_INFO_1513::sv1513_maxpagedmemoryusage)
            ,
        xlb_class<SERVER_INFO_1515>("SERVER_INFO_1515") .constructor<>() .destructor()
            .property("sv1515_enableforcedlogoff", &SERVER_INFO_1515::sv1515_enableforcedlogoff)
            ,
        xlb_class<SERVER_INFO_1516>("SERVER_INFO_1516") .constructor<>() .destructor()
            .property("sv1516_timesource", &SERVER_INFO_1516::sv1516_timesource)
            ,
        xlb_class<SERVER_INFO_1518>("SERVER_INFO_1518") .constructor<>() .destructor()
            .property("sv1518_lmannounce", &SERVER_INFO_1518::sv1518_lmannounce)
            ,
        xlb_class<SERVER_INFO_1523>("SERVER_INFO_1523") .constructor<>() .destructor()
            .property("sv1523_maxkeepsearch", &SERVER_INFO_1523::sv1523_maxkeepsearch)
            ,
        xlb_class<SERVER_INFO_1528>("SERVER_INFO_1528") .constructor<>() .destructor()
            .property("sv1528_scavtimeout", &SERVER_INFO_1528::sv1528_scavtimeout)
            ,
        xlb_class<SERVER_INFO_1529>("SERVER_INFO_1529") .constructor<>() .destructor()
            .property("sv1529_minrcvqueue", &SERVER_INFO_1529::sv1529_minrcvqueue)
            ,
        xlb_class<SERVER_INFO_1530>("SERVER_INFO_1530") .constructor<>() .destructor()
            .property("sv1530_minfreeworkitems", &SERVER_INFO_1530::sv1530_minfreeworkitems)
            ,
        xlb_class<SERVER_INFO_1533>("SERVER_INFO_1533") .constructor<>() .destructor()
            .property("sv1533_maxmpxct", &SERVER_INFO_1533::sv1533_maxmpxct)
            ,
        xlb_class<SERVER_INFO_1536>("SERVER_INFO_1536") .constructor<>() .destructor()
            .property("sv1536_enableoplocks", &SERVER_INFO_1536::sv1536_enableoplocks)
            ,
        xlb_class<SERVER_INFO_1538>("SERVER_INFO_1538") .constructor<>() .destructor()
            .property("sv1538_enablefcbopens", &SERVER_INFO_1538::sv1538_enablefcbopens)
            ,
        xlb_class<SERVER_INFO_1539>("SERVER_INFO_1539") .constructor<>() .destructor()
            .property("sv1539_enableraw", &SERVER_INFO_1539::sv1539_enableraw)
            ,
        xlb_class<SERVER_INFO_1540>("SERVER_INFO_1540") .constructor<>() .destructor()
            .property("sv1540_enablesharednetdrives", &SERVER_INFO_1540::sv1540_enablesharednetdrives)
            ,
        xlb_class<SERVER_INFO_1541>("SERVER_INFO_1541") .constructor<>() .destructor()
            .property("sv1541_minfreeconnections", &SERVER_INFO_1541::sv1541_minfreeconnections)
            ,
        xlb_class<SERVER_INFO_1542>("SERVER_INFO_1542") .constructor<>() .destructor()
            .property("sv1542_maxfreeconnections", &SERVER_INFO_1542::sv1542_maxfreeconnections)
            ,
        xlb_class<SERVER_INFO_1544>("SERVER_INFO_1544") .constructor<>() .destructor()
            .property("sv1544_initconntable", &SERVER_INFO_1544::sv1544_initconntable)
            ,
        xlb_class<SERVER_INFO_1550>("SERVER_INFO_1550") .constructor<>() .destructor()
            .property("sv1550_diskspacethreshold", &SERVER_INFO_1550::sv1550_diskspacethreshold)
            ,
        xlb_class<SERVER_INFO_1552>("SERVER_INFO_1552") .constructor<>() .destructor()
            .property("sv1552_maxlinkdelay", &SERVER_INFO_1552::sv1552_maxlinkdelay)
            ,
        xlb_class<SERVER_INFO_402>("SERVER_INFO_402") .constructor<>() .destructor()
            .property("sv402_ulist_mtime", &SERVER_INFO_402::sv402_ulist_mtime)
            .property("sv402_glist_mtime", &SERVER_INFO_402::sv402_glist_mtime)
            .property("sv402_alist_mtime", &SERVER_INFO_402::sv402_alist_mtime)
            .property("sv402_alerts", &SERVER_INFO_402::sv402_alerts)
            .property("sv402_security", &SERVER_INFO_402::sv402_security)
            .property("sv402_numadmin", &SERVER_INFO_402::sv402_numadmin)
            .property("sv402_lanmask", &SERVER_INFO_402::sv402_lanmask)
            .property("sv402_guestacct", &SERVER_INFO_402::sv402_guestacct)
            .property("sv402_chdevs", &SERVER_INFO_402::sv402_chdevs)
            .property("sv402_chdevq", &SERVER_INFO_402::sv402_chdevq)
            .property("sv402_chdevjobs", &SERVER_INFO_402::sv402_chdevjobs)
            .property("sv402_connections", &SERVER_INFO_402::sv402_connections)
            .property("sv402_shares", &SERVER_INFO_402::sv402_shares)
            .property("sv402_openfiles", &SERVER_INFO_402::sv402_openfiles)
            .property("sv402_sessopens", &SERVER_INFO_402::sv402_sessopens)
            .property("sv402_sessvcs", &SERVER_INFO_402::sv402_sessvcs)
            .property("sv402_sessreqs", &SERVER_INFO_402::sv402_sessreqs)
            .property("sv402_opensearch", &SERVER_INFO_402::sv402_opensearch)
            .property("sv402_activelocks", &SERVER_INFO_402::sv402_activelocks)
            .property("sv402_numreqbuf", &SERVER_INFO_402::sv402_numreqbuf)
            .property("sv402_sizreqbuf", &SERVER_INFO_402::sv402_sizreqbuf)
            .property("sv402_numbigbuf", &SERVER_INFO_402::sv402_numbigbuf)
            .property("sv402_numfiletasks", &SERVER_INFO_402::sv402_numfiletasks)
            .property("sv402_alertsched", &SERVER_INFO_402::sv402_alertsched)
            .property("sv402_erroralert", &SERVER_INFO_402::sv402_erroralert)
            .property("sv402_logonalert", &SERVER_INFO_402::sv402_logonalert)
            .property("sv402_accessalert", &SERVER_INFO_402::sv402_accessalert)
            .property("sv402_diskalert", &SERVER_INFO_402::sv402_diskalert)
            .property("sv402_netioalert", &SERVER_INFO_402::sv402_netioalert)
            .property("sv402_maxauditsz", &SERVER_INFO_402::sv402_maxauditsz)
            .property("sv402_srvheuristics", &SERVER_INFO_402::sv402_srvheuristics)
            ,
        xlb_class<SERVER_INFO_403>("SERVER_INFO_403") .constructor<>() .destructor()
            .property("sv403_ulist_mtime", &SERVER_INFO_403::sv403_ulist_mtime)
            .property("sv403_glist_mtime", &SERVER_INFO_403::sv403_glist_mtime)
            .property("sv403_alist_mtime", &SERVER_INFO_403::sv403_alist_mtime)
            .property("sv403_alerts", &SERVER_INFO_403::sv403_alerts)
            .property("sv403_security", &SERVER_INFO_403::sv403_security)
            .property("sv403_numadmin", &SERVER_INFO_403::sv403_numadmin)
            .property("sv403_lanmask", &SERVER_INFO_403::sv403_lanmask)
            .property("sv403_guestacct", &SERVER_INFO_403::sv403_guestacct)
            .property("sv403_chdevs", &SERVER_INFO_403::sv403_chdevs)
            .property("sv403_chdevq", &SERVER_INFO_403::sv403_chdevq)
            .property("sv403_chdevjobs", &SERVER_INFO_403::sv403_chdevjobs)
            .property("sv403_connections", &SERVER_INFO_403::sv403_connections)
            .property("sv403_shares", &SERVER_INFO_403::sv403_shares)
            .property("sv403_openfiles", &SERVER_INFO_403::sv403_openfiles)
            .property("sv403_sessopens", &SERVER_INFO_403::sv403_sessopens)
            .property("sv403_sessvcs", &SERVER_INFO_403::sv403_sessvcs)
            .property("sv403_sessreqs", &SERVER_INFO_403::sv403_sessreqs)
            .property("sv403_opensearch", &SERVER_INFO_403::sv403_opensearch)
            .property("sv403_activelocks", &SERVER_INFO_403::sv403_activelocks)
            .property("sv403_numreqbuf", &SERVER_INFO_403::sv403_numreqbuf)
            .property("sv403_sizreqbuf", &SERVER_INFO_403::sv403_sizreqbuf)
            .property("sv403_numbigbuf", &SERVER_INFO_403::sv403_numbigbuf)
            .property("sv403_numfiletasks", &SERVER_INFO_403::sv403_numfiletasks)
            .property("sv403_alertsched", &SERVER_INFO_403::sv403_alertsched)
            .property("sv403_erroralert", &SERVER_INFO_403::sv403_erroralert)
            .property("sv403_logonalert", &SERVER_INFO_403::sv403_logonalert)
            .property("sv403_accessalert", &SERVER_INFO_403::sv403_accessalert)
            .property("sv403_diskalert", &SERVER_INFO_403::sv403_diskalert)
            .property("sv403_netioalert", &SERVER_INFO_403::sv403_netioalert)
            .property("sv403_maxauditsz", &SERVER_INFO_403::sv403_maxauditsz)
            .property("sv403_srvheuristics", &SERVER_INFO_403::sv403_srvheuristics)
            .property("sv403_auditedevents", &SERVER_INFO_403::sv403_auditedevents)
            .property("sv403_autoprofile", &SERVER_INFO_403::sv403_autoprofile)
            .property("sv403_autopath", &SERVER_INFO_403::sv403_autopath)
            ,
            xlb_const("SV_SHARESECURITY", SV_SHARESECURITY),
            xlb_const("SV_USERSECURITY", SV_USERSECURITY),
            xlb_const("SW_AUTOPROF_LOAD_MASK", SW_AUTOPROF_LOAD_MASK),
            xlb_const("SW_AUTOPROF_SAVE_MASK", SW_AUTOPROF_SAVE_MASK),
        xlb_class<SERVER_INFO_502>("SERVER_INFO_502") .constructor<>() .destructor()
            .property("sv502_sessopens", &SERVER_INFO_502::sv502_sessopens)
            .property("sv502_sessvcs", &SERVER_INFO_502::sv502_sessvcs)
            .property("sv502_opensearch", &SERVER_INFO_502::sv502_opensearch)
            .property("sv502_sizreqbuf", &SERVER_INFO_502::sv502_sizreqbuf)
            .property("sv502_initworkitems", &SERVER_INFO_502::sv502_initworkitems)
            .property("sv502_maxworkitems", &SERVER_INFO_502::sv502_maxworkitems)
            .property("sv502_rawworkitems", &SERVER_INFO_502::sv502_rawworkitems)
            .property("sv502_irpstacksize", &SERVER_INFO_502::sv502_irpstacksize)
            .property("sv502_maxrawbuflen", &SERVER_INFO_502::sv502_maxrawbuflen)
            .property("sv502_sessusers", &SERVER_INFO_502::sv502_sessusers)
            .property("sv502_sessconns", &SERVER_INFO_502::sv502_sessconns)
            .property("sv502_maxpagedmemoryusage", &SERVER_INFO_502::sv502_maxpagedmemoryusage)
            .property("sv502_maxnonpagedmemoryusage", &SERVER_INFO_502::sv502_maxnonpagedmemoryusage)
            .property("sv502_enablesoftcompat", &SERVER_INFO_502::sv502_enablesoftcompat)
            .property("sv502_enableforcedlogoff", &SERVER_INFO_502::sv502_enableforcedlogoff)
            .property("sv502_timesource", &SERVER_INFO_502::sv502_timesource)
            .property("sv502_acceptdownlevelapis", &SERVER_INFO_502::sv502_acceptdownlevelapis)
            .property("sv502_lmannounce", &SERVER_INFO_502::sv502_lmannounce)
            ,
        xlb_class<SERVER_INFO_503>("SERVER_INFO_503") .constructor<>() .destructor()
            .property("sv503_sessopens", &SERVER_INFO_503::sv503_sessopens)
            .property("sv503_sessvcs", &SERVER_INFO_503::sv503_sessvcs)
            .property("sv503_opensearch", &SERVER_INFO_503::sv503_opensearch)
            .property("sv503_sizreqbuf", &SERVER_INFO_503::sv503_sizreqbuf)
            .property("sv503_initworkitems", &SERVER_INFO_503::sv503_initworkitems)
            .property("sv503_maxworkitems", &SERVER_INFO_503::sv503_maxworkitems)
            .property("sv503_rawworkitems", &SERVER_INFO_503::sv503_rawworkitems)
            .property("sv503_irpstacksize", &SERVER_INFO_503::sv503_irpstacksize)
            .property("sv503_maxrawbuflen", &SERVER_INFO_503::sv503_maxrawbuflen)
            .property("sv503_sessusers", &SERVER_INFO_503::sv503_sessusers)
            .property("sv503_sessconns", &SERVER_INFO_503::sv503_sessconns)
            .property("sv503_maxpagedmemoryusage", &SERVER_INFO_503::sv503_maxpagedmemoryusage)
            .property("sv503_maxnonpagedmemoryusage", &SERVER_INFO_503::sv503_maxnonpagedmemoryusage)
            .property("sv503_enablesoftcompat", &SERVER_INFO_503::sv503_enablesoftcompat)
            .property("sv503_enableforcedlogoff", &SERVER_INFO_503::sv503_enableforcedlogoff)
            .property("sv503_timesource", &SERVER_INFO_503::sv503_timesource)
            .property("sv503_acceptdownlevelapis", &SERVER_INFO_503::sv503_acceptdownlevelapis)
            .property("sv503_lmannounce", &SERVER_INFO_503::sv503_lmannounce)
            .property("sv503_domain", &SERVER_INFO_503::sv503_domain)
            .property("sv503_maxcopyreadlen", &SERVER_INFO_503::sv503_maxcopyreadlen)
            .property("sv503_maxcopywritelen", &SERVER_INFO_503::sv503_maxcopywritelen)
            .property("sv503_minkeepsearch", &SERVER_INFO_503::sv503_minkeepsearch)
            .property("sv503_maxkeepsearch", &SERVER_INFO_503::sv503_maxkeepsearch)
            .property("sv503_minkeepcomplsearch", &SERVER_INFO_503::sv503_minkeepcomplsearch)
            .property("sv503_maxkeepcomplsearch", &SERVER_INFO_503::sv503_maxkeepcomplsearch)
            .property("sv503_threadcountadd", &SERVER_INFO_503::sv503_threadcountadd)
            .property("sv503_numblockthreads", &SERVER_INFO_503::sv503_numblockthreads)
            .property("sv503_scavtimeout", &SERVER_INFO_503::sv503_scavtimeout)
            .property("sv503_minrcvqueue", &SERVER_INFO_503::sv503_minrcvqueue)
            .property("sv503_minfreeworkitems", &SERVER_INFO_503::sv503_minfreeworkitems)
            .property("sv503_xactmemsize", &SERVER_INFO_503::sv503_xactmemsize)
            .property("sv503_threadpriority", &SERVER_INFO_503::sv503_threadpriority)
            .property("sv503_maxmpxct", &SERVER_INFO_503::sv503_maxmpxct)
            .property("sv503_oplockbreakwait", &SERVER_INFO_503::sv503_oplockbreakwait)
            .property("sv503_oplockbreakresponsewait", &SERVER_INFO_503::sv503_oplockbreakresponsewait)
            .property("sv503_enableoplocks", &SERVER_INFO_503::sv503_enableoplocks)
            .property("sv503_enableoplockforceclose", &SERVER_INFO_503::sv503_enableoplockforceclose)
            .property("sv503_enablefcbopens", &SERVER_INFO_503::sv503_enablefcbopens)
            .property("sv503_enableraw", &SERVER_INFO_503::sv503_enableraw)
            .property("sv503_enablesharednetdrives", &SERVER_INFO_503::sv503_enablesharednetdrives)
            .property("sv503_minfreeconnections", &SERVER_INFO_503::sv503_minfreeconnections)
            .property("sv503_maxfreeconnections", &SERVER_INFO_503::sv503_maxfreeconnections)
            ,
        xlb_class<SERVER_TRANSPORT_INFO_0>("SERVER_TRANSPORT_INFO_0") .constructor<>() .destructor()
            .property("svti0_numberofvcs", &SERVER_TRANSPORT_INFO_0::svti0_numberofvcs)
            .property("svti0_transportname", &SERVER_TRANSPORT_INFO_0::svti0_transportname)
            .property("svti0_transportaddress", &SERVER_TRANSPORT_INFO_0::svti0_transportaddress)
            .property("svti0_transportaddresslength", &SERVER_TRANSPORT_INFO_0::svti0_transportaddresslength)
            .property("svti0_networkaddress", &SERVER_TRANSPORT_INFO_0::svti0_networkaddress)
            ,
        xlb_class<SERVER_TRANSPORT_INFO_1>("SERVER_TRANSPORT_INFO_1") .constructor<>() .destructor()
            .property("svti1_numberofvcs", &SERVER_TRANSPORT_INFO_1::svti1_numberofvcs)
            .property("svti1_transportname", &SERVER_TRANSPORT_INFO_1::svti1_transportname)
            .property("svti1_transportaddress", &SERVER_TRANSPORT_INFO_1::svti1_transportaddress)
            .property("svti1_transportaddresslength", &SERVER_TRANSPORT_INFO_1::svti1_transportaddresslength)
            .property("svti1_networkaddress", &SERVER_TRANSPORT_INFO_1::svti1_networkaddress)
            .property("svti1_domain", &SERVER_TRANSPORT_INFO_1::svti1_domain)
            ,
        xlb_class<SERVER_TRANSPORT_INFO_2>("SERVER_TRANSPORT_INFO_2") .constructor<>() .destructor()
            .property("svti2_numberofvcs", &SERVER_TRANSPORT_INFO_2::svti2_numberofvcs)
            .property("svti2_transportname", &SERVER_TRANSPORT_INFO_2::svti2_transportname)
            .property("svti2_transportaddress", &SERVER_TRANSPORT_INFO_2::svti2_transportaddress)
            .property("svti2_transportaddresslength", &SERVER_TRANSPORT_INFO_2::svti2_transportaddresslength)
            .property("svti2_networkaddress", &SERVER_TRANSPORT_INFO_2::svti2_networkaddress)
            .property("svti2_domain", &SERVER_TRANSPORT_INFO_2::svti2_domain)
            .property("svti2_flags", &SERVER_TRANSPORT_INFO_2::svti2_flags)
            ,
            xlb_const("SVTI2_REMAP_PIPE_NAMES", SVTI2_REMAP_PIPE_NAMES),
            xlb_const("SVTI2_SCOPED_NAME", SVTI2_SCOPED_NAME),
        xlb_class<SERVER_TRANSPORT_INFO_3>("SERVER_TRANSPORT_INFO_3") .constructor<>() .destructor()
            .property("svti3_numberofvcs", &SERVER_TRANSPORT_INFO_3::svti3_numberofvcs)
            .property("svti3_transportname", &SERVER_TRANSPORT_INFO_3::svti3_transportname)
            .property("svti3_transportaddress", &SERVER_TRANSPORT_INFO_3::svti3_transportaddress)
            .property("svti3_transportaddresslength", &SERVER_TRANSPORT_INFO_3::svti3_transportaddresslength)
            .property("svti3_networkaddress", &SERVER_TRANSPORT_INFO_3::svti3_networkaddress)
            .property("svti3_domain", &SERVER_TRANSPORT_INFO_3::svti3_domain)
            .property("svti3_flags", &SERVER_TRANSPORT_INFO_3::svti3_flags)
            .property("svti3_passwordlength", &SERVER_TRANSPORT_INFO_3::svti3_passwordlength)
            .property("svti3_password", &SERVER_TRANSPORT_INFO_3::svti3_password)
            ,
        xlb_class<STD_ALERT>("STD_ALERT") .constructor<>() .destructor()
            .property("alrt_timestamp", &STD_ALERT::alrt_timestamp)
            .property("alrt_eventname", &STD_ALERT::alrt_eventname)
            .property("alrt_servicename", &STD_ALERT::alrt_servicename)
            ,
            xlb_const("ALERT_ADMIN_EVENT", ALERT_ADMIN_EVENT),
            xlb_const("ALERT_ERRORLOG_EVENT", ALERT_ERRORLOG_EVENT),
            xlb_const("ALERT_MESSAGE_EVENT", ALERT_MESSAGE_EVENT),
            xlb_const("ALERT_PRINT_EVENT", ALERT_PRINT_EVENT),
            xlb_const("ALERT_USER_EVENT", ALERT_USER_EVENT),
        xlb_class<TIME_OF_DAY_INFO>("TIME_OF_DAY_INFO") .constructor<>() .destructor()
            .property("tod_elapsedt", &TIME_OF_DAY_INFO::tod_elapsedt)
            .property("tod_msecs", &TIME_OF_DAY_INFO::tod_msecs)
            .property("tod_hours", &TIME_OF_DAY_INFO::tod_hours)
            .property("tod_mins", &TIME_OF_DAY_INFO::tod_mins)
            .property("tod_secs", &TIME_OF_DAY_INFO::tod_secs)
            .property("tod_hunds", &TIME_OF_DAY_INFO::tod_hunds)
            .property("tod_timezone", &TIME_OF_DAY_INFO::tod_timezone)
            .property("tod_tinterval", &TIME_OF_DAY_INFO::tod_tinterval)
            .property("tod_day", &TIME_OF_DAY_INFO::tod_day)
            .property("tod_month", &TIME_OF_DAY_INFO::tod_month)
            .property("tod_year", &TIME_OF_DAY_INFO::tod_year)
            .property("tod_weekday", &TIME_OF_DAY_INFO::tod_weekday)
            ,
        xlb_class<USE_INFO_0>("USE_INFO_0") .constructor<>() .destructor()
            .property("ui0_local", &USE_INFO_0::ui0_local)
            .property("ui0_remote", &USE_INFO_0::ui0_remote)
            ,
        xlb_class<USE_INFO_1>("USE_INFO_1") .constructor<>() .destructor()
            .property("ui1_local", &USE_INFO_1::ui1_local)
            .property("ui1_remote", &USE_INFO_1::ui1_remote)
            .property("ui1_password", &USE_INFO_1::ui1_password)
            .property("ui1_status", &USE_INFO_1::ui1_status)
            .property("ui1_asg_type", &USE_INFO_1::ui1_asg_type)
            .property("ui1_refcount", &USE_INFO_1::ui1_refcount)
            .property("ui1_usecount", &USE_INFO_1::ui1_usecount)
            ,
            xlb_const("USE_OK", USE_OK),
            xlb_const("USE_PAUSED", USE_PAUSED),
            xlb_const("USE_SESSLOST", USE_SESSLOST),
            xlb_const("USE_DISCONN", USE_DISCONN),
            xlb_const("USE_NETERR", USE_NETERR),
            xlb_const("USE_CONN", USE_CONN),
            xlb_const("USE_RECONN", USE_RECONN),
            xlb_const("USE_WILDCARD", USE_WILDCARD),
            xlb_const("USE_DISKDEV", USE_DISKDEV),
            xlb_const("USE_SPOOLDEV", USE_SPOOLDEV),
            xlb_const("USE_IPC", USE_IPC),
        xlb_class<USE_INFO_2>("USE_INFO_2") .constructor<>() .destructor()
            .property("ui2_local", &USE_INFO_2::ui2_local)
            .property("ui2_remote", &USE_INFO_2::ui2_remote)
            .property("ui2_password", &USE_INFO_2::ui2_password)
            .property("ui2_status", &USE_INFO_2::ui2_status)
            .property("ui2_asg_type", &USE_INFO_2::ui2_asg_type)
            .property("ui2_refcount", &USE_INFO_2::ui2_refcount)
            .property("ui2_usecount", &USE_INFO_2::ui2_usecount)
            .property("ui2_username", &USE_INFO_2::ui2_username)
            .property("ui2_domainname", &USE_INFO_2::ui2_domainname)
            ,
            xlb_const("USE_OK", USE_OK),
            xlb_const("USE_PAUSED", USE_PAUSED),
            xlb_const("USE_SESSLOST", USE_SESSLOST),
            xlb_const("USE_DISCONN", USE_DISCONN),
            xlb_const("USE_NETERR", USE_NETERR),
            xlb_const("USE_CONN", USE_CONN),
            xlb_const("USE_RECONN", USE_RECONN),
            xlb_const("USE_WILDCARD", USE_WILDCARD),
            xlb_const("USE_DISKDEV", USE_DISKDEV),
            xlb_const("USE_SPOOLDEV", USE_SPOOLDEV),
            xlb_const("USE_IPC", USE_IPC),
        xlb_class<USE_INFO_3>("USE_INFO_3") .constructor<>() .destructor()
            .property("ui3_ui2", &USE_INFO_3::ui3_ui2)
            .property("ui3_flags", &USE_INFO_3::ui3_flags)
            ,
        xlb_class<USER_INFO_0>("USER_INFO_0") .constructor<>() .destructor()
            .property("usri0_name", &USER_INFO_0::usri0_name)
            ,
        xlb_class<USER_INFO_1>("USER_INFO_1") .constructor<>() .destructor()
            .property("usri1_name", &USER_INFO_1::usri1_name)
            .property("usri1_password", &USER_INFO_1::usri1_password)
            .property("usri1_password_age", &USER_INFO_1::usri1_password_age)
            .property("usri1_priv", &USER_INFO_1::usri1_priv)
            .property("usri1_home_dir", &USER_INFO_1::usri1_home_dir)
            .property("usri1_comment", &USER_INFO_1::usri1_comment)
            .property("usri1_flags", &USER_INFO_1::usri1_flags)
            .property("usri1_script_path", &USER_INFO_1::usri1_script_path)
            ,
            xlb_const("USER_PRIV_GUEST", USER_PRIV_GUEST),
            xlb_const("USER_PRIV_USER", USER_PRIV_USER),
            xlb_const("USER_PRIV_ADMIN", USER_PRIV_ADMIN),
            xlb_const("UF_SCRIPT", UF_SCRIPT),
            xlb_const("UF_ACCOUNTDISABLE", UF_ACCOUNTDISABLE),
            xlb_const("UF_HOMEDIR_REQUIRED", UF_HOMEDIR_REQUIRED),
            xlb_const("UF_PASSWD_NOTREQD", UF_PASSWD_NOTREQD),
            xlb_const("UF_PASSWD_CANT_CHANGE", UF_PASSWD_CANT_CHANGE),
            xlb_const("UF_LOCKOUT", UF_LOCKOUT),
            xlb_const("UF_DONT_EXPIRE_PASSWD", UF_DONT_EXPIRE_PASSWD),
            xlb_const("UF_ENCRYPTED_TEXT_PASSWORD_ALLOWED", UF_ENCRYPTED_TEXT_PASSWORD_ALLOWED),
            xlb_const("UF_NOT_DELEGATED", UF_NOT_DELEGATED),
            xlb_const("UF_SMARTCARD_REQUIRED", UF_SMARTCARD_REQUIRED),
            xlb_const("UF_USE_DES_KEY_ONLY", UF_USE_DES_KEY_ONLY),
            xlb_const("UF_DONT_REQUIRE_PREAUTH", UF_DONT_REQUIRE_PREAUTH),
            xlb_const("UF_TRUSTED_FOR_DELEGATION", UF_TRUSTED_FOR_DELEGATION),
            xlb_const("UF_PASSWORD_EXPIRED", UF_PASSWORD_EXPIRED),
            xlb_const("UF_TRUSTED_TO_AUTHENTICATE_FOR_DELEGATION", UF_TRUSTED_TO_AUTHENTICATE_FOR_DELEGATION),
            xlb_const("UF_NORMAL_ACCOUNT", UF_NORMAL_ACCOUNT),
            xlb_const("UF_TEMP_DUPLICATE_ACCOUNT", UF_TEMP_DUPLICATE_ACCOUNT),
            xlb_const("UF_WORKSTATION_TRUST_ACCOUNT", UF_WORKSTATION_TRUST_ACCOUNT),
            xlb_const("UF_SERVER_TRUST_ACCOUNT", UF_SERVER_TRUST_ACCOUNT),
            xlb_const("UF_INTERDOMAIN_TRUST_ACCOUNT", UF_INTERDOMAIN_TRUST_ACCOUNT),
        xlb_class<USER_INFO_10>("USER_INFO_10") .constructor<>() .destructor()
            .property("usri10_name", &USER_INFO_10::usri10_name)
            .property("usri10_comment", &USER_INFO_10::usri10_comment)
            .property("usri10_usr_comment", &USER_INFO_10::usri10_usr_comment)
            .property("usri10_full_name", &USER_INFO_10::usri10_full_name)
            ,
        xlb_class<USER_INFO_1003>("USER_INFO_1003") .constructor<>() .destructor()
            .property("usri1003_password", &USER_INFO_1003::usri1003_password)
            ,
        xlb_class<USER_INFO_1005>("USER_INFO_1005") .constructor<>() .destructor()
            .property("usri1005_priv", &USER_INFO_1005::usri1005_priv)
            ,
            xlb_const("USER_PRIV_GUEST", USER_PRIV_GUEST),
            xlb_const("USER_PRIV_USER", USER_PRIV_USER),
            xlb_const("USER_PRIV_ADMIN", USER_PRIV_ADMIN),
        xlb_class<USER_INFO_1006>("USER_INFO_1006") .constructor<>() .destructor()
            .property("usri1006_home_dir", &USER_INFO_1006::usri1006_home_dir)
            ,
        xlb_class<USER_INFO_1007>("USER_INFO_1007") .constructor<>() .destructor()
            .property("usri1007_comment", &USER_INFO_1007::usri1007_comment)
            ,
        xlb_class<USER_INFO_1008>("USER_INFO_1008") .constructor<>() .destructor()
            .property("usri1008_flags", &USER_INFO_1008::usri1008_flags)
            ,
            xlb_const("UF_SCRIPT", UF_SCRIPT),
            xlb_const("UF_ACCOUNTDISABLE", UF_ACCOUNTDISABLE),
            xlb_const("UF_HOMEDIR_REQUIRED", UF_HOMEDIR_REQUIRED),
            xlb_const("UF_PASSWD_NOTREQD", UF_PASSWD_NOTREQD),
            xlb_const("UF_PASSWD_CANT_CHANGE", UF_PASSWD_CANT_CHANGE),
            xlb_const("UF_LOCKOUT", UF_LOCKOUT),
            xlb_const("UF_DONT_EXPIRE_PASSWD", UF_DONT_EXPIRE_PASSWD),
            xlb_const("UF_ENCRYPTED_TEXT_PASSWORD_ALLOWED", UF_ENCRYPTED_TEXT_PASSWORD_ALLOWED),
            xlb_const("UF_NOT_DELEGATED", UF_NOT_DELEGATED),
            xlb_const("UF_SMARTCARD_REQUIRED", UF_SMARTCARD_REQUIRED),
            xlb_const("UF_USE_DES_KEY_ONLY", UF_USE_DES_KEY_ONLY),
            xlb_const("UF_DONT_REQUIRE_PREAUTH", UF_DONT_REQUIRE_PREAUTH),
            xlb_const("UF_TRUSTED_FOR_DELEGATION", UF_TRUSTED_FOR_DELEGATION),
            xlb_const("UF_PASSWORD_EXPIRED", UF_PASSWORD_EXPIRED),
            xlb_const("UF_TRUSTED_TO_AUTHENTICATE_FOR_DELEGATION", UF_TRUSTED_TO_AUTHENTICATE_FOR_DELEGATION),
            xlb_const("UF_NORMAL_ACCOUNT", UF_NORMAL_ACCOUNT),
            xlb_const("UF_TEMP_DUPLICATE_ACCOUNT", UF_TEMP_DUPLICATE_ACCOUNT),
            xlb_const("UF_WORKSTATION_TRUST_ACCOUNT", UF_WORKSTATION_TRUST_ACCOUNT),
            xlb_const("UF_SERVER_TRUST_ACCOUNT", UF_SERVER_TRUST_ACCOUNT),
            xlb_const("UF_INTERDOMAIN_TRUST_ACCOUNT", UF_INTERDOMAIN_TRUST_ACCOUNT),
        xlb_class<USER_INFO_1009>("USER_INFO_1009") .constructor<>() .destructor()
            .property("usri1009_script_path", &USER_INFO_1009::usri1009_script_path)
            ,
        xlb_class<USER_INFO_1010>("USER_INFO_1010") .constructor<>() .destructor()
            .property("usri1010_auth_flags", &USER_INFO_1010::usri1010_auth_flags)
            ,
            xlb_const("AF_OP_PRINT", AF_OP_PRINT),
            xlb_const("AF_OP_COMM", AF_OP_COMM),
            xlb_const("AF_OP_SERVER", AF_OP_SERVER),
            xlb_const("AF_OP_ACCOUNTS", AF_OP_ACCOUNTS),
        xlb_class<USER_INFO_1011>("USER_INFO_1011") .constructor<>() .destructor()
            .property("usri1011_full_name", &USER_INFO_1011::usri1011_full_name)
            ,
        xlb_class<USER_INFO_1012>("USER_INFO_1012") .constructor<>() .destructor()
            .property("usri1012_usr_comment", &USER_INFO_1012::usri1012_usr_comment)
            ,
        xlb_class<USER_INFO_1013>("USER_INFO_1013") .constructor<>() .destructor()
            .property("usri1013_parms", &USER_INFO_1013::usri1013_parms)
            ,
        xlb_class<USER_INFO_1014>("USER_INFO_1014") .constructor<>() .destructor()
            .property("usri1014_workstations", &USER_INFO_1014::usri1014_workstations)
            ,
        xlb_class<USER_INFO_1017>("USER_INFO_1017") .constructor<>() .destructor()
            .property("usri1017_acct_expires", &USER_INFO_1017::usri1017_acct_expires)
            ,
        xlb_class<USER_INFO_1018>("USER_INFO_1018") .constructor<>() .destructor()
            .property("usri1018_max_storage", &USER_INFO_1018::usri1018_max_storage)
            ,
        xlb_class<USER_INFO_1020>("USER_INFO_1020") .constructor<>() .destructor()
            .property("usri1020_units_per_week", &USER_INFO_1020::usri1020_units_per_week)
            .property("usri1020_logon_hours", &USER_INFO_1020::usri1020_logon_hours)
            ,
        xlb_class<USER_INFO_1023>("USER_INFO_1023") .constructor<>() .destructor()
            .property("usri1023_logon_server", &USER_INFO_1023::usri1023_logon_server)
            ,
        xlb_class<USER_INFO_1024>("USER_INFO_1024") .constructor<>() .destructor()
            .property("usri1024_country_code", &USER_INFO_1024::usri1024_country_code)
            ,
        xlb_class<USER_INFO_1025>("USER_INFO_1025") .constructor<>() .destructor()
            .property("usri1025_code_page", &USER_INFO_1025::usri1025_code_page)
            ,
        xlb_class<USER_INFO_1051>("USER_INFO_1051") .constructor<>() .destructor()
            .property("usri1051_primary_group_id", &USER_INFO_1051::usri1051_primary_group_id)
            ,
        xlb_class<USER_INFO_1052>("USER_INFO_1052") .constructor<>() .destructor()
            .property("usri1052_profile", &USER_INFO_1052::usri1052_profile)
            ,
        xlb_class<USER_INFO_1053>("USER_INFO_1053") .constructor<>() .destructor()
            .property("usri1053_home_dir_drive", &USER_INFO_1053::usri1053_home_dir_drive)
            ,
        xlb_class<USER_INFO_11>("USER_INFO_11") .constructor<>() .destructor()
            .property("usri11_name", &USER_INFO_11::usri11_name)
            .property("usri11_comment", &USER_INFO_11::usri11_comment)
            .property("usri11_usr_comment", &USER_INFO_11::usri11_usr_comment)
            .property("usri11_full_name", &USER_INFO_11::usri11_full_name)
            .property("usri11_priv", &USER_INFO_11::usri11_priv)
            .property("usri11_auth_flags", &USER_INFO_11::usri11_auth_flags)
            .property("usri11_password_age", &USER_INFO_11::usri11_password_age)
            .property("usri11_home_dir", &USER_INFO_11::usri11_home_dir)
            .property("usri11_parms", &USER_INFO_11::usri11_parms)
            .property("usri11_last_logon", &USER_INFO_11::usri11_last_logon)
            .property("usri11_last_logoff", &USER_INFO_11::usri11_last_logoff)
            .property("usri11_bad_pw_count", &USER_INFO_11::usri11_bad_pw_count)
            .property("usri11_num_logons", &USER_INFO_11::usri11_num_logons)
            .property("usri11_logon_server", &USER_INFO_11::usri11_logon_server)
            .property("usri11_country_code", &USER_INFO_11::usri11_country_code)
            .property("usri11_workstations", &USER_INFO_11::usri11_workstations)
            .property("usri11_max_storage", &USER_INFO_11::usri11_max_storage)
            .property("usri11_units_per_week", &USER_INFO_11::usri11_units_per_week)
            .property("usri11_logon_hours", &USER_INFO_11::usri11_logon_hours)
            .property("usri11_code_page", &USER_INFO_11::usri11_code_page)
            ,
            xlb_const("USER_PRIV_GUEST", USER_PRIV_GUEST),
            xlb_const("USER_PRIV_USER", USER_PRIV_USER),
            xlb_const("USER_PRIV_ADMIN", USER_PRIV_ADMIN),
            xlb_const("AF_OP_PRINT", AF_OP_PRINT),
            xlb_const("AF_OP_COMM", AF_OP_COMM),
            xlb_const("AF_OP_SERVER", AF_OP_SERVER),
            xlb_const("AF_OP_ACCOUNTS", AF_OP_ACCOUNTS),
        xlb_class<USER_INFO_2>("USER_INFO_2") .constructor<>() .destructor()
            .property("usri2_name", &USER_INFO_2::usri2_name)
            .property("usri2_password", &USER_INFO_2::usri2_password)
            .property("usri2_password_age", &USER_INFO_2::usri2_password_age)
            .property("usri2_priv", &USER_INFO_2::usri2_priv)
            .property("usri2_home_dir", &USER_INFO_2::usri2_home_dir)
            .property("usri2_comment", &USER_INFO_2::usri2_comment)
            .property("usri2_flags", &USER_INFO_2::usri2_flags)
            .property("usri2_script_path", &USER_INFO_2::usri2_script_path)
            .property("usri2_auth_flags", &USER_INFO_2::usri2_auth_flags)
            .property("usri2_full_name", &USER_INFO_2::usri2_full_name)
            .property("usri2_usr_comment", &USER_INFO_2::usri2_usr_comment)
            .property("usri2_parms", &USER_INFO_2::usri2_parms)
            .property("usri2_workstations", &USER_INFO_2::usri2_workstations)
            .property("usri2_last_logon", &USER_INFO_2::usri2_last_logon)
            .property("usri2_last_logoff", &USER_INFO_2::usri2_last_logoff)
            .property("usri2_acct_expires", &USER_INFO_2::usri2_acct_expires)
            .property("usri2_max_storage", &USER_INFO_2::usri2_max_storage)
            .property("usri2_units_per_week", &USER_INFO_2::usri2_units_per_week)
            .property("usri2_logon_hours", &USER_INFO_2::usri2_logon_hours)
            .property("usri2_bad_pw_count", &USER_INFO_2::usri2_bad_pw_count)
            .property("usri2_num_logons", &USER_INFO_2::usri2_num_logons)
            .property("usri2_logon_server", &USER_INFO_2::usri2_logon_server)
            .property("usri2_country_code", &USER_INFO_2::usri2_country_code)
            .property("usri2_code_page", &USER_INFO_2::usri2_code_page)
            ,
            xlb_const("UF_SCRIPT", UF_SCRIPT),
            xlb_const("UF_ACCOUNTDISABLE", UF_ACCOUNTDISABLE),
            xlb_const("UF_HOMEDIR_REQUIRED", UF_HOMEDIR_REQUIRED),
            xlb_const("UF_PASSWD_NOTREQD", UF_PASSWD_NOTREQD),
            xlb_const("UF_PASSWD_CANT_CHANGE", UF_PASSWD_CANT_CHANGE),
            xlb_const("UF_LOCKOUT", UF_LOCKOUT),
            xlb_const("UF_DONT_EXPIRE_PASSWD", UF_DONT_EXPIRE_PASSWD),
            xlb_const("UF_ENCRYPTED_TEXT_PASSWORD_ALLOWED", UF_ENCRYPTED_TEXT_PASSWORD_ALLOWED),
            xlb_const("UF_NOT_DELEGATED", UF_NOT_DELEGATED),
            xlb_const("UF_SMARTCARD_REQUIRED", UF_SMARTCARD_REQUIRED),
            xlb_const("UF_USE_DES_KEY_ONLY", UF_USE_DES_KEY_ONLY),
            xlb_const("UF_DONT_REQUIRE_PREAUTH", UF_DONT_REQUIRE_PREAUTH),
            xlb_const("UF_TRUSTED_FOR_DELEGATION", UF_TRUSTED_FOR_DELEGATION),
            xlb_const("UF_PASSWORD_EXPIRED", UF_PASSWORD_EXPIRED),
            xlb_const("UF_TRUSTED_TO_AUTHENTICATE_FOR_DELEGATION", UF_TRUSTED_TO_AUTHENTICATE_FOR_DELEGATION),
            xlb_const("UF_NORMAL_ACCOUNT", UF_NORMAL_ACCOUNT),
            xlb_const("UF_TEMP_DUPLICATE_ACCOUNT", UF_TEMP_DUPLICATE_ACCOUNT),
            xlb_const("UF_WORKSTATION_TRUST_ACCOUNT", UF_WORKSTATION_TRUST_ACCOUNT),
            xlb_const("UF_SERVER_TRUST_ACCOUNT", UF_SERVER_TRUST_ACCOUNT),
            xlb_const("UF_INTERDOMAIN_TRUST_ACCOUNT", UF_INTERDOMAIN_TRUST_ACCOUNT),
            xlb_const("AF_OP_PRINT", AF_OP_PRINT),
            xlb_const("AF_OP_COMM", AF_OP_COMM),
            xlb_const("AF_OP_SERVER", AF_OP_SERVER),
            xlb_const("AF_OP_ACCOUNTS", AF_OP_ACCOUNTS),
        xlb_class<USER_INFO_20>("USER_INFO_20") .constructor<>() .destructor()
            .property("usri20_name", &USER_INFO_20::usri20_name)
            .property("usri20_full_name", &USER_INFO_20::usri20_full_name)
            .property("usri20_comment", &USER_INFO_20::usri20_comment)
            .property("usri20_flags", &USER_INFO_20::usri20_flags)
            .property("usri20_user_id", &USER_INFO_20::usri20_user_id)
            ,
        xlb_class<USER_INFO_21>("USER_INFO_21") .constructor<>() .destructor()
            .property("usri21_password", &USER_INFO_21::usri21_password)
            ,
        xlb_class<USER_INFO_22>("USER_INFO_22") .constructor<>() .destructor()
            .property("usri22_name", &USER_INFO_22::usri22_name)
            .property("usri22_password", &USER_INFO_22::usri22_password)
            .property("usri22_password_age", &USER_INFO_22::usri22_password_age)
            .property("usri22_priv", &USER_INFO_22::usri22_priv)
            .property("usri22_home_dir", &USER_INFO_22::usri22_home_dir)
            .property("usri22_comment", &USER_INFO_22::usri22_comment)
            .property("usri22_flags", &USER_INFO_22::usri22_flags)
            .property("usri22_script_path", &USER_INFO_22::usri22_script_path)
            .property("usri22_auth_flags", &USER_INFO_22::usri22_auth_flags)
            .property("usri22_full_name", &USER_INFO_22::usri22_full_name)
            .property("usri22_usr_comment", &USER_INFO_22::usri22_usr_comment)
            .property("usri22_parms", &USER_INFO_22::usri22_parms)
            .property("usri22_workstations", &USER_INFO_22::usri22_workstations)
            .property("usri22_last_logon", &USER_INFO_22::usri22_last_logon)
            .property("usri22_last_logoff", &USER_INFO_22::usri22_last_logoff)
            .property("usri22_acct_expires", &USER_INFO_22::usri22_acct_expires)
            .property("usri22_max_storage", &USER_INFO_22::usri22_max_storage)
            .property("usri22_units_per_week", &USER_INFO_22::usri22_units_per_week)
            .property("usri22_logon_hours", &USER_INFO_22::usri22_logon_hours)
            .property("usri22_bad_pw_count", &USER_INFO_22::usri22_bad_pw_count)
            .property("usri22_num_logons", &USER_INFO_22::usri22_num_logons)
            .property("usri22_logon_server", &USER_INFO_22::usri22_logon_server)
            .property("usri22_country_code", &USER_INFO_22::usri22_country_code)
            .property("usri22_code_page", &USER_INFO_22::usri22_code_page)
            ,
        xlb_class<USER_INFO_23>("USER_INFO_23") .constructor<>() .destructor()
            .property("usri23_name", &USER_INFO_23::usri23_name)
            .property("usri23_full_name", &USER_INFO_23::usri23_full_name)
            .property("usri23_comment", &USER_INFO_23::usri23_comment)
            .property("usri23_flags", &USER_INFO_23::usri23_flags)
            .property("usri23_user_sid", &USER_INFO_23::usri23_user_sid)
            ,
        xlb_class<USER_INFO_24>("USER_INFO_24") .constructor<>() .destructor()
            .property("usri24_internet_identity", &USER_INFO_24::usri24_internet_identity)
            .property("usri24_flags", &USER_INFO_24::usri24_flags)
            .property("usri24_internet_provider_name", &USER_INFO_24::usri24_internet_provider_name)
            .property("usri24_internet_principal_name", &USER_INFO_24::usri24_internet_principal_name)
            .property("usri24_user_sid", &USER_INFO_24::usri24_user_sid)
            ,
        xlb_class<USER_INFO_3>("USER_INFO_3") .constructor<>() .destructor()
            .property("usri3_name", &USER_INFO_3::usri3_name)
            .property("usri3_password", &USER_INFO_3::usri3_password)
            .property("usri3_password_age", &USER_INFO_3::usri3_password_age)
            .property("usri3_priv", &USER_INFO_3::usri3_priv)
            .property("usri3_home_dir", &USER_INFO_3::usri3_home_dir)
            .property("usri3_comment", &USER_INFO_3::usri3_comment)
            .property("usri3_flags", &USER_INFO_3::usri3_flags)
            .property("usri3_script_path", &USER_INFO_3::usri3_script_path)
            .property("usri3_auth_flags", &USER_INFO_3::usri3_auth_flags)
            .property("usri3_full_name", &USER_INFO_3::usri3_full_name)
            .property("usri3_usr_comment", &USER_INFO_3::usri3_usr_comment)
            .property("usri3_parms", &USER_INFO_3::usri3_parms)
            .property("usri3_workstations", &USER_INFO_3::usri3_workstations)
            .property("usri3_last_logon", &USER_INFO_3::usri3_last_logon)
            .property("usri3_last_logoff", &USER_INFO_3::usri3_last_logoff)
            .property("usri3_acct_expires", &USER_INFO_3::usri3_acct_expires)
            .property("usri3_max_storage", &USER_INFO_3::usri3_max_storage)
            .property("usri3_units_per_week", &USER_INFO_3::usri3_units_per_week)
            .property("usri3_logon_hours", &USER_INFO_3::usri3_logon_hours)
            .property("usri3_bad_pw_count", &USER_INFO_3::usri3_bad_pw_count)
            .property("usri3_num_logons", &USER_INFO_3::usri3_num_logons)
            .property("usri3_logon_server", &USER_INFO_3::usri3_logon_server)
            .property("usri3_country_code", &USER_INFO_3::usri3_country_code)
            .property("usri3_code_page", &USER_INFO_3::usri3_code_page)
            .property("usri3_user_id", &USER_INFO_3::usri3_user_id)
            .property("usri3_primary_group_id", &USER_INFO_3::usri3_primary_group_id)
            .property("usri3_profile", &USER_INFO_3::usri3_profile)
            .property("usri3_home_dir_drive", &USER_INFO_3::usri3_home_dir_drive)
            .property("usri3_password_expired", &USER_INFO_3::usri3_password_expired)
            ,
        xlb_class<USER_INFO_4>("USER_INFO_4") .constructor<>() .destructor()
            .property("usri4_name", &USER_INFO_4::usri4_name)
            .property("usri4_password", &USER_INFO_4::usri4_password)
            .property("usri4_password_age", &USER_INFO_4::usri4_password_age)
            .property("usri4_priv", &USER_INFO_4::usri4_priv)
            .property("usri4_home_dir", &USER_INFO_4::usri4_home_dir)
            .property("usri4_comment", &USER_INFO_4::usri4_comment)
            .property("usri4_flags", &USER_INFO_4::usri4_flags)
            .property("usri4_script_path", &USER_INFO_4::usri4_script_path)
            .property("usri4_auth_flags", &USER_INFO_4::usri4_auth_flags)
            .property("usri4_full_name", &USER_INFO_4::usri4_full_name)
            .property("usri4_usr_comment", &USER_INFO_4::usri4_usr_comment)
            .property("usri4_parms", &USER_INFO_4::usri4_parms)
            .property("usri4_workstations", &USER_INFO_4::usri4_workstations)
            .property("usri4_last_logon", &USER_INFO_4::usri4_last_logon)
            .property("usri4_last_logoff", &USER_INFO_4::usri4_last_logoff)
            .property("usri4_acct_expires", &USER_INFO_4::usri4_acct_expires)
            .property("usri4_max_storage", &USER_INFO_4::usri4_max_storage)
            .property("usri4_units_per_week", &USER_INFO_4::usri4_units_per_week)
            .property("usri4_logon_hours", &USER_INFO_4::usri4_logon_hours)
            .property("usri4_bad_pw_count", &USER_INFO_4::usri4_bad_pw_count)
            .property("usri4_num_logons", &USER_INFO_4::usri4_num_logons)
            .property("usri4_logon_server", &USER_INFO_4::usri4_logon_server)
            .property("usri4_country_code", &USER_INFO_4::usri4_country_code)
            .property("usri4_code_page", &USER_INFO_4::usri4_code_page)
            .property("usri4_user_sid", &USER_INFO_4::usri4_user_sid)
            .property("usri4_primary_group_id", &USER_INFO_4::usri4_primary_group_id)
            .property("usri4_profile", &USER_INFO_4::usri4_profile)
            .property("usri4_home_dir_drive", &USER_INFO_4::usri4_home_dir_drive)
            .property("usri4_password_expired", &USER_INFO_4::usri4_password_expired)
            ,
        xlb_class<USER_MODALS_INFO_0>("USER_MODALS_INFO_0") .constructor<>() .destructor()
            .property("usrmod0_min_passwd_len", &USER_MODALS_INFO_0::usrmod0_min_passwd_len)
            .property("usrmod0_max_passwd_age", &USER_MODALS_INFO_0::usrmod0_max_passwd_age)
            .property("usrmod0_min_passwd_age", &USER_MODALS_INFO_0::usrmod0_min_passwd_age)
            .property("usrmod0_force_logoff", &USER_MODALS_INFO_0::usrmod0_force_logoff)
            .property("usrmod0_password_hist_len", &USER_MODALS_INFO_0::usrmod0_password_hist_len)
            ,
        xlb_class<USER_MODALS_INFO_1>("USER_MODALS_INFO_1") .constructor<>() .destructor()
            .property("usrmod1_role", &USER_MODALS_INFO_1::usrmod1_role)
            .property("usrmod1_primary", &USER_MODALS_INFO_1::usrmod1_primary)
            ,
            xlb_const("UAS_ROLE_STANDALONE", UAS_ROLE_STANDALONE),
            xlb_const("UAS_ROLE_MEMBER", UAS_ROLE_MEMBER),
            xlb_const("UAS_ROLE_BACKUP", UAS_ROLE_BACKUP),
            xlb_const("UAS_ROLE_PRIMARY", UAS_ROLE_PRIMARY),
        xlb_class<USER_MODALS_INFO_1001>("USER_MODALS_INFO_1001") .constructor<>() .destructor()
            .property("usrmod1001_min_passwd_len", &USER_MODALS_INFO_1001::usrmod1001_min_passwd_len)
            ,
        xlb_class<USER_MODALS_INFO_1002>("USER_MODALS_INFO_1002") .constructor<>() .destructor()
            .property("usrmod1002_max_passwd_age", &USER_MODALS_INFO_1002::usrmod1002_max_passwd_age)
            ,
        xlb_class<USER_MODALS_INFO_1003>("USER_MODALS_INFO_1003") .constructor<>() .destructor()
            .property("usrmod1003_min_passwd_age", &USER_MODALS_INFO_1003::usrmod1003_min_passwd_age)
            ,
        xlb_class<USER_MODALS_INFO_1004>("USER_MODALS_INFO_1004") .constructor<>() .destructor()
            .property("usrmod1004_force_logoff", &USER_MODALS_INFO_1004::usrmod1004_force_logoff)
            ,
        xlb_class<USER_MODALS_INFO_1005>("USER_MODALS_INFO_1005") .constructor<>() .destructor()
            .property("usrmod1005_password_hist_len", &USER_MODALS_INFO_1005::usrmod1005_password_hist_len)
            ,
        xlb_class<USER_MODALS_INFO_1006>("USER_MODALS_INFO_1006") .constructor<>() .destructor()
            .property("usrmod1006_role", &USER_MODALS_INFO_1006::usrmod1006_role)
            ,
            xlb_const("UAS_ROLE_STANDALONE", UAS_ROLE_STANDALONE),
            xlb_const("UAS_ROLE_MEMBER", UAS_ROLE_MEMBER),
            xlb_const("UAS_ROLE_BACKUP", UAS_ROLE_BACKUP),
            xlb_const("UAS_ROLE_PRIMARY", UAS_ROLE_PRIMARY),
        xlb_class<USER_MODALS_INFO_1007>("USER_MODALS_INFO_1007") .constructor<>() .destructor()
            .property("usrmod1007_primary", &USER_MODALS_INFO_1007::usrmod1007_primary)
            ,
        xlb_class<USER_MODALS_INFO_2>("USER_MODALS_INFO_2") .constructor<>() .destructor()
            .property("usrmod2_domain_name", &USER_MODALS_INFO_2::usrmod2_domain_name)
            .property("usrmod2_domain_id", &USER_MODALS_INFO_2::usrmod2_domain_id)
            ,
        xlb_class<USER_MODALS_INFO_3>("USER_MODALS_INFO_3") .constructor<>() .destructor()
            .property("usrmod3_lockout_duration", &USER_MODALS_INFO_3::usrmod3_lockout_duration)
            .property("usrmod3_lockout_observation_window", &USER_MODALS_INFO_3::usrmod3_lockout_observation_window)
            .property("usrmod3_lockout_threshold", &USER_MODALS_INFO_3::usrmod3_lockout_threshold)
            ,
        xlb_class<USER_OTHER_INFO>("USER_OTHER_INFO") .constructor<>() .destructor()
            .property("alrtus_errcode", &USER_OTHER_INFO::alrtus_errcode)
            .property("alrtus_numstrings", &USER_OTHER_INFO::alrtus_numstrings)
            ,
        xlb_class<WKSTA_INFO_100>("WKSTA_INFO_100") .constructor<>() .destructor()
            .property("wki100_platform_id", &WKSTA_INFO_100::wki100_platform_id)
            .property("wki100_computername", &WKSTA_INFO_100::wki100_computername)
            .property("wki100_langroup", &WKSTA_INFO_100::wki100_langroup)
            .property("wki100_ver_major", &WKSTA_INFO_100::wki100_ver_major)
            .property("wki100_ver_minor", &WKSTA_INFO_100::wki100_ver_minor)
            ,
            xlb_const("PLATFORM_ID_DOS", PLATFORM_ID_DOS),
            xlb_const("PLATFORM_ID_OS2", PLATFORM_ID_OS2),
            xlb_const("PLATFORM_ID_NT", PLATFORM_ID_NT),
            xlb_const("PLATFORM_ID_OSF", PLATFORM_ID_OSF),
            xlb_const("PLATFORM_ID_VMS", PLATFORM_ID_VMS),
        xlb_class<WKSTA_INFO_101>("WKSTA_INFO_101") .constructor<>() .destructor()
            .property("wki101_platform_id", &WKSTA_INFO_101::wki101_platform_id)
            .property("wki101_computername", &WKSTA_INFO_101::wki101_computername)
            .property("wki101_langroup", &WKSTA_INFO_101::wki101_langroup)
            .property("wki101_ver_major", &WKSTA_INFO_101::wki101_ver_major)
            .property("wki101_ver_minor", &WKSTA_INFO_101::wki101_ver_minor)
            .property("wki101_lanroot", &WKSTA_INFO_101::wki101_lanroot)
            ,
        xlb_class<WKSTA_INFO_102>("WKSTA_INFO_102") .constructor<>() .destructor()
            .property("wki102_platform_id", &WKSTA_INFO_102::wki102_platform_id)
            .property("wki102_computername", &WKSTA_INFO_102::wki102_computername)
            .property("wki102_langroup", &WKSTA_INFO_102::wki102_langroup)
            .property("wki102_ver_major", &WKSTA_INFO_102::wki102_ver_major)
            .property("wki102_ver_minor", &WKSTA_INFO_102::wki102_ver_minor)
            .property("wki102_lanroot", &WKSTA_INFO_102::wki102_lanroot)
            .property("wki102_logged_on_users", &WKSTA_INFO_102::wki102_logged_on_users)
            ,
        xlb_class<WKSTA_INFO_502>("WKSTA_INFO_502") .constructor<>() .destructor()
            .property("wki502_char_wait", &WKSTA_INFO_502::wki502_char_wait)
            .property("wki502_collection_time", &WKSTA_INFO_502::wki502_collection_time)
            .property("wki502_maximum_collection_count", &WKSTA_INFO_502::wki502_maximum_collection_count)
            .property("wki502_keep_conn", &WKSTA_INFO_502::wki502_keep_conn)
            .property("wki502_max_cmds", &WKSTA_INFO_502::wki502_max_cmds)
            .property("wki502_sess_timeout", &WKSTA_INFO_502::wki502_sess_timeout)
            .property("wki502_siz_char_buf", &WKSTA_INFO_502::wki502_siz_char_buf)
            .property("wki502_max_threads", &WKSTA_INFO_502::wki502_max_threads)
            .property("wki502_lock_quota", &WKSTA_INFO_502::wki502_lock_quota)
            .property("wki502_lock_increment", &WKSTA_INFO_502::wki502_lock_increment)
            .property("wki502_lock_maximum", &WKSTA_INFO_502::wki502_lock_maximum)
            .property("wki502_pipe_increment", &WKSTA_INFO_502::wki502_pipe_increment)
            .property("wki502_pipe_maximum", &WKSTA_INFO_502::wki502_pipe_maximum)
            .property("wki502_cache_file_timeout", &WKSTA_INFO_502::wki502_cache_file_timeout)
            .property("wki502_dormant_file_limit", &WKSTA_INFO_502::wki502_dormant_file_limit)
            .property("wki502_read_ahead_throughput", &WKSTA_INFO_502::wki502_read_ahead_throughput)
            .property("wki502_num_mailslot_buffers", &WKSTA_INFO_502::wki502_num_mailslot_buffers)
            .property("wki502_num_srv_announce_buffers", &WKSTA_INFO_502::wki502_num_srv_announce_buffers)
            .property("wki502_max_illegal_datagram_events", &WKSTA_INFO_502::wki502_max_illegal_datagram_events)
            .property("wki502_illegal_datagram_event_reset_frequency", &WKSTA_INFO_502::wki502_illegal_datagram_event_reset_frequency)
            .property("wki502_log_election_packets", &WKSTA_INFO_502::wki502_log_election_packets)
            .property("wki502_use_opportunistic_locking", &WKSTA_INFO_502::wki502_use_opportunistic_locking)
            .property("wki502_use_unlock_behind", &WKSTA_INFO_502::wki502_use_unlock_behind)
            .property("wki502_use_close_behind", &WKSTA_INFO_502::wki502_use_close_behind)
            .property("wki502_buf_named_pipes", &WKSTA_INFO_502::wki502_buf_named_pipes)
            .property("wki502_use_lock_read_unlock", &WKSTA_INFO_502::wki502_use_lock_read_unlock)
            .property("wki502_utilize_nt_caching", &WKSTA_INFO_502::wki502_utilize_nt_caching)
            .property("wki502_use_raw_read", &WKSTA_INFO_502::wki502_use_raw_read)
            .property("wki502_use_raw_write", &WKSTA_INFO_502::wki502_use_raw_write)
            .property("wki502_use_write_raw_data", &WKSTA_INFO_502::wki502_use_write_raw_data)
            .property("wki502_use_encryption", &WKSTA_INFO_502::wki502_use_encryption)
            .property("wki502_buf_files_deny_write", &WKSTA_INFO_502::wki502_buf_files_deny_write)
            .property("wki502_buf_read_only_files", &WKSTA_INFO_502::wki502_buf_read_only_files)
            .property("wki502_force_core_create_mode", &WKSTA_INFO_502::wki502_force_core_create_mode)
            .property("wki502_use_512_byte_max_transfer", &WKSTA_INFO_502::wki502_use_512_byte_max_transfer)
            ,
        xlb_class<WKSTA_TRANSPORT_INFO_0>("WKSTA_TRANSPORT_INFO_0") .constructor<>() .destructor()
            .property("wkti0_quality_of_service", &WKSTA_TRANSPORT_INFO_0::wkti0_quality_of_service)
            .property("wkti0_number_of_vcs", &WKSTA_TRANSPORT_INFO_0::wkti0_number_of_vcs)
            .property("wkti0_transport_name", &WKSTA_TRANSPORT_INFO_0::wkti0_transport_name)
            .property("wkti0_transport_address", &WKSTA_TRANSPORT_INFO_0::wkti0_transport_address)
            .property("wkti0_wan_ish", &WKSTA_TRANSPORT_INFO_0::wkti0_wan_ish)
            ,
        xlb_class<WKSTA_USER_INFO_0>("WKSTA_USER_INFO_0") .constructor<>() .destructor()
            .property("wkui0_username", &WKSTA_USER_INFO_0::wkui0_username)
            ,
        xlb_class<WKSTA_USER_INFO_1>("WKSTA_USER_INFO_1") .constructor<>() .destructor()
            .property("wkui1_username", &WKSTA_USER_INFO_1::wkui1_username)
            .property("wkui1_logon_domain", &WKSTA_USER_INFO_1::wkui1_logon_domain)
            .property("wkui1_oth_domains", &WKSTA_USER_INFO_1::wkui1_oth_domains)
            .property("wkui1_logon_server", &WKSTA_USER_INFO_1::wkui1_logon_server)
            ,
        xlb_class<WKSTA_USER_INFO_1101>("WKSTA_USER_INFO_1101") .constructor<>() .destructor()
            .property("wkui1101_oth_domains", &WKSTA_USER_INFO_1101::wkui1101_oth_domains)
            ,
        xlb_const("ERROR_ACCESS_DENIED", ERROR_ACCESS_DENIED),
        xlb_const("NERR_InvalidComputer", NERR_InvalidComputer),
        xlb_const("NERR_NotPrimary", NERR_NotPrimary),
        xlb_const("NERR_SpeGroupOp", NERR_SpeGroupOp),
        xlb_const("NERR_UserNotFound", NERR_UserNotFound),
        xlb_const("NERR_GroupNotFound", NERR_GroupNotFound),

#ifdef compile
#endif

        xlb_const("CHECK_BIND_NWM", CHECK_BIND_NWM)
#endif // 0x0600
    } );
#endif // defined(CHECK_BIND_NWM)
return 0;
} // load_nwm
