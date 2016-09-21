#include<iostream>
#include<vector>
#include<iterator>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
	vector<int> a {1, 2, 3, 4, 5, 6, 7, 8, 9};
	for(auto i = a.crbegin(); i != a.crend(); ++i)
		cout << *i << " ";
	cout << endl;
}
