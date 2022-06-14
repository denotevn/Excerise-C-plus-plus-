#include <iostream>
#include <iomanip>	// for std::setw(n), std::setfill(ch), std::left, std::right
using namespace std;

int main()
{
	cout << "Kteam Solutions and Entertainment" << endl;
	cout << "HowKteam.com" << endl << endl;

	cout << setw(5) << left << "ID";		// độ rộng 5 ký tự, canh trái ID
	cout << setw(30) << left << "Name";	// độ rộng 30 ký tự, canh trái Name
	cout << setw(20) << right << "Address" << endl;	// độ rộng 20 ký tự, canh phải Address
	
	cout << setfill('-');		// set fill bằng ký tự '-' thay vì ' '
	cout << setw(55) << "-" << endl;	// fill 55 ký tự '-'

    // reset fill bằng ký tự ' '
	cout << setfill(' ');
	
	// in thông tin theo format như trên
	cout << setw(5) << left << 1;
	cout << setw(30) << left << "Tuan Dinh";
	cout << setw(20) << right << "Sai Gon" << endl;

	cout << setw(5) << left << 2;
	cout << setw(30) << left << "Khanh Ngoc";
	cout << setw(20) << right << "Sai Gon" << endl;

	cout << setw(5) << left << 3;
	cout << setw(30) << left << "Miu";
	cout << setw(20) << right << "Sai Gon" << endl;

    return 0;


	
}