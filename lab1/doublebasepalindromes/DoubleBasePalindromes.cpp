//
// Created by Joanna on 03.03.2018.
//

#include "DoubleBasePalindromes.h"
#include <cstdint>
#include <string>
#include <iostream>

uint64_t DoubleBasePalindromes(int max_vaule_exculsive){
    int suma = 0;
    int sprawdzana;
    int licznik;
    for (licznik=0; licznik <= max_vaule_exculsive; licznik++){
        sprawdzana = licznik;
        std::string tmp;
        sprintf((char*)tmp.c_str(), "%d", sprawdzana);
        std::string str = tmp.c_str();
        int i,j;

        bool czy10palindrom = true;
        bool czy2palindrom = true;
        for (i=0, j=str.length()-1; i<j; i++, j--){
            if (str[i] != str[j])  czy10palindrom = false;
        };

        if (czy10palindrom){
            std::string binarna = "";
            do{
                if ((sprawdzana%2) == 1)
                    binarna = '1'+binarna;
                else
                    binarna = '0'+binarna;
                sprawdzana /= 2;
            }while (sprawdzana != 0);
            int x,y;
            //bool czy2palindrom;
            for (x=0, y=binarna.length()-1; x<y; x++, y--){
                if (binarna[x] != binarna[y])  czy2palindrom = false;
            };
        }
        if (czy10palindrom && czy2palindrom){
            suma += licznik;
        }
    }
    return suma;
}
