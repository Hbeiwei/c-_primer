//
// Created by admin on 2024/3/13.
//

#ifndef PRIMER_CHAPTER7_H
#define PRIMER_CHAPTER7_H

/**
 * 定义在类里面的方法默认是inline内联的! 也可以手动定义inline/static,定义时可省略此关键字
 */
class Chapter7 {
public:
    // 友元类和函数,提供了其他方法访问此类的非public元素

    static const int cnt = 0;

    // 当有多个构造器时,需要指定其为默认构造器
    Chapter7() = default;

    Chapter7(double ht, double wt) : height(ht), weight(wt) {
        // c++中构造方法body是assign,并非初始化,在构造器初始化列表时就完成初始化了
        // c++中成员变量初始化顺序跟class中定义顺序相关,跟构造器初始化列表无关,最好建议跟定义顺序相关,并且最好不要使成员变量初始化依赖另外一个成员变量;
    };

    // delegate + explicit: 表示类构造器是被代理的,并且其构造器为一个参数时,使用explicit表示禁止隐式转换,隐式类转换包括成员方法实参传入自动封装成类,或者=复制对象
    // explicit可以使用强制类型转换,static_cast<class_name>(obj1)
    explicit Chapter7(double ht) : Chapter7(ht, 0) {}

    double get_size() const {
        return Chapter7::height * Chapter7::weight * Chapter7::cnt;
    }

    int test (){
      return -1;
    }

    static int get_cnt() {
        return Chapter7::cnt;
    }

private:
    double height = 0, weight = 0;
};


// 常量构造器,构造字面类,即在编译时期就能计算到类中每个成员变量的值,能提供编译优化

#endif //PRIMER_CHAPTER7_H
