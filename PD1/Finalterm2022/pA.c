#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define URL_MAX 2048
#define KEY_MAX 100

typedef struct search_s {
    char *key;
    char *value;
} search_t;

search_t *get_param_by_key(char *url, char *key);

int main ()
{
    char url[URL_MAX + 1], key[KEY_MAX + 1];

    fgets(url, URL_MAX, stdin);
    scanf("%s", key );

    search_t  *param = get_param_by_key (url, key);

    if (param)
        printf("key: %s, value: %s", param->key, param->value);
    else
        printf("404 Not Found");
}
search_t *get_param_by_key (char *url, char *key)
{
    search_t *ans=malloc(sizeof(search_t));
    ans->key=key;
    strcat(key,"=");
    char *c=strstr(url,key);
    if(c==NULL) return NULL;
    ans->value=malloc(sizeof(char)*10000);
    c+=strlen(key);
    int end=0;
    for(;(*c)!='\0'&&(*c)!='&'&&(*c)!='#';c++){
        end++;
    }
    ans->key[strlen(ans->key)-1]='\0';
    strncpy(ans->value,c-end,end);
    return ans;
}