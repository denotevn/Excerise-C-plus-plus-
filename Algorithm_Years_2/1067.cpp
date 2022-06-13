#include <bits/stdc++.h>

using namespace std;

struct Directory{
    map<string, Directory* > children;
};


Directory *getDirectory(string const name, Directory* const parents){

    if((parents->children).find(name) == parents->children.end()){
        parents->children[name] = new Directory{};
        return parents->children[name];
    }else
    {
        return parents->children[name];
    }
}

void print(Directory* const parents, string currTab){

    string tab = " ";
    tab += currTab;
    map<string, Directory*> subfiles(parents->children.begin(), parents->children.end());
    map<string, Directory*> ::iterator p;
    
    for(p = subfiles.begin(); p != subfiles.end(); p++){
        cout << currTab << p->first << endl;
        print(p->second,tab);
    }
}

int main(){

    int n;
    cin >> n;
    Directory* root = new Directory{};
    string str;
    for(int i = 0 ; i <= n; i++){
        getline(cin,str);
        // Used for breaking words
        stringstream ss(str);

        Directory* current = root;
        // Dive into each subfolder
        // tach ra theo tung dong mot tung tu mot dong
        while (getline(ss,str,'\\'))
        {
            current = getDirectory(str,current);
        }
    }

    print(root,"");
    return 0;
}
