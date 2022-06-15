// lambda.cpp by Bill Weinman <http://bw.org/>
// 2018-09-24 for CppSTL
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
void disp_v(vector<T> & v) {
    if(!v.size()) return;
    for(T e :  v) { cout << e << " "; }
    cout << endl;
}

int main()
{
    int accum = 14;
    auto x = [accum](int d) mutable -> int { return accum += d; };
    
    vector<int> v1 = { 1, 2, 3, 4, 5};
    disp_v(v1);
    
    vector<int> v2(v1.size());
    transform(v1.begin(), v1.end(), v2.begin(), x);

    disp_v(v2);
    
    return 0;
}
