//
// Created by admin on 2024/3/18.
//

#include <iostream>
#include <list>
#include "Chapter10.h"
#include "algorithm"
#include "iterator"
#include "vector"
#include "functional"


using namespace std;

/**
 * 第十章
 * Generic algorithm:
 * 1.find
 * 2.equal
 * 3.fill
 * 4.copy:并非insert
 * 5.replace  replace_copy
 * back_insert可以声明一个inserter iterator,能够添加元素
 *
 *
 * Reorder:
 * 1.sort
 * 2.unique
 * 3.stable_sort
 * 4.find_if
 */


void test_copy() {
    int a1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int a2[sizeof(a1) / sizeof(*a1)]; // a2 has the same size as a1
    a2[0] = -1;
// ret points just past the last element copied into a2
    auto ret = copy(begin(a1), end(a1), a2); // copy a1 into a

    for (auto &a: a2) {
        std::cout << a << std::endl;
    }
}

bool predicate(string &s, string::size_type t, string & type) {

    return s.size() > t;
}

// find_if是一个unary predicate,only accept oen argument, so use lambdas!
/**
 * lambda表达式
 * [capture list](param list)->return type {func body}
 * capture list:use the information surround by this lambda;
 * return type can omit, can refer to the return(only one line),other will get void return type.
 * capture list可以使用[=],[&]让编译器自行推断,从当前执行环境中进行参数推演,并且可传递引用,跟正常方法一样;
 * 如果lambda表达式需要修改capture list中的rvalue,则需要声明为mutable,表明其capture list可以被修改,而不是const;
 *
 * lambda表达式是创建了一个class type对象,可callable,它的capture list就是data param
 *
 */
void test_algorithm() {
    vector<int> v{};
    const vector<int>::iterator &iterator = find(v.begin(), v.end(), 1);
    stable_sort(v.begin(), v.end(), [](const int &a,const int &b){ return a > b; });

    auto f = [] { return 1; };
//    find_if(v.begin(), v.end(), predicate)
    int size = 5;
    string type = "hbw";
    const vector<int>::iterator &index = find_if(v.begin(), v.end(), [size,type](int a) { return a >= size; });

    // 可使用build-in的for_each()方法来打印container中的content
    for_each(v.begin(),v.end(),[](int i){std::cout<< i << std::endl;});

    // 可以使用bind方法绑定,传递参数,但是最好使用Lambda代替
    auto bind_func = bind(predicate, std::placeholders::_1, 1, ref(type));
}

/**
 * iterator:
 * sort1 - insert iterator
 * back_inserter,front_inserter,inserter - push_back,push_front,push(value,position)
 * sort2 - iostream iterator
 */
void test_iterator(){
    list<int> lst{};
//    back_inserter(lst);
//    front_inserter(lst);
//    inserter(lst, lst.end());

    istream_iterator<int> in(cin),eof;
    while(in != eof){
        std::cout<< *in++ << std::endl;
    }
}

