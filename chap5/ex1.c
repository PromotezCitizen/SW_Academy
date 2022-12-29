#include <stdio.h>
#include <stdlib.h>

#define MAX_ROW 5

// 한줄 최대값
int main() {
    int a[MAX_ROW][MAX_ROW];
    int result = 0, temp1, temp2;

    for (int i = 0; i < MAX_ROW; i++) {
        for (int j = 0; j < MAX_ROW; j++) {
            a[i][j] = rand() % 10;
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < MAX_ROW; i++) {
        temp1 = 0; temp2 = 0;
        for (int j = 0; j < MAX_ROW; j++) {
            temp1 += a[i][j];
            temp2 += a[j][i];
        }
        temp1 = temp1 < temp2 ? temp2 : temp1;
        result = result < temp1 ? temp1 : result;
    }

    temp1 = 0; temp2 = 0;
    for (int i = 0; i < MAX_ROW; i++) {
        temp1 += a[i][i];
        temp2 += a[i][MAX_ROW-1-i];
    }
    temp1 = temp1 < temp2 ? temp2 : temp1;
    result = result < temp1 ? temp1 : result;



    printf("%d\n", result);

    return 0;
}