#include<iostream>
#include<string>
#include<vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
	vector<int> array;
	vector<int> array1;

	for(int i = 0; i < 10; ++i)
		array.push_back(i);

	for(auto i = array.begin(); i != array.end(); ++i)
		array1.push_back(*i);

	for(auto i : array)
		cout << i << " ";
	cout << endl;

	for(auto i : array1)
		cout << i << " ";
	cout << endl;

	return 0;
}
