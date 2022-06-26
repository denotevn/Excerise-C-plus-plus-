#include <iostream> 
#include <iterator>
#include <vector>
#include <string>
#include<functional>
#include<algorithm>

using namespace std;
void message(const char * m) { cout << m <<  endl; }
int main(){
    // output stream
    ostream_iterator<int> output(cout, "--"); // khai bao - gan gia tri la tu dong in ra
    for(int i : {1,2,3,4,5}){
        *output++ = i;
    }
    cout << endl;

    // input-stream
    puts("Practice with input stream");
    vector<int> data;
    cout << "Enter two value: " << endl;
    istream_iterator<int> eos; // end of stream
    istream_iterator<int> input(cin); // stdin

    if(input == eos){
        message("no value! ");
        return 0;
    }else{
        data.push_back(*input++);
    }

    if(input == eos){
        message("No second value! ");
        return 0;
    }else{
        data.push_back(*input);
    }

    for(int i : data){
        cout << i << " ";
    }
    cout << endl;

    
    /*
    cout << "Use istream-iterator for value string: " << endl;
    cout << "Enter some string" <<  endl;
    cout << "Enter a series of strings: ";
    istream_iterator<string> start(cin);
    istream_iterator<string> end;
    vector<string> v(start, end);

    for(int i = 0; i < 3; i++){
        v.push_back(*start);
    }
    */
    
    return 0;
}