#ifndef PROG_H
#define PROG_H

#include<iostream>
#include<string>
#include<vector>

class NoDefault {
public:
	NoDefault (int i) {  };
};

class C {
public:
	C (): a(0) {  };
	NoDefault sb() { return a; };

private:
	NoDefault a;
};
#endif

int main()
{
	C c;
	NoDefault a = c.sb();
	int i = 23;
	std::cout << i << std::endl;
	return 0;
}
