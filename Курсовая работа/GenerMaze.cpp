#include <time.h>
#include <iostream>
#include "InitGrid.h"
#include "PrintMazeFiles.h"
#include "Graph.h"
#include "DFS.h"

using namespace std;

void GenerMaze() {
    int i, j, ** maze, n, input, output, *vis, *parent, **G, ran, SizeG;
    srand(time(NULL));

    cout << "Введите размер лабиринта" << endl;
    cin >> n;
    n = 2 * n + 1;

    maze = (int**)malloc(sizeof(int) * n);
    InitGrid(n, maze); // Инициализирует сетку (n - количество клеток сетки)

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
        ran = rand() % n;
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
        output = n * (n - 1) + ran;
    }
    else {
        ran = rand() % n;
        while (ran % 2 == 0) {
            ran = rand() % n;
        }
        maze[ran][n - 1] = 1; // вход справа
        input = n * (ran + 1) - 1;

        ran = rand() % n;
        while (ran % 2 == 0) {
            ran = rand() % n;
        }
        maze[ran][0] = 1; // выход слева
        output = n * ran;
    }

    PrintMazeFiles(maze, n, input, output); // Выводит на экран лабиринт и сохраняет его в файл

    G = Graph(n, maze);

    SizeG = n * n;

    vis = (int*)malloc(SizeG * sizeof(int));
    mass(SizeG, vis);

    parent = (int*)malloc(SizeG * sizeof(int));
    mass(SizeG, parent);

    DFS(n, input, vis, G, parent, output, maze);
}