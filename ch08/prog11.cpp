#include<sstream>
#include<iostream>
#include<vector>
#include<string>

using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::cin;
using std::istringstream;

struct PeronInfo {
	string name;
	vector<string> phones;
};

int main() 
{
	string line, word;
	vector<PeronInfo> people;
	istringstream record;
	while(getline(cin, line)) {
		record.clear();
		PeronInfo info;
		record.str(line);
		record >> info.name;
		while(record >> word)
			info.phones.push_back(word);
		people.push_back(info);
	}
	for(const auto i : people) {
		cout << i.name << " ";
		for(const auto k : i.phones)
			cout << k << " ";
		cout << endl;
	}
}
