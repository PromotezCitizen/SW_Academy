#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARR 20

void printResult(const int* a) {
    for (int i = 0; i < MAX_ARR; i++) {
        if (*(a + i) != -1) printf("%d ", *(a + i));
    }
}

// 양의 정수 20개 입력될때 최초의 오름차순 숫자열 출력
int main() {
    int inputed[MAX_ARR];
    int result[MAX_ARR];

    for (int i = 0; i < MAX_ARR; i++) scanf("%d", &inputed[i]);

    memset(result, -1, sizeof(int) * MAX_ARR);

    int start = inputed[0];
    int pos = 0;
    int isFind = 0;
    result[pos] = start;
    for (int i = 1; i < MAX_ARR; i++) {
        if (start < inputed[i]) {
            result[++pos] = inputed[i];
            start = inputed[i];
            isFind = 1;
        }
        else {
            if (isFind == 1) break;
            pos = 0;
            start = inputed[i];
            result[pos] = start;
        }
    }
    // 89 76 14 15 35 68 90 78 2 15 25 35 49 87 32 21 54 3 5 90
    printResult(result);
}