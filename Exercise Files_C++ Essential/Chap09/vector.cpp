// std::vector.cpp by Bill Weinman <http://bw.org/>
// updated 2002-09-02
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::cout << "vector from initializer list: " << std::endl;
    std::vector<int> vi1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    
    std::cout << "size: " << vi1.size() << std::endl;
    std::cout << "front: " << vi1.front() << std::endl;
    std::cout << "back: " << vi1.back() << std::endl;
    std::cout << std::endl;
    
    // iterator
    std::vector<int>::iterator itbegin = vi1.begin();
    std::vector<int>::iterator itend = vi1.end();
    for (auto it = itbegin; it < itend; ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;
    
    std::cout << "element at 5: " << vi1[5] << std::endl;
    std::cout << "element at 5: " << vi1.at(5) << std::endl;

    std::cout << "range-based for loop:" << std::endl;
    for (int i : vi1) {
        std::cout << i << ' ';
    }
    std::cout << std::endl << std::endl;

    std::cout << "insert 42 at begin + 5: " << std::endl;
    vi1.insert(vi1.begin() + 5, 42);
    std::cout << "size: " << vi1.size() << std::endl;
    std::cout << "vi1[5]: " << vi1[5] << std::endl;
    
    std::cout << "erase at begin + 5: " << std::endl;
    vi1.erase(vi1.begin() + 5);
    std::cout << "size: " << vi1.size() << std::endl;
    std::cout << "vi1[5]: " << vi1[5] << std::endl;
    
    std::cout << "push_back 47: " << std::endl;
    vi1.push_back(47);
    std::cout << "size: " << vi1.size() << std::endl;
    std::cout << "vi1.back() " << vi1.back() << std::endl;
    std::cout << std::endl;

    // from C-array
    const static size_t size = 10;
    int ia[size] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    std::cout << "vector from C-array: " << std::endl;
    std::vector<int> vi2(ia, ia + size);
    for( int i : vi2 ) {
        std::cout << i << ' ';
    }
    std::cout << std::endl << std::endl;
    
    // std::vector of strings
    std::cout << "vector of strings:" << std::endl;
    std::vector<std::string> vs = { "one", "two", "three", "four", "five" };
    for(const std::string & v : vs) {
        std::cout << v << std::endl;
    }
    
    return 0;
}
