// iterator.cpp by Bill Weinman <http://bw.org/>
// 2018-09-18 for CppSTL
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vi1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    vector<int>::iterator it1;   // iterator object
    
    vector<int>::iterator ibegin = vi1.begin();
    vector<int>::iterator iend = vi1.end();
    
    for(it1 = ibegin; it1 < iend; ++it1) {
        cout << *it1 << " ";
    }
    cout << endl;
    
    return 0;
}
