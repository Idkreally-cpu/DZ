#include <iostream>

class Counter {
public:
    virtual int fold(int arr[], int size) = 0;  
    virtual ~Counter() {}                       
};

class EvenCounter : public Counter {
public:
    int fold(int arr[], int size) override {
        int count = 0;
        for (int i = 0; i < size; ++i) {
            if (arr[i] % 2 == 0) {
                ++count;
            }
        }
        return count;
    }
};

class OddCounter : public Counter {
public:
    int fold(int arr[], int size) override {
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
    std::cout << "Enter size: ";
    std::cin >> size;

    int* arr = new int[size];
    std::cout << "Enter elements: ";
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }

    Counter* counters[] = { new EvenCounter(), new OddCounter() };

    std::cout << "Even count: " << counters[0]->fold(arr, size) << std::endl;
    std::cout << "Odd count: " << counters[1]->fold(arr, size) << std::endl;

    delete counters[0];
    delete counters[1];
    delete[] arr;

    return 0;
}
