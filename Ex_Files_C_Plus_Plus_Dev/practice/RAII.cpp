// Resource Acquisition Is Initialization -  "việc thu hồi tài nguyên chính là khi khởi tạo"
//  RAII không chỉ có ứng dụng trong quản lí bộ nhớ, phương pháp này là tiền đề cho việc quản lí resource nói chung.
// mart Pointers được tạo ra để giúp cho các lập trình viên có thể tạm quên đi 
// việc quản lý bộ nhớ phức tạp này và giúp cho ứng dụng chạy hiệu quả hơn và chính xác hơn
// shared_ptr, unique_ptr, weak_ptr, scoped_ptr

#include <utility>
#include <iostream>

// Y tuong :
// Dua cac doi tuong vao trong class de sau khi khong dung den
// no se tu goi ham huy de giai phong bo nho
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

void demo(bool shouldThrow) {
    std::cout << "Enter demo \n";
    DemoRaii dr1("Em nha que");
    DemoRaii dr2("Tuan Dinh");
    if(shouldThrow){
        throw std::runtime_error("Alocation error !");
    }
    std::cout << "Exit demo clean \n";
}

int main(){
    try{
        demo(true);
    }catch(std::exception &e){
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}