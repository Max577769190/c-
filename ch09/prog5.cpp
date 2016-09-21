#include<iostream>
#include<vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

vector<int>::const_iterator find_integer(vector<int>::const_iterator begin, vector<int>::const_iterator end, int num) {
	for(; begin != end; ++begin) {
		if(*begin == num)
			return begin;
	}
	std::cerr << "Can't find the number!" << endl;
	return end;
}

int main()
{
	vector<int> a{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	auto a_cbegin = a.cbegin();
	auto a_cend = a.cend();
	cout << *(find_integer(a_cbegin, a_cend, 5)) << endl;
	cout << *(find_integer(a_cbegin, a_cend, 10)) << endl;
	return 0;
}
