#include<iostream>
#include<string>
#include<cstring>
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	string sentence1 = "WELCOME TO CHINA";
	string sentence2 = "WELCOME TO AMERICA";
	
	if(sentence1 < sentence2)
		cout << "sentence 1 less than sentence 2" << endl;
	else
		cout << "sentence 1 more than sentence 2" << endl;

	char word1[] = {'w', 'o', 'r', 'd', '1', '\0'};
	char word2[] = {'w', 'o', 'r', 'd', '2', '\0'};
	int n = strcmp(word1, word2);

	if(n == 0)
		cout << "word 1 and word 2 are equal" << endl;
	else
		cout << "word 1 and word 2 aren't equal" << endl;

	return 0;
}
