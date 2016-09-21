#include<iostream>
using std::cin;
using std::cout;
using std::endl;

int absoluteValue(int n)
{
	if(n >= 0)
		return n;
	else
		return -n;
}

int main()
{
	int i;
	while(cin >> i)
		cout << absoluteValue(i) << endl;
	return 0;
}
