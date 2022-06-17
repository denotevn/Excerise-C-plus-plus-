#include <bits/stdc++.h>
using namespace std;

template <typename T>
void display_arr(T arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    // to add 2 array 
    // khong dung transform
    /*
    int arr1[] = {1, 2, 3};
    int arr2[] = {4, 5, 6};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    int res[n];

    // Code to add two arrays
    for (int i=0; i<n; i++)
        res[i] = arr1[i] + arr2[i];

    for (int i=0; i<3; i++)
        cout << res[i] << " ";
    */
    cout << " dung ham transform: " << endl;
    int arr1[] = {1, 2, 3};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "arr1: " << endl;
    display_arr<int>(arr1, n1);

    int arr2[] = {4, 5, 6};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "Array 2: " << endl;
    display_arr<int> (arr2,n2);
    

    int n = sizeof(arr1)/sizeof(arr1[0]);
    int res[n];

    // Single line code to add arr1[] and arr2[] and
    // store result in res[]
    transform(arr1, arr1+n, arr2, res, plus<int>()); // cong array 1 vao 2
    int n_res = sizeof(res) / sizeof(res[0]);
    cout << "Result arr1 + arr2:" << endl;
    display_arr<int>(res,n_res);

    return 0;
}