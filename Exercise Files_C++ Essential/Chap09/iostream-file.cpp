// iostream-file.cpp by Bill Weinman <http://bw.org/>
// updated 2002-06-24
#include <iostream>
#include <fstream>

int main() {
    static int lineno = 0;
    static const char * filename = "test.txt";
    static const char * textstring = "This is the test file";
    
    // write a file
    std::cout << "write the file:" << std::endl;
    std::ofstream ofile(filename);
    ofile << ++lineno << " " << textstring << std::endl;
    ofile << ++lineno << " " << textstring << std::endl;
    ofile << ++lineno << " " << textstring << std::endl;
    ofile.close();
    
    // read a file
    static char buf[128];
    std::cout << "read the file:" << std::endl;
    std::ifstream infile(filename);
    while (infile.good()) {
        infile.getline(buf, sizeof(buf));
        std::cout << buf << std::endl;
    }
    infile.close();
    
    // delete file
    std::cout << "delete file." << std::endl;
    remove(filename);
    return 0;
}
