#include<iostream>
using std::cin;
using std::cout;
using std::endl;

int &get(int *arry, int index);
int main()
{
	int ia[10];
	for (int i = 0; i != 10; ++i)
		get(ia, i) = i;
	for (auto i : ia)
		cout << i << endl;
	return 0;
}
int &get(int *arry, int index)
{
	return arry[index];
}
