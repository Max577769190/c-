#include<iostream>
using std::cin;
using std::cout;
using std::endl;

typedef bool Func(const string &, const string &);
typedef decltype(lengthCompare) Func2;
typedef bool (*FuncP) (const string &, const string &);
typedef decltype(lengthCompare) *FuncP2;
using F = int(int *, int);
using PF = int(*)(int *, int);

bool lengthCompare(const string &, const string &);
string::size_type sumLength(const string &, const string &);
bool cstringCompare(const char *, const char *);
void ff(int *);
void ff(unsigned int);
void useBigger(const string &s1, const string &s2, bool pf(const string &, const string &));
void useBigger(const string &s1, const string &s2, bool (*pf)(const string &, const string &));
void useBigger(const string &, const string &, Func);
void useBigger(const string &, const string &, FuncP2);
int main()
{
	bool (*pf) (const string &, const string &);
	void (*pf1)(unsigned int ) = ff;
	pf = lengthCompare;
	pf = &lengthCompare;
	bool b1 = pf("Hello", "Goodbye");
	bool b2 = (*pf)("Hello", "Goodbye");
	bool b3 = lengthCompare("Hello", "Goodbye");
	pf = 0;
	pf = sumLength;
	pf = cstringCompare;
	pf = lengthCompare;
	useBigger(s1, s2, lengthCompare);
}
