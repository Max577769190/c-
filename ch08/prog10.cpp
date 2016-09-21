#include<iostream>
#include<sstream>
#include<vector>
#include<string>
#include<fstream>

using std::ifstream;
using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::istringstream;

int main()
{
	ifstream isf("infile");
	string setence;
	vector<string> src;
	istringstream is;
	
	while(getline(isf, setence))
		src.push_back(setence);

	for(auto i : src) {
		string wd;
		is.str(i);
		while(is >> wd)
			cout << wd << endl;
		is.clear();
	}

	return 0;
}
