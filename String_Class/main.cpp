#include <iostream>
#include "String.h"

int main() {
    String s("Hello");
    s.c_str();
    std::cout << "\n" << s.size() << std::endl;
    s.append(" World");
    s.c_str();
    std::cout << "\n" << s.size() << std::endl;

    return 0;
}
