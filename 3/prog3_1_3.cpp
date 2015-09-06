#include<iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
	int max = 0, min = 0;
	cout << "Enter two numbers:";
	cin >> max >> min;
	if(max < min)
	{
		int i = max;
		max = min;
		min = i;
	}
	while (min <= max)
	{
		cout << min << endl;
		min++;
	}
	return 0;
}
