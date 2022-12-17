#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "string.h"

int main(){
    int arr[105][105];

    int angle,x,y;
    scanf("%d",&angle);
    scanf("%d %d",&y,&x);

    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            scanf("%d",&arr[i][j]);
        }
    }

    
    if(angle==90){
        for(int i=0;i<x;i++){
        for(int j=y-1;j>=0;j--){
            printf("%d ",arr[j][i]);
        }
        printf("\n");
    }
    }
    if(angle==180){
        for(int i=y-1;i>=0;i--){
        for(int j=x-1;j>=0;j--){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    }
    if(angle==270){
       for(int i=x-1;i>=0;i--){
        for(int j=0;j<y;j++){
            printf("%d ",arr[j][i]);
        }
        printf("\n");
    }
    }
    

}

