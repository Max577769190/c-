#include"Debug.h"
#include<iostream>
using std::cerr;
using std::endl;

int main()
{
	constexpr Debug io_sub(false, true, false);
	if(io_sub.any())
		cerr << "Print appropriate error message" << endl;
	constexpr Debug prod(false);
	if(prod.any())
		cerr << "Print an error message" << endl;
	return 0;
}
