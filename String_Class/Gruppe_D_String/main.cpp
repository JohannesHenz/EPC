#include <iostream>
#include "String.h"

int main() {
    String s("Hello");
    std::cout << s.c_str() << std::endl;

    std::cout << "Current Size: " << s.size() << std::endl;
    s.append(" World");
    std::cout << s.c_str() << std::endl;
    std::cout << "Current Size: " << s.size() << std::endl;
    std::cout << "Current Capacity: " << s.capacity() << std::endl;
    s.reserve(100);
    std::cout << "Current Capacity: " << s.capacity() << std::endl;
    std::cout << "Current Size: " << s.size() << std::endl;
    std::cout << s.c_str() << std::endl;
    s.reserve(5);
    std::cout << "Current Capacity: " << s.capacity() << std::endl;
    std::cout << s.c_str() << std::endl;
    std::cout << "Current Size: " << s.size() << std::endl;
    s.reserve(20);
    std::cout << s.c_str() << std::endl;


    return 0;
}
