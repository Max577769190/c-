#include"Sales_data.h"
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int main()
{
	vector<Sales_data> data;
	Sales_data temp;

	while(read(cin, temp))
		data.push_back(temp);

	sort(data.begin(), data.end(), 
			[] (const Sales_data &s1, const Sales_data &s2) { return s1.isbn().size() < s2.isbn().size(); });

	for(auto i : data)
		print(cout, i) << endl;
	cout << endl;

	return 0;
}
