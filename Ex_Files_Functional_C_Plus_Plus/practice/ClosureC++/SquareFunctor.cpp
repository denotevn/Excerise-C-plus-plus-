//  những class overload operator() còn được gọi là Functor
#include <iostream>
#include <algorithm>
#include <functional>
#include<bits/stdc++.h>

using namespace std;

class MySquareFunctor{
    public:
        MySquareFunctor(int data) : _data{data}{}
        int operator()(){
            return _data*_data;
        }
    private:
        int _data;
};

int main(){
    MySquareFunctor functor_5{5}, functor_10{10};
    std::cout << "Square of 5 = " << functor_5() << std::endl;
    std::cout << "Square of 10 = " << functor_10() << std:: endl;
    return 0;
}