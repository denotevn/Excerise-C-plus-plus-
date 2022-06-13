#include <iostream>
#include <cstdio>


unsigned long int factorial(unsigned long int n){
    unsigned long int result = n;
    while (n > 1)
    {
        result *= --n;
    }
    return result;
}

int main()
{
    unsigned long int n = 6;
    //printf("Enter the value n: ");
    //std::cin >> n;
    printf("Factiorial of %ld is: %ld",n, factorial(n));

    return 0;

}