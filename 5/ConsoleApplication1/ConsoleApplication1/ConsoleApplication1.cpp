#include <iostream>
#include <string>

class Animal {
private:
    std::string name;
    int weight;

protected:
    std::string sound;

public:
    Animal(const std::string& n, int w, const std::string& s)
        : name(n), weight(w), sound(s) {}

    void print() const {
        std::cout << "Name: " << name << ", Weight: " << weight << ", Sound: " << sound << std::endl;
    }
};

class Cat : public Animal {
public:
    Cat(const std::string& n, int w)
        : Animal(n, w, "Meow") {}
};

class Dog : public Animal {
public:
    Dog(const std::string& n, int w)
        : Animal(n, w, "Woof") {}
};

int main() {
    Cat cat1("Whiskers", 5);
    Cat cat2("Mittens", 4);
    Dog dog1("Buddy", 10);
    Dog dog2("Max", 8);

    cat1.print();
    cat2.print();
    dog1.print();
    dog2.print();

    return 0;
}