// 05_solution.cpp by Bill Weinman <http://bw.org/>
// updated 2020-07-18
#include <cstdio>

// non-recursive factorial
unsigned long int factorial( unsigned long int n ) {
    unsigned long int rc = n;

    // the product of all numbers 2 through n
    while(n > 1) {
        rc *= --n;
    }

    return rc;
}

int main() {
    unsigned long int n = 5;
    printf("Factorial of %ld is %ld\n", n, factorial(n));
    return 0;
}
