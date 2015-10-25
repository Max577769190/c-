#include<iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	int sum = 0, val = 1;

	while (val <= 10)
	{
		sum += val, ++ val;
	}

	cout << sum << endl;

	return 0;
}
