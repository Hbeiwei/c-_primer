//
// Created by admin on 2024/3/14.
//

#include "Chapter8.h"
#include "iostream"

/**
 * 第八章
 * iostream流操作,并且不指iostream,还有文件fstream和字符串sstream;
 * 其中讲到继承,可以将其都转换成iostream;但也有一些特别需要注意的地方; 其共用一套bits集合,通过字节位来表示不同的状态.
 * 常见的io流状态有 good,fail,end of file, crash
 * iostream特别的点它是标准输入输出流,无法被copy
 * fstream是针对文件,open(),close().
 * sstream针对in-memory string,用来操作字符流的;
 *
*/