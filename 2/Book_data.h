#ifndef BOOK_DATA_H
#define BOOK_DATA_H
#include<string>
struct Book {
	std::string book_isbn;
	int book_number = 0;
	double book_price = 0;
	double book_revenue = 0;
};
#endif
