#include"Sales_data.h"
#include<iostream>
#include<vector>
#include<algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

bool compareIsbn(Sales_data &s1, Sales_data &s2) {
	return s1.isbn() < s2.isbn();
}

void sortSales_data(vector<Sales_data> &data) {
	sort(data.begin(), data.end(), compareIsbn);
}

int main()
{
	vector<Sales_data> data;
	Sales_data temp;

	while(read(cin, temp))
		data.push_back(temp);

	sortSales_data(data);

	for(auto i : data)
		print(cout, i) << endl;
	cout << endl;

	return 0;
}
