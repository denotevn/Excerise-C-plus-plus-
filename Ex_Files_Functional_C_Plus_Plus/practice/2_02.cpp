/**
 * @file transform instead of map
 * @author Tuan Dinh (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-27
 * 
 * @copyright Copyright (c) 2022
 *
 * Map, filter and reduce dont exist in C++
 * std::transform replaces map
 * std::copy_if replaces filter
 * std::accumulate replaces resuce
 * 
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

int main(){

    auto render = [](auto collection){
        for(const auto &val: collection){
            cout << val << " ";
        }
        cout << endl;
    };

    vector<int> inCollection{1,2,3,4,5,6,7,8,9,10};
    render(inCollection);
    vector<int> outCollection;
    transform(inCollection.begin(), inCollection.end(),
        back_inserter(outCollection), [](const int &value){return value*3;}
        // std :: back_inserter xây dựng một trình lặp chèn ngược để chèn các 
        //phần tử mới vào cuối vùng chứa mà nó được áp dụng. Nó được định nghĩa bên trong tệp tiêu đề .
    );
    cout <<"Transforms" << endl;
    render(outCollection);

    // example using back_interter
    // Declaring first container
    vector<int> v1 = { 1, 2, 3 };
  
    // Declaring second container for
    // copying values
    vector<int> v2 = { 4, 5, 6 };
  
    // Using std::back_inserter inside std::copy
    std::copy(v1.begin(), v1.end(), std::back_inserter(v2));
    render(v1);
    render(v2);

    std::cout << "filteredCollection" << std::endl;
    vector<int> filteredCollection;
    copy_if(outCollection.begin(), outCollection.end(),
        back_inserter(filteredCollection), [](int &value){return value % 2 != 0;}
    );
    cout << "copy_if" << endl;
    render(filteredCollection);

    vector<int> filteredCollection1;
    copy_if(outCollection.begin(), outCollection.end(),
        back_inserter(filteredCollection1), [](int &value){return value % 2 == 0;}
    );
    cout << "Copy if so chan" << endl;
    render(filteredCollection1);

    cout << "Accumulate" << endl; // nhu kieu tinh tong cua mot mang 
    int result = accumulate(filteredCollection.begin(), filteredCollection.end(),
        0, [](int total, int current){ return total + current; }
    );
    cout << "result: " << result << endl;

    // v2 now contains 4 5 6 1 2 3
    return 0;
}