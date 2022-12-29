#include <stdio.h>
#include <math.h>

void m_itoa(char* dest, int num) {
    int numlen = (int)log10(num) + 1;
    dest[numlen] = '\0';

    for (int i = numlen-1; i >= 0; i--) {
        dest[i] = num%10 + '0';
        num /= 10;
    }
}

// itoa 구현
int main() {
    char dest[100];
    int num;

    scanf("%d", &num);
    m_itoa(dest, num);
    printf("%s\n", dest);

    return 0;
}