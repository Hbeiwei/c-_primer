//
// Created by admin on 2024/3/7.
//

/**
 * 预处理器中的守卫,头文件守卫,防止重复文件引用,导致多次定义
 * 预处理变量
 */
#ifndef PRIMER_SALES_DATA_H
#define PRIMER_SALES_DATA_H

#include "string"
#include "iostream"

using namespace std;

struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

    Sales_data &operator+=(const Sales_data &obj);
};

bool operator==(const Sales_data &s1, const Sales_data &s2) {
    return s1.bookNo == s2.bookNo;
}

bool operator!=(const Sales_data &s1, const Sales_data &s2) {
    return !(s1 == s2);
}

Sales_data &Sales_data::operator+=(const Sales_data &obj) {
    if (*this != obj) return *this;

    units_sold += obj.units_sold;
    revenue += obj.revenue;
    return *this;
}

// output operator
ostream &operator<<(ostream &os, const Sales_data &item) {
    os << item.bookNo << item.units_sold << item.revenue;
    return os;
}

Sales_data operator+(const Sales_data &s1, const Sales_data &s2) {
    Sales_data sum = s1;
    // compound assignment accomplish this action
    //sum += s2;
    return sum;
}

#endif //PRIMER_SALES_DATA_H
