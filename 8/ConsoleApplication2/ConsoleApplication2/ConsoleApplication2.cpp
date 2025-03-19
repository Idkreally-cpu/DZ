#include <iostream>
using namespace std;

class ElectricVehicle {
protected:
    int batteryLevel;
public:
    ElectricVehicle() : batteryLevel(0) {}
    void charge(int amount) { batteryLevel += amount; }
    void showBattery() { cout << "Battery Level: " << batteryLevel << endl; }
};

class LandTransport {
protected:
    int speed;
public:
    LandTransport() : speed(0) {}
    void accelerate(int value) { speed += value; }
    void brake(int value) { speed -= value; }
    virtual void drive() { cout << "Driving at speed: " << speed << endl; }
};

class WaterTransport {
protected:
    int depth;
public:
    WaterTransport() : depth(0) {}
    void dive(int value) { depth += value; }
    void surface(int value) { depth -= value; }
    virtual void sail() { cout << "Sailing at depth: " << depth << endl; }
};

class ElectricCar : public ElectricVehicle, public LandTransport {
public:
    void drive() { cout << "Electric Car is driving at speed: " << speed << endl; }
};

class ElectricBoat : public ElectricVehicle, public WaterTransport {
public:
    void sail() { cout << "Electric Boat is sailing at depth: " << depth << endl; }
};

class AmphibiousVehicle : public ElectricCar, public ElectricBoat {
public:
    void switchToLandMode() {
        cout << "Switching to Land Mode" << endl;
        ElectricCar::drive();
    }
    void switchToWaterMode() {
        cout << "Switching to Water Mode" << endl;
        ElectricBoat::sail();
    }
};

int main() {
    AmphibiousVehicle av;
    av.charge(100);
    av.showBattery();
    av.accelerate(50);
    av.dive(10);
    av.switchToLandMode();
    av.switchToWaterMode();
    return 0;
}