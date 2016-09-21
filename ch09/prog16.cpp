#include<vector>
#include<iostream>
#include<list>

using std::vector;
using std::list;
using std::cin;
using std::cout;
using std::endl;

bool compare_vector(vector<int> &a1, list<int> &a2) {
	vector<int> a3(a2.begin(), a2.end());
	return a3 == a1;
}

int main()
{
	vector<int> a1(10, 1);
	list<int> a2(10, 1);

	cout << compare_vector(a1, a2) << endl;

	return 0;
}
