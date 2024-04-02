//
// Created by admin on 2024/3/12.
//

#include "Chapter1_to_5.h"
#include "../obj/Sales_item.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;


/**
 * 第五章
 * statement - 声明
 * for,do-while,while.
 * if-else,switch.
 * break,continue,return,goto
 */
void test_chapter5() {
    // int &i = 3;  // reference can't bind to literal!!!  字面量是一个常量,如果用非常量引用绑定,则不符合常量要求
    const int &j = 3;
}

/**
 * 第四章
 * 1.表达式 && || > < != =
 * 2.条件表达式 expr ? true : false
 */
void test_chapter4() {
    int i = 0;
    std::cout << i << ++i << std::endl;

    int x = 18;
    double y = 5.0;
    std::cout << (int) (x / y) << std::endl;

    vector<string> v = {};

    for (auto t = v.begin(); t != v.end(); t++) {
        std::cout << *++t << std::endl;
        std::cout << *t++ << std::endl;
    }
}

/**
 * 第三章
 * 1.string literal无法相加.
 * 2.通过下标访问,可以修改,最好检查其在范围内 subscript
 * 3.vector
 * 4.array
 */
void test_chapter3() {
    std::string s1 = "std";
    int temp = -2;
    std::cout << s1.size() << std::endl;
    std::cout << (s1.size() < -2) << std::endl;
    std::cout << (s1.size() < temp) << std::endl;

    // vector类似于arraylist,可以通过下标访问,类似于string.
    vector<int> v = {1, 2, 3, 4, 5};
    std::cout << v[v.size() - 1] << std::endl;

    // array
    int (*p)[10]; // 一个指向int[10]的指针p;
    int a[10] = {1, 2, 3, 4};
    int b[2][3] = {{1, 2, 3},
                   {4, 5}};

    // iterator遍历
    std::cout << "this is vector iterator print" << std::endl;
    for (auto i = v.begin(); i != v.end(); i++) {
        std::cout << *i << std::endl;
    }


    // array遍历
    for (auto &x: b) {
        // p1表示最外层
        for (auto &y: x) {
            std::cout << y << std::endl;
        }
    }
}

/**
 * 1.pointer & reference.
 * 2.extern多文件引用本地常量
 * 3.typedef|using 定义别名
 * 4.auto自动检测类型(const+基本类|指针|引用)
 * 5.decltype自动类型检测(推断类型,舍弃值)
 * 6.定义类
 *
 * 引用&:
 * lvalue reference can't bind to rvalue;
 * 特例:
 * const int &i = 3;
 * 特别记住: auto & 和 auto的区别;
 */
void test_chapter2() {
    int i = 1;
    int m = 2;
    const int *j = &i; // 说明j不能修改i,但是i还是能修改
    const int *const f = &i; // 常量指针指向常量
    const int &s = 1; // literal是一个常量
    int null = 0;
    int *p = &null;

    j = &m;
}

// namespace
int test_chapter1() {
    Sales_item total;

    if (std::cin >> total) {
        Sales_item trans;
        while (std::cin >> trans) {
            if (total.isbn() == trans.isbn()) {
                total += trans;
            } else {
                std::cout << total << std::endl;
                total = trans;
            }
        }
        std::cout << total << std::endl;
    } else {
        std::cerr << "No data?!" << std::endl;
        return -1;
    }
    return 0;
}