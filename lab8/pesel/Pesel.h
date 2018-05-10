#ifndef JIMP_EXERCISES_PESEL_H
#define JIMP_EXERCISES_PESEL_H

#include <iostream>
#include <stdexcept>
#include <string.h>
#include <sstream>

using namespace std;

namespace academia {

    class AcademiaDataValidationError : public runtime_error {  // co wynika z dziedziczenia po runtime_error?
    public:
        AcademiaDataValidationError(string str):runtime_error(str){

        }
    private:
        string str;   // potrzebne?
    };

    class InvalidPeselChecksum : public AcademiaDataValidationError {
    public:
        InvalidPeselChecksum(string pesel, int checkSum):AcademiaDataValidationError("Invalid PESEL(" + pesel + ") checksum: "+ to_string(checkSum)){
            // czy to jest tak że AdacemiaData(...) tworzy ten długi string i następnie przekazuje go do runtime_error? A runtime_error go wyświetla?

        }
    };   // dlaczego brak sekcji private i string pesel_?

    class InvalidPeselCharacter : public AcademiaDataValidationError {
    public:
        InvalidPeselCharacter(string pesel):AcademiaDataValidationError("Invalid PESEL(" + pesel + ") character set"){

        }
    };

    class InvalidPeselLength : public AcademiaDataValidationError {
    public:
        InvalidPeselLength(string pesel, int length):AcademiaDataValidationError("Invalid PESEL(" + pesel + ") length: " + to_string(length)) {

        }
    };

    class Pesel {
    public:
        Pesel();   // konstruktor domyśly
        Pesel(string pesel);  // dodatkowy konstruktor?
        ~Pesel()= default; //destruktor domyślny

        void validatePESEL(string pesel);

    private:
        string pesel_;   // string potrzebny do dodatkowego konstruktora?
    };
}

#endif //JIMP_EXERCISES_PESEL_H