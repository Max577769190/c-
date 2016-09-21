#include<vector>
#include<iostream>

using namespace std;

class Foo{
public:
    Foo()=default;

    Foo sorted() &&;
    Foo sorted() const &;
    void push_back(int n) {
        data.push_back(n);
    }
private:
    vector<int> data;
};

Foo Foo::sorted() const & {
    Foo ret(*this);
    cout << "done" << endl;
    return ret.sorted();
}
