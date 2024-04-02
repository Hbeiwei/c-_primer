//
// Created by admin on 2024/3/21.
//

#ifndef PRIMER_STRVEC_H
#define PRIMER_STRVEC_H

#include "string"
#include "memory"

using namespace std;

class StrVec {
public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}

    StrVec(const StrVec &); // copy constructor
    StrVec &operator=(const StrVec &); // copy assignment
    StrVec(StrVec &&) noexcept; // move constructor
    StrVec &operator=(StrVec &&) noexcept; // move assignment
    ~StrVec(); // destructor

    StrVec &operator=(std::initializer_list<string>) noexcept; // move assignment

    void push_back(const string &) &;

    void push_back(string &&);

    size_t size() const { return first_free - elements; }

    size_t capacity() const { return cap - elements; } // 注意容量是cap-elements;

    string *begin() const { return elements; }

    string *end() const { return first_free; }

    // 下标访问,一个const表示常量,无法assignment
    const string &operator[](size_t index)const{
        return elements[index];
    }

    string &operator[](size_t index){
        return elements[index];
    }

private:
    static allocator<string> alloc; // allocates the elements

    // 检查当前是否超过了capacity
    void chk_n_alloc() {
        if (size() == capacity()) reallocate();
    }

    // 分配n个空间,并且copy. 此方法待商议?
    static pair<string *, string *> alloc_n_copy(const string *, const string *);

    void free();

    void reallocate();

    string *elements; // 第一个元素位置
    string *first_free; // one pass last elements
    string *cap; // 容量
};

#endif //PRIMER_STRVEC_H
