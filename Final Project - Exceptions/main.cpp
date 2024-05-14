#include <iostream>
#include "Sigma.h"

int main() {
    try {
        unsigned long sum = sigma(5);
        std::cout << "sigma(5) = " << sum << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        unsigned long sum = sigma(0);
        std::cout << "sigma(0) = " << sum << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
