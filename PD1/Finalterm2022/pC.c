#include <stdio.h>                             
#include <stdlib.h>                                                                           
#include <string.h>  
                                               
#define MAX_ID_LEN 32                       
#define MAX_PATH_CNT 16
                                               
typedef struct node_s {
    char *id;                                  
    struct node_s **paths;   
} node_t;                                                                                     
                                               
typedef struct map_s {
    unsigned node_cnt;           
    node_t *nodes;                                                                            
} map_t;                               

map_t *build_map();             
void destroy_map(map_t *map);                                                                 
void init_node(node_t *node, const char *id, node_t *paths[]);
void deinit_node(node_t *node);
node_t *step_to_next(node_t *curr, int next_idx);
                                               
int main()                                                                                    
{                                              
    map_t *map = build_map();

    int start_idx;
    scanf("%d", &start_idx);

    node_t *curr = &map->nodes[start_idx];
    while (curr) {
        int next_idx;
        scanf("%d", &next_idx);
        curr = step_to_next(curr, next_idx);
    }

    destroy_map(map);
   
    return 0;
}


map_t *build_map()
{
    map_t *map = malloc(sizeof(map_t));

    scanf("%d", &map->node_cnt);
    map->nodes = malloc(sizeof(node_t) * map->node_cnt);

    int max = 0;
    for (int i = 0; i < map->node_cnt; i++) {
        char id[MAX_ID_LEN + 1];
        node_t *paths[MAX_PATH_CNT + 1];

        scanf("%s", id);

        int curr_idx = 0, path_idx;
        while (scanf("%d", &path_idx), path_idx != -1) {
            paths[curr_idx++] = &map->nodes[path_idx];
        }

        paths[curr_idx] = NULL;

        init_node(&map->nodes[i], id, paths);
    }

    return map;
}

void destroy_map(map_t *map)
{
    for (int i = 0; i < map->node_cnt; i++)
        deinit_node(&map->nodes[i]);

    free(map->nodes);
    free(map);
}
void init_node(node_t *node, const char *id, node_t *paths[])
{

}

void deinit_node(node_t *node)
{

}

node_t *step_to_next(node_t *curr, int next_idx)
{

}