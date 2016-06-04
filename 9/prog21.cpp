#include<vector>
#include<iostream>
#include<string>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	vector<string> a;
	auto iter = a.begin();
	string word;

	while(cin >> word)
		iter = a.insert(iter, word);

	for(auto i : a)
		cout << i << " ";
	cout << endl;

	return 0;
}
