//
// Created by admin on 2024/3/22.
//

#include <stdexcept>
#include "Chapter14_Operator.h"
#include "string"
#include "functional"
#include "iostream"

using namespace std;
/**
 * 第十四章: 操作符重载与转换
 * operator:操作符   operation:操作
 * *操作符是否定义为成员方法或非成员方法(对称性):
 * 1.如果当前操作跟对象状态有关,则需要定义为成员方法,并且对象操作方法有个隐式约定,就是第一个操作数必须是obj,因为需要转换给this
 * 2.如果当前操作需要对称操作,比如mixed type,则需要定义为非成员方方法
 * *操作符需要思考操作符是否改变操作数的状态(const or const);
 *
 * 常见操作符重载:
 * 1.IO operator: nonmembers function(friend),little formatting
 * 2.arithmetic and relational operator: usually nonmember function: ==,< (关联性, 定义<需要与==要保持logical consistent result),
 * =(copy,assign,other assign| member function),+=/-=
 * 3.subscript operator [],->,*,
 * 4.function-call operator: Obj o; o(); build-in type没有function-call; lambda expression就是声明一个临时的类,且有一个成员就是功能调用operator;
 * functional包里面包含function<type>方法,能定义bind function,比如可callable function:lambda, function, function obj
 *
 * class-type conversion
 * 1.build-in conversion
 * 2.define conversion
 * 3.implicit/explicit conversion | static_cast,const_cast,dynamic_const
 *
 * explicit conversion will be implicit in the condition(need bool)
 *
 */


class SmallInt {
public:
    SmallInt(int i = 0): val(i)
    {
        if (i < 0 || i > 255)
            throw std::out_of_range("Bad SmallInt value");
    }
private:
    std::size_t val;
};


void test(){
    SmallInt s = 4; // implicit conversion


    std::cout<< "yes" << std::endl;
}
