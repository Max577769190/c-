#include<iostream>
#include<string>
using std::string;
using std::cin;
using std::cout;
using std::endl;
int main()
{
	string word1, word2, word3;
	int n = 1, temp = 1;
	
	cin >> word1;
	while(cin >> word2)
	{
		if(word1 == word2)
			++n;
		else
		{
			n = 1;
			word1 = word2;
		}
		if(n > 2 && n >= temp)
		{
			cout << "n = " << n << endl;
			temp = n;
			word3 = word1;
		}
	}

	if(temp == 1)
		cout << "No repeated word" << endl;
	else
	{
		cout << "The max repeated word is " << word3 << endl;
		cout << "The repeated number is " << temp << endl;
	}

	return 0;
}
