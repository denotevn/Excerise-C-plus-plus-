// file-io.cpp by Bill Weinman <http://bw.org/>
// updated 2002-09-01
#include <cstdio>

constexpr int maxstring = 1024;    // read buffer size
constexpr int repeat = 5;

int main() {
    const char * fn = "testfile.txt";   // file name
    const char * str = "This is a literal c-string.\n";

    // create/write the file
    puts("writing file");
    FILE * fw = fopen(fn, "w");
    for(int i = 0; i < repeat; i++) {
        fputs(str, fw);
    }
    
    fclose(fw);
    puts("done.");
    
    // read the file
    puts("reading file");
    char buf[maxstring];
    FILE * fr = fopen(fn, "r");
    while(fgets(buf, maxstring, fr)) {
        fputs(buf, stdout);
    }
    
    fclose(fr);
    remove(fn);
    
    puts("done.");
    
    return 0;
}
