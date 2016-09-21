#ifndef PROG_H
#define PROG_H

#include<iostream>
#include<string>
#include<vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

class NoDefault {
public:
	NoDefault (int i) {  };
};

class C {
public:
	C (): a(0) {  };

private:
	NoDefault a;
};
#endif

int main()
{
	C c;
	vector<NoDefault> vec(10);
	return 0;
}
