// merge.cpp by Bill Weinman <http://bw.org/>
// 2018-11-06 for CppSTL
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// compare for reverse sort
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
    vector<int> v1 = { 83, 53, 47, 23, 13, 59, 29, 41, 19, 71, 31, 67 };
    vector<int> v2 = { 2, 97, 7, 61, 73, 3, 79, 37, 43, 17, 5, 89, 11 };
    vector<int> v3(v1.size() + v2.size());
    disp_v(v1);
    disp_v(v2);
    cout << endl;
    
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    disp_v(v1);
    disp_v(v2);
    cout << endl;
    
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    disp_v(v3);
    
    return 0;
}
