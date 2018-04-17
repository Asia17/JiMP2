//
// Created by Joanna on 18.04.2018.
//

#include "WordCounter.h"
#include <iostream>
#include <set>
#include "WordCounter.h"
namespace datastructures {

    std::ostream& operator << (std::ostream& out,WordCounter &wc)
    {
        std::vector<Word> t;
        for (Word w:wc.Words())
            t.push_back(w);
        //kopiowanie kluczy

        // sortowanie za pomocą obietktu sortującego
        struct sorter{
            WordCounter& wc;
            sorter(WordCounter& w):wc(w){};

            bool operator()(Word &w1, Word &w2) const
            {
                return wc[w1.word]>wc[w2.word];
            }
        };

        std::sort(t.begin(), t.end(),sorter(wc));

        //wyświetlenie kluczy
        for (Word p:t){
            out<<wc[p.word]<<" : "<<p.word<<std::endl;
        }

        return out;
    }

    WordCounter::WordCounter():index() {}

    WordCounter WordCounter::FromInputStream(std::istream *in) {
        std::istream::sentry s(*in);//przygotowanie streamu do odczytu danych
        WordCounter wC;


        if(s){//wykonanie w przypadku istnienia danych

            std::string w ="";
            while(in->good()){//odczytywanie do momentu gdy skończą sie dane
                char c = in->get();//wczytywanie słowa po literze
                if(isalpha(c))
                    w+=tolower(c);//zwiększenie słowa

                else if(w.length()>0) {
                    wC.add(Word(w));//zwiększenie/dodanie nowego licznika
                    w="";//reset buforu
                }
            }
        }

        return wC;
    }

    void WordCounter::add(Word word) {
        auto it = index.find(word);
        if(it== index.end())//wstawienie nowego licznika
            index.emplace(word,Counts());
        else //aktualizacja starego
            (it->second)++;
    }

    std::set<Word> WordCounter::Words() {
        std::set<Word> w;

        //wopiowanie kluczy do wektora
        for(auto word : index)
            w.insert(word.first);

        return w;
    }

    unsigned long WordCounter::DistinctWords() {
        return index.size();
    }

    unsigned long WordCounter::TotalWords() {
        unsigned long count=0;

        for(auto word : index)
            count+=word.second.getCount();//dodanie do siebie ilości róznych słow

        return count;
    }

    WordCounter::WordCounter(const std::initializer_list<Word> &list) {
        for(Word w: list)
            add(w);
    }


}