#include <stdio.h>

// ������ �� �ڸ� ��
int main() {
    int num;
    int result;
    scanf("%d", &num);

    while(num != 0) {
        result += num % 10;
        num /= 10;
    }

    printf("��� : %d\n", result);
}