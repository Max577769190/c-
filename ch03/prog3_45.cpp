#include<iostream>
#include<iterator>
using std::endl;
using std::cout;
using std::cin;
using std::begin;
using std::end;

int main()
{
	int ia[3][4] = 
	{
		{0, 1, 2, 3},
		{4, 5, 6, 7},
		{8, 9, 10, 11}
	};

	//release 1
	for(auto &row : ia)
		for(auto col : row)
			cout << col << endl;

	//release 2
	for(auto row = begin(ia); row != end(ia); ++row)
		for(auto col = begin(*row); col != end(*row); ++col)
			cout << *col << endl;
	
	//release 3
	for(auto row = ia; row != ia + 3; ++row)
		for(auto col = *row; col != *row + 4; ++col)
			cout << *col << endl;
	
	return 0;
}
