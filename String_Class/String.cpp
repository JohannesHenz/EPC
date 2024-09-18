//
// Created by johen on 17/09/2024.
//

#include "String.h"

String String(char* s) {
    str = new std::string s;
}

String ~String ()
{
    delete str;
}

void append(char* s) {
    //fügt ein char* array zu dem char*[] array hinzu
}

char* c_str() {
    //gibt ein char* zurück was alle einzelnen char* aus dem char*[] zusammenfügt
}

const int size() {
    //gibt die Anzahl der char* im char*[] zurück
}

void reserve(int new_size) {
    //ändert die Größe des char*[] arrays
}

const int capacity() {
    //gibt die Kapazität des char*[] arrays zurück
}
