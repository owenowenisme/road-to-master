#include "stdio.h"
#include "math.h"
//#define int long long
int main(){
    char now;
    char c;int tmp=1;char ign;
    scanf("%d",&tmp);
    scanf("%c",&ign);
    scanf("%c",&c);
    scanf("%c",&ign);
    
    if(c=='a'){

        while(scanf("%c",&now)&&now!='\n'){
            tmp%=26;
            if(now>='A'&&now<='Z'){
                printf("%c",(now+tmp+13)%26+65);
                tmp++;
            }
            else if(now>='a'&&now<='z'){
                printf("%c",(now+tmp+7)%26+97);
                tmp++;
            }
            else{
                printf("%c",now);
            }
        }
    }
    if(c=='d'){
		
        while(scanf("%c",&now)&&now!='\n'){
			tmp%=26;
            if(now>='A'&&now<='Z'){
                printf("%c",(now+tmp+13)%26+65);
                tmp--;
            }
            else if(now>='a'&&now<='z'){
                printf("%c",(now+tmp+7)%26+97);
                tmp--;
            }
            else{
                printf("%c",now);
            }
        }
    }
}