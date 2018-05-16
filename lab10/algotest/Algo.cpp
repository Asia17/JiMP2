//
// Created by Joanna on 15.05.2018.
//

#include "Algo.h"
#include <iostream>
#include <set>
#include<map>
#include <tuple>
#include <functional>
#include <numeric>
#include <sstream>
#include <iomanip>

namespace algo {
    std::set<std::string> Keys(const std::map<std::string, int> &m) {
        std::set<std::string> keys;
        auto alokator = std::inserter(keys, keys.end());  //wstawia do pustegu setu

        std::transform(
                m.begin(), // iterator pcczątkowu
                m.end(), // iterator końcowy
                alokator,  // wypełnia mapke
                [](std::pair<std::string, int> para)  // funckja lambda
                { return para.first; }  // zwrot kluczy
        );
        return keys;

    }


    std::vector<int> Values(const std::map<std::string, int> &m) {
        std::vector<int> wartosci;
        auto alokator = std::inserter(wartosci, wartosci.end());

        std::transform(m.begin(), m.end(), alokator, [](std::pair<std::string, int> para) { return para.second; });
        return wartosci;
    }

    std::map<std::string, int> DivisableBy(const std::map<std::string, int> &m, int divisor) {
        std::map<std::string, int> mapka;
        auto alokator = std::inserter(mapka, mapka.end());

        std::transform(m.begin(), m.end(), alokator,
                       [divisor](std::pair<std::string, int> para) { if (para.second % divisor == 0) return para; });
        return mapka;

    }

/*
 * std::map<std::string, int> DivisableBy(const std::map<std::string, int> &m, int divisor){
 * std::vector<int> wektorek;
 * std::copy_if(m.begin(),m.end(),std::back_inserter(wektorek),[divisor])int value){retur value%divisor==0;}
 * return wektorek;
 * } */

    void SortInPlace(std::vector<int> *v) {
        std::sort(v->begin(), v->end());
    } //zmieniony originalny vektor w posortowany

    std::vector<int> Sort(const std::vector<int> &v) {
        std::vector<int> copy;
        std::copy(v.begin(), v.end(), std::back_inserter(copy));
        SortInPlace(&copy);
        return copy;
    }

    void SortByFirstInPlace(std::vector<std::pair<int, int>> *v) {
        std::sort(v->begin(), v->end(), [](std::pair<int,int> a, std::pair<int,int> b) { return (a.first < b.first); });
    }

    void SortBySecondInPlace(std::vector<std::pair<int, int>> *v) {
        std::sort(v->begin(), v->end(), [](std::pair<int,int> a, std::pair<int,int> b) { return (a.second < b.second); });
    }

    void SortByThirdInPlace(std::vector<std::tuple<int, int, int>> *v) {
        std::sort(v->begin(), v->end(), [](std::tuple<int, int, int> &a, std::tuple<int, int, int> &b) {
            return std::get<2>(a) < std::get<2>(b);
        });
    }

    int Sum(const std::vector<int> &v) {
        return std::accumulate(v.begin(),v.end(),0);
    }

    int Product(const std::vector<int> &v) {
        return std::accumulate(v.begin(), v.end(), 1, std::multiplies<>());
    }

    void InitializeWith(int initial_value, std::vector<int> *v) {
        //std::vector<int> wypelniony;
        std::fill(v->begin(),v->end(),initial_value);
    }
    std::vector<int> InitializedVectorOfLength(int length, int initial_value) {
       std::vector<int> wektor;
        auto alokator = std::back_inserter(wektor);
        fill_n(alokator,length,initial_value);
        return wektor;
    }
    void RemoveDuplicatesInPlace(std::vector<std::string> *v) {
        std::unique(v->begin(),v->end());
    }

    std::vector<std::string> RemoveDuplicates(const std::vector<std::string> &v) {
        std::vector<std::string> kopia;
        std::copy(v.begin(),v.end(),std::back_inserter(kopia));
        RemoveDuplicatesInPlace(&kopia);
        return kopia;
    }

    bool Contains(const std::vector<int> &v, int element) {
        return std::find(v.begin(),v.end(),element) != v.end();
    }

    bool ContainsKey(const std::map<std::string, int> &v, const std::string &key) {
        return v.find(key) != v.end();
    }

    bool ContainsValue(const std::map<std::string, int> &v, int value) {
        return std::find_if(v.begin(),v.end(),[value](std::pair<std::string, int> para) { return para.second==value; }) != v.end();
    }
    int HowManyShortStrings(const std::vector<std::string> &v, int inclusive_short_length) {
        return (int)std::count_if(v.begin(),v.end(),[inclusive_short_length](std::string& s){return s.length()<=inclusive_short_length;});
    }

    std::vector<std::string> MapToString(const std::vector<double> &v) {
        std::vector<std::string> strings;
        std::transform(v.begin(), v.end(), std::back_inserter(strings), [](double d) {return std::to_string(d); });
        return strings;
    }


}


