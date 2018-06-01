//
// Created by Joanna on 01.06.2018.
//

#include "TeacherHash.h"
using namespace std;
namespace academia{
size_t TeacherHash::operator()(const Teacher &object) const {
    size_t h0 =  hash<int>{}(object.Id());
    size_t h1 = hash<std::string>{}(object.Name());
    size_t h2 = hash<std::string>{}(object.Department());
    return (size_t) (h0 + h1 + h2);
}




}