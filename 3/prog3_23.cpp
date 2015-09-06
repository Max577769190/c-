#include<iostream>
#include<string>
#include<vector>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int main()
{
	vector<int> array;

	for(int i = 1; i <= 10; ++i)
		array.push_back(i);

	for(auto i = array.begin(); i != array.end(); ++i)
		*i *= 2;

	for(auto i = array.begin(); i != array.end(); ++i)
		cout << *i << endl;
	return 0;
}
