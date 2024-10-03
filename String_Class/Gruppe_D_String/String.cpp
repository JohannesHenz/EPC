//
// Created by johen on 17/09/2024.
//

#include "String.h"


String::String(const char* s) {

    int initial_size = string_length(s);
    current_cap = initial_size;
    current_size = initial_size;
    data = new char[initial_size]; //erstellt ein neues char array mit der Größe von initial_size

    string_copy(data, s); //kopiert den Inhalt von s in data
}

String::~String ()
{
    delete[] data;
}

//Copy Constructor (Deep Copy)
String::String(const String& other): current_size(other.current_size), current_cap(other.current_cap) {
    data = new char[current_cap];
    string_copy(data, other.data);
}

//Copy Assignment Operator (Deep Copy)
String &String::operator=(const String &other) {
    if (this != &other ) {
        delete[] data;
       data = new char[other.size()];
        current_size = other.size();
        current_cap = other.capacity();
        string_copy(data, other.c_str());
    }
    std::cout << "Copy Assignment Operator called" << std::endl;
    return *this;
}

//Move Constructor
String::String(String&& other) noexcept : data(other.data), current_size(other.current_size), current_cap(other.current_cap) {
    other.data = nullptr;
    other.current_size = 0;
    other.current_cap = 0;

    std::cout << "Move Constructor called" << std::endl;
}

//Move Assignment Operator
String &String::operator=(String&& other) noexcept {
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



int String::string_length(const char *s) const{
    //gibt die Anzahl der char* in s zurück

    int sizeOfString = 0;
    /*
    while (s[sizeOfString] != '\0') {
        sizeOfString++;
    }
    return sizeOfString;
    */

    char end = '1';
    while (end != '\0') {
        sizeOfString++;
        end = s[sizeOfString];
    }
    return sizeOfString;

}

void String::string_copy(char *dest, const char *src) const{
    //kopiert den Inhalt von src in dest
    /*
    for (int i = 0; i < capacity(); i++) {
        dest[i] = src[i];
    }
    dest[capacity()] = '\0';
    */
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0'; // Ensure the null terminator is copied
}


void String::append(const char* stringToAppend) {
    const int new_string_size = string_length(stringToAppend);
    if (current_size + new_string_size >= current_cap) {
        reserve(current_size + new_string_size);
    }
    string_copy(data + current_size, stringToAppend);
    current_size += new_string_size;
    data[current_size] = '\0';

}

const char* String::c_str() const {
    //gibt ein char* zurück was alle einzelnen char* aus dem char*[] zusammenfügt
    return data;

}

int String::size() const {
    return current_size;
}

void String::reserve(const int new_size) {
    if (new_size >= current_cap) {
        char* new_data = new char[new_size];
        //std::cout << "Length of new Data: " << string_length(new_data) << std::endl;
        string_copy(new_data, data);
        delete[] data;
        data = new_data;
        //std::cout << "Length of Data: " << string_length(data) << std::endl;
        current_cap = new_size;
    }
    else {
        std::cout << "New size is smaller than current size" << std::endl;
    }


}

int String::capacity() const {
    return current_cap;
}


//TEST CASE 1
String String::operator+(const String& stringToAdd) {
    this->append(stringToAdd.c_str());
    std::cout << "Added string: " << this->c_str() << std::endl;
    return *this;
}
//TEST CASE 2
String String::operator+(const char* charPointerToAdd) {
    this->append(charPointerToAdd);
    return *this;
}
//TEST CASE 3
void String::operator+=(const String& stringToAppend) {
    this->append(stringToAppend.c_str());
    //return *this;
}
//TEST CASE 4
void String::operator+=(const char* charPointerToAppend) {
    this->append(charPointerToAppend);
   // return *this;
}
