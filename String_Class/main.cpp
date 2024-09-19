#include <iostream>
#include "String.h"

int main() {
    String s("Hello");
    s.c_str();
    std::cout << "\nCurrent Size: " << s.size() << std::endl;
    s.append(" World");
    s.c_str();
    std::cout << "\nCurrent Size: " << s.size() << std::endl;
    std::cout << "Current Capacity: " << s.capacity() << std::endl;
    s.reserve(100);
    std::cout << "Current Capacity: " << s.capacity() << std::endl;
    std::cout << "Current Size: " << s.size() << std::endl;
    s.reserve(5);
    std::cout << "Current Capacity: " << s.capacity() << std::endl;
    s.c_str();
    std::cout << "\nCurrent Size: " << s.size() << std::endl;
    s.reserve(20);
    s.c_str();



    return 0;
}
