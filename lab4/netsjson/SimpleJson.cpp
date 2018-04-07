//
// Created by Joanna 07.04.2018.
//

#include "SimpleJson.h"
namespace nets {
    const std::string bannedChars = R"(\"/)";
    std::string escape(std::string in){
        std::stringstream s;
        for(auto c:in){
            int x=bannedChars.find(c);
            if(x!=-1)
                s<<R"(\)";
            s<<c;
        }
        return s.str();
    }
    std::string nets::JsonValue::ToString() const {
        std::stringstream s;
        switch (type) {
            case NONE:
                s << "null";
                break;
            case NUMBER:
                s << number;
                break;
            case BOOL:
                s << (boolean ? "true" : "false");
                break;
            case STRING:
                s << '"' << escape(string) << '"';
                break;
            case ARRAY:
                s << '[';
                for (int i = 0; i < arraySize; i++) {
                    s << mapa.at(std::to_string(i)).ToString();
                    if (i != arraySize - 1)
                        s << ", ";
                }
                s << ']';
                break;
            case OBJECT:
                s << '{';
                auto last = mapa.end();
                last--;
                for (auto it = mapa.begin(); it != mapa.end(); it++) {
                    s << '"'<<escape(it->first) + "\": " + it->second.ToString();
                    if(it !=last)
                        s<<", ";
                }
                s << '}';

                break;

        }
        return s.str();
    }

    std::experimental::optional<nets::JsonValue> nets::JsonValue::ValueByName(const std::string &name) const {
        if (type == OBJECT or type == ARRAY)
            for (auto it:mapa)
                if (it.first == name)
                    return it.second;
    }
}