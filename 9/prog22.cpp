#include<vector>
#include<iostream>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

void insert_int(vector<int> &ivec, int num) {
	/*auto ivec_begin1 = ivec.begin(), mid = ivec.begin() + ivec.size() / 2, ivec_begin2 = ivec.begin();
	while(ivec_begin1 != mid) {
		if(*ivec_begin1 == num) {
			ivec.insert(ivec_begin2, 2 * num);
		}
		++ivec_begin1;
	}*/
	auto ivec_begin = ivec.begin(), mid = ivec.begin() + ivec.size() / 2;
	while(ivec_begin != mid) {
		if(*ivec_begin == num)
			++(ivec.insert(ivec_begin, 2*num));
		++ivec_begin;
	}
}

int main()
{
	vector<int> ivec{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	int num = 4;

	insert_int(ivec, num);
	for(auto i : ivec)
		cout << i << " ";
	cout << endl;

	return 0;
}
