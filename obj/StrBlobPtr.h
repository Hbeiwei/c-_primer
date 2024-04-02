//
// Created by admin on 2024/3/19.
//

#ifndef PRIMER_STRBLOBPTR_H
#define PRIMER_STRBLOBPTR_H

#include <memory>
#include "string"
#include "vector"
#include "StrBlob.h"


using namespace std;




class StrBlobPtr {
public:
    StrBlobPtr() : cur(0) {};

    explicit StrBlobPtr(StrBlob &strBlob, size_t cur = 0) : wk_ptr(strBlob.data), cur(cur) {};

    string &deref();

    StrBlobPtr &incr();

private:
    size_t cur;
    weak_ptr<vector<string>> wk_ptr;
    shared_ptr<vector<string>> check(size_t, const string &) const;
};

shared_ptr<vector<string>> StrBlobPtr::check(size_t t, const string &msg) const {
    const shared_ptr<vector<string>> ptr = wk_ptr.lock();

    if (!ptr) {
        throw runtime_error(msg);
    }

    if (t >= ptr->size()) {
        throw out_of_range(msg);
    }

    return ptr;
}

string &StrBlobPtr::deref() {
    auto ptr = check(cur, "dereference past end");
    return (*ptr)[cur];
}

StrBlobPtr &StrBlobPtr::incr() {
    check(cur, "increment past end");
    cur++;
    return *this;
}


StrBlobPtr StrBlob::begin(){
    return StrBlobPtr(*this, 0);
}

StrBlobPtr StrBlob::end(){
    return StrBlobPtr(*this, this->size());
}

#endif //PRIMER_STRBLOBPTR_H
