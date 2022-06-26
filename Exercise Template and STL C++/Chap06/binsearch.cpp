// binsearch.cpp by Bill Weinman <http://bw.org/>
// 2018-11-06 for CppSTL
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template <typename T>
bool gtcomp(const T & lh, const T & rh) {
    return lh > rh;
}

template <typename T>
void disp_v(const T & v) {
    if(!v.size()) return;
    for(auto e :  v) { cout << e << " "; }
    cout << endl;
}

int main() {
    int n = 47;
    
    // prime numbers < 100
    vector<int> v1 = { 83, 53, 47, 23, 13, 59, 29, 41, 19, 71, 31, 67, 11, 2, 97, 7, 61, 73, 3, 79, 37, 43, 17, 5, 89 };
    disp_v(v1);
    
    sort(v1.begin(), v1.end());
    disp_v(v1);
    
    cout << "searching for " << n << " ... ";
    if(binary_search(v1.begin(), v1.end(), n)) {
        cout << "found ";
    } else {
        cout << "not found";
    }
    cout << endl;
    
    return 0;
}
