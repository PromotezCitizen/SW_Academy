#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define TRUE 1
#define FALSE 0

int tree[100];
int results[12][12];
int end_points = 0;

int stacker[12];
int idx = 0;

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


void search(int c) {
    if (tree[c] == -1) return;
    if (tree[c*2] == -1 && tree[c*2+1] == -1) {
        stacker[idx] = tree[c];
        for (int i = idx; i >= 0; i--) results[end_points][idx-i] = stacker[i];
        end_points++;
        return;
    }
    else {
        stacker[idx++] = tree[c];
    }
    search(c*2);
    search(c*2+1);
    idx--;
}
// 1 2 1 3 2 4 3 5 3 6 4 7 5 8 5 9 6 10 6 11 7 12 11 13

// 단말노드로부터 조상노드를 전부 찾아가자!
int main() {
    int datas[100];
    int j = 0;
    memset(tree, -1, sizeof(tree));
    for (int i = 0; i < 12; i++) {
        memset(results[i], -1, sizeof(results[i]));
    }
    tree[1] = 1;

    for (int i = 0; i < 24; i++) scanf("%d", &datas[i]);
    for (int i = 0; i < 12; i++) stack(datas[i*2], datas[i*2+1], 1);

    search(1);

    printf("%d\n", end_points);
    for (int i = 0; i < end_points; i++) {
        j = 0;
        while (i != 12 && results[i][j] != -1) printf("%d ", results[i][j++]);
        printf("\n");
    }
}