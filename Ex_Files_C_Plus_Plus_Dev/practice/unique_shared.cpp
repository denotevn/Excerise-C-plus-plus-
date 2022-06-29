// std::unique_ptr là một trong số các Smart Pointers của C++, được support từ C++11
//  khi sử dụng std::unique_ptr chúng ta không cần phải lo về việc giải phóng vùng nhớ của dynamic object 
// vì khi một biến std::unique_ptr đi ra khỏi phạm vi của nó thì đối tượng mà nó sở hữu cũng sẽ bị xoá

#include <iostream> 
#include <string>
#include <memory>

class Test{
    private:
        int mX;
    public:
        Test(){std::cout << "Test contructors " << std::endl;}
        ~Test(){std::cout << "Test is destructors" << std::endl;}
        void setX(int x){
            mX = x;
        }
        int getX(){return mX; }
};

int main(){
    std::unique_ptr<Test> ptr = std::make_unique<Test>();
    // Khi hàm main() kết thúc, 
    // biến ptr sẽ bị huỷ và đối tượng của class Test thuộc quyền sở hữu của ptr cũng sẽ được huỷ một cách tự động
    // chuyển quyền sở hữu dynamic object từ một std::unique_ptr sang một std::unique_ptr khác  dung std::move
    // std::unique_ptr<Test> ptr1 = std::move(ptr);
    ptr->setX(10);
    std::cout << ptr->getX() << std::endl;

    return 0;

}