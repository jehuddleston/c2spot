#ifndef _ADDON_H_
#define _ADDON_H_

#include <node_api.h>
napi_value create_addon(napi_env env);
#endif //_ADDON_H_

#include <curl/curl.h>
#include <string.h>
#include <stdlib.h>
#include "auth/auth.h"
#include "util/util.h"


# define OK 200
# define BAD_TOKEN 401
# define BAD_REQUEST 403
# define RATE_LIMIT_EXCEEDED 429


const char *uribase = "https://api.spotify.com/v1";

struct Request
{
    char header[1024];
    char body[1024];
};

