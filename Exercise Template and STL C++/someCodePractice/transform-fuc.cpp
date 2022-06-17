#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

// keyword : back_inserter()

int main(){

    vector<int> v = {1,2,4,3};
    vector<string> result;

    transform(v.begin(),v.end(),back_inserter(result),[](int x){
        return to_string(x*2);
    });

    cout << "result with transform: " << endl;
    for_each(result.begin(), result.end(), [](const string& s){
        cout << s << endl;
    });

    // hoat dong voi char
    cout << "Word with type char : " <<endl;
    vector<char> v1 = { 'a','b','c' };  
    vector<int> v2 = { 3,1,4 };  
    vector<string> result1;  
  
    transform(v1.begin(), v1.end(), v2.begin(), back_inserter(result1),[](char a, int b) { 
        return string(b, a); 
    });  
  
    for_each(result1.begin(), result1.end(),[](const string& s) { 
        cout << s << endl; 
    });

    return 0;
}