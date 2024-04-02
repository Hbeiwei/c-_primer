//
// Created by admin on 2024/3/20.
//

#ifndef PRIMER_CHAPTER13_CLASSCONTROL_H
#define PRIMER_CHAPTER13_CLASSCONTROL_H

#include "string"
void test();

/**
 * destructor -> copy constructor/assignment
 * copy constructor <-> copy assignment
 * identify: default, delete
 *
 */
class Chapter13_classControl {
public:
    Chapter13_classControl() = default;

    explicit Chapter13_classControl(int cnt, int &d) : cnt(cnt), d(d) {}; // explicit加在构造方法前,是在一个参数时,禁止使用'='来初始化,因为这样会导致copy constructor和direct initialization不好区分

    // copy constructor:可以有其他参数
    Chapter13_classControl(const Chapter13_classControl&);

    // copy assignment:return this
    Chapter13_classControl& operator= (const Chapter13_classControl&);

    // destructor:没有参数,无法重载,执行完function body后会destroy member;
    // 析构函数唯一需要管理这个类中自行创建的动态内存(可以使用shared_ptr),其他数据成员会在某个时间点执行完析构后进行destroy;
    ~Chapter13_classControl(){};

    int cnt;

private:
    std::string *str; // 假设这个t默认是用new初始化的
    int i;
    int &d;

};

#endif //PRIMER_CHAPTER13_CLASSCONTROL_H
