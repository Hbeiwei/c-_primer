//
// Created by admin on 2024/3/19.
//

#ifndef PRIMER_CHAPTER11_H
#define PRIMER_CHAPTER11_H
#include "fstream"

using namespace std;

class Chapter11 {
};

// 如果需要被其他文件中调用此方法,则需要在头文件中声明此方法
void transform_word(ifstream&, ifstream&);

#endif //PRIMER_CHAPTER11_H
