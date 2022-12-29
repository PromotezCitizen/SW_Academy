#include <stdio.h>

#define MAX_STACK 5

int stack[MAX_STACK] = {0, };
int idx = 0;

void push(int data) {
    stack[idx++] = data;
}

int pop() {
    return stack[--idx];
}

int stack1() { 
    int t = 1;
    int data = 0;
    push(t++);
    push(t++);
    push(t++);
    data += 100*pop();
    data += 10*pop();
    data += pop();
    return data;
}

int stack2() {
    int t = 1;
    int data = 0;
    push(t++);
    push(t++);
    data += 100*pop();
    push(t++);
    data += 10*pop();
    data += pop();
    return data;
}

int stack3() {
    int t = 1;
    int data = 0;
    push(t++);
    push(t++);
    data += 100*pop();
    data += 10*pop();
    push(t++);
    data += pop();
    return data;
}

int stack4() {
    int t = 1;
    int data = 0;
    push(t++);
    data += 100*pop();
    push(t++);
    push(t++);
    data += 10*pop();
    data += pop();
    return data;
}

int stack5() {
    int t = 1;
    int data = 0;
    push(t++);
    data += 100*pop();
    push(t++);
    data += 10*pop();
    push(t++);
    data += pop();
    return data;
}

int main() {
    // int origin_arr[3];
    int datas[5];
    int t = 0;

    // for (int i = 0; i < sizeof(origin_arr) / sizeof(int); i++) scanf("%d", &origin_arr[i]);

    // push push push pop pop pop
    // push push pop push pop pop
    // push push pop pop push pop
    // push pop push push pop pop
    // push pop push pop push pop

    datas[t++] = stack1();
    datas[t++] = stack2();
    datas[t++] = stack3();
    datas[t++] = stack4();
    datas[t++] = stack5();

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", datas[i] % 10);
            datas[i] /= 10;
        }
        printf("\n");
    }
    
}