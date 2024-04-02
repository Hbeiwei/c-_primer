//
// Created by admin on 2024/3/29.
//

#ifndef PRIMER_TEXTQUERY_H
#define PRIMER_TEXTQUERY_H

#include <sstream>
#include "memory"
#include "string"
#include "vector"
#include "map"
#include "set"
#include "iostream"
#include "fstream"
#include "QueryResult.h"

using namespace std;

void runTextQuery(ifstream& file);

// 头文件只能含有声明,不能含有定义
class NoQuery;

class TextQuery {
    friend class NoQuery;

public:
    using line_no = string::size_type;

    explicit TextQuery(ifstream&);

    QueryResult query(const string&) const;

private:
    shared_ptr<vector<string>> context;  // 文本内容
    map<string, shared_ptr<multiset<line_no>>> wm; // word map;
};




#endif //PRIMER_TEXTQUERY_H
