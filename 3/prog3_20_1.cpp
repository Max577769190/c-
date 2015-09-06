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

	for(int i = 0; i < array.size(); i++)
		cout << array[i] + array[i+1] << endl;
	return 0;
}
