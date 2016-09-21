#include<iostream>
#include<string>
#include<memory>
#include<utility>
#include<initializer_list>

using std::cout;
using std::endl;
using std::allocator;
using std::string;
using std::pair;
using std::initializer_list;

class StrVec {
public:
    StrVec(): elements(nullptr), first_free(nullptr), cap(nullptr) { }
    StrVec(const string &s, int n) {
        auto data = alloc.allocate(n*2);
        auto next = data;
        for(int i = 0; i != n; ++i){
             alloc.construct(next++, s);
        }

        elements = data;
        first_free = next;
        cap = elements + (2*n);
    }
    StrVec(initializer_list<string> il){
        //auto data = alloc.allocate(il.size());
        auto data = alloc_n_copy(il.begin(), il.end());
        elements = data.first;
        first_free = cap = data.second;
    }
    StrVec(const StrVec&);
    StrVec& operator=(const StrVec &);
    ~StrVec();
    StrVec(StrVec &&sv) noexcept : elements(sv.elements), first_free(sv.first_free), cap(sv.cap){
        sv.cap = sv.elements = sv.first_free = nullptr;
    }
    StrVec& operator=(StrVec &&) noexcept;

    string* begin() const { return elements; }
    string* end() const { return first_free; }
    void push_back(const string &);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }

    void print_string(){
        for(auto i = begin(); i != end(); ++i)
            cout << *i << endl;
    }
private:
    allocator<string> alloc;
    void chk_n_alloc() { if (size() == capacity()) reallocate();}
    pair<string*, string*> alloc_n_copy(const string*, const string*);
    void free();
    void reallocate();

    string *elements; //point to the first element
    string *first_free; //point to the element at the end of the next element;
    string *cap; //point to the allocated memory to the next position
};

void StrVec::push_back(const string &s) {
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

pair<string *, string *>
StrVec::alloc_n_copy(const string *b, const string *e){
    auto data = alloc.allocate(e-b);
    return {data, uninitialized_copy(b, e, data)};
}
void StrVec::free(){
    if(elements){
        for(auto p = first_free; p != elements; )
            alloc.destroy(--p);
        alloc.deallocate(elements, cap-elements);
    }
}
StrVec::StrVec(const StrVec &original){
    auto newdata = alloc_n_copy(original.begin(), original.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}
StrVec::~StrVec() { free(); }
StrVec& StrVec::operator=(const StrVec &original){
    auto data = alloc_n_copy(original.begin(), original.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}
void StrVec::reallocate(){
    auto newcapacity = size() ? 2*size() : 1;
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements;
    for(size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}
/*
 * mobile construct and mobile assignment
 *
 */
/*StrVec::StrVec(StrVec &&s) noexcept : elements(s.elements), first_free(s.first_free), cap(s.cap){
    s.elements = s.first_free s.cap = nullptr;
}*/
StrVec& StrVec::operator=(StrVec &&s) noexcept {
    if(this != &s){
        free();
        elements = s.elements;
        cap = s.cap;
        first_free = s.first_free;
        s.cap = s.elements = s.first_free = nullptr;
    }
    return *this;
}
