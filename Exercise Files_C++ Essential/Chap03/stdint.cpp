// stdint.cpp by Bill Weinman <http://bw.org/>
// updated 2020-06-24
#include <cstdio>
#include <cstdint>

int main()
{
    printf("sizeof int8_t is %ld bits\n", sizeof(int8_t) * 8);
    printf("sizeof int16_t is %ld bits\n", sizeof(int16_t) * 8);
    printf("sizeof int32_t is %ld bits\n", sizeof(int32_t) * 8);
    printf("sizeof int64_t is %ld bits\n", sizeof(int64_t) * 8);

    printf("sizeof uint8_t is %ld bits\n", sizeof(uint8_t) * 8);
    printf("sizeof uint16_t is %ld bits\n", sizeof(uint16_t) * 8);
    printf("sizeof uint32_t is %ld bits\n", sizeof(uint32_t) * 8);
    printf("sizeof uint64_t is %ld bits\n", sizeof(uint64_t) * 8);

    return 0;
}
