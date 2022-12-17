#include "stdio.h"
#include "math.h"
#include "stdlib.h"
//#define int long long

int arr[105][105]={0};
int ans[105][105]={0};
int n;

void recu(int num,int a){
    for(int i=1;i<=n;i++){
        if(arr[a][i]==1){
            ans[a][i]=1;
            ans[num][i]=1;
            recu(num,i);
        }
        
    }
}

int main(){
    scanf("%d",&n);
    int num,tmp=0;char c;
    while(scanf("%d",&num)&&num!=0){
        while(scanf("%c",&c)&&c!='\n'){
            if(c>='0'&&c<='9'){
                tmp*=10;
                tmp+=c-48;
            }
            else{
                arr[num][tmp]=1;
                tmp=0;
            }
        }
        arr[num][tmp]=1;
        tmp=0;
    }
    for(int i=1;i<=n;i++){
        recu(i,i);
    }
    for(int i=1;i<=n;i++){
        ans[i][i]=1;
    }
    for(int i=1;i<=n;i++){
        printf("%d ->",i);
        for(int j=1;j<=n;j++){
            if(ans[i][j]) 
                printf(" %d",j);
        }
        printf("\n");
    }
    
}