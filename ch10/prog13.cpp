#include<string>
#include<vector>
#include<algorithm>
#include<iostream>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

bool compareSize(string &s) {
	return s.size() >= 5;
}

int main()
{
	vector<string> ls;
	string word;

	while(cin >> word)
		ls.push_back(word);

	auto stringEnd = partition(ls.begin(), ls.end(), compareSize);

	for(auto begin = ls.begin(); begin != stringEnd; ++begin) {
		cout << *begin << endl;
	}

	return 0;
}
