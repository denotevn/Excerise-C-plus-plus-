#include<iostream>
#include<algorithm>
#include <vector>

using namespace std;

template<typename T>
void print_info(const vector<T> & s){
    if(!s.size()) return;
    for(auto s1 : s){ cout << s1 << ' '; }
    cout << endl;
}

int main(){

    int n = 2;
    vector<int> v = {1,2,3,4,23,2,23,42,-12,42,4,5,6,7,8,9,10,81,72};
    print_info(v);

    sort(v.begin(),v.end());
    print_info(v);

    if(binary_search(v.begin(), v.end(), n)){
        cout << "Found !" << endl;
    }else{
        cout << "Did not find! " << endl;
    }

    return 0;
}