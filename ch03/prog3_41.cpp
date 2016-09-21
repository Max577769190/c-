#include<iostream>
#include<cstring>
#include<vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::begin;
using std::end;

int main()
{
	int array[10];

	for(int i = 0; i < 10; ++i)
		array[i] = i;

	vector<int> array1(begin(array), end(array));
	
	for(auto i : array1)
		cout << i << " ";
	cout << endl;

	return 0;
}
