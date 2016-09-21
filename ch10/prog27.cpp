#include<vector>
#include<list>
#include<iostream>
#include<algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::list;

int main()
{
	vector<int> vi = {1, 1, 2, 3, 4, 4, 5, 5, 5, 6, 6, 7};
	list<int> li;

	unique_copy(vi.cbegin(), vi.cend(), back_inserter(li));

	for(auto i : li)
		cout << i << " ";
	cout << endl;
}
