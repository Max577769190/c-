#include<vector>
#include<iostream>
#include<string>
#include<algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int main()
{
	vector<string> ls;
	string word;

	while(cin >> word)
		ls.push_back(word);

	auto i = count_if(ls.begin(), ls.end(), [] (const string &s) {return s.size() >= 6;});

	cout << "The word size bigger than six number of " << i << endl;

	return 0;
}
