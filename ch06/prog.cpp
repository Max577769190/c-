#include<iostream>
#include<vector>
using std::vector;
using std::cin;
using std::cout;
using std::endl;

int sum(const int, const int);
typedef decltype(sum) sumP;

int sumAdd(const int a, const int b) { return a+b; }
int sumSub(const int a, const int b) { return a-b; }
int sumMul(const int a, const int b) { return a*b; }
int sumDiv(const int a, const int b) { return a/b; }

int main()
{
	vector<sumP *> f { sumAdd, sumSub, sumMul, sumDiv };	
	for(auto it = f.cbegin(); it != f.cend(); ++it)
		cout << (*it)(2, 2) << endl;
	return 0;
}
