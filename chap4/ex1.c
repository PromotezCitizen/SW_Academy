
#include <stdio.h>

#define MAX_ARR 10
#define SWAP(x, y, z) ((z) = (x), (x) = (y), (y) = (z))

// selection sort 이용하여 배열 정렬
int main() {
    int a[MAX_ARR];
    int pos, temp;

    for (int i = 0; i < MAX_ARR; i++) scanf("%d", &a[i]);

    for (int i = 0; i < MAX_ARR-1; i++) {
        pos = i;
        for (int j = MAX_ARR-1; j > i; j--) {
            if (a[i] <= a[j]) continue;
            else {
                if (a[j] < a[pos]) pos = j;
            }
        }
        SWAP(a[i], a[pos], temp);

        for (int i = 0; i < MAX_ARR; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
    }

    return 0;

    // 4 1 6 2 8 3 5 7 9 10
}