/**
 * @file prog33.cpp
 * @Synopsis  只需要传递给递归函数容器的起始与结束就好
 * 	但不明白我的为什么错了
 * @author Max577769190
 * @version 
 * @date 2015-10-30
 */
#include<iostream>
#include<vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

//void print(vector<int> , vector<int>::iterator );
void print(vector<int>::iterator, vector<int>::iterator);
int main()
{
	vector<int> arry{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	auto acc = arry.begin(), add = arry.end();
	print(acc, add);	
	return 0;
}

/*void print(vector<int> arry, vector<int>::iterator acc)
{
	if(acc < arry.end())
	{
		print(arry, ++acc);
	}
}*/
void print(vector<int>::iterator begin, vector<int>::iterator end)
{
	if(begin != end)
	{
		cout << *begin << endl;
		print(++begin, end);
	}
}
