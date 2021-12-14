#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "PrintMazeConsole.h"
#include "Graph.h"
#include "DFS.h"

using namespace std;

void UploadFiles() {
	int n, **maze, **G, SizeG, *vis, *parent, input, output;
	char filename[25];
	FILE* file;

	cout << "Введите имя файла для того чтобы загрузить лабиринт" << endl;
	do
	{
		cin >> filename;
		file = fopen(filename, "r");
		if (file == NULL)
		{
			cout << "Имя файла не соответствует регламенту" << endl;
		}
	} while (file == NULL);
	
	fscanf(file, "%d ", &n);
	fscanf(file, "%d ", &input);
	fscanf(file, "%d ", &output);

	maze = (int**)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		maze[i] = (int*)malloc(sizeof(int) * n);
		for (int j = 0; j < n; j++) {
			fscanf(file, "%d", &maze[i][j]);
		}
	}
	fclose(file);

	PrintMazeConsole(maze, n);

	G = Graph(n, maze);

	SizeG = n * n;

	vis = (int*)malloc(SizeG * sizeof(int));
	mass(SizeG, vis);

	parent = (int*)malloc(SizeG * sizeof(int));
	mass(SizeG, parent);

	DFS(n, input, vis, G, parent, output, maze);
}