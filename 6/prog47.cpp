#include<iostream>
#include<vector>
#include<cassert>
//#define NDEBUG
using std::cin;
using std::cout;
using std::endl;
using std::vector;

void printVector(vector<int> &, vector<int>::iterator, vector<int>::iterator);
void printVector(vector<int>&);

int main()
{
	vector<int> array0 {1, 2, 3, 4, 5, 6, 7, 8, 9};
	printVector(array0, array0.begin(), array0.end());
	printVector(array0);
	return 0;
}

void printVector(vector<int>& array0)
{
#ifndef NDEBUG
	cout << "The vector size is " << array0.size() << endl;
#endif
	while(!array0.empty())
	{
		auto tmp = array0.back();
		array0.pop_back();
		printVector(array0);
		cout << tmp << endl;
	}
}
void printVector(vector<int>& array0, vector<int>::iterator beg0, vector<int>::iterator end)
{
#ifndef NDEBUG
	cout << "Vector size is " << array0.size() << endl;
#endif
	if(beg0 < end)
	{
		cout << *beg0 << endl;
		printVector(array0, ++beg0, end);
	}
}
