#include<iostream>
#include<cstring>
using std::cout;
using std::cin;
using std::endl;

int main()
{
	char word1[] = {'w', 'e', 'l', '\0'};
	char word2[] = {'c', 'o', 'm', 'e', '\0'};
	char word3[10] = {'a'};

	strcpy(word3, word1);
	strcat(word3, word2);

	for(int i = 0; i < 10; ++i)
		cout << word3[i] << endl;
	return 0;
}
