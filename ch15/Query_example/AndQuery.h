#include<iostream>
#include<string>
#include<memory>
#include<algorithm>
#include"BinaryQuery.h"

using namespace std;

class AndQuery: public BinaryQuery {
    friend Query operator&(const Query&, const Query&);
    AndQuery(const Query &left, const Query &right): BinaryQuery(left, right, "&") { }
    QueryResult eval(const TextQuery&) const override;
};

inline Query operator&(const Query &lhs, const Query &rhs){
    return shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

QueryResult
AndQuery::eval(const TextQuery &text) const {
    auto left = lhs.eval(text), right = rhs.eval(text);
    shared_ptr<set<line_no>> ret_lines = make_shared<set<line_no>>();
    set_intersection(left.begin(), left.end(), right.begin(), right.end(), inserter(*ret_lines, ret_lines->begin()));
    return QueryResult(rep(), ret_lines, left.get_file());
}
