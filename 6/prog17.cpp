/**
 * @file prog17.cpp
 * @Synopsis  
 * @author Max577769190
 * @version 
 * @date 2015-10-29
 */
#include<iostream>
#include<string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

bool if_upper(const string &s);
string to_lower(string &s);
int main()
{
	string s;
	cin >> s;
	cout << s << " if exists upper letter " << if_upper(s) << endl;
	cout << s << " to lower " << to_lower(s) << endl;
}

bool if_upper(const string &s)
{
	for(auto i : s)
	{
		if(isupper(i))
			return true;
	}
}

string to_lower(string &s)
{
	for(auto &i : s)
	{
		if(isupper(i))
		{
			i = tolower(i);
		}
		else
			continue;
	}
	return s;
}
