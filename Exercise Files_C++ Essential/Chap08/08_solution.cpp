// 08_solution.cpp by Bill Weinman <http://bw.org/>
// updated 2002-07-23
#include <cstdio>
#include <cerrno>
#include <cstdlib>
#include <cstring>

constexpr size_t maxstring = 1024;  // size of line buffer
constexpr size_t name_size = 32;    // size of name string
constexpr size_t desc_size = 128;   // size of description string
constexpr const char * filename = "/Users/billw/Desktop/ExerciseFiles/Chap08/items.txt";
constexpr size_t max_split = 15;
constexpr char tab_char = '\t';

struct Item {
    int sku;                // stock keeping unit
    char name[name_size];   // item name
    char desc[desc_size];   // item description
};

// str_seps(s) -- returns an array where each element
// represents the position of a separator in the string
// first element is a count
size_t * str_seps(const char * s, size_t len) {
    static size_t indicies[max_split + 1];
    size_t & count = indicies[0];
    if(len < 3) return indicies;
    for(size_t & z : indicies) z = 0; // zero out the array

    for(size_t i = 0; i < len; ++i) {
        if(s[i] == tab_char) {
            ++count;
            indicies[count] = i;
            if(count >= max_split) break;
        }
    }
    return indicies;
}

int main()
{
    char buf[maxstring];    // buffer for reading lines in file

    // open the file
    FILE * fr = fopen(filename, "r");
    if(!fr) {
        const char * errstr = strerror(errno);
        printf("cannot open file (%d): %s\n", errno, errstr);
        return 1;
    }

    // read loop
    while(fgets(buf, maxstring, fr)) {
        size_t len = strnlen(buf, maxstring);
        if(len <= 5) continue;

        // trim the newline from the end of the string
        if(buf[len - 1] == '\n') {
            buf[len - 1] = 0;
            --len;
        }
        
        size_t * split3 = str_seps(buf, len);
        if(split3[0] < 2) break;
        buf[split3[1]] = buf[split3[2]] = 0;   // change separators to terminators

        Item current_item;
        current_item.sku = atoi(buf);
        strncpy(current_item.name, buf + split3[1] + 1, name_size - 1);
        strncpy(current_item.desc, buf + split3[2] + 1, desc_size - 1);
        printf("sku: %d, name: %s, desc: %s\n", current_item.sku, current_item.name, current_item.desc);
    }
    return 0;
}
