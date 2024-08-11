#include <iostream>
#include <cstdio>
#include <cstdlib>
int** alloc2DInt1(int rows, int cols)
{
	if (rows <= 0 || cols <= 0) return NULL;

	int** mat = new int* [rows];
	for (int i = 0; i < rows; i++)
		mat[i] = new int[cols];
	return mat;
}

int** alloc2DInt2(int rows, int cols)
{
	if (rows <= 0 || cols <= 0) return NULL;

	int** mat = new int* [rows];
	mat[0] = new int[cols * rows];
	for (int i = 1; i < rows; i++)
		mat[i] = mat[i - 1] + cols;
	return mat;
}

int** alloc2DInt(int rows, int cols)
{
	if (rows <= 0 || cols <= 0) return NULL;

	int size = sizeof(int*) * rows + sizeof(int) * rows * cols;
	char* data = new char[size];

	int** mat = (int**)data;
	data = data + sizeof(int*) * rows;
	for (int i = 0; i < rows; i++)
		mat[i] = (int*)(data + i * sizeof(int));
	return mat;
}

void free2DInt1(int** mat, int rows, int cols = 0)
{
	if (mat != NULL)
	{
		for (int i = 0; i < rows; i++)
			delete[] mat[i];
		delete[] mat;
	}
}

void free2Dint2(int** mat, int rows, int cols = 0)
{
	if (mat != NULL)
	{
		delete[] mat[0];
		delete[] mat;
	}
}

void free2DInt(int** mat, int rows, int cols = 0)
{
	if (mat != NULL)
		delete[] mat;
}

void set2DRandom(int** mat, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			mat[i][j] = rand() % 100;
	}
}

void print2DInt(int** mat, int rows, int cols)
{
	printf("행의수 = %d, 열의 수 = %d\n", rows, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			printf("%4d", mat[i][j]);
		printf("\n");
	}
}

void main()
{
	int** mat;
	int rows, cols;

	printf("행과 열의 크기를 입력하시오 : ");
	scanf_s("%d%d", &rows, &cols);
	mat = alloc2DInt(rows, cols);
	set2DRandom(mat, rows, cols);
	print2DInt(mat, rows, cols);
	free2DInt(mat, rows, cols);
}
