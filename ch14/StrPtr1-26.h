#include"StrBlob.h"
#include<iostream>

class Ptr {
public:
    StrPtr(StrBlobPtr *p): ptr(p) {}
private:
    StrBlobPtr *ptr;
};
