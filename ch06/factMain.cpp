#include<iostream>
#include<stdexcept>
#include"Chapter6.h"
using std::runtime_error;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	int i;
	while(cin >> i)
	{
		try
		{
			if(i <= 0)
				throw runtime_error("The number should bigger zero!");
			cout << i << "! is " << fact(i) << endl;
		}
		catch (runtime_error err)
		{
			cout << err.what()
				 << "\nTry Again? Enter y or n" << endl;
			char c;
			cin >> c;
			if(!cin || c == 'n')
				break;
		}
	}
}
