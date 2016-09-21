#include<string>
#include<iostream>

using std::cout;
using std::endl;
using std::string;

class HasPtr {
public:
    friend void swap(HasPtr&, HasPtr&);

    HasPtr(const string &s): ps(new string(s)), i(0), use(new size_t(1)) {}
    HasPtr(const HasPtr &p): ps(p.ps), i(p.i), use(p.use) { ++*use; }
    /*HasPtr& operator=(const HasPtr &rhs) {
        ++(*rhs.use);
        if(--*use == 0) {
            delete ps;
            delete use;
        }
        ps = rhs.ps;
        i = rhs.i;
        use = rhs.use;
        return *this;
    }*/
    HasPtr& operator=(HasPtr);
    bool operator<(HasPtr &);
    ~HasPtr();

    string& return_string() {
        return *ps;
    }
private:
    string *ps;
    int i;
    size_t *use;
};

inline
void swap(HasPtr &lhs, HasPtr &rhs){
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    cout << "using swap..." << endl;
}

HasPtr::~HasPtr() {
    if(--*use == 0){
        delete ps;
        delete use;
    }
}

HasPtr& HasPtr::operator=(HasPtr rhs){
    swap(*this, rhs);
    return *this;
}

bool HasPtr::operator<(HasPtr &rhs){
    return (*this).ps->size() < rhs.ps->size();
}
