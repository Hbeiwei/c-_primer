//
// Created by admin on 2024/3/20.
//
#include "iostream"
#include "fstream"
#include "TextQuery.h"


using namespace std;

void print(const QueryResult &result, ostream &os) {
    os << result.sought << " occurs " << result.lines->size() << " time" << endl;
    for (auto line_num: *result.lines) {
        os << "\t(line" << line_num + 1 << ") " << (*result.context)[line_num] << endl;
    }
}

/**
 * 文本查询设计成两个类并使用了动态内存,有两个好处
 * 1.节省空间,提高空间利用率
 * 2.在TextQuery out of the scope时,TextQuery仍然有效
 * @param file
 */
void runTextQuery(ifstream &file) {
    TextQuery t(file);

    string s;
    while (true) {
        std::cout << "enter the key word to search, or enter 'q' to quit:" << std::endl;
        if (!(cin >> s) || s == "q") break;

        /**
         * QueryResult res1 = t.query(s); // res1作为一个rvalue,可以修改其值
         * QueryResult &res2 = t.query(s); // 错误,因为t.query(s)返回的是一个rvalue,而res2是一个lvalue reference.
         * 特例:常量引用可以绑定到临时对象(右值)
         * const QueryResult &res3 = t.query(s);
         */

        print(t.query(s));
    }
}


TextQuery::TextQuery(ifstream &file) : context(new vector<string>) {
    string str;
    while (getline(file, str)) {
        context->push_back(str);
        unsigned num = context->size() - 1;
        istringstream line(str);
        string word;
        while (line >> word) {
            auto &str_set = wm[word];
            if (!str_set) {
                str_set.reset(new multiset<line_no>);
            }

            str_set->insert(num);
        }
    }
}

QueryResult TextQuery::query(const string &word) const {
    // 声明一个static,懒加载模式,来打印为空的情况
    static shared_ptr<multiset<line_no>> nodata(new multiset<line_no>);

    auto res = wm.find(word);
    if (res != wm.end()) {
        return {word, context, res->second};
    } else {
        return {word, context, nodata};
    }
}

