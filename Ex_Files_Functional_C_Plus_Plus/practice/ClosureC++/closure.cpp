#include <iostream>

using namespace std;

auto incremeter = [](){
    auto increment = 0;
    return [increment]() mutable {
        return increment++;
    };
};

int main(){
    auto myInc = incremeter();
    cout <<  "My Inc = " << myInc() << endl;
    cout <<  "My Inc = " << myInc() << endl;
    cout <<  "My Inc = " << myInc() << endl;
    cout <<  "My Inc = " << myInc() << endl;

    return 0;
}