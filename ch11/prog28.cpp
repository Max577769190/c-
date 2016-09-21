#include<map>
#include<string>
#include<vector>
#include<iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::map;

int main()
{
	map<string, vector<int>> unknow;
	vector<int> ivec = {1};
	unknow.insert(make_pair("string", ivec));
	unknow["first"].push_back(2);

	map<string, vector<int>>::iterator one;
	one = unknow.find("string");
	cout << one->first << endl;
}
