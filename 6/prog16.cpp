#include<iostream>
#include<string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

bool is_empty0(const string &s);
int main()
{
	string s;
	cin >> s;
	cout << is_empty0("Hello World!") << endl;
	cout << is_empty0(s) << endl;
	return 0;
}

bool is_empty0(const string &s)
{
	cout << s << endl;
	return s.empty();
}
