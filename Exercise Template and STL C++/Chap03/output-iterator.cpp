// output-iterator.cpp by Bill Weinman <http://bw.org/>
// 2018-09-18 for CppSTL
#include <iostream>
#include <iterator>
using namespace std;

int main()
{
    ostream_iterator<int> output(cout, " ");
    
    for(int i : { 3, 197, 42 }) {
        *output++ = i;
    }
    cout << endl;

    return 0;
}
