// stablesort.cpp by Bill Weinman <http://bw.org/>
// 2018-10-01 for CppSTL
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template <typename T>
bool mycomp(const T & lh, const T & rh) {
    return int(lh) < int(rh);
}

template <typename T>
void disp_v(const T & v) {
    if(!v.size()) return;
    for(auto e :  v) { cout << e << " "; }
    cout << endl;
}

int main() {
    // prime numbers < 100
    vector<int> v1 = { 83, 53, 47, 23, 13, 59, 29, 41, 19, 71, 31, 67, 11, 2, 97, 7, 61, 73, 3, 79, 37, 43, 17, 5, 89 };
    vector<double> v2 = { 3.07, 2.49, 3.73, 6.58, 3.3, 2.72, 3.44, 8.78, 9.23, 4.09, 4.4, 1.65, 4.92, 0.42, 4.87, 5.03, 3.27, 7.29, 8.4, 6.12 };
    disp_v(v2);

    vector<double> v3;

    v3 = v2;
    sort(v3.begin(), v3.end(), mycomp<double>);
    disp_v(v3);
    
    v3 = v2;
    stable_sort(v3.begin(), v3.end(), mycomp<double>);
    disp_v(v3);
    
    return 0;
}
