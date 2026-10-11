#include <iostream>
#include <cmath>
#include <windows.h>
#include <cstdlib>
#include <limits>

#define CLEAR_CIN() {\
	std::cin.clear();\
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');\
}

#define GET_FLOAT_FROM_USER(text, error_text, number) {\
	while (true) {\
		std::cout << '\n' << text;\
		while (!(std::cin >> number)) {\
	        CLEAR_CIN();\
	        std::cout << "\nПожалуйста, введите число!" << std::endl;\
	    	std::cout << '\n' << text;\
	    }\
	    if (a > 0)\
	        break;\
	    std::cout << error_text << std::endl;\
	    CLEAR_CIN();\
	}\
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	float a, b, c, d, h;
	
	while (true) {
		GET_FLOAT_FROM_USER("Введите длину комнаты (в метрах): ",  "Пожалуйста, введите длину комнаты большую нуля!",  a);
		GET_FLOAT_FROM_USER("Введите ширину комнаты (в метрах): ", "Пожалуйста, введите ширину комнаты большую нуля!", b);
		GET_FLOAT_FROM_USER("Введите высоту комнаты (в метрах): ", "Пожалуйста, введите высоту комнаты большую нуля!", c);
		GET_FLOAT_FROM_USER("Введите ширину рулона (в метрах): ",  "Пожалуйста, введите ширину рулона большую нуля!",  d);
		GET_FLOAT_FROM_USER("Введите длину рулона (в метрах): ",   "Пожалуйста, введи длину рулона большую нуля!",     h);
		
		if (h >= c)
			break;
		
		std::cout << "\nВысота комнаты не может быть меньше длины рулона. Введите корректные данные!" << std::endl;
	}

	
	float lines_in_room_real = (a + b) / d * 2,
		  lines_in_roll_real = h / c,
		  roll_count_real    = lines_in_room_real / lines_in_roll_real,
		  lines_in_room      = std::ceil((a + b) / d) * 2,
		  lines_in_roll      = std::floor(lines_in_roll_real),
		  roll_count         = lines_in_room / lines_in_roll;
	
	std::cout
		<< "Рулонов обоев понадобится: "
		<<  roll_count
		<< '\n'
		<< "Остаток обоев: "
		<< round((1.0f - (roll_count_real / roll_count)) * 1000) / 10.0f 
		<< "%"
		<< std::endl;
	
	system("pause");
}
