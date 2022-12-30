#include <stdio.h>

#define MAX_STACK 100

char stack[MAX_STACK];
int idx_stack = 0;

int paran[MAX_STACK] = {0, };
int idx_paran = 0;


void push(int data) {
    paran[idx_paran++] = data;
}

int pop() {
    return paran[--idx_paran];
}

// 괄호열 계산
// () : 2
// [] : 3
// (X) : X*2
// [X] : X*3
// ()[] : 2+3

void calcPop(int facter) {
    int push_data = 0;
    int data;
    while ((data = pop()) != 1) {
        push_data += data;
    }
    push_data = push_data == 0 ? 1 : push_data;
    push(push_data*facter);
}

int main() {
    char* str = "(()[[]])([]))";

    int idx = 0;
    int result = 0;

    int data;
    int push_data = 0;

    int temp = 0;


    while (str[idx] != '\0') {
        if (str[idx] == '(') {
            stack[idx_stack++] = '(';
            push(1);
        }
        else if (str[idx] == '[') {
            stack[idx_stack++] = '[';
            push(1);
        }
        else if (str[idx] == ')') {
            if (stack[--idx_stack] == '[') {
                result = 0;
                break;
            }
            
            calcPop(2);
        }
        else {
            if (stack[--idx_stack] == '(') {
                result = 0;
                break;
            }

            calcPop(3);
        }

        idx++;
    }

    if (idx_stack == 0) {
        while(idx_paran != 0) result += pop();
    }
    else result = 0;
    
    printf("%d\n", result);

    return 0;
}