#include <stdio.h>

unsigned long construct(unsigned char parts[16]);

int main()
{
    unsigned char parts[16];
    for (int i = 0; i < 16; i++)
        scanf("%hhx", parts + i);

    printf("%lu", construct(parts));
    return 0;
}
unsigned long construct(unsigned char parts[16])
{
    unsigned long a=0,b=0;
    for(int i=7;i>=0;i--){
        a<<=8;
        b<<=8;
        a+=(unsigned long)parts[i];
        b+=(unsigned long)parts[i+8];
    }
    return a^b;
}