//
// Created by Joanna on 22.05.2018.
//
#include "FactoryMethod.h"
using::factoryMethod::Create;
using::factoryMethod::MyType;

int main(){

    int i = Create<int>();
    double k = Create<double>();
    factoryMethod::MyType b= Create<MyType>();
    std::cout << b.SayHello() << std::endl;
     return 0;
}