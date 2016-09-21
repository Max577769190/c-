#include"Disc_quote.h"

class Bulk_quote : public Disc_quote{
public:
    Bulk_quote() { cout << "Bulk_quote default construct" << endl; }
    Bulk_quote(const string &_bookNo, double _price, size_t _quantity, double _discount): Disc_quote(_bookNo, _price, _quantity, _discount) {
        cout << "Bulk_quote normal construct" << endl;
    }
    Bulk_quote(const Bulk_quote &b): Disc_quote(b) {
        cout << "Bulk_quote copy construct" << endl;
    }
    Bulk_quote& operator=(const Bulk_quote &rhs){
        Disc_quote::operator=(rhs);
        cout << "Bulk_quote assignment construct" << endl;
    }
    ~Bulk_quote() { cout << "Bulk_quote destruct" << endl; }

    double net_price(size_t n) const override;
};

/*
Bulk_quote& Bulk_quote::operator=(const Bulk_quote &b){
    Quote(b.isbn(), b.price);
    //*this = b; lead to recursion
    //Qoute::operator=(rhs); correct way but did not compiler yet because redefine after you add "Quote.h"
    quantity = b.quantity;
    discount = b.discount;
    cout << "Bulk_quote assignment construct" << endl;

    return *this;
}*/
double Bulk_quote::net_price(size_t n) const {
    if(n >= quantity)
        return price * (1-discount) * n;
    else
        return price * n;
}
