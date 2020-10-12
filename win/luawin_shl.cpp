// https://docs.microsoft.com/en-us/windows/win32/api/_shell/
#include "luawin.h"

//-------------------------------------------------------------------------------------------------------------------
// Windows Shell
int load_shl(lua_State* L)
{
#if defined(CHECK_BIND_SHL)
    xlb_module( L, MODULE_NAME )( {

#if defined(WINVER) && (WINVER>=0x0600) // Vista
#ifdef compile
#endif
        // Class
        // class template
        //xlb_class<CItemIDFactory>("CItemIDFactory") .constructor<>() .destructor()
        //    .method( "CreateItemID", &CItemIDFactory::CreateItemID )
        //    .method( "GetDataFromIDList", &CItemIDFactory::GetDataFromIDList )
        //    .method( "GetDataFromIDList", &CItemIDFactory::GetDataFromIDList )
        //    .method( "GetPropertyFromIDList", &CItemIDFactory::GetPropertyFromIDList )
        //    .method( "GetPropertyFromIDList", &CItemIDFactory::GetPropertyFromIDList )
        //    .method( "GetPropertyFromIDList", &CItemIDFactory::GetPropertyFromIDList )
        //    .method( "GetPropertyFromIDList", &CItemIDFactory::GetPropertyFromIDList )
        //    .method( "GetPropertyStorage", &CItemIDFactory::GetPropertyStorage )
        //    .method( "GetPropertyStorageFromIDList", &CItemIDFactory::GetPropertyStorageFromIDList )
        //    .method( "IsDelegateFolder", &CItemIDFactory::IsDelegateFolder )
        //    .method( "SetItemAlloc", &CItemIDFactory::SetItemAlloc )
        //    ,

        //_BROWSERFRAMEOPTIONS
        xlb_const( "BFO_NONE,", BFO_NONE ),
        xlb_const( "BFO_BROWSER_PERSIST_SETTINGS,", BFO_BROWSER_PERSIST_SETTINGS ),
        xlb_const( "BFO_RENAME_FOLDER_OPTIONS_TOINTERNET,",
                   BFO_RENAME_FOLDER_OPTIONS_TOINTERNET ),
        xlb_const( "BFO_BOTH_OPTIONS,", BFO_BOTH_OPTIONS ),
        xlb_const( "BIF_PREFER_INTERNET_SHORTCUT,", BIF_PREFER_INTERNET_SHORTCUT ),
        xlb_const( "BFO_BROWSE_NO_IN_NEW_PROCESS,", BFO_BROWSE_NO_IN_NEW_PROCESS ),
        xlb_const( "BFO_ENABLE_HYPERLINK_TRACKING,", BFO_ENABLE_HYPERLINK_TRACKING ),
        xlb_const( "BFO_USE_IE_OFFLINE_SUPPORT,", BFO_USE_IE_OFFLINE_SUPPORT ),
        xlb_const( "BFO_SUBSTITUE_INTERNET_START_PAGE,", BFO_SUBSTITUE_INTERNET_START_PAGE ),
        xlb_const( "BFO_USE_IE_LOGOBANDING,", BFO_USE_IE_LOGOBANDING ),
        xlb_const( "BFO_ADD_IE_TOCAPTIONBAR,", BFO_ADD_IE_TOCAPTIONBAR ),
        xlb_const( "BFO_USE_DIALUP_REF,", BFO_USE_DIALUP_REF ),
        xlb_const( "BFO_USE_IE_TOOLBAR,", BFO_USE_IE_TOOLBAR ),
        xlb_const( "BFO_NO_PARENT_FOLDER_SUPPORT,", BFO_NO_PARENT_FOLDER_SUPPORT ),
        xlb_const( "BFO_NO_REOPEN_NEXT_RESTART,", BFO_NO_REOPEN_NEXT_RESTART ),
        xlb_const( "BFO_GO_HOME_PAGE,", BFO_GO_HOME_PAGE ),
        xlb_const( "BFO_PREFER_IEPROCESS,", BFO_PREFER_IEPROCESS ),
        xlb_const( "BFO_SHOW_NAVIGATION_CANCELLED,", BFO_SHOW_NAVIGATION_CANCELLED ),
        xlb_const( "BFO_USE_IE_STATUSBAR,", BFO_USE_IE_STATUSBAR ),
        xlb_const( "BFO_QUERY_ALL", BFO_QUERY_ALL ),

        //_EXPCMDSTATE
        xlb_const( "ECS_ENABLED,", ECS_ENABLED ), 
        xlb_const( "ECS_DISABLED,", ECS_DISABLED ),
        xlb_const( "ECS_HIDDEN,", ECS_HIDDEN ), 
        xlb_const( "ECS_CHECKBOX,", ECS_CHECKBOX ),
        xlb_const( "ECS_CHECKED,", ECS_CHECKED ),
        xlb_const( "ECS_RADIOCHECK", ECS_RADIOCHECK ),

        //_EXPLORERPANESTATE
        xlb_const( "EPS_DONTCARE,", EPS_DONTCARE ),
        xlb_const( "EPS_DEFAULT_ON,", EPS_DEFAULT_ON ),
        xlb_const( "EPS_DEFAULT_OFF,", EPS_DEFAULT_OFF ),
        xlb_const( "EPS_STATEMASK,", EPS_STATEMASK ),
        xlb_const( "EPS_INITIALSTATE,", EPS_INITIALSTATE ),
        xlb_const( "EPS_FORCE", EPS_FORCE ),

        //_FILEOPENDIALOGOPTIONS
        xlb_const( "FOS_OVERWRITEPROMPT,", FOS_OVERWRITEPROMPT ),
        xlb_const( "FOS_STRICTFILETYPES,", FOS_STRICTFILETYPES ),
        xlb_const( "FOS_NOCHANGEDIR,", FOS_NOCHANGEDIR ),
        xlb_const( "FOS_PICKFOLDERS,", FOS_PICKFOLDERS ),
        xlb_const( "FOS_FORCEFILESYSTEM,", FOS_FORCEFILESYSTEM ),
        xlb_const( "FOS_ALLNONSTORAGEITEMS,", FOS_ALLNONSTORAGEITEMS ),
        xlb_const( "FOS_NOVALIDATE,", FOS_NOVALIDATE ),
        xlb_const( "FOS_ALLOWMULTISELECT,", FOS_ALLOWMULTISELECT ),
        xlb_const( "FOS_PATHMUSTEXIST,", FOS_PATHMUSTEXIST ),
        xlb_const( "FOS_FILEMUSTEXIST,", FOS_FILEMUSTEXIST ),
        xlb_const( "FOS_CREATEPROMPT,", FOS_CREATEPROMPT ),
        xlb_const( "FOS_SHAREAWARE,", FOS_SHAREAWARE ),
        xlb_const( "FOS_NOREADONLYRETURN,", FOS_NOREADONLYRETURN ),
        xlb_const( "FOS_NOTESTFILECREATE,", FOS_NOTESTFILECREATE ),
        xlb_const( "FOS_HIDEMRUPLACES,", FOS_HIDEMRUPLACES ),
        xlb_const( "FOS_HIDEPINNEDPLACES,", FOS_HIDEPINNEDPLACES ),
        xlb_const( "FOS_NODEREFERENCELINKS,", FOS_NODEREFERENCELINKS ),
        xlb_const( "FOS_OKBUTTONNEEDSINTERACTION,", FOS_OKBUTTONNEEDSINTERACTION ),
        xlb_const( "FOS_DONTADDTORECENT,", FOS_DONTADDTORECENT ),
        xlb_const( "FOS_FORCESHOWHIDDEN,", FOS_FORCESHOWHIDDEN ),
        xlb_const( "FOS_DEFAULTNOMINIMODE,", FOS_DEFAULTNOMINIMODE ),
        xlb_const( "FOS_FORCEPREVIEWPANEON,", FOS_FORCEPREVIEWPANEON ),
        xlb_const( "FOS_SUPPORTSTREAMABLEITEMS", FOS_SUPPORTSTREAMABLEITEMS ),

        //_KF_DEFINITION_FLAGS
        xlb_const( "KFDF_LOCAL_REDIRECT_ONLY,", KFDF_LOCAL_REDIRECT_ONLY ),
        xlb_const( "KFDF_ROAMABLE,", KFDF_ROAMABLE ),
        xlb_const( "KFDF_PRECREATE,", KFDF_PRECREATE ),
        xlb_const( "KFDF_STREAM,", KFDF_STREAM ),
        xlb_const( "KFDF_PUBLISHEXPANDEDPATH,", KFDF_PUBLISHEXPANDEDPATH ),
        xlb_const( "KFDF_NO_REDIRECT_UI", KFDF_NO_REDIRECT_UI ),

        //_KF_REDIRECT_FLAGS
        xlb_const( "KF_REDIRECT_USER_EXCLUSIVE,", KF_REDIRECT_USER_EXCLUSIVE ),
        xlb_const( "KF_REDIRECT_COPY_SOURCE_DACL,", KF_REDIRECT_COPY_SOURCE_DACL ),
        xlb_const( "KF_REDIRECT_OWNER_USER,", KF_REDIRECT_OWNER_USER ),
        xlb_const( "KF_REDIRECT_SET_OWNER_EXPLICIT,", KF_REDIRECT_SET_OWNER_EXPLICIT ),
        xlb_const( "KF_REDIRECT_CHECK_ONLY,", KF_REDIRECT_CHECK_ONLY ),
        xlb_const( "KF_REDIRECT_WITH_UI,", KF_REDIRECT_WITH_UI ),
        xlb_const( "KF_REDIRECT_UNPIN,", KF_REDIRECT_UNPIN ),
        xlb_const( "KF_REDIRECT_PIN,", KF_REDIRECT_PIN ),
        xlb_const( "KF_REDIRECT_COPY_CONTENTS,", KF_REDIRECT_COPY_CONTENTS ),
        xlb_const( "KF_REDIRECT_DEL_SOURCE_CONTENTS,", KF_REDIRECT_DEL_SOURCE_CONTENTS ),
        xlb_const( "KF_REDIRECT_EXCLUDE_ALL_KNOWN_SUBFOLDERS",
                   KF_REDIRECT_EXCLUDE_ALL_KNOWN_SUBFOLDERS ),

        //_KF_REDIRECTION_CAPABILITIES
        xlb_const( "KF_REDIRECTION_CAPABILITIES_ALLOW_ALL,",
                   KF_REDIRECTION_CAPABILITIES_ALLOW_ALL ),
        xlb_const( "KF_REDIRECTION_CAPABILITIES_REDIRECTABLE,",
                   KF_REDIRECTION_CAPABILITIES_REDIRECTABLE ),
        xlb_const( "KF_REDIRECTION_CAPABILITIES_DENY_ALL,",
                   KF_REDIRECTION_CAPABILITIES_DENY_ALL ),
        xlb_const( "KF_REDIRECTION_CAPABILITIES_DENY_POLICY_REDIRECTED,",
                   KF_REDIRECTION_CAPABILITIES_DENY_POLICY_REDIRECTED ),
        xlb_const( "KF_REDIRECTION_CAPABILITIES_DENY_POLICY,",
                   KF_REDIRECTION_CAPABILITIES_DENY_POLICY ),
        xlb_const( "KF_REDIRECTION_CAPABILITIES_DENY_PERMISSIONS",
                   KF_REDIRECTION_CAPABILITIES_DENY_PERMISSIONS ),

        //_NSTCITEMSTATE
        xlb_const( "NSTCIS_NONE,", NSTCIS_NONE ),
        xlb_const( "NSTCIS_SELECTED,", NSTCIS_SELECTED ),
        xlb_const( "NSTCIS_EXPANDED,", NSTCIS_EXPANDED ),
        xlb_const( "NSTCIS_BOLD,", NSTCIS_BOLD ),
        xlb_const( "NSTCIS_DISABLED,", NSTCIS_DISABLED ),
        xlb_const( "NSTCIS_SELECTEDNOEXPAND", NSTCIS_SELECTEDNOEXPAND ),

        //_NSTCSTYLE
        xlb_const( "NSTCS_HASEXPANDOS,", NSTCS_HASEXPANDOS ),
        xlb_const( "NSTCS_HASLINES,", NSTCS_HASLINES ),
        xlb_const( "NSTCS_SINGLECLICKEXPAND,", NSTCS_SINGLECLICKEXPAND ),
        xlb_const( "NSTCS_FULLROWSELECT,", NSTCS_FULLROWSELECT ),
        xlb_const( "NSTCS_SPRINGEXPAND,", NSTCS_SPRINGEXPAND ),
        xlb_const( "NSTCS_HORIZONTALSCROLL,", NSTCS_HORIZONTALSCROLL ),
        xlb_const( "NSTCS_ROOTHASEXPANDO,", NSTCS_ROOTHASEXPANDO ),
        xlb_const( "NSTCS_SHOWSELECTIONALWAYS,", NSTCS_SHOWSELECTIONALWAYS ),
        xlb_const( "NSTCS_NOINFOTIP,", NSTCS_NOINFOTIP ),
        xlb_const( "NSTCS_EVENHEIGHT,", NSTCS_EVENHEIGHT ),
        xlb_const( "NSTCS_NOREPLACEOPEN,", NSTCS_NOREPLACEOPEN ),
        xlb_const( "NSTCS_DISABLEDRAGDROP,", NSTCS_DISABLEDRAGDROP ),
        xlb_const( "NSTCS_NOORDERSTREAM,", NSTCS_NOORDERSTREAM ),
        xlb_const( "NSTCS_RICHTOOLTIP,", NSTCS_RICHTOOLTIP ),
        xlb_const( "NSTCS_BORDER,", NSTCS_BORDER ),
        xlb_const( "NSTCS_NOEDITLABELS,", NSTCS_NOEDITLABELS ),
        xlb_const( "NSTCS_TABSTOP,", NSTCS_TABSTOP ),
        xlb_const( "NSTCS_FAVORITESMODE,", NSTCS_FAVORITESMODE ),
        xlb_const( "NSTCS_AUTOHSCROLL,", NSTCS_AUTOHSCROLL ),
        xlb_const( "NSTCS_FADEINOUTEXPANDOS,", NSTCS_FADEINOUTEXPANDOS ),
        xlb_const( "NSTCS_EMPTYTEXT,", NSTCS_EMPTYTEXT ),
        xlb_const( "NSTCS_CHECKBOXES,", NSTCS_CHECKBOXES ),
        xlb_const( "NSTCS_PARTIALCHECKBOXES,", NSTCS_PARTIALCHECKBOXES ),
        xlb_const( "NSTCS_EXCLUSIONCHECKBOXES,", NSTCS_EXCLUSIONCHECKBOXES ),
        xlb_const( "NSTCS_DIMMEDCHECKBOXES,", NSTCS_DIMMEDCHECKBOXES ),
        xlb_const( "NSTCS_NOINDENTCHECKS,", NSTCS_NOINDENTCHECKS ),
        xlb_const( "NSTCS_ALLOWJUNCTIONS,", NSTCS_ALLOWJUNCTIONS ),
        xlb_const( "NSTCS_SHOWTABSBUTTON,", NSTCS_SHOWTABSBUTTON ),
        xlb_const( "NSTCS_SHOWDELETEBUTTON,", NSTCS_SHOWDELETEBUTTON ),
        xlb_const( "NSTCS_SHOWREFRESHBUTTON", NSTCS_SHOWREFRESHBUTTON ),

        //_SHCONTF
        xlb_const( "SHCONTF_CHECKING_FOR_CHILDREN,", SHCONTF_CHECKING_FOR_CHILDREN ),
        xlb_const( "SHCONTF_FOLDERS,", SHCONTF_FOLDERS ),
        xlb_const( "SHCONTF_NONFOLDERS,", SHCONTF_NONFOLDERS ),
        xlb_const( "SHCONTF_INCLUDEHIDDEN,", SHCONTF_INCLUDEHIDDEN ),
        xlb_const( "SHCONTF_INIT_ON_FIRST_NEXT,", SHCONTF_INIT_ON_FIRST_NEXT ),
        xlb_const( "SHCONTF_NETPRINTERSRCH,", SHCONTF_NETPRINTERSRCH ),
        xlb_const( "SHCONTF_SHAREABLE,", SHCONTF_SHAREABLE ),
        xlb_const( "SHCONTF_STORAGE,", SHCONTF_STORAGE ),
        xlb_const( "SHCONTF_NAVIGATION_ENUM,", SHCONTF_NAVIGATION_ENUM ),
        xlb_const( "SHCONTF_FASTITEMS,", SHCONTF_FASTITEMS ),
        xlb_const( "SHCONTF_FLATLIST,", SHCONTF_FLATLIST ),
        xlb_const( "SHCONTF_ENABLE_ASYNC,", SHCONTF_ENABLE_ASYNC ),
        xlb_const( "SHCONTF_INCLUDESUPERHIDDEN", SHCONTF_INCLUDESUPERHIDDEN ),

        //_SHGDNF
        xlb_const( "SHGDN_NORMAL,", SHGDN_NORMAL ),
        xlb_const( "SHGDN_INFOLDER,", SHGDN_INFOLDER ),
        xlb_const( "SHGDN_FOREDITING,", SHGDN_FOREDITING ),
        xlb_const( "SHGDN_FORADDRESSBAR,", SHGDN_FORADDRESSBAR ),
        xlb_const( "SHGDN_FORPARSING", SHGDN_FORPARSING ),

        //_SICHINTF
        xlb_const( "SICHINT_DISPLAY,", SICHINT_DISPLAY ),
        xlb_const( "SICHINT_ALLFIELDS,", SICHINT_ALLFIELDS ),
        xlb_const( "SICHINT_CANONICAL,", SICHINT_CANONICAL ),
        xlb_const( "SICHINT_TEST_FILESYSPATH_IF_NOT_EQUAL",
                   SICHINT_TEST_FILESYSPATH_IF_NOT_EQUAL ),

        //_SPBEGINF
        xlb_const( "SPBEGINF_NORMAL,", SPBEGINF_NORMAL ),
        xlb_const( "SPBEGINF_AUTOTIME,", SPBEGINF_AUTOTIME ),
        xlb_const( "SPBEGINF_NOPROGRESSBAR,", SPBEGINF_NOPROGRESSBAR ),
        xlb_const( "SPBEGINF_MARQUEEPROGRESS,", SPBEGINF_MARQUEEPROGRESS ),
        xlb_const( "SPBEGINF_NOCANCELBUTTON", SPBEGINF_NOCANCELBUTTON ),

        //_SVGIO
        xlb_const( "SVGIO_BACKGROUND,", SVGIO_BACKGROUND ),
        xlb_const( "SVGIO_SELECTION,", SVGIO_SELECTION ),
        xlb_const( "SVGIO_ALLVIEW,", SVGIO_ALLVIEW ),
        xlb_const( "SVGIO_CHECKED,", SVGIO_CHECKED ),
        xlb_const( "SVGIO_TYPE_MASK,", SVGIO_TYPE_MASK ),
        xlb_const( "SVGIO_FLAG_VIEWORDER", SVGIO_FLAG_VIEWORDER ),

        //_SVSIF
        xlb_const( "SVSI_DESELECT,", SVSI_DESELECT ),
        xlb_const( "SVSI_SELECT,", SVSI_SELECT ), 
        xlb_const( "SVSI_EDIT,", SVSI_EDIT ),
        xlb_const( "SVSI_DESELECTOTHERS,", SVSI_DESELECTOTHERS ),
        xlb_const( "SVSI_ENSUREVISIBLE,", SVSI_ENSUREVISIBLE ),
        xlb_const( "SVSI_FOCUSED,", SVSI_FOCUSED ),
        xlb_const( "SVSI_TRANSLATEPT,", SVSI_TRANSLATEPT ),
        xlb_const( "SVSI_SELECTIONMARK,", SVSI_SELECTIONMARK ),
        xlb_const( "SVSI_POSITIONITEM,", SVSI_POSITIONITEM ),
        xlb_const( "SVSI_CHECK,", SVSI_CHECK ), 
        xlb_const( "SVSI_CHECK2,", SVSI_CHECK2 ),
        xlb_const( "SVSI_KEYBOARDSELECT,", SVSI_KEYBOARDSELECT ),
        xlb_const( "SVSI_NOTAKEFOCUS", SVSI_NOTAKEFOCUS ),

        //_TRANSFER_SOURCE_FLAGS
        xlb_const( "TSF_NORMAL,", TSF_NORMAL ),
        xlb_const( "TSF_FAIL_EXIST,", TSF_FAIL_EXIST ),
        xlb_const( "TSF_RENAME_EXIST,", TSF_RENAME_EXIST ),
        xlb_const( "TSF_OVERWRITE_EXIST,", TSF_OVERWRITE_EXIST ),
        xlb_const( "TSF_ALLOW_DECRYPTION,", TSF_ALLOW_DECRYPTION ),
        xlb_const( "TSF_NO_SECURITY,", TSF_NO_SECURITY ),
        xlb_const( "TSF_COPY_CREATION_TIME,", TSF_COPY_CREATION_TIME ),
        xlb_const( "TSF_COPY_WRITE_TIME,", TSF_COPY_WRITE_TIME ),
        xlb_const( "TSF_USE_FULL_ACCESS,", TSF_USE_FULL_ACCESS ),
        xlb_const( "TSF_DELETE_RECYCLE_IF_POSSIBLE,", TSF_DELETE_RECYCLE_IF_POSSIBLE ),
        xlb_const( "TSF_COPY_HARD_LINK,", TSF_COPY_HARD_LINK ),
        xlb_const( "TSF_COPY_LOCALIZED_NAME,", TSF_COPY_LOCALIZED_NAME ),
        xlb_const( "TSF_MOVE_AS_COPY_DELETE,", TSF_MOVE_AS_COPY_DELETE ),
        xlb_const( "TSF_SUSPEND_SHELLEVENTS", TSF_SUSPEND_SHELLEVENTS ),

        //_tagAppActionFlags
        xlb_const( "APPACTION_INSTALL,", APPACTION_INSTALL ),
        xlb_const( "APPACTION_UNINSTALL,", APPACTION_UNINSTALL ),
        xlb_const( "APPACTION_MODIFY,", APPACTION_MODIFY ),
        xlb_const( "APPACTION_REPAIR,", APPACTION_REPAIR ),
        xlb_const( "APPACTION_UPGRADE,", APPACTION_UPGRADE ),
        xlb_const( "APPACTION_CANGETSIZE,", APPACTION_CANGETSIZE ),
        xlb_const( "APPACTION_MODIFYREMOVE,", APPACTION_MODIFYREMOVE ),
        xlb_const( "APPACTION_ADDLATER,", APPACTION_ADDLATER ),
        xlb_const( "APPACTION_UNSCHEDULE", APPACTION_UNSCHEDULE ),

        //_tagAppInfoFlags
        xlb_const( "AIM_DISPLAYNAME,", AIM_DISPLAYNAME ),
        xlb_const( "AIM_VERSION,", AIM_VERSION ),
        xlb_const( "AIM_PUBLISHER,", AIM_PUBLISHER ),
        xlb_const( "AIM_PRODUCTID,", AIM_PRODUCTID ),
        xlb_const( "AIM_REGISTEREDOWNER,", AIM_REGISTEREDOWNER ),
        xlb_const( "AIM_REGISTEREDCOMPANY,", AIM_REGISTEREDCOMPANY ),
        xlb_const( "AIM_LANGUAGE,", AIM_LANGUAGE ),
        xlb_const( "AIM_SUPPORTURL,", AIM_SUPPORTURL ),
        xlb_const( "AIM_SUPPORTTELEPHONE,", AIM_SUPPORTTELEPHONE ),
        xlb_const( "AIM_HELPLINK,", AIM_HELPLINK ),
        xlb_const( "AIM_INSTALLLOCATION,", AIM_INSTALLLOCATION ),
        xlb_const( "AIM_INSTALLSOURCE,", AIM_INSTALLSOURCE ),
        xlb_const( "AIM_INSTALLDATE,", AIM_INSTALLDATE ),
        xlb_const( "AIM_CONTACT,", AIM_CONTACT ), 
        xlb_const( "AIM_COMMENTS,", AIM_COMMENTS ),
        xlb_const( "AIM_IMAGE,", AIM_IMAGE ), 
        xlb_const( "AIM_READMEURL,", AIM_READMEURL ),
        xlb_const( "AIM_UPDATEINFOURL", AIM_UPDATEINFOURL ),

        // APPLICATION_VIEW_ORIENTATION
        xlb_const( "AVO_LANDSCAPE,", AVO_LANDSCAPE ),
        xlb_const( "AVO_PORTRAIT", AVO_PORTRAIT ),

        // APPLICATION_VIEW_SIZE_PREFERENCE
        xlb_const( "AVSP_DEFAULT,", AVSP_DEFAULT ),
        xlb_const( "AVSP_USE_LESS,", AVSP_USE_LESS ),
        xlb_const( "AVSP_USE_HALF,", AVSP_USE_HALF ),
        xlb_const( "AVSP_USE_MORE,", AVSP_USE_MORE ),
        xlb_const( "AVSP_USE_MINIMUM,", AVSP_USE_MINIMUM ),
        xlb_const( "AVSP_USE_NONE,", AVSP_USE_NONE ), 
        xlb_const( "AVSP_CUSTOM", AVSP_CUSTOM ),

        // APPLICATION_VIEW_STATE
        xlb_const( "AVS_FULLSCREEN_LANDSCAPE,", AVS_FULLSCREEN_LANDSCAPE ),
        xlb_const( "AVS_FILLED,", AVS_FILLED ), 
        xlb_const( "AVS_SNAPPED,", AVS_SNAPPED ),
        xlb_const( "AVS_FULLSCREEN_PORTRAIT", AVS_FULLSCREEN_PORTRAIT ),

        // ASSOCDATA
        xlb_const( "ASSOCDATA_MSIDESCRIPTOR,", ASSOCDATA_MSIDESCRIPTOR ),
        xlb_const( "ASSOCDATA_NOACTIVATEHANDLER,", ASSOCDATA_NOACTIVATEHANDLER ),
        xlb_const( "ASSOCDATA_UNUSED1,", ASSOCDATA_UNUSED1 ),
        xlb_const( "ASSOCDATA_HASPERUSERASSOC,", ASSOCDATA_HASPERUSERASSOC ),
        xlb_const( "ASSOCDATA_EDITFLAGS,", ASSOCDATA_EDITFLAGS ),
        xlb_const( "ASSOCDATA_VALUE,", ASSOCDATA_VALUE ),
        xlb_const( "ASSOCDATA_MAX", ASSOCDATA_MAX ),

        // ASSOCIATIONLEVEL
        xlb_const( "AL_MACHINE,", AL_MACHINE ), 
        xlb_const( "AL_EFFECTIVE,", AL_EFFECTIVE ),
        xlb_const( "AL_USER", AL_USER ),

        // ASSOCIATIONTYPE
        xlb_const( "AT_FILEEXTENSION,", AT_FILEEXTENSION ),
        xlb_const( "AT_URLPROTOCOL,", AT_URLPROTOCOL ),
        xlb_const( "AT_STARTMENUCLIENT,", AT_STARTMENUCLIENT ),
        xlb_const( "AT_MIMETYPE", AT_MIMETYPE ),

        // ASSOCKEY
        xlb_const( "ASSOCKEY_SHELLEXECCLASS,", ASSOCKEY_SHELLEXECCLASS ),
        xlb_const( "ASSOCKEY_APP,", ASSOCKEY_APP ),
        xlb_const( "ASSOCKEY_CLASS,", ASSOCKEY_CLASS ),
        xlb_const( "ASSOCKEY_BASECLASS,", ASSOCKEY_BASECLASS ),
        xlb_const( "ASSOCKEY_MAX", ASSOCKEY_MAX ),

        // ASSOCSTR
        xlb_const( "ASSOCSTR_COMMAND,", ASSOCSTR_COMMAND ),
        xlb_const( "ASSOCSTR_EXECUTABLE,", ASSOCSTR_EXECUTABLE ),
        xlb_const( "ASSOCSTR_FRIENDLYDOCNAME,", ASSOCSTR_FRIENDLYDOCNAME ),
        xlb_const( "ASSOCSTR_FRIENDLYAPPNAME,", ASSOCSTR_FRIENDLYAPPNAME ),
        xlb_const( "ASSOCSTR_NOOPEN,", ASSOCSTR_NOOPEN ),
        xlb_const( "ASSOCSTR_SHELLNEWVALUE,", ASSOCSTR_SHELLNEWVALUE ),
        xlb_const( "ASSOCSTR_DDECOMMAND,", ASSOCSTR_DDECOMMAND ),
        xlb_const( "ASSOCSTR_DDEIFEXEC,", ASSOCSTR_DDEIFEXEC ),
        xlb_const( "ASSOCSTR_DDEAPPLICATION,", ASSOCSTR_DDEAPPLICATION ),
        xlb_const( "ASSOCSTR_DDETOPIC,", ASSOCSTR_DDETOPIC ),
        xlb_const( "ASSOCSTR_INFOTIP,", ASSOCSTR_INFOTIP ),
        xlb_const( "ASSOCSTR_QUICKTIP,", ASSOCSTR_QUICKTIP ),
        xlb_const( "ASSOCSTR_TILEINFO,", ASSOCSTR_TILEINFO ),
        xlb_const( "ASSOCSTR_CONTENTTYPE,", ASSOCSTR_CONTENTTYPE ),
        xlb_const( "ASSOCSTR_DEFAULTICON,", ASSOCSTR_DEFAULTICON ),
        xlb_const( "ASSOCSTR_SHELLEXTENSION,", ASSOCSTR_SHELLEXTENSION ),
        xlb_const( "ASSOCSTR_DROPTARGET,", ASSOCSTR_DROPTARGET ),
        xlb_const( "ASSOCSTR_DELEGATEEXECUTE,", ASSOCSTR_DELEGATEEXECUTE ),
        xlb_const( "ASSOCSTR_SUPPORTED_URI_PROTOCOLS,", ASSOCSTR_SUPPORTED_URI_PROTOCOLS ),
        xlb_const( "ASSOCSTR_PROGID,", ASSOCSTR_PROGID ),
        xlb_const( "ASSOCSTR_APPID,", ASSOCSTR_APPID ),
        xlb_const( "ASSOCSTR_APPPUBLISHER,", ASSOCSTR_APPPUBLISHER ),
        xlb_const( "ASSOCSTR_APPICONREFERENCE,", ASSOCSTR_APPICONREFERENCE ),
        xlb_const( "ASSOCSTR_MAX", ASSOCSTR_MAX ),

        // ATTACHMENT_ACTION
        xlb_const( "ATTACHMENT_ACTION_CANCEL,", ATTACHMENT_ACTION_CANCEL ),
        xlb_const( "ATTACHMENT_ACTION_SAVE,", ATTACHMENT_ACTION_SAVE ),
        xlb_const( "ATTACHMENT_ACTION_EXEC", ATTACHMENT_ACTION_EXEC ),

        // ATTACHMENT_PROMPT
        xlb_const( "ATTACHMENT_PROMPT_NONE,", ATTACHMENT_PROMPT_NONE ),
        xlb_const( "ATTACHMENT_PROMPT_SAVE,", ATTACHMENT_PROMPT_SAVE ),
        xlb_const( "ATTACHMENT_PROMPT_EXEC,", ATTACHMENT_PROMPT_EXEC ),
        xlb_const( "ATTACHMENT_PROMPT_EXEC_OR_SAVE", ATTACHMENT_PROMPT_EXEC_OR_SAVE ),

        //_tagAUTOCOMPLETELISTOPTIONS
        xlb_const( "ACLO_NONE,", ACLO_NONE ),
        xlb_const( "ACLO_CURRENTDIR,", ACLO_CURRENTDIR ),
        xlb_const( "ACLO_MYCOMPUTER,", ACLO_MYCOMPUTER ),
        xlb_const( "ACLO_DESKTOP,", ACLO_DESKTOP ),
        xlb_const( "ACLO_FAVORITES,", ACLO_FAVORITES ),
        xlb_const( "ACLO_FILESYSONLY,", ACLO_FILESYSONLY ),
        xlb_const( "ACLO_FILESYSDIRS,", ACLO_FILESYSDIRS ),
        xlb_const( "ACLO_VIRTUALNAMESPACE", ACLO_VIRTUALNAMESPACE ),

        //_tagAUTOCOMPLETEOPTIONS
        xlb_const( "ACO_NONE,", ACO_NONE ), 
        xlb_const( "ACO_AUTOSUGGEST,", ACO_AUTOSUGGEST ),
        xlb_const( "ACO_AUTOAPPEND,", ACO_AUTOAPPEND ),
        xlb_const( "ACO_SEARCH,", ACO_SEARCH ),
        xlb_const( "ACO_FILTERPREFIXES,", ACO_FILTERPREFIXES ),
        xlb_const( "ACO_USETAB,", ACO_USETAB ),
        xlb_const( "ACO_UPDOWNKEYDROPSLIST,", ACO_UPDOWNKEYDROPSLIST ),
        xlb_const( "ACO_RTLREADING,", ACO_RTLREADING ),
        xlb_const( "ACO_WORD_FILTER,", ACO_WORD_FILTER ),
        xlb_const( "ACO_NOPREFIXFILTERING", ACO_NOPREFIXFILTERING ),

        // tagBNSTATE
        xlb_const( "BNS_NORMAL,", BNS_NORMAL ),
        xlb_const( "BNS_BEGIN_NAVIGATE,", BNS_BEGIN_NAVIGATE ),
        xlb_const( "BNS_NAVIGATE", BNS_NAVIGATE ),

        // CATEGORYINFO_FLAGS
        xlb_const( "CATINFO_NORMAL,", CATINFO_NORMAL ),
        xlb_const( "CATINFO_COLLAPSED,", CATINFO_COLLAPSED ),
        xlb_const( "CATINFO_HIDDEN,", CATINFO_HIDDEN ),
        xlb_const( "CATINFO_EXPANDED,", CATINFO_EXPANDED ),
        xlb_const( "CATINFO_NOHEADER,", CATINFO_NOHEADER ),
        xlb_const( "CATINFO_NOTCOLLAPSIBLE,", CATINFO_NOTCOLLAPSIBLE ),
        xlb_const( "CATINFO_NOHEADERCOUNT,", CATINFO_NOHEADERCOUNT ),
        xlb_const( "CATINFO_SUBSETTED,", CATINFO_SUBSETTED ),
        xlb_const( "CATINFO_SEPARATE_IMAGES,", CATINFO_SEPARATE_IMAGES ),
        xlb_const( "CATINFO_SHOWEMPTY", CATINFO_SHOWEMPTY ),

        // CATSORT_FLAGS
        xlb_const( "CATSORT_DEFAULT,", CATSORT_DEFAULT ),
        xlb_const( "CATSORT_NAME", CATSORT_NAME ),

        // CM_ENUM_FLAGS
        xlb_const( "CM_ENUM_ALL,", CM_ENUM_ALL ),
        xlb_const( "CM_ENUM_VISIBLE", CM_ENUM_VISIBLE ),

        // CM_MASK
        xlb_const( "CM_MASK_WIDTH,", CM_MASK_WIDTH ),
        xlb_const( "CM_MASK_DEFAULTWIDTH,", CM_MASK_DEFAULTWIDTH ),
        xlb_const( "CM_MASK_IDEALWIDTH,", CM_MASK_IDEALWIDTH ),
        xlb_const( "CM_MASK_NAME,", CM_MASK_NAME ),
        xlb_const( "CM_MASK_STATE", CM_MASK_STATE ),

        // CM_SET_WIDTH_VALUE
        xlb_const( "CM_WIDTH_USEDEFAULT,", CM_WIDTH_USEDEFAULT ),
        xlb_const( "CM_WIDTH_AUTOSIZE", CM_WIDTH_AUTOSIZE ),

        // CM_STATE
        xlb_const( "CM_STATE_NONE,", CM_STATE_NONE ),
        xlb_const( "CM_STATE_VISIBLE,", CM_STATE_VISIBLE ),
        xlb_const( "CM_STATE_FIXEDWIDTH,", CM_STATE_FIXEDWIDTH ),
        xlb_const( "CM_STATE_NOSORTBYFOLDERNESS,", CM_STATE_NOSORTBYFOLDERNESS ),
        xlb_const( "CM_STATE_ALWAYSVISIBLE", CM_STATE_ALWAYSVISIBLE ),

        // CREDENTIAL_PROVIDER_ACCOUNT_OPTIONS
        xlb_const( "CPAO_NONE,", CPAO_NONE ),
        xlb_const( "CPAO_EMPTY_LOCAL,", CPAO_EMPTY_LOCAL ),
        xlb_const( "CPAO_EMPTY_CONNECTED", CPAO_EMPTY_CONNECTED ),

        // CREDENTIAL_PROVIDER_CREDENTIAL_FIELD_OPTIONS
        xlb_const( "CPCFO_NONE,", CPCFO_NONE ),
        xlb_const( "CPCFO_ENABLE_PASSWORD_REVEAL,", CPCFO_ENABLE_PASSWORD_REVEAL ),
        xlb_const( "CPCFO_IS_EMAIL_ADDRESS,", CPCFO_IS_EMAIL_ADDRESS ),
        xlb_const( "CPCFO_ENABLE_TOUCH_KEYBOARD_AUTO_INVOKE,",
                   CPCFO_ENABLE_TOUCH_KEYBOARD_AUTO_INVOKE ),
        xlb_const( "CPCFO_NUMBERS_ONLY,", CPCFO_NUMBERS_ONLY ),
        xlb_const( "CPCFO_SHOW_ENGLISH_KEYBOARD", CPCFO_SHOW_ENGLISH_KEYBOARD ),

        //_CREDENTIAL_PROVIDER_FIELD_INTERACTIVE_STATE
        xlb_const( "CPFIS_NONE,", CPFIS_NONE ),
        xlb_const( "CPFIS_READONLY,", CPFIS_READONLY ),
        xlb_const( "CPFIS_DISABLED,", CPFIS_DISABLED ),
        xlb_const( "CPFIS_FOCUSED", CPFIS_FOCUSED ),

        //_CREDENTIAL_PROVIDER_FIELD_STATE
        xlb_const( "CPFS_HIDDEN,", CPFS_HIDDEN ),
        xlb_const( "CPFS_DISPLAY_IN_SELECTED_TILE,", CPFS_DISPLAY_IN_SELECTED_TILE ),
        xlb_const( "CPFS_DISPLAY_IN_DESELECTED_TILE,", CPFS_DISPLAY_IN_DESELECTED_TILE ),
        xlb_const( "CPFS_DISPLAY_IN_BOTH", CPFS_DISPLAY_IN_BOTH ),

        //_CREDENTIAL_PROVIDER_FIELD_TYPE
        xlb_const( "CPFT_INVALID,", CPFT_INVALID ),
        xlb_const( "CPFT_LARGE_TEXT,", CPFT_LARGE_TEXT ),
        xlb_const( "CPFT_SMALL_TEXT,", CPFT_SMALL_TEXT ),
        xlb_const( "CPFT_COMMAND_LINK,", CPFT_COMMAND_LINK ),
        xlb_const( "CPFT_EDIT_TEXT,", CPFT_EDIT_TEXT ),
        xlb_const( "CPFT_PASSWORD_TEXT,", CPFT_PASSWORD_TEXT ),
        xlb_const( "CPFT_TILE_IMAGE,", CPFT_TILE_IMAGE ),
        xlb_const( "CPFT_CHECKBOX,", CPFT_CHECKBOX ),
        xlb_const( "CPFT_COMBOBOX,", CPFT_COMBOBOX ),
        xlb_const( "CPFT_SUBMIT_BUTTON", CPFT_SUBMIT_BUTTON ),

        //_CREDENTIAL_PROVIDER_GET_SERIALIZATION_RESPONSE
        xlb_const( "CPGSR_NO_CREDENTIAL_NOT_FINISHED,", CPGSR_NO_CREDENTIAL_NOT_FINISHED ),
        xlb_const( "CPGSR_NO_CREDENTIAL_FINISHED,", CPGSR_NO_CREDENTIAL_FINISHED ),
        xlb_const( "CPGSR_RETURN_CREDENTIAL_FINISHED,", CPGSR_RETURN_CREDENTIAL_FINISHED ),
        xlb_const( "CPGSR_RETURN_NO_CREDENTIAL_FINISHED",
                   CPGSR_RETURN_NO_CREDENTIAL_FINISHED ),

        //_CREDENTIAL_PROVIDER_STATUS_ICON
        xlb_const( "CPSI_NONE,", CPSI_NONE ), 
        xlb_const( "CPSI_ERROR,", CPSI_ERROR ),
        xlb_const( "CPSI_WARNING,", CPSI_WARNING ), 
        xlb_const( "CPSI_SUCCESS", CPSI_SUCCESS ),

        //_CREDENTIAL_PROVIDER_USAGE_SCENARIO
        xlb_const( "CPUS_INVALID,", CPUS_INVALID ), 
        xlb_const( "CPUS_LOGON,", CPUS_LOGON ),
        xlb_const( "CPUS_UNLOCK_WORKSTATION,", CPUS_UNLOCK_WORKSTATION ),
        xlb_const( "CPUS_CHANGE_PASSWORD,", CPUS_CHANGE_PASSWORD ),
        xlb_const( "CPUS_CREDUI,", CPUS_CREDUI ), 
        xlb_const( "CPUS_PLAP", CPUS_PLAP ),

        // DATAOBJ_GET_ITEM_FLAGS
        xlb_const( "DOGIF_DEFAULT,", DOGIF_DEFAULT ),
        xlb_const( "DOGIF_TRAVERSE_LINK,", DOGIF_TRAVERSE_LINK ),
        xlb_const( "DOGIF_NO_HDROP,", DOGIF_NO_HDROP ),
        xlb_const( "DOGIF_NO_URL,", DOGIF_NO_URL ),
        xlb_const( "DOGIF_ONLY_IF_ONE", DOGIF_ONLY_IF_ONE ),

        // DEF_SHARE_ID
        xlb_const( "DEFSHAREID_USERS,", DEFSHAREID_USERS ),
        xlb_const( "DEFSHAREID_PUBLIC", DEFSHAREID_PUBLIC ),

        // DEFAULT_FOLDER_MENU_RESTRICTIONS
        xlb_const( "DFMR_DEFAULT,", DFMR_DEFAULT ),
        xlb_const( "DFMR_NO_STATIC_VERBS,", DFMR_NO_STATIC_VERBS ),
        xlb_const( "DFMR_STATIC_VERBS_ONLY,", DFMR_STATIC_VERBS_ONLY ),
        xlb_const( "DFMR_NO_RESOURCE_VERBS,", DFMR_NO_RESOURCE_VERBS ),
        xlb_const( "DFMR_OPTIN_HANDLERS_ONLY,", DFMR_OPTIN_HANDLERS_ONLY ),
        xlb_const( "DFMR_RESOURCE_AND_FOLDER_VERBS_ONLY,",
                   DFMR_RESOURCE_AND_FOLDER_VERBS_ONLY ),
        xlb_const( "DFMR_USE_SPECIFIED_HANDLERS,", DFMR_USE_SPECIFIED_HANDLERS ),
        xlb_const( "DFMR_USE_SPECIFIED_VERBS,", DFMR_USE_SPECIFIED_VERBS ),
        xlb_const( "DFMR_NO_ASYNC_VERBS,", DFMR_NO_ASYNC_VERBS ),
        xlb_const( "DFMR_NO_NATIVECPU_VERBS", DFMR_NO_NATIVECPU_VERBS ),

        // DEFAULTSAVEFOLDERTYPE
        xlb_const( "DSFT_DETECT,", DSFT_DETECT ), 
        xlb_const( "DSFT_PRIVATE,", DSFT_PRIVATE ),
        xlb_const( "DSFT_PUBLIC", DSFT_PUBLIC ),

        // DESKTOP_WALLPAPER_POSITION
        xlb_const( "DWPOS_CENTER,", DWPOS_CENTER ), 
        xlb_const( "DWPOS_TILE,", DWPOS_TILE ),
        xlb_const( "DWPOS_STRETCH,", DWPOS_STRETCH ), 
        xlb_const( "DWPOS_FIT,", DWPOS_FIT ),
        xlb_const( "DWPOS_FILL,", DWPOS_FILL ), 
        xlb_const( "DWPOS_SPAN", DWPOS_SPAN ),

        // DEVICE_SCALE_FACTOR
        xlb_const( "DEVICE_SCALE_FACTOR_INVALID,", DEVICE_SCALE_FACTOR_INVALID ),
        xlb_const( "SCALE_100_PERCENT,", SCALE_100_PERCENT ),
        xlb_const( "SCALE_120_PERCENT,", SCALE_120_PERCENT ),
        xlb_const( "SCALE_125_PERCENT,", SCALE_125_PERCENT ),
        xlb_const( "SCALE_140_PERCENT,", SCALE_140_PERCENT ),
        xlb_const( "SCALE_150_PERCENT,", SCALE_150_PERCENT ),
        xlb_const( "SCALE_160_PERCENT,", SCALE_160_PERCENT ),
        xlb_const( "SCALE_175_PERCENT,", SCALE_175_PERCENT ),
        xlb_const( "SCALE_180_PERCENT,", SCALE_180_PERCENT ),
        xlb_const( "SCALE_200_PERCENT,", SCALE_200_PERCENT ),
        xlb_const( "SCALE_225_PERCENT,", SCALE_225_PERCENT ),
        xlb_const( "SCALE_250_PERCENT,", SCALE_250_PERCENT ),
        xlb_const( "SCALE_300_PERCENT,", SCALE_300_PERCENT ),
        xlb_const( "SCALE_350_PERCENT,", SCALE_350_PERCENT ),
        xlb_const( "SCALE_400_PERCENT,", SCALE_400_PERCENT ),
        xlb_const( "SCALE_450_PERCENT,", SCALE_450_PERCENT ),
        xlb_const( "SCALE_500_PERCENT", SCALE_500_PERCENT ),

        // DISPLAY_DEVICE_TYPE
        xlb_const( "DEVICE_PRIMARY,", DEVICE_PRIMARY ),
        xlb_const( "DEVICE_IMMERSIVE", DEVICE_IMMERSIVE ),

        // DROPIMAGETYPE
        xlb_const( "DROPIMAGE_INVALID,", DROPIMAGE_INVALID ),
        xlb_const( "DROPIMAGE_NONE,", DROPIMAGE_NONE ),
        xlb_const( "DROPIMAGE_COPY,", DROPIMAGE_COPY ),
        xlb_const( "DROPIMAGE_MOVE,", DROPIMAGE_MOVE ),
        xlb_const( "DROPIMAGE_LINK,", DROPIMAGE_LINK ),
        xlb_const( "DROPIMAGE_LABEL,", DROPIMAGE_LABEL ),
        xlb_const( "DROPIMAGE_WARNING,", DROPIMAGE_WARNING ),
        xlb_const( "DROPIMAGE_NOIMAGE", DROPIMAGE_NOIMAGE ),

        // EXPLORER_BROWSER_FILL_FLAGS
        xlb_const( "EBF_NONE,", EBF_NONE ),
        xlb_const( "EBF_SELECTFROMDATAOBJECT,", EBF_SELECTFROMDATAOBJECT ),
        xlb_const( "EBF_NODROPTARGET", EBF_NODROPTARGET ),

        // EXPLORER_BROWSER_OPTIONS
        xlb_const( "EBO_NONE,", EBO_NONE ),
        xlb_const( "EBO_NAVIGATEONCE,", EBO_NAVIGATEONCE ),
        xlb_const( "EBO_SHOWFRAMES,", EBO_SHOWFRAMES ),
        xlb_const( "EBO_ALWAYSNAVIGATE,", EBO_ALWAYSNAVIGATE ),
        xlb_const( "EBO_NOTRAVELLOG,", EBO_NOTRAVELLOG ),
        xlb_const( "EBO_NOWRAPPERWINDOW,", EBO_NOWRAPPERWINDOW ),
        xlb_const( "EBO_HTMLSHAREPOINTVIEW,", EBO_HTMLSHAREPOINTVIEW ),
        xlb_const( "EBO_NOBORDER,", EBO_NOBORDER ),
        xlb_const( "EBO_NOPERSISTVIEWSTATE", EBO_NOPERSISTVIEWSTATE ),

        // FDAP
        xlb_const( "FDAP_BOTTOM,", FDAP_BOTTOM ), 
        xlb_const( "FDAP_TOP", FDAP_TOP ),

        // FDE_OVERWRITE_RESPONSE
        xlb_const( "FDEOR_DEFAULT,", FDEOR_DEFAULT ),
        xlb_const( "FDEOR_ACCEPT,", FDEOR_ACCEPT ), 
        xlb_const( "FDEOR_REFUSE", FDEOR_REFUSE ),

        // FDE_SHAREVIOLATION_RESPONSE
        xlb_const( "FDESVR_DEFAULT,", FDESVR_DEFAULT ),
        xlb_const( "FDESVR_ACCEPT,", FDESVR_ACCEPT ),
        xlb_const( "FDESVR_REFUSE", FDESVR_REFUSE ),

        // FFFP_MODE
        xlb_const( "FFFP_EXACTMATCH,", FFFP_EXACTMATCH ),
        xlb_const( "FFFP_NEARESTPARENTMATCH", FFFP_NEARESTPARENTMATCH ),

        // FILE_USAGE_TYPE
        xlb_const( "FUT_PLAYING,", FUT_PLAYING ), 
        xlb_const( "FUT_EDITING,", FUT_EDITING ),
        xlb_const( "FUT_GENERIC", FUT_GENERIC ),

        // FILETYPEATTRIBUTEFLAGS
        xlb_const( "FTA_None,", FTA_None ), 
        xlb_const( "FTA_Exclude,", FTA_Exclude ),
        xlb_const( "FTA_Show,", FTA_Show ),
        xlb_const( "FTA_HasExtension,", FTA_HasExtension ),
        xlb_const( "FTA_NoEdit,", FTA_NoEdit ), 
        xlb_const( "FTA_NoRemove,", FTA_NoRemove ),
        xlb_const( "FTA_NoNewVerb,", FTA_NoNewVerb ),
        xlb_const( "FTA_NoEditVerb,", FTA_NoEditVerb ),
        xlb_const( "FTA_NoRemoveVerb,", FTA_NoRemoveVerb ),
        xlb_const( "FTA_NoEditDesc,", FTA_NoEditDesc ),
        xlb_const( "FTA_NoEditIcon,", FTA_NoEditIcon ),
        xlb_const( "FTA_NoEditDflt,", FTA_NoEditDflt ),
        xlb_const( "FTA_NoEditVerbCmd,", FTA_NoEditVerbCmd ),
        xlb_const( "FTA_NoEditVerbExe,", FTA_NoEditVerbExe ),
        xlb_const( "FTA_NoDDE,", FTA_NoDDE ), 
        xlb_const( "FTA_NoEditMIME,", FTA_NoEditMIME ),
        xlb_const( "FTA_OpenIsSafe,", FTA_OpenIsSafe ),
        xlb_const( "FTA_AlwaysUnsafe,", FTA_AlwaysUnsafe ),
        xlb_const( "FTA_NoRecentDocs,", FTA_NoRecentDocs ),
        xlb_const( "FTA_SafeForElevation,", FTA_SafeForElevation ),
        xlb_const( "FTA_AlwaysUseDirectInvoke", FTA_AlwaysUseDirectInvoke ),

        // FOLDER_ENUM_MODE
        xlb_const( "FEM_VIEWRESULT,", FEM_VIEWRESULT ),
        xlb_const( "FEM_NAVIGATION", FEM_NAVIGATION ),

        // FOLDERFLAGS
        xlb_const( "FWF_NONE,", FWF_NONE ), 
        xlb_const( "FWF_AUTOARRANGE,", FWF_AUTOARRANGE ),
        xlb_const( "FWF_ABBREVIATEDNAMES,", FWF_ABBREVIATEDNAMES ),
        xlb_const( "FWF_SNAPTOGRID,", FWF_SNAPTOGRID ),
        xlb_const( "FWF_OWNERDATA,", FWF_OWNERDATA ),
        xlb_const( "FWF_BESTFITWINDOW,", FWF_BESTFITWINDOW ),
        xlb_const( "FWF_DESKTOP,", FWF_DESKTOP ),
        xlb_const( "FWF_SINGLESEL,", FWF_SINGLESEL ),
        xlb_const( "FWF_NOSUBFOLDERS,", FWF_NOSUBFOLDERS ),
        xlb_const( "FWF_TRANSPARENT,", FWF_TRANSPARENT ),
        xlb_const( "FWF_NOCLIENTEDGE,", FWF_NOCLIENTEDGE ),
        xlb_const( "FWF_NOSCROLL,", FWF_NOSCROLL ),
        xlb_const( "FWF_ALIGNLEFT,", FWF_ALIGNLEFT ),
        xlb_const( "FWF_NOICONS,", FWF_NOICONS ),
        xlb_const( "FWF_SHOWSELALWAYS,", FWF_SHOWSELALWAYS ),
        xlb_const( "FWF_NOVISIBLE,", FWF_NOVISIBLE ),
        xlb_const( "FWF_SINGLECLICKACTIVATE,", FWF_SINGLECLICKACTIVATE ),
        xlb_const( "FWF_NOWEBVIEW,", FWF_NOWEBVIEW ),
        xlb_const( "FWF_HIDEFILENAMES,", FWF_HIDEFILENAMES ),
        xlb_const( "FWF_CHECKSELECT,", FWF_CHECKSELECT ),
        xlb_const( "FWF_NOENUMREFRESH,", FWF_NOENUMREFRESH ),
        xlb_const( "FWF_NOGROUPING,", FWF_NOGROUPING ),
        xlb_const( "FWF_FULLROWSELECT,", FWF_FULLROWSELECT ),
        xlb_const( "FWF_NOFILTERS,", FWF_NOFILTERS ),
        xlb_const( "FWF_NOCOLUMNHEADER,", FWF_NOCOLUMNHEADER ),
        xlb_const( "FWF_NOHEADERINALLVIEWS,", FWF_NOHEADERINALLVIEWS ),
        xlb_const( "FWF_EXTENDEDTILES,", FWF_EXTENDEDTILES ),
        xlb_const( "FWF_TRICHECKSELECT,", FWF_TRICHECKSELECT ),
        xlb_const( "FWF_AUTOCHECKSELECT,", FWF_AUTOCHECKSELECT ),
        xlb_const( "FWF_NOBROWSERVIEWSTATE,", FWF_NOBROWSERVIEWSTATE ),
        xlb_const( "FWF_SUBSETGROUPS,", FWF_SUBSETGROUPS ),
        xlb_const( "FWF_USESEARCHFOLDER,", FWF_USESEARCHFOLDER ),
        xlb_const( "FWF_ALLOWRTLREADING", FWF_ALLOWRTLREADING ),

        // FOLDERLOGICALVIEWMODE
        xlb_const( "FLVM_UNSPECIFIED,", FLVM_UNSPECIFIED ),
        xlb_const( "FLVM_FIRST,", FLVM_FIRST ), 
        xlb_const( "FLVM_DETAILS,", FLVM_DETAILS ),
        xlb_const( "FLVM_TILES,", FLVM_TILES ), 
        xlb_const( "FLVM_ICONS,", FLVM_ICONS ),
        xlb_const( "FLVM_LIST,", FLVM_LIST ), 
        xlb_const( "FLVM_CONTENT,", FLVM_CONTENT ),
        xlb_const( "FLVM_LAST", FLVM_LAST ),

        // FOLDERVIEWMODE
        xlb_const( "FVM_AUTO,", FVM_AUTO ), 
        xlb_const( "FVM_FIRST,", FVM_FIRST ),
        xlb_const( "FVM_ICON,", FVM_ICON ), 
        xlb_const( "FVM_SMALLICON,", FVM_SMALLICON ),
        xlb_const( "FVM_LIST,", FVM_LIST ), 
        xlb_const( "FVM_DETAILS,", FVM_DETAILS ),
        xlb_const( "FVM_THUMBNAIL,", FVM_THUMBNAIL ), 
        xlb_const( "FVM_TILE,", FVM_TILE ),
        xlb_const( "FVM_THUMBSTRIP,", FVM_THUMBSTRIP ),
        xlb_const( "FVM_CONTENT,", FVM_CONTENT ), 
        xlb_const( "FVM_LAST", FVM_LAST ),

        // FOLDERVIEWOPTIONS
        xlb_const( "FVO_DEFAULT,", FVO_DEFAULT ),
        xlb_const( "FVO_VISTALAYOUT,", FVO_VISTALAYOUT ),
        xlb_const( "FVO_CUSTOMPOSITION,", FVO_CUSTOMPOSITION ),
        xlb_const( "FVO_CUSTOMORDERING,", FVO_CUSTOMORDERING ),
        xlb_const( "FVO_SUPPORTHYPERLINKS,", FVO_SUPPORTHYPERLINKS ),
        xlb_const( "FVO_NOANIMATIONS,", FVO_NOANIMATIONS ),
        xlb_const( "FVO_NOSCROLLTIPS", FVO_NOSCROLLTIPS ),

        // tagIESHORTCUTFLAGS
        xlb_const( "IESHORTCUT_NEWBROWSER,", IESHORTCUT_NEWBROWSER ),
        xlb_const( "IESHORTCUT_OPENNEWTAB,", IESHORTCUT_OPENNEWTAB ),
        xlb_const( "IESHORTCUT_FORCENAVIGATE,", IESHORTCUT_FORCENAVIGATE ),
        xlb_const( "IESHORTCUT_BACKGROUNDTAB", IESHORTCUT_BACKGROUNDTAB ),

        // KF_CATEGORY
        xlb_const( "KF_CATEGORY_VIRTUAL,", KF_CATEGORY_VIRTUAL ),
        xlb_const( "KF_CATEGORY_FIXED,", KF_CATEGORY_FIXED ),
        xlb_const( "KF_CATEGORY_COMMON,", KF_CATEGORY_COMMON ),
        xlb_const( "KF_CATEGORY_PERUSER", KF_CATEGORY_PERUSER ),

        // KNOWN_FOLDER_FLAG
        xlb_const( "KF_FLAG_DEFAULT,", KF_FLAG_DEFAULT ),
        xlb_const( "KF_FLAG_FORCE_APP_DATA_REDIRECTION,",
                   KF_FLAG_FORCE_APP_DATA_REDIRECTION ),
        xlb_const( "KF_FLAG_RETURN_FILTER_REDIRECTION_TARGET,",
                   KF_FLAG_RETURN_FILTER_REDIRECTION_TARGET ),
        xlb_const( "KF_FLAG_FORCE_PACKAGE_REDIRECTION,", KF_FLAG_FORCE_PACKAGE_REDIRECTION ),
        xlb_const( "KF_FLAG_NO_PACKAGE_REDIRECTION,", KF_FLAG_NO_PACKAGE_REDIRECTION ),
        xlb_const( "KF_FLAG_FORCE_APPCONTAINER_REDIRECTION,",
                   KF_FLAG_FORCE_APPCONTAINER_REDIRECTION ),
        xlb_const( "KF_FLAG_NO_APPCONTAINER_REDIRECTION,",
                   KF_FLAG_NO_APPCONTAINER_REDIRECTION ),
        xlb_const( "KF_FLAG_CREATE,", KF_FLAG_CREATE ),
        xlb_const( "KF_FLAG_DONT_VERIFY,", KF_FLAG_DONT_VERIFY ),
        xlb_const( "KF_FLAG_DONT_UNEXPAND,", KF_FLAG_DONT_UNEXPAND ),
        xlb_const( "KF_FLAG_NO_ALIAS,", KF_FLAG_NO_ALIAS ),
        xlb_const( "KF_FLAG_INIT,", KF_FLAG_INIT ),
        xlb_const( "KF_FLAG_DEFAULT_PATH,", KF_FLAG_DEFAULT_PATH ),
        xlb_const( "KF_FLAG_NOT_PARENT_RELATIVE,", KF_FLAG_NOT_PARENT_RELATIVE ),
        xlb_const( "KF_FLAG_SIMPLE_IDLIST,", KF_FLAG_SIMPLE_IDLIST ),
        xlb_const( "KF_FLAG_ALIAS_ONLY", KF_FLAG_ALIAS_ONLY ),

        // LIBRARYFOLDERFILTER
        xlb_const( "LFF_FORCEFILESYSTEM,", LFF_FORCEFILESYSTEM ),
        xlb_const( "LFF_STORAGEITEMS,", LFF_STORAGEITEMS ),
        xlb_const( "LFF_ALLITEMS", LFF_ALLITEMS ),

        // LIBRARYMANAGEDIALOGOPTIONS
        xlb_const( "LMD_DEFAULT,", LMD_DEFAULT ),
        xlb_const( "LMD_ALLOWUNINDEXABLENETWORKLOCATIONS",
                   LMD_ALLOWUNINDEXABLENETWORKLOCATIONS ),

        // LIBRARYOPTIONFLAGS
        xlb_const( "LOF_DEFAULT,", LOF_DEFAULT ),
        xlb_const( "LOF_PINNEDTONAVPANE,", LOF_PINNEDTONAVPANE ),
        xlb_const( "LOF_MASK_ALL", LOF_MASK_ALL ),

        // LIBRARYSAVEFLAGS
        xlb_const( "LSF_FAILIFTHERE,", LSF_FAILIFTHERE ),
        xlb_const( "LSF_OVERRIDEEXISTING,", LSF_OVERRIDEEXISTING ),
        xlb_const( "LSF_MAKEUNIQUENAME", LSF_MAKEUNIQUENAME ),

        // mimeassociationdialog_in_flags
        xlb_const( "MIMEASSOCDLG_FL_REGISTER_ASSOC", MIMEASSOCDLG_FL_REGISTER_ASSOC ),

        // MONITOR_APP_VISIBILITY
        xlb_const( "MAV_UNKNOWN,", MAV_UNKNOWN ),
        xlb_const( "MAV_NO_APP_VISIBLE,", MAV_NO_APP_VISIBLE ),
        xlb_const( "MAV_APP_VISIBLE", MAV_APP_VISIBLE ),

        // NSTCFOLDERCAPABILITIES
        xlb_const( "NSTCFC_NONE,", NSTCFC_NONE ),
        xlb_const( "NSTCFC_PINNEDITEMFILTERING,", NSTCFC_PINNEDITEMFILTERING ),
        xlb_const( "NSTCFC_DELAY_REGISTER_NOTIFY", NSTCFC_DELAY_REGISTER_NOTIFY ),

        // NSTCSTYLE2
        xlb_const( "NSTCS2_DEFAULT,", NSTCS2_DEFAULT ),
        xlb_const( "NSTCS2_INTERRUPTNOTIFICATIONS,", NSTCS2_INTERRUPTNOTIFICATIONS ),
        xlb_const( "NSTCS2_SHOWNULLSPACEMENU,", NSTCS2_SHOWNULLSPACEMENU ),
        xlb_const( "NSTCS2_DISPLAYPADDING,", NSTCS2_DISPLAYPADDING ),
        xlb_const( "NSTCS2_DISPLAYPINNEDONLY,", NSTCS2_DISPLAYPINNEDONLY ),
        xlb_const( "NTSCS2_NOSINGLETONAUTOEXPAND,", NTSCS2_NOSINGLETONAUTOEXPAND ),
        xlb_const( "NTSCS2_NEVERINSERTNONENUMERATED", NTSCS2_NEVERINSERTNONENUMERATED ),

        // NWMF
        xlb_const( "NWMF_UNLOADING,", NWMF_UNLOADING ),
        xlb_const( "NWMF_USERINITED,", NWMF_USERINITED ),
        xlb_const( "NWMF_FIRST,", NWMF_FIRST ),
        xlb_const( "NWMF_OVERRIDEKEY,", NWMF_OVERRIDEKEY ),
        xlb_const( "NWMF_SHOWHELP,", NWMF_SHOWHELP ),
        xlb_const( "NWMF_HTMLDIALOG,", NWMF_HTMLDIALOG ),
        xlb_const( "NWMF_FROMDIALOGCHILD,", NWMF_FROMDIALOGCHILD ),
        xlb_const( "NWMF_USERREQUESTED,", NWMF_USERREQUESTED ),
        xlb_const( "NWMF_USERALLOWED,", NWMF_USERALLOWED ),
        xlb_const( "NWMF_FORCEWINDOW,", NWMF_FORCEWINDOW ),
        xlb_const( "NWMF_FORCETAB,", NWMF_FORCETAB ),
        xlb_const( "NWMF_SUGGESTWINDOW,", NWMF_SUGGESTWINDOW ),
        xlb_const( "NWMF_SUGGESTTAB,", NWMF_SUGGESTTAB ),
        xlb_const( "NWMF_INACTIVETAB", NWMF_INACTIVETAB ),

        // PACKAGE_EXECUTION_STATE
        xlb_const( "PES_UNKNOWN,", PES_UNKNOWN ), 
        xlb_const( "PES_RUNNING,", PES_RUNNING ),
        xlb_const( "PES_SUSPENDING,", PES_SUSPENDING ),
        xlb_const( "PES_SUSPENDED,", PES_SUSPENDED ),
        xlb_const( "PES_TERMINATED", PES_TERMINATED ),

        // tagPERCEIVED
        xlb_const( "PERCEIVED_TYPE_FIRST,", PERCEIVED_TYPE_FIRST ),
        xlb_const( "PERCEIVED_TYPE_CUSTOM,", PERCEIVED_TYPE_CUSTOM ),
        xlb_const( "PERCEIVED_TYPE_UNSPECIFIED,", PERCEIVED_TYPE_UNSPECIFIED ),
        xlb_const( "PERCEIVED_TYPE_FOLDER,", PERCEIVED_TYPE_FOLDER ),
        xlb_const( "PERCEIVED_TYPE_UNKNOWN,", PERCEIVED_TYPE_UNKNOWN ),
        xlb_const( "PERCEIVED_TYPE_TEXT,", PERCEIVED_TYPE_TEXT ),
        xlb_const( "PERCEIVED_TYPE_IMAGE,", PERCEIVED_TYPE_IMAGE ),
        xlb_const( "PERCEIVED_TYPE_AUDIO,", PERCEIVED_TYPE_AUDIO ),
        xlb_const( "PERCEIVED_TYPE_VIDEO,", PERCEIVED_TYPE_VIDEO ),
        xlb_const( "PERCEIVED_TYPE_COMPRESSED,", PERCEIVED_TYPE_COMPRESSED ),
        xlb_const( "PERCEIVED_TYPE_DOCUMENT,", PERCEIVED_TYPE_DOCUMENT ),
        xlb_const( "PERCEIVED_TYPE_SYSTEM,", PERCEIVED_TYPE_SYSTEM ),
        xlb_const( "PERCEIVED_TYPE_APPLICATION,", PERCEIVED_TYPE_APPLICATION ),
        xlb_const( "PERCEIVED_TYPE_GAMEMEDIA,", PERCEIVED_TYPE_GAMEMEDIA ),
        xlb_const( "PERCEIVED_TYPE_CONTACTS,", PERCEIVED_TYPE_CONTACTS ),
        xlb_const( "PERCEIVED_TYPE_LAST", PERCEIVED_TYPE_LAST ),

        //_tagPublishedAppInfoFlags
        xlb_const( "PAI_SOURCE,", PAI_SOURCE ),
        xlb_const( "PAI_ASSIGNEDTIME,", PAI_ASSIGNEDTIME ),
        xlb_const( "PAI_PUBLISHEDTIME,", PAI_PUBLISHEDTIME ),
        xlb_const( "PAI_SCHEDULEDTIME,", PAI_SCHEDULEDTIME ),
        xlb_const( "PAI_EXPIRETIME", PAI_EXPIRETIME ),

        // QUERY_USER_NOTIFICATION_STATE
        xlb_const( "QUNS_NOT_PRESENT,", QUNS_NOT_PRESENT ),
        xlb_const( "QUNS_BUSY,", QUNS_BUSY ),
        xlb_const( "QUNS_RUNNING_D3D_FULL_SCREEN,", QUNS_RUNNING_D3D_FULL_SCREEN ),
        xlb_const( "QUNS_PRESENTATION_MODE,", QUNS_PRESENTATION_MODE ),
        xlb_const( "QUNS_ACCEPTS_NOTIFICATIONS,", QUNS_ACCEPTS_NOTIFICATIONS ),
        xlb_const( "QUNS_QUIET_TIME,", QUNS_QUIET_TIME ), 
        xlb_const( "QUNS_APP", QUNS_APP ),

        // RESTRICTIONS
        xlb_const( "REST_NONE,", REST_NONE ), 
        xlb_const( "REST_NORUN,", REST_NORUN ),
        xlb_const( "REST_NOCLOSE,", REST_NOCLOSE ),
        xlb_const( "REST_NOSAVESET,", REST_NOSAVESET ),
        xlb_const( "REST_NOFILEMENU,", REST_NOFILEMENU ),
        xlb_const( "REST_NOSETFOLDERS,", REST_NOSETFOLDERS ),
        xlb_const( "REST_NOSETTASKBAR,", REST_NOSETTASKBAR ),
        xlb_const( "REST_NODESKTOP,", REST_NODESKTOP ),
        xlb_const( "REST_NOFIND,", REST_NOFIND ),
        xlb_const( "REST_NODRIVES,", REST_NODRIVES ),
        xlb_const( "REST_NODRIVEAUTORUN,", REST_NODRIVEAUTORUN ),
        xlb_const( "REST_NODRIVETYPEAUTORUN,", REST_NODRIVETYPEAUTORUN ),
        xlb_const( "REST_NONETHOOD,", REST_NONETHOOD ),
        xlb_const( "REST_STARTBANNER,", REST_STARTBANNER ),
        xlb_const( "REST_RESTRICTRUN,", REST_RESTRICTRUN ),
        xlb_const( "REST_NOPRINTERTABS,", REST_NOPRINTERTABS ),
        xlb_const( "REST_NOPRINTERDELETE,", REST_NOPRINTERDELETE ),
        xlb_const( "REST_NOPRINTERADD,", REST_NOPRINTERADD ),
        xlb_const( "REST_NOSTARTMENUSUBFOLDERS,", REST_NOSTARTMENUSUBFOLDERS ),
        xlb_const( "REST_MYDOCSONNET,", REST_MYDOCSONNET ),
        xlb_const( "REST_NOEXITTODOS,", REST_NOEXITTODOS ),
        xlb_const( "REST_ENFORCESHELLEXTSECURITY,", REST_ENFORCESHELLEXTSECURITY ),
        xlb_const( "REST_LINKRESOLVEIGNORELINKINFO,", REST_LINKRESOLVEIGNORELINKINFO ),
        xlb_const( "REST_NOCOMMONGROUPS,", REST_NOCOMMONGROUPS ),
        xlb_const( "REST_SEPARATEDESKTOPPROCESS,", REST_SEPARATEDESKTOPPROCESS ),
        xlb_const( "REST_NOWEB,", REST_NOWEB ),
        xlb_const( "REST_NOTRAYCONTEXTMENU,", REST_NOTRAYCONTEXTMENU ),
        xlb_const( "REST_NOVIEWCONTEXTMENU,", REST_NOVIEWCONTEXTMENU ),
        xlb_const( "REST_NONETCONNECTDISCONNECT,", REST_NONETCONNECTDISCONNECT ),
        xlb_const( "REST_STARTMENULOGOFF,", REST_STARTMENULOGOFF ),
        xlb_const( "REST_NOSETTINGSASSIST,", REST_NOSETTINGSASSIST ),
        xlb_const( "REST_NOINTERNETICON,", REST_NOINTERNETICON ),
        xlb_const( "REST_NORECENTDOCSHISTORY,", REST_NORECENTDOCSHISTORY ),
        xlb_const( "REST_NORECENTDOCSMENU,", REST_NORECENTDOCSMENU ),
        xlb_const( "REST_NOACTIVEDESKTOP,", REST_NOACTIVEDESKTOP ),
        xlb_const( "REST_NOACTIVEDESKTOPCHANGES,", REST_NOACTIVEDESKTOPCHANGES ),
        xlb_const( "REST_NOFAVORITESMENU,", REST_NOFAVORITESMENU ),
        xlb_const( "REST_CLEARRECENTDOCSONEXIT,", REST_CLEARRECENTDOCSONEXIT ),
        xlb_const( "REST_CLASSICSHELL,", REST_CLASSICSHELL ),
        xlb_const( "REST_NOCUSTOMIZEWEBVIEW,", REST_NOCUSTOMIZEWEBVIEW ),
        xlb_const( "REST_NOHTMLWALLPAPER,", REST_NOHTMLWALLPAPER ),
        xlb_const( "REST_NOCHANGINGWALLPAPER,", REST_NOCHANGINGWALLPAPER ),
        xlb_const( "REST_NODESKCOMP,", REST_NODESKCOMP ),
        xlb_const( "REST_NOADDDESKCOMP,", REST_NOADDDESKCOMP ),
        xlb_const( "REST_NODELDESKCOMP,", REST_NODELDESKCOMP ),
        xlb_const( "REST_NOCLOSEDESKCOMP,", REST_NOCLOSEDESKCOMP ),
        xlb_const( "REST_NOCLOSE_DRAGDROPBAND,", REST_NOCLOSE_DRAGDROPBAND ),
        xlb_const( "REST_NOMOVINGBAND,", REST_NOMOVINGBAND ),
        xlb_const( "REST_NOEDITDESKCOMP,", REST_NOEDITDESKCOMP ),
        xlb_const( "REST_NORESOLVESEARCH,", REST_NORESOLVESEARCH ),
        xlb_const( "REST_NORESOLVETRACK,", REST_NORESOLVETRACK ),
        xlb_const( "REST_FORCECOPYACLWITHFILE,", REST_FORCECOPYACLWITHFILE ),
        // xlb_const("REST_NOLOGO3CHANNELNOTIFY,", REST_NOLOGO3CHANNELNOTIFY), // unsupported
        xlb_const( "REST_NOFORGETSOFTWAREUPDATE,", REST_NOFORGETSOFTWAREUPDATE ),
        xlb_const( "REST_NOSETACTIVEDESKTOP,", REST_NOSETACTIVEDESKTOP ),
        xlb_const( "REST_NOUPDATEWINDOWS,", REST_NOUPDATEWINDOWS ),
        xlb_const( "REST_NOCHANGESTARMENU,", REST_NOCHANGESTARMENU ),
        xlb_const( "REST_NOFOLDEROPTIONS,", REST_NOFOLDEROPTIONS ),
        xlb_const( "REST_HASFINDCOMPUTERS,", REST_HASFINDCOMPUTERS ),
        xlb_const( "REST_INTELLIMENUS,", REST_INTELLIMENUS ),
        xlb_const( "REST_RUNDLGMEMCHECKBOX,", REST_RUNDLGMEMCHECKBOX ),
        xlb_const( "REST_ARP_ShowPostSetup,", REST_ARP_ShowPostSetup ),
        xlb_const( "REST_NOCSC,", REST_NOCSC ),
        xlb_const( "REST_NOCONTROLPANEL,", REST_NOCONTROLPANEL ),
        xlb_const( "REST_ENUMWORKGROUP,", REST_ENUMWORKGROUP ),
        xlb_const( "REST_ARP_NOARP,", REST_ARP_NOARP ),
        xlb_const( "REST_ARP_NOREMOVEPAGE,", REST_ARP_NOREMOVEPAGE ),
        xlb_const( "REST_ARP_NOADDPAGE,", REST_ARP_NOADDPAGE ),
        xlb_const( "REST_ARP_NOWINSETUPPAGE,", REST_ARP_NOWINSETUPPAGE ),
        xlb_const( "REST_GREYMSIADS,", REST_GREYMSIADS ),
        xlb_const( "REST_NOCHANGEMAPPEDDRIVELABEL,", REST_NOCHANGEMAPPEDDRIVELABEL ),
        xlb_const( "REST_NOCHANGEMAPPEDDRIVECOMMENT,", REST_NOCHANGEMAPPEDDRIVECOMMENT ),
        xlb_const( "REST_MaxRecentDocs,", REST_MaxRecentDocs ),
        xlb_const( "REST_NONETWORKCONNECTIONS,", REST_NONETWORKCONNECTIONS ),
        xlb_const( "REST_FORCESTARTMENULOGOFF,", REST_FORCESTARTMENULOGOFF ),
        xlb_const( "REST_NOWEBVIEW,", REST_NOWEBVIEW ),
        xlb_const( "REST_NOCUSTOMIZETHISFOLDER,", REST_NOCUSTOMIZETHISFOLDER ),
        xlb_const( "REST_NOENCRYPTION,", REST_NOENCRYPTION ),
        xlb_const( "REST_DONTSHOWSUPERHIDDEN,", REST_DONTSHOWSUPERHIDDEN ),
        xlb_const( "REST_NOSHELLSEARCHBUTTON,", REST_NOSHELLSEARCHBUTTON ),
        xlb_const( "REST_NOHARDWARETAB,", REST_NOHARDWARETAB ),
        xlb_const( "REST_NORUNASINSTALLPROMPT,", REST_NORUNASINSTALLPROMPT ),
        xlb_const( "REST_PROMPTRUNASINSTALLNETPATH,", REST_PROMPTRUNASINSTALLNETPATH ),
        xlb_const( "REST_NOMANAGEMYCOMPUTERVERB,", REST_NOMANAGEMYCOMPUTERVERB ),
        xlb_const( "REST_DISALLOWRUN,", REST_DISALLOWRUN ),
        xlb_const( "REST_NOWELCOMESCREEN,", REST_NOWELCOMESCREEN ),
        xlb_const( "REST_RESTRICTCPL,", REST_RESTRICTCPL ),
        xlb_const( "REST_DISALLOWCPL,", REST_DISALLOWCPL ),
        xlb_const( "REST_NOSMBALLOONTIP,", REST_NOSMBALLOONTIP ),
        xlb_const( "REST_NOSMHELP,", REST_NOSMHELP ),
        xlb_const( "REST_NOWINKEYS,", REST_NOWINKEYS ),
        xlb_const( "REST_NOENCRYPTONMOVE,", REST_NOENCRYPTONMOVE ),
        xlb_const( "REST_NOLOCALMACHINERUN,", REST_NOLOCALMACHINERUN ),
        xlb_const( "REST_NOCURRENTUSERRUN,", REST_NOCURRENTUSERRUN ),
        xlb_const( "REST_NOLOCALMACHINERUNONCE,", REST_NOLOCALMACHINERUNONCE ),
        xlb_const( "REST_NOCURRENTUSERRUNONCE,", REST_NOCURRENTUSERRUNONCE ),
        xlb_const( "REST_FORCEACTIVEDESKTOPON,", REST_FORCEACTIVEDESKTOPON ),
        xlb_const( "REST_NOVIEWONDRIVE,", REST_NOVIEWONDRIVE ),
        xlb_const( "REST_NONETCRAWL,", REST_NONETCRAWL ),
        xlb_const( "REST_NOSHAREDDOCUMENTS,", REST_NOSHAREDDOCUMENTS ),
        xlb_const( "REST_NOSMMYDOCS,", REST_NOSMMYDOCS ),
        xlb_const( "REST_NOSMMYPICS,", REST_NOSMMYPICS ),
        xlb_const( "REST_ALLOWBITBUCKDRIVES,", REST_ALLOWBITBUCKDRIVES ),
        xlb_const( "REST_NONLEGACYSHELLMODE,", REST_NONLEGACYSHELLMODE ),
        xlb_const( "REST_NOCONTROLPANELBARRICADE,", REST_NOCONTROLPANELBARRICADE ),
        xlb_const( "REST_NOSTARTPAGE,", REST_NOSTARTPAGE ),
        xlb_const( "REST_NOAUTOTRAYNOTIFY,", REST_NOAUTOTRAYNOTIFY ),
        xlb_const( "REST_NOTASKGROUPING,", REST_NOTASKGROUPING ),
        xlb_const( "REST_NOCDBURNING,", REST_NOCDBURNING ),
        xlb_const( "REST_MYCOMPNOPROP,", REST_MYCOMPNOPROP ),
        xlb_const( "REST_MYDOCSNOPROP,", REST_MYDOCSNOPROP ),
        xlb_const( "REST_NOSTARTPANEL,", REST_NOSTARTPANEL ),
        xlb_const( "REST_NODISPLAYAPPEARANCEPAGE,", REST_NODISPLAYAPPEARANCEPAGE ),
        xlb_const( "REST_NOTHEMESTAB,", REST_NOTHEMESTAB ),
        xlb_const( "REST_NOVISUALSTYLECHOICE,", REST_NOVISUALSTYLECHOICE ),
        xlb_const( "REST_NOSIZECHOICE,", REST_NOSIZECHOICE ),
        xlb_const( "REST_NOCOLORCHOICE,", REST_NOCOLORCHOICE ),
        xlb_const( "REST_SETVISUALSTYLE,", REST_SETVISUALSTYLE ),
        xlb_const( "REST_STARTRUNNOHOMEPATH,", REST_STARTRUNNOHOMEPATH ),
        xlb_const( "REST_NOUSERNAMEINSTARTPANEL,", REST_NOUSERNAMEINSTARTPANEL ),
        xlb_const( "REST_NOMYCOMPUTERICON,", REST_NOMYCOMPUTERICON ),
        xlb_const( "REST_NOSMNETWORKPLACES,", REST_NOSMNETWORKPLACES ),
        xlb_const( "REST_NOSMPINNEDLIST,", REST_NOSMPINNEDLIST ),
        xlb_const( "REST_NOSMMYMUSIC,", REST_NOSMMYMUSIC ),
        xlb_const( "REST_NOSMEJECTPC,", REST_NOSMEJECTPC ),
        xlb_const( "REST_NOSMMOREPROGRAMS,", REST_NOSMMOREPROGRAMS ),
        xlb_const( "REST_NOSMMFUPROGRAMS,", REST_NOSMMFUPROGRAMS ),
        xlb_const( "REST_NOTRAYITEMSDISPLAY,", REST_NOTRAYITEMSDISPLAY ),
        xlb_const( "REST_NOTOOLBARSONTASKBAR,", REST_NOTOOLBARSONTASKBAR ),
        xlb_const( "REST_NOSMCONFIGUREPROGRAMS,", REST_NOSMCONFIGUREPROGRAMS ),
        xlb_const( "REST_HIDECLOCK,", REST_HIDECLOCK ),
        xlb_const( "REST_NOLOWDISKSPACECHECKS,", REST_NOLOWDISKSPACECHECKS ),
        xlb_const( "REST_NOENTIRENETWORK,", REST_NOENTIRENETWORK ),
        xlb_const( "REST_NODESKTOPCLEANUP,", REST_NODESKTOPCLEANUP ),
        xlb_const( "REST_BITBUCKNUKEONDELETE,", REST_BITBUCKNUKEONDELETE ),
        xlb_const( "REST_BITBUCKCONFIRMDELETE,", REST_BITBUCKCONFIRMDELETE ),
        xlb_const( "REST_BITBUCKNOPROP,", REST_BITBUCKNOPROP ),
        xlb_const( "REST_NODISPBACKGROUND,", REST_NODISPBACKGROUND ),
        xlb_const( "REST_NODISPSCREENSAVEPG,", REST_NODISPSCREENSAVEPG ),
        xlb_const( "REST_NODISPSETTINGSPG,", REST_NODISPSETTINGSPG ),
        xlb_const( "REST_NODISPSCREENSAVEPREVIEW,", REST_NODISPSCREENSAVEPREVIEW ),
        xlb_const( "REST_NODISPLAYCPL,", REST_NODISPLAYCPL ),
        xlb_const( "REST_HIDERUNASVERB,", REST_HIDERUNASVERB ),
        xlb_const( "REST_NOTHUMBNAILCACHE,", REST_NOTHUMBNAILCACHE ),
        xlb_const( "REST_NOSTRCMPLOGICAL,", REST_NOSTRCMPLOGICAL ),
        xlb_const( "REST_NOPUBLISHWIZARD,", REST_NOPUBLISHWIZARD ),
        xlb_const( "REST_NOONLINEPRINTSWIZARD,", REST_NOONLINEPRINTSWIZARD ),
        xlb_const( "REST_NOWEBSERVICES,", REST_NOWEBSERVICES ),
        xlb_const( "REST_ALLOWUNHASHEDWEBVIEW,", REST_ALLOWUNHASHEDWEBVIEW ),
        xlb_const( "REST_ALLOWLEGACYWEBVIEW,", REST_ALLOWLEGACYWEBVIEW ),
        xlb_const( "REST_REVERTWEBVIEWSECURITY,", REST_REVERTWEBVIEWSECURITY ),
        xlb_const( "REST_INHERITCONSOLEHANDLES,", REST_INHERITCONSOLEHANDLES ),
        // xlb_const("REST_SORTMAXITEMCOUNT,", REST_SORTMAXITEMCOUNT), // unsupported
        xlb_const( "REST_NOREMOTERECURSIVEEVENTS,", REST_NOREMOTERECURSIVEEVENTS ),
        xlb_const( "REST_NOREMOTECHANGENOTIFY,", REST_NOREMOTECHANGENOTIFY ),
        // xlb_const("REST_NOSIMPLENETIDLIST,", REST_NOSIMPLENETIDLIST), // unsupported
        xlb_const( "REST_NOENUMENTIRENETWORK,", REST_NOENUMENTIRENETWORK ),
        // xlb_const("REST_NODETAILSTHUMBNAILONNETWORK,", REST_NODETAILSTHUMBNAILONNETWORK),
        // // unsupported
        xlb_const( "REST_NOINTERNETOPENWITH,", REST_NOINTERNETOPENWITH ),
        xlb_const( "REST_DONTRETRYBADNETNAME,", REST_DONTRETRYBADNETNAME ),
        xlb_const( "REST_ALLOWFILECLSIDJUNCTIONS,", REST_ALLOWFILECLSIDJUNCTIONS ),
        xlb_const( "REST_NOUPNPINSTALL,", REST_NOUPNPINSTALL ),
        xlb_const( "REST_ARP_DONTGROUPPATCHES,", REST_ARP_DONTGROUPPATCHES ),
        xlb_const( "REST_ARP_NOCHOOSEPROGRAMSPAGE,", REST_ARP_NOCHOOSEPROGRAMSPAGE ),
        xlb_const( "REST_NODISCONNECT,", REST_NODISCONNECT ),
        xlb_const( "REST_NOSECURITY,", REST_NOSECURITY ),
        xlb_const( "REST_NOFILEASSOCIATE,", REST_NOFILEASSOCIATE ),
        xlb_const( "REST_ALLOWCOMMENTTOGGLE,", REST_ALLOWCOMMENTTOGGLE ),
        // xlb_const("REST_USEDESKTOPINICACHE", REST_USEDESKTOPINICACHE), // unsupported

        // SCALE_CHANGE_FLAGS
        xlb_const( "SCF_VALUE_NONE,", SCF_VALUE_NONE ), 
        xlb_const( "SCF_SCALE,", SCF_SCALE ),
        xlb_const( "SCF_PHYSICAL", SCF_PHYSICAL ),

        // SCNRT_STATUS
        xlb_const( "SCNRT_ENABLE,", SCNRT_ENABLE ),
        xlb_const( "SCNRT_DISABLE", SCNRT_DISABLE ),

        // SECURELOCKCODE
        xlb_const( "SECURELOCK_NOCHANGE,", SECURELOCK_NOCHANGE ),
        xlb_const( "SECURELOCK_SET_UNSECURE,", SECURELOCK_SET_UNSECURE ),
        xlb_const( "SECURELOCK_SET_MIXED,", SECURELOCK_SET_MIXED ),
        xlb_const( "SECURELOCK_SET_SECUREUNKNOWNBIT,", SECURELOCK_SET_SECUREUNKNOWNBIT ),
        xlb_const( "SECURELOCK_SET_SECURE40BIT,", SECURELOCK_SET_SECURE40BIT ),
        xlb_const( "SECURELOCK_SET_SECURE56BIT,", SECURELOCK_SET_SECURE56BIT ),
        xlb_const( "SECURELOCK_SET_FORTEZZA,", SECURELOCK_SET_FORTEZZA ),
        xlb_const( "SECURELOCK_SET_SECURE128BIT,", SECURELOCK_SET_SECURE128BIT ),
        xlb_const( "SECURELOCK_FIRSTSUGGEST,", SECURELOCK_FIRSTSUGGEST ),
        xlb_const( "SECURELOCK_SUGGEST_UNSECURE,", SECURELOCK_SUGGEST_UNSECURE ),
        xlb_const( "SECURELOCK_SUGGEST_MIXED,", SECURELOCK_SUGGEST_MIXED ),
        xlb_const( "SECURELOCK_SUGGEST_SECUREUNKNOWNBIT,",
                   SECURELOCK_SUGGEST_SECUREUNKNOWNBIT ),
        xlb_const( "SECURELOCK_SUGGEST_SECURE40BIT,", SECURELOCK_SUGGEST_SECURE40BIT ),
        xlb_const( "SECURELOCK_SUGGEST_SECURE56BIT,", SECURELOCK_SUGGEST_SECURE56BIT ),
        xlb_const( "SECURELOCK_SUGGEST_FORTEZZA,", SECURELOCK_SUGGEST_FORTEZZA ),
        xlb_const( "SECURELOCK_SUGGEST_SECURE128BIT", SECURELOCK_SUGGEST_SECURE128BIT ),

        // SHARD
        xlb_const( "SHARD_PIDL,", SHARD_PIDL ), 
        xlb_const( "SHARD_PATHA,", SHARD_PATHA ),
        xlb_const( "SHARD_PATHW,", SHARD_PATHW ),
        xlb_const( "SHARD_APPIDINFO,", SHARD_APPIDINFO ),
        xlb_const( "SHARD_APPIDINFOIDLIST,", SHARD_APPIDINFOIDLIST ),
        xlb_const( "SHARD_LINK,", SHARD_LINK ),
        xlb_const( "SHARD_APPIDINFOLINK,", SHARD_APPIDINFOLINK ),
        xlb_const( "SHARD_SHELLITEM", SHARD_SHELLITEM ),

        // SHARE_ROLE
        xlb_const( "SHARE_ROLE_INVALID,", SHARE_ROLE_INVALID ),
        xlb_const( "SHARE_ROLE_READER,", SHARE_ROLE_READER ),
        xlb_const( "SHARE_ROLE_CONTRIBUTOR,", SHARE_ROLE_CONTRIBUTOR ),
        xlb_const( "SHARE_ROLE_CO_OWNER,", SHARE_ROLE_CO_OWNER ),
        xlb_const( "SHARE_ROLE_OWNER,", SHARE_ROLE_OWNER ),
        xlb_const( "SHARE_ROLE_CUSTOM,", SHARE_ROLE_CUSTOM ),
        xlb_const( "SHARE_ROLE_MIXED", SHARE_ROLE_MIXED ),

        // tagSHCOLSTATE
        xlb_const( "SHCOLSTATE_DEFAULT,", SHCOLSTATE_DEFAULT ),
        xlb_const( "SHCOLSTATE_TYPE_STR,", SHCOLSTATE_TYPE_STR ),
        xlb_const( "SHCOLSTATE_TYPE_INT,", SHCOLSTATE_TYPE_INT ),
        xlb_const( "SHCOLSTATE_TYPE_DATE,", SHCOLSTATE_TYPE_DATE ),
        xlb_const( "SHCOLSTATE_TYPEMASK,", SHCOLSTATE_TYPEMASK ),
        xlb_const( "SHCOLSTATE_ONBYDEFAULT,", SHCOLSTATE_ONBYDEFAULT ),
        xlb_const( "SHCOLSTATE_SLOW,", SHCOLSTATE_SLOW ),
        xlb_const( "SHCOLSTATE_EXTENDED,", SHCOLSTATE_EXTENDED ),
        xlb_const( "SHCOLSTATE_SECONDARYUI,", SHCOLSTATE_SECONDARYUI ),
        xlb_const( "SHCOLSTATE_HIDDEN,", SHCOLSTATE_HIDDEN ),
        xlb_const( "SHCOLSTATE_PREFER_VARCMP,", SHCOLSTATE_PREFER_VARCMP ),
        xlb_const( "SHCOLSTATE_PREFER_FMTCMP,", SHCOLSTATE_PREFER_FMTCMP ),
        xlb_const( "SHCOLSTATE_NOSORTBYFOLDERNESS,", SHCOLSTATE_NOSORTBYFOLDERNESS ),
        xlb_const( "SHCOLSTATE_VIEWONLY,", SHCOLSTATE_VIEWONLY ),
        xlb_const( "SHCOLSTATE_BATCHREAD,", SHCOLSTATE_BATCHREAD ),
        xlb_const( "SHCOLSTATE_NO_GROUPBY,", SHCOLSTATE_NO_GROUPBY ),
        xlb_const( "SHCOLSTATE_FIXED_WIDTH,", SHCOLSTATE_FIXED_WIDTH ),
        xlb_const( "SHCOLSTATE_NODPISCALE,", SHCOLSTATE_NODPISCALE ),
        xlb_const( "SHCOLSTATE_FIXED_RATIO,", SHCOLSTATE_FIXED_RATIO ),
        xlb_const( "SHCOLSTATE_DISPLAYMASK", SHCOLSTATE_DISPLAYMASK ),

        // SHELL_LINK_DATA_FLAGS
        xlb_const( "SLDF_DEFAULT,", SLDF_DEFAULT ),
        xlb_const( "SLDF_HAS_ID_LIST,", SLDF_HAS_ID_LIST ),
        xlb_const( "SLDF_HAS_LINK_INFO,", SLDF_HAS_LINK_INFO ),
        xlb_const( "SLDF_HAS_NAME,", SLDF_HAS_NAME ),
        xlb_const( "SLDF_HAS_RELPATH,", SLDF_HAS_RELPATH ),
        xlb_const( "SLDF_HAS_WORKINGDIR,", SLDF_HAS_WORKINGDIR ),
        xlb_const( "SLDF_HAS_ARGS,", SLDF_HAS_ARGS ),
        xlb_const( "SLDF_HAS_ICONLOCATION,", SLDF_HAS_ICONLOCATION ),
        xlb_const( "SLDF_UNICODE,", SLDF_UNICODE ),
        xlb_const( "SLDF_FORCE_NO_LINKINFO,", SLDF_FORCE_NO_LINKINFO ),
        xlb_const( "SLDF_HAS_EXP_SZ,", SLDF_HAS_EXP_SZ ),
        xlb_const( "SLDF_RUN_IN_SEPARATE,", SLDF_RUN_IN_SEPARATE ),
        // xlb_const("SLDF_HAS_LOGO3ID,", SLDF_HAS_LOGO3ID), // unsupported
        xlb_const( "SLDF_HAS_DARWINID,", SLDF_HAS_DARWINID ),
        xlb_const( "SLDF_RUNAS_USER,", SLDF_RUNAS_USER ),
        xlb_const( "SLDF_HAS_EXP_ICON_SZ,", SLDF_HAS_EXP_ICON_SZ ),
        xlb_const( "SLDF_NO_PIDL_ALIAS,", SLDF_NO_PIDL_ALIAS ),
        xlb_const( "SLDF_FORCE_UNCNAME,", SLDF_FORCE_UNCNAME ),
        xlb_const( "SLDF_RUN_WITH_SHIMLAYER,", SLDF_RUN_WITH_SHIMLAYER ),
        xlb_const( "SLDF_FORCE_NO_LINKTRACK,", SLDF_FORCE_NO_LINKTRACK ),
        xlb_const( "SLDF_ENABLE_TARGET_METADATA,", SLDF_ENABLE_TARGET_METADATA ),
        xlb_const( "SLDF_DISABLE_LINK_PATH_TRACKING,", SLDF_DISABLE_LINK_PATH_TRACKING ),
        xlb_const( "SLDF_DISABLE_KNOWNFOLDER_RELATIVE_TRACKING,",
                   SLDF_DISABLE_KNOWNFOLDER_RELATIVE_TRACKING ),
        xlb_const( "SLDF_NO_KF_ALIAS,", SLDF_NO_KF_ALIAS ),
        xlb_const( "SLDF_ALLOW_LINK_TO_LINK,", SLDF_ALLOW_LINK_TO_LINK ),
        xlb_const( "SLDF_UNALIAS_ON_SAVE,", SLDF_UNALIAS_ON_SAVE ),
        xlb_const( "SLDF_PREFER_ENVIRONMENT_PATH,", SLDF_PREFER_ENVIRONMENT_PATH ),
        xlb_const( "SLDF_KEEP_LOCAL_IDLIST_FOR_UNC_TARGET,",
                   SLDF_KEEP_LOCAL_IDLIST_FOR_UNC_TARGET ),
        xlb_const( "SLDF_PERSIST_VOLUME_ID_RELATIVE,", SLDF_PERSIST_VOLUME_ID_RELATIVE ),
        xlb_const( "SLDF_VALID,", SLDF_VALID ), 
        xlb_const( "SLDF_RESERVED", SLDF_RESERVED ),

        // SHELL_UI_COMPONENT
        xlb_const( "SHELL_UI_COMPONENT_TASKBARS,", SHELL_UI_COMPONENT_TASKBARS ),
        xlb_const( "SHELL_UI_COMPONENT_NOTIFICATIONAREA,",
                   SHELL_UI_COMPONENT_NOTIFICATIONAREA ),
        xlb_const( "SHELL_UI_COMPONENT_DESKBAND", SHELL_UI_COMPONENT_DESKBAND ),

        // ShellFolderViewOptions
        xlb_const( "SFVVO_SHOWALLOBJECTS,", SFVVO_SHOWALLOBJECTS ),
        xlb_const( "SFVVO_SHOWEXTENSIONS,", SFVVO_SHOWEXTENSIONS ),
        xlb_const( "SFVVO_SHOWCOMPCOLOR,", SFVVO_SHOWCOMPCOLOR ),
        xlb_const( "SFVVO_SHOWSYSFILES,", SFVVO_SHOWSYSFILES ),
        xlb_const( "SFVVO_WIN95CLASSIC,", SFVVO_WIN95CLASSIC ),
        xlb_const( "SFVVO_DOUBLECLICKINWEBVIEW,", SFVVO_DOUBLECLICKINWEBVIEW ),
        xlb_const( "SFVVO_DESKTOPHTML", SFVVO_DESKTOPHTML ),

        // ShellSpecialFolderConstants
        xlb_const( "ssfDESKTOP,", ssfDESKTOP ), 
        xlb_const( "ssfPROGRAMS,", ssfPROGRAMS ),
        xlb_const( "ssfCONTROLS,", ssfCONTROLS ), 
        xlb_const( "ssfPRINTERS,", ssfPRINTERS ),
        xlb_const( "ssfPERSONAL,", ssfPERSONAL ), 
        xlb_const( "ssfFAVORITES,", ssfFAVORITES ),
        xlb_const( "ssfSTARTUP,", ssfSTARTUP ), 
        xlb_const( "ssfRECENT,", ssfRECENT ),
        xlb_const( "ssfSENDTO,", ssfSENDTO ), 
        xlb_const( "ssfBITBUCKET,", ssfBITBUCKET ),
        xlb_const( "ssfSTARTMENU,", ssfSTARTMENU ),
        xlb_const( "ssfDESKTOPDIRECTORY,", ssfDESKTOPDIRECTORY ),
        xlb_const( "ssfDRIVES,", ssfDRIVES ), 
        xlb_const( "ssfNETWORK,", ssfNETWORK ),
        xlb_const( "ssfNETHOOD,", ssfNETHOOD ), 
        xlb_const( "ssfFONTS,", ssfFONTS ),
        xlb_const( "ssfTEMPLATES,", ssfTEMPLATES ),
        xlb_const( "ssfCOMMONSTARTMENU,", ssfCOMMONSTARTMENU ),
        xlb_const( "ssfCOMMONPROGRAMS,", ssfCOMMONPROGRAMS ),
        xlb_const( "ssfCOMMONSTARTUP,", ssfCOMMONSTARTUP ),
        xlb_const( "ssfCOMMONDESKTOPDIR,", ssfCOMMONDESKTOPDIR ),
        xlb_const( "ssfAPPDATA,", ssfAPPDATA ), 
        xlb_const( "ssfPRINTHOOD,", ssfPRINTHOOD ),
        xlb_const( "ssfLOCALAPPDATA,", ssfLOCALAPPDATA ),
        xlb_const( "ssfALTSTARTUP,", ssfALTSTARTUP ),
        xlb_const( "ssfCOMMONALTSTARTUP,", ssfCOMMONALTSTARTUP ),
        xlb_const( "ssfCOMMONFAVORITES,", ssfCOMMONFAVORITES ),
        xlb_const( "ssfINTERNETCACHE,", ssfINTERNETCACHE ),
        xlb_const( "ssfCOOKIES,", ssfCOOKIES ), 
        xlb_const( "ssfHISTORY,", ssfHISTORY ),
        xlb_const( "ssfCOMMONAPPDATA,", ssfCOMMONAPPDATA ),
        xlb_const( "ssfWINDOWS,", ssfWINDOWS ), 
        xlb_const( "ssfSYSTEM,", ssfSYSTEM ),
        xlb_const( "ssfPROGRAMFILES,", ssfPROGRAMFILES ),
        xlb_const( "ssfMYPICTURES,", ssfMYPICTURES ), 
        xlb_const( "ssfPROFILE,", ssfPROFILE ),
        xlb_const( "ssfSYSTEMx86,", ssfSYSTEMx86 ),
        xlb_const( "ssfPROGRAMFILESx86", ssfPROGRAMFILESx86 ),

        // ShellWindowFindWindowOptions
        xlb_const( "SWFO_NEEDDISPATCH,", SWFO_NEEDDISPATCH ),
        xlb_const( "SWFO_INCLUDEPENDING,", SWFO_INCLUDEPENDING ),
        xlb_const( "SWFO_COOKIEPASSED", SWFO_COOKIEPASSED ),

        // ShellWindowTypeConstants
        xlb_const( "SWC_EXPLORER,", SWC_EXPLORER ), 
        xlb_const( "SWC_BROWSER,", SWC_BROWSER ),
        xlb_const( "SWC_3RDPARTY,", SWC_3RDPARTY ),
        xlb_const( "SWC_CALLBACK,", SWC_CALLBACK ), 
        xlb_const( "SWC_DESKTOP", SWC_DESKTOP ),

        // SHGLOBALCOUNTER
        xlb_const( "GLOBALCOUNTER_SEARCHMANAGER,", GLOBALCOUNTER_SEARCHMANAGER ),
        xlb_const( "GLOBALCOUNTER_SEARCHOPTIONS,", GLOBALCOUNTER_SEARCHOPTIONS ),
        xlb_const( "GLOBALCOUNTER_FOLDERSETTINGSCHANGE,",
                   GLOBALCOUNTER_FOLDERSETTINGSCHANGE ),
        xlb_const( "GLOBALCOUNTER_RATINGS,", GLOBALCOUNTER_RATINGS ),
        xlb_const( "GLOBALCOUNTER_APPROVEDSITES,", GLOBALCOUNTER_APPROVEDSITES ),
        xlb_const( "GLOBALCOUNTER_RESTRICTIONS,", GLOBALCOUNTER_RESTRICTIONS ),
        xlb_const( "GLOBALCOUNTER_SHELLSETTINGSCHANGED,",
                   GLOBALCOUNTER_SHELLSETTINGSCHANGED ),
        xlb_const( "GLOBALCOUNTER_SYSTEMPIDLCHANGE,", GLOBALCOUNTER_SYSTEMPIDLCHANGE ),
        xlb_const( "GLOBALCOUNTER_OVERLAYMANAGER,", GLOBALCOUNTER_OVERLAYMANAGER ),
        xlb_const( "GLOBALCOUNTER_QUERYASSOCIATIONS,", GLOBALCOUNTER_QUERYASSOCIATIONS ),
        xlb_const( "GLOBALCOUNTER_IESESSIONS,", GLOBALCOUNTER_IESESSIONS ),
        xlb_const( "GLOBALCOUNTER_IEONLY_SESSIONS,", GLOBALCOUNTER_IEONLY_SESSIONS ),
        xlb_const( "GLOBALCOUNTER_APPLICATION_DESTINATIONS,",
                   GLOBALCOUNTER_APPLICATION_DESTINATIONS ),
        xlb_const( "__UNUSED_RECYCLE_WAS_GLOBALCOUNTER_CSCSYNCINPROGRESS,",
                   __UNUSED_RECYCLE_WAS_GLOBALCOUNTER_CSCSYNCINPROGRESS ),
        xlb_const( "GLOBALCOUNTER_BITBUCKETNUMDELETERS,",
                   GLOBALCOUNTER_BITBUCKETNUMDELETERS ),
        xlb_const( "GLOBALCOUNTER_RECYCLEDIRTYCOUNT_SHARES,",
                   GLOBALCOUNTER_RECYCLEDIRTYCOUNT_SHARES ),
        xlb_const( "GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_A,",
                   GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_A ),
        xlb_const( "GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_B,",
                   GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_B ),
        xlb_const( "GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_C,",
                   GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_C ),
        xlb_const( "GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_D,",
                   GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_D ),
        xlb_const( "GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_E,",
                   GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_E ),
        xlb_const( "GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_F,",
                   GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_F ),
        xlb_const( "GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_G,",
                   GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_G ),
        xlb_const( "GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_H,",
                   GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_H ),
        xlb_const( "GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_I,",
                   GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_I ),
        xlb_const( "GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_J,",
                   GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_J ),
        xlb_const( "GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_K,",
                   GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_K ),
        xlb_const( "GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_L,",
                   GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_L ),
        xlb_const( "GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_M,",
                   GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_M ),
        xlb_const( "GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_N,",
                   GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_N ),
        xlb_const( "GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_O,",
                   GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_O ),
        xlb_const( "GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_P,",
                   GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_P ),
        xlb_const( "GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_Q,",
                   GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_Q ),
        xlb_const( "GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_R,",
                   GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_R ),
        xlb_const( "GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_S,",
                   GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_S ),
        xlb_const( "GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_T,",
                   GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_T ),
        xlb_const( "GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_U,",
                   GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_U ),
        xlb_const( "GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_V,",
                   GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_V ),
        xlb_const( "GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_W,",
                   GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_W ),
        xlb_const( "GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_X,",
                   GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_X ),
        xlb_const( "GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_Y,",
                   GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_Y ),
        xlb_const( "GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_Z,",
                   GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_Z ),
        xlb_const( "__UNUSED_RECYCLE_WAS_GLOBALCOUNTER_RECYCLEDIRTYCOUNT_SERVERDRIVE,",
                   __UNUSED_RECYCLE_WAS_GLOBALCOUNTER_RECYCLEDIRTYCOUNT_SERVERDRIVE ),
        xlb_const( "__UNUSED_RECYCLE_WAS_GLOBALCOUNTER_RECYCLEGLOBALDIRTYCOUNT,",
                   __UNUSED_RECYCLE_WAS_GLOBALCOUNTER_RECYCLEGLOBALDIRTYCOUNT ),
        xlb_const( "GLOBALCOUNTER_RECYCLEBINENUM,", GLOBALCOUNTER_RECYCLEBINENUM ),
        xlb_const( "GLOBALCOUNTER_RECYCLEBINCORRUPTED,", GLOBALCOUNTER_RECYCLEBINCORRUPTED ),
        xlb_const( "GLOBALCOUNTER_RATINGS_STATECOUNTER,",
                   GLOBALCOUNTER_RATINGS_STATECOUNTER ),
        xlb_const( "GLOBALCOUNTER_PRIVATE_PROFILE_CACHE,",
                   GLOBALCOUNTER_PRIVATE_PROFILE_CACHE ),
        xlb_const( "GLOBALCOUNTER_INTERNETTOOLBAR_LAYOUT,",
                   GLOBALCOUNTER_INTERNETTOOLBAR_LAYOUT ),
        xlb_const( "GLOBALCOUNTER_FOLDERDEFINITION_CACHE,",
                   GLOBALCOUNTER_FOLDERDEFINITION_CACHE ),
        xlb_const( "GLOBALCOUNTER_COMMONPLACES_LIST_CACHE,",
                   GLOBALCOUNTER_COMMONPLACES_LIST_CACHE ),
        xlb_const( "GLOBALCOUNTER_PRIVATE_PROFILE_CACHE_MACHINEWIDE,",
                   GLOBALCOUNTER_PRIVATE_PROFILE_CACHE_MACHINEWIDE ),
        xlb_const( "GLOBALCOUNTER_ASSOCCHANGED,", GLOBALCOUNTER_ASSOCCHANGED ),
        xlb_const( "GLOBALCOUNTER_APP_ITEMS_STATE_STORE_CACHE,",
                   GLOBALCOUNTER_APP_ITEMS_STATE_STORE_CACHE ),
        xlb_const( "GLOBALCOUNTER_SETTINGSYNC_ENABLED,", GLOBALCOUNTER_SETTINGSYNC_ENABLED ),
        xlb_const( "GLOBALCOUNTER_APPSFOLDER_FILETYPEASSOCIATION_COUNTER,",
                   GLOBALCOUNTER_APPSFOLDER_FILETYPEASSOCIATION_COUNTER ),
        xlb_const( "GLOBALCOUNTER_USERINFOCHANGED,", GLOBALCOUNTER_USERINFOCHANGED ),
        xlb_const( "GLOBALCOUNTER_SYNC_ENGINE_INFORMATION_CACHE_MACHINEWIDE,",
                   GLOBALCOUNTER_SYNC_ENGINE_INFORMATION_CACHE_MACHINEWIDE ),
        xlb_const( "GLOBALCOUNTER_BANNERS_DATAMODEL_CACHE_MACHINEWIDE,",
                   GLOBALCOUNTER_BANNERS_DATAMODEL_CACHE_MACHINEWIDE ),
        xlb_const( "GLOBALCOUNTER_MAXIMUMVALUE", GLOBALCOUNTER_MAXIMUMVALUE ),

        // SHREGDEL_FLAGS
        xlb_const( "SHREGDEL_DEFAULT,", SHREGDEL_DEFAULT ),
        xlb_const( "SHREGDEL_HKCU,", SHREGDEL_HKCU ),
        xlb_const( "SHREGDEL_HKLM,", SHREGDEL_HKLM ),
        xlb_const( "SHREGDEL_BOTH", SHREGDEL_BOTH ),

        // SHREGENUM_FLAGS
        xlb_const( "SHREGENUM_DEFAULT,", SHREGENUM_DEFAULT ),
        xlb_const( "SHREGENUM_HKCU,", SHREGENUM_HKCU ),
        xlb_const( "SHREGENUM_HKLM,", SHREGENUM_HKLM ),
        xlb_const( "SHREGENUM_BOTH", SHREGENUM_BOTH ),

        // SHSTOCKICONID
        xlb_const( "SIID_DOCNOASSOC,", SIID_DOCNOASSOC ),
        xlb_const( "SIID_DOCASSOC,", SIID_DOCASSOC ),
        xlb_const( "SIID_APPLICATION,", SIID_APPLICATION ),
        xlb_const( "SIID_FOLDER,", SIID_FOLDER ),
        xlb_const( "SIID_FOLDEROPEN,", SIID_FOLDEROPEN ),
        xlb_const( "SIID_DRIVE525,", SIID_DRIVE525 ),
        xlb_const( "SIID_DRIVE35,", SIID_DRIVE35 ),
        xlb_const( "SIID_DRIVEREMOVE,", SIID_DRIVEREMOVE ),
        xlb_const( "SIID_DRIVEFIXED,", SIID_DRIVEFIXED ),
        xlb_const( "SIID_DRIVENET,", SIID_DRIVENET ),
        xlb_const( "SIID_DRIVENETDISABLED,", SIID_DRIVENETDISABLED ),
        xlb_const( "SIID_DRIVECD,", SIID_DRIVECD ),
        xlb_const( "SIID_DRIVERAM,", SIID_DRIVERAM ), 
        xlb_const( "SIID_WORLD,", SIID_WORLD ),
        xlb_const( "SIID_SERVER,", SIID_SERVER ), 
        xlb_const( "SIID_PRINTER,", SIID_PRINTER ),
        xlb_const( "SIID_MYNETWORK,", SIID_MYNETWORK ), 
        xlb_const( "SIID_FIND,", SIID_FIND ),
        xlb_const( "SIID_HELP,", SIID_HELP ), 
        xlb_const( "SIID_SHARE,", SIID_SHARE ),
        xlb_const( "SIID_LINK,", SIID_LINK ), 
        xlb_const( "SIID_SLOWFILE,", SIID_SLOWFILE ),
        xlb_const( "SIID_RECYCLER,", SIID_RECYCLER ),
        xlb_const( "SIID_RECYCLERFULL,", SIID_RECYCLERFULL ),
        xlb_const( "SIID_MEDIACDAUDIO,", SIID_MEDIACDAUDIO ),
        xlb_const( "SIID_LOCK,", SIID_LOCK ), 
        xlb_const( "SIID_AUTOLIST,", SIID_AUTOLIST ),
        xlb_const( "SIID_PRINTERNET,", SIID_PRINTERNET ),
        xlb_const( "SIID_SERVERSHARE,", SIID_SERVERSHARE ),
        xlb_const( "SIID_PRINTERFAX,", SIID_PRINTERFAX ),
        xlb_const( "SIID_PRINTERFAXNET,", SIID_PRINTERFAXNET ),
        xlb_const( "SIID_PRINTERFILE,", SIID_PRINTERFILE ),
        xlb_const( "SIID_STACK,", SIID_STACK ),
        xlb_const( "SIID_MEDIASVCD,", SIID_MEDIASVCD ),
        xlb_const( "SIID_STUFFEDFOLDER,", SIID_STUFFEDFOLDER ),
        xlb_const( "SIID_DRIVEUNKNOWN,", SIID_DRIVEUNKNOWN ),
        xlb_const( "SIID_DRIVEDVD,", SIID_DRIVEDVD ),
        xlb_const( "SIID_MEDIADVD,", SIID_MEDIADVD ),
        xlb_const( "SIID_MEDIADVDRAM,", SIID_MEDIADVDRAM ),
        xlb_const( "SIID_MEDIADVDRW,", SIID_MEDIADVDRW ),
        xlb_const( "SIID_MEDIADVDR,", SIID_MEDIADVDR ),
        xlb_const( "SIID_MEDIADVDROM,", SIID_MEDIADVDROM ),
        xlb_const( "SIID_MEDIACDAUDIOPLUS,", SIID_MEDIACDAUDIOPLUS ),
        xlb_const( "SIID_MEDIACDRW,", SIID_MEDIACDRW ),
        xlb_const( "SIID_MEDIACDR,", SIID_MEDIACDR ),
        xlb_const( "SIID_MEDIACDBURN,", SIID_MEDIACDBURN ),
        xlb_const( "SIID_MEDIABLANKCD,", SIID_MEDIABLANKCD ),
        xlb_const( "SIID_MEDIACDROM,", SIID_MEDIACDROM ),
        xlb_const( "SIID_AUDIOFILES,", SIID_AUDIOFILES ),
        xlb_const( "SIID_IMAGEFILES,", SIID_IMAGEFILES ),
        xlb_const( "SIID_VIDEOFILES,", SIID_VIDEOFILES ),
        xlb_const( "SIID_MIXEDFILES,", SIID_MIXEDFILES ),
        xlb_const( "SIID_FOLDERBACK,", SIID_FOLDERBACK ),
        xlb_const( "SIID_FOLDERFRONT,", SIID_FOLDERFRONT ),
        xlb_const( "SIID_SHIELD,", SIID_SHIELD ), 
        xlb_const( "SIID_WARNING,", SIID_WARNING ),
        xlb_const( "SIID_INFO,", SIID_INFO ), 
        xlb_const( "SIID_ERROR,", SIID_ERROR ),
        xlb_const( "SIID_KEY,", SIID_KEY ), 
        xlb_const( "SIID_SOFTWARE,", SIID_SOFTWARE ),
        xlb_const( "SIID_RENAME,", SIID_RENAME ), 
        xlb_const( "SIID_DELETE,", SIID_DELETE ),
        xlb_const( "SIID_MEDIAAUDIODVD,", SIID_MEDIAAUDIODVD ),
        xlb_const( "SIID_MEDIAMOVIEDVD,", SIID_MEDIAMOVIEDVD ),
        xlb_const( "SIID_MEDIAENHANCEDCD,", SIID_MEDIAENHANCEDCD ),
        xlb_const( "SIID_MEDIAENHANCEDDVD,", SIID_MEDIAENHANCEDDVD ),
        xlb_const( "SIID_MEDIAHDDVD,", SIID_MEDIAHDDVD ),
        xlb_const( "SIID_MEDIABLURAY,", SIID_MEDIABLURAY ),
        xlb_const( "SIID_MEDIAVCD,", SIID_MEDIAVCD ),
        xlb_const( "SIID_MEDIADVDPLUSR,", SIID_MEDIADVDPLUSR ),
        xlb_const( "SIID_MEDIADVDPLUSRW,", SIID_MEDIADVDPLUSRW ),
        xlb_const( "SIID_DESKTOPPC,", SIID_DESKTOPPC ),
        xlb_const( "SIID_MOBILEPC,", SIID_MOBILEPC ), 
        xlb_const( "SIID_USERS,", SIID_USERS ),
        xlb_const( "SIID_MEDIASMARTMEDIA,", SIID_MEDIASMARTMEDIA ),
        xlb_const( "SIID_MEDIACOMPACTFLASH,", SIID_MEDIACOMPACTFLASH ),
        xlb_const( "SIID_DEVICECELLPHONE,", SIID_DEVICECELLPHONE ),
        xlb_const( "SIID_DEVICECAMERA,", SIID_DEVICECAMERA ),
        xlb_const( "SIID_DEVICEVIDEOCAMERA,", SIID_DEVICEVIDEOCAMERA ),
        xlb_const( "SIID_DEVICEAUDIOPLAYER,", SIID_DEVICEAUDIOPLAYER ),
        xlb_const( "SIID_NETWORKCONNECT,", SIID_NETWORKCONNECT ),
        xlb_const( "SIID_INTERNET,", SIID_INTERNET ),
        xlb_const( "SIID_ZIPFILE,", SIID_ZIPFILE ),
        xlb_const( "SIID_SETTINGS,", SIID_SETTINGS ),
        xlb_const( "SIID_DRIVEHDDVD,", SIID_DRIVEHDDVD ),
        xlb_const( "SIID_DRIVEBD,", SIID_DRIVEBD ),
        xlb_const( "SIID_MEDIAHDDVDROM,", SIID_MEDIAHDDVDROM ),
        xlb_const( "SIID_MEDIAHDDVDR,", SIID_MEDIAHDDVDR ),
        xlb_const( "SIID_MEDIAHDDVDRAM,", SIID_MEDIAHDDVDRAM ),
        xlb_const( "SIID_MEDIABDROM,", SIID_MEDIABDROM ),
        xlb_const( "SIID_MEDIABDR,", SIID_MEDIABDR ),
        xlb_const( "SIID_MEDIABDRE,", SIID_MEDIABDRE ),
        xlb_const( "SIID_CLUSTEREDDRIVE,", SIID_CLUSTEREDDRIVE ),
        xlb_const( "SIID_MAX_ICONS", SIID_MAX_ICONS ),

        //_SIGDN
        xlb_const( "SIGDN_NORMALDISPLAY,", SIGDN_NORMALDISPLAY ),
        xlb_const( "SIGDN_PARENTRELATIVEPARSING,", SIGDN_PARENTRELATIVEPARSING ),
        xlb_const( "SIGDN_DESKTOPABSOLUTEPARSING,", SIGDN_DESKTOPABSOLUTEPARSING ),
        xlb_const( "SIGDN_PARENTRELATIVEEDITING,", SIGDN_PARENTRELATIVEEDITING ),
        xlb_const( "SIGDN_DESKTOPABSOLUTEEDITING,", SIGDN_DESKTOPABSOLUTEEDITING ),
        xlb_const( "SIGDN_FILESYSPATH,", SIGDN_FILESYSPATH ),
        xlb_const( "SIGDN_URL,", SIGDN_URL ),
        xlb_const( "SIGDN_PARENTRELATIVEFORADDRESSBAR,", SIGDN_PARENTRELATIVEFORADDRESSBAR ),
        xlb_const( "SIGDN_PARENTRELATIVE,", SIGDN_PARENTRELATIVE ),
        xlb_const( "SIGDN_PARENTRELATIVEFORUI", SIGDN_PARENTRELATIVEFORUI ),

        //_SPACTION
        xlb_const( "SPACTION_NONE,", SPACTION_NONE ),
        xlb_const( "SPACTION_MOVING,", SPACTION_MOVING ),
        xlb_const( "SPACTION_COPYING,", SPACTION_COPYING ),
        xlb_const( "SPACTION_RECYCLING,", SPACTION_RECYCLING ),
        xlb_const( "SPACTION_APPLYINGATTRIBS,", SPACTION_APPLYINGATTRIBS ),
        xlb_const( "SPACTION_DOWNLOADING,", SPACTION_DOWNLOADING ),
        xlb_const( "SPACTION_SEARCHING_INTERNET,", SPACTION_SEARCHING_INTERNET ),
        xlb_const( "SPACTION_CALCULATING,", SPACTION_CALCULATING ),
        xlb_const( "SPACTION_UPLOADING,", SPACTION_UPLOADING ),
        xlb_const( "SPACTION_SEARCHING_FILES,", SPACTION_SEARCHING_FILES ),
        xlb_const( "SPACTION_DELETING,", SPACTION_DELETING ),
        xlb_const( "SPACTION_RENAMING,", SPACTION_RENAMING ),
        xlb_const( "SPACTION_FORMATTING,", SPACTION_FORMATTING ),
        xlb_const( "SPACTION_COPY_MOVING", SPACTION_COPY_MOVING ),

        //_SPTEXT
        xlb_const( "SPTEXT_ACTIONDESCRIPTION,", SPTEXT_ACTIONDESCRIPTION ),
        xlb_const( "SPTEXT_ACTIONDETAIL", SPTEXT_ACTIONDETAIL ),

        // STPFLAG
        xlb_const( "STPF_NONE,", STPF_NONE ),
        xlb_const( "STPF_USEAPPTHUMBNAILALWAYS,", STPF_USEAPPTHUMBNAILALWAYS ),
        xlb_const( "STPF_USEAPPTHUMBNAILWHENACTIVE,", STPF_USEAPPTHUMBNAILWHENACTIVE ),
        xlb_const( "STPF_USEAPPPEEKALWAYS,", STPF_USEAPPPEEKALWAYS ),
        xlb_const( "STPF_USEAPPPEEKWHENACTIVE", STPF_USEAPPPEEKWHENACTIVE ),

        // SVUIA_STATUS
        xlb_const( "SVUIA_DEACTIVATE,", SVUIA_DEACTIVATE ),
        xlb_const( "SVUIA_ACTIVATE_NOFOCUS,", SVUIA_ACTIVATE_NOFOCUS ),
        xlb_const( "SVUIA_ACTIVATE_FOCUS,", SVUIA_ACTIVATE_FOCUS ),
        xlb_const( "SVUIA_INPLACEACTIVATE", SVUIA_INPLACEACTIVATE ),

        // SYNCMGR_CANCEL_REQUEST
        xlb_const( "SYNCMGR_CR_NONE,", SYNCMGR_CR_NONE ),
        xlb_const( "SYNCMGR_CR_CANCEL_ITEM,", SYNCMGR_CR_CANCEL_ITEM ),
        xlb_const( "SYNCMGR_CR_CANCEL_ALL,", SYNCMGR_CR_CANCEL_ALL ),
        xlb_const( "SYNCMGR_CR_MAX", SYNCMGR_CR_MAX ),

        // SYNCMGR_CONFLICT_ITEM_TYPE
        xlb_const( "SYNCMGR_CIT_UPDATED,", SYNCMGR_CIT_UPDATED ),
        xlb_const( "SYNCMGR_CIT_DELETED", SYNCMGR_CIT_DELETED ),

        // SYNCMGR_CONTROL_FLAGS
        xlb_const( "SYNCMGR_CF_NONE,", SYNCMGR_CF_NONE ),
        xlb_const( "SYNCMGR_CF_NOWAIT,", SYNCMGR_CF_NOWAIT ),
        xlb_const( "SYNCMGR_CF_WAIT,", SYNCMGR_CF_WAIT ),
        xlb_const( "SYNCMGR_CF_NOUI,", SYNCMGR_CF_NOUI ),
        xlb_const( "SYNCMGR_CF_VALID", SYNCMGR_CF_VALID ),

        // SYNCMGR_EVENT_FLAGS
        xlb_const( "SYNCMGR_EF_NONE,", SYNCMGR_EF_NONE ),
        xlb_const( "SYNCMGR_EF_VALID", SYNCMGR_EF_VALID ),

        // SYNCMGR_EVENT_LEVEL
        xlb_const( "SYNCMGR_EL_INFORMATION,", SYNCMGR_EL_INFORMATION ),
        xlb_const( "SYNCMGR_EL_WARNING,", SYNCMGR_EL_WARNING ),
        xlb_const( "SYNCMGR_EL_ERROR,", SYNCMGR_EL_ERROR ),
        xlb_const( "SYNCMGR_EL_MAX", SYNCMGR_EL_MAX ),

        // SYNCMGR_HANDLER_CAPABILITIES
        xlb_const( "SYNCMGR_HCM_NONE,", SYNCMGR_HCM_NONE ),
        xlb_const( "SYNCMGR_HCM_PROVIDES_ICON,", SYNCMGR_HCM_PROVIDES_ICON ),
        xlb_const( "SYNCMGR_HCM_EVENT_STORE,", SYNCMGR_HCM_EVENT_STORE ),
        xlb_const( "SYNCMGR_HCM_CONFLICT_STORE,", SYNCMGR_HCM_CONFLICT_STORE ),
        xlb_const( "SYNCMGR_HCM_SUPPORTS_CONCURRENT_SESSIONS,",
                   SYNCMGR_HCM_SUPPORTS_CONCURRENT_SESSIONS ),
        xlb_const( "SYNCMGR_HCM_CAN_BROWSE_CONTENT,", SYNCMGR_HCM_CAN_BROWSE_CONTENT ),
        xlb_const( "SYNCMGR_HCM_CAN_SHOW_SCHEDULE,", SYNCMGR_HCM_CAN_SHOW_SCHEDULE ),
        xlb_const( "SYNCMGR_HCM_QUERY_BEFORE_ACTIVATE,", SYNCMGR_HCM_QUERY_BEFORE_ACTIVATE ),
        xlb_const( "SYNCMGR_HCM_QUERY_BEFORE_DEACTIVATE,",
                   SYNCMGR_HCM_QUERY_BEFORE_DEACTIVATE ),
        xlb_const( "SYNCMGR_HCM_QUERY_BEFORE_ENABLE,", SYNCMGR_HCM_QUERY_BEFORE_ENABLE ),
        xlb_const( "SYNCMGR_HCM_QUERY_BEFORE_DISABLE,", SYNCMGR_HCM_QUERY_BEFORE_DISABLE ),
        xlb_const( "SYNCMGR_HCM_VALID_MASK", SYNCMGR_HCM_VALID_MASK ),

        // SYNCMGR_HANDLER_POLICIES
        xlb_const( "SYNCMGR_HPM_NONE,", SYNCMGR_HPM_NONE ),
        xlb_const( "SYNCMGR_HPM_PREVENT_ACTIVATE,", SYNCMGR_HPM_PREVENT_ACTIVATE ),
        xlb_const( "SYNCMGR_HPM_PREVENT_DEACTIVATE,", SYNCMGR_HPM_PREVENT_DEACTIVATE ),
        xlb_const( "SYNCMGR_HPM_PREVENT_ENABLE,", SYNCMGR_HPM_PREVENT_ENABLE ),
        xlb_const( "SYNCMGR_HPM_PREVENT_DISABLE,", SYNCMGR_HPM_PREVENT_DISABLE ),
        xlb_const( "SYNCMGR_HPM_PREVENT_START_SYNC,", SYNCMGR_HPM_PREVENT_START_SYNC ),
        xlb_const( "SYNCMGR_HPM_PREVENT_STOP_SYNC,", SYNCMGR_HPM_PREVENT_STOP_SYNC ),
        xlb_const( "SYNCMGR_HPM_DISABLE_ENABLE,", SYNCMGR_HPM_DISABLE_ENABLE ),
        xlb_const( "SYNCMGR_HPM_DISABLE_DISABLE,", SYNCMGR_HPM_DISABLE_DISABLE ),
        xlb_const( "SYNCMGR_HPM_DISABLE_START_SYNC,", SYNCMGR_HPM_DISABLE_START_SYNC ),
        xlb_const( "SYNCMGR_HPM_DISABLE_STOP_SYNC,", SYNCMGR_HPM_DISABLE_STOP_SYNC ),
        xlb_const( "SYNCMGR_HPM_DISABLE_BROWSE,", SYNCMGR_HPM_DISABLE_BROWSE ),
        xlb_const( "SYNCMGR_HPM_DISABLE_SCHEDULE,", SYNCMGR_HPM_DISABLE_SCHEDULE ),
        xlb_const( "SYNCMGR_HPM_HIDDEN_BY_DEFAULT,", SYNCMGR_HPM_HIDDEN_BY_DEFAULT ),
        xlb_const( "SYNCMGR_HPM_BACKGROUND_SYNC_ONLY,", SYNCMGR_HPM_BACKGROUND_SYNC_ONLY ),
        xlb_const( "SYNCMGR_HPM_VALID_MASK", SYNCMGR_HPM_VALID_MASK ),

        // SYNCMGR_HANDLER_TYPE
        xlb_const( "SYNCMGR_HT_UNSPECIFIED,", SYNCMGR_HT_UNSPECIFIED ),
        xlb_const( "SYNCMGR_HT_APPLICATION,", SYNCMGR_HT_APPLICATION ),
        xlb_const( "SYNCMGR_HT_DEVICE,", SYNCMGR_HT_DEVICE ),
        xlb_const( "SYNCMGR_HT_FOLDER,", SYNCMGR_HT_FOLDER ),
        xlb_const( "SYNCMGR_HT_SERVICE,", SYNCMGR_HT_SERVICE ),
        xlb_const( "SYNCMGR_HT_COMPUTER,", SYNCMGR_HT_COMPUTER ),
        xlb_const( "SYNCMGR_HT_MIN,", SYNCMGR_HT_MIN ),
        xlb_const( "SYNCMGR_HT_MAX", SYNCMGR_HT_MAX ),

        // SYNCMGR_ITEM_CAPABILITIES
        xlb_const( "SYNCMGR_ICM_NONE,", SYNCMGR_ICM_NONE ),
        xlb_const( "SYNCMGR_ICM_PROVIDES_ICON,", SYNCMGR_ICM_PROVIDES_ICON ),
        xlb_const( "SYNCMGR_ICM_EVENT_STORE,", SYNCMGR_ICM_EVENT_STORE ),
        xlb_const( "SYNCMGR_ICM_CONFLICT_STORE,", SYNCMGR_ICM_CONFLICT_STORE ),
        xlb_const( "SYNCMGR_ICM_CAN_DELETE,", SYNCMGR_ICM_CAN_DELETE ),
        xlb_const( "SYNCMGR_ICM_CAN_BROWSE_CONTENT,", SYNCMGR_ICM_CAN_BROWSE_CONTENT ),
        xlb_const( "SYNCMGR_ICM_QUERY_BEFORE_ENABLE,", SYNCMGR_ICM_QUERY_BEFORE_ENABLE ),
        xlb_const( "SYNCMGR_ICM_QUERY_BEFORE_DISABLE,", SYNCMGR_ICM_QUERY_BEFORE_DISABLE ),
        xlb_const( "SYNCMGR_ICM_QUERY_BEFORE_DELETE,", SYNCMGR_ICM_QUERY_BEFORE_DELETE ),
        xlb_const( "SYNCMGR_ICM_VALID_MASK", SYNCMGR_ICM_VALID_MASK ),

        // SYNCMGR_ITEM_POLICIES
        xlb_const( "SYNCMGR_IPM_NONE,", SYNCMGR_IPM_NONE ),
        xlb_const( "SYNCMGR_IPM_PREVENT_ENABLE,", SYNCMGR_IPM_PREVENT_ENABLE ),
        xlb_const( "SYNCMGR_IPM_PREVENT_DISABLE,", SYNCMGR_IPM_PREVENT_DISABLE ),
        xlb_const( "SYNCMGR_IPM_PREVENT_START_SYNC,", SYNCMGR_IPM_PREVENT_START_SYNC ),
        xlb_const( "SYNCMGR_IPM_PREVENT_STOP_SYNC,", SYNCMGR_IPM_PREVENT_STOP_SYNC ),
        xlb_const( "SYNCMGR_IPM_DISABLE_ENABLE,", SYNCMGR_IPM_DISABLE_ENABLE ),
        xlb_const( "SYNCMGR_IPM_DISABLE_DISABLE,", SYNCMGR_IPM_DISABLE_DISABLE ),
        xlb_const( "SYNCMGR_IPM_DISABLE_START_SYNC,", SYNCMGR_IPM_DISABLE_START_SYNC ),
        xlb_const( "SYNCMGR_IPM_DISABLE_STOP_SYNC,", SYNCMGR_IPM_DISABLE_STOP_SYNC ),
        xlb_const( "SYNCMGR_IPM_DISABLE_BROWSE,", SYNCMGR_IPM_DISABLE_BROWSE ),
        xlb_const( "SYNCMGR_IPM_DISABLE_DELETE,", SYNCMGR_IPM_DISABLE_DELETE ),
        xlb_const( "SYNCMGR_IPM_HIDDEN_BY_DEFAULT,", SYNCMGR_IPM_HIDDEN_BY_DEFAULT ),
        xlb_const( "SYNCMGR_IPM_VALID_MASK", SYNCMGR_IPM_VALID_MASK ),

        // SYNCMGR_PRESENTER_CHOICE
        xlb_const( "SYNCMGR_PC_NO_CHOICE,", SYNCMGR_PC_NO_CHOICE ),
        xlb_const( "SYNCMGR_PC_KEEP_ONE,", SYNCMGR_PC_KEEP_ONE ),
        xlb_const( "SYNCMGR_PC_KEEP_MULTIPLE,", SYNCMGR_PC_KEEP_MULTIPLE ),
        xlb_const( "SYNCMGR_PC_KEEP_RECENT,", SYNCMGR_PC_KEEP_RECENT ),
        xlb_const( "SYNCMGR_PC_REMOVE_FROM_SYNC_SET,", SYNCMGR_PC_REMOVE_FROM_SYNC_SET ),
        xlb_const( "SYNCMGR_PC_SKIP", SYNCMGR_PC_SKIP ),

        // SYNCMGR_PRESENTER_NEXT_STEP
        xlb_const( "SYNCMGR_PNS_CONTINUE,", SYNCMGR_PNS_CONTINUE ),
        xlb_const( "SYNCMGR_PNS_DEFAULT,", SYNCMGR_PNS_DEFAULT ),
        xlb_const( "SYNCMGR_PNS_CANCEL", SYNCMGR_PNS_CANCEL ),

        // SYNCMGR_PROGRESS_STATUS
        xlb_const( "SYNCMGR_PS_UPDATING,", SYNCMGR_PS_UPDATING ),
        xlb_const( "SYNCMGR_PS_UPDATING_INDETERMINATE,", SYNCMGR_PS_UPDATING_INDETERMINATE ),
        xlb_const( "SYNCMGR_PS_SUCCEEDED,", SYNCMGR_PS_SUCCEEDED ),
        xlb_const( "SYNCMGR_PS_FAILED,", SYNCMGR_PS_FAILED ),
        xlb_const( "SYNCMGR_PS_CANCELED,", SYNCMGR_PS_CANCELED ),
        xlb_const( "SYNCMGR_PS_DISCONNECTED,", SYNCMGR_PS_DISCONNECTED ),
        xlb_const( "SYNCMGR_PS_MAX", SYNCMGR_PS_MAX ),

        // SYNCMGR_RESOLUTION_ABILITIES
        xlb_const( "SYNCMGR_RA_KEEPOTHER,", SYNCMGR_RA_KEEPOTHER ),
        xlb_const( "SYNCMGR_RA_KEEPRECENT,", SYNCMGR_RA_KEEPRECENT ),
        xlb_const( "SYNCMGR_RA_REMOVEFROMSYNCSET,", SYNCMGR_RA_REMOVEFROMSYNCSET ),
        xlb_const( "SYNCMGR_RA_KEEP_SINGLE,", SYNCMGR_RA_KEEP_SINGLE ),
        xlb_const( "SYNCMGR_RA_KEEP_MULTIPLE,", SYNCMGR_RA_KEEP_MULTIPLE ),
        xlb_const( "SYNCMGR_RA_VALID", SYNCMGR_RA_VALID ),

        // SYNCMGR_RESOLUTION_FEEDBACK
        xlb_const( "SYNCMGR_RF_CONTINUE,", SYNCMGR_RF_CONTINUE ),
        xlb_const( "SYNCMGR_RF_REFRESH,", SYNCMGR_RF_REFRESH ),
        xlb_const( "SYNCMGR_RF_CANCEL", SYNCMGR_RF_CANCEL ),

        // SYNCMGR_SYNC_CONTROL_FLAGS
        xlb_const( "SYNCMGR_SCF_NONE,", SYNCMGR_SCF_NONE ),
        xlb_const( "SYNCMGR_SCF_IGNORE_IF_ALREADY_SYNCING,",
                   SYNCMGR_SCF_IGNORE_IF_ALREADY_SYNCING ),
        xlb_const( "SYNCMGR_SCF_VALID", SYNCMGR_SCF_VALID ),

        //_tagSYNCMGRFLAG
        xlb_const( "SYNCMGRFLAG_CONNECT,", SYNCMGRFLAG_CONNECT ),
        xlb_const( "SYNCMGRFLAG_PENDINGDISCONNECT,", SYNCMGRFLAG_PENDINGDISCONNECT ),
        xlb_const( "SYNCMGRFLAG_MANUAL,", SYNCMGRFLAG_MANUAL ),
        xlb_const( "SYNCMGRFLAG_IDLE,", SYNCMGRFLAG_IDLE ),
        xlb_const( "SYNCMGRFLAG_INVOKE,", SYNCMGRFLAG_INVOKE ),
        xlb_const( "SYNCMGRFLAG_SCHEDULED,", SYNCMGRFLAG_SCHEDULED ),
        xlb_const( "SYNCMGRFLAG_EVENTMASK,", SYNCMGRFLAG_EVENTMASK ),
        xlb_const( "SYNCMGRFLAG_SETTINGS,", SYNCMGRFLAG_SETTINGS ),
        xlb_const( "SYNCMGRFLAG_MAYBOTHERUSER", SYNCMGRFLAG_MAYBOTHERUSER ),

        //_tagSYNCMGRHANDLERFLAGS
        xlb_const( "SYNCMGRHANDLER_HASPROPERTIES,", SYNCMGRHANDLER_HASPROPERTIES ),
        xlb_const( "SYNCMGRHANDLER_MAYESTABLISHCONNECTION,",
                   SYNCMGRHANDLER_MAYESTABLISHCONNECTION ),
        xlb_const( "SYNCMGRHANDLER_ALWAYSLISTHANDLER,", SYNCMGRHANDLER_ALWAYSLISTHANDLER ),
        xlb_const( "SYNCMGRHANDLER_HIDDEN", SYNCMGRHANDLER_HIDDEN ),

        //_tagSYNCMGRINVOKEFLAGS
        xlb_const( "SYNCMGRINVOKE_STARTSYNC,", SYNCMGRINVOKE_STARTSYNC ),
        xlb_const( "SYNCMGRINVOKE_MINIMIZED", SYNCMGRINVOKE_MINIMIZED ),

        //_tagSYNCMGRITEMFLAGS
        xlb_const( "SYNCMGRITEM_HASPROPERTIES,", SYNCMGRITEM_HASPROPERTIES ),
        xlb_const( "SYNCMGRITEM_TEMPORARY,", SYNCMGRITEM_TEMPORARY ),
        xlb_const( "SYNCMGRITEM_ROAMINGUSER,", SYNCMGRITEM_ROAMINGUSER ),
        xlb_const( "SYNCMGRITEM_LASTUPDATETIME,", SYNCMGRITEM_LASTUPDATETIME ),
        xlb_const( "SYNCMGRITEM_MAYDELETEITEM,", SYNCMGRITEM_MAYDELETEITEM ),
        xlb_const( "SYNCMGRITEM_HIDDEN", SYNCMGRITEM_HIDDEN ),

        //_tagSYNCMGRLOGLEVEL
        xlb_const( "SYNCMGRLOGLEVEL_INFORMATION,", SYNCMGRLOGLEVEL_INFORMATION ),
        xlb_const( "SYNCMGRLOGLEVEL_WARNING,", SYNCMGRLOGLEVEL_WARNING ),
        xlb_const( "SYNCMGRLOGLEVEL_ERROR,", SYNCMGRLOGLEVEL_ERROR ),
        xlb_const( "SYNCMGRLOGLEVEL_LOGLEVELMAX", SYNCMGRLOGLEVEL_LOGLEVELMAX ),

        //_tagSYNCMGRREGISTERFLAGS
        xlb_const( "SYNCMGRREGISTERFLAG_CONNECT,", SYNCMGRREGISTERFLAG_CONNECT ),
        xlb_const( "SYNCMGRREGISTERFLAG_PENDINGDISCONNECT,",
                   SYNCMGRREGISTERFLAG_PENDINGDISCONNECT ),
        xlb_const( "SYNCMGRREGISTERFLAG_IDLE", SYNCMGRREGISTERFLAG_IDLE ),

        //_tagSYNCMGRSTATUS
        xlb_const( "SYNCMGRSTATUS_STOPPED,", SYNCMGRSTATUS_STOPPED ),
        xlb_const( "SYNCMGRSTATUS_SKIPPED,", SYNCMGRSTATUS_SKIPPED ),
        xlb_const( "SYNCMGRSTATUS_PENDING,", SYNCMGRSTATUS_PENDING ),
        xlb_const( "SYNCMGRSTATUS_UPDATING,", SYNCMGRSTATUS_UPDATING ),
        xlb_const( "SYNCMGRSTATUS_SUCCEEDED,", SYNCMGRSTATUS_SUCCEEDED ),
        xlb_const( "SYNCMGRSTATUS_FAILED,", SYNCMGRSTATUS_FAILED ),
        xlb_const( "SYNCMGRSTATUS_PAUSED,", SYNCMGRSTATUS_PAUSED ),
        xlb_const( "SYNCMGRSTATUS_RESUMING,", SYNCMGRSTATUS_RESUMING ),
        xlb_const( "SYNCMGRSTATUS_UPDATING_INDETERMINATE,",
                   SYNCMGRSTATUS_UPDATING_INDETERMINATE ),
        xlb_const( "SYNCMGRSTATUS_DELETED", SYNCMGRSTATUS_DELETED ),

        // tagDESKBANDCID
        xlb_const( "DBID_BANDINFOCHANGED,", DBID_BANDINFOCHANGED ),
        xlb_const( "DBID_SHOWONLY,", DBID_SHOWONLY ),
        xlb_const( "DBID_MAXIMIZEBAND,", DBID_MAXIMIZEBAND ),
        xlb_const( "DBID_PUSHCHEVRON,", DBID_PUSHCHEVRON ),
        xlb_const( "DBID_DELAYINIT,", DBID_DELAYINIT ),
        xlb_const( "DBID_FINISHINIT,", DBID_FINISHINIT ),
        xlb_const( "DBID_SETWINDOWTHEME,", DBID_SETWINDOWTHEME ),
        xlb_const( "DBID_PERMITAUTOHIDE", DBID_PERMITAUTOHIDE ),

        // tagSFBS_FLAGS
        xlb_const( "SFBS_FLAGS_ROUND_TO_NEAREST_DISPLAYED_DIGIT,",
                   SFBS_FLAGS_ROUND_TO_NEAREST_DISPLAYED_DIGIT ),
        xlb_const( "SFBS_FLAGS_TRUNCATE_UNDISPLAYED_DECIMAL_DIGITS",
                   SFBS_FLAGS_TRUNCATE_UNDISPLAYED_DECIMAL_DIGITS ),

        // THUMBBUTTONFLAGS
        xlb_const( "THBF_ENABLED,", THBF_ENABLED ),
        xlb_const( "THBF_DISABLED,", THBF_DISABLED ),
        xlb_const( "THBF_DISMISSONCLICK,", THBF_DISMISSONCLICK ),
        xlb_const( "THBF_NOBACKGROUND,", THBF_NOBACKGROUND ),
        xlb_const( "THBF_HIDDEN,", THBF_HIDDEN ),
        xlb_const( "THBF_NONINTERACTIVE", THBF_NONINTERACTIVE ),

        // THUMBBUTTONMASK
        xlb_const( "THB_BITMAP,", THB_BITMAP ), 
        xlb_const( "THB_ICON,", THB_ICON ),
        xlb_const( "THB_TOOLTIP,", THB_TOOLTIP ), 
        xlb_const( "THB_FLAGS", THB_FLAGS ),

        // ThumbnailStreamCacheOptions
        xlb_const( "ExtractIfNotCached,", ExtractIfNotCached ),
        xlb_const( "ReturnOnlyIfCached,", ReturnOnlyIfCached ),
        xlb_const( "ResizeThumbnail,", ResizeThumbnail ),
        xlb_const( "AllowSmallerSize", AllowSmallerSize ),

        // translateurl_in_flags
        xlb_const( "TRANSLATEURL_FL_GUESS_PROTOCOL,", TRANSLATEURL_FL_GUESS_PROTOCOL ),
        xlb_const( "TRANSLATEURL_FL_USE_DEFAULT_PROTOCOL",
                   TRANSLATEURL_FL_USE_DEFAULT_PROTOCOL ),

        // UNDOCK_REASON
        xlb_const( "UR_RESOLUTION_CHANGE,", UR_RESOLUTION_CHANGE ),
        xlb_const( "UR_MONITOR_DISCONNECT", UR_MONITOR_DISCONNECT ),

        // URL_SCHEME
        xlb_const( "URL_SCHEME_INVALID,", URL_SCHEME_INVALID ),
        xlb_const( "URL_SCHEME_UNKNOWN,", URL_SCHEME_UNKNOWN ),
        xlb_const( "URL_SCHEME_FTP,", URL_SCHEME_FTP ),
        xlb_const( "URL_SCHEME_HTTP,", URL_SCHEME_HTTP ),
        xlb_const( "URL_SCHEME_GOPHER,", URL_SCHEME_GOPHER ),
        xlb_const( "URL_SCHEME_MAILTO,", URL_SCHEME_MAILTO ),
        xlb_const( "URL_SCHEME_NEWS,", URL_SCHEME_NEWS ),
        xlb_const( "URL_SCHEME_NNTP,", URL_SCHEME_NNTP ),
        xlb_const( "URL_SCHEME_TELNET,", URL_SCHEME_TELNET ),
        xlb_const( "URL_SCHEME_WAIS,", URL_SCHEME_WAIS ),
        xlb_const( "URL_SCHEME_FILE,", URL_SCHEME_FILE ),
        xlb_const( "URL_SCHEME_MK,", URL_SCHEME_MK ),
        xlb_const( "URL_SCHEME_HTTPS,", URL_SCHEME_HTTPS ),
        xlb_const( "URL_SCHEME_SHELL,", URL_SCHEME_SHELL ),
        xlb_const( "URL_SCHEME_SNEWS,", URL_SCHEME_SNEWS ),
        xlb_const( "URL_SCHEME_LOCAL,", URL_SCHEME_LOCAL ),
        xlb_const( "URL_SCHEME_JAVASCRIPT,", URL_SCHEME_JAVASCRIPT ),
        xlb_const( "URL_SCHEME_VBSCRIPT,", URL_SCHEME_VBSCRIPT ),
        xlb_const( "URL_SCHEME_ABOUT,", URL_SCHEME_ABOUT ),
        xlb_const( "URL_SCHEME_RES,", URL_SCHEME_RES ),
        xlb_const( "URL_SCHEME_MSSHELLROOTED,", URL_SCHEME_MSSHELLROOTED ),
        xlb_const( "URL_SCHEME_MSSHELLIDLIST,", URL_SCHEME_MSSHELLIDLIST ),
        xlb_const( "URL_SCHEME_MSHELP,", URL_SCHEME_MSHELP ),
        xlb_const( "URL_SCHEME_MSSHELLDEVICE,", URL_SCHEME_MSSHELLDEVICE ),
        xlb_const( "URL_SCHEME_WILDCARD,", URL_SCHEME_WILDCARD ),
        xlb_const( "URL_SCHEME_SEARCH_MS,", URL_SCHEME_SEARCH_MS ),
        xlb_const( "URL_SCHEME_SEARCH,", URL_SCHEME_SEARCH ),
        xlb_const( "URL_SCHEME_KNOWNFOLDER,", URL_SCHEME_KNOWNFOLDER ),
        xlb_const( "URL_SCHEME_MAXVALUE", URL_SCHEME_MAXVALUE ),

        // urlassociationdialog_in_flags
        xlb_const( "URLASSOCDLG_FL_USE_DEFAULT_NAME,", URLASSOCDLG_FL_USE_DEFAULT_NAME ),
        xlb_const( "URLASSOCDLG_FL_REGISTER_ASSOC", URLASSOCDLG_FL_REGISTER_ASSOC ),

        // VPCOLORFLAGS
        xlb_const( "VPCF_TEXT,", VPCF_TEXT ),
        xlb_const( "VPCF_BACKGROUND,", VPCF_BACKGROUND ),
        xlb_const( "VPCF_SORTCOLUMN,", VPCF_SORTCOLUMN ),
        xlb_const( "VPCF_SUBTEXT,", VPCF_SUBTEXT ),
        xlb_const( "VPCF_TEXTBACKGROUND", VPCF_TEXTBACKGROUND ),

        // VPWATERMARKFLAGS
        xlb_const( "VPWF_DEFAULT,", VPWF_DEFAULT ),
        xlb_const( "VPWF_ALPHABLEND", VPWF_ALPHABLEND ),

        // WTS_CONTEXTFLAGS
        xlb_const( "WTSCF_DEFAULT,", WTSCF_DEFAULT ),
        xlb_const( "WTSCF_APPSTYLE,", WTSCF_APPSTYLE ),
        xlb_const( "WTSCF_SQUARE,", WTSCF_SQUARE ), 
        xlb_const( "WTSCF_WIDE,", WTSCF_WIDE ),
        xlb_const( "WTSCF_FAST", WTSCF_FAST ),

        // WTS_FLAGS
        xlb_const( "WTS_NONE,", WTS_NONE ), 
        xlb_const( "WTS_EXTRACT,", WTS_EXTRACT ),
        xlb_const( "WTS_INCACHEONLY,", WTS_INCACHEONLY ),
        xlb_const( "WTS_FASTEXTRACT,", WTS_FASTEXTRACT ),
        xlb_const( "WTS_FORCEEXTRACTION,", WTS_FORCEEXTRACTION ),
        xlb_const( "WTS_SLOWRECLAIM,", WTS_SLOWRECLAIM ),
        xlb_const( "WTS_EXTRACTDONOTCACHE,", WTS_EXTRACTDONOTCACHE ),
        xlb_const( "WTS_SCALETOREQUESTEDSIZE,", WTS_SCALETOREQUESTEDSIZE ),
        xlb_const( "WTS_SKIPFASTEXTRACT,", WTS_SKIPFASTEXTRACT ),
        xlb_const( "WTS_EXTRACTINPROC,", WTS_EXTRACTINPROC ),
        xlb_const( "WTS_CROPTOSQUARE,", WTS_CROPTOSQUARE ),
        xlb_const( "WTS_INSTANCESURROGATE,", WTS_INSTANCESURROGATE ),
        xlb_const( "WTS_REQUIRESURROGATE,", WTS_REQUIRESURROGATE ),
        xlb_const( "WTS_APPSTYLE,", WTS_APPSTYLE ),
        xlb_const( "WTS_WIDETHUMBNAILS,", WTS_WIDETHUMBNAILS ),
        xlb_const( "WTS_IDEALCACHESIZEONLY,", WTS_IDEALCACHESIZEONLY ),
        xlb_const( "WTS_SCALEUP", WTS_SCALEUP ),

        // Functions
        // xlb_f("_CancelPendingNavigationAsync", _CancelPendingNavigationAsync), //
        // deprecated xlb_f("_CancelPendingView", _CancelPendingView), // deprecated
        // xlb_f("_CloseAndReleaseToolbars", _CloseAndReleaseToolbars), // deprecated
        // xlb_f("_DisableModeless", _DisableModeless), // deprecated
        // xlb_f("_ExecChildren", _ExecChildren), // deprecated
        // xlb_f("_FindTBar", _FindTBar), // deprecated
        // xlb_f("_get_itbLastFocus", _get_itbLastFocus), // deprecated
        // xlb_f("_GetBorderDWHelper", _GetBorderDWHelper), // deprecated
        // xlb_f("_GetEffectiveClientArea", _GetEffectiveClientArea), // deprecated
        // xlb_f("_GetToolbarCount", _GetToolbarCount), // deprecated
        // xlb_f("_GetToolbarItem", _GetToolbarItem), // deprecated
        // xlb_f("_GetViewBorderRect", _GetViewBorderRect), // deprecated
        // xlb_f("_Initialize", _Initialize), // deprecated
        // xlb_f("_LoadToolbars", _LoadToolbars), // deprecated
        // xlb_f("_MaySaveChanges", _MaySaveChanges), // deprecated
        // xlb_f("_NavigateToPidl", _NavigateToPidl), // deprecated
        // xlb_f("_NewEnum", _NewEnum), // deprecated
        // xlb_f("_OnFocusChange", _OnFocusChange), // deprecated
        // xlb_f("_PauseOrResumeView", _PauseOrResumeView), // deprecated
        // xlb_f("_PositionViewWindow", _PositionViewWindow),// deprecated
        // xlb_f("_put_itbLastFocus", _put_itbLastFocus),// deprecated
        // xlb_f("_ResizeAllBorders", _ResizeAllBorders),// deprecated
        // xlb_f("_ResizeNextBorder", _ResizeNextBorder),// deprecated
        // xlb_f("_ResizeNextBorderHelper", _ResizeNextBorderHelper),// deprecated
        // xlb_f("_ResizeView", _ResizeView),// deprecated
        // xlb_f("_SaveToolbars", _SaveToolbars),// deprecated
        // xlb_f("_SendChildren", _SendChildren),// deprecated
        // xlb_f("_SetFocus", _SetFocus),// deprecated
        // xlb_f("_SwitchActivationNow", _SwitchActivationNow),// deprecated
        // xlb_f("_TryShell2Rename", _TryShell2Rename),// deprecated
        // xlb_f("_UIActivateView", _UIActivateView),// deprecated
        // xlb_f("_UpdateViewRectSize", _UpdateViewRectSize),// deprecated
        // xlb_f("AbortList", AbortList),
        // xlb_f("Activate", Activate),
        // xlb_f("ActivateApplication", ActivateApplication),
        // xlb_f("ActivateBackgroundTask", ActivateBackgroundTask),
        // xlb_f("ActivateForFile", ActivateForFile),
        // xlb_f("ActivateForProtocol", ActivateForProtocol),
        // xlb_f("ActivateHandler", ActivateHandler),
        // xlb_f("ActivatePendingView", ActivatePendingView),
        // xlb_f("ActivateTab", ActivateTab),
        // xlb_f("ActivateView", ActivateView),
        // xlb_f("AddBand", AddBand),
        // xlb_f("AddCheckButton", AddCheckButton),
        // xlb_f("AddComboBox", AddComboBox),
        // xlb_f("AddControlItem", AddControlItem),
        // xlb_f("AddCreateFlags", AddCreateFlags),
        // xlb_f("AddDataBlock", AddDataBlock),
        // xlb_f("AddEditBox", AddEditBox),
        // xlb_f("AddEntry", AddEntry),
        // xlb_f("AddFolder", AddFolder),
        // xlb_f("AddFromArray", AddFromArray),
        // xlb_f("AddIDList", AddIDList),
        // xlb_f("AddItem", AddItem),
        // xlb_f("AddItemToSession", AddItemToSession),
        // xlb_f("AddMenu", AddMenu),
        // xlb_f("AddObject", AddObject),
        // xlb_f("AddObject", AddObject),
        // xlb_f("AddPages", AddPages),
        // xlb_f("AddPages", AddPages),
        // xlb_f("AddPlace", AddPlace),
        // xlb_f("AddPropertySheetPages", AddPropertySheetPages),
        // xlb_f("AddPushButton", AddPushButton),
        // xlb_f("AddRadioButtonList", AddRadioButtonList),
        // xlb_f("AddSeparator", AddSeparator),
        // xlb_f("AddStartupFlags", AddStartupFlags),
        // xlb_f("AddTab", AddTab),
        // xlb_f("AddTask", AddTask),
        // xlb_f("AddText", AddText),
        // xlb_f("AddToolbar", AddToolbar),
        // xlb_f("AddUserTasks", AddUserTasks),
        // xlb_f("AdvanceSlideshow", AdvanceSlideshow),
        // xlb_f("Advise", Advise),
        // xlb_f("Advise", Advise),
        // xlb_f("Advise", Advise),
        // xlb_f("Advise", Advise),
        // xlb_f("Advise", Advise),
        // xlb_f("Advise", Advise),
        // xlb_f("Advise", Advise),
        // xlb_f("Advise", Advise),
        // xlb_f("Advise", Advise),
        // xlb_f("AdviseWithHWND", AdviseWithHWND),
        // xlb_f("AllowAutoPlay", AllowAutoPlay),
        // xlb_f("AllowViewResize", AllowViewResize),
        // xlb_f("Append", Append),
        // xlb_f("AppendCategory", AppendCategory),
        // xlb_f("AppendFieldComboBoxItem", AppendFieldComboBoxItem),
        // xlb_f("AppendKnownCategory", AppendKnownCategory),
        // xlb_f("AppendRoot", AppendRoot),
        // xlb_f("APPLET_PROC", APPLET_PROC),
        // xlb_f("ApplyProperties", ApplyProperties),
        // xlb_f("ApplyPropertiesToItem", ApplyPropertiesToItem),
        // xlb_f("ApplyPropertiesToItem", ApplyPropertiesToItem),
        // xlb_f("ApplyPropertiesToItems", ApplyPropertiesToItems),
        // xlb_f("AppVisibilityOnMonitorChanged", AppVisibilityOnMonitorChanged),
        // xlb_f("ArePrintersShared", ArePrintersShared),
        // xlb_f("AreSnapshotsAvailable", AreSnapshotsAvailable),
        // xlb_f("ArrangeGrid", ArrangeGrid),
        xlb_f( "AssocCreate", AssocCreate ),
        xlb_f( "AssocCreateForClasses", AssocCreateForClasses ),
        xlb_f( "AssocGetDetailsOfPropKey", AssocGetDetailsOfPropKey ),
        xlb_f( "AssocGetPerceivedType", AssocGetPerceivedType ),
        xlb_f( "AssocIsDangerous", AssocIsDangerous ),
        xlb_f( "AssocQueryKey", AssocQueryKey ),
        xlb_f( "AssocQueryString", AssocQueryString ),
        xlb_f( "AssocQueryStringByKey", AssocQueryStringByKey ),
        xlb_f( "AssocQueryStringByKeyW", AssocQueryStringByKeyW ),
        // xlb_f("AutoArrange", AutoArrange),
        // xlb_f("BeforeCoCreateInstance", BeforeCoCreateInstance),
        // xlb_f("BeforeCreateProcess", BeforeCreateProcess),
        // xlb_f("Begin", Begin),
        // xlb_f("BeginFieldUpdates", BeginFieldUpdates),
        // xlb_f("BeginList", BeginList),
        // xlb_f("BindToConflict", BindToConflict),
        // xlb_f("BindToHandler", BindToHandler),
        // xlb_f("BindToHandler", BindToHandler),
        // xlb_f("BindToHandler", BindToHandler),
        // xlb_f("BindToObject", BindToObject),
        // xlb_f("BindToStorage", BindToStorage),
        // xlb_f("BrowseObject", BrowseObject),
        // xlb_f("BrowseToIDList", BrowseToIDList),
        // xlb_f("BrowseToObject", BrowseToObject),
        // xlb_f("Burn", Burn),
        // xlb_f("ByteToChar", ByteToChar),
        // xlb_f("ByteToInt8", ByteToInt8),
        // xlb_f("CacheOLEServer", CacheOLEServer),
        // xlb_f("CallBack", CallBack),
        // xlb_f("CallbackSM", CallbackSM),
        // xlb_f("CanCategorizeOnSCID", CanCategorizeOnSCID),
        // xlb_f("CancelIo", CancelIo),
        // xlb_f("CanContinue", CanContinue),
        // xlb_f("CanNavigateNow", CanNavigateNow),
        // xlb_f("CanRenderComposited", CanRenderComposited),
        // xlb_f("CaptureThumbnail", CaptureThumbnail),
        // xlb_f("CDefFolderMenu_Create2", CDefFolderMenu_Create2),
        // xlb_f("CheckPolicy", CheckPolicy),
        // xlb_f("ChrCmpIA", ChrCmpIA),
        // xlb_f("ChrCmpIW", ChrCmpIW),
        // xlb_f("CIDLData_CreateFromIDArray", CIDLData_CreateFromIDArray),
        // xlb_f("Clear", Clear),
        // xlb_f("ClearClientData", ClearClientData),
        // xlb_f("ClearClientState", ClearClientState),
        // xlb_f("ClearUserAssociations", ClearUserAssociations),
        // xlb_f("Clone", Clone),
        // xlb_f("Clone", Clone),
        // xlb_f("Clone", Clone),
        // xlb_f("Clone", Clone),
        // xlb_f("Clone", Clone),
        // xlb_f("Clone", Clone),
        // xlb_f("Clone", Clone),
        // xlb_f("Clone", Clone),
        // xlb_f("Clone", Clone),
        // xlb_f("Clone", Clone),
        // xlb_f("Clone", Clone),
        // xlb_f("Clone", Clone),
        // xlb_f("CloneFrame", CloneFrame),
        // xlb_f("Close", Close),
        // xlb_f("Close", Close),
        // xlb_f("CloseDW", CloseDW),
        // xlb_f("CloseFile", CloseFile),
        // xlb_f("CollapseAll", CollapseAll),
        xlb_f( "ColorAdjustLuma", ColorAdjustLuma ), 
        xlb_f( "ColorHLSToRGB", ColorHLSToRGB ),
        xlb_f( "ColorRGBToHLS", ColorRGBToHLS ),
        // xlb_f("ColumnClick", ColumnClick),
        xlb_f( "CommandLineToArgvW", CommandLineToArgvW ),
        // xlb_f("CommandLinkClicked", CommandLinkClicked),
        // xlb_f("Commit", Commit),
        // xlb_f("Commit", Commit),
        // xlb_f("CommitItem", CommitItem),
        // xlb_f("CommitList", CommitList),
        // xlb_f("Compare", Compare),
        // xlb_f("CompareCategory", CompareCategory),
        // xlb_f("CompareIDs", CompareIDs),
        // xlb_f("ComputeApplicationSize", ComputeApplicationSize),
        // xlb_f("ComputerInfoChanged", ComputerInfoChanged),
        // xlb_f("ConfirmEncryptionLoss", ConfirmEncryptionLoss),
        // xlb_f("ConfirmOverwrite", ConfirmOverwrite),
        // xlb_f("Connect", Connect),
        xlb_f( "ConnectToConnectionPoint", ConnectToConnectionPoint ),
        // xlb_f("CopyCallback", CopyCallback),
        // xlb_f("CopyCallback", CopyCallback),
        // xlb_f("CopyDataBlock", CopyDataBlock),
        // xlb_f("CopyItem", CopyItem),
        // xlb_f("CopyItems", CopyItems),
        // xlb_f("CountEntries", CountEntries),
        // xlb_f("CountTasks", CountTasks),
        // xlb_f("CreateAppContainerProfile", CreateAppContainerProfile),
        // xlb_f("CreateBand", CreateBand),
        // xlb_f("CreateBrowserPropSheetExt", CreateBrowserPropSheetExt),
        // xlb_f("CreateCategory", CreateCategory),
        // xlb_f("CreateEnumIDListFromContents", CreateEnumIDListFromContents),
        xlb_f( "CreateEnvironmentBlock", CreateEnvironmentBlock ),
        // xlb_f("CreateImageFromFile", CreateImageFromFile),
        // xlb_f("CreateImageFromStream", CreateImageFromStream),
        // xlb_f("CreateInvoker", CreateInvoker),
        // xlb_f("CreateIShellImageData", CreateIShellImageData),
        // xlb_f("CreateItem", CreateItem),
        // xlb_f("CreateItemID", CreateItemID),
        // xlb_f("CreateObject", CreateObject),
        xlb_f( "CreateProfile", CreateProfile ),
        // xlb_f("CreateResource", CreateResource),
        // xlb_f("CreateSession", CreateSession),
        // xlb_f("CreateShare", CreateShare),
        // xlb_f("CreateViewObject", CreateViewObject),
        // xlb_f("CreateViewWindow", CreateViewWindow),
        // xlb_f("CreateViewWindow", CreateViewWindow),
        // xlb_f("CreateViewWindow2", CreateViewWindow2),
        // xlb_f("CreateViewWindow3", CreateViewWindow3),
        // xlb_f("CredentialsChanged", CredentialsChanged),
        xlb_f( "DAD_AutoScroll", DAD_AutoScroll ),
        xlb_f( "DAD_DragEnterEx", DAD_DragEnterEx ),
        xlb_f( "DAD_DragEnterEx2", DAD_DragEnterEx2 ),
        xlb_f( "DAD_DragLeave", DAD_DragLeave ), 
        xlb_f( "DAD_DragMove", DAD_DragMove ),
        xlb_f( "DAD_SetDragImage", DAD_SetDragImage ),
        xlb_f( "DAD_ShowDragImage", DAD_ShowDragImage ),
        // xlb_f("Decode", Decode),
        // xlb_f("DEFINE_PROPERTYKEY", DEFINE_PROPERTYKEY),
        // xlb_f("DefScreenSaverProc", DefScreenSaverProc),
        xlb_f( "DefSubclassProc", DefSubclassProc ),
        // xlb_f("Delete", Delete),
        // xlb_f("DeleteAppContainerProfile", DeleteAppContainerProfile),
        // xlb_f("DeleteFieldComboBoxItem", DeleteFieldComboBoxItem),
        // xlb_f("DeleteItem", DeleteItem),
        // xlb_f("DeleteItems", DeleteItems),
        // xlb_f("DeleteList", DeleteList),
        // xlb_f("DeleteLogError", DeleteLogError),
        xlb_f( "DeleteProfile", DeleteProfile ),
        // xlb_f("DeleteProfileW", DeleteProfileW),
        // xlb_f("DeleteShare", DeleteShare),
        // xlb_f("DeleteTab", DeleteTab),
        // xlb_f("DeriveAppContainerSidFromAppContainerName",
        // DeriveAppContainerSidFromAppContainerName),
        // xlb_f("DeriveRestrictedAppContainerSidFromAppContainerSidAndRestrictedName",
        // DeriveRestrictedAppContainerSidFromAppContainerSidAndRestrictedName),
        // xlb_f("DeskBandRegistrationChanged", DeskBandRegistrationChanged),
        // xlb_f("Destroy", Destroy),
        // xlb_f("DestroyBand", DestroyBand),
        xlb_f( "DestroyEnvironmentBlock", DestroyEnvironmentBlock ),
        // xlb_f("DestroyViewWindow", DestroyViewWindow),
        // xlb_f("Detach", Detach),
        // xlb_f("DisableDebugging", DisableDebugging),
        // xlb_f("DiscardEdit", DiscardEdit),
        // xlb_f("Disconnect", Disconnect),
        // xlb_f("DisplayName", DisplayName),
        // xlb_f("DisplayParseError", DisplayParseError),
        // xlb_f("DLLGETVERSIONPROC", DLLGETVERSIONPROC),
        //xlb_f( "DllInstall", DllInstall ), // undefined
        // xlb_f("DoContextMenuPopup", DoContextMenuPopup),
        xlb_f( "DoEnvironmentSubst", DoEnvironmentSubst ),
        // xlb_f("DoPreview", DoPreview),
        // xlb_f("DoRename", DoRename),
        xlb_f( "DragAcceptFiles", DragAcceptFiles ),
        // xlb_f("DragEnter", DragEnter),
        xlb_f( "DragFinish", DragFinish ),
        // xlb_f("DragLeave", DragLeave),
        // xlb_f("DragOver", DragOver),
        xlb_f( "DragQueryFile", DragQueryFile ), 
        xlb_f( "DragQueryFileW", DragQueryFileW ),
        xlb_f( "DragQueryPoint", DragQueryPoint ),
        // xlb_f("Draw", Draw),
        xlb_f( "DriveType", DriveType ), 
        xlb_f( "DriveType", DriveType ),
        // xlb_f("Drop", Drop),
        xlb_f( "DuplicateIcon", DuplicateIcon ),
        // xlb_f("DWordPtrAdd", DWordPtrAdd),
        // xlb_f("DWordPtrMult", DWordPtrMult),
        // xlb_f("DWordPtrSub", DWordPtrSub),
        // xlb_f("Enable", Enable),
        // xlb_f("Enable", Enable),
        // xlb_f("Enable", Enable),
        // xlb_f("Enable", Enable),
        // xlb_f("EnableDebugging", EnableDebugging),
        // xlb_f("EnableFocusTracking", EnableFocusTracking),
        // xlb_f("EnableHandler", EnableHandler),
        // xlb_f("EnableItem", EnableItem),
        // xlb_f("EnableModeless", EnableModeless),
        // xlb_f("EnableModeless", EnableModeless),
        // xlb_f("EnableModelessSB", EnableModelessSB),
        // xlb_f("EnableOpenDropDown", EnableOpenDropDown),
        // xlb_f("End", End),
        // xlb_f("EndFieldUpdates", EndFieldUpdates),
        // xlb_f("EndOperation", EndOperation),
        // xlb_f("EndVisualGroup", EndVisualGroup),
        // xlb_f("EnsureItemVisible", EnsureItemVisible),
        // xlb_f("EnterFolder", EnterFolder),
        // xlb_f("EnterFolder", EnterFolder),
        // xlb_f("EnumApps", EnumApps),
        // xlb_f("EnumBands", EnumBands),
        // xlb_f("EnumCategories", EnumCategories),
        // xlb_f("EnumConflicts", EnumConflicts),
        // xlb_f("EnumerateBackgroundTasks", EnumerateBackgroundTasks),
        // xlb_f("EnumItems", EnumItems),
        xlb_f( "EnumObjects", EnumObjects ),
        // xlb_f("EnumReady", EnumReady),
        // xlb_f("EnumResources", EnumResources),
        // xlb_f("EnumSearches", EnumSearches),
        // xlb_f("EnumSubCommands", EnumSubCommands),
        // xlb_f("EnumSyncMgrItems", EnumSyncMgrItems),
        // xlb_f("EstablishConnection", EstablishConnection),
        // xlb_f("EvaluateNewWindow", EvaluateNewWindow),
        // xlb_f("Execute", Execute),
        // xlb_f("Execute", Execute),
        // xlb_f("Expand", Expand),
        xlb_f( "ExpandEnvironmentStringsForUser", ExpandEnvironmentStringsForUser ),
        // xlb_f("Extract", Extract),
        // xlb_f("Extract", Extract),
        // xlb_f("Extract", Extract),
        xlb_f( "ExtractAssociatedIcon", ExtractAssociatedIcon ),
        xlb_f( "ExtractAssociatedIconEx", ExtractAssociatedIconEx ),
        xlb_f( "ExtractIcon", ExtractIcon ), 
        xlb_f( "ExtractIconEx", ExtractIconEx ),
        // xlb_f("FileFailure", FileFailure),
        // xlb_f("FillFromObject", FillFromObject),
        // xlb_f("Filter", Filter),
        // xlb_f("FilterView", FilterView),
        // xlb_f("FindCIE4ConnectionPoint", FindCIE4ConnectionPoint),
        // xlb_f("FindConnectionPoint", FindConnectionPoint),
        xlb_f( "FindExecutable", FindExecutable ),
        // xlb_f("FindFolderFromIDList", FindFolderFromIDList),
        // xlb_f("FindFolderFromPath", FindFolderFromPath),
        // xlb_f("FindToolbar", FindToolbar),
        // xlb_f("FindTravelEntry", FindTravelEntry),
        // xlb_f("FindWindowSW", FindWindowSW),
        // xlb_f("FinishOperations", FinishOperations),
        // xlb_f("FolderIdFromCsidl", FolderIdFromCsidl),
        // xlb_f("FolderIdToCsidl", FolderIdToCsidl),
        // xlb_f("ForwardViewMsg", ForwardViewMsg),
        // xlb_f("FoundItem", FoundItem),
        xlb_f( "FreeConfirmConflictItem", FreeConfirmConflictItem ),
        xlb_f( "FreeIDListArray", FreeIDListArray ),
        xlb_f( "FreeIDListArrayChild", FreeIDListArrayChild ),
        xlb_f( "FreeIDListArrayFull", FreeIDListArrayFull ),
        xlb_f( "FreeKnownFolderDefinitionFields", FreeKnownFolderDefinitionFields ),
        // xlb_f("get_Application", get_Application),
        // xlb_f("get_Count", get_Count),
        // xlb_f("get_CurrentViewMode", get_CurrentViewMode),
        // xlb_f("get_FocusedItem", get_FocusedItem),
        // xlb_f("get_Folder", get_Folder),
        // xlb_f("get_FolderFlags", get_FolderFlags),
        // xlb_f("get_GroupBy", get_GroupBy),
        // xlb_f("get_IconSize", get_IconSize),
        // xlb_f("get_Parent", get_Parent),
        // xlb_f("get_Script", get_Script),
        // xlb_f("get_SortColumns", get_SortColumns),
        // xlb_f("get_ViewOptions", get_ViewOptions),
        xlb_f( "GetAcceptLanguages", GetAcceptLanguages ),
        // xlb_f("GetAccountOptions", GetAccountOptions),
        xlb_f( "GetAllUsersProfileDirectory", GetAllUsersProfileDirectory ),
        // xlb_f("GetAnyOperationsAborted", GetAnyOperationsAborted),
        // xlb_f("GetAppContainerFolderPath", GetAppContainerFolderPath),
        // xlb_f("GetAppContainerRegistryLocation", GetAppContainerRegistryLocation),
        // xlb_f("GetAppID", GetAppID),
        // xlb_f("GetAppInfo", GetAppInfo),
        // xlb_f("GetApplicationDisplayName", GetApplicationDisplayName),
        // xlb_f("GetApplicationIconReference", GetApplicationIconReference),
        // xlb_f("GetApplicationPublisher", GetApplicationPublisher),
        // xlb_f("GetApplicationSizeBounds", GetApplicationSizeBounds),
        // xlb_f("GetApplicationViewOrientation", GetApplicationViewOrientation),
        // xlb_f("GetAppName", GetAppName),
        // xlb_f("GetAppUserModelId", GetAppUserModelId),
        // xlb_f("GetAppVisibilityOnMonitor", GetAppVisibilityOnMonitor),
        // xlb_f("GetArguments", GetArguments),
        // xlb_f("GetArguments", GetArguments),
        // xlb_f("GetArrangeParam", GetArrangeParam),
        // xlb_f("GetAsyncMode", GetAsyncMode),
        // xlb_f("GetAt", GetAt),
        // xlb_f("GetAt", GetAt),
        // xlb_f("GetAttributes", GetAttributes),
        // xlb_f("GetAttributes", GetAttributes),
        // xlb_f("GetAttributes", GetAttributes),
        // xlb_f("GetAttributesOf", GetAttributesOf),
        // xlb_f("GetAutoArrange", GetAutoArrange),
        // xlb_f("GetAutoArrange", GetAutoArrange),
        // xlb_f("GetAvailableSize", GetAvailableSize),
        // xlb_f("GetBackgroundColor", GetBackgroundColor),
        // xlb_f("GetBandInfo", GetBandInfo),
        // xlb_f("GetBandInfoSFB", GetBandInfoSFB),
        // xlb_f("GetBandObject", GetBandObject),
        // xlb_f("GetBandSiteInfo", GetBandSiteInfo),
        // xlb_f("GetBaseBrowserData", GetBaseBrowserData),
        // xlb_f("GetBitmapValue", GetBitmapValue),
        // xlb_f("GetBool", GetBool),
        // xlb_f("GetBorderDW", GetBorderDW),
        // xlb_f("GetBrowserByIndex", GetBrowserByIndex),
        // xlb_f("GetBrowserIndex", GetBrowserIndex),
        // xlb_f("GetCachedSlowAppInfo", GetCachedSlowAppInfo),
        // xlb_f("GetCancelEvent", GetCancelEvent),
        // xlb_f("GetCancelInformation", GetCancelInformation),
        // xlb_f("GetCancelledPage", GetCancelledPage),
        // xlb_f("GetCanonicalName", GetCanonicalName),
        // xlb_f("GetCapabilities", GetCapabilities),
        // xlb_f("GetCapabilities", GetCapabilities),
        // xlb_f("GetCapabilities", GetCapabilities),
        // xlb_f("GetCategories", GetCategories),
        // xlb_f("GetCategory", GetCategory),
        // xlb_f("GetCategory", GetCategory),
        // xlb_f("GetCategoryForSCID", GetCategoryForSCID),
        // xlb_f("GetCategoryInfo", GetCategoryInfo),
        // xlb_f("GetCategoryName", GetCategoryName),
        // xlb_f("GetCheckboxValue", GetCheckboxValue),
        // xlb_f("GetCheckButtonState", GetCheckButtonState),
        // xlb_f("GetCheckState", GetCheckState),
        // xlb_f("GetClient", GetClient),
        // xlb_f("GetCLSID", GetCLSID),
        // xlb_f("GetCodePage", GetCodePage),
        // xlb_f("GetColor", GetColor),
        // xlb_f("GetColumnCount", GetColumnCount),
        // xlb_f("GetColumnInfo", GetColumnInfo),
        // xlb_f("GetColumnInfo", GetColumnInfo),
        // xlb_f("GetColumnPropertyList", GetColumnPropertyList),
        // xlb_f("GetColumns", GetColumns),
        // xlb_f("GetComboBoxValueAt", GetComboBoxValueAt),
        // xlb_f("GetComboBoxValueCount", GetComboBoxValueCount),
        // xlb_f("GetCommand", GetCommand),
        // xlb_f("GetCommands", GetCommands),
        // xlb_f("GetCommandString", GetCommandString),
        // xlb_f("GetComment", GetComment),
        // xlb_f("GetComment", GetComment),
        // xlb_f("GetCompositionState", GetCompositionState),
        // xlb_f("GetCondition", GetCondition),
        // xlb_f("GetConflictIdInfo", GetConflictIdInfo),
        // xlb_f("GetConflictIDList", GetConflictIDList),
        // xlb_f("GetContext", GetContext),
        // xlb_f("GetControlItemState", GetControlItemState),
        // xlb_f("GetControlState", GetControlState),
        // xlb_f("GetControlStyle", GetControlStyle),
        // xlb_f("GetControlStyle2", GetControlStyle2),
        // xlb_f("GetControlWindow", GetControlWindow),
        // xlb_f("GetCount", GetCount),
        // xlb_f("GetCount", GetCount),
        // xlb_f("GetCount", GetCount),
        // xlb_f("GetCount", GetCount),
        // xlb_f("GetCount", GetCount),
        // xlb_f("GetCount", GetCount),
        // xlb_f("GetCreateFlags", GetCreateFlags),
        // xlb_f("GetCredentialAt", GetCredentialAt),
        // xlb_f("GetCredentialCount", GetCredentialCount),
        // xlb_f("GetCurFolder", GetCurFolder),
        // xlb_f("GetCurrentFilter", GetCurrentFilter),
        // xlb_f("GetCurrentFolderFlags", GetCurrentFolderFlags),
        // xlb_f("GetCurrentInfo", GetCurrentInfo),
        // xlb_f("GetCurrentPage", GetCurrentPage),
        xlb_f( "GetCurrentProcessExplicitAppUserModelID",
               GetCurrentProcessExplicitAppUserModelID ),
        // xlb_f("GetCurrentSelection", GetCurrentSelection),
        // xlb_f("GetCurrentView", GetCurrentView),
        // xlb_f("GetCurrentView", GetCurrentView),
        // xlb_f("GetCurrentViewMode", GetCurrentViewMode),
        // xlb_f("GetData", GetData),
        // xlb_f("GetDataFormatFromPath", GetDataFormatFromPath),
        // xlb_f("GetDataFromIDList", GetDataFromIDList),
        // xlb_f("GetDataFromIDList", GetDataFromIDList),
        // xlb_f("GetDataObject", GetDataObject),
        // xlb_f("GetDateStamp", GetDateStamp),
        // xlb_f("GetDefaultBandWidth", GetDefaultBandWidth),
        // xlb_f("GetDefaultCategory", GetDefaultCategory),
        // xlb_f("GetDefaultColumn", GetDefaultColumn),
        // xlb_f("GetDefaultColumnState", GetDefaultColumnState),
        // xlb_f("GetDefaultDestinationName", GetDefaultDestinationName),
        // xlb_f("GetDefaultMenuText", GetDefaultMenuText),
        // xlb_f("GetDefaultSaveFolder", GetDefaultSaveFolder),
        // xlb_f("GetDefaultSearchGUID", GetDefaultSearchGUID),
        // xlb_f("GetDefaultSpacing", GetDefaultSpacing),
        xlb_f( "GetDefaultUserProfileDirectory", GetDefaultUserProfileDirectory ),
        // xlb_f("GetDelay", GetDelay),
        // xlb_f("GetDelayedPropertyStore", GetDelayedPropertyStore),
        // xlb_f("GetDescription", GetDescription),
        // xlb_f("GetDescription", GetDescription),
        // xlb_f("GetDescription", GetDescription),
        // xlb_f("GetDescription", GetDescription),
        // xlb_f("GetDestinationStream", GetDestinationStream),
        // xlb_f("GetDetailsEx", GetDetailsEx),
        // xlb_f("GetDetailsOf", GetDetailsOf),
        // xlb_f("GetDetailsOf", GetDetailsOf),
        // xlb_f("GetDirectory", GetDirectory),
        // xlb_f("GetDisplayName", GetDisplayName),
        // xlb_f("GetDisplayNameOf", GetDisplayNameOf),
        xlb_f( "GetDpiForShellUIComponent", GetDpiForShellUIComponent ),
        // xlb_f("GetDragPoint", GetDragPoint),
        // xlb_f("GetDropDownStatus", GetDropDownStatus),
        // xlb_f("GetDropPoint", GetDropPoint),
        // xlb_f("GetDynamicInfo", GetDynamicInfo),
        // xlb_f("GetEditBoxText", GetEditBoxText),
        // xlb_f("GetEncoderParams", GetEncoderParams),
        // xlb_f("GetEntry", GetEntry),
        // xlb_f("GetEnum", GetEnum),
        // xlb_f("GetEnumFlags", GetEnumFlags),
        // xlb_f("GetEnumFlagsForItem", GetEnumFlagsForItem),
        // xlb_f("GetEvent", GetEvent),
        // xlb_f("GetEventCount", GetEventCount),
        // xlb_f("GetEventEnumerator", GetEventEnumerator),
        // xlb_f("GetEventID", GetEventID),
        // xlb_f("GetExtension", GetExtension),
        // xlb_f("GetExtension", GetExtension),
        // xlb_f("GetFieldDescriptorAt", GetFieldDescriptorAt),
        // xlb_f("GetFieldDescriptorCount", GetFieldDescriptorCount),
        // xlb_f("GetFieldOptions", GetFieldOptions),
        // xlb_f("GetFieldState", GetFieldState),
        // xlb_f("GetFileID", GetFileID),
        // xlb_f("GetFileName", GetFileName),
        xlb_f( "GetFileNameFromBrowse", GetFileNameFromBrowse ),
        // xlb_f("GetFileOverlayInfo", GetFileOverlayInfo),
        xlb_f( "GetFileTime", GetFileTime ),
        // xlb_f("GetFileTypeIndex", GetFileTypeIndex),
        // xlb_f("GetFindData", GetFindData),
        // xlb_f("GetFirstPage", GetFirstPage),
        // xlb_f("GetFlags", GetFlags),
        // xlb_f("GetFlags", GetFlags),
        // xlb_f("GetFlags", GetFlags),
        // xlb_f("GetFlags", GetFlags),
        // xlb_f("GetFocusedItem", GetFocusedItem),
        // xlb_f("GetFolder", GetFolder),
        // xlb_f("GetFolder", GetFolder),
        // xlb_f("GetFolder", GetFolder),
        // xlb_f("GetFolder", GetFolder),
        // xlb_f("GetFolder", GetFolder),
        // xlb_f("GetFolderByName", GetFolderByName),
        // xlb_f("GetFolderCapabilities", GetFolderCapabilities),
        // xlb_f("GetFolderDefinition", GetFolderDefinition),
        // xlb_f("GetFolderFlags", GetFolderFlags),
        // xlb_f("GetFolderIds", GetFolderIds),
        // xlb_f("GetFolders", GetFolders),
        // xlb_f("GetFolderSetData", GetFolderSetData),
        // xlb_f("GetFolderTargetInfo", GetFolderTargetInfo),
        // xlb_f("GetFolderType", GetFolderType),
        // xlb_f("GetFolderType", GetFolderType),
        // xlb_f("GetFolderViewOptions", GetFolderViewOptions),
        // xlb_f("GetFont", GetFont),
        // xlb_f("GetFormat", GetFormat),
        // xlb_f("GetForWindow", GetForWindow),
        // xlb_f("GetFrameOptions", GetFrameOptions),
        // xlb_f("GetGroupBy", GetGroupBy),
        // xlb_f("GetGroupByProperty", GetGroupByProperty),
        // xlb_f("GetGroupSubsetCount", GetGroupSubsetCount),
        // xlb_f("GetGroupSubsetCount", GetGroupSubsetCount),
        // xlb_f("GetHandlerEnumerator", GetHandlerEnumerator),
        // xlb_f("GetHandlerID", GetHandlerID),
        // xlb_f("GetHandlerInfo", GetHandlerInfo),
        // xlb_f("GetHandlerInfo", GetHandlerInfo),
        // xlb_f("GetHandlerRegistrationInfo", GetHandlerRegistrationInfo),
        // xlb_f("GetHistoryObject", GetHistoryObject),
        // xlb_f("GetHotkey", GetHotkey),
        // xlb_f("GetHotkey", GetHotkey),
        // xlb_f("GetIcon", GetIcon),
        // xlb_f("GetIcon", GetIcon),
        // xlb_f("GetIconLocation", GetIconLocation),
        // xlb_f("GetIconLocation", GetIconLocation),
        // xlb_f("GetIconLocation", GetIconLocation),
        // xlb_f("GetIconLocation", GetIconLocation),
        // xlb_f("GetIconLocation", GetIconLocation),
        // xlb_f("GetIconOf", GetIconOf),
        // xlb_f("GetIconSize", GetIconSize),
        // xlb_f("GetId", GetId),
        // xlb_f("GetIDArrayResult", GetIDArrayResult),
        // xlb_f("GetIDList", GetIDList),
        // xlb_f("GetIDList", GetIDList),
        // xlb_f("GetIDList", GetIDList),
        // xlb_f("GetIDList", GetIDList),
        // xlb_f("GetIDList", GetIDList),
        // xlb_f("GetImage", GetImage),
        // xlb_f("GetInfoFlags", GetInfoFlags),
        // xlb_f("GetInfoTip", GetInfoTip),
        // xlb_f("GetInt32", GetInt32),
        // xlb_f("GetItem", GetItem),
        // xlb_f("GetItem", GetItem),
        // xlb_f("GetItem", GetItem),
        // xlb_f("GetItem", GetItem),
        // xlb_f("GetItem", GetItem),
        // xlb_f("GetItemAt", GetItemAt),
        // xlb_f("GetItemChoice", GetItemChoice),
        // xlb_f("GetItemChoiceCount", GetItemChoiceCount),
        // xlb_f("GetItemCustomState", GetItemCustomState),
        // xlb_f("GetItemData", GetItemData),
        // xlb_f("GetItemHeight", GetItemHeight),
        // xlb_f("GetItemID", GetItemID),
        // xlb_f("GetItemID", GetItemID),
        // xlb_f("GetItemIDList", GetItemIDList),
        // xlb_f("GetItemInfo", GetItemInfo),
        // xlb_f("GetItemObject", GetItemObject),
        // xlb_f("GetItemObject", GetItemObject),
        // xlb_f("GetItemPosition", GetItemPosition),
        // xlb_f("GetItemRect", GetItemRect),
        // xlb_f("GetItemsArray", GetItemsArray),
        // xlb_f("GetItemSpacing", GetItemSpacing),
        // xlb_f("GetItemState", GetItemState),
        // xlb_f("GetIterationInfo", GetIterationInfo),
        // xlb_f("GetJunctionCLSID", GetJunctionCLSID),
        // xlb_f("GetKey", GetKey),
        // xlb_f("GetLastPage", GetLastPage),
        // xlb_f("GetLastSyncTime", GetLastSyncTime),
        // xlb_f("GetLastSyncTime", GetLastSyncTime),
        // xlb_f("GetLevel", GetLevel),
        // xlb_f("GetLinkReference", GetLinkReference),
        // xlb_f("GetLinkText", GetLinkText),
        // xlb_f("GetList", GetList),
        // xlb_f("GetLocation", GetLocation),
        // xlb_f("GetMaxLength", GetMaxLength),
        xlb_f( "GetMenu", GetMenu ), 
        xlb_f( "GetMenuContextHelpId", GetMenuContextHelpId ),
        xlb_f( "GetMenuInfo", GetMenuInfo ), 
        xlb_f( "GetMenuPosFromID", GetMenuPosFromID ),
        // xlb_f("GetMenuRestrictions", GetMenuRestrictions),
        // xlb_f("GetMilliseconds", GetMilliseconds),
        // xlb_f("GetMode", GetMode),
        // xlb_f("GetMonitor", GetMonitor),
        // xlb_f("GetMonitorDevicePathAt", GetMonitorDevicePathAt),
        // xlb_f("GetMonitorDevicePathCount", GetMonitorDevicePathCount),
        // xlb_f("GetMonitorRECT", GetMonitorRECT),
        // xlb_f("GetName", GetName),
        // xlb_f("GetName", GetName),
        // xlb_f("GetName", GetName),
        // xlb_f("GetName", GetName),
        // xlb_f("GetName", GetName),
        // xlb_f("GetName", GetName),
        // xlb_f("GetNameAt", GetNameAt),
        // xlb_f("GetNameCount", GetNameCount),
        // xlb_f("GetNamedValue", GetNamedValue),
        // xlb_f("GetNavigateState", GetNavigateState),
        // xlb_f("GetNextItem", GetNextItem),
        // xlb_f("GetNextPage", GetNextPage),
        // xlb_f("GetNumberOfApps", GetNumberOfApps),
        // xlb_f("GetNumberOfCategories", GetNumberOfCategories),
        xlb_f( "GetObject", GetObject ),
        // xlb_f("GetObjectCount", GetObjectCount),
        // xlb_f("GetOleObject", GetOleObject),
        // xlb_f("GetOperationStatus", GetOperationStatus),
        // xlb_f("GetOptions", GetOptions),
        // xlb_f("GetOptions", GetOptions),
        // xlb_f("GetOptions", GetOptions),
        // xlb_f("GetOptions", GetOptions),
        // xlb_f("GetOptions", GetOptions),
        // xlb_f("GetOverlayIconIndex", GetOverlayIconIndex),
        // xlb_f("GetOverlayIndex", GetOverlayIndex),
        // xlb_f("GetOverlayInfo", GetOverlayInfo),
        // xlb_f("GetPackageExecutionState", GetPackageExecutionState),
        // xlb_f("GetPageCount", GetPageCount),
        // xlb_f("GetPalette", GetPalette),
        // xlb_f("GetPaneState", GetPaneState),
        xlb_f( "GetParent", GetParent ),
        // xlb_f("GetParentAndItem", GetParentAndItem),
        // xlb_f("GetParentSite", GetParentSite),
        xlb_f( "GetPath", GetPath ),
        // xlb_f("GetPidl", GetPidl),
        // xlb_f("GetPidl", GetPidl),
        // xlb_f("GetPinnedWindow", GetPinnedWindow),
        xlb_f( "GetPixelFormat", GetPixelFormat ),
        // xlb_f("GetPolicies", GetPolicies),
        // xlb_f("GetPolicies", GetPolicies),
        // xlb_f("GetPosition", GetPosition),
        // xlb_f("GetPossibleActions", GetPossibleActions),
        // xlb_f("GetPresenterChoice", GetPresenterChoice),
        // xlb_f("GetPresenterNextStep", GetPresenterNextStep),
        // xlb_f("GetPreviousPage", GetPreviousPage),
        // xlb_f("GetPriority", GetPriority),
        //xlb_f( "GetProcessReference", GetProcessReference ), // undefined
        xlb_f( "GetProfilesDirectory", GetProfilesDirectory ),
        xlb_f( "GetProfileType", GetProfileType ),
        // xlb_f("GetProgID", GetProgID),
        // xlb_f("GetProperties", GetProperties),
        // xlb_f("GetProperties", GetProperties),
        // xlb_f("GetProperty", GetProperty),
        // xlb_f("GetProperty", GetProperty),
        // xlb_f("GetPropertyDescriptionList", GetPropertyDescriptionList),
        // xlb_f("GetPropertyDescriptionList", GetPropertyDescriptionList),
        // xlb_f("GetPropertyFromIDList", GetPropertyFromIDList),
        // xlb_f("GetPropertyFromIDList", GetPropertyFromIDList),
        // xlb_f("GetPropertyFromIDList", GetPropertyFromIDList),
        // xlb_f("GetPropertyFromIDList", GetPropertyFromIDList),
        // xlb_f("GetPropertyHandlerFromFileId", GetPropertyHandlerFromFileId),
        // xlb_f("GetPropertyHandlerFromPath", GetPropertyHandlerFromPath),
        // xlb_f("GetPropertyHandlerFromUri", GetPropertyHandlerFromUri),
        // xlb_f("GetPropertyKey", GetPropertyKey),
        // xlb_f("GetPropertyStorage", GetPropertyStorage),
        // xlb_f("GetPropertyStorage", GetPropertyStorage),
        // xlb_f("GetPropertyStorageBuffer", GetPropertyStorageBuffer),
        // xlb_f("GetPropertyStorageFromIDList", GetPropertyStorageFromIDList),
        // xlb_f("GetPropertyStorageSize", GetPropertyStorageSize),
        // xlb_f("GetPropertyStore", GetPropertyStore),
        // xlb_f("GetPropertyStore", GetPropertyStore),
        // xlb_f("GetPropertyStoreForKeys", GetPropertyStoreForKeys),
        // xlb_f("GetPropertyStoreWithCreateObject", GetPropertyStoreWithCreateObject),
        // xlb_f("GetProviderID", GetProviderID),
        // xlb_f("GetPublishedAppInfo", GetPublishedAppInfo),
        // xlb_f("GetRawDataFormat", GetRawDataFormat),
        // xlb_f("GetRecorderDriveLetter", GetRecorderDriveLetter),
        // xlb_f("GetRedirectionCapabilities", GetRedirectionCapabilities),
        // xlb_f("GetReferent", GetReferent),
        // xlb_f("GetReferent", GetReferent),
        // xlb_f("GetRemovedDestinations", GetRemovedDestinations),
        // xlb_f("GetReservedOverlayInfo", GetReservedOverlayInfo),
        // xlb_f("GetResolution", GetResolution),
        // xlb_f("GetResolutionHandler", GetResolutionHandler),
        // xlb_f("GetResourceDescription", GetResourceDescription),
        // xlb_f("GetResult", GetResult),
        // xlb_f("GetResults", GetResults),
        // xlb_f("GetResults", GetResults),
        // xlb_f("GetRootItems", GetRootItems),
        xlb_f( "GetScaleFactorForDevice", GetScaleFactorForDevice ),
        xlb_f( "GetScaleFactorForMonitor", GetScaleFactorForMonitor ),
        // xlb_f("GetSearchStyle", GetSearchStyle),
        // xlb_f("GetSearchText", GetSearchText),
        // xlb_f("GetSearchUrl", GetSearchUrl),
        // xlb_f("GetSectorSize", GetSectorSize),
        // xlb_f("GetSelectedControlItem", GetSelectedControlItem),
        // xlb_f("GetSelectedCount", GetSelectedCount),
        // xlb_f("GetSelectedItem", GetSelectedItem),
        // xlb_f("GetSelectedItems", GetSelectedItems),
        // xlb_f("GetSelectedItems", GetSelectedItems),
        // xlb_f("GetSelectedObjects", GetSelectedObjects),
        // xlb_f("GetSelection", GetSelection),
        // xlb_f("GetSelection", GetSelection),
        // xlb_f("GetSelectionMarkedItem", GetSelectionMarkedItem),
        // xlb_f("GetSelectionState", GetSelectionState),
        // xlb_f("GetSerialization", GetSerialization),
        // xlb_f("GetSetCodePage", GetSetCodePage),
        // xlb_f("GetSharedBitmap", GetSharedBitmap),
        // xlb_f("GetSharePermissions", GetSharePermissions),
        // xlb_f("GetShellFolder", GetShellFolder),
        // xlb_f("GetShellItem", GetShellItem),
        // xlb_f("GetShellItem", GetShellItem),
        // xlb_f("GetShowCmd", GetShowCmd),
        // xlb_f("GetShowCmd", GetShowCmd),
        // xlb_f("GetSid", GetSid),
        // xlb_f("GetSize", GetSize),
        // xlb_f("GetSize", GetSize),
        // xlb_f("GetSize", GetSize),
        // xlb_f("GetSlideshow", GetSlideshow),
        // xlb_f("GetSlideshowOptions", GetSlideshowOptions),
        // xlb_f("GetSlowAppInfo", GetSlowAppInfo),
        // xlb_f("GetSortColumnCount", GetSortColumnCount),
        // xlb_f("GetSortColumns", GetSortColumns),
        // xlb_f("GetSortColumns", GetSortColumns),
        // xlb_f("GetSourceViewSizePreference", GetSourceViewSizePreference),
        // xlb_f("GetSourceViewToPosition", GetSourceViewToPosition),
        // xlb_f("GetSpacing", GetSpacing),
        // xlb_f("GetState", GetState),
        // xlb_f("GetState", GetState),
        // xlb_f("GetState", GetState),
        // xlb_f("GetStatus", GetStatus),
        // xlb_f("GetString", GetString),
        // xlb_f("GetString", GetString),
        // xlb_f("GetStringValue", GetStringValue),
        // xlb_f("GetStringValue", GetStringValue),
        // xlb_f("GetSubmitButtonValue", GetSubmitButtonValue),
        // xlb_f("GetSupportedActionTypes", GetSupportedActionTypes),
        // xlb_f("GetSwitchToHWND", GetSwitchToHWND),
        // xlb_f("GetSyncItem", GetSyncItem),
        // xlb_f("GetSyncItemCount", GetSyncItemCount),
        // xlb_f("GetSyncItemEnumerator", GetSyncItemEnumerator),
        // xlb_f("GetTargetViewSizePreference", GetTargetViewSizePreference),
        // xlb_f("GetText", GetText),
        // xlb_f("GetThumbnail", GetThumbnail),
        // xlb_f("GetThumbnail", GetThumbnail),
        // xlb_f("GetThumbnailByID", GetThumbnailByID),
        // xlb_f("GetThumbnailHandler", GetThumbnailHandler),
        // xlb_f("GetThumbnailStream", GetThumbnailStream),
        // xlb_f("GetTime", GetTime),
        // xlb_f("GetTimes", GetTimes),
        // xlb_f("GetTitle", GetTitle),
        // xlb_f("GetTitle", GetTitle),
        // xlb_f("GetToolTip", GetToolTip),
        // xlb_f("GetToolTipText", GetToolTipText),
        // xlb_f("GetTransferManifest", GetTransferManifest),
        // xlb_f("GetTravelEntry", GetTravelEntry),
        // xlb_f("GetTravelLog", GetTravelLog),
        // xlb_f("GetType", GetType),
        // xlb_f("GetTypeLabel", GetTypeLabel),
        // xlb_f("GetTypeLabel", GetTypeLabel),
        // xlb_f("GetUIMode", GetUIMode),
        // xlb_f("GetUIName", GetUIName),
        // xlb_f("GetUInt32", GetUInt32),
        // xlb_f("GetUInt64", GetUInt64),
        // xlb_f("GetUIObjectOf", GetUIObjectOf),
        // xlb_f("GetUsage", GetUsage),
        xlb_f( "GetUserProfileDirectory", GetUserProfileDirectory ),
        // xlb_f("GetUserSid", GetUserSid),
        // xlb_f("GetValidCharacters", GetValidCharacters),
        // xlb_f("GetValue", GetValue),
        // xlb_f("GetValue", GetValue),
        // xlb_f("GetView", GetView),
        // xlb_f("GetViewFlags", GetViewFlags),
        // xlb_f("GetViewMode", GetViewMode),
        // xlb_f("GetViewModeAndIconSize", GetViewModeAndIconSize),
        // xlb_f("GetViewProperty", GetViewProperty),
        // xlb_f("GetViewRect", GetViewRect),
        // xlb_f("GetViewStateStream", GetViewStateStream),
        // xlb_f("GetViewWindow", GetViewWindow),
        // xlb_f("GetVisibleItem", GetVisibleItem),
        // xlb_f("GetWallpaper", GetWallpaper),
        // xlb_f("GetWindowContext", GetWindowContext),
        xlb_f( "GetWindowContextHelpId", GetWindowContextHelpId ),
        // xlb_f("GetWindowDesktopId", GetWindowDesktopId),
        xlb_f( "GetWindowSubclass", GetWindowSubclass ),
        // xlb_f("GetWorkingDirectory", GetWorkingDirectory),
        // xlb_f("GetWorkingDirectory", GetWorkingDirectory),
        // xlb_f("GroupChildWithParent", GroupChildWithParent),
        // xlb_f("HandleEvent", HandleEvent),
        // xlb_f("HandleEventWithContent", HandleEventWithContent),
        // xlb_f("HandleEventWithHWND", HandleEventWithHWND),
        // xlb_f("HandleMenuMsg", HandleMenuMsg),
        // xlb_f("HandleMenuMsg2", HandleMenuMsg2),
        // xlb_f("HandleRename", HandleRename),
        // xlb_f("HasFocusIO", HasFocusIO),
        xlb_f( "HashData", HashData ),
        // xlb_f("HasRecordableDrive", HasRecordableDrive),
        // xlb_f("HasUserCancelled", HasUserCancelled),
        // xlb_f("HideDeskBand", HideDeskBand),
        // xlb_f("Hiding", Hiding),
        // xlb_f("HitTest", HitTest),
        // xlb_f("HrInit", HrInit),
        xlb_f( "IDListContainerIsConsistent", IDListContainerIsConsistent ),
        // xlb_f("IEGetDisplayName", IEGetDisplayName),
        // xlb_f("IEParseDisplayName", IEParseDisplayName),
        // xlb_f("IEParseDisplayNameEx", IEParseDisplayNameEx),
        // xlb_f("IID_PPV_ARGS", IID_PPV_ARGS),
        xlb_f( "ILAppendID", ILAppendID ), 
        xlb_f( "ILClone", ILClone ),
        xlb_f( "ILCloneChild", ILCloneChild ), 
        xlb_f( "ILCloneFirst", ILCloneFirst ),
        xlb_f( "ILCloneFull", ILCloneFull ), 
        xlb_f( "ILCombine", ILCombine ),
        xlb_f( "ILCreateFromPath", ILCreateFromPath ), 
        xlb_f( "ILFindChild", ILFindChild ),
        xlb_f( "ILFindLastID", ILFindLastID ), 
        xlb_f( "ILFree", ILFree ),
        xlb_f( "ILGetNext", ILGetNext ), 
        xlb_f( "ILGetSize", ILGetSize ),

        xlb_f("ILIsAligned", [](PCUIDLIST_RELATIVE pidl)->auto { return ILIsAligned(pidl); }),
        xlb_f("ILIsChild", [](PCUIDLIST_RELATIVE pidl)->auto { return ILIsChild(pidl); }),
        xlb_f("ILIsEmpty", [](PCUIDLIST_RELATIVE pidl)->auto { return ILIsEmpty(pidl); }),

        xlb_f( "ILIsEqual", ILIsEqual ), 
        xlb_f( "ILIsParent", ILIsParent ),
        // xlb_f("ILLoadFromStream", ILLoadFromStream),
        xlb_f( "ILLoadFromStreamEx", ILLoadFromStreamEx ),
        xlb_f("ILNext", [](PCUIDLIST_RELATIVE pidl)->auto { return ILNext(pidl); }),
        xlb_f( "ILRemoveLastID", ILRemoveLastID ), 
        xlb_f( "ILSaveToStream", ILSaveToStream ),
        xlb_f("ILSkip", [](PCUIDLIST_RELATIVE pidl, unsigned cb)->auto { return ILSkip(pidl, cb); }),
        // xlb_f("IncludeItem", IncludeItem),
        // xlb_f("IncludeItems", IncludeItems),
        // xlb_f("IncludeObject", IncludeObject),
        //xlb_f( "InetIsOffline", InetIsOffline ), // undefined
        // xlb_f("Init", Init),
        // xlb_f("Init", Init),
        // xlb_f("Init", Init),
        // xlb_f("Initialize", Initialize),
        // xlb_f("Initialize", Initialize),
        // xlb_f("Initialize", Initialize),
        // xlb_f("Initialize", Initialize),
        // xlb_f("Initialize", Initialize),
        // xlb_f("Initialize", Initialize),
        // xlb_f("Initialize", Initialize),
        // xlb_f("Initialize", Initialize),
        // xlb_f("Initialize", Initialize),
        // xlb_f("Initialize", Initialize),
        // xlb_f("Initialize", Initialize),
        // xlb_f("Initialize", Initialize),
        // xlb_f("Initialize", Initialize),
        // xlb_f("Initialize", Initialize),
        // xlb_f("Initialize", Initialize),
        // xlb_f("Initialize", Initialize),
        // xlb_f("Initialize", Initialize),
        // xlb_f("Initialize", Initialize),
        // xlb_f("Initialize", Initialize),
        // xlb_f("Initialize", Initialize),
        // xlb_f("InitializeBitmap", InitializeBitmap),
        // xlb_f("InitializeDownloadManager", InitializeDownloadManager),
        // xlb_f("InitializeEx", InitializeEx),
        // xlb_f("InitializeFromBitmap", InitializeFromBitmap),
        // xlb_f("InitializeFromWindow", InitializeFromWindow),
        // xlb_f("InitializeProgressDialog", InitializeProgressDialog),
        // xlb_f("InitializeSFB", InitializeSFB),
        // xlb_f("InitializeTransitionSite", InitializeTransitionSite),
        // xlb_f("InitializeTravelLog", InitializeTravelLog),
        xlb_f( "InitNetworkAddressControl", InitNetworkAddressControl ),
        // xlb_f("InitWizard", InitWizard),
        // xlb_f("InOperation", InOperation),
        // xlb_f("InsertItem", InsertItem),
        // xlb_f("InsertMenuEntries", InsertMenuEntries),
        // xlb_f("InsertMenusSB", InsertMenusSB),
        // xlb_f("InsertRoot", InsertRoot),
        // xlb_f("Install", Install),
        // xlb_f("Install2", Install2),
        // xlb_f("Int8Add", Int8Add),
        // xlb_f("Int8Mult", Int8Mult),
        // xlb_f("Int8Sub", Int8Sub),
        // xlb_f("Int8ToUChar", Int8ToUChar),
        // xlb_f("Int8ToUInt", Int8ToUInt),
        // xlb_f("Int8ToUInt8", Int8ToUInt8),
        // xlb_f("Int8ToUIntPtr", Int8ToUIntPtr),
        // xlb_f("Int8ToULong", Int8ToULong),
        // xlb_f("Int8ToULongLong", Int8ToULongLong),
        // xlb_f("Int8ToULongPtr", Int8ToULongPtr),
        // xlb_f("Int8ToUShort", Int8ToUShort),
        // xlb_f("IntAdd", IntAdd),
        // xlb_f("IntlStrEqNA", IntlStrEqNA),
        // xlb_f("IntlStrEqNIA", IntlStrEqNIA),
        // xlb_f("IntlStrEqNIW", IntlStrEqNIW),
        // xlb_f("IntlStrEqNW", IntlStrEqNW),
        // xlb_f("IntlStrEqWorker", IntlStrEqWorker),
        // xlb_f("IntMult", IntMult),
        // xlb_f("IntPtrAdd", IntPtrAdd),
        // xlb_f("IntPtrMult", IntPtrMult),
        // xlb_f("IntPtrSub", IntPtrSub),
        // xlb_f("IntPtrToChar", IntPtrToChar),
        // xlb_f("IntPtrToInt", IntPtrToInt),
        // xlb_f("IntPtrToInt8", IntPtrToInt8),
        // xlb_f("IntPtrToLong", IntPtrToLong),
        // xlb_f("IntPtrToLongPtr", IntPtrToLongPtr),
        // xlb_f("IntPtrToShort", IntPtrToShort),
        // xlb_f("IntPtrToUChar", IntPtrToUChar),
        // xlb_f("IntPtrToUInt", IntPtrToUInt),
        // xlb_f("IntPtrToUInt8", IntPtrToUInt8),
        // xlb_f("IntPtrToUIntPtr", IntPtrToUIntPtr),
        // xlb_f("IntPtrToULong", IntPtrToULong),
        // xlb_f("IntPtrToULongLong", IntPtrToULongLong),
        // xlb_f("IntPtrToULongPtr", IntPtrToULongPtr),
        // xlb_f("IntPtrToUShort", IntPtrToUShort),
        // xlb_f("IntSub", IntSub),
        // xlb_f("IntToChar", IntToChar),
        // xlb_f("IntToInt8", IntToInt8),
        // xlb_f("IntToShort", IntToShort),
        // xlb_f("IntToUChar", IntToUChar),
        // xlb_f("IntToUInt", IntToUInt),
        // xlb_f("IntToUInt8", IntToUInt8),
        // xlb_f("IntToULong", IntToULong),
        // xlb_f("IntToULongLong", IntToULongLong),
        // xlb_f("IntToUShort", IntToUShort),
        // xlb_f("InvalidateItem", InvalidateItem),
        // xlb_f("Invoke", Invoke),
        // xlb_f("Invoke", Invoke),
        // xlb_f("Invoke", Invoke),
        // xlb_f("Invoke", Invoke),
        // xlb_f("InvokeCommand", InvokeCommand),
        // xlb_f("InvokeVerbOnSelection", InvokeVerbOnSelection),
        // xlb_f("IsActive", IsActive),
        // xlb_f("IsAnimated", IsAnimated),
        // xlb_f("IsApplicationViewStateSupported", IsApplicationViewStateSupported),
        // xlb_f("IsBkDropTarget", IsBkDropTarget),
        xlb_f( "IsCharSpace", IsCharSpace ),
        // xlb_f("IsConnected", IsConnected),
        // xlb_f("IsConnected", IsConnected),
        // xlb_f("IsControlWindowShown", IsControlWindowShown),
        // xlb_f("IsDecoded", IsDecoded),
        // xlb_f("IsDelegateFolder", IsDelegateFolder),
        // xlb_f("IsDeskBandShown", IsDeskBandShown),
        // xlb_f("IsDropOnSource", IsDropOnSource),
        // xlb_f("IsEditable", IsEditable),
        // xlb_f("IsEnabled", IsEnabled),
        // xlb_f("IsEnabled", IsEnabled),
        // xlb_f("IsEntryInStore", IsEntryInStore),
        // xlb_f("IsEqualPropertyKey", IsEqualPropertyKey),
        // xlb_f("IsInstalled", IsInstalled),
        xlb_f( "IsInternetESCEnabled", IsInternetESCEnabled ),
        // xlb_f("IsLauncherVisible", IsLauncherVisible),
        // xlb_f("IsMember", IsMember),
        // xlb_f("IsMemberOf", IsMemberOf),
        // xlb_f("IsMenuMessage", IsMenuMessage),
        // xlb_f("IsMoveInSameFolder", IsMoveInSameFolder),
        // xlb_f("IsMultipage", IsMultipage),
        xlb_f( "IsNetDrive", IsNetDrive ), 
        xlb_f( "IsOS", IsOS ),
        // xlb_f("IsPrintable", IsPrintable),
        // xlb_f("IsRecommended", IsRecommended),
        // xlb_f("IsRunning", IsRunning),
        // xlb_f("IsTransparent", IsTransparent),
        xlb_f( "IStream_Copy", IStream_Copy ), 
        xlb_f( "IStream_Read", IStream_Read ),
        xlb_f( "IStream_ReadPidl", IStream_ReadPidl ),
        xlb_f( "IStream_ReadStr", IStream_ReadStr ), 
        xlb_f( "IStream_Reset", IStream_Reset ),
        xlb_f( "IStream_Size", IStream_Size ), 
        xlb_f( "IStream_Write", IStream_Write ),
        xlb_f( "IStream_WritePidl", IStream_WritePidl ),
        xlb_f( "IStream_WriteStr", IStream_WriteStr ),
        xlb_f( "IsUserAnAdmin", IsUserAnAdmin ),
        // xlb_f("IsVector", IsVector),
        // xlb_f("IsWindowOnCurrentVirtualDesktop", IsWindowOnCurrentVirtualDesktop),
        // xlb_f("Item", Item),
        // xlb_f("Item", Item),
        // xlb_f("ItemCount", ItemCount),
        // xlb_f("ItemPostPaint", ItemPostPaint),
        // xlb_f("ItemPrePaint", ItemPrePaint),
        // xlb_f("Items", Items),
        xlb_f( "IUnknown_AtomicRelease", IUnknown_AtomicRelease ),
        xlb_f( "IUnknown_GetSite", IUnknown_GetSite ),
        xlb_f( "IUnknown_GetWindow", IUnknown_GetWindow ),
        xlb_f( "IUnknown_QueryService", IUnknown_QueryService ),
        xlb_f( "IUnknown_Set", IUnknown_Set ), 
        xlb_f( "IUnknown_SetSite", IUnknown_SetSite ),
        // xlb_f("KeepItems", KeepItems),
        // xlb_f("KeepOther", KeepOther),
        // xlb_f("KeepRecent", KeepRecent),
        // xlb_f("Kill", Kill),
        // xlb_f("LaunchAdvancedAssociationUI", LaunchAdvancedAssociationUI),
        // xlb_f("LauncherVisibilityChange", LauncherVisibilityChange),
        // xlb_f("LeaveFolder", LeaveFolder),
        // xlb_f("LeaveFolder", LeaveFolder),
        // xlb_f("LinkItem", LinkItem),
        // xlb_f("LoadLibraryFromItem", LoadLibraryFromItem),
        // xlb_f("LoadLibraryFromKnownFolder", LoadLibraryFromKnownFolder),
        // xlb_f("LoadNonloadedOverlayIdentifiers", LoadNonloadedOverlayIdentifiers),
        xlb_f( "LoadUserProfile", LoadUserProfile ),
        // xlb_f("Location", Location),
        // xlb_f("LogError", LogError),
        // xlb_f("LongAdd", LongAdd),
        // xlb_f("LongLongAdd", LongLongAdd),
        // xlb_f("LongLongMult", LongLongMult),
        // xlb_f("LongLongSub", LongLongSub),
        // xlb_f("LongLongToChar", LongLongToChar),
        // xlb_f("LongLongToInt", LongLongToInt),
        // xlb_f("LongLongToInt8", LongLongToInt8),
        // xlb_f("LongLongToIntPtr", LongLongToIntPtr),
        // xlb_f("LongLongToLong", LongLongToLong),
        // xlb_f("LongLongToLongPtr", LongLongToLongPtr),
        // xlb_f("LongLongToShort", LongLongToShort),
        // xlb_f("LongLongToUChar", LongLongToUChar),
        // xlb_f("LongLongToUInt", LongLongToUInt),
        // xlb_f("LongLongToUInt8", LongLongToUInt8),
        // xlb_f("LongLongToULong", LongLongToULong),
        // xlb_f("LongLongToULongLong", LongLongToULongLong),
        // xlb_f("LongLongToUShort", LongLongToUShort),
        // xlb_f("LongMult", LongMult),
        // xlb_f("LongPtrAdd", LongPtrAdd),
        // xlb_f("LongPtrMult", LongPtrMult),
        // xlb_f("LongPtrSub", LongPtrSub),
        // xlb_f("LongPtrToChar", LongPtrToChar),
        // xlb_f("LongPtrToInt", LongPtrToInt),
        // xlb_f("LongPtrToInt8", LongPtrToInt8),
        // xlb_f("LongPtrToIntPtr", LongPtrToIntPtr),
        // xlb_f("LongPtrToLong", LongPtrToLong),
        // xlb_f("LongPtrToShort", LongPtrToShort),
        // xlb_f("LongPtrToUChar", LongPtrToUChar),
        // xlb_f("LongPtrToUInt", LongPtrToUInt),
        // xlb_f("LongPtrToUInt8", LongPtrToUInt8),
        // xlb_f("LongPtrToUIntPtr", LongPtrToUIntPtr),
        // xlb_f("LongPtrToULong", LongPtrToULong),
        // xlb_f("LongPtrToULongLong", LongPtrToULongLong),
        // xlb_f("LongPtrToULongPtr", LongPtrToULongPtr),
        // xlb_f("LongPtrToUShort", LongPtrToUShort),
        // xlb_f("LongSub", LongSub),
        // xlb_f("LongToChar", LongToChar),
        // xlb_f("LongToInt", LongToInt),
        // xlb_f("LongToInt8", LongToInt8),
        // xlb_f("LongToIntPtr", LongToIntPtr),
        // xlb_f("LongToShort", LongToShort),
        // xlb_f("LongToUChar", LongToUChar),
        // xlb_f("LongToUInt", LongToUInt),
        // xlb_f("LongToUInt8", LongToUInt8),
        // xlb_f("LongToUIntPtr", LongToUIntPtr),
        // xlb_f("LongToULong", LongToULong),
        // xlb_f("LongToULongLong", LongToULongLong),
        // xlb_f("LongToULongPtr", LongToULongPtr),
        // xlb_f("LongToUShort", LongToUShort),
        xlb_class<xlb_cbf<LPFNDFMCALLBACK>>( "LPFNDFMCALLBACK" ).constructor<xlb_luafunc>(),
        xlb_class<xlb_cbf<LPFNVIEWCALLBACK>>( "LPFNVIEWCALLBACK" ).constructor<xlb_luafunc>(),
        // xlb_f("MakeDefault", MakeDefault),
        // xlb_f("MAKEDLLVERULL", MAKEDLLVERULL),
        // xlb_f("MakeProminent", MakeProminent),
        // xlb_f("MapColumnToSCID", MapColumnToSCID),
        // xlb_f("MarkForDelete", MarkForDelete),
        // xlb_f("MarkFullscreenWindow", MarkFullscreenWindow),
        // xlb_f("Merge", Merge),
        // xlb_f("MessageSFVCB", MessageSFVCB),
        //xlb_f( "MIMEAssociationDialog", MIMEAssociationDialog ), // undefined
        // xlb_f("MoveIcons", MoveIcons),
        // xlb_f("MoveItem", MoveItem),
        // xlb_f("MoveItem", MoveItem),
        // xlb_f("MoveItems", MoveItems),
        // xlb_f("MoveWindowToDesktop", MoveWindowToDesktop),
        // xlb_f("NavigateToPidl", NavigateToPidl),
        // xlb_f("NetAddr_DisplayErrorTip", NetAddr_DisplayErrorTip),
        // xlb_f("NetAddr_GetAddress", NetAddr_GetAddress),
        // xlb_f("NetAddr_GetAllowType", NetAddr_GetAllowType),
        // xlb_f("NetAddr_SetAllowType", NetAddr_SetAllowType),
        // xlb_f("NewItem", NewItem),
        // xlb_f("Next", Next),
        // xlb_f("Next", Next),
        // xlb_f("Next", Next),
        // xlb_f("Next", Next),
        // xlb_f("Next", Next),
        // xlb_f("Next", Next),
        // xlb_f("Next", Next),
        // xlb_f("Next", Next),
        // xlb_f("Next", Next),
        // xlb_f("Next", Next),
        // xlb_f("Next", Next),
        // xlb_f("Next", Next),
        // xlb_f("Next", Next),
        // xlb_f("NextFrame", NextFrame),
        // xlb_f("NextPage", NextPage),
        // xlb_f("Notify", Notify),
        // xlb_f("NotifyRedirect", NotifyRedirect),
        // xlb_f("Offline", Offline),
        // xlb_f("OnActivated", OnActivated),
        // xlb_f("OnAfterContextMenu", OnAfterContextMenu),
        // xlb_f("OnAfterExpand", OnAfterExpand),
        // xlb_f("OnBalloonUserClick", OnBalloonUserClick),
        // xlb_f("OnBeforeContextMenu", OnBeforeContextMenu),
        // xlb_f("OnBeforeExpand", OnBeforeExpand),
        // xlb_f("OnBeforeItemDelete", OnBeforeItemDelete),
        // xlb_f("OnBeforeStateImageChange", OnBeforeStateImageChange),
        // xlb_f("OnBeginLabelEdit", OnBeginLabelEdit),
        // xlb_f("OnButtonClicked", OnButtonClicked),
        // xlb_f("OnChange", OnChange),
        // xlb_f("OnCheckButtonToggled", OnCheckButtonToggled),
        // xlb_f("OnColumnClicked", OnColumnClicked),
        // xlb_f("OnCommand", OnCommand),
        // xlb_f("OnContextMenu", OnContextMenu),
        // xlb_f("OnControlActivating", OnControlActivating),
        // xlb_f("OnCreate", OnCreate),
        // xlb_f("OnCreated", OnCreated),
        // xlb_f("OnCreating", OnCreating),
        // xlb_f("OnCreatingWindow", OnCreatingWindow),
        // xlb_f("OnDefaultCommand", OnDefaultCommand),
        // xlb_f("OnDestroy", OnDestroy),
        // xlb_f("OnDoDefaultAccessibilityAction", OnDoDefaultAccessibilityAction),
        // xlb_f("OnDragEnter", OnDragEnter),
        // xlb_f("OnDragLeave", OnDragLeave),
        // xlb_f("OnDragOver", OnDragOver),
        // xlb_f("OnDragPosition", OnDragPosition),
        // xlb_f("OnDrop", OnDrop),
        // xlb_f("OnDropPosition", OnDropPosition),
        // xlb_f("OnEndLabelEdit", OnEndLabelEdit),
        // xlb_f("OnFileOk", OnFileOk),
        // xlb_f("OnFocusChangeIS", OnFocusChangeIS),
        // xlb_f("OnFolderChange", OnFolderChange),
        // xlb_f("OnFolderChanging", OnFolderChanging),
        // xlb_f("OnFrameWindowActivateBS", OnFrameWindowActivateBS),
        // xlb_f("OnGetAccessibilityRole", OnGetAccessibilityRole),
        // xlb_f("OnGetDefaultAccessibilityAction", OnGetDefaultAccessibilityAction),
        // xlb_f("OnGetToolTip", OnGetToolTip),
        // xlb_f("OnHttpEquiv", OnHttpEquiv),
        // xlb_f("OnInvoke", OnInvoke),
        // xlb_f("OnInvoke", OnInvoke),
        // xlb_f("OnItemAdded", OnItemAdded),
        // xlb_f("OnItemClick", OnItemClick),
        // xlb_f("OnItemDeleted", OnItemDeleted),
        // xlb_f("OnItemSelected", OnItemSelected),
        // xlb_f("OnItemStateChanged", OnItemStateChanged),
        // xlb_f("OnItemStateChanging", OnItemStateChanging),
        // xlb_f("OnKeyboardInput", OnKeyboardInput),
        // xlb_f("OnLeftClick", OnLeftClick),
        // xlb_f("OnNavigate", OnNavigate),
        // xlb_f("OnNavigationComplete", OnNavigationComplete),
        // xlb_f("OnNavigationFailed", OnNavigationFailed),
        // xlb_f("OnNavigationPending", OnNavigationPending),
        // xlb_f("OnNotify", OnNotify),
        // xlb_f("OnOverwrite", OnOverwrite),
        // xlb_f("OnPictureChange", OnPictureChange),
        // xlb_f("OnPosRectChangeDB", OnPosRectChangeDB),
        // xlb_f("OnPreViewCreated", OnPreViewCreated),
        // xlb_f("OnPropertyItemCommit", OnPropertyItemCommit),
        // xlb_f("OnSelect", OnSelect),
        // xlb_f("OnSelectionChange", OnSelectionChange),
        // xlb_f("OnSelectionChanged", OnSelectionChanged),
        // xlb_f("OnSetFocus", OnSetFocus),
        // xlb_f("OnSetTitle", OnSetTitle),
        // xlb_f("OnShareViolation", OnShareViolation),
        // xlb_f("OnSize", OnSize),
        // xlb_f("OnStateChange", OnStateChange),
        // xlb_f("OnStateChanged", OnStateChanged),
        // xlb_f("OnTranslateAccelerator", OnTranslateAccelerator),
        // xlb_f("OnTranslateAccelerator", OnTranslateAccelerator),
        // xlb_f("OnTypeChange", OnTypeChange),
        // xlb_f("OnViewCreated", OnViewCreated),
        // xlb_f("OnViewWindowActive", OnViewWindowActive),
        // xlb_f("Open", Open),
        // xlb_f("Open", Open),
        // xlb_f("OpenItem", OpenItem),
        xlb_f( "OpenRegStream", OpenRegStream ),
        // xlb_f("OpenResource", OpenResource),
        // xlb_f("OverlappedResult", OverlappedResult),
        // xlb_f("OverlayIndexFromImageIndex", OverlayIndexFromImageIndex),
        // xlb_f("PageInThumbnail", PageInThumbnail),
        xlb_class<xlb_cbf<PAPPSTATE_CHANGE_ROUTINE>>( "PAPPSTATE_CHANGE_ROUTINE" )
            .constructor<xlb_luafunc>(),
        // xlb_f("ParseDisplayName", ParseDisplayName),
        xlb_f( "ParseURL", ParseURL ), 
        xlb_f( "PathAddBackslash", PathAddBackslash ),
        xlb_f( "PathAddExtension", PathAddExtension ),
        xlb_f( "PathAllocCanonicalize", PathAllocCanonicalize ),
        xlb_f( "PathAllocCombine", PathAllocCombine ), 
        xlb_f( "PathAppend", PathAppend ),
        xlb_f( "PathBuildRoot", PathBuildRoot ),
        xlb_f( "PathCanonicalize", PathCanonicalize ),
        xlb_f( "PathCchAddBackslash", PathCchAddBackslash ),
        xlb_f( "PathCchAddBackslashEx", PathCchAddBackslashEx ),
        xlb_f( "PathCchAddExtension", PathCchAddExtension ),
        xlb_f( "PathCchAppend", PathCchAppend ), 
        xlb_f( "PathCchAppendEx", PathCchAppendEx ),
        xlb_f( "PathCchCanonicalize", PathCchCanonicalize ),
        xlb_f( "PathCchCanonicalizeEx", PathCchCanonicalizeEx ),
        xlb_f( "PathCchCombine", PathCchCombine ),
        xlb_f( "PathCchCombineEx", PathCchCombineEx ),

        xlb_f<HRESULT APIENTRY ( * )( PCWSTR, size_t, PCWSTR* )>( "PathCchFindExtension",
                                                                  PathCchFindExtension ),

        xlb_f( "PathCchIsRoot", PathCchIsRoot ),
        xlb_f( "PathCchRemoveBackslash", PathCchRemoveBackslash ),
        xlb_f( "PathCchRemoveBackslashEx", PathCchRemoveBackslashEx ),
        xlb_f( "PathCchRemoveExtension", PathCchRemoveExtension ),
        xlb_f( "PathCchRemoveFileSpec", PathCchRemoveFileSpec ),
        xlb_f( "PathCchRenameExtension", PathCchRenameExtension ),

        xlb_f<HRESULT APIENTRY ( * )( PCWSTR, PCWSTR* )>( "PathCchSkipRoot",
                                                          PathCchSkipRoot ),

        xlb_f( "PathCchStripPrefix", PathCchStripPrefix ),
        xlb_f( "PathCchStripToRoot", PathCchStripToRoot ),
        xlb_f( "PathCleanupSpec", PathCleanupSpec ), 
        xlb_f( "PathCombine", PathCombine ),
        xlb_f( "PathCommonPrefix", PathCommonPrefix ),
        xlb_f( "PathCompactPath", PathCompactPath ),
        xlb_f( "PathCompactPathEx", PathCompactPathEx ),
        xlb_f( "PathCreateFromUrl", PathCreateFromUrl ),
        xlb_f( "PathCreateFromUrlAlloc", PathCreateFromUrlAlloc ),
        xlb_f( "PathFileExists", PathFileExists ),
        xlb_f( "PathFindExtension", PathFindExtension ),
        xlb_f( "PathFindFileName", PathFindFileName ),
        xlb_f( "PathFindNextComponent", PathFindNextComponent ),
        xlb_f( "PathFindOnPath", PathFindOnPath ),
        xlb_f( "PathFindSuffixArray", PathFindSuffixArray ),
        xlb_f( "PathGetArgs", PathGetArgs ), 
        xlb_f( "PathGetCharType", PathGetCharType ),
        xlb_f( "PathGetDriveNumber", PathGetDriveNumber ),
        xlb_f( "PathGetShortPath", PathGetShortPath ),
        xlb_f( "PathIsContentType", PathIsContentType ),
        xlb_f( "PathIsDirectory", PathIsDirectory ),
        xlb_f( "PathIsDirectoryEmpty", PathIsDirectoryEmpty ),
        xlb_f( "PathIsExe", PathIsExe ), 
        xlb_f( "PathIsFileSpec", PathIsFileSpec ),
        // xlb_f("PathIsHTMLFileA", PathIsHTMLFileA),
        // xlb_f("PathIsHTMLFileW", PathIsHTMLFileW),
        xlb_f( "PathIsLFNFileSpec", PathIsLFNFileSpec ),
        xlb_f( "PathIsNetworkPath", PathIsNetworkPath ),
        xlb_f( "PathIsPrefix", PathIsPrefix ), 
        xlb_f( "PathIsRelative", PathIsRelative ),
        xlb_f( "PathIsRoot", PathIsRoot ), 
        xlb_f( "PathIsSameRoot", PathIsSameRoot ),
        xlb_f( "PathIsSlow", PathIsSlow ), 
        xlb_f( "PathIsSystemFolder", PathIsSystemFolder ),
        xlb_f( "PathIsUNC", PathIsUNC ),

        xlb_f<BOOL APIENTRY ( * )( PCWSTR, PCWSTR* )>( "PathIsUNCEx", PathIsUNCEx ),

        xlb_f( "PathIsUNCServer", PathIsUNCServer ),
        xlb_f( "PathIsUNCServerShare", PathIsUNCServerShare ),
        xlb_f( "PathIsURL", PathIsURL ), 
        xlb_f( "PathMakePretty", PathMakePretty ),
        xlb_f( "PathMakeSystemFolder", PathMakeSystemFolder ),
        xlb_f( "PathMakeUniqueName", PathMakeUniqueName ),
        xlb_f( "PathMatchSpec", PathMatchSpec ), 
        xlb_f( "PathMatchSpecEx", PathMatchSpecEx ),
        xlb_f( "PathParseIconLocation", PathParseIconLocation ),
        // xlb_f("PathProcessCommand", PathProcessCommand),
        xlb_f( "PathQuoteSpaces", PathQuoteSpaces ),
        xlb_f( "PathRelativePathTo", PathRelativePathTo ),
        xlb_f( "PathRemoveArgs", PathRemoveArgs ),
        xlb_f( "PathRemoveBackslash", PathRemoveBackslash ),
        xlb_f( "PathRemoveBlanks", PathRemoveBlanks ),
        xlb_f( "PathRemoveExtension", PathRemoveExtension ),
        xlb_f( "PathRemoveFileSpec", PathRemoveFileSpec ),
        xlb_f( "PathRenameExtension", PathRenameExtension ),
        xlb_f( "PathResolve", PathResolve ),
        xlb_f( "PathSearchAndQualify", PathSearchAndQualify ),
        xlb_f( "PathSetDlgItemPath", PathSetDlgItemPath ),
        xlb_f( "PathSkipRoot", PathSkipRoot ), 
        xlb_f( "PathStripPath", PathStripPath ),
        xlb_f( "PathStripToRoot", PathStripToRoot ),
        xlb_f( "PathUndecorate", PathUndecorate ),
        xlb_f( "PathUnExpandEnvStrings", PathUnExpandEnvStrings ),
        xlb_f( "PathUnmakeSystemFolder", PathUnmakeSystemFolder ),
        xlb_f( "PathUnquoteSpaces", PathUnquoteSpaces ),
        xlb_f( "PathYetAnotherMakeUniqueName", PathYetAnotherMakeUniqueName ),
        // xlb_f("PauseTimer", PauseTimer),
        // xlb_f("PauseTimer", PauseTimer),
        // xlb_f("PerformOperations", PerformOperations),
        //xlb_f( "PerUserInit", PerUserInit ), // undefined
        xlb_f( "PickIconDlg", PickIconDlg ),
        //xlb_f( "PlaySound", PlaySound ), // undefined
        // xlb_f("Popup", Popup),
        // xlb_f("Popup", Popup),
        // xlb_f("PopupItemMenu", PopupItemMenu),
        // xlb_f("PostCopyItem", PostCopyItem),
        // xlb_f("PostDeleteItem", PostDeleteItem),
        // xlb_f("PostMoveItem", PostMoveItem),
        // xlb_f("PostNewItem", PostNewItem),
        // xlb_f("PostPaint", PostPaint),
        // xlb_f("PostRenameItem", PostRenameItem),
        // xlb_f("PreCopyItem", PreCopyItem),
        // xlb_f("PreDeleteItem", PreDeleteItem),
        // xlb_f("PreMoveItem", PreMoveItem),
        // xlb_f("PreNewItem", PreNewItem),
        // xlb_f("PrePaint", PrePaint),
        // xlb_f("PrepareForSync", PrepareForSync),
        // xlb_f("PrepareForSyncCompleted", PrepareForSyncCompleted),
        // xlb_f("PreRenameItem", PreRenameItem),
        // xlb_f("PresentConflict", PresentConflict),
        // xlb_f("PrevPage", PrevPage),
        // xlb_f("PrintTo", PrintTo),
        // xlb_f("PrintTo", PrintTo),
        // xlb_f("ProcessAttachDetach", ProcessAttachDetach),
        // xlb_f("ProfferService", ProfferService),
        // xlb_f("Progress", Progress),
        // xlb_f("Prompt", Prompt),
        // xlb_f("PropertyFailure", PropertyFailure),
        // xlb_f("ProposeItem", ProposeItem),
        // xlb_f("PtrdiffTAdd", PtrdiffTAdd),
        // xlb_f("PtrdiffTMult", PtrdiffTMult),
        // xlb_f("PtrdiffTSub", PtrdiffTSub),
        // xlb_f("put_CurrentViewMode", put_CurrentViewMode),
        // xlb_f("put_FolderFlags", put_FolderFlags),
        // xlb_f("put_GroupBy", put_GroupBy),
        // xlb_f("put_IconSize", put_IconSize),
        // xlb_f("put_SortColumns", put_SortColumns),
        // xlb_f("PutBaseBrowserData", PutBaseBrowserData),
        xlb_f( "QISearch", QISearch ),
        // xlb_f("QueryAbilities", QueryAbilities),
        // xlb_f("QueryAbort", QueryAbort),
        // xlb_f("QueryActiveShellView", QueryActiveShellView),
        // xlb_f("QueryAppIsDefault", QueryAppIsDefault),
        // xlb_f("QueryAppIsDefaultAll", QueryAppIsDefaultAll),
        // xlb_f("QueryBand", QueryBand),
        // xlb_f("QueryCancel", QueryCancel),
        // xlb_f("QueryContextMenu", QueryContextMenu),
        // xlb_f("QueryContinue", QueryContinue),
        // xlb_f("QueryCurrentDefault", QueryCurrentDefault),
        // xlb_f("QueryFocus", QueryFocus),
        // xlb_f("QueryForAdditionalItems", QueryForAdditionalItems),
        // xlb_f("QueryObject", QueryObject),
        // xlb_f("QuerySupport", QuerySupport),
        // xlb_f("ReadAsync", ReadAsync),
        xlb_f( "ReadCabinetState", ReadCabinetState ),
        // xlb_f("ReadPropertyNPB", ReadPropertyNPB),
        xlb_f( "RealDriveType", RealDriveType ),
        // xlb_f("Rearrange", Rearrange),
        // xlb_f("RecompressImage", RecompressImage),
        // xlb_f("RecycleItem", RecycleItem),
        // xlb_f("Redirect", Redirect),
        // xlb_f("Refresh", Refresh),
        // xlb_f("RefreshObject", RefreshObject),
        // xlb_f("RefreshOverlayImages", RefreshOverlayImages),
        // xlb_f("Register", Register),
        // xlb_f("RegisterAbort", RegisterAbort),
        xlb_f( "RegisterAppStateChangeNotification", RegisterAppStateChangeNotification ),
        // xlb_f("RegisterAsChild", RegisterAsChild),
        // xlb_f("RegisterDialogClasses", RegisterDialogClasses),
        // xlb_f("RegisterFolder", RegisterFolder),
        // xlb_f("RegisterForPackageStateChanges", RegisterForPackageStateChanges),
        // xlb_f("RegisterPending", RegisterPending),
        xlb_f( "RegisterScaleChangeEvent", RegisterScaleChangeEvent ),
        xlb_f( "RegisterScaleChangeNotifications", RegisterScaleChangeNotifications ),
        // xlb_f("RegisterSyncMgrHandler", RegisterSyncMgrHandler),
        // xlb_f("RegisterTab", RegisterTab),
        // xlb_f("RegisterWindow", RegisterWindow),
        // xlb_f("ReleaseShellView", ReleaseShellView),
        // xlb_f("Remove", Remove),
        // xlb_f("RemoveAll", RemoveAll),
        // xlb_f("RemoveAll", RemoveAll),
        // xlb_f("RemoveAllControlItems", RemoveAllControlItems),
        // xlb_f("RemoveAllDestinations", RemoveAllDestinations),
        // xlb_f("RemoveAllRoots", RemoveAllRoots),
        // xlb_f("RemoveBackReferences", RemoveBackReferences),
        // xlb_f("RemoveBand", RemoveBand),
        // xlb_f("RemoveConflicts", RemoveConflicts),
        // xlb_f("RemoveControlItem", RemoveControlItem),
        // xlb_f("RemoveDataBlock", RemoveDataBlock),
        // xlb_f("RemoveDestination", RemoveDestination),
        // xlb_f("RemoveEvent", RemoveEvent),
        // xlb_f("RemoveFolder", RemoveFolder),
        // xlb_f("RemoveFromList", RemoveFromList),
        // xlb_f("RemoveFromSyncSet", RemoveFromSyncSet),
        // xlb_f("RemoveIDList", RemoveIDList),
        // xlb_f("RemoveItem", RemoveItem),
        // xlb_f("RemoveItem", RemoveItem),
        // xlb_f("RemoveMenusSB", RemoveMenusSB),
        // xlb_f("RemoveObject", RemoveObject),
        // xlb_f("RemoveObjectAt", RemoveObjectAt),
        // xlb_f("RemovePropertyNPB", RemovePropertyNPB),
        // xlb_f("RemoveRoot", RemoveRoot),
        // xlb_f("RemoveTasks", RemoveTasks),
        // xlb_f("RemoveToolbar", RemoveToolbar),
        xlb_f( "RemoveWindowSubclass", RemoveWindowSubclass ),
        // xlb_f("RenameItem", RenameItem),
        // xlb_f("RenameItem", RenameItem),
        // xlb_f("RenameItems", RenameItems),
        // xlb_f("ReplaceFrame", ReplaceFrame),
        // xlb_f("ReplacePage", ReplacePage),
        xlb_f( "ReportEvent", ReportEvent ),
        // xlb_f("ReportManualSync", ReportManualSync),
        // xlb_f("ReportProgress", ReportProgress),
        // xlb_f("ReportResult", ReportResult),
        // xlb_f("RequestBorderSpaceDW", RequestBorderSpaceDW),
        // xlb_f("RequireTouchInEditControl", RequireTouchInEditControl),
        // xlb_f("Reset", Reset),
        // xlb_f("Reset", Reset),
        // xlb_f("Reset", Reset),
        // xlb_f("Reset", Reset),
        // xlb_f("Reset", Reset),
        // xlb_f("Reset", Reset),
        // xlb_f("Reset", Reset),
        // xlb_f("Reset", Reset),
        // xlb_f("Reset", Reset),
        // xlb_f("Reset", Reset),
        // xlb_f("Reset", Reset),
        // xlb_f("Reset", Reset),
        // xlb_f("ResetCancel", ResetCancel),
        // xlb_f("ResetEnumerator", ResetEnumerator),
        // xlb_f("ResetTimer", ResetTimer),
        // xlb_f("ResetTimer", ResetTimer),
        // xlb_f("ResizeBorderDW", ResizeBorderDW),
        // xlb_f("Resolve", Resolve),
        // xlb_f("Resolve", Resolve),
        // xlb_f("Resolve", Resolve),
        // xlb_f("ResolveFolder", ResolveFolder),
        // xlb_f("ResolveShellLink", ResolveShellLink),
        xlb_f( "RestartDialog", RestartDialog ), 
        xlb_f( "RestartDialogEx", RestartDialogEx ),
        // xlb_f("Result", Result),
        // xlb_f("Resume", Resume),
        // xlb_f("Resume", Resume),
        // xlb_f("ResumeTimer", ResumeTimer),
        // xlb_f("ResumeTimer", ResumeTimer),
        // xlb_f("RetrieveProperties", RetrieveProperties),
        // xlb_f("Revert", Revert),
        // xlb_f("Revoke", Revoke),
        xlb_f( "RevokeScaleChangeNotifications", RevokeScaleChangeNotifications ),
        // xlb_f("RevokeService", RevokeService),
        // xlb_f("Rotate", Rotate),
        // xlb_f("Run", Run),
        // xlb_f("Run", Run),
        // xlb_f("Run", Run),
        // xlb_f("RunGadget", RunGadget),
        // xlb_f("Save", Save),
        // xlb_f("Save", Save),
        // xlb_f("SaveInKnownFolder", SaveInKnownFolder),
        // xlb_f("SaveProperties", SaveProperties),
        // xlb_f("SaveViewState", SaveViewState),
        // xlb_f("SaveViewState", SaveViewState),
        // xlb_f("SaveWithUI", SaveWithUI),
        // xlb_f("Scale", Scale),
        //xlb_f( "ScreenSaverConfigureDialog", ScreenSaverConfigureDialog ), // undefined
        //xlb_f( "ScreenSaverProc", ScreenSaverProc ),
        // xlb_f("Select", Select),
        // xlb_f("SelectAndEditItem", SelectAndEditItem),
        // xlb_f("SelectAndPositionItem", SelectAndPositionItem),
        // xlb_f("SelectAndPositionItems", SelectAndPositionItems),
        // xlb_f("SelectedItems", SelectedItems),
        // xlb_f("SelectItem", SelectItem),
        // xlb_f("SelectItem", SelectItem),
        // xlb_f("SelectItem", SelectItem),
        // xlb_f("SelectItemRelative", SelectItemRelative),
        // xlb_f("SelectPage", SelectPage),
        // xlb_f("SendControlMsg", SendControlMsg),
        // xlb_f("SetAcceleratorMenu", SetAcceleratorMenu),
        // xlb_f("SetAccelerators", SetAccelerators),
        // xlb_f("SetAccessibleName", SetAccessibleName),
        // xlb_f("SetActivateState", SetActivateState),
        // xlb_f("SetActiveAlt", SetActiveAlt),
        // xlb_f("SetAdjacentDisplayEdges", SetAdjacentDisplayEdges),
        // xlb_f("SetAnimation", SetAnimation),
        // xlb_f("SetAppAsDefault", SetAppAsDefault),
        // xlb_f("SetAppAsDefaultAll", SetAppAsDefaultAll),
        // xlb_f("SetAppID", SetAppID),
        // xlb_f("SetAppID", SetAppID),
        // xlb_f("SetAppID", SetAppID),
        // xlb_f("SetAppID", SetAppID),
        // xlb_f("SetApplicationViewMinWidth", SetApplicationViewMinWidth),
        // xlb_f("SetApplicationViewOrientation", SetApplicationViewOrientation),
        // xlb_f("SetApplicationViewState", SetApplicationViewState),
        // xlb_f("SetArguments", SetArguments),
        // xlb_f("SetArguments", SetArguments),
        // xlb_f("SetAsDefFolderSettings", SetAsDefFolderSettings),
        // xlb_f("SetAsyncMode", SetAsyncMode),
        // xlb_f("SetAutomationObject", SetAutomationObject),
        // xlb_f("SetBackgroundColor", SetBackgroundColor),
        // xlb_f("SetBackgroundColor", SetBackgroundColor),
        // xlb_f("SetBalloonInfo", SetBalloonInfo),
        // xlb_f("SetBalloonInfo", SetBalloonInfo),
        // xlb_f("SetBalloonRetry", SetBalloonRetry),
        // xlb_f("SetBalloonRetry", SetBalloonRetry),
        // xlb_f("SetBandAvailability", SetBandAvailability),
        // xlb_f("SetBandInfoSFB", SetBandInfoSFB),
        // xlb_f("SetBandSiteInfo", SetBandSiteInfo),
        // xlb_f("SetBandState", SetBandState),
        // xlb_f("SetBorderSpaceDW", SetBorderSpaceDW),
        // xlb_f("SetCallback", SetCallback),
        // xlb_f("SetCancelButtonLabel", SetCancelButtonLabel),
        // xlb_f("SetCancelInformation", SetCancelInformation),
        // xlb_f("SetCancelMsg", SetCancelMsg),
        // xlb_f("SetCascade", SetCascade),
        // xlb_f("SetCheckboxValue", SetCheckboxValue),
        // xlb_f("SetCheckButtonState", SetCheckButtonState),
        // xlb_f("SetCheckState", SetCheckState),
        // xlb_f("SetClient", SetClient),
        // xlb_f("SetClientGuid", SetClientGuid),
        // xlb_f("SetClientGuid", SetClientGuid),
        // xlb_f("SetClientTitle", SetClientTitle),
        // xlb_f("SetClipboard", SetClipboard),
        // xlb_f("SetCodePage", SetCodePage),
        // xlb_f("SetCollectedProperties", SetCollectedProperties),
        // xlb_f("SetColor", SetColor),
        // xlb_f("SetColumnInfo", SetColumnInfo),
        // xlb_f("SetColumns", SetColumns),
        // xlb_f("SetComboBoxSelectedValue", SetComboBoxSelectedValue),
        // xlb_f("SetCompositionState", SetCompositionState),
        // xlb_f("SetCondition", SetCondition),
        // xlb_f("SetContext", SetContext),
        xlb_f( "SetContractDelegateWindow", SetContractDelegateWindow ),
        // xlb_f("SetControlItemState", SetControlItemState),
        // xlb_f("SetControlItemText", SetControlItemText),
        // xlb_f("SetControlLabel", SetControlLabel),
        // xlb_f("SetControlState", SetControlState),
        // xlb_f("SetControlStyle", SetControlStyle),
        // xlb_f("SetControlStyle2", SetControlStyle2),
        // xlb_f("SetCreateFlags", SetCreateFlags),
        // xlb_f("SetCurrentFolderFlags", SetCurrentFolderFlags),
        xlb_f( "SetCurrentProcessExplicitAppUserModelID",
               SetCurrentProcessExplicitAppUserModelID ),
        // xlb_f("SetCurrentViewMode", SetCurrentViewMode),
        // xlb_f("SetDataObject", SetDataObject),
        // xlb_f("SetDefaultExtension", SetDefaultExtension),
        // xlb_f("SetDefaultFolder", SetDefaultFolder),
        // xlb_f("SetDefaultIcon", SetDefaultIcon),
        // xlb_f("SetDefaultSaveFolder", SetDefaultSaveFolder),
        // xlb_f("SetDescription", SetDescription),
        // xlb_f("SetDescription", SetDescription),
        // xlb_f("SetDeselected", SetDeselected),
        // xlb_f("SetDirectory", SetDirectory),
        // xlb_f("SetDirectory", SetDirectory),
        // xlb_f("SetDisplayName", SetDisplayName),
        // xlb_f("SetEditBoxText", SetEditBoxText),
        // xlb_f("SetEmptyText", SetEmptyText),
        // xlb_f("SetEncoderParams", SetEncoderParams),
        // xlb_f("SetEnumReadyCallback", SetEnumReadyCallback),
        xlb_f( "SetEnvironmentVariable", SetEnvironmentVariable ),
        // xlb_f("SetErrorURL", SetErrorURL),
        // xlb_f("SetExtendedTileViewProperties", SetExtendedTileViewProperties),
        // xlb_f("SetFieldBitmap", SetFieldBitmap),
        // xlb_f("SetFieldCheckbox", SetFieldCheckbox),
        // xlb_f("SetFieldComboBoxSelectedItem", SetFieldComboBoxSelectedItem),
        // xlb_f("SetFieldInteractiveState", SetFieldInteractiveState),
        // xlb_f("SetFieldOptions", SetFieldOptions),
        // xlb_f("SetFieldState", SetFieldState),
        // xlb_f("SetFieldString", SetFieldString),
        // xlb_f("SetFieldSubmitButton", SetFieldSubmitButton),
        // xlb_f("SetFileID", SetFileID),
        // xlb_f("SetFileName", SetFileName),
        // xlb_f("SetFileName", SetFileName),
        // xlb_f("SetFileNameLabel", SetFileNameLabel),
        // xlb_f("SetFileTypeIndex", SetFileTypeIndex),
        // xlb_f("SetFileTypes", SetFileTypes),
        // xlb_f("SetFilter", SetFilter),
        // xlb_f("SetFilter", SetFilter),
        // xlb_f("SetFindData", SetFindData),
        // xlb_f("SetFlags", SetFlags),
        // xlb_f("SetFlags", SetFlags),
        // xlb_f("SetFlags", SetFlags),
        // xlb_f("SetFlags", SetFlags),
        // xlb_f("SetFlags", SetFlags),
        xlb_f( "SetFocus", SetFocus ),
        // xlb_f("SetFolder", SetFolder),
        // xlb_f("SetFolder", SetFolder),
        // xlb_f("SetFolder", SetFolder),
        // xlb_f("SetFolderLogicalViewMode", SetFolderLogicalViewMode),
        // xlb_f("SetFolderSettings", SetFolderSettings),
        // xlb_f("SetFolderType", SetFolderType),
        // xlb_f("SetFolderTypeID", SetFolderTypeID),
        // xlb_f("SetFolderViewOptions", SetFolderViewOptions),
        // xlb_f("SetFont", SetFont),
        // xlb_f("SetFont", SetFont),
        // xlb_f("SetGroupBy", SetGroupBy),
        // xlb_f("SetGroupColumn", SetGroupColumn),
        // xlb_f("SetGroupSubsetCount", SetGroupSubsetCount),
        // xlb_f("SetHandlerClsid", SetHandlerClsid),
        // xlb_f("SetHandlerProgressText", SetHandlerProgressText),
        // xlb_f("SetHistoryObject", SetHistoryObject),
        // xlb_f("SetHotkey", SetHotkey),
        // xlb_f("SetHotkey", SetHotkey),
        // xlb_f("SetHotKey", SetHotKey),
        // xlb_f("SetIcon", SetIcon),
        // xlb_f("SetIconInfo", SetIconInfo),
        // xlb_f("SetIconInfo", SetIconInfo),
        // xlb_f("SetIconLocation", SetIconLocation),
        // xlb_f("SetIconLocation", SetIconLocation),
        // xlb_f("SetIconSize", SetIconSize),
        // xlb_f("SetIDList", SetIDList),
        // xlb_f("SetIDList", SetIDList),
        // xlb_f("SetIDList", SetIDList),
        // xlb_f("SetInitialURL", SetInitialURL),
        // xlb_f("SetIsOnLockScreen", SetIsOnLockScreen),
        // xlb_f("SetItem", SetItem),
        // xlb_f("SetItemAlloc", SetItemAlloc),
        // xlb_f("SetItemAlloc", SetItemAlloc),
        // xlb_f("SetItemChoices", SetItemChoices),
        // xlb_f("SetItemCustomState", SetItemCustomState),
        // xlb_f("SetItemHeight", SetItemHeight),
        // xlb_f("SetItemPos", SetItemPos),
        // xlb_f("SetItemState", SetItemState),
        // xlb_f("SetItemStatus", SetItemStatus),
        // xlb_f("SetJunctionCLSID", SetJunctionCLSID),
        // xlb_f("SetKey", SetKey),
        // xlb_f("SetKeyState", SetKeyState),
        // xlb_f("SetLine", SetLine),
        // xlb_f("SetLocalPath", SetLocalPath),
        xlb_f( "SetMenu", SetMenu ), 
        xlb_f( "SetMenuContextHelpId", SetMenuContextHelpId ),
        // xlb_f("SetMenuRestrictions", SetMenuRestrictions),
        // xlb_f("SetMenuSB", SetMenuSB),
        // xlb_f("SetMenuToolbar", SetMenuToolbar),
        // xlb_f("SetMode", SetMode),
        // xlb_f("SetMode", SetMode),
        // xlb_f("SetNamedValue", SetNamedValue),
        // xlb_f("SetNameOf", SetNameOf),
        // xlb_f("SetNativeDisplayOrientation", SetNativeDisplayOrientation),
        // xlb_f("SetNativeDisplaySize", SetNativeDisplaySize),
        // xlb_f("SetNavigateState", SetNavigateState),
        // xlb_f("SetNavigationRoot", SetNavigationRoot),
        // xlb_f("SetNoIcons", SetNoIcons),
        // xlb_f("SetNormalIcon", SetNormalIcon),
        // xlb_f("SetNoShowUI", SetNoShowUI),
        // xlb_f("SetNoText", SetNoText),
        // xlb_f("SetObjectCount", SetObjectCount),
        // xlb_f("SetObscured", SetObscured),
        // xlb_f("SetOkButtonLabel", SetOkButtonLabel),
        // xlb_f("SetOpenIcon", SetOpenIcon),
        // xlb_f("SetOperation", SetOperation),
        // xlb_f("SetOperationFlags", SetOperationFlags),
        // xlb_f("SetOptions", SetOptions),
        // xlb_f("SetOptions", SetOptions),
        // xlb_f("SetOptions", SetOptions),
        // xlb_f("SetOptions", SetOptions),
        // xlb_f("SetOptions", SetOptions),
        // xlb_f("SetOverlayIcon", SetOverlayIcon),
        // xlb_f("SetOwner", SetOwner),
        // xlb_f("SetOwnerWindow", SetOwnerWindow),
        // xlb_f("SetParameters", SetParameters),
        // xlb_f("SetParentAndItem", SetParentAndItem),
        // xlb_f("SetPath", SetPath),
        // xlb_f("SetPath", SetPath),
        // xlb_f("SetPath", SetPath),
        // xlb_f("SetPinnedWindow", SetPinnedWindow),
        // xlb_f("SetPoints", SetPoints),
        // xlb_f("SetPosition", SetPosition),
        // xlb_f("SetPosition", SetPosition),
        // xlb_f("SetPresenterChoice", SetPresenterChoice),
        // xlb_f("SetPresenterNextStep", SetPresenterNextStep),
        //xlb_f( "SetProcessReference", SetProcessReference ), // undefined
        // xlb_f("SetProgID", SetProgID),
        // xlb_f("SetProgress", SetProgress),
        // xlb_f("SetProgress64", SetProgress64),
        // xlb_f("SetProgressCallback", SetProgressCallback),
        // xlb_f("SetProgressDialog", SetProgressDialog),
        // xlb_f("SetProgressMessage", SetProgressMessage),
        // xlb_f("SetProgressState", SetProgressState),
        // xlb_f("SetProgressValue", SetProgressValue),
        // xlb_f("SetProperties", SetProperties),
        // xlb_f("SetProperties", SetProperties),
        // xlb_f("SetProperties", SetProperties),
        // xlb_f("SetPropertyBag", SetPropertyBag),
        // xlb_f("SetPropertyKey", SetPropertyKey),
        // xlb_f("SetPropertyStorage", SetPropertyStorage),
        // xlb_f("SetProviderFilter", SetProviderFilter),
        xlb_f( "SetRect", SetRect ), 
        xlb_f( "SetRect", SetRect ),
        // xlb_f("SetRedraw", SetRedraw),
        // xlb_f("SetRedraw", SetRedraw),
        // xlb_f("SetReferent", SetReferent),
        // xlb_f("SetReferent", SetReferent),
        // xlb_f("SetReferrer", SetReferrer),
        // xlb_f("SetReferrer", SetReferrer),
        // xlb_f("SetRelativePath", SetRelativePath),
        // xlb_f("SetRelativePath", SetRelativePath),
        // xlb_f("SetSaveAsItem", SetSaveAsItem),
        // xlb_f("SetScaleFactor", SetScaleFactor),
        // xlb_f("SetScope", SetScope),
        // xlb_f("SetSelected", SetSelected),
        // xlb_f("SetSelectedControlItem", SetSelectedControlItem),
        // xlb_f("SetSelection", SetSelection),
        // xlb_f("SetSerialization", SetSerialization),
        // xlb_f("SetShellFolder", SetShellFolder),
        // xlb_f("SetShortcutIcon", SetShortcutIcon),
        // xlb_f("SetShowCmd", SetShowCmd),
        // xlb_f("SetShowCmd", SetShowCmd),
        // xlb_f("SetShowWindow", SetShowWindow),
        // xlb_f("SetSlideshow", SetSlideshow),
        // xlb_f("SetSlideshowOptions", SetSlideshowOptions),
        // xlb_f("SetSortColumns", SetSortColumns),
        // xlb_f("SetSortColumns", SetSortColumns),
        // xlb_f("SetSource", SetSource),
        // xlb_f("SetStacks", SetStacks),
        // xlb_f("SetStatusMessage", SetStatusMessage),
        // xlb_f("SetStatusTextSB", SetStatusTextSB),
        // xlb_f("SetStringValue", SetStringValue),
        // xlb_f("SetSubMenu", SetSubMenu),
        // xlb_f("SetTabActive", SetTabActive),
        // xlb_f("SetTabOrder", SetTabOrder),
        // xlb_f("SetTabProperties", SetTabProperties),
        // xlb_f("SetTargetSessionId", SetTargetSessionId),
        // xlb_f("SetText", SetText),
        xlb_f( "SetTextColor", SetTextColor ),
        // xlb_f("SetTheme", SetTheme),
        // xlb_f("SetTheme", SetTheme),
        // xlb_f("SetThumbnailClip", SetThumbnailClip),
        // xlb_f("SetThumbnailStream", SetThumbnailStream),
        // xlb_f("SetThumbnailTooltip", SetThumbnailTooltip),
        // xlb_f("SetTileViewProperties", SetTileViewProperties),
        // xlb_f("SetTimes", SetTimes),
        // xlb_f("SetTitle", SetTitle),
        // xlb_f("SetTitle", SetTitle),
        // xlb_f("SetTitle", SetTitle),
        // xlb_f("SetTitle", SetTitle),
        // xlb_f("SetToolbarItems", SetToolbarItems),
        // xlb_f("SetTopBrowser", SetTopBrowser),
        // xlb_f("SetUsageScenario", SetUsageScenario),
        // xlb_f("SetUserArray", SetUserArray),
        // xlb_f("SetViewModeAndIconSize", SetViewModeAndIconSize),
        // xlb_f("SetViewProperty", SetViewProperty),
        // xlb_f("SetVisibleColumns", SetVisibleColumns),
        // xlb_f("SetWallpaper", SetWallpaper),
        // xlb_f("SetWatermark", SetWatermark),
        // xlb_f("SetWindow", SetWindow),
        xlb_f( "SetWindowContextHelpId", SetWindowContextHelpId ),
        xlb_f( "SetWindowSubclass", SetWindowSubclass ),
        // xlb_f("SetWorkingDirectory", SetWorkingDirectory),
        // xlb_f("SetWorkingDirectory", SetWorkingDirectory),
        xlb_f( "SHAddFolderPathToLibrary", SHAddFolderPathToLibrary ),
        xlb_f( "SHAddFromPropSheetExtArray", SHAddFromPropSheetExtArray ),
        xlb_f( "SHAddToRecentDocs", SHAddToRecentDocs ), 
        xlb_f( "SHAlloc", SHAlloc ),
        xlb_f( "SHAllocShared", SHAllocShared ), 
        xlb_f( "SHAnsiToAnsi", SHAnsiToAnsi ),
        xlb_f( "SHAnsiToUnicode", SHAnsiToUnicode ),
        xlb_f( "SHAppBarMessage", SHAppBarMessage ),
        // xlb_f("ShareExists", ShareExists),
        // xlb_f("SharePrinters", SharePrinters),
        xlb_f( "SHAssocEnumHandlers", SHAssocEnumHandlers ),
        xlb_f( "SHAssocEnumHandlersForProtocolByApplication",
               SHAssocEnumHandlersForProtocolByApplication ),
        xlb_f( "SHAutoComplete", SHAutoComplete ),
        xlb_f( "SHBindToFolderIDListParent", SHBindToFolderIDListParent ),
        xlb_f( "SHBindToFolderIDListParentEx", SHBindToFolderIDListParentEx ),
        xlb_f( "SHBindToObject", SHBindToObject ), 
        xlb_f( "SHBindToParent", SHBindToParent ),
        xlb_f( "SHBrowseForFolder", SHBrowseForFolder ),
        xlb_f( "SHChangeNotification_Lock", SHChangeNotification_Lock ),
        xlb_f( "SHChangeNotification_Unlock", SHChangeNotification_Unlock ),
        xlb_f( "SHChangeNotify", SHChangeNotify ),
        xlb_f( "SHChangeNotifyDeregister", SHChangeNotifyDeregister ),
        xlb_f( "SHChangeNotifyRegister", SHChangeNotifyRegister ),
        xlb_f( "SHChangeNotifyRegisterThread", SHChangeNotifyRegisterThread ),
        xlb_f( "SHCloneSpecialIDList", SHCloneSpecialIDList ),
        xlb_f( "SHCLSIDFromString", SHCLSIDFromString ),
        xlb_f( "SHCoCreateInstance", SHCoCreateInstance ), 
        xlb_f( "SHCopyKey", SHCopyKey ),
        xlb_f( "SHCreateAssociationRegistration", SHCreateAssociationRegistration ),
        xlb_f( "SHCreateDataObject", SHCreateDataObject ),
        xlb_f( "SHCreateDefaultContextMenu", SHCreateDefaultContextMenu ),
        xlb_f( "SHCreateDefaultExtractIcon", SHCreateDefaultExtractIcon ),
        xlb_f( "SHCreateDefaultPropertiesOp", SHCreateDefaultPropertiesOp ),
        xlb_f( "SHCreateDirectory", SHCreateDirectory ),
        xlb_f( "SHCreateDirectoryEx", SHCreateDirectoryEx ),
        xlb_f( "SHCreateFileExtractIconW", SHCreateFileExtractIconW ),
        xlb_f( "SHCreateItemFromIDList", SHCreateItemFromIDList ),
        xlb_f( "SHCreateItemFromParsingName", SHCreateItemFromParsingName ),
        xlb_f( "SHCreateItemFromRelativeName", SHCreateItemFromRelativeName ),
        xlb_f( "SHCreateItemInKnownFolder", SHCreateItemInKnownFolder ),
        xlb_f( "SHCreateItemWithParent", SHCreateItemWithParent ),
        xlb_f( "SHCreateLibrary", SHCreateLibrary ),
        xlb_f( "SHCreateMemStream", SHCreateMemStream ),
        xlb_f( "SHCreateProcessAsUserW", SHCreateProcessAsUserW ),
        xlb_f( "SHCreatePropSheetExtArray", SHCreatePropSheetExtArray ),
        xlb_f( "SHCreateQueryCancelAutoPlayMoniker", SHCreateQueryCancelAutoPlayMoniker ),
        xlb_f( "SHCreateShellFolderView", SHCreateShellFolderView ),
        xlb_f( "SHCreateShellFolderViewEx", SHCreateShellFolderViewEx ),
        xlb_f( "SHCreateShellItem", SHCreateShellItem ),
        xlb_f( "SHCreateShellItemArray", SHCreateShellItemArray ),
        xlb_f( "SHCreateShellItemArrayFromDataObject", SHCreateShellItemArrayFromDataObject ),
        xlb_f( "SHCreateShellItemArrayFromIDLists", SHCreateShellItemArrayFromIDLists ),
        xlb_f( "SHCreateShellItemArrayFromShellItem", SHCreateShellItemArrayFromShellItem ),
        xlb_f( "SHCreateShellPalette", SHCreateShellPalette ),
        xlb_f( "SHCreateStdEnumFmtEtc", SHCreateStdEnumFmtEtc ),
        xlb_f( "SHCreateStreamOnFile", SHCreateStreamOnFile ),
        xlb_f( "SHCreateStreamOnFileEx", SHCreateStreamOnFileEx ),
        xlb_f( "SHCreateThread", SHCreateThread ),
        xlb_f( "SHCreateThreadRef", SHCreateThreadRef ),
        xlb_f( "SHCreateThreadWithHandle", SHCreateThreadWithHandle ),
        xlb_f( "SHDefExtractIcon", SHDefExtractIcon ),
        xlb_f( "SHDeleteEmptyKey", SHDeleteEmptyKey ), 
        xlb_f( "SHDeleteKey", SHDeleteKey ),
        xlb_f( "SHDeleteValue", SHDeleteValue ),
        xlb_f( "SHDestroyPropSheetExtArray", SHDestroyPropSheetExtArray ),
        xlb_f( "SHDoDragDrop", SHDoDragDrop ),
        xlb_f( "Shell_GetCachedImageIndex", Shell_GetCachedImageIndex ),
        xlb_f( "Shell_GetCachedImageIndex", Shell_GetCachedImageIndex ),
        xlb_f( "Shell_GetImageLists", Shell_GetImageLists ),
        xlb_f( "Shell_MergeMenus", Shell_MergeMenus ),
        xlb_f( "Shell_NotifyIcon", Shell_NotifyIcon ),
        xlb_f( "Shell_NotifyIconGetRect", Shell_NotifyIconGetRect ),
        xlb_f( "ShellAbout", ShellAbout ), 
        xlb_f( "ShellExecute", ShellExecute ),
        xlb_f( "ShellExecuteEx", ShellExecuteEx ),
        //xlb_f( "ShellMessageBox", ShellMessageBox ), //XXX: ... argument
        xlb_f( "SHEmptyRecycleBin", SHEmptyRecycleBin ),
        //xlb_f( "SHEnumerateUnreadMailAccounts", SHEnumerateUnreadMailAccounts ), // undefined
        xlb_f( "SHEnumKeyEx", SHEnumKeyEx ), 
        xlb_f( "SHEnumValue", SHEnumValue ),
        xlb_f( "SHEvaluateSystemCommandTemplate", SHEvaluateSystemCommandTemplate ),
        xlb_f( "SHFileOperation", SHFileOperation ),
        xlb_f( "SHFind_InitMenuPopup", SHFind_InitMenuPopup ),
        xlb_f( "SHFindFiles", SHFindFiles ), 
        xlb_f( "SHFlushSFCache", SHFlushSFCache ),
        xlb_f( "SHFormatDateTime", SHFormatDateTime ),
        xlb_f( "SHFormatDrive", SHFormatDrive ), 
        xlb_f( "SHFree", SHFree ),
        xlb_f( "SHFreeNameMappings", SHFreeNameMappings ),
        xlb_f( "SHFreeShared", SHFreeShared ), 
        //xlb_f( "SHGetAssocKeys", SHGetAssocKeys ), // undefined
        xlb_f( "SHGetAttributesFromDataObject", SHGetAttributesFromDataObject ),
        xlb_f( "SHGetDataFromIDList", SHGetDataFromIDList ),
        xlb_f( "SHGetDesktopFolder", SHGetDesktopFolder ),
        xlb_f( "SHGetDiskFreeSpaceEx", SHGetDiskFreeSpaceEx ),
        xlb_f( "SHGetDriveMedia", SHGetDriveMedia ), 
        xlb_f( "SHGetFileInfo", SHGetFileInfo ),
        xlb_f( "SHGetFolderLocation", SHGetFolderLocation ),
        xlb_f( "SHGetFolderPath", SHGetFolderPath ),
        xlb_f( "SHGetFolderPathAndSubDir", SHGetFolderPathAndSubDir ),
        xlb_f( "SHGetIconOverlayIndex", SHGetIconOverlayIndex ),
        xlb_f( "SHGetIDListFromObject", SHGetIDListFromObject ),
        xlb_f( "SHGetImageList", SHGetImageList ),
        xlb_f( "SHGetInstanceExplorer", SHGetInstanceExplorer ),
        xlb_f( "SHGetInverseCMAP", SHGetInverseCMAP ),
        xlb_f( "SHGetItemFromDataObject", SHGetItemFromDataObject ),
        xlb_f( "SHGetItemFromObject", SHGetItemFromObject ),
        xlb_f( "SHGetKnownFolderIDList", SHGetKnownFolderIDList ),
        xlb_f( "SHGetKnownFolderItem", SHGetKnownFolderItem ),
        xlb_f( "SHGetKnownFolderPath", SHGetKnownFolderPath ),
        xlb_f( "SHGetLocalizedName", SHGetLocalizedName ),
        xlb_f( "SHGetMalloc", SHGetMalloc ),
        xlb_f( "SHGetNameFromIDList", SHGetNameFromIDList ),
        xlb_f( "SHGetNewLinkInfo", SHGetNewLinkInfo ),
        xlb_f( "SHGetPathFromIDList", SHGetPathFromIDList ),
        xlb_f( "SHGetPathFromIDListEx", SHGetPathFromIDListEx ),
        xlb_f( "SHGetRealIDL", SHGetRealIDL ),
        xlb_f( "SHGetSetFolderCustomSettings", SHGetSetFolderCustomSettings ),
        xlb_f( "SHGetSetSettings", SHGetSetSettings ),
        xlb_f( "SHGetSettings", SHGetSettings ),
        xlb_f( "SHGetSpecialFolderLocation", SHGetSpecialFolderLocation ),
        xlb_f( "SHGetSpecialFolderPath", SHGetSpecialFolderPath ),
        xlb_f( "SHGetStockIconInfo", SHGetStockIconInfo ),
        xlb_f( "SHGetTemporaryPropertyForItem", SHGetTemporaryPropertyForItem ),
        xlb_f( "SHGetThreadRef", SHGetThreadRef ),
        xlb_f( "SHGetUnreadMailCountW", SHGetUnreadMailCountW ),
        xlb_f( "SHGetValue", SHGetValue ),
        xlb_f( "SHGetViewStatePropertyBag", SHGetViewStatePropertyBag ),
        xlb_f( "SHGlobalCounterDecrement", SHGlobalCounterDecrement ),
        xlb_f( "SHGlobalCounterGetValue", SHGlobalCounterGetValue ),
        xlb_f( "SHGlobalCounterIncrement", SHGlobalCounterIncrement ),
        xlb_f( "SHHandleUpdateImage", SHHandleUpdateImage ),
        xlb_f( "SHILCreateFromPath", SHILCreateFromPath ),
        xlb_f( "SHInvokePrinterCommand", SHInvokePrinterCommand ),
        xlb_f( "SHIsFileAvailableOffline", SHIsFileAvailableOffline ),
        xlb_f( "SHIsLowMemoryMachine", SHIsLowMemoryMachine ),
        xlb_f( "SHLimitInputEdit", SHLimitInputEdit ),
        xlb_f( "SHLoadIndirectString", SHLoadIndirectString ),
        xlb_f( "SHLoadInProc", SHLoadInProc ),
        xlb_f( "SHLoadLibraryFromItem", SHLoadLibraryFromItem ),
        xlb_f( "SHLoadLibraryFromKnownFolder", SHLoadLibraryFromKnownFolder ),
        xlb_f( "SHLoadLibraryFromParsingName", SHLoadLibraryFromParsingName ),
        xlb_f( "SHLoadNonloadedIconOverlayIdentifiers",
               SHLoadNonloadedIconOverlayIdentifiers ),
        // xlb_f("SHLoadOLE", SHLoadOLE),
        xlb_f( "SHLocalStrDup", SHLocalStrDup ), 
        xlb_f( "SHLockShared", SHLockShared ),
        xlb_f( "SHMapPIDLToSystemImageListIndex", SHMapPIDLToSystemImageListIndex ),
        xlb_f( "SHMessageBoxCheck", SHMessageBoxCheck ),
        xlb_f( "SHMultiFileProperties", SHMultiFileProperties ),
        xlb_f( "SHObjectProperties", SHObjectProperties ),
        xlb_f( "SHOpenFolderAndSelectItems", SHOpenFolderAndSelectItems ),
        //xlb_f( "SHOpenPropSheet", SHOpenPropSheet ), // undefined
        xlb_f( "SHOpenRegStream2", SHOpenRegStream2 ),
        xlb_f( "SHOpenRegStream", SHOpenRegStream ),
        xlb_f( "SHOpenWithDialog", SHOpenWithDialog ),
        // xlb_f("ShortAdd", ShortAdd),
        // xlb_f("ShortMult", ShortMult),
        // xlb_f("ShortSub", ShortSub),
        xlb_f( "ShortToChar", ShortToChar ), 
        xlb_f( "ShortToDWordPtr", ShortToDWordPtr ),
        xlb_f( "ShortToInt8", ShortToInt8 ), 
        xlb_f( "ShortToUChar", ShortToUChar ),
        xlb_f( "ShortToUInt", ShortToUInt ), 
        xlb_f( "ShortToUInt8", ShortToUInt8 ),
        xlb_f( "ShortToUIntPtr", ShortToUIntPtr ), 
        xlb_f( "ShortToULong", ShortToULong ),
        xlb_f( "ShortToULongLong", ShortToULongLong ),
        xlb_f( "ShortToULongPtr", ShortToULongPtr ), 
        xlb_f( "ShortToUShort", ShortToUShort ),
        // xlb_f("ShouldShow", ShouldShow),
        // xlb_f("Show", Show),
        // xlb_f("Show", Show),
        // xlb_f("Show", Show),
        // xlb_f("Show", Show),
        // xlb_f("Show", Show),
        // xlb_f("Show", Show),
        // xlb_f("ShowContactCardForWindow", ShowContactCardForWindow),
        // xlb_f("ShowControlWindow", ShowControlWindow),
        // xlb_f("ShowDeskBand", ShowDeskBand),
        // xlb_f("ShowDW", ShowDW),
        // xlb_f("ShowError", ShowError),
        // xlb_f("ShowErrorCompleted", ShowErrorCompleted),
        // xlb_f("Showing", Showing),
        // xlb_f("ShowInitialize", ShowInitialize),
        // xlb_f("ShowInitialize", ShowInitialize),
        // xlb_f("ShowProperties", ShowProperties),
        // xlb_f("ShowPropertiesCompleted", ShowPropertiesCompleted),
        // xlb_f("ShowResolveConflictUIAsync", ShowResolveConflictUIAsync),
        // xlb_f("ShowShareUIForWindow", ShowShareUIForWindow),
        // xlb_f("ShowSharingWizard", ShowSharingWizard),
        xlb_f( "SHParseDisplayName", SHParseDisplayName ),
        xlb_f( "SHPathPrepareForWrite", SHPathPrepareForWrite ),
        xlb_f( "SHQueryInfoKey", SHQueryInfoKey ),
        xlb_f( "SHQueryRecycleBin", SHQueryRecycleBin ),
        xlb_f( "SHQueryUserNotificationState", SHQueryUserNotificationState ),
        xlb_f( "SHQueryValueEx", SHQueryValueEx ),
        xlb_f( "SHRegCloseUSKey", SHRegCloseUSKey ),
        xlb_f( "SHRegCreateUSKey", SHRegCreateUSKey ),
        xlb_f( "SHRegDeleteEmptyUSKey", SHRegDeleteEmptyUSKey ),
        // xlb_f("SHRegDeleteUSValueA", SHRegDeleteUSValueA),
        // xlb_f("SHRegDeleteUSValueW", SHRegDeleteUSValueW),
        xlb_f( "SHRegDuplicateHKey", SHRegDuplicateHKey ),
        xlb_f( "SHRegEnumUSKey", SHRegEnumUSKey ),
        xlb_f( "SHRegEnumUSValue", SHRegEnumUSValue ),
        xlb_f( "SHRegGetBoolUSValue", SHRegGetBoolUSValue ),
        //xlb_f( "SHRegGetBoolValueFromHKCUHKLM", SHRegGetBoolValueFromHKCUHKLM ), // undefined
        xlb_f( "SHRegGetIntW", SHRegGetIntW ), 
        xlb_f( "SHRegGetPath", SHRegGetPath ),
        xlb_f( "SHRegGetUSValue", SHRegGetUSValue ), 
        xlb_f( "SHRegGetValue", SHRegGetValue ),
        //xlb_f( "SHRegGetValueFromHKCUHKLM", SHRegGetValueFromHKCUHKLM ), // undefined
        xlb_f( "SHRegOpenUSKey", SHRegOpenUSKey ),
        xlb_f( "SHRegQueryInfoUSKey", SHRegQueryInfoUSKey ),
        xlb_f( "SHRegQueryUSValue", SHRegQueryUSValue ),
        xlb_f( "SHRegSetPath", SHRegSetPath ), 
        xlb_f( "SHRegSetUSValue", SHRegSetUSValue ),
        //xlb_f( "SHRegSetValue", SHRegSetValue ), // undefined
        xlb_f( "SHRegWriteUSValue", SHRegWriteUSValue ),
        xlb_f( "SHReleaseThreadRef", SHReleaseThreadRef ),
        xlb_f( "SHRemoveFolderPathFromLibrary", SHRemoveFolderPathFromLibrary ),
        xlb_f( "SHRemoveLocalizedName", SHRemoveLocalizedName ),
        xlb_f( "SHReplaceFromPropSheetExtArray", SHReplaceFromPropSheetExtArray ),
        xlb_f( "SHResolveFolderPathInLibrary", SHResolveFolderPathInLibrary ),
        xlb_f( "SHResolveLibrary", SHResolveLibrary ), 
        xlb_f( "SHRestricted", SHRestricted ),
        //xlb_f( "SHRunControlPanel", SHRunControlPanel ), // undefined
        xlb_f( "SHSaveLibraryInFolderPath", SHSaveLibraryInFolderPath ),
        xlb_f( "SHSendMessageBroadcast", SHSendMessageBroadcast ),
        xlb_f( "SHSetDefaultProperties", SHSetDefaultProperties ),
        xlb_f( "SHSetFolderPath", SHSetFolderPath ),
        xlb_f( "SHSetInstanceExplorer", SHSetInstanceExplorer ),
        xlb_f( "SHSetKnownFolderPath", SHSetKnownFolderPath ),
        xlb_f( "SHSetLocalizedName", SHSetLocalizedName ),
        xlb_f( "SHSetTemporaryPropertyForItem", SHSetTemporaryPropertyForItem ),
        xlb_f( "SHSetThreadRef", SHSetThreadRef ),
        xlb_f( "SHSetUnreadMailCountW", SHSetUnreadMailCountW ),
        xlb_f( "SHSetValue", SHSetValue ),
        xlb_f( "SHShellFolderView_Message", SHShellFolderView_Message ),
        xlb_f( "SHShowManageLibraryUI", SHShowManageLibraryUI ),
        xlb_f( "SHSimpleIDListFromPath", SHSimpleIDListFromPath ),
        xlb_f( "SHSkipJunction", SHSkipJunction ),
        //xlb_f( "SHStartNetConnectionDialog", SHStartNetConnectionDialog ), // undefined
        xlb_f( "SHStrDup", SHStrDup ), 
        xlb_f( "SHStripMneumonic", SHStripMneumonic ),
        xlb_f( "SHTestTokenMembership", SHTestTokenMembership ),
        xlb_f( "SHUnicodeToAnsi", SHUnicodeToAnsi ),
        xlb_f( "SHUnicodeToUnicode", SHUnicodeToUnicode ),
        xlb_f( "SHUnlockShared", SHUnlockShared ), 
        xlb_f( "SHUpdateImage", SHUpdateImage ),
        xlb_f( "SHValidateUNC", SHValidateUNC ), 
        xlb_f( "SignalFileOpen", SignalFileOpen ),
        xlb_f( "SizeTAdd", SizeTAdd ), 
        xlb_f( "SizeTMult", SizeTMult ),
        xlb_f( "SizeTSub", SizeTSub ),
        // xlb_f("Skip", Skip),
        // xlb_f("Skip", Skip),
        // xlb_f("Skip", Skip),
        // xlb_f("Skip", Skip),
        // xlb_f("Skip", Skip),
        // xlb_f("Skip", Skip),
        // xlb_f("Skip", Skip),
        // xlb_f("Skip", Skip),
        // xlb_f("Skip", Skip),
        // xlb_f("Skip", Skip),
        // xlb_f("Skip", Skip),
        //xlb_f( "SoftwareUpdateMessageBox", SoftwareUpdateMessageBox ), // undefined
        // xlb_f("SSIZETAdd", SSIZETAdd),
        // xlb_f("SSIZETMult", SSIZETMult),
        // xlb_f("SSIZETSub", SSIZETSub),
        // xlb_f("StartHandlerSync", StartHandlerSync),
        // xlb_f("StartItemSync", StartItemSync),
        // xlb_f("StartOperation", StartOperation),
        // xlb_f("StartOperations", StartOperations),
        // xlb_f("StartProgressDialog", StartProgressDialog),
        // xlb_f("StartProgressDialog", StartProgressDialog),
        // xlb_f("StartServicing", StartServicing),
        // xlb_f("StartSessionRedirection", StartSessionRedirection),
        // xlb_f("StartSyncAll", StartSyncAll),
        // xlb_f("StartVisualGroup", StartVisualGroup),
        // xlb_f("Status", Status),
        xlb_f( "StgMakeUniqueName", StgMakeUniqueName ),
        // xlb_f("Stop", Stop),
        // xlb_f("StopHandlerSync", StopHandlerSync),
        // xlb_f("StopItemSync", StopItemSync),
        // xlb_f("StopProgressDialog", StopProgressDialog),
        // xlb_f("StopProgressDialog", StopProgressDialog),
        // xlb_f("StopServicing", StopServicing),
        // xlb_f("StopSessionRedirection", StopSessionRedirection),
        // xlb_f("StopSharingPrinters", StopSharingPrinters),
        // xlb_f("StopSyncAll", StopSyncAll),
        // xlb_f("StopWatchFlush", StopWatchFlush),
        // xlb_f("StopWatchMode", StopWatchMode),
        xlb_f( "StrCatBuff", StrCatBuff ), 
        xlb_f( "StrCatChainW", StrCatChainW ),
        xlb_f( "StrCatW", StrCatW ), 
        xlb_f( "StrChr", StrChr ), 
        xlb_f( "StrChrI", StrChrI ),
        xlb_f( "StrChrNIW", StrChrNIW ), 
        xlb_f( "StrChrNW", StrChrNW ),
        xlb_f( "StrCmpC", StrCmpC ), 
        xlb_f( "StrCmpIC", StrCmpIC ),
        xlb_f( "StrCmpIW", StrCmpIW ), 
        xlb_f( "StrCmpLogicalW", StrCmpLogicalW ),
        xlb_f( "StrCmpN", StrCmpN ), 
        xlb_f( "StrCmpNC", StrCmpNC ),
        xlb_f( "StrCmpNI", StrCmpNI ), 
        xlb_f( "StrCmpNIC", StrCmpNIC ),
        xlb_f( "StrCmpW", StrCmpW ), 
        xlb_f( "StrCpyNW", StrCpyNW ),
        xlb_f( "StrCpyW", StrCpyW ), 
        xlb_f( "StrCSpn", StrCSpn ),
        xlb_f( "StrCSpnI", StrCSpnI ), 
        xlb_f( "StrDup", StrDup ),
        xlb_f( "StrFormatByteSize64A", StrFormatByteSize64A ),
        xlb_f( "StrFormatByteSize", StrFormatByteSize ),
        xlb_f( "StrFormatByteSizeEx", StrFormatByteSizeEx ),
        xlb_f( "StrFormatKBSize", StrFormatKBSize ),
        xlb_f( "StrFromTimeInterval", StrFromTimeInterval ),
        xlb_f( "StrIsIntlEqual", StrIsIntlEqual ), 
        xlb_f( "StrNCat", StrNCat ),
        xlb_f( "StrPBrk", StrPBrk ), 
        xlb_f( "StrRChr", StrRChr ),
        xlb_f( "StrRChrI", StrRChrI ), 
        xlb_f( "StrRetToBSTR", StrRetToBSTR ),
        xlb_f( "StrRetToBuf", StrRetToBuf ), 
        xlb_f( "StrRetToStr", StrRetToStr ),
        xlb_f( "StrRStrI", StrRStrI ), 
        xlb_f( "StrSpn", StrSpn ), 
        xlb_f( "StrStr", StrStr ),
        xlb_f( "StrStrI", StrStrI ), 
        xlb_f( "StrStrNIW", StrStrNIW ),
        xlb_f( "StrStrNW", StrStrNW ), 
        xlb_f( "StrToInt64Ex", StrToInt64Ex ),
        xlb_f( "StrToInt", StrToInt ), 
        xlb_f( "StrToIntEx", StrToIntEx ),
        xlb_f( "StrTrim", StrTrim ), 

        xlb_class<xlb_cbf<SUBCLASSPROC>>( "SUBCLASSPROC" ).constructor<xlb_luafunc>(),

        // xlb_f("SubStreamFailure", SubStreamFailure),
        // xlb_f("SupportsResource", SupportsResource),
        // xlb_f("SupportsSelection", SupportsSelection),
        // xlb_f("Suspend", Suspend),
        // xlb_f("Suspend", Suspend),
        // xlb_f("Synchronize", Synchronize),
        // xlb_f("Synchronize", Synchronize),
        // xlb_f("SynchronizeCompleted", SynchronizeCompleted),
        // xlb_f("TerminateAllProcesses", TerminateAllProcesses),
        // xlb_f("ThumbBarAddButtons", ThumbBarAddButtons),
        // xlb_f("ThumbBarSetImageList", ThumbBarSetImageList),
        // xlb_f("ThumbBarUpdateButtons", ThumbBarUpdateButtons),
        // xlb_f("Timer", Timer),
        // xlb_f("TranscodeImage", TranscodeImage),
        // xlb_f("Translate", Translate),
        xlb_f( "TranslateAccelerator", TranslateAccelerator ),
        xlb_f( "TranslateAccelerator", TranslateAccelerator ),
        xlb_f( "TranslateAccelerator", TranslateAccelerator ),
        // xlb_f("TranslateAcceleratorGlobal", TranslateAcceleratorGlobal),
        // xlb_f("TranslateAcceleratorIO", TranslateAcceleratorIO),
        // xlb_f("TranslateAcceleratorSB", TranslateAcceleratorSB),
        // xlb_f("TranslateMenuMessage", TranslateMenuMessage),
        //xlb_f( "TranslateURL", TranslateURL ), // undefined
        // xlb_f("TranslateWithSearchContext", TranslateWithSearchContext),
        // xlb_f("Travel", Travel),
        // xlb_f("TreeAdvise", TreeAdvise),
        // xlb_f("TreeUnadvise", TreeUnadvise),
        // xlb_f("TriggerEdgeGesture", TriggerEdgeGesture),
        // xlb_f("UIActivate", UIActivate),
        // xlb_f("UIActivateIO", UIActivateIO),
        xlb_f( "UInt8Add", UInt8Add ), 
        xlb_f( "UInt8Mult", UInt8Mult ),
        xlb_f( "UInt8Sub", UInt8Sub ), 
        xlb_f( "UInt8ToChar", UInt8ToChar ),
        xlb_f( "UInt8ToInt8", UInt8ToInt8 ), 
        xlb_f( "UIntAdd", UIntAdd ),
        xlb_f( "UIntMult", UIntMult ), 
        xlb_f( "UIntPtrAdd", UIntPtrAdd ),
        xlb_f( "UIntPtrMult", UIntPtrMult ), 
        xlb_f( "UIntPtrSub", UIntPtrSub ),
        xlb_f( "UIntPtrToChar", UIntPtrToChar ), 
        xlb_f( "UIntPtrToInt", UIntPtrToInt ),
        xlb_f( "UIntPtrToInt16", UIntPtrToInt16 ), 
        xlb_f( "UIntPtrToInt8", UIntPtrToInt8 ),
        xlb_f( "UIntPtrToIntPtr", UIntPtrToIntPtr ), 
        xlb_f( "UIntPtrToLong", UIntPtrToLong ),
        xlb_f( "UIntPtrToLongLong", UIntPtrToLongLong ),
        xlb_f( "UIntPtrToLongPtr", UIntPtrToLongPtr ),
        xlb_f( "UIntPtrToShort", UIntPtrToShort ), 
        xlb_f( "UIntPtrToUChar", UIntPtrToUChar ),
        xlb_f( "UIntPtrToUInt", UIntPtrToUInt ), 
        xlb_f( "UIntPtrToUInt16", UIntPtrToUInt16 ),
        xlb_f( "UIntPtrToUInt8", UIntPtrToUInt8 ), 
        xlb_f( "UIntPtrToULong", UIntPtrToULong ),
        xlb_f( "UIntPtrToUShort", UIntPtrToUShort ), 
        xlb_f( "UIntSub", UIntSub ),
        xlb_f( "UIntToChar", UIntToChar ), 
        xlb_f( "UIntToInt", UIntToInt ),
        xlb_f( "UIntToInt8", UIntToInt8 ), 
        xlb_f( "UIntToIntPtr", UIntToIntPtr ),
        xlb_f( "UIntToLong", UIntToLong ), 
        xlb_f( "UIntToLongPtr", UIntToLongPtr ),
        xlb_f( "UIntToShort", UIntToShort ), 
        xlb_f( "UIntToUChar", UIntToUChar ),
        xlb_f( "UIntToUInt8", UIntToUInt8 ), 
        xlb_f( "UIntToUShort", UIntToUShort ),
        xlb_f( "ULongAdd", ULongAdd ), 
        xlb_f( "ULongLongAdd", ULongLongAdd ),
        xlb_f( "ULongLongMult", ULongLongMult ), 
        xlb_f( "ULongLongSub", ULongLongSub ),
        xlb_f( "ULongLongToChar", ULongLongToChar ),
        xlb_f( "ULongLongToInt", ULongLongToInt ),
        xlb_f( "ULongLongToInt8", ULongLongToInt8 ),
        xlb_f( "ULongLongToLong", ULongLongToLong ),
        xlb_f( "ULongLongToLongLong", ULongLongToLongLong ),
        xlb_f( "ULongLongToLongPtr", ULongLongToLongPtr ),
        xlb_f( "ULongLongToShort", ULongLongToShort ),
        xlb_f( "ULongLongToUChar", ULongLongToUChar ),
        xlb_f( "ULongLongToUInt", ULongLongToUInt ),
        xlb_f( "ULongLongToUInt8", ULongLongToUInt8 ),
        xlb_f( "ULongLongToUIntPtr", ULongLongToUIntPtr ),
        xlb_f( "ULongLongToULong", ULongLongToULong ),
        xlb_f( "ULongLongToULongPtr", ULongLongToULongPtr ),
        xlb_f( "ULongLongToUShort", ULongLongToUShort ), 
        xlb_f( "ULongMult", ULongMult ),
        xlb_f( "ULongPtrAdd", ULongPtrAdd ), 
        xlb_f( "ULongPtrMult", ULongPtrMult ),
        xlb_f( "ULongPtrSub", ULongPtrSub ), 
        xlb_f( "ULongPtrToChar", ULongPtrToChar ),
        xlb_f( "ULongPtrToInt", ULongPtrToInt ), 
        xlb_f( "ULongPtrToInt8", ULongPtrToInt8 ),
        xlb_f( "ULongPtrToIntPtr", ULongPtrToIntPtr ),
        xlb_f( "ULongPtrToLong", ULongPtrToLong ),
        xlb_f( "ULongPtrToLongLong", ULongPtrToLongLong ),
        xlb_f( "ULongPtrToLongPtr", ULongPtrToLongPtr ),
        xlb_f( "ULongPtrToShort", ULongPtrToShort ),
        xlb_f( "ULongPtrToUChar", ULongPtrToUChar ),
        xlb_f( "ULongPtrToUInt", ULongPtrToUInt ),
        xlb_f( "ULongPtrToUInt8", ULongPtrToUInt8 ),
        xlb_f( "ULongPtrToUIntPtr", ULongPtrToUIntPtr ),
        xlb_f( "ULongPtrToULong", ULongPtrToULong ),
        xlb_f( "ULongPtrToUShort", ULongPtrToUShort ), 
        xlb_f( "ULongSub", ULongSub ),
        xlb_f( "ULongToChar", ULongToChar ), 
        xlb_f( "ULongToInt", ULongToInt ),
        xlb_f( "ULongToInt8", ULongToInt8 ), 
        xlb_f( "ULongToIntPtr", ULongToIntPtr ),
        xlb_f( "ULongToLong", ULongToLong ), 
        xlb_f( "ULongToLongPtr", ULongToLongPtr ),
        xlb_f( "ULongToShort", ULongToShort ), 
        xlb_f( "ULongToUChar", ULongToUChar ),
        xlb_f( "ULongToUInt", ULongToUInt ), 
        xlb_f( "ULongToUInt8", ULongToUInt8 ),
        xlb_f( "ULongToUIntPtr", ULongToUIntPtr ), 
        xlb_f( "ULongToUShort", ULongToUShort ),
        // xlb_f("Unadvise", Unadvise),
        // xlb_f("Unadvise", Unadvise),
        // xlb_f("Unadvise", Unadvise),
        // xlb_f("Unadvise", Unadvise),
        // xlb_f("Unadvise", Unadvise),
        // xlb_f("Unadvise", Unadvise),
        // xlb_f("Unadvise", Unadvise),
        // xlb_f("UnAdvise", UnAdvise),
        // xlb_f("UnAdvise", UnAdvise),
        // xlb_f("UngroupChildFromParent", UngroupChildFromParent),
        // xlb_f("Unload", Unload),
        xlb_f( "UnloadUserProfile", UnloadUserProfile ),
        xlb_f( "UnregisterAppStateChangeNotification", UnregisterAppStateChangeNotification ),
        // xlb_f("UnregisterFolder", UnregisterFolder),
        // xlb_f("UnregisterForPackageStateChanges", UnregisterForPackageStateChanges),
        xlb_f( "UnregisterScaleChangeEvent", UnregisterScaleChangeEvent ),
        // xlb_f("UnregisterSyncMgrHandler", UnregisterSyncMgrHandler),
        // xlb_f("UnregisterTab", UnregisterTab),
        // xlb_f("Unschedule", Unschedule),
        // xlb_f("Update", Update),
        // xlb_f("Update", Update),
        // xlb_f("Update", Update),
        // xlb_f("UpdateAll", UpdateAll),
        // xlb_f("UpdateBackForwardState", UpdateBackForwardState),
        // xlb_f("UpdateConflicts", UpdateConflicts),
        // xlb_f("UpdateEntry", UpdateEntry),
        // xlb_f("UpdateEvents", UpdateEvents),
        // xlb_f("UpdateExternal", UpdateExternal),
        // xlb_f("UpdateHandler", UpdateHandler),
        // xlb_f("UpdateHandlerCollection", UpdateHandlerCollection),
        // xlb_f("UpdateItem", UpdateItem),
        // xlb_f("UpdateItems", UpdateItems),
        // xlb_f("UpdateLocations", UpdateLocations),
        // xlb_f("UpdateObject", UpdateObject),
        // xlb_f("UpdateProgress", UpdateProgress),
        // xlb_f("UpdateProgress", UpdateProgress),
        // xlb_f("UpdateProgress", UpdateProgress),
        // xlb_f("UpdateProgress", UpdateProgress),
        // xlb_f("UpdateRemoteCredential", UpdateRemoteCredential),
        // xlb_f("UpdateSecureLockIcon", UpdateSecureLockIcon),
        // xlb_f("UpdateText", UpdateText),
        // xlb_f("UpdateTransferState", UpdateTransferState),
        // xlb_f("UpdateWindowList", UpdateWindowList),
        xlb_f( "UrlApplyScheme", UrlApplyScheme ),
        //xlb_f( "URLAssociationDialog", URLAssociationDialog ), // undefined
        xlb_f( "UrlCanonicalize", UrlCanonicalize ), 
        xlb_f( "UrlCombine", UrlCombine ),
        xlb_f( "UrlCompare", UrlCompare ), 
        xlb_f( "UrlCreateFromPath", UrlCreateFromPath ),
        xlb_f( "UrlEscape", UrlEscape ),
        // xlb_f("UrlEscapeSpaces", UrlEscapeSpaces),
        xlb_f( "UrlFixupW", UrlFixupW ), 
        xlb_f( "UrlGetLocation", UrlGetLocation ),
        xlb_f( "UrlGetPart", UrlGetPart ), 
        xlb_f( "UrlHash", UrlHash ),
        xlb_f( "UrlIs", UrlIs ),
        // xlb_f("UrlIsFileUrlA", UrlIsFileUrlA),
        // xlb_f("UrlIsFileUrlW", UrlIsFileUrlW),
        //xlb_f( "UrlIsNoHistory", UrlIsNoHistory ),  // no AW
        xlb_f( "UrlIsOpaque", UrlIsOpaque ),
        xlb_f( "UrlUnescape", UrlUnescape ),
        // xlb_f("UrlUnescapeInPlace", UrlUnescapeInPlace),
        xlb_f( "UShortAdd", UShortAdd ), 
        xlb_f( "UShortMult", UShortMult ),
        xlb_f( "UShortSub", UShortSub ), 
        xlb_f( "UShortToChar", UShortToChar ),
        xlb_f( "UShortToInt8", UShortToInt8 ), 
        xlb_f( "UShortToShort", UShortToShort ),
        xlb_f( "UShortToUChar", UShortToUChar ), 
        xlb_f( "UShortToUInt8", UShortToUInt8 ),
        // xlb_f("v_CheckZoneCrossing", v_CheckZoneCrossing),
        // xlb_f("v_GetViewStream", v_GetViewStream),
        // xlb_f("v_MayGetNextToolbarFocus", v_MayGetNextToolbarFocus),
        // xlb_f("v_MayTranslateAccelerator", v_MayTranslateAccelerator),
        // xlb_f("v_ShowHideChildWindows", v_ShowHideChildWindows),
        // xlb_f("Walk", Walk),
        // xlb_f("WalkComplete", WalkComplete),
        xlb_f( "WhichPlatform", WhichPlatform ), 
        xlb_f( "Win32DeleteFile", Win32DeleteFile ),
        xlb_f( "WinHelp", WinHelp ),
        // xlb_f("WndProcBS", WndProcBS),
        //xlb_f( "wnsprintf", wnsprintf ), //XXX: ... argument
        // xlb_f("WriteAsync", WriteAsync),
        xlb_f( "WriteCabinetState", WriteCabinetState ),
        // xlb_f("WritePropertyNPB", WritePropertyNPB),
        xlb_f( "wvnsprintf", wvnsprintf ),
        // xlb_f("YouAreAReplica", YouAreAReplica),

            // Structures
        xlb_class<AASHELLMENUFILENAME>("AASHELLMENUFILENAME") .constructor<>() .destructor()
            .property("cbTotal", &AASHELLMENUFILENAME::cbTotal)
            .property("rgbReserved", &AASHELLMENUFILENAME::rgbReserved)
            .property("szFileName", &AASHELLMENUFILENAME::szFileName)
            ,
        xlb_class<AASHELLMENUITEM>("AASHELLMENUITEM") .constructor<>() .destructor()
            .property("lpReserved1", &AASHELLMENUITEM::lpReserved1)
            .property("iReserved", &AASHELLMENUITEM::iReserved)
            .property("uiReserved", &AASHELLMENUITEM::uiReserved)
            .property("lpName", &AASHELLMENUITEM::lpName)
            .property("psz", &AASHELLMENUITEM::psz)
            ,

        xlb_class<APPBARDATA>("APPBARDATA") .constructor<>() .destructor()
            .property("cbSize", &APPBARDATA::cbSize)
            .property("hWnd", &APPBARDATA::hWnd)
            .property("uCallbackMessage", &APPBARDATA::uCallbackMessage)
            .property("uEdge", &APPBARDATA::uEdge)
            .property("rc", &APPBARDATA::rc)
            .property("lParam", &APPBARDATA::lParam)
            ,
        xlb_class<APPCATEGORYINFO>("APPCATEGORYINFO") .constructor<>() .destructor()
            .property("Locale", &APPCATEGORYINFO::Locale)
            .property("pszDescription", &APPCATEGORYINFO::pszDescription)
            .property("AppCategoryId", &APPCATEGORYINFO::AppCategoryId)
            ,
    
        xlb_class<APPCATEGORYINFOLIST>("APPCATEGORYINFOLIST") .constructor<>() .destructor()
            .property("cCategory", &APPCATEGORYINFOLIST::cCategory)
            .property("pCategoryInfo", &APPCATEGORYINFOLIST::pCategoryInfo)
            ,

        xlb_class<APPINFODATA>("APPINFODATA") .constructor<>() .destructor()
            .property("cbSize", &APPINFODATA::cbSize)
            .property("dwMask", &APPINFODATA::dwMask)
            .property("pszDisplayName", &APPINFODATA::pszDisplayName)
            .property("pszVersion", &APPINFODATA::pszVersion)
            .property("pszPublisher", &APPINFODATA::pszPublisher)
            .property("pszProductID", &APPINFODATA::pszProductID)
            .property("pszRegisteredOwner", &APPINFODATA::pszRegisteredOwner)
            .property("pszRegisteredCompany", &APPINFODATA::pszRegisteredCompany)
            .property("pszLanguage", &APPINFODATA::pszLanguage)
            .property("pszSupportUrl", &APPINFODATA::pszSupportUrl)
            .property("pszSupportTelephone", &APPINFODATA::pszSupportTelephone)
            .property("pszHelpLink", &APPINFODATA::pszHelpLink)
            .property("pszInstallLocation", &APPINFODATA::pszInstallLocation)
            .property("pszInstallSource", &APPINFODATA::pszInstallSource)
            .property("pszInstallDate", &APPINFODATA::pszInstallDate)
            .property("pszContact", &APPINFODATA::pszContact)
            .property("pszComments", &APPINFODATA::pszComments)
            .property("pszImage", &APPINFODATA::pszImage)
            .property("pszReadmeUrl", &APPINFODATA::pszReadmeUrl)
            .property("pszUpdateInfoUrl", &APPINFODATA::pszUpdateInfoUrl)
            ,

        xlb_class<ASSOCIATIONELEMENT>("ASSOCIATIONELEMENT") .constructor<>() .destructor()
            .property("ac", &ASSOCIATIONELEMENT::ac)
            .property("hkClass", &ASSOCIATIONELEMENT::hkClass)
            .property("pszClass", &ASSOCIATIONELEMENT::pszClass)
            ,

        xlb_class<AUTO_SCROLL_DATA>("AUTO_SCROLL_DATA") .constructor<>() .destructor()
            .property("iNextSample", &AUTO_SCROLL_DATA::iNextSample)
            .property("dwLastScroll", &AUTO_SCROLL_DATA::dwLastScroll)
            .property("bFull", &AUTO_SCROLL_DATA::bFull)
            .property("pts", &AUTO_SCROLL_DATA::pts)
            .property("dwTimes", &AUTO_SCROLL_DATA::dwTimes)
            ,

        xlb_class<BANDINFOSFB>("BANDINFOSFB") .constructor<>() .destructor()
            .property("dwMask", &BANDINFOSFB::dwMask)
            .property("dwStateMask", &BANDINFOSFB::dwStateMask)
            .property("dwState", &BANDINFOSFB::dwState)
            .property("crBkgnd", &BANDINFOSFB::crBkgnd)
            .property("crBtnLt", &BANDINFOSFB::crBtnLt)
            .property("crBtnDk", &BANDINFOSFB::crBtnDk)
            .property("wViewMode", &BANDINFOSFB::wViewMode)
            .property("wAlign", &BANDINFOSFB::wAlign)
            .property("psf", &BANDINFOSFB::psf)
            .property("pidl", &BANDINFOSFB::pidl)
            ,

        xlb_class<BANDSITEINFO>("BANDSITEINFO") .constructor<>() .destructor()
            .property("dwMask", &BANDSITEINFO::dwMask)
            .property("dwState", &BANDSITEINFO::dwState)
            .property("dwStyle", &BANDSITEINFO::dwStyle)
            ,

        xlb_class<BASEBROWSERDATALH>("BASEBROWSERDATALH") .constructor<>() .destructor()
            .property("_hwnd", &BASEBROWSERDATALH::_hwnd)
            .property("_ptl", &BASEBROWSERDATALH::_ptl)
            .property("_phlf", &BASEBROWSERDATALH::_phlf)
            .property("_pautoWB2", &BASEBROWSERDATALH::_pautoWB2)
            .property("_pautoEDS", &BASEBROWSERDATALH::_pautoEDS)
            .property("_pautoSS", &BASEBROWSERDATALH::_pautoSS)
            .property("_eSecureLockIcon", &BASEBROWSERDATALH::_eSecureLockIcon)

            // bitfield
            .property(XLB_BF3ARG(BASEBROWSERDATALH, _fCreatingViewWindow ))

            .property("_uActivateState", &BASEBROWSERDATALH::_uActivateState)
            .property("_pidlViewState", &BASEBROWSERDATALH::_pidlViewState)
            .property("_pctView", &BASEBROWSERDATALH::_pctView)
            .property("_pidlCur", &BASEBROWSERDATALH::_pidlCur)
            .property("_psv", &BASEBROWSERDATALH::_psv)
            .property("_psf", &BASEBROWSERDATALH::_psf)
            .property("_hwndView", &BASEBROWSERDATALH::_hwndView)
            .property("_pszTitleCur", &BASEBROWSERDATALH::_pszTitleCur)
            .property("_pidlPending", &BASEBROWSERDATALH::_pidlPending)
            .property("_psvPending", &BASEBROWSERDATALH::_psvPending)
            .property("_psfPending", &BASEBROWSERDATALH::_psfPending)
            .property("_hwndViewPending", &BASEBROWSERDATALH::_hwndViewPending)
            .property("_pszTitlePending", &BASEBROWSERDATALH::_pszTitlePending)
            .property("_fIsViewMSHTML", &BASEBROWSERDATALH::_fIsViewMSHTML)
            .property("_fPrivacyImpacted", &BASEBROWSERDATALH::_fPrivacyImpacted)
            .property("_clsidView", &BASEBROWSERDATALH::_clsidView)
            .property("_clsidViewPending", &BASEBROWSERDATALH::_clsidViewPending)
            .property("_hwndFrame", &BASEBROWSERDATALH::_hwndFrame)
            .property("_lPhishingFilterStatus", &BASEBROWSERDATALH::_lPhishingFilterStatus)
            ,

        xlb_class<BASEBROWSERDATAXP>("BASEBROWSERDATAXP") .constructor<>() .destructor()
            .property("_hwnd", &BASEBROWSERDATAXP::_hwnd)
            .property("_ptl", &BASEBROWSERDATAXP::_ptl)
            .property("_phlf", &BASEBROWSERDATAXP::_phlf)
            .property("_pautoWB2", &BASEBROWSERDATAXP::_pautoWB2)
            .property("_pautoEDS", &BASEBROWSERDATAXP::_pautoEDS)
            .property("_pautoSS", &BASEBROWSERDATAXP::_pautoSS)
            .property("_eSecureLockIcon", &BASEBROWSERDATAXP::_eSecureLockIcon)

            // bitfield
            .property(XLB_BF3ARG(BASEBROWSERDATAXP, _fCreatingViewWindow ))
            
            .property("_uActivateState", &BASEBROWSERDATAXP::_uActivateState)
            .property("_pidlViewState", &BASEBROWSERDATAXP::_pidlViewState)
            .property("_pctView", &BASEBROWSERDATAXP::_pctView)
            .property("_pidlCur", &BASEBROWSERDATAXP::_pidlCur)
            .property("_psv", &BASEBROWSERDATAXP::_psv)
            .property("_psf", &BASEBROWSERDATAXP::_psf)
            .property("_hwndView", &BASEBROWSERDATAXP::_hwndView)
            .property("_pszTitleCur", &BASEBROWSERDATAXP::_pszTitleCur)
            .property("_pidlPending", &BASEBROWSERDATAXP::_pidlPending)
            .property("_psvPending", &BASEBROWSERDATAXP::_psvPending)
            .property("_psfPending", &BASEBROWSERDATAXP::_psfPending)
            .property("_hwndViewPending", &BASEBROWSERDATAXP::_hwndViewPending)
            .property("_pszTitlePending", &BASEBROWSERDATAXP::_pszTitlePending)
            .property("_fIsViewMSHTML", &BASEBROWSERDATAXP::_fIsViewMSHTML)
            .property("_fPrivacyImpacted", &BASEBROWSERDATAXP::_fPrivacyImpacted)
            .property("_clsidView", &BASEBROWSERDATAXP::_clsidView)
            .property("_clsidViewPending", &BASEBROWSERDATAXP::_clsidViewPending)
            .property("_hwndFrame", &BASEBROWSERDATAXP::_hwndFrame)
            ,

        xlb_class<BROWSEINFO>("BROWSEINFO") .constructor<>() .destructor()
            .property("hwndOwner", &BROWSEINFO::hwndOwner)
            .property("pidlRoot", &BROWSEINFO::pidlRoot)
            .property("pszDisplayName", &BROWSEINFO::pszDisplayName)
            .property("lpszTitle", &BROWSEINFO::lpszTitle)
            .property("ulFlags", &BROWSEINFO::ulFlags)
            .property("lpfn", &BROWSEINFO::lpfn)
            .property("lParam", &BROWSEINFO::lParam)
            .property("iImage", &BROWSEINFO::iImage)
            ,

        xlb_class<CABINETSTATE>("CABINETSTATE") .constructor<>() .destructor()
            .property("cLength", &CABINETSTATE::cLength)
            .property("nVersion", &CABINETSTATE::nVersion)

            // bitfield
            .property(XLB_BF3ARG(CABINETSTATE, fFullPathTitle ))
            .property(XLB_BF3ARG(CABINETSTATE, fSaveLocalView ))
            .property(XLB_BF3ARG(CABINETSTATE, fNotShell ))
            .property(XLB_BF3ARG(CABINETSTATE, fSimpleDefault ))
            .property(XLB_BF3ARG(CABINETSTATE, fDontShowDescBar ))
            .property(XLB_BF3ARG(CABINETSTATE, fNewWindowMode ))
            .property(XLB_BF3ARG(CABINETSTATE, fShowCompColor ))
            .property(XLB_BF3ARG(CABINETSTATE, fDontPrettyNames ))
            .property(XLB_BF3ARG(CABINETSTATE, fAdminsCreateCommonGroups ))
            .property(XLB_BF3ARG(CABINETSTATE, fUnusedFlags ))

            .property("fMenuEnumFilter", &CABINETSTATE::fMenuEnumFilter)
            ,

        xlb_class<CATEGORY_INFO>("CATEGORY_INFO") .constructor<>() .destructor()
            .property("cif", &CATEGORY_INFO::cif)
            .property("wszName", &CATEGORY_INFO::wszName)
            ,

        xlb_class<CIDA>("CIDA") .constructor<>() .destructor()
            .property("cidl", &CIDA::cidl)
            .property("aoffset", &CIDA::aoffset)
            ,

        xlb_class<CM_COLUMNINFO>("CM_COLUMNINFO") .constructor<>() .destructor()
            .property("cbSize", &CM_COLUMNINFO::cbSize)
            .property("dwMask", &CM_COLUMNINFO::dwMask)
            .property("dwState", &CM_COLUMNINFO::dwState)
            .property("uWidth", &CM_COLUMNINFO::uWidth)
            .property("uDefaultWidth", &CM_COLUMNINFO::uDefaultWidth)
            .property("uIdealWidth", &CM_COLUMNINFO::uIdealWidth)
            .property("wszName", &CM_COLUMNINFO::wszName)
            ,

        xlb_class<CMINVOKECOMMANDINFO>("CMINVOKECOMMANDINFO") .constructor<>() .destructor()
            .property("cbSize", &CMINVOKECOMMANDINFO::cbSize)
            .property("fMask", &CMINVOKECOMMANDINFO::fMask)
            .property("hwnd", &CMINVOKECOMMANDINFO::hwnd)
            .property("lpVerb", &CMINVOKECOMMANDINFO::lpVerb)
            .property("lpParameters", &CMINVOKECOMMANDINFO::lpParameters)
            .property("lpDirectory", &CMINVOKECOMMANDINFO::lpDirectory)
            .property("nShow", &CMINVOKECOMMANDINFO::nShow)
            .property("dwHotKey", &CMINVOKECOMMANDINFO::dwHotKey)
            .property("hIcon", &CMINVOKECOMMANDINFO::hIcon)
            ,

        xlb_class<CMINVOKECOMMANDINFOEX>("CMINVOKECOMMANDINFOEX") .constructor<>() .destructor()
            .property("cbSize", &CMINVOKECOMMANDINFOEX::cbSize)
            .property("fMask", &CMINVOKECOMMANDINFOEX::fMask)
            .property("hwnd", &CMINVOKECOMMANDINFOEX::hwnd)
            .property("lpVerb", &CMINVOKECOMMANDINFOEX::lpVerb)
            .property("lpParameters", &CMINVOKECOMMANDINFOEX::lpParameters)
            .property("lpDirectory", &CMINVOKECOMMANDINFOEX::lpDirectory)
            .property("nShow", &CMINVOKECOMMANDINFOEX::nShow)
            .property("dwHotKey", &CMINVOKECOMMANDINFOEX::dwHotKey)
            .property("hIcon", &CMINVOKECOMMANDINFOEX::hIcon)
            .property("lpTitle", &CMINVOKECOMMANDINFOEX::lpTitle)
            .property("lpVerbW", &CMINVOKECOMMANDINFOEX::lpVerbW)
            .property("lpParametersW", &CMINVOKECOMMANDINFOEX::lpParametersW)
            .property("lpDirectoryW", &CMINVOKECOMMANDINFOEX::lpDirectoryW)
            .property("lpTitleW", &CMINVOKECOMMANDINFOEX::lpTitleW)
            .property("ptInvoke", &CMINVOKECOMMANDINFOEX::ptInvoke)
            ,

        xlb_class<COMDLG_FILTERSPEC>("COMDLG_FILTERSPEC") .constructor<>() .destructor()
            .property("pszName", &COMDLG_FILTERSPEC::pszName)
            .property("pszSpec", &COMDLG_FILTERSPEC::pszSpec)
            ,

#ifdef _WININET_
        xlb_class<COMPONENT>("COMPONENT") .constructor<>() .destructor()
            .property("dwSize", &COMPONENT::dwSize)
            .property("dwID", &COMPONENT::dwID)
            .property("iComponentType", &COMPONENT::iComponentType)
            .property("fChecked", &COMPONENT::fChecked)
            .property("fDirty", &COMPONENT::fDirty)
            .property("fNoScroll", &COMPONENT::fNoScroll)
            .property("cpPos", &COMPONENT::cpPos)
            .property("wszFriendlyName", &COMPONENT::wszFriendlyName)
            .property("wszSource", &COMPONENT::wszSource)
            .property("wszSubscribedURL", &COMPONENT::wszSubscribedURL)
            .property("dwCurItemState", &COMPONENT::dwCurItemState)
            .property("csiOriginal", &COMPONENT::csiOriginal)
            .property("csiRestored", &COMPONENT::csiRestored)
            ,
#endif

        xlb_class<COMPONENTSOPT>("COMPONENTSOPT") .constructor<>() .destructor()
            .property("dwSize", &COMPONENTSOPT::dwSize)
            .property("fEnableComponents", &COMPONENTSOPT::fEnableComponents)
            .property("fActiveDesktop", &COMPONENTSOPT::fActiveDesktop)
            ,

        xlb_class<COMPPOS>("COMPPOS") .constructor<>() .destructor()
            .property("dwSize", &COMPPOS::dwSize)
            .property("iLeft", &COMPPOS::iLeft)
            .property("iTop", &COMPPOS::iTop)
            .property("dwWidth", &COMPPOS::dwWidth)
            .property("dwHeight", &COMPPOS::dwHeight)
            .property("izIndex", &COMPPOS::izIndex)
            .property("fCanResize", &COMPPOS::fCanResize)
            .property("fCanResizeX", &COMPPOS::fCanResizeX)
            .property("fCanResizeY", &COMPPOS::fCanResizeY)
            .property("iPreferredLeftPercent", &COMPPOS::iPreferredLeftPercent)
            .property("iPreferredTopPercent", &COMPPOS::iPreferredTopPercent)
            ,

        xlb_class<COMPSTATEINFO>("COMPSTATEINFO") .constructor<>() .destructor()
            .property("dwSize", &COMPSTATEINFO::dwSize)
            .property("iLeft", &COMPSTATEINFO::iLeft)
            .property("iTop", &COMPSTATEINFO::iTop)
            .property("dwWidth", &COMPSTATEINFO::dwWidth)
            .property("dwHeight", &COMPSTATEINFO::dwHeight)
            .property("dwItemState", &COMPSTATEINFO::dwItemState)
            ,

        xlb_class<CONFIRM_CONFLICT_ITEM>("CONFIRM_CONFLICT_ITEM") .constructor<>() .destructor()
            .property("pShellItem", &CONFIRM_CONFLICT_ITEM::pShellItem)
            .property("pszOriginalName", &CONFIRM_CONFLICT_ITEM::pszOriginalName)
            .property("pszAlternateName", &CONFIRM_CONFLICT_ITEM::pszAlternateName)
            .property("pszLocationShort", &CONFIRM_CONFLICT_ITEM::pszLocationShort)
            .property("pszLocationFull", &CONFIRM_CONFLICT_ITEM::pszLocationFull)
            .property("nType", &CONFIRM_CONFLICT_ITEM::nType)
            ,

        xlb_class<CONFIRM_CONFLICT_RESULT_INFO>("CONFIRM_CONFLICT_RESULT_INFO") .constructor<>() .destructor()
            .property("pszNewName", &CONFIRM_CONFLICT_RESULT_INFO::pszNewName)
            .property("iItemIndex", &CONFIRM_CONFLICT_RESULT_INFO::iItemIndex)
            ,

        xlb_class<CPLINFO>("CPLINFO") .constructor<>() .destructor()
            .property("idIcon", &CPLINFO::idIcon)
            .property("idName", &CPLINFO::idName)
            .property("idInfo", &CPLINFO::idInfo)
            .property("lData", &CPLINFO::lData)
            ,

        xlb_class<CREDENTIAL_PROVIDER_CREDENTIAL_SERIALIZATION>("CREDENTIAL_PROVIDER_CREDENTIAL_SERIALIZATION") .constructor<>() .destructor()
            .property("ulAuthenticationPackage", &CREDENTIAL_PROVIDER_CREDENTIAL_SERIALIZATION::ulAuthenticationPackage)
            .property("clsidCredentialProvider", &CREDENTIAL_PROVIDER_CREDENTIAL_SERIALIZATION::clsidCredentialProvider)
            .property("cbSerialization", &CREDENTIAL_PROVIDER_CREDENTIAL_SERIALIZATION::cbSerialization)
            .property("rgbSerialization", &CREDENTIAL_PROVIDER_CREDENTIAL_SERIALIZATION::rgbSerialization)
            ,

        xlb_class<CREDENTIAL_PROVIDER_FIELD_DESCRIPTOR>("CREDENTIAL_PROVIDER_FIELD_DESCRIPTOR") .constructor<>() .destructor()
            .property("dwFieldID", &CREDENTIAL_PROVIDER_FIELD_DESCRIPTOR::dwFieldID)
            .property("cpft", &CREDENTIAL_PROVIDER_FIELD_DESCRIPTOR::cpft)
            .property("pszLabel", &CREDENTIAL_PROVIDER_FIELD_DESCRIPTOR::pszLabel)
            .property("guidFieldType", &CREDENTIAL_PROVIDER_FIELD_DESCRIPTOR::guidFieldType)
            ,

        xlb_class<CSFV>("CSFV") .constructor<>() .destructor()
            .property("cbSize", &CSFV::cbSize)
            .property("pshf", &CSFV::pshf)
            .property("psvOuter", &CSFV::psvOuter)
            .property("pidl", &CSFV::pidl)
            .property("lEvents", &CSFV::lEvents)
            .property("pfnCallback", &CSFV::pfnCallback)
            .property("fvm", &CSFV::fvm)
            ,

        xlb_class<DATABLOCK_HEADER>("DATABLOCK_HEADER") .constructor<>() .destructor()
            .property("cbSize", &DATABLOCK_HEADER::cbSize)
            .property("dwSignature", &DATABLOCK_HEADER::dwSignature)
            ,

        xlb_class<DEFCONTEXTMENU>("DEFCONTEXTMENU") .constructor<>() .destructor()
            .property("hwnd", &DEFCONTEXTMENU::hwnd)
            .property("pcmcb", &DEFCONTEXTMENU::pcmcb)
            .property("pidlFolder", &DEFCONTEXTMENU::pidlFolder)
            .property("psf", &DEFCONTEXTMENU::psf)
            .property("cidl", &DEFCONTEXTMENU::cidl)
            .property("apidl", &DEFCONTEXTMENU::apidl)
            .property("punkAssociationInfo", &DEFCONTEXTMENU::punkAssociationInfo)
            .property("cKeys", &DEFCONTEXTMENU::cKeys)
            .property("aKeys", &DEFCONTEXTMENU::aKeys)
            ,

        xlb_class<DELEGATEITEMID>("DELEGATEITEMID") .constructor<>() .destructor()
            .property("cbSize", &DELEGATEITEMID::cbSize)
            .property("wOuter", &DELEGATEITEMID::wOuter)
            .property("cbInner", &DELEGATEITEMID::cbInner)
            .property("rgb", &DELEGATEITEMID::rgb)
            ,

        xlb_class<DESKBANDINFO>("DESKBANDINFO") .constructor<>() .destructor()
            .property("dwMask", &DESKBANDINFO::dwMask)
            .property("ptMinSize", &DESKBANDINFO::ptMinSize)
            .property("ptMaxSize", &DESKBANDINFO::ptMaxSize)
            .property("ptIntegral", &DESKBANDINFO::ptIntegral)
            .property("ptActual", &DESKBANDINFO::ptActual)
            .property("wszTitle", &DESKBANDINFO::wszTitle)
            .property("dwModeFlags", &DESKBANDINFO::dwModeFlags)
            .property("crBkgnd", &DESKBANDINFO::crBkgnd)
            ,

        xlb_class<DETAILSINFO>("DETAILSINFO") .constructor<>() .destructor()
            .property("pidl", &DETAILSINFO::pidl)
            .property("fmt", &DETAILSINFO::fmt)
            .property("cxChar", &DETAILSINFO::cxChar)
            .property("str", &DETAILSINFO::str)
            .property("iImage", &DETAILSINFO::iImage)
            ,

        xlb_class<DFMICS>("DFMICS") .constructor<>() .destructor()
            .property("cbSize", &DFMICS::cbSize)
            .property("fMask", &DFMICS::fMask)
            .property("lParam", &DFMICS::lParam)
            .property("idCmdFirst", &DFMICS::idCmdFirst)
            .property("idDefMax", &DFMICS::idDefMax)
            .property("pici", &DFMICS::pici)
            .property("punkSite", &DFMICS::punkSite)
            ,

        xlb_class<DLLVERSIONINFO>("DLLVERSIONINFO") .constructor<>() .destructor()
            .property("cbSize", &DLLVERSIONINFO::cbSize)
            .property("dwMajorVersion", &DLLVERSIONINFO::dwMajorVersion)
            .property("dwMinorVersion", &DLLVERSIONINFO::dwMinorVersion)
            .property("dwBuildNumber", &DLLVERSIONINFO::dwBuildNumber)
            .property("dwPlatformID", &DLLVERSIONINFO::dwPlatformID)
            ,

        xlb_class<DLLVERSIONINFO2>("DLLVERSIONINFO2") .constructor<>() .destructor()
            .property("info1", &DLLVERSIONINFO2::info1)
            .property("dwFlags", &DLLVERSIONINFO2::dwFlags)
            .property("ullVersion", &DLLVERSIONINFO2::ullVersion)
            ,

        xlb_class<DROPDESCRIPTION>("DROPDESCRIPTION") .constructor<>() .destructor()
            .property("type", &DROPDESCRIPTION::type)
            .property("szMessage", &DROPDESCRIPTION::szMessage)
            .property("szInsert", &DROPDESCRIPTION::szInsert)
            ,

        xlb_class<DROPFILES>("DROPFILES") .constructor<>() .destructor()
            .property("pFiles", &DROPFILES::pFiles)
            .property("pt", &DROPFILES::pt)
            .property("fNC", &DROPFILES::fNC)
            .property("fWide", &DROPFILES::fWide)
            ,

        xlb_class<EXP_DARWIN_LINK>("EXP_DARWIN_LINK") .constructor<>() .destructor()
            .property("dbh", &EXP_DARWIN_LINK::dbh)
            .property("szDarwinID", &EXP_DARWIN_LINK::szDarwinID)
            .property("szwDarwinID", &EXP_DARWIN_LINK::szwDarwinID)
            ,

        xlb_class<EXP_PROPERTYSTORAGE>("EXP_PROPERTYSTORAGE") .constructor<>() .destructor()
            .property("cbSize", &EXP_PROPERTYSTORAGE::cbSize)
            .property("dwSignature", &EXP_PROPERTYSTORAGE::dwSignature)
            .property("abPropertyStorage", &EXP_PROPERTYSTORAGE::abPropertyStorage)
            ,

        xlb_class<EXP_SPECIAL_FOLDER>("EXP_SPECIAL_FOLDER") .constructor<>() .destructor()
            .property("cbSize", &EXP_SPECIAL_FOLDER::cbSize)
            .property("dwSignature", &EXP_SPECIAL_FOLDER::dwSignature)
            .property("idSpecialFolder", &EXP_SPECIAL_FOLDER::idSpecialFolder)
            .property("cbOffset", &EXP_SPECIAL_FOLDER::cbOffset)
            ,

        xlb_class<EXP_SZ_LINK>("EXP_SZ_LINK") .constructor<>() .destructor()
            .property("cbSize", &EXP_SZ_LINK::cbSize)
            .property("dwSignature", &EXP_SZ_LINK::dwSignature)
            .property("szTarget", &EXP_SZ_LINK::szTarget)
            .property("swzTarget", &EXP_SZ_LINK::swzTarget)
            ,

        xlb_class<EXTRASEARCH>("EXTRASEARCH") .constructor<>() .destructor()
            .property("guidSearch", &EXTRASEARCH::guidSearch)
            .property("wszFriendlyName", &EXTRASEARCH::wszFriendlyName)
            .property("wszUrl", &EXTRASEARCH::wszUrl)
            ,

        xlb_class<FILE_ATTRIBUTES_ARRAY>("FILE_ATTRIBUTES_ARRAY") .constructor<>() .destructor()
            .property("cItems", &FILE_ATTRIBUTES_ARRAY::cItems)
            .property("dwSumFileAttributes", &FILE_ATTRIBUTES_ARRAY::dwSumFileAttributes)
            .property("dwProductFileAttributes", &FILE_ATTRIBUTES_ARRAY::dwProductFileAttributes)
            .property("rgdwFileAttributes", &FILE_ATTRIBUTES_ARRAY::rgdwFileAttributes)
            ,

        xlb_class<FILEDESCRIPTOR>("FILEDESCRIPTOR") .constructor<>() .destructor()
            .property("dwFlags", &FILEDESCRIPTOR::dwFlags)
            .property("clsid", &FILEDESCRIPTOR::clsid)
            .property("sizel", &FILEDESCRIPTOR::sizel)
            .property("pointl", &FILEDESCRIPTOR::pointl)
            .property("dwFileAttributes", &FILEDESCRIPTOR::dwFileAttributes)
            .property("ftCreationTime", &FILEDESCRIPTOR::ftCreationTime)
            .property("ftLastAccessTime", &FILEDESCRIPTOR::ftLastAccessTime)
            .property("ftLastWriteTime", &FILEDESCRIPTOR::ftLastWriteTime)
            .property("nFileSizeHigh", &FILEDESCRIPTOR::nFileSizeHigh)
            .property("nFileSizeLow", &FILEDESCRIPTOR::nFileSizeLow)
            .property("cFileName", &FILEDESCRIPTOR::cFileName)
            ,

        xlb_class<FILEGROUPDESCRIPTOR>("FILEGROUPDESCRIPTOR") .constructor<>() .destructor()
            .property("cItems", &FILEGROUPDESCRIPTOR::cItems)
            .property("fgd", &FILEGROUPDESCRIPTOR::fgd)
            ,

        xlb_class<FOLDERSETDATA>("FOLDERSETDATA") .constructor<>() .destructor()
            .property("_fs", &FOLDERSETDATA::_fs)
            .property("_vidRestore", &FOLDERSETDATA::_vidRestore)
            .property("_dwViewPriority", &FOLDERSETDATA::_dwViewPriority)
            ,

        xlb_class<FOLDERSETTINGS>("FOLDERSETTINGS") .constructor<>() .destructor()
            .property("ViewMode", &FOLDERSETTINGS::ViewMode)
            .property("fFlags", &FOLDERSETTINGS::fFlags)
            ,

#if (NTDDI_VERSION < NTDDI_WIN2K)
        xlb_class<FVSHOWINFO>("FVSHOWINFO") .constructor<>() .destructor()
            .property("cbSize", &FVSHOWINFO::cbSize)
            .property("hwndOwner", &FVSHOWINFO::hwndOwner)
            .property("iShow", &FVSHOWINFO::iShow)
            .property("dwFlags", &FVSHOWINFO::dwFlags)
            .property("rect", &FVSHOWINFO::rect)
            .property("punkRel", &FVSHOWINFO::punkRel)
            .property("strNewFile", &FVSHOWINFO::strNewFile)
            ,
#endif

        xlb_class<HELPINFO>("HELPINFO") .constructor<>() .destructor()
            .property("cbSize", &HELPINFO::cbSize)
            .property("iContextType", &HELPINFO::iContextType)
            .property("iCtrlId", &HELPINFO::iCtrlId)
            .property("hItemHandle", &HELPINFO::hItemHandle)
            .property("dwContextId", &HELPINFO::dwContextId)
            .property("MousePos", &HELPINFO::MousePos)
            ,

        xlb_class<HELPWININFO>("HELPWININFO") .constructor<>() .destructor()
            .property("wStructSize", &HELPWININFO::wStructSize)
            .property("x", &HELPWININFO::x)
            .property("y", &HELPWININFO::y)
            .property("dx", &HELPWININFO::dx)
            .property("dy", &HELPWININFO::dy)
            .property("wMax", &HELPWININFO::wMax)
            .property("rgchMember", &HELPWININFO::rgchMember)
            ,

        xlb_class<IE4COMPONENT>("IE4COMPONENT") .constructor<>() .destructor()
            .property("dwSize", &IE4COMPONENT::dwSize)
            .property("dwID", &IE4COMPONENT::dwID)
            .property("iComponentType", &IE4COMPONENT::iComponentType)
            .property("fChecked", &IE4COMPONENT::fChecked)
            .property("fDirty", &IE4COMPONENT::fDirty)
            .property("fNoScroll", &IE4COMPONENT::fNoScroll)
            .property("cpPos", &IE4COMPONENT::cpPos)
            .property("wszFriendlyName", &IE4COMPONENT::wszFriendlyName)
            .property("wszSource", &IE4COMPONENT::wszSource)
            .property("wszSubscribedURL", &IE4COMPONENT::wszSubscribedURL)
            ,

        xlb_class<ITEMIDLIST>("ITEMIDLIST") .constructor<>() .destructor()
            .property("mkid", &ITEMIDLIST::mkid)
            ,

        xlb_class<ITEMSPACING>("ITEMSPACING") .constructor<>() .destructor()
            .property("cxSmall", &ITEMSPACING::cxSmall)
            .property("cySmall", &ITEMSPACING::cySmall)
            .property("cxLarge", &ITEMSPACING::cxLarge)
            .property("cyLarge", &ITEMSPACING::cyLarge)
            ,

        xlb_class<KNOWNFOLDER_DEFINITION>("KNOWNFOLDER_DEFINITION") .constructor<>() .destructor()
            .property("category", &KNOWNFOLDER_DEFINITION::category)
            .property("pszName", &KNOWNFOLDER_DEFINITION::pszName)
            .property("pszDescription", &KNOWNFOLDER_DEFINITION::pszDescription)
            .property("fidParent", &KNOWNFOLDER_DEFINITION::fidParent)
            .property("pszRelativePath", &KNOWNFOLDER_DEFINITION::pszRelativePath)
            .property("pszParsingName", &KNOWNFOLDER_DEFINITION::pszParsingName)
            .property("pszTooltip", &KNOWNFOLDER_DEFINITION::pszTooltip)
            .property("pszLocalizedName", &KNOWNFOLDER_DEFINITION::pszLocalizedName)
            .property("pszIcon", &KNOWNFOLDER_DEFINITION::pszIcon)
            .property("pszSecurity", &KNOWNFOLDER_DEFINITION::pszSecurity)
            .property("dwAttributes", &KNOWNFOLDER_DEFINITION::dwAttributes)
            .property("kfdFlags", &KNOWNFOLDER_DEFINITION::kfdFlags)
            .property("ftidType", &KNOWNFOLDER_DEFINITION::ftidType)
            ,

        xlb_class<LOGFONT>("LOGFONT") .constructor<>() .destructor()
            .property("lfHeight", &LOGFONT::lfHeight)
            .property("lfWidth", &LOGFONT::lfWidth)
            .property("lfEscapement", &LOGFONT::lfEscapement)
            .property("lfOrientation", &LOGFONT::lfOrientation)
            .property("lfWeight", &LOGFONT::lfWeight)
            .property("lfItalic", &LOGFONT::lfItalic)
            .property("lfUnderline", &LOGFONT::lfUnderline)
            .property("lfStrikeOut", &LOGFONT::lfStrikeOut)
            .property("lfCharSet", &LOGFONT::lfCharSet)
            .property("lfOutPrecision", &LOGFONT::lfOutPrecision)
            .property("lfClipPrecision", &LOGFONT::lfClipPrecision)
            .property("lfQuality", &LOGFONT::lfQuality)
            .property("lfPitchAndFamily", &LOGFONT::lfPitchAndFamily)
            .property("lfFaceName", &LOGFONT::lfFaceName)
            ,

        xlb_class<MULTIKEYHELP>("MULTIKEYHELP") .constructor<>() .destructor()
            .property("mkSize", &MULTIKEYHELP::mkSize)
            .property("mkKeylist", &MULTIKEYHELP::mkKeylist)
            .property("szKeyphrase", &MULTIKEYHELP::szKeyphrase)
            ,

        xlb_class<NC_ADDRESS>("NC_ADDRESS") .constructor<>() .destructor()
            .property("pAddrInfo", &NC_ADDRESS::pAddrInfo)
            .property("PortNumber", &NC_ADDRESS::PortNumber)
            .property("PrefixLength", &NC_ADDRESS::PrefixLength)
            ,

        xlb_class<NEWCPLINFO>("NEWCPLINFO") .constructor<>() .destructor()
            .property("dwSize", &NEWCPLINFO::dwSize)
            .property("dwFlags", &NEWCPLINFO::dwFlags)
            .property("dwHelpContext", &NEWCPLINFO::dwHelpContext)
            .property("lData", &NEWCPLINFO::lData)
            .property("hIcon", &NEWCPLINFO::hIcon)
            .property("szName", &NEWCPLINFO::szName)
            .property("szInfo", &NEWCPLINFO::szInfo)
            .property("szHelpFile", &NEWCPLINFO::szHelpFile)
            ,

        xlb_class<NOTIFYICONDATA>("NOTIFYICONDATA") .constructor<>() .destructor()
            .property("cbSize", &NOTIFYICONDATAA::cbSize)
            .property("hWnd", &NOTIFYICONDATAA::hWnd)
            .property("uID", &NOTIFYICONDATAA::uID)
            .property("uFlags", &NOTIFYICONDATAA::uFlags)
            .property("uCallbackMessage", &NOTIFYICONDATAA::uCallbackMessage)
            .property("hIcon", &NOTIFYICONDATAA::hIcon)
            .property("szTip", &NOTIFYICONDATAA::szTip)
            .property("dwState", &NOTIFYICONDATAA::dwState)
            .property("dwStateMask", &NOTIFYICONDATAA::dwStateMask)
            .property("szInfo", &NOTIFYICONDATAA::szInfo)
            .property("uTimeout", &NOTIFYICONDATAA::uTimeout)
            .property("uVersion", &NOTIFYICONDATAA::uVersion)
            .property("szInfoTitle", &NOTIFYICONDATAA::szInfoTitle)
            .property("dwInfoFlags", &NOTIFYICONDATAA::dwInfoFlags)
            .property("guidItem", &NOTIFYICONDATAA::guidItem)
            .property("hBalloonIcon", &NOTIFYICONDATAA::hBalloonIcon)
            ,

        xlb_class<NOTIFYICONIDENTIFIER>("NOTIFYICONIDENTIFIER") .constructor<>() .destructor()
            .property("cbSize", &NOTIFYICONIDENTIFIER::cbSize)
            .property("hWnd", &NOTIFYICONIDENTIFIER::hWnd)
            .property("uID", &NOTIFYICONIDENTIFIER::uID)
            .property("guidItem", &NOTIFYICONIDENTIFIER::guidItem)
            ,

        xlb_class<NRESARRAY>("NRESARRAY") .constructor<>() .destructor()
            .property("cItems", &NRESARRAY::cItems)
            .property("nr", &NRESARRAY::nr)
            ,

        xlb_class<NSTCCUSTOMDRAW>("NSTCCUSTOMDRAW") .constructor<>() .destructor()
            .property("psi", &NSTCCUSTOMDRAW::psi)
            .property("uItemState", &NSTCCUSTOMDRAW::uItemState)
            .property("nstcis", &NSTCCUSTOMDRAW::nstcis)
            .property("pszText", &NSTCCUSTOMDRAW::pszText)
            .property("iImage", &NSTCCUSTOMDRAW::iImage)
            .property("himl", &NSTCCUSTOMDRAW::himl)
            .property("iLevel", &NSTCCUSTOMDRAW::iLevel)
            .property("iIndent", &NSTCCUSTOMDRAW::iIndent)
            ,

        xlb_class<NT_CONSOLE_PROPS>("NT_CONSOLE_PROPS") .constructor<>() .destructor()
            .property("dbh", &NT_CONSOLE_PROPS::dbh)
            .property("wFillAttribute", &NT_CONSOLE_PROPS::wFillAttribute)
            .property("wPopupFillAttribute", &NT_CONSOLE_PROPS::wPopupFillAttribute)
            .property("dwScreenBufferSize", &NT_CONSOLE_PROPS::dwScreenBufferSize)
            .property("dwWindowSize", &NT_CONSOLE_PROPS::dwWindowSize)
            .property("dwWindowOrigin", &NT_CONSOLE_PROPS::dwWindowOrigin)
            .property("nFont", &NT_CONSOLE_PROPS::nFont)
            .property("nInputBufferSize", &NT_CONSOLE_PROPS::nInputBufferSize)
            .property("dwFontSize", &NT_CONSOLE_PROPS::dwFontSize)
            .property("uFontFamily", &NT_CONSOLE_PROPS::uFontFamily)
            .property("uFontWeight", &NT_CONSOLE_PROPS::uFontWeight)
            .property("FaceName", &NT_CONSOLE_PROPS::FaceName)
            .property("uCursorSize", &NT_CONSOLE_PROPS::uCursorSize)
            .property("bFullScreen", &NT_CONSOLE_PROPS::bFullScreen)
            .property("bQuickEdit", &NT_CONSOLE_PROPS::bQuickEdit)
            .property("bInsertMode", &NT_CONSOLE_PROPS::bInsertMode)
            .property("bAutoPosition", &NT_CONSOLE_PROPS::bAutoPosition)
            .property("uHistoryBufferSize", &NT_CONSOLE_PROPS::uHistoryBufferSize)
            .property("uNumberOfHistoryBuffers", &NT_CONSOLE_PROPS::uNumberOfHistoryBuffers)
            .property("bHistoryNoDup", &NT_CONSOLE_PROPS::bHistoryNoDup)
            .property("ColorTable", &NT_CONSOLE_PROPS::ColorTable)
            ,

        xlb_class<NT_FE_CONSOLE_PROPS>("NT_FE_CONSOLE_PROPS") .constructor<>() .destructor()
            .property("dbh", &NT_FE_CONSOLE_PROPS::dbh)
            .property("uCodePage", &NT_FE_CONSOLE_PROPS::uCodePage)
            ,

        xlb_class<OPEN_PRINTER_PROPS_INFO>("OPEN_PRINTER_PROPS_INFO") .constructor<>() .destructor()
            .property("dwSize", &OPEN_PRINTER_PROPS_INFO::dwSize)
            .property("pszSheetName", &OPEN_PRINTER_PROPS_INFO::pszSheetName)
            .property("uSheetIndex", &OPEN_PRINTER_PROPS_INFO::uSheetIndex)
            .property("dwFlags", &OPEN_PRINTER_PROPS_INFO::dwFlags)
            .property("bModal", &OPEN_PRINTER_PROPS_INFO::bModal)
            ,

        xlb_class<OPENASINFO>("OPENASINFO") .constructor<>() .destructor()
            .property("pcszFile", &OPENASINFO::pcszFile)
            .property("pcszClass", &OPENASINFO::pcszClass)
            .property("oaifInFlags", &OPENASINFO::oaifInFlags)
            ,

        xlb_class<OVERLAPPED>("OVERLAPPED") .constructor<>() .destructor()
            .property("Internal", &OVERLAPPED::Internal)
            .property("InternalHigh", &OVERLAPPED::InternalHigh)
            .property("Offset", &OVERLAPPED::Offset)
            .property("OffsetHigh", &OVERLAPPED::OffsetHigh)
            .property("Pointer", &OVERLAPPED::Pointer)
            .property("hEvent", &OVERLAPPED::hEvent)
            ,

        xlb_class<PARSEDURL>("PARSEDURL") .constructor<>() .destructor()
            .property("cbSize", &PARSEDURL::cbSize)
            .property("pszProtocol", &PARSEDURL::pszProtocol)
            .property("cchProtocol", &PARSEDURL::cchProtocol)
            .property("pszSuffix", &PARSEDURL::pszSuffix)
            .property("cchSuffix", &PARSEDURL::cchSuffix)
            .property("nScheme", &PARSEDURL::nScheme)
            ,

        xlb_class<PERSIST_FOLDER_TARGET_INFO>("PERSIST_FOLDER_TARGET_INFO") .constructor<>() .destructor()
            .property("pidlTargetFolder", &PERSIST_FOLDER_TARGET_INFO::pidlTargetFolder)
            .property("szTargetParsingName", &PERSIST_FOLDER_TARGET_INFO::szTargetParsingName)
            .property("szNetworkProvider", &PERSIST_FOLDER_TARGET_INFO::szNetworkProvider)
            .property("dwAttributes", &PERSIST_FOLDER_TARGET_INFO::dwAttributes)
            .property("csidl", &PERSIST_FOLDER_TARGET_INFO::csidl)
            ,

        xlb_class<PREVIEWHANDLERFRAMEINFO>("PREVIEWHANDLERFRAMEINFO") .constructor<>() .destructor()
            .property("haccel", &PREVIEWHANDLERFRAMEINFO::haccel)
            .property("cAccelEntries", &PREVIEWHANDLERFRAMEINFO::cAccelEntries)
            ,

        xlb_class<PROFILEINFO>("PROFILEINFO") .constructor<>() .destructor()
            .property("dwSize", &PROFILEINFO::dwSize)
            .property("dwFlags", &PROFILEINFO::dwFlags)
            .property("lpUserName", &PROFILEINFO::lpUserName)
            .property("lpProfilePath", &PROFILEINFO::lpProfilePath)
            .property("lpDefaultPath", &PROFILEINFO::lpDefaultPath)
            .property("lpServerName", &PROFILEINFO::lpServerName)
            .property("lpPolicyPath", &PROFILEINFO::lpPolicyPath)
            .property("hProfile", &PROFILEINFO::hProfile)
            ,

        xlb_class<PUBAPPINFO>("PUBAPPINFO") .constructor<>() .destructor()
            .property("cbSize", &PUBAPPINFO::cbSize)
            .property("dwMask", &PUBAPPINFO::dwMask)
            .property("pszSource", &PUBAPPINFO::pszSource)
            .property("stAssigned", &PUBAPPINFO::stAssigned)
            .property("stPublished", &PUBAPPINFO::stPublished)
            .property("stScheduled", &PUBAPPINFO::stScheduled)
            .property("stExpire", &PUBAPPINFO::stExpire)
            ,

        xlb_class<QCMINFO>("QCMINFO") .constructor<>() .destructor()
            .property("hmenu", &QCMINFO::hmenu)
            .property("indexMenu", &QCMINFO::indexMenu)
            .property("idCmdFirst", &QCMINFO::idCmdFirst)
            .property("idCmdLast", &QCMINFO::idCmdLast)
            .property("pIdMap", &QCMINFO::pIdMap)
            ,

        xlb_class<QITAB>("QITAB") .constructor<>() .destructor()
            .property("piid", &QITAB::piid)
            .property("dwOffset", &QITAB::dwOffset)
            ,

        xlb_class<SERIALIZEDPROPERTYVALUE>("SERIALIZEDPROPERTYVALUE") .constructor<>() .destructor()
            .property("dwType", &SERIALIZEDPROPERTYVALUE::dwType)
            .property("rgb", &SERIALIZEDPROPERTYVALUE::rgb)
            ,

        xlb_class<SFV_CREATE>("SFV_CREATE") .constructor<>() .destructor()
            .property("cbSize", &SFV_CREATE::cbSize)
            .property("pshf", &SFV_CREATE::pshf)
            .property("psvOuter", &SFV_CREATE::psvOuter)
            .property("psfvcb", &SFV_CREATE::psfvcb)
            ,

        xlb_class<SFV_SETITEMPOS>("SFV_SETITEMPOS") .constructor<>() .destructor()
            .property("pidl", &SFV_SETITEMPOS::pidl)
            .property("pt", &SFV_SETITEMPOS::pt)
            ,

        xlb_class<SFVM_HELPTOPIC_DATA>("SFVM_HELPTOPIC_DATA") .constructor<>() .destructor()
            .property("wszHelpFile", &SFVM_HELPTOPIC_DATA::wszHelpFile)
            .property("wszHelpTopic", &SFVM_HELPTOPIC_DATA::wszHelpTopic)
            ,

        xlb_class<SFVM_PROPPAGE_DATA>("SFVM_PROPPAGE_DATA") .constructor<>() .destructor()
            .property("dwReserved", &SFVM_PROPPAGE_DATA::dwReserved)
            .property("pfn", &SFVM_PROPPAGE_DATA::pfn)
            .property("lParam", &SFVM_PROPPAGE_DATA::lParam)
            ,

        xlb_class<SHARDAPPIDINFO>("SHARDAPPIDINFO") .constructor<>() .destructor()
            .property("psi", &SHARDAPPIDINFO::psi)
            .property("pszAppID", &SHARDAPPIDINFO::pszAppID)
            ,

        xlb_class<SHARDAPPIDINFOIDLIST>("SHARDAPPIDINFOIDLIST") .constructor<>() .destructor()
            .property("pidl", &SHARDAPPIDINFOIDLIST::pidl)
            .property("pszAppID", &SHARDAPPIDINFOIDLIST::pszAppID)
            ,

        xlb_class<SHARDAPPIDINFOLINK>("SHARDAPPIDINFOLINK") .constructor<>() .destructor()
            .property("psl", &SHARDAPPIDINFOLINK::psl)
            .property("pszAppID", &SHARDAPPIDINFOLINK::pszAppID)
            ,

        xlb_class<SHChangeDWORDAsIDList>("SHChangeDWORDAsIDList") .constructor<>() .destructor()
            .property("cb", &SHChangeDWORDAsIDList::cb)
            .property("dwItem1", &SHChangeDWORDAsIDList::dwItem1)
            .property("dwItem2", &SHChangeDWORDAsIDList::dwItem2)
            .property("cbZero", &SHChangeDWORDAsIDList::cbZero)
            ,

        xlb_class<SHChangeNotifyEntry>("SHChangeNotifyEntry") .constructor<>() .destructor()
            .property("pidl", &SHChangeNotifyEntry::pidl)
            .property("fRecursive", &SHChangeNotifyEntry::fRecursive)
            ,

        xlb_class<SHChangeProductKeyAsIDList>("SHChangeProductKeyAsIDList") .constructor<>() .destructor()
            .property("cb", &SHChangeProductKeyAsIDList::cb)
            .property("wszProductKey", &SHChangeProductKeyAsIDList::wszProductKey)
            .property("cbZero", &SHChangeProductKeyAsIDList::cbZero)
            ,

        xlb_class<SHChangeUpdateImageIDList>("SHChangeUpdateImageIDList") .constructor<>() .destructor()
            .property("cb", &SHChangeUpdateImageIDList::cb)
            .property("iIconIndex", &SHChangeUpdateImageIDList::iIconIndex)
            .property("iCurIndex", &SHChangeUpdateImageIDList::iCurIndex)
            .property("uFlags", &SHChangeUpdateImageIDList::uFlags)
            .property("dwProcessID", &SHChangeUpdateImageIDList::dwProcessID)
            .property("szName", &SHChangeUpdateImageIDList::szName)
            .property("cbZero", &SHChangeUpdateImageIDList::cbZero)
            ,

        xlb_class<SHCOLUMNDATA>("SHCOLUMNDATA") .constructor<>() .destructor()
            .property("dwFlags", &SHCOLUMNDATA::dwFlags)
            .property("dwFileAttributes", &SHCOLUMNDATA::dwFileAttributes)
            .property("dwReserved", &SHCOLUMNDATA::dwReserved)
            .property("pwszExt", &SHCOLUMNDATA::pwszExt)
            .property("wszFile", &SHCOLUMNDATA::wszFile)
            ,

        xlb_class<SHCOLUMNINFO>("SHCOLUMNINFO") .constructor<>() .destructor()
            .property("scid", &SHCOLUMNINFO::scid)
            .property("vt", &SHCOLUMNINFO::vt)
            .property("fmt", &SHCOLUMNINFO::fmt)
            .property("cChars", &SHCOLUMNINFO::cChars)
            .property("csFlags", &SHCOLUMNINFO::csFlags)
            .property("wszTitle", &SHCOLUMNINFO::wszTitle)
            .property("wszDescription", &SHCOLUMNINFO::wszDescription)
            ,

        xlb_class<SHCOLUMNINIT>("SHCOLUMNINIT") .constructor<>() .destructor()
            .property("dwFlags", &SHCOLUMNINIT::dwFlags)
            .property("dwReserved", &SHCOLUMNINIT::dwReserved)
            .property("wszFolder", &SHCOLUMNINIT::wszFolder)
            ,

        xlb_class<SHCREATEPROCESSINFOW>("SHCREATEPROCESSINFOW") .constructor<>() .destructor()
            .property("cbSize", &SHCREATEPROCESSINFOW::cbSize)
            .property("fMask", &SHCREATEPROCESSINFOW::fMask)
            .property("hwnd", &SHCREATEPROCESSINFOW::hwnd)
            .property("pszFile", &SHCREATEPROCESSINFOW::pszFile)
            .property("pszParameters", &SHCREATEPROCESSINFOW::pszParameters)
            .property("pszCurrentDirectory", &SHCREATEPROCESSINFOW::pszCurrentDirectory)
            .property("hUserToken", &SHCREATEPROCESSINFOW::hUserToken)
            .property("lpProcessAttributes", &SHCREATEPROCESSINFOW::lpProcessAttributes)
            .property("lpThreadAttributes", &SHCREATEPROCESSINFOW::lpThreadAttributes)
            .property("bInheritHandles", &SHCREATEPROCESSINFOW::bInheritHandles)
            .property("dwCreationFlags", &SHCREATEPROCESSINFOW::dwCreationFlags)
            .property("lpStartupInfo", &SHCREATEPROCESSINFOW::lpStartupInfo)
            .property("lpProcessInformation", &SHCREATEPROCESSINFOW::lpProcessInformation)
            ,

        xlb_class<SHDESCRIPTIONID>("SHDESCRIPTIONID") .constructor<>() .destructor()
            .property("dwDescriptionId", &SHDESCRIPTIONID::dwDescriptionId)
            .property("clsid", &SHDESCRIPTIONID::clsid)
            ,

        xlb_class<SHDRAGIMAGE>("SHDRAGIMAGE") .constructor<>() .destructor()
            .property("sizeDragImage", &SHDRAGIMAGE::sizeDragImage)
            .property("ptOffset", &SHDRAGIMAGE::ptOffset)
            .property("hbmpDragImage", &SHDRAGIMAGE::hbmpDragImage)
            .property("crColorKey", &SHDRAGIMAGE::crColorKey)
            ,

        xlb_class<SHELL_ITEM_RESOURCE>("SHELL_ITEM_RESOURCE") .constructor<>() .destructor()
            .property("guidType", &SHELL_ITEM_RESOURCE::guidType)
            .property("szName", &SHELL_ITEM_RESOURCE::szName)
            ,

        xlb_class<SHELLDETAILS>("SHELLDETAILS") .constructor<>() .destructor()
            .property("fmt", &SHELLDETAILS::fmt)
            .property("cxChar", &SHELLDETAILS::cxChar)
            .property("str", &SHELLDETAILS::str)
            ,

        xlb_class<SHELLEXECUTEINFO>("SHELLEXECUTEINFO") .constructor<>() .destructor()
            .property("cbSize", &SHELLEXECUTEINFO::cbSize)
            .property("fMask", &SHELLEXECUTEINFO::fMask)
            .property("hwnd", &SHELLEXECUTEINFO::hwnd)
            .property("lpVerb", &SHELLEXECUTEINFO::lpVerb)
            .property("lpFile", &SHELLEXECUTEINFO::lpFile)
            .property("lpParameters", &SHELLEXECUTEINFO::lpParameters)
            .property("lpDirectory", &SHELLEXECUTEINFO::lpDirectory)
            .property("nShow", &SHELLEXECUTEINFO::nShow)
            .property("hInstApp", &SHELLEXECUTEINFO::hInstApp)
            .property("lpIDList", &SHELLEXECUTEINFO::lpIDList)
            .property("lpClass", &SHELLEXECUTEINFO::lpClass)
            .property("hkeyClass", &SHELLEXECUTEINFO::hkeyClass)
            .property("dwHotKey", &SHELLEXECUTEINFO::dwHotKey)
            .property("hIcon", &SHELLEXECUTEINFO::hIcon)
            .property("hMonitor", &SHELLEXECUTEINFO::hMonitor)
            .property("hProcess", &SHELLEXECUTEINFO::hProcess)
            ,

        xlb_class<SHELLFLAGSTATE>("SHELLFLAGSTATE") .constructor<>() .destructor()
            // bitfield
            .property(XLB_BF3ARG(SHELLFLAGSTATE, fShowAllObjects ))
            .property(XLB_BF3ARG(SHELLFLAGSTATE, fShowExtensions ))
            .property(XLB_BF3ARG(SHELLFLAGSTATE, fNoConfirmRecycle ))
            .property(XLB_BF3ARG(SHELLFLAGSTATE, fShowSysFiles ))
            .property(XLB_BF3ARG(SHELLFLAGSTATE, fShowCompColor ))
            .property(XLB_BF3ARG(SHELLFLAGSTATE, fDoubleClickInWebView ))
            .property(XLB_BF3ARG(SHELLFLAGSTATE, fDesktopHTML ))
            .property(XLB_BF3ARG(SHELLFLAGSTATE, fWin95Classic ))
            .property(XLB_BF3ARG(SHELLFLAGSTATE, fDontPrettyPath ))
            .property(XLB_BF3ARG(SHELLFLAGSTATE, fShowAttribCol ))
            .property(XLB_BF3ARG(SHELLFLAGSTATE, fMapNetDrvBtn ))
            .property(XLB_BF3ARG(SHELLFLAGSTATE, fShowInfoTip ))
            .property(XLB_BF3ARG(SHELLFLAGSTATE, fHideIcons ))
            .property(XLB_BF3ARG(SHELLFLAGSTATE, fAutoCheckSelect ))
            .property(XLB_BF3ARG(SHELLFLAGSTATE, fIconsOnly ))
            .property(XLB_BF3ARG(SHELLFLAGSTATE, fRestFlags ))
            ,

        xlb_class<SHELLSTATE>("SHELLSTATE") .constructor<>() .destructor()
            // bitfield
            .property(XLB_BF3ARG(SHELLSTATE, fShowAllObjects ))
            .property(XLB_BF3ARG(SHELLSTATE, fShowExtensions ))
            .property(XLB_BF3ARG(SHELLSTATE, fNoConfirmRecycle ))
            .property(XLB_BF3ARG(SHELLSTATE, fShowSysFiles ))
            .property(XLB_BF3ARG(SHELLSTATE, fShowCompColor ))
            .property(XLB_BF3ARG(SHELLSTATE, fDoubleClickInWebView ))
            .property(XLB_BF3ARG(SHELLSTATE, fDesktopHTML ))
            .property(XLB_BF3ARG(SHELLSTATE, fWin95Classic ))
            .property(XLB_BF3ARG(SHELLSTATE, fDontPrettyPath ))
            .property(XLB_BF3ARG(SHELLSTATE, fShowAttribCol ))
            .property(XLB_BF3ARG(SHELLSTATE, fMapNetDrvBtn ))
            .property(XLB_BF3ARG(SHELLSTATE, fShowInfoTip ))
            .property(XLB_BF3ARG(SHELLSTATE, fHideIcons ))
            .property(XLB_BF3ARG(SHELLSTATE, fWebView ))
            .property(XLB_BF3ARG(SHELLSTATE, fFilter ))
            .property(XLB_BF3ARG(SHELLSTATE, fShowSuperHidden ))
            .property(XLB_BF3ARG(SHELLSTATE, fNoNetCrawling ))
            .property(XLB_BF3ARG(SHELLSTATE, dwWin95Unused ))
            .property(XLB_BF3ARG(SHELLSTATE, uWin95Unused ))
            .property(XLB_BF3ARG(SHELLSTATE, lParamSort ))
            .property(XLB_BF3ARG(SHELLSTATE, iSortDirection ))
            .property(XLB_BF3ARG(SHELLSTATE, version ))
            .property(XLB_BF3ARG(SHELLSTATE, uNotUsed ))
            .property(XLB_BF3ARG(SHELLSTATE, fSepProcess ))
            .property(XLB_BF3ARG(SHELLSTATE, fStartPanelOn ))
            .property(XLB_BF3ARG(SHELLSTATE, fShowStartPage ))
            .property(XLB_BF3ARG(SHELLSTATE, fAutoCheckSelect ))
            .property(XLB_BF3ARG(SHELLSTATE, fIconsOnly ))
            .property(XLB_BF3ARG(SHELLSTATE, fShowTypeOverlay ))
            .property(XLB_BF3ARG(SHELLSTATE, fShowStatusBar ))
            .property(XLB_BF3ARG(SHELLSTATE, fSpareFlags ))
            ,

        xlb_class<SHFILEINFO>("SHFILEINFO") .constructor<>() .destructor()
            .property("hIcon", &SHFILEINFO::hIcon)
            .property("iIcon", &SHFILEINFO::iIcon)
            .property("dwAttributes", &SHFILEINFO::dwAttributes)
            .property("szDisplayName", &SHFILEINFO::szDisplayName)
            .property("szTypeName", &SHFILEINFO::szTypeName)
            ,

        xlb_class<SHFILEOPSTRUCT>("SHFILEOPSTRUCT") .constructor<>() .destructor()
            .property("hwnd", &SHFILEOPSTRUCT::hwnd)
            .property("wFunc", &SHFILEOPSTRUCT::wFunc)
            .property("pFrom", &SHFILEOPSTRUCT::pFrom)
            .property("pTo", &SHFILEOPSTRUCT::pTo)
            .property("fFlags", &SHFILEOPSTRUCT::fFlags)
            .property("fAnyOperationsAborted", &SHFILEOPSTRUCT::fAnyOperationsAborted)
            .property("hNameMappings", &SHFILEOPSTRUCT::hNameMappings)
            .property("lpszProgressTitle", &SHFILEOPSTRUCT::lpszProgressTitle)
            ,

        xlb_class<SHFOLDERCUSTOMSETTINGS>("SHFOLDERCUSTOMSETTINGS") .constructor<>() .destructor()
            .property("dwSize", &SHFOLDERCUSTOMSETTINGS::dwSize)
            .property("dwMask", &SHFOLDERCUSTOMSETTINGS::dwMask)
            .property("pvid", &SHFOLDERCUSTOMSETTINGS::pvid)
            .property("pszWebViewTemplate", &SHFOLDERCUSTOMSETTINGS::pszWebViewTemplate)
            .property("cchWebViewTemplate", &SHFOLDERCUSTOMSETTINGS::cchWebViewTemplate)
            .property("pszWebViewTemplateVersion", &SHFOLDERCUSTOMSETTINGS::pszWebViewTemplateVersion)
            .property("pszInfoTip", &SHFOLDERCUSTOMSETTINGS::pszInfoTip)
            .property("cchInfoTip", &SHFOLDERCUSTOMSETTINGS::cchInfoTip)
            .property("pclsid", &SHFOLDERCUSTOMSETTINGS::pclsid)
            .property("dwFlags", &SHFOLDERCUSTOMSETTINGS::dwFlags)
            .property("pszIconFile", &SHFOLDERCUSTOMSETTINGS::pszIconFile)
            .property("cchIconFile", &SHFOLDERCUSTOMSETTINGS::cchIconFile)
            .property("iIconIndex", &SHFOLDERCUSTOMSETTINGS::iIconIndex)
            .property("pszLogo", &SHFOLDERCUSTOMSETTINGS::pszLogo)
            .property("cchLogo", &SHFOLDERCUSTOMSETTINGS::cchLogo)
            ,

        xlb_class<SHITEMID>("SHITEMID") .constructor<>() .destructor()
            .property("cb", &SHITEMID::cb)
            .property("abID", &SHITEMID::abID)
            ,

        xlb_class<SHNAMEMAPPING>("SHNAMEMAPPING") .constructor<>() .destructor()
            .property("pszOldPath", &SHNAMEMAPPING::pszOldPath)
            .property("pszNewPath", &SHNAMEMAPPING::pszNewPath)
            .property("cchOldPath", &SHNAMEMAPPING::cchOldPath)
            .property("cchNewPath", &SHNAMEMAPPING::cchNewPath)
            ,

        xlb_class<SHQUERYRBINFO>("SHQUERYRBINFO") .constructor<>() .destructor()
            .property("cbSize", &SHQUERYRBINFO::cbSize)
            .property("i64Size", &SHQUERYRBINFO::i64Size)
            .property("i64NumItems", &SHQUERYRBINFO::i64NumItems)
            ,

        xlb_class<SHSTOCKICONINFO>("SHSTOCKICONINFO") .constructor<>() .destructor()
            .property("cbSize", &SHSTOCKICONINFO::cbSize)
            .property("hIcon", &SHSTOCKICONINFO::hIcon)
            .property("iSysImageIndex", &SHSTOCKICONINFO::iSysImageIndex)
            .property("iIcon", &SHSTOCKICONINFO::iIcon)
            .property("szPath", &SHSTOCKICONINFO::szPath)
            ,

        xlb_class<SLOWAPPINFO>("SLOWAPPINFO") .constructor<>() .destructor()
            .property("ullSize", &SLOWAPPINFO::ullSize)
            .property("ftLastUsed", &SLOWAPPINFO::ftLastUsed)
            .property("iTimesUsed", &SLOWAPPINFO::iTimesUsed)
            .property("pszImage", &SLOWAPPINFO::pszImage)
            ,

        xlb_class<SMCSHCHANGENOTIFYSTRUCT>("SMCSHCHANGENOTIFYSTRUCT") .constructor<>() .destructor()
            .property("lEvent", &SMCSHCHANGENOTIFYSTRUCT::lEvent)
            .property("pidl1", &SMCSHCHANGENOTIFYSTRUCT::pidl1)
            .property("pidl2", &SMCSHCHANGENOTIFYSTRUCT::pidl2)
            ,

        xlb_class<SMDATA>("SMDATA") .constructor<>() .destructor()
            .property("dwMask", &SMDATA::dwMask)
            .property("dwFlags", &SMDATA::dwFlags)
            .property("hmenu", &SMDATA::hmenu)
            .property("hwnd", &SMDATA::hwnd)
            .property("uId", &SMDATA::uId)
            .property("uIdParent", &SMDATA::uIdParent)
            .property("uIdAncestor", &SMDATA::uIdAncestor)
            .property("punk", &SMDATA::punk)
            .property("pidlFolder", &SMDATA::pidlFolder)
            .property("pidlItem", &SMDATA::pidlItem)
            .property("psf", &SMDATA::psf)
            .property("pvUserData", &SMDATA::pvUserData)
            ,

        xlb_class<SMINFO>("SMINFO") .constructor<>() .destructor()
            .property("dwMask", &SMINFO::dwMask)
            .property("dwType", &SMINFO::dwType)
            .property("dwFlags", &SMINFO::dwFlags)
            .property("iIcon", &SMINFO::iIcon)
            ,

        xlb_class<SOFTDISTINFO>("SOFTDISTINFO") .constructor<>() .destructor()
            .property("cbSize", &SOFTDISTINFO::cbSize)
            .property("dwFlags", &SOFTDISTINFO::dwFlags)
            .property("dwAdState", &SOFTDISTINFO::dwAdState)
            .property("szTitle", &SOFTDISTINFO::szTitle)
            .property("szAbstract", &SOFTDISTINFO::szAbstract)
            .property("szHREF", &SOFTDISTINFO::szHREF)
            .property("dwInstalledVersionMS", &SOFTDISTINFO::dwInstalledVersionMS)
            .property("dwInstalledVersionLS", &SOFTDISTINFO::dwInstalledVersionLS)
            .property("dwUpdateVersionMS", &SOFTDISTINFO::dwUpdateVersionMS)
            .property("dwUpdateVersionLS", &SOFTDISTINFO::dwUpdateVersionLS)
            .property("dwAdvertisedVersionMS", &SOFTDISTINFO::dwAdvertisedVersionMS)
            .property("dwAdvertisedVersionLS", &SOFTDISTINFO::dwAdvertisedVersionLS)
            .property("dwReserved", &SOFTDISTINFO::dwReserved)
            ,

        xlb_class<SORTCOLUMN>("SORTCOLUMN") .constructor<>() .destructor()
            .property("propkey", &SORTCOLUMN::propkey)
            .property("direction", &SORTCOLUMN::direction)
            ,

        xlb_class<STRRET>("STRRET") .constructor<>() .destructor()
            .property("uType", &STRRET::uType)
            .property("pOleStr", &STRRET::pOleStr)
            .property("uOffset", &STRRET::uOffset)
            .property("cStr", &STRRET::cStr)
            ,

        xlb_class<SV2CVW2_PARAMS>("SV2CVW2_PARAMS") .constructor<>() .destructor()
            .property("cbSize", &SV2CVW2_PARAMS::cbSize)
            .property("psvPrev", &SV2CVW2_PARAMS::psvPrev)
            .property("pfs", &SV2CVW2_PARAMS::pfs)
            .property("psbOwner", &SV2CVW2_PARAMS::psbOwner)
            .property("prcView", &SV2CVW2_PARAMS::prcView)
            .property("pvid", &SV2CVW2_PARAMS::pvid)
            .property("hwndView", &SV2CVW2_PARAMS::hwndView)
            ,

        xlb_class<SYNCMGR_CONFLICT_ID_INFO>("SYNCMGR_CONFLICT_ID_INFO") .constructor<>() .destructor()
            .property("pblobID", &SYNCMGR_CONFLICT_ID_INFO::pblobID)
            .property("pblobExtra", &SYNCMGR_CONFLICT_ID_INFO::pblobExtra)
            ,

        xlb_class<SYNCMGRHANDLERINFO>("SYNCMGRHANDLERINFO") .constructor<>() .destructor()
            .property("cbSize", &SYNCMGRHANDLERINFO::cbSize)
            .property("hIcon", &SYNCMGRHANDLERINFO::hIcon)
            .property("SyncMgrHandlerFlags", &SYNCMGRHANDLERINFO::SyncMgrHandlerFlags)
            .property("wszHandlerName", &SYNCMGRHANDLERINFO::wszHandlerName)
            ,

        xlb_class<SYNCMGRITEM>("SYNCMGRITEM") .constructor<>() .destructor()
            .property("cbSize", &SYNCMGRITEM::cbSize)
            .property("dwFlags", &SYNCMGRITEM::dwFlags)
            .property("ItemID", &SYNCMGRITEM::ItemID)
            .property("dwItemState", &SYNCMGRITEM::dwItemState)
            .property("hIcon", &SYNCMGRITEM::hIcon)
            .property("wszItemName", &SYNCMGRITEM::wszItemName)
            .property("ftLastUpdate", &SYNCMGRITEM::ftLastUpdate)
            ,

        xlb_class<SYNCMGRITEM>("SYNCMGRITEM") .constructor<>() .destructor()
            .property("cbSize", &SYNCMGRITEM::cbSize)
            .property("dwFlags", &SYNCMGRITEM::dwFlags)
            .property("ItemID", &SYNCMGRITEM::ItemID)
            .property("dwItemState", &SYNCMGRITEM::dwItemState)
            .property("hIcon", &SYNCMGRITEM::hIcon)
            .property("wszItemName", &SYNCMGRITEM::wszItemName)
            .property("ftLastUpdate", &SYNCMGRITEM::ftLastUpdate)
            ,

        xlb_class<SYNCMGRPROGRESSITEM>("SYNCMGRPROGRESSITEM") .constructor<>() .destructor()
            .property("cbSize", &SYNCMGRPROGRESSITEM::cbSize)
            .property("mask", &SYNCMGRPROGRESSITEM::mask)
            .property("lpcStatusText", &SYNCMGRPROGRESSITEM::lpcStatusText)
            .property("dwStatusType", &SYNCMGRPROGRESSITEM::dwStatusType)
            .property("iProgValue", &SYNCMGRPROGRESSITEM::iProgValue)
            .property("iMaxValue", &SYNCMGRPROGRESSITEM::iMaxValue)
            ,

        xlb_class<TBINFO>("TBINFO") .constructor<>() .destructor()
            .property("cbuttons", &TBINFO::cbuttons)
            .property("uFlags", &TBINFO::uFlags)
            ,

        xlb_class<THUMBBUTTON>("THUMBBUTTON") .constructor<>() .destructor()
            .property("dwMask", &THUMBBUTTON::dwMask)
            .property("iId", &THUMBBUTTON::iId)
            .property("iBitmap", &THUMBBUTTON::iBitmap)
            .property("hIcon", &THUMBBUTTON::hIcon)
            .property("szTip", &THUMBBUTTON::szTip)
            .property("dwFlags", &THUMBBUTTON::dwFlags)
            ,

        xlb_class<TOOLBARITEM>("TOOLBARITEM") .constructor<>() .destructor()
            .property("ptbar", &TOOLBARITEM::ptbar)
            .property("rcBorderTool", &TOOLBARITEM::rcBorderTool)
            .property("pwszItem", &TOOLBARITEM::pwszItem)
            .property("fShow", &TOOLBARITEM::fShow)
            .property("hMon", &TOOLBARITEM::hMon)
            ,

        xlb_class<WALLPAPEROPT>("WALLPAPEROPT") .constructor<>() .destructor()
            .property("dwSize", &WALLPAPEROPT::dwSize)
            .property("dwStyle", &WALLPAPEROPT::dwStyle)
            ,

        xlb_class<WINDOWDATA>("WINDOWDATA") .constructor<>() .destructor()
            .property("dwWindowID", &WINDOWDATA::dwWindowID)
            .property("uiCP", &WINDOWDATA::uiCP)
            .property("pidl", &WINDOWDATA::pidl)
            .property("lpszUrl", &WINDOWDATA::lpszUrl)
            .property("lpszUrlLocation", &WINDOWDATA::lpszUrlLocation)
            .property("lpszTitle", &WINDOWDATA::lpszTitle)
            ,

        xlb_class<WTS_THUMBNAILID>("WTS_THUMBNAILID") .constructor<>() .destructor()
            .property("rgbKey", &WTS_THUMBNAILID::rgbKey)
            ,








            xlb_const( "CHECK_BIND_SHL", CHECK_BIND_SHL )
#endif // 0x0600
    } );
#endif // defined(CHECK_BIND_SHL)
    return 0;
} // load_shl
