#include<iostream>
using std::cout;
using std::endl;
using std::cin;

int numberMax(int, const int*);
int main()
{
	int a = 2, b = 3;
	cout << "The max number is " << numberMax(a, &b) << endl;
}

int numberMax(int a, const int *b)
{
	return a > *b ? a : *b ;
}
