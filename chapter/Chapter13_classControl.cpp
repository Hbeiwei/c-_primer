//
// Created by admin on 2024/3/20.
//

#include "Chapter13_classControl.h"
#include "iostream"
#include "string"
#include "new"
#include "memory"
#include "utility"
#include "vector"

using namespace std;

/**
 * 第十三章 class control
 * 1.copy constructor ;
 * 2.copy assignment : overloaded operation
 * 3.destructor
 * 4.move constructor
 * 5.move assignment
 * class可以通过class control使其赋值操作像'value',也可以使其像'pointer',关键取决于如何定义class control行为;
 *
 * define class control是用于管理'resource',不仅局限于dynamic memory!比如对象指针
 *
 * 此章节揭露指针的实际作用,可以让对象的copy像value一样,也可以像'指针'一样;指针的好处可以节省一些不必要的资源浪费
 * 比如说用std::move();
 * not copy but move!
 *
 * reference qualifier
 * 右值引用 X&&: 表示当前对象没有其他地方使用,可以放心使用
 *
 * copy constructor合成跟default constructor没有关系;
 * move control会默认生成; 除非有以下两种情况,可认为move control被delete或不默认生成: 1.定义了copy control. 2.类成员data有无法move.
 *
 *
 */

// 经典重载方法
void push_back(const string &f1);
void push_back(string &&f1);



void test_right_reference(){
    string &&x = "1";
    string &d = x;
}

void test() {
    vector<string> v;
    string s = "hello world";
    v.emplace_back("hello world!");
    v.push_back(s);
}

// 编写copy-assignment方法时,需要注意一种极端情况,就是自我赋值,比如a=a;
Chapter13_classControl &Chapter13_classControl::operator=(const Chapter13_classControl &c) {
    // self-assignment
    if (this == &c) {
        return *this;
    }

    auto temp = new string(*c.str);
    delete str; // delete只能删除指针
    str = temp;
    i = c.i;
    return *this;
}



// swap - copy && swap (optimize performance)

