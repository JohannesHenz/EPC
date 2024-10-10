//
// Created by johen on 17/09/2024.
//

#include "String.h"


template<typename T>
String<T>::String(const T* s) {
    int initial_size = string_length(s);
    current_cap = initial_size + 1; // +1 für den Nullterminator
    current_size = initial_size;
    data = new T[current_cap]; // erstellt ein neues T-Array mit der Größe von initial_size + 1
    string_copy(data, s); // kopiert den Inhalt von s in data
}

template<typename T>
String<T>::~String() {
    delete[] data;
}

//Copy Constructor (Deep Copy)
template<typename T>
String<T>::String(const String& other) : current_size(other.current_size), current_cap(other.current_cap) {
    data = new T[current_cap];
    string_copy(data, other.data);
}

//Copy Assignment Operator (Deep Copy)
template<typename T>
String<T>& String<T>::operator=(const String& other) {
    if (this != &other) {
        delete[] data;
        data = new T[other.current_cap];
        current_size = other.current_size;
        current_cap = other.current_cap;
        string_copy(data, other.data);
    }
    return *this;
}

//Move Constructor
template<typename T>
String<T>::String(String&& other) noexcept : data(other.data), current_size(other.current_size), current_cap(other.current_cap) {
    other.data = nullptr;
    other.current_size = 0;
    other.current_cap = 0;
}

//Move Assignment Operator
template<typename T>
String<T>& String<T>::operator=(String&& other) noexcept {
    if (this != &other) {
        delete[] data;
        data = other.data;
        current_size = other.current_size;
        current_cap = other.current_cap;
        other.data = nullptr;
        other.current_size = 0;
        other.current_cap = 0;
    }
    std::cout << "Move Assignment Operator called" << std::endl;
    return *this;

}



template<typename T>
int String<T>::string_length(const T* s) const {
    int sizeOfString = 0;
    while (s[sizeOfString] != '\0') {
        sizeOfString++;
    }
    return sizeOfString;
}



template<typename T>
void String<T>::string_copy(T* dest, const T* src) const {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0'; // Ensure the null terminator is copied
}


template<typename T>
void String<T>::append(const T* stringToAppend) {
    int new_string_size = string_length(stringToAppend);
    if (current_size + new_string_size >= current_cap) {
        reserve(current_size + new_string_size);
    }
    string_copy(data + current_size, stringToAppend);
    current_size += new_string_size;
    data[current_size] = '\0';
}



template<typename T>
const T* String<T>::c_str() const {
    return data;
}


template<typename T>
int String<T>::size() const {
    return current_size;
}

template<typename T>
void String<T>::reserve(int new_size) {
    if (new_size >= current_cap) {
        T* new_data = new T[new_size + 1]; // +1 für den Nullterminator
        string_copy(new_data, data);
        delete[] data;
        data = new_data;
        current_cap = new_size + 1;
    }
}

template<typename T>
int String<T>::capacity() const {
    return current_cap;
}


template<typename T>
String<T> String<T>::operator+(const String& stringToAdd) {
    String result(*this);
    result.append(stringToAdd.c_str());
    return result;
}

template<typename T>
String<T> String<T>::operator+(const T* charPointerToAdd) {
    String result(*this);
    result.append(charPointerToAdd);
    return result;
}

template<typename T>
void String<T>::operator+=(const String& stringToAppend) {
    append(stringToAppend.c_str());
}

template<typename T>
void String<T>::operator+=(const T* charPointerToAppend) {
    append(charPointerToAppend);
}


template<typename T>
typename String<T>::Iterator String<T>::begin() const {
    return Iterator(data);
}

template<typename T>
typename String<T>::Iterator String<T>::end() const {
    return Iterator(data + current_size);
}



// Explicit template instantiation for char
template class String<char>;
