#include<iostream>
#include<string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using stringT = string[10];

string (*func(void))[10];
int main()
{
	//string array_number [10] = {"A", "B", "C", "D", "E", "F", "G", "H", "H"};
	string (* array_string) [10]; 
	array_string = func();
	return 0;
}

/*string (*func(void))[10]
{
	static string array_number [10] = {"A", "B", "C", "D", "E", "F", "G", "H", "H"};
	return &array_number;
}*/

/*auto func(void) -> string(*)[10]
{
	static string array_number [10] = {"A", "B", "C", "D", "E", "F", "G", "H", "H"};
	return &array_number;
}*/

/*stringT* func(void)
{
	static string array_number [10] = {"A", "B", "C", "D", "E", "F", "G", "H", "H"};
	return &array_number;
}*/
