#include<iostream>
#include<string>
#include<map>
#include<set>

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::set;
using std::string;

int main()
{
	map<string, size_t> word_count;
	set<string> exclude = {"The", "But", "And", "Or", "An", "A",
							"the", "but", "and", "or", "an", "a", ",", "."};
	string word;

	while(cin >> word)
		if(exclude.find(word) == exclude.end())
			++word_count[word];

	for(const auto &a : word_count)
		cout << a.first << " occurs " << a.second << ((a.second > 1) ? " times." : " time.") << endl;
}
