#include <stdio.h>
#include <math.h>
int arr[1050]={0};
char str[1050],judge[250];

int max(int a,int b){
    if(a>b) return a;
     return b;
}

int min(int a,int b){
    if(a>b) return b;
     return a;
}

int cmp(int a,int b){
    if(str[arr[a]]=='r'&&str[arr[b]]=='p'){
        return arr[b];
    }
    else if(str[arr[a]]=='p'&&str[arr[b]]=='r'){
        return arr[a];
    }
    else if(str[arr[a]]=='s'&&str[arr[b]]=='r'){
        return arr[b];
    }
    else if(str[arr[a]]=='r'&&str[arr[b]]=='s'){
        return arr[a];
    }
    else if(str[arr[a]]=='s'&&str[arr[b]]=='p'){
        return arr[a];
    }
    else if(str[arr[a]]=='p'&&str[arr[b]]=='s'){
        return arr[b];
    }
    printf("debug");
    return arr[b];
}

int main(){

    int n;int power=0;

    scanf("%d",&n);

    int tmp=n;
    
    while(tmp>1){
        tmp/=2;
        power++;
    }

        scanf("%s",str+1);

        scanf("%s",judge+1);
        //printf("%s",judge+1);

    for(int i=1;i<=1024;i++)
        arr[i]=i;
    
    for(int i=1;i<=power;i++){
        
        if(judge[i]=='b'){
            for(int j=1;j<=pow(2,power-i+1);j+=2){
                //printf("\n%d %d %c %c ",arr[j],arr[j+1],str[arr[j]],str[arr[j+1]]);
                if(str[arr[j]]==str[arr[j+1]]){
                    arr[(j+1)/2]=max(arr[j],arr[j+1]);
                   // printf("tst1 ");
                }
                else{
                    arr[(j+1)/2]=cmp(j,j+1);
                   // printf("tst2 ");
                }
            }
        }                
        else{
             for(int j=1;j<=pow(2,power-i+1);j+=2){
                //printf("\n%d %d %c %c ",arr[j],arr[j+1],str[arr[j]],str[arr[j+1]]);
                if(str[arr[j]]==str[arr[j+1]]){
                    arr[(j+1)/2]=min(arr[j],arr[j+1]);
                    //printf("tst3 ");
                }
                else{
                    arr[(j+1)/2]=cmp(j,j+1);
                    //printf("tst4 ");
                }
            }
        }
        // for(int j=1;j<=pow(2,power-i+1);j++){
        //     printf("%d ",arr[j]);
        // }
        //printf("\n");

    }

    printf("%d",arr[1]);
    return 0;
}