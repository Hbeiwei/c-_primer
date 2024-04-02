//
// Created by admin on 2024/3/25.
//

#include "Chapter16_template.h"
#include "iostream"

/**
* 第十六章:
 * template function/class - generic programs
 * decltype(*ptr) 得到的是一个引用
 *
 * static_cast允许一个lvalue转换成rvalue reference,但是一般使用move function更方便
 *
 * sizeof():计算对象所占空间字节数; sizeof...();返回pack包中参数的个数
*/

using namespace std;

// T可以被deduce为const和&;但如果 int& &t = int &;所以此方法只能被lvalue调用,或者const int调用
//template <typename T> void test_template(T &t){ // 支持non const,也支持const
//    std::cout<< "1" << std::endl;
//}

// 表示此方法可以被lvalue,temporary,literal调用
template<typename T>
void test_template(const T &t) { // 支持non const,也支持const
    std::cout << "2" << std::endl;
}

// 表示此方法可以被lvalue,rvalue调用;
template<typename T>
void test_template(T &&t) {
    std::cout << "3" << std::endl;
}

void test(int &i); // 仅支持non const

void test(const int &i); // 支持non const,也支持const

// 可变参数的模板方法
template<typename ... Args> void g(Args ... args) {
    cout << sizeof...(Args) << endl; // number of type parameters
    cout << sizeof...(args) << endl; // number of function parameters
}


void test() {
    int j = 0;
    test_template(j);

    const int i = 0;
    test_template(i);

    int &&test3(); // 方法返回右值,可以使用右值指派,而不像 int && b = 右值变量;无法执行

    g(i,j);
}

