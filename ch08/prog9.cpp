#include<iostream>
#include<string>
#include<sstream>

using std::istringstream;
using std::cin;
using std::cout;
using std::endl;
using std::string;

std::istringstream &input(istringstream &);

int main()
{
	istringstream is;
	string as;
	getline(cin, as);
	is.str(as);
	input(is);	
	cout << is.rdstate() << endl;
	return 0;
}

istringstream &input(istringstream &is)
{
	std::string buf;
	while(is >> buf)
		cout << buf << endl;
	is.clear();
	return is;
}
