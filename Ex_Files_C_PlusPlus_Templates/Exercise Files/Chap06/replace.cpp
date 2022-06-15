// replace.cpp by Bill Weinman <http://bw.org/>
// 2018-09-30 for CppSTL
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template <typename T>
bool is_even(const T & n) {
    return ((n % 2) == 0);
}

template <typename T>
void disp_v(const T & v) {
    if(!v.size()) return;
    for(auto e :  v) { cout << e << " "; }
    cout << endl;
}

int main() {
    // prime numbers < 100
    vector<int> v1 = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
    disp_v(v1);

    replace(v1.begin(), v1.end(), 47, 99);
    disp_v(v1);

    return 0;
}
