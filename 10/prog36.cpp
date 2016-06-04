#include<iostream>
#include<list>
#include<algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::list;

int main()
{
	list<int> a {1, 2, 3, 4, 5, 0, 6, 7, 8, 9, 19};
	int i = 0;
	auto result = find(a.crbegin(), a.crend(), i);
	cout << *result << endl;
}
