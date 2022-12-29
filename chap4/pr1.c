#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <memory.h>

#define DATA 6174
#define ARR_TO_INT(a) (1000*(a[0]) + 100*(a[1]) + 10*(a[2]) + (a[3]))

int cmpfunc_i(const void* a, const void *b) {
    return ( *(int*)a - *(int*)b );
}

int cmpfunc_d(const void* a, const void *b) {
    return ( *(int*)b - *(int*)a );
}

int main() {
    int num;
    int result = 0;
    int temp[4];
    int num1, num2;
    scanf("%d", &num);

    if (num == DATA) {
        printf("0");
        return 0;
    }

    while(num != DATA) {
        int i;
        memset(temp, -1, sizeof(temp));
        for (i = 0; i < 4; i++) {
            temp[i] = num % 10;
            num /= 10;
        }

        qsort(temp, 4, sizeof(int), cmpfunc_i);
        num1 = ARR_TO_INT(temp);
        qsort(temp, 4, sizeof(int), cmpfunc_d);
        num2 = ARR_TO_INT(temp);

        result++;
        num = num2 - num1;
    }

    printf("%d\n", result);

    return 0;
}