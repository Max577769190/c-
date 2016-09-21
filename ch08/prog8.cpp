#include"Sales_data.h"
#include<fstream>
#include<iostream>

using std::ifstream;
using std::ofstream;
using std::endl;

int main(int argc, char *argv[])
{
	Sales_data total;
	ifstream input(argv[1]);
	ofstream output(argv[2], ofstream::app);

	if(read(input, total)) {
		Sales_data trans;
		while(read(input, trans)) {
			if(total.isbn() == trans.isbn())
				total.combine(trans);
			else {
				print(output, total) << endl;
				total = trans;
			}
		}
		print(output, total) << endl;
	}
	else
		std::cerr<< "No data?" << endl;
}
