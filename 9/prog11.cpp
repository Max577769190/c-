#include<vector>

using std::vector;

int main()
{
	vector<int> a1;
	vector<int> a3 = {1, 2, 3, 4, 5};
	vector<int> a4(a3);
	vector<int> a5 = a4;
	vector<int> a6(5);
	vector<int> a2(10, 1);

	return 0;
}
