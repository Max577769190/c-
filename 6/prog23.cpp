#include<iostream>
#include<iterator>
using std::cin;
using std::cout;
using std::endl;
using std::begin;
using std::end;

void print(const int*);
void print(const int *begn, const int *end);
void print(const int *, size_t );
int main()
{
	int j[2] = {1, 2};
	print(begin(j), end(j));
	print(j, end(j) - begin(j));
}

void print(const int *cp)
{
	if(cp)
		while(*cp)
			cout << *cp++;
}

void print(const int *begn, const int *end)
{
	while(begn != end)
		cout << *begn++ << endl;
}

void print(const int *ia, size_t size)
{
	for(size_t i = 0; i != size; ++i)
		cout << ia[i] << endl;
}
