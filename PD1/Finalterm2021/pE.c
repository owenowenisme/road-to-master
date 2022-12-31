#include<stdio.h>
#include<string.h>
int arr[64]={0};
int cnt=63;
void f(char a) {
    int tmp;
    if (a <= '9' && a >= '0')
        tmp = a - '0';
    else
        tmp = a - 'a' + 10;
    for (int i = 0; i < 4; i++) {
        arr[cnt] = tmp % 2;
        cnt--;
        tmp /= 2;
    }
    return;
}
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        for (int i = 0; i < 64; i++) arr[i] = 0;
        cnt = 63;
        int n;
        scanf("%d", &n);
        char str[50];
        scanf("%s", str);
        for (int i = strlen(str) - 1; i >= 3; i--) {
            f(str[i]);
        }
        for (int i = 0; i < 64; i++) {
            if (i >= 56 - n && i <= 63 - n)
                printf("%d", arr[i]);
            else
                printf("0");
            if (i % 8 == 7) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
