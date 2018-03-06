//
// Created by Joanna on 05.03.2018.
//

#ifndef JIMP_EXERCISES_ARRAY2D_H
#define JIMP_EXERCISES_ARRAY2D_H



#include "stdio.h"

#include "iostream"

#include "cstdlib"



using namespace std;

int **Array2D(int wiersze, int kolumny);
void FillArray2D(int wiersze, int kolumny, int *const *tablica);
int **NewArray2D(int n_rows, int n_columns);

void DeleteArray2D(int **array, int n_rows, int n_columns);


#endif //JIMP_EXERCISES_ARRAY2D_H
