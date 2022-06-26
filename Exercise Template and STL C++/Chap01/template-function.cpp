// template-function.cpp by Bill Weinman <http://bw.org/>
// updated 2018-08-18
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
T maxof ( const T & a, const T & b ) {
    return ( a > b ? a : b );
}

template <typename T>
void printv(const vector<T> & v){
    if(v.empty()) return;
    for(int i = 0; i < v.size(); i++){
        cout << v[i] <<  " ";
    }
    cout << endl;
}

int main() {

    vector<int> v1 = {1,2,3,4,5,6,7,8,9};
    vector<string> s1 = {"one", "two", "three", "four", "five"};
    printv<int>(v1);
    printv<string>(s1);

    int a = 7;
    int b = 9;
    
    cout << "max is " << maxof<int>( a, b ) << endl;
    
    return 0;
}
