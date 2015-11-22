#include<iostream>
#include<initializer_list>
#include<string>
#include<vector>
using std::vector;
using std::initializer_list;
using std::string;
using std::cin;
using std::cout;
using std::endl;

//6.2
void error_msg(initializer_list<string> il);
//void error_msg(ErrCode e, initializer_list<string> il);

//6.3
void swap(int &v1, int &v2);
string make_plural(size_t ctr, const string &word, const string &ending);
const string &shorter_string(const string &s1, const string &s2);
char &get_val(string &str1, string::size_type ix);
vector<string> process();
int factorial(int val);
bool str_subrange(const string &str1, const string &str2);
//int (*func(int i))[10];
//auto func(int i) -> int(*)[10];
//decltype(odd) *arrptr(int i)
int main()
{
	cout << factorial(5) << endl;
	return 0;
}

void error_msg(initializer_list<string> il)
{
	for(auto beg = il.begin(); beg != il.end(); ++beg)
		cout << *beg << " ";
	cout << endl;
}

/*void error_msg(ErrCode e, initializer_list<string> il)
{
	cout << e.msg() << ": ";
	for(const auto &elem : il)
		cout << elem << " ";
	cout << endl;
}*/

void swap(int &v1, int &v2)
{
	int temp;
	if(v1 == v2)
		return;
	else
	{
		temp = v1;
		v1 = v2;
		v2 = temp;
	}
}

string make_plural(size_t ctr, const string &word, const string &ending)
{
	return (ctr > 1) ? word + ending : word;
}

const string &shorter_string(const string &s1, const string &s2)
{
	return s1.size() <= s2.size() ? s1 : s2;
}

char &get_val(string &str1, string::size_type ix)
{
	return str1[ix];
}

/*vector<string> process()
{
	...
	expect 和 actual 都是string对象
	if(expected.empty())
		return{};
	else if (expected == actual)
		return {"functionX", "Okay"};
	else
		return {"functionX", expected, actual};
}*/

int factorial(int val)
{
	if(val > 1)
		return factorial(val - 1) * val;
	return 1;
}

bool str_subrange(const string &str1, const string &str2)
{
	if (str1.size() == str2.size())
		return str1 == str2;
	auto size = (str1.size() < str2.size())
		? str1.size() : str2.size();
	for(decltype(size) i = 0; i != size; ++i)
	{
		if (str1[i] != str2[i])
			return;
	}
}
