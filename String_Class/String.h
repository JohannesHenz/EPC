//
// Created by johen on 17/09/2024.
//

#ifndef STRING_H
#define STRING_H
#include <string>


class String {

public:
    String(char* s){};
    ~String(){};
    char* c_str();
    void append(char* s);
    const int size();
    void reserve(int new_size);
    const int capacity();

private:
    char* string;
    char*[] all_strings;
    int cap;
    int size;

};



#endif //STRING_H
