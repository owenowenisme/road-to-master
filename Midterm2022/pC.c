#include<stdio.h>
#include<math.h>
#include <stdlib.h>

int main(){//A=65
    int chart[26]={0,1,2,3,4,4,0,6,7,8,9,0,0,2,0,3,4,5,6,7,8,9,0,0,y0,2};
    char str[20];
    char c;
    while(scanf("%s",str)!=EOF){
        int ans=0;
        if(str[0]>='a'&&str[0]<='z'){
            ans+=(chart[str[0]-97])*9;
            //printf(" %d ",str[0]-97);
        }
        else{
            ans+=(chart[str[0]-65])*9;

        }
       // printf("ans%d\n",ans);
        for(int i=1;i<=8;i++){
            ans+=(str[i]-48)*(9-i);
            //printf("%d ",(str[i]-48)*(9-i));
        }
        //printf("%d\n",ans);
        if(ans%10!=0)
        printf("%s is the imposter!!!\n",str);
    }
}