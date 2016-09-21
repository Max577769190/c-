#include<string>
#include<iostream>
#include"Disc_quote.h"

using namespace std;

class Bulk_quote : public Disc_quote{
public:
    Bulk_quote() = default;
    Bulk_quote(const string &s, double _price, size_t _min_qty, double _discount):
        Disc_quote(s, _price, _min_qty, _discount) { }

    double net_price(size_t) const override;
    void debug() const override {
        cout << "bookNo: " << this->isbn() << endl;
        cout << "price: " << price << endl;
        cout << "min_qty: " << min_qty << endl;
        cout << "discount: " << discount << endl;
    }
private:
    size_t min_qty;
    double discount = 0.0;
};

/*double Bulk_quote::net_price(size_t n) const {
    if(n > min_qty)
        return price * (1-discount) * n;
    else
        return n * price;
}*/
