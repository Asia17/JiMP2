//
// Created by Asia on 2018-04-06.
//

#include "TinyUrl.h"

namespace tinyurl {

    void NextHash(std::array<char, 6> *kod) {  //kod to to samo co hash tylko po prostu inaczej nazwałam
        unsigned long i = 5;
        unsigned long indeks;
        std::string zbior_znakow = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

        if (kod->at(i) == 'z') {
            while (kod->at(i) == 'z') {
                kod->at(i) = '0';
                i--;
            }
            indeks = zbior_znakow.find(kod->at(i));
            kod->at(i) = zbior_znakow.at(indeks + 1);
        } else {

            indeks = zbior_znakow.find(kod->at(i));
            kod->at(i) = zbior_znakow.at(indeks + 1);
        }


        // kod = ? ? ? ? ?
        // NextHash(kod):
        //       kod = ? ? ? ? 1

        // kod = 0 0 0 Z Z Z
        // NextHash(kod)
        //       kod = 0 0 1 0 0 0


    }


    std::unique_ptr<TinyUrlCodec> Init()
    {
        std::unique_ptr<TinyUrlCodec> struktura = std::make_unique<TinyUrlCodec>();  //stworzenie obiekt który jest wskaźnikiem uniq_ptr i jednoczesna alokacja pamięci dla niego
        struktura->hash = {'0','0','0','0','0','0'};
        return struktura;
    }

    std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *struktura)
    {

        string kod;
        for (auto letter_in_hash: struktura->get()->hash)
            kod += letter_in_hash;

        struktura->get()->mapka.emplace(kod, url);
        // po 1. wykonaniu:
        //
        // mapka = {"?????": "http://...."}
        //

        NextHash(&struktura->get()->hash);

        // hash = "????1"
        return kod;

    }
    std::string Decode(const std::unique_ptr<TinyUrlCodec> &struktura, const std::string &kod)
    {
        string url;
        auto krotka = struktura->mapka.find(kod);   // wyciaga ze słownika(mapki) tuple (KEY,VALUE),    KEY = kod,   VALUE = url
        url = krotka->second;
        return url;
    }

}