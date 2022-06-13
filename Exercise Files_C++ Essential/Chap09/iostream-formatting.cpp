// iostream-formatting.cpp by Bill Weinman <http://bw.org/>
// updated 2002-09-03
#include <iostream>
#include <string>
#include <iomanip>

int main() {
    // cout is a very common class from iostream
    std::cout << "Hello, World!" << std::endl;

    std::string istr;
    std::cout << "Prompt: ";
    std::cin >> istr;    // one word at a time
    std::cout << "Input: " << istr << std::endl;

    // integer formatting
    int i1 = 42;
    int i2 = 127;
    int i3 = 5555;
    std::cout << "default: " << i1 << ' ' << i2 << ' ' << i3 << std::endl;
    std::cout << "hex: " << std::hex << i1 << ' ' << i2 << ' ' << i3 << std::endl;
    std::cout << "hex with showbase: " << std::showbase << std::hex << i1 << ' ' << i2 << ' ' << i3 << std::endl;
    std::cout << "octal with showbase: " << std::oct << i1 << ' ' << i2 << ' ' << i3 << std::endl;
    std::cout << "default: " << std::noshowbase << std::dec << i1 << ' ' << i2 << ' ' << i3 << std::endl << std::endl;
    
    // floating point formatting options
    double d1, d2, d3;
    d1 = 3.1415926534;
    d2 = 1234.5;
    d3 = 4.2e-10;
    std::cout << "default: " << d1 << ' ' << d2 << ' ' << d3 << ' ' << std::endl;
    std::cout << "fixed: " << std::fixed << d1 << ' ' << d2 << ' ' << d3 << ' ' << std::endl;
    std::cout << "scientific: " << std::scientific << d1 << ' ' << d2 << ' ' << d3 << ' ' << std::endl;
    std::cout << "set precision (3): " << std::setprecision(3) << std::fixed << d1 << ' ' << d2 << ' ' << d3 << ' ' << std::endl;
    std::cout << "scientific (7): " << std::setprecision(7) << std::scientific << d1 << ' ' << d2 << ' ' << d3 << ' ' << std::endl;
    std::cout.unsetf(std::ios_base::floatfield);
    std::cout << "default: " << d1 << ' ' << d2 << ' ' << d3 << ' ' << std::endl << std::endl;
    
    // string formatting options
    std::string s1 = "This is a string.";
    std::string s2 = "This is a much longer string.";
    std::string s3 = "Today's news: Big Light in Sky Slated to Appear in East";
    
    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;
    std::cout << s3 << std::endl;
    
    std::cout << std::setw(64) << std::right << s1 << std::endl;
    std::cout << std::setw(64) << std::right << s2 << std::endl;
    std::cout << std::setw(64) << std::right << s3 << std::endl;
    
    std::cout << std::setfill('-') << std::setw(64) << std::right << s1 << std::endl;
    std::cout << std::setfill(' ') << std::setw(64) << std::right << s1 << std::endl;
    std::cout << std::left << s1 << std::endl;
    
    return 0;
}
