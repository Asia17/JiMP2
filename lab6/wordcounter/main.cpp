//
// Created by Joanna on 18.04.2018.
//

#include <iostream>
#include <fstream>

#include "WordCounter.h"

using namespace datastructures;
int main(){
    std::ifstream is("myfile.txt");
    WordCounter wc = WordCounter::FromInputStream(&is) ;
    // w zmiennej ilość powinna znaleźć się ilość powtórzeń
    // słowa "programowanie" w pliku "myfile.txt"
    //int ilosc = wc["programowanie"];
    //std::cout<<ilosc;
    std::cout<<wc;
    return 0;
}