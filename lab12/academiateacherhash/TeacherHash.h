//
// Created by Joanna on 01.06.2018.
//

#ifndef JIMP_EXERCISES_TEACHERHASH_H
#define JIMP_EXERCISES_TEACHERHASH_H
#include <string>
#include <unordered_map>
#include <iostream>

namespace academia{


    class TeacherId{
    private:
        int id_;
    public:
        TeacherId(int id):id_(id){};
        ~TeacherId()= default;
        operator int() const {return id_;};

    };
    //class TeacherId;
    class Teacher{
    private:
        TeacherId id_;
        std::string name_;
        std::string department_;
    public:
        Teacher(TeacherId id,std::string name, std::string department):id_(id),name_(name),department_(department){};
        ~Teacher()= default;
        int Id()const{ return id_;};
        std::string Name()const{ return name_;};
        std::string Department ()const{ return department_;};

        //operatory
        bool operator !=(Teacher another) const
        { return (id_ != another.Id() || name_ != another.Name() || department_ != another.Department() ) ; }

        bool operator ==(Teacher another) const
        { return (id_ == another.Id() && name_ == another.Name() && department_ == another.Department() );}
    };



    class TeacherHash{
    public:
        TeacherHash()= default;
        ~TeacherHash()= default;
        size_t operator () (const Teacher &object) const;
    };


}


#endif //JIMP_EXERCISES_TEACHERHASH_H
