#include<iostream>
#include<vector>
#include<memory>
#include<stdexcept>
#include<initializer_list>

using namespace std;

template <typename T> class BlobPtr;

template <typename T>
class Blob {
public:
    typedef typename vector<T>::size_type size_type;
    friend class BlobPtr<T>;

    Blob(): data(make_shared<shared_ptr<T>>()) { }
    Blob(initializer_list<T> il): data(make_shared<vector<T>>(il)) { }

    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const T &t) { data->push_back(t); }
    void push_back(T &&t) { data->push_back(move(t)); }

    T& back();
    void pop_back();
    T& operator[](size_type);
private:
    shared_ptr<vector<T>> data;
    void check(size_type i, const string &msg) const;
};

template <typename T>
void Blob<T>::check(size_type i, const string &msg) const {
    if (i >= data->size())
        throw out_of_range(msg);
}

template <typename T>
T& Blob<T>::back() {
    check(0, "back on empty Blob");
    return data->back();
}

template <typename T>
void Blob<T>::pop_back() {
    check(0, "pop_back on empty Blob");
    data->pop_back();
}

template <typename T>
T& Blob<T>::operator[](size_type i) {
    check(i, "subscript out of range");
    return (*data)[i];
}
