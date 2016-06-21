/*
 * 11.22 	argument type: pair<string, vector<int>>
 * 			return type: pair<map<string, vector<int>>::iterator, bool>	
 */
#include<map>
#include<iostream>
#include<string>

using std::cin;
using std::cout;
using std::endl;
using std::multimap;
using std::string;

int main()
{
	multimap<string, string> family;
	string surname, child;

	while (cin >> surname >> child)
		family.emplace(surname, child);
	for (const auto &i : family)
		cout << i.first << " : " << i.second << endl;
}
