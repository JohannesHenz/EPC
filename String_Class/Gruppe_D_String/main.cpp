#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>
#include "doctest.h"
#include "String.h"

TEST_CASE("Testing String constructor") {
    String<char> s("Hello");
    CHECK(std::string(s.c_str()) == "Hello");
}

TEST_CASE("Testing the begin method") {
    String<char> s("Hello");
    String<char>::Iterator it = s.begin();
    CHECK(*it == 'H');
}

TEST_CASE("Testing the end method") {
    String<char> s("Hello");
    String<char>::Iterator it = s.end();
    CHECK(*it == '\0');
}

TEST_CASE("Test the iteration with cout") {
    String<char> s("Hello");
    for (String<char>::Iterator it = s.begin(); it != s.end(); ++it) {
        std::cout << *it;
    }
    std::cout << std::endl;
}

TEST_CASE("Iterate over String with self implemented iterator and check if it matches the expected result") {
    const String<char> test("Hello");
    std::string result;
    for (String<char>::Iterator it = test.begin(); it != test.end(); ++it) {
        result += *it;
    }
    CHECK(result == "Hello");
}
    TEST_CASE("Testing std::find with String iterator") {
        const String<char> test("Hello World");
        auto it = std::find(test.begin(), test.end(), 'W');
        CHECK(*it == 'W');
    }

TEST_CASE("Testing std::find with String iterator") {
    const String<char> test("World World");
    auto it = std::find(test.begin(), test.end(), 'W');
    CHECK(*it == 'W');
}

TEST_CASE("std::find fails to find the element") {
    const String<char> test("Hello World");
    auto it = std::find(test.begin(), test.end(), 'Z');
    CHECK(it == test.end());
}

TEST_CASE("Testing the != operator overload for the Iterator") {
    String<char> s("Hello");
    String<char>::Iterator it = s.begin();
    CHECK(it != s.end());
}

TEST_CASE("Testing the == operator overload for the Iterator") {
    String<char> s("Hello");
    String<char>::Iterator it = s.begin();
    it++;
    it++;
    it++;
    it++;
    it++;
    CHECK(it == s.end());
}

TEST_CASE("Testing the * operator overload for the Iterator") {
    String<char> s("Hello");
    String<char>::Iterator it = s.begin();
    CHECK(*it == 'H');
}

TEST_CASE("Testing the -> operator overload for the Iterator") {
    String<char> s("Hello");
    String<char>::Iterator it = s.begin();
    CHECK(it.operator->() == &s.c_str()[0]);
}


///// Previous Tests
TEST_CASE("Testing + operator overload for String object + String object") {
    String<char> s1("Hello");
    String<char> s2(" World");
    const String<char> s3 = s1 + s2;
    CHECK(std::string(s3.c_str()) == "Hello World");
}

TEST_CASE("Testing + operator overload for String object + char*") {
    String<char> s1("Hello");
    const String<char> s2 = s1 + " World";
    CHECK(std::string(s2.c_str()) == "Hello World");
}

TEST_CASE("Testing += operator overload for String object + String object") {
    String<char> s1("Hello");
    String<char> s2(" World");
    s1 += s2;
    CHECK(std::string(s1.c_str()) == "Hello World");
}

TEST_CASE("Testing += operator overload for String object + char*") {
    String<char> s1("Hello");
    s1 += " World";
    CHECK(std::string(s1.c_str()) == "Hello World");
}











/*
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