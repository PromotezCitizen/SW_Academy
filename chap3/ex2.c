#include <stdio.h>
#include <string.h>

#define MAX_ARR 20

// 가장 긴 오름차순 숫자열 출력
int main() {
    int inputed[MAX_ARR];
    int start_pos[MAX_ARR];
    int end_pos[MAX_ARR];
    int start;
    int pos = 0;

    for (int i = 0; i < MAX_ARR; i++) scanf("%d", &inputed[i]);

    memset(start_pos, -1, sizeof(int) * MAX_ARR);
    memset(end_pos, -1, sizeof(int) * MAX_ARR);

    start = inputed[0];
    start_pos[0] = 0;
    end_pos[0] = 0;
    
    for (int i = 1; i < MAX_ARR; i++) {
        if (start < inputed[i]) {
            end_pos[pos] = i;
        }
        else {
            start_pos[++pos] = i;
            end_pos[pos] = i;
        }
        start = inputed[i];
    }

    int s = 0;
    int idx = 0;
    int i = 0;
    while (start_pos[i] != -1) {
        s = s > (end_pos[i] - start_pos[i]) ? s : (end_pos[i] - start_pos[i]);
        idx = s > (end_pos[i] - start_pos[i]) ? idx : i;
        i++;
    }
    
    for (int i = start_pos[idx]; i < end_pos[idx] + 1; i++) printf("%d ", inputed[i]);
    printf("\n");

    return 0;
}