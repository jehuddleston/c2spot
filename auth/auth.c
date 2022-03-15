#include "auth.h"

char *ClientID = "5efa288dc5dd47b09f4d034481cf741f";
char *ClientSecret = "123928e48dbc4867abe170ca5c44c765";
//static char *authbase = "https://accounts.spotify.com/api/token";
static char *authbase = "https://hookb.in/MqDxbZjyDotDRWppnoqJ";


int client_auth(){
    char err[1024];
    memset(err,0,1024);
    char resp[1024];
    memset(resp,0,1024);
    char AuthHeader[256];
    char clientHeader[256];
    memset(AuthHeader,0,256);
    memset(clientHeader,0,256);
    int len = sprintf(clientHeader, "%s:%s",ClientID,ClientSecret);
    const char *encoded = base64_encode((const unsigned char *) clientHeader,len);
    sprintf(AuthHeader,"Authorization:Basic %s",encoded);
    printf("%s\n",AuthHeader);
    char *maybe = "Authorization:Basic NWVmYTI4OGRjNWRkNDdiMDlmNGQwMzQ0ODFjZjc0MWY6MTIzOTI4ZTQ4ZGJjNDg2N2FiZTE3MGNhNWM0NGM3NjU=";
    printf("%s\n", maybe);
    printf("%d\n", strcmp(AuthHeader,maybe));
    const char *headers[2] = {maybe, "Content-Type:application/x-www-form-urlencoded"};
    struct curl_slist *slist = build_headers(headers,2);
    struct curl_httppost* post = NULL;
    struct curl_httppost* last = NULL;
    struct curl_slist *postslist = malloc(sizeof(struct curl_slist));
    curl_slist_append(postslist, "grant_type:client_credentials");
    curl_formadd(&post, &last, CURLFORM_COPYNAME,"grant_type", CURLFORM_COPYCONTENTS, "{grant_type:client_credentials}", CURLFORM_CONTENTTYPE, "application/json",CURLFORM_CONTENTHEADER,postslist, CURLFORM_END);
    char *data = "{grant_type:client_credentials}";
    int res = sendpostreq((char *)authbase,err,resp,slist, post, NULL);
    if(res == CURLE_OK)
        printf("%s",resp);
    else
        printf("%s",err);
    free(slist);
    free(postslist);
    return res;
}