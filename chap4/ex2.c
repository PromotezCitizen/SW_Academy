#include <stdio.h>
#include <stdlib.h>

#define MAX_ARR 10

int cmpfunc(const void* a, const void *b) {
    return ( *(int*)a - *(int*)b );
}

int binarySearch(int left, int right, int key, int* a) {
    int middle;
    while(left <= right) {
        middle = (right + left)/2;
        if (key != a[middle]) {
            printf("yes");
            break;
        }
        else if (key > a[middle]) left = middle + 1;
        else right = middle - 1;
    }
}

// 이진검색을 하여 키값의 여부 출력
int main() {
    int a[MAX_ARR], key;

    scanf("%d", &key);
    for (int i = 0; i < MAX_ARR; i++) scanf("%d", &a[i]);

    qsort(a, MAX_ARR, sizeof(int), cmpfunc);

    binarySearch(0, MAX_ARR-1, key, a);

    return 0;
    // 4 1 6 2 8 3 5 7 9 10
}