#include<vector>
#include<string>
#include<iostream>
#include<algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

void elimDups(vector<string> &ls) {
	sort(ls.begin(), ls.end());
	auto unique_end = unique(ls.begin(), ls.end());
	ls.erase(unique_end, ls.end());
}

void biggers(vector<string> &ls, vector<string>::size_type sz) {
	elimDups(ls);
	auto ls_end = stable_partition(ls.begin(), ls.end(), [sz] (const string &s) { return s.size() >= sz; });
	for_each(ls.begin(), ls_end, [] (const string &s) { cout << s << " "; });
}

int main()
{
	vector<string> ls;
	string word;

	while(cin >> word)
		ls.push_back(word);

	biggers(ls, 3);
	cout << endl;

	return 0;
}
