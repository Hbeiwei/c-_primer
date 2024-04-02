//
// Created by admin on 2024/3/25.
//

#include "Chapter17_Facilities.h"
#include "tuple"
#include "bitset"
#include "regex"
#include "random"
#include "string"
#include "iostream"
#include "ctime"
#include "iomanip"


/**
* 第十七章
 * specialized library facilities
 * 1.tuple:返回多个值时,不想定义对象,可使用这个,类似于pair,但pair只能返回两个
 * 2.bitset:位操作类;
 * 3.regular expression;
 * 4.random number: engine,distribution
 * 5.io operator: format,un-formatted,random access
*/

using namespace std;

void test(){
    tuple<int,float,double,long> t;

    auto i = get<0>(t);
}


// 默认随机数会每次都创造相同的序列,方便测试
vector<unsigned > test_random_generator(){
    default_random_engine e1(time(nullptr));
    default_random_engine e(e1()); //  random engine
    uniform_int_distribution<unsigned> u(0,9);
    uniform_real_distribution();
    vector<unsigned> ret;

    for(size_t i=0; i<100; i++){
        ret.push_back(u(e));
    }

    return ret;
}


void test_normal_generator(){
    default_random_engine e(time(nullptr));
    normal_distribution<> n(4, 1.5);
    vector<int> ret(9);

    for(size_t i=0; i<200; i++){
        auto index = lround(n(e));
        if(index < ret.size()){
            ++ret[index];
        }
    }

    for (int i = 0; i < ret.size(); ++i) {
        std::cout<< i << string(ret[i], '*')<< std::endl;
        
    }

    bernoulli_distribution();
}
void test_bitset(){
    bitset<32> bit(30);
}