//
//  MyString.hpp
//  Lab 2
//
//  Created by Thomas Bouvier on 09/10/2017.
//  Copyright © 2017 Thomas Bouvier. All rights reserved.
//

#ifndef MyString_hpp
#define MyString_hpp

#include <stdio.h>
#include <cstring>
#include <cstdlib>
#include <iostream>

#if 0
#define LOGME(x) std::cout << x << std::endl;
#else
#define LOGME(x)
#endif

class MyString {
    
    char * _first = nullptr;
    
    bool init(const char * c);
    void free();
    
public:
    
    MyString();
    MyString(const char * s);
    MyString(const MyString& s);
    
    ~MyString();
    
    void toUpper();
    
    MyString subString(char begin , char end) const;
    MyString subString(int begin , int s) const;
    
    const char * getFirst() const;
    
    char& operator[](std::size_t idx);
    const char operator[](std::size_t idx) const;
    
    MyString& operator=(const MyString& s);
};

std::ostream& operator<<(std::ostream& os, const MyString& s);

bool operator==(const MyString & s1, const MyString &s2);
bool operator<(const MyString & s1, const MyString &s2);
bool operator<=(const MyString & s1, const MyString &s2);
bool operator>(const MyString & s1, const MyString &s2);
bool operator>=(const MyString & s1, const MyString &s2);

MyString operator+(const MyString &s1, const MyString &s2);

#endif /* MyString_hpp */
