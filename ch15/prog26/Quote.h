#include<iostream>
#include<string>

using namespace std;

class Quote{
public:
    Quote() { cout << "default construct" << endl; } ;
    Quote(const string &_bookNo, double _price): bookNo(_bookNo), price(_price) { cout << "normal construct" << endl; }
    Quote(const Quote &q): bookNo(q.bookNo), price(q.price) { cout << "copy construct" << endl; }
    Quote& operator=(const Quote&);
    virtual ~Quote() { cout << "destruct" << endl; }

    virtual double net_price(size_t n) const { return n * price; }
    string isbn() const { return bookNo; }
private:
    string bookNo;
protected:
    double price = 10.0;
};

Quote& Quote::operator=(const Quote &q){
    bookNo = q.bookNo;
    price = q.price;

    cout << "assignment construct" << endl;

    return *this;
}
