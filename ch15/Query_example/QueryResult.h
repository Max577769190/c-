#include<iostream>
#include<string>
#include<memory>
#include<vector>
#include<set>

using namespace std;

class QueryResult {
    friend ostream& print(ostream&, const QueryResult&);
public:
    using line_no = vector<string>::size_type;
    QueryResult(string s, shared_ptr<set<line_no>> p, shared_ptr<vector<string>> f):
        sought(s), lines(p), file(f) { }

    set<line_no>::iterator begin() { return lines->begin(); }
    set<line_no>::iterator end() { return lines->end(); }
    shared_ptr<vector<string>> get_file() { return file; }
private:
    string sought;
    shared_ptr<set<line_no>> lines;
    shared_ptr<vector<string>> file;
};

ostream &print(ostream &os, const QueryResult &qr){
    os << qr.sought << " occurs " << qr.lines->size() << " times!" << endl;
    for(auto num : *qr.lines)
        os << "\t(line " << num+1 << ") " << *(qr.file->begin()+num) << endl;
    return os;
}

QueryResult
TextQuery::query(const string &sought) const {
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    auto loc = wm.find(sought);
    if (loc == wm.end())
        return QueryResult(sought, nodata, file);
    else
        return QueryResult(sought, loc->second, file);
}
