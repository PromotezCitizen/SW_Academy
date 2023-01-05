#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define MAX_TREE 100

typedef struct Data {
    int cur;
    int p;
    int c_l;
    int c_r;
} data;

int tree[100];
data results[100];

void stack(int p, int c, int i) {
    if (tree[i] == -1) return; // 노드가 없는 경우 break 처리
    if (tree[i] == p) {
        if (tree[i*2] == -1) tree[i*2] = c;
        else tree[i*2+1] = c;
        return;
    }

    stack(p, c, i*2);
    stack(p, c, i*2+1);
}

void search(int p, int cur) {
    if (tree[cur] == -1) return;

    results[cur].p = tree[p] == -1 ? 0 : tree[p];
    results[cur].cur = tree[cur];
    results[cur].c_l = tree[cur*2] == -1 ? 0 : tree[cur*2];
    results[cur].c_r = tree[cur*2+1] == -1 ? 0 : tree[cur*2+1];

    search(cur, cur*2);
    search(cur, cur*2+1);
}

// 트리 표현
int main() {
    int datas[24];
    memset(tree, -1, sizeof(tree));
    tree[1] = 1;

    for (int i = 0; i < 24; i++) scanf("%d", &datas[i]);
    // 1 2 1 3 2 4 3 5 3 6 4 7 5 8 5 9 6 10 6 11 7 12 11 13
    for (int i = 0; i < 12; i++) stack(datas[i*2], datas[i*2+1], 1);

    search(0, 1);

    printf("%3s | %3s %3s %3s\n", "cur", "l", "r", "p");
    for (int i = 0; i < 100; i++) {
        if (results[i].cur != 0) printf("%3d | %3d %3d %3d\n", results[i].cur, results[i].c_l, results[i].c_r, results[i].p);
    }
}