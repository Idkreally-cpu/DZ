#include <iostream>
#include <string>
#include <vector>

class Vehicle {
protected:
    std::string type;
public:
    Vehicle(const std::string& t) : type(t) {}
    virtual ~Vehicle() {
        std::cout << type << " destroyed." << std::endl;
    }
    virtual void drive() = 0;
};

class Car : public Vehicle {
    std::string* model;
public:
    Car(const std::string& m) : Vehicle("Car"), model(new std::string(m)) {}
    ~Car() {
        delete model;
        std::cout << "Car model " << *model << " destroyed." << std::endl;
    }
    void drive() override {
        std::cout << "Driving a " << *model << " car." << std::endl;
    }
};

class Bike : public Vehicle {
    std::string* brand;
public:
    Bike(const std::string& b) : Vehicle("Bike"), brand(new std::string(b)) {}
    ~Bike() {
        delete brand;
        std::cout << "Bike brand " << *brand << " destroyed." << std::endl;
    }
    void drive() override {
        std::cout << "Riding a " << *brand << " bike." << std::endl;
    }
};

int main() {
    std::vector<Vehicle*> vehicles;
    vehicles.push_back(new Car("Tesla"));
    vehicles.push_back(new Bike("Harley"));

    for (auto v : vehicles) {
        v->drive();
    }

    for (auto v : vehicles) {
        delete v;
    }

    return 0;
}