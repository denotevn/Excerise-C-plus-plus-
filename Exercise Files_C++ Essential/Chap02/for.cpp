// for.cpp by Bill Weinman [bw.org]
// updated 2020-06-24
#include <cstdio>

int main()
{
    int array[] = { 1, 2, 3, 4, 5 };

    for(int i = 0; i < 5; ++i) {
        printf("element %d is %d\n", i, array[i]);
    }

    return 0;
}
