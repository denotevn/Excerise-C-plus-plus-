// bwexception.h by Bill Weinman <http://bw.org/>
// updated 2002-09-03

#ifndef bwexception_h
#define bwexception_h

#include <exception>

namespace BW {

class E : public std::exception {
    const char * msg = nullptr;
    E();
public:
    E(const char *s) noexcept(true) : msg(s) {}
    const char * what() const noexcept(true) { return msg; }
};

} // namespace

#endif /* bwexception_h */
