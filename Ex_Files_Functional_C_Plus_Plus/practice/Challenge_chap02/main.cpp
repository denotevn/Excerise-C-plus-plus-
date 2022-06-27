#include <iostream>
#include <vector>
#include <functional>


auto ContinuousAdd = [](int initial, int addBy){
    auto total = initial;
    return [total, addBy]()mutable {
        total += addBy;
        return total;
    };
};

int main(){
    auto x = ContinuousAdd(1997,3);
    std::cout << x() << std::endl;
    std::cout << x() << std::endl;
    std::cout << x() << std::endl;
    std::cout << x() << std::endl;

    return 0;
    
    
}