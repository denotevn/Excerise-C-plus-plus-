## Topics 1 : transform, copy_if, acumulate in C++
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
    
