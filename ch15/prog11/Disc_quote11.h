#include<iostream>
#include<string>

using namespace std;

class Disc_quote : public Quote{
public:
    Disc_quote() = default;
    Disc_quote(const string &_bookNo, double _price, size_t _qty, double _discount):
        Quote(_bookNo, _price), quanity(_qty), discount(_discount) { }
    double net_price(size_t) const = 0;
    void debug() const override;
protected:
    size_t quanity = 0;
    double discount = 0.0;
};
