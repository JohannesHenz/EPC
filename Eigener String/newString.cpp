#include <iostream>
#include "newString.h"

//---------- Needed to get length from input String ----------
size_t newString::getLength(const char* input){
    size_t tempLen = 0;
    while(input[tempLen] != '\0'){ // '\0' character to end string 
        tempLen++;
    }

    return tempLen;
}

// ---------- Needed to to copy string ----------
void newString::copyString(char*  thisString, const char* source){
    size_t i = 0;

    for(;source[i] != '\0'; i++){
        thisString[i] = source[i];
    }

    thisString[i] = '\0';
}

//---------- Constructor ----------
/*newString::newString(){
    str = nullptr;
    len = 0;
    currentCapacity = 0;
}*/

newString::newString(const char* initStr){
    this->len = getLength(initStr);
    this->currentCapacity = this->len;
    str = new char[this->len+1]; //String is one char longer than actual string because of '\0' - mentioned earlier
    copyString(str, initStr);
}

//----------- Rule of Five -----------
//Destructor
newString::~newString(){
    delete[] str;
    //std::cout << "Destructor is called" << std::endl;
}

//Copy Constructor (Deep copy)
newString::newString(const newString& other): len(other.len), currentCapacity(other.currentCapacity){
    std::cout << "Copy Constructor is called" << std::endl;
    //Declaration also possible like...
    //this->len = other.len;
    //this->currentCapacity = other.currentCapacity;
    str = new char[currentCapacity];
    copyString(str, other.str);
} 

//Copy AssignmentOperator (Deep copy)
newString& newString::operator=(const newString& other){

    if(this != &other){ // statt delete/new --> pointer?
        delete[] str;
        str = new char[other.size()];
        len = other.size();
        currentCapacity = other.capacity();
        copyString(str, other.c_str());
    }

    std::cout << "Copy AssignmentOperator is called" << std::endl;
    return *this;
} 

//Move Constructor
newString::newString(newString&& other) noexcept: str(other.str), len(other.len), currentCapacity(other.currentCapacity){

    other.str = nullptr;
    other.len = 0;
    other.currentCapacity = 0;

    std::cout << "Move Constructor is called" << std::endl;
}

//Move Assignment Operator
newString& newString::operator=(newString&& other) noexcept{
    if(this != &other){
        delete[] str;
        str = other.str;
        len = other.size();
        currentCapacity = other.capacity();
        other.str = nullptr;
        other.len = 0;
        other.currentCapacity = 0;
    }

    std::cout << "Move AssignmentOperator is called" << std::endl;
    return *this;
}



//---------- Exercise specific ----------
void newString::append(const char* stringToAppend){
    
    //Calculate new length
    size_t newLength = len + getLength(stringToAppend);

    //If current storage is not enough reserve space
    if(newLength+1 > currentCapacity){
        reserve(newLength+1);
    }

    int i = 0;
    while(stringToAppend[i] != '\0'){
        str[len+i] = stringToAppend[i];
        ++i;
    }

    str[newLength] = '\0';

    len = newLength; 

}

const char* newString::c_str() const{
    /*if(str == nullptr){
        return "";
    }
    */
    return str;
}

size_t newString::length() const{
    return len;
}
size_t newString::size() const{
    return len;
}


//---------- Bonus ----------
void newString::reserve(size_t newCapacity){
    if(newCapacity <= currentCapacity){
        return;
    }


    //Initialize new arraw with new Length
    char* newStr = new char[newCapacity];

    copyString(newStr, str);

    //Delete old save data
    delete[] str;

    //Set new Capacity
    str = newStr;
    currentCapacity = newCapacity;
}

size_t newString::capacity() const{
 return currentCapacity;
}



