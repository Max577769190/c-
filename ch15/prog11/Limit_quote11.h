#include<iostream>
#include<string>

using namespace std;

class Limit_quote : public Disc_quote {
public:
    Limit_quote() = default;
    Limit_quote(const string &_bookNo, double _price, size_t _limit, double _discount):
        Disc_quote(_bookNo, _price, _limit, _discount) { }

    double net_price(size_t n) const override;
    void debug() const override {
        cout << "bookNo: " << this->isbn() << endl;
        cout << "price: " << price << endl;
        cout << "limit: " << limit << endl;
        cout << "discount: " << discount << endl;
    }
private:
    size_t limit;
    double discount = 0.5;
};

double Limit_quote::net_price(size_t n) const {
    if(n >= limit)
        return n * price;
    else
        return price * (1-discount) * n;
}
