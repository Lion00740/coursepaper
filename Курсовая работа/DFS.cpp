#include <iostream>
#include <Windows.h>

using namespace std;

void mass(int n, int *mass) {
    for (int i = 0; i < n; i++) {
        mass[i] = 0;
    }
}

int DFS(int n, int num, int* vis, int** G, int* parent, int output, int** maze) {
    int i, j, SizeG = n * n;
    vis[num] = 1;

    maze[num / n][num % n] = 2;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (maze[i][j] == 0) { cout << " *"; }
            if (maze[i][j] == 1) { cout << "  "; }
            if (maze[i][j] == 2) { cout << " +"; } 
        }
        cout << endl;
    }
    
    cout << endl;
    Sleep(500);
    system("cls");
    maze[num / n][num % n] = 1;

    for (i = 0; i < SizeG; i++) {
        if (G[num][i] == 1 && vis[i] == 0 && vis[output] == 0) {
            parent[i] = num;
            DFS(n, i, vis, G, parent, output, maze);
        }
    }

    for (i = 0; i < SizeG; i++) {
        if (vis[output] == 0) {
            num = parent[num];
            DFS(n, num, vis, G, parent, output, maze);
        }
    }
    return 0;
}