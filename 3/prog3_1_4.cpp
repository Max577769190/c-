#include<iostream>
#include<string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

struct Book {
	string isbn;
	int number;
	double price;
	double revenue;
};

int main()
{
	Book book1, book2;
	if(cin >> book1.isbn >> book1.number >> book1.price)
	{
		book1.revenue = book1.number * book1.price;
		while(cin >> book2.isbn >> book2.number >> book2.price)
		{
			book2.revenue = book2.number * book2.price;
			if(book1.isbn == book2.isbn)
			{
				book1.number += book2.number;
				book1.revenue += book2.revenue;
			}
			else
			{
				cout << book1.isbn << " " << book1.number << " " << book1.price << " " << book1.revenue << endl;
				book1.isbn = book2.isbn;
				book1.number = book2.number;
				book1.price = book2.price;
				book1.revenue = book2.revenue;
			}
		}
		cout << book1.isbn << " " << book1.number << " " << book1.price << " " << book1.revenue << endl;
	}
	return 0;
}
