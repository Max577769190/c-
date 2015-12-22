#include"Sales_data.h"
#include<iostream>
#include<string>
using std::cin;
using std::cout;
using std::endl;
using std::cerr;

int main()
{
	Sales_data a(cin);
	if(!a.isbn().empty())
	{
		std::istream &is = cin;	
		while(is)
		{
			Sales_data b(is);
			if(a.isbn() == b.isbn())
				a.combine(b);
			else
			{
				print(cout, a) << endl;
				a = b;
			}
		}
		print(cout, a) << endl;
	}
	else
		cerr << "No data!" << endl;
}
