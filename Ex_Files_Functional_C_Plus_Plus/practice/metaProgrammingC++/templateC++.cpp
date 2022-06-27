#include <iostream>
#include <vector>
/*
template metaprogramming hoan thanh trong complie time
template thuong chay trong runtime
complie time -> runtime
vay thang template metaprogramming chay ra ket qua truoc khi runtime bat dau chay
*/
using namespace std;

//called at runtime
template<typename T>
T cube(const T& value){
    return value * value * value;
}

// using template metaprogramming
// Cube function for the tamplate metaprogramming is done at complie time
template<int toCube>
struct Cube{
    enum{
        result = toCube * toCube * toCube
    };
};

template<int u, int v>
struct Divisible{
    enum{
        value = u % v == 0 ? 1:0
    };  
};

template<int u>
struct Divisible<u,0>{
    enum{
        value = -1
    };
};

int main(){

    cout << "8 cube = " << cube(8) <<  endl;
    cout << "5 cube = " << Cube<5>::result << endl;
//============================================================================================
    cout<<Divisible<2,3>::value<<endl;  //Trả về 0; vì không chia hết
    cout<<Divisible<2,2>::value<<endl;  //Trả về 1; vì chia hết
    cout<<Divisible<2,0>::value<<endl;
    return 0;
}