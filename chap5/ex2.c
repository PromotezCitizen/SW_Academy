#include <stdio.h>
#include <stdlib.h>

#define MAX_ROW 5

// 3 * 3 최대값 

int main() {
    int a[MAX_ROW][MAX_ROW];
    int result = 0, temp;

    for (int i = 0; i < MAX_ROW; i++) {
        for (int j = 0; j < MAX_ROW; j++) {
            a[i][j] = rand() % 10;
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < MAX_ROW-2; i++) {
        for (int j = 0; j < MAX_ROW-2; j++) {
            temp = 0;
            for (int k = i; k < i+3; k++) {
                for (int l = j; l < j+3; l++) temp += a[k][l];
            }
            result = result < temp ? temp : result;
        }
    }

    printf("%d\n", result);
}