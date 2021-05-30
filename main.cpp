#include <cstdlib>
#include <exception>
#include <iostream>
#include <system_error>
#include "cat.hpp"

int main(int argc, char *argv[]) {
    auto cat = cat::Cat();
    try {
        cat.do_cat(argv[1]);
    } catch (std::system_error e) {
        std::cerr << e.what() << std::endl;
        std::exit(1);
    }
    return 0;
}
