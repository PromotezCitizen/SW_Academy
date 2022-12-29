#include <stdio.h>
#include <stdlib.h>

// 1 ~ 100������ ���� 10�� �� 2������ ���� ����?

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

    printf("�Է� : ");
    printArr(a, sizeof(a)/sizeof(int));
    qsort(a, sizeof(a)/sizeof(int), sizeof(int), cmpfunc);
    printf("��� : %d\n", a[1]);

    return 0;
}