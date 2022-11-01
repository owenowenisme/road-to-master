#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "string.h"

int min(int a,int b){
    if(a>b)return b;
    return a;
}
int cmp(char a[],char b[]){
    int shorter=min(strlen(a),strlen(b));
    for(int i=0;i<shorter;i++){
        if(a[i]<97)a[i]+=32;
        if(b[i]<97)b[i]+=32;
        if(a[i]!=b[i])
            return a[i]>b[i];
    }
    return strlen(a)>strlen(b);
}
int main(){
    int n;int rank=1;
    int newstu,tmp;char newstr[10000];char tmpstr[10000];
    scanf("%d",&n);
    scanf("%d",&newstu);
    scanf("%s",newstr);
    while(n--){
        scanf("%d",&tmp);
        scanf("%s",tmpstr);
        rank+=cmp(newstr,tmpstr);
    }
    printf("%d",rank);
}