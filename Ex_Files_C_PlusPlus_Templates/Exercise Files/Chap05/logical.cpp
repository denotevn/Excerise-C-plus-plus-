// logical.cpp by Bill Weinman <http://bw.org/>
// 2018-11-06 for CppSTL
#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;

template <typename T>
void disp_v(T & v) {
    if(!v.size()) return;
    for(auto e :  v) { cout << e << " "; }
    cout << endl;
}

int main() {
    vector<int> v1 = { 1, 0, 1, 0, 1, 0, 1, 0 };
    vector<int> v2 = { 1, 1, 1, 1, 0, 0, 0, 0 };
    vector<int> v3(v1.size(), 0);
    disp_v(v1);
    disp_v(v2);
    cout << endl;
    
    logical_and<int> f;
    transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), f);
    disp_v(v3);
    
    return 0;
}
