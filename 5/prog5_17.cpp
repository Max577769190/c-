#include<iostream>
#include<vector>
using std::cin;
using std::endl;
using std::cout;
using std::vector;

int main()
{
	vector<int> a{1, 2, 3, 4}, b{1, 2 ,5, 4, 5};

	for(auto a_beg = a.begin(), b_beg = b.begin(); a_beg != a.end(), b_beg != b.end(); ++a_beg, ++b_beg)
	{
		if(*a_beg == *b_beg)
		{
			if(a_beg == (a.end() - 1) || b_beg == (b.end() - 1))
			{
				cout << "True!" << endl;
				break;
			}
		}
		else
		{
			cout << "False!" << endl;
			break;
		}
	}

	return 0;
}
