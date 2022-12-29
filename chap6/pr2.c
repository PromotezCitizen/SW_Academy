#include <stdio.h>

#define MAX_MAP 7
#define FALSE 0
#define TRUE 1

int map[MAX_MAP][MAX_MAP] = {
    {0, 0, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 1, 1, 1},
    {1, 0, 1, 0, 0, 0, 0},
    {1, 0, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0}
};
int visited[MAX_MAP][MAX_MAP] = {
    {0, },
    {0, },
    {0, },
    {0, },
    {0, },
    {0, },
    {0, }
};
int result = FALSE;

void stack(int r, int c) {
    if (result) return;
    if (visited[r][c] == 1) return;
    if (r == 6 && c == 6) {
        result = TRUE;
        return;
    }

    visited[r][c] = 1;

    if (c+1 != 7 && map[r][c+1] == 0) stack(r, c+1);
    if (r+1 != 7 && map[r+1][c] == 0) stack(r+1, c);
    if (c-1 != -1 && map[r][c-1] == 0) stack(r, c-1);
    if (r-1 != -1 && map[r-1][c] == 0) stack(r-1, c);
}


int main() {
    stack(0, 0);
    printf("%s\n", result == TRUE ? "yes" : "no");
}