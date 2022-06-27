#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

void acceptFunctionObject(std::function<void (int&)> f, int y) {
    f(y);
}

int main(){
    std::vector<int> data_list {1,2,5,6,7,8,9,4};

    auto visualizer = [](int &data){
        std::cout << data << " ";
    };

    std::cout << "Initial init: " <<  endl;
    std::for_each(data_list.begin(), data_list.end(), visualizer);

    std::cout << std::endl;

    //Compare ascen{Ascending};
    // We created a lambda function which captured Ascending variable
    // The caller of this function object will pass values for first argument and second argument
    // when call the function object

    bool Ascending{true};
    auto comparator = [& Ascending](int first, int second){
        if(Ascending)
            return first > second; //  cai nay binh thuong can ding hai ham
                                    // h dung mot ham la sort duoc theo 2 chieu luon
                                    // hieu qua cua dung lambda
        else
            return first < second;
    };

    std::cout << "sorted ascending: " <<  std::endl;
    std::sort(data_list.begin(), data_list.end(), comparator);
    for_each(data_list.begin(), data_list.end(), visualizer);
    std::cout << endl;

    
    //======================================
    Ascending = false;
    //Compare desc{Ascending};
    std::cout << "Sorted descending:" << std::endl;
    std::sort(data_list.begin(), data_list.end(), comparator); // we pass desc function object to sort function
    std::for_each(data_list.begin(), data_list.end(), visualizer); // we passed visualizer function object
    std::cout << std::endl;


    
    auto lambda3 = [](int& x, int& y) {
        std::cout << "Subtract x to y : " << x-y << std::endl;
    };

    using namespace std::placeholders;
    // neu chi de la ham con tro se bi complier error
    // nen la dung std::bin()
    auto lambda_bind = std::bind(lambda3, _1, 5); // _1 co nghia la so duoc gan sau do se tru di 5
    // Muon ro hon hay doc placeholders
    
    //acceptFunctionObject(lambda3, 3);  Compile error
    acceptFunctionObject(lambda_bind, 3); //  3 - 5 = -2

    return 0;
}


