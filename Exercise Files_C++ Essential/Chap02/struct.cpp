// struct.cpp by Bill Weinman [bw.org]
// updated 2020-06-24
#include <cstdio>

struct S {
    int i;
    double d;
    const char * s;
};

int main() {
    S s1 = { 3, 47.9, "string one" };

    printf("s1: %d, %f, %s\n", s1.i, s1.d, s1.s);

    return 0;
}
