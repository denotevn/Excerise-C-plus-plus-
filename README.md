###***How to install boost for C++ libraies in Ubuntu*** 
> **Install libboost-all-dev Using apt-get**: 
> sudo apt-get update
> sudo apt-get -y install libboost-all-dev

### RAII in C++ programming (Resource Acquisition Is Initialization)
> Very complex memory management problem in C++. If you want to minimize the impact of memory management on the programming process, then RAII is the choice for you.
>
>
> Performs a ***binding between an object initialized*** on the heap and an ***object stored on the stack***. Thereby, when the object on the stack is destroyed, ie exits the scope of the object, the memory on the heap will also be destroyed.

###### You can see an example [example 1](https://github.com/denotevn/Practice-with-C-plus-plus/blob/master/Ex_Files_C_Plus_Plus_Dev/practice/RAII.cpp) , [example 2](https://github.com/denotevn/Practice-with-C-plus-plus/blob/master/Ex_Files_C_Plus_Plus_Dev/practice/challenge05.cpp)




#Some topics for C++

### Topics 1 : transform, copy_if, acumulate in C++

* ***1. Transform***
> Applies an operation sequentially to the elements of one (1) or two (2) ranges and stores the result in the range that begins at result.
***For example:***
~~~
int main()
{
    auto render = [](auto collection) {
        for(const auto &val: collection) {
            cout << val << endl;
        }
    };

    vector<int> inCollection{1,2,3,4,5,6,7,8,9,10};
    vector<int> outCollection;
    transform(inCollection.begin(), inCollection.end(), 
       back_inserter(outCollection), [](const int &value){ return value * 3;}
    );
    cout << "Transform" << endl;
    render(outCollection);
}
~~~
> The output: {3,,6,9,12,15,...,30}
> More examples at this link ***[Examples](https://github.com/denotevn/Practice-with-C-plus-plus/tree/master/Ex_Files_Functional_C_Plus_Plus/Ch02)***
    
***2. Copy_if***
> C++ Algorithm copy_if() function is used to copy the elements of the container [first,last] into a different container starting from result for which the value of pred is true.
> ***For examples: ***
~~~

int main()
{
    vector<int> inCollection{1,2,3,4,5,6,7,8,9,10};
    vector<int> filteredCollection;
    copy_if(outCollection.begin(), outCollection.end(),
        back_inserter(filteredCollection), [](int &value){ return value %2 != 0;});
    cout << "copy_if" << endl;
    render(filteredCollection);
    return 0;
}
~~~
> The output is the numbers in the original vector that satisfy the filter condition in copy_if. In this case , the output is {1,3,5,7,9}
> More examples at this link ***[Examples](https://github.com/denotevn/Practice-with-C-plus-plus/tree/master/Ex_Files_Functional_C_Plus_Plus/Ch02)***
    
***3. Acumulate***
> In short, the function is the sum of the elements
> More examples at this link ***[Examples](https://github.com/denotevn/Practice-with-C-plus-plus/tree/master/Ex_Files_Functional_C_Plus_Plus/Ch02)***
    
### Topics 2: Template metaprogramming with C++

***Difference between template and template metaprogramming***
> normal templates run ***at runtime*** , template metaprogramming runs at ***compile time***
> See example with factorial calculation function  ***[here](https://github.com/denotevn/Practice-with-C-plus-plus/blob/master/Ex_Files_Functional_C_Plus_Plus/practice/metaProgrammingC%2B%2B/factorial.cpp)***