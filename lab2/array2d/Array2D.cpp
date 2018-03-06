//
// Created by Joanna on 05.03.2018.
//

#include "Array2D.h"


int **NewArray2D(int wiersze, int kolumny);

void FillArray2D(int wiersze, int kolumny, int *const *tablica);

void DeleteArray2D(int **array, int n_rows, int n_columns)  // zwolnienie pamięci
{

    for (int i=0; i<n_rows; i++)
    {
        delete [] array [i];
    }
    delete [] array;
}
void ShowArray(int **tablica, int wiersze, int kolumny) // wypełnienie pamięci
{
    for (int i=0; i<wiersze; i++)
    {
        for(int j=0;j<kolumny;j++)
        {
            cout<<tablica[i][j]<<" "; // wyświetlenie tablicy
        }
        cout<<endl;
    }
}
int **Array2D(int wiersze, int kolumny)
{
    if ((wiersze<=0)||(kolumny<=0)) //błędne dane
        return nullptr;


    int **tablica = NewArray2D(wiersze, kolumny);  // alokacja pamięci
    int k=1;
    FillArray2D(wiersze, kolumny, tablica);
    ShowArray(tablica, wiersze, kolumny);
    return tablica;

}

void FillArray2D(int wiersze, int kolumny, int *const *tablica) {
    int k = 1;
    for (int i=0; i < wiersze; i++)
    {
        for (int j=0;j<kolumny; j++)
        {
            tablica[i][j]=k;  // wypełnienie tablicy
            k++;
        }
    }
}

int **NewArray2D(int wiersze, int kolumny) {
    int k=1;
    int **tablica = new int *[wiersze]; // alokacja pamięci
    for (int i=0; i< wiersze; i++)
        tablica[i]=new int [kolumny];
    return tablica;
}