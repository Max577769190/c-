#include<list>
#include<string>
#include<vector>
#include<iostream>

using std::list;
using std::string;
using std::vector;

int main()
{
	list<const char *> s1 = {"a", "an", "the"};
	vector<string> s2;

	s2.assign(s1.begin(), s1.end());
	for(const auto i : s2)
		std::cout << i << std::endl;	

	return 0;
}
