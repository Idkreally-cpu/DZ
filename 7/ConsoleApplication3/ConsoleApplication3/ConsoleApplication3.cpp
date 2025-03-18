#include <iostream>
#include <vector>

int main() {
    int count;
    std::cout << "¬ведите количество указателей: ";
    std::cin >> count;

    int* obj = new int(42);
    std::vector<int*> pointers(count, obj);

    for (int i = 0; i < count; ++i) {
        std::cout << "”казатель " << i + 1 << ": " << pointers[i] << std::endl;
    }

    delete obj;
    return 0;
}