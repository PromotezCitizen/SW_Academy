#include <stdio.h>
#include <string.h>

#define MAX_ARR 20

int abs(int num) {
    return num < 0 ? -num : num;
}

// °è°î Ã¤¿ì±â
int main() {
    int inputed[MAX_ARR];
    int top[MAX_ARR/2]; // index

    int idx = 0;
    int rising_flag = 0;

    for (int i = 0; i < MAX_ARR; i++) scanf("%d", &inputed[i]);
    memset(top, -1, sizeof(top));

    if (inputed[0] > inputed[1]) top[idx++] = 0;

    for (int i = 0; i < MAX_ARR - 1; i++) {
        if (inputed[i] < inputed[i+1]) rising_flag = 1;
        else if (inputed[i] == inputed[i+1]) continue;
        else {
            if (rising_flag == 1) top[idx++] = i;
            rising_flag = 0;
        }
    }

    if (inputed[MAX_ARR-2] < inputed[MAX_ARR-1]) top[idx++] = MAX_ARR-1;

    int t1 = 0;
    int t2 = 0;
    int min_height = 0;
    int result = 0;
    for (int i = 0; i < MAX_ARR/2; i++) {
        t1 = inputed[top[i]]; t2 = inputed[top[i+1]];
        if (top[i+1] == -1) break;

        min_height = t1 > t2 ? t2 : t1;

        printf("%3d(%3d) %3d(%3d) %3d\n", t1, top[i], t2, top[i+1], min_height);

        for (int j = top[i]+1; j < top[i+1]; j++) {
            result += inputed[j] < min_height ? abs(inputed[j] - min_height) : 0;
        }
    }

    printf("%d\n", result);
    // 2 1 5 2 1 3 3 2 1 0 10 8 4 1 7 6 3 3 4 8
}