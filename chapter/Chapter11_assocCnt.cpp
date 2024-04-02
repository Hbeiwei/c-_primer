//
// Created by admin on 2024/3/19.
//

#include "Chapter11.h"
#include "map"
#include "set"
#include "unordered_map"
#include "unordered_set"
#include "utility"
#include "string"
#include "fstream"
#include "exception"
#include "sstream"
#include "iostream"

using namespace std;

/**
 * Associated container:use the key to find the element
 * wm/set
 * multimap/multiset
 * unordered_map/unordered_set
 * unordered_multimap/unordered_multiset
 */

/**
 * map可以通过角标访问,但此方式会隐式添加元素,需要注意
 * map通过下标访问元素时,如果不存在,则使用默认构造方法,指针会是nullptr,而对象调用默认构造函数,build-in type会是默认初始化值
 */
void test_map() {
    map<string, string> maps;
    maps["hbw"] = "hello world";
    map<string,string>::key_type t1;
    map<string,string>::value_type t2;
    map<string,string>::mapped_type t3;
}

void test_set() {
    set<string> sets;

    set<string>::key_type t;
}

unordered_map<string, string> build_map(ifstream &map_file) {
    unordered_map<string, string> map;

    string key, value;
    while (map_file >> key && getline(map_file, value)) {
        if (value.size() > 1) {
            map[key] = value.substr(1);
        } else {
            throw runtime_error("no rule for " + key);
        }
    }

    return map;
}

const string &transform(unordered_map<string, string> &map, string &word) {
    auto itr = map.find(word);
    if (itr != map.end()) {
        return itr->second;
    } else {
        return word;
    }
}

// a word transformation wm
void transform_word(ifstream &map_file, ifstream &input) {
    unordered_map map = build_map(map_file);

    string str;
    while (getline(input, str)) {
        istringstream stream(str);
        string word;
        while (stream >> word) {
            std::cout << " ";
            std::cout << transform(map, word);
        }

        std::cout << std::endl;
    }
}
