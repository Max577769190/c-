#include<iostream>
#include<string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	string line;
	getline(cin, line);
	for(auto i : line)
	{
		if(!ispunct(i) && !isspace(i))
			cout << i;
	}
	cout << endl;
	for(auto &i : line)
	{
		if(ispunct(i))
			i = ' ';
	}
	cout << line << endl;
	return 0;
}
