// working.cpp by Bill Weinman <http://bw.org/>
// updated 2002-06-24
#include <iostream>
#include <fstream>
#include <string> 
#include <vector>

constexpr size_t  maxString = 512;
constexpr const char * filename = "items.txt";
constexpr char tab_char = '\t';

class Item{
    int _sku;
    std::string _name;
    std::string _desc;
public:
    Item(){reset();}
    Item(int sku, std::string &name, std::string &desc): _sku(sku), _name(name),_desc(desc){}
    Item(const Item &);
    Item &operator = (const Item &);
    ~Item(){reset();}

    void reset(){
        _sku = 0; _name = _desc = "unknown!";
    }

    void sku(int sku){_sku = sku;}
    void name(const std::string name){_name = name;}
    void desc(const std::string desc){_desc = desc;}

    int sku(){return _sku;}
    std::string name(){return _name;}
    std::string desc(){return _desc;}

};

Item :: Item(const Item &rsh){
    _sku = rsh._sku;
    _name = rsh._name;
    _desc = rsh._desc;
}

Item & Item::operator = (const Item &rsh){
    if(this != &rsh){
        _sku = rsh._sku;
        _name = rsh._name;
        _desc = rsh._desc;    
    }
}

std::vector<std::string> strsplit(const std::string &s){
    std::vector<std::string> strs_v;
    size_t start_loc = 0;
    size_t sep_loc = 0;
    while(true){
        // sep_loc tra ve vi tri dau tien tim thay tab_char
        sep_loc = s.find(tab_char, start_loc); // base.find(str, pos)
        strs_v.push_back(s.substr(start_loc, sep_loc - start_loc));
        if(sep_loc == std::string::npos){break; }
        // sep_loc == npos tuc la khong tim thay ky tu tab_char trong chuoi nua
        start_loc = sep_loc + 1;
    }
    return strs_v;
}


int main()
{
    char buf[maxString]; 
    // open file
    std::ifstream infile(filename);
    //read the file
    while (infile.good())
    {
        infile.getline(buf,sizeof(buf));
        if(*buf == 0) break;

        std::vector<std::string> split_v = strsplit(buf);
        if(split_v.size() < 3) continue;

        Item current_item(std::stoi(split_v[0]),split_v[1], split_v[2]);
        std::cout << "sku: " << current_item.sku()
            << ", name: " << current_item.name()
            << ", desc: " << current_item.desc() << std::endl;
    }

    infile.close();    

    return 0;
}
