#include <stdio.h>
#include <stdlib.h>

#define MAX_ROW 5
#define FALSE 0
#define TRUE 1

int main() {
    int a[MAX_ROW][MAX_ROW];
    int result[(MAX_ROW-2) * (MAX_ROW-2)];
    int idx = 0;
    int flag = 0;

    for (int i = 0; i < MAX_ROW; i++) {
        for (int j = 0; j < MAX_ROW; j++) {
            a[i][j] = rand() % 9 + 1;
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    for (int i = 1; i < MAX_ROW - 1; i++) {
        for (int j = 1; j < MAX_ROW - 1; j++) {
            flag = TRUE;
            for (int k = i-1; k < i+2; k++) {
                for (int l = j-1; l < j+2; l++) {
                    if (i == k && j == l) continue;
                    if (a[i][j] >= a[k][l]) flag = FALSE;
                }
            }
            if (flag) result[idx++] = a[i][j];
        }
    }

    for (int i = 0; i < idx; i++) printf("%d ", result[i]);
    printf("\n");
}