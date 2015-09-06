#include<iostream>
#include<string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main()
{
	string word1, word2;
	while(cin >> word1 )
	{
		if(word1 != "quit")
		{
			word2 = word2 + word1 + " ";
		}
		else
			break;
	}
	cout << word2 << endl;
	return 0;
}
