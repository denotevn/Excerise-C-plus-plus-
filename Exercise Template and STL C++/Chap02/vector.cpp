// vector.cpp by Bill Weinman <http://bw.org/>
// 2019-11-03 for CppSTL
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// MARK: - utility functions

// print the elements of the vector
template<typename T>
void printv(vector<T> & v) {
    if(v.empty()) return;
    for(T &i : v) cout << i << " ";
    cout << endl;
}

// print a simple message
void message(const char * s) { cout << s << endl; }
void message(const char * s, const int n) { cout << s << ": " << n << endl; }

// MARK: - main

int main() {
    cout << "vector from initializer list: " << endl;
    vector<int> v1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    printv(v1);
    
    // info
    message("size", (int) v1.size());
    message("front", v1.front());
    message("back", v1.back());
    
    // index
    message("element at 5", v1[5]);
    message("element at 5", v1.at(5));
    
    // insert
    message("insert 42 at begin + 5:");
    v1.insert(v1.begin() + 5, 42);
    printv(v1);
    
    // erase
    message("erase at begin + 5:");
    v1.erase(v1.begin() + 5);
    printv(v1);
    
    // push_back
    message("push back 47:");
    v1.push_back(47);
    printv(v1);
    
    // pop_back
    message("pop_back:");
    v1.pop_back();
    printv(v1);
    
    // empty
    message("empty:");
    vector<int> vx = { 1, 2, 3 };
    while(!vx.empty()) {
        printv(vx);
        vx.pop_back();
    }
    
    // clear
    message("clear:");
    vx.insert(vx.begin(), { 1, 2, 3, 4, 5 });
    printv(vx);
    message("vx size", (int) vx.size());
    message("vx.clear()");
    vx.clear();
    message("vx size", (int) vx.size());
    printv(vx);
    
    // constructors
    
    // from C-array
    constexpr size_t size = 10;
    int ia[size] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    message("vector from C-array:");
    vector<int> v2(ia, ia + size);
    printv(v2);
    
    // filled with strings
    message("vector filled with string:");
    vector<string> v3(5, "string");
    printv(v3);
    
    // copy constructor
    message("vector copied from vector:");
    vector<string> v4(v3);
    printv(v4);
    
    // move constructor
    message("vector (v5) moved from vector (v4):");
    message("size of v4", (int) v4.size());
    vector<string> v5(std::move(v4));
    printv(v5);
    message("size of v4", (int) v4.size());
    
    return 0;
}
