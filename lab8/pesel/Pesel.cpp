#include "Pesel.h"

academia::Pesel::Pesel() {

}

academia::Pesel::Pesel(string pesel) {

    validatePESEL(pesel); // dlaczego brak pesel_ = pesel? w jakim celu jest validatePESEL
    /*pobiera string w konstruktorze -
     * potem "wysyła" go do funkcji validate, funkcja
     * ta sprawdza czy ten string jest poprawnym peselem */

}

//academia::Pesel::~Pesel() {

//}

void academia::Pesel::validatePESEL(string pesel) {
    if(pesel.length() != 11){
        throw InvalidPeselLength(pesel, pesel.length());
    }

    for(int i=0; i<pesel.length(); i++){
        if((int)pesel[i]-48 < 0 || (int)pesel[i]-48 > 9){
            throw InvalidPeselCharacter(pesel);
        }
    }

    int array[] = {9, 7, 3, 1, 9, 7, 3, 1, 9, 7};
    int checkSum = 0;

    for(int i=0; i<pesel.length()-1; i++){
        checkSum += ((int)pesel[i]-48) * array[i];
    }

    if(checkSum%10 != ((int)pesel[pesel.length()-1]-48)){
        throw InvalidPeselChecksum(pesel, checkSum);
    }

}