#include <stdio.h>

// 숫자의 각 자리 합
int main() {
    int num;
    int result;
    scanf("%d", &num);

    while(num != 0) {
        result += num % 10;
        num /= 10;
    }

    printf("결과 : %d\n", result);
}