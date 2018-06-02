//
// Created by Joanna on 02.06.2018.
//

#ifndef JIMP_EXERCISES_SEQUENTIALGENERATOR_H
#define JIMP_EXERCISES_SEQUENTIALGENERATOR_H


#include <iostream>

template<class T, class TYP_PROSTY>
class SequentialIdGenerator {
private:
    TYP_PROSTY licznik_id;
    bool head_;
public:
    SequentialIdGenerator(){
        licznik_id=0;
        head_=true;
    };
    SequentialIdGenerator(TYP_PROSTY nr){
        licznik_id=nr;
        head_=true;
    };
    T NextValue(){
        if(!head_){
            ++licznik_id;
            return T(licznik_id);
        }
        else {
            head_=false;
            return T(licznik_id);

        }
    }
    ~SequentialIdGenerator(){};
};



#endif //JIMP_EXERCISES_SEQUENTIALGENERATOR_H
