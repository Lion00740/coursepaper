#include <iostream>
#include <malloc.h>
#include <locale.h>
#include "PrintMaze.h"
#include "InitGrid.h"
#include "GenerMaze.h"

using namespace std;

void DFS(int n, int num, int* vis, int** G, int* parent) {
    int i;
    vis[num] = 1;

    for (i = 0; i < n; i++) {
        if (G[num][i] == 1 && vis[i] == 0) {
            parent[i] = num;
            cout << i << " ";
            DFS(n, i, vis, G, parent);
        }
    }

    for (i = 0; i < n; i++) {
        if (vis[i] == 0) { // работает только для массива, в котором нет не соединенных вершин
            num = parent[num];
            DFS(n, num, vis, G, parent);
        }
    }
}

int main() {
    int n, **maze, SizeGrid, type;
    setlocale(LC_ALL, "RU");
    
    cout << "Загрузить лабиринт или сгенерировать? (загрузить-1, сгенерировать-2)" << endl;
    cin >> type;

    if (type == 2) {
        cout << "Введите размер лабиринта" << endl;
        cin >> n;
        SizeGrid = 2 * n + 1;

        maze = (int**)malloc(sizeof(int) * SizeGrid);
        InitGrid(SizeGrid, maze); // Инициализирует сетку (SizeGrid - количество клеток сетки)
        //PrintMaze(maze, SizeGrid); // Выводит на экран сетку

        GenerMaze(SizeGrid, maze); // Генерирует лабиринт (по инициализированной сетке)
        PrintMaze(maze, SizeGrid); // Выводит на экран лабиринт
        return 0;
    }
}