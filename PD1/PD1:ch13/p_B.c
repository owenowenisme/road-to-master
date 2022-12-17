#include<stdio.h>

int main(){
    int n,m;int arr[200005];
    scanf("%d %d",&n,&m);
    int head=1, end=n+1;
    for(int i=1;i<=n;i++){
        arr[i]=i;
    }
    for(int i=0;i<m;i++){
        printf("%d ",arr[head++]);
        arr[end++]=arr[head++];
    }
    return 0;
}
