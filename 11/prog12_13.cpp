#include<utility>
#include<string>
#include<vector>
#include<iostream>

using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::string;
using std::vector;

int main()
{
	string word;
	int number;
	vector<pair<string, int>> word_number;
	
	while (cin >> word >> number) {
		word_number.push_back(make_pair(word, number));
		//word_number.push_back({word, number});
		//word_number.push_back(pair<string, int>(word, number));
	}

	for (const auto &i : word_number) {
		cout << i.first << " : " << i.second << endl;
	}
}
