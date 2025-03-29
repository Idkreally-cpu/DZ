#include <iostream>
#include <string>

int main() {
    try {
        double a, b;
        if (!(std::cin >> a >> b)) {
            throw "Invalid input";
        }
        if (b == 0) {
            throw "Division by zero";
        }
        std::cout << a / b << std::endl;
    } catch (const char* e) {
        std::cerr << "Error: " << e << std::endl;
    } catch (...) {
        std::cerr << "Unknown error" << std::endl;
    }
    return 0;
}
