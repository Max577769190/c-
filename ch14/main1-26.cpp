#include<iostream>
#include"Sales_data.h"
#include"StrBlob.h"
#include<memory>
#include"StrVec.h"
#include"String.h"
//#include"StrPtr.h"

using namespace std;

int main()
{
    /*Sales_data book1;
    Sales_data book2;
    cin >> book1;
    cin >> book2;
    cout << "|**************************************|" << endl;
    book2 += book1;
    cout << book2;
    StrBlob a({"Hello"});
    StrBlob b({"Hello"});
    cout << (a==b) << endl;*/
    /*StrVec str1({"Hello"});
    StrVec str2({"Hello"});
    cout << (str1 == str2) << endl;*/
    /*String str1("Hello");
    String str2("Hello");
    cout << (str1 == str2) << endl;*/
    /*StrBlob str1({"Hello", "World"});
    StrBlob str2({"Hello", "Zero"});
    cout << (str1 < str2) << endl;*/
    /*StrVec str1({"Hello", "World"});
    StrVec str2({"Hello", "Zero"});
    cout << (str1<str2) << endl;*/
    /*String str1("Hello");
    String str2("Hellz");
    cout << (str1 < str2) << endl;*/
    /*Sales_data a;
    a = "Hello";
    cout << a;*/
    /*StrBlob str({"Hello", "World", "Are", "You", "OK"});
    cout << str[3] << endl;*/
    /*String str("Hello");
    cout << (char)str[2] << endl;*/
    StrBlob a1 = {"hi", "bye", "now"};
    StrBlobPtr p(a1);
    *p = "okay";
    cout << p->size() << endl;
    cout << (*p).size() << endl;
    return 0;
}
