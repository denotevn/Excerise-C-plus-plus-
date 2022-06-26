// cpp11.cpp by Bill Weinman <http://bw.org/>
// test for modern C++ compiler
// updated 2020-06-24
#include <cstdio>

int main()
{
    int ia[] = { 1, 2, 3, 4, 5 };
    for( auto i : ia ) {
        printf("i is %d\n", i);
    }
    return 0;
}
