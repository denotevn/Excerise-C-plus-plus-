// template-function.cpp by Bill Weinman <http://bw.org/>
// updated 2018-08-18
#include <iostream>
#include <string>
using namespace std;

template <typename T>
T maxof ( const T & a, const T & b ) {
    return ( a > b ? a : b );
}

int main() {
    int a = 7;
    int b = 9;
    
    cout << "max is " << maxof<int>( a, b ) << endl;
    
    return 0;
}
