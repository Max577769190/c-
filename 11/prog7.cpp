#include<iostream>
#include<map>
#include<string>
#include<vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;
using std::vector;

int main()
{
	map<string, vector<string>> family;
	string lastName, childName;
	int i;

	while(1) {
		cout << "The family table:" << endl;
		for(auto &w: family) {
			cout << w.first << " child: ";
			for(auto &i: w.second) {
				cout << "[ " << i << "]" << " ";
			}
			cout << endl;
		}
		cin >> i;
		switch(i) {
			case(1) :
				cin >> lastName;
				family[lastName].push_back("key must with a value?");
				break;
			case(2) :
				cin >> lastName;
				cin >> childName;
				family[lastName].push_back(childName);
				break;
			default :
				std::cerr << "unkonw number" << endl;
		}
	}
}
