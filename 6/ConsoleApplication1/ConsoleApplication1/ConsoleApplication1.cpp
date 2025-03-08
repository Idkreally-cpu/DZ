#include <iostream>

class B;

class A {
public:
    int x;
    int y;

    A(int a, int b) : x(a), y(b) {}

    friend int sum(const A& a, const B& b);
};

class B {
public:
    int u;
    int v;

    B(int c, int d) : u(c), v(d) {}

    friend int sum(const A& a, const B& b);
};

int sum(const A& a, const B& b) {
    return a.x + a.y + b.u + b.v;
}

int main() {
    A a(1, 2);
    B b(3, 4);
    std::cout << sum(a, b) << std::endl;
}