//
// Created by johen on 17/09/2024.
//

#ifndef STRING_H
#define STRING_H
#include <iostream>
#include <string>

template<typename T>

class String {

public:
    class Iterator;
    String(const T* s);
    ~String();
    String(const String& other); // Copy Constructor
    String& operator=(const String& other); // Copy Assignment Operator
    String(String&& other) noexcept; // Move Constructor
    String& operator=(String&& other) noexcept; // Move Assignment Operator
    const T* c_str() const;
    void append(const T* stringToAppend);
    int size() const;
    void reserve(int new_size);
    int capacity() const;

    String operator+(const String& stringToAdd);
    String operator+(const T* charPointerToAdd);

    void operator+=(const String& stringToAppend);
    void operator+=(const T* charPointerToAppend);



    Iterator begin() const;
    Iterator end() const;

    class Iterator {
    public:

        using iterator_category = std::forward_iterator_tag; // Definiert den Iterator als Forward-Iterator (checkt welche Operationen möglich sind)
        using value_type = T; // Definiert den Typ der Elemente, auf die der Iterator zeigt (hier char)
        using difference_type = std::ptrdiff_t; // Definiert den Typ für die Differenz zweier Pointer
        using pointer = T*; // Definiert den Typ für den Zugriff auf die Elemente
        using reference = T&; // Definiert den Typ für den Zugriff auf die Elemente


        Iterator(T* ptr) : current(ptr) {}

        // Überladene Operatoren für den Iterator
        Iterator& operator++() { ++current; return *this; } // Prefix-Inkrement
        Iterator operator++(int) { Iterator temp = *this; ++(*this); return temp; } // Postfix-Inkrement
        Iterator& operator--() { --current; return *this; } // Prefix-Dekrement
        Iterator operator--(int) { Iterator temp = *this; --(*this); return temp; } // Postfix-Dekrement

        bool operator==(const Iterator& other) const { return current == other.current; }
        bool operator!=(const Iterator& other) const { return current != other.current; }

        T& operator*() const { return *current; }
        T* operator->() const { return current; }

    private:
        T* current;
    };
private:
    T* data;
    int current_cap = 0;
    int current_size = 0;

    // Helfer Funktionen
    int string_length(const T* s) const;
    void string_copy(T* dest, const T* src) const;
};



#endif //STRING_H
