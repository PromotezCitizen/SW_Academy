#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ARR 100000

int cmpfunc(const void* a, const void* b) {
    return (*(double*)(b) - *(double*)(a)) * 100;
}


int main() {
    double a[MAX_ARR] = {0, };
    int count[101] = {0, };
    int t = 0, idx = 0;
    double hwakyul = 0;

    for (int i = 0; i < MAX_ARR; i++) a[i] = ((double)rand() / RAND_MAX);

    for (int i = 0; i < MAX_ARR; i++) count[(int)(a[i]*100)]++;




    for (int i = 0; i < 101; i++) t = count[t] < count[i] ? i : t;
    for (int i = 0; i < t; i++) idx += count[i];
    idx += 1;
    hwakyul = a[idx];

    qsort(a, MAX_ARR, sizeof(double), cmpfunc);
    // for (int i = 0; i < MAX_ARR; i++) {
    //     if (i % 16 == 0) printf("\n");
    //     printf("%0.2f ", a[i]);
    // }
    printf("%0.2f\n", hwakyul);
    return 0;
}