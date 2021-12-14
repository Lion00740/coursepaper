#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <locale.h>
#include "GenerMaze.h"
#include "UploadFiles.h"

using namespace std;

int main() {
    int type;

    setlocale(LC_ALL, "RU");
    
    cout << "Загрузить лабиринт или сгенерировать? (загрузить-1, сгенерировать-2)" << endl;
    do {
        cin >> type;
        if (type != 1 && type != 2) {
            cout << "Введите правильное значение" << endl;
        }
    } while (type != 1 && type != 2);

    if (type == 2) {
        GenerMaze(); // Генерирует лабиринт (по инициализированной сетке)        
    }
    else {
        UploadFiles(); // Считывает лабиринт с файла и выводит его в консоль
    }

    return 0;
}