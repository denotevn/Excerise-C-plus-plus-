#include <iostream>
#include <vector>
#include <algorithm>

class Compare {
    public:
        Compare(bool ascending) : _ascending{ascending} {}
        bool operator() (int first, int second) {
            if(_ascending)
                return first < second; // ascending order
            else
                return first > second; // descending order
        }
        
    private:
        bool _ascending{true};
};

class Display {
    public:
        // Operator take 1 argument to print
        void operator()(int something) {
            std::cout << something << " ";
        }
};

int main(){
    std::vector<int> data_list {1,5,6,3,2,7,8,9,4};
    
    Display visualizer;
    std::cout << "Initial list:" << std::endl;
    std::for_each(data_list.begin(), data_list.end(), visualizer); // we passed visualizer function object 
                                                    // as argument of function for_each
    std::cout << std::endl;
    
    std::cout << "Sorted ascending:" << std::endl;
    bool Ascending{true};
    Compare ascen{Ascending};
    std::sort(data_list.begin(), data_list.end(), ascen); // we pass ascen function object to sort function
    std::for_each(data_list.begin(), data_list.end(), visualizer); // we passed visualizer function object
    std::cout << std::endl;
    
    std::cout << "Sorted descending:" << std::endl;
    Ascending = false;
    Compare desc{Ascending};
    std::sort(data_list.begin(), data_list.end(), desc); // we pass desc function object to sort function
    std::for_each(data_list.begin(), data_list.end(), visualizer); // we passed visualizer function object
    std::cout << std::endl;
    
    return 0;
}
