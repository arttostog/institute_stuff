#pragma once

#include <windows.h>
#include <iostream>
#include <limits>

#define SET_CODE_PAGE() {\
    SetConsoleCP(1251);\
	SetConsoleOutputCP(1251);\
}

#define GET_NUMBER_CIN(text, error_text, number) {\
    std::cout << text;\
	while (!(std::cin >> number)) {\
		std::cin.clear();\
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');\
		std::cout << error_text << std::endl;\
		std::cout << text;\
	}\
}