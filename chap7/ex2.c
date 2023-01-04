#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE 10
#define MAX_PROP 100

typedef struct PriorityQueue {
    int priotity;
    int data;
    struct PriorityQueue *next;
} pq;

pq* head = NULL;
void printPq();

pq* init(int data) {
    pq* t = malloc(sizeof(pq));
    t->priotity = -1;
    t->data = -1;
    t->next = NULL;
    return t;
}

void enqueuePriorityQueue(int data) {
    pq *t1, *t2;
    t1 = head; t2 = head->next;

    if (t2 == NULL) {
        t1->next = malloc(sizeof(pq));
        t1 = t1->next;
        t1->priotity = MAX_PROP - data;
        t1->data = data;
        t1->next = NULL;
        return;
    }

    while(t2 != NULL && t2->priotity > MAX_PROP - data) {
        t1 = t1->next;
        t2 = t2->next;
    }
    t1->next = malloc(sizeof(pq));
    t1 = t1->next;
    t1->priotity = MAX_PROP - data;
    t1->data = data;
    t1->next = t2;
}

int dequeuePriorityQueue() {
    pq *t1, *t2;
    int ret = 0;
    t1 = head; t2 = head->next;

    if (t2 == NULL) return -1;

    ret = t2->data;
    t1->next = t2->next;
    free(t2);
    return ret;
}

void printPq() {
    pq *t = head->next;
    while(t != NULL) {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

// 우선순위 큐 구현
// 링크드리스트 이용

int main() {
    head = init(-1);

    enqueuePriorityQueue(5);
    enqueuePriorityQueue(4);
    enqueuePriorityQueue(1);

    printf("%d ", dequeuePriorityQueue());
    printf("%d ", dequeuePriorityQueue());
    printf("%d\n", dequeuePriorityQueue());
    return 0;
}