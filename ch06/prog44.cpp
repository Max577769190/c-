#include<iostream>
#include<string>
using std::string;
using std::cin;
using std::cout;
using std::endl;

inline const string& shorterString(const string&, const string &);

int main()
{
	string s1, s2;
	cin >> s1;
	cin >> s2;
	cout << shorterString(s1, s2) << endl;
	return 0;
}

const string& shorterString(const string &s1, const string &s2)
{
	return (s1.size() < s2.size()) ? s1 : s2;
}
