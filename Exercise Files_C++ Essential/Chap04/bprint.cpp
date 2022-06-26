// bprint.cpp by Bill Weinman <http://bw.org/>
// updated 2020-08-07
#include <cstdio>
#include <cstdint>

const char * u8_to_bstr(const uint8_t & u8) {
    static char s[9];   // space for 8-char string
    s[8] = 0;           // terminate string
    char * sp = s;
    for (uint8_t xbit = 0b10000000; xbit > 0; xbit >>= 1) {
        *(sp++) = ((u8 & xbit) == xbit) ? '1' : '0';
    }
    return s;
}

int main()
{
    uint8_t a = 5;
    uint8_t b = 10;
    uint8_t c = a | b;
    
    printf("x is %s\n", u8_to_bstr(a));
    printf("y is %s\n", u8_to_bstr(b));
    printf("result is %s\n", u8_to_bstr(c));
    
    return 0;
}

