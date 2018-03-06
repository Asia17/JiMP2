//
// Created by Joanna on 05.03.2018.
//

#include "Array2D.h"
int main()
{
    int wiersze, kolumny;
    cout<<"liczba wierszy: ";
    cin>>wiersze;
    cout<<"liczba kolumn: ";
    cin>>kolumny;

    int ** tablica= Array2D(wiersze, kolumny);
    DeleteArray2D(tablica, wiersze, kolumny); // zwolnienie pamięci

    return 0;

}