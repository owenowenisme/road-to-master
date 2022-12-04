#include"stdio.h"
#include "math.h"

int main(){
    float a,b;
    scanf("%f %f",&a,&b);
    //printf("%f\n",a);
    int *c=&a;
    int *d=&b;
    
    int aa[32]={0};
    int bb[32]={0};
    int ans=*c+*d;
    int anss[32]={0};
    int p=a,q=b,r=ans;
    for(int i=31;i>=0;i--){
        aa[i]=*c&1;
        *c>>=1;
    }
    for(int i=31;i>=0;i--){
        bb[i]=*d&1;
        *d>>=1;
    }
    for(int i=31;i>=0;i--){
        anss[i]=ans&1;
        ans>>=1;
    }
    printf("   ");
    for(int i=0;i<4;i++){
        for(int j=0;j<8;j++)
            printf("%d",aa[i*8+j]);
        printf(" ");
    }
    printf("\n+) ");
    for(int i=0;i<4;i++){
        for(int j=0;j<8;j++)
            printf("%d",bb[i*8+j]);
        printf(" ");
    }
    printf("\n---------------------------------------\n   ");
    for(int i=0;i<4;i++){
        for(int j=0;j<8;j++)
            printf("%d",anss[i*8+j]);
        printf(" ");
    }

    printf("\n%d + %d = %d",p,q,r);
}

for(int i=1;i<=118;i++) touch i.cpp