#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int **Graph(int n, int **maze) {
    int** G, i, j;
	int SizeG = n * n;

	G = (int**)malloc(sizeof(int) * SizeG);
    for (i = 0; i < SizeG; i++) {
        G[i] = (int*)malloc(SizeG * sizeof(int));
        for (j = 0; j < SizeG; j++) {
            G[i][j] = 0;
        }
    }

    for (i = 1; i < n - 1; i++) {
        for (j = 1; j < n - 1; j++) {
            if (maze[i][j] == 1) {
                if (maze[i - 1][j] == 1) {
                    G[i * n + j][i * n + j - n] = 1;
                    G[i * n + j - n][i * n + j] = 1;
                }
                if (maze[i + 1][j] == 1) {
                    G[i * n + j][i * n + j + n] = 1;
                    G[i * n + j + n][i * n + j] = 1;
                }
                if (maze[i][j - 1] == 1) {
                    G[i * n + j][i * n + j - 1] = 1;
                    G[i * n + j - 1][i * n + j] = 1;
                }
                if (maze[i][j + 1] == 1) {
                    G[i * n + j][i * n + j + 1] = 1;
                    G[i * n + j + 1][i * n + j] = 1;
                }
            }
        }
    }
    return G;
}