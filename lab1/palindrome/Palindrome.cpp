//
// Created by Joanna on 03.03.2018.
//

#include "Palindrome.h"
#include <string>

bool is_palindrome(std::string str){
   // const char *characters = str.c_str(); //uzyskanie z obiektu string wskaźnika na poszczególne znaki
    int i,j;
    for (i=0, j=str.length()-1; i<j; i++, j--)
        if (str[i] != str[j]) return false;

    if (i<j) return false;
    else return true;


}

