#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

string weatherS(int a, string word, string ending) {
	return (a > 1) ? word+ending : word;
}

void elimDups(vector<string> &word) {
	sort(word.begin(), word.end());
	auto unique_end = unique(word.begin(), word.end());
	word.erase(unique_end, word.end());
}

void biggers(vector<string> &ls, vector<string>::size_type sz) {
	elimDups(ls);
	sort(ls.begin(), ls.end(), [](const string &s1, const string &s2) { return s1.size() < s2.size(); });
	auto wc = find_if(ls.begin(), ls.end(), [sz] (const string &s) { return s.size() >= sz; });
	auto count = ls.end() - wc;
	cout << count << " " << weatherS(count, "word", "s") << " of length " << sz << " or longer." << endl;
	for_each(wc, ls.end(), [] (const string &s) { cout << s << " "; });
}

int main()
{
	vector<string> ls;
	string word;

	while(cin >> word)
		ls.push_back(word);

	biggers(ls, 3);

	return 0;
}
