#include<iostream>
#include<vector>
#include<string>
using std::string;
using std::vector;
using std::cin;
using std::endl;
using std::cout;

int main()
{
	vector<string> array {"One", "two", "two", "Three", "khree", "Four"};
	auto first = array.begin();
	string temp = *first;
	first++;
	while(first != array.end())
	{
		if(*first == temp)
		{
			if(isupper((*first)[0]) && isupper(temp[0]))
				break;
			else
			{
				temp = *first;
				first++;
				continue;
			}
		}
		else
		{
			temp = *first;
			first++;
		}
	}
	if(first == array.end())
		cout << "No two same words" << endl;
	else
		cout << temp << " and " << *first << " are two same words" << endl;

	return 0;
}
