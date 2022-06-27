#include<iostream>
#include<vector>

using namespace std;
int factorial(const int input, const int sum = 1){
    if(input > 1){
        return factorial(input - 1, sum * input);
    }
    return sum;
}

// using template metaProgramming
// ====================================================================
template<int input, int sum = 1>
struct Factorial : Factorial<input - 1, input * sum>{
};

template<int sum>
struct Factorial<1,sum> {
    enum{
        value = sum
    };
};

int main(){
    cout << "3! = " << factorial(3) << endl;
    cout << "Factorial<3> " << Factorial<3>::value << endl;
    cout << "Factorial<5> " << Factorial<5>::value << endl;
    return 0;
}
