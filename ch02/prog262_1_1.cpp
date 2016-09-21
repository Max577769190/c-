/*
 * 可以把book3换成book2,代码量小一些
 */
#include<iostream>
#include<string>
#include"Book_data.h"
int main()
{
	Book book1, book2, book3;
	std::cin >> book1.book_isbn >> book1.book_number >> book1.book_price ;
	book1.book_revenue = book1.book_number * book1.book_price;
	
	std::cin >> book2.book_isbn >> book2.book_number >> book2.book_price ;
	book2.book_revenue = book2.book_number * book2.book_price;
	
	
	if(book1.book_isbn == book2.book_isbn)
		book3.book_isbn = book1.book_isbn;
	book3.book_number = book1.book_number + book2.book_number;
	book3.book_price = book1.book_price;
	book3.book_revenue = book1.book_revenue + book2.book_revenue;

	std::cout << book3.book_isbn << " " <<  book3.book_number << " " <<  book3.book_price << " " <<  book3.book_revenue << std::endl;

	return 0;
}
