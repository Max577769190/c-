#include<iostream>
#include<string>
using std::string;
using std::cin;
using std::cout;
using std::endl;

string make_plural(size_t ctr, const string &word, const string& ending = "s");

int main()
{
	cout << make_plural(1, "success") << endl;
	cout << make_plural(2, "success", "es") << endl;
	cout << make_plural(1, "failure") << endl;
	cout << make_plural(2, "failure") << endl;
	return 0;
}

string make_plural(size_t ctr, const string &word, const string& ending)
{
	return (ctr > 1) ? word + ending : word;
}
