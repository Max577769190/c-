#include<iostream>
#include<memory>
#include<vector>

using namespace std;

template <typename T>
class BlobPtr {
public:
    BlobPtr(): curr(0) { }
    BlobPtr(Blob<T> &a, size_t sz = 0): wptr(a.data), curr(sz) { }

    T& operator*() const {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }

    BlobPtr& operator++();
    BlobPtr& operator--();
    BlobPtr& operator++(int);
    BlobPtr& operator--(int);
private:
    shared_ptr<vector<T>> check(size_t, const string&) const;
    weak_ptr<vector<T>> wptr;
    size_t curr;
};

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator++() {
    ++curr;
    auto ret = check(curr, "subscript out of range");
    return ret;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator--() {
    --curr;
    auto ret = check(curr, "subscript out of range");
    return ret;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator++(int) {
    auto ret = *this;
    ++*this;
    return ret;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator--(int) {
    auto ret = *this;
    --*this;
    return ret;
}

template <typename T>
shared_ptr<vector<T>> BlobPtr<T>::check(size_t i, const string &msg) const {
    if (i > wptr->size())
        throw out_of_range(msg);

    return (*wptr)[i];
}
