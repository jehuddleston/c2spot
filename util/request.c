#include <curl/curl.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"

struct memory{
    size_t size;
    char *response;
};

CURL *init_curl(char *url, char *errbuf, void *resp, int opts){

    CURL *curl = curl_easy_init();
    if(curl == NULL)
        return NULL;
    curl_easy_setopt(curl,CURLOPT_URL,url);
    if(errbuf != NULL)
        curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, errbuf);
    if(resp != NULL)
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, resp);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION,write_callback);
    curl_easy_setopt(curl, CURLOPT_HEADER, 1);
    
    return curl;
}

struct curl_slist *build_headers(const char *headers[], int numheaders){

    struct curl_slist *slist=malloc(sizeof(struct curl_slist));
    for(int i = 0; i < numheaders; i++)
        curl_slist_append(slist, headers[i]);   
    return slist;
}

int sendreq(char *url, char *errbuf, char *response, struct curl_slist *headers){

    struct memory mem;
    memset(&mem,0,sizeof(struct memory));

    CURL *curl = init_curl(url, errbuf, (void*) &mem,0);
    if(!curl)
        return -1;
    CURLcode res;
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 60);
    if(headers)
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    res = curl_easy_perform(curl);
    if(res == CURLE_OK){
        char *ct;
        res = curl_easy_getinfo(curl, CURLINFO_CONTENT_TYPE, &ct);
        memmove(response,mem.response,mem.size);
    }else{
        const char *err = curl_easy_strerror(res);
        memmove(errbuf,err,strlen(err));
    }
    curl_easy_cleanup(curl);
    return res;
}
  
int sendpostreq(char *url, char *errbuf, char *response, struct curl_slist *headers, struct curl_httppost *formpost, char* data){
    struct memory mem;
    memset(&mem,0,sizeof(struct memory));
    CURL *curl = init_curl(url, errbuf, (void*) &mem,0);
    if(!curl)
        return -1;
    CURLcode res;
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 60);
    curl_easy_setopt(curl, CURLOPT_POST,1);
    if(data){
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, strlen(data));
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS,data);
    }
    if(headers)
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    if(formpost)
        curl_easy_setopt(curl, CURLOPT_HTTPPOST, formpost);

    res = curl_easy_perform(curl);
    if(res == CURLE_OK){
        char *ct;
        res = curl_easy_getinfo(curl, CURLINFO_CONTENT_TYPE, &ct);
        memmove(response,mem.response,mem.size);
    }else{
        const char *err = curl_easy_strerror(res);
        memmove(errbuf,err,strlen(err));
    }
    curl_easy_cleanup(curl);
    return res;
}

size_t write_callback(char *buffer, size_t size, size_t nitems, void *outstream){
    size_t actsize = size * nitems;
    struct memory *mem = (struct memory *)outstream;

    char *ptr = realloc(mem->response,mem->size + actsize + 1);
    if(ptr == 0){
        return 0;
    }
    mem->response=ptr;
    memmove(ptr + mem->size, buffer,actsize);
    mem->size += actsize;
    mem->response[mem->size] = 0;

    return actsize;
}