#include <iostream>
#include <string>

class Foo{
    private:
        int  data;
    public: 
        Foo(int data){
            this->data = data;
        }

        ~Foo(){};

        //Assigment contructor
        Foo& operator = (const Foo& rhs){
            std::cout << "Assigment contructors" << std::endl;
            data = rhs.data;
            return *this;
        }

        void printData(){
            std::cout << data << std::endl;
        }

        // Copying contructors
        Foo(const Foo& rhs){
            std::cout << "Cpoying contructors" << std::endl;
            data = rhs.data;
        }

};

int main(){
    Foo obj1(2); //Foo(int data) / Normal Constructor called
    Foo obj2 = obj1; // Copying Constructor Called
    obj2.printData(); // Prints 2
 
    Foo obj3(42);
    obj3 = obj1; //Assignment Constructor Called
    obj3.printData(); // Prints 2
}