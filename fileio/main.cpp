/*
	Работает на стандарте C++11 и выше
*/

#include <windows.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
#include <string>
#include <cmath>

enum RETURN_CODES {
    SUCCESS                        = 0,
    INPUT_FILE_OPEN_FAILED         = 1,
    OUTPUT_FILE_OPEN_FAILED        = 2,
    FOUND_NUMBER_INSTEAD_OF_STRING = 3,
    FOUND_STRING_INSTEAD_OF_NUMBER = 4,
    GRADE_OUT_OF_RANGE             = 5,
    TOO_FEW_DATA                   = 6,
};

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

    int return_code = SUCCESS;
    int min_grade;
    int max_grade;
    std::ifstream     input_file;
    std::ofstream     output_file;
    std::stringstream output_stream;
    std::string       readed_line;
    std::stringstream readed_line_stream;
    std::string       readed_word;
    
    while (true) {
		GET_INTEGER("Введите максимальную оценку: ", max_grade);
		
		if (max_grade > -1)
			break;
		
		std::cout << "\nМаксимальная оценка не должна быть отрицательной!" << std::endl;
	}
    
    while (true) {
		GET_INTEGER("Введите минимальную оценку: ", min_grade);
		
		if (min_grade < 0) {
			std::cout << "\nМинимальная оценка должна быть не отрицательной!" << std::endl;
			continue;
		}
		
		if (min_grade > max_grade) {
			std::cout << "\nМинимальная оценка должна быть меньше или равной максимальной!" << std::endl;
			continue;
		}
		
		break;
	}
    
    std::cout << "Открываем файлы..." << std::endl;

    input_file.open("input.txt");
    if (!input_file.is_open()) {
        std::cout << "Невозможно открыть файл \"input.txt\"!" << std::endl;
        return_code = INPUT_FILE_OPEN_FAILED;
        goto main_exit;
    }

    output_file.open("output.txt");
    if (!output_file.is_open()) {
        std::cout << "Невозможно открыть файл \"output.txt\"!" << std::endl;
        return_code = OUTPUT_FILE_OPEN_FAILED;
        goto main_exit;
    }

    std::cout << "Обрабатываем данные..." << std::endl;

    for (int line = 1, counter = 0, grades_sum = 0, word_as_number; std::getline(input_file, readed_line);) {
        readed_line_stream << readed_line;
        for (; std::getline(readed_line_stream, readed_word, ' '); ++counter) {
            switch (counter)
            {
            case 1:
                output_stream << ' ';
            case 0:
                try {
                    std::stoi(readed_word);
                } catch (std::exception) {
                    output_stream << readed_word;
                    break;
                }
                std::cout << "Некорректный синтаксис в файле \"input.txt\" в строке " << line << ": было получено число, а ожидалась строка!\n\"" << readed_line << "\"" << std::endl;
				return_code = FOUND_NUMBER_INSTEAD_OF_STRING;
                goto main_exit;
            default:
                try {
                    word_as_number = std::stoi(readed_word);
                    if (word_as_number < min_grade || word_as_number > max_grade) {
                    	std::cout << "Некорректный синтаксис в файле \"input.txt\" в строке " << line << ": оценка выходит за диапазон оценивания!\n\"" << readed_line << "\"" << std::endl;
						return_code = GRADE_OUT_OF_RANGE;
                    	goto main_exit;
					}
                    
                    grades_sum += word_as_number;
                } catch (std::exception) {
                    std::cout << "Некорректный синтаксис в файле \"input.txt\" в строке " << line << ": была получена строка, а ожидалось число!\n\"" << readed_line << "\"" << std::endl;
					return_code = FOUND_STRING_INSTEAD_OF_NUMBER;
                    goto main_exit;
                }
                break;
            }    
        }
        
        if (counter == 2) {
        	output_stream << " 0 0" << '\n';
        	++line;
        	counter = 0;
            readed_line_stream.str("");
        	readed_line_stream.clear();
        	continue;
		}

        if (counter > 2) {
            output_stream << ' ' << grades_sum << ' ' << std::round((grades_sum / float(counter - 2)) * 100) / 100.0f << '\n';
            ++line;
			counter = 0;
            grades_sum = 0;
            readed_line_stream.str("");
        	readed_line_stream.clear();
            continue;
        }

        std::cout << "Некорректный синтаксис в файле \"input.txt\" в строке " << line << ": не хватает данных!\n\"" << readed_line << "\"" << std::endl;
        return_code = TOO_FEW_DATA;
        goto main_exit;
    }
    std::cout << "Записываем результаты..." << std::endl;

    output_file << output_stream.str();
	
    std::cout << "Успешно!" << std::endl;
main_exit:
    input_file.close();
    output_file.close();
    switch (return_code) {
    	case OUTPUT_FILE_OPEN_FAILED:
    		break;
    	case SUCCESS:
    		std::system("notepad.exe output.txt");
    		break;
    	default:
    		std::system("notepad.exe input.txt");
    		break;
	}
    system("pause");
    return return_code;
}
