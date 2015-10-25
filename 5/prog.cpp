#include"Sales_item.h"
#include<iostream>
#include<stdexcept>
using std::cin;
using std::cout;
using std::endl;
using std::runtime_error;

int main()
{
	while (cin >> item1 >> item2)
		try{
			//
			//
		} catch {
			cout << err.what()
				 << "\nTry Again? Enter y or n" << endl;
			char c;
			cin >> c;
			if(!cin || c == 'n')
				break;
		}
}
