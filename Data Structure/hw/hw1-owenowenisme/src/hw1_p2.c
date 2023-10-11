#include <stdio.h>
#include <string.h>
#define fmax(a, b) (a >=b) ? a : b
int parent[10005];
int height[10005];
void init() {
    for (int i = 0; i < 10005; i++) {
        parent[i] = i;
        height[i] = 1;
    }
}
int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

int same(int a, int b) { return (find(a) == find(b)) ? 1 : 0; }
void set_union(int a, int b) {
    int roota = find(a);
    int rootb = find(b);

    if (roota == rootb) return;

    if (height[roota] >= height[rootb]) {
        parent[rootb] = roota;
        height[roota] = fmax(height[rootb] + 1, height[roota]);

    } else {
        parent[roota] = rootb;
        height[rootb] = fmax(height[roota] + 1, height[rootb]);
    }
}
int main() {
    int t, n, m;
    scanf("%d", &t);
    while (t--) {
        init();
        int n, k;
        scanf("%d %d", &n, &k);
        while (k--) {
            int x, y;
            char opn[10];
            scanf("%s", opn);
            if (opn[0] == 'u') {
                scanf("%d %d", &x, &y);
                set_union(x, y);
            } else if (opn[0] == 's') {
                scanf("%d %d", &x, &y);
                (same(x, y)) ? printf("true\n") : printf("false\n");
            } else {
                scanf("%d", &x);
                printf("%d\n", find(x));
            }
        }
    }
    return 0;
}
