#include<iostream>
#include<initializer_list>
using std::initializer_list;
using std::cin;
using std::cout;
using std::endl;

int number_sum(initializer_list<int> a);
int main()
{
	int sum;
	sum = number_sum({1, 2, 3, 4, 5, 6});
	cout << sum << endl;
	return 0;
}

int number_sum(initializer_list<int> a)
{
	int sum = 0;
	for(const auto i : a)
		sum += i;
	return sum;
}
