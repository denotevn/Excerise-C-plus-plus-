#include <iostream>
#include <functional>


void (*func_ptr)(int&);

void print_it(int& x) {
    std::cout << "Funtion pointer received: " << x << std::endl;
}

// This function takes 2 arguments: function pointer and a desired value to print
void acceptFunctionPointer(void (*f)(int&), int y) {
    f(y);
}

void acceptFunctionObject(std::function<void(int&)> f, int y) {
    f(y);
}

class Functor {
    public:
        void operator()(int& x) {
            std::cout << "Functor received: " << x << std::endl;
        }
};
int main() {
    int dummy = 10;
    int a = 100;
    
    auto lambda1 = [dummy](int& x) {
        std::cout << "Lambda1 received: " << x << std::endl;
    };
    
    auto lambda2 = [](int& x) {
        std::cout << "Lambda2 received: " << x << std::endl;
    };
    
    // Pass function pointer
    func_ptr = &print_it;
    acceptFunctionObject(func_ptr, a);
    
    // Pass Lambda1
    acceptFunctionObject(lambda1, a);
    
    // Pass Lambda2
    acceptFunctionObject(lambda2, a);
    
    // Pass Functor
    Functor func;
    acceptFunctionObject(func, a);   

    return 0;
}
