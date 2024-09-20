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
    for (int i = 0; i < capacity(); i++) {
        dest[i] = src[i];
    }
    dest[capacity()] = '\0';
}


void String::append(const char* stringToAppend) {

    int new_string_size = string_length(stringToAppend);
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
        std::cout << "Length of new Data: " << string_length(new_data) << std::endl;
        string_copy(new_data, data);
        delete[] data;
        data = new_data;
        std::cout << "Length of Data: " << string_length(data) << std::endl;
        current_cap = new_size;
    }
    else {
        std::cout << "New size is smaller than current size" << std::endl;
    }


}

int String::capacity() const {
    return current_cap;
}
