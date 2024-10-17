//
// Created by johen on 17/10/2024.
//

#ifndef MYPOINTER_H
#define MYPOINTER_H


template<typename T>
class MyPointer {

public:
    MyPointer(); // Default Constructor
    MyPointer(T *ptr); // Constructor
    ~MyPointer(); // Destructor
    MyPointer(MyPointer&& other) noexcept; // Move Constructor
    MyPointer& operator=(MyPointer&& other) noexcept; // Move Assignment Operator

    MyPointer(const MyPointer& other) = delete; //Copy Constructor = delete
    MyPointer& operator=(const MyPointer& other) = delete; //Copy Assignment Constructor = delete

    T& operator*() const; // Dereferenzierungs Operator
    T* operator->() const; // Pfeil Operator
    explicit operator bool() const; // Bool Operator

    T* release(); // Release Methode
    void reset(T* newPtr = nullptr); // Reset Methode
    void swap(MyPointer& other); // Swap Methode


private:
     T* ptr;
};



#endif //MYPOINTER_H
