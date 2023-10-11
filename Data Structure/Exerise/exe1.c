#include "stdio.h"
#include "string.h"

int recursive_f(int num){
    if(num<=1) return num;
    else return recursive_f(num-2)+recursive_f(num-1);
}
int main(){
    int t;scanf("%d",&t);
    int f[50];
    f[0]=0;f[1]=1;
    char s[10];int n;
    for(int i=2;i<50;i++){
        f[i]=f[i-1]+f[i-2];
    }
    while(t--){
        scanf("%s %d",s,&n);
        if(s[0]=='r'){
            printf("%d\n",recursive_f(n));
        }else{
            printf("%d\n",f[n]);
        }
    }
}
