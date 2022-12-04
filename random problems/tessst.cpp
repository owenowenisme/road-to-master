#include "bits/stdc++.h"
#include <vector>
using namespace std;

int main() {
    int a;
    char b;
    int l = 0, i, g = 0;
    scanf("%d", &a);
    scanf("%c", &b);
    char c[300];
    char d[300];
    scanf("%s", c);
    l = strlen(c);
    g = strlen(c);
    i = 0;
    while (i < g) {
        if (l > 0) {
            d[i] = c[l];
            l--;
        }
        i++;
    }
    d[0]='Q';
    // for(int i=0;i<=g;i++){
    //     printf("%d%c",i,d[i]);
    // }

    printf("%s",d);
    return 0;
}