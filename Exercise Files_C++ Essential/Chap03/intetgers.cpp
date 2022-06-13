// integers.cpp by Bill Weinman <http://bw.org/>
// updated 2020-06-24
#include <cstdio>

int main()
{
    char c = 0;
    short int si = 0;
    int i = 0;
    long int li = 0;
    long long int lli = 0;

    printf("sizeof char is %zd bits\n", sizeof(c) * 8);
    printf("sizeof short int is %zd bits\n", sizeof(si) * 8);
    printf("sizeof int is %zd bits\n", sizeof(i) * 8);
    printf("sizeof long int is %zd bits\n", sizeof(li) * 8);
    printf("sizeof long long int is %zd bits\n", sizeof(lli) * 8);
    return 0;
}
