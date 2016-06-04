#include<iostream>
#include<string>
using std::cin;
using std::cout;
using std::endl;

std::istream &input(std::istream &);

int main()
{
	std::istream &is = input(cin);
	cout << is.rdstate() << endl;
	return 0;
}

std::istream &input(std::istream &is)
{
	std::string buf;
	while(is >> buf)
		cout << buf << endl;
	is.clear();
	return is;
}
