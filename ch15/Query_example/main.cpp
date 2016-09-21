#include<iostream>
#include<sstream>
#include"TextQuery.h"
#include"QueryResult.h"
#include"WordQuery.h"
#include"NotQuery.h"
#include"AndQuery.h"
#include"OrQuery.h"

using namespace std;
    /*ifstream input("input.txt");
    TextQuery query(input);
    Query one("like");
    Query two("a");
    auto three = one|two;
    auto four = three.eval(query);
    print(cout, four);*/
void word(string&, TextQuery&);
void notWord(string&, TextQuery&);
void orWord(string&, TextQuery&);
void andWord(string&, TextQuery&);

int main()
{
    ifstream input("input.txt");
    TextQuery query(input);
    while(true){
        cout << "Executing Query for: ";
        string line;
        getline(cin, line);
        int k = 0;
        for(auto i : line) {
            if(i == '~')
                k = 1;
            else if(i == '|')
                k = 2;
            else if(i == '&')
                k = 3;
        }
        switch(k){
        case(0): word(line, query); break;
        case(1): notWord(line, query); break;
        case(2): orWord(line, query); break;
        case(3): andWord(line, query); break;
        }

    }
    return 0;
}

void word(string &s, TextQuery &input) {
    Query one(s);
    auto two = one.eval(input);
    print(cout, two);
}

void notWord(string &s, TextQuery &input){
    string word;
    for(auto i : s){
        if(isspace(i))
            continue;
        if(isalpha(i))
            word += i;
    }

    Query one(word);
    auto three = ~one;
    auto two = three.eval(input);
    print(cout, two);
}

void orWord(string &s, TextQuery &input){
    vector<string> words;
    string word = "";
    for(auto i : s){
        if(isspace(i))
            continue;
        if(!isalpha(i)){
            words.push_back(word);
            word = "";
            continue;
        }
        word += i;
    }
    words.push_back(word);
    string word1 = words[0];
    string word2 = words[1];
    auto one = Query(word1);
    auto two = Query(word2);
    auto three = one|two;
    auto four = three.eval(input);
    print(cout, four);
}

void andWord(string &s, TextQuery &input){
    vector<string> words;
    string word = "";
    for(auto i : s){
        if(isspace(i))
            continue;
        if(!isalpha(i)){
            words.push_back(word);
            word = "";
            continue;
        }
        word += i;
    }
    words.push_back(word);
    string word1 = words[0];
    string word2 = words[1];
    auto one = Query(word1);
    auto two = Query(word2);
    auto three = one&two;
    auto four = three.eval(input);
    print(cout, four);
}
