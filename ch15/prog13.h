#include<iostream>
#include<string>

using namespace std;

class Base {
public:
    string name() { return basename; }
    virtual void print(ostream &os) { os << basename; }
private:
    string basename = "Hello";
};

class Derived : public Base {
public:
    void print(ostream &os) override { Base::print(os); os << " " << i;}
private:
    int i = 0;
};
