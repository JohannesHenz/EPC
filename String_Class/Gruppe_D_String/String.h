//
// Created by johen on 17/09/2024.
//

#ifndef STRING_H
#define STRING_H
#include <iostream>
#include <string>


class String {

public:
    String(const char* s);
    ~String();
    String(const String& other); //Copy Constructor
    String& operator=(const String& other); //Copy AssignmentOperator
    String(String&& other) noexcept; //Move Constructor
    String& operator=(String&& other) noexcept; //Move Assignment Operator
    const char* c_str() const;
    void append(const char* stringToAppend);
    int size() const;
    void reserve(int new_size);
    int capacity () const;



    String operator+(const String& stringToAdd);
    String operator+(const char* charPointerToAdd);

    void operator+=(const String& stringToAppend);
    void operator+=(const char* charPointerToAppend);



private:
    char* data;
    int current_cap = 0;
    int current_size = 0;

    //Helfer Funktionen
    int string_length(const char* s) const;
    void string_copy(char* dest, const char* src) const;
};



#endif //STRING_H
