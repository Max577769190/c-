#include<iostream>
#include<string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	string line;
	cin >> line;
	string::size_type n = 0;
	/*while 循环*/
	while(n < line.size())
		line[n++] = 'x';
	cout << line << endl;

	/*for 循环*/
	for(n = 0; n < line.size(); n++)
		line[n] = 'D';
	cout << line << endl;

	return 0;
}
