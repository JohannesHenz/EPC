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
    const void c_str() const;
    void append(const char* s);
    int size() const;
    void reserve(const int new_size);
    int capacity () const;

private:
    char* data;
    int current_cap = 0;
    int current_size = 0;

    //Helfer Funktionen
    int string_length(const char* s) const;
    void string_copy(char* dest, const char* src) const;
};



#endif //STRING_H
