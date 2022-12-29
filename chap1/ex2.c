#include <stdio.h>
#include <stdlib.h>

#define MAX_ROW 10

void printMap(const int* a) {
    for (int r = 0; r < MAX_ROW; r++) {
        for (int c = 0; c < MAX_ROW; c++) {
            printf("%d ", *(a + r * MAX_ROW + c));
        }
        printf("\n");
    }
}

int checkRow(const int* a) {
    int cnt = 0;
    int t = 0;
    for (int r = 0; r < MAX_ROW; r++) {
        for (int c = 0; c < MAX_ROW; c++) {
            if (*(a + r*MAX_ROW + c) == 1) {
                if (c == MAX_ROW - 1 && t > 1) {
                    cnt++;
                    t = 0;
                    continue;
                }
                t++;
            }
            else {
                if (t > 1) {
                    cnt++;
                }
                t = 0;
            }
        }
    }
    return cnt;
}

int checkCol(const int* a) {
    int cnt = 0;
    int t = 0;
    for (int c = 0; c < MAX_ROW; c++) {
        for (int r = 0; r < MAX_ROW; r++) {
            if (*(a + r*MAX_ROW + c) == 1) {
                if (r == MAX_ROW-1 && t > 1) {
                    cnt++;
                    t = 0;
                    continue;
                }
                t++;
            }
            else {
                if (t > 1) {
                    cnt++;
                }
                t = 0;
            }
        }
    }
    return cnt;
}

// 주어진 배열에서 직선의 개수는?
int main(int argc, char* argv[]) {
    int a[MAX_ROW * MAX_ROW] = {
        1, 1, 1, 0, 0, 0, 0, 0, 0, 1,
        0, 0, 0, 0, 1, 1, 0, 0, 0, 1,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        0, 0, 0, 0, 0, 0, 1, 0, 0, 1,
        0, 0, 1, 1, 1, 1, 0, 1, 0, 1,
        0, 1, 0, 0, 0, 0, 1, 0, 0, 1,
        0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 1, 1, 0, 0, 0
    };
    int result = 0;

    printMap(a);

    result += checkRow(a);
    result += checkCol(a);

    printf("결과 : %d\n", result);

    return 0;
}