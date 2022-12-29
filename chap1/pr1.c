#include <stdio.h>

#define MAX_ROW 10

struct edge {
    int x;
    int y;
};

struct edge line[100][2];
int iter = 0;

void printLines() {
    for (int i = 0; i < 100; i++) {
        printf("start : %d %d, end : %d %d\n", line[i][0].x, line[i][0].y, line[i][1].x, line[i][1].y);
    }
}

void detectLines_r(const int* a) {
    int start = 0;
    int end = 0;
    int t = 0;
    for (int r = 0; r < MAX_ROW; r++) {
        for (int c = 0; c < MAX_ROW; c++) {
            if (*(a + r*MAX_ROW + c) == 1) {
                if (c == MAX_ROW - 1 && t > 1) {
                    line[iter][1].x = r;
                    line[iter++][1].y = c;
                    t = 0;
                    continue;
                }
                if (t == 0) {
                    line[iter][0].x = r;
                    line[iter][0].y = c;
                }
                t++;
            }
            else {
                if (t > 1) {
                    line[iter][1].x = r;
                    line[iter++][1].y = c-1;
                }
                t = 0;
            }
        }
    }
}

void detectLines_c(const int* a) {
    int start = 0;
    int end = 0;
    int t = 0;
    for (int c = 0; c < MAX_ROW; c++) {
        for (int r = 0; r < MAX_ROW; r++) {
            if (*(a + r*MAX_ROW + c) == 1) {
                if (c == MAX_ROW - 1 && t > 1) {
                    line[iter][1].x = r;
                    line[iter++][1].y = c;
                    t = 0;
                    continue;
                }
                if (t == 0) {
                    line[iter][0].x = r;
                    line[iter][0].y = c;
                }
                t++;
            }
            else {
                if (t > 1) {
                    line[iter][1].x = r;
                    line[iter++][1].y = c;
                }
                t = 0;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    int a[MAX_ROW * MAX_ROW] = {
        1, 1, 1, 0, 0, 0, 0, 1, 1, 1,
        1, 0, 1, 0, 1, 1, 0, 1, 0, 1,
        1, 1, 1, 0, 1, 1, 0, 1, 0, 1,
        0, 0, 0, 0, 0, 0, 0, 1, 0, 1,
        0, 0, 1, 1, 1, 1, 0, 1, 0, 1,
        0, 0, 1, 0, 0, 0, 0, 1, 1, 1,
        0, 0, 1, 1, 1, 1, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 1, 1, 1, 0, 0, 0,
        0, 0, 0, 0, 1, 1, 1, 0, 0, 0
    };

    detectLines_r(a);
    detectLines_c(a);

    printLines();
}