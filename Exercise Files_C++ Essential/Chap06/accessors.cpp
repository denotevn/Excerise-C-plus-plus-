// accessors.cpp by Bill Weinman <http://bw.org/>
// updated 2020-08-28
#include <cstdio>

class A {
    int ia = 0;
    int ib = 0;
    int ic = 0;
public:
    A ( int a, int b, int c ) : ia(a), ib(b), ic(c) {};
    void seta ( int a ) { ia = a; }
    void setb ( int b ) { ib = b; }
    void setc ( int c ) { ic = c; }
    int geta () const { return ia; }
    int getb () const { return ib; }
    int getc () const { return ic; }
};

int main() {
    A a(1, 2, 3);
    printf("ia is %d, ib is %d, ic is %d\n", a.geta(), a.getb(), a.getc());
    return 0;
}
