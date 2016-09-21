#include<iostream>
#include<string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main()
{
	string word;
	while(cin >> word)
		cout << word << endl;
	return 0;
}

/* 读取一行
 * 	while(getline(cin, line))
 * 		cout << line << endl;
 * */
