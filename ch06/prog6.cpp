#include<iostream>
using std::cin;
using std::cout;
using std::endl;

int fact(int i)
{
	static int n = 0;
	n++;
	cout << "n = " << n << endl;
	if(i == 1)
		return 1;
	else
		return i * fact(i - 1);
}

int main()
{
	int i;
	while(cin >> i)
	{
		cout << i << "! is " << fact(i) << endl;
		cout << "Continue? Please enter y or n:" << endl;
		char c;
		cin >> c;
		if(!cin || c == 'n')
			break;
	}
	return 0;
}
