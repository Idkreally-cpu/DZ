#include <iostream>
using namespace std;

class Point {
private:
    int x;
    int y;
    int z;
    int SIZE;
    int* arr;

public:
    Point() : x(0), y(0), z(0), SIZE(5), arr(new int[SIZE]) {}

    Point(int x, int y, int z, int SIZE) : x(x), y(y), z(z), SIZE(SIZE), arr(new int[SIZE]) {}

    Point(const Point& other) : x(other.x), y(other.y), z(other.z), SIZE(other.SIZE), arr(new int[other.SIZE]) {
        for (int i = 0; i < SIZE; i++) {
            arr[i] = other.arr[i];
            cout << arr[i] << endl;
        }
    }

    ~Point() {
        delete[] arr;
    }

    int GetX() const { return x; }
    int GetY() const { return y; }
    int GetZ() const { return z; }

    bool operator==(const Point& other) const {
        return x == other.x && y == other.y && z == other.z;
    }

    bool operator!=(const Point& other) const {
        return !(*this == other);
    }

    Point operator-(const Point& other) const {
        return Point(x - other.x, y - other.y, z - other.z, SIZE);
    }

    Point& operator++() {
        ++x;
        ++y;
        ++z;
        return *this;
    }

    Point operator++(int) {
        Point temp = *this;
        ++(*this);
        return temp;
    }

    Point& operator=(const Point& other) {
        if (this != &other) {
            x = other.x;
            y = other.y;
            z = other.z;
            SIZE = other.SIZE;
            delete[] arr;
            arr = new int[SIZE];
            for (int i = 0; i < SIZE; i++) {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }

    void FillArray() {
        for (int i = 0; i < SIZE; i++) {
            arr[i] = rand() % 11;
        }
    }
};

int main() {
    Point a(3, 6, 9, 6);
    a.FillArray();

    Point b(a);

    Point c = a - b;
    ++c;

    if (a == b) {
        cout << "a and b are equal" << endl;
    }
    else {
        cout << "a and b are not equal" << endl;
    }

    return 0;
}
