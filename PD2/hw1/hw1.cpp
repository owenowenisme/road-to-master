#include <bits/stdc++.h>
using namespace std;
int main(int argc,char *argv[]){
    int num=atoi(argv[1]);
    for(int i=0;i<=num;i++){
        printf("(%d,%d)\n",i,num-i);
    } 
    printf("%d",(num/2)*(num-num/2));
    return 0;
}