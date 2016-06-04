#include<vector>
#include<string>
#include<iostream>
#include<algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

void deleteRepeatWords(vector<string> &word) {
	sort(word.begin(), word.end());
	auto unique_end = unique(word.begin(), word.end());
	word.erase(unique_end, word.end());
}

int main()
{
	vector<string> ls;
	string word;

	while(cin >> word)
		ls.push_back(word);
	
	deleteRepeatWords(ls);

	for(auto i : ls)
		cout << i << " ";
	cout << endl;
}
