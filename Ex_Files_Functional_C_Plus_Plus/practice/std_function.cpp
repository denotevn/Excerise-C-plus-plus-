#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <string>

/**
 * @brief 
 * 
 * là trình bao bọc cho các đối tượng bất khả xâm phạm
    Các đối tượng có thể xâm nhập bao gồm hàm, chức năng và lamdas
    có thể lưu trữ hàm trong các đối tượng như vectơ
 */
using namespace std;

void demoFunction(){
    cout << "Called demofunction "<<  endl;
}

void adder(int a, int b){
    cout << "Called adder, a + b = " << a + b << endl;
}

class functor{
    public:
        void operator()() const{
            cout << "Called functor" << endl;
        }
};

int main(){

    std::vector<std::function<void()>> funcs;
    funcs.push_back(demoFunction);
    functor functor_istance;
    funcs.push_back(functor_istance);
    funcs.push_back([](){cout << "Called anoymous lambda" << endl;});
    funcs.push_back(std::bind(&adder, 10 , 15));

    for(auto &f : funcs){
        f();
    }

    return 0;
}