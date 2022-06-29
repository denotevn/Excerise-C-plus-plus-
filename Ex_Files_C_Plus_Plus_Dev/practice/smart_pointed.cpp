#include <iostream>
#include <string>
#include <memory>
 
class Test {
private:
    int mX;
public:
    Test() { std::cout << "Test's constructor" << std::endl;}
    ~Test() { std::cout << "Test's destructor" << std::endl; }
    void setX(int x) { mX = x; }
    int getX() { return mX; }
};
 
int main()
{ 
    {
        std::cout << "scope of firstShared -- start" << std::endl;
        std::shared_ptr<Test> firstShared = std::make_shared<Test>();
        firstShared->setX(10);
        
        {
            std::cout << "scope of secondShared -- start" << std::endl;
            std::shared_ptr<Test> secondShared(firstShared); 
            std::cout << secondShared->getX() << std::endl;
            std::cout << "scope of secondShared -- end" << std::endl;
        }
        
        std::cout << "scope of firstShared -- end" << std::endl;
    }
    
    return 0;
}