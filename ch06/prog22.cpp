#include<iostream>
using std::cin;
using std::cout;
using std::endl;

void swap_two_pointer(int **, int **);
int main()
{
	int a = 2, b = 3;
	int *p_a = &a, *p_b = &b;
	swap_two_pointer(&p_a, &p_b);
	cout << "p_a = " << *p_a << endl;
	cout << "p_b = " << *p_b << endl;
	return 0;
}

void swap_two_pointer(int **a, int **b)
{
	int *temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
