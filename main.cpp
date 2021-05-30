#include <cstdlib>
#include <exception>
#include <iostream>
#include <system_error>
#include <vector>
#include "cat.hpp"

int main(int argc, char *argv[]) {
    auto cat = cat::Cat();
    try {
        if (argc == 1) {
            cat.do_cat("-");
            return EXIT_SUCCESS;
        }
        for (int i = 1; i < argc; i++) {
            cat.do_cat(argv[i]);
        }
    } catch (std::system_error e) {
        std::cerr << e.what() << std::endl;
        std::exit(EXIT_FAILURE);
    }
    return EXIT_SUCCESS;
}
