#include<list>
#include<iostream>

using std::list;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	list<int> a = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	auto prev0 = a.begin();
	while(prev0 != a.end()) {
		if(*prev0 % 2) {
			prev0 = a.insert(prev0, *prev0);
			advance(prev0, 2);
		} else
			prev0 = a.erase(prev0);
	}

	for(auto i : a)
		cout << i << " ";
	cout << endl;

	return 0;
}
