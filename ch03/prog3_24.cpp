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
	int n;

	while(cin >> n)
		array.push_back(n);

	for(auto beg = array.begin(); beg != array.end(); ++beg)
		cout << (*beg + *(beg + 1)) << endl;
	cout << "----------------------------------------" << endl;	

	for(auto beg = array.begin(), end = array.end(); beg < end; ++beg, --end)
		cout << (*beg + *(end - 1)) / 2 << endl;

	return 0;
}
