// variadic.c by Bill Weinman <http://bw.org/>
// updated 2020-06-24
#include <cstdio>
#include <iostream>
#include <cstdarg>

using namespace std;
// first argument -- int count of remaining args
// remaining args -- doubles for average
double average(const int count, ...)
{
    va_list ap;
    double total = 0.0;
    
    va_start(ap, count);
    for(int i = 0; i < count; ++i) {
        total += va_arg(ap, double);
    }
    va_end(ap);
    return total / count;
}



// message works like printf, format plus args
// sends newline after message
int message(const char * fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    int rc = vfprintf(stdout, fmt, ap);
    puts("");
    va_end(ap);
    return rc;
}

double tong(double arr[], size_t size){
    static double tong = 0;
    for(int i =0 ; i < size ; i++){
        tong += arr[i];
    }
    return tong;
}

int main() {

    message("This is a message");
    int n;
    cin >> n;
    double arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << "Tong cua mang arr la: " << tong(arr,n);


    message("Average: %lf", average(n, 25.0, 35.7, 50.1, 127.6, 75.0));
    message("Average: %lf", average(5, 25.0, 35.7, 50.1, 127.6, 75.0));
    return 0;
}


double average2(double x1, double x2){
    return (x1+x2)/2;
}


double average3(double x1, double x2, double x3){
    return (x1+x2 + x3)/3;
}
double average4(double x1, double x2, double x3, double x4){
    return (x1+x2 + x3+x4)/4;
}
