
#include <string.h>
#include "cJSON.h"
#include <curl/curl.h>
#include <stdlib.h>

struct memory;

char *base64_encode(const unsigned char *src, size_t len);
size_t  write_callback(char*,size_t,size_t,void*);
int     sendreq(char*,char*,char*, struct curl_slist*);
int     sendpostreq(char*,char*,char*, struct curl_slist*, struct curl_httppost*, char*);
CURL    *init_curl(char *url, char *errbuf, void *resp, int opts);
struct curl_slist *build_headers(const char *headers[], int numheaders);
