// stack.h by Bill Weinman <http://bw.org/>
// updated 2018-09-08 for CppSTL 2018
#ifndef _STACK
#define _STACK

#include <exception>

// simple exception class
class StackExeption : public std::exception {
    const char * msg;
    StackExeption(){};    // no default constructor
public:
    explicit StackExeption(const char * s) throw() : msg(s) { }
    const char * what() const throw() { return msg; }
};

// simple fixed-size LIFO stack template
template <typename T>
class Stack {
private:
    static const int defaultSize = 10;
    static const int maxSize = 1000;
    int _size;
    int _top;
    T * stackPtr;
public:
    explicit Stack(int s = defaultSize);
    ~Stack() { delete[] stackPtr; }
    T & push( const T & );
    T & pop();
    bool isEmpty() const { return _top < 0; }
    bool isFull() const { return _top >= _size - 1; }
    int top() const { return _top; }
    int size() const { return _size; }
};

#endif // _STACK
