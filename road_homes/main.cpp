#include <iostream>
#include <cmath>
#include <windows.h>
#include <cstdlib>
#include <limits>

#define CLEAR_ARRAY(array, size) {\
	for (int i = 0; i < size; ++i)\
		array[i] = '\0';\
}

#define GET_INTEGER(text, number) {\
	std::cout << text;\
	while (!(std::cin >> number)) {\
		std::cin.clear();\
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');\
		std::cout << "\nПожалуйста, введите целое число!" << std::endl;\
	    std::cout << text;\
	}\
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	int houses_count, houses_with_internet_count;
	
	while (true) {
		GET_INTEGER("Введите кол-во домов всего: ", houses_count);
		
		if (houses_count > 0)
			break;
		
		std::cout << "Кол-во домов должно быть больше 0!" << std::endl;
	}
	
	while (true) {
		GET_INTEGER("\nВведите кол-во подключаемых к интернету домов: ", houses_with_internet_count);
		
		if (houses_with_internet_count > houses_count) {
			std::cout << "Кол-во подключаемых к интернету домов не может быть больше общего кол-ва домов!" << std::endl;
			continue;
		}
		
		if (houses_with_internet_count < 1) {
			std::cout << "Кол-во подключаемых к интернету домов должно быть больше 0!" << std::endl;
			continue;
		}
		
		break;
	}
	
	int* houses_with_internet = new int[houses_with_internet_count];
	CLEAR_ARRAY(houses_with_internet, houses_with_internet_count);
	
	for (size_t i = 0 ; i < houses_with_internet_count; ++i) {
		while(true) {
			int number_of_house = 0;
			GET_INTEGER("\nВведите номера подключаемого к интернету дома: ", number_of_house);
			
			if (number_of_house < 1 || number_of_house > houses_count) {
				std::cout << "\nВведите корректный номер дома от 1 до " << houses_count << " включительно!" << std::endl;
				continue;
			}
			
			bool already_in_array = false;
			for (int j = 0; j < houses_with_internet_count; ++j)
				if (houses_with_internet[j] == number_of_house)
					already_in_array = true;
					
			if (already_in_array) {
				std::cout << "\nЭтот номер уже присутствует в списке!" << std::endl;
				continue;
			}
			
			houses_with_internet[i] = number_of_house;
			
			break;
		}
	}
	
	int* length_between_houses = new int[houses_count];
	CLEAR_ARRAY(length_between_houses, houses_count);
	
	for (int i = 0; i < houses_count; ++i)
		for (int j = 0; j < houses_with_internet_count; ++j)
			length_between_houses[i] += std::abs((i + 1) - houses_with_internet[j]);
	
	int min_length = length_between_houses[0];
	for (int i = 1; i < houses_count; ++i)
		if (length_between_houses[i] < min_length)
			min_length = length_between_houses[i];
	
	std::cout << "\nСамые подходящие дома для установки коммутатора: " << std::endl;
	
	for (int i = 0; i < houses_count; ++i)
		if (length_between_houses[i] == min_length)
			std::cout << i + 1 << ' ';
	std::cout << std::endl;
	
	delete [] houses_with_internet;
	delete [] length_between_houses;
	system("pause");
}
