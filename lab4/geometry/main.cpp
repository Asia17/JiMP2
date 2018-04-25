//
// Created by Joanna on 14.04.2018.
//

#include "Geometry.h"

int main(){

    Point p1(0,0);
    Point p2(2,0);
    Point p3(2,2);
    Point p4 (0,2);

    Square kwadrat(p1,p2,p3,p4);
    cout << "Obwood: " << kwadrat.Circumference() << endl;
    cout << "Pole: " << kwadrat.Area() << endl;

}