#include<vector>
#include<iostream>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

bool compare_vector(vector<int> &a1, vector<int> &a2) {
	return a1 == a2;
}

int main()
{
	vector<int> a1(10, 1);
	vector<int> a2(10, 1);

	cout << compare_vector(a1, a2) << endl;

	return 0;
}
