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
    friend bool operator==(const StrBlob&, const StrBlob&);
    friend bool operator!=(const StrBlob&, const StrBlob&);
    friend bool operator<(const StrBlob&, const StrBlob&);
public:
    friend class StrBlobPtr;
    typedef vector<string>::size_type size_type;

    StrBlob();
    StrBlob(initializer_list<string> il);
    // copy constructor
    StrBlob(const StrBlob &);
    // copy assignment operators
    StrBlob& operator=(const StrBlob &);
    string& operator[](size_t n){
        check(n, "OUT_OF_RANGE");
        return (*data).at(n);
    }
    const string& operator[](size_t n)const{
        check(n, "OUT_OF_RANGE");
        return (*data).at(n);
    }
    /*string& operator[](size_t n){
        return *((*data).begin()+n);
    }
    const string& operator[](size_t n)const{
        return *((*data).begin()+n);
    }*/

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
bool operator==(const StrBlob &lhs, const StrBlob &rhs){
    return *(lhs.data) == *(rhs.data);
}
bool operator!=(const StrBlob &lhs, const StrBlob &rhs){
    return !(lhs==rhs);
}
bool operator<(const StrBlob &lhs, const StrBlob &rhs){
    return *(lhs.data) < *(rhs.data);
}

/*
 * the realization of StrBlobPtr
 *
 */
class StrBlobPtr{
    friend bool operator==(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator!=(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator<(const StrBlobPtr&, const StrBlobPtr&);
public:
    StrBlobPtr(): curr(0) { }
    StrBlobPtr(StrBlob &a, size_t sz = 0): wptr(a.data), curr(sz) { }
    string& operator[](size_t n){
        auto p = check(n, "out_of_range");
        return (*p)[n];
    }
    const string& operator[](size_t n)const{
        auto p = check(n, "out_of_range");
        return (*p)[n];
    }
    StrBlobPtr& operator++(){
        check(curr, "OUT_OF_RANGE");
        ++curr;
        return *this;
    }
    StrBlobPtr& operator--(){
        --curr;
        check(curr, "OUT_OF_RANGE");
        return *this;
    }
    StrBlobPtr& operator++(int){
        StrBlobPtr ret = *this;
        ++*this;
        return ret;
    }
    StrBlobPtr& operator--(int){
        StrBlobPtr ret = *this;
        --*this;
        return ret;
    }
    string& operator*()const{
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }
    string* operator->()const{
        return &(this->operator*());
    }

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
bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs){
    return lhs.curr == rhs.curr;
}
bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs){
    return !(lhs==rhs);
}
bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs){
    return lhs.curr < rhs.curr;
}
