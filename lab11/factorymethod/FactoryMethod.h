//
// Created by Joanna on 22.05.2018.
//

#ifndef JIMP_EXERCISES_FACTORYMETHOD_H
#define JIMP_EXERCISES_FACTORYMETHOD_H

#include <iostream>
namespace factoryMethod{

    template<typename T>  // typename to to samo co class
    T Create() {std::cout << "OK" << std::endl;
        return T();}


    class MyType{
    public:
        MyType()= default;
        ~MyType()= default;
        std::string SayHello(){ return "hello";};
    };

}



#endif //JIMP_EXERCISES_FACTORYMETHOD_H
