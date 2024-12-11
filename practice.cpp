#include <iostream>
#include <locale>

void createSumArray(const int* arrA, const int* arrB, int* arrC, int size) {
    for (int i = 0; i < size; i++) {
        arrC[i] = arrA[i] + arrB[i];
    }
}

void createFilteredSet(const int* arrA, int sizeA, const int* arrB, int sizeB, int t, int*& filtered, int& filteredSize) {
    filteredSize = 0;
    for (int i = 0; i < sizeA; i++) {
        bool isInB = false;
        for (int j = 0; j < sizeB; j++) {
            if (arrA[i] == arrB[j]) {
                isInB = true;
                break;
            }
        }
        if (!isInB && arrA[i] < t) {
            filteredSize++;
        }
    }
    filtered = new int[filteredSize];
    int index = 0;
    for (int i = 0; i < sizeA; i++) {
        bool isInB = false;
        for (int j = 0; j < sizeB; j++) {
            if (arrA[i] == arrB[j]) {
                isInB = true;
                break;
            }
        }
        if (!isInB && arrA[i] < t) {
            filtered[index++] = arrA[i];
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    const int N = 5; // Размер массивов фиксирован на 5

    int* A = new int[N]; // Динамическое выделение памяти для массива A
    int* B = new int[N]; // Динамическое выделение памяти для массива B
    int* C = new int[N]; // Динамическое выделение памяти для массива C

    // Ввод массивов
    std::cout << "Введите " << N << " элементов для массива A:" << std::endl;
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::cout << "Введите " << N << " элементов для массива B:" << std::endl;
    for (int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    // Вывод массива C (сумма массивов A и B)
    createSumArray(A, B, C, N);
    std::cout << "Массив C (сумма массивов A и B):" << std::endl;
    for (int i = 0; i < N; i++) {
        std::cout << C[i] << " ";
    }
    std::cout << std::endl;

    // Создание и вывод фильтрованного множества
    int t;
    std::cout << "Введите значение t: ";
    std::cin >> t;
    int* filtered = nullptr;
    int filteredSize = 0;
    createFilteredSet(A, N, B, N, t, filtered, filteredSize);
    std::cout << "Элементы массива A, отсутствующие в B и меньшие t:" << std::endl;
    for (int i = 0; i < filteredSize; i++) {
        std::cout << filtered[i] << " ";
    }
    std::cout << std::endl;

    // Освобождение выделенной памяти
    delete[] A;
    delete[] B;
    delete[] C;
    delete[] filtered;

    return 0;
}
