#ifndef CAT_H
#define CAT_H

#include <fstream>
#include <pthread.h>
#include <string>
#include <vector>

namespace cat {
    class Cat {
    public:
        Cat();
        void do_cat(std::string path);
    private:
        void do_cat_stdin();
    };
}

#endif /* CAT_H */
