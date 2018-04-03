//
// Created by Joanna on 03.04.2018.
//

#include "XorCypherBreaker.h"

string XorCypherBreaker(const vector<char> &cryptogram, int key_length,
                        const vector<string> &dictionary) {
    string slowo = "";
    string tmp_klucz = "   ";
    vector<char> zaszyfr;
    int licznik_maxa = -10;
    int licznik_zwykly = 0;

    for (int x = 97;x <= 122;x++)
    {
        for (int y = 97;y <= 122;y++)
        {
            for (int z = 97;z <= 122;z++)
            {
                int k=0;

                tmp_klucz[0] = (char)(x);
                tmp_klucz[1] = (char)(y);
                tmp_klucz[2] = (char)(z);
                string slowo1="";

                for (int i :  cryptogram) //range-based for,fajna rzecz
                {
                    char letter = (char) (tmp_klucz[k % key_length] xor i);

                    if ((letter >= 97)&&(letter <= 122)||((letter >= 65)&&(letter <=90 )))
                    {
                        slowo1 += letter;
                    }
                    else {
                        if (slowo1.length()>2)
                        {
                            transform(slowo1.begin(), slowo1.end(), slowo1.begin(),::tolower);
                            if (find(dictionary.begin(), dictionary.end(), slowo1) != dictionary.end())
                            {
                                licznik_zwykly++;
                            }
                        }
                        slowo1 = "";
                    }
                    k++;
                }
                if (licznik_zwykly >= licznik_maxa)
                {
                    licznik_maxa = licznik_zwykly;
                    slowo = tmp_klucz;
                }
                licznik_zwykly = 0;
            }
        }
    }
    return slowo;
}