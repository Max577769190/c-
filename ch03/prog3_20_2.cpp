#include<iostream>
#include<vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main()
{
	int n;
	vector<int> array;

	while(cin >> n)
		array.push_back(n);

	for(int i = 0; i < (array.size() / 2); i++)
	{
		int temp;
		temp = (array[i] + array[array.size() - i - 1]) / 2;
		cout << temp << endl;
	}
	return 0;
	}
