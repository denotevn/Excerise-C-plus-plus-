// func-operator.cpp by Bill Weinman <http://bw.org/>
// updated 2020-06-24
#include <cstdio>

class A {
    int a;
public:
    A ( const int &a ) : a(a) {}
    const int & value() const { return a; }
};

int operator + (const A & lhs, const A & rhs ) {
    puts("operator + for class A");
    return lhs.value() + rhs.value();
}

int main() {
    A a(7);
    A b(42);
    printf("add em up! %d\n", a + b);
    return 0;
}
