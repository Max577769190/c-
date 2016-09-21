#include<iostream>
#include<iterator>
using std::cin;
using std::cout;
using std::endl;
using std::end;
using std::begin;

int main()
{
	int ia[3][4] = 
	{
		{0, 1, 2, 3},
		{4, 5, 6, 7},
		{8, 9, 10, 11}
	};

	//版本1
	for(int (&row)[4] : ia)
		for(int col : row)
			cout << col << endl;
	//版本2
	for(int (*row)[4] = begin(ia); row != end(ia); ++row)
		for(int *col = begin(*row); col != end(*row); ++col)
			cout << *col << endl;

	//版本3
	for(int (*row)[4] = ia; row != ia + 3; ++row)
		for(int *col = *row; col != *row + 4; ++col)
			cout << *col << endl;

	return 0;
}
