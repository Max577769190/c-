#include<vector>
#include<string>
#include<iostream>
#include<algorithm>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

bool isShorter(const string &s1, const string &s2) {
	return s1.size() < s2.size();
}

void slimDups(vector<string> &ls) {
	sort(ls.begin(), ls.end());
	auto unique_end = unique(ls.begin(), ls.end());
	ls.erase(unique_end, ls.end());
}

int main()
{
	vector<string> ls;
	string word;

	while(cin >> word)
		ls.push_back(word);

	slimDups(ls);
	stable_sort(ls.begin(), ls.end(), isShorter);

	for(auto i : ls)
		cout << i << " ";
	cout << endl;

	return 0;
}
