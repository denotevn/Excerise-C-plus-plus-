// template-function.cpp by Bill Weinman <http://bw.org/>
// updated 2020-07-21
#include <iostream>
#include <vector>
#include <string>

template <typename T>
T maxof ( T a, T b ) {
    return ( a > b ? a : b );
}

template<typename T>
T mutiplate(T a, T b){
    return a+b;
}

// A template function to implement bubble sort.
// We can use this for any data type that supports
// comparison operator < and swap works for it.
template <class T> void bubbleSort(T a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; i < j; j--)
			if (a[j] < a[j - 1])
				std::swap(a[j], a[j - 1]);
}


int main() {
    std::cout << maxof<int>( 7, 9 ) << std::endl;
    std::cout << maxof<double> (1.2,3.4) << std::endl;
    
    int a[5] = { 10, 50, 30, 40, 20 };
    int n = sizeof(a) / sizeof(a[0]);
    std::cout << n << std::endl;
    // calls template function
    bubbleSort<int>(a, n);
  
    std::cout << "Sorted array : ";
    for (int i = 0; i < n; i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;

    std::cout <<"Phep cong: "<< mutiplate<double> (1.2,2.8) << std:: endl;

    std::cout << "using with another type"<< std::endl;
    std::cout << maxof<const char *> ("aaa", "bbb") << std::endl;
    return 0;
}
