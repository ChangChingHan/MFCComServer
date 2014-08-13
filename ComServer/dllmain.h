// dllmain.h : Declaration of module class.

class CComServerModule : public CAtlDllModuleT< CComServerModule >
{
public :
	DECLARE_LIBID(LIBID_ComServerLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_COMSERVER, "{72708F23-2AAB-498B-BFB9-4A9A81072E4C}")
};

extern class CComServerModule _AtlModule;
