#ifndef PROG_41_H
#define PROG_41_H

#include<string>
#include<iostream>

class Sales_data {
	friend Sales_data add(const Sales_data&, const Sales_data&);
	friend std::istream &read(std::istream&, Sales_data&);
	friend std::ostream &print(std::ostream&, Sales_data&);
public:
	Sales_data(std::string s, unsigned cnt, double price): bookNo(s), units_sold(cnt), revenue(cnt * price) {  };
	Sales_data(): Sales_data("", 0, 0.0) { std::cout << "the constructor is Sales_data()" << std::endl; };
	Sales_data(std::string s): Sales_data(s, 0, 0.0) { std::cout << "The constructor is Sales_data(std::string s)" << std::endl; };
	Sales_data(std::istream &is): Sales_data() { read(is, *this); };

	std::string isbn() const { return bookNo; };
	Sales_data &combine(const Sales_data&);
	inline double avg_price() const { return units_sold ? revenue/units_sold : 0; };
private:
	std::string bookNo;
	unsigned units_sold;
	double revenue;
};
#endif

Sales_data &Sales_data::combine(const Sales_data &rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

std::istream &read(std::istream &is, Sales_data &item)
{
	double price;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = item.units_sold * price;
	return is;
}

std::ostream &print(std::ostream &os, Sales_data &item)
{
	os << item.bookNo << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
	return os;
}

Sales_data add(Sales_data &rhs, Sales_data &lhs)
{
	Sales_data sum = rhs;
	sum.combine(lhs);
	return sum;
}
