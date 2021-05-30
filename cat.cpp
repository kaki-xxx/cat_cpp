#include <fstream>
#include <cerrno>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include "cat.hpp"

Cat::Cat() {}

void Cat::do_cat(std::string path) {
    std::ifstream ifs(path);
    if (!ifs) {
        std::cerr << path << ": " << std::strerror(errno) << std::endl;
        std::exit(1);
    }

    std::string buf;
    while (std::getline(ifs, buf)) {
        std::cout << buf << '\n';
    }

    if (!ifs.eof()) {
        std::cerr << path << ": " << std::strerror(errno) << std::endl;
        std::exit(1);
    }
}
