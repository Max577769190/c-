#include<iostream>
#include<vector>
#include<iterator>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::end;
using std::begin;

int main()
{
	vector<int> array1;

	for(int i = 0; i < 10; ++i)
		array1.push_back(i);
	for(auto i : array1)
		cout << i << endl;

	int array2[10];
	int *p_array2 = array2;

	for(auto i = array1.begin(); i != array1.end(); ++i)
		*(p_array2++) = *i;

	for(auto i : array2)
		cout << i << endl;

	return 0;
}
