#include <curl/curl.h>
#include <node_api.h>
#include <stdlib.h>
#include "../util/util.h"

//auth.c
int client_auth();

//exports.c
napi_value authRequest(napi_env, napi_callback_info);