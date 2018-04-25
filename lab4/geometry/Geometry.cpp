//
// Created by Joanna on 14.04.2018.
//
#include <iostream>
#include <cmath>
#include <ostream>
#include "Geometry.h"
using namespace std;
using ::std::ostream;
using ::std::endl;
using ::std::pow;
using ::std::sqrt;



//Specjalna inicjalizacja zmiennych. Zmienne są inicjowane
//nim zostanie wywołane ciało konstruktorra
Point::Point():x_(0),y_(0){

}

Point::Point(double x, double y){

    x_ = x;
    y_ = y;
}

Point::~Point(){

}
double Point::GetX() const{
    return x_;
}
double Point::GetY() const{
    return y_;
}

double Point::Distance(const Point &other) const{
    return sqrt(pow(GetX()-other.GetX(),2)+pow(GetY()-other.GetY(),2));
}
Square::Square(): A_(0,0), B_(1,1), C_(2,2), D_(3,3){}
Square::Square(Point A, Point B, Point C, Point D) {
    A_ = A;
    B_ = B;
    C_ = C;
    D_ = D;
}
Square::~Square()
    { cout << "Usuwam sobie!"; }

double Square::Circumference() {
        return A_.Point::Distance(B_)*4;
};

double  Square::Area() {
    return (A_.Point::Distance(B_))*( A_.Point::Distance(B_));
}
