// algorithm.cpp by Bill Weinman <http://bw.org/>
// 2018-09-27 for CppSTL
#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;

template <typename T>
void disp_v(const T & v) {
    if(!v.size()) return;
    for(auto e :  v) { cout << e << " "; }
    cout << endl;
}

int main() {
    int n = 42;

    // prime numbers < 100, out of order
    vector<int> v1 = { 71, 13, 59, 7, 53, 29, 3, 97, 5, 11, 17, 19, 23, 2, 31, 83, 37, 41, 89, 43, 47, 61, 67, 73, 79 };
    disp_v(v1);

    sort(v1.begin(), v1.end());
    disp_v(v1);
    if(binary_search(v1.begin(), v1.end(), n)) {
        cout << "found " << n << endl;
    } else {
        cout << "did not find " << n << endl;
    }
    
    return 0;
}
