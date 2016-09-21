#include"Sales_item.h"
#include<vector>
#include<iostream>
#include<algorithm>
#include<iterator>

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::istream_iterator;
using std::ostream_iterator;

int main()
{
	istream_iterator<Sales_item> SCin(cin), eof;
	vector<Sales_item> Svec;
	Sales_item total;
	total = *SCin++;
	while(SCin != eof) {
		Sales_item temp = *SCin++;
		if(total.isbn() == temp.isbn()) 
			total += temp;
		else {
			Svec.push_back(total);
			total = temp;
		}
	}
	Svec.push_back(total);

	sort(Svec.begin(), Svec.end(), [] (const Sales_item &s1, const Sales_item &s2) { return s1.isbn() < s2.isbn(); });

	for(auto i : Svec)
		cout << i << endl;
	cout << endl;
}
