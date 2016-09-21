#include<iostream>
#include"Blob.h"
#include"BlobPtr.h"

using namespace std;

int main()
{
    Blob<int> a = {1, 2, 3, 4};
    a.push_back(4);
    BlobPtr<int> b(a);
    cout << *b << endl;
    return 0;
}
