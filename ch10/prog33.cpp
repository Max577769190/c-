#include<iostream>
#include<iterator>
#include<fstream>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::istream_iterator;
using std::ostream_iterator;

int main(int argc, char *argv[])
{
	ifstream fcin(argv[1]);
	ofstream fcout1(argv[2]), fcout2(argv[3]);

	istream_iterator<int> icin(fcin), eof;
	ostream_iterator<int> icout1(fcout1, " ");
	ostream_iterator<int> icout2(fcout2, " ");

	while(icin  != eof) {
		if(*icin % 2)
			icout1 = *icin;
		else
			icout2 = *icin;
		++icin;
	}
}
