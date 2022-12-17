#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "string.h"
int change(char c){
    if(c>='A'&&c<='F') c+=32;
    if(c>='a'&&c<='f')return c-87;
    
    return c-48;
}
void decode(int n){
    if(n<16){
        printf("%x",n);
        return ;
    }
    int even=0,odd=0;
    int tmp=n;int cnt=0;
    while(tmp){
        tmp/=16;
        cnt++;
    }
    if(cnt%2){
        while(n){
        even+=n%16;
        n/=16;
        odd+=n%16;
        n/=16;
        }
    }
    else {
        while(n){
        odd+=n%16;
        n/=16;
        even+=n%16;
        n/=16;
        }
    }

    decode(even);
    decode(odd);
}

int main(){
    char str[10005];int even=0,odd=0;
    scanf("%s",str);
    for(int i=0;i<strlen(str);i+=2){
        even+=change(str[i]);
    }
    for(int i=1;i<strlen(str);i+=2){
        odd+=change(str[i]);
    }
    decode(even);
    decode(odd);
    
}