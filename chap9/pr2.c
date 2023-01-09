#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct Tree {
    struct Tree* left;
    struct Tree* right;
    int data;
} tree;

struct Result {
    int width;
    int depth;
};
int treeWidth[100] = {0, };

struct Result result = {0, 0};

void treeAlloc(tree* t, int data);
void stack(tree* t, int c, int l, int r) {
    if (t == NULL) return; // 노드가 생성되지 않은 경우 break
    if (t->data == -1) return; // 노드가 없는 경우 break
    if (t->data == c) {
        t->left = malloc(sizeof(tree));
        t->right = malloc(sizeof(tree));
        t->data = c;
        treeAlloc(t->left, l);
        treeAlloc(t->right, r);
        return;
    }

    stack(t->left, c, l, r);
    stack(t->right, c, l, r);
}

void print(tree* t, int i) {
    if (t == NULL) return;
    print(t->left, i+1);
    if (t->data != -1) {
        result.depth = result.depth > i ? result.depth : i;
        treeWidth[i]++;
        printf("%d ", t->data);
    }
    print(t->right, i+1);
}

void treeAlloc(tree* t, int data) {
    t->left = NULL;
    t->right = NULL;
    t->data = data;
}

// tree의 높이 : 가장 높은곳
// tree의 넓이 : 해당 층에 원소가 가장 많은 것
int main() {
    tree* root = NULL;
    tree* t = NULL;
    int node, left, right;

    for (int i = 0; i < 20; i++) {
        scanf("%d %d %d", &node, &left, &right);
        if (root == NULL) {
            root = malloc(sizeof(tree));
            root->data = node;
            root->left = NULL;
            root->right = NULL;
        }
        stack(root, node, left, right);
    }

    print(root, 1); // 중위순회 출력
    printf("\n");

    for (int i = 1; i < 20; i++) {
        if (treeWidth[i] == 0) break;
        result.width = result.width > treeWidth[i] ? result.width : treeWidth[i];
    } 
    printf("depth : %d, width : %d\n", result.depth, result.width);

    return 0;
}

/*

1 2 3
2 4 5
3 6 7
4 8 -1
5 9 10
6 11 12
7 13 -1
8 -1 -1
9 14 15
10 -1 -1
11 16 -1
12 -1 -1
13 17 -1
14 -1 -1
15 18 -1
16 -1 -1
17 -1 19
18 -1 -1
19 20 -1
20 -1 -1

*/