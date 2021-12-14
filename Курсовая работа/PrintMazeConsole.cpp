#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

void PrintMazeConsole(int** mass, int n) {
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (mass[i][j] == 0) { cout << " *"; }
            else { cout << "  "; }
        }
        cout << endl;
    }
}