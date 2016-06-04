#include<list>
#include<string>
#include<iostream>
#include<algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::list;
using std::string;

int main()
{
	list<string> lst = {"Hello", "World", "Jealous", "One", "Two", "Three", "Four"};
	string word;
	while(cin >> word) {
		if(find(lst.cbegin(), lst.cend(), word) != lst.cend())
			cout << "The word " << word << " occurs " << count(lst.cbegin(), lst.cend(), word) << " times" << endl; 
		else
			cout << "The word " << word << " doesn't occurs." << endl;
	}
	return 0;
}
