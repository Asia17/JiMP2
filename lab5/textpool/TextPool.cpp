//
// Created by Joanna on 10.04.2018.
//

#include <iostream>
#include "TextPool.h"

namespace pool {

    TextPool::TextPool(TextPool &&s) noexcept{
        swap(pool,s.pool);
    }

    TextPool::TextPool() : pool() {
    }

    size_t pool::TextPool::StoredStringCount() const {
        return pool.size();
    }

    std::experimental::string_view pool::TextPool::Intern(const std::string &str) {
        auto i = pool.insert(str);
        return *(i.first);
    }

    TextPool::TextPool(const std::initializer_list<const std::string> list) : pool() {

        for (auto e:list) {
            std::string l = e;
            Intern(l);
        }
    }

    TextPool &TextPool::operator=(TextPool &&c) {
        if (this == &c) {
            return c;
        }
        pool.clear();

        swap(c.pool,pool);

        return *this;
    }


}