#include<stdio.h>
#include<math.h>
#include <stdlib.h>

const double old=0.2966;
const double new=0.2178;
const double rateold=0.08;
const double ratenew=0.1;
const double eps=1e-8;
long aabs(long a){
    if(a<0)
    return -a;
    return a;
}
int main () {
    int twd=0,yen=0;int tmpold=0,tmpnew=0;int final=0;
    scanf("%d",&yen);
    tmpold=yen;tmpnew=yen;
    if(yen<=5000){
        tmpnew=lround(tmpnew*1.1+eps);
        tmpold=lround(tmpold*1.08+eps);
    }
    //printf("%d %d\n",tmpold,tmpnew);
    tmpold=lround(tmpold*old+eps);tmpnew=lround(tmpnew*new+eps);
    //printf("%d %d\n",tmpold,tmpnew);
    printf("%ld",lround(tmpold-tmpnew+eps));
    return 0;
}
