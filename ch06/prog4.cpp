#include<iostream>
using std::cin;
using std::cout;
using std::endl;

int fact(int val)
{
	cout << val << endl;
	if(val == 1)
		return 1;
	else
		return val * fact(val - 1);
}

int main()
{
	int i;
	cin >> i;
	cout << i << "! is " << fact(i) << endl;
	return 0;
}
