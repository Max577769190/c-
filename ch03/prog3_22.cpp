#include<iostream>
#include<string>
#include<vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
	string line;
	vector<string> setence;

	while(getline(cin, line))
		setence.push_back(line);

	for(auto i = setence.begin(); i != setence.end(); ++i)
		for(auto n = i->begin(); n != i->end(); ++n)
			*n = toupper(*n);

	for(auto i = setence.begin(); i != setence.end(); ++i)
		cout << *i << endl;

	return 0;
}
