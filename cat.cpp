#include <fstream>
#include <cerrno>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <system_error>
#include "cat.hpp"

namespace cat {
    Cat::Cat() {}

    void Cat::do_cat(std::string path) {
        std::ifstream ifs(path);
        if (!ifs) {
            throw std::system_error(errno, std::generic_category(), path);
        }

        std::string buf;
        while (std::getline(ifs, buf)) {
            std::cout << buf << '\n';
        }

        if (!ifs.eof()) {
            throw std::system_error(errno, std::generic_category(), path);
        }
    }
}
