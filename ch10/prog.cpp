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
	vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	list<int> lint;
	/*auto begin = vec[3], end = vec[7];
	for(; end > begin; --end)
		lint.push_back(end);
	cout << endl;

	for(auto i : lint)
		cout << i << endl;*/
	copy(vec.crbegin() + 3, vec.crbegin() + 8, back_inserter(lint));
	for(auto i : lint)
		cout << i << " ";
	cout << endl;
}
