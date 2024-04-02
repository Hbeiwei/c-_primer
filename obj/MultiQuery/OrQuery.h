//
// Created by admin on 2024/3/29.
//

#ifndef PRIMER_ORQUERY_H
#define PRIMER_ORQUERY_H

#include "BinaryQuery.h"
#include "algorithm"
#include "iterator"

class OrQuery : public BinaryQuery {
public:
    friend Query operator|(const Query&, const Query&);

private:
    OrQuery(const Query& left, const Query& right) : BinaryQuery(left, right, "|") {}

    QueryResult eval(const TextQuery& query) const override;
};

inline Query operator|(const Query& q1, const Query& q2) {
    return Query(shared_ptr<Query_base>(new OrQuery(q1, q2)));
}

QueryResult OrQuery::eval(const TextQuery& query) const{
    auto lr = left.eval(query);
    auto rr = right.eval(query);

    auto ret_lines = make_shared<multiset<line_no>>();

    std::set_union(lr.lines->begin(), lr.lines->end(), rr.lines->begin(), rr.lines->end(),
                   inserter(*ret_lines, ret_lines->begin()));

    return {rep(), lr.get_file(), ret_lines};
}

#endif //PRIMER_ORQUERY_H
