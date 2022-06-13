// template-class.cpp by Bill Weinman <http://bw.org/>
// updated 2020-08-31
#include <iostream>
#include <string>
#include <exception>

// simple exception class
class BWEx : public std::exception {
    const char * msg;
    BWEx();    // no default constructor
public:
    explicit BWEx(const char * s) throw() : msg(s) { }
    const char * what() const throw() { return msg; }
};

// simple fixed-size LIFO stack template
template <typename T>
class Stack {
    static const int defaultSize = 10;
    static const int maxSize = 1000;
    int S_size;
    int S_top;
    T * stackPtr;
public:
    explicit Stack(int s = defaultSize);
    ~Stack() { if(stackPtr) delete[] stackPtr; }
    T & push( const T & );
    T & pop();
    bool isEmpty() const { return S_top < 0; }
    bool isFull() const { return S_top >= S_size - 1; }
    int top() const { return S_top; }
    int size() const { return S_size; }
};

// Stack<T> constructor
template <typename T>
Stack<T>::Stack ( int s ) {
    if(s > maxSize || s < 1) throw BWEx("invalid stack size");
    else S_size = s;
    stackPtr = new T[S_size];
    S_top = -1;
}

template <typename T>
T & Stack<T>::push ( const T & i ) {
    if(isFull()) throw BWEx("stack full");
    return stackPtr[++S_top] = i;
}

template <typename T>
T & Stack<T>::pop () {
    if(isEmpty()) throw BWEx("stack empty");
    return stackPtr[S_top--];
}

int main() {
    try {

        Stack<int> si(5);
        
        std::cout << "si size: " << si.size() << std::endl;
        std::cout << "si top: " << si.top() << std::endl;
        
        for ( int i : { 1, 2, 3, 4, 5 } ) {
            si.push(i);
        }
        
        std::cout << "si top after pushes: " << si.top() << std::endl;
        std::cout << "si is " << ( si.isFull() ? "" : "not " ) << "full" << std::endl;
        
        while(!si.isEmpty()) {
            std::cout << "popped " << si.pop() << std::endl;
        }

        Stack<std::string> ss(5);
        
        std::cout << "ss size: " << ss.size() << std::endl;
        std::cout << "ss top: " << ss.top() << std::endl;
        
        for ( const char * s : { "one", "two", "three", "four", "five" } ) {
            ss.push(s);
        }
        
        std::cout << "ss top after pushes: " << ss.top() << std::endl;
        std::cout << "ss is " << ( ss.isFull() ? "" : "not " ) << "full" << std::endl;
        
        while(!ss.isEmpty()) {
            std::cout << "popped " << ss.pop() << std::endl;
        }

    } catch (BWEx & e) {
        std::cout << "Stack error: " << e.what() << std::endl;
    }
    
    return 0;
}
