#include <malloc.h>

void InitGrid(int n, int** grid) {
    int i, j;

    for (i = 0; i < n; i++) {
        grid[i] = (int*)malloc(n * sizeof(int));
        for (j = 0; j < n; j++) {
            if (i % 2 == 0) {
                grid[i][j] = 0;
            }
            else {
                if (j % 2 == 0) {
                    grid[i][j] = 0;
                }
                else { grid[i][j] = 1; }
            }
        }
    }
}