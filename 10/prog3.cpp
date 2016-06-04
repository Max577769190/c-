#include<vector>
#include<iostream>
#include<numeric>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
	vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int sum = accumulate(a.cbegin(), a.cend(), 0);
	cout << sum << endl;

	return 0;
}
