#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define PRE_ORD 0
#define MID_ORD 1
#define PST_ORD 2

int tree[100];

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

void search(int c, int o) {
    if (tree[c] == -1) return;

    switch(o) {
        case PRE_ORD:
            printf("%3d ", tree[c]);
            search(c*2, o);
            search(c*2+1, o);
            break;
        case MID_ORD:
            search(c*2, o);
            printf("%3d ", tree[c]);
            search(c*2+1, o);
            break;
        case PST_ORD:
            search(c*2, o);
            search(c*2+1, o);
            printf("%3d ", tree[c]);
            break;
    }
}
// 트리 표현
int main() {
    int datas[24];
    memset(tree, -1, sizeof(tree));
    tree[1] = 1;

    for (int i = 0; i < 24; i++) scanf("%d", &datas[i]);
    // 1 2 1 3 2 4 3 5 3 6 4 7 5 8 5 9 6 10 6 11 7 12 11 13
    for (int i = 0; i < 12; i++) stack(datas[i*2], datas[i*2+1], 1);

    printf("전위순회 : ");
    search(1, PRE_ORD);
    printf("\n");
    printf("중위순회 : ");
    search(1, MID_ORD);
    printf("\n");
    printf("후위순회 : ");
    search(1, PST_ORD);
    printf("\n");
}