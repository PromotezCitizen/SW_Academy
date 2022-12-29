#include <stdio.h>

#define MAX_STACK 5

int stack[MAX_STACK] = {0, };
int idx = 0;

void push(int data) {
    if (idx == MAX_STACK) return;
    stack[idx++] = data;
}

int pop() {
    if (idx == 0) return -1;
    return stack[--idx];
}

int main() {
    for (int i = 0; i < 3; i++) push(i+1);
    for (int i = 0; i < 3; i++) printf("%d ", pop());
    
    printf("\n");
}