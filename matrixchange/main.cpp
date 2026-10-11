#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <ctime>
#include <cmath>

#define GET_INTEGER(text, number) {\
	std::cout << text;\
	while (!(std::cin >> number)) {\
		std::cin.clear();\
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');\
		std::cout << "\nПожалуйста, введите целое число!" << std::endl;\
		std::cout << text;\
	}\
}

#define DRAW_MATRIX(matrix, width, height) {\
	for (int i = 0; i < height; ++i) {\
		for (int j = 0; j < width; ++j)\
			std::cout << matrix[i][j] << '\t';\
		std::cout << std::endl;\
	}\
}

int main(int argc, char** argv) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::srand(std::time(nullptr));

	int height, width;
	while (true) {
		GET_INTEGER("Введите количество столбцов в матрице: ", width);

		if (width > 0)
			break;
		
		std::cout << "\nКоличество столбцов должно быть больше 0!" << std::endl;
	}

	while (true) {
		GET_INTEGER("Введите количество строк в матрице: ", height);

		if (height > 0)
			break;
		
		std::cout << "\nКоличество строк должно быть больше 0!" << std::endl;
	}

	int** matrix = new int*[height];
	for (int i = 0; i < height; ++i) {
		matrix[i] = new int[width];
		for (int j = 0; j < width; ++j)
			matrix[i][j] = rand() % (width * height) + 1;
	}

	std::cout << "\nСгенерированная матрица:" << std::endl;

	DRAW_MATRIX(matrix, width, height);

	for (int i = 1; i < width - 1; i += 2)
		for (int j = 0; j < height; ++j)
			for (int k = width - 1; k > i; --k) {
				matrix[j][k-1] ^= matrix[j][k];
				matrix[j][k] = matrix[j][k-1] ^ matrix[j][k];
				matrix[j][k-1] ^= matrix[j][k];
			}

	std::cout << "\nИзменённая матрица:" << std::endl;

	DRAW_MATRIX(matrix, width, height);
	
	for (int i = 0; i < height; ++i)
		delete [] matrix[i];
	delete [] matrix;
	
	system("pause");
}
