//
// Created by Joanna on 18.04.2018.
//

#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H

#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
#include<set>

namespace datastructures {
    class Word {
    public:
        std::string word;
        bool operator <(const Word w) const{
            return word.compare(w.word)<0;
        }
        bool operator ==(const Word w) const{
            return word==w.word;
        }
        Word(const std::string &w) : word(w) {}

    };

    class Counts {
    public:
        Counts(int v=1) : count(v) {}


        Counts & operator++(int) {
            count++;
            return *this;
        }
        Counts & operator++() {
            return (*this)++;
        }
        bool operator <(const Counts c) const{
            return count<c.count;
        }
        bool operator >(const Counts c) const{
            return count>c.count;
        }
        bool operator ==(const Counts c) const{
            return count==c.count;
        }
        int getCount(){
            return count;
        }

    private:
        unsigned int count;

    };

    class WordCounter {
    public:
        WordCounter();
        WordCounter(const std::initializer_list<Word> &list);
        //todo: initializer list WordCounter()
        std::set<Word> Words();
        unsigned long DistinctWords();
        unsigned long TotalWords();

        static WordCounter FromInputStream(std::istream* in);
        friend std::ostream& operator << (std::ostream& out,WordCounter &c);

        int operator [](std::string w){
            Word word(w);
            auto it = index.find(word);
            if(it== index.end())//nie ma danego elementu
                return 0;
            else
                return it->second.getCount();
        }

    private:
        std::map<Word, Counts> index;


        void add(Word word);
    };


}


#endif //JIMP_EXERCISES_WORDCOUNTER_H
