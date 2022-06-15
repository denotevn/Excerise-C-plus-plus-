// search.cpp by Bill Weinman <http://bw.org/>
// 2018-09-30 for CppSTL
#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;

template <typename T>
bool is_odd(const T & n) {
    return ((n % 2) == 1);
}

template <typename T>
void disp_v(const T & v) {
    if(!v.size()) return;
    for(auto e :  v) { cout << e << " "; }
    cout << endl;
}

int main() {
    // prime numbers < 100
    const vector<int> v1 = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
    disp_v(v1);
    
    auto it = find(v1.begin(), v1.end(), 41);
    
    if(it != v1.end()) {
        size_t index = it - v1.begin();
        cout << "found at index " << index << ": " << *it << endl;
    } else {
        cout << "not found" << endl;
    }
    
    return 0;
}
