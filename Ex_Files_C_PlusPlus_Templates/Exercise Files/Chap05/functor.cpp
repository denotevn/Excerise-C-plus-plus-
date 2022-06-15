// functor.cpp by Bill Weinman <http://bw.org/>
// 2018-09-27 for CppSTL
#include <iostream>
using namespace std;

template <typename T>
class multiply_by {
    T _mult = 0;
    multiply_by();
public:
    multiply_by(T n) : _mult(n) {}
    void mult(T n) { _mult = n; }
    T mult() const { return _mult; }
    T operator() (T n) const { return _mult * n; }
};

int main() {
    multiply_by<int> x(9);
    cout << "x mult is " << x.mult() << endl;
    
    cout << "x(5) is " << x(5) << endl;
    cout << "x(25) is " << x(25) << endl;
    
    x.mult(7);
    cout << "x mult is " << x.mult() << endl;
    
    cout << "x(5) is " << x(5) << endl;
    cout << "x(25) is " << x(25) << endl;
    
    return 0;
}
