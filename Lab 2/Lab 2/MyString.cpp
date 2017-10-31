//
//  MyString.cpp
//  Lab 2
//
//  Created by Thomas Bouvier on 09/10/2017.
//  Copyright © 2017 Thomas Bouvier. All rights reserved.
//

#include "MyString.hpp"

using namespace std;

MyString::MyString() {
    LOGME("--Default constructor MyString()");
}

MyString::MyString(const char * s) {
    LOGME("--Constructor MyString(const char * s)");
    
    init(s);
}

MyString::MyString(const MyString& s) {
    LOGME("--Constructor MyString(const MyString& s)");
    
    init(s.getFirst());
}

bool MyString::init(const char * c) {
    if (c == _first)
        return false;
    
    const size_t length = strlen(c) + 1;
    _first = new char[length];
    strcpy(_first, c);
    
    return true;
}

void MyString::free() {
    delete[] _first;
}

MyString::~MyString() {
    LOGME("--Destructor");
    
    free();
}

void MyString::toUpper() {
    for (size_t i = 0; i < strlen(_first); ++i)
        _first[i] = toupper(_first[i]);
}

MyString MyString::subString(char begin, char end) const {
    int beginPos = -1, endPos = -1;
    
    // find the first char position
    
    for (size_t i = 0; i < strlen(_first); ++i) {
        if (_first[i] == begin) {
            beginPos = (int) i;
            break;
        }
    }
    
    if (beginPos < 0)
        return MyString();
    
    // find the end char position
    
    for (size_t i = beginPos; i < strlen(_first); ++i) {
        if (_first[i] == end) {
            endPos = (int) i;
            break;
        }
    }
    
    if (endPos < 0)
        endPos = (int) strlen(_first) - 1;
    
    return subString(beginPos, endPos - beginPos + 1);
}

MyString MyString::subString(int begin, int s) const {
    if (begin < 0)
        return MyString();
    
    if ((int) (begin + s) > (int) strlen(_first))
        s = (int) strlen(_first) - begin;
    
    // extract substring
    
    char * subString = (char *) alloca(s + 1);
    strncpy(subString, _first + begin, s);
    subString[s] = '\0';
    
    return MyString(subString);
}

inline const char * MyString::getFirst() const {
    return _first;
}

char& MyString::operator[](std::size_t idx) {
    LOGME("--Operator[]");
    
    if (idx < strlen(_first))
        return _first[idx];
    
    throw out_of_range("OUT OF RANGE");
}

const char MyString::operator[](std::size_t idx) const {
    LOGME("--Operator[] const");
    
    if (idx < strlen(_first))
        return _first[idx];
    
    throw out_of_range("OUT OF RANGE");
}

MyString& MyString::operator=(const MyString& s) {
    LOGME("--Operator=");
    
    if (this != &s) {
        free();
        
        init(s.getFirst());
    }
    
    return *this;
}

std::ostream& operator<<(std::ostream& os, const MyString& s) {
    os << s.getFirst();
    
    return os;
}

bool operator==(const MyString& s1, const MyString& s2) {
    return strcmp(s1.getFirst(), s2.getFirst()) == 0;
}

bool operator<(const MyString& s1, const MyString& s2) {
    return strcmp(s1.getFirst(), s2.getFirst()) < 0;
}

bool operator<=(const MyString& s1, const MyString& s2) {
    return strcmp(s1.getFirst(), s2.getFirst()) <= 0;
}

bool operator>(const MyString& s1, const MyString& s2) {
    return strcmp(s1.getFirst(), s2.getFirst()) > 0;
}

bool operator>=(const MyString& s1, const MyString& s2) {
    return strcmp(s1.getFirst(), s2.getFirst()) >= 0;
}

MyString operator+(const MyString& s1, const MyString& s2) {
	size_t length = strlen(s1.getFirst()) + strlen(s2.getFirst());
    char * str = (char *) alloca(length + 1);
    
    strcpy(str, s1.getFirst());
    strcat(str, s2.getFirst());

    return MyString(str);
}
