#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *protocol;
    char *host;
    char *pathname;
    char *search;
    char *hash;
    int port;
} Location;

Location *parse_url(char *url);

int main()
{
    char url[500] = "";
    fgets(url, 500, stdin); // Get url string
    Location *l = parse_url(url);
    printf("Location {\n  protocol: %s,\n  host: %s,\n", l->protocol, l->host);
    if (l->port)
        printf("  port: %d,\n", l->port);
    else
        printf("  port: (default),\n");
    printf("  pathname: /%s,\n  search: ?%s,\n  hash: #%s,\n}\n", l->pathname, l->search, l->hash);
    return 0;
}
Location a;

Location *parse_url(char *url) {
    url[strlen(url)-1]='\0';
    a.protocol = malloc(sizeof(char) * 20000);
    a.host = malloc(sizeof(char) * 20000);
    a.pathname = malloc(sizeof(char) * 20000);
    a.search = malloc(sizeof(char) * 20000);
    a.hash = malloc(sizeof(char) * 20000);
    a.port = 0;
    int idx = 0;
    for (int i = 0; idx < strlen(url); i++) {
        if (url[idx] == ':') {
            a.protocol[i] = '\0';
            idx += 3;
            break;
        }
        a.protocol[i] = url[idx];
        idx++;
    }

    for (int i = 0; idx < strlen(url); i++) {
        if (url[idx] == '/' || url[idx] == ':' || url[idx] == '?' ||
            url[idx] == '#') {
            a.host[i] = '\0';
            break;
        }
        a.host[i] = url[idx];
        idx++;
    }
    if (url[idx] == ':') {
        idx++;
        for (int i = 0; idx < strlen(url); i++) {
            if (url[idx] == '/' || url[idx] == ':' || url[idx] == '?' ||
                url[idx] == '#') {
                break;
            }
            a.port *= 10;
            a.port += url[idx] - '0';
            idx++;
        }
    }
    if (url[idx] == '/') {
        idx++;
        for (int i = 0; idx < strlen(url); i++) {
            if (url[idx] == ':' || url[idx] == '?' || url[idx] == '#') {
                a.pathname[i] = '\0';
                break;
            }
            a.pathname[i] = url[idx];
            idx++;
        }
    }
    if (url[idx] == '?') {
        idx++;
        for (int i = 0; idx < strlen(url); i++) {
            if (url[idx] == ':' || url[idx] == '?' || url[idx] == '#') {
                a.search[i] = '\0';
                break;
            }
            a.search[i] = url[idx];
            idx++;
        }
    }
    if (url[idx] == '#') {
        idx++;
        for (int i = 0; idx < strlen(url); i++) {
            if (url[idx] == ':' || url[idx] == '?' || url[idx] == '#') {
                a.hash[i] = '\0';
                break;
            }
            a.hash[i] = url[idx];
            idx++;
        }
    }

    return &a;
}
