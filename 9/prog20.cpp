#include<list>
#include<deque>
#include<iostream>

using std::list;
using std::deque;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	list<int> int_list;
	deque<int> oddDeque, evenDeque;

	for(int i = 0; i < 10; ++i)
		int_list.push_back(i);

	for(auto listBegin = int_list.begin(); listBegin != int_list.end(); ++listBegin) {
		if(*listBegin %2 == 0)
			evenDeque.push_back(*listBegin);
		else
			oddDeque.push_back(*listBegin);
	}

	for(auto i : oddDeque)
		cout << i << " ";
	cout << endl;

	for(auto i : evenDeque)
		cout << i << " ";
	cout << endl;

	return 0;
}
