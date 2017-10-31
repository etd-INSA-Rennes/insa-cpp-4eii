//
//  main.cpp
//  Lab 2
//
//  Created by Thomas Bouvier on 09/10/2017.
//  Copyright © 2017 Thomas Bouvier. All rights reserved.
//

#include <iostream>

#include "MyString.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    // test of operator=
    
//    MyString s("abc");
//    s = s;
    
    // what is the difference between the three following MyString initialization ?
    
//    cout << "ch1" << endl;
//    MyString ch1("abc");
//
//    cout << "ch2" << endl;
//    MyString ch2 = "abc";
//
//    cout << "ch3" << endl;
//    MyString ch3;
//    ch3 = "abc";
    
    // test of operator[]
    
//    MyString ch1("bbb");
//    MyString ch2 = "abc";
//
//    ch1[0] = ch2[0];
//
//    cout << "ch1 = " << ch1 << endl;
    
    // ch1=abb ch2=abc
    
//    cout << (ch1 < ch2) << endl;
//    cout << (ch1 <= ch2) << endl;
//    cout << (ch1 > ch2) << endl;
//    cout << (ch1 >= ch2) << endl;
    
    // ch1=abc ch2=abc
    
//    ch1 = "abc";
//    cout << (ch1 == ch2) << endl;
    
    // toUpper
    
//    ch1.toUpper();
//    cout << ch1 << endl;
    
    // subString()
    
//    MyString ch1("abcdefghijkl");
//    cout << ch1 << endl;
//
//    MyString ch2 = ch1.subString('b', 'g');
//    cout << ch2 << endl;
//
//    MyString ch3 = ch1.subString(2, 5);
//    cout << ch3 << endl;
    
    // test of operator+
    
    MyString ch1("Hello, "), ch2("world"), ch3("!");
    
    MyString concat = ch1 + ch2 + ch3;
    
    cout << concat << endl;
    
	system("pause");
    return 0;
}
