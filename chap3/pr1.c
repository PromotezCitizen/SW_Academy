#include <stdio.h>

#define MAX_ARR 20

// ºÀ¿ì¸® Ã£±â
int main() {
    int inputed[MAX_ARR];
    int result = 0;
    int rising_flag = 0;
    int edging_flag = 0;
    // 2 1 5 2 1 3 3 2 1 0 10 8 4 1 7 6 3 3 4 8

    for (int i = 0; i < MAX_ARR; i++) scanf("%d", &inputed[i]);

    if (inputed[0] > inputed[1]) result++;
    if (inputed[MAX_ARR-2] < inputed[MAX_ARR-1]) result++;

    for (int i = 0; i < MAX_ARR - 1; i++) {
        if (inputed[i] < inputed[i+1]) rising_flag = 1;
        else if (inputed[i] == inputed[i+1]) continue;
        else {
            if (rising_flag == 1) result++;
            rising_flag = 0;
        }
    }

    printf("%d\n", result);
}