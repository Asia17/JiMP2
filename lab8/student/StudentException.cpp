//
// Created by Joanna on 06.05.2018.
//
#include <set>
#include <regex>
#include "StudentException.h"
namespace academia{

     void Student::ValidateWiek(int wiek) {
         if (wiek <= 10 || wiek >= 100){
             throw InvalidAge(wiek);
         }
     }

    void Student::ValidateKierunek(const std::string &kierunek) {
        std::set<std::string> check_kierunek={"fizyka","filozofia"};

    auto znalezione = check_kierunek.find(kierunek);
        if (znalezione == check_kierunek.end()){
            throw InvalidProgram(kierunek);
        }
    }

    void Student::ValidateZnaki(const std::string &imie_nazwisko) {
        std::regex patern  {"[a-z A-Z]*"};
        if(!std::regex_match(imie_nazwisko,patern)){
            throw InvalidNameCharacter(imie_nazwisko);
        }};

    void Student::ValidateFormat(const std::string &imie_nazwisko) {
        std::regex patern {"(([A-Z][a-z]+) ?)+"};
        if (!std::regex_match(imie_nazwisko,patern)||imie_nazwisko.length()==0){
            throw InvalidNameSurname(imie_nazwisko);
        }
    }
}