#include <stdio.h>
#include <math.h>

// �ڱ� ���������� �Ǻ�
// 5^2 �� �� �� ���ڸ��� 5�� �ִ°�?
// 76^2 �� �� �� ���ڸ��� 76�� �ִ°�?
int main() {
    int num;
    int num_pow;

    scanf("%d", &num);
    num_pow = (int)pow(num, 2);

    if (num_pow % (int)pow(10, (int)log10(num) + 1) == num) printf("�ڱ⺹���� ���� pow : %d, num : %d\n", num_pow, num);
    else printf("�ڱ⺹���� �ƴ� pow : %d, num : %d\n", num_pow, num);
}