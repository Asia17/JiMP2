//
// Created by Joanna on 05.03.2018.
//

#include "GreatestProduct.h"

int main()
{
    string dane_wejsciowe;
    vector <int> vektorek;
    cout << "Podaj liczby, z ktorych chcesz wybrac iloczyn,wcisnij enter zeby skonczyc: " << endl;
    getline(cin,dane_wejsciowe);
    while(true){
        if(dane_wejsciowe.length()!=0){
            stringstream ss; // Strumień do napisów
            ss << dane_wejsciowe;
            int wpisane_liczy; // Zmienna do przechowania liczby
            ss >> wpisane_liczy;
            vektorek.push_back(wpisane_liczy);
            getline(cin,dane_wejsciowe);
        }
        else {
            break;
        }
    }
    cout << "Najwiekszy iloczyn to " << GreatestProduct(vektorek, 2);

    return 0;
}