#include <cstdio>
#include <fstream>
#include <cerrno>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <system_error>
#include <iomanip>
#include "cat.hpp"
#include "cxxopts.hpp"

namespace cat {
    Cat::Cat(cxxopts::ParseResult result) : m_result(result) {
        m_line_num = 1;
    }

    void Cat::println(std::string s) {
        if (m_result["number"].as<bool>()) {
            std::cout << std::setw(6) << m_line_num << "  " << s << '\n';
        } else {
            std::cout << s << '\n';
        }
    }

    void Cat::do_cat(std::string path) {
        if (std::string(path) == "-") {
            do_cat_stdin();
            return;
        }
        std::ifstream ifs(path);
        if (!ifs) {
            throw std::system_error(errno, std::generic_category(), path);
        }

        std::string buf;
        while (std::getline(ifs, buf)) {
            println(buf);
            m_line_num++;
        }

        if (!ifs.eof()) {
            throw std::system_error(errno, std::generic_category(), path);
        }
    }

    void Cat::do_cat_stdin() {
        std::string buf;
        while (std::getline(std::cin, buf)) {
            println(buf);
        }

        if (!std::cin.eof()) {
            throw std::system_error(errno, std::generic_category(), "stdin");
        }

        // iostreamとstdio両方のEOFフラグをリセット
        std::cin.clear();
        std::clearerr(stdin);
    }
}
