#include <stdio.h>

#define MAX_STACK 100

char stack[MAX_STACK];
int idx_stack = 0;

// °ýÈ£¿­ °è»ê
// () : 2
// [] : 3
// (X) : X*2
// [X] : X*3
// ()[] : 2+3

int main() {
    char* str = "(())";
    char* str1 = "([)]";

    int idx = 0;
    int result = 0;

    int sum[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int idx_sum = 0;

    while (str[idx] != '\0') {
        if (str[idx] == '(') {
            stack[idx_stack++] = str[idx];
        }
        else if (str[idx] == '[') {
            stack[idx_stack++] = str[idx];
        }
        else if (str[idx] == ')') {
            if (stack[--idx_stack] == ']') {
                result = 0;
                break;
            }


        }
        else {
            if (stack[--idx_stack] == ')') {
                result = 0;
                break;
            }


        }

        idx++;
    }

    printf("%d\n", result);

    return 0;
}