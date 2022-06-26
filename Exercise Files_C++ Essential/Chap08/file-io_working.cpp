#include <cstdio>
#include <iostream>
#include <vector>

constexpr int maxstring = 512;
constexpr int repeat = 5;

int main()
{
    const char * file_path = "text.txt";
    const char * str = "My name is Tuan \n" ;

    puts("Writing file");
    FILE *fw = fopen(file_path, "w");
    for(int i = 0; i < repeat; i++){
        fputs(str,fw);
    }
    fclose(fw);
    puts("Done!");

    puts("Reading file!");
    FILE *fr = fopen(file_path, "r");
    char buf[maxstring];

    std::vector<std::string> word;
    while (fgets(buf, maxstring, fr)) // fgets doc tu stream fr va luu vao buf voi size la maxstring
    {
        fputs(buf, stdout);
        word.push_back(buf);
    }

    fclose(fr);
    remove(file_path);

    for(int i = 0; i < word.size(); i++){
        std::cout << word[i] << std::endl;
    }

    puts("Done");

    return 0;
    

}