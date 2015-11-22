#include<iostream>
using std::cin;
using std::cout;
using std::endl;

void switch_number(int *a, int *b)
{
	int i;
	i = *a;
	*a = *b;
	*b = i;
	return;
}

int main()
{
	int a, b;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;

	switch_number(&a, &b);
	cout << "a = " << a << " b = " << b << endl;
	return 0;
}
