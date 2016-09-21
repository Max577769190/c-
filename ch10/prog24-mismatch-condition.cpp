#include<vector>
#include<string>
#include<iostream>
#include<functional>
#include<algorithm>

using namespace std::placeholders;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

bool check_size(const string &s, string::size_type sz) {
	return s.size() <= sz;
}

vector<int>::const_iterator compareSize(vector<int> &v, const string &s) {
	auto one = [&] (int i) { return check_size(s, i); };
	return find_if(v.begin(), v.end(), one);
}

int main()
{
	vector<int> vi = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	cout << *(compareSize(vi, "Hello"));
	return 0;
}
