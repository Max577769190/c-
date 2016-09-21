#include"Person.h"
#include<iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	Person a(cin), b("ass", "asdf"), c;
	print(cout, a) << endl;
	print(cout, b) << endl;
	print(cout, c) << endl;
	return 0;
}
