#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std::placeholders;
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

bool compareSize(const string &s, string::size_type sz) {
	return s.size() >= sz;
}

void compareInt(vector<string> &ls, vector<string>::size_type sz) {
	elimDups(ls);
	sort(ls.begin(), ls.end(), [] (const string &s1, const string &s2) { return s1.size() < s2.size(); });
	auto wc = find_if(ls.begin(), ls.end(), bind(compareSize, _1, sz));
	for_each(wc, ls.end(), [] (const string &s) { cout << s << " "; });
}

int main()
{
	vector<string> ls;
	string word;

	while(cin >> word)
		ls.push_back(word);

	compareInt(ls, 5);
	cout << endl;

	return 0;
}
