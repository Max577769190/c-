#include<vector>
#include<iostream>
#include<list>
#include<algorithm>

using std::vector;
using std::list;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	/*vector<int> vec;
	list<int> lst;
	int i;

	while(cin >> i)
		lst.push_back(i);
	vec.resize(lst.size());
	copy(lst.cbegin(), lst.cend(), vec.begin());
	for(auto i : vec)
		cout << i << " ";
	cout << endl;*/

	vector<int> vec;
	vec.reserve(10);
	fill_n(back_inserter(vec), 10, 0);
	for(auto i : vec)
		cout << i << " ";
	cout << endl;
}
