#include<iostream>
#include<string>
#include<vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
	int array[10], array1[10];

	for(int i = 0; i < 10; ++i)
		array[i] = i;

	for(int i = 0; i < 10; ++i)
		array1[i] = array[i];
	
	return 0;
}
