#include <iostream>

template<typename T> class Array{
    T *ptr;
    int size;

    public:
        Array(T a[], int s);
        void print();
};

template<typename T>
Array<T>::Array(T arr[], int s)
{
    ptr = new T[s];
    size = s;
    for(int i = 0; i < size; i++){
        ptr[i] = arr[i];
    }
}

template<typename T>
void Array<T> :: print()
{
    for(int i = 0; i < size; i++ ){
        std::cout << *(ptr+i) <<" ";
    }
    std::cout << std::endl;
}

int main()
{
    int arr[5] = { 1, 2, 3, 4, 5 };
    Array<int> a(arr, 5);
    a.print();
    return 0;
}