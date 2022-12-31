#include<stdio.h>
char str[25][25];
int choose[25]={0};
int n,k;
void recu(int p, int cnt) {
    if (cnt == k) {
        for (int i = 0; i < n; i++) 
            if (choose[i]) printf("%s ", str[i]);
        
        printf("\n");
        return;
    }
    for (int i = p; i < n; i++) {
        choose[i] = 1;
        recu(i + 1, cnt + 1);
        choose[i] = 0;
    }
    return;
}
int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%s", str[i]);
    recu(0, 0);
    return 0;
}
