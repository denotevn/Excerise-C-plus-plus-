// pair.cpp by Bill Weinman <http://bw.org/>
// 2019-09-10 for CppSTL
#include <iostream>
#include <utility>
#include <string>
using namespace std;

// print the pair
template<typename T1, typename T2>
void printpair(pair<T1, T2> & p) {
    cout << p.first << " : " << p.second << endl;
}

// print a simple message
void message(const char * s) { cout << s << endl; }
void message(const char * s, const int n) { cout << s << ": " << n << endl; }

int main() {
    // initializer list
    message("initializer list");
    pair<int, string> p1 = { 47, "forty-seven" };
    printpair(p1);
    
    // default constructor
    message("default constructor");
    pair<int, string> p2(72, "seventy-two");
    printpair(p2);
    
    // from make_pair
    message("make_pair");
    pair<int, string> p3;
    p3 = make_pair(7, "seven");
    printpair(p3);
    
    // comparison operators
    message("p1 == p2", p1 == p2);
    message("p1 < p2", p1 < p2);
    message("p1 < p3", p1 < p3);
    message("p1 > p2", p1 > p2);
    message("p2 > p3", p2 > p3);
    
    return 0;
}
