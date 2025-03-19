#include <iostream>

class EvenCounter {
public:
    int fold(int arr[], int size) {
        int count = 0;
        for (int i = 0; i < size; ++i) {
            if (arr[i] % 2 == 0) {
                ++count;
            }
        }
        return count;
    }
};

class OddCounter {
public:
    int fold(int arr[], int size) {
        int count = 0;
        for (int i = 0; i < size; ++i) {
            if (arr[i] % 2 != 0) {
                ++count;
            }
        }
        return count;
    }
};

int main() {
    int size;
    std::cout << "������� ������ �������: ";
    std::cin >> size;

    int* arr = new int[size];
    std::cout << "������� �������� �������: ";
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }

    EvenCounter evenCounter;
    OddCounter oddCounter;

    std::cout << "���������� ������ �����: " << evenCounter.fold(arr, size) << std::endl;
    std::cout << "���������� �������� �����: " << oddCounter.fold(arr, size) << std::endl;

    delete[] arr;
}
