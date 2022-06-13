#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include<cctype>

constexpr size_t maxlen = 127;

struct s1{
    uint8_t num;
    uint8_t len;
    char s[maxlen+1];
};

int main()
{
    const char  *file_path = "test.file";
    const char *str = "This is a literal C-string.";
    // creat/write the file 
    puts("Writing file");
    FILE *fw = fopen(file_path,"wb");

    static s1 buf1;
     for( int i = 0; i < 5; i++ ) {
        buf1.num = i;
        buf1.len = (uint8_t) strlen(str);
        if(buf1.len > maxlen) buf1.len = maxlen;
        strncpy(buf1.s, str, maxlen);
        buf1.s[buf1.len] = 0; // make sure it's terminated
        fwrite(&buf1, sizeof(s1), 1, fw);
        // con tro toi mang cac phan tu duoc gi
        // kich cu ohan tu duoc ghi
        // so phan tu, voi moi phan tu co ich co la size byte
        // stream - la con tro toi doi tuong FILE da xac dinh la mot Output Stream
    }

    fclose(fw);
    puts("Done.");

    // read file
    puts("reading file");
    FILE * fr = fopen(file_path, "rb");
    
    static s1 buf2;
    size_t rc;
    std::vector<s1> word;
    while(( rc = fread(&buf2, sizeof(s1), 1, fr) )) {
        word.push_back(buf2);
        std::cout<< rc << std::endl;
        printf("a: %d, b: %d, s: %s\n", buf2.num, buf2.len, buf2.s);
    }

    std::cout << "Data in vector word is: " << std::endl;
    for(int i = 0; i < word.size(); i++){
        char *sub_str = word[i].s;
        std::cout << word[i].num << " " << word[i].len << " " << sub_str;
    }
    puts("Done all!");

    fclose(fr);
    remove(file_path);

    std::vector <std::string> textWithDot;
    for(int i = 0; i < word.size(); i++){
        std::string s = word[i].s;
        s.replace(0,1,".");
        for(int j = 0; j < s.size(); j++){
            if (isspace(s[j]))
            {
                s.replace(j,1,".");
            }
        }
        textWithDot.push_back(s);
    }

    std::cout << "Result when replace spacce with dot: " << std::endl;

    for(std::string s: textWithDot){
        std::cout << s << std::endl;
    }
    return 0;

}

