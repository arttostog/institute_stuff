#include <windows.h>
#include <iostream>
#include <sstream>
#include <string>

inline bool is_separator(char symbol) {
	switch (symbol) {
		case '\0':
		case ' ':
		case '.':
		case ',':
		case '?':
		case '!':
		case '(':
		case ')':
		case '{':
		case '}':
		case '[':
		case ']':
		case '/':
		case '\'':
		case '\"':
		case ';':
		case ':':
		case '«':
		case '»':
		case '—':
			return true;
		default:
			return false;
	}
}

inline bool contains_number(const char* word, size_t size) {
	for (size_t i = 0; i < size; ++i)
		if (word[i] >= '0' && word[i] <= '9')
			return true;
	return false;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	std::string       input;
	const char       *buffer;
	std::stringstream max_sized_words,
					  min_sized_words;
	size_t            max_sized_word_length = 0,
		              min_sized_word_length = -1;
	
	while (true) {
		std::cout << "Пожалуйста, введите текст: ";
		std::getline(std::cin, input);
		
		if (!input.empty())
			break;
		
		std::cout << "Вы ничего не ввели!" << std::endl;
	}
	
	input += '\0';
	buffer = input.c_str();
	
	for (size_t i = 0, counter = 0; i < input.size(); ++i) {
		if (!is_separator(buffer[i])) {
			++counter;
			continue;
		}
		
		if (!counter)
			continue;
		
		size_t word_size = counter;
		char*  word      = (char*) buffer + i - word_size;
			   counter   = 0;
		
//		if (contains_number(word, word_size))
//			continue;
		
		if (word_size > max_sized_word_length) {
			max_sized_word_length = word_size;
			max_sized_words.str("");
			max_sized_words.clear();
			max_sized_words.write(word, word_size);
		}
		else if (word_size == max_sized_word_length) {
			max_sized_words << ' ';
			max_sized_words.write(word, word_size);
		}
		
		if (word_size < min_sized_word_length) {
			min_sized_word_length = word_size;
			min_sized_words.str("");
			min_sized_words.clear();
			min_sized_words.write(word, word_size);
		}
		else if (word_size == min_sized_word_length) {
			min_sized_words << ' ';
			min_sized_words.write(word, word_size);
		}
	}
	
	if (max_sized_word_length == 0) {
		std::cout << "Слов не найдено!" << std::endl;
		system("pause");
		return 0;
	}
	
	std::cout << "Слова с наибольшим размером (" << max_sized_word_length << "): "
			  << max_sized_words.str()
			  << std::endl
			  << "Слова с наименьшим размером (" << min_sized_word_length << "): "
			  << min_sized_words.str()
			  << std::endl;
	
	system("pause");
}
