#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

char* myStrcpy(char* dest, const char* origin, int result_pos[2]) {
    int i = 0;
    for (i = 0; i < result_pos[1]; i++) 
        dest[i] = origin[result_pos[0]+i];
    dest[i] = '\0';
    return dest;
}

// 가장 긴 회문 찾기
// 긴 쪽부터 차례로 찾아가다가 회문 찾으면 바로 break
int main() {
    char str[100];
    // char* str = "ABBACAAABBBBAAACAABBCABBBCCCAAAACCBBAACB";
    scanf("%s", str);

    char* result;

    int input_len = strlen(str);
    int flag = FALSE;
    
    int result_pos[2] = {0, };

    for (int len = input_len; len > 1; len--) {
        for (int start = 0; start + len <= input_len; start++) {
            for (int idx = 0; idx < len / 2; idx++) {
                if (str[start + idx] != str[len + start - idx - 1]) {
                    flag = FALSE;
                    break;
                }
                flag = TRUE;
            }
            if (flag == TRUE) {
                result_pos[0] = start;
                result_pos[1] = len;
                len = -1;
                break;
            }
        }
    }

    result = (char*)malloc(sizeof(char) * result_pos[1] + 1);

    myStrcpy(result, str, result_pos);
    printf("%s\n", result);

    return 0;
}