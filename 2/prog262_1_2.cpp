#include<iostream>
#include<string>
#include"Book_data.h"
int main()
{
	Book book1, temp, book2;
	if(std::cin >> book1.book_isbn >> book1.book_number >> book1.book_price)
	{
		book1.book_revenue = book1.book_number * book1.book_price;
		while(std::cin >> book2.book_isbn >> book2.book_number >> book2.book_price)
		{
			book2.book_revenue = book2.book_number * book2.book_price;
			if(book1.book_isbn == book2.book_isbn)
			{
				book1.book_number += book2.book_number;
				book1.book_revenue += book2.book_revenue;
			}
			else
			{
				std::cout << book1.book_isbn << " " << book1.book_number << " " << book1.book_price << " " << book1.book_revenue << std::endl;
				book1.book_number = 0;
				book1.book_revenue = 0;
				book1.book_isbn = book2.book_isbn;
				book1.book_number += book2.book_number;
				book1.book_revenue += book2.book_revenue;
			}
		}
		std::cout << book1.book_isbn << " " << book1.book_number << " " << book1.book_price << " " << book1.book_revenue  << std::endl;
	}
	return 0;
}
