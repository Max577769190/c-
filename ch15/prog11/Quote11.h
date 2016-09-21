#include<string>
#include<iostream>

using namespace std;

class Quote{
public:
    Quote() = default;
    Quote(const string &s, double pr): bookNo(s), price(pr){ }
    virtual ~Quote() = default;

    string isbn() const { return bookNo; }
    virtual double net_price(size_t n) const { return price * n; }
    virtual void debug() const {
        cout << "bookNo: " << bookNo << endl;
        cout << "price: " << price << endl;
    }
private:
    string bookNo;
protected:
    double price = 0.0;
};
