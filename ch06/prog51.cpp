#include<iostream>
using std::cin;
using std::cout;
using std::endl;

void f();
void f(int);
void f(int, int);
void f(double, double);

int main()
{
	f();
	f(1);
	f(1, 2);
	f(1.2, 3.3);
	return 0;
}
void f()
{
	cout << "Nothing to do!" << endl;
}

void f(int i)
{
	cout << "The integer is " << i << endl;
}

void f(int a, int b)
{
	cout << "The number " << a << " and " << b << " sum is " << a+b << endl;
}

void f(double a, double b)
{
	cout << "The number " << a << " and " << b << " sum is " << a+b << endl;
}
