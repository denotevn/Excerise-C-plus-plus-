#include <iostream>
#include <boost/filesystem/fstream.hpp>
#include <iterator>
#include <vector>
#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

void write_file(){
    fs::path fpath{"count.txt"};
    fs::ofstream ofs{fpath};
    for(size_t i = 1; i <= 10; i++){
        ofs << i << "\n";
    }
}

int main(int argc, char *argv[]){
    write_file();
}