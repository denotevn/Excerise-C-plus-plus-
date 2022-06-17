#include <iostream>
#include<iterator>

using namespace std;

void message(const char * m){ cout << m << endl; }

int main(){
    double d1 = 0, d2 = 0;

    cout << "Two number value: " << flush; //flush thì đơn giản là bắt nó ghi ra output ngay
    cin.clear();
    istream_iterator<double> eos; // default constructor is end-of-stream
    istream_iterator<double> iit(cin); // stdin iterator

    if(iit == eos){
        message("no value");
        return 0;
    }else{
        d1 = *iit++;
    }

    if(iit == eos){
        message("no second values !");
        return 0;
    }else{
        d2 = *iit;
    }

    cin.clear();
    cout << "d1 = " <<  d1 << endl;
    cout <<  "d2 = " << d2 << endl;
    cout << "d1 * d2 = " << d1*d2 << endl;
    return 0;

}