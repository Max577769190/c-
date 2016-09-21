#include<iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	int x[10];
	int *p = x;

	cout << sizeof(x)/sizeof(*x) << endl;
	//sizeof对数组执行返回数组所占空间的大小，sizeof对解引用指针得到所指对象的大小，cout << 10 << endl;
	cout << sizeof(p)/sizeof(*p) << endl;
	//sizeof对指针执行会得到指针本身所占空间大小，cout << 1 << endl;

	return 0;
}
