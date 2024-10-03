#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>
#include "doctest.h"
#include "String.h"

TEST_CASE("Testing String constructor") {
    String s("Hello");
    CHECK(std::string(s.c_str()) == "Hello");
}

TEST_CASE("Tesing the overloaded + operator for String object + String object") {
    String s1("Hello");
    const String s2(" World");
    const String s3 = s1 + s2;
    std::cout << "String s3: " << s3.c_str() << std::endl;
    CHECK(std::string(s3.c_str()) == "Hello World");
}

TEST_CASE("Testing + operator overload for String object + char*") {
    String s1("Hello");
    const String s2 = s1 + " World";
    CHECK(std::string(s2.c_str()) == "Hello World");
}

TEST_CASE("Testing += operator overload for String object + String object") {
    String s1("Hello");
    const String s2(" World");
    s1 += s2;
    CHECK(std::string(s1.c_str()) == "Hello World");
}

TEST_CASE("Testing += operator overload for String object + char*") {
    String s1("Hello");
    s1 += " World";
    CHECK(std::string(s1.c_str()) == "Hello World");
}
/*
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
*/