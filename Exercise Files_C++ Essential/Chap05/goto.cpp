// goto.cpp by Bill Weinman <http://bw.org/>
// updated 2020-06-24
#include <cstdio>

int main() {
	printf("Before the goto.\n");
	goto target;
	printf("After the goto.\n");
	target:
	printf("After the target.\n");
	return 0;
}
