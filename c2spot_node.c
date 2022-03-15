#include <node_api.h>
#include "c2spot.h"

NAPI_MODULE_INIT(){
	return create_addon(env);
}
