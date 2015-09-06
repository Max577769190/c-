#include<iostream>
#include<string>
#include<vector>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int main()
{
	string word;
	vector<string> setence;
	while(cin >> word)
		setence.push_back(word);
	for(auto &i : setence)
		for(auto &n : i)
			n = toupper(n);
	for(auto i : setence)
		cout << i << endl;
	return 0;
}
