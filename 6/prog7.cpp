#include<iostream>
using std::cin;
using std::cout;
using std::endl;

int function()
{
	static int n = 0;
	return n++;
}

int main()
{
	cout << function() << endl;
	cout << function() << endl;
	cout << function() << endl;
	cout << function() << endl;

	return 0;
}
