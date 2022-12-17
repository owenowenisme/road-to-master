#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "string.h"
    


int main(){
    int n;
    scanf("%d",&n);
    int arr[55][55]={0};

    arr[0][n/2]=1;
    int x=n/2,y=0;int nextx,nexty;
    for(int now=2;now<=n*n;now++){
        nextx=(x+1)%n;nexty=(y-1+n)%n;
        if(arr[nexty][nextx]!=0){
            arr[(y+1)%n][x]=now;
            y=(y+1)%n;
        }
        else{
            arr[nexty][nextx]=now;
            x=nextx;y=nexty;
        }
        
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }

    
}