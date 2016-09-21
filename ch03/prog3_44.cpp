#include<iostream>
#include<iterator>
using std::endl;
using std::cin;
using std::cout;
using std::end;
using std::begin;
using int_array = int[4];

int main()
{
	int ia[3][4] = {
		{0, 1, 2, 3},
		{4, 5, 6, 7},
		{8, 9, 10, 11}
	};
	//release 1
	for(int_array &row : ia)
		for(int col : row)
			cout << col << endl;
	//release 2
	for(int_array *row = begin(ia); row != end(ia); ++row)
		for(int *col = begin(*row); col != end(*row); ++col)
			cout << *col << endl;
	//release 3
	for(int_array *row = ia; row != ia + 3; ++row)
		for(int *col = *row; col != *row + 4; ++col)
			cout << *col << endl;

	return 0;
}
