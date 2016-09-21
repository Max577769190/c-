#include<iostream>
#include<string>
#include<vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
	vector<int> v1(10, 42);
	vector<int> v2{42, 42, 42, 42, 42, 42, 42, 42, 42, 42};
	//若42是字符
	vector<string> v3{10,"42"};

	for(auto i : v3)
	{
		cout << i << " ";
	}
	return 0;
}
