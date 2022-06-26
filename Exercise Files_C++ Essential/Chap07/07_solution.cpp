// 07_solution.cpp by Bill Weinman <http://bw.org/>
// updated 2002-08-31
#include <cstdio>

// non-recursive factorial template
template<typename T>
T factorial( T n ) {
    T rc = n;
    while(n > 1) {
        rc *= --n;
    }
    return rc;
}

int main() {
    int i = 5;
    printf("%d! is %d\n", i, factorial(i));

    long long unsigned int llui = 15;
    printf("%lld! is %lld\n", llui, factorial(llui));
    
    long double ld = 25;
    printf("%.3Lf! is %-4.10Lg\n", ld, factorial(ld));

    return 0;
}
