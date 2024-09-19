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
   const char* c_str();
    void append(const char* s);
    const int size();
    void reserve(const int new_size);
    const int capacity();

private:
    char* data;
    int current_cap = 0;
    int current_size = 0;

    //Helfer Funktionen
    int string_length(const char* s);
    void string_copy(char* dest, const char* src);
    void string_concat(char* dest, const char* src);

};



#endif //STRING_H
