/*
 * decltype () 只有一个()返回的是()里面的类型，如果里面是一个a=b时返回的是int& 
 * */
#include<iostream>
int main()
{
	int a = 3, b = 4, f = 5;
	decltype(a) c = b;
	decltype(a) e = f;
	decltype(a = b) d = a;

	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;
	std::cout << "e = " << e << std::endl;
	std::cout << "----------------------------------" << std::endl;

	c = 11;
	d = 14;
	e = 10;

	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "e = " << e << std::endl;
	std::cout << "f = " << f << std::endl;

	return 0;
}
