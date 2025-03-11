#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec;

    // Копирование данных из потока ввода в вектор
    std::copy(
        std::istream_iterator<int>(std::cin),  // Начало потока
        std::istream_iterator<int>(),          // Конец потока
        std::back_inserter(vec)                // Вставка в вектор
    );

    // Вывод прочитанных данных
    for (int x : vec) {
        std::cout << x << " ";
    }
    return 0;
}