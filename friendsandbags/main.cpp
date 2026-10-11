#include <windows.h>
#include <iostream>
#include <sstream>
#include <vector>
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

static inline void sort(std::vector<float>& vector) {
	for (size_t i = 0; i < vector.size() - 1; ++i)
		for (size_t j = 0; j < vector.size() - i - 1; ++j) {
			float temp = vector.at(j);
			if (temp < vector.at(j + 1)) {
				vector.at(j) = vector.at(j + 1);
				vector.at(j + 1) = temp;
			}
		}
}

static float sum(const std::vector<float>& vector) {
	if (vector.size() == 0)
		return 0;

	float output = vector.at(0);
	for (size_t i = 1; i < vector.size(); ++i)
		output += vector.at(i);
	
	return output;
}

static void print_vector(const std::vector<float>& vector) {
	std::stringstream stream;

	if (vector.size() == 0) {
		stream << "{ }";
		std::cout << stream.str() << std::endl;
		return;
	}

	stream << "{ ";
	stream << vector.at(0);
	for (size_t i = 1; i < vector.size(); ++i)
		stream << ", " << vector.at(i);
	stream << " }";
	
	std::cout << stream.str() << std::endl;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	int friends_count, items_count;
	float total_mass, average_mass;
	std::vector<float> items_mass;

	GET_NUMBER("Введите количество друзей: ", friends_count, "Пожалуйста, введите число!", friends_count > 1, "Количество друзей должно быть больше 1!");
	GET_NUMBER("Введите количество предметов: ", items_count, "Пожалуйста, введите число!", items_count > 0, "Количество предметов должно быть больше 0!");
	for (int i = 0; i < items_count; ++i) {
		float item_mass;
		GET_NUMBER("Введите массу предмета: ", item_mass, "Пожалуйста, введите число!", item_mass > 0, "Масса предмета должна быть больше 0!");
		items_mass.push_back(item_mass);
	}
	std::cout << std::endl;

	sort(items_mass);
	total_mass = sum(items_mass);
	average_mass = total_mass / friends_count;
	
	std::vector<std::vector<float>> bags;
	for (size_t i = 0; i < friends_count; ++i) {
		std::vector<float> bag;
		bags.push_back(bag);
	}

	for (int i = 0; i < items_count; ++i) {
		std::vector<float>* bags_min_sum = &bags.at(0);
		for (int j = 1; j < friends_count; ++j) {
			if (sum(bags[j]) < sum(*bags_min_sum)) {
				bags_min_sum = &bags.at(j);
			}
		}
		bags_min_sum->push_back(items_mass.at(i));
	}

	for (int i = 0; i < friends_count; ++i)
		print_vector(bags[i]);
	
	system("pause");
}