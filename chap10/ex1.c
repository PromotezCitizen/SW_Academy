#include <stdio.h>
#include <memory.h>

#define MAX_NODES 8

int graph[MAX_NODES][MAX_NODES] = { {0, }};
int visited[MAX_NODES] = {0, };

void search(int c) {
    if (visited[c] == 1) return;
    visited[c] = 1;
    printf("%d ", c);

    // 오름차순 인덱스 검색
    for (int i = 1; i < MAX_NODES; i++) {
        if (graph[c][i] != 0) search(i);
    }

    // 내림차순 인덱스 검색
/*     for (int i = MAX_NODES-1; i > 0; i--) {
        if (graph[c][i] != 0) search(i);
    } */
}

// 깊이 우선 탐색 - 스택 이용
// 단순 2차원 배열로 해결 - 문제가 단순
int main() {
    int head, node;
    for (int i = 0; i < MAX_NODES; i++) {
        scanf("%d %d", &head, &node);
        graph[head][node] = 1;
        graph[node][head] = 1;
    }

    // 그래프 출력
    for (int i = 1; i < MAX_NODES; i++) {
        for (int j = 1; j < MAX_NODES; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    search(1);
    printf("\n");


    return 0;
}

// data : 1 2 1 3 2 4 2 5 4 6 5 6 6 7 3 7