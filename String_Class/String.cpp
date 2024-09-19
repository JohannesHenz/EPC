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

int String::string_length(const char *s) const{
    //gibt die Anzahl der char* in s zurück
    int sizeOfString = 0;
    char end = '1';
    while (end != '\0') {
        sizeOfString++;
        end = s[sizeOfString];
    }
    return sizeOfString;
}

void String::string_copy(char *dest, const char *src) const{
    //kopiert den Inhalt von src in dest
    int sizeOfString = string_length(src);
    for (int i = 0; i < sizeOfString; i++) {
        dest[i] = src[i];
    }
}


void String::append(const char* s) {

    int new_string_size = string_length(s);
    if (current_size + new_string_size >= current_cap) {
        reserve(current_size + new_string_size + 1);
    }
    string_copy(data + current_size, s);
    current_size += new_string_size;
    data[current_size] = '\0';

}

const void String::c_str() const {
    //gibt ein char* zurück was alle einzelnen char* aus dem char*[] zusammenfügt
    for (int i = 0; i < current_cap; i++) {
        std::cout << data[i];
    }

}

int String::size() const {
    return current_size;
}

void String::reserve(const int new_size) {
    char* new_data = new char[new_size];
    string_copy(new_data, data);
    delete[] data;
    data = new_data;
    current_cap = new_size;
}

int String::capacity() const {
    return current_cap;
}
