#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <locale.h>
#include "GenerMaze.h"
#include "UploadFiles.h"

using namespace std;

int main() {
    int type;

    setlocale(LC_ALL, "RU");
    
    cout << "��������� �������� ��� �������������? (���������-1, �������������-2)" << endl;
    do {
        cin >> type;
        if (type != 1 && type != 2) {
            cout << "������� ���������� ��������" << endl;
        }
    } while (type != 1 && type != 2);

    if (type == 2) {
        GenerMaze(); // ���������� �������� (�� ������������������ �����)        
    }
    else {
        UploadFiles(); // ��������� �������� � ����� � ������� ��� � �������
    }

    return 0;
}