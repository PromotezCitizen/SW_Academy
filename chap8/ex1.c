#include <stdio.h>

int m_strlen(const char* str) {
    int idx = 0;
    while(str[idx++] != '\0') idx++;
    return idx;
}

void m_strcpy(char* dest, const char* origin) {
    int i;
    for (i = 0; i < m_strlen(origin); i++)
        dest[i] = origin[i];
    dest[i] = '\0';
}

// strcpy ±¸Çö
int main() {
    char origin[] = "testing msg";
    char dest[100];

    m_strcpy(dest, origin);

    printf("%s\n", dest);
}