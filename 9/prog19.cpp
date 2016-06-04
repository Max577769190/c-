#include<iostream>
#include<string>
#include<deque> //==> #include<list>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::deque; //==> using std::list;

int main()
{
	deque<string> sdeque; // ==> list<string> slist;
	string word;

	while(cin >> word)
		sdeque.push_back(word); // ==> slist.push_back(word);

	for(auto sdequeBegin = sdeque.begin(); sdequeBegin != sdeque.end(); ++sdequeBegin)
		//for(auto slistBegin = slist.begin(); slistBegin != slist.end(); ++slistBegin)
		cout << *sdequeBegin << endl;

	return 0;
}
