#include <stdio.h>
#include <stdlib.h>

#define MAX_ROW 7
#define MAX_MOVE 100
#define TRUE 1
#define FALSE 0

typedef struct PriorityQueue {
    int priotity;
    int data;
    struct PriorityQueue *next;
} pq;

pq* head = NULL;
void printPq();

pq* init() {
    pq* t = malloc(sizeof(pq));
    t->priotity = -1;
    t->data = -1;
    t->next = NULL;
    return t;
}

void enqueuePriorityQueue(int data, int move) {
    pq *t1, *t2;
    t1 = head; t2 = head->next;

    while(t2 != NULL && t2->priotity > MAX_MOVE - move) {
        t1 = t1->next;
        t2 = t2->next;
    }
    t1->next = malloc(sizeof(pq));
    t1 = t1->next;
    t1->priotity = MAX_MOVE - move;
    t1->data = data;
    t1->next = t2;
}

void printPq() {
    pq *t = head->next;
    while(t != NULL) {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

int map[MAX_ROW][MAX_ROW] = {
    {0, 0, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 3, 1},
    {1, 0, 0, 0, 0, 0, 0},
    {1, 0, 1, 1, 1, 1, 2},
    {1, 0, 0, 0, 4, 1, 1},
    {1, 1, 1, 1, 1, 1, 1}
};

int visited[MAX_ROW][MAX_ROW] = {
    {0, },
    {0, },
    {0, },
    {0, },
    {0, },
    {0, },
    {0, }
};

void stack(int r, int c, int m) {
    if (visited[r][c] == 1) return;
    if (map[r][c] != 0) enqueuePriorityQueue(map[r][c], m);
    visited[r][c] = 1;

    if (c+1 != 7 && map[r][c+1] != 1) stack(r, c+1, m+1);
    if (r+1 != 7 && map[r+1][c] != 1) stack(r+1, c, m+1);
    if (c-1 != -1 && map[r][c-1] != 1) stack(r, c-1, m+1);
    if (r-1 != -1 && map[r-1][c] != 1) stack(r-1, c, m+1);
}

// 보물찾기 - 우선순위 큐 이용
// 길찾는건 스택 이용하고 우선순위는 큐?

int main() {
    head = init();
    stack(0, 0, 0);
    printf("%d", head->next->data);
    return 0;
}