#include "auth.h"

napi_value authRequest(napi_env env, napi_callback_info info){
	char errbuf[1024];
	char resp[1024];
	int res = client_auth();
	if(res != 0){
		printf("%s",errbuf);
	}else{
		printf("%s",resp);
	}
	napi_value val;
	napi_create_int32(env, res, &val);
	return val;
}

napi_value AuthInit(napi_env env, napi_value exports) {
	napi_status status;

	napi_value fn;
	status = napi_create_function(env, NULL, 0, authRequest, NULL, &fn);
	if (status != napi_ok) return NULL;

	status = napi_set_named_property(env, exports, "authRequest", fn);
	if (status != napi_ok) return NULL;

	return exports;
}
