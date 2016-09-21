#include<vector>
#include<list>
#include<iostream>
#include<algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::inserter;
using std::list;

int main()
{
	vector<int> vi0 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	list<int> vi1, vi2, vi3;

	copy(vi0.cbegin(), vi0.cend(), inserter(vi1, vi1.begin()));
	copy(vi0.cbegin(), vi0.cend(), front_inserter(vi2));
	copy(vi0.cbegin(), vi0.cend(), back_inserter(vi3));

	for(auto i : vi1)
		cout << i << " ";
	cout << endl;

	for(auto i : vi2)
		cout << i << " ";
	cout << endl;

	for(auto i : vi3)
		cout << i << " ";
	cout << endl;
}
