#include <algorithm>
#include<string>
#include<iostream>
#include <vector>

using namespace std;

template<typename T> 
void display_v(vector<T> &v){
    if(!v.size()) return;
    for(T s : v) cout << s << " ";
    cout << endl;
}

int main(){
    vector<string> v1 = {"one","two","three", "four","five"};
    display_v<string>(v1);

    cout << "Size of each elemment: " <<  endl;
    vector<size_t> v2(v1.size());
    transform(v1.begin(), v1.end(), v2.begin(),[](string &s) -> size_t{
        return s.size();
    });
    display_v<size_t>(v2);

    cout << "Noi them chuoi vao: "<<  endl;
    vector<string> v3(v1.size());
    
    static int count  = 0; // static se thay doi lien tuc trong qua trinh bien dich
    transform(v1.begin(), v1.end(), v3.begin(), [](string &s) -> string{
        string s1;
        cout << "Nhap chuoi s"<< count++ <<": " << endl; // chi nhap duoc khong codau cach
       // cin >> s1;
        cin.clear();
        getline(cin, s1); // phai dung getline(cin, <ten chuoi can nhap>) thi moi nhap duoc chuoi co khoang trang
        // vi get line coi khi nhap het la kys tu xuong dong
        return s+s1;
        // return s+s; // phai return no moi them vao vector v3 duoc;
    });
    fflush(stdin);
    display_v<string>(v3);


}