//
// Created by admin on 2024/3/26.
//

#include "Chapter18_Tools.h"
#include "exception"


/**
 * 第十八章 - 大型编程工具
 * 1.exception; 可以通过throw抛出异常,并且抛出异常是编译时期确定,所以指针会发生 'slice down';
 * 2.namespace: 禁止使用using namespace std;会引用所有声明,除非是在实现类中引入它本身!
 * 3.multiple inheritance: X x = b; copy constructor; 编译器默认生成的copy constructor没有explicit
 *  1)基类定义了class control,子类一般也要定义.
*/

namespace test{
    int st;
}


// empty throw只能出现在catch clause中
void test_exception() {
    try {
        int i = 0;
        throw std::bad_exception();
    } catch (...) {
        // do something when exception happened;
        throw;
    }
}


class Test final{

    virtual void test1()  const & noexcept final = 0; // final修饰类表示不可继承,修饰虚函数,表示不可修改虚函数

    bool operator<(const Test &t1){
        return false;
    }
};

