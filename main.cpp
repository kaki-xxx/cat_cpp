#include <cstdlib>
#include <exception>
#include <iostream>
#include <system_error>
#include <vector>
#include "cat.hpp"
#include "cxxopts.hpp"

int main(int argc, char *argv[]) {
    cxxopts::Options options("cat", "Concatenate FILE(s) to standard output.");

    options.add_options()
        ("n,number", "number all output line")
        ("help", "print this message and exit")
    ;

    cxxopts::ParseResult result;
    try {
        result = options.parse(argc, argv);
    } catch (cxxopts::OptionException e) {
        std::cerr << e.what() << std::endl;
        std::exit(EXIT_SUCCESS);
    }

    options.custom_help("[OPTION]... [FILE]...");

    if (result.count("help")) {
        std::cout << options.help() << std::endl;
        std::exit(EXIT_SUCCESS);
    }

    auto cat = cat::Cat(result);
    try {
        if (argc == 1) {
            cat.do_cat("-");
            return EXIT_SUCCESS;
        }
        for (auto path : result.unmatched()) {
            cat.do_cat(path);
        }
    } catch (std::system_error e) {
        std::cerr << e.what() << std::endl;
        std::exit(EXIT_FAILURE);
    }
    return EXIT_SUCCESS;
}
