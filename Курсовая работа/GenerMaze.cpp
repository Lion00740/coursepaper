#include <time.h>
#include <iostream>

int input;

void GenerMaze(int n, int** maze) {
    int i, j;
    srand(time(NULL));

    for (i = 1; i < n; i += 2) {
        for (j = 1; j < n; j += 2) {
            if (rand() % 2 == 0) {
                if (j != n - 2) {
                    maze[i][j + 1] = 1;
                }
                else {
                    maze[i - 1][j] = 1;
                }
            }
            else {
                if (i > 1) { maze[i - 1][j] = 1; }
                else {
                    if (j != n - 2) {
                        maze[i][j + 1] = 1;
                    }
                    else {
                        maze[i - 1][j] = 1;
                    }
                }
            }
        }
    }

    maze[0][n - 2] = 0;
    if (rand() % 2 == 0) {
        int ran = rand() % n;
        while (ran % 2 == 0) {
            ran = rand() % n;
        }
        maze[0][ran] = 1; // вход сверху
        input = ran;

        ran = rand() % n;
        while (ran % 2 == 0) {
            ran = rand() % n;
        }
        maze[n - 1][ran] = 1; //выход снизу
    }
    else {
        int ran = rand() % n;
        while (ran % 2 == 0) {
            ran = rand() % n;
        }
        maze[ran][n - 1] = 1; // вход справа
        input = ran;

        ran = rand() % n;
        while (ran % 2 == 0) {
            ran = rand() % n;
        }
        maze[ran][0] = 1; // выход слева
    }
}