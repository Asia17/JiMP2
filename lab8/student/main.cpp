//
// Created by Joanna on 06.05.2018.
//
#include <iostream>
#include "StudentException.h"
using namespace academia;
int main(){
    try{
        Student S1{"Kasia","Cos","filozofia",23};

    }catch(const std::invalid_argument &a){
        std::cerr << a.what()<<std::endl;
    }

    try{
        Student S2{"KASI","Cos","filozofia",33};

    }catch(const std::invalid_argument &a){
        std::cerr << a.what()<<std::endl;
    }
    try{
        Student S3{"kASIA","Cos","fizyka",70};

    }catch(const std::invalid_argument &a){
        std::cerr << a.what()<<std::endl;
    }

    try{
        Student S4{"Kasia ","cos","filozofia",98};

    }catch(const std::invalid_argument &a){
        std::cerr << a.what()<<std::endl;
    }

    try{
        Student S5{"Kasia","COS","filozofia",26};

    }catch(const std::invalid_argument &a){
        std::cerr << a.what()<<std::endl;
    }

    try{
        Student S6{"","Cos","filozofia",62};

    }catch(const std::invalid_argument &a){
        std::cerr << a.what()<<std::endl;
    }

    try{
        Student S6{"Kasia","","filozofia",62};

    }catch(const std::invalid_argument &a){
        std::cerr << a.what()<<std::endl;
    }









}