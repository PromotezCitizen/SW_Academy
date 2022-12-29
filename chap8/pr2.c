#include <stdio.h>

#define MAX_STR 6
#define MAX_ROW 6
#define MAX_COL 8

char arr[MAX_ROW][MAX_COL];
char alpha_splited[MAX_ROW * MAX_COL];
char inputed[MAX_STR][100];

int alpha[26] = {0, };

void splitStr(const char* str) {
    int idx = 0;
    while(str[idx++] != '\0') alpha[str[idx-1]-'a']++;
}

// 문자열 2차원 배열에 나선형으로 정렬
int main() {
    for (int i = 0; i < MAX_STR; i++) scanf("%s", inputed[i]);

    for (int i = 0; i < MAX_STR; i++) splitStr(inputed[i]);

    int idx = 0;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < alpha[i]; j++) {
            alpha_splited[idx++] = i+'a';
            if (idx == MAX_ROW * MAX_COL) goto break_nested_for;
        }
    }
break_nested_for:

    for (; idx < MAX_ROW * MAX_COL; idx++) {
        alpha_splited[idx] = '-';
    }

    idx = 0;
    int r, c;
    int row = 0;
    for (int loop = 0; loop < MAX_ROW; loop++) {
        if (loop % 2 == 1) {
            for (c = MAX_COL - (int)(loop/2) - 1; c > (int)(loop/2)-1; c--) {
                arr[MAX_ROW - (int)(loop/2) - 1][c] = alpha_splited[idx++];
            }
            for (r = MAX_ROW - (int)(loop/2) - 2; r > (int)(loop/2); r--) {
                arr[r][c+1] = alpha_splited[idx++];
            }
            row = loop;
        }
        else {
            for (c = (int)(loop/2); c < MAX_COL - (int)(loop/2); c++) {
                arr[(int)(loop/2)][c] = alpha_splited[idx++];
            }
            for (r = (int)(loop/2) + 1; r < MAX_ROW - (int)(loop/2) - 1; r++) {
                arr[r][c-1] = alpha_splited[idx++];
            }
            row = MAX_ROW - loop - 1;
        }
    }

    for (r = 0; r < MAX_ROW; r++) {
        for (c = 0; c < MAX_COL; c++) printf("%2c ", arr[r][c]);
        printf("\n");
    }

}