#include<vector>
#include<iostream>

int main()
{
	std::vector<int> vec = {1, 2, 3, 4};

	for(auto i = vec.cend() - 1; i >= vec.cbegin(); --i)
		std::cout << *i << " ";
	std::cout << std::endl;
}
