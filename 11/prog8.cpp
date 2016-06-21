#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int main()
{
	vector<string> number;
	string i;

	while(cin >> i) {
		auto result = find(number.cbegin(), number.cend(), i);
		if(result == number.cend())
			number.push_back(i);
	}
	for(auto &i : number)
		cout << i << " ";
	cout << endl;
}
