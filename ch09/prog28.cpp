#include<forward_list>
#include<iostream>
#include<string>

using std::forward_list;
using std::string;
using std::cin;
using std::cout;
using std::endl;

void insert_word(forward_list<string> &flst, const string &s1, const string &s2) {
	auto prev0 = flst.before_begin();
	auto curr = flst.begin();

	while(*curr != s1) {
		while(curr != flst.end()) {
			prev0 = curr;
			++curr;
		}
		break;
	}

	if(curr == flst.end())
		flst.insert_after(prev0, s2);
	else
		flst.insert_after(prev0, s2);
}

int main()
{
	forward_list<string> flst = {"apple", "pea", "one", "two", "three"};

	insert_word(flst, "onw", "one");

	for(auto i : flst)
		cout << i << " ";
	cout << endl;

	return 0;
}
