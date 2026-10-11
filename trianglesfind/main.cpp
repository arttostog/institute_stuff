#include <windows.h>
#include <iostream>
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

typedef struct {
	float a;
	float b;
	float c;
} triangle_t;

inline int factorial(int number) {
	int output = 1;
	for (int i = 2; i <= number; output *= i, ++i);
	return output;
}

inline int get_count_of_combinations(int lines_count) {
	int multiplier = lines_count - 3;
	return factorial(lines_count) / (6 * (multiplier ? multiplier : 1));
}

inline bool is_triangle(const triangle_t* triangle) {
	return triangle->a + triangle->b > triangle->c &&
		   triangle->a + triangle->c > triangle->b &&
		   triangle->b + triangle->c > triangle->a;
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
	
	triangle_t* triangles = new triangle_t[get_count_of_combinations(lines_count)];
	int triangles_count = 0;

	for (int i = 0; i < lines_count; ++i)
		for (int j = i + 1; j < lines_count; ++j)
			for (int k = j + 1; k < lines_count; ++k) {
				triangle_t triangle = {lines[i], lines[j], lines[k]};
				
				if (!is_triangle(&triangle))
					continue;
				
				triangles[triangles_count] = triangle;
				++triangles_count;
			}
	
	std::cout << std::endl
			  << "Возможные треугольники из отрезков ("
			  << triangles_count
			  << "): "
			  << std::endl;
	
	for (int i = 0; i < triangles_count; ++i)
		std::cout << triangles[i].a
			      << ' '
				  << triangles[i].b
				  << ' '
				  << triangles[i].c
				  << std::endl;
	
	delete [] lines;
	delete [] triangles;
	
	system("pause");
}
