#include<iostream>
#include<functional>
#include<map>
#include<sstream>
#include<string>

using namespace std;

void calculator(map<string, function<int(int, int)>>&, string &);
int main()
{
    map<string, function<int(int, int)>> binops = {
        {"+", [](int i, int j) { return i+j; }},
        {"-", [](int i, int j) { return i-j; }},
        {"*", [](int i, int j) { return i*j; }},
        {"/", [](int i, int j) { return i/j; }}
        };
    string line;

    while(getline(cin, line))
        calculator(binops, line);
    return 0;
}
void calculator(map<string, function<int(int, int)>> &cal, string &s) {
    istringstream input(s);
    int i, j;
    string symbol;
    input >> i >> symbol >> j;
    cout << "result = " << cal[symbol](i, j) << endl;
}
