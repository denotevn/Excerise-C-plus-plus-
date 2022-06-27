#include <iostream>
#include <cmath>
#include <vector>
#include <functional>
#include <algorithm>
#include <numeric>


using namespace std;


auto greater_than(int first, int second){
    return first >= second;
}


int main() {

    // this is for show element of array
    auto render = [](auto collection){
        for(const auto &val: collection){
            cout << val << " ";
        }
        cout << endl;
    };

    vector<int> ages{9, 20, 13, 4, 5, 6, 10, 28, 19, 15, 60, 23, 47, 12, 19, 99};
    int over21 = 0;
    for (int age : ages) {
        if (age >= 21) {
            over21++;
    }
    }
    cout << "Number over 21 = " << over21 << endl;

    auto num_over21 = count_if(ages.begin(), ages.end(),
    std::bind(&greater_than, std::placeholders::_1, 21)); // placeholders là không gian tên 
    // định hướng vị trí của một giá trị trong một hàm. Chúng được đại diện bởi _1, _2, _3 … 
    // _1 is for first parameter and assigned

    cout << "New Number of 21: " << num_over21 <<  endl;

//'--------------------------------------------------------------'

    // mot cach dung count_if
    vector<int> list {1,3,2,4,3,56,24,33,21,-2};
    auto count_div3 = std::count_if(list.begin(), list.end(),
        [](int &value){return value % 3 == 0;});

    vector<int> collection_div3;
    std::copy_if(list.begin(), list.end(), back_inserter(collection_div3),
    [](int &val){return val % 3 == 0;});

    cout << "number of list after using count_if: " << count_div3 << endl;
    cout << "New number of list div3: " << collection_div3.size() << endl;
    render(collection_div3);


    return 0;
}