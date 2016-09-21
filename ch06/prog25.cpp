/**
 * @file prog25.cpp
 * @Synopsis  接收传递给main的两个参数，变成string输出
 * 			  要点：c风格的字符串与c++风格的字符串
 * @author Max577769190
 * @version 
 * @date 2015-10-29
 */
#include<iostream>
#include<string>
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
	string s1, s2;
	s1 = argv[1];
	s2 = argv[2];
	cout << s1 + s2 << endl;
	return 0;
}
