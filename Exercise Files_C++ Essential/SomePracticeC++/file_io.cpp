#include<iostream>
#include<cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <cctype>

constexpr int maxstring = 512;
constexpr int repeat = 5;

int main()
{
    const char * path = "tuandinh.txt";
    const char *str = "My name is Tuan \n";
    const char *str1 = "My nam is Tuan. Im from Viet Nam. Now, I am studying at ITMO Univercity. My hobbies are watch on TV i son on. My English is not very well. I want to improve my English.";
    puts("Wring file \n");
    FILE *fw = fopen(path,"w");
    fputs(str,fw);
    for(int i = 0; i < repeat; i++)
    {
        fputs(str1,fw);
    }
    fclose(fw);
    puts("Done!");

    puts("Reading file! \n");
    FILE *fr = fopen(path,"r");
    char buf[maxstring];

    std::vector<std::string> words;
    size_t rc ;
    while (fgets(buf, maxstring, fr))
    // fgets - doc tu stream fr du lieu voi size maxstring 
    // vaf luu vao buf
    {
        fputs(buf, stdout);
        words.push_back(buf);

    }
    fclose(fr);
    remove(path);

    // Xu ly khoang trang va chu in hoa
    std::vector<std::string> textWithDot;
    for(int i = 0; i < words.size(); i++){
        std::string s = " " + words[i];
        

        for(int j = 0; j < s.size(); j++){
            if(isspace(s[j])){
                s.replace(j,1,".");
            }
            if(s[j] >= 65 && s[j] <= 90){
                s[j] = s[j] + 32;
            }
        }
        textWithDot.push_back(s);

    }

    // Sau khi da xu ly
    std::cout << "Sau khi da xu ly khoang trang va chu in hoa" << std::endl;
    for(std::string s : textWithDot){
        std::cout << s << std::endl;
    }

    return 0;
    
}