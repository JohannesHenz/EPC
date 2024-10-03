#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include "newString.h"
#include "doctest.h"

using namespace std;

//---------------------------- Operator overload --------------------
//---(s1 += s2)
TEST_CASE("testing += operator with 2 newString objects"){
    newString test1("Hello");
    const newString test2(" World");
    test1 += test2;
    CHECK(std::string(test1.c_str()) == "Hello World");
    CHECK(std::string(test2.c_str()) == " World");
}

TEST_CASE("testing += operator with the same newString object"){
    newString test1("Hello");
    test1 += test1;
    CHECK(std::string(test1.c_str()) == "HelloHello");
}

//---(s1 += "Hello")

TEST_CASE("testing += operator with const char*"){
    newString test1("Hello");
    test1 += " World";
    CHECK(std::string(test1.c_str()) == "Hello World");
}

TEST_CASE("testing += operator with own const char*"){
    newString test1("Hello");
    test1 += test1.c_str();
    CHECK(std::string(test1.c_str()) == "HelloHello");
}

TEST_CASE("testing += operator with empty string \"\""){
    newString test1("Hello");
    test1 += "";
    CHECK(std::string(test1.c_str()) == "Hello");
}

//---(s1 + s2)

TEST_CASE("testing + operator with 2 newString objects"){
    newString test1("Hello");
    const newString test2(" World");
    const newString test3 = test1 + test2;
    CHECK(std::string(test3.c_str()) == "Hello World");
    CHECK(std::string(test1.c_str()) == "Hello");
    CHECK(std::string(test2.c_str()) == " World");
}

TEST_CASE("testing + operator with the same newString object"){
    newString test1("Hello");
    const newString test2 = test1 + test1;
    CHECK(std::string(test2.c_str()) == "HelloHello");
    CHECK(std::string(test1.c_str()) == "Hello");
}

//---(s1 + "Hello")

TEST_CASE("testing + operator with const char*"){
    newString test1("Hello");
    const newString test2 = test1 + " World";
    CHECK(std::string(test2.c_str()) == "Hello World");
    CHECK(std::string(test1.c_str()) == "Hello");
}

TEST_CASE("testing + operator with own const char*"){
    newString test1("Hello");
    const newString test2 = test1 + test1.c_str();
    CHECK(std::string(test2.c_str()) == "HelloHello");
    CHECK(std::string(test1.c_str()) == "Hello");
}

TEST_CASE("testing + operator with empty string \"\""){
    newString test1("Hello");
    const newString test2 = test1 + "";
    CHECK(std::string(test1.c_str()) == "Hello");
    CHECK(std::string(test2.c_str()) == "Hello");
}

//---(puts(s1))

TEST_CASE("testing puts"){
    newString test1("Hello");
    int result = puts(test1);
    CHECK(result >= 0);
}


/*int main(){

    //------------------- Exercise 1 ------------------- // Testfälle umschreiben wie in Fprog
    cout << "\n-- Exercise 1 -- \n" << endl;

    //Test Empty String
    newString test1;

    cout << "Test string 1: " << test1.c_str() << " with length " << test1.length() << endl;

    //Test "Hello World"
    newString test2("Hello");

    cout << "Test string2: " << test2.c_str() << " with length " << test2.length() << endl;

    //Test append string directly
    newString world(" World");
    test2.append(world.c_str());
    cout << "Test append string directly: " << test2.c_str() << " with length " << test2.length() << endl;

    //Test append string via newString class
    test1.append("Hello World");
    cout << "Test append string via newString class: " << test1.c_str() << " with length " << test1.length() << endl;

    //Reserve storage
    cout << "Capacity before increasing reserve: " << test1.capacity() << endl;
    test1.reserve(20);
    cout << "Capacity after increasing reserve: " << test1.capacity() << endl;

    //Not possible to decrease reserve
    test1.reserve(5);
    cout << "Capacity after decreasingdecrease reserve: " << test1.capacity() << endl;

    //------------------- Exercise 2 -------------------

    cout << "\n-- Exercise 2 -- \n" << endl;

    newString testString1("Hello");
    newString testString2("Bye World");

    cout << "- Copy Constructor -" << endl;
    newString copyString(testString1);
    cout << "Copied Hello in copyString - copyString: " << copyString.c_str() << "\n" << endl;

    cout << "- Copy Assignment Operator -" << endl;
    cout << "TestCase: t1 = t1" << endl;
    testString1 = testString1;
    cout << "teststring1 after: " << testString1.c_str() << endl;
    cout << "TestCase: t1 = t2" << endl;
    cout << "teststring1 before: " << testString1.c_str() << endl;
    testString1 = testString2;
    cout << "teststring1 after: " << testString1.c_str() << endl;
    cout << "teststring2 after: " << testString2.c_str() << "\n" <<endl;

    cout << "- Move Constructor -" << endl;
    cout << "teststring1 before: " << testString1.c_str() << endl;
    newString testString3 = move(testString1);
    // cout << "teststring1 after: " << testString1.c_str() << endl; --> nullptr
    cout << "teststring3 after: " << testString3.c_str() << "\n" << endl;

    cout << "- Move Assignment Operator -" << endl;
    cout << "teststring2 before: " << testString2.c_str() << endl;
    newString testString4;
    testString4 = move(testString2);
    //cout << "teststring2 after: " << testString2.c_str() << endl; --> nullptr
    cout << "teststring4: " << testString4.c_str() << endl; 
}*/

