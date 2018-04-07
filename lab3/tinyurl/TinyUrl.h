//
// Created by Asia on 2018-04-06.
//

#ifndef JIMP_EXERCISES_TINYURL_H
#define JIMP_EXERCISES_TINYURL_H

#include <utility>
#include <string>
#include <array>
#include <memory>
#include <iostream>
#include <map>
#include <vector>
#include <memory>

using ::std::string;
using ::std::unique_ptr;
using ::std::map;


namespace tinyurl {

    struct TinyUrlCodec{
        std::array<char, 6> hash;
        map<string, string > mapka;
    };


    std::unique_ptr<TinyUrlCodec> Init();
    void NextHash(std::array<char, 6> *kod);
    std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *struktura);
    std::string Decode(const std::unique_ptr<TinyUrlCodec> &struktura, const std::string &kod);
}

#endif //JIMP_EXERCISES_TINYURL_HL_H