#include <iostream>
#include "cat.hpp"

int main(int argc, char *argv[]) {
    auto cat = cat::Cat();
    cat.do_cat(argv[1]);
    return 0;
}
