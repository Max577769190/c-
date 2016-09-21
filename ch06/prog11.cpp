#include<iostream>
#include<string>
using std::string;
using std::cin;
using std::cout;
using std::endl;

void reset(int &);
bool isShorter(const string &, const string &);
string::size_type find_char(const string &s, char c, string::size_type &occurs);
int main()
{
	string s;
	string::size_type ret_number, occurs_number;
	char c;
	cout << "Please enter a string: ";
	cin >> s;
	cout << "Please enter a char that you want to find: ";
	cin >> c;
	ret_number = find_char(s, c, occurs_number);
	cout << "The char happen in the first time is " << ret_number << " the time is " << occurs_number << endl;
}

void reset(int &i)
{
	i = 0;
}

bool isShorter(const string &a, const string &b)
{
	return a.size() < b.size();
}

string::size_type find_char(const string &s, char c, string::size_type &occurs)
{
	auto ret = s.size();
	cout << "ret = " << ret << endl;
	occurs = 0;
	for(decltype(ret) i = 0; i != s.size(); ++i)
	{
		if(s[i] == c)
		{
			if(ret == s.size())
				ret = i;
			++occurs;
		}
	}
	return ret;
}
