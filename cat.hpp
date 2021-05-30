#ifndef CAT_H
#define CAT_H

#include <fstream>
#include <pthread.h>
#include <string>
#include <vector>
#include "cxxopts.hpp"

namespace cat {
    class Cat {
    public:
        Cat(cxxopts::ParseResult result);
        void do_cat(std::string path);
    private:
        cxxopts::ParseResult m_result;
        int m_line_num;
        void println(std::string s);
        void do_cat_stdin();
    };
}

#endif /* CAT_H */
