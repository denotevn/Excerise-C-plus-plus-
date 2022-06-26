// file-io-struct.cpp by Bill Weinman <http://bw.org/>
// updated 2002-09-01
#include <cstdio>
#include <cstring>
#include <cstdint>


constexpr size_t maxlen = 127;

struct s1 {
    uint8_t num;
    uint8_t len;
    char s[maxlen + 1];
};

int main() {
    const char * fn = "test.file";            // file name
    const char * str = "This is a literal C-string.";
    
    // create/write the file
    puts("writing file");
    FILE * fw = fopen(fn, "wb");
    
    static s1 buf1;
    for( int i = 0; i < 5; i++ ) {
        buf1.num = i;
        buf1.len = (uint8_t) strlen(str);
        if(buf1.len > maxlen) buf1.len = maxlen;
        strncpy(buf1.s, str, maxlen);
        buf1.s[buf1.len] = 0; // make sure it's terminated
        fwrite(&buf1, sizeof(s1), 1, fw);
    }
    
    fclose(fw);
    puts("done.");
    
    // read the file
    puts("reading file");
    FILE * fr = fopen(fn, "rb");
    
    static s1 buf2;
    size_t rc;
    while(( rc = fread(&buf2, sizeof(s1), 1, fr) )) {
        printf("a: %d, b: %d, s: %s\n", buf2.num, buf2.len, buf2.s);
    }
    
    fclose(fr);
    
    puts("done.");
    
    return 0;
}
