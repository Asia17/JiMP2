//
// Created by Joanna on 10.04.2018.
//

#ifndef JIMP_EXERCISES_TEXTPOOL_H
#define JIMP_EXERCISES_TEXTPOOL_H

#include <initializer_list>
#include <string>
#include <experimental/string_view>
#include <set>
#include <string_view>

namespace pool {
    class TextPool {
    public:
        TextPool();
        TextPool(const std::initializer_list<const std::string>);


        TextPool(TextPool&& s) noexcept;
        TextPool & operator = (TextPool&& c);

        TextPool(const TextPool &s)=delete;
        TextPool & operator = (const TextPool &c)=delete;


        ~TextPool(){pool.clear();};

        std::experimental::string_view Intern(const std::string &str);

        size_t StoredStringCount() const;

    private:
        std::set<std::string> pool;
    };
}

#endif //JIMP_EXERCISES_TEXTPOOL_H
