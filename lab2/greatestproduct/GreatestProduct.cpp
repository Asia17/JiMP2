//
// Created by Joanna on 05.03.2018.
//

#include "GreatestProduct.h"



int GreatestProduct(const vector <int> &numbers, int k)
{
    //ustawiam max1 i max2 na najmniejsze mozliwe inty #include <limits>
    int max1 = numeric_limits<int>::lowest(), max2=numeric_limits<int>::lowest(), tmp;
    //cout << max1 << " i " << max2 << endl; dolny zakres inta

    for(int wartosc_z_input : numbers) // przechodzenie przez wartości w wektorze(wartosci wpisane przez użytkownika)
    {
        if(wartosc_z_input>max1){
            max1 = wartosc_z_input;
        }
        if(max2<max1){
            tmp = max2;
            max2 = max1;
            max1 = tmp;
        }
    }
    cout << max1 << " i " << max2 << endl;
    cout << max1*max2 << endl;
    return max1*max2;
}