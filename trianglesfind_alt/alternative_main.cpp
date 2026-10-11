#include <windows.h>
#include <iostream>
#include <sstream>
#include <limits>

#define CLEAR_CIN() {\
	std::cin.clear();\
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');\
}

#define GET_NUMBER(text, number, number_error_text, condition, condition_error_text) {\
	while(true) {\
		std::cout << '\n' << text;\
		while (!(std::cin >> number)) {\
			CLEAR_CIN();\
			std::cout << '\n' << number_error_text << std::endl;\
			std::cout << '\n' << text;\
		}\
		if (condition)\
			break;\
		std::cout << '\n' << condition_error_text << std::endl;\
		CLEAR_CIN();\
	}\
}

inline bool is_triangle(float a, float b, float c) {
	return a + b > c &&
		   a + c > b &&
		   b + c > a;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	int lines_count;
	GET_NUMBER("Введите количество отрезков: ", lines_count, "Пожалуйста, введите целое число!", lines_count > 2, "Количество отрезков должно быть больше 2-х!");
	
	float* lines = new float[lines_count];
	for (int i = 0; i < lines_count; ++i)
		GET_NUMBER("Введите длину отрезка: ", lines[i], "Пожалуйста, введите целое число!", lines[i] > 0, "Длина отрезка должна быть больше 0!");
	
	std::cout << std::endl;
	
	std::stringstream triangles_buffer;
	int triangles_count = 0;

	for (int i = 0; i < lines_count; ++i)
		for (int j = i + 1; j < lines_count; ++j)
			for (int k = j + 1; k < lines_count; ++k) {
				
				if (!is_triangle(lines[i], lines[j], lines[k]))
					continue;
				
				triangles_buffer << lines[i] << ' ' << lines[j] << ' ' << lines[k] << '\n';
				++triangles_count;
			}
	
	std::cout << std::endl
			  << "Возможные треугольники из отрезков ("
			  << triangles_count
			  << "): \n"
			  << triangles_buffer.str()
			  << std::endl;
	
	delete [] lines;
	system("pause");
}
