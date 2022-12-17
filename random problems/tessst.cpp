#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct
{
    const char* protocol = 0;
    const char* site = 0;
    const char* port = 0;
    const char* path = 0;
} URL_INFO;
URL_INFO* split_url(URL_INFO* info, const char* url)
{
    if (!info || !url)
        return NULL;
    info->protocol = strtok(strcpy((char*)malloc(strlen(url)+1), url), "://");
    info->site = strstr(url, "://");
    if (info->site)
    {
        info->site += 3;
        char* site_port_path = strcpy((char*)calloc(1, strlen(info->site) + 1), info->site);
        info->site = strtok(site_port_path, ":");
        info->site = strtok(site_port_path, "/");
    }
    else
    {
        char* site_port_path = strcpy((char*)calloc(1, strlen(url) + 1), url);
        info->site = strtok(site_port_path, ":");
        info->site = strtok(site_port_path, "/");
    }
    char* URL = strcpy((char*)malloc(strlen(url) + 1), url);
    info->port = strstr(URL + 6, ":");
    char* port_path = 0;
    char* port_path_copy = 0;
    if (info->port && isdigit(*(port_path = (char*)info->port + 1)))
    {
        port_path_copy = strcpy((char*)malloc(strlen(port_path) + 1), port_path);
        char * r = strtok(port_path, "/");
        if (r)
            info->port = r;
        else
            info->port = port_path;
    }
    else
        info->port = "80";
    if (port_path_copy)
        info->path = port_path_copy + strlen(info->port ? info->port : "");
    else 
    {
        char* path = strstr(URL + 8, "/");
        info->path = path ? path : "/";
    }
    int r = strcmp(info->protocol, info->site) == 0;
    if (r && info->port == "80")
        info->protocol = "http";
    else if (r)
        info->protocol = "tcp";
    return info;
}