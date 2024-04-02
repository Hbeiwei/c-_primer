//
// Created by admin on 2024/3/21.
//

#ifndef PRIMER_HASPTR_H
#define PRIMER_HASPTR_H

#include "string"
#include "memory"

using namespace std;

/**
 * resource-allocation class; actions: copy,assignment like value
 */
class HasPtr_Value {
public:
    // constructor
    explicit HasPtr_Value(const string &ps = string()) : ps(new string(ps)), i(0) {}

    // define copy constructor
    HasPtr_Value(const HasPtr_Value &p) : ps(new string(*p.ps)), i(p.i) {}

    // define copy assignment: 传入一个copy,然后将当前对象与copy的进行swap,完成'='; 并且没有自我指派风险
    HasPtr_Value &operator=(HasPtr_Value copy) {
        swap(copy);
        return *this;
    }

    // destructor
    ~HasPtr_Value() {
        delete ps;
    }

    // swap方法,减少operator=指派时所花费的资源
    void swap(HasPtr_Value &rpt) {
        using std::swap;
        swap(ps, rpt.ps);
        swap(i, rpt.i);
    }

private:
    string *ps;
    int i;
};

/**
 * 指派和copy让class看起来像指针,这种行为相当于value来说更dangerous;
 */
class HasPtr_Ptr {
public:
    // constructor method
    HasPtr_Ptr(const string &ps) : ps(new string(ps)), i(0), use(new size_t(1)) {}

    // copy constructor
    HasPtr_Ptr(const HasPtr_Ptr &obj) : ps(obj.ps), i(obj.i), use(obj.use) {
        ++*use;
    }

    // copy assignment:很像是destructor和copy constructor的组合
    HasPtr_Ptr &operator=(HasPtr_Ptr &obj) {
        if (this == &obj) return *this;
        // 需要手动调用destructor,是在obj out scope执行,但自定义指派,是手动管理资源
        if(--*use == 0){
            delete ps;
            delete use;
        }
        ps = obj.ps;
        i = obj.i;
        use = obj.use;
        (*use)++;
        return *this;
    }

    // destructor
    ~HasPtr_Ptr() {
        // 需要先--,因为在调用destructor时,相当于此对象被销毁
        if (--*use == 0) {
            delete ps;
            delete use;
        }
    }

private:
    string *ps;
    int i;
    size_t *use; // reference count;
};

#endif //PRIMER_HASPTR_H
