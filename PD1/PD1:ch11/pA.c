#include <stdio.h>
#include <stdlib.h>

struct ESPer {
    char name[64];
    int level;
};

int cmp(const void *a, const void *b);
void sort_level(struct ESPer *arr, int length);

int main()
{
    int n;
    struct ESPer tokiwadai[100];

    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d %s", &(tokiwadai[i].level), tokiwadai[i].name);
    }
    sort_level(tokiwadai, n);
    for(int i = 0;i < n;++i) {
        printf("%d %s\n", tokiwadai[i].level, tokiwadai[i].name);
    }
    return 0;
}
typedef struct ESPer ESPer;
int cmp(const void *a, const void *b) {
    return ((ESPer *)a)->level>((ESPer *)b)->level;
}

void sort_level(struct ESPer *arr, int length) {
    qsort(arr,length,sizeof(ESPer),cmp);
}
