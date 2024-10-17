//
// Created by johen on 17/10/2024.
//

#include "MyPointer.h"

#include <string>

//Default Constructor
template<typename T>
::MyPointer<T>::MyPointer() {
    ptr = nullptr;
}

//Argument Constructor
template<typename T>
MyPointer<T>::MyPointer(T* ptr) : ptr(ptr) {}



// Destructor
template<typename T>
MyPointer<T>::~MyPointer() {
    if (ptr != nullptr) {
        delete ptr;
    }
}

// Move Constructor
template<typename T>
MyPointer<T>::MyPointer(MyPointer &&other) noexcept : ptr(other.ptr) {
    other.ptr = nullptr;

}

//Move Assignment Constructor
template<typename T>
MyPointer<T> &MyPointer<T>::operator=(MyPointer &&other) noexcept {
    if (this != &other) {
        reset();
        ptr = other.ptr;
        other.ptr = nullptr;
    }
    return *this;
}

//* Operator
template<typename T>
T &MyPointer<T>::operator*() const {
    return *ptr;
}

// Pfeil Operator
template<typename T>
T *MyPointer<T>::operator->() const {
    return ptr;
}

//Bool Operator (returned true wenn der ptr nicht nullptr ist
template<typename T>
MyPointer<T>::operator bool() const {
    return ptr != nullptr;
}

//Release Methode setzt den alten Pointer frei und gibt einen neuen zurück
template<typename T>
T *MyPointer<T>::release() {
    T* oldPtr = ptr;
    ptr = nullptr;
    return oldPtr;
}

// Reset Methode setzt den alten Pointer auf den im Argument gegebenen neuen Pointer
template<typename T>
void MyPointer<T>::reset(T *newPtr) {
    if (ptr) {
        delete ptr;
    }
    ptr = newPtr;
}

// Swap Methode tauscht den alter Pointer mit dem Pointer aus dem Argument
template<typename T>
void MyPointer<T>::swap(MyPointer &other) {
    T* temp = ptr;
    ptr = other.ptr;
    other.ptr = temp;
}

// Explicit template instantiation für die Testzwecke
template class MyPointer<int>;
template class MyPointer<std::string>;