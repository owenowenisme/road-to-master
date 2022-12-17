#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "string.h"


int main(){
    char str[105];char now;int key[105];int strleng;
    scanf("%d",&strleng);
    scanf("%s",str);
    for(int i=0;i<strleng;i++){
        key[i]=str[i]-97;
    }
    int index=0;
    scanf("%c",&now);
    while(scanf("%c",&now)&&now!='\n'){
            if(now>='A'&&now<='Z'){
                printf("%c",(now+key[index%strleng]+13)%26+65);
                index++;
            }
            else if(now>='a'&&now<='z'){
                printf("%c",(now+key[index%strleng]+7)%26+97);
                index++;
            }
            else{
                printf("%c",now);
            }
        }
}