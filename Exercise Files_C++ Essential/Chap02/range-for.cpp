// range-for.cpp by Bill Weinman [bw.org]
// updated 2020-06-24
#include <cstdio>

int main()
{
    int array[] = { 1, 2, 3, 4, 5 };

    for(int i : array) {
        printf("i is %d\n", i);
    }
    return 0;
}
