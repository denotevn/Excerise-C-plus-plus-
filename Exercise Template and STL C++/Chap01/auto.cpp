// auto.cpp by Bill Weinman <http://bw.org/>
// updated 2018-11-02
#include <iostream>
#include <typeinfo>
#include <string>
using namespace std;

int main() {
    int i = 47;
    const char * cstr = "this is a c-string";
    const string sclass = string("this is a string class string");
    
    auto x = "this is a c-string";
    decltype(x) y;
    
    cout << "type of i is " << typeid(i).name() << endl;
    cout << "type of cstr is " << typeid(cstr).name() << endl;
    cout << "type of sclass is " << typeid(sclass).name() << endl;
    cout << "type of x is " << typeid(x).name() << endl;
    cout << "type of y is " << typeid(y).name() << endl;
    
    return 0;
}
