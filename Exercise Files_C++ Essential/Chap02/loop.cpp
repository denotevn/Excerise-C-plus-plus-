// loop.cpp by Bill Weinman [bw.org]
// updated 2020-06-24
#include <cstdio>

int main(int argc, char ** argv)
{
    puts("loop test");
    for (int i = 0; argv[i]; i++) {
        printf("%d: %s\n", i, argv[i]);
    }
    return 0;
}
