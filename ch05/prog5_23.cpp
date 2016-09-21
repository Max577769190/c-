#include<iostream>
#include<stdexcept>
using std::cin;
using std::cout;
using std::endl;
using std::runtime_error;

int main()
{
	int a, b;
	while(cin >> a >> b)
		try
		{
			if(b == 0)
				throw runtime_error("Divisor should not be 0!");
			cout << a / b << endl;
		}
		catch (runtime_error err)
		{
			cout << err.what()
				 << "\n Try Again? Enter y or n" << endl;
			char c;
			cin >> c;
			if(!cin || c == 'n')
				break;
		}
	return 0;
}
