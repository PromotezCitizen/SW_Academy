#include <stdio.h>
#include <stdlib.h>

#define MAX_ROW 5

#define SUM(a, r, c) ((a)[(r)-1][(c)] + (a)[(r)][(c)] + (a)[(r)+1][(c)] + (a)[(r)][(c)-1] + (a)[(r)][(c)+1])

// 최대 십자 합
// 5*5 배열에서 중앙과 상하좌우 요소 합을 십자합이라 한다.
int main() {
    int a[MAX_ROW][MAX_ROW];
    int result = 0;
    int sum;
    for (int i = 0; i < MAX_ROW; i++) {
        for (int j = 0; j < MAX_ROW; j++) {
            a[i][j] = rand() % 10;
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    for (int i = 1; i < MAX_ROW - 1; i++) {
        for (int j = 1; j < MAX_ROW - 1; j++) {
            sum = SUM(a, i, j);
            result = result < sum ? sum : result;
        }
    }

    printf("%d\n", result);
    return 0;
}