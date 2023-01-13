#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 15

void convert (char *last, char *first);

int main()
{
    char last_name[MAX_LEN + 2];
    char first_name[MAX_LEN + 2];
    
    // Enter last name
    fgets(last_name, MAX_LEN*2 , stdin);
    if(last_name[strlen(last_name) - 1] == '\n')
        last_name[strlen(last_name) - 1] = '\0';
    
    // Enter first name
    fgets(first_name, MAX_LEN*2, stdin);
    if(first_name[strlen(first_name) - 1] == '\n')
        first_name[strlen(first_name) - 1] = '\0';
    
    // Convert and print the name by using the function convert
    convert(last_name, first_name);
    
    return 0;
}
void convert (char *last, char *first) {
    if(strlen(last)>15||strlen(first)>15){
        printf("illegal");
        return;
    }

    for(int i=0;i<strlen(last);i++){
        if(last[i]>='a'){
            last[i]-=32;
        }
    }
    for(int i=0;i<strlen(first);i++){
        if(first[i]==' ')first[i]='-';
        else if(first[i]>='a'){
            first[i]-=32;
        }
    }
    printf("%s, %s",last,first);

}