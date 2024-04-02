//
// Created by admin on 2024/3/29.
//

#ifndef PRIMER_QUERY_BASE_H
#define PRIMER_QUERY_BASE_H

#include "string"
#include "TextQuery.h"

class Query;

class Query_base {
    friend Query;
protected:
    using line_no = TextQuery::line_no;

    virtual ~Query_base() = default; // 使用默认析构函数
private:
    // private的virtual,表示子类必须实现各自的方法
    virtual QueryResult eval(const TextQuery&) const = 0;

    virtual std::string rep() const = 0;
};

#endif //PRIMER_QUERY_BASE_H
