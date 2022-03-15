{
	"targets": [
		{
			"target_name" : "c2spot",
			"sources": ["c2spot.c"],
			"type": "loadable_module",
			"include_dirs": ["<!(node -e \"require('nan')\")"],
			"library_dirs": ["/usr/lib","node_modules/node-libcurl"],
			"libraries": ['-lcurl'],
			"dependencies": ["auth","util"],
		},
		{
			"target_name" : "auth",
			"sources": ["auth/auth.c","auth/exports.c"],
			"type": "shared_library",
			"include_dirs": ["<!(node -e \"require('nan')\")","auth"],
			"library_dirs": ["/usr/lib","node_modules/node-libcurl"],
			"libraries": ['-lcurl'],
			"dependencies": ["util"],
		},
		{
			"target_name" : "util",
			"sources": ["util/base64.c","util/request.c","util/cJSON.c"],
			"type": "shared_library",
			"include_dirs": ["<!(node -e \"require('nan')\")","util"],
			"library_dirs": ["/usr/lib","node_modules/node-libcurl"],
			"libraries": ['-lcurl'],
		},
	]
}
