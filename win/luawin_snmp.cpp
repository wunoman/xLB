#include "luawin.h"

//------------------------------------------------------------------------------------------------
int load_snmp(lua_State* L)
{
#if defined(BIND_SNMP)

    xlb_module(L, MODULE_NAME) ({
            xlb_class<xlb_cbf<SNMPAPI_CALLBACK>>("SNMPAPI_CALLBACK").constructor<xlb_luafunc>(),
            xlb_f("SnmpCancelMsg", SnmpCancelMsg),
            xlb_f("SnmpCleanup", SnmpCleanup),
            xlb_f("SnmpCleanupEx", SnmpCleanupEx),
            xlb_f("SnmpClose", SnmpClose),
            xlb_f("SnmpContextToStr", SnmpContextToStr),
            xlb_f("SnmpCountVbl", SnmpCountVbl),
            xlb_f("SnmpCreatePdu", SnmpCreatePdu),
            xlb_f("SnmpCreateSession", SnmpCreateSession),
            xlb_f("SnmpCreateVbl", SnmpCreateVbl),
            xlb_f("SnmpDecodeMsg", SnmpDecodeMsg),
            xlb_f("SnmpDeleteVb", SnmpDeleteVb),
            xlb_f("SnmpDuplicatePdu", SnmpDuplicatePdu),
            xlb_f("SnmpDuplicateVbl", SnmpDuplicateVbl),
            xlb_f("SnmpEncodeMsg", SnmpEncodeMsg),
            xlb_f("SnmpEntityToStr", SnmpEntityToStr),
            //xlb_f("SnmpExtensionClose", SnmpExtensionClose),
            //xlb_f("SnmpExtensionInit", SnmpExtensionInit),
            //xlb_f("SnmpExtensionInitEx", SnmpExtensionInitEx),
            //xlb_f("SnmpExtensionMonitor", SnmpExtensionMonitor),
            //xlb_f("SnmpExtensionQuery", SnmpExtensionQuery),
            //xlb_f("SnmpExtensionQueryEx", SnmpExtensionQueryEx),
            //xlb_f("SnmpExtensionTrap", SnmpExtensionTrap),
            xlb_f("SnmpFreeContext", SnmpFreeContext),
            xlb_f("SnmpFreeDescriptor", SnmpFreeDescriptor),
            xlb_f("SnmpFreeEntity", SnmpFreeEntity),
            xlb_f("SnmpFreePdu", SnmpFreePdu),
            xlb_f("SnmpFreeVbl", SnmpFreeVbl),
            xlb_f("SnmpGetLastError", SnmpGetLastError),
            xlb_f("SnmpGetPduData", SnmpGetPduData),
            xlb_f("SnmpGetRetransmitMode", SnmpGetRetransmitMode),
            xlb_f("SnmpGetRetry", SnmpGetRetry),
            xlb_f("SnmpGetTimeout", SnmpGetTimeout),
            xlb_f("SnmpGetTranslateMode", SnmpGetTranslateMode),
            xlb_f("SnmpGetVb", SnmpGetVb),
            xlb_f("SnmpGetVendorInfo", SnmpGetVendorInfo),
            xlb_f("SnmpListen", SnmpListen),
            xlb_f("SnmpMgrClose", SnmpMgrClose),
            xlb_f("SnmpMgrCtl", SnmpMgrCtl),
            xlb_f("SnmpMgrGetTrap", SnmpMgrGetTrap),
            xlb_f("SnmpMgrGetTrapEx", SnmpMgrGetTrapEx),
            xlb_f("SnmpMgrOidToStr", SnmpMgrOidToStr),
            xlb_f("SnmpMgrOpen", SnmpMgrOpen),
            xlb_f("SnmpMgrRequest", SnmpMgrRequest),
            xlb_f("SnmpMgrStrToOid", SnmpMgrStrToOid),
            xlb_f("SnmpMgrTrapListen", SnmpMgrTrapListen),
            xlb_f("SnmpOidCompare", SnmpOidCompare),
            xlb_f("SnmpOidCopy", SnmpOidCopy),
            xlb_f("SnmpOidToStr", SnmpOidToStr),
            xlb_f("SnmpOpen", SnmpOpen),
            xlb_f("SnmpRecvMsg", SnmpRecvMsg),
            xlb_f("SnmpRegister", SnmpRegister),
            xlb_f("SnmpSendMsg", SnmpSendMsg),
            xlb_f("SnmpSetPduData", SnmpSetPduData),
            xlb_f("SnmpSetPort", SnmpSetPort),
            xlb_f("SnmpSetRetransmitMode", SnmpSetRetransmitMode),
            xlb_f("SnmpSetRetry", SnmpSetRetry),
            xlb_f("SnmpSetTimeout", SnmpSetTimeout),
            xlb_f("SnmpSetTranslateMode", SnmpSetTranslateMode),
            xlb_f("SnmpSetVb", SnmpSetVb),
            xlb_f("SnmpStartup", SnmpStartup),
            xlb_f("SnmpStartupEx", SnmpStartupEx),
            xlb_f("SnmpStrToContext", SnmpStrToContext),
            xlb_f("SnmpStrToEntity", SnmpStrToEntity),
            xlb_f("SnmpStrToOid", SnmpStrToOid),
            xlb_f("SnmpSvcGetUptime", SnmpSvcGetUptime),
            xlb_f("SnmpSvcSetLogLevel", SnmpSvcSetLogLevel),
            xlb_f("SnmpSvcSetLogType", SnmpSvcSetLogType),
            xlb_f("SnmpUtilAsnAnyCpy", SnmpUtilAsnAnyCpy),
            xlb_f("SnmpUtilAsnAnyFree", SnmpUtilAsnAnyFree),
            //xlb_f("SnmpUtilDbgPrint", SnmpUtilDbgPrint), // ...
            xlb_f("SnmpUtilIdsToA", SnmpUtilIdsToA),
            xlb_f("SnmpUtilMemAlloc", SnmpUtilMemAlloc),
            xlb_f("SnmpUtilMemFree", SnmpUtilMemFree),
            xlb_f("SnmpUtilMemReAlloc", SnmpUtilMemReAlloc),
            xlb_f("SnmpUtilOctetsCmp", SnmpUtilOctetsCmp),
            xlb_f("SnmpUtilOctetsCpy", SnmpUtilOctetsCpy),
            xlb_f("SnmpUtilOctetsFree", SnmpUtilOctetsFree),
            xlb_f("SnmpUtilOctetsNCmp", SnmpUtilOctetsNCmp),
            xlb_f("SnmpUtilOidAppend", SnmpUtilOidAppend),
            xlb_f("SnmpUtilOidCmp", SnmpUtilOidCmp),
            xlb_f("SnmpUtilOidCpy", SnmpUtilOidCpy),
            xlb_f("SnmpUtilOidFree", SnmpUtilOidFree),
            xlb_f("SnmpUtilOidNCmp", SnmpUtilOidNCmp),
            xlb_f("SnmpUtilOidToA", SnmpUtilOidToA),
            xlb_f("SnmpUtilPrintAsnAny", SnmpUtilPrintAsnAny),
            xlb_f("SnmpUtilPrintOid", SnmpUtilPrintOid),
            xlb_f("SnmpUtilVarBindCpy", SnmpUtilVarBindCpy),
            xlb_f("SnmpUtilVarBindFree", SnmpUtilVarBindFree),
            xlb_f("SnmpUtilVarBindListCpy", SnmpUtilVarBindListCpy),
            xlb_f("SnmpUtilVarBindListFree", SnmpUtilVarBindListFree),

            xlb_class<AsnAny>("AsnAny") .constructor<>() .destructor()
                .property("asnType", &AsnAny::asnType)
                .property("asnValue", &AsnAny::asnValue)
                ,
            xlb_class<decltype(AsnAny::asnValue)>("AsnAny::asnValue") .constructor<>() .destructor()
                .property("unsigned32", &decltype(AsnAny::asnValue)::unsigned32)
                .property("counter64", &decltype(AsnAny::asnValue)::counter64)
                .property("string", &decltype(AsnAny::asnValue)::string)
                .property("bits", &decltype(AsnAny::asnValue)::bits)
                .property("object", &decltype(AsnAny::asnValue)::object)
                .property("sequence", &decltype(AsnAny::asnValue)::sequence)
                .property("address", &decltype(AsnAny::asnValue)::address)
                .property("counter", &decltype(AsnAny::asnValue)::counter)
                .property("gauge", &decltype(AsnAny::asnValue)::gauge)
                .property("ticks", &decltype(AsnAny::asnValue)::ticks)
                .property("arbitrary", &decltype(AsnAny::asnValue)::arbitrary)
                ,
            xlb_class<AsnObjectIdentifier>("AsnObjectIdentifier") .constructor<>() .destructor()
                .property("idLength", &AsnObjectIdentifier::idLength)
                .property("ids", &AsnObjectIdentifier::ids)
                ,
            xlb_class<AsnOctetString>("AsnOctetString") .constructor<>() .destructor()
                .property("stream", &AsnOctetString::stream)
                .property("length", &AsnOctetString::length)
                .property("dynamic", &AsnOctetString::dynamic)
                ,
            xlb_class<smiCNTR64>("smiCNTR64") .constructor<>() .destructor()
                .property("hipart", &smiCNTR64::hipart)
                .property("lopart", &smiCNTR64::lopart)
                ,
            xlb_class<smiOCTETS>("smiOCTETS") .constructor<>() .destructor()
                .property("len", &smiOCTETS::len)
                .property("ptr", &smiOCTETS::ptr)
                ,
            xlb_class<smiOID>("smiOID") .constructor<>() .destructor()
                .property("len", &smiOID::len)
                .property("ptr", &smiOID::ptr)
                ,
            xlb_class<smiVALUE>("smiVALUE") .constructor<>() .destructor()
                .property("syntax", &smiVALUE::syntax)
                .property("value", &smiVALUE::value)
                ,
            xlb_class<decltype(smiVALUE::value)>("smiVALUE::value") .constructor<>() .destructor()
                .property("sNumber", &decltype(smiVALUE::value)::sNumber)
                .property("uNumber", &decltype(smiVALUE::value)::uNumber)
                .property("hNumber", &decltype(smiVALUE::value)::hNumber)
                .property("string", &decltype(smiVALUE::value)::string)
                .property("oid", &decltype(smiVALUE::value)::oid)
                .property("empty", &decltype(smiVALUE::value)::empty)
                ,
            xlb_class<smiVENDORINFO>("smiVENDORINFO") .constructor<>() .destructor()
                .property("vendorName", &smiVENDORINFO::vendorName)
                .property("vendorContact", &smiVENDORINFO::vendorContact)
                .property("vendorVersionId", &smiVENDORINFO::vendorVersionId)
                .property("vendorVersionDate", &smiVENDORINFO::vendorVersionDate)
                .property("vendorEnterprise", &smiVENDORINFO::vendorEnterprise)
                ,
            xlb_class<SnmpVarBind>("SnmpVarBind") .constructor<>() .destructor()
                .property("name", &SnmpVarBind::name)
                .property("value", &SnmpVarBind::value)
                ,
            xlb_class<SnmpVarBindList>("SnmpVarBindList") .constructor<>() .destructor()
                .property("list", &SnmpVarBindList::list)
                .property("len", &SnmpVarBindList::len)
#ifdef compile
#endif
    });
#endif // defined(BIND_SNMP)

    return 0;
}
