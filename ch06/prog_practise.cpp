#include<iostream>
#include<string>
#include<vector>
using std::string;
using std::vector;
using std::endl;
using std::cin;
using std::cout;

vector<string> switch_2(string );
string switch_8(string );
int main()
{
	string line;
	while(cin >> line)
	{
		vector<string> line_2;
		string line_8;
		line_2 = switch_2(line);
		line = {'\0'};
		for(auto i : line_2)
			line += i;
		cout << line << endl;
		line_8 = switch_8(line);
		cout << line_8 << endl;
	}
	return 0;
}

string switch_8(string line)
{
	string line_3, line_8;
	auto line_beg = line.begin();
	auto line_end = line.end();
	while(line_beg <= line_end)
	{
		++line_beg;
		line_3 += *line_beg;
		++line_beg;
		line_3 += *line_beg;
		++line_beg;
		line_3 += *line_beg;
		cout << line_3 << endl;
		if(line_3 == "000")
			line_8 += "0";
		else if (line_3 == "001")
			line_8 += "1";
		else if (line_3 == "010")
			line_8 += "2";
		else if (line_3 == "011")
			line_8 += "3";
		else if (line_3 == "100")
			line_8 += "4";
		else if (line_3 == "101")
			line_8 += "5";
		else if (line_3 == "110")
			line_8 += "6";
		else if (line_3 == "111")
			line_8 += "7";
		cout << line_8 << endl;
		++line_beg;
		line_3 = {'\0'};
	}
	/*for(auto line_beg = line_8.begin(); line_beg != line.end(); ++line_beg)
	{
		switch(*line_beg){
			case "000":
				line_3 += '0';
				break;
			case "001":
				line_3 += '1';
				break;
			case "010":
				line_3 += '2';
				break;
			case "011":
				line_3 += '3';
				break;
			case "100":
				line_3 += '4';
				break;
			case "101":
				line_3 += '5';
				break;
			case "110":
				line_3 += '6';
				break;
			case "111":
				line_3 += '7';
				break;
		}
	}*/
	/*for (auto i : line_8)
	{
		if(i == "000")
			line_3 += '0';
		else if (i == "001")
			line_3 += '1';
		else if (i == "010")
			line_3 += '2';
		else if (i == "011")
			line_3 += '3';
		else if (i == "100")
			line_3 += '4';
		else if (i == "101")
			line_3 += '5';
		else if (i == "110")
			line_3 += '6';
		else if (i == "111")
			line_3 += '7';
		cout << line_3 << endl;
	}*/
	return line_8;
}
vector<string> switch_2(string line)
{
	vector<string> string_2;
	for(auto i : line)
	{
		switch(i) {
			case '0':
				string_2.push_back("0000");
				break;
			case '1':
				string_2.push_back("0001");
				break;
			case '2':
				string_2.push_back("0010");
				break;
			case '3':
				string_2.push_back("0011");
				break;
			case '4':
				string_2.push_back("0100");
				break;
			case '5':
				string_2.push_back("0101");
				break;
			case '6':
				string_2.push_back("0110");
				break;
			case '7':
				string_2.push_back("0111");
				break;
			case '8':
				string_2.push_back("1000");
				break;
			case '9':
				string_2.push_back("1001");
				break;
			case 'a':
			case 'A':
				string_2.push_back("1010");
				break;
			case 'b':
			case 'B':
				string_2.push_back("1011");
				break;
			case 'c':
			case 'C':
				string_2.push_back("1100");
				break;
			case 'd':
			case 'D':
				string_2.push_back("1101");
				break;
			case 'e':
			case 'E':
				string_2.push_back("1110");
				break;
			case 'f':
			case 'F':
				string_2.push_back("1111");
				break;
		}
	}
	return string_2;
}
