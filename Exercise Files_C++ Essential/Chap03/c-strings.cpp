// c-strings.cpp by Bill Weinman <http://bw.org/>
// updated 2020-07-05
#include <cstdio>

int main() {
    char cstring[] = "String";
    
    puts(cstring);
    
    for(int i = 0; cstring[i]; i++) {
        printf("%d: %c\n", i, cstring[i]);
    }
    return 0;
}
