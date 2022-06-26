// errno.cpp by Bill Weinman <http://bw.org/>
// updated 2002-06-24
#include <cstdio>
#include <cerrno>

int main() {
    printf("Erasing file foo.bar\n");
    remove("foo.bar");
    printf("errno is: %d\n", errno);
    perror("Cannot erase file");
    return 0;
}
