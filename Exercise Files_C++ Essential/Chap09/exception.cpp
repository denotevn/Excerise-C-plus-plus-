// exception.cpp by Bill Weinman <http://bw.org/>
// updated 2002-09-03
#include <iostream>
#include <exception>

namespace BW {
    class E : public std::exception {
        const char * msg;
        E();
    public:
        E(const char *s) noexcept(true) : msg(s) {}
        const char * what() const noexcept(true) { return msg; }
    };
}

void broken() {
    std::cout << "this is a broken function" << std::endl;
    throw std::exception();
}

int main() {
    std::cout << "let's have an emergency!" << std::endl;
    broken();
    return 0;
}
