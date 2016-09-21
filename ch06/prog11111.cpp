#include<string>
#include<iostream>
#include<vector>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	string line, line_1;
	vector<string> string_8;
	cin >> line;
	auto line_beg = line.begin();
	auto line_end = line.end();
	while(line_beg != line_end)
	{
		string line_8;
		line_8 += *line_beg;
		++line_beg;
		line_8 += *line_beg;
		++line_beg;
		line_8 += *line_beg;
		++line_beg;
		if(line_8 == "000")
			line_1 += "0";
		line_8 = {'\0'};
	}
	cout << line_1 << endl;
	return 0;
}
