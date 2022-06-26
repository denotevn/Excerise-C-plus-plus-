// array.cpp by Bill Weinman [bw.org]
// updated 2020-07-07
#include <cstdio>

int main()
{
    int array[] = { 1, 2, 3, 4, 5 };
    for(int i : array) {
        printf("%d ", i);
    }
    puts("");
    return 0;
}
