#include<iostream>
#include<string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	/*编译器没有报错
	 * 书上说：默认初始化，string对象中没有任何字符
	 * */
	string s;
	cout << s[0] << endl;
	return 0;
}
