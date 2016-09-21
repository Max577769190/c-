#include<iostream>
#include<string>
#include<exception>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::istream;
using std::ostream;

class Sales_data {
    friend istream& operator>>(istream&, Sales_data&);
    friend ostream& operator<<(ostream&, const Sales_data&);
    friend Sales_data& operator+(const Sales_data &, const Sales_data&);
    friend bool operator==(const Sales_data&, const Sales_data&);
    friend bool operator!=(const Sales_data&, const Sales_data&);
public:
    Sales_data()=default;
    Sales_data(const string &s): isbn(s){}
    Sales_data(const string &s, int n, double price): isbn(s), units_sold(n), price(price), revenue(n*price) {}

    Sales_data& operator+=(const Sales_data &);
    Sales_data& operator=(const string&);
private:
    string isbn;
    int units_sold = 0;
    double price = 0;
    double revenue = 0;
};

istream& operator>>(istream &input, Sales_data &term){
    cout << "isbn :" ;
    input >> term.isbn;
    cout << "units_sold :" ;
    input >> term.units_sold;
    cout << "price :" ;
    input >> term.price;

    if(input) term.revenue = term.price * term.units_sold;
    else term = Sales_data();

    return input;
}
ostream& operator<<(ostream &output, const Sales_data &term){
    output << "ISBN: " << term.isbn << " units_sold: " << term.units_sold << " revenue: " << term.revenue << endl;
    return output;
}
Sales_data& Sales_data::operator+=(const Sales_data &term){
    units_sold += term.units_sold;
    revenue += term.revenue;
    return *this;
}
Sales_data& operator+(const Sales_data &lhs, const Sales_data &rhs){
    Sales_data sum = lhs;
    sum += rhs;
    return sum;
}
bool operator==(const Sales_data &lhs, const Sales_data &rhs){
    return lhs.isbn==rhs.isbn && lhs.units_sold == rhs.units_sold && lhs.revenue == rhs.revenue;
}
bool operator!=(const Sales_data &lhs, const Sales_data &rhs){
    return !(rhs==lhs);
}
Sales_data& Sales_data::operator=(const string &s){
    isbn = s;
    return *this;
}

