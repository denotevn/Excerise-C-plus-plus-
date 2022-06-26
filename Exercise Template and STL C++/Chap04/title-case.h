// title-case.h by Bill Weinman <http://bw.org/>
// 2018-09-25 for CppSTL
#include <cctype>

class title_case {
    char _last;
    char _sep = 0;
public:
    title_case() : _last(0) {}
    title_case(const char c) : _last(1), _sep(c) {}
    const char operator() (const char c);
};

const char title_case::operator() (const char c) {
    if(_sep) _last = (!_last || _last == _sep) ? toupper(c) : c;
    else _last = (!_last || isblank(_last)) ? toupper(c) : c;
    return _last;
}
