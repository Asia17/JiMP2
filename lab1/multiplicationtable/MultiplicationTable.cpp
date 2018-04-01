//
// Created by Joanna on 01.04.2018.
//
#include <iostream>
#include "MultiplicationTable.h"
void MultiplicationTable(int tab[][10]) {
    int x, y;
    for (x = 0; x < 10; x++) {
        for (y = 0; y < 10; y++) {
            tab[x][y] = (x+1)*(y+1);



        }
    }
    Show(tab);

}
void Show(int tab[][10]){
    int x,y;
    for (x=0;x<10;x++){
            for(y=0;y<10;y++){
                std::cout << tab[x][y] << " ";
        }
            std::cout << "\n";

    }



    }






