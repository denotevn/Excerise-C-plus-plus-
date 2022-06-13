// while.cpp by Bill Weinman [bw.org]
// updated 2020-06-24
#include <cstdio>

int main()
{
    int array[] = { 1, 2, 3, 4, 5 };
    int i = 0;
    
    while(i < 5) {
        printf("element %d is %d\n", i, array[i]);
        ++i;
    }
    
    return 0;
}
