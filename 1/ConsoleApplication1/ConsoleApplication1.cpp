#include <iostream>

using namespace std;

class DynamicArray {
private:
    int* data;
    int size;

public:
    DynamicArray(int size) : size(size) {
        data = new int[size];
        for (int i = 0; i < size; ++i) {
            data[i] = 0;
        }
    }

    ~DynamicArray() {
        delete[] data;
    }

    DynamicArray(const DynamicArray& other) : size(other.size) {
        data = new int[size];
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i] + 1;
        }
        cout << "Copied array with size " << size << std::endl;
    }

    int getSize() const {
        return size;
    }

    int get(int index) const {
        return data[index];
    }

    void set(int index, int value) {
        data[index] = value;
    }
};