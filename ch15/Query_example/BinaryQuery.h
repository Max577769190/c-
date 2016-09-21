#include<iostream>
#include<string>

using namespace std;

class BinaryQuery: public Query_base {
protected:
    BinaryQuery(const Query &l, const Query &r, string s):
        lhs(l), rhs(r), opSym(s) { }
    string rep() const override { return "(" + lhs.rep() + " " + opSym + " " +rhs.rep() + ")"; }
    Query lhs, rhs;
    string opSym;
};
