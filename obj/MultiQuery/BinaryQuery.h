//
// Created by admin on 2024/3/29.
//

#ifndef PRIMER_BINARYQUERY_H
#define PRIMER_BINARYQUERY_H

#include "Query.h"
#include <utility>

// 定义基类时,需要定义其data,method,constructor,构造器中需要负责初始化自己定义的data,无需管
class BinaryQuery : public Query_base {

protected:
    Query left, right;
    std::string opSym;

    BinaryQuery(Query left, Query right, std::string opSym) : left(std::move(left)), right(std::move(right)), opSym(std::move(opSym)) {}

    std::string rep() const override{
        return "(" + left.rep() + " " + opSym + " " + right.rep() + ")";
    }
};

#endif //PRIMER_BINARYQUERY_H
