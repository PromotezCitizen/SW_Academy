#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

// 같은 높이 최대 면적 찾기
// 1 1 2 3 4
// 2 3 3 3 4
// 1 1 2 3 3
// 1 2 3 3 3
// 1 1 1 1 1

// 일 경우, MAX[1-4] : { 8, 1, 9, 2 }
// 로 9 를 출력하면 된다.


#define MAX_TILE 8
#define TRUE 1
#define FALSE 0

int tiles[8][8];
int visited[8][8] = { {0, } };
int max_area[6] = {0, 0, 0, 0, 0, 0}; // 각 index별 가장 큰 넓이 저장. 사실 필요 없긴 함

int area = 1;

int cmpfunc(const void* a, const void* b) {
    return *(int*)b - *(int*)a;
}

void search(int idx, int r, int c) {
    if (r == -1) return;
    if (r == MAX_TILE) return;
    if (c == -1) return;
    if (c == MAX_TILE) return;
    if (visited[r][c] == TRUE) return;
    if (tiles[r][c] != idx) return;

    printf("%d - %d %d\n", idx, r, c);
    visited[r][c] = TRUE;
    max_area[idx] = max_area[idx] > ++area ? max_area[idx] : area;

    search(idx, r-1, c);
    search(idx, r, c+1);
    search(idx, r+1, c);
    search(idx, r, c-1);
}

// 깊이 우선? 너비 우선?
int main() {
    for (int i = 0; i < MAX_TILE; i++) {
        for (int j = 0; j < MAX_TILE; j++) {
            scanf("%d", &tiles[i][j]);
            // tiles[i][j] = rand() % 5 + 1;
        }
    }

    for (int i = 1; i <= 5; i++) {
        for (int r = 0; r < MAX_TILE; r++) {
            for (int c = 0; c < MAX_TILE; c++) {
                area = 0;
                search(i, r, c);
                // if (visited[r][c] == TRUE) continue;
                // if (tiles[r][c] == i) {
                //     // 탐색 시작 - 깊이 우선?
                //     search(i, r, c);
                // }
            }
        }
    }

    qsort(max_area, sizeof(max_area) / sizeof(int), sizeof(int), cmpfunc);
    printf("%d\n", max_area[0]);
}

// data

/*
1 2 2 1 1 3 3 3
4 1 1 3 3 3 3 3
4 1 5 3 1 1 1 3
2 2 2 3 3 4 4 4
2 3 3 3 3 4 2 2
3 4 4 2 2 1 2 4
3 4 4 1 2 2 5 2
3 3 3 4 4 4 5 5
*/