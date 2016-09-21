#include<iostream>
#include<memory>
#include<utility>
#include<algorithm>

using std::cout;
using std::endl;
using std::allocator;
using std::pair;

class String {
    friend bool operator==(const String&, const String&);
    friend bool operator!=(const String&, const String&);
    friend bool operator<(const String&, const String&);
public:
    String(): elements(nullptr), first_free(nullptr){ }
    String(const char *s) {
        char *s1 = const_cast<char*>(s);
        while(*s1)
            ++s1;
        range_initializer(s, s1);
    }
    String(const String &);
    String& operator=(const String&);
    ~String();
    String(String &&s) noexcept : elements(s.elements), first_free(s.first_free) {
        s.elements = s.first_free = nullptr;
        cout << "Mobile Assignment" << endl;
    }
    String& operator=(String &&) noexcept;
    char& operator[](size_t i){
        return elements[i];
    }
    const char& operator[](size_t i)const{
        return elements[i];
    }

    char* begin() const { return elements; }
    char* end() const { return first_free; }
    void print_string() {
        while(elements != first_free)
            cout << *(elements++);
    }
private:
    allocator<char> alloc;
    pair<char*, char*> alloc_n_copy(const char*, const char*);
    void range_initializer(const char*, const char*);
    void free();

    char *elements;
    char *first_free;
};

pair<char*, char*>
String::alloc_n_copy(const char *b, const char *e){
    auto data = alloc.allocate(e-b);
    return {data, std::uninitialized_copy(b, e, data)};
}
void String::range_initializer(const char *b, const char *e){
    auto data = alloc_n_copy(b, e);
    elements = data.first;
    first_free = data.second;
}
String::String(const String &s){
    /*auto data = alloc.allocate(s.end()-s.begin());
    elements = data;
    first_free = std::uninitialized_copy(s.begin(), s.end(), data);*/
    range_initializer(s.begin(), s.end());
    cout << "copy-construct" << endl;
}
void String::free(){
    if(elements){
        for(auto p = first_free; p != elements; )
            alloc.destroy(--p);
        alloc.deallocate(elements, first_free - elements);
    }
    /*if(elements){
        std::for_each(elements, first_free, [this](char &c){ alloc.destroy(&c); });
        alloc.deallocate(elements, first_free-elements);
    }*/
}
String::~String(){
    free();
}
String& String::operator=(const String &s){
    auto data = alloc_n_copy(s.begin(), s.end());
    free();
    elements = data.first;
    first_free = data.second;
    cout << "copy-assignment" << endl;
    return *this;
}
/*
 * mobile assignment
 *
 */
String& String::operator=(String &&s) noexcept {
    if(this != &s){
        free();
        elements = s.elements;
        first_free = s.first_free;
        s.elements = s.first_free = nullptr;
    }
    cout << "mobile assignment" << endl;
    return *this;
}
bool operator==(const String &lhs, const String &rhs){
    if((lhs.begin()-lhs.end()) == (rhs.begin()-rhs.end())){
        for(auto b1 = lhs.begin(), b2 = rhs.begin(); b1 != lhs.end(); ++b1, ++b2){
            if(*b1 == *b2)
                continue;
            else
                return false;
        }
    }else{
        return false;
    }
    return true;
}
bool operator!=(const String &lhs, const String &rhs){
    return !(lhs==rhs);
}
bool operator<(const String &lhs, const String &rhs){
    if((lhs.end()-lhs.begin()) == (rhs.end()-rhs.begin())){
        for(auto p1 = lhs.begin(), p2 = rhs.begin(); p1 != lhs.end(); ++p1, ++p2){
            if(*p1 < *p2)
                return true;
            else
                continue;
        }
    }else{
        if((lhs.end()-lhs.begin()) < (rhs.end()-rhs.begin())){
            return true;
        }else{
            return false;
        }
    }
    return false;
}
