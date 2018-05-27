//
// Created by Joanna on 27.05.2018.
//
#ifndef JIMP_EXERCISES_TIMERECORDER_H
#define JIMP_EXERCISES_TIMERECORDER_H
#include <chrono>
#include <ctime>
#include <iostream>


namespace profiling
{
    template<class T>

    auto TimeRecorder(T object)    {
        std::chrono::time_point<std::chrono::system_clock> begin, stop;
            begin = std::chrono::system_clock::now();
            auto o = object();
            stop = std::chrono::system_clock::now();

        auto time =  std::chrono::duration<double, std::milli>(stop-begin).count();

        return std::pair<decltype(o), double> {o, time};

    };
}
#endif //JIMP_EXERCISES_TIMERECORDER_H