/**
 * @file prog.cpp
 * @Synopsis  no proplems?
 * @author Max577769190
 * @version 1.0.0
 * @date 2015-10-29
 */
#include<iostream>
using std::endl;
using std::cout;
using std::cin;

void print(const int *);
int main()
{
	int ia[10] = {0};
	print(ia);
	return 0;
}

void print(const int *ia)
{
	for(size_t i = 0; i != 10; ++i)
		cout << ia[i] << endl;
}
