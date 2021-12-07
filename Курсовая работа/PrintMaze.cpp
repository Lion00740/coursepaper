#include <iostream>

using namespace std;

void PrintMaze(int** mass, int n) {
    int i, j;

    /*for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cout << mass[i][j] << " ";
        }
        cout << endl;
    }*/
    cout << endl;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (mass[i][j] == 0) { cout << " *"; }
            else { cout << "  "; }
        }
        cout << endl;
    }
}