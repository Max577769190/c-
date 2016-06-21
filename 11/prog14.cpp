#include<map>
#include<iostream>
#include<utility>
#include<vector>
#include<string>

using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::vector;
using std::map;
using std::string;

int main()
{
	pair<string, string> child;
	map<string, vector<pair<string, string>>> family;
	string firstname, lastname, birthday;

	while (1) {
		cout << "The family list:" << endl;
		for (const auto &i : family) {
			cout << i.first << " : ";
			for (const auto &w : i.second) {
				cout << "[" << w.first << " : "<< w.second << "]" << " ";
			}
			cout << endl;
		}
		cout << "Must be enter the family firstname the child lastname and birthday:" << endl; 
		cin >> firstname >> lastname >> birthday;
		family[firstname].push_back(make_pair(lastname, birthday));
	}
}
