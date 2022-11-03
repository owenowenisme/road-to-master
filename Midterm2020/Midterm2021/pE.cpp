#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "string.h"

int main(){
    int arr[105][105]={0};
    
    int n;
    scanf("%d",&n);
    double d=n;
    double pr[105][105]={0};

    int t=n;int tmp;
    for(int i=0;i<n;i++){
        pr[0][i]=1/d;
    }

    while(t--){
        while(scanf("%d",&tmp)&&tmp!=-1){
            arr[n-t-1][n]++;
            arr[n-t-1][tmp]=1;
        }
    }
    for(int q=1;q<101;q++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                pr[q][i]+=arr[j][i]*pr[q-1][j]/arr[j][n];
                //printf("%d %d %d %lf %d %lf\n",i,j,arr[j][i],pr[0][j],arr[j][n],pr[q][i]);
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%.2lf%% ",100*pr[100][i]);
    }
    

}

