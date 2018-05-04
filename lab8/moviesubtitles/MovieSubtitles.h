//
// Created by Asia on 2018-05-03.
//

#ifndef JIMP_EXERCISES_MOVIESUBTITLES_H
#define JIMP_EXERCISES_MOVIESUBTITLES_H

#include <string>
#include <iostream>
#include <memory>
#include <sstream>
#include <regex>
#include <stdexcept>

using std::invalid_argument;
using std::cout;
using std::string;
using std::endl;
using std::unique_ptr;
using std::stringstream;
using std::regex;
using std::smatch;
using std::to_string;



namespace moviesubs {

    class MovieSubtitles {
    public:
        virtual void ShiftAllSubtitlesBy(int delay, int fps, stringstream *in, stringstream *out) = 0 ;

    };


    class SubRipSubtitles : public MovieSubtitles {
    public:
        void ShiftAllSubtitlesBy(int delay, int fps, stringstream *in, stringstream *out);

    };

    class MicroDvdSubtitles : public MovieSubtitles {
    public:
        void ShiftAllSubtitlesBy(int delay, int fps, stringstream *in, stringstream *out);
    };

    class NegativeFrameAfterShift{

    };

    class SubtitleEndBeforeStart{
    public:
        int line_number;
        string line;
        SubtitleEndBeforeStart(int _line_nr, string line_);

        int LineAt()const;
        string what() const;
    };

    class InvalidSubtitleLineFormat{

    };

    class MissingTimeSpecification {


    };

    class OutOfOrderFrames {


    };

}

#endif //JIMP_EXERCISES_MOVIESUBTITLES_H