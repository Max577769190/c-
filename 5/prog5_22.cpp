#include<iostream>
using std::endl;
using std::cin;
using std::cout;

int get_size()
{
	int i;
	cin >> i;
	return i;
}

int main()
{
	int sz;
	while(sz = get_size())
	{
		if(sz <= 0)
		{
			cout << sz << endl;
			continue;
		}
		else
		{
			sz = 0;
			break;
		}
	}
	cout << sz << endl;
}
