//
// Created by admin on 2024/3/12.
//

#include <iostream>
#include <cassert>
#include "Chapter6.h"

using namespace std;

/**
 * 第六章 - function
 * 值传递,'引用'传递
 * 1.指针作为参数传递,更加灵活,但无法知道其大小,需要额外帮助
 * 2.引用作为参数传递,通用
 * 3.参数如果传递是指针或者引用,尽量使用const.
 */
void test_chapter6() {
    int array[10];
    int *parry[10] = {};  // 定义10个指针数组
    int (*p)[10] = {}; // 定义一个指针,指向10个数,数组
    int (&ref)[10] = array;

    std::cout << "this is chapter6 test file!" << std::endl;
}

// 可变参数的initializer_list,但初始化完成后,长度固定,都为const
void print_message(initializer_list<string> ls) {
    for (const auto &s: ls) {
        std::cout << s << std::endl;
    }
}

// 练习通过迭代器,但为了阅读方便,更推荐range for来编写
void print_message_by_point(initializer_list<string> ls) {
    for (auto beg = ls.begin(); beg != ls.end(); beg++) {
        std::cout << *beg << std::endl;
    }
}

// 函数返回值-数组指针
int (*func(int a))[10] {
    return nullptr;
}

// 函数重载:返回值不同,不能作为重载表示
void print(const char *cp);

void print(const int *beg, const int *end);

void print(const int a[], size_t size);

void print(const string &);

void print(string);

void test() {
    int i = 0;
    // 引用没有top-level const,只有low-level const.
    const int &a = i;

    // c++虽然可以声明const,不管高低,其rvalue都是可以修改的
    const int *p = &i; // low-level const, whether i is const;   p可以修改地址
    const int *const p2 = &i; // top-level const. whether i is const;  p不可以修改

    float f = 1.2f;

}

// 底层常量可以重载,顶层常量无法重载,因为底层是针对实参,而顶层针对形参!
void lookup(int&); // function that takes a reference to Account
void lookup(const int&); // new function that takes a const reference
void lookup(int*); // new function, takes a pointer to Account
void lookup(const int*);

void set_default_param_value(int a,char c = 'c');

// 内联函数,特征是被编译器优化,直接代码代替函数,所以适合短,频繁,非递归函数
inline void test_inline();

// 常量表达式函数 - 是inline函数,返回常量; 内联和常量表达函数,为了编译器展开代码,通常都放在头文件中;
constexpr int test_const_func();

// 测试工具,打印一些基本信息
void test_debug_info(){
    std::cout<< __FILE__ << std::endl;
    std::cout<< __LINE__ << std::endl;

    cerr << "Error: " << __FILE__
         << " : in function " << __func__
         << " at line " << __LINE__ << endl
         << " Compiled on " << __DATE__
         << " at " << __TIME__ << endl
         << " Word read was \"  " << "test"
         << "\": Length too short" << endl;

    assert(1);
}

// 函数指针方法
int (*pFunc(int *)) (int *, int);

// 函数指针pf,只需要知道其方法的参数列表和返回值类型即可声明一个函数指针
bool (*pf)(const string &);

