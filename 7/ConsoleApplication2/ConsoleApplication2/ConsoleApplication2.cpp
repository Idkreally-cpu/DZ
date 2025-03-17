#include <iostream>
#include <vector>

using namespace std;

const double M_PI = 3.14159265358979323846;

class IDGenerator {
public:
    static int generateID() {
        static int id = 0;
        return ++id;
    }
};

class Shape {
protected:
    int id;
public:
    Shape() : id(IDGenerator::generateID()) {}
    virtual ~Shape() {
        cout << "Shape with ID " << id << " destroyed." << endl;
    }
    virtual double area() const = 0;
    int getID() const { return id; }
};

class Circle : public Shape {
protected:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override {
        return M_PI * radius * radius;
    }
    double circumference() const {
        return 2 * M_PI * radius;
    }
    Circle operator+(const Circle& other) const {
        return Circle(radius + other.radius);
    }
    bool operator==(const Circle& other) const {
        return radius == other.radius;
    }
};

class Sphere : public Circle {
public:
    Sphere(double r) : Circle(r) {}
    double volume() const {
        return (4.0 / 3.0) * M_PI * radius * radius * radius;
    }
    Sphere operator+(const Sphere& other) const {
        return Sphere(radius + other.radius);
    }
    bool operator==(const Sphere& other) const {
        return radius == other.radius;
    }
};

class Rectangle : public Shape {
protected:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override {
        return width * height;
    }
    double diagonal() const {
        return width * width + height * height;
    }
    Rectangle operator+(const Rectangle& other) const {
        return Rectangle(width + other.width, height + other.height);
    }
    bool operator==(const Rectangle& other) const {
        return width == other.width && height == other.height;
    }
};

class Cuboid : public Rectangle {
    double depth;
public:
    Cuboid(double w, double h, double d) : Rectangle(w, h), depth(d) {}
    double volume() const {
        return width * height * depth;
    }
    Cuboid operator+(const Cuboid& other) const {
        return Cuboid(width + other.width, height + other.height, depth + other.depth);
    }
    bool operator==(const Cuboid& other) const {
        return width == other.width && height == other.height && depth == other.depth;
    }
};

void printMenu(const vector<Shape*>& shapes) {
    for (const auto& shape : shapes) {
        cout << "Shape ID: " << shape->getID() << ", Area: " << shape->area() << endl;
        if (auto circle = dynamic_cast<Circle*>(shape)) {
            cout << "  Type: Circle, Circumference: " << circle->circumference() << endl;
        }
        else if (auto sphere = dynamic_cast<Sphere*>(shape)) {
            cout << "  Type: Sphere, Volume: " << sphere->volume() << endl;
        }
        else if (auto rectangle = dynamic_cast<Rectangle*>(shape)) {
            cout << "  Type: Rectangle, Diagonal: " << rectangle->diagonal() << endl;
        }
        else if (auto cuboid = dynamic_cast<Cuboid*>(shape)) {
            cout << "  Type: Cuboid, Volume: " << cuboid->volume() << endl;
        }
    }
}

int main() {
    vector<Shape*> shapes;

    shapes.push_back(new Circle(5));
    shapes.push_back(new Sphere(3));
    shapes.push_back(new Rectangle(4, 5));
    shapes.push_back(new Cuboid(3, 4, 5));

    printMenu(shapes);

    for (auto& shape : shapes) {
        delete shape;
    }
}