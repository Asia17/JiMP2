//
// Created by Joanna on 03.03.2018.
//
#include <cstdint>
#include <string>
#include <iostream>
#include "DoubleBasePalindromes.h"

int main() {
    int liczba;
    bool flag = true;
    while (flag){
        std::cout << "Wpisz liczbe: " <<  std::endl;
        std::cin >> liczba;
        if (liczba < 0 or liczba > 1000000){
            std::cout << "Bledny  zakres, wpisz jeszcze raz: " <<  std::endl;
        }
        else{
            flag = false;
        }
    }
    int result = DoubleBasePalindromes(liczba);
    std::cout << result  <<  std::endl;
    return 0;
}


