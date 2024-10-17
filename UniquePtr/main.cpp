//
// Created by johen on 17/10/2024.
//
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "MyPointer.h"
#include <string>

struct Entity {
    int id;
    Entity(int id) : id(id) {}
};

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
