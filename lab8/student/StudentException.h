//
// Created by Joanna on 06.05.2018.
//

#ifndef JIMP_EXERCISES_STUDENTEXCEPTION_H
#define JIMP_EXERCISES_STUDENTEXCEPTION_H

#include <exception>
#include <stdexcept>

namespace academia{
    class Student {
    private:
        std::string imie_;
        std::string nazwisko_;
        std::string kierunek_;
        int wiek_;
        void ValidateWiek(int wiek);
        void ValidateKierunek(const std::string &kierunek);
        void ValidateZnaki(const std::string &imie_nazwisko);
        void ValidateFormat(const std::string &imie_nazwisko);
    public:
        Student(const std::string &imie, const std::string &nazwisko,const std::string &kierunek,int wiek):
        imie_(imie),nazwisko_(nazwisko),kierunek_(kierunek),wiek_(wiek){
            ValidateWiek(wiek);
            ValidateKierunek(kierunek);
            ValidateZnaki(imie);
            ValidateZnaki(nazwisko);
            ValidateFormat(imie);
            ValidateFormat(nazwisko);
        };

    };


////////////////////WYJĄTKI////////////////////////////
    class InvalidNameSurname : public std::invalid_argument{
    public:
        InvalidNameSurname(std::string name_surname) : invalid_argument("Zle imie lub nazwisko: "+name_surname) {};
    }; // zły format

    class InvalidNameCharacter : public std::invalid_argument{
    public:
        InvalidNameCharacter(std::string name) : invalid_argument("Zly znak: "+name) {};
    };

    class InvalidAge : public std::invalid_argument{
    public:
        InvalidAge(int age) : invalid_argument("Zly wiek"+std::to_string(age)) {};
    };

    class InvalidProgram: public std::invalid_argument{
    public:
        InvalidProgram(std::string program) : invalid_argument("Zly program"+program) {};
    };
}


#endif //JIMP_EXERCISES_STUDENTEXCEPTION_H
