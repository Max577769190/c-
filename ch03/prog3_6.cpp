#include<iostream>
#include<string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main()
{
	string a;
	cin >> a;
	for(char &x : a)
		x = 'x';
	cout << a << endl;
	return 0;
}
