#include <iostream>
#include <set>

void createFilteredSet(const std::set<int>& setA, const std::set<int>& setB, int t, std::set<int>& filtered) {
    for (const auto& elem : setA) {
        if (setB.find(elem) == setB.end() && elem < t) {
            filtered.insert(elem);
        }
    }
}

int main() {
    setlocale(LC_ALL, "russian");
    std::set<int> A, B, filtered;
    int t;

    // Ввод множества A
    std::cout << "Введите количество элементов множества A:" << std::endl;
    int sizeA;
    std::cin >> sizeA;
    std::cout << "Введите элементы множества A:" << std::endl;
    for (int i = 0; i < sizeA; ++i) {
        int temp;
        std::cin >> temp;
        A.insert(temp);
    }

    // Ввод множества B
    std::cout << "Введите количество элементов множества B:" << std::endl;
    int sizeB;
    std::cin >> sizeB;
    std::cout << "Введите элементы множества B:" << std::endl;
    for (int i = 0; i < sizeB; ++i) {
        int temp;
        std::cin >> temp;
        B.insert(temp);
    }

    // Ввод значения t
    std::cout << "Введите значение t: ";
    std::cin >> t;

    // Создание фильтрованного множества
    createFilteredSet(A, B, t, filtered);

    // Вывод результата
    std::cout << "Множество элементов из A, которых нет в B и которые меньше t:" << std::endl;
    for (const auto& elem : filtered) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}
