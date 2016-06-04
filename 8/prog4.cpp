#include<iostream>
#include<fstream>
#include<vector>
#include<string>

using std::ifstream;
using std::vector;
using std::string;
using std::endl;
using std::cin;
using std::cout;

void readLineToVec(const string &fileName, vector<string> &vec)
{
	ifstream ifs(fileName);
	string buf;
	if(ifs)
	{
		while(std::getline(ifs, buf))
			vec.push_back(buf);
	}
}

int main()
{
	vector<string> vec;
	readLineToVec("infile", vec);
	for(auto i : vec)
		cout << i << endl;
	return 0;
}
