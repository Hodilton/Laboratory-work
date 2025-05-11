#include "./Singleton.h"

#include <iostream>

int main() {
    auto instance1 = Singleton::getInstance();
    auto instance2 = Singleton::getInstance();

    std::cout << instance1 << std::endl;
    std::cout << instance2 << std::endl;

    Singleton::CleanApp();

    return 0;
}