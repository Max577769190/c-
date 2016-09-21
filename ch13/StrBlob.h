#include<string>
#include<iostream>
#include<vector>
#include<memory>
#include<initializer_list>

using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::shared_ptr;
using std::initializer_list;
using std::make_shared;
using std::ostream;
using std::weak_ptr;

class StrBlobPtr;
/*
 * the realization of StrBlob
 *
 */
class StrBlob{
public:
    friend class StrBlobPtr;
    typedef vector<string>::size_type size_type;

    StrBlob();
    StrBlob(initializer_list<string> il);
    // copy constructor
    StrBlob(const StrBlob &);
    // copy assignment operators
    StrBlob& operator=(const StrBlob &);

    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const string &s){ data->push_back(s); }
    void pop_back();
    string &front();
    string &back();
    void print_string() {
        for (auto i : *data)
            cout << i << " ";
        cout << endl;
    }

    StrBlobPtr begin();
    StrBlobPtr end();

    int print_use_count(){
        return data.use_count();
    }
private:
    shared_ptr<vector<string>> data;

    void check(size_type i, const string &msg) const;
};

StrBlob::StrBlob(const StrBlob &original): data(original.data) { }
StrBlob& StrBlob::operator=(const StrBlob &original){
    data = original.data;
}

StrBlob::StrBlob(): data(make_shared<vector<string>>()) { }
StrBlob::StrBlob(initializer_list<string> il): data(make_shared<vector<string>> (il)) { }

void StrBlob::check(size_type i, const string &msg) const {
    if(i >= data->size())
        throw std::out_of_range(msg);
}

string& StrBlob::front() {
    check(0, "front on empty StrBlob");
    return data->front();
}
string& StrBlob::back() {
    check(0, "back on empty StrBlob");
    return data->back();
}
void StrBlob::pop_back() {
    check(0, "pop_back on empty StrBlob");
    return data->pop_back();
}

/*
 * the realization of StrBlobPtr
 *
 */
class StrBlobPtr{
public:
    StrBlobPtr(): curr(0) { }
    StrBlobPtr(StrBlob &a, size_t sz = 0): wptr(a.data), curr(sz) { }

    string& deref() const;
    StrBlobPtr& incr();
private:
    shared_ptr<vector<string>> check(size_t, const string &) const;

    weak_ptr<vector<string>> wptr;
    size_t curr;
};

shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string &msg) const {
    auto ret = wptr.lock();
    if(!ret)
        throw std::runtime_error("unbound StrBlobPtr");
    if(i > ret->size())
        throw std::out_of_range(msg);
    return ret;
}

string& StrBlobPtr::deref() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr(){
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

StrBlobPtr StrBlob::begin(){
    return StrBlobPtr(*this);
}
StrBlobPtr StrBlob::end(){
    auto ret = StrBlobPtr(*this, data->size());
    return ret;
}
