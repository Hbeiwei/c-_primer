//
// Created by admin on 2024/3/21.
//

#include "StrVec.h"

using namespace std;

/**
* 第十三章:StrVec实现 - class controls
 * copy constructor,copy assignment,move constructor,move assignment,destructor
*/

/**
 *
 * 通常此方法可以表示copy或者move两者,因为string &&可以转换成const string&; 所以可以通过reference qualifier
 * 来限定其this传入的是lvalue还是rvalue, &表示lvalue,&&表示rvalue.
 * @param s
 */
void StrVec::push_back(const string &s) &{
    chk_n_alloc();

    alloc.construct(first_free++, s);
}

// 方法重载,此方法走的string move constructor
void StrVec::push_back(string &&s) {
    chk_n_alloc();

    alloc.construct(first_free++, std::move(s));
}

pair<string *, string *> StrVec::alloc_n_copy(const string *s1, const string *s2) {
    auto data = alloc.allocate(s2 - s1);

    return {data, uninitialized_copy(s1, s2, data)};
}

// 释放空间,通过allocator中的destroy和deallocate;
void StrVec::free() {
    // 如果element初始为nullptr,则直接退出
    if (!elements) return;

    // 必须要先destroy,此会调用destructor,然后再回收空间
    for (auto p = first_free; p != elements; p--) {
        alloc.destroy(p);
    }

    alloc.deallocate(elements, capacity());
}

// copy constructor
StrVec::StrVec(const StrVec &obj) {
    auto new_pair = alloc_n_copy(obj.begin(), obj.end());
    elements = new_pair.first;
    first_free = cap = new_pair.second;
}

// copy assignment
StrVec &StrVec::operator=(const StrVec &obj) {
    if (this == &obj) return *this;

    free();
    auto new_pair = alloc_n_copy(obj.begin(), obj.end());
    elements = new_pair.first;
    first_free = cap = new_pair.second;

    return *this;
}

/**
 * move方法额外说明一下:
 * 当明确知道move方法里不会抛出异常时,则可以使用noexcept,这表明在一些容器进行插入值,会优先选择move,但如果没有声明此noexcept,则
 * 会使用copy;
 *
 * move中都涉及到rvalue reference,这个很特殊,能指定一个常量或者临时值,当它做为方法时,表明没有其他对象指向此rvalue reference,所以
 * 可以modify.
 *
 * 所以这涉及到copy和move对于class control的区别:
 * 1.copy是复制,如果是值赋值,则与当前obj没有任何关联,而move不一样,是将obj 'steal' 过来; 所以move可能会提高性能,因为能减少copy,
 * 但move仅限于class inner code中;
 * 2.copy是const value,而move是个可modified value obj; (针对参数obj)
 * @param obj
 */

// move constructor
StrVec::StrVec(StrVec &&obj) noexcept: elements(obj.elements), first_free(obj.first_free), cap(obj.cap) {
    // let the moved-from obj is destructible
    obj.elements = obj.first_free = obj.cap = nullptr;
}

// move assignment
StrVec &StrVec::operator=(StrVec &&obj) noexcept {
    if (this == &obj) return *this;
    free();
    elements = obj.elements;
    first_free = obj.first_free;
    cap = obj.cap;

//    obj.elements = obj.first_free = obj.cap = nullptr;  // 此可以不需要
    return *this;
}

// destructor
StrVec::~StrVec() {
    free();
}

// assign operator
StrVec &StrVec::operator=(std::initializer_list<string> list) noexcept {
    auto new_pair = alloc_n_copy(list.begin(), list.end());
    free();
    elements = new_pair.first;
    first_free = cap = new_pair.second;
    return *this;
}

// reallocate
void StrVec::reallocate() {
    auto new_capacity = size() ? 2 * size() : 1;

    auto p = alloc.allocate(new_capacity), b_ptr = p;

    // 重新分配,无需copy,直接move
    for (auto f = elements; f != first_free; f++) {
        alloc.construct(p++, std::move(*f));
    }

    free();

    elements = b_ptr;
    first_free = p;
    cap = elements + new_capacity;
}

void test() {
    StrVec t, v;

    t = StrVec();
}
