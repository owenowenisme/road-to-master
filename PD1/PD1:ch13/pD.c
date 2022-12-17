#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_s {
	int weight;
	int value;
	struct node_s *next;
} node_t;

typedef struct prio_queue_s {
	node_t *head;
} prio_queue_t;

void enqueue(prio_queue_t * const queue, int value, int weight);
node_t *dequeue(prio_queue_t * const queue);
void print_nodes(const prio_queue_t * const queue);

int main() {
	int N;
	scanf("%d", &N);
	prio_queue_t queue = {
		.head = NULL,
	};
	for (int i = 0; i < N; i++) {
		char op[8];
		scanf("%s", op);
		if (!strcmp(op, "ENQUEUE")) {
			int v, w;
			scanf("%d%d", &v, &w);
			enqueue(&queue, v, w);
		}
		else if (!strcmp(op, "DEQUEUE")) {
			free(dequeue(&queue));
        }
		print_nodes(&queue);
	}
	return 0;
}

void print_nodes(const prio_queue_t *const queue) {
	if (!queue->head) {
		printf("EMPTY\n");
		return;
	}
	for (node_t *node = queue->head; node; node = node->next) {
		printf(" -> %d", node->value);
    }
	printf("\n");
    return;
}
void enqueue(prio_queue_t *const queue, int value, int weight) {
    node_t *tmp = malloc(sizeof(node_t));
    tmp->value = value;
    tmp->weight = weight;
    tmp->next = NULL;
    if (!queue->head) {
        tmp->next = NULL;
        queue->head = tmp;
    } else {
        node_t *now = queue->head;
        node_t *prev = NULL;
        while (1) {
            prev = now;
            now = now->next;
            if (now == NULL || now->weight > weight) {
                break;
            }
        }
        if (weight < queue->head->weight) {
            tmp->next = queue->head;
            queue->head = tmp;
        } else if (now == NULL) {
            prev->next = tmp;
        } else {
            tmp->next = now;
            prev->next = tmp;
        }
    }
    return;
}

node_t *dequeue(prio_queue_t *const queue) {
    if (!queue->head) 
        return NULL;
    node_t *tmp = queue->head;
    queue->head = queue->head->next;
    return tmp;
}