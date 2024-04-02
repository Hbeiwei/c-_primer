//
// Created by admin on 2024/3/19.
//

#ifndef PRIMER_STRBLOB_H
#define PRIMER_STRBLOB_H

#include <stdexcept>
#include "vector"
#include "string"
#include "memory"
#include "exception"


class StrBlobPtr;

// 自定义集合类
class StrBlob {
public:
    friend class StrBlobPtr;

    typedef std::vector<std::string>::size_type size_type;

    StrBlob();

    StrBlob(std::initializer_list<std::string> il);

    size_type size() const { return data->size(); };

    bool empty() const { return data->empty(); }

    void push_back(const std::string &t) { data->push_back(t); }

    void pop_back();

    std::string &front();

    std::string &back();

    StrBlobPtr begin();

    StrBlobPtr end();

private:
    // 动态内存
    std::shared_ptr<std::vector<std::string>> data;

    void check_size(size_type i, const std::string &msg) const;
};


// 定义构造方法

StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}

StrBlob::StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) {}

// 定义方法
void StrBlob::pop_back() {
}

std::string &StrBlob::front() {
    check_size(0, "front on empty StrBlob");
    return data->front();
}

std::string &StrBlob::back() {
    check_size(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::check_size(StrBlob::size_type i, const std::string &msg) const {
    if (i > size()) {
        throw std::out_of_range(msg);
    }
}


#endif //PRIMER_STRBLOB_H
