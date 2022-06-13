// 04_solution.cpp by Bill Weinman <http://bw.org/>
// updated 2020-07-18
#include <cstdio>

int main()
{
    bool prime_flag = false;    // is it prime?

    // outer loop for prime candidates 2-99
    for(unsigned int candidate = 2; candidate < 100; ++candidate) {

        // test candidate for factors
        prime_flag = true;
        for(unsigned int factor = 2; factor < candidate; ++factor) {
            if(candidate % factor == 0) {
                prime_flag = false;
                break;
            }
        }

        // print it if it's prime
        if(prime_flag) printf("%d ", candidate);
    }

    // end with a newline
    puts("");
    return 0;
}
