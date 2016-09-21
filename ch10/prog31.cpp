#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::istream_iterator;
using std::ostream_iterator;

int main()
{
	istream_iterator<int> icin(cin), eof;
	ostream_iterator<int> icout(cout, " ");
	vector<int> vec;

	while(icin != eof)
		vec.push_back(*icin++);

	sort(vec.begin(), vec.end());
	unique_copy(vec.begin(), vec.end(), icout);
	cout << endl;
}
