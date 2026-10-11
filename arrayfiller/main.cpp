#include <windows.h>
#include <iostream>
#include <limits>

inline void fill_array_left_up(int **array, int array_size) {
    int y = 0, x = 0, number = 0;
    bool go_down = true, second_half = false;
    while (true) {
        array[y][x] = ++number;
        if (number == array_size * array_size)
            break;
        
        if (!second_half) {
            if (go_down) {
                --x;
                ++y;

                if (x < 0 && y == array_size) {
                    go_down = false;
                    x += 2;
                    --y;
                    second_half = true;
                    continue;
                }

                if (x < 0) {
                    go_down = false;
                    ++x;
                }

                if (y == array_size) {
                    go_down = false;
                    --y;
                }

                continue;
            }

            ++x;
            --y;

            if (y < 0 && x == array_size) {
                go_down = true;
                y += 2;
                --x;
                second_half = true;
                continue;
            }

            if (y < 0) {
                go_down = true;
                ++y;
            }

            if (x == array_size) {
                go_down = true;
                --x;
            }

            continue;
        }

        if (go_down) {
            --x;
            ++y;

            if (y == array_size) {
                go_down = false;
                x += 2;
                --y;
            }

            continue;
        }

        ++x;
        --y;

        if (x == array_size) {
            go_down = true;
            y += 2;
            --x;
        }
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    int array_size;

    while (true) {
        std::cout << "Введите размер массива: ";
        while (!(std::cin >> array_size)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\nПожалуйста, введите целое число!" << std::endl;
            std::cout << "Введите размер массива: ";
        }

        if (array_size > 0)
            break;
        
        std::cout << "\nРазмер массива должен быть больше 0!" << std::endl;
    }

    int** array = new int*[array_size];
    for (int i = 0; i < array_size; ++i) {
        array[i] = new int[array_size];
        for (int j = 0; j < array_size; ++j)
            array[i][j] = 0;
    }

    fill_array_left_up(array, array_size);

    for (int y = 0; y < array_size; ++y) {
        for (int x = 0; x < array_size; ++x) {
//             if (array[y][x] < 10)
//                 std::cout << '';
            std::cout << array[y][x] << '\t';
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < array_size; ++i)
        delete [] array[i];
    delete [] array;
    system("pause");
}
