#include<iostream>
#include<string>
#include<vector>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int main()
{
	int n;
	vector<int> array;
	while(cin >> n)
	{
		array.push_back(n);
	}
	for (auto i : array)
		cout << i << " " ;
	cout << endl;
	//使用for循环输出
	auto i = array[1];
	for (i = 0; i != array.size(); i++)
		cout << array[i] << " ";
	cout << endl;
	return 0;
}
