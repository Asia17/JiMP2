//
// Created by Joanna on 05.03.2018.
//

#include "ReverseString.h"

string Reverse(string str)
{
    long length=str.size();
    string new_word, character;

    for (int i = 0; i < length; i++)
    {
        character = str[length-1-i];
        new_word.append(character);
    }
    return new_word;
}