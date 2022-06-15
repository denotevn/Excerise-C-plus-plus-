#include <iostream>
#include <cctype>
#include <cstring>
#include <string>
// bai nay lam theo 2 cach
// mot la in truc tiep tu struct
// 2 la lu vao file binary
// sau do doc va in ket qua ra man hinh
constexpr const int name_size = 32;
constexpr int desc_size = 128;
constexpr const char * path = "items.txt";
constexpr const char *file_result = "result.txt";

constexpr const int maxString = 512;
constexpr const char tab_char = '\t';

struct Item{
    int sku;
    char name[name_size];
    char desc[desc_size];
};

size_t *str_seps(const char *s, size_t n)
{
    static size_t indicies[15];
    size_t &count = indicies[0];
    if(n < 3) return indicies;
    for(size_t &z : indicies){
        z = 0;
    }

    for(size_t i = 0; i < n; i++){
        if (s[i] == tab_char)
        {   
            ++count;
            indicies[count] = i;
            if(count >= 15) break; 
        }
        
    }

    return indicies;
}

int main()
{
    FILE *fr = fopen(path,"r");
    char buf[maxString];
    if(!fr){
        const char *errstr = strerror(errno);
        printf("Can not open file %d: %s\n",errno, errstr);
        return 1;
    }

    FILE *fw = fopen(file_result,"wb");


    while (fgets(buf,maxString,fr))
    {
        size_t len = strnlen(buf, maxString);
        if(len < 5) continue;

        size_t *split3 = str_seps(buf, len); 

        if(split3[0] < 2) break;
        buf[split3[1]] = buf [split3[2]] = 0; // thay tab_char == dau let thuc cua chuoi

        Item item;
        item.sku = atoi(buf);
        strncpy(item.name, buf + split3[1] + 1, name_size -1);
        strncpy(item.desc, buf + split3[2] + 1, desc_size - 1);

        // buf1.sku = atoi(buf);
        // strncpy(buf1.name, buf + split3[1]+ 1, name_size - 1);
        // strncpy(buf1.desc, buf + split3[2] + 1, desc_size - 1);
        // fwrite(&buf1,sizeof(Item), 1, fw);
        fwrite(&item, sizeof(Item),1, fw);
        printf("sku: %d, name: %s, desc: %s\n", item.sku, item.name, item.desc);
    }

    fclose(fw);
    puts("Writed file!");
    puts ("--------------------------------------------------!\n");
    puts("Read file! \n");

    FILE *fr1 = fopen(file_result, "rb");
    static Item buf2;
    size_t rc;
    while ((rc = fread(&buf2, sizeof(Item), 1, fr1))) // neu cho 2 dau bang se khong doc duoc file naycd 
    {
        printf("sku: %d, name: %s, desc: %s\n", buf2.sku, buf2.name, buf2.desc);
    }
    return 0;
}

