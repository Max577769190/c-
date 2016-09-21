#include<iostream>
#include<iterator>
#include<string>
#include<vector>
using std::vector;
using std::end;
using std::begin;
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	int array[10] = {0};
	int array1[8] = {0};

	auto n = end(array) - begin(array);
	auto n1 = end(array1) - begin(array1);
	if( n == n1 )
		cout << "The two array is equal" << endl;
	else
		cout << "The two array isn't equal" << endl;

	cout << "------------------------------------" << endl;
	vector<int> array2{1, 2, 3, 4, 5};
	vector<int> array3{1, 2, 3, 3};

	auto n2 = array2.begin() - array2.end();
	auto n3 = array3.begin() - array3.end();


	if( n2 == n3 )
		cout << "The two array is equal" << endl;
	else
		cout << "The two array isn't equal" << endl;
	
	return 0;
}
