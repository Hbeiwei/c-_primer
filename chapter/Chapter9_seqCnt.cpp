//
// Created by admin on 2024/3/18.
//

#include "Chapter9.h"
#include "forward_list"
#include "list"
#include "deque"
#include "array"
#include "iostream"
#include "vector"
#include "string"
#include "exception"
#include "stack"
#include "queue"

/**
* 第九章,顺序容器
 * list,forward_list
 * vector, string, array, deque
*/
void test() {
    std::array<int, 10> a{};
    for (const auto &i: a) {
        std::cout << i << std::endl;
    }
}

/**
 * string
 */
void test_string() {
    try {
        std::string s = "hello";
        std::cout << s.find("world") << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}


/**
 * container adapter
 * stack,queue,priority_queue
 * stack -> 除array,forward_list
 * queue -> list,deque
 * priority queue ->vector,deque
 */
void test_container_adapter(){
    std::vector<int> vct{1,2,3,4,5};
    std::stack<int, std::vector<int>> stk(vct);

    while(!stk.empty()){
        std::cout<< stk.top() << std::endl;
        stk.pop();
    }

    std::queue<int, std::vector<int>> vstk(vct);

}


