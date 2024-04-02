//
// Created by admin on 2024/3/27.
//

#include "Chapter19_SpecialFeature.h"

#include <utility>
#include "cstdlib"
#include "typeinfo"
#include "functional"

/**
* 第十九章（最后一张 0.0）
 * 1.new/delete allocate memory: 跟allocator类似,但是placement使其能完成初始化
 * new和delete类似于allocate分配/回收内存,但不负责初始化和析构,这两个分别由class type的constructor和destructor负责!
 * 2.Run-Time type identification: dynamic_cast<type>(val); typeid operator(build in);
 * 3.Enumerations: scoped enumerator,unscoped enumerator. (unscoped能直接赋值int,scoped无法)
 * 4.pointer to class member; pointer to class member可以通过成员方法返回private成员指针,直接在外部是无法定义的;
 * 可以作为方法参数和返回值类别;pointer to class member分为data member和function member,无论哪一种,记住它都是跟class有关,跟obj无关;
 * function可以封装member function pointer.用来传递给其他方法,但需要定义其成员方法指针类别,其次men_fn可以自行推演.
 * pointer ->  called object by (function | men_fn | bind),都属于functional header头文件中
 * 5.nested class: 内嵌类
 * 6.union class: 共享变量,分配在栈中,一般是将其作为class member,因为如果union class涉及到class type,会非常麻烦,需要手动constructor和destroy在每次switch时!
 * 7.local class: 很少使用
 * 8.inherently non-portable feature: bit-field, volatile
*/

#include "string"
#include "iostream"

using std::string;

class Screen {
private:
    string content;
public:
    static const std::string Screen::*data() { return &Screen::content; }
};

// function pointer or member function pointer主要用来作为function table使用
class Screen_table {
private:
    using Action = Screen_table& (Screen_table::*)();
    using p_cdm = Action Screen_table::*; // 如果想指向menu,定义一个p_cdm指针数组

    Screen_table& left();

    Screen_table& right();

    Screen_table& up();

    Screen_table& down();

    enum Directions {
        LEFT, RIGHT, UP, DOWN
    };

    static Action menu[];
public:
    Screen_table& move(Directions&);
};

Screen_table& Screen_table::left() {
    return *this;
}

Screen_table& Screen_table::right() {
    return *this;
}

Screen_table& Screen_table::up() {
    return *this;
}

Screen_table& Screen_table::down() {
    return *this;
}

// 初始化static成员,只需要一份;因为它是一份类成员方法table,跟object无关,只跟class有关,所以可以声明为static
Screen_table::Action Screen_table::menu[] = {
        &Screen_table::left,
        &Screen_table::right,
        &Screen_table::up,
        &Screen_table::down,
};

// 定义move方法,跟obj相关,所以非static
Screen_table& Screen_table::move(Directions& d) {
    return (this->*menu[d])();
}

// unnamed union
static union {
    int i;
//  string s;
};

class A{


};


// union - trivial/nontrivial(平凡/非平凡:定义了构造or析构or移动or拷贝函数,影响了对象的创建和销毁的称之为nontrivial)
// 1.赋值,指派; 2.union的class control
union Token {
    char cval;
    int ival;
    double dval;
    string s;
};



// trivial-copyable movable types.表明使用的是编译器默认生成的copy,move函数,由编译器优化所决定,所以此时不区分copy和move
void test_class_control(){
    A a1,a2; // default constructor

    A a3 = a1;  // copy constructor
}

void test_allocate_memory() {
    auto* s = new std::string();
    auto* arr = new std::string[10];

    delete s;
    delete[] arr;

    std::size_t t;
    std::string::size_type t2;
}

void test_member_pointer() {
    const std::string Screen::*pdata;
    pdata = Screen::data(); // 初始化pdata pointer,使其指向一个Screen的content;
}


