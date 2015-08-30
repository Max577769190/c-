#include<iostream>
#include<string>
struct Book {
	std::string book_isbn;
	int book_number = 0;
	double book_price = 0;
	double book_revenue = 0;
};
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
