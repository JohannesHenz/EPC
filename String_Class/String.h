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
    void reserve();
    int capacity();
    int size();
    std::string append(std::string str);

private:
    std::string str;
    int cap;
    int sz;

};



#endif //STRING_H
