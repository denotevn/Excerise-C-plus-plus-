// void-type.cpp by Bill Weinman <http://bw.org/>
// updated 2020-06-24
#include <cstdio>

void func ( void ) {
    puts("this is void func ( void )");
}

int main() {
    puts("calling func()");
    func();
    return 0;
}

