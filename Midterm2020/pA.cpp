#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "string.h"

int  max(int a,int b){
    if(a>b)return a;
    return b;
}

int main(){
    int an,bn;
    scanf("%d %d",&an,&bn);
    int a[1005]={0},b[1005]={0};

    for(int i=0;i<an;i++)scanf("%d",&a[i]);
    for(int i=0;i<bn;i++)scanf("%d",&b[i]);
    

    
    int indexa=0;int indexb=0;

    while(indexa<an&&indexb<bn){
        //printf("%d %d",an,bn);
        if(a[indexa]<b[indexb]){
            printf("%d ",a[indexa]);
            indexa++;
        }
        else{
            printf("%d ",b[indexb]);
            indexb++;
        }
    }
    for(int i=indexa;i<an;i++){
        printf("%d ",a[i]);
    }
    for(int i=indexb;i<bn;i++){
        printf("%d ",b[i]);
    }


    return 0;
}
