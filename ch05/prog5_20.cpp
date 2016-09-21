#include<iostream>
#include<string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	string word1, word2;
	cin >> word1;
	while (cin >> word2)
	{
		cout << word1 << " and " << word2 << endl;
		if (word1 == word2)
		{
			break;
		}
		else
		{
			word1 = word2;
		}
	}
	if (!cin.eof())
		cout << "The repeat word is: " << word1 << endl;
	else
		cout << "No repeat word." << endl;
	return 0;
}
