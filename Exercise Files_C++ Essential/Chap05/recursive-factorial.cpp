// recursive-factorial.cpp by Bill Weinman <http://bw.org/>
// updated 2020-06-24
#include <cstdio>

unsigned long int factorial( unsigned long int n ) {
    if( n < 2 ) return 1;
    return n * factorial( n - 1 );
}

int main() {
    unsigned long int n = 5;
    printf("Factorial of %ld is %ld\n", n, factorial(n));
    return 0;
}
