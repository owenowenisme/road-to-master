#include <stdio.h>
#include <stdlib.h>

struct node {
    int id;
    struct node *next;
};

struct node *read_data(int *size); // TODO: implement this function

void print_data(struct node *adj, int size) {
    if (!adj) {
        return;
    }
    for (int i = 0; i < size; ++i) {
        printf("%d -> ", adj[i].id);
        for (struct node *ptr = adj[i].next; ptr != NULL; ptr = ptr->next) {
            printf("%d ", ptr->id);
        }
        putchar('\n');
    }
    return;
}

void free_data(struct node *adj, int size) {
    if (!adj) {
        return;
    }
    for (int i = 0; i < size; ++i) {
        struct node *ptr = adj[i].next;
        while (ptr) {
            adj[i].next = ptr->next;
            free(ptr);
            ptr = adj[i].next;
        }
    }
    free(adj);
    return;
}

int main() {
    int size;
    struct node *adj = read_data(&size);
    if (!adj) {
        fprintf(stderr, "Error allocating memory.");
        exit(1);
    }
    print_data(adj, size);
    free_data(adj, size);
    return 0;
}
typedef struct node node;
int cmp(const void * a, const void * b){
    return ((node*)a)->id-((node*)b)->id;
}
struct node *read_data(int *size) {
    *size = 0;
    int n;
    int idx = 0;
    node *a = malloc(sizeof(node) * 1005);
    node *b = a;
    while (scanf("%d", &n) != EOF) {
        b->id = n;
        for (int i = 0; i < 4; i++) getchar();
        int tmp = 0;

        (*size)++;
        node *now = b;
        while (scanf("%d", &tmp) && tmp != 0) {
            node *q = malloc(sizeof(node));
            q->id = tmp;
            now->next = q;
            now = now->next;
        }
        now->next = NULL;
        b++;
    }
    qsort((void *)a, *size, sizeof(node), cmp);
    return a;
}