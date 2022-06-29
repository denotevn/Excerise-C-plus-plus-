#include <iostream>
#include <memory>

//std::weak_ptrlà một con trỏ thông minh chứa một tham chiếu không sở hữu ("yếu") 
//đến một đối tượng được quản lý bởi std :: shared_ptr . Nó phải được chuyển đổi 
//thành std :: shared_ptr để truy cập đối tượng được tham chiếu.

std::weak_ptr<int> gw;
 
void observe()

{// returns the number of shared_ptr objects that manage the object
    std::cout << "gw.use_count() == " << gw.use_count() << "; "; 

    // we have to make a copy of shared pointer before usage:
    if (std::shared_ptr<int> spt = gw.lock()) // creates a shared_ptr that manages the referenced object) 
    {
        std::cout << "*spt == " << *spt << '\n';
    }
    else {
        std::cout << "gw is expired\n";
    }
}
 
int main()
{
    {
        auto sp = std::make_shared<int>(42);
        gw = sp;
 
        observe();
    }
 
    observe();
}
