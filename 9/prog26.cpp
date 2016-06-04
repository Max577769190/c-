#include<iostream>
#include<vector>
#include<list>

using std::cin;
using std::cout;
using std::endl;
using std::list;
using std::vector;

int main()
{
	int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
	vector<int> vecia;
	list<int> listia;

	//vector<int> vecia(ia, end(ia));
	//list<int> listia(vecia.begin(), vecia.end());

	for(int i = 0; i < (int)(sizeof(ia) / sizeof(int)); ++i) {
		vecia.push_back(ia[i]);
		listia.push_back(ia[i]);
	}

	for(auto iter = vecia.begin(); iter != vecia.end();)
		if(!(*iter % 2))
			iter = vecia.erase(iter);
		else
			++iter;

	for(auto listiter = listia.begin(); listiter != listia.end();)
		if(*listiter % 2)
			listiter = listia.erase(listiter);
		else
			++listiter;

	cout << "Vector: ";
	for(auto i : vecia)
		cout << i << " ";
	cout << endl;
	cout << "List: ";
	for(auto i : listia)
		cout << i << " ";
	cout << endl;

	return 0;
}
