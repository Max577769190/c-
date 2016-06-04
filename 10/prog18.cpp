#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include<typeinfo>

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

string weatherS(int i, string word, string ending) {
	return (i > 1) ? word + ending : word;
}

void binggers(vector<string> &ls, vector<string>::size_type sz) {
	elimDups(ls);
	auto wc = partition(ls.begin(), ls.end(), [sz] (string &s) { return s.size() >= sz; });
	auto num = ls.end() - wc;
	cout << typeid(wc).name() << endl;
	cout << num << " " << weatherS(num, "word", "s") << " of length " << sz << " or longer." << endl;
	for_each(ls.begin(), wc, [] (const string &s) { cout << s << " "; });
}

int main()
{
	vector<string> ls;
	string word;

	while(cin >> word)
		ls.push_back(word);

	binggers(ls, 3);
	cout << endl;

	return 0;
}
