#include <stdio.h>
#include <stdlib.h>

#define MAX_BOOK 10

int cmpfunc(const void* a, const void *b) {
    return ( *(int*)a - *(int*)b );
}

int cmpfunc_d(const void* a, const void *b) {
    return ( *(int*)b - *(int*)a );
}

// 원래는 큐를 이용해야하는데
// 굳?이
int main() {
    int shelf[MAX_BOOK];
    int movebook;
    int tomove, frommove;
    int cnt = 0;
    for (int i = 0; i < MAX_BOOK; i++) 
        scanf("%d", &shelf[i]);
        // shelf[i] = rand() % 10 + 1;

    printf("이동 횟수 입력 >> ");
    scanf("%d", &movebook);

    for (int move = 0; move < movebook; move++) {
        
    }


    // 0인 선반 개수 세기
    qsort(shelf, MAX_BOOK, sizeof(int), cmpfunc);

    for (int i = 0; i < MAX_BOOK; i++) printf("%d ", shelf[i]);
    printf("\n");

    cnt = 0;
    for (int i = 0; i < MAX_BOOK; i++) {
        if (shelf[i] != 0) break;
        cnt++;
    }

    printf("0의 개수는 %d\n", cnt);
    return 0;
}