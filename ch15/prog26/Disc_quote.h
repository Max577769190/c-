#include<iostream>
#include<string>

using namespace std;

class Disc_quote : public Quote {
public:
    Disc_quote() { cout << "Disc_quote default construct" << endl;}
    Disc_quote(const string &_bookNo, double _price, size_t _quantity, double _discount):
        Quote(_bookNo, _price), quantity(_quantity), discount(_discount) { cout << "Disc_quote normal construct" << endl; }
    Disc_quote(const Disc_quote &d): Quote(d), quantity(d.quantity), discount(d.discount) {
        cout << "Disc_quote copy construct" << endl;
    }
    Disc_quote& operator=(const Disc_quote &rhs){
        Quote::operator=(rhs);
        quantity = rhs.quantity;
        discount = rhs.discount;
        cout << "Disc_quote assignment construct" << endl;

        return *this;
    }
    ~Disc_quote() { cout << "Disc_quote destruct" << endl; }

    virtual double net_price(size_t) const override = 0;
protected:
    size_t quantity;
    double discount;
};
