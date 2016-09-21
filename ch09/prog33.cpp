#include<vector>
#include<iostream>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	vector<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	auto begin = vi.begin();
	while(begin != vi.end()) {
		for(auto i : vi)
			cout << i << " ";
		cout << endl;
		++begin;
		vi.insert(begin, 42);
		++begin;
	}

	for(const auto i : vi)
		cout << i << " ";
	cout << endl;

	return 0;
}
