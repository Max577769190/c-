#include<fstream>
#include<iostream>
#include<vector>
#include<string>

using std::ifstream;
using std::cout;
using std::endl;
using std::vector;
using std::string;

void getWordToVec(const string &filename, vector<string> &vec)
{
	ifstream isf(filename);
	if(isf)
	{
		string buf;
		while(isf >> buf)
			vec.push_back(buf);
	}
}
int main()
{
	vector<string> vec;
	getWordToVec("infile", vec);
	for(const auto i : vec)
		cout << i << endl;
	return 0;
}
