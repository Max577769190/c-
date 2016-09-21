#include<list>
#include<vector>

using std::list;
using std::vector;

int main()
{
	list<int> a1(10, 1);
	vector<int> a2(10, 1);

	auto begin = a1.begin(), end = a1.end();
	vector<double> a3(begin, end);

	auto begin1 = a2.begin(), end1 = a2.end();
	vector<double> a4(begin1, end1);

	return 0;
}
