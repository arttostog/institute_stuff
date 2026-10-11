#include <iostream>
#include <windows.h>
#include <limits>
#include <sstream>

#define GET_INTEGER(text, number) {\
	std::cout << text;\
	while (!(std::cin >> number)) {\
		std::cin.clear();\
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');\
		std::cout << "\nПожалуйста, введите целое число!" << std::endl;\
		std::cout << text;\
	}\
}

int main(int argc, char** argv) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	int count = 0;
	while (true) {
		GET_INTEGER("Введите количество ёлочек: ", count);
		
		if (count > 0)
			break;
		
		std::cout << "\nВведите число большее 0!" << std::endl;
	}
	
	std::cout << std::endl;
	
	std::stringstream buffer;
		
	for (int i = 0; i < count; ++i) {
		for (int j = 0, flag = 0; j < (i * 2) + 1; ++j) {
			for (int k = 0; k < count - i - 1 && !flag; ++k) {
				buffer << ' ';
			}
			flag = 1;
			buffer << '#';
		}
		
		for (int k = 0; k < count - i; ++k)
			buffer << ' ';
		buffer << '\n';
	}
	
	std::string line;
	std::stringstream output_buffer;
	while (std::getline(buffer, line)) {
		for (int i = 0; i < count; ++i)
			output_buffer << line;
		output_buffer << '\n';
	}
	
	std::cout << output_buffer.str() << std::endl;
	
	system("pause");
}
