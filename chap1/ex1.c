#include <stdio.h>
#include <stdlib.h>

// 1 ~ 100까지의 숫자 10개 중 2번쨰로 작은 값은?

int cmpfunc(const void* a, const void *b) {
    return ( *(int*)a - *(int*)b );
}

void printArr(const int* a, const int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main(int argc, char* argv[]) {
    int a[10];

    for (int i = 0; i < 10; i++) {
        a[i] = rand() % 100;
    }

    printf("입력 : ");
    printArr(a, sizeof(a)/sizeof(int));
    qsort(a, sizeof(a)/sizeof(int), sizeof(int), cmpfunc);
    printf("결과 : %d\n", a[1]);

    return 0;
}