// queue.cpp by Bill Weinman <http://bw.org/>
// updated 2018-09-14 for CppSTL
#include <iostream>
#include <list>
#include <deque>
#include <queue>
#include <string>
using namespace std;

template <typename T>
void report_queue(T & q) {
    size_t sz = q.size();
    cout << "size: " << sz;
    if(sz) cout << " front: " << q.front() << " back: " << q.back();
    cout << endl;
}

// print a simple message
void message(const char * s) { cout << s << endl; }

int main()
{
    // queue from list
    message("initialize queue from list");
    list<int> l1 = {1, 2, 3, 4, 5};
    queue<int, list<int>> q1(l1);    // constructor copies to new list
    report_queue(q1);
    
    message("pop all from q1");
    while(!q1.empty()) {
        cout << q1.front() << " ";
        q1.pop();
    }
    cout << endl;
    report_queue(q1);
    
    // default queue (deque)
    queue<string> q2;
    message("push strings onto q2");
    for( string s : {"one", "two", "three", "four", "five"} ) {
        q2.push(s);
    }
    report_queue(q2);
    
    message("pop all from q2");
    while(!q2.empty()) {
        cout << q2.front() << " ";
        q2.pop();
    }
    cout << endl;
    report_queue(q2);
    
    return 0;
}
