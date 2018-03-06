//
// Created by Joanna on 03.03.2018.
//
#include <iostream>
#include "Palindrome.h"

int main() {

    std::string wyraz;
    int menu;
    std::cout << "Menu: " <<  std::endl;
    std::cout << "1.Sprawdz palindorom (wpisz 1) " <<  std::endl;
    std::cout << "2.Wyjscie  (wpisz 2) " <<  std::endl;
    while (true){
        std::cout << "Wpisz odpowiednia cyfre: " <<  std::endl;
        std::cin >> menu;
        if (menu == 1){
            std::cout << "Wpisz wyraz do sprawdzenia: " <<  std::endl;
            std::cin >>  wyraz;
            bool check = is_palindrome(wyraz);
            if (check) {
                std::cout << "To jest palindrom" << std::endl;
                break;
            }
            else{
                    std::cout << "To nie jest palindrom" <<  std::endl;
                    break;
            }

        }

        if (menu == 2) exit(0);
        if (menu != 1 && menu !=2) std::cout << "Bledna cyfra, wprowadz jeszcze raz: " <<  std::endl;
    }

    return 0;
}