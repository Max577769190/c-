#include <iostream>
#include <vector>

using namespace std;

/*
 * 16-4
 */
template<typename T, typename N>
N my_find(T v1, const N v2){
    while(*v1 != v2)
        ++v1;
    return *v1;
}

/*
 * 16-2
 */
template<typename T>
bool compare(T v1, T v2){
    if(v1 < v2) return 1;
    if(v2 < v1) return -1;
    if(v1 == v2) return 0;
}

/*
 * 16-5
 */
template<typename T>
void print(T &v){
    for(auto i : v)
        cout << i << " ";
    cout << endl;
}

/*
 * 16-6
 */
 template<typename T, unsigned si>
 T* my_begin(T &v){
    return v;
 }

 template<typename T, unsigned si>
 T* my_end(T (&arr)[si]){
    return arr+si;
 }

 /*
  * 16-7
  */
  template<typename T, unsigned si>
  constexpr unsigned get_size(const T(&)[si]){
    return si;
  }

int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    int *a_end = my_end(a);
    cout << *(--a_end) << endl;
    return 0;
}
