#ifndef SALES_DATA_H
#define SALES_DATA_H

#include<iostream>
#include<string>

class Sales_data 
{
	friend Sales_data add(const Sales_data&, const Sales_data&);
	friend std::istream &read(std::istream&, Sales_data&);
	friend std::ostream &print(std::ostream&, Sales_data&);
public:
	//构造函数
	Sales_data () = default;
	Sales_data (const std::string &s): bookNo(s) {  };
	Sales_data (std::string s = ""): bookNo(s) {  };
	Sales_data (const std::string &s, unsigned n, double p): bookNo(s), units_sold(n), revenue(p * n) {  };
	Sales_data (std::istream &);
	//成员函数
	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);
	inline double avg_price() const { return units_sold ? revenue/units_sold : 0; };
private:
	//double avg_price() const { return units_sold ? revenue/units_sold : 0; };
	//类成员
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);
#endif

Sales_data& Sales_data::combine(const Sales_data &rhs)
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
	os << item.isbn() << " " << item.units_sold << " "
		<< item.revenue << " " << item.avg_price();
	return os;
}

Sales_data add(const Sales_data &lhs, Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

Sales_data::Sales_data (std::istream &is)
{
	read(is, *this);		
}
