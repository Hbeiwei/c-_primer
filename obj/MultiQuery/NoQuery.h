//
// Created by admin on 2024/3/29.
//

#ifndef PRIMER_NOQUERY_H
#define PRIMER_NOQUERY_H

#include "Query.h"
#include <utility>
#include <algorithm>

class NoQuery : public Query_base {
public:
    friend Query operator~(const Query&);

private:

    QueryResult eval(const TextQuery& query) const override;

    string rep() const override {
        return "~" + p.rep();
    }

    explicit NoQuery(Query q) : p(std::move(q)) {
    }

    Query p;
};

inline Query operator~(const Query& q) {
    return Query(std::shared_ptr<Query_base>(new NoQuery(q)));
}

QueryResult NoQuery::eval(const TextQuery& query) const {
    auto inner = p.eval(query);

    multiset<line_no> all;

    for (int i = 0; i < query.context->size(); i++) {
        all.insert(i);
    }

    auto result = make_shared<multiset<line_no>>();

    std::set_difference(all.begin(), all.end(), inner.lines->begin(), inner.lines->end(),
                        inserter(*result, result->begin()));

    return {rep(), inner.get_file(), result};
}

#endif //PRIMER_NOQUERY_H
