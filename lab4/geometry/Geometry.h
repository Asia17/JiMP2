//
// Created by Joanna on 14.04.2018.
//
#include <iostream>
#ifndef PROJECTNAME_PATH_POINT_H_
#define PROJECTNAME_PATH_POINT_H_
using namespace std;
class Point {
public:
    //Konstruktor bezparametrowy
    Point();
    //Konstruktor parametrowy
    Point(double x, double y);
    //Destruktor wykonywany przed zwolnieniem pamięci
    ~Point();

    //metody akcesorów są publiczne i tylko w przy ich pomocy
    //można się dostać z zewnątrz do pól klasy
    double GetX() const;
    double GetY() const;
    double Distance(const Point &other) const;

    //metody seterów pozwalające zmienić stan obiektu
    //po jego zainicjalizowaniu
    void SetX(double x);
    void SetY(double y);
private:
    //w przeciwienstwie do pythona C++ wymaga jawnej deklaracji składowych pól klasy:
    double x_, y_;
};


class Square {
public:
    Square();  // bezparametrowy
    Square(Point A, Point B, Point C, Point D); //parametrowy
    ~Square() ;

    double Circumference()  ;

    double Area();

private:
    Point A_;
    Point B_;
    Point C_;
    Point D_;
};


#endif  // PROJECTNAME_PATH_POINT_H_