#include "stdio.h"
#include "math.h"

int min(int a,int b){
    if(a>b) return b;
    return a;
}
int main(){
    int now,n,train,h,m,tmp,ans,minmin=10000;char ign;
    scanf("%d",&h);
    scanf("%c",&ign);
    scanf("%d",&m);
    scanf("%d",&n);
    now=h*60+m;
    //printf("%d\n",n);
    while(n--){
        scanf("%d",&train);
        scanf("%d",&h);
        scanf("%c",&ign);
        scanf("%d",&m);
        scanf("%d",&tmp);
        tmp+=h*60+m;
        
        if(tmp<minmin&&now<=(h*60+m)){
            minmin=tmp;
            ans=train;
            //printf("%d %d\n",ans,tmp);
        }
        
    }
    printf("%d",ans);
    return 0;
}