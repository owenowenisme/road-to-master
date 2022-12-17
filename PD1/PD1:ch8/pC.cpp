#include<stdio.h>
#include<stdlib.h>
int array[1500];
int maxChandy( int size) ;
int main() {
    int size = 0;
    scanf("%d", &size);
    for(int i = 0 ; i < size; ++i) {
        scanf("%d", &array[i]);
    }
    printf("%d\n", maxChandy(size));
    return 0;
}
int max(int a,int b){
    if(a>b)return a;
    return b;
}
int dp[100]={0};
int maxChandy(int size){
    dp[0]=array[0];
    dp[1]=max(array[0],array[1]);

    for(int i=2;i<size;i++){
        dp[i]=max(dp[i-1],dp[i-2]+array[i]);
    }
    return dp[size-1];
}