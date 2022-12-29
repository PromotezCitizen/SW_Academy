#include <stdio.h>

#define MAX_QUEUE 10

int queue[MAX_QUEUE];
int idx = 0;
int start = 0;

void enqueue(int data) {
    if (idx == MAX_QUEUE-1) return;
    queue[idx++] = data;
}

int dequeue() {
    if (start == MAX_QUEUE-1) return -1;
    return queue[start++];
}

// Å¥ ±¸Çö
int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);

    printf("%d ", dequeue());
    printf("%d ", dequeue());
    printf("%d\n", dequeue());

    return 0;
}