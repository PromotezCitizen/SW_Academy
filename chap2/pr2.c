#include <stdio.h>
#include <stdlib.h>

#define MAX_ARR 6

int cmpfunc_i(const void* a, const void *b) {
    return ( *(int*)a - *(int*)b );
}

int cmpfunc_d(const void* a, const void *b) {
    return ( *(int*)b - *(int*)a);
}

void printArr(const int* a) {
    for (int i = 0; i < MAX_ARR; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// baby-gin 게임
// 카드가 run이거나 트리플인 2쌍

int main() {
    int a[MAX_ARR];
    int calc = 0;
    for (int i = 0; i < MAX_ARR; i++) scanf("%d", &a[i]);

    // 1. triple 찾자
    for (int z = 0; z < 2; z++) {
        qsort(a, MAX_ARR, sizeof(int), cmpfunc_i);
        int pos = 0;
        int cur = a[0];
        int cnt = 1;
        for (int i = 1; i < MAX_ARR; i++) {
            if (a[i] == cur) {
                if (++cnt == 3) break;
            }
            else {
                cur = a[i];
                pos = i;
                cnt = 1;
            }
        }
        if (cnt == 3) {
            for (int i = pos; i < pos+3; i++) a[i] += 100+i*2;
            calc++;
        }
    }

    // 2. run 찾자
    for (int z = calc; z < 2; z++) {
        qsort(a, MAX_ARR, sizeof(int), cmpfunc_i);
        for (int i = 0; i < MAX_ARR-2; i++){
            for (int j = i+1; j < MAX_ARR-1; j++) {
                for (int k = j+1; k < MAX_ARR; k++) {
                    if (abs(a[i] - a[j]) * abs(a[j] - a[k]) == 1) { // i와 j의 차이가 1이고 j와 k의 차이가 1일때
                        a[i] = a[i] * 2 + 1000;
                        a[j] = a[j] * 2 + 1000;
                        a[k] = a[k] * 2 + 1000;
                        calc++;

                        i = MAX_ARR; j = MAX_ARR; k = MAX_ARR; // escape nested for-loop
                    }
                }
            }
        }
    }

    if (calc == 2) printf("gin\n");
    else printf("lose\n");
}