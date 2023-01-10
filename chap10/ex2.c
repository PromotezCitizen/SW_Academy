#include <stdio.h>

#define MAX_NODES 8
#define MAX_QUEUE 10

#define TRUE 1
#define FALSE 0

int graph[MAX_NODES][MAX_NODES] = { {0, }};
int visited[MAX_NODES] = {0, };
int queue[MAX_QUEUE];
int idx = 0;
int start = 0;

void enqueue(int data) {
    if (idx == MAX_QUEUE-1) return;
    queue[idx++] = data;
}

int dequeue() {
    if (start == MAX_QUEUE-1) return -1;
    return queue[start++];
}

int sumVisited() {
    int ret = 0;
    for (int i = 1; i < MAX_NODES; i++) {
        if (visited[i] == 1) ret++;
    }
    return ret == MAX_NODES - 1 ? TRUE : FALSE;
}

// 너비 우선 탐색 - 큐 이용
// 단순 2차원 배열로 해결 - 문제가 단순
int main() {
    int head, node;
    int cur;
    for (int i = 0; i < MAX_NODES; i++) {
        scanf("%d %d", &head, &node);
        graph[head][node] = 1;
        graph[node][head] = 1;
    }

    // 그래프 출력
    for (int i = 1; i < MAX_NODES; i++) {
        for (int j = 1; j < MAX_NODES; j++)
            printf("%d ", graph[i][j]);
        printf("\n");
    }

    enqueue(1);
    while(!sumVisited()) {
        cur = dequeue();
        visited[cur] = 1;
        printf("%d ", cur);
        for (int i = 1; i < MAX_NODES; i++) {
            if (graph[cur][i] != 0 && visited[i] == 0) enqueue(i);
        }
    }
    printf("\n");

    return 0;
}

// data - 1 2 1 3 2 4 2 5 4 6 5 6 6 7 3 7