#include<iostream>
#include<string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	int array[10];
	int *p_array = array;

	for(auto i : array)
		cout << i << endl;
	cout << endl;

	for(int i = 0; i < 10; ++i)
		*(p_array + i) = 0;

	for(auto i : array)
		cout << i << " ";
	cout << endl;

	return 0;
}
