#include <iostream>

void createSumArray(const int* arrA, const int* arrB, int* arrC, int size) {
    for (int i = 0; i < size; ++i) {
        arrC[i] = arrA[i] + arrB[i];
    }
}

int main() {
    setlocale(LC_ALL, "russian");
    const int N = 5; // Размер массивов фиксирован на 5

    int A[N], B[N], C[N];

    // Ввод массива A
    std::cout << "Введите " << N << " элементов для массива A:" << std::endl;
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }

    // Ввод массива B
    std::cout << "Введите " << N << " элементов для массива B:" << std::endl;
    for (int i = 0; i < N; ++i) {
        std::cin >> B[i];
    }

    // Создание массива C
    createSumArray(A, B, C, N);

    // Вывод массива C
    std::cout << "Массив C (сумма массивов A и B):" << std::endl;
    for (int i = 0; i < N; ++i) {
        std::cout << C[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
