#include <utility>
#include <iostream>

// tao class goi ham huy cho doi tuong
class resoure{
    int ID;
public:
    explicit resoure(int id):ID(std::move(id)){
        std::cout << "DemoRAII :" << ID << "\n";
    }

    ~resoure(){
        std::cout << "~resourse: " <<  ID << "\n";
    } 
};

class DemoRaii{
    public:
        explicit DemoRaii(std::string name) : m_name(std::move(name)) {
        std::cout << "DemoRaii: " << m_name << "\n";
        }

        ~DemoRaii(){
            std::cout << "~DemoRAii: " << m_name << "\n";
        }
    private:
        std::string m_name;
};

void demo(bool flag){
    std::cout << "Start demo: " << "\n";
    resoure rs1(2);
    DemoRaii("Khanh Ngoc");
    DemoRaii("Cuc cut boa");
    resoure rs2(15);


    if (flag)
    {
        std::__throw_runtime_error("Alocation is not true !!");
    }
    std::cout << "Exit demo cleaned ! ";

}

int main(){
    try{
        demo(true);
    }catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }
    return 0;
}