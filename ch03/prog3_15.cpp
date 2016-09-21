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
	string word;
	vector<string> setence;
	while(cin >> word)
		setence.push_back(word);
	for(auto i : setence)
		cout << i << " " ;
	cout << endl;
	return 0;
}
