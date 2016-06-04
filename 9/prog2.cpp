#include<list>
#include<deque>
#include<iostream>

int main()
{
	std::list<std::deque<int>> a;
	std::cout << a.max_size() << std::endl;
	return 0;
}
