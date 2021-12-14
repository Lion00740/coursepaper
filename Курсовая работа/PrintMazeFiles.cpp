#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

void PrintMazeFiles(int** mass, int n, int input, int output) {
    int i, j;
    char filename[25];
    FILE* file;

    cout << "Введите имя файла для того чтобы сохранить лабиринт" << endl;
    do
    {
        cin >> filename;
        file = fopen(filename, "w");
        if (file == NULL)
        {
            cout << "Имя файла не соответствует регламенту" << endl;
        }
    } while (file == NULL);

    cout << endl;

    fprintf(file, "%d ", n);
    fprintf(file, "%d ", input);
    fprintf(file, "%d ", output);
    fprintf(file, "\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (mass[i][j] == 0) { cout << " *"; }
            else { cout << "  "; }
            fprintf(file, "%d ", mass[i][j]);
        }
        cout << endl;
        fprintf(file, "\n");
    }

    fclose(file);
}