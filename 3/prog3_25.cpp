#include<iostream>
#include<string>
#include<vector>
using std::endl;
using std::cin;
using std::cout;
using std::string;
using std::vector;

int main()
{
	vector<int> array(11, 0);
	int grade;

	while(cin >> grade)
		if(grade > 100)
			cout << "Please enter the right grade!" << endl;
		else
			++(*(array.begin() + (grade / 10)));

	for(auto i : array)
		cout << i << endl;

	return 0;
}
