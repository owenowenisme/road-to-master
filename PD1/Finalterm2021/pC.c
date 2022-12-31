#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char a[2000],b[2000];
    scanf("%s",a);
    scanf("%s",b);
    printf("%d",strcmp(a,b));
}