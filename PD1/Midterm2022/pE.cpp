#include<stdio.h>
#include<math.h>
#include <stdlib.h>
#include <string.h>
int max(int a,int b){
    if(a>b)
    return a;
    return b;
}
int cnt=0;
char all[600][25];
int recu(char c){
    
    
    if(c>='a'&&c<='e'){
        cnt++;
        return 1;
    }
        
    int tmp=0;
    for(int i=0;i<strlen(all[c]);i++){
        tmp=max(tmp,recu(all[c][i]));
    }
    return tmp+1;
}
int main(){
    char unused,c;
    int n;
    scanf("%d",&n);
    int chart[200]={0};
    char str[25];
    for(int i=0;i<n;i++){
        scanf("%c",&unused);
        scanf("%c",&c);
        scanf("%c",&unused);
        scanf("%c",&unused);
        scanf("%c",&unused);
        scanf("%s",all[c]);
       // printf("%d %s\n",'f',all[c]);
    }
    scanf("%c",&unused);
    scanf("%c",&c);
    scanf("%c",&unused);
    scanf("%c",&unused);
    scanf("%s",str);
    //printf("%s\n",str);
    int ans=0;
    for(int i=0;i<strlen(str);i++){
        ans=max(ans,recu(str[i]));
    }
    printf("%d %d",ans+1,cnt);
    
}