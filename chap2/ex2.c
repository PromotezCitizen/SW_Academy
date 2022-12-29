#include <stdio.h>
#include <math.h>

// 자기복제수 찾기
// 5^2 = 25 => 25 % 10 == 5
// 76^2 = 5776 => 5776 % 100 == 76
int main() {
    int num;
    int num_pow;

    scanf("%d", &num);
    num_pow = (int)pow(num, 2);

    if (num_pow % (int)pow(10, (int)log10(num) + 1) == num) printf("자기복제수임 pow : %d, num : %d\n", num_pow, num);
    else printf("자기복제수 아님 pow : %d, num : %d\n", num_pow, num);
}