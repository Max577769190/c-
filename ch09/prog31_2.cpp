#include<forward_list>
#include<iostream>

using std::forward_list;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	forward_list<int> a = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	auto before_beg0 = a.before_begin();
	auto beg0 = a.begin();

	while(beg0 != a.end()) {
		if(*beg0 % 2) {
			beg0 = a.insert_after(before_beg0, *beg0);
			advance(beg0, 2);
			advance(before_beg0, 2);
		} else {
			beg0 = a.erase_after(before_beg0);
		}
	}

	for(auto i : a)
		cout << i << " ";
	cout << endl;

	return 0;
}
