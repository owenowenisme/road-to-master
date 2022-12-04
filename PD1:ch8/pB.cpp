#include <stdio.h>

typedef unsigned long long uint64_t;

void fib_fast_doubling(unsigned k, uint64_t *f2k, uint64_t *f2k1);

int main()
{
    unsigned k;
    scanf("%u", &k);

    uint64_t f2k, f2k1;
    fib_fast_doubling(k / 2, &f2k, &f2k1);

    printf("%llu", (k & 0x1) ? f2k1 : f2k);

    return 0;
}
void fib_fast_doubling(unsigned k, uint64_t *f2k, uint64_t *f2k1)
{	
    uint64_t dp[100]={0};
    dp[1]=1;dp[2]=1;
	for(int i=3;i<100;i++){
        dp[i]=dp[i-1]+dp[i-2];
     //printf("%llu %llu\n",dp[i]);
    }
    
    *f2k=dp[k*2];
     *f2k1=dp[k*2+1];
    return;
}