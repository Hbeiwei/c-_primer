//
// Created by admin on 2024/3/29.
//

#ifndef PRIMER_QUERYRESULT_H
#define PRIMER_QUERYRESULT_H

#include <memory>
#include <utility>
#include "string"
#include "vector"
#include "set"

using namespace std;

class AndQuery;

class OrQuery;

class NOQuery;

class QueryResult {
    friend class AndQuery;

    friend class NoQuery;

    friend class OrQuery;

    // friend方法可以访问private元素
    friend void print(const QueryResult&, ostream&);

public:
    using line_no = string::size_type;

    shared_ptr<vector<string>> get_file() {
        return context;
    }

    QueryResult(string sought, shared_ptr<vector<string>> context, shared_ptr<multiset<line_no>> lines)
            : sought(std::move(sought)), context(std::move(context)), lines(std::move(lines)) {}

private:
    string sought;
    shared_ptr<vector<string>> context;
    shared_ptr<multiset<line_no>> lines;
};

void print(const QueryResult&, ostream& = cout);

#endif //PRIMER_QUERYRESULT_H
