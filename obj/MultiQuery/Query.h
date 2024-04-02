//
// Created by admin on 2024/3/29.
//

#ifndef PRIMER_QUERY_H
#define PRIMER_QUERY_H

#include <utility>
#include "string"
#include "Query_base.h"
#include "WordQuery.h"
#include "memory"

class Query {
    friend Query operator&(const Query&, const Query&);

    friend Query operator|(const Query&, const Query&);

    friend Query operator~(const Query&);

public:
    explicit Query(const std::string& str) : p(shared_ptr<WordQuery>(new WordQuery(str))) {
    }

    QueryResult eval(const TextQuery& t) const {
        return p->eval(t);
    }

    std::string rep() const {
        return p->rep();
    }

private:
    // 构造方法私有化,只能通过operator操作&|~来创建Query
    explicit Query(shared_ptr<Query_base> p) : p(std::move(p)) {}

    std::shared_ptr<Query_base> p; // shared_ptr,因为需要共享资源
};

std::ostream&
operator<<(std::ostream& os, const Query& query) {
// Query::rep makes a virtual call through its Query_base pointer to rep()
    return os << query.rep();
}

// A & B | C = D

#endif //PRIMER_QUERY_H
