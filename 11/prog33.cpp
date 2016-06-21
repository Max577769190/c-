#include<map>
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::istringstream;
using std::ifstream;
using std::string;
using std::runtime_error;

map<string, string> buildMap(ifstream &map_file)
{
	map<string, string> trans_map;
	string key;
	string value;
	while (map_file >> key && getline(map_file, value))
		if (value.size() > 1)
			trans_map[key] = value.substr(1);
		else
			throw runtime_error("no rule for " + key);
	return trans_map;
}

const string &
transform(const string &s, const map<string, string> &m) {
	auto temp = m.find(s);
	if (temp != m.cend())
		return temp->second;
	else
		return s;
}

void word_transform(ifstream &map_file, ifstream &input)
{
	auto trans_map = buildMap(map_file);
	string text;
	while (getline(input, text)) {
		istringstream stream(text);
		string word;
		bool firstword = true;
		while (stream >> word) {
			if (firstword)
				firstword = false;
			else
				cout << " ";
			cout << transform(word, trans_map);
		}
	}
	cout << endl;
}

int main(int argc, char *argv[])
{
	ifstream map_file(argv[1]), input(argv[2]);
	word_transform(map_file, input);
	return 0;
}
