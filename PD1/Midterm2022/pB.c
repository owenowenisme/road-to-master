#include<stdio.h>
#include<math.h>
#include <stdlib.h>

int main(){
    int vend[31]={10};
    for(int i=0;i<=31;i++)
        vend[i]=10;
    int n;
    scanf("%d",&n);int a,b;
    int earn =0;
    // for(int i=0;i<=2;i++){
    //     for(int j=1;j<=10;j++){
    //         printf("%d ",vend[i*10+j]);
    //     }
    //     printf("\n");
    // }
    for(int i=0;i<n;i++){
        scanf("%d %d",&a,&b);
        
        if((vend[a]-b)>0){
            earn+=(((a-1)/10)+1)*10*b;
            vend[a]-=b;
        }
        else{
            earn+=(((a-1)/10)+1)*10*vend[a];
            vend[a]=0;
        }
    }
    for(int i=0;i<=2;i++){
        for(int j=1;j<=10;j++){
            printf("%d ",vend[i*10+j]);
        }
        printf("\n");
    }
    printf("Earned: $%d",earn);
}