#include <stdio.h>
#include <stdlib.h>
#define MAXN 200005
#define fmax(a, b) (a >=b) ? a : b
long long parent[MAXN];
long long height[MAXN];
typedef struct node {
    long long vertex;
    long long cost;
    struct node* next;
} node;
typedef struct edge {
    long long src;
    long long dest;
    long long cost;
}edge;
typedef struct graph {
    long long vertex_num;
    struct node** adjlist;
} graph;
graph* create_graph(long long v_num){
    graph* g = (graph*)malloc(sizeof(graph));
    g->vertex_num=v_num;
    g->adjlist = (node**)malloc(v_num*sizeof(node*));
    for(long long i=0;i<v_num;i++)
        g->adjlist[i] = NULL;
    return g;
}
edge create_edge(graph* g ,long long src,long long dest,long long cost){
    node* new_node = (node*)malloc(sizeof(node));
    new_node->vertex = dest;
    new_node->cost = cost;
    new_node->next = g->adjlist[src];
    g->adjlist[src] = new_node;
    new_node = (node*)malloc(sizeof(node));
    new_node->vertex = src;
    new_node->cost = cost;
    new_node->next = g->adjlist[dest];
    g->adjlist[dest] = new_node; 
    edge new_edge; 
    new_edge.src = src;
    new_edge.dest = dest;
    new_edge.cost = cost;
    return new_edge;
}
int cmp(const void *a, const void *b) {
    edge* edge_a = (edge *)a;
    edge* edge_b = (edge *)b;
    return edge_a->cost - edge_b->cost;
}
void init() {
    for (long long i = 0; i < MAXN; i++) {
        parent[i] = i;
        height[i] = i;
    }
}
long long find(long long x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}
long long same(long long a, long long b) { return (find(a) == find(b)) ? 1 : 0; }
void set_union(long long a, long long b) {
    long long roota = find(a);
    long long rootb = find(b);

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
    long long v_num, e_num;
    init();
    scanf("%lld %lld", &v_num, &e_num);
    long long s, t, c;
    graph* g = create_graph(v_num);
    edge* edges = (edge*)malloc(e_num*sizeof(edge));
    for (long long i = 0; i < e_num; i++) {
        scanf("%lld %lld %lld", &s, &t, &c);
        edges[i]=create_edge(g,s,t,c);
    }
    qsort(edges,e_num,sizeof(edge),cmp);
    long long ans = 0;
    for(long long i=0;i<e_num;i++){
        if(!same(edges[i].dest,edges[i].src)){
            ans+=edges[i].cost;
            set_union(edges[i].dest,edges[i].src);
        }
    }
    printf("%lld",ans);
    return 0;
}