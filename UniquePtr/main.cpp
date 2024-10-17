//
// Created by johen on 17/10/2024.
//
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "MyPointer.h"
#include <string>


TEST_CASE("MyPointer initialization and dereference") {
    MyPointer<int> intPtr(new int(10));
    CHECK(*intPtr == 10);  // Dereference test
}

struct Entity {
    int id;
    Entity(int id) : id(id) {}
};

TEST_CASE("MyPointer arrow operator") {
    MyPointer<Entity> entityPtr(new Entity(5));
    CHECK(entityPtr->id == 5);  // Arrow operator test
}


TEST_CASE("MyPointer boolean conversion") {
    MyPointer<int> intPtr(new int(10));
    CHECK(static_cast<bool>(intPtr) == true);  // Non-null pointer should return true

    MyPointer<int> emptyPtr;
    CHECK(static_cast<bool>(emptyPtr) == false);  // Null pointer should return false
}


TEST_CASE("MyPointer move constructor") {
    MyPointer<int> intPtr(new int(20));
    MyPointer<int> movedPtr(std::move(intPtr));

    CHECK(static_cast<bool>(intPtr) == false);  // Original pointer should be null
    CHECK(static_cast<bool>(movedPtr) == true);  // Moved pointer should be valid
    CHECK(*movedPtr == 20);  // Moved pointer should retain the value
}


TEST_CASE("MyPointer move assignment operator") {
    MyPointer<int> intPtr(new int(30));
    MyPointer<int> assignedPtr;

    assignedPtr = std::move(intPtr);

    CHECK(static_cast<bool>(intPtr) == false);  // Original pointer should be null
    CHECK(static_cast<bool>(assignedPtr) == true);  // Assigned pointer should be valid
    CHECK(*assignedPtr == 30);  // Assigned pointer should retain the value
}


TEST_CASE("MyPointer release method") {
    MyPointer<int> intPtr(new int(40));
    int* rawPtr = intPtr.release();

    CHECK(static_cast<bool>(intPtr) == false);  // After release, pointer should be null
    CHECK(*rawPtr == 40);  // Raw pointer should retain the value
    delete rawPtr;  // Clean up manually
}

TEST_CASE("MyPointer reset method") {
    MyPointer<int> intPtr(new int(50));
    intPtr.reset(new int(60));

    CHECK(*intPtr == 60);  // Pointer should hold the new value

    intPtr.reset();  // Reset to null
    CHECK(static_cast<bool>(intPtr) == false);  // After reset, pointer should be null
}


TEST_CASE("MyPointer swap method") {
    MyPointer<int> ptr1(new int(70));
    MyPointer<int> ptr2(new int(80));

    ptr1.swap(ptr2);

    CHECK(*ptr1 == 80);  // Pointers should have swapped values
    CHECK(*ptr2 == 70);
}


void customDeleter(int* ptr) {
    std::cout << "Custom deleter called for value: " << *ptr << std::endl;
    delete ptr;
}

TEST_CASE("MyPointer custom deleter") {
    MyPointer<int, void(*)(int*)> intPtr(new int(90), customDeleter);
    CHECK(*intPtr == 90);  // Custom deleter should be set and functional
}


/*
TEST_CASE("MyPointer initialisieren und operatoren ausprobieren") {
    MyPointer<int> intPtr(new int(10));
    CHECK(*intPtr == 10);
    CHECK(intPtr.operator->() != nullptr);
    CHECK(static_cast<bool>(intPtr) == true);

    MyPointer<int> emptyPtr;
    CHECK(static_cast<bool>(emptyPtr) == false);
}

TEST_CASE("MyPointer move semantics") {
    MyPointer<int> intPtr(new int(20));
    MyPointer<int> movedPtr(std::move(intPtr));
    CHECK(static_cast<bool>(intPtr) == false);
    CHECK(static_cast<bool>(movedPtr) == true);
    CHECK(*movedPtr == 20);

    MyPointer<int> assignedPtr;
    assignedPtr = std::move(movedPtr);
    CHECK(static_cast<bool>(movedPtr) == false);
    CHECK(static_cast<bool>(assignedPtr) == true);
    CHECK(*assignedPtr == 20);
}

TEST_CASE("MyPointer release and reset") {
    MyPointer<int> intPtr(new int(30));
    int* rawPtr = intPtr.release();
    CHECK(static_cast<bool>(intPtr) == false);
    CHECK(*rawPtr == 30);
    delete rawPtr;

    intPtr.reset(new int(40));
    CHECK(static_cast<bool>(intPtr) == true);
    CHECK(*intPtr == 40);
    intPtr.reset();
    CHECK(static_cast<bool>(intPtr) == false);
}

TEST_CASE("MyPointer swap") {
    MyPointer<int> ptr1(new int(50));
    MyPointer<int> ptr2(new int(60));
    ptr1.swap(ptr2);
    CHECK(*ptr1 == 60);
    CHECK(*ptr2 == 50);
}
*/
