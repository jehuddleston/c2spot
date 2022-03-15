#include "./c2spot.h"

# define NAPI_CALL(env, call) \
	do { \
		napi_status status = (call); \
		if(status != napi_ok){ \
			const napi_extended_error_info* error_info = NULL; \
			napi_get_last_error_info((env), &error_info); \
			const char *err_message = error_info->error_message; \
			bool is_pending; \
			napi_is_exception_pending((env), &is_pending); \
			if(is_pending) { \
				const char *message = (err_message == NULL) ? "empty error message": err_message; \
				napi_throw_error((env),NULL, message); \
				return NULL; \
			} \
		} \
	} while(0) 


napi_value sendRequest(napi_env env, napi_callback_info info){
	char errbuf[1024];
	char resp[1024];
	int res = sendreq("https://google.com",errbuf,resp, NULL);
	if(res != 0){
		printf("%s",errbuf);
	}else{
		printf("%s",resp);
	}
	napi_value val;
	napi_create_int32(env, res, &val);
	return val;
}

napi_value Init(napi_env env, napi_value exports) {
	napi_status status;

	napi_value fn;
	status = napi_create_function(env, NULL, 0, sendRequest, NULL, &fn);
	if (status != napi_ok) return NULL;

	status = napi_set_named_property(env, exports, "sendRequest", fn);
	if (status != napi_ok) return NULL;

	status = napi_create_function(env, "authRequest", 0, authRequest, NULL, &fn);
	if (status != napi_ok) return NULL;

	status = napi_set_named_property(env, exports, "authRequest", fn);
	if (status != napi_ok) return NULL;

	return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init)
