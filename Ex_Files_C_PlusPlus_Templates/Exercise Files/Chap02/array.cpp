// array.cpp by Bill Weinman <http://bw.org/>
// 2019-11-04 for CppSTL
#include <iostream>
#include <array>
#include <string>
using namespace std;

// print the elements of the array
template<typename T, size_t N>
void printa(array<T, N> & a) {
    for(T &i : a) cout << i << " ";
    cout << endl;
}

// print a simple message
void message(const char * s) { cout << s << endl; }
template<typename T>
void message(const char * s, const T & v) { cout << s << ": " << v << endl; }

int main() {
    // initializer list
    message("initializer list");
    array<int, 5> a1 = { 1, 2, 3, 4, 5 };
    printa(a1);
    
    // default constructor
    message("default constructor");
    array<string, 5> a2;
    a2 = {"one", "two", "three"};
    printa(a2);
    
    // check the size
    message("size of a1", (int) a1.size());
    message("size of a2", (int) a2.size());
    
    // access elements
    message("a1 element 3 is", a1[3]);
    message("a2 element 2 is", a2[2]);
    message("a1 element 3 is", a1.at(3));
    message("a2 element 2 is", a2.at(2));
    
    // direct access data
    int * ip1 = a1.data();
    for (size_t i = 0; i < a1.size(); ++i) {
        cout << "element " << i << " is " << *ip1++ << endl;
    }
    
    string * ip2 = a2.data();
    for (size_t i = 0; i < a2.size(); ++i) {
        cout << "element " << i << " is " << *ip2++ << endl;
    }
    
    return 0;
}
