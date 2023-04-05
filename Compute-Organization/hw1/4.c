#include <stdio.h>
int main() {
    int i = 0;
    int h[9] = {0}, x[3] = {0}, y[3] = {0};
    FILE *input = fopen("../input/4.txt", "r");
    for (i = 0; i < 9; i++) fscanf(input, "%d", &h[i]);
    for (i = 0; i < 3; i++) fscanf(input, "%d", &x[i]);
    for (i = 0; i < 3; i++) fscanf(input, "%d", &y[i]);
    fclose(input);
    int *p_x = &x[0];
    int *p_h = &h[0];
    int *p_y = &y[0];

    asm volatile(
        "add t3,%[y],0;"
        "add t5,%[h],0;"
        "loop:lw t4,0(%[x]);"
        "   lw t6,0(t5);"
        "   mul t6,t4,t6;"
        "   lw s11,0(t3);"
        "   add s11,s11,t6;"
        "   sw s11,0(t3);"
        "   lw t4,4(%[x]);"
        "   lw t6,4(t5);"
        "   mul t6,t4,t6;"
        "   lw s11,0(t3);"
        "   add s11,s11,t6;"
        "   sw s11,0(t3);"
        "   lw t4,8(%[x]);"        
        "   lw t6,8(t5);"
        "   mul t6,t4,t6;"
        "   lw s11,0(t3);"
        "   add s11,s11,t6;"
        "   sw s11,0(t3);"
        "   add t3,t3,4;"
        "   add t5,t5,12;"
        "   add t4,zero,108;"
        "   add t4,t4,%[h];"
        "   bne t4,t5,loop;"
        :[x] "+&r" (p_x), [h] "+&r" (p_h),[y] "+&r" (p_y)
        :
    );
    p_y = &y[0];
    for (i = 0; i < 3; i++) printf("%d \n", *p_y++);
    return (0);
}

