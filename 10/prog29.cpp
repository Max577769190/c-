#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<fstream>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::ifstream;
using std::istream_iterator;

int main()
{
	ifstream in("infile");
	istream_iterator<string> ins(in), eof;
	vector<string> vs;

	while(ins != eof)
		vs.push_back(*ins++);

	for(auto i : vs)
		cout << i << " ";
	cout << endl;
}
