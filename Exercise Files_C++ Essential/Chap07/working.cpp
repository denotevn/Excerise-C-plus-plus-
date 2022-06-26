// working.cpp by Bill Weinman <http://bw.org/>
// updated 2020-06-24
#include <cstdio>
#include <iostream>

template <typename T>
T factorial(T a){
    T result = a;
    while (a > 1){
        result *= --a;
    }
    return result;
}

int main()
{
    int n = 5;
    std::cout << "The factorial of " << n << " is " << factorial<int>(n) << std::endl;
    puts("Hello, World!");
    double n1 = 5.32;
    std::cout << "The factorial of "<< n1 << " is " << factorial<double>(n1) << std::endl;
    return 0;
}
