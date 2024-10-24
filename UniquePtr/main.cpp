//
// Created by johen on 17/10/2024.
//
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "MyPointer.h"
#include <string>

TEST_CASE("MyPointer initialisierung und Dereferenzierung") {
    MyPointer<int> intPtr(new int(10));
    CHECK(*intPtr == 10);  // Dereferenzierungstest
}

struct Entity {
    int id;
    Entity(int id) : id(id) {}
};

TEST_CASE("MyPointer Pfeiloperator") {
    MyPointer<Entity> entityPtr(new Entity(5));
    CHECK(entityPtr->id == 5);  // Pfeiloperator-Test
}

TEST_CASE("MyPointer bool umwandlung") {
    MyPointer<int> intPtr(new int(10));
    CHECK(static_cast<bool>(intPtr) == true);  // Nicht-null-Pointer sollte true zurückgeben

    MyPointer<int> emptyPtr;
    CHECK(static_cast<bool>(emptyPtr) == false);  // Null-Pointer sollte false zurückgeben
}

TEST_CASE("MyPointer move constructor") {
    MyPointer<int> intPtr(new int(20));
    MyPointer<int> movedPtr(std::move(intPtr));

    CHECK(static_cast<bool>(intPtr) == false);  // Ursprünglicher Pointer sollte null sein
    CHECK(static_cast<bool>(movedPtr) == true);  // Verschobener Pointer sollte gültig sein
    CHECK(*movedPtr == 20);  // Verschobener Pointer sollte den Wert behalten
}

TEST_CASE("MyPointer move assignment operator") {
    MyPointer<int> intPtr(new int(30));
    MyPointer<int> assignedPtr;

    assignedPtr = std::move(intPtr);

    CHECK(static_cast<bool>(intPtr) == false);  // Ursprünglicher Pointer sollte null sein
    CHECK(static_cast<bool>(assignedPtr) == true);  // Zugewiesener Pointer sollte gültig sein
    CHECK(*assignedPtr == 30);  // Zugewiesener Pointer sollte den Wert behalten
}

TEST_CASE("MyPointer release methode") {
    MyPointer<int> intPtr(new int(40));
    int* rawPtr = intPtr.release();

    std::cout << "raw Pointer: " << *rawPtr << std::endl;
    CHECK(static_cast<bool>(intPtr) == false);  // Checkt ob nach release der Pointer null ist
    CHECK(*rawPtr == 40);  // raw Pointer sollte den Wert behalten
    delete rawPtr;  // Manuelles Aufräumen
}

TEST_CASE("MyPointer reset methode") {
    MyPointer<int> intPtr(new int(50));
    intPtr.reset(new int(60));

    CHECK(*intPtr == 60);  // Pointer sollte den neuen Wert halten

    intPtr.reset();  // Auf null zurücksetzen
    CHECK(static_cast<bool>(intPtr) == false);  // Nach reset sollte der Pointer null sein
}

TEST_CASE("reset den nullptr") {
    MyPointer<int> ptr(nullptr);
    ptr.reset();
    CHECK(static_cast<bool>(ptr) == false);
}

TEST_CASE("MyPointer swap methode") {
    MyPointer<int> ptr1(new int(70));
    MyPointer<int> ptr2(new int(80));

    ptr1.swap(ptr2);

    CHECK(*ptr1 == 80);  // Pointer sollten die Werte getauscht haben
    CHECK(*ptr2 == 70);
}

TEST_CASE("swap mit Nullptr") {
    MyPointer<int> ptr1(new int(70));
    MyPointer<int> ptr2(nullptr);

    ptr1.swap(ptr2);

    CHECK(static_cast<bool>(ptr1) == false); // Checkt ob nach release der Pointer null ist
    CHECK(*ptr2 == 70);
}

TEST_CASE("Swap hin und zurück") {
    MyPointer<int> ptr1(new int(70));
    MyPointer<int> ptr2(new int(30));

    ptr1.swap(ptr2);
    ptr1.swap(ptr2);

    CHECK(*ptr1 == 70);
    CHECK(*ptr2 == 30);
}


TEST_CASE("MyPointer swap methode mit sich selber") {
    MyPointer<int> ptr1(new int(70));
    ptr1.swap(ptr1);

    CHECK(*ptr1 == 70);  // Check ob sich die werte verändert haben
}


void customDeleter(int* ptr) {
    std::cout << "Benutzerdefinierter Deleter aufgerufen für Wert: " << *ptr << std::endl;
    delete ptr;
}

TEST_CASE("MyPointer custom deleter") {
    MyPointer<int, void(*)(int*)> intPtr(new int(90), customDeleter);
    CHECK(*intPtr == 90);  // Benutzerdefinierter Deleter sollte gesetzt und funktionsfähig sein
}


TEST_CASE("Destruktor mit nullptr") {
    MyPointer<int> ptr(nullptr);

}