//
// Created by Joanna 07.04.2018.
//


#ifndef JIMP_EXERCISES_SIMPLEJSON_H
#define JIMP_EXERCISES_SIMPLEJSON_H
#include <experimental/optional>
#include <string>
#include <map>
#include <vector>
#include <sstream>
namespace nets{

    class JsonValue{
    public:
        enum TYPE{NONE,OBJECT,NUMBER,BOOL,STRING,ARRAY};
        JsonValue(std::vector<JsonValue> v):type(ARRAY),arraySize(0){
            for(auto elem : v)
                mapa.emplace(std::to_string(arraySize++),elem);

        }
        JsonValue(std::map <std::string, JsonValue> map):type(OBJECT),mapa(map){};
        JsonValue(int val):type(NUMBER),number(val){};
        JsonValue(double val):type(NUMBER),number(val){};
        JsonValue(bool val):type(BOOL),boolean(val){};
        JsonValue(std::string val):type(STRING),string(val){};
        JsonValue():type(NONE){};

        std::experimental::optional<JsonValue> ValueByName(const std::string &name) const;
        std::string ToString() const;
    private:
        std::map <std::string, JsonValue> mapa;
        TYPE type;
        double number;
        bool boolean;
        std::string string;
        int arraySize;
    };
}
#endif //JIMP_EXERCISES_SIMPLEJSON_H
