#include <stdio.h>
#define MAX_ARR 1000

// 1 ~ 1000�� �������� 1�� ������?
int main() {
    int a[MAX_ARR] = {0,};
    int result = 0;
    for (int i = 0; i < MAX_ARR; i++) a[i] = i+1;

    for (int i = 0; i < MAX_ARR; i++) {
        while(a[i] != 0) {
            if (a[i] % 10 == 1)  result += 1;
            a[i] /= 10;
        }
    }

    printf("��� : %d��\n", result);
}