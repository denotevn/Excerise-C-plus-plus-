// typedef.cpp by Bill Weinman <http://bw.org/>
// updated 2020-08-05
#include <cstdio>

typedef unsigned char points_t;
typedef unsigned char rank_t;

struct score {
    points_t p;
    rank_t r;
};

int main()
{
    score s = { 5, 1 };
    printf("score s had %d points and a rank of %d\n", s.p, s.r);
    
    return 0;
}
