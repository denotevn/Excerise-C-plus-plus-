#include <iostream>
# include<exception>

namespace BW {
    class E : public std::exception{
        const char *msg;
        E();
        public:
            E(const char *s) noexcept(true) : msg(s){}
            const char * what() const noexcept(true){return msg;}
    };
}

const BW::E  e_ouch("Ouch!");
const BW::E e_bad("Bad_code!");
const BW::E e_worse("don't do that!");

void broken(){
    std::cout << "This is a broken function" << std::endl;
    //throw std::exception();
    // hoac minh tao mot namespace rieng cho exception
    throw e_ouch;
    // throw e_bad;
    // throw e_worse;
}

int main(){
    std::cout << "Let's have an emergency!" << std::endl;
    try{
        broken();
    }catch(BW::E &e){
        std::cout << e.what() << std::endl;
    }

    return 0;
}