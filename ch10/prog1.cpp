#include<vector>
#include<iostream>
#include<algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	vector<int> a = {1, 1, 2, 2, 2, 3, 3, 3, 3, 3, 4, 5, 5, 6, 7, 8, 8};
	int i;
	while(cin >> i) {
		if(find(a.cbegin(), a.cend(), i) != a.cend())
			cout << "The number " << i << " was present " << count(a.cbegin(), a.cend(), i) << " times." << endl;
		else
			cout << "The number " << i << " doesn't exists in vector a." << endl;
	}

	return 0;
}
