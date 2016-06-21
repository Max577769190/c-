#include<map>
#include<string>
#include<iostream>
#include<set>

using std::cout;
using std::endl;
using std::multimap;
using std::string;
using std::multiset;
using std::map;

int main()
{
	multimap<string, string> author_article = {
		{"a", "e"},
		{"c", "c"},
		{"l", "a"},
		{"m", "a"},
		{"a", "a"},
	};
	map<string, multiset<string>> update;

	for (const auto &i : author_article) {
		update[i.first].insert(i.second);
	}
	for (const auto &i : update) {
		cout << i.first << " : ";
		for (const auto &w : i.second)
			cout << w ;
		cout << endl;
	}
	return 0;
}
