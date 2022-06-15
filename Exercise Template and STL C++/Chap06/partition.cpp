// partition.cpp by Bill Weinman <http://bw.org/>
// 2018-10-01 for CppSTL
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template <typename T>
bool is_even_tens(T & n) {
    if(n < 10) return false;
    return ((n / 10) % 2) == 0;
}

template <typename T>
void disp_v(const T & v) {
    if(!v.size()) return;
    for(auto e :  v) { cout << e << " "; }
    cout << endl;
}

int main() {
    // prime numbers > 10 & < 100
    vector<int> v1 = { 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
    disp_v(v1);
    
    partition(v1.begin(), v1.end(), is_even_tens<int>);
    disp_v(v1);

    return 0;
}
