#include<iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	int i = 5;
	auto f = [&i] ()->int { if(i > 0) return i--; else return false; };
}
