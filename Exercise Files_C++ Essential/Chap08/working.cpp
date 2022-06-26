// working.cpp by Bill Weinman <http://bw.org/>
// updated 2002-06-24
#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <cstdlib>


constexpr int maxString = 512;
constexpr size_t name_size = 32;
constexpr size_t desc_size = 128;
constexpr const char * filename = "items.txt";
constexpr const char * result = "result.txt";

constexpr char tab_char = '\t';
constexpr size_t max_split = 15;

struct Item{
    int sku;   // stock keeping unit
    char name[name_size];
    char desc[desc_size];
};


size_t * str_seps(const char * s, size_t len)
{
    static size_t indicies[max_split +1];
    size_t & count = indicies[0];
    if(len < 3) return indicies;
    for(size_t &z : indicies){
        z = 0;
    }

    for(size_t i = 0; i < len; i++)
    {
        if(s[i] == tab_char){
            ++count;
            indicies[count] = i; // lu vi tri co tab_char
            if(count >= max_split) break;
        }
    }
    return indicies;
}


int main()
{

    char buf[maxString];
    FILE *fr = fopen(filename,"r");
    if(!fr){
        const char * errstr = strerror(errno);
        printf("Cannot open file (%d): %s \n", errno,errstr);
        return 1;
    }

    FILE *fw = fopen(result,"wb");
    static char buf1[maxString];

    while (fgets(buf,maxString,fr))
    {
        size_t len = strnlen(buf,maxString);
        if(len <= 5)
        {
            continue;
        }

        if(buf[len-1] == '\n'){
            buf[len-1] = 0;
            --len;
        }

        size_t * split3 = str_seps(buf,len);
        if(split3[0] < 2) break;
        buf[split3[1]] = buf[split3[2]] = 0; // thay doi dau tab_char thanh dau ket htuc cua chuoi char

        Item current_item;
        current_item.sku = atoi(buf);
        strncpy(current_item.name, buf + split3[1] + 1, name_size - 1);
        strncpy(current_item.desc, buf + split3[2] + 1, desc_size - 1);
        fwrite(& current_item, sizeof(Item), 1, fw);
        printf("sku: %d, name: %s, desc: %s\n", current_item.sku, current_item.name, current_item.desc);
    }

    // Read file binary
    FILE *fr1 = fopen(result,"rb");
    static Item buf2;
    size_t rc;

    while(rc = fread(&buf2,sizeof(Item),1,fr1)){
        printf("sku: %d, name: %s, desc: %s\n", buf2.sku, buf2.name, buf2.desc);
    }

    return 0;
}
