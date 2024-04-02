//
// Created by admin on 2024/3/29.
//

#ifndef PRIMER_WORDQUERY_H
#define PRIMER_WORDQUERY_H

#include <utility>
#include "Query_base.h"
#include "string"

class Query;

class WordQuery : public Query_base {
    friend class Query;

public:

    std::string str;

private:
    explicit WordQuery(string str) : str(std::move(str)) {}

    QueryResult eval(const TextQuery& t) const override {
        return t.query(str);
    }

    string rep() const override {
        return str;
    }
};

#endif //PRIMER_WORDQUERY_H
