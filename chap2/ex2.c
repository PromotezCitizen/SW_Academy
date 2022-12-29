#include <stdio.h>
#include <math.h>

// 자기 복제수인지 판별
// 5^2 일 때 맨 뒷자리에 5가 있는가?
// 76^2 일 때 맨 뒷자리에 76이 있는가?
int main() {
    int num;
    int num_pow;

    scanf("%d", &num);
    num_pow = (int)pow(num, 2);

    if (num_pow % (int)pow(10, (int)log10(num) + 1) == num) printf("자기복제수 맞음 pow : %d, num : %d\n", num_pow, num);
    else printf("자기복제수 아님 pow : %d, num : %d\n", num_pow, num);
}