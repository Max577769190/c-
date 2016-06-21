#include<string>
#include<map>
#include<iostream>

using std::cout;
using std::cin;
using std::endl;
using std::multimap;
using std::string;

int main()
{
	multimap<string, string> author_aticle = {
		{"a", "a"},
		{"a", "a"},
		{"a", "a"},
		{"b", "b"},
		{"c", "c"},
	};
	string author;

	cin >> author;
	for (auto temp = author_aticle.equal_range(author); temp.first != temp.second; ++temp.first)
		author_aticle.erase(temp.first);

	for (const auto &i : author_aticle)
		cout << i.first << " : " << i.second << endl;
}
