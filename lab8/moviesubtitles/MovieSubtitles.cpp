//
// Created by Asia on 2018-05-03.
//

#include "MovieSubtitles.h"

void moviesubs::SubRipSubtitles::ShiftAllSubtitlesBy(int delay, int fps, stringstream *in, stringstream *out) {

    regex pattern {R"((\d{2}):(\d{2}):(\d{2}),(\d{3}) --> (\d{2}):(\d{2}):(\d{2}),(\d{3}))"};
    regex pattern_start {R"((^\d\n))"};
    regex pattern_frame_order {R"((\n\d\n))"};
    regex pattern_invalid_format {R"(^\d$)"};
    smatch matches;
    smatch matches_first_frame;
    smatch frame_order;
    smatch frame;
    bool flag = false;
    int line_number=0;

    if(fps < 0 )
        throw std::invalid_argument("error 404: invalid argument");

    string in_string_cp = (*in).str();
    std::regex_search(in_string_cp, matches_first_frame, pattern_start);
    int first_frame_number = stoi(matches_first_frame[1]);
    int prior = first_frame_number;

    std::regex_search(in_string_cp, frame_order, pattern_frame_order);
    for(int i = 1; i < frame_order.size() ; i++, prior++)
    {
        if (stoi(frame_order[i]) != prior+1)
            throw OutOfOrderFrames();
    }

    string in_string = "";
    while(getline(*in,in_string,'\n')) {

        if (std::regex_search(in_string, matches, pattern)) {
            line_number++;
            flag = false;

            *out << matches[1] << ":" << matches[2] << ":";

            int match_4_delayed = stoi(matches[4].str()) + delay;
            int match_3_delayed = stoi(matches[3])+match_4_delayed/1000;
            string match_3_str = to_string(match_3_delayed);
            string match_4_str = matches[4].str();

            if(match_4_delayed < 1000) {
                while(match_4_str.size() < 3)
                    match_4_str='0'+match_4_str;
                while(match_3_str.size()<2)
                    match_3_str='0'+match_3_str;
                (*out)<< match_3_str << "," << match_4_delayed << " --> ";
            }
            else {
                match_4_str = to_string(match_4_delayed%1000);

                while(match_4_str.size()<3)
                    match_4_str='0'+match_4_str;
                while(match_3_str.size()<2)
                    match_3_str='0'+match_3_str;
                (*out)<< match_3_str << "," << match_4_str << " --> ";
            }

            *out << matches[5] << ":" << matches[6] << ":";
            string match_8_str = matches[8].str();
            int match_8_delayed = stoi(matches[8].str()) + delay;
            int match_7_delayed = stoi(matches[7])+match_8_delayed/1000;
            string match_7_str = to_string(match_7_delayed);

            if(match_8_delayed < 1000)
            {
                while(match_8_str.size() < 3)
                    match_8_str = '0' + match_8_str;
                while(match_7_str.size() < 2)
                    match_7_str = '0' + match_7_str;

                (*out)<< match_7_str << "," << match_8_str << " --> ";
            }
            else{
                match_8_str = to_string(match_8_delayed%1000);

                while(match_8_str.size() < 3)
                    match_8_str = '0' + match_8_str;
                while(match_7_str.size() < 2)
                    match_7_str = '0' + match_7_str;
                (*out)<< match_7_str << "," << match_8_str << '\n';
            }

            if(match_3_delayed < 0 || match_4_delayed < 0 || match_7_delayed < 0 || match_8_delayed < 0)
                throw NegativeFrameAfterShift();

            if (stoi(matches[1]) * 3600 + stoi(matches[2]) * 60 + stoi(matches[3]) + stoi(matches[4]) * 0.001 >= stoi(matches[5]) * 3600 + stoi(matches[6]) * 60 + stoi(matches[7]) + stoi(matches[8]) * 0.001)
                throw moviesubs::SubtitleEndBeforeStart(line_number, in_string);

        }
        else {
            if(flag)
                throw InvalidSubtitleLineFormat();

            if (std::regex_search(in_string, frame, pattern_invalid_format))
                flag = true;

            *out << in_string << '\n';
        }
    }

}

void moviesubs::MicroDvdSubtitles::ShiftAllSubtitlesBy(int delay, int fps, stringstream *in, stringstream *out) {
    string in_string = (*in).str();
    regex pattern {R"(\{(\d+)\}\{(\d+)\}(.*))"};
    smatch matches;
    int line_number=0;
    if (fps < 0 )
        throw invalid_argument("wstrzymaj konie");
    while(getline(*in,in_string,'\n')) {
        line_number++;

        if (std::regex_search(in_string, matches, pattern)) {
            int start = stoi(matches[1]) + (delay * fps / 1000);
            int end = stoi(matches[2]) + (delay * fps / 1000);

            if (start < 0 || end < 0 )
                throw moviesubs::NegativeFrameAfterShift();

            if (end < start)
                throw moviesubs::SubtitleEndBeforeStart(line_number, in_string);

            *out << "{" << start << "}";
            *out << "{" << end << "}";
            *out << matches[3] << "\n";
        }
        else {
            throw moviesubs::InvalidSubtitleLineFormat();
        }
    }

}

int moviesubs::SubtitleEndBeforeStart::LineAt() const {
    return line_number;
}

string moviesubs::SubtitleEndBeforeStart::what() const {
    return "At line " + to_string(line_number) + ": " + line;
}

moviesubs::SubtitleEndBeforeStart::SubtitleEndBeforeStart(int _line_nr, string line_) {
    line_number = _line_nr;
    line = line_;
}