#include"Sales_data.h"
#include<iostream>
#include<string>
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	Sales_data a, b("asdf"), c("asdfasf", 2, 3), d(cin);

	read(cin, a);
	print(cout, a) << endl;
	print(cout, b) << endl;
	print(cout, c) << endl;
	print(cout, d) << endl;
	
	return 0;
}
